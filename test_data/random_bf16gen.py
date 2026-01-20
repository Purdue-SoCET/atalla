import numpy as np
import csv
import os
from pathlib import Path

# *no native bf16 for numpy, emulating via conversion to fp32 rn
# could swap to tensorflow or pytorch if needed or possibly add library extension*


N = 1000000  # number of random cases
np.random.seed(67)

# Get script directory and set output path
SCRIPT_DIR = Path(__file__).parent.resolve()
OUTPUT_FILE = SCRIPT_DIR / "random_bf16_cases.csv"

# Random 16-bit value from 0x0000 -> 0xFFFF
def random_bf16_bits():
    return np.random.randint(0, 0x10000)

# Convert BF16 bits -> float32 (BF16 widened to FP32)
def bf16_from_bits(bits):
    u = np.uint16(bits)
    # BF16 stored in upper 16 bits of FP32
    return np.frombuffer(np.uint32(u.astype(np.uint32) << 16).tobytes(), dtype=np.float32)[0]

# Convert float32 -> BF16 bits (truncate, no rounding)
def bits_from_bf16(val):
    val = np.float32(val)
    u32 = np.frombuffer(val.tobytes(), dtype=np.uint32)[0]
    return np.uint16(u32 >> 16)

# Check if BF16 is subnormal
def is_subnormal(bits):
    exponent = (bits >> 7) & 0xFF
    mantissa = bits & 0x7F
    return exponent == 0 and mantissa != 0

# Apply DAZ (Denormals-Are-Zero)
def apply_daz(bits):
    if is_subnormal(bits):
        return bits & 0x8000  # preserve sign
    return bits

# Apply FTZ (Flush-To-Zero)
def apply_ftz(bits):
    if is_subnormal(bits):
        return bits & 0x8000
    return bits

# Check if NaN
def is_nan(bits):
    exponent = (bits >> 7) & 0xFF
    mantissa = bits & 0x7F
    return exponent == 0xFF and mantissa != 0

# Canonicalize NaN -> qNaN (set MSB of mantissa)
# *Note*: This changes since we are working with BF16 now so the MSB of mantissa is bit 6
def canonicalize_nan(bits):
    if is_nan(bits):
        return bits | 0x0040  # qNaN bit for BF16
    return bits

with open(OUTPUT_FILE, "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["a", "b", "sub", "expected"])

    for _ in range(N):
        a_bits = random_bf16_bits()
        b_bits = random_bf16_bits()
        sub = np.random.randint(0, 2) # 0 = addition, 1 = subtraction

        # DAZ on inputs
        a_bits_daz = apply_daz(a_bits)
        b_bits_daz = apply_daz(b_bits)

        # Subtraction via sign flip
        if sub:
            b_bits_daz ^= 0x8000

        # Compute in FP32
        # *no native bf16 for numpy, emulating via conversion to fp32 rn, could swap to tensorflow or pytorch if needed or possibly add library extension*
        a_val = bf16_from_bits(a_bits_daz)
        b_val = bf16_from_bits(b_bits_daz)
        exp_val = np.float32(a_val + b_val)

        exp_bits = bits_from_bf16(exp_val)

        # FTZ + NaN canonicalization
        exp_bits = apply_ftz(exp_bits)
        exp_bits = canonicalize_nan(exp_bits)

        # Write original operands (pre-negation) along w sub flag
        writer.writerow([
            f"{a_bits:04x}",
            f"{b_bits:04x}",
            sub,
            f"{int(exp_bits):04x}"
        ])

print(f"Generated {N} test cases to {OUTPUT_FILE}")
