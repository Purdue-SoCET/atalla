#!/usr/bin/env python3
from __future__ import annotations

import argparse
import math
import os
import shutil
import struct
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path

import numpy as np

ROOT = Path(__file__).resolve().parent
WORKSPACE = ROOT.parent
if str(WORKSPACE) not in sys.path:
    sys.path.insert(0, str(WORKSPACE))

from functional_sim.build_flash_attention import flash_attention_online_ref, q_bf16
try:
    import torch
except ModuleNotFoundError as exc:
    _venv_py = ROOT / ".venv" / "bin" / "python"
    if _venv_py.exists() and Path(sys.executable) != _venv_py:
        os.execv(str(_venv_py), [str(_venv_py), __file__, *sys.argv[1:]])
    raise RuntimeError(
        "PyTorch is required for validation. Install it (recommended in functional_sim/.venv)."
    ) from exc

@dataclass
class KernelResult:
    name: str
    status: str
    cosine_sim: float = 0.0
    max_error: float = 0.0
    mean_error: float = 0.0
    packets: int = 0
    instructions: int = 0
    slot_utilization: float = 0.0
    emulator_packets: int = 0
    emulator_instructions: int = 0
    error_msg: str = ""

    def summary_line(self) -> str:
        if self.status == "ERROR":
            return f"  {self.name:20s} ERROR {self.error_msg[:120]}"
        return f"  {self.name:20s} {self.status:4s}  cos={self.cosine_sim:.4f}  max_err={self.max_error:.6f}"


def run(cmd: list[str], cwd: Path = WORKSPACE) -> None:
    proc = subprocess.run(cmd, cwd=str(cwd), text=True, capture_output=True, timeout=240)
    if proc.returncode != 0:
        raise RuntimeError(f"Command failed: {' '.join(cmd)}\n{proc.stdout}\n{proc.stderr}")


def bf16_to_f32(bits: int) -> np.float32:
    return np.float32(struct.unpack("<f", struct.pack("<I", (int(bits) & 0xFFFF) << 16))[0])


def read_mem_dump(path: Path) -> dict[int, int]:
    out: dict[int, int] = {}
    in_data = False
    for line in path.read_text().splitlines():
        if line.strip().upper() == "DATA MEM":
            in_data = True
            continue
        if not in_data or ":" not in line:
            continue
        a, v = [x.strip() for x in line.split(":", 1)]
        if len(v) != 8:
            continue
        out[int(a, 16)] = int(v, 16)
    return out


def read_bf16(mem: dict[int, int], base: int, count: int) -> np.ndarray:
    out = np.zeros(count, dtype=np.float32)
    for i in range(count):
        out[i] = bf16_to_f32(mem.get(base + 2 * i, 0) & 0xFFFF)
    return out


def compare(actual: np.ndarray, expected: np.ndarray) -> tuple[float, float, float]:
    a = actual.flatten().astype(np.float64)
    e = expected.flatten().astype(np.float64)
    dot = float(np.dot(a, e))
    na = float(np.linalg.norm(a))
    ne = float(np.linalg.norm(e))
    cos = dot / (na * ne) if na > 0 and ne > 0 else 0.0
    diff = np.abs(a - e)
    return cos, float(np.max(diff)), float(np.mean(diff))


def compare_dual(actual: np.ndarray, expected_np: np.ndarray, expected_torch: np.ndarray) -> tuple[float, float, float]:
    cos_np, max_np, mean_np = compare(actual, expected_np)
    cos_t, max_t, mean_t = compare(actual, expected_torch)
    return min(cos_np, cos_t), max(max_np, max_t), max(mean_np, mean_t)


def parse_instruction_metrics(in_path: Path) -> tuple[int, int]:
    packets = 0
    instructions = 0
    for line in in_path.read_text().splitlines():
        if line.strip().upper() == "DATA MEM":
            break
        if ":" not in line:
            continue
        payload = line.split(":", 1)[1].split("#", 1)[0].strip()
        toks = payload.split()
        if len(toks) < 4:
            continue
        packets += 1
        instructions += sum(1 for t in toks[:4] if t.lower() != "000000000031")
    return packets, instructions


def parse_perf(path: Path) -> dict[str, float]:
    out: dict[str, float] = {}
    if not path.exists():
        return out
    for line in path.read_text().splitlines():
        if ":" not in line:
            continue
        k, v = [x.strip() for x in line.split(":", 1)]
        try:
            out[k] = float(v)
        except ValueError:
            pass
    return out


