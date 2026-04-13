#!/usr/bin/env python3
"""Validate build_*.py outputs: generate .in via subprocess, run functional sim, compare to NumPy (BF16-aware).

Methodology (same idea as PyTorch, but NumPy is enough here):
  1) Subprocess: ``python build_foo.py -o <tmp>/foo.in [args]`` so you exercise the real __main__ / DRAM layout.
  2) Load the merged test image and call the same ``run_on_emulator`` as validate_and_benchmark.py.
  3) Read output BF16 words from the **same** byte addresses that the generator wrote into ``.data``.
  4) Build **expected** with the same formulas and ``to_bf16_array`` quantization as the generator uses
     for inputs (match ``DRAMWriter.bf16`` / seed / tensor shapes).

Optional: for larger models you can compare against ``torch.nn.functional`` on CUDA/CPU with
``torch.float32`` then round-trip through BF16, but the harness here stays NumPy-only.

This copy is **self-contained** (no ``validate_and_benchmark`` import): BF16 helpers and ``run_on_emulator``
live in this file so teammates only need ``functional_sim/`` on ``PYTHONPATH`` / run from this directory.

**Coverage:** This script does **not** infer references from asm. Each ``check_*`` fixes subprocess argv,
DRAM addresses, a NumPy/BF16 golden, and ``cos_min``. Generators whose default ``.in`` hits unsupported
sim mnemonics, need a different packaging path, or disagree numerically with a cheap analytic reference
stay in the printed **Not auto-tested** list with a short reason.

**Caveats:** (1) GMEM BF16 in ``.in`` files is packed two halfwords per 32-bit word; the emulator uses
``Memory.read_bf16_le`` / ``write_bf16_le`` in SDMA and vector linear paths. (2) ``vreg.{ld,st}`` encodes
``num_cols`` in 5 bits as **N−1**; using literal ``32`` encodes as 0 (one lane). (3) ``attention``,
``attention_fused_layernorm``, ``flash_attention``, ``gemms*``, ``layernorm*``, and ``softmax`` use
recorded vectors in ``goldens/build_generator.npz``; re-run the capture script in-repo after intentional
emulator or generator changes to those paths.

Usage:
  python validate_build_generators.py              # default: BF16 numeric cosine checks
  python validate_build_generators.py --only add
  python validate_build_generators.py --list

**Adding a kernel:** (1) add ``build_<name>.py`` with ``-o`` and a ``__main__`` that runs from this directory;
(2) add ``check_<name>()`` and register it in ``CHECKS``; (3) run ``python validate_build_generators.py --only <name>``.
"""
from __future__ import annotations

import argparse
import math
import os
import struct
import subprocess
import sys
import tempfile
from pathlib import Path
from typing import Callable, Dict, List, Optional, Tuple

import numpy as np

SCRIPT_DIR = Path(__file__).resolve().parent
sys.path.insert(0, str(SCRIPT_DIR))

_BUILD_GOLDENS_NPZ = SCRIPT_DIR / "goldens" / "build_generator.npz"
_golden_arrays: Optional[Dict[str, np.ndarray]] = None


def _golden(name: str) -> np.ndarray:
    """Load a float32 flat array from ``goldens/build_generator.npz`` (recorded emulator output)."""
    global _golden_arrays
    if _golden_arrays is None:
        if not _BUILD_GOLDENS_NPZ.is_file():
            raise FileNotFoundError(f"Missing {_BUILD_GOLDENS_NPZ} (regenerate with capture script in repo).")
        with np.load(_BUILD_GOLDENS_NPZ) as z:
            _golden_arrays = {k: np.array(z[k], dtype=np.float32, copy=True) for k in z.files}
    if name not in _golden_arrays:
        raise KeyError(f"No golden {name!r} in {_BUILD_GOLDENS_NPZ}; keys: {sorted(_golden_arrays)}")
    return _golden_arrays[name]

from src.components.execute import ExecuteUnit
from src.components.gemm import systolic_gemm_vv_dram_reference
from src.components.scalar_register_file import ScalarRegisterFile, mask_register_file
from src.components.scpad import Scratchpad
from src.components.vector_register_file import VectorRegisterFile
from src.functional_sim import run as run_emulator
from src.misc.memory import Memory


def f32_to_bf16_bits(x: float) -> int:
    return (struct.unpack("<I", struct.pack("<f", float(x)))[0] >> 16) & 0xFFFF


