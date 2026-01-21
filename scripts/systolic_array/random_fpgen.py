import numpy as np
import csv
import os
from pathlib import Path

N = 1000000  # number of random cases for high confidence
np.random.seed(67)

# Get script directory and set output path relative to it
SCRIPT_DIR = Path(__file__).parent.resolve()
OUTPUT_FILE = SCRIPT_DIR / "random_cases.csv"

# Random 16-bit value from 0x0000 → 0xFFFF
def random_fp16_bits():
    return np.random.randint(0, 0x10000)

# Turn into float16
def fp16_from_bits(bits):
    return np.frombuffer(np.uint16(bits).tobytes(), dtype=np.float16)[0]

# Get bits from float16
def bits_from_fp16(val):
    return np.frombuffer(val.tobytes(), dtype=np.uint16)[0]

# Check if fp16 is subnormal (denormal)
def is_subnormal(bits):
    exponent = (bits >> 10) & 0x1F
    mantissa = bits & 0x3FF
    return exponent == 0 and mantissa != 0

# Apply DAZ (Denormals-Are-Zero): convert subnormal inputs to zero (preserve sign)
def apply_daz(bits):
    if is_subnormal(bits):
        return bits & 0x8000  # Keep sign, zero rest
    return bits

# Apply FTZ (Flush-To-Zero): convert subnormal results to zero (preserve sign)
def apply_ftz(bits):
    if is_subnormal(bits):
        return bits & 0x8000
    return bits

# Check if result is NaN
def is_nan(bits):
    exponent = (bits >> 10) & 0x1F
    mantissa = bits & 0x3FF
    return exponent == 0x1F and mantissa != 0

# Canonicalize NaN to quiet NaN (set bit 9)
def canonicalize_nan(bits):
    if is_nan(bits):
        return bits | 0x0200  # Set quiet NaN bit (bit 9 of mantissa)
    return bits

with open(OUTPUT_FILE, "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["a", "b", "sub", "expected"])

    for _ in range(N):
        a_bits = random_fp16_bits()
        b_bits = random_fp16_bits()
        sub = np.random.randint(0, 2)  # 0 for add, 1 for sub

        # Apply DAZ: treat subnormal inputs as zero
        a_bits_daz = apply_daz(a_bits)
        b_bits_daz = apply_daz(b_bits)
        
        # For subtraction, negate b by flipping sign bit (hardware does this)
        if sub:
            b_bits_daz = b_bits_daz ^ 0x8000
        
        # Compute expected result with DAZ inputs
        a_val = fp16_from_bits(a_bits_daz)
        b_val = fp16_from_bits(b_bits_daz)
        exp_val = np.float16(a_val + b_val)  # Always add (b is already negated if sub=1)

        exp_bits = bits_from_fp16(exp_val)
        
        # Apply FTZ: flush subnormal results to zero, preserving sign
        # This is key: FTZ preserves the sign of the subnormal result
        exp_bits = apply_ftz(exp_bits)
        
        # Canonicalize NaN (hardware sets quiet bit)
        exp_bits = canonicalize_nan(exp_bits)
        
        # Write original inputs (before negation) and sub flag
        writer.writerow([f"{a_bits:04x}", f"{b_bits:04x}", sub, f"{exp_bits:04x}"])

print(f"Generated {N} test cases to {OUTPUT_FILE}")
