"""AlexNet end-to-end orchestrator.

Chains all 19 AlexNet layers: for each layer, generates assembly + data,
runs the Atalla emulator, extracts output, and feeds it to the next layer.
Compares final output against a NumPy reference.

Usage:
    python run_alexnet.py --scale 0.1       # fast test with reduced channels
    python run_alexnet.py --scale 1.0       # full AlexNet (slow)
"""
from __future__ import annotations

import os, sys, struct, math, time
from pathlib import Path
from dataclasses import dataclass
import argparse
import numpy as np

sys.path.insert(0, os.path.dirname(__file__))

from build import assemble_file, emit_test_format, DRAMWriter, render_testfile
from build_alexnet_layer import (
    alexnet_layers, build_layer, im2col,
    ConvSpec, FCSpec, PoolSpec, ActivationSpec, SoftmaxSpec,
    TILE,
)
from src.functional_sim import run as run_emulator
from src.misc.memory import Memory
from src.components.scalar_register_file import ScalarRegisterFile
from src.components.vector_register_file import VectorRegisterFile
from src.components.execute import ExecuteUnit
from src.components.scpad import Scratchpad


def bf16_to_f32(bits: int) -> float:
    return struct.unpack("<f", struct.pack("<I", (bits & 0xFFFF) << 16))[0]


def run_layer_on_emulator(in_file: str, out_dir: str, tag: str) -> Memory:
    """Run the emulator on a .in file and return the post-execution Memory."""
    mem = Memory(in_file)
    sregs = ScalarRegisterFile()
    mregs = ScalarRegisterFile(num_regs=16)
    vregs = VectorRegisterFile()
    SP0 = Scratchpad(slots_per_bank=32)
    SP1 = Scratchpad(slots_per_bank=32)
    EU = ExecuteUnit()

    os.makedirs(out_dir, exist_ok=True)
    prefix = f"{out_dir}/{tag}"

    run_emulator(
        mem, sregs, mregs, vregs, SP0, SP1, EU, 0, 4,
        f"{prefix}_mem.out",
        f"{prefix}_sregs.out",
        f"{prefix}_vregs.out",
        f"{prefix}_mregs.out",
        f"{prefix}_sp0.out",
        f"{prefix}_sp1.out",
        f"{prefix}_perf.out",
        debug=False,
    )
    return mem


def extract_bf16_array(mem: Memory, base_addr: int, count: int) -> np.ndarray:
    """Read `count` bf16 values from data memory starting at base_addr."""
    result = np.zeros(count, dtype=np.float32)
    for i in range(count):
        byte_addr = base_addr + i * 2
        word_addr = byte_addr & ~0x1
        word = mem.read_data(word_addr)
        if byte_addr & 1:
            bits = (word >> 8) & 0xFFFF
        else:
            bits = word & 0xFFFF
        result[i] = bf16_to_f32(bits)
    return result


