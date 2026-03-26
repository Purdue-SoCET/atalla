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


def load_tile_data(data_path: Path, n: int) -> list:
    tile = np.loadtxt(data_path, delimiter=',')
    if tile.ndim == 1:
        tile = tile.reshape(1, -1)
    if tile.shape != (n, n):
        raise ValueError(f"Tile shape mismatch: expected ({n}, {n}), got {tile.shape}.")
    return tile.flatten(order='C').tolist()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input",  type=Path, default=None)
    ap.add_argument("-o", "--output", type=Path, default="./tests/attention.in")
    ap.add_argument("--no-graph", action="store_true")
    ap.add_argument("--data", type=Path, default=None)
    ap.add_argument("--n", type=int, default=4)
    args = ap.parse_args()

    N = args.n


    ADDR_TABLE_BASE  = 0x0000_0040
    EPSILON_LOCATION = 0x0000_0020

    TILE_ADDR_INPUT  = 0x0000_1000
    TILE_ADDR_Q      = 0x0000_2000
    TILE_ADDR_K      = 0x0000_3000
    TILE_ADDR_V      = 0x0000_4000
    TILE_ADDR_OUTPUT = 0x0000_5000
    TILE_ADDR_W      = 0x0000_6000
    TILE_ADDR_B      = 0x0000_7000
    TILE_ADDR_ATTN   = 0x0000_8000

    SCPAD_ADDR       = 1   # scratchpad base row index (loaded into $3)

    COLS        = N
    ROWS        = N
    SID0        = 0
    SID1        = 1
    LAYER_ELEMS = N * N
    RSUM_IMM    = 64