def run_kernel(builder: str, name: str, work_dir: Path, extra_args: list[str] | None = None) -> tuple[Path, dict[str, float], int, int]:
    extra_args = extra_args or []
    in_path = work_dir / f"{name}.in"
    mem_path = work_dir / f"{name}_mem.out"
    perf_path = work_dir / f"{name}_perf.out"
    run([sys.executable, "-m", f"functional_sim.{builder}", "-o", str(in_path), *extra_args])
    packets, instructions = parse_instruction_metrics(in_path)
    run([
        sys.executable, "-m", "functional_sim.run",
        "--input_file", str(in_path),
        "--output_mem_file", str(mem_path),
        "--output_perf_file", str(perf_path),
    ])
    return mem_path, parse_perf(perf_path), packets, instructions


def run_generated(name: str, in_text: str, work_dir: Path) -> tuple[Path, dict[str, float], int, int]:
    in_path = work_dir / f"{name}.in"
    mem_path = work_dir / f"{name}_mem.out"
    perf_path = work_dir / f"{name}_perf.out"
    in_path.write_text(in_text)
    packets, instructions = parse_instruction_metrics(in_path)
    run([
        sys.executable, "-m", "functional_sim.run",
        "--input_file", str(in_path),
        "--output_mem_file", str(mem_path),
        "--output_perf_file", str(perf_path),
    ])
    return mem_path, parse_perf(perf_path), packets, instructions


def pack_result(name: str, cos: float, max_err: float, mean_err: float, packets: int, instructions: int, perf: dict[str, float], cos_pass: float) -> KernelResult:
    return KernelResult(
        name=name,
        status="PASS" if cos >= cos_pass else "FAIL",
        cosine_sim=cos,
        max_error=max_err,
        mean_error=mean_err,
        packets=packets,
        instructions=instructions,
        slot_utilization=(instructions / (packets * 4.0)) if packets else 0.0,
        emulator_packets=int(perf.get("packets_executed", 0)),
        emulator_instructions=int(perf.get("instructions_executed", 0)),
    )


def test_relu(work_dir: Path) -> KernelResult:
    mem_path, perf, pkts, ins = run_kernel("build_relu", "relu", work_dir)
    tensor = np.array([
        [-4.0, -2.0, -1.0, -0.5, 0.5, 1.0, 2.0, 4.0],
        [-3.0, -1.5, -0.25, 0.25, 0.75, 1.5, 3.0, 6.0],
        [-5.0, -2.5, -1.25, 0.0, 1.25, 2.5, 5.0, 7.0],
        [-6.0, -3.0, -1.75, 0.1, 1.75, 3.0, 6.0, 8.0],
    ], dtype=np.float32)
    expected_np = np.maximum(q_bf16(tensor), 0.0).reshape(-1)
    expected_t = torch.relu(torch.tensor(tensor, dtype=torch.float32)).numpy().reshape(-1)
    expected_t = q_bf16(expected_t)
    actual = read_bf16(read_mem_dump(mem_path), 0x00001040, expected_np.size)
    return pack_result("relu", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.99)


def test_sigmoid(work_dir: Path) -> KernelResult:
    mem_path, perf, pkts, ins = run_kernel("build_sigmoid", "sigmoid", work_dir)
    tensor = np.array([
        [-4.0, -2.0, -1.0, -0.5, 0.5, 1.0, 2.0, 4.0],
        [-3.0, -1.5, -0.25, 0.25, 0.75, 1.5, 3.0, 6.0],
        [-5.0, -2.5, -1.25, 0.0, 1.25, 2.5, 5.0, 7.0],
        [-6.0, -3.0, -1.75, 0.1, 1.75, 3.0, 6.0, 8.0],
    ], dtype=np.float32)
    inp = q_bf16(tensor)
    expected_np = q_bf16(1.0 / (1.0 + np.exp(-inp))).reshape(-1)
    expected_t = torch.sigmoid(torch.tensor(inp, dtype=torch.float32)).numpy().reshape(-1)
    expected_t = q_bf16(expected_t)
    actual = read_bf16(read_mem_dump(mem_path), 0x00001040, expected_np.size)
    return pack_result("sigmoid", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.97)


