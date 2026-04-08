from __future__ import annotations

import argparse
import math
import os
import re
import struct
from pathlib import Path

import numpy as np

try:
    from .build import DRAMWriter, assemble_file, emit_test_format, render_testfile
except Exception:
    try:
        from functional_sim.build import DRAMWriter, assemble_file, emit_test_format, render_testfile
    except Exception:
        from build import DRAMWriter, assemble_file, emit_test_format, render_testfile


TILE = 32


def bf16_bits_trunc(x: float) -> int:
    u = struct.unpack("<I", struct.pack("<f", float(x)))[0]
    return (u >> 16) & 0xFFFF


def bf16_to_f32(bits: int) -> np.float32:
    return np.float32(struct.unpack("<f", struct.pack("<I", (int(bits) & 0xFFFF) << 16))[0])


def f32_bits(x: float) -> int:
    return struct.unpack("<I", struct.pack("<f", float(x)))[0]


def q_bf16(arr: np.ndarray) -> np.ndarray:
    flat = arr.astype(np.float32).reshape(-1)
    out = np.empty_like(flat, dtype=np.float32)
    for i, v in enumerate(flat):
        out[i] = bf16_to_f32(bf16_bits_trunc(float(v)))
    return out.reshape(arr.shape)


def emit_load_imm(reg: int, value: int) -> list[str]:
    if value < 0:
        raise ValueError("emit_load_imm expects non-negative values")
    upper = value >> 7
    lower = value & 0x7F
    return [
        f"lui.s   ${reg}, {upper}",
        f"addi.s  ${reg}, ${reg}, {lower}",
    ]


def emit_scalar_exp(src_sreg: int, dst_sreg: int, tmp_vreg: int = 26) -> list[str]:
    return [
        f"add.vs   ${tmp_vreg}, $0, ${src_sreg}, 1",
        f"expi.vi  ${tmp_vreg}, ${tmp_vreg}, 0, 1",
        f"vmov.vts ${dst_sreg}, ${tmp_vreg}, 0",
    ]


def emit_sdma_ctl(reg: int, num_cols: int, num_rows: int, sid: int) -> list[str]:
    ctl = ((sid & 0x3) << 30) | ((num_rows & 0x1F) << 25) | ((num_cols & 0x1F) << 20)
    return emit_load_imm(reg, ctl)


