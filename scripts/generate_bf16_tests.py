#!/usr/bin/env python3
"""
Generate 1,000,000 bfloat16 multiply testcases (a, b, expected)
Outputs lines with hex 4-digit values: a b expected

Conversion and rounding follow round-to-nearest-even when reducing float32 -> bfloat16.
"""
import numpy as np
import os

OUT_PATH = os.path.join(os.path.dirname(__file__), "bf16_1M_tests.txt")
NUM = 1_000_000

def uint32_to_bf16_round(u32):
    # u32: np.uint32 array of float32 bitpatterns
    upper = (u32 >> np.uint32(16)).astype(np.uint32)
    lower = (u32 & np.uint32(0xFFFF)).astype(np.uint32)
    # Round to nearest even based on lower 16 bits
    inc = (lower > np.uint32(0x8000)) | ((lower == np.uint32(0x8000)) & ((upper & np.uint32(1)) != 0))
    upper = upper + inc.astype(np.uint32)
    upper = upper & np.uint32(0xFFFF)
    return upper.astype(np.uint16)

def bf16_to_float32_bits(u16):
    # expand bf16 16-bit pattern to float32 bits by shifting left 16
    return (u16.astype(np.uint32) << np.uint32(16)).astype(np.uint32)

def make_edge_values():
    edges = []
    def enc(sign, exp, mant):
        return np.uint16((sign << 15) | (exp << 7) | mant)

    # zeros
    edges.append(enc(0, 0, 0))  # +0
    edges.append(enc(1, 0, 0))  # -0
    # smallest subnormal (mantissa non-zero, exp=0)
    edges.append(enc(0, 0, 1))
    edges.append(enc(1, 0, 1))
    # smallest normal: exp=1, mant=0
    edges.append(enc(0, 1, 0))
    edges.append(enc(1, 1, 0))
    # largest normal finite (exp=254, mant all ones)
    edges.append(enc(0, 254, 0x7f))
    edges.append(enc(1, 254, 0x7f))
    # infinities
    edges.append(enc(0, 255, 0))
    edges.append(enc(1, 255, 0))
    # NaNs (quiet/signaling variations)
    edges.append(enc(0, 255, 1))
    edges.append(enc(0, 255, 0x40))
    edges.append(enc(1, 255, 1))
    return edges

def main():
    np.random.seed(12345)

    edges = make_edge_values()
    n_edges = len(edges)
    remaining = NUM - n_edges
    if remaining < 0:
        remaining = 0

    a_rand = np.random.randint(0, 0x10000, size=remaining, dtype=np.uint16)
    b_rand = np.random.randint(0, 0x10000, size=remaining, dtype=np.uint16)

    a_all = np.concatenate([np.array(edges, dtype=np.uint16), a_rand])
    b_all = np.concatenate([np.array(edges, dtype=np.uint16), b_rand])

    # compute float32 representations
    a_f32_bits = bf16_to_float32_bits(a_all.astype(np.uint32))
    b_f32_bits = bf16_to_float32_bits(b_all.astype(np.uint32))

    a_f32 = a_f32_bits.view(dtype=np.float32)
    b_f32 = b_f32_bits.view(dtype=np.float32)

    # multiply in float32 precision
    prod_f32 = (a_f32 * b_f32).astype(np.float32)
    prod_bits = prod_f32.view(np.uint32)

    # round to bfloat16
    prod_bf16 = uint32_to_bf16_round(prod_bits)

    # write out
    with open(OUT_PATH, "w") as f:
        N = len(a_all)
        for i in range(N):
            f.write(f"{a_all[i]:04x} {b_all[i]:04x} {prod_bf16[i]:04x}\n")
            if (i+1) % 100000 == 0:
                print(f"Generated {i+1} testcases")

    print(f"Wrote {len(a_all)} testcases to {OUT_PATH}")

if __name__ == '__main__':
    main()
