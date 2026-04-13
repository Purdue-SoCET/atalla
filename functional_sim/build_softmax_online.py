from __future__ import annotations

from pathlib import Path
import argparse
import os

from build import *
from kernels.utils.dataloader import load_tile_data


def _emit_load_mask(lines: list[str], scalar_reg: int, mask_reg: int, mask_val: int, comment: str = "") -> None:
    suffix = f"  # {comment}" if comment else ""
    lines.append(f"lui.s    ${scalar_reg}, {mask_val >> 7}{suffix}")
    lines.append(f"addi.s   ${scalar_reg}, ${scalar_reg}, {mask_val & 0x7f}")
    lines.append(f"mv.stm   {mask_reg}, ${scalar_reg}")


def unroll_online_softmax(
    n: int,
    *,
    tile_addr_location: int,
    sid: int,
    rsum_imm: int = 64,
    mask_reg_full: int = 1,
    row_reg_base: int = 64,
) -> str:
    """
    Proof-of-concept online softmax.

    This keeps a running max per row and rescales previously accumulated numerators
    whenever the max increases. To avoid relying on scalar floating-point add/mul,
    it recomputes the running normalization term from the numerator vector with
    rsum.vi. That is heavier than a polished online kernel, but it is robust with
    the ISA behavior demonstrated so far.
    """
    if n < 1:
        raise ValueError("n must be >= 1")
    if n > 32:
        raise ValueError("online softmax is limited to n <= 32 (5-bit SCPAD / mask fields)")
    if row_reg_base + n - 1 > 255:
        raise ValueError("n is too large for row register allocation")

    max_col_ind = n - 1
    max_row_ind = n - 1
    full_mask_val = (1 << n) - 1

    row_regs = [row_reg_base + i for i in range(n)]

    # Scalar regs
    mask_loader_reg = 6
    row_load_idx_reg = 7
    row_store_idx_reg = 9
    running_max_reg = 15
    new_max_reg = 16
    alpha_reg = 17
    inv_sum_reg = 18
    lane_mask_scalar_reg = 20
    pair_mask_scalar_reg = 21

    # Mask regs
    current_lane_mask_reg = 2
    pair_mask_reg = 3
    lane0_mask_reg = 4

    # Vector regs
    pair_vec_reg = 10
    max_reduce_reg = 11
    numer_reg = 12
    exp_tmp_reg = 13
    sum_vec_reg = 14

    lines: list[str] = []
    append = lines.append

    append(f"addi.s   $1, $0, {tile_addr_location}       # load tile/scpad address table location into $1")
    append("lw.s     $2, 0($1)                           # load gmem tile base address into $2")
    append("lw.s     $3, 4($1)                           # load scratchpad tile base address into $3")
    append("")
    append(f"scpad.ld $3, $2, {max_col_ind}, {max_row_ind}, {sid}       # load NxN tile from gmem to scratchpad")
    append("")
    _emit_load_mask(lines, mask_loader_reg, mask_reg_full, full_mask_val, "write full active-lane mask")
    _emit_load_mask(lines, lane_mask_scalar_reg, lane0_mask_reg, 1, "mask for lane 0")
    append("")

    append("############## PHASE 1: LOAD ROWS (unrolled) ##############")
    append(f"addi.s   ${row_load_idx_reg}, $0, 0                            # row load index = 0")
    append(f"vreg.ld  ${row_regs[0]}, $3, {max_col_ind}, {max_row_ind}, {sid}, 1, ${row_load_idx_reg}  # load row 0")
    for i in range(1, n):
        append(f"addi.s   ${row_load_idx_reg}, ${row_load_idx_reg}, 1                            # advance load row index")
        append(f"vreg.ld  ${row_regs[i]}, $3, {max_col_ind}, {max_row_ind}, {sid}, 1, ${row_load_idx_reg}  # load row {i}")
    append("")

    append("############## PHASE 2: ONLINE SOFTMAX + STORE (unrolled) ##############")
    for row_idx, row_reg in enumerate(row_regs):
        append(f"# ---------------- row {row_idx} ----------------")

        # m = x[0]
        append(f"vmov.vts ${running_max_reg}, ${row_reg}, 0                  # running max m = x[0]")

        # numer = 0; numer[0] = exp(0) = 1
        append(f"sub.vv   ${numer_reg}, ${numer_reg}, ${numer_reg}, {mask_reg_full}, 0   # clear numerator vector")
        append(f"expi.vi  ${numer_reg}, ${numer_reg}, 0, {lane0_mask_reg}                  # numerator[0] = exp(0) = 1")

        for lane in range(1, n):
            lane_mask_val = 1 << lane
            pair_mask_val = 1 | lane_mask_val

            append(f"# lane {lane}: update running max and rescale prior numerators")
            _emit_load_mask(lines, lane_mask_scalar_reg, current_lane_mask_reg, lane_mask_val, f"mask for lane {lane}")
            _emit_load_mask(lines, pair_mask_scalar_reg, pair_mask_reg, pair_mask_val, f"mask for lanes 0 and {lane}")

            # new_max = max(m_old, x_k)
            append(f"sub.vv   ${pair_vec_reg}, ${pair_vec_reg}, ${pair_vec_reg}, {mask_reg_full}, 0   # clear pair vector")
            append(f"add.vs   ${pair_vec_reg}, ${pair_vec_reg}, ${running_max_reg}, {lane0_mask_reg}   # place running max in lane 0")
            append(f"add.vv   ${pair_vec_reg}, ${pair_vec_reg}, ${row_reg}, {current_lane_mask_reg}, 0   # place x[{lane}] in lane {lane}")
            append(f"rmax.vi  ${max_reduce_reg}, ${pair_vec_reg}, 0, {pair_mask_reg}         # new max = max(m_old, x[{lane}])")
            append(f"vmov.vts ${new_max_reg}, ${max_reduce_reg}, 0              # extract new max")

            # alpha = exp(m_old - m_new)
            append(f"sub.vv   ${exp_tmp_reg}, ${exp_tmp_reg}, ${exp_tmp_reg}, {mask_reg_full}, 0   # clear exp temp")
            append(f"add.vs   ${exp_tmp_reg}, ${exp_tmp_reg}, ${running_max_reg}, {lane0_mask_reg}   # temp[0] = m_old")
            append(f"sub.vs   ${exp_tmp_reg}, ${exp_tmp_reg}, ${new_max_reg}, {lane0_mask_reg}   # temp[0] = m_old - m_new")
            append(f"expi.vi  ${exp_tmp_reg}, ${exp_tmp_reg}, 0, {lane0_mask_reg}              # alpha = exp(m_old - m_new)")
            append(f"vmov.vts ${alpha_reg}, ${exp_tmp_reg}, 0                    # extract alpha")

            # numer *= alpha
            append(f"mul.vs   ${numer_reg}, ${numer_reg}, ${alpha_reg}, {mask_reg_full}   # rescale prior numerators")

            # numer[lane] += exp(x_k - m_new)
            append(f"sub.vv   ${exp_tmp_reg}, ${exp_tmp_reg}, ${exp_tmp_reg}, {mask_reg_full}, 0   # clear exp temp")
            append(f"sub.vs   ${exp_tmp_reg}, ${row_reg}, ${new_max_reg}, {current_lane_mask_reg}   # temp[{lane}] = x[{lane}] - m_new")
            append(f"expi.vi  ${exp_tmp_reg}, ${exp_tmp_reg}, 0, {current_lane_mask_reg}              # temp[{lane}] = exp(x[{lane}] - m_new)")
            append(f"add.vv   ${numer_reg}, ${numer_reg}, ${exp_tmp_reg}, {mask_reg_full}, 0   # insert current numerator")
            append(f"addi.s   ${running_max_reg}, ${new_max_reg}, 0              # m = m_new")

        # sum and normalize once at the end
        append(f"rsum.vi  ${sum_vec_reg}, ${numer_reg}, {rsum_imm}, {mask_reg_full}         # sum online numerators")
        append(f"vmov.vts ${inv_sum_reg}, ${sum_vec_reg}, 0                  # extract sum")
        append(f"rcp.bf   ${inv_sum_reg}, ${inv_sum_reg}, $0                # reciprocal(sum)")
        append(f"mul.vs   ${numer_reg}, ${numer_reg}, ${inv_sum_reg}, {mask_reg_full}   # normalize row")
        append(f"addi.s   ${row_store_idx_reg}, $0, {row_idx}                            # store row index = {row_idx}")
        append(f"vreg.st  ${numer_reg}, $3, {max_col_ind}, {max_row_ind}, {sid}, 1, ${row_store_idx_reg}   # store normalized row {row_idx}")
        append("")

    append(f"scpad.st $3, $2, {max_col_ind}, {max_row_ind}, {sid}            # store NxN tile back to gmem")
    append("")
    append("halt.s")

    return "\n".join(f"        {line}" if line else "" for line in lines)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input", type=Path, default=None, help="Input assembly file")
    ap.add_argument("-o", "--output", type=Path, default="./softmax_online.in", help="Output test file")
    ap.add_argument("--data", type=Path, default=None,
                    help="Path to input tile CSV data file (N×N). If omitted, uses hardcoded defaults.")
    ap.add_argument("--n", type=int, default=32,
                    help="Tile dimension N for an N×N tile (default: 32)")
    args = ap.parse_args()

    N = args.n

    TILE_ADDR_LOCATION = 60
    SCPAD_ADDR_LOCATION = TILE_ADDR_LOCATION + 4
    TILE_ADDR = 0xCAFA
    SCPAD_ADDR = 0
    SID = 0
    RSUM_IMM = 64

    asm = unroll_online_softmax(
        N,
        tile_addr_location=TILE_ADDR_LOCATION,
        sid=SID,
        rsum_imm=RSUM_IMM,
    )

    instrs = assemble_file(asm)

    # Keep the emitted order. build.py's current scheduler does not model mask-reg deps.
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(TILE_ADDR_LOCATION, TILE_ADDR)
    img.u32(SCPAD_ADDR_LOCATION, SCPAD_ADDR)

    base_addr = TILE_ADDR
    if args.data is not None:
        tile_values = load_tile_data(args.data, N)
    else:
        tile_values = [float(v) for v in range(N * N)]

    for i, val in enumerate(tile_values):
        addr = base_addr + (i * 2)
        img.bf16(addr, float(val))

    data_text = img.render_data_mem(include_zeros=False)
    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
    else:
        print(final)


if __name__ == "__main__":
    main()
