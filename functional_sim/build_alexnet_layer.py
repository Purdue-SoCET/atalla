"""Per-layer AlexNet builder.

Generates a .in file for a single AlexNet layer on the Atalla emulator.
Supports: Conv (tiled im2col GEMM), ReLU, MaxPool, FC (tiled GEMM), Softmax.

Usage:
    python build_alexnet_layer.py --layer 1 -o tests/alexnet_layer1.in
    python build_alexnet_layer.py --layer 2 -o tests/alexnet_layer2.in
    ...
    python build_alexnet_layer.py --layer 19 -o tests/alexnet_layer19.in

With --scale <f> to reduce channel counts for faster testing.
"""
from __future__ import annotations

import os, math, struct
from pathlib import Path
from dataclasses import dataclass
from typing import Optional
import argparse
import numpy as np

from build import *

TILE = 32


# ---------------------------------------------------------------------------
# AlexNet layer definitions
# ---------------------------------------------------------------------------
@dataclass
class ConvSpec:
    H: int; W: int; C_in: int; C_out: int
    R: int; S: int; stride: int; pad: int


@dataclass
class FCSpec:
    in_features: int; out_features: int


@dataclass
class PoolSpec:
    H: int; W: int; channels: int
    pool: int; stride: int


@dataclass
class ActivationSpec:
    total_elements: int
    width: int


@dataclass
class SoftmaxSpec:
    length: int


def alexnet_layers(scale: float = 1.0):
    """Return list of (layer_num, name, spec) for AlexNet."""
    def sc(c):
        return max(1, int(c * scale))

    layers = []
    # Conv1: 227x227x3 -> 55x55x96, 11x11 s4 p0
    layers.append((1, "conv", ConvSpec(227, 227, 3, sc(96), 11, 11, 4, 0)))
    # ReLU1
    layers.append((2, "relu", ActivationSpec(55 * 55 * sc(96), min(55 * sc(96), 32))))
    # MaxPool1: 55x55x96 -> 27x27x96, 3x3 s2
    layers.append((3, "maxpool", PoolSpec(55, 55, sc(96), 3, 2)))
    # Conv2: 27x27x96 -> 27x27x256, 5x5 s1 p2
    layers.append((4, "conv", ConvSpec(27, 27, sc(96), sc(256), 5, 5, 1, 2)))
    # ReLU2
    layers.append((5, "relu", ActivationSpec(27 * 27 * sc(256), min(27 * sc(256), 32))))
    # MaxPool2: 27x27x256 -> 13x13x256, 3x3 s2
    layers.append((6, "maxpool", PoolSpec(27, 27, sc(256), 3, 2)))
    # Conv3: 13x13x256 -> 13x13x384, 3x3 s1 p1
    layers.append((7, "conv", ConvSpec(13, 13, sc(256), sc(384), 3, 3, 1, 1)))
    # ReLU3
    layers.append((8, "relu", ActivationSpec(13 * 13 * sc(384), min(13 * sc(384), 32))))
    # Conv4: 13x13x384 -> 13x13x384, 3x3 s1 p1
    layers.append((9, "conv", ConvSpec(13, 13, sc(384), sc(384), 3, 3, 1, 1)))
    # ReLU4
    layers.append((10, "relu", ActivationSpec(13 * 13 * sc(384), min(13 * sc(384), 32))))
    # Conv5: 13x13x384 -> 13x13x256, 3x3 s1 p1
    layers.append((11, "conv", ConvSpec(13, 13, sc(384), sc(256), 3, 3, 1, 1)))
    # ReLU5
    layers.append((12, "relu", ActivationSpec(13 * 13 * sc(256), min(13 * sc(256), 32))))
    # MaxPool3: 13x13x256 -> 6x6x256, 3x3 s2
    layers.append((13, "maxpool", PoolSpec(13, 13, sc(256), 3, 2)))
    # FC1: 9216 -> 4096
    fc1_in = 6 * 6 * sc(256)
    layers.append((14, "fc", FCSpec(fc1_in, sc(4096))))
    # ReLU6
    layers.append((15, "relu", ActivationSpec(sc(4096), min(sc(4096), 32))))
    # FC2: 4096 -> 4096
    layers.append((16, "fc", FCSpec(sc(4096), sc(4096))))
    # ReLU7
    layers.append((17, "relu", ActivationSpec(sc(4096), min(sc(4096), 32))))
    # FC3: 4096 -> 1000
    layers.append((18, "fc", FCSpec(sc(4096), sc(1000))))
    # Softmax
    layers.append((19, "softmax", SoftmaxSpec(sc(1000))))

    return layers


