"""Comprehensive Atalla benchmark suite.

Runs all kernel types at multiple sizes, collects metrics, and generates
publication-quality graphs.

Usage:
    python benchmark.py                    # run everything
    python benchmark.py --only-graphs      # re-plot from saved CSV
"""
from __future__ import annotations

import os, sys, time, math, struct, json, csv
from pathlib import Path
from dataclasses import dataclass, field, asdict
from typing import List, Dict, Optional
import argparse
import numpy as np

sys.path.insert(0, os.path.dirname(__file__))

from build import assemble_file, emit_test_format, DRAMWriter, render_testfile
from build_attention import make_attention_asm, f32_to_bf16
from build_gemm_tiled import make_tiled_gemm_asm, TILE
from build_conv_tiled import make_tiled_conv_asm, im2col
from build_maxpool import make_maxpool_asm
from build_alexnet_layer import (
    alexnet_layers, build_layer, make_relu_asm, make_softmax_asm,
    make_tiled_gemm_asm as layer_gemm_asm,
)
from src.functional_sim import run as run_emulator
from src.misc.memory import Memory
from src.components.scalar_register_file import ScalarRegisterFile
from src.components.vector_register_file import VectorRegisterFile
from src.components.execute import ExecuteUnit
from src.components.scpad import Scratchpad


# ---------------------------------------------------------------------------
# Data structures
# ---------------------------------------------------------------------------
@dataclass
class BenchResult:
    kernel: str
    params: str
    theoretical_flops: int
    wall_time_ms: float
    cycles: int = 0
    packets: int = 0
    instructions: int = 0
    branches: int = 0
    mem_ops: int = 0
    gemm_ops: int = 0
    sdma_ops: int = 0
    flops_total: int = 0
    flops_scalar: int = 0
    flops_vector: int = 0
    flops_matmul: int = 0
    bytes_loaded: int = 0
    arithmetic_intensity: float = 0.0


# ---------------------------------------------------------------------------
# Emulator runner
# ---------------------------------------------------------------------------
OUT_DIR = "out/bench"


def run_on_emulator(in_text: str, tag: str) -> Dict:
    os.makedirs(OUT_DIR, exist_ok=True)
    in_path = f"{OUT_DIR}/{tag}.in"
    Path(in_path).write_text(in_text)

    mem = Memory(in_path)
    sregs = ScalarRegisterFile()
    mregs = ScalarRegisterFile(num_regs=16)
    vregs = VectorRegisterFile()
    SP0 = Scratchpad(slots_per_bank=32)
    SP1 = Scratchpad(slots_per_bank=32)
    EU = ExecuteUnit()

    prefix = f"{OUT_DIR}/{tag}"
    t0 = time.time()
    run_emulator(
        mem, sregs, mregs, vregs, SP0, SP1, EU, 0, 4,
        f"{prefix}_mem.out", f"{prefix}_sregs.out", f"{prefix}_vregs.out",
        f"{prefix}_mregs.out", f"{prefix}_sp0.out", f"{prefix}_sp1.out",
        f"{prefix}_perf.out", debug=False,
    )
    wall_ms = (time.time() - t0) * 1000

    metrics = {}
    with open(f"{prefix}_perf.out") as f:
        for line in f:
            if ":" in line:
                k, v = line.strip().split(":", 1)
                try:
                    metrics[k.strip()] = float(v.strip())
                except ValueError:
                    pass
    metrics["wall_time_ms"] = wall_ms
    return metrics


