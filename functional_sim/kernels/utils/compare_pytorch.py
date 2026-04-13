#!/usr/bin/env python3
"""
Compare emulated kernel output against PyTorch golden reference.

Loads the input tile from a CSV data file, runs the specified PyTorch kernel,
parses the emulator scratchpad output, and reports element-wise error metrics.

Usage:
    python compare_pytorch.py \
        --kernel layernorm --n 4 \
        --data layernorm_data.csv \
        --output_scpad_file0 kernels/layernorm_output/output_scpad0.out
"""

from __future__ import annotations

import argparse
import ast
import re
import sys
from pathlib import Path

import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F


# ---------------------------------------------------------------------------
# Kernel registry — add new kernels here
# ---------------------------------------------------------------------------
SUPPORTED_KERNELS = {"layernorm", "relu", "sigmoid", "softmax"}


def pytorch_kernel(name: str, tile: torch.Tensor, *, epsilon: float = 0.0) -> torch.Tensor:
    """Run the named PyTorch operation on *tile* and return the result tensor."""
    if name == "layernorm":
        normalized_shape = list(tile.shape)
        layer = nn.LayerNorm(normalized_shape, elementwise_affine=False, eps=epsilon)
        # LayerNorm expects float — cast up, compute, cast back
        out = layer(tile.float()).to(tile.dtype)
        return out
    elif name == "relu":
        return F.relu(tile)
    elif name == "sigmoid":
        return torch.sigmoid(tile.float()).to(tile.dtype)
    elif name == "softmax":
        return F.softmax(tile.float(), dim=-1).to(tile.dtype)
    else:
        raise ValueError(f"Unknown kernel {name!r}. Supported: {SUPPORTED_KERNELS}")


# ---------------------------------------------------------------------------
# Data I/O helpers
# ---------------------------------------------------------------------------


def load_tile_csv(path: str, n: int) -> np.ndarray:
    """Load an N×N tile from a CSV file and return as float32 numpy array."""
    tile = np.loadtxt(path, delimiter=",")
    if tile.ndim == 1:
        tile = tile.reshape(1, -1)
    if tile.shape != (n, n):
        raise ValueError(f"Tile shape mismatch: expected ({n}, {n}), got {tile.shape}")
    return tile.astype(np.float32)


def parse_scpad_output(path: str, n: int, scpad_base_row: int = 1) -> np.ndarray:
    """
    Parse an emulator scratchpad dump file and extract the N×N result tile.

    The file format (from dump_scpad_rc) is one line per bank:
        Bank 0: ['', '', 4.0, 5.0, '', '', ...]
        Bank 1: ['', '', 5.0, 6.0, '', '', ...]

    For an N×N tile written at scpad_base_row, element [row][col] lives at
    Bank[col], slot index (scpad_base_row + row).
    """
    banks: dict[int, list] = {}
    with open(path, "r") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            # Example: "Bank 0: ['', '', 4.0, ...]"
            colon_idx = line.index(":")
            bank_id = int(line[len("Bank "):colon_idx])
            list_str = line[colon_idx + 1:].strip()
            # The emulator may dump np.float32(...) wrappers — strip them so
            # ast.literal_eval sees plain floats.
            list_str = re.sub(r"np\.float32\(([^)]+)\)", r"\1", list_str)
            bank_data = ast.literal_eval(list_str)
            banks[bank_id] = bank_data

    tile = np.zeros((n, n), dtype=np.float32)
    for row in range(n):
        for col in range(n):
            slot_idx = scpad_base_row + row
            if col not in banks:
                print(f"[WARN] Bank {col} not found in scratchpad output", file=sys.stderr)
                continue
            val = banks[col][slot_idx]
            if isinstance(val, str) and val == "":
                tile[row][col] = 0.0
            else:
                tile[row][col] = float(val)
    return tile


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------


def main():
    ap = argparse.ArgumentParser(description="Compare emulated kernel output against PyTorch reference")

    # Required
    ap.add_argument("--kernel", type=str, required=True, choices=sorted(SUPPORTED_KERNELS),
                    help="Kernel operation to compare")
    ap.add_argument("--n", type=int, required=True, help="Tile dimension (N×N)")
    ap.add_argument("--data", type=str, required=True, help="Path to input tile CSV data file")
    ap.add_argument("--output_scpad_file0", type=str, required=True,
                    help="Path to emulator output scratchpad 0 file")

    # Optional emulator output files (accepted for future use / extensibility)
    ap.add_argument("--output_mem_file", type=str, default=None)
    ap.add_argument("--output_sreg_file", type=str, default=None)
    ap.add_argument("--output_vreg_file", type=str, default=None)
    ap.add_argument("--output_mreg_file", type=str, default=None)
    ap.add_argument("--output_scpad_file1", type=str, default=None)

    # Configuration
    ap.add_argument("--epsilon", type=float, default=0.0,
                    help="Epsilon for layernorm (default: 0.0, matching emulator default)")
    ap.add_argument("--scpad_base_row", type=int, default=0,
                    help="Scratchpad base row where tile starts (default: 1)")
    ap.add_argument("--verbose", action="store_true", help="Print per-element difference matrix")

    args = ap.parse_args()

    # 1. Load input tile
    input_tile_np = load_tile_csv(args.data, args.n)
    input_tile_torch = torch.from_numpy(input_tile_np).to(torch.bfloat16)

    # 2. Run PyTorch golden kernel
    with torch.no_grad():
        pytorch_out = pytorch_kernel(args.kernel, input_tile_torch, epsilon=args.epsilon)
    pytorch_out_np = pytorch_out.float().numpy()

    # 3. Parse emulator output
    emulator_out_np = parse_scpad_output(args.output_scpad_file0, args.n, args.scpad_base_row)

    # 4. Compare
    diff = np.abs(pytorch_out_np - emulator_out_np)
    mae = float(np.mean(diff))
    max_err = float(np.max(diff))

    print(f"[COMPARE] Kernel: {args.kernel} | Tile: {args.n}x{args.n}")
    print(f"[COMPARE] PyTorch output:\n{pytorch_out_np}")
    print(f"[COMPARE] Emulator output:\n{emulator_out_np}")
    print(f"[COMPARE] Mean Absolute Error:  {mae:.6f}")
    print(f"[COMPARE] Max Absolute Error:   {max_err:.6f}")

    if args.verbose:
        print(f"[COMPARE] Element-wise |diff|:\n{diff}")

    # Simple pass/fail threshold (generous for bf16 quantization)
    threshold = 0.5
    if mae < threshold:
        print(f"[COMPARE] PASS (MAE {mae:.6f} < {threshold})")
        sys.exit(0)
    else:
        print(f"[COMPARE] FAIL (MAE {mae:.6f} >= {threshold})")
        sys.exit(1)


if __name__ == "__main__":
    main()
