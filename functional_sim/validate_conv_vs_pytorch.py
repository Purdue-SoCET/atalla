from __future__ import annotations

import argparse
from pathlib import Path
import numpy as np


def load_data_mem(mem_path: Path) -> dict[int, int]:
    data_section = False
    mem: dict[int, int] = {}
    with mem_path.open("r") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            if line.upper().startswith("DATA MEM"):
                data_section = True
                continue
            if not data_section or ":" not in line:
                continue
            addr_str, val_str = [x.strip() for x in line.split(":", 1)]
            try:
                mem[int(addr_str, 16)] = int(val_str, 16)
            except ValueError:
                continue
    return mem


def bf16_quantize_array(arr: np.ndarray) -> np.ndarray:
    u = arr.astype(np.float32).view(np.uint32)
    return (u & np.uint32(0xFFFF0000)).view(np.float32)


def build_ifmap_weights(N: int, H: int, W: int, C: int, K: int, R: int, S: int):
    ifmap = np.arange(N * H * W * C, dtype=np.int32).reshape(N, H, W, C)
    weights = (np.arange(R * S * C * K, dtype=np.int32) + 100).reshape(R, S, C, K)
    return ifmap, weights


def conv_ref(ifmap: np.ndarray, weights: np.ndarray, stride: int, pad: int):
    N, H, W, C = ifmap.shape
    R, S, C2, K = weights.shape
    assert C == C2
    Ho = (H + 2 * pad - R) // stride + 1
    Wo = (W + 2 * pad - S) // stride + 1
    out = np.zeros((N, Ho, Wo, K), dtype=np.float32)
    for n in range(N):
        for oh in range(Ho):
            for ow in range(Wo):
                for k in range(K):
                    acc = 0.0
                    for r in range(R):
                        for s in range(S):
                            ih = oh * stride + r - pad
                            iw = ow * stride + s - pad
                            if ih < 0 or ih >= H or iw < 0 or iw >= W:
                                continue
                            for c in range(C):
                                acc += float(ifmap[n, ih, iw, c]) * float(weights[r, s, c, k])
                    out[n, oh, ow, k] = acc
    return out


def conv_ref_bf16_io(ifmap: np.ndarray, weights: np.ndarray, stride: int, pad: int):
    if_q = bf16_quantize_array(ifmap.astype(np.float32))
    w_q = bf16_quantize_array(weights.astype(np.float32))
    return bf16_quantize_array(conv_ref(if_q, w_q, stride=stride, pad=pad))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--mem", type=Path, default=Path("out/output_mem.out"))
    ap.add_argument("--N", type=int, default=1)
    ap.add_argument("--H", type=int, default=4)
    ap.add_argument("--W", type=int, default=4)
    ap.add_argument("--C", type=int, default=3)
    ap.add_argument("--K", type=int, default=4)
    ap.add_argument("--R", type=int, default=3)
    ap.add_argument("--S", type=int, default=3)
    ap.add_argument("--stride", type=int, default=1)
    ap.add_argument("--pad", type=int, default=0)
    ap.add_argument("--ofmap_base", type=lambda x: int(x, 0), default="0x3000")
    ap.add_argument("--ref_mode", choices=["bf16_io", "fp32"], default="bf16_io")
    ap.add_argument("--tol", type=float, default=0.1)
    args = ap.parse_args()

    N, H, W, C = args.N, args.H, args.W, args.C
    K, R, S = args.K, args.R, args.S
    stride, pad = args.stride, args.pad
    Ho = (H + 2 * pad - R) // stride + 1
    Wo = (W + 2 * pad - S) // stride + 1
    if Ho <= 0 or Wo <= 0:
        raise ValueError("Invalid H/W/R/S/stride/pad combination: Ho/Wo must be positive.")

    ifmap_i32, weights_i32 = build_ifmap_weights(N, H, W, C, K, R, S)
    ifmap = ifmap_i32.astype(np.float32)
    weights = weights_i32.astype(np.float32)
    ref = conv_ref_bf16_io(ifmap, weights, stride, pad) if args.ref_mode == "bf16_io" else conv_ref(ifmap, weights, stride, pad)

    mem = load_data_mem(args.mem)
    M = N * Ho * Wo
    emu_C = np.zeros((M, K), dtype=np.float32)
    for m_idx in range(M):
        for k_idx in range(K):
            addr = args.ofmap_base + 2 * (m_idx * K + k_idx)
            raw = mem.get(addr, 0)
            bf16_bits = raw & 0xFFFF
            u32 = (bf16_bits << 16) & 0xFFFFFFFF
            emu_C[m_idx, k_idx] = np.frombuffer(u32.to_bytes(4, "little"), dtype=np.float32)[0]

    emu_ofmap = np.zeros_like(ref, dtype=np.float32)
    for m in range(M):
        n_b = m // (Ho * Wo)
        oh = (m // Wo) % Ho
        ow = m % Wo
        emu_ofmap[n_b, oh, ow, :] = emu_C[m, :]

    diff = emu_ofmap - ref
    max_abs = float(np.max(np.abs(diff)))
    max_ref = float(np.max(np.abs(ref))) if ref.size else 0.0
    rel_err = max_abs / max_ref if max_ref > 0 else 0.0
    ok = rel_err <= args.tol

    print(f"Conv config: N={N}, H={H}, W={W}, C={C}, K={K}, R={R}, S={S}, stride={stride}, pad={pad}")
    print(f"Output shape Ho={Ho}, Wo={Wo}")
    print(f"Ref mode: {args.ref_mode}  tol={args.tol:.3g}")
    print(f"Max abs diff: {max_abs:.4e}  (rel_err={rel_err:.4e})")
    print(f"MATCH (rel_err <= {args.tol:.3g})" if ok else "MISMATCH")


if __name__ == "__main__":
    main()
