from __future__ import annotations
from pathlib import Path
import argparse, struct, os
import numpy as np
from functional_sim.src.misc.opcode_table import OPCODES, name_to_opcode
from functional_sim.build import  (
    assemble_file, emit_test_format,
    emit_test_format_global_dag_pack,   
    DRAMWriter, render_testfile
)

def bf16_round(x: float) -> int:
    u = struct.unpack("<I", struct.pack("<f", float(x)))[0]
    lsb     = (u >> 16) & 1
    u_round = (u + 0x7FFF + lsb) & 0xFFFFFFFF
    return (u_round >> 16) & 0xFFFF


def generate_asm(
    ROWS, COLS,
    TILE_ADDR_LOCATION,
    WEIGHT_GMEM_ADDR, INPUT_GMEM_ADDR, OUTPUT_GMEM_ADDR,
    WEIGHT_SCPAD_ADDR, INPUT_SCPAD_ADDR, OUTPUT_SCPAD_ADDR,
    SID0, SID1,
):
    META_SID0 = (SID0 << 30) | ((ROWS - 1) << 25) | ((COLS - 1) << 20)
    META_SID1 = (SID1 << 30) | ((ROWS - 1) << 25) | ((COLS - 1) << 20)

    def lw(dst, base, off):        return f"    lw.s    ${dst}, ${base}, {off}"
    def addi(dst, imm):            return f"    addi.s  ${dst}, $0, {imm}"
    def addi_src(dst, src, imm):   return f"    addi.s  ${dst}, ${src}, {imm}"
    def lw_vi(vd, vs):             return f"    lw.vi   ${vd}, ${vs}, 0, 0xf"
    def scpad_ld(drow, gsrc, meta_reg): return f"    scpad.ld ${drow}, ${gsrc}, ${meta_reg}"
    def scpad_st(srow, gdst, meta_reg): return f"    scpad.st ${srow}, ${gdst}, ${meta_reg}"
    def vld(vd, sa, sid):          return f"    vreg.ld ${vd}, ${sa}, {COLS}, {ROWS}, {sid}, 1, $27"
    def vst(vs, sa, sid):          return f"    vreg.st ${vs}, ${sa}, {COLS}, {ROWS}, {sid}, 1, $27"
    def gemm_vv():                 return f"    gemm.vv $6, $4, $5, 0, 0"
    def comment(msg):              return f"    # {msg}"
    def blank():                   return ""

    L = []

    # Prologue
    L += [
        comment(" Prologue "),
        f"    addi.s  $1, $0, {TILE_ADDR_LOCATION}",
        lw(2,  1,  0),   comment(f"$2  = WEIGHT_GMEM  0x{WEIGHT_GMEM_ADDR:X}"),
        lw(3,  1,  4),   comment(f"$3  = WEIGHT_SCPAD {WEIGHT_SCPAD_ADDR}"),
        lw(20, 1,  8),   comment(f"$20 = INPUT_GMEM   0x{INPUT_GMEM_ADDR:X}"),
        lw(21, 1, 12),   comment(f"$21 = INPUT_SCPAD  {INPUT_SCPAD_ADDR}"),
        lw(25, 1, 16),   comment(f"$25 = OUTPUT_GMEM  0x{OUTPUT_GMEM_ADDR:X}"),
        lw(24, 1, 20),   comment(f"$24 = OUTPUT_SCPAD {OUTPUT_SCPAD_ADDR}"),
        blank(),
        f"    lui.s   $14, {META_SID0 >> 7}",   comment("metadata SID0"),
        f"    lui.s   $15, {META_SID1 >> 7}",   comment("metadata SID1"),
        blank(),
        addi_src(23, 24, 0),
        blank(),
    ]

    # Load weights
    L += [
        comment(" Load weights"),
        scpad_ld(3, 2, 14),
        blank(),
    ]
    for row in range(ROWS):
        L.append(addi(27, row))
        L.append(f"    vreg.ld $10, $3, {COLS}, {ROWS}, {SID0}, 1, $27")
        L.append(lw_vi(10, 10))
    L.append(blank())

    # Load output (C) and input (A)
    L += [
        scpad_ld(24, 25, 15),
        blank(),
        scpad_ld(21, 20, 14),
        blank(),
    ]

    # Pipeline loop (fully unrolled)
    ROW_REGS = [4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 16, 17, 18, 19, 22, 26, 27] 
    GROUP = 4                        # packet width

    def vld_r(vd, sa, sid, rreg):
        return f"    vreg.ld ${vd}, ${sa}, {COLS}, {ROWS}, {sid}, 1, ${rreg}"
    def vst_r(vs, sa, sid, rreg):
        return f"    vreg.st ${vs}, ${sa}, {COLS}, {ROWS}, {sid}, 1, ${rreg}"

    L.append(comment(" pipeline: grouped addi for packing, correct per-row compute"))

    for group_start in range(0, ROWS, GROUP):
        group = list(range(group_start, min(group_start + GROUP, ROWS)))
        rregs = [ROW_REGS[r % len(ROW_REGS)] for r in group]

        # All addi's are independent → pack into one packet
        L.append(comment(f" rows {group[0]}..{group[-1]}: set indices"))
        for row, rreg in zip(group, rregs):
            L.append(f"    addi.s  ${rreg}, $0, {row}")
        L.append(blank())

        # Per-row compute: vld A, vld C, gemm, vst — must stay together per row
        for row, rreg in zip(group, rregs):
            L.append(comment(f" row {row}"))
            L.append(vld_r(4, 21, SID0, rreg))   # load A row → $4
            L.append(vld_r(5, 23, SID1, rreg))   # load C row → $5
            L.append(gemm_vv())                   # $6 = $4 @ weights + $5
            L.append(vst_r(6, 23, SID1, rreg))   # store result
            L.append(blank())

    # Epilogue
    L += [
        scpad_st(24, 25, 15),
        "    halt.s",
    ]

    return "\n".join(L)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path,
                    default=Path("tests/gemms_unrolled.in"))
    ap.add_argument("--no-graph", action="store_true")
    args = ap.parse_args()

    ROWS = 31
    COLS = 31
    TILE_ADDR_LOCATION = 60
    WEIGHT_GMEM_ADDR  = 0x1000
    INPUT_GMEM_ADDR   = 0x2000
    OUTPUT_GMEM_ADDR  = 0x5000
    WEIGHT_SCPAD_ADDR = 0
    INPUT_SCPAD_ADDR  = 1984
    OUTPUT_SCPAD_ADDR = 0
    SID0, SID1 = 0, 1

    asm = generate_asm(
        ROWS=ROWS, COLS=COLS,
        TILE_ADDR_LOCATION=TILE_ADDR_LOCATION,
        WEIGHT_GMEM_ADDR=WEIGHT_GMEM_ADDR,
        INPUT_GMEM_ADDR=INPUT_GMEM_ADDR,
        OUTPUT_GMEM_ADDR=OUTPUT_GMEM_ADDR,
        WEIGHT_SCPAD_ADDR=WEIGHT_SCPAD_ADDR,
        INPUT_SCPAD_ADDR=INPUT_SCPAD_ADDR,
        OUTPUT_SCPAD_ADDR=OUTPUT_SCPAD_ADDR,
        SID0=SID0, SID1=SID1,
    )

    # instrs = assemble_file(asm)

    # instr_text = emit_test_format(instrs)

    if args.no_graph:
        instrs = assemble_file(asm)
        instr_text = emit_test_format(instrs)
    else:
        instr_text = emit_test_format_global_dag_pack(asm)

    img = DRAMWriter()
    img.u32(TILE_ADDR_LOCATION +  0, WEIGHT_GMEM_ADDR)
    img.u32(TILE_ADDR_LOCATION +  4, WEIGHT_SCPAD_ADDR)
    img.u32(TILE_ADDR_LOCATION +  8, INPUT_GMEM_ADDR)
    img.u32(TILE_ADDR_LOCATION + 12, INPUT_SCPAD_ADDR)
    img.u32(TILE_ADDR_LOCATION + 16, OUTPUT_GMEM_ADDR)
    img.u32(TILE_ADDR_LOCATION + 20, OUTPUT_SCPAD_ADDR)

    W  = np.array([[float(r+c) for c in range(COLS)] for r in range(ROWS)], dtype=np.float32)
    WT = W.T
    for r in range(ROWS):
        for c in range(COLS):
            img.bf16(WEIGHT_GMEM_ADDR + (r*COLS+c)*2, float(WT[r, c]))
    for r in range(ROWS):
        for c in range(COLS):
            img.bf16(INPUT_GMEM_ADDR + (r*COLS+c)*2, float(r+1))
    for i in range(ROWS*COLS):
        img.bf16(OUTPUT_GMEM_ADDR + i*2, 0.0)

    inp  = np.array([[float(r+1) for c in range(COLS)] for r in range(ROWS)], dtype=np.float32)
    C    = WT @ inp
    last = ROWS - 1
    print(f"Expected C = W^T @ Input  ({ROWS}x{COLS})")
    for r, c in [(0, 0), (0, last), (last, 0), (last, last)]:
        print(f"  C[{r},{c}] = {C[r,c]}  → 0x{bf16_round(C[r,c]):04X}")

    data_text = img.render_data_mem(include_zeros=True)
    os.makedirs(args.output.parent, exist_ok=True)
    args.output.write_text(render_testfile(instr_text, data_text))
    print(f"\nWrote {args.output}")


if __name__ == "__main__":
    main()