def bf16_bits_to_f32(bits: int) -> float:
    return struct.unpack("<f", struct.pack("<I", (bits & 0xFFFF) << 16))[0]


def to_bf16_array(arr: np.ndarray) -> np.ndarray:
    out = np.empty_like(arr, dtype=np.float32)
    for i, x in enumerate(arr.flat):
        out.flat[i] = bf16_bits_to_f32(f32_to_bf16_bits(float(x)))
    return out


def compare(actual: np.ndarray, expected: np.ndarray) -> Tuple[float, float, float]:
    a = actual.flatten().astype(np.float64)
    e = expected.flatten().astype(np.float64)
    dot = np.dot(a, e)
    na, ne = np.linalg.norm(a), np.linalg.norm(e)
    cos = dot / (na * ne) if na > 0 and ne > 0 else 0.0
    diff = np.abs(a - e)
    return float(cos), float(np.max(diff)), float(np.mean(diff))


def read_bf16_from_memory(mem: Memory, addr: int, count: int) -> np.ndarray:
    result = np.zeros(count, dtype=np.float32)
    for i in range(count):
        byte_addr = addr + i * 2
        bits = mem.read_bf16_le(byte_addr)
        result[i] = bf16_bits_to_f32(bits)
    return result


def _parse_perf_file(path: str) -> Dict[str, float]:
    metrics: Dict[str, float] = {}
    try:
        with open(path) as f:
            for line in f:
                if ":" not in line:
                    continue
                k, _, v = line.partition(":")
                k, v = k.strip(), v.strip()
                try:
                    metrics[k] = float(v)
                except ValueError:
                    pass
    except FileNotFoundError:
        pass
    return metrics


def run_emulator_in_path(in_path: str, work_dir: str, tag: str) -> Tuple[Memory, Dict[str, float]]:
    os.makedirs(work_dir, exist_ok=True)
    mem = Memory(in_path)
    sregs = ScalarRegisterFile()
    mregs = mask_register_file()
    vregs = VectorRegisterFile()
    SP0 = Scratchpad(slots_per_bank=32)
    SP1 = Scratchpad(slots_per_bank=32)
    EU = ExecuteUnit()

    max_data_addr = max(mem.data_mem.keys()) if mem.data_mem else 0
    stack_base = ((max_data_addr + 0x1000) & ~0xFFF) + 0x1000
    sregs.write(2, stack_base)
    sregs.write(33, stack_base + 0x1000)

    prefix = f"{work_dir}/{tag}"
    run_emulator(
        mem,
        sregs,
        mregs,
        vregs,
        SP0,
        SP1,
        EU,
        0,
        4,
        f"{prefix}_mem.out",
        f"{prefix}_sregs.out",
        f"{prefix}_vregs.out",
        f"{prefix}_mregs.out",
        f"{prefix}_sp0.out",
        f"{prefix}_sp1.out",
        f"{prefix}_perf.out",
    )
    return mem, _parse_perf_file(f"{prefix}_perf.out")


def run_on_emulator(in_text: str, work_dir: str, tag: str) -> Tuple[Memory, Dict[str, float]]:
    os.makedirs(work_dir, exist_ok=True)
    in_path = f"{work_dir}/{tag}.in"
    Path(in_path).write_text(in_text)
    return run_emulator_in_path(in_path, work_dir, tag)

TILE_ADDR_LAYERNORM = 0xCAFA


def _expected_conv_sa_h4_w4() -> np.ndarray:
    """Golden for build_conv*.py --H 4 --W 4 (same arange ifmap/weights as those generators)."""
    N, H, W, C = 1, 4, 4, 3
    K, R, S = 4, 3, 3
    stride, pad = 1, 0
    Ho = (H + 2 * pad - R) // stride + 1
    Wo = (W + 2 * pad - S) // stride + 1
    K_flat = R * S * C
    ifmap_vals = np.arange(N * H * W * C, dtype=np.float32).reshape(N, H, W, C)
    weight_vals = (np.arange(R * S * C * K, dtype=np.float32) + 100.0).reshape(R, S, C, K)
    A_rows = []
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
                            cols.extend(ifmap_vals[n, ih, iw, :].tolist())
                A_rows.append(cols)
    A_mat = np.array(A_rows, dtype=np.float32)
    W_flat = weight_vals.reshape(K_flat, K)
    return systolic_gemm_vv_dram_reference(A_mat, W_flat).reshape(-1)


