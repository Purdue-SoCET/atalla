#!/usr/bin/env python3
"""
Generate an N×N tile data CSV file for kernel emulation testing.

Usage examples:
    python gen_data.py --n 4 --mode sequential --start 4 --output layernorm_data.csv
    python gen_data.py --n 8 --mode random --seed 42 --low -5 --high 5 --output data.csv
    python gen_data.py --n 4 --mode ones --output ones_tile.csv
"""

import argparse
import numpy as np
from pathlib import Path


def generate_tile(n: int, mode: str, start: float, low: float, high: float, seed: int | None) -> np.ndarray:
    """Generate an N×N tile of float values according to the specified mode."""
    if mode == "sequential":
        tile = np.arange(start, start + n * n, dtype=np.float32).reshape(n, n)
    elif mode == "random":
        rng = np.random.default_rng(seed)
        tile = rng.uniform(low, high, size=(n, n)).astype(np.float32)
    elif mode == "ones":
        tile = np.ones((n, n), dtype=np.float32)
    elif mode == "zeros":
        tile = np.zeros((n, n), dtype=np.float32)
    else:
        raise ValueError(f"Unknown mode: {mode!r}. Choose from: sequential, random, ones, zeros")
    return tile


def main():
    ap = argparse.ArgumentParser(description="Generate N×N tile data CSV for kernel testing")
    ap.add_argument("--n", type=int, required=True, help="Tile dimension (N×N)")
    ap.add_argument("--output", type=Path, default=Path("layernorm_data.csv"), help="Output CSV file path")
    ap.add_argument("--mode", type=str, default="sequential",
                    choices=["sequential", "random", "ones", "zeros"],
                    help="Data generation mode (default: sequential)")
    ap.add_argument("--start", type=float, default=1.0,
                    help="Start value for sequential mode (default: 1.0)")
    ap.add_argument("--seed", type=int, default=None,
                    help="Random seed for reproducibility (random mode only)")
    ap.add_argument("--low", type=float, default=-5.0,
                    help="Lower bound for random mode (default: -5.0)")
    ap.add_argument("--high", type=float, default=5.0,
                    help="Upper bound for random mode (default: 5.0)")
    args = ap.parse_args()

    if args.n < 1:
        raise ValueError(f"--n must be >= 1, got {args.n}")

    tile = generate_tile(args.n, args.mode, args.start, args.low, args.high, args.seed)

    args.output.parent.mkdir(parents=True, exist_ok=True)
    np.savetxt(args.output, tile, delimiter=", ", fmt="%.4f")

    print(f"[GEN_DATA] Wrote {args.n}×{args.n} tile ({args.mode}) to {args.output}")


if __name__ == "__main__":
    main()