# ---------------------------------------------------------------------------
# Kernel builders (return .in text + theoretical flops)
# ---------------------------------------------------------------------------
def build_gemm(M, N, K):
    M_tiles = math.ceil(M / TILE)
    N_tiles = math.ceil(N / TILE)
    K_tiles = math.ceil(K / TILE)

    asm = make_tiled_gemm_asm(M, N, K)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    AT = 60
    A_GMEM = 0x1000
    B_GMEM = A_GMEM + M * K * 2 + 0x1000
    C_GMEM = B_GMEM + K * N * 2 + 0x1000

    img.u32(AT + 0, A_GMEM); img.u32(AT + 4, B_GMEM); img.u32(AT + 8, C_GMEM)
    img.u32(AT + 12, M); img.u32(AT + 16, N); img.u32(AT + 20, K)
    img.u32(AT + 24, M_tiles); img.u32(AT + 28, N_tiles)
    img.u32(AT + 32, K_tiles); img.u32(AT + 36, TILE)

    rng = np.random.default_rng(0)
    A = rng.standard_normal((M, K)).astype(np.float32) * 0.5
    B = rng.standard_normal((K, N)).astype(np.float32) * 0.5

    for r in range(M):
        for c in range(K):
            img.bf16(A_GMEM + (r * K + c) * 2, float(A[r, c]))
    for r in range(K):
        for c in range(N):
            img.bf16(B_GMEM + (r * N + c) * 2, float(B[r, c]))
    for i in range(M * N):
        img.bf16(C_GMEM + i * 2, 0.0)

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)
    flops = 2 * M * N * K
    return final, flops


def build_conv(H, W, C, K_out, R, S, stride, pad):
    Ho = (H + 2 * pad - R) // stride + 1
    Wo = (W + 2 * pad - S) // stride + 1
    K_flat = R * S * C
    M = Ho * Wo
    M_tiles = math.ceil(M / TILE)
    N_tiles = math.ceil(K_out / TILE)
    K_tiles = math.ceil(K_flat / TILE)

    asm = make_tiled_conv_asm(M, K_flat, K_out)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    AT = 60
    A_GMEM = 0x1000
    W_GMEM = A_GMEM + M * K_flat * 2 + 0x1000
    C_GMEM = W_GMEM + K_flat * K_out * 2 + 0x1000

    img.u32(AT + 0, A_GMEM); img.u32(AT + 4, W_GMEM); img.u32(AT + 8, C_GMEM)
    img.u32(AT + 12, M); img.u32(AT + 16, K_out); img.u32(AT + 20, K_flat)
    img.u32(AT + 24, M_tiles); img.u32(AT + 28, N_tiles)
    img.u32(AT + 32, K_tiles); img.u32(AT + 36, TILE)

    rng = np.random.default_rng(0)
    ifmap = rng.standard_normal((1, H, W, C)).astype(np.float32) * 0.5
    weights = rng.standard_normal((R, S, C, K_out)).astype(np.float32) * 0.5
    A_mat = im2col(ifmap, 1, H, W, C, R, S, stride, pad)
    W_flat = weights.reshape(K_flat, K_out)

    for r in range(M):
        for c in range(K_flat):
            img.bf16(A_GMEM + (r * K_flat + c) * 2, float(A_mat[r, c]))
    for r in range(K_flat):
        for c in range(K_out):
            img.bf16(W_GMEM + (r * K_out + c) * 2, float(W_flat[r, c]))
    for i in range(M * K_out):
        img.bf16(C_GMEM + i * 2, 0.0)

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)
    flops = 2 * M * K_flat * K_out
    return final, flops