def test_softmax(work_dir: Path) -> KernelResult:
    mem_path, perf, pkts, ins = run_kernel("build_softmax", "softmax", work_dir)
    x = q_bf16(np.arange(1, 17, dtype=np.float32).reshape(4, 4))
    shifted = x - np.max(x, axis=1, keepdims=True)
    e = np.exp(shifted)
    expected_np = q_bf16(e / np.sum(e, axis=1, keepdims=True)).reshape(-1)
    xt = torch.tensor(x, dtype=torch.float32)
    expected_t = torch.softmax(xt, dim=1).numpy().reshape(-1)
    expected_t = q_bf16(expected_t)
    actual = read_bf16(read_mem_dump(mem_path), 0x0000CAFA, expected_np.size)
    return pack_result("softmax", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.95)


def layernorm_expected() -> np.ndarray:
    x = q_bf16(np.arange(16, dtype=np.float32).reshape(4, 4))
    mean = np.mean(x)
    var = np.mean((x - mean) ** 2)
    return q_bf16((x - mean) / np.sqrt(var)).reshape(-1)


def test_layernorm(work_dir: Path) -> KernelResult:
    mem_path, perf, pkts, ins = run_kernel("build_layernorm", "layernorm", work_dir)
    expected_np = layernorm_expected()
    x = torch.tensor(np.arange(16, dtype=np.float32).reshape(4, 4), dtype=torch.float32)
    m = torch.mean(x)
    v = torch.mean((x - m) ** 2)
    expected_t = ((x - m) / torch.sqrt(v)).numpy().reshape(-1)
    expected_t = q_bf16(expected_t)
    actual = read_bf16(read_mem_dump(mem_path), 0x0000CAFA, expected_np.size)
    return pack_result("layernorm", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.98)


def test_layernorm_pipelined(work_dir: Path) -> KernelResult:
    mem_path, perf, pkts, ins = run_kernel("build_layernorm_pipelined", "layernorm_pipelined", work_dir)
    expected_np = layernorm_expected()
    x = torch.tensor(np.arange(16, dtype=np.float32).reshape(4, 4), dtype=torch.float32)
    m = torch.mean(x)
    v = torch.mean((x - m) ** 2)
    expected_t = ((x - m) / torch.sqrt(v)).numpy().reshape(-1)
    expected_t = q_bf16(expected_t)
    actual = read_bf16(read_mem_dump(mem_path), 0x0000CAFA, expected_np.size)
    return pack_result("layernorm_pipelined", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.98)


def test_layernorm_param(work_dir: Path) -> KernelResult:
    mem_path, perf, pkts, ins = run_kernel("build_layernorm_param", "layernorm_param", work_dir)
    expected_np = layernorm_expected()
    x = torch.tensor(np.arange(16, dtype=np.float32).reshape(4, 4), dtype=torch.float32)
    m = torch.mean(x)
    v = torch.mean((x - m) ** 2)
    expected_t = ((x - m) / torch.sqrt(v)).numpy().reshape(-1)
    expected_t = q_bf16(expected_t)
    actual = read_bf16(read_mem_dump(mem_path), 0x0000CAFA, expected_np.size)
    return pack_result("layernorm_param", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.98)


def test_gemm(work_dir: Path) -> KernelResult:
    mem_path, perf, pkts, ins = run_kernel("build_gemm", "gemm", work_dir)
    rows, cols = 20, 20
    rng = np.random.default_rng(0)
    A = q_bf16(rng.normal(0.0, 0.5, size=(rows, cols)).astype(np.float32))
    W = q_bf16(rng.normal(0.0, 0.5, size=(rows, cols)).astype(np.float32))
    # lw.vi feeds systolic columns from row vectors, yielding A @ W^T.
    expected_np = q_bf16(A @ W.T).reshape(-1)
    expected_t = torch.matmul(torch.tensor(A, dtype=torch.float32), torch.tensor(W.T, dtype=torch.float32)).numpy().reshape(-1)
    expected_t = q_bf16(expected_t)
    actual = read_bf16(read_mem_dump(mem_path), 0x00003000, expected_np.size)
    return pack_result("gemm", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.99)


