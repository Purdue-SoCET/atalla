from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, List, Union
import struct
import os
import sys, re 
from pathlib import Path
import argparse
import numpy as np

from .build import *


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input", type=Path, default=None, help="Input assembly file")
    ap.add_argument("-o", "--output", type=Path, default='./tests/layernorm.in', help="Output test file")
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
    SCPAD_ADDR = 1
    EPSILON_LOCATION = 20
    INV_LAYER_ELEMS_LOCATION = 24
    COLS = N
    ROWS = N
    SID = 0
    LAYER_ELEMS = N * N
    RSUM_IMM = 64
    
    #
    # ScalarConvention: 
    # 1     holds address of gmem base address 
    # 2     holds gmem base address
    # 3     holds scratchpad base address
    # 4     holds epsilon stability constant
    # 5     holds epsilon address
    # 10-13 holds the original rows
    # 20-23 hold partial sums
    # 30-33 hold normalized numerator
    # 34-37 hold variance calculations
    # 38    holds variance
    # 39    holds normalized denominator
    
    asm = f"""
    
        lui.s    $1, 0                              # load 0 into $1
        addi.s   $1, $0, {TILE_ADDR_LOCATION}       # load tile/scpad address table location into $1
        lw.s     $2, 0($1)                          # load gmem tile base address into $2
        lw.s     $3, 4($1)                          # load scratchpad tile base address into $3

        scpad.ld $3, $2, {COLS}, {ROWS}, {SID}      # load 4x4 tile from gmem to scratchpad

        addi.s   $5, $0, {EPSILON_LOCATION}         # load epsilon location into $5
        lw.s     $4, 0($5)                          # load epsilon into $4
        addi.s   $14, $0, {INV_LAYER_ELEMS_LOCATION} # load inv(N^2) location into $14
        lw.s     $14, 0($14)                        # load inv(N^2) as fp32 bit-pattern

        lui.s    $6, 0x00000                    # load upper 25 bit mask of all 1's into $6
        addi.s   $6, $6, 0xf                        # add lower bit mask of all 1's into $6
        mv.stm   1, $6                              # load '1 into mask 1
        
        vreg.ld  $10, $3, {COLS}, {ROWS}, {SID}, 1, 0  # load row 0 into $10
        vreg.ld  $11, $3, {COLS}, {ROWS}, {SID}, 1, 1  # load row 1 into $11
        vreg.ld  $12, $3, {COLS}, {ROWS}, {SID}, 1, 2  # load row 2 into $12
        vreg.ld  $13, $3, {COLS}, {ROWS}, {SID}, 1, 3  # load row 3 into $13
        
        rsum.vi  $20, $10, {RSUM_IMM}, 1                    # reduce row 0 -> partial sum 0, imm = 1 << 6
        rsum.vi  $21, $11, {RSUM_IMM}, 1                    # reduce row 1 -> partial sum 1, imm = 1 << 6
        rsum.vi  $22, $12, {RSUM_IMM}, 1                    # reduce row 2 -> partial sum 2, imm = 1 << 6
        rsum.vi  $23, $13, {RSUM_IMM}, 1                    # reduce row 3 -> partial sum 3, imm = 1 << 6
        
        add.vv   $21, $20, $21, 1, 0                # partial sum 0 + partial sum 1
        add.vv   $22, $22, $23, 1, 0                # partial sum 2 + partial sum 3
        add.vv   $24, $21, $22, 1, 0                # layer mean sum in $24

        mul.vs   $24, $24, $14, 1                   # layer mean sum * inv(N^2) -> final mean in $24

        sub.vv   $30, $10, $24, 1, 0                # normalized numerator row 0 = row 0 - mean
        sub.vv   $31, $11, $24, 1, 0                # normalized numerator row 1 = row 1 - mean
        sub.vv   $32, $12, $24, 1, 0                # normalized numerator row 2 = row 2 - mean
        sub.vv   $33, $13, $24, 1, 0                # normalized numerator row 3 = row 3 - mean

        mul.vv   $34, $30, $30, 1, 0                # row variance contribution for row 0
        mul.vv   $35, $31, $31, 1, 0                # row variance contribution for row 1
        mul.vv   $36, $32, $32, 1, 0                # row variance contribution for row 2
        mul.vv   $37, $33, $33, 1, 0                # row variance contribution for row 3

        rsum.vi  $34, $34, {RSUM_IMM}, 1                    # reduce row variance contribution 0
        rsum.vi  $35, $35, {RSUM_IMM}, 1                    # reduce row variance contribution 1
        rsum.vi  $36, $36, {RSUM_IMM}, 1                    # reduce row variance contribution 2
        rsum.vi  $37, $37, {RSUM_IMM}, 1                    # reduce row variance contribution 3

        add.vv   $35, $34, $35, 1, 0                # partial variance pair 0+1
        add.vv   $37, $36, $37, 1, 0                # partial variance pair 2+3
        add.vv   $38, $35, $37, 1, 0                # variance sum in $38
        
        mul.vs   $39, $38, $14, 1                   # variance sum * inv(N^2) -> final variance in $39

        add.vs   $39, $39, $4, 1                    # denominator seed = variance + epsilon
        sqrti.vi $39, $39, 0, 1                     # denominator = sqrt(denominator seed) -> normalized denominator in $39

        vmov.vts $15, $39, 0                        # extract denominator lane 0 to scalar
        rcp.bf   $15, $15, $0                       # reciprocal(denominator)

        mul.vs   $30, $30, $15, 1                   # normalized row 0 * reciprocal(denominator)
        mul.vs   $31, $31, $15, 1                   # normalized row 1 * reciprocal(denominator)
        mul.vs   $32, $32, $15, 1                   # normalized row 2 * reciprocal(denominator)
        mul.vs   $33, $33, $15, 1                   # normalized row 3 * reciprocal(denominator)

        vreg.st  $30, $3, {COLS}, {ROWS}, {SID}, 1, 0  # store normalized row 0 to scratchpad
        vreg.st  $31, $3, {COLS}, {ROWS}, {SID}, 1, 1  # store normalized row 1 to scratchpad
        vreg.st  $32, $3, {COLS}, {ROWS}, {SID}, 1, 2  # store normalized row 2 to scratchpad
        vreg.st  $33, $3, {COLS}, {ROWS}, {SID}, 1, 3  # store normalized row 3 to scratchpad

        scpad.st $3, $2, {COLS}, {ROWS}, {SID}      # store normalized 4x4 tile back to gmem

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
    img.u32(TILE_ADDR_LOCATION, TILE_ADDR) # Place tile base address at address 67
    img.u32(SCPAD_ADDR_LOCATION, SCPAD_ADDR)
    img.f32(EPSILON_LOCATION, 0)
    img.f32(INV_LAYER_ELEMS_LOCATION, float(1.0 / LAYER_ELEMS))
    #-----------TILE INITIALIZATION----------
    base_addr = TILE_ADDR
    if args.data is not None:
        tile_values = load_tile_data(args.data, N)
    else:
        tile_values = [float(v) for v in range(4, 4 + N * N)]
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
    