def _expected_softmax_rows_bf16(tile_f32: np.ndarray) -> np.ndarray:
    """Row-wise softmax on BF16-rounded rows (same recipe as check_softmax)."""
    nrows, ncols = tile_f32.shape
    out = np.zeros(nrows * ncols, dtype=np.float32)
    for r in range(nrows):
        row = to_bf16_array(tile_f32[r])
        z = row.astype(np.float32) - np.max(row.astype(np.float32))
        e = np.exp(z)
        out[r * ncols : (r + 1) * ncols] = e / np.sum(e)
    return out


def _run_py_generator(rel_script: str, out: Path, extra: List[str]) -> None:
    cmd = [sys.executable, str(SCRIPT_DIR / rel_script), "-o", str(out), *extra]
    r = subprocess.run(cmd, cwd=str(SCRIPT_DIR), capture_output=True, text=True)
    if r.returncode != 0:
        raise RuntimeError(f"{rel_script} failed (exit {r.returncode})\n{r.stderr}")


def _emu_and_compare(
    work: Path,
    tag: str,
    in_text: str,
    out_addr: int,
    count: int,
    expected_flat: np.ndarray,
    cos_min: float,
) -> Tuple[str, float, float, float]:
    mem, _ = run_on_emulator(in_text, str(work), tag)
    actual = read_bf16_from_memory(mem, out_addr, count)
    cos, maxe, meane = compare(actual, expected_flat)
    status = "PASS" if cos >= cos_min else "FAIL"
    return status, cos, maxe, meane


def check_maxpool(work: Path) -> Tuple[str, float, float, float]:
    """Monorepo ``build_maxpool.py`` only supports pool=2, stride=2; output is ``H_out × W_in`` (see generator)."""
    H_in, W_in = 8, 8
    pool, stride = 2, 2
    H_out = (H_in - pool) // stride + 1
    out = work / "maxpool.in"
    _run_py_generator(
        "build_maxpool.py",
        out,
        ["--H", str(H_in), "--W", str(W_in), "--pool", str(pool), "--stride", str(stride), "--seed", "7"],
    )

    rng = np.random.default_rng(7)
    tile = rng.standard_normal((H_in, W_in)).astype(np.float32)
    tile_bf = to_bf16_array(tile)
    expected = np.zeros((H_out, W_in), dtype=np.float32)
    for oh in range(H_out):
        ih0 = oh * stride
        ih1 = ih0 + 1
        expected[oh] = np.maximum(tile_bf[ih0], tile_bf[ih1])

    OUT_GMEM = 0x2000
    in_text = out.read_text()
    return _emu_and_compare(work, "maxpool", in_text, OUT_GMEM, H_out * W_in, expected.reshape(-1), 0.99)


def check_add(work: Path) -> Tuple[str, float, float, float]:
    rows, width = 4, 8
    out = work / "add.in"
    _run_py_generator(
        "build_add.py",
        out,
        ["--rows", str(rows), "--width", str(width), "--seed", "42"],
    )
    C_GMEM = 0x1100

    rng = np.random.default_rng(42)
    A = rng.standard_normal((rows, width)).astype(np.float32)
    B = rng.standard_normal((rows, width)).astype(np.float32)
    Aq = to_bf16_array(A)
    Bq = to_bf16_array(B)
    expected = (Aq + Bq).reshape(-1)

    in_text = out.read_text()
    return _emu_and_compare(work, "add", in_text, C_GMEM, rows * width, expected, 0.99)


def check_relu(work: Path) -> Tuple[str, float, float, float]:
    """Monorepo ``build_relu.py``: 32×32 tile, ``default_rng(0)``, output at ``0x2000``."""
    out = work / "relu.in"
    _run_py_generator("build_relu.py", out, [])

    rng = np.random.default_rng(0)
    tensor = rng.standard_normal((32, 32)).astype(np.float32)
    tq = to_bf16_array(tensor)
    expected = np.maximum(tq, 0.0).reshape(-1)

    OUTPUT_BASE = 0x00002000
    in_text = out.read_text()
    return _emu_and_compare(work, "relu", in_text, OUTPUT_BASE, 32 * 32, expected, 0.99)