def test_gemms(work_dir: Path) -> KernelResult:
    mem_path, perf, pkts, ins = run_kernel("build_gemms", "gemms", work_dir)
    rows, cols, num_tiles = 20, 20, 3
    W = np.array([[float(r + c) for c in range(cols)] for r in range(rows)], dtype=np.float32)
    col_sums = W.sum(axis=0)
    tile_sum = float(sum(t + 1 for t in range(num_tiles)))
    base_row = col_sums * tile_sum
    expected = np.zeros((rows, cols), dtype=np.float32)
    for r in range(rows):
        expected[r, :] = base_row * (r + 1)
    expected_np = q_bf16(expected).reshape(-1)
    expected_t = torch.tensor(expected, dtype=torch.float32).numpy().reshape(-1)
    expected_t = q_bf16(expected_t)
    actual = read_bf16(read_mem_dump(mem_path), 0x00005000, expected_np.size)
    return pack_result("gemms", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.999)


def test_attention(work_dir: Path) -> KernelResult:
    mem_path, perf, pkts, ins = run_kernel("build_attention", "attention", work_dir, ["--n", "4", "--no-graph"])
    N = 4
    X = np.array([float(v) for v in range(4, 4 + N * N)], dtype=np.float32).reshape(N, N)
    Q = np.array([[1, 1, 1, 1], [1, 2, 1, 1], [1, 1, 3, 1], [1, 1, 1, 4]], dtype=np.float32)
    K = np.array([[1, 0, 0, 0], [0, 2, 0, 0], [0, 0, 3, 0], [0, 0, 0, 4]], dtype=np.float32)
    V = np.array([[10, 0, 0, 0], [0, 20, 0, 0], [0, 0, 30, 0], [0, 0, 0, 40]], dtype=np.float32)
    scores = (Q @ K.T) / np.sqrt(N)
    s_exp = np.exp(scores - scores.max(axis=1, keepdims=True))
    attn = (s_exp / s_exp.sum(axis=1, keepdims=True)) @ V
    residual = attn + X
    relu = np.maximum(0.0, residual)
    Wlin = np.array([
        [0.1, 0.5, 0.3, 0.8],
        [0.6, 0.2, 0.7, 0.1],
        [0.4, 0.9, 0.2, 0.5],
        [0.8, 0.3, 0.6, 0.2],
    ], dtype=np.float32)
    linear = relu @ Wlin
    shifted = linear - linear.max(axis=1, keepdims=True)
    e = np.exp(shifted)
    expected_np = q_bf16(e / e.sum(axis=1, keepdims=True)).reshape(-1)
    xt = torch.tensor(X, dtype=torch.float32)
    qt = torch.tensor(Q, dtype=torch.float32)
    kt = torch.tensor(K, dtype=torch.float32)
    vt = torch.tensor(V, dtype=torch.float32)
    scores_t = (qt @ kt.T) / math.sqrt(N)
    attn_t = torch.softmax(scores_t, dim=1) @ vt
    residual_t = attn_t + xt
    relu_t = torch.relu(residual_t)
    wlin_t = torch.tensor(Wlin, dtype=torch.float32)
    out_t = torch.softmax(relu_t @ wlin_t, dim=1).numpy().reshape(-1)
    expected_t = q_bf16(out_t)
    actual = read_bf16(read_mem_dump(mem_path), 0x00005000, expected_np.size)
    return pack_result("attention", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.95)


def test_flash_attention(work_dir: Path) -> KernelResult:
    mem_path, perf, pkts, ins = run_kernel("build_flash_attention", "flash_attention", work_dir, ["--n", "64", "--d", "32", "--seed", "0"])
    n, d = 64, 32
    rng = np.random.default_rng(0)
    q = q_bf16(rng.normal(0.0, 0.5, size=(n, d)).astype(np.float32))
    k = q_bf16(rng.normal(0.0, 0.5, size=(n, d)).astype(np.float32))
    v = q_bf16(rng.normal(0.0, 0.5, size=(n, d)).astype(np.float32))
    expected_np = q_bf16(flash_attention_online_ref(q, k, v, 1.0 / math.sqrt(float(d)))).reshape(-1)
    qt = torch.tensor(q, dtype=torch.float32)
    kt = torch.tensor(k, dtype=torch.float32)
    vt = torch.tensor(v, dtype=torch.float32)
    scores_t = (qt @ kt.T) * (1.0 / math.sqrt(float(d)))
    expected_t = torch.softmax(scores_t, dim=1) @ vt
    expected_t = q_bf16(expected_t.numpy().reshape(-1))
    actual = read_bf16(read_mem_dump(mem_path), 0x00007000, expected_np.size)
    return pack_result("flash_attention", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.999)


