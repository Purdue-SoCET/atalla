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
    ap.add_argument("-o", "--output", type=Path, default=Path('gemms.in'), help="Output test file")
    args = ap.parse_args()

    N = 32
    SDMA_IDX = N - 1
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

    TILE_BYTES = N * N * 2


    asm = f"""
        lui.s   $20, 0
        addi.s  $20, $0, {TILE_ADDR_LOCATION}


        lw.s    $2, 0($20)   # Weight GMEM
        lw.s    $3, 4($20)   # Weight SCPAD
        lw.s    $21, 8($20)  # Input GMEM
        lw.s    $22, 12($20) # Input SCPAD
        lw.s    $24, 16($20) # Output GMEM
        lw.s    $23, 20($20) # Output SCPAD

        scpad.ld $3, $2, {SDMA_IDX}, {SDMA_IDX}, {SID0}

        lui.s   $6, 0
        addi.s  $6, $6, 0xf
        mv.stm  1, $6

        addi.s  $27, $0, 0
        addi.s  $28, $0, {N}
        
    weights_loop:
        vreg.ld $10, $3, {SDMA_IDX}, {SDMA_IDX}, {SID0}, 1, $27
        lw.vi   $10, $10, 0, 0xf
        addi.s  $27, $27, 1
        blt.s   $27, $28, weights_loop

        # Initial Tile Loads
        scpad.ld $22, $21, {SDMA_IDX}, {SDMA_IDX}, {SID0}
        scpad.ld $23, $24, {SDMA_IDX}, {SDMA_IDX}, {SID1}   

        addi.s  $25, $0, 0
        addi.s  $29, $0, {NUM_TILES}

    tile_loop:
        #prefetch
        addi.s  $27, $0, 0         #row counter = 0
        vreg.ld $4, $22, {SDMA_IDX}, {SDMA_IDX}, {SID0}, 1, $27     #grp 1
        vreg.ld $5, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $27
        
        addi.s  $28, $0, 1           #next row counter  = 1
        addi.s  $26, $0, {N}      

pipeline_loop:
        # 1. Start GEMM on Row N (group 1)
        gemm.vv $6, $4, $5, 0, 0
        
        # 2. Check if we need to prefetch Row N+1 into group 2 (overlapping with GEMM on Row N)
        bge.s   $28, $26, skip_fetch_2    #isnext row counter past row limit?
        vreg.ld $14, $22, {SDMA_IDX}, {SDMA_IDX}, {SID0}, 1, $28    
        vreg.ld $15, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $28

    skip_fetch_2:

        # 3. Store Result of Row N (Stalls for GEMM)
        vreg.st $6, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $27
        
        # 4. next row
        addi.s  $27, $27, 1         
        addi.s  $28, $28, 1          
        
        # 5. Check if we are done and all rows finished 
        bge.s   $27, $26, pipeline_done

        # 6. Start GEMM on Row N+1 (grup 2) while Row N is still computing (group 1)
        gemm.vv $6, $14, $15, 0, 0

        # 7. Check if we need to prefetch Row N+2 into group 1
        bge.s   $28, $26, skip_fetch_1
        vreg.ld $4, $22, {SDMA_IDX}, {SDMA_IDX}, {SID0}, 1, $28
        vreg.ld $5, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $28

    skip_fetch_1:

        # 8. Store Result of Row N+1
        vreg.st $6, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $27
        
        # 9. Final loop
        addi.s  $27, $27, 1
        addi.s  $28, $28, 1
        blt.s   $27, $26, pipeline_loop

    pipeline_done:
        addi.s  $25, $25, 1
        bge.s   $25, $29, tile_loop_done
        addi.s  $21, $21, {TILE_BYTES}
        scpad.ld $22, $21, {SDMA_IDX}, {SDMA_IDX}, {SID0}
        blt.s   $25, $29, tile_loop

    tile_loop_done:
        scpad.st $23, $24, {SDMA_IDX}, {SDMA_IDX}, {SID1}

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

    W = np.array([[float(r + c) for c in range(N)] for r in range(N)])
    WT = W.T
    for r in range(N):
        for c in range(N):
            img.bf16(WEIGHT_GMEM_ADDR + (r * N + c) * 2, float(WT[r, c]))

    for t in range(NUM_TILES):
        base = INPUT_GMEM_ADDR + t * TILE_BYTES
        for r in range(N):
            for c in range(N):
                img.bf16(base + (r * N + c) * 2, float((r + 1) * (t + 1)))

    for i in range(N * N):
        img.bf16(OUTPUT_GMEM_ADDR + i * 2, 0.0)

    # expected
    col_sums = W.sum(axis=0)
    tile_sum = sum(t + 1 for t in range(NUM_TILES))
    base_row = col_sums * float(tile_sum)
    print("Expected C (Row-Major):")
    C_expected = np.zeros((N, N))
    for r in range(N):
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
    for c in range(N):
        bank_hex = []
        for r in range(N):
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