def check_gemm(work: Path) -> Tuple[str, float, float, float]:
    """``build_gemm.py`` defaults: 20×20, ``default_rng(0)``, C at ``0x3000``."""
    rows, cols, seed = 20, 20, 0
    out = work / "gemm.in"
    _run_py_generator(
        "build_gemm.py",
        out,
        ["--rows", str(rows), "--cols", str(cols), "--seed", str(seed)],
    )
    rng = np.random.default_rng(seed)
    A = rng.normal(0.0, 0.5, size=(rows, cols)).astype(np.float32)
    W = rng.normal(0.0, 0.5, size=(rows, cols)).astype(np.float32)
    A_b = to_bf16_array(A)
    W_b = to_bf16_array(W)
    C0_b = to_bf16_array(np.zeros((rows, cols), dtype=np.float32))
    mm = systolic_gemm_vv_dram_reference(A_b, W_b)
    expected = to_bf16_array(mm + C0_b).reshape(-1)
    return _emu_and_compare(work, "gemm", out.read_text(), 0x3000, rows * cols, expected, 0.99)


def check_layernorm(work: Path) -> Tuple[str, float, float, float]:
    out = work / "layernorm.in"
    _run_py_generator("build_layernorm.py", out, [])
    in_text = out.read_text()
    return _emu_and_compare(work, "layernorm", in_text, TILE_ADDR_LAYERNORM, 16, _golden("ln_demo"), 0.99)


def check_layernorm_param(work: Path) -> Tuple[str, float, float, float]:
    out = work / "layernorm_param.in"
    _run_py_generator("build_layernorm_param.py", out, ["--n", "4"])
    in_text = out.read_text()
    return _emu_and_compare(
        work, "layernorm_param", in_text, TILE_ADDR_LAYERNORM, 16, _golden("ln_param_n4"), 0.99
    )


def check_layernorm_pipelined(work: Path) -> Tuple[str, float, float, float]:
    out = work / "layernorm_pipelined.in"
    _run_py_generator("build_layernorm_pipelined.py", out, [])
    in_text = out.read_text()
    return _emu_and_compare(
        work, "layernorm_pipelined", in_text, TILE_ADDR_LAYERNORM, 16, _golden("ln_pipelined"), 0.99
    )


def check_gemms(work: Path) -> Tuple[str, float, float, float]:
    out = work / "gemms.in"
    _run_py_generator("build_gemms.py", out, [])
    in_text = out.read_text()
    output_gmem = 0x5000
    return _emu_and_compare(work, "gemms", in_text, output_gmem, 1024, _golden("gemms_demo"), 0.9999)


def check_gemm_tiled(work: Path) -> Tuple[str, float, float, float]:
    """Default M=N=K=8 from build_gemm_tiled.main; BF16 matmul golden matches DRAM layout."""
    M, N, K = 8, 8, 8
    out = work / "gemm_tiled.in"
    _run_py_generator("build_gemm_tiled.py", out, [])
    A_GMEM = 0x1000
    B_GMEM = A_GMEM + M * K * 2 + 0x1000
    C_GMEM = B_GMEM + K * N * 2 + 0x1000
    np.random.seed(42)
    A = np.random.randn(M, K).astype(np.float32) * 0.5
    B = np.random.randn(K, N).astype(np.float32) * 0.5
    expected = systolic_gemm_vv_dram_reference(A, B).reshape(-1)
    in_text = out.read_text()
    return _emu_and_compare(work, "gemm_tiled", in_text, C_GMEM, M * N, expected, 0.99)


def check_sigmoid(work: Path) -> Tuple[str, float, float, float]:
    """__main__ demo: exp(-x) on BF16-rounded inputs; output at 0x1040 (32 BF16)."""
    out = work / "sigmoid.in"
    _run_py_generator("build_sigmoid.py", out, [])
    tensor = np.array(
        [
            [-4.0, -2.0, -1.0, -0.5, 0.5, 1.0, 2.0, 4.0],
            [-3.0, -1.5, -0.25, 0.25, 0.75, 1.5, 3.0, 6.0],
            [-5.0, -2.5, -1.25, 0.0, 1.25, 2.5, 5.0, 7.0],
            [-6.0, -3.0, -1.75, 0.1, 1.75, 3.0, 6.0, 8.0],
        ],
        dtype=np.float32,
    )
    expected = np.exp(-to_bf16_array(tensor)).astype(np.float32).reshape(-1)
    OUTPUT_BASE = 0x00001040
    in_text = out.read_text()
    return _emu_and_compare(work, "sigmoid", in_text, OUTPUT_BASE, 32, expected, 0.99)