def test_flash_attention_causal(work_dir: Path) -> KernelResult:
    mem_path, perf, pkts, ins = run_kernel(
        "build_flash_attention", "flash_attention_causal", work_dir,
        ["--n", "64", "--d", "32", "--seed", "0", "--causal"],
    )
    n, d = 64, 32
    rng = np.random.default_rng(0)
    q = q_bf16(rng.normal(0.0, 0.5, size=(n, d)).astype(np.float32))
    k = q_bf16(rng.normal(0.0, 0.5, size=(n, d)).astype(np.float32))
    v = q_bf16(rng.normal(0.0, 0.5, size=(n, d)).astype(np.float32))
    scale = 1.0 / math.sqrt(float(d))
    expected_np = q_bf16(flash_attention_online_ref(q, k, v, scale, causal=True)).reshape(-1)
    qt = torch.tensor(q, dtype=torch.float32)
    kt = torch.tensor(k, dtype=torch.float32)
    vt = torch.tensor(v, dtype=torch.float32)
    scores_t = (qt @ kt.T) * scale
    tri_mask = torch.tril(torch.ones((n, n), dtype=torch.bool))
    scores_t = scores_t.masked_fill(~tri_mask, float("-inf"))
    expected_t = torch.softmax(scores_t, dim=1) @ vt
    expected_t = q_bf16(expected_t.numpy().reshape(-1))
    actual = read_bf16(read_mem_dump(mem_path), 0x00007000, expected_np.size)
    return pack_result("flash_attention_causal", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.999)


def conv_expected() -> np.ndarray:
    N, H, W, C = 1, 4, 4, 3
    K_out, R, S = 4, 3, 3
    Ho = (H - R) + 1
    Wo = (W - S) + 1
    K_flat = R * S * C
    ifmap = np.arange(N * H * W * C, dtype=np.float32).reshape(N, H, W, C)
    weights = (np.arange(R * S * C * K_out, dtype=np.float32) + 100.0).reshape(R, S, C, K_out)
    rows = []
    for n in range(N):
        for oh in range(Ho):
            for ow in range(Wo):
                cols = []
                for r in range(R):
                    for s in range(S):
                        cols.extend(ifmap[n, oh + r, ow + s, :].tolist())
                rows.append(cols)
    return (np.array(rows, dtype=np.float32) @ weights.reshape(K_flat, K_out)).reshape(-1)


def test_conv_variant(builder: str, name: str, work_dir: Path) -> KernelResult:
    mem_path, perf, pkts, ins = run_kernel(builder, name, work_dir)
    expected_np = conv_expected()
    # pytorch conv2d reference
    ifmap = torch.arange(1 * 4 * 4 * 3, dtype=torch.float32).reshape(1, 4, 4, 3).permute(0, 3, 1, 2)
    w = (torch.arange(3 * 3 * 3 * 4, dtype=torch.float32) + 100.0).reshape(3, 3, 3, 4).permute(3, 2, 0, 1)
    expected_t = torch.nn.functional.conv2d(ifmap, w, bias=None, stride=1, padding=0)
    expected_t = expected_t.permute(0, 2, 3, 1).reshape(-1).numpy()
    actual = read_bf16(read_mem_dump(mem_path), 0x00003000, expected_np.size)
    return pack_result(name, *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.999)


def test_add(work_dir: Path) -> KernelResult:
    rows, width = 4, 8
    mem_path, perf, pkts, ins = run_kernel("build_add", "add", work_dir, ["--rows", str(rows), "--width", str(width), "--seed", "42"])
    rng = np.random.default_rng(42)
    A = q_bf16(rng.standard_normal((rows, width)).astype(np.float32))
    B = q_bf16(rng.standard_normal((rows, width)).astype(np.float32))
    expected_np = q_bf16(A + B).reshape(-1)
    expected_t = (torch.tensor(A, dtype=torch.float32) + torch.tensor(B, dtype=torch.float32)).numpy().reshape(-1)
    expected_t = q_bf16(expected_t)
    actual = read_bf16(read_mem_dump(mem_path), 0x00001100, expected_np.size)
    return pack_result("add", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.999)


