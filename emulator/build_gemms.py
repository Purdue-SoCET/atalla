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



def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path('gemms.in'), help="Output test file")
    args = ap.parse_args()


    TILE_ADDR_LOCATION = 60

    WEIGHT_GMEM_ADDR = 0x100   # Tile B (weights)
    INPUT_GMEM_ADDR  = 0x500   # Tile A (inputs)
    OUTPUT_GMEM_ADDR = 0x1000  # Tile C (accumulator / output)

    WEIGHT_SCPAD_ADDR = 0
    INPUT_SCPAD_ADDR  = 100
    OUTPUT_SCPAD_ADDR = 200

    COLS = 4
    ROWS = 4
    SID0 = 0
    SID1 = 1


    asm = f"""
        # $20 = table base = 0x3C
        lui.s   $20, 0
        addi.s  $20, $0, {TILE_ADDR_LOCATION}

        # Load weight tile descriptors
        lw.s    $2, 0($20)          # WEIGHT_GMEM_ADDR
        lw.s    $3, 4($20)          # WEIGHT_SCPAD_ADDR -> $3 = 0

        scpad.ld $3, $2, {COLS}, {ROWS}, {SID0}


        #for new way of handling rc_id
        addi.s  $27, $0, 0


        # Load weights into systolic array rows 0-3
        lui.s   $6, 0
        addi.s  $6, $6, 0xf
        mv.stm  1, $6
        # vreg.ld $10, $3, {COLS}, {ROWS}, {SID0}, 1, 0
        vreg.ld $10, $3, {COLS}, {ROWS}, {SID0}, 1, $27
        lw.vi   $10, $10, 0, 0

        addi.s  $27, $0, 1
        # vreg.ld $11, $3, {COLS}, {ROWS}, {SID0}, 1, 1
        vreg.ld $11, $3, {COLS}, {ROWS}, {SID0}, 1, $27
        lw.vi   $11, $11, 0, 0

        addi.s  $27, $0, 2
        # vreg.ld $12, $3, {COLS}, {ROWS}, {SID0}, 1, 2
        vreg.ld $12, $3, {COLS}, {ROWS}, {SID0}, 1, $27
        lw.vi   $12, $12, 0, 0

        addi.s  $27, $0, 3
        # vreg.ld $13, $3, {COLS}, {ROWS}, {SID0}, 1, 3
        vreg.ld $13, $3, {COLS}, {ROWS}, {SID0}, 1, $27
        lw.vi   $13, $13, 0, 0

        # Load input tile A
        lw.s    $2, 8($20)          # INPUT_GMEM_ADDR
        lw.s    $21, 12($20)        # INPUT_SCPAD_ADDR  -- save in $21

        scpad.ld $21, $2, {COLS}, {ROWS}, {SID0}

        # Load output tile C
        lw.s    $24, 16($20)        # OUTPUT_GMEM_ADDR -- save in $24 (never used as vreg)
        lw.s    $23, 20($20)        # OUTPUT_SCPAD_ADDR -- save in $23


        scpad.ld $23, $24, {COLS}, {ROWS}, {SID1}


        # Compute: C[i] = A[i] * W + C[i] for each row

        # Row 0
        addi.s  $27, $0, 0                # rc_id = 0
        vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, $27  # A row 0
        vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, $27  # C row 0
        # vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, 0  # A row 0
        # vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, 0  # C row 0
        gemm.vv $6, $4, $5, 0, 0                       # C0 = A0 * W0 + C0
        # vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, 0
        vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, $27


        # Row 1
        addi.s  $27, $0, 1                # rc_id = 1
        vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, $27  # A row 1
        vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, $27  # C row 1
        # vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, 1
        # vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, 1
        gemm.vv $6, $4, $5, 0, 0                       # C1 = A1 * W0 + C1
        # vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, 1
        vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, $27


        # Row 2
        addi.s  $27, $0, 2                # rc_id = 2
        vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, $27  # A row 2
        vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, $27  # C row 2
        # vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, 2
        # vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, 2
        gemm.vv $6, $4, $5, 0, 0                       # C2 = A2 * W0 + C2
        # vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, 2
        vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, $27


        # Row 3
        addi.s  $27, $0, 3                # rc_id = 3
        vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, $27  # A row 3
        vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, $27  # C row 3
        # vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, 3
        # vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, 3
        gemm.vv $6, $4, $5, 0, 0                       # C3 = A3 * W0 + C3
        # vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, 3
        vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, $27



        # Store output tile back to gmem
        scpad.st $23, $24, {COLS}, {ROWS}, {SID1}

        halt.s
    """

    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()

    # Weight tile
    img.u32(0x3c, WEIGHT_GMEM_ADDR)
    img.u32(0x40, WEIGHT_SCPAD_ADDR)

    # Input tile
    img.u32(0x44, INPUT_GMEM_ADDR)
    img.u32(0x48, INPUT_SCPAD_ADDR)

    # Output tile
    img.u32(0x4c, OUTPUT_GMEM_ADDR)
    img.u32(0x50, OUTPUT_SCPAD_ADDR)

    # ===== Tile B (Weights) =====
    for i in range(16):
        img.bf16(WEIGHT_GMEM_ADDR + i * 2, 1.0)

    # ===== Tile A (Inputs) =====
    for i in range(16):
        img.bf16(INPUT_GMEM_ADDR + i * 2, 1.0)

    # ===== Tile C (Output accumulator) =====
    for i in range(16):
        img.bf16(OUTPUT_GMEM_ADDR + i * 2, 0.0)

    data_text = img.render_data_mem(include_zeros=True)

    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
    else: 
        print(final)

if __name__ == "__main__":
    main()