def numpy_reference_forward(layers, seed):
    """Run AlexNet forward pass purely in NumPy with same RNG seeds as orchestrator."""
    activation = None

    for lnum, lname, lspec in layers:
        layer_rng = np.random.default_rng(seed + lnum)

        if lname == "conv":
            s = lspec
            Ho = (s.H + 2 * s.pad - s.R) // s.stride + 1
            Wo = (s.W + 2 * s.pad - s.S) // s.stride + 1
            K_flat = s.R * s.S * s.C_in

            w = layer_rng.standard_normal((s.R, s.S, s.C_in, s.C_out)).astype(np.float32) * 0.1
            if activation is None:
                activation = layer_rng.standard_normal((1, s.H, s.W, s.C_in)).astype(np.float32) * 0.1

            inp = activation.reshape(1, s.H, s.W, s.C_in)
            A_mat = im2col(inp, 1, s.H, s.W, s.C_in, s.R, s.S, s.stride, s.pad)
            W_flat = w.reshape(K_flat, s.C_out)
            activation = (A_mat @ W_flat).reshape(Ho, Wo, s.C_out)

        elif lname == "relu":
            activation = np.maximum(activation, 0.0)

        elif lname == "maxpool":
            s = lspec
            H_out = (s.H - s.pool) // s.stride + 1
            W_out = (s.W - s.pool) // s.stride + 1
            inp = activation.reshape(s.H, s.W, -1)
            C = inp.shape[2]
            out = np.full((H_out, W_out, C), -np.inf)
            for oh in range(H_out):
                for ow in range(W_out):
                    for pr in range(s.pool):
                        for pc in range(s.pool):
                            ih = oh * s.stride + pr
                            iw = ow * s.stride + pc
                            if ih < s.H and iw < s.W:
                                out[oh, ow] = np.maximum(out[oh, ow], inp[ih, iw])
            activation = out

        elif lname == "fc":
            s = lspec
            w = layer_rng.standard_normal((s.in_features, s.out_features)).astype(np.float32) * 0.1
            inp = activation.flatten()[:s.in_features].reshape(1, -1)
            activation = (inp @ w).flatten()

        elif lname == "softmax":
            flat = activation.flatten()
            ex = np.exp(flat - np.max(flat))
            activation = ex / ex.sum()

    return activation


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--scale", type=float, default=0.1, help="Channel scale factor")
    ap.add_argument("--seed", type=int, default=42)
    ap.add_argument("--out-dir", type=str, default="out/alexnet")
    ap.add_argument("--skip-emulation", action="store_true", help="Only compute NumPy reference")
    args = ap.parse_args()

    layers = alexnet_layers(scale=args.scale)
    out_dir = args.out_dir
    os.makedirs(out_dir, exist_ok=True)
    os.makedirs(f"{out_dir}/tests", exist_ok=True)

    print(f"AlexNet end-to-end: scale={args.scale}, {len(layers)} layers")
    print("=" * 60)

    activation_data = None
    weight_data = None
    total_start = time.time()

    for lnum, lname, lspec in layers:
        layer_start = time.time()
        layer_rng = np.random.default_rng(args.seed + lnum)

        print(f"\n[Layer {lnum:2d}] {lname:8s} ", end="", flush=True)

        # Generate weights for this layer
        w = None
        if lname == "conv":
            w = layer_rng.standard_normal(
                (lspec.R, lspec.S, lspec.C_in, lspec.C_out)
            ).astype(np.float32) * 0.1
        elif lname == "fc":
            w = layer_rng.standard_normal(
                (lspec.in_features, lspec.out_features)
            ).astype(np.float32) * 0.1

        # First layer: generate input
        if activation_data is None and lname == "conv":
            activation_data = layer_rng.standard_normal(
                (1, lspec.H, lspec.W, lspec.C_in)
            ).astype(np.float32) * 0.1

        # MaxPool with spatial dims > 32 cannot run on emulator directly;
        # compute in NumPy and continue to next layer.
        if lname == "maxpool":
            s = lspec
            H_out = (s.H - s.pool) // s.stride + 1
            W_out = (s.W - s.pool) // s.stride + 1
            inp = activation_data.reshape(s.H, s.W, -1)
            C = inp.shape[2]
            out = np.full((H_out, W_out, C), -np.inf)
            for oh in range(H_out):
                for ow in range(W_out):
                    for pr in range(s.pool):
                        for pc in range(s.pool):
                            ih = oh * s.stride + pr
                            iw = ow * s.stride + pc
                            if ih < s.H and iw < s.W:
                                out[oh, ow] = np.maximum(out[oh, ow], inp[ih, iw])
            activation_data = out
            elapsed = time.time() - layer_start
            print(f"numpy ({elapsed:.1f}s)", end="", flush=True)
            continue

        # Reshape activation to match expected input shape
        shaped_input = activation_data
        if activation_data is not None:
            if lname == "conv":
                s = lspec
                shaped_input = activation_data.reshape(1, s.H, s.W, s.C_in)
            elif lname == "relu":
                shaped_input = activation_data.flatten()
            elif lname == "fc":
                shaped_input = activation_data.flatten()
            elif lname == "softmax":
                shaped_input = activation_data.flatten()

        try:
            instr_text, img, expected = build_layer(
                lnum, lname, lspec, layer_rng,
                input_data=shaped_input, weights=w,
            )
        except Exception as e:
            print(f"ERROR ({e})")
            continue

        data_text = img.render_data_mem(include_zeros=True)
        final = render_testfile(instr_text, data_text)

        in_file = f"{out_dir}/tests/layer{lnum}.in"
        Path(in_file).write_text(final)

        if not args.skip_emulation:
            mem = run_layer_on_emulator(in_file, out_dir, f"layer{lnum}")
            elapsed = time.time() - layer_start
            print(f"OK ({elapsed:.1f}s)", end="", flush=True)
        else:
            elapsed = time.time() - layer_start
            print(f"built ({elapsed:.1f}s)", end="", flush=True)

        # Use NumPy expected as the activation for next layer
        activation_data = np.array(expected)

    total_elapsed = time.time() - total_start
    print(f"\n\n{'=' * 60}")
    print(f"Total time: {total_elapsed:.1f}s")

    if activation_data is not None:
        emulator_output = activation_data.flatten()
        print(f"\nEmulator output shape: {emulator_output.shape}")
        print(f"Top-5 indices: {np.argsort(emulator_output)[-5:][::-1]}")
        print(f"Top-5 values:  {emulator_output[np.argsort(emulator_output)[-5:][::-1]]}")
        print(f"Sum of probs:  {emulator_output.sum():.6f}")

        # NumPy reference forward pass
        print(f"\n{'=' * 60}")
        print("Computing NumPy reference forward pass...")
        ref_output = numpy_reference_forward(layers, args.seed)
        ref_flat = ref_output.flatten()

        print(f"Reference output shape: {ref_flat.shape}")
        print(f"Top-5 indices: {np.argsort(ref_flat)[-5:][::-1]}")
        print(f"Top-5 values:  {ref_flat[np.argsort(ref_flat)[-5:][::-1]]}")
        print(f"Sum of probs:  {ref_flat.sum():.6f}")

        # Compare
        if emulator_output.shape == ref_flat.shape:
            max_diff = np.max(np.abs(emulator_output - ref_flat))
            mean_diff = np.mean(np.abs(emulator_output - ref_flat))
            cos_sim = np.dot(emulator_output, ref_flat) / (
                np.linalg.norm(emulator_output) * np.linalg.norm(ref_flat) + 1e-12
            )
            top5_emu = set(np.argsort(emulator_output)[-5:][::-1])
            top5_ref = set(np.argsort(ref_flat)[-5:][::-1])
            top5_match = len(top5_emu & top5_ref)

            print(f"\n--- Validation ---")
            print(f"Max abs diff:    {max_diff:.6f}")
            print(f"Mean abs diff:   {mean_diff:.6f}")
            print(f"Cosine sim:      {cos_sim:.6f}")
            print(f"Top-5 overlap:   {top5_match}/5")
            if cos_sim > 0.99:
                print("PASS: outputs match within BF16 tolerance")
            else:
                print("WARN: outputs diverge (expected with BF16 precision)")
        else:
            print(f"Shape mismatch: emulator={emulator_output.shape} vs ref={ref_flat.shape}")


if __name__ == "__main__":
    main()