# ---------------------------------------------------------------------------
# Assembly generators (reuse patterns from build_*.py)
# ---------------------------------------------------------------------------
def make_relu_asm(total: int, width: int) -> str:
    rows = math.ceil(total / width)
    w_m1 = width - 1
    sp_rows = min(rows, TILE)
    sp_r_m1 = sp_rows - 1
    tile_count = math.ceil(rows / sp_rows)
    tile_bytes = sp_rows * width * 2

    return f"""
        addi.s  $1, $0, 60
        lw.s    $3, 0($1)           # IN_GMEM (advances per tile)
        lw.s    $8, 4($1)           # OUT_GMEM (advances per tile)
        addi.s  $9, $0, 0           # SCPAD addr

        addi.s  $255, $0, -1
        mv.stm  1, $255
        addi.vi $2, $0, 0.0, 1

        addi.s  $40, $0, 0          # tile counter
        addi.s  $41, $0, {tile_count}

tile_loop:
        bge.s   $40, $41, tile_done
        scpad.ld $9, $3, {w_m1}, {sp_r_m1}, 0

        addi.s  $25, $0, 0
        addi.s  $26, $0, {sp_rows}

relu_loop:
        vreg.ld $4, $9, {w_m1}, {sp_r_m1}, 0, 1, $25
        mgt.mvv 2, $4, $2, 1
        addi.vi $1, $0, 0.0, 1
        add.vv  $1, $4, $2, 2, 0
        vreg.st $1, $9, {w_m1}, {sp_r_m1}, 0, 1, $25
        addi.s  $25, $25, 1
        blt.s   $25, $26, relu_loop

        scpad.st $9, $8, {w_m1}, {sp_r_m1}, 0
        addi.s  $3, $3, {tile_bytes}
        addi.s  $8, $8, {tile_bytes}
        addi.s  $40, $40, 1
        blt.s   $40, $41, tile_loop

tile_done:
        halt.s
    """


def make_softmax_asm(length: int) -> str:
    w_m1 = min(length, 32) - 1
    rows = math.ceil(length / 32)
    r_m1 = rows - 1
    mask_val = (1 << min(length, 32)) - 1
    # Simplified: treat as single row if length <= 32
    return f"""
        addi.s  $1, $0, 60
        lw.s    $2, 0($1)
        lw.s    $3, 4($1)
        scpad.ld $3, $2, {w_m1}, {r_m1}, 0

        addi.s  $4, $0, {mask_val}
        mv.stm  1, $4

        addi.s  $25, $0, 0
        addi.s  $26, $0, {rows}

sm_loop:
        vreg.ld $10, $3, {w_m1}, {r_m1}, 0, 1, $25
        rmax.vi  $11, $10, 0, 1
        vmov.vts $1, $11, 0
        sub.vs   $10, $10, $1, 1
        expi.vi  $12, $10, 0, 1
        rsum.vi  $13, $12, 64, 1
        vmov.vts $6, $13, 0
        div.vs   $10, $12, $6, 1
        vreg.st  $10, $3, {w_m1}, {r_m1}, 0, 1, $25
        addi.s   $25, $25, 1
        blt.s    $25, $26, sm_loop

        scpad.st $3, $2, {w_m1}, {r_m1}, 0
        halt.s
    """


