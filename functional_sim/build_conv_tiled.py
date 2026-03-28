"""Tiled convolution: Conv as GEMM with im2col, tiled for arbitrary sizes.

C[M, K_out] = A_im2col[M, K_flat] * W[K_flat, K_out]
where M = N*Ho*Wo, K_flat = R*S*C, K_out = output channels.

Tiles M, K_flat, K_out dimensions in blocks of up to 32.
"""
from __future__ import annotations

import os, math
from pathlib import Path
import argparse
import numpy as np

from build import *

TILE = 32


def make_tiled_conv_asm(M: int, K_flat: int, K_out: int) -> str:
    M_tiles = math.ceil(M / TILE)
    N_tiles = math.ceil(K_out / TILE)
    K_tiles = math.ceil(K_flat / TILE)

    tm1 = min(TILE, M) - 1
    tn1 = min(TILE, K_out) - 1
    tk1 = min(TILE, K_flat) - 1

    return f"""
        # Tiled Conv-as-GEMM: C[{M},{K_out}] = A[{M},{K_flat}] * W[{K_flat},{K_out}]
        # Tiles: M={M_tiles}, N={N_tiles}, K={K_tiles}

        addi.s  $1, $0, 60

        lw.s    $2, 0($1)           # A_GMEM
        lw.s    $3, 4($1)           # W_GMEM
        lw.s    $4, 8($1)           # C_GMEM
        lw.s    $50, 12($1)         # M
        lw.s    $51, 16($1)         # K_out (N)
        lw.s    $52, 20($1)         # K_flat (K)
        lw.s    $53, 24($1)         # M_TILES
        lw.s    $54, 28($1)         # N_TILES
        lw.s    $55, 32($1)         # K_TILES
        lw.s    $56, 36($1)         # TILE_SIZE

        addi.s  $20, $0, -1
        mv.stm  1, $20

        addi.s  $70, $0, 0          # A in SP0 at 0
        addi.s  $71, $0, 512        # W in SP0 at offset
        addi.s  $72, $0, 0          # C in SP1 at 0

        addi.s  $60, $0, 0          # m_tile

m_tile_loop:
        bge.s   $60, $53, done

        addi.s  $61, $0, 0          # n_tile (k_out tile)

n_tile_loop:
        bge.s   $61, $54, m_next

        # C tile addr
        mul.s   $66, $60, $56
        mul.s   $66, $66, $51
        mul.s   $67, $61, $56
        add.s   $66, $66, $67
        addi.s  $67, $0, 2
        mul.s   $66, $66, $67
        add.s   $65, $4, $66

        scpad.ld $72, $65, {tn1}, {tm1}, 1

        addi.s  $62, $0, 0          # k_tile

k_tile_loop:
        bge.s   $62, $55, k_done

        # A tile addr
        mul.s   $66, $60, $56
        mul.s   $66, $66, $52
        mul.s   $67, $62, $56
        add.s   $66, $66, $67
        addi.s  $67, $0, 2
        mul.s   $66, $66, $67
        add.s   $63, $2, $66

        # W tile addr
        mul.s   $66, $62, $56
        mul.s   $66, $66, $51
        mul.s   $67, $61, $56
        add.s   $66, $66, $67
        addi.s  $67, $0, 2
        mul.s   $66, $66, $67
        add.s   $64, $3, $66

        scpad.ld $70, $63, {tk1}, {tm1}, 0
        scpad.ld $71, $64, {tn1}, {tk1}, 0

        addi.s  $27, $0, 0
        addi.s  $28, $0, {min(TILE, K_flat)}

wt_loop:
        bge.s   $27, $28, wt_done
        vreg.ld $10, $71, {tn1}, {tk1}, 0, 1, $27
        lw.vi   $10, $10, 0, 0xf
        addi.s  $27, $27, 1
        blt.s   $27, $28, wt_loop

wt_done:
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

k_done:
        scpad.st $72, $65, {tn1}, {tm1}, 1

        addi.s  $61, $61, 1
        blt.s   $61, $54, n_tile_loop

m_next:
        addi.s  $60, $60, 1
        blt.s   $60, $53, m_tile_loop

done:
        halt.s
    """


