from __future__ import annotations
from pathlib import Path
import argparse, struct, os
import numpy as np
from functional_sim.src.misc.opcode_table import OPCODES, name_to_opcode
from functional_sim.build import *


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

    def lw(dst, base, off):        return f"    lw.s    ${dst}, ${base}, {off}"
    def addi(dst, imm):            return f"    addi.s  ${dst}, $0, {imm}"
    def addi_src(dst, src, imm):   return f"    addi.s  ${dst}, ${src}, {imm}"
    def lw_vi(vd, vs):             return f"    lw.vi   ${vd}, ${vs}, 0, 0xf"
    def scpad_ld(drow, gsrc, sid): return f"    scpad.ld ${drow}, ${gsrc}, {COLS}, {ROWS}, {sid}"
    def scpad_st(srow, gdst, sid): return f"    scpad.st ${srow}, ${gdst}, {COLS}, {ROWS}, {sid}"
    def vld(vd, sa, sid):          return f"    vreg.ld ${vd}, ${sa}, {COLS}, {ROWS}, {sid}, 1, $27"
    def vst(vs, sa, sid):          return f"    vreg.st ${vs}, ${sa}, {COLS}, {ROWS}, {sid}, 1, $27"
    def gemm_vv():                 return f"    gemm.vv $6, $4, $5, 0, 0"
    def comment(msg):              return f"    # {msg}"
    def blank():                   return ""

    L = []

    #  Prologue
    L += [
        comment(" Prologue "),
        f"    addi.s  $1, $0, {TILE_ADDR_LOCATION}",
        lw(2,  1,  0),  comment(f"$2  = WEIGHT_GMEM  0x{WEIGHT_GMEM_ADDR:X}"),
        lw(3,  1,  4),  comment(f"$3  = WEIGHT_SCPAD {WEIGHT_SCPAD_ADDR}"),
        lw(20, 1,  8),  comment(f"$20 = INPUT_GMEM   0x{INPUT_GMEM_ADDR:X}"),
        lw(21, 1, 12),  comment(f"$21 = INPUT_SCPAD  {INPUT_SCPAD_ADDR}"),
        lw(25, 1, 16),  comment(f"$25 = OUTPUT_GMEM  0x{OUTPUT_GMEM_ADDR:X}"),
        lw(24, 1, 20),  comment(f"$24 = OUTPUT_SCPAD {OUTPUT_SCPAD_ADDR}"),
        blank(),
        addi_src(23, 24, 0),  
        blank(),
    ]

    # One vreg.ld + lw.vi per weight row, fully unrolled.

    L += [
        comment(" Load weights"),
        scpad_ld(3, 2, SID0),
        blank(),
    ]
    for row in range(ROWS):
        L.append(addi(27, row))
        L.append(f"    vreg.ld $10, $3, {COLS}, {ROWS}, {SID0}, 1, $27")
        L.append(lw_vi(10, 10))
    L.append(blank())


    L += [
        scpad_ld(24, 25, SID1),
        blank(),
    ]

    L += [
        scpad_ld(21, 20, SID0),
        blank(),
    ]

    #   addi.s  $27, $0, {row}   set row index
    #   vreg.ld $4,  $21, SID0   load input  row
    #   vreg.ld $5,  $23, SID1   load accum  row
    #   gemm.vv $6,  $4,  $5     compute
    #   vreg.st $6,  $23, SID1   store result
    for row in range(ROWS):
        L.append(comment(f"row {row}"))
        L.append(addi(27, row))
        L.append(vld(4,  21, SID0))
        L.append(vld(5,  23, SID1))
        L.append(gemm_vv())
        L.append(vst(6,  23, SID1))
        L.append(blank())

    #  Epilogue 
    L += [
        scpad_st(24, 25, SID1),
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
    INPUT_SCPAD_ADDR  = 1024
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

    instrs = assemble_file(asm)

    instr_text = emit_test_format(instrs)

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