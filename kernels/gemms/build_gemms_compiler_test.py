from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, List, Union
import struct
import os
import sys, re
from pathlib import Path
import argparse
import numpy as np

from functional_sim.src.misc.opcode_table import OPCODES, name_to_opcode
from functional_sim.build import *


def bf16_round(x: float) -> int:
    #using to calculate expected - same as logic in src files 
    u = struct.unpack("<I", struct.pack("<f", float(x)))[0]
    lsb = (u >> 16) & 1
    add = 0x7FFF + lsb
    u_round = (u + add) & 0xFFFFFFFF 
    u_bf16 = (u_round & 0xFFFF0000) >> 16
    return u_bf16 & 0xFFFF


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path('tests/gemms.in'), help="Output test file")
    args = ap.parse_args()

    COLS      = 20
    ROWS      = 20
    NUM_TILES = 3


    TILE_ADDR_LOCATION = 60

    WEIGHT_GMEM_ADDR  = 0x1000
    INPUT_GMEM_ADDR   = 0x2000
    OUTPUT_GMEM_ADDR  = 0x5000

    WEIGHT_SCPAD_ADDR = 0        
    INPUT_SCPAD_ADDR  = 1024     
    OUTPUT_SCPAD_ADDR = 2048   



    SID0      = 0
    SID1      = 1

    TILE_BYTES = ROWS * COLS * 2   



    asm = f"""
 gemm_4x4:
       addi_s x2, x2, -272
       sw_s x1, 4(x2)
       sw_s x8, 0(x2)
       addi_s x8, x2, 8
       addi_s x2, x2, -16
 gemm_4x4_block0:
       li_s x9, 0
       addi_s x11, x9, 0
       li_s x9, 4096
       addi_s x10, x9, 0
       li_s x9, 0
       scpad_ld x11, x10, x9
       li_s x9, 0
       addi_s x11, x9, 0
       jal x0, gemm_4x4_block2
 gemm_4x4_block2:
       li_s x9, 4
       blt_s x11, x9, gemm_4x4_block3
       jal x0, gemm_4x4_block4
 gemm_4x4_block3:
       li_s x9, 1
       vreg_ld v1, x11, x9, 31, 0
       add_vv v1, v1, v0, m0
       addi_s x10, x8, 8
       muli_s x9, x11, 64
       add_s x10, x10, x9
       li_s x9, 1
       vreg_st v1, x10, x9, 31, 0
       addi_s x10, x8, 8
       muli_s x9, x11, 64
       add_s x10, x10, x9
       li_s x9, 1
       vreg_ld v1, x10, x9, 31, 0
       add_vv v1, v1, v0, m0
       add_vv v1, v1, v0, m0
       lw_vi v1, v1, 0, m0
       addi_s x9, x11, 1
       addi_s x11, x9, 0
       jal x0, gemm_4x4_block2
 gemm_4x4_block4:
       li_s x9, 64
       addi_s x11, x9, 0
       li_s x9, 4160
       addi_s x10, x9, 0
       li_s x9, 0
       scpad_ld x11, x10, x9
       li_s x9, 128
       addi_s x11, x9, 0
       li_s x9, 4224
       addi_s x10, x9, 0
       li_s x9, 1
       scpad_ld x11, x10, x9
       li_s x9, 0
       addi_s x11, x9, 0
       jal x0, gemm_4x4_block6
 gemm_4x4_block6:
       li_s x9, 4
       blt_s x11, x9, gemm_4x4_block7
       jal x0, gemm_4x4_block8
 gemm_4x4_block7:
       addi_s x10, x11, 128
       li_s x9, 1
       vreg_ld v1, x10, x9, 31, 0
       add_vv v2, v1, v0, m0
       addi_s x10, x8, 8
       li_s x9, 0
       muli_s x9, x9, 64
       add_s x10, x10, x9
       li_s x9, 1
       vreg_ld v1, x10, x9, 31, 0
       add_vv v1, v1, v0, m0
       addi_s x10, x11, 64
       li_s x9, 4
       mv_stm m1, x9
       gemm_vv v1, v2, v1, m1
       li_s x9, 1
       vreg_st v1, x10, x9, 31, 0
       addi_s x9, x11, 1
       addi_s x11, x9, 0
       jal x0, gemm_4x4_block6
 gemm_4x4_block8:
       li_s x9, 64
       addi_s x11, x9, 0
       li_s x9, 4160
       addi_s x10, x9, 0
       li_s x9, 0
       scpad_st x11, x10, x9
       li_s x9, 0
       jal x0, gemm_4x4_epilog
 gemm_4x4_epilog:
       addi_s x10, x9, 0
       addi_s x2, x2, 16
       lw_s x1, 4(x2)
       lw_s x8, 0(x2)
       addi_s x2, x2, 272
       jalr x0,x1, 0
       .section data
       .section code
       .align 4
       global main
       type main func
 main:
       addi_s x2, x2, -16
       sw_s x1, 4(x2)
       sw_s x8, 0(x2)
       addi_s x8, x2, 8
       addi_s x2, x2, -16
 main_block0:
       jal x1, gemm_4x4
       li_s x9, 0
       jal x0, main_epilog
 main_epilog:
       addi_s x10, x9, 0
       addi_s x2, x2, 16
       lw_s x1, 4(x2)
       lw_s x8, 0(x2)
       addi_s x2, x2, 16
       jalr x0,x1, 0


        halt.s
    """

    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()

    img.u32(0x3c, WEIGHT_GMEM_ADDR)
    img.u32(0x40, WEIGHT_SCPAD_ADDR)  
    img.u32(0x44, INPUT_GMEM_ADDR)
    img.u32(0x48, INPUT_SCPAD_ADDR)   
    img.u32(0x4c, OUTPUT_GMEM_ADDR)
    img.u32(0x50, OUTPUT_SCPAD_ADDR)   

    #  store W^T in gmem - no transposing needed later?
    # W[r][c] = r + c/100  -hard to determine expected result with fractional values-bf16 rounding
    # W^T[r][c] = W[c][r] = c + r/100
    # Stored row-major: scratchpad row r = W^T row r = W column r
    # W = np.array([[float(r) + float(c) / 100.0 for c in range(COLS)]
    #           for r in range(ROWS)])
    W = np.array([[float(r + c) for c in range(COLS)]
              for r in range(ROWS)])
    WT = W.T
    for r in range(ROWS):
        for c in range(COLS):
            img.bf16(WEIGHT_GMEM_ADDR + (r * COLS + c) * 2, float(WT[r, c]))
    # input tile - making this more distinct to test
    # tile 0: all 1.0,  tile 1: all 2.0,  tile 2: all 3.0
    # for t in range(NUM_TILES):
    #     base = INPUT_GMEM_ADDR + t * TILE_BYTES
    #     for i in range(ROWS * COLS):
    #         img.bf16(base + i * 2, float(t + 1))
    for t in range(NUM_TILES):
        base = INPUT_GMEM_ADDR + t * TILE_BYTES
        for r in range(ROWS):
            for c in range(COLS):
                img.bf16(base + (r * COLS + c) * 2, float((r + 1) * (t + 1)))

    # output tile - 0 initialized
    for i in range(ROWS * COLS):
        img.bf16(OUTPUT_GMEM_ADDR + i * 2, 0.0)

    # expected
    col_sums = W.sum(axis=0)
    tile_sum = sum(t + 1 for t in range(NUM_TILES))
    base_row = col_sums * float(tile_sum)
    print("Expected C (Row-Major):")
    C_expected = np.zeros((ROWS, COLS))
    for r in range(ROWS):
        C_expected[r, :] = base_row * (r + 1)

    print(C_expected)
    print("W =")
    print(W)
    print()
    print("W^T (stored in gmem / loaded into systolic array) =")
    print(WT)
    print()

    print()
    print("\nExpected BF16 Hex (Column-Major / Bank-Interleaved):")
    for c in range(COLS):
        bank_hex = []
        for r in range(ROWS):
            f_val = float(C_expected[r, c])
            bits = bf16_round(f_val)
            bank_hex.append(f"0x{bits:04X}")
        print(f"Bank {c}: {bank_hex}")

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
    else:
        print(final)


if __name__ == "__main__":
    main()