def generate_flash_attention_asm(
    n: int,
    q_addr: int,
    k_addr: int,
    v_addr: int,
    o_addr: int,
    scale_addr: int,
    causal: bool = False,
) -> str:
    tiles = n // TILE
    block_bytes = TILE * TILE * 2
    ptmp_addr = 0x00009000
    neg_init_bits = f32_bits(-1000.0)

    # Scalar register allocation
    s_scale = 70
    s_tmp = 60
    s_cmp = 61
    s_mt = 62
    s_lt = 63
    s_mnew = 64
    s_a = 65
    s_b = 66
    s_t1 = 67
    s_t2 = 68
    s_recip = 69

    m_base = 80
    l_base = 112
    bn_base = 144

    row_reg = 7
    sp_row0 = 46
    sp_row1 = 47
    sp_row2 = 48
    ctl_full0 = 49
    ctl_row0 = 50

    gmem_reg = 2

    v_q = 10
    v_o = 11
    v_s = 12
    v_m = 13
    v_p = 14
    v_l = 15
    v_tmp = 16
    v_out = 17
    v_w = 20

    lines: list[str] = []
    lines.append("    # FlashAttention-1 forward (online softmax), unrolled for TILE=32")
    lines.append("    # mask register 1 -> all lanes enabled")
    lines.append("    addi.s  $8, $0, -1")
    lines.append("    mv.stm  1, $8")
    lines.append("")
    lines.append("    # Warm GEMM weight FIFO once so subsequent weight loads replace via full-path shift.")
    for _ in range(32):
        lines.append("    lw.vi   $0, $0, 0, 0")
    lines.append("")

    lines.append("    # Scratchpad row selectors within SID0")
    lines.append(f"    addi.s  ${sp_row0}, $0, 0")
    lines.append(f"    addi.s  ${sp_row1}, $0, 1")
    lines.append(f"    addi.s  ${sp_row2}, $0, 2")
    lines.extend([f"    {x}" for x in emit_sdma_ctl(ctl_full0, 31, 31, 0)])
    lines.extend([f"    {x}" for x in emit_sdma_ctl(ctl_row0, 31, 0, 0)])
    lines.append("")

    lines.extend([f"    {x}" for x in emit_load_imm(s_tmp, scale_addr)])
    lines.append(f"    lw.s    ${s_scale}, 0(${s_tmp})")
    lines.append("")

    for ib in range(tiles):
        lines.append(f"    # ===== Q block i={ib} =====")

        # m = -1000.0 (bf16), l = 0.0 (bf16)
        for r in range(TILE):
            lines.extend([f"    {x}" for x in emit_load_imm(m_base + r, neg_init_bits)])
            lines.append(f"    addi.s  ${l_base + r}, $0, 0")
            lines.append(f"    addi.s  ${bn_base + r}, $0, 0")
        lines.append("")

        for jb in range(tiles):
            k_block_addr = k_addr + jb * block_bytes
            v_block_addr = v_addr + jb * block_bytes
            lines.append(f"    # -- KV block j={jb} for i={ib} --")
            lines.extend([f"    {x}" for x in emit_load_imm(gmem_reg, k_block_addr)])
            lines.append(f"    scpad.ld ${sp_row0}, ${gmem_reg}, ${ctl_full0}")
            lines.append("")

            # Phase 1: load K^T into SA (reverse due full-path lw.vi behavior)
            lines.append("    # Phase 1: Qi @ Kj^T, online softmax stats, store P~ to temp scpad")
            for rr in reversed(range(TILE)):
                lines.append(f"    addi.s  ${row_reg}, $0, {rr}")
                lines.append(f"    vreg.ld ${v_w}, ${sp_row0}, 31, 31, 0, 1, ${row_reg}")
                lines.append(f"    lw.vi   ${v_w}, ${v_w}, 0, 0")
            lines.append("")

            for r in range(TILE):
                label = f"max_done_i{ib}_j{jb}_r{r}"
                label_do_recip = f"do_recip_i{ib}_j{jb}_r{r}"
                label_recip_done = f"recip_done_i{ib}_j{jb}_r{r}"
                label_row_end = f"row_end_i{ib}_j{jb}_r{r}"
                q_row_addr = q_addr + ((ib * TILE + r) * TILE) * 2
                o_row_addr = o_addr + ((ib * TILE + r) * TILE) * 2
                p_row_addr = ptmp_addr + r * TILE * 2
                m_r = m_base + r
                l_r = l_base + r
                bn_r = bn_base + r

                lines.append(f"    # row {r}: S, P~, rowmax/rowsum, online m/l update")
                lines.extend([f"    {x}" for x in emit_load_imm(gmem_reg, q_row_addr)])
                lines.append(f"    scpad.ld ${sp_row0}, ${gmem_reg}, ${ctl_row0}")
                lines.append(f"    addi.s  ${row_reg}, $0, 0")
                lines.append(f"    vreg.ld ${v_q}, ${sp_row0}, 31, 0, 0, 1, ${row_reg}")
                lines.extend([f"    {x}" for x in emit_load_imm(gmem_reg, o_row_addr)])
                lines.append(f"    scpad.ld ${sp_row1}, ${gmem_reg}, ${ctl_row0}")
                lines.append(f"    addi.s  ${row_reg}, $0, 0")
                lines.append(f"    vreg.ld ${v_o}, ${sp_row1}, 31, 0, 0, 1, ${row_reg}")
                lines.append(f"    gemm.vv ${v_s}, ${v_q}, $0, 0, 0")
                lines.append(f"    mul.vs  ${v_s}, ${v_s}, ${s_scale}, 1")
                if causal and jb > ib:
                    lines.append(f"    addi.s  ${bn_r}, $0, 0")
                    lines.append(f"    beq.s   $0, $0, {label_row_end}")
                elif causal and jb == ib:
                    mask_row_addr = 0x0000A000 + (r * TILE * 2)
                    lines.extend([f"    {x}" for x in emit_load_imm(gmem_reg, mask_row_addr)])
                    lines.append(f"    scpad.ld ${sp_row2}, ${gmem_reg}, ${ctl_row0}")
                    lines.append(f"    addi.s  ${row_reg}, $0, 0")
                    lines.append(f"    vreg.ld ${v_tmp}, ${sp_row2}, 31, 0, 0, 1, ${row_reg}")
                    lines.append(f"    addi.vi ${v_l}, $0, 0.0, 1")
                    lines.append(f"    mgt.mvv 2, ${v_tmp}, ${v_l}, 1")
                    lines.append(f"    rmax.vi ${v_m}, ${v_s}, 64, 2")
                    lines.append(f"    addi.vi ${v_p}, $0, 0.0, 1")
                    lines.append(f"    sub.vv  ${v_p}, ${v_s}, ${v_m}, 2, 0")
                    lines.append(f"    expi.vi ${v_p}, ${v_p}, 0, 2")
                    lines.append(f"    rsum.vi ${v_l}, ${v_p}, 64, 2")
                else:
                    lines.append(f"    rmax.vi ${v_m}, ${v_s}, 64, 1")
                    lines.append(f"    sub.vv  ${v_p}, ${v_s}, ${v_m}, 1, 0")
                    lines.append(f"    expi.vi ${v_p}, ${v_p}, 0, 1")
                    lines.append(f"    rsum.vi ${v_l}, ${v_p}, 64, 1")
                lines.append(f"    vmov.vts ${s_mt}, ${v_m}, 0")
                lines.append(f"    vmov.vts ${s_lt}, ${v_l}, 0")

                lines.append(f"    add.s   ${s_mnew}, $0, ${m_r}")
                lines.append(f"    slt.bf  ${s_cmp}, ${m_r}, ${s_mt}")
                lines.append(f"    beq.s   ${s_cmp}, $0, {label}")
                lines.append(f"    add.s   ${s_mnew}, $0, ${s_mt}")
                lines.append(f"{label}:")

                lines.append(f"    sub.bf  ${s_t1}, ${m_r}, ${s_mnew}")
                lines.extend([f"    {x}" for x in emit_scalar_exp(s_t1, s_a, tmp_vreg=v_tmp)])
                lines.append(f"    sub.bf  ${s_t2}, ${s_mt}, ${s_mnew}")
                lines.extend([f"    {x}" for x in emit_scalar_exp(s_t2, s_b, tmp_vreg=v_tmp)])

                lines.append(f"    mul.bf  ${s_t1}, ${l_r}, ${s_a}")
                lines.append(f"    mul.bf  ${s_t2}, ${s_b}, ${s_lt}")
                lines.append(f"    add.bf  ${s_t2}, ${s_t1}, ${s_t2}")  # l_new
                lines.append(f"    bne.s   ${s_t2}, $0, {label_do_recip}")
                lines.append(f"    addi.s  ${s_recip}, $0, 0")
                lines.append(f"    beq.s   $0, $0, {label_recip_done}")
                lines.append(f"{label_do_recip}:")
                lines.append(f"    rcp.bf  ${s_recip}, ${s_t2}, $0")
                lines.append(f"{label_recip_done}:")
                lines.append(f"    mul.bf  ${s_t1}, ${s_t1}, ${s_recip}")  # old scale
                lines.append(f"    mul.bf  ${bn_r}, ${s_b}, ${s_recip}")  # beta_norm

                lines.append(f"    mul.vs  ${v_o}, ${v_o}, ${s_t1}, 1")
                lines.append(f"    addi.s  ${row_reg}, $0, 0")
                lines.append(f"    vreg.st ${v_o}, ${sp_row1}, 31, 0, 0, 1, ${row_reg}")
                lines.extend([f"    {x}" for x in emit_load_imm(gmem_reg, o_row_addr)])
                lines.append(f"    scpad.st ${sp_row1}, ${gmem_reg}, ${ctl_row0}")
                lines.append(f"    addi.s  ${row_reg}, $0, 0")
                lines.append(f"    vreg.st ${v_p}, ${sp_row2}, 31, 0, 0, 1, ${row_reg}")
                lines.extend([f"    {x}" for x in emit_load_imm(gmem_reg, p_row_addr)])
                lines.append(f"    scpad.st ${sp_row2}, ${gmem_reg}, ${ctl_row0}")
                lines.append(f"    add.s   ${m_r}, $0, ${s_mnew}")
                lines.append(f"    add.s   ${l_r}, $0, ${s_t2}")
                lines.append(f"{label_row_end}:")
                lines.append("")

            # Phase 2: load V into SA (reverse), scale P~, accumulate into O
            lines.append("    # Phase 2: (beta_norm * P~) @ V + O")
            lines.extend([f"    {x}" for x in emit_load_imm(gmem_reg, v_block_addr)])
            lines.append(f"    scpad.ld ${sp_row0}, ${gmem_reg}, ${ctl_full0}")
            for rr in reversed(range(TILE)):
                lines.append(f"    addi.s  ${row_reg}, $0, {rr}")
                lines.append(f"    vreg.ld ${v_w}, ${sp_row0}, 31, 31, 0, 0, ${row_reg}")
                lines.append(f"    lw.vi   ${v_w}, ${v_w}, 0, 0")
            lines.append("")

            for r in range(TILE):
                o_row_addr = o_addr + ((ib * TILE + r) * TILE) * 2
                p_row_addr = ptmp_addr + r * TILE * 2
                bn_r = bn_base + r
                lines.extend([f"    {x}" for x in emit_load_imm(gmem_reg, p_row_addr)])
                lines.append(f"    scpad.ld ${sp_row0}, ${gmem_reg}, ${ctl_row0}")
                lines.append(f"    addi.s  ${row_reg}, $0, 0")
                lines.append(f"    vreg.ld ${v_p}, ${sp_row0}, 31, 0, 0, 1, ${row_reg}")
                lines.extend([f"    {x}" for x in emit_load_imm(gmem_reg, o_row_addr)])
                lines.append(f"    scpad.ld ${sp_row1}, ${gmem_reg}, ${ctl_row0}")
                lines.append(f"    addi.s  ${row_reg}, $0, 0")
                lines.append(f"    vreg.ld ${v_o}, ${sp_row1}, 31, 0, 0, 1, ${row_reg}")
                lines.append(f"    mul.vs  ${v_p}, ${v_p}, ${bn_r}, 1")
                lines.append(f"    gemm.vv ${v_out}, ${v_p}, ${v_o}, 0, 0")
                lines.append(f"    addi.s  ${row_reg}, $0, 0")
                lines.append(f"    vreg.st ${v_out}, ${sp_row1}, 31, 0, 0, 1, ${row_reg}")
                lines.extend([f"    {x}" for x in emit_load_imm(gmem_reg, o_row_addr)])
                lines.append(f"    scpad.st ${sp_row1}, ${gmem_reg}, ${ctl_row0}")
            lines.append("")

    lines.append("    halt.s")
    return "\n".join(lines) + "\n"