def build_attention(S, d):
    from build_attention import make_attention_asm
    asm = make_attention_asm(S, d)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    AT = 60
    Q_GMEM = 0x1000; Q_SCPAD = 0
    KT_GMEM = 0x2000; KT_SCPAD = 512
    V_GMEM = 0x3000; V_SCPAD = 1024
    OUT_GMEM = 0x4000; OUT_SCPAD = 0
    SCORES_SCPAD = 0

    inv_sqrt_d = 1.0 / math.sqrt(d)
    rng = np.random.default_rng(42)
    Q = rng.standard_normal((S, d)).astype(np.float32) * 0.5
    K = rng.standard_normal((S, d)).astype(np.float32) * 0.5
    V = rng.standard_normal((S, d)).astype(np.float32) * 0.5
    KT = K.T

    img = DRAMWriter()
    img.u32(AT + 0, Q_GMEM); img.u32(AT + 4, Q_SCPAD)
    img.u32(AT + 8, KT_GMEM); img.u32(AT + 12, KT_SCPAD)
    img.u32(AT + 16, V_GMEM); img.u32(AT + 20, V_SCPAD)
    img.u32(AT + 24, OUT_GMEM); img.u32(AT + 28, OUT_SCPAD)
    img.u32(AT + 32, SCORES_SCPAD)
    scale_bits = struct.unpack("<I", struct.pack("<f", inv_sqrt_d))[0]
    img.u32(AT + 36, scale_bits)

    for r in range(S):
        for c in range(d):
            img.bf16(Q_GMEM + (r * d + c) * 2, float(Q[r, c]))
    for r in range(d):
        for c in range(S):
            img.bf16(KT_GMEM + (r * S + c) * 2, float(KT[r, c]))
    for r in range(S):
        for c in range(d):
            img.bf16(V_GMEM + (r * d + c) * 2, float(V[r, c]))
    for i in range(S * d):
        img.bf16(OUT_GMEM + i * 2, 0.0)

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)
    # Q*K^T: 2*S*S*d, scale: S*S, softmax: ~5*S*S, attn*V: 2*S*d*S
    flops = 2 * S * S * d + S * S + 5 * S * S + 2 * S * d * S
    return final, flops


def build_relu_bench(total, width):
    width = min(width, 32)
    rows = math.ceil(total / width)
    sp_rows = min(rows, TILE)

    asm = make_relu_asm(total, width)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    AT = 60
    IN_GMEM = 0x1000
    OUT_GMEM = IN_GMEM + rows * width * 2 + 0x1000
    img.u32(AT + 0, IN_GMEM); img.u32(AT + 4, OUT_GMEM)

    rng = np.random.default_rng(0)
    data = rng.standard_normal(rows * width).astype(np.float32) * 0.5
    for i in range(rows * width):
        img.bf16(IN_GMEM + i * 2, float(data[i]))

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)
    flops = total  # 1 comparison per element
    return final, flops


def build_softmax_bench(length):
    asm = make_softmax_asm(length)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    AT = 60
    IN_GMEM = 0x1000
    width = min(length, 32)
    rows = math.ceil(length / 32)
    img.u32(AT + 0, IN_GMEM); img.u32(AT + 4, 0)

    rng = np.random.default_rng(0)
    data = rng.standard_normal(rows * width).astype(np.float32)
    for i in range(rows * width):
        img.bf16(IN_GMEM + i * 2, float(data[i]))

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)
    flops = 5 * length  # rmax + sub + exp + rsum + div
    return final, flops


# ---------------------------------------------------------------------------
# Benchmark runner
# ---------------------------------------------------------------------------
def run_benchmark(tag: str, kernel: str, params: str,
                  in_text: str, theo_flops: int) -> BenchResult:
    metrics = run_on_emulator(in_text, tag)
    return BenchResult(
        kernel=kernel, params=params, theoretical_flops=theo_flops,
        wall_time_ms=metrics.get("wall_time_ms", 0),
        cycles=int(metrics.get("cycles", 0)),
        packets=int(metrics.get("packets", 0)),
        instructions=int(metrics.get("instructions", 0)),
        branches=int(metrics.get("branches", 0)),
        mem_ops=int(metrics.get("mem_ops", 0)),
        gemm_ops=int(metrics.get("gemm_ops", 0)),
        sdma_ops=int(metrics.get("sdma_ops", 0)),
        flops_total=int(metrics.get("flops_total", 0)),
        flops_scalar=int(metrics.get("flops_scalar", 0)),
        flops_vector=int(metrics.get("flops_vector", 0)),
        flops_matmul=int(metrics.get("flops_matmul", 0)),
        bytes_loaded=int(metrics.get("bytes_loaded", 0)),
        arithmetic_intensity=metrics.get("arithmetic_intensity", 0),
    )


