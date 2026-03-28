from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, List, Union
import struct
import os
import sys, re 
from pathlib import Path
import argparse
import numpy as np

from build import *

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input", type=Path, default=None, help="Input assembly file")
    ap.add_argument("-o", "--output", type=Path, default='./layernorm.in', help="Output test file")
    ap.add_argument("--no-graph", action="store_true", help="Disable dependency graph packet scheduling")
    ap.add_argument("--data", type=Path, default=None,
                    help="Path to input tile CSV data file (N×N). If omitted, uses hardcoded defaults.")
    ap.add_argument("--n", type=int, default=4,
                    help="Tile dimension N for an N×N tile (default: 4)")
    args = ap.parse_args()

    N = args.n

    TILE_ADDR_LOCATION = 60 # 0x3c
    SCPAD_ADDR_LOCATION = TILE_ADDR_LOCATION + 4
    TILE_ADDR = 0xcafa
    SCPAD_ADDR = 0
    EPSILON_LOCATION = 20
    INV_LAYER_ELEMS_LOCATION = 24
    MAX_COL_IND = N - 1
    MAX_ROW_IND = N - 1
    SID = 0
    LAYER_ELEMS = N * N
    RSUM_IMM = 64
    MASK_VAL = (1 << N) - 1
    
    #
    # ScalarConvention:
    # 1     holds address of gmem base address
    # 2     holds gmem base address
    # 3     holds scratchpad base address
    # 4     holds epsilon stability constant
    # 5     holds epsilon address
    # 6     holds lane-enable bit mask
    # 7     holds loop counter (i)
    # 8     holds N (loop bound)
    # 9     holds previous row index (for pipelined store)
    # Vector Convention:
    # $10   current row data (reused across iterations)
    # $11   rsum partial / temp
    # $12   squared diff / temp
    # $20   mean accumulator (row-sum total)
    # $24   final mean (broadcast across lanes)
    # $30   row diff (row - mean) / normalized result
    # $38   variance accumulator
    # $39   normalized denominator
    
    asm = f"""
        
        addi.s   $1, $0, {TILE_ADDR_LOCATION}       # load tile/scpad address table location into $1
        lw.s     $2, 0($1)                           # load gmem tile base address into $2
        lw.s     $3, 4($1)                           # load scratchpad tile base address into $3

        scpad.ld $3, $2, {MAX_COL_IND}, {MAX_ROW_IND}, {SID}       # load NxN tile from gmem to scratchpad
        
        addi.s   $5, $0, {EPSILON_LOCATION}          # load epsilon address into $5
        lw.s     $4, 0($5)                           # load epsilon into $4
        addi.s   $14, $0, {INV_LAYER_ELEMS_LOCATION} # load inv(N^2) location into $14
        lw.s     $14, 0($14)                         # load inv(N^2) as fp32 bit-pattern

        lui.s    $6, {MASK_VAL >> 7}
        addi.s   $6, $6, {MASK_VAL & 0x7f}
        mv.stm   1, $6                               # write mask into mask register 1

        addi.s   $8, $0, {N}                         # load loop bound N into $8

        ############## PHASE 1: MEAN (pipelined) ##############
        sub.vv   $20, $20, $20, 1, 0                 # zero mean accumulator
        addi.s   $7, $0, 0                            # i = 0
        vreg.ld  $10, $3, {MAX_COL_IND}, {MAX_ROW_IND}, {SID}, 1, $7  # fetch row 0, store in $10
        addi.s   $7, $7, 1                            # i += 1
        bge.s    $7, $8, MEAN_DONE                    # skip loop if N == 1
    MEAN_LOOP:
        rsum.vi  $11, $10, {RSUM_IMM}, 1              # reduction sum row i - 1
        vreg.ld  $10, $3, {MAX_COL_IND}, {MAX_ROW_IND}, {SID}, 1, $7  # load row i (pipelined with rsum)
        add.vv   $20, $20, $11, 1, 0                  # accumulate partial sum of row i - 1
        addi.s   $7, $7, 1                             # i += 1
        blt.s    $7, $8, MEAN_LOOP                     # loop while i < N

    MEAN_DONE:
        rsum.vi  $11, $10, {RSUM_IMM}, 1              # reduce last row
        add.vv   $20, $20, $11, 1, 0                  # accumulate last partial sum
        mul.vs   $24, $20, $14, 1                      # mean = total_sum * inv(N^2)

        ############## PHASE 2: VARIANCE (pipelined) ##############
        sub.vv   $38, $38, $38, 1, 0                  # zero variance accumulator
        addi.s   $7, $0, 0                             # i = 0
        vreg.ld  $10, $3, {MAX_COL_IND}, {MAX_ROW_IND}, {SID}, 1, $7  # prefetch row 0
        sub.vv   $30, $10, $24, 1, 0                   # diff = row 0 - mean
        addi.s   $7, $7, 1                              # i = 1
        bge.s    $7, $8, VAR_DONE                       # skip loop if N == 1
    VAR_LOOP:
        mul.vv   $12, $30, $30, 1, 0                   # square previous diff
        vreg.ld  $10, $3, {MAX_COL_IND}, {MAX_ROW_IND}, {SID}, 1, $7  # load row i (pipelined)
        rsum.vi  $12, $12, {RSUM_IMM}, 1                # reduce squared diff
        sub.vv   $30, $10, $24, 1, 0                    # diff = row i - mean (pipelined)
        add.vv   $38, $38, $12, 1, 0                    # accumulate variance
        addi.s   $7, $7, 1                               # i++
        blt.s    $7, $8, VAR_LOOP                        # loop while i < N

    VAR_DONE:
        mul.vv   $12, $30, $30, 1, 0                   # square last diff
        rsum.vi  $12, $12, {RSUM_IMM}, 1                # reduce last squared diff
        add.vv   $38, $38, $12, 1, 0                    # accumulate last variance contribution
        mul.vs   $39, $38, $14, 1                        # variance = sum * inv(N^2)
        add.vs   $39, $39, $4, 1                         # add epsilon for stability
        sqrti.vi $39, $39, 0, 1                          # denominator = sqrt(variance + epsilon)

        vmov.vts $15, $39, 0                             # extract denominator lane 0 to scalar
        rcp.bf   $15, $15, $0                            # reciprocal(denominator)

        ############## PHASE 3: NORMALIZE + STORE (pipelined) ##############
        addi.s   $7, $0, 0                              # i = 0
        vreg.ld  $10, $3, {MAX_COL_IND}, {MAX_ROW_IND}, {SID}, 1, $7  # load row 0
        sub.vv   $30, $10, $24, 1, 0                     # row 0 - mean
        mul.vs   $30, $30, $15, 1                        # normalize row 0 via reciprocal multiply
        addi.s   $7, $7, 1                                # i = 1
        bge.s    $7, $8, NORM_DONE                        # skip loop if N == 1
    NORM_LOOP:
        vreg.ld  $10, $3, {MAX_COL_IND}, {MAX_ROW_IND}, {SID}, 1, $7   # load row i (pipelined)
        subi.s   $9, $7, 1                                # prev = i - 1
        vreg.st  $30, $3, {MAX_COL_IND}, {MAX_ROW_IND}, {SID}, 1, $9   # store prev normalized row (pipelined)
        sub.vv   $30, $10, $24, 1, 0                      # row i - mean
        mul.vs   $30, $30, $15, 1                         # normalize row i via reciprocal multiply
        addi.s   $7, $7, 1                                 # i++
        blt.s    $7, $8, NORM_LOOP                         # loop while i < N

    NORM_DONE:
        subi.s   $9, $7, 1                                # prev = N - 1
        vreg.st  $30, $3, {MAX_COL_IND}, {MAX_ROW_IND}, {SID}, 1, $9   # store last normalized row

        scpad.st $3, $2, {MAX_COL_IND}, {MAX_ROW_IND}, {SID}            # store NxN tile back to gmem

        halt.s
    """

    instrs = assemble_file(asm)         

    if args.no_graph:
        instr_text = emit_test_format(instrs)
    else:
        dependency_instrs = convert_instructions(instrs)
        ready = build_dependency_graph(dependency_instrs, DEFAULT_LATENCY_MAP)
        packets = greedy_pack(dependency_instrs, ready, max_width=GRAPH_PACKET_WIDTH)
        scheduled = materialize_scheduled_instructions(
            instrs,
            packets,
            packet_width=GRAPH_PACKET_WIDTH,
        )
        instr_text = emit_test_format(
            scheduled,
            virtual_packet_size=GRAPH_PACKET_WIDTH,
        )

    
    img = DRAMWriter() 
    #-----------DEFAULT ADDRESS INITIALIZATIONS--------
    img.u32(TILE_ADDR_LOCATION, TILE_ADDR) # Place tile base address at address 0x3c
    img.u32(SCPAD_ADDR_LOCATION, SCPAD_ADDR)
    img.f32(EPSILON_LOCATION, 0)
    img.f32(INV_LAYER_ELEMS_LOCATION, float(1.0 / LAYER_ELEMS))
    #-----------TILE INITIALIZATION----------
    base_addr = TILE_ADDR
    if args.data is not None:
        tile_values = load_tile_data(args.data, N)
    else:
        tile_values = [float(v) for v in range(N * N)]
    for i, val in enumerate(tile_values):
        addr = base_addr + (i * 2)
        img.bf16(addr, float(val))
    # -----------------------------------------
    
    
    data_text = img.render_data_mem(include_zeros=False)
    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
    else: 
        print(final)

if __name__ == "__main__":
    main()
    