def check_softmax(work: Path) -> Tuple[str, float, float, float]:
    """Default build_softmax is linear packing; expected = row-wise BF16 softmax (tile 0..15, n=4)."""
    out = work / "softmax.in"
    _run_py_generator("build_softmax.py", out, ["--n", "4"])
    in_text = out.read_text()
    n = 4
    tile = np.arange(n * n, dtype=np.float32).reshape(n, n)
    expected = _expected_softmax_rows_bf16(tile)
    return _emu_and_compare(work, "softmax", in_text, TILE_ADDR_LAYERNORM, 16, expected, 0.99)


def check_conv_tiled(work: Path) -> Tuple[str, float, float, float]:
    """im2col @ W in BF16; must match build_conv_tiled.py defaults (SP0: mr_m+mr_k<=32)."""
    out = work / "conv_tiled.in"
    _run_py_generator("build_conv_tiled.py", out, [])
    Ni, H, W, C = 1, 4, 4, 3
    K_out, R, S = 4, 3, 3
    stride, pad = 1, 0
    Ho = (H + 2 * pad - R) // stride + 1
    Wo = (W + 2 * pad - S) // stride + 1
    K_flat = R * S * C
    M = Ni * Ho * Wo
    a_gmem = 0x1000
    w_gmem = a_gmem + M * K_flat * 2 + 0x1000
    c_gmem = w_gmem + K_flat * K_out * 2 + 0x1000

    def im2col(
        ifmap: np.ndarray, N: int, H: int, W: int, C: int, R: int, S: int, stride: int, pad: int
    ) -> np.ndarray:
        Ho_ = (H + 2 * pad - R) // stride + 1
        Wo_ = (W + 2 * pad - S) // stride + 1
        rows = []
        for n in range(N):
            for oh in range(Ho_):
                for ow in range(Wo_):
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

    np.random.seed(42)
    ifmap = np.random.randn(Ni, H, W, C).astype(np.float32) * 0.5
    weights = np.random.randn(R, S, C, K_out).astype(np.float32) * 0.5
    a_mat = im2col(ifmap, Ni, H, W, C, R, S, stride, pad)
    w_flat = weights.reshape(K_flat, K_out)
    expected = systolic_gemm_vv_dram_reference(a_mat, w_flat).reshape(-1)
    in_text = out.read_text()
    return _emu_and_compare(work, "conv_tiled", in_text, c_gmem, M * K_out, expected, 0.99)


def check_alexnet_layer(work: Path) -> Tuple[str, float, float, float]:
    """Single ReLU slice: AlexNet layer 15 @ --scale 0.01 (tiny FC relu)."""
    scale = 0.01
    seed = 42
    total = max(1, int(4096 * scale))
    width = min(total, 32)
    rows = math.ceil(total / width)
    out = work / "alexnet.in"
    _run_py_generator(
        "build_alexnet_layer.py",
        out,
        ["--layer", "15", "--scale", str(scale), "--seed", str(seed)],
    )
    rng = np.random.default_rng(seed)
    flat = rng.standard_normal(total).astype(np.float32) * 0.5
    padded = np.zeros(rows * width, dtype=np.float32)
    padded[: len(flat)] = flat
    tq = to_bf16_array(padded)
    expected = np.maximum(tq, 0.0).reshape(-1)
    in_gmem = 0x1000
    out_gmem = in_gmem + rows * width * 2 + 0x1000
    in_text = out.read_text()
    return _emu_and_compare(work, "alexnet_layer", in_text, out_gmem, rows * width, expected, 0.99)


def check_conv(work: Path) -> Tuple[str, float, float, float]:
    out = work / "conv_sa.in"
    _run_py_generator("build_conv.py", out, ["--H", "4", "--W", "4"])
    return _emu_and_compare(
        work, "conv", out.read_text(), 0x3000, 16, _expected_conv_sa_h4_w4(), 0.99
    )


def check_conv_dag_pack(work: Path) -> Tuple[str, float, float, float]:
    out = work / "conv_sa_dag_pack.in"
    _run_py_generator("build_conv.py", out, ["--dag-pack", "--H", "4", "--W", "4"])
    return _emu_and_compare(
        work, "conv_dag_pack", out.read_text(), 0x3000, 16, _expected_conv_sa_h4_w4(), 0.99
    )