def flash_attention_online_ref(q: np.ndarray, k: np.ndarray, v: np.ndarray, scale: float, causal: bool = False) -> np.ndarray:
    q = q.astype(np.float32)
    k = k.astype(np.float32)
    v = v.astype(np.float32)
    n, d = q.shape
    tiles = n // TILE
    out = np.zeros((n, d), dtype=np.float32)
    neg_inf = np.float32(-1000.0)

    for ib in range(tiles):
        i0 = ib * TILE
        i1 = i0 + TILE
        qi = q[i0:i1, :]
        oi = np.zeros((TILE, d), dtype=np.float32)
        m = np.full((TILE,), neg_inf, dtype=np.float32)
        l = np.zeros((TILE,), dtype=np.float32)

        for jb in range(tiles):
            j0 = jb * TILE
            j1 = j0 + TILE
            kj = k[j0:j1, :]
            vj = v[j0:j1, :]

            s = (qi @ kj.T) * np.float32(scale)
            if causal:
                row_idx = np.arange(i0, i1, dtype=np.int32)[:, None]
                col_idx = np.arange(j0, j1, dtype=np.int32)[None, :]
                s = np.where(col_idx <= row_idx, s, np.float32(-1e9))
            mt = np.max(s, axis=1)
            p = np.exp(s - mt[:, None]).astype(np.float32)
            lt = np.sum(p, axis=1).astype(np.float32)

            m_new = np.maximum(m, mt)
            a = np.exp(m - m_new).astype(np.float32)
            b = np.exp(mt - m_new).astype(np.float32)
            l_new = a * l + b * lt
            recip = 1.0 / l_new
            scale_old = (a * l) * recip
            scale_new = b * recip

            oi = (oi * scale_old[:, None]) + ((p * scale_new[:, None]) @ vj)
            m = m_new
            l = l_new

        out[i0:i1, :] = oi
    return out


