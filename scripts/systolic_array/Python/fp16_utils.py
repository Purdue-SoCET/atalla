import numpy as np
import csv
import sys
from pathlib import Path

def random_fp16_bits():
    return np.random.randint(0, 0x10000)

def fp16_from_bits(bits):
    return np.frombuffer(np.uint16(bits).tobytes(), dtype=np.float16)[0]

def bits_from_fp16(val):
    return np.frombuffer(val.tobytes(), dtype=np.uint16)[0]

def is_subnormal(bits):
    exponent = (bits >> 10) & 0x1F
    mantissa = bits & 0x3FF
    return exponent == 0 and mantissa != 0

def apply_daz(bits):
    if is_subnormal(bits):
        return bits & 0x8000
    return bits

def apply_ftz(bits):
    if is_subnormal(bits):
        return bits & 0x8000
    return bits

def is_nan(bits):
    exponent = (bits >> 10) & 0x1F
    mantissa = bits & 0x3FF
    return exponent == 0x1F and mantissa != 0

def canonicalize_nan(bits):
    if is_nan(bits):
        return 0x7E00
    return bits

def normalize_zero(bits):
    if (bits & 0x7FFF) == 0:
        return 0x0000
    return bits

def fp16_mul_hw(a_bits: int, b_bits: int) -> int:
    """Multiply with DAZ/FTZ, return fp16 bits of product."""
    a_daz = apply_daz(a_bits)
    b_daz = apply_daz(b_bits)
    a_val = fp16_from_bits(a_daz)
    b_val = fp16_from_bits(b_daz)
    prod = np.float16(a_val * b_val)
    prod_bits = bits_from_fp16(prod)
    prod_bits = apply_ftz(prod_bits)
    prod_bits = canonicalize_nan(prod_bits)
    return prod_bits

def fp16_add_hw(a_bits: int, b_bits: int) -> int:
    """Add with DAZ/FTZ, return fp16 bits of sum."""
    a_daz = apply_daz(a_bits)
    b_daz = apply_daz(b_bits)
    a_val = fp16_from_bits(a_daz)
    b_val = fp16_from_bits(b_daz)
    s = np.float16(a_val + b_val)
    s_bits = bits_from_fp16(s)
    s_bits = apply_ftz(s_bits)
    s_bits = canonicalize_nan(s_bits)
    return s_bits

def fp16_mac(a_bits, b_bits, c_bits):
    """MAC: (a * b) + c, matching hardware two-step (mul then add, each with DAZ/FTZ)."""
    prod_bits = fp16_mul_hw(a_bits, b_bits)
    result_bits = fp16_add_hw(prod_bits, c_bits)
    result_bits = normalize_zero(result_bits)
    return result_bits

# script_dir = Path(__file__).parent
# output_file = script_dir / "random_mac_cases.csv"

# with open(output_file, "w", newline="") as f:
#     writer = csv.writer(f)
#     writer.writerow(["a", "b", "c", "expected"])

#     for _ in range(N):
#         a_bits = random_fp16_bits()
#         b_bits = random_fp16_bits()
#         c_bits = random_fp16_bits()
#         expected = fp16_mac(a_bits, b_bits, c_bits)
#         writer.writerow([f"{a_bits:04x}", f"{b_bits:04x}", f"{c_bits:04x}", f"{expected:04x}"])

# print(f"Generated {N} FP16 MAC test cases (a*b+c with DAZ/FTZ) to {output_file}")