#bunch of python to cross check
    input_values = [float(v) for v in range(4, 4 + N * N)]
    X_ref = np.array(input_values, dtype=np.float32).reshape(N, N)


    mean    = X_ref.mean()
    var     = X_ref.var()
    ln_out  = (X_ref - mean) / np.sqrt(var + 1e-5)

    Q = np.array([[1,1,1,1],[1,2,1,1],[1,1,3,1],[1,1,1,4]], dtype=np.float32)
    K = np.array([[1,0,0,0],[0,2,0,0],[0,0,3,0],[0,0,0,4]], dtype=np.float32)
    V = np.array([[10,0,0,0],[0,20,0,0],[0,0,30,0],[0,0,0,40]], dtype=np.float32)

    scores   = (Q @ K.T) / np.sqrt(N)
    s_exp    = np.exp(scores - scores.max(axis=1, keepdims=True))
    s_soft   = s_exp / s_exp.sum(axis=1, keepdims=True)
    attn_ref = s_soft @ V


    residual  = attn_ref + X_ref
    relu_out  = np.maximum(0, residual)


    W = np.array([
        [0.1, 0.5, 0.3, 0.8],
        [0.6, 0.2, 0.7, 0.1],
        [0.4, 0.9, 0.2, 0.5],
        [0.8, 0.3, 0.6, 0.2],
    ], dtype=np.float32)
    WT = W.T

    linear_out  = relu_out @ W
    shifted     = linear_out - linear_out.max(axis=1, keepdims=True)
    exp_out     = np.exp(shifted)
    softmax_ref = exp_out / exp_out.sum(axis=1, keepdims=True)

    print(f"\n[LayerNorm ]\n{np.round(ln_out, 5)}")
    print(f"\n[Attention ]\n{np.round(attn_ref, 5)}")
    print(f"\n[Residual ]\n{np.round(residual, 5)}")
    print(f"\n[ReLU ]\n{np.round(relu_out, 5)}")

    print(f"\n[relu_out rows - should all differ??]:")
    for i in range(N):
        print(f"  row {i}: {np.round(relu_out[i], 4)}")
    
    print(f"\n[W]\n{np.round(W, 4)}")
    print(f"\n[Linear  (relu * W)]\n{np.round(linear_out, 5)}")

    print(f"\n[linear_output rows - should all differ??]:")
    for i in range(N):
        print(f"  row {i}: {np.round(linear_out[i], 4)}")

    print(f"\n[Pre-softmax row max]: {linear_out.max(axis=1)}")
    print(f"\n[Softmax ]\n{np.round(softmax_ref, 5)}")


    asm = f"""
        lui.s    $1, 0
        addi.s   $1, $0, {ADDR_TABLE_BASE}

        lw.s     $2, 0($1)                           # $2 = TILE_ADDR_INPUT
        lw.s     $3, 4($1)                           # $3 = SCPAD_ADDR (=1)

        addi.s   $5, $0, {EPSILON_LOCATION}
        lw.s     $4, 0($5)                           # $4 = epsilon

        lui.s    $16, 0x00000
        addi.s   $16, $6, 0xf
        mv.stm   1, $16

        #  LAYERNORM 
        scpad.ld $3, $2, {COLS}, {ROWS}, {SID0}

        vreg.ld  $10, $3, {COLS}, {ROWS}, {SID0}, 1, 0
        vreg.ld  $11, $3, {COLS}, {ROWS}, {SID0}, 1, 1
        vreg.ld  $12, $3, {COLS}, {ROWS}, {SID0}, 1, 2
        vreg.ld  $13, $3, {COLS}, {ROWS}, {SID0}, 1, 3

        rsum.vi  $20, $10, {RSUM_IMM}, 1
        rsum.vi  $21, $11, {RSUM_IMM}, 1
        rsum.vi  $22, $12, {RSUM_IMM}, 1
        rsum.vi  $23, $13, {RSUM_IMM}, 1

        add.vv   $21, $20, $21, 1, 0
        add.vv   $22, $22, $23, 1, 0
        add.vv   $24, $21, $22, 1, 0
        divi.vi  $24, $24, {LAYER_ELEMS}, 1          # $24 = mean

        sub.vv   $30, $10, $24, 1, 0
        sub.vv   $31, $11, $24, 1, 0
        sub.vv   $32, $12, $24, 1, 0
        sub.vv   $33, $13, $24, 1, 0

        mul.vv   $34, $30, $30, 1, 0
        mul.vv   $35, $31, $31, 1, 0
        mul.vv   $36, $32, $32, 1, 0
        mul.vv   $37, $33, $33, 1, 0

        rsum.vi  $34, $34, {RSUM_IMM}, 1
        rsum.vi  $35, $35, {RSUM_IMM}, 1
        rsum.vi  $36, $36, {RSUM_IMM}, 1
        rsum.vi  $37, $37, {RSUM_IMM}, 1

        add.vv   $35, $34, $35, 1, 0
        add.vv   $37, $36, $37, 1, 0
        add.vv   $38, $35, $37, 1, 0
        divi.vi  $39, $38, {LAYER_ELEMS}, 1          # $39 = variance

        add.vs   $39, $39, $4, 1
        sqrti.vi $39, $39, 0, 1                      # $39 = sqrt(var + eps)

        div.vv   $30, $30, $39, 1, 0
        div.vv   $31, $31, $39, 1, 0
        div.vv   $32, $32, $39, 1, 0
        div.vv   $33, $33, $39, 1, 0

        vreg.st  $30, $3, {COLS}, {ROWS}, {SID0}, 1, 0
        vreg.st  $31, $3, {COLS}, {ROWS}, {SID0}, 1, 1
        vreg.st  $32, $3, {COLS}, {ROWS}, {SID0}, 1, 2
        vreg.st  $33, $3, {COLS}, {ROWS}, {SID0}, 1, 3

        # ATTENTION 
        lw.s     $15, 32($1)                         # $15 = TILE_ADDR_ATTN
        scpad.ld $3, $15, {COLS}, {ROWS}, {SID0}

        vreg.ld  $40, $3, {COLS}, {ROWS}, {SID0}, 1, 0
        vreg.ld  $41, $3, {COLS}, {ROWS}, {SID0}, 1, 1
        vreg.ld  $42, $3, {COLS}, {ROWS}, {SID0}, 1, 2
        vreg.ld  $43, $3, {COLS}, {ROWS}, {SID0}, 1, 3

        # RESIDUAL ADD  ($40-$43) + ($10-$13)
        add.vv   $50, $40, $10, 1, 0
        add.vv   $51, $41, $11, 1, 0
        add.vv   $52, $42, $12, 1, 0
        add.vv   $53, $43, $13, 1, 0

        #  ReLU
        addi.vi  $0, $0, 0.0, 1

        mgt.mvv  2, $50, $0, 1
        addi.vi  $60, $0, 0.0, 1
        add.vv   $60, $50, $0, 2, 0

        mgt.mvv  2, $51, $0, 1
        addi.vi  $61, $0, 0.0, 1
        add.vv   $61, $51, $0, 2, 0

        mgt.mvv  2, $52, $0, 1
        addi.vi  $62, $0, 0.0, 1
        add.vv   $62, $52, $0, 2, 0

        mgt.mvv  2, $53, $0, 1
        addi.vi  $63, $0, 0.0, 1
        add.vv   $63, $53, $0, 2, 0

        # LINEAR  y = relu * W + bias 
        lw.s     $8, 24($1)                          # $8 = TILE_ADDR_W
        scpad.ld $3, $8, {COLS}, {ROWS}, {SID0}      # W^T → scpad SID0

        vreg.ld  $70, $3, {COLS}, {ROWS}, {SID0}, 1, 0
        vreg.ld  $71, $3, {COLS}, {ROWS}, {SID0}, 1, 1
        vreg.ld  $72, $3, {COLS}, {ROWS}, {SID0}, 1, 2
        vreg.ld  $73, $3, {COLS}, {ROWS}, {SID0}, 1, 3

        lw.vi    $70, $70, 0, 0xf               
        lw.vi    $71, $71, 1, 0xf               
        lw.vi    $72, $72, 2, 0xf                
        lw.vi    $73, $73, 3, 0xf                  

        # bias → scpad SID0
        lw.s     $9, 28($1)                          # $9 = TILE_ADDR_B
        scpad.ld $3, $9, {COLS}, {ROWS}, {SID0}

        vreg.ld  $74, $3, {COLS}, {ROWS}, {SID0}, 1, 0
        vreg.ld  $75, $3, {COLS}, {ROWS}, {SID0}, 1, 1
        vreg.ld  $76, $3, {COLS}, {ROWS}, {SID0}, 1, 2
        vreg.ld  $77, $3, {COLS}, {ROWS}, {SID0}, 1, 3

        # vd = vs1(relu) * gemm_weights + vs2(bias)
        gemm.vv  $60, $60, $74, 0, 0
        gemm.vv  $61, $61, $75, 0, 0
        gemm.vv  $62, $62, $76, 0, 0
        gemm.vv  $63, $63, $77, 0, 0

        # SOFTMAX (row-wisee) 
       rmax.vi  $90, $60, 0, 1
        vmov.vts $14, $90, 0
        sub.vs   $60, $60, $14, 1
        expi.vi  $90, $60, 0, 1
        rsum.vi  $91, $90, {RSUM_IMM}, 1
        vmov.vts $14, $91, 0
        div.vs   $60, $90, $14, 1

        rmax.vi  $92, $61, 0, 1
        vmov.vts $14, $92, 0
        sub.vs   $61, $61, $14, 1
        expi.vi  $92, $61, 0, 1
        rsum.vi  $93, $92, {RSUM_IMM}, 1
        vmov.vts $14, $93, 0
        div.vs   $61, $92, $14, 1

        rmax.vi  $94, $62, 0, 1
        vmov.vts $14, $94, 0
        sub.vs   $62, $62, $14, 1
        expi.vi  $94, $62, 0, 1
        rsum.vi  $95, $94, {RSUM_IMM}, 1
        vmov.vts $14, $95, 0
        div.vs   $62, $94, $14, 1

        rmax.vi  $96, $63, 0, 1
        vmov.vts $14, $96, 0
        sub.vs   $63, $63, $14, 1
        expi.vi  $96, $63, 0, 1
        rsum.vi  $97, $96, {RSUM_IMM}, 1
        vmov.vts $14, $97, 0
        div.vs   $63, $96, $14, 1

        # STORE → scpad SID0 → DRAM 
        # biasin vregs $74-$77
        vreg.st  $60, $3, {COLS}, {ROWS}, {SID0}, 1, 0
        vreg.st  $61, $3, {COLS}, {ROWS}, {SID0}, 1, 1
        vreg.st  $62, $3, {COLS}, {ROWS}, {SID0}, 1, 2
        vreg.st  $63, $3, {COLS}, {ROWS}, {SID0}, 1, 3

        lw.s     $17, 20($1)                         # $17 = TILE_ADDR_OUTPUT
        scpad.st $3, $17, {COLS}, {ROWS}, {SID0}

        halt.s
    """

    instrs = assemble_file(asm)

    if args.no_graph:
        instr_text = emit_test_format(instrs)
    else:
        dependency_instrs = convert_instructions(instrs)
        ready = build_dependency_graph(dependency_instrs, DEFAULT_LATENCY_MAP)
        packets = greedy_pack(dependency_instrs, ready, max_width=GRAPH_PACKET_WIDTH)
        scheduled = materialize_scheduled_instructions(instrs, packets, packet_width=GRAPH_PACKET_WIDTH)
        instr_text = emit_test_format(scheduled, virtual_packet_size=GRAPH_PACKET_WIDTH)


    img = DRAMWriter()


    img.u32(ADDR_TABLE_BASE + 0,  TILE_ADDR_INPUT)   
    img.u32(ADDR_TABLE_BASE + 4,  SCPAD_ADDR)         
    img.u32(ADDR_TABLE_BASE + 8,  TILE_ADDR_Q)       
    img.u32(ADDR_TABLE_BASE + 12, TILE_ADDR_K)        
    img.u32(ADDR_TABLE_BASE + 16, TILE_ADDR_V)        
    img.u32(ADDR_TABLE_BASE + 20, TILE_ADDR_OUTPUT)   
    img.u32(ADDR_TABLE_BASE + 24, TILE_ADDR_W)      
    img.u32(ADDR_TABLE_BASE + 28, TILE_ADDR_B)        
    img.u32(ADDR_TABLE_BASE + 32, TILE_ADDR_ATTN)    

    # Epsilon
    img.f32(EPSILON_LOCATION, 1e-5)

    # Input tile 
    if args.data is not None:
        input_values = load_tile_data(args.data, N)
    else:
        input_values = [float(v) for v in range(4, 4 + N * N)]
    for i, val in enumerate(input_values):
        img.bf16(TILE_ADDR_INPUT + i * 2, val)

    # Q, K, V tiles
    for i, val in enumerate(Q.flatten()):
        img.bf16(TILE_ADDR_Q + i * 2, float(val))
    for i, val in enumerate(K.flatten()):
        img.bf16(TILE_ADDR_K + i * 2, float(val))
    for i, val in enumerate(V.flatten()):
        img.bf16(TILE_ADDR_V + i * 2, float(val))

    # Attention 
    for i in range(N):
        for j in range(N):
            img.bf16(TILE_ADDR_ATTN + (i * N + j) * 2, float(attn_ref[i, j]))

    W = np.array([
        [0.1, 0.5, 0.3, 0.8],
        [0.6, 0.2, 0.7, 0.1],
        [0.4, 0.9, 0.2, 0.5],
        [0.8, 0.3, 0.6, 0.2],
    ], dtype=np.float32)
    WT = W.T
    for r in range(N):
        for c in range(N):
            img.bf16(TILE_ADDR_W + (r * N + c) * 2, float(WT[r, c]))
    for i in range(N * N):
        img.bf16(TILE_ADDR_B + i * 2, 0.0)

    # Output (initiailized to 0)
    for i in range(N * N):
        img.bf16(TILE_ADDR_OUTPUT + i * 2, 0.0)

    data_text = img.render_data_mem(include_zeros=False)
    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
        print(f"[INFO] Written to {args.output}")
    else:
        print(final)


if __name__ == "__main__":
    main()