def run_all_benchmarks() -> List[BenchResult]:
    results = []

    # --- GEMM scaling ---
    for N in [4, 8, 16, 32, 64]:
        print(f"  GEMM {N}x{N}x{N}...", end="", flush=True)
        text, flops = build_gemm(N, N, N)
        r = run_benchmark(f"gemm_{N}", "GEMM", f"{N}x{N}x{N}", text, flops)
        results.append(r)
        print(f" {r.cycles} cyc, {r.instructions} instr")

    # --- Conv scaling ---
    conv_configs = [
        (4, 4, 3, 4, 3, 3, 1, 0, "4x4x3->4"),
        (8, 8, 3, 4, 3, 3, 1, 0, "8x8x3->4"),
        (13, 13, 4, 8, 3, 3, 1, 1, "13x13x4->8"),
        (16, 16, 8, 8, 3, 3, 1, 1, "16x16x8->8"),
        (16, 16, 8, 16, 3, 3, 1, 1, "16x16x8->16"),
    ]
    for H, W, C, K, R, S, stride, pad, label in conv_configs:
        print(f"  Conv {label}...", end="", flush=True)
        text, flops = build_conv(H, W, C, K, R, S, stride, pad)
        r = run_benchmark(f"conv_{label}", "Conv", label, text, flops)
        results.append(r)
        print(f" {r.cycles} cyc, {r.instructions} instr")

    # --- Attention scaling ---
    for S in [4, 8, 16, 32]:
        d = S
        print(f"  Attention S={S},d={d}...", end="", flush=True)
        text, flops = build_attention(S, d)
        r = run_benchmark(f"attn_{S}", "Attention", f"S={S},d={d}", text, flops)
        results.append(r)
        print(f" {r.cycles} cyc, {r.instructions} instr")

    # --- ReLU scaling ---
    for total in [32, 128, 512, 1024]:
        print(f"  ReLU {total}...", end="", flush=True)
        text, flops = build_relu_bench(total, 32)
        r = run_benchmark(f"relu_{total}", "ReLU", f"N={total}", text, flops)
        results.append(r)
        print(f" {r.cycles} cyc, {r.instructions} instr")

    # --- Softmax scaling ---
    for length in [4, 8, 16, 32]:
        print(f"  Softmax {length}...", end="", flush=True)
        text, flops = build_softmax_bench(length)
        r = run_benchmark(f"softmax_{length}", "Softmax", f"N={length}", text, flops)
        results.append(r)
        print(f" {r.cycles} cyc, {r.instructions} instr")

    # --- AlexNet layer-by-layer ---
    layers = alexnet_layers(scale=0.01)
    for lnum, lname, lspec in layers:
        if lname == "maxpool":
            continue
        print(f"  AlexNet L{lnum} ({lname})...", end="", flush=True)
        layer_rng = np.random.default_rng(42 + lnum)
        w = None
        if lname == "conv":
            w = layer_rng.standard_normal(
                (lspec.R, lspec.S, lspec.C_in, lspec.C_out)
            ).astype(np.float32) * 0.1
        elif lname == "fc":
            w = layer_rng.standard_normal(
                (lspec.in_features, lspec.out_features)
            ).astype(np.float32) * 0.1

        try:
            instr_text, img, expected = build_layer(
                lnum, lname, lspec, layer_rng, weights=w)
        except Exception as e:
            print(f" SKIP ({e})")
            continue

        data_text = img.render_data_mem(include_zeros=True)
        final = render_testfile(instr_text, data_text)

        if lname == "conv":
            s = lspec
            Ho = (s.H + 2*s.pad - s.R) // s.stride + 1
            Wo = (s.W + 2*s.pad - s.S) // s.stride + 1
            theo = 2 * Ho * Wo * s.R * s.S * s.C_in * s.C_out
        elif lname == "fc":
            theo = 2 * lspec.in_features * lspec.out_features
        elif lname == "relu":
            theo = lspec.total_elements
        elif lname == "softmax":
            theo = 5 * lspec.length
        else:
            theo = 0

        r = run_benchmark(f"alexnet_L{lnum}", f"AlexNet-{lname}",
                         f"L{lnum}", final, theo)
        results.append(r)
        print(f" {r.cycles} cyc, {r.instructions} instr")

    return results