def im2col(ifmap, N, H, W, C, R, S, stride, pad):
    Ho = (H + 2 * pad - R) // stride + 1
    Wo = (W + 2 * pad - S) // stride + 1
    rows = []
    for n in range(N):
        for oh in range(Ho):
            for ow in range(Wo):
                cols = []
                for r in range(R):
                    for s in range(S):
                        ih = oh * stride + r - pad
                        iw = ow * stride + s - pad
                        if ih < 0 or ih >= H or iw < 0 or iw >= W:
                            cols.extend([0.0] * C)
                        else:
                            cols.extend(ifmap[n, ih, iw, :].tolist())
                rows.append(cols)
    return np.array(rows, dtype=np.float32)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/conv_tiled.in"))
    ap.add_argument("--N", type=int, default=1)
    ap.add_argument("--H", type=int, default=8)
    ap.add_argument("--W", type=int, default=8)
    ap.add_argument("--C", type=int, default=3)
    ap.add_argument("--K", type=int, default=4)
    ap.add_argument("--R", type=int, default=3)
    ap.add_argument("--S", type=int, default=3)
    ap.add_argument("--stride", type=int, default=1)
    ap.add_argument("--pad", type=int, default=0)
    args = ap.parse_args()

    Ni, H, W, C = args.N, args.H, args.W, args.C
    K_out, R, S = args.K, args.R, args.S
    stride, pad = args.stride, args.pad

    Ho = (H + 2 * pad - R) // stride + 1
    Wo = (W + 2 * pad - S) // stride + 1
    K_flat = R * S * C
    M = Ni * Ho * Wo

    M_tiles = math.ceil(M / TILE)
    N_tiles = math.ceil(K_out / TILE)
    K_tiles = math.ceil(K_flat / TILE)

    ADDR_TABLE = 60
    A_GMEM = 0x1000
    W_GMEM = A_GMEM + M * K_flat * 2 + 0x1000
    C_GMEM = W_GMEM + K_flat * K_out * 2 + 0x1000

    np.random.seed(42)
    ifmap = np.random.randn(Ni, H, W, C).astype(np.float32) * 0.5
    weights = np.random.randn(R, S, C, K_out).astype(np.float32) * 0.5

    A_mat = im2col(ifmap, Ni, H, W, C, R, S, stride, pad)
    W_flat = weights.reshape(K_flat, K_out)

    asm = make_tiled_conv_asm(M, K_flat, K_out)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(ADDR_TABLE + 0, A_GMEM)
    img.u32(ADDR_TABLE + 4, W_GMEM)
    img.u32(ADDR_TABLE + 8, C_GMEM)
    img.u32(ADDR_TABLE + 12, M)
    img.u32(ADDR_TABLE + 16, K_out)
    img.u32(ADDR_TABLE + 20, K_flat)
    img.u32(ADDR_TABLE + 24, M_tiles)
    img.u32(ADDR_TABLE + 28, N_tiles)
    img.u32(ADDR_TABLE + 32, K_tiles)
    img.u32(ADDR_TABLE + 36, TILE)

    for r in range(M):
        for c in range(K_flat):
            img.bf16(A_GMEM + (r * K_flat + c) * 2, float(A_mat[r, c]))

    for r in range(K_flat):
        for c in range(K_out):
            img.bf16(W_GMEM + (r * K_out + c) * 2, float(W_flat[r, c]))

    for i in range(M * K_out):
        img.bf16(C_GMEM + i * 2, 0.0)

    expected = A_mat @ W_flat
    print(f"Tiled Conv: im2col [{M},{K_flat}] * W [{K_flat},{K_out}]")
    print(f"Input: {Ni}x{H}x{W}x{C}, Kernel: {R}x{S}, K_out={K_out}, stride={stride}, pad={pad}")
    print(f"Output: {Ho}x{Wo}x{K_out} (M={M})")
    print(f"Tiles: M={M_tiles}, N={N_tiles}, K={K_tiles}")
    print(f"\nExpected C (first 4 rows):\n{expected[:4]}")

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