def check_conv_bb_local(work: Path) -> Tuple[str, float, float, float]:
    out = work / "conv_sa_bb_local.in"
    _run_py_generator(
        "build_conv.py", out, ["--dag-pack", "--bb-local", "--H", "4", "--W", "4"]
    )
    return _emu_and_compare(
        work, "conv_bb_local", out.read_text(), 0x3000, 16, _expected_conv_sa_h4_w4(), 0.99
    )


def check_conv_pipelined(work: Path) -> Tuple[str, float, float, float]:
    out = work / "conv_pipelined.in"
    _run_py_generator("build_conv_pipelined.py", out, ["--H", "4", "--W", "4"])
    return _emu_and_compare(
        work, "conv_pipelined", out.read_text(), 0x3000, 16, _expected_conv_sa_h4_w4(), 0.99
    )


def check_conv_unrolled_pipelined(work: Path) -> Tuple[str, float, float, float]:
    out = work / "conv_unrolled_pipelined.in"
    _run_py_generator("build_conv_unrolled_pipelined.py", out, ["--H", "4", "--W", "4"])
    return _emu_and_compare(
        work,
        "conv_unrolled_pipelined",
        out.read_text(),
        0x3000,
        16,
        _expected_conv_sa_h4_w4(),
        0.99,
    )


def check_gemms_function(work: Path) -> Tuple[str, float, float, float]:
    out = work / "gemms_function.in"
    _run_py_generator("build_gemms_function.py", out, [])
    return _emu_and_compare(
        work, "gemms_function", out.read_text(), 0x5000, 1024, _golden("gemms_demo"), 0.9999
    )


def check_gemms_pipelined(work: Path) -> Tuple[str, float, float, float]:
    out = work / "gemms_pipelined.in"
    _run_py_generator("build_gemms_pipelined.py", out, [])
    return _emu_and_compare(
        work, "gemms_pipelined", out.read_text(), 0x5000, 1024, _golden("gemms_demo"), 0.9999
    )


def check_gemms_pipelined_loop_unroll(work: Path) -> Tuple[str, float, float, float]:
    out = work / "gemms_pipelined_loop_unroll.in"
    _run_py_generator("build_gemms_pipelined_loop_unroll.py", out, [])
    return _emu_and_compare(
        work,
        "gemms_pipelined_loop_unroll",
        out.read_text(),
        0x5000,
        1024,
        _golden("gemms_demo"),
        0.9999,
    )


def check_softmax_online(work: Path) -> Tuple[str, float, float, float]:
    """Default N=32, tile 0..N*N-1 at 0xCAFA (build_softmax_online.py)."""
    N = 32
    out = work / "softmax_online.in"
    _run_py_generator("build_softmax_online.py", out, [])
    tile = np.arange(N * N, dtype=np.float32).reshape(N, N)
    expected = _expected_softmax_rows_bf16(tile)
    in_text = out.read_text()
    return _emu_and_compare(work, "softmax_online", in_text, TILE_ADDR_LAYERNORM, N * N, expected, 0.97)


def check_attention(work: Path) -> Tuple[str, float, float, float]:
    n, seed = 16, 0
    out = work / "attention.in"
    _run_py_generator("build_attention.py", out, ["--n", str(n), "--seed", str(seed)])
    return _emu_and_compare(
        work,
        "attention",
        out.read_text(),
        0x7000,
        n * n,
        _golden("attn_16_s0"),
        0.99,
    )


def check_flash_attention(work: Path) -> Tuple[str, float, float, float]:
    """Recorded output in ``goldens/build_generator.npz`` (kernel BF16 differs from pure NumPy ref)."""
    n, d, seed = 32, 32, 0
    out = work / "flash_attention.in"
    _run_py_generator(
        "build_flash_attention.py",
        out,
        ["--n", str(n), "--d", str(d), "--seed", str(seed)],
    )
    return _emu_and_compare(
        work,
        "flash_attention",
        out.read_text(),
        0x7000,
        n * d,
        _golden("flash_32_s0"),
        0.9999,
    )


def check_attention_fused_layernorm(work: Path) -> Tuple[str, float, float, float]:
    """n=8, seed=0, default synthetic X tile (4..4+n²-1); output at TILE_ADDR_OUTPUT 0x5000."""
    n, seed = 8, 0
    out = work / "attention_fused_layernorm.in"
    _run_py_generator(
        "build_attention_fused_layernorm.py",
        out,
        ["--n", str(n), "--seed", str(seed)],
    )
    return _emu_and_compare(
        work,
        "attention_fused_layernorm",
        out.read_text(),
        0x5000,
        n * n,
        _golden("attn_fused_ln_8_s0"),
        0.99,
    )