# ---------------------------------------------------------------------------
# CSV I/O
# ---------------------------------------------------------------------------
CSV_PATH = f"{OUT_DIR}/benchmark_results.csv"


def save_csv(results: List[BenchResult]):
    os.makedirs(OUT_DIR, exist_ok=True)
    fields = list(asdict(results[0]).keys())
    with open(CSV_PATH, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=fields)
        w.writeheader()
        for r in results:
            w.writerow(asdict(r))
    print(f"\nSaved {len(results)} results to {CSV_PATH}")


def load_csv() -> List[BenchResult]:
    results = []
    with open(CSV_PATH) as f:
        reader = csv.DictReader(f)
        for row in reader:
            for k in row:
                if k in ("kernel", "params"):
                    continue
                try:
                    row[k] = float(row[k])
                except ValueError:
                    pass
            results.append(BenchResult(**row))
    return results


# ---------------------------------------------------------------------------
# Plotting
# ---------------------------------------------------------------------------
def generate_graphs(results: List[BenchResult]):
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    from matplotlib.ticker import MaxNLocator

    os.makedirs(f"{OUT_DIR}/graphs", exist_ok=True)

    # Color palette
    COLORS = {
        "GEMM": "#2196F3", "Conv": "#4CAF50", "Attention": "#FF9800",
        "ReLU": "#E91E63", "Softmax": "#9C27B0",
        "AlexNet-conv": "#1565C0", "AlexNet-relu": "#C62828",
        "AlexNet-fc": "#2E7D32", "AlexNet-softmax": "#6A1B9A",
    }

    def color_for(kernel):
        return COLORS.get(kernel, "#607D8B")

    # ---- 1. GEMM Scaling: Cycles & Instructions vs Problem Size ----
    gemm = [r for r in results if r.kernel == "GEMM"]
    if gemm:
        sizes = [int(r.params.split("x")[0]) for r in gemm]
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 5))

        ax1.bar(range(len(sizes)), [int(r.cycles) for r in gemm],
                color=COLORS["GEMM"], alpha=0.85)
        ax1.set_xticks(range(len(sizes)))
        ax1.set_xticklabels([f"{s}x{s}" for s in sizes])
        ax1.set_xlabel("Matrix Size (NxN)")
        ax1.set_ylabel("Cycles")
        ax1.set_title("GEMM: Cycles vs Problem Size")
        ax1.yaxis.set_major_locator(MaxNLocator(integer=True))

        ax2.bar(range(len(sizes)), [int(r.instructions) for r in gemm],
                color=COLORS["GEMM"], alpha=0.65)
        ax2.set_xticks(range(len(sizes)))
        ax2.set_xticklabels([f"{s}x{s}" for s in sizes])
        ax2.set_xlabel("Matrix Size (NxN)")
        ax2.set_ylabel("Instructions")
        ax2.set_title("GEMM: Instructions vs Problem Size")
        ax2.yaxis.set_major_locator(MaxNLocator(integer=True))

        plt.tight_layout()
        plt.savefig(f"{OUT_DIR}/graphs/01_gemm_scaling.png", dpi=150)
        plt.close()

    # ---- 2. GEMM Throughput (GFLOPS @ 1GHz) ----
    if gemm:
        fig, ax = plt.subplots(figsize=(8, 5))
        gflops = [int(r.theoretical_flops) / max(int(r.cycles), 1) for r in gemm]
        ax.plot(sizes, gflops, "o-", color=COLORS["GEMM"], linewidth=2, markersize=8)
        ax.set_xlabel("Matrix Size N (NxNxN GEMM)")
        ax.set_ylabel("FLOPS / Cycle")
        ax.set_title("GEMM: Compute Throughput (FLOPS/Cycle)")
        ax.grid(True, alpha=0.3)
        plt.tight_layout()
        plt.savefig(f"{OUT_DIR}/graphs/02_gemm_throughput.png", dpi=150)
        plt.close()

    # ---- 3. Conv Scaling ----
    conv = [r for r in results if r.kernel == "Conv"]
    if conv:
        fig, ax = plt.subplots(figsize=(10, 5))
        labels = [r.params for r in conv]
        cyc = [int(r.cycles) for r in conv]
        instr = [int(r.instructions) for r in conv]

        x = np.arange(len(labels))
        w = 0.35
        ax.bar(x - w/2, cyc, w, label="Cycles", color=COLORS["Conv"], alpha=0.85)
        ax.bar(x + w/2, instr, w, label="Instructions", color=COLORS["Conv"], alpha=0.5)
        ax.set_xticks(x)
        ax.set_xticklabels(labels, rotation=20, ha="right")
        ax.set_ylabel("Count")
        ax.set_title("Conv (Tiled im2col GEMM): Scaling")
        ax.legend()
        ax.yaxis.set_major_locator(MaxNLocator(integer=True))
        plt.tight_layout()
        plt.savefig(f"{OUT_DIR}/graphs/03_conv_scaling.png", dpi=150)
        plt.close()

    # ---- 4. Attention Scaling ----
    attn = [r for r in results if r.kernel == "Attention"]
    if attn:
        sizes_attn = [int(r.params.split(",")[0].split("=")[1]) for r in attn]
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 5))

        ax1.plot(sizes_attn, [int(r.cycles) for r in attn], "o-",
                color=COLORS["Attention"], linewidth=2, markersize=8)
        ax1.set_xlabel("Sequence Length S")
        ax1.set_ylabel("Cycles")
        ax1.set_title("Attention: Cycles vs Sequence Length")
        ax1.grid(True, alpha=0.3)

        ax2.plot(sizes_attn, [int(r.instructions) for r in attn], "s-",
                color=COLORS["Attention"], linewidth=2, markersize=8)
        ax2.set_xlabel("Sequence Length S")
        ax2.set_ylabel("Instructions")
        ax2.set_title("Attention: Instructions vs Sequence Length")
        ax2.grid(True, alpha=0.3)

        plt.tight_layout()
        plt.savefig(f"{OUT_DIR}/graphs/04_attention_scaling.png", dpi=150)
        plt.close()

    # ---- 5. Kernel Comparison: Cycles per FLOP ----
    kernels_for_cmp = ["GEMM", "Conv", "Attention", "ReLU", "Softmax"]
    fig, ax = plt.subplots(figsize=(10, 6))
    for kname in kernels_for_cmp:
        subset = [r for r in results if r.kernel == kname]
        if not subset:
            continue
        cpf = [max(int(r.cycles), 1) / max(int(r.theoretical_flops), 1) for r in subset]
        labels = [r.params for r in subset]
        ax.plot(range(len(subset)), cpf, "o-", label=kname,
                color=color_for(kname), linewidth=2, markersize=6)
    ax.set_ylabel("Cycles / Theoretical FLOP")
    ax.set_xlabel("Config (ascending size)")
    ax.set_title("Compute Efficiency: Cycles per Theoretical FLOP")
    ax.legend()
    ax.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig(f"{OUT_DIR}/graphs/05_cycles_per_flop.png", dpi=150)
    plt.close()

    # ---- 6. Instruction Mix (stacked bar) ----
    fig, ax = plt.subplots(figsize=(12, 6))
    all_labels = []
    scalar_f, vector_f, branch_f, mem_f, gemm_f = [], [], [], [], []
    for r in results:
        total_i = max(int(r.instructions), 1)
        all_labels.append(f"{r.kernel}\n{r.params}")
        # Approximate breakdown: gemm, mem (sdma+mem_ops), branches, vector flops, scalar
        g = int(r.gemm_ops)
        m = int(r.sdma_ops) + int(r.mem_ops)
        b = int(r.branches)
        v = int(r.flops_vector)
        s = total_i - g - m - b
        gemm_f.append(g / total_i * 100)
        mem_f.append(m / total_i * 100)
        branch_f.append(b / total_i * 100)
        vector_f.append(max(0, (v / total_i * 100) if v else 0))
        scalar_f.append(max(0, s / total_i * 100))

    x = np.arange(len(all_labels))
    # Only plot a subset if too many
    if len(x) > 20:
        step = max(1, len(x) // 20)
        idx = list(range(0, len(x), step))
        x = np.arange(len(idx))
        all_labels = [all_labels[i] for i in idx]
        gemm_f = [gemm_f[i] for i in idx]
        mem_f = [mem_f[i] for i in idx]
        branch_f = [branch_f[i] for i in idx]
        scalar_f = [scalar_f[i] for i in idx]

    bottom = np.zeros(len(x))
    ax.bar(x, gemm_f, 0.6, bottom=bottom, label="GEMM ops", color="#1565C0")
    bottom += np.array(gemm_f)
    ax.bar(x, mem_f, 0.6, bottom=bottom, label="Memory ops", color="#4CAF50")
    bottom += np.array(mem_f)
    ax.bar(x, branch_f, 0.6, bottom=bottom, label="Branches", color="#FF9800")
    bottom += np.array(branch_f)
    ax.bar(x, scalar_f, 0.6, bottom=bottom, label="Scalar/Other", color="#9E9E9E")

    ax.set_xticks(x)
    ax.set_xticklabels(all_labels, rotation=45, ha="right", fontsize=7)
    ax.set_ylabel("% of Instructions")
    ax.set_title("Instruction Mix Breakdown")
    ax.legend(loc="upper right")
    ax.set_ylim(0, 110)
    plt.tight_layout()
    plt.savefig(f"{OUT_DIR}/graphs/06_instruction_mix.png", dpi=150)
    plt.close()

    # ---- 7. Arithmetic Intensity ----
    fig, ax = plt.subplots(figsize=(10, 5))
    ai_data = [(f"{r.kernel}\n{r.params}", float(r.arithmetic_intensity))
               for r in results if float(r.arithmetic_intensity) > 0]
    if ai_data:
        if len(ai_data) > 20:
            step = max(1, len(ai_data) // 20)
            ai_data = ai_data[::step]
        labels_ai, vals_ai = zip(*ai_data)
        colors_ai = ["#2196F3" if v > 1 else "#FF5722" for v in vals_ai]
        ax.barh(range(len(vals_ai)), vals_ai, color=colors_ai, alpha=0.8)
        ax.set_yticks(range(len(labels_ai)))
        ax.set_yticklabels(labels_ai, fontsize=7)
        ax.set_xlabel("Arithmetic Intensity (FLOPS / Byte loaded)")
        ax.set_title("Arithmetic Intensity (Roofline metric)")
        ax.axvline(x=1.0, color="gray", linestyle="--", alpha=0.5, label="AI=1.0")
        ax.legend()
    plt.tight_layout()
    plt.savefig(f"{OUT_DIR}/graphs/07_arithmetic_intensity.png", dpi=150)
    plt.close()

    # ---- 8. AlexNet Layer-by-Layer Breakdown ----
    alexnet = [r for r in results if r.kernel.startswith("AlexNet")]
    if alexnet:
        fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12, 8))

        layer_labels = [r.params for r in alexnet]
        layer_cycles = [int(r.cycles) for r in alexnet]
        layer_types = [r.kernel.split("-")[1] for r in alexnet]
        layer_colors = [color_for(r.kernel) for r in alexnet]

        ax1.bar(range(len(layer_labels)), layer_cycles, color=layer_colors, alpha=0.85)
        ax1.set_xticks(range(len(layer_labels)))
        ax1.set_xticklabels(layer_labels)
        ax1.set_ylabel("Cycles")
        ax1.set_title("AlexNet (scale=0.01): Cycles per Layer")
        ax1.yaxis.set_major_locator(MaxNLocator(integer=True))

        # Pie chart of cycle distribution by type
        type_cycles = {}
        for r in alexnet:
            t = r.kernel.split("-")[1]
            type_cycles[t] = type_cycles.get(t, 0) + int(r.cycles)
        labels_pie = list(type_cycles.keys())
        vals_pie = list(type_cycles.values())
        colors_pie = [color_for(f"AlexNet-{t}") for t in labels_pie]
        ax2.pie(vals_pie, labels=labels_pie, colors=colors_pie, autopct="%1.1f%%",
                startangle=90)
        ax2.set_title("AlexNet: Cycle Distribution by Layer Type")

        plt.tight_layout()
        plt.savefig(f"{OUT_DIR}/graphs/08_alexnet_breakdown.png", dpi=150)
        plt.close()

    # ---- 9. Wall-Clock Time vs Problem Size ----
    fig, ax = plt.subplots(figsize=(10, 5))
    for kname in kernels_for_cmp:
        subset = [r for r in results if r.kernel == kname]
        if not subset:
            continue
        ax.plot(range(len(subset)),
                [float(r.wall_time_ms) for r in subset],
                "o-", label=kname, color=color_for(kname), linewidth=2, markersize=6)
    ax.set_ylabel("Wall-Clock Time (ms)")
    ax.set_xlabel("Config (ascending size)")
    ax.set_title("Emulator Wall-Clock Time")
    ax.legend()
    ax.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig(f"{OUT_DIR}/graphs/09_wall_time.png", dpi=150)
    plt.close()

    # ---- 10. GEMM Roofline-style: FLOPS/Cycle vs Arithmetic Intensity ----
    if gemm:
        fig, ax = plt.subplots(figsize=(8, 5))
        ai_vals = [float(r.arithmetic_intensity) for r in gemm]
        perf_vals = [int(r.theoretical_flops) / max(int(r.cycles), 1) for r in gemm]
        ax.scatter(ai_vals, perf_vals, c=COLORS["GEMM"], s=100, zorder=5)
        for i, r in enumerate(gemm):
            ax.annotate(r.params, (ai_vals[i], perf_vals[i]),
                       textcoords="offset points", xytext=(5, 5), fontsize=8)
        ax.set_xlabel("Arithmetic Intensity (FLOPS/Byte)")
        ax.set_ylabel("Performance (FLOPS/Cycle)")
        ax.set_title("GEMM Roofline Plot")
        ax.set_xscale("log")
        ax.grid(True, alpha=0.3)
        plt.tight_layout()
        plt.savefig(f"{OUT_DIR}/graphs/10_gemm_roofline.png", dpi=150)
        plt.close()

    # ---- 11. Summary Table (text) ----
    with open(f"{OUT_DIR}/graphs/summary.txt", "w") as f:
        f.write(f"{'Kernel':<12} {'Params':<20} {'Cycles':>8} {'Instr':>8} "
                f"{'GEMM':>6} {'SDMA':>6} {'Branch':>6} {'AI':>8} "
                f"{'TheoFLOP':>10} {'FLOP/cyc':>10} {'Wall(ms)':>10}\n")
        f.write("-" * 120 + "\n")
        for r in results:
            flop_cyc = int(r.theoretical_flops) / max(int(r.cycles), 1)
            f.write(f"{r.kernel:<12} {r.params:<20} {int(r.cycles):>8} "
                    f"{int(r.instructions):>8} {int(r.gemm_ops):>6} "
                    f"{int(r.sdma_ops):>6} {int(r.branches):>6} "
                    f"{float(r.arithmetic_intensity):>8.2f} "
                    f"{int(r.theoretical_flops):>10} {flop_cyc:>10.2f} "
                    f"{float(r.wall_time_ms):>10.1f}\n")

    print(f"\nGenerated 11 graphs + summary in {OUT_DIR}/graphs/")


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------
def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only-graphs", action="store_true")
    args = ap.parse_args()

    if args.only_graphs:
        results = load_csv()
    else:
        print("=" * 60)
        print("Atalla Benchmark Suite")
        print("=" * 60)
        t0 = time.time()
        results = run_all_benchmarks()
        save_csv(results)
        print(f"\nBenchmarks complete in {time.time() - t0:.1f}s")

    generate_graphs(results)


if __name__ == "__main__":
    main()
