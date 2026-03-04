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

    WEIGHT_GMEM_ADDR  = 0x1000  
    INPUT_GMEM_ADDR   = 0x2000   
    OUTPUT_GMEM_ADDR  = 0x5000  

    WEIGHT_SCPAD_ADDR = 0
    INPUT_SCPAD_ADDR  = 1024
    OUTPUT_SCPAD_ADDR = 2048

    COLS      = 31   #for 32x32 cause it's 0 to 31
    ROWS      = 31
    SID0      = 0
    SID1      = 1

    # Number of input tiles 
    NUM_TILES     = 3
    # Each tile is ROWS*COLS bf16 values (bf16 is half-precision)
    TILE_BYTES    = ROWS * COLS * 2   # bytes/input tile



    
    # math:
    # weights -> all 1.0
    # tile0 -> all 1.0
    # tile1 -> all 2.0
    # tile2 -> all 3.0

    # 1row in 1tile =  (1*1)+(1*1)+(1*1)+(1*1) = 4.0
    # after tile 0, C = 4.0
    # after tile 1, C = 4.0 + (1*2)+(1*2)+(1*2)+(1*2) = 4.0 + 8.0 = 12.0
    # after tile 2, C = 12.0 + (1*3)+(1*3)+(1*3)+(1*3) = 12.0 + 12.0 = 24.0
    

    # 41c0 -> 0100 0001 1100 0000
    # sign bit -> 0 ->positive
    # exponent -> 10000011 -> 131 - 127(bias) = 4 -> 2^4 = 16
    # mantissa -> 1000000 -> 1.1 -> 1.5
    # value = 1.5 * 16 = 24.0 -> 0x41c0 


    asm = f"""
        # (scalar):
        #   $20  = tile descriptor table base
        #   $2   = current INPUT_GMEM_ADDR 
        #   $3   = WEIGHT_SCPAD_ADDR
        #   $21  = INPUT_SCPAD_ADDR
        #   $23  = OUTPUT_SCPAD_ADDR
        #   $24  = OUTPUT_GMEM_ADDR
        #   $25  = tile loop counter (0 .. NUM_TILES-1)
        #   $26  = tile loop limit   (= NUM_TILES)

        #  (vector ):
        #   $10..$13 = weight vregs for systolic rows 0..3 
        #   $4 = input vreg A[silce]  
        #   $5  = output vreg C[slice] 
        #   $6 = gemm result vreg  
        #
        # per-row vreg.ld / gemm.vv / vreg.st -> not looped yet? -> rc_id is static imm?
        # 

        lui.s   $20, 0
        addi.s  $20, $0, {TILE_ADDR_LOCATION}   
                  

        lw.s    $2,  0($20)                     
        lw.s    $3,  4($20)                    
        lw.s    $2,  8($20)                     
        lw.s    $21, 12($20)                   
        lw.s    $24, 16($20)                    
        lw.s    $23, 20($20)                 

        #weights
        lw.s    $6,  0($20)                     # $6  = WEIGHT_GMEM_ADDR
        scpad.ld $3, $6, {COLS}, {ROWS}, {SID0}

        #mask
        lui.s   $6, 0xffff
        addi.s  $6, $6, 0xffff
        mv.stm  1, $6


        #weight load
        # vreg.ld $10, $3, {COLS}, {ROWS}, {SID0}, 1, 0   # weight rc_id=$0 -> vreg $10
        # lw.vi   $10, $10, 0, 0                           # load vreg $10 into systolic row 0

        # vreg.ld $11, $3, {COLS}, {ROWS}, {SID0}, 1, 1   # weight rc_id=$1 -> vreg $11
        # lw.vi   $11, $11, 0, 0                           # load vreg $11 into systolic row 1

        # vreg.ld $12, $3, {COLS}, {ROWS}, {SID0}, 1, 2   # weight rc_id=$2 -> vreg $12
        # lw.vi   $12, $12, 0, 0                           # load vreg $12 into systolic row 2

        # vreg.ld $13, $3, {COLS}, {ROWS}, {SID0}, 1, 3   # weight rc_id=$3 -> vreg $13
        # lw.vi   $13, $13, 0, 0                           # load vreg $13 into systolic row 3

        addi.s  $27, $0, 0                #  rc_id counter
        addi.s  $28, $0, {ROWS}           # Row limit 

weight_load_loop:
        # Load specific row (rc_id) from scratchpad into vreg
        vreg.ld $10, $3, {COLS}, {ROWS}, {SID0}, 1, $27
        
        lw.vi   $10, $10, 0, 0            
        
        addi.s  $27, $27, 1
        blt.s   $27, $28, weight_load_loop


        #tile C
        scpad.ld $23, $24, {COLS}, {ROWS}, {SID1}

        # tile loop:  for tile = 0; tile < NUM_TILES; tile++
        #
        #   - current input tile A (at $2) -> scratchpad
        #   - compute
        #   - next input tile


        addi.s  $25, $0, 0                      # $25 = tile counter = 0
        addi.s  $26, $0, {NUM_TILES}            # $26 = loop limit

tile_loop:

        scpad.ld $21, $2, {COLS}, {ROWS}, {SID0}

        # vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, 0   # A[rc_id=0] -> vreg $4
        # vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, 0   # C[rc_id=0] -> vreg $5
        # gemm.vv $6, $4, $5, 0, 0                        # vreg $6 = A[0]*W + C[0]
        # vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, 0   # vreg $6 -> C[rc_id=0]

        # vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, 1   # A[rc_id=1] -> vreg $4
        # vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, 1   # C[rc_id=1] -> vreg $5
        # gemm.vv $6, $4, $5, 0, 0                        # vreg $6 = A[1]*W + C[1]
        # vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, 1   # vreg $6 -> C[rc_id=1]

        # vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, 2   # A[rc_id=2] -> vreg $4
        # vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, 2   # C[rc_id=2] -> vreg $5
        # gemm.vv $6, $4, $5, 0, 0                        # vreg $6 = A[2]*W + C[2]
        # vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, 2   # vreg $6 -> C[rc_id=2]

        # vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, 3   # A[rc_id=3] -> vreg $4
        # vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, 3   # C[rc_id=3] -> vreg $5
        # gemm.vv $6, $4, $5, 0, 0                        # vreg $6 = A[3]*W + C[3]
        # vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, 3   # vreg $6 -> C[rc_id=3]

        # dynamic row loop using register rc_id
        addi.s $27, $0, 0               # rc_id counter = 0
        addi.s $28, $0, {ROWS}          # row limit = 4

        row_loop:
            vreg.ld $4, $21, {COLS}, {ROWS}, {SID0}, 1, $27
            vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, $27
            gemm.vv $6, $4, $5, 0, 0
            vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, $27
            addi.s $27, $27, 1
            blt.s  $27, $28, row_loop

        #nextt tile
        addi.s  $2, $2, {TILE_BYTES}

        #branch to tile_loop 
        bne.s   $25, $26, tile_loop, 1

        scpad.st $23, $24, {COLS}, {ROWS}, {SID1}

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

    for i in range(ROWS * COLS):
        img.bf16(WEIGHT_GMEM_ADDR + i * 2, 1.0)

    for t in range(NUM_TILES):
        base = INPUT_GMEM_ADDR + t * TILE_BYTES
        for i in range(ROWS * COLS):
            img.bf16(base + i * 2, float(t + 1))

    for i in range(ROWS * COLS):
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