def make_tiled_gemm_asm(M: int, N: int, K: int) -> str:
    M_tiles = math.ceil(M / TILE)
    N_tiles = math.ceil(N / TILE)
    K_tiles = math.ceil(K / TILE)
    tm1 = min(TILE, M) - 1
    tn1 = min(TILE, N) - 1
    tk1 = min(TILE, K) - 1

    return f"""
        addi.s  $1, $0, 60
        lw.s    $2, 0($1)
        lw.s    $3, 4($1)
        lw.s    $4, 8($1)
        lw.s    $50, 12($1)
        lw.s    $51, 16($1)
        lw.s    $52, 20($1)
        lw.s    $53, 24($1)
        lw.s    $54, 28($1)
        lw.s    $55, 32($1)
        lw.s    $56, 36($1)

        addi.s  $20, $0, -1
        mv.stm  1, $20

        addi.s  $70, $0, 0
        addi.s  $71, $0, 512
        addi.s  $72, $0, 0

        addi.s  $60, $0, 0
m_tile_loop:
        bge.s   $60, $53, done
        addi.s  $61, $0, 0
n_tile_loop:
        bge.s   $61, $54, m_next
        mul.s   $66, $60, $56
        mul.s   $66, $66, $51
        mul.s   $67, $61, $56
        add.s   $66, $66, $67
        addi.s  $67, $0, 2
        mul.s   $66, $66, $67
        add.s   $65, $4, $66
        scpad.ld $72, $65, {tn1}, {tm1}, 1
        addi.s  $62, $0, 0
k_tile_loop:
        bge.s   $62, $55, k_done
        mul.s   $66, $60, $56
        mul.s   $66, $66, $52
        mul.s   $67, $62, $56
        add.s   $66, $66, $67
        addi.s  $67, $0, 2
        mul.s   $66, $66, $67
        add.s   $63, $2, $66
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
        addi.s  $28, $0, {min(TILE, K)}
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


def make_maxpool_asm(H_in: int, W_in: int, pool_size: int, stride: int) -> str:
    H_out = (H_in - pool_size) // stride + 1
    W_out = (W_in - pool_size) // stride + 1
    h_m1 = H_in - 1
    w_m1 = W_in - 1
    ho_m1 = H_out - 1
    wo_m1 = W_out - 1
    mask_all = (1 << W_in) - 1

    lines = []
    a = lines.append
    a(f"addi.s  $1, $0, 60")
    a(f"lw.s    $2, 0($1)")
    a(f"lw.s    $3, 4($1)")
    a(f"lw.s    $4, 8($1)")
    a(f"lw.s    $5, 12($1)")
    a(f"scpad.ld $3, $2, {w_m1}, {h_m1}, 0")
    a(f"addi.s  $20, $0, {mask_all}")
    a(f"mv.stm  1, $20")
    a(f"addi.s  $25, $0, 0")
    a(f"addi.s  $26, $0, {H_out}")
    a(f"addi.s  $29, $0, 0")
    a(f"out_row_loop:")
    for p in range(pool_size):
        a(f"addi.s  $27, $29, {p}")
        a(f"vreg.ld ${40 + p}, $3, {w_m1}, {h_m1}, 0, 1, $27")
    # vertical max
    a(f"sub.vv  $50, $50, $50, 1, 0")
    a(f"add.vv  $50, $50, $41, 1, 0")
    a(f"mgt.mvv 2, $40, $41, 1")
    a(f"sub.vv  $50, $50, $50, 2, 0")
    a(f"add.vv  $50, $50, $40, 2, 0")
    if pool_size >= 3:
        a(f"sub.vv  $51, $51, $51, 1, 0")
        a(f"add.vv  $51, $51, $42, 1, 0")
        a(f"mgt.mvv 2, $50, $42, 1")
        a(f"sub.vv  $51, $51, $51, 2, 0")
        a(f"add.vv  $51, $51, $50, 2, 0")
    vert = "$51" if pool_size >= 3 else "$50"
    # horizontal max
    a(f"shift.vi $52, {vert}, 1, 1")
    a(f"mgt.mvv 2, {vert}, $52, 1")
    a(f"sub.vv  $53, $53, $53, 1, 0")
    a(f"add.vv  $53, $53, $52, 1, 0")
    a(f"sub.vv  $53, $53, $53, 2, 0")
    a(f"add.vv  $53, $53, {vert}, 2, 0")
    if pool_size >= 3:
        a(f"shift.vi $52, {vert}, 2, 1")
        a(f"mgt.mvv 2, $53, $52, 1")
        a(f"sub.vv  $54, $54, $54, 1, 0")
        a(f"add.vv  $54, $54, $52, 1, 0")
        a(f"sub.vv  $54, $54, $54, 2, 0")
        a(f"add.vv  $54, $54, $53, 2, 0")
        hz = "$54"
    else:
        hz = "$53"
    a(f"vreg.st {hz}, $5, {wo_m1}, {ho_m1}, 1, 1, $25")
    a(f"addi.s  $29, $29, {stride}")
    a(f"addi.s  $25, $25, 1")
    a(f"blt.s   $25, $26, out_row_loop")
    a(f"scpad.st $5, $4, {wo_m1}, {ho_m1}, 1")
    a(f"halt.s")

    return "\n".join(f"        {l}" for l in lines)


# ---------------------------------------------------------------------------
# im2col helper
# ---------------------------------------------------------------------------
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


# ---------------------------------------------------------------------------
# Build a single layer .in file
# ---------------------------------------------------------------------------
def build_layer(layer_num: int, name: str, spec, rng,
                input_data: Optional[np.ndarray] = None,
                weights: Optional[np.ndarray] = None,
                bias: Optional[np.ndarray] = None) -> tuple:
    """Returns (instr_text, img, output_data_expected)."""

    ADDR_TABLE = 60

    if name == "conv":
        s = spec
        Ho = (s.H + 2 * s.pad - s.R) // s.stride + 1
        Wo = (s.W + 2 * s.pad - s.S) // s.stride + 1
        K_flat = s.R * s.S * s.C_in
        M = Ho * Wo
        N = s.C_out
        K = K_flat

        M_tiles = math.ceil(M / TILE)
        N_tiles = math.ceil(N / TILE)
        K_tiles = math.ceil(K / TILE)

        if input_data is None:
            input_data = rng.standard_normal((1, s.H, s.W, s.C_in)).astype(np.float32) * 0.1
        if weights is None:
            weights = rng.standard_normal((s.R, s.S, s.C_in, s.C_out)).astype(np.float32) * 0.1

        A_mat = im2col(input_data, 1, s.H, s.W, s.C_in, s.R, s.S, s.stride, s.pad)
        W_flat = weights.reshape(K_flat, s.C_out)

        A_GMEM = 0x1000
        W_GMEM = A_GMEM + M * K * 2 + 0x1000
        C_GMEM = W_GMEM + K * N * 2 + 0x1000

        asm = make_tiled_gemm_asm(M, N, K)
        instrs = assemble_file(asm)
        instr_text = emit_test_format(instrs)

        img = DRAMWriter()
        img.u32(ADDR_TABLE + 0, A_GMEM)
        img.u32(ADDR_TABLE + 4, W_GMEM)
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
                img.bf16(A_GMEM + (r * K + c) * 2, float(A_mat[r, c]))
        for r in range(K):
            for c in range(N):
                img.bf16(W_GMEM + (r * N + c) * 2, float(W_flat[r, c]))
        for i in range(M * N):
            img.bf16(C_GMEM + i * 2, 0.0)

        expected = (A_mat @ W_flat).reshape(Ho, Wo, s.C_out)
        return instr_text, img, expected

    elif name == "relu":
        s = spec
        width = min(s.width, 32)
        rows = math.ceil(s.total_elements / width)

        if input_data is None:
            input_data = rng.standard_normal(s.total_elements).astype(np.float32) * 0.5

        flat = input_data.flatten()[:s.total_elements]

        IN_GMEM = 0x1000
        OUT_GMEM = IN_GMEM + rows * width * 2 + 0x1000

        asm = make_relu_asm(s.total_elements, width)
        instrs = assemble_file(asm)
        instr_text = emit_test_format(instrs)

        img = DRAMWriter()
        img.u32(ADDR_TABLE + 0, IN_GMEM)
        img.u32(ADDR_TABLE + 4, OUT_GMEM)

        padded = np.zeros(rows * width, dtype=np.float32)
        padded[:len(flat)] = flat
        for i in range(rows * width):
            img.bf16(IN_GMEM + i * 2, float(padded[i]))

        expected = np.maximum(flat, 0.0)
        return instr_text, img, expected

    elif name == "maxpool":
        s = spec
        # Per-channel: process each channel slice independently
        # For simplicity, flatten channels into rows: H_in rows each of W_in*C values
        # But since vector width is 32, we process one channel at a time
        # and the orchestrator handles iteration over channels.
        # For the .in file, we'll do a single-channel slice.
        H_out = (s.H - s.pool) // s.stride + 1
        W_out = (s.W - s.pool) // s.stride + 1

        if s.W <= 32:
            if input_data is None:
                input_data = rng.standard_normal((s.H, s.W)).astype(np.float32)

            tile = input_data[:s.H, :s.W] if input_data.ndim == 2 else input_data.reshape(s.H, s.W)

            IN_GMEM = 0x1000
            OUT_GMEM = 0x2000

            asm = make_maxpool_asm(s.H, s.W, s.pool, s.stride)
            instrs = assemble_file(asm)
            instr_text = emit_test_format(instrs)

            img = DRAMWriter()
            img.u32(ADDR_TABLE + 0, IN_GMEM)
            img.u32(ADDR_TABLE + 4, 0)
            img.u32(ADDR_TABLE + 8, OUT_GMEM)
            img.u32(ADDR_TABLE + 12, 0)

            for r in range(s.H):
                for c in range(s.W):
                    img.bf16(IN_GMEM + (r * s.W + c) * 2, float(tile[r, c]))

            for i in range(H_out * W_out):
                img.bf16(OUT_GMEM + i * 2, 0.0)

            expected = np.full((H_out, W_out), -np.inf)
            for oh in range(H_out):
                for ow in range(W_out):
                    for pr in range(s.pool):
                        for pc in range(s.pool):
                            ih = oh * s.stride + pr
                            iw = ow * s.stride + pc
                            if ih < s.H and iw < s.W:
                                expected[oh, ow] = max(expected[oh, ow], tile[ih, iw])

            return instr_text, img, expected
        else:
            raise NotImplementedError("MaxPool with W > 32 requires channel-wise iteration")

    elif name == "fc":
        s = spec
        M = 1
        N = s.out_features
        K = s.in_features
        M_tiles = math.ceil(M / TILE)
        N_tiles = math.ceil(N / TILE)
        K_tiles = math.ceil(K / TILE)

        if input_data is None:
            input_data = rng.standard_normal(K).astype(np.float32) * 0.1
        if weights is None:
            weights = rng.standard_normal((K, N)).astype(np.float32) * 0.1

        A = input_data.reshape(1, K)
        B = weights

        A_GMEM = 0x1000
        B_GMEM = A_GMEM + M * K * 2 + 0x1000
        C_GMEM = B_GMEM + K * N * 2 + 0x1000

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

        expected = (A @ B).flatten()
        return instr_text, img, expected

    elif name == "softmax":
        s = spec
        if input_data is None:
            input_data = rng.standard_normal(s.length).astype(np.float32)

        flat = input_data.flatten()[:s.length]

        IN_GMEM = 0x1000

        asm = make_softmax_asm(s.length)
        instrs = assemble_file(asm)
        instr_text = emit_test_format(instrs)

        img = DRAMWriter()
        img.u32(ADDR_TABLE + 0, IN_GMEM)
        img.u32(ADDR_TABLE + 4, 0)

        width = min(s.length, 32)
        rows = math.ceil(s.length / 32)
        padded = np.zeros(rows * width, dtype=np.float32)
        padded[:len(flat)] = flat
        for i in range(rows * width):
            img.bf16(IN_GMEM + i * 2, float(padded[i]))

        ex = np.exp(flat - np.max(flat))
        expected = ex / ex.sum()
        return instr_text, img, expected

    else:
        raise ValueError(f"Unknown layer type: {name}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--layer", type=int, required=True, help="Layer number (1-19)")
    ap.add_argument("-o", "--output", type=Path, default=None)
    ap.add_argument("--scale", type=float, default=1.0, help="Channel scale factor (e.g. 0.1)")
    ap.add_argument("--seed", type=int, default=42)
    args = ap.parse_args()

    layers = alexnet_layers(scale=args.scale)
    target = None
    for lnum, lname, lspec in layers:
        if lnum == args.layer:
            target = (lnum, lname, lspec)
            break

    if target is None:
        raise ValueError(f"Layer {args.layer} not found (valid: 1-19)")

    lnum, lname, lspec = target
    rng = np.random.default_rng(args.seed)

    print(f"Building AlexNet layer {lnum}: {lname}")
    instr_text, img, expected = build_layer(lnum, lname, lspec, rng)

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)

    out_path = args.output or Path(f"tests/alexnet_layer{lnum}.in")
    os.makedirs(out_path.parent, exist_ok=True)
    out_path.write_text(final)
    print(f"Wrote {out_path}")
    print(f"Expected output shape: {np.array(expected).shape}")
    print(f"Expected output (first 10): {np.array(expected).flatten()[:10]}")


if __name__ == "__main__":
    main()