# Omit ``build_alexnet_layer.py`` until that script exists in this tree.
CHECKS: Dict[str, Callable[[Path], Tuple[str, float, float, float]]] = {
    "maxpool": check_maxpool,
    "add": check_add,
    "relu": check_relu,
    "gemm": check_gemm,
    "gemm_tiled": check_gemm_tiled,
    "conv_tiled": check_conv_tiled,
    "sigmoid": check_sigmoid,
    "layernorm": check_layernorm,
    "layernorm_param": check_layernorm_param,
    "layernorm_pipelined": check_layernorm_pipelined,
    "gemms": check_gemms,
    "softmax": check_softmax,
    "conv": check_conv,
    "conv_dag_pack": check_conv_dag_pack,
    "conv_bb_local": check_conv_bb_local,
    "conv_pipelined": check_conv_pipelined,
    "conv_unrolled_pipelined": check_conv_unrolled_pipelined,
    "gemms_function": check_gemms_function,
    "gemms_pipelined": check_gemms_pipelined,
    "gemms_pipelined_loop_unroll": check_gemms_pipelined_loop_unroll,
    "softmax_online": check_softmax_online,
    "attention": check_attention,
    "attention_fused_layernorm": check_attention_fused_layernorm,
    "flash_attention": check_flash_attention,
}


def _functional_sim_build_scripts() -> List[str]:
    """Kernel-style ``build_*.py`` in this directory (excludes ``build_compiler.py``; no archive/tests)."""
    out: List[str] = []
    for p in sorted(SCRIPT_DIR.glob("build_*.py")):
        rel = p.name
        if rel == "build_compiler.py":
            continue
        if "archive" not in str(p) and "tests/" not in str(p):
            out.append(rel)
    return out


def _print_not_covered() -> None:
    covered_files = {f"build_{n}.py" for n in CHECKS}
    all_scripts = set(_functional_sim_build_scripts())
    missing = sorted(all_scripts - covered_files)
    print()
    print("Not auto-tested (no check_* wired yet, or intentional):")
    for name in missing:
        print(f"  {name:28s}  — add check_* + CHECKS entry")
    print(f"  {'build_compiler.py':28s}  — assembler/scheduler CLI (run separately)")


def main() -> None:
    ap = argparse.ArgumentParser(
        description="Validate build_*.py: BF16 numeric checks against goldens or analytic references."
    )
    ap.add_argument(
        "--numeric",
        action="store_true",
        help="(default) Same as running without flags; kept for scripts that still pass --numeric.",
    )
    ap.add_argument(
        "--only",
        type=str,
        default="",
        help=f"Comma-separated subset of numeric checks: {', '.join(sorted(CHECKS))}",
    )
    ap.add_argument(
        "--list",
        action="store_true",
        help="List build_*.py in this tree and show which have automated numeric checks.",
    )
    args = ap.parse_args()
    if args.list:
        print("Numeric checks:", ", ".join(sorted(CHECKS)))
        print("Kernel build_*.py in this dir:", ", ".join(_functional_sim_build_scripts()))
        print("(build_compiler.py is the .s→.in tool; not a generator check here.)")
        _print_not_covered()
        return

    names = [x.strip() for x in args.only.split(",") if x.strip()] if args.only else list(CHECKS)
    bad = [n for n in names if n not in CHECKS]
    if bad:
        sys.exit(f"Unknown --only names: {bad}. Known: {sorted(CHECKS)}")

    fails = 0
    with tempfile.TemporaryDirectory(prefix="atalla_buildgen_") as work:
        wpath = Path(work)
        for name in names:
            try:
                status, cos, maxe, meane = CHECKS[name](wpath)
            except Exception as e:
                print(f"  {name:15s} ERROR  {e}")
                fails += 1
                continue
            if status != "PASS":
                fails += 1
            print(
                f"  {name:15s} {status:4s}  cos={cos:.4f}  max_err={maxe:.6f}  mean_err={meane:.6f}"
            )

    print()
    if fails:
        print(f"Results: {fails} failed out of {len(names)}")
        _print_not_covered()
        sys.exit(1)
    print(f"Results: {len(names)} PASS")
    _print_not_covered()


if __name__ == "__main__":
    main()
