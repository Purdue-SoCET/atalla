#!/usr/bin/env python3
# Fused demo: layernorm + ReLU(attn_ref+LN) + row-softmax; attn_ref is Python-precomputed in GMEM (no QKV matmul in ASM); real QKV kernel → build_attention.py.
from __future__ import annotations

import argparse
import os
import struct
from pathlib import Path

import numpy as np

try:
    from .build import *
except Exception:
    try:
        from functional_sim.build import *
    except Exception:
        from build import *

try:
    from .build_layernorm_param import unroll_layernorm
except Exception:
    from build_layernorm_param import unroll_layernorm


def load_tile_data(data_path: Path, n: int) -> list[float]:
    tile = np.loadtxt(data_path, delimiter=",")
    if tile.ndim == 1:
        tile = tile.reshape(1, -1)
    if tile.shape != (n, n):
        raise ValueError(f"Tile shape mismatch: expected ({n}, {n}), got {tile.shape}.")
    return tile.flatten(order="C").tolist()


def _emit_fused_attention_post_ln(
    n: int,
    *,
    addr_table_base: int,
    rsum_imm: int,
    sid: int = 0,
) -> str:
    if n < 1 or n > 32:
        raise ValueError("n must be in [1, 32] (lane / SDMA 5-bit limits).")

    mc = n - 1
    x0 = 64
    attn_b = x0 + n
    sum_b = x0 + 2 * n
    relu_b = x0 + 3 * n
    b_b = x0 + 4 * n
    if relu_b + n - 1 > 255 or b_b + n - 1 > 255:
        raise ValueError("vector register indices overflow")

    lines: list[str] = []

    def ln(s: str) -> None:
        lines.append(f"        {s}")

    ln("# --- fused attention tail (post layernorm) ---")
    ln(f"addi.s   $1, $0, {addr_table_base}")
    ln("lw.s     $2, 0($1)                    # gmem input (LN output)")
    ln("lw.s     $3, 4($1)                    # scpad base")
    ln(f"scpad.ld $3, $2, {mc}, {mc}, {sid}    # refresh LN(x) in scpad")
    for i in range(n):
        ln(f"vreg.ld  ${x0 + i}, $3, {mc}, {mc}, {sid}, 1, {i}    # LN row {i}")

    ln("lw.s     $15, 32($1)                  # attn gmem")
    ln(f"scpad.ld $3, $15, {mc}, {mc}, {sid}")
    for i in range(n):
        ln(f"vreg.ld  ${attn_b + i}, $3, {mc}, {mc}, {sid}, 1, {i}    # attn row {i}")

    ln("li.s     $19, 0")
    ln(f"mul.vs   $11, ${x0}, $19, 1          # zero vector for ReLU")
    for i in range(n):
        ln(f"add.vv   ${sum_b + i}, ${attn_b + i}, ${x0 + i}, 1, 0")
        ln(f"mgt.mvv  2, ${sum_b + i}, $11, 1")
        ln(f"mul.vs   ${relu_b + i}, $11, $19, 1")
        ln(f"add.vv   ${relu_b + i}, ${sum_b + i}, $11, 2, 0")

    ln("lw.s     $8, 24($1)                   # W gmem")
    ln(f"scpad.ld $3, $8, {mc}, {mc}, {sid}")
    for i in reversed(range(n)):
        ln(f"vreg.ld  $11, $3, {mc}, {mc}, {sid}, 1, {i}")
        ln("lw.vi    $11, $11, 0, 0xf")

    ln("lw.s     $9, 28($1)                   # second tile (B) gmem")
    ln(f"scpad.ld $3, $9, {mc}, {mc}, {sid}")
    for i in range(n):
        ln(f"vreg.ld  ${b_b + i}, $3, {mc}, {mc}, {sid}, 1, {i}")

    for i in range(n):
        ln(f"gemm.vv  ${relu_b + i}, ${relu_b + i}, ${b_b + i}, 0, 0")

    for i in range(n):
        r = relu_b + i
        ln(f"rmax.vi  $90, ${r}, 0, 1")
        ln("vmov.vts $14, $90, 0")
        ln(f"sub.vs   ${r}, ${r}, $14, 1")
        ln(f"expi.vi  $90, ${r}, 0, 1")
        ln(f"rsum.vi  $91, $90, {rsum_imm}, 1")
        ln("vmov.vts $14, $91, 0")
        ln("rcp.bf   $14, $14, $0")
        ln(f"mul.vs   ${r}, $90, $14, 1")

    ln("lw.s     $17, 20($1)                  # output gmem")
    for i in range(n):
        ln(f"vreg.st  ${relu_b + i}, $3, {mc}, {mc}, {sid}, 1, {i}")
    ln(f"scpad.st $3, $17, {mc}, {mc}, {sid}")
    ln("halt.s")

    return "\n".join(lines)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input", type=Path, default=None)
    ap.add_argument("-o", "--output", type=Path, default=Path("./tests/attention_fused_layernorm.in"))
    ap.add_argument(
        "--latency",
        action="store_true",
        help="Experimental: DAG + greedy_pack with latency rows in static .in.",
    )
    ap.add_argument("--graph", action="store_true", help=argparse.SUPPRESS)
    ap.add_argument("--no-graph", action="store_true", help=argparse.SUPPRESS)
    ap.add_argument("--data", type=Path, default=None)
    ap.add_argument("--n", type=int, default=32, help="N×N fused demo (default 32; max 32)")
    ap.add_argument("--seed", type=int, default=0)
    args = ap.parse_args()
    use_latency_pack = bool(args.latency or args.graph)
    if use_latency_pack and args.no_graph:
        ap.error("Do not combine --no-graph with --latency")

    n = args.n
    if n < 1 or n > 32:
        raise ValueError("n must be in [1, 32].")

    ADDR_TABLE_BASE = 0x0000_0040
    EPSILON_LOCATION = 0x0000_0020
    TILE_ADDR_INPUT = 0x0000_1000
    TILE_ADDR_Q = 0x0000_2000
    TILE_ADDR_K = 0x0000_3000
    TILE_ADDR_V = 0x0000_4000
    TILE_ADDR_OUTPUT = 0x0000_5000
    TILE_ADDR_W = 0x0000_6000
    TILE_ADDR_B = 0x0000_7000
    TILE_ADDR_ATTN = 0x0000_8000

    SCPAD_ADDR = 0
    SID0 = 0
    RSUM_IMM = 64

    rng = np.random.default_rng(args.seed)
    Q = rng.standard_normal((n, n)).astype(np.float32)
    K = rng.standard_normal((n, n)).astype(np.float32)
    V = rng.standard_normal((n, n)).astype(np.float32)
    W = rng.standard_normal((n, n)).astype(np.float32)

    scale = 1.0 / np.sqrt(float(n))
    scores = (Q @ K.T) * scale
    s_exp = np.exp(scores - scores.max(axis=1, keepdims=True))
    attn_ref = (s_exp / s_exp.sum(axis=1, keepdims=True)) @ V

    if args.data is not None:
        input_values = load_tile_data(args.data, n)
    else:
        input_values = [float(v) for v in range(4, 4 + n * n)]
    X_ref = np.array(input_values, dtype=np.float32).reshape(n, n)

    x_ln_ref = (X_ref - X_ref.mean()) / (X_ref.var() + 1e-5) ** 0.5
    u_ref = np.maximum(0, attn_ref + x_ln_ref)
    linear_out = u_ref @ W
    shifted = linear_out - linear_out.max(axis=1, keepdims=True)
    exp_out = np.exp(shifted)
    y_ref = exp_out / exp_out.sum(axis=1, keepdims=True)

    ln_asm = unroll_layernorm(
        n,
        tile_addr_location=ADDR_TABLE_BASE,
        epsilon_location=EPSILON_LOCATION,
        sid=SID0,
        rsum_imm=RSUM_IMM,
        halt=False,
    )
    tail_asm = _emit_fused_attention_post_ln(n, addr_table_base=ADDR_TABLE_BASE, rsum_imm=RSUM_IMM, sid=SID0)
    asm = ln_asm + "\n" + tail_asm

    instrs = assemble_file(asm)
    if use_latency_pack:
        dependency_instrs = convert_instructions(instrs)
        ready = build_dependency_graph(dependency_instrs, DEFAULT_LATENCY_MAP)
        packets = greedy_pack(dependency_instrs, ready, max_width=GRAPH_PACKET_WIDTH)
        scheduled = materialize_scheduled_instructions(instrs, packets, packet_width=GRAPH_PACKET_WIDTH)
        instr_text = emit_test_format(scheduled, virtual_packet_size=GRAPH_PACKET_WIDTH)
    else:
        instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(ADDR_TABLE_BASE + 0, TILE_ADDR_INPUT)
    img.u32(ADDR_TABLE_BASE + 4, SCPAD_ADDR)
    img.u32(ADDR_TABLE_BASE + 8, TILE_ADDR_Q)
    img.u32(ADDR_TABLE_BASE + 12, TILE_ADDR_K)
    img.u32(ADDR_TABLE_BASE + 16, TILE_ADDR_V)
    img.u32(ADDR_TABLE_BASE + 20, TILE_ADDR_OUTPUT)
    img.u32(ADDR_TABLE_BASE + 24, TILE_ADDR_W)
    img.u32(ADDR_TABLE_BASE + 28, TILE_ADDR_B)
    img.u32(ADDR_TABLE_BASE + 32, TILE_ADDR_ATTN)
    img.f32(EPSILON_LOCATION, 1e-5)

    for i, val in enumerate(input_values):
        img.bf16(TILE_ADDR_INPUT + i * 2, val)
    for i, val in enumerate(Q.flatten()):
        img.bf16(TILE_ADDR_Q + i * 2, float(val))
    for i, val in enumerate(K.flatten()):
        img.bf16(TILE_ADDR_K + i * 2, float(val))
    for i, val in enumerate(V.flatten()):
        img.bf16(TILE_ADDR_V + i * 2, float(val))
    for i in range(n):
        for j in range(n):
            img.bf16(TILE_ADDR_ATTN + (i * n + j) * 2, float(attn_ref[i, j]))
    WT = W.T
    for r in range(n):
        for c in range(n):
            img.bf16(TILE_ADDR_W + (r * n + c) * 2, float(WT[r, c]))
    for r in range(n):
        for c in range(n):
            img.bf16(TILE_ADDR_B + (r * n + c) * 2, float(V[r, c]))
    for i in range(n * n):
        img.bf16(TILE_ADDR_OUTPUT + i * 2, 0.0)

    final = render_testfile(instr_text, img.render_data_mem(include_zeros=False))
    os.makedirs(args.output.parent, exist_ok=True)
    args.output.write_text(final)
    print(f"[INFO] Written to {args.output} (n={n})")
    print(f"[INFO] ref output[0,:4]={y_ref[0, :4]}")


if __name__ == "__main__":
    main()