def test_maxpool(work_dir: Path) -> KernelResult:
    h_in, w_in = 8, 8
    pool, stride = 2, 2
    h_out = (h_in - pool) // stride + 1
    mem_path, perf, pkts, ins = run_kernel(
        "build_maxpool", "maxpool", work_dir,
        ["--H", str(h_in), "--W", str(w_in), "--pool", str(pool), "--stride", str(stride), "--seed", "7"],
    )
    rng = np.random.default_rng(7)
    tile = q_bf16(rng.standard_normal((h_in, w_in)).astype(np.float32))
    expected = np.zeros((h_out, w_in), dtype=np.float32)
    for oh in range(h_out):
        ih0 = oh * stride
        ih1 = ih0 + 1
        expected[oh] = np.maximum(tile[ih0], tile[ih1])
    expected_np = q_bf16(expected).reshape(-1)
    xt = torch.tensor(tile, dtype=torch.float32).unsqueeze(0).unsqueeze(0)
    expected_t = torch.nn.functional.max_pool2d(xt, kernel_size=(2, 1), stride=(2, 1)).squeeze(0).squeeze(0).numpy().reshape(-1)
    expected_t = q_bf16(expected_t)
    actual = read_bf16(read_mem_dump(mem_path), 0x00002000, expected.size)
    return pack_result("maxpool", *compare_dual(actual, expected_np, expected_t), pkts, ins, perf, cos_pass=0.999)


TESTS = {
    "relu": test_relu,
    "add": test_add,
    "maxpool": test_maxpool,
    "sigmoid": test_sigmoid,
    "softmax": test_softmax,
    "layernorm": test_layernorm,
    "layernorm_pipelined": test_layernorm_pipelined,
    "layernorm_param": test_layernorm_param,
    "gemm": test_gemm,
    "gemms": test_gemms,
    "attention": test_attention,
    "flash_attention": test_flash_attention,
    "flash_attention_causal": test_flash_attention_causal,
    "conv": lambda wd: test_conv_variant("build_conv", "conv", wd),
    "conv_pipelined": lambda wd: test_conv_variant("build_conv_pipelined", "conv_pipelined", wd),
    "conv_unrolled_pipelined": lambda wd: test_conv_variant("build_conv_unrolled_pipelined", "conv_unrolled_pipelined", wd),
}


def main() -> int:
    parser = argparse.ArgumentParser(description="Validate and benchmark functional_sim kernels")
    parser.add_argument("--kernels", nargs="*", default=list(TESTS.keys()), help="Kernels to test (default: all)")
    parser.add_argument("--keep-tmp", action="store_true", help="Keep temp work directory")
    parser.add_argument("--work-dir", type=str, default=None, help="Explicit work directory")
    args = parser.parse_args()

    if args.work_dir:
        work_dir = Path(args.work_dir)
        work_dir.mkdir(parents=True, exist_ok=True)
    elif args.keep_tmp:
        work_dir = ROOT / "out" / "validate"
        work_dir.mkdir(parents=True, exist_ok=True)
    else:
        work_dir = Path(tempfile.mkdtemp(prefix="atalla_validate_"))

    print(f"Working directory: {work_dir}")
    print(f"Compiler: {ROOT} (build_* generators)")
    print(f"Kernels:  {ROOT}")
    print()

    results: list[KernelResult] = []
    for name in args.kernels:
        if name not in TESTS:
            r = KernelResult(name=name, status="ERROR", error_msg="unknown kernel")
        else:
            try:
                r = TESTS[name](work_dir)
            except Exception as exc:
                r = KernelResult(name=name, status="ERROR", error_msg=str(exc))
        results.append(r)
        print(r.summary_line())

    print()
    n_pass = sum(1 for r in results if r.status == "PASS")
    n_fail = sum(1 for r in results if r.status == "FAIL")
    n_err = sum(1 for r in results if r.status == "ERROR")
    print(f"Results: {n_pass} PASS, {n_fail} FAIL, {n_err} ERROR out of {len(results)}")

    print()
    print("Metrics summary:")
    print(f"  {'kernel':20s} {'pkts':>6s} {'instrs':>7s} {'slot%':>7s} {'emu_pkts':>9s} {'emu_ins':>8s}")
    for r in results:
        if r.status == "ERROR":
            continue
        print(
            f"  {r.name:20s} {r.packets:6d} {r.instructions:7d} "
            f"{r.slot_utilization:7.3f} {r.emulator_packets:9d} {r.emulator_instructions:8d}"
        )

    if not args.keep_tmp and not args.work_dir:
        shutil.rmtree(work_dir, ignore_errors=True)
    return 0 if (n_fail == 0 and n_err == 0) else 1


if __name__ == "__main__":
    raise SystemExit(main())