def write_matrix_bf16(img: DRAMWriter, base_addr: int, mat: np.ndarray) -> None:
    rows, cols = mat.shape
    for r in range(rows):
        for c in range(cols):
            img.bf16(base_addr + 2 * (r * cols + c), float(mat[r, c]))


def read_data_mem_dump(path: Path) -> dict[int, int]:
    out: dict[int, int] = {}
    line_re = re.compile(r"^\s*([0-9A-Fa-f]+)\s*:\s*([0-9A-Fa-f]+)\s*$")
    in_data = False
    for line in path.read_text().splitlines():
        if line.strip().upper() == "DATA MEM":
            in_data = True
            continue
        if not in_data:
            continue
        m = line_re.match(line)
        if not m:
            continue
        addr = int(m.group(1), 16)
        val_hex = m.group(2)
        if len(val_hex) != 8:
            continue
        out[addr] = int(val_hex, 16)
    return out


def read_bf16_matrix_from_dump(dump: dict[int, int], base_addr: int, rows: int, cols: int) -> np.ndarray:
    arr = np.zeros((rows, cols), dtype=np.float32)
    for r in range(rows):
        for c in range(cols):
            addr = base_addr + 2 * (r * cols + c)
            word = dump.get(addr, 0)
            bits = word & 0xFFFF
            arr[r, c] = bf16_to_f32(bits)
    return arr


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/flash_attention.in"))
    ap.add_argument("--n", type=int, default=32)
    ap.add_argument("--d", type=int, default=32)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--causal", action="store_true")
    ap.add_argument("--compare_mem_dump", type=Path, default=None)
    args = ap.parse_args()

    if args.d != 32:
        raise ValueError("This kernel currently supports d=32 only.")
    if args.n % TILE != 0:
        raise ValueError("n must be a multiple of 32.")

    n = args.n
    d = args.d
    scale = 1.0 / math.sqrt(float(d))

    q_addr = 0x00001000
    k_addr = 0x00003000
    v_addr = 0x00005000
    o_addr = 0x00007000
    scale_addr = 0x00000020

    rng = np.random.default_rng(args.seed)
    q = rng.normal(0.0, 0.5, size=(n, d)).astype(np.float32)
    k = rng.normal(0.0, 0.5, size=(n, d)).astype(np.float32)
    v = rng.normal(0.0, 0.5, size=(n, d)).astype(np.float32)

    q_b = q_bf16(q)
    k_b = q_bf16(k)
    v_b = q_bf16(v)

    o_ref = flash_attention_online_ref(q_b, k_b, v_b, scale, causal=args.causal)
    o_ref_b = q_bf16(o_ref)

    asm = generate_flash_attention_asm(
        n=n,
        q_addr=q_addr,
        k_addr=k_addr,
        v_addr=v_addr,
        o_addr=o_addr,
        scale_addr=scale_addr,
        causal=args.causal,
    )
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.f32(scale_addr, scale)
    write_matrix_bf16(img, q_addr, q_b)
    write_matrix_bf16(img, k_addr, k_b)
    write_matrix_bf16(img, v_addr, v_b)
    if args.causal:
        tri = np.tril(np.ones((TILE, TILE), dtype=np.float32))
        write_matrix_bf16(img, 0x0000A000, tri)
    write_matrix_bf16(img, o_addr, np.zeros((n, d), dtype=np.float32))

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)
    os.makedirs(args.output.parent, exist_ok=True)
    args.output.write_text(final)

    print(f"[INFO] Wrote kernel to {args.output}")
    print(f"[INFO] N={n}, d={d}, tiles={n // TILE}, scale={scale:.8f}, causal={args.causal}")
    print(f"[INFO] Expected O (first 2 rows, first 8 cols):\n{o_ref_b[:2, :8]}")

    if args.compare_mem_dump is not None:
        dump = read_data_mem_dump(args.compare_mem_dump)
        o_sim = read_bf16_matrix_from_dump(dump, o_addr, n, d)
        diff = np.abs(o_sim - o_ref_b)
        print(f"[COMPARE] max_abs_err={float(np.max(diff)):.6f}, mean_abs_err={float(np.mean(diff)):.6f}")
        print(f"[COMPARE] sim first row first 8: {o_sim[0, :8]}")
        print(f"[COMPARE] ref first row first 8: {o_ref_b[0, :8]}")


if __name__ == "__main__":
    main()
