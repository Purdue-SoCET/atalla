"""Blocked GEMM: C[M,N] += A[M,K] * B[K,N], tiled in 32x32 blocks.

The assembly loops over M-tiles, N-tiles, then K-tiles (reduction).
Each K-tile iteration accumulates into C via gemm.vv (C_row += A_row @ B_tile).
"""
from __future__ import annotations

import os, struct, math
from pathlib import Path
import argparse
import numpy as np

from build import *

TILE = 32


def make_tiled_gemm_asm(M: int, N: int, K: int) -> str:
    M_tiles = math.ceil(M / TILE)
    N_tiles = math.ceil(N / TILE)
    K_tiles = math.ceil(K / TILE)

    tm1 = min(TILE, M) - 1
    tn1 = min(TILE, N) - 1
    tk1 = min(TILE, K) - 1

    return f"""
        # Tiled GEMM: C[{M},{N}] += A[{M},{K}] * B[{K},{N}]
        # Tiles: M={M_tiles}, N={N_tiles}, K={K_tiles} (each up to {TILE})
        #
        # Address table at 60:
        #   [0] A_GMEM  [4] B_GMEM  [8] C_GMEM
        #   [12] M  [16] N  [20] K
        #   [24] M_TILES  [28] N_TILES  [32] K_TILES
        #   [36] TILE_SIZE (=32)

        addi.s  $1, $0, 60

        lw.s    $2, 0($1)           # A_GMEM base
        lw.s    $3, 4($1)           # B_GMEM base
        lw.s    $4, 8($1)           # C_GMEM base
        lw.s    $50, 12($1)         # M
        lw.s    $51, 16($1)         # N
        lw.s    $52, 20($1)         # K
        lw.s    $53, 24($1)         # M_TILES
        lw.s    $54, 28($1)         # N_TILES
        lw.s    $55, 32($1)         # K_TILES
        lw.s    $56, 36($1)         # TILE_SIZE

        # mask: all lanes
        addi.s  $20, $0, -1
        mv.stm  1, $20

        # Outer loops via scalar registers
        # $60 = m_tile_idx, $61 = n_tile_idx, $62 = k_tile_idx
        # $63 = current A tile gmem addr
        # $64 = current B tile gmem addr
        # $65 = current C tile gmem addr
        # $66, $67 = scratch for address computation
        # $70 = A_scpad (0, SID0)
        # $71 = B_scpad (offset in SID0)
        # $72 = C_scpad (0, SID1)

        addi.s  $70, $0, 0          # A in SP0 at 0
        addi.s  $71, $0, 512        # B in SP0 at offset
        addi.s  $72, $0, 0          # C in SP1 at 0

        addi.s  $60, $0, 0          # m_tile_idx = 0

m_tile_loop:
        bge.s   $60, $53, done

        addi.s  $61, $0, 0          # n_tile_idx = 0

n_tile_loop:
        bge.s   $61, $54, m_tile_next

        # Zero C tile in SP1: load C tile from gmem (initialized to 0)
        # C_offset = (m_tile_idx * N_TILES + n_tile_idx) * TILE * TILE * 2
        # Actually, C is at C_GMEM + (m_tile_idx*TILE*N + n_tile_idx*TILE) * 2
        # For simplicity, compute C tile address:
        # $65 = C_GMEM + m_tile_idx * TILE * N * 2 + n_tile_idx * TILE * 2
        mul.s   $66, $60, $56       # m_tile_idx * TILE
        mul.s   $66, $66, $51       # * N
        mul.s   $67, $61, $56       # n_tile_idx * TILE
        add.s   $66, $66, $67       # m*TILE*N + n*TILE
        addi.s  $67, $0, 2
        mul.s   $66, $66, $67       # * 2 (bytes)
        add.s   $65, $4, $66        # C tile gmem addr

        scpad.ld $72, $65, {tn1}, {tm1}, 1

        addi.s  $62, $0, 0          # k_tile_idx = 0

k_tile_loop:
        bge.s   $62, $55, k_tile_done

        # Compute A tile addr: A_GMEM + (m_tile_idx*TILE*K + k_tile_idx*TILE)*2
        mul.s   $66, $60, $56
        mul.s   $66, $66, $52
        mul.s   $67, $62, $56
        add.s   $66, $66, $67
        addi.s  $67, $0, 2
        mul.s   $66, $66, $67
        add.s   $63, $2, $66

        # Compute B tile addr: B_GMEM + (k_tile_idx*TILE*N + n_tile_idx*TILE)*2
        mul.s   $66, $62, $56
        mul.s   $66, $66, $51
        mul.s   $67, $61, $56
        add.s   $66, $66, $67
        addi.s  $67, $0, 2
        mul.s   $66, $66, $67
        add.s   $64, $3, $66

        # Load A tile and B tile
        scpad.ld $70, $63, {tk1}, {tm1}, 0
        scpad.ld $71, $64, {tn1}, {tk1}, 0

        # Load B rows into systolic array
        addi.s  $27, $0, 0
        addi.s  $28, $0, {min(TILE, K)}

wt_loop:
        bge.s   $27, $28, wt_done
        vreg.ld $10, $71, {tn1}, {tk1}, 0, 1, $27
        lw.vi   $10, $10, 0, 0xf
        addi.s  $27, $27, 1
        blt.s   $27, $28, wt_loop

wt_done:
        # GEMM: for each A row, C_row += A_row @ B_tile
        addi.s  $25, $0, 0
        addi.s  $26, $0, {min(TILE, M)}

row_loop:
        vreg.ld $30, $70, {tk1}, {tm1}, 0, 1, $25
        vreg.ld $31, $72, {tn1}, {tm1}, 1, 1, $25
        gemm.vv $32, $30, $31, 0, 0
        vreg.st $32, $72, {tn1}, {tm1}, 1, 1, $25
        addi.s  $25, $25, 1
        blt.s   $25, $26, row_loop

        addi.s  $62, $62, 1
        blt.s   $62, $55, k_tile_loop

k_tile_done:
        # Store C tile back to DRAM
        scpad.st $72, $65, {tn1}, {tm1}, 1

        addi.s  $61, $61, 1
        blt.s   $61, $54, n_tile_loop

m_tile_next:
        addi.s  $60, $60, 1
        blt.s   $60, $53, m_tile_loop

done:
        halt.s
    """


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/gemm_tiled.in"))
    ap.add_argument("--M", type=int, default=8)
    ap.add_argument("--N", type=int, default=8)
    ap.add_argument("--K", type=int, default=8)
    args = ap.parse_args()

    M, N, K = args.M, args.N, args.K
    M_tiles = math.ceil(M / TILE)
    N_tiles = math.ceil(N / TILE)
    K_tiles = math.ceil(K / TILE)

    ADDR_TABLE = 60
    A_GMEM = 0x1000
    B_GMEM = A_GMEM + M * K * 2 + 0x1000
    C_GMEM = B_GMEM + K * N * 2 + 0x1000

    np.random.seed(42)
    A = np.random.randn(M, K).astype(np.float32) * 0.5
    B = np.random.randn(K, N).astype(np.float32) * 0.5

    asm = make_tiled_gemm_asm(M, N, K)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(ADDR_TABLE + 0, A_GMEM)
    img.u32(ADDR_TABLE + 4, B_GMEM)
    img.u32(ADDR_TABLE + 8, C_GMEM)
    img.u32(ADDR_TABLE + 12, M)
    img.u32(ADDR_TABLE + 16, N)
    img.u32(ADDR_TABLE + 20, K)
    img.u32(ADDR_TABLE + 24, M_tiles)
    img.u32(ADDR_TABLE + 28, N_tiles)
    img.u32(ADDR_TABLE + 32, K_tiles)
    img.u32(ADDR_TABLE + 36, TILE)

    for r in range(M):
        for c in range(K):
            img.bf16(A_GMEM + (r * K + c) * 2, float(A[r, c]))

    for r in range(K):
        for c in range(N):
            img.bf16(B_GMEM + (r * N + c) * 2, float(B[r, c]))

    for i in range(M * N):
        img.bf16(C_GMEM + i * 2, 0.0)

    expected = A @ B
    print(f"Tiled GEMM: C[{M},{N}] = A[{M},{K}] * B[{K},{N}]")
    print(f"Tiles: {M_tiles}x{N_tiles}x{K_tiles}")
    print(f"\nA =\n{A}")
    print(f"\nB =\n{B}")
    print(f"\nExpected C =\n{expected}")

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
        print(f"\nWrote {args.output}")
    else:
        print(final)


if __name__ == "__main__":
    main()
