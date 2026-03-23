from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, List, Union
import struct
import os
import sys, re
from pathlib import Path
import argparse
import numpy as np

from src.misc.opcode_table import OPCODES, name_to_opcode
from build import *


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

    # Change values here for parametrization:
    COLS      = 20
    ROWS      = 20
    NUM_TILES = 3


    TILE_ADDR_LOCATION = 60

    WEIGHT_GMEM_ADDR  = 0x1000
    INPUT_GMEM_ADDR   = 0x2000
    OUTPUT_GMEM_ADDR  = 0x5000

    # # Scratchpad layout (banks are 32 words deep, 1 word = 2 bytes = 1 bf16):
    WEIGHT_SCPAD_ADDR = 0         #(transposed weights, loaded once)
    INPUT_SCPAD_ADDR  = 1024     #(one input tile at a time, overwritten for tile iteration)
    OUTPUT_SCPAD_ADDR = 2048   #(output, here for all tile iterations)



    SID0      = 0
    SID1      = 1

    TILE_BYTES = ROWS * COLS * 2   # bytes per input tile



    asm = f"""
        # Register map:
        #   $20      = tile descriptor table base
        #   $2       = current INPUT_GMEM_ADDR (advances by TILE_BYTES each iteration)
        #   $3       = WEIGHT_SCPAD_ADDR  (= 0,  SID0)
        #   $6       = WEIGHT_GMEM_ADDR (temp) / STM mask / gemm result
        #   $21      = INPUT_SCPAD_ADDR   (= {INPUT_SCPAD_ADDR}, SID0)
        #   $23      = OUTPUT_SCPAD_ADDR  (= 0,  SID1)
        #   $24      = OUTPUT_GMEM_ADDR
        #   $25      = tile loop counter
        #   $26      = tile loop limit   (= {NUM_TILES})
        #   $27      = weight/row loop counter
        #   $28      = weight/row loop limit
        #   $10-$13  = weight vregs (up to 4 rows)
        #   $4       = input vreg  (A row i)
        #   $5       = output vreg (C row i)

        # load address table
        lui.s   $20, 0
        addi.s  $20, $0, {TILE_ADDR_LOCATION}

        lw.s    $6,  0($20)         # $6  = WEIGHT_GMEM_ADDR
        lw.s    $3,  4($20)         # $3  = WEIGHT_SCPAD_ADDR (= 0)
        lw.s    $2,  8($20)         # $2  = INPUT_GMEM_ADDR
        lw.s    $21, 12($20)        # $21 = INPUT_SCPAD_ADDR  (= {INPUT_SCPAD_ADDR})
        lw.s    $24, 16($20)        # $24 = OUTPUT_GMEM_ADDR
        lw.s    $23, 20($20)        # $23 = OUTPUT_SCPAD_ADDR (= 0)

        #  load W^T tile into scpad0
        scpad.ld $3, $6, {COLS}, {ROWS}, {SID0}

        #  enable systolic rows (0xF enables all 4 rows)
        lui.s   $6, 0
        addi.s  $6, $6, 0xf
        mv.stm  1, $6

        # load W^T rows into systolic array using loop with branches
        addi.s  $27, $0, 0        # weight row counter = 0
        addi.s  $28, $0, {ROWS}   # weight row limit = {ROWS}

weight_load_loop:
        bge.s   $27, $28, weight_load_done  # if counter >= {ROWS}, done
        vreg.ld $10, $3, {COLS}, {ROWS}, {SID0}, 1, $27
        lw.vi   $10, $10, 0, 0xf
        addi.s  $27, $27, 1
        blt.s   $27, $28, weight_load_loop  # jump back if counter < limit

weight_load_done:
        # load initial C (zeros) into scpad1
        scpad.ld $23, $24, {COLS}, {ROWS}, {SID1}

        # tile loop
        # For each input tile:
        #   1. Load A tile -> scpad0 starting at {INPUT_SCPAD_ADDR} (overwrites previous tile)
        #   2. For each row i: C[i] += gemm.vv(A[i])  using W^T in systolic array
        #   3. Advance gmem input pointer

        addi.s  $25, $0, 0
        addi.s  $26, $0, {NUM_TILES}

tile_loop:
        scpad.ld $21, $2, {COLS}, {ROWS}, {SID0}

        addi.s  $27, $0, 0
        addi.s  $28, $0, {ROWS}

row_loop:
        vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, $27
        vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, $27
        gemm.vv $6, $4, $5, 0, 0
        vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, $27

        addi.s  $27, $27, 1
        blt.s   $27, $28, row_loop

        addi.s  $2,  $2,  {TILE_BYTES}
        addi.s  $25, $25, 1
        blt.s   $25, $26, tile_loop

        #store final C: scpad1 -> gmem
        scpad.st $23, $24, {COLS}, {ROWS}, {SID1}

        halt.s
    """

    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()

    img.u32(0x3c, WEIGHT_GMEM_ADDR)
    img.u32(0x40, WEIGHT_SCPAD_ADDR)   # 0
    img.u32(0x44, INPUT_GMEM_ADDR)
    img.u32(0x48, INPUT_SCPAD_ADDR)    # 16
    img.u32(0x4c, OUTPUT_GMEM_ADDR)
    img.u32(0x50, OUTPUT_SCPAD_ADDR)   # 0

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