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
    u = struct.unpack("<I", struct.pack("<f", float(x)))[0]
    lsb = (u >> 16) & 1
    add = 0x7FFF + lsb
    u_round = (u + add) & 0xFFFFFFFF
    u_bf16 = (u_round & 0xFFFF0000) >> 16
    return u_bf16 & 0xFFFF

def bf16_bits_to_float(bits: int) -> float:
    fp32_bits = (int(bits) & 0xFFFF) << 16
    return struct.unpack("<f", struct.pack("<I", fp32_bits))[0]



def to_bf16_f32(x):
    x = np.asarray(x, dtype=np.float32)
    u = x.view(np.uint32).copy()
    lsb = (u >> 16) & np.uint32(1)
    u_round = u + np.uint32(0x7FFF) + lsb
    u_bf16 = (u_round & np.uint32(0xFFFF0000)).astype(np.uint32)
    return u_bf16.view(np.float32)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path,
                    default=Path('./emulator/tests/gemms_1024x1024.in'),
                    help="Output test file")
    ap.add_argument("--no-graph", action="store_true")
    ap.add_argument("--check", type=Path, default=None, metavar="OUTPUT_MEM",
                    help="Path to emulator output_mem.txt — diff against expected C")
    args = ap.parse_args()

    TILE_ROWS = 31
    TILE_COLS = 31

    FULL_ROWS = 1024
    FULL_COLS = 1024
    FULL_K    = 1024

    NUM_TILE_ROWS = (FULL_ROWS + TILE_ROWS - 1) // TILE_ROWS   # 34
    NUM_TILE_COLS = (FULL_COLS + TILE_COLS - 1) // TILE_COLS   # 34
    NUM_TILE_K    = (FULL_K    + TILE_COLS - 1) // TILE_COLS   # 34

    TILE_BYTES  = TILE_ROWS * TILE_COLS * 2   # 1922


    B_GMEM_BASE = 0x0001_0000
    A_GMEM_BASE = B_GMEM_BASE + NUM_TILE_K * NUM_TILE_COLS * TILE_BYTES + 0x1000
    C_GMEM_BASE = A_GMEM_BASE + NUM_TILE_ROWS * NUM_TILE_K  * TILE_BYTES + 0x1000

    B_SCPAD_ADDR = 0
    A_SCPAD_ADDR = 1984
    C_SCPAD_ADDR = 0
    SID0 = 0
    SID1 = 1
    META_SID0 = (SID0 << 30) | ((TILE_ROWS - 1) << 25) | ((TILE_COLS - 1) << 20)
    META_SID1 = (SID1 << 30) | ((TILE_ROWS - 1) << 25) | ((TILE_COLS - 1) << 20)
    TABLE_BASE = 0x0000_8000

    OFF_B_SCPAD   = 0x00
    OFF_A_SCPAD   = 0x04
    OFF_C_SCPAD   = 0x08
    OFF_NJ        = 0x0C
    OFF_NK        = 0x10
    OFF_NI        = 0x14
    OFF_TILE_ROWS = 0x18
    OFF_B_TABLE_PTR = 0x1C   # stores absolute addr of B table start
    OFF_A_TABLE_PTR = 0x20   # stores absolute addr of A table start  
    OFF_C_TABLE_PTR = 0x24   # stores absolute addr of C table start
    OFF_B_TABLE     = 0x28   # actual B tile addresses start here
    OFF_A_TABLE     = OFF_B_TABLE + NUM_TILE_K * NUM_TILE_COLS * 4
    OFF_C_TABLE     = OFF_A_TABLE + NUM_TILE_ROWS * NUM_TILE_K * 4

    print(f"Tile grid: {NUM_TILE_ROWS}x{NUM_TILE_COLS}, NUM_TILE_K={NUM_TILE_K}")
    print(f"TILE_BYTES={TILE_BYTES}")
    print(f"B_GMEM_BASE=0x{B_GMEM_BASE:08X}")
    print(f"A_GMEM_BASE=0x{A_GMEM_BASE:08X}")
    print(f"C_GMEM_BASE=0x{C_GMEM_BASE:08X}")
    print(f"TABLE size needed: 0x{OFF_C_TABLE + NUM_TILE_ROWS*NUM_TILE_COLS*4:X} bytes from TABLE_BASE")
    print()

    print("Building A and B matrices...")
    A_full = np.array([[float(r + c) for c in range(FULL_K)]
                       for r in range(FULL_ROWS)], dtype=np.float32)
    B_full = np.array([[float((r + 1) * (c + 1)) for c in range(FULL_COLS)]
                       for r in range(FULL_K)], dtype=np.float32)
    # A_full = np.ones((FULL_ROWS, FULL_K), dtype=np.float32)
    # B_full = np.ones((FULL_K, FULL_COLS), dtype=np.float32)
    # Expected C: every element = 1024.0



    A_full = to_bf16_f32(A_full)
    B_full = to_bf16_f32(B_full)
    
    print("Done.")
    print()

    asm = f"""
        lui.s   $20, {TABLE_BASE >> 7} #lui.s instead of addi.s?? 
        #immediate lenght for addi.s -> 12 bits (0 to 4095) 

        lw.s    $3,  {OFF_B_SCPAD}($20)
        lw.s    $22, {OFF_A_SCPAD}($20)
        lw.s    $23, {OFF_C_SCPAD}($20)
        #use table PTR?
        lw.s    $11, {OFF_B_TABLE_PTR}($20)   # $11 =B
        lw.s    $12, {OFF_A_TABLE_PTR}($20)   # $12 =A
        lw.s    $13, {OFF_C_TABLE_PTR}($20)   # $13 =C
        lui.s   $14, {META_SID0 >> 7}
        lui.s   $15, {META_SID1 >> 7}
        
        lui.s   $6, 0
        addi.s  $6, $6, 0xf
        mv.stm  1, $6

        addi.s  $25, $0, 0
    j_loop:
        addi.s  $26, $0, 0
    k_loop:

        lw.s    $30, {OFF_NJ}($20)
        addi.s  $31, $0, 0
        addi.s  $8,  $0, 0
    mul_k_ncols:
        bge.s   $8,  $26, mul_k_ncols_done
        add.s   $31, $31, $30
        addi.s  $8,  $8,  1
        blt.s   $8,  $26, mul_k_ncols
    mul_k_ncols_done:
        add.s   $31, $31, $25
        add.s   $31, $31, $31
        add.s   $31, $31, $31
        add.s   $31, $31, $11
        lw.s    $2,  0($31)

        scpad.ld $3, $2, $14

        addi.s  $27, $0, 0
        lw.s    $28, {OFF_TILE_ROWS}($20)
    weights_loop:
        vreg.ld $10, $3,  {TILE_COLS}, {TILE_ROWS}, {SID0}, 1, $27
        lw.vi   $10, $10, 0, 0xf
        addi.s  $27, $27, 1
        blt.s   $27, $28, weights_loop

        addi.s  $29, $0, 0
    i_loop:

        lw.s    $30, {OFF_NK}($20)
        addi.s  $31, $0, 0
        addi.s  $8,  $0, 0
    mul_i_nk:
        bge.s   $8,  $29, mul_i_nk_done
        add.s   $31, $31, $30
        addi.s  $8,  $8,  1
        blt.s   $8,  $29, mul_i_nk
    mul_i_nk_done:
        add.s   $31, $31, $26
        add.s   $31, $31, $31
        add.s   $31, $31, $31
        add.s   $31, $31, $12
        lw.s    $21, 0($31)

        lw.s    $30, {OFF_NJ}($20)
        addi.s  $31, $0, 0
        addi.s  $8,  $0, 0
    mul_i_nj:
        bge.s   $8,  $29, mul_i_nj_done
        add.s   $31, $31, $30
        addi.s  $8,  $8,  1
        blt.s   $8,  $29, mul_i_nj
    mul_i_nj_done:
        add.s   $31, $31, $25
        add.s   $31, $31, $31
        add.s   $31, $31, $31
        add.s   $31, $31, $13
        lw.s    $24, 0($31)

        scpad.ld $22, $21, $14
        scpad.ld $23, $24, $15

        addi.s  $27, $0, 0
        lw.s    $30, {OFF_TILE_ROWS}($20)

    pipeline_loop:
        vreg.ld $4,  $22, {TILE_COLS}, {TILE_ROWS}, {SID0}, 1, $27
        vreg.ld $5,  $23, {TILE_COLS}, {TILE_ROWS}, {SID1}, 1, $27
        gemm.vv $6,  $4,  $5, 0, 0
        vreg.st $6,  $23, {TILE_COLS}, {TILE_ROWS}, {SID1}, 1, $27
        addi.s  $27, $27, 1
        blt.s   $27, $30, pipeline_loop

        scpad.st $23, $24, $15

        addi.s  $29, $29, 1
        lw.s    $30, {OFF_NI}($20)
        blt.s   $29, $30, i_loop

        addi.s  $26, $26, 1
        lw.s    $30, {OFF_NK}($20)
        blt.s   $26, $30, k_loop

        addi.s  $25, $25, 1
        lw.s    $30, {OFF_NJ}($20)
        blt.s   $25, $30, j_loop

        halt.s
    """

    if args.no_graph:
        instrs = assemble_file(asm)
        instr_text = emit_test_format(instrs)
    else:
        instr_text = emit_test_format_global_dag_pack(asm)
    # instrs     = assemble_file(asm)
    # instr_text = emit_test_format(instrs)

    img_table  = DRAMWriter()
    img_matrix = DRAMWriter()

    img_table.u32(TABLE_BASE + OFF_B_SCPAD,   B_SCPAD_ADDR)
    img_table.u32(TABLE_BASE + OFF_A_SCPAD,   A_SCPAD_ADDR)
    img_table.u32(TABLE_BASE + OFF_C_SCPAD,   C_SCPAD_ADDR)
    img_table.u32(TABLE_BASE + OFF_NJ,        NUM_TILE_COLS)
    img_table.u32(TABLE_BASE + OFF_NK,        NUM_TILE_K)
    img_table.u32(TABLE_BASE + OFF_NI,        NUM_TILE_ROWS)
    img_table.u32(TABLE_BASE + OFF_TILE_ROWS, TILE_ROWS)
    img_table.u32(TABLE_BASE + OFF_B_TABLE_PTR, TABLE_BASE + OFF_B_TABLE)
    img_table.u32(TABLE_BASE + OFF_A_TABLE_PTR, TABLE_BASE + OFF_A_TABLE)
    img_table.u32(TABLE_BASE + OFF_C_TABLE_PTR, TABLE_BASE + OFF_C_TABLE)

    for tk in range(NUM_TILE_K):
        for tj in range(NUM_TILE_COLS):
            idx = tk * NUM_TILE_COLS + tj
            img_table.u32(TABLE_BASE + OFF_B_TABLE + idx * 4,
                          B_GMEM_BASE + idx * TILE_BYTES)

    for ti in range(NUM_TILE_ROWS):
        for tk in range(NUM_TILE_K):
            idx = ti * NUM_TILE_K + tk
            img_table.u32(TABLE_BASE + OFF_A_TABLE + idx * 4,
                          A_GMEM_BASE + idx * TILE_BYTES)

    for ti in range(NUM_TILE_ROWS):
        for tj in range(NUM_TILE_COLS):
            idx = ti * NUM_TILE_COLS + tj
            img_table.u32(TABLE_BASE + OFF_C_TABLE + idx * 4,
                          C_GMEM_BASE + idx * TILE_BYTES)

    print("Writing B tiles...")
    for tk in range(NUM_TILE_K):
        for tj in range(NUM_TILE_COLS):
            idx       = tk * NUM_TILE_COLS + tj
            tile_base = B_GMEM_BASE + idx * TILE_BYTES
            r0 = tk * TILE_ROWS
            c0 = tj * TILE_COLS
            r_end = min(r0 + TILE_ROWS, FULL_K)
            c_end = min(c0 + TILE_COLS, FULL_COLS)
            rows_this = r_end - r0
            cols_this = c_end - c0
            B_slice = B_full[r0:r_end, c0:c_end] 

            BT = B_slice.T
            for r in range(cols_this):
                for c in range(rows_this):
                    img_matrix.bf16(tile_base + (r * TILE_COLS + c) * 2, float(BT[r, c]))    
    print("Done.")

    print("Writing A tiles...")
    for ti in range(NUM_TILE_ROWS):
        for tk in range(NUM_TILE_K):
            idx       = ti * NUM_TILE_K + tk
            tile_base = A_GMEM_BASE + idx * TILE_BYTES
            r0 = ti * TILE_ROWS
            c0 = tk * TILE_COLS
            r_end = min(r0 + TILE_ROWS, FULL_ROWS)
            c_end = min(c0 + TILE_COLS, FULL_K)
            rows_this = r_end - r0
            cols_this = c_end - c0
            AT = A_full[r0:r_end, c0:c_end]
            for r in range(rows_this):
                for c in range(cols_this):
                    img_matrix.bf16(tile_base + (r * TILE_COLS + c) * 2, float(AT[r, c]))
    print("Done.")

    print("Zero-initialising C tiles...")
    for idx in range(NUM_TILE_ROWS * NUM_TILE_COLS * TILE_ROWS * TILE_COLS):
        img_matrix.bf16(C_GMEM_BASE + idx * 2, 0.0)
    print("Done.")

    table_words  = img_table.to_u32_words(include_zeros=True, stride=4)
    matrix_words = img_matrix.to_u32_words(include_zeros=True, stride=2)
    all_words    = {**table_words, **matrix_words}
    data_text    = "\n".join(f"{addr:08X}: {val:08X}"
                             for addr, val in sorted(all_words.items()))
    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
        print(f"\nWrote {args.output}")
    else:
        print(final)


if __name__ == "__main__":
    main()