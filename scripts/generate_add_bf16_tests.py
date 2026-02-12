import torch
from pathlib import Path
import random
import struct
import math

# BF16 addition test case generator with DAZ/FTZ
#
# NOTE: NumPy does NOT support bf16 natively. PyTorch (or tf) is required
# for proper BF16. NumPy only supports float16

# saving mixuan and vedant - Myles "Myles Querimit" Querimit
# thank you Myles - Mixuan "Mixuan Pan" Pan 

N = 1000000
SEED = 67

random.seed(SEED)
torch.manual_seed(SEED)

SCRIPT_DIR = Path(__file__).parent.resolve()
OUTPUT_FILE = SCRIPT_DIR / "random_bf16_add_cases.txt"

# Random BF16 bit generator
def random_bf16_bits():
    return random.getrandbits(16)

# BF16 bits -> torch.bfloat16
def bf16_from_bits(bits):
    bits = bits & 0xFFFF
    u32 = bits << 16
    f32 = struct.unpack("<f", struct.pack("<I", u32))[0]
    return torch.tensor(f32, dtype=torch.float32).to(torch.bfloat16)

# torch.bfloat16 -> BF16 bits
def bits_from_bf16(val):
    f32 = val.to(torch.float32).item()
    u32 = struct.unpack("<I", struct.pack("<f", f32))[0]
    return (u32 >> 16) & 0xFFFF

# BF16 helpers
def is_subnormal(bits):
    exponent = (bits >> 7) & 0xFF
    mantissa = bits & 0x7F
    return exponent == 0 and mantissa != 0

def is_zero(bits):
    return (bits & 0x7FFF) == 0

def is_infinity(bits):
    exponent = (bits >> 7) & 0xFF
    mantissa = bits & 0x7F
    return exponent == 0xFF and mantissa == 0

def is_nan(bits):
    exponent = (bits >> 7) & 0xFF
    mantissa = bits & 0x7F
    return exponent == 0xFF and mantissa != 0

def apply_daz(bits):
    return bits & 0x8000 if is_subnormal(bits) else bits

def apply_ftz(bits):
    return bits & 0x8000 if is_subnormal(bits) else bits

def canonicalize_nan(bits):
    return bits | 0x0040 if is_nan(bits) else bits  # BF16 qNaN bit

def compute_add_in_float32(a_bits, b_bits):
    """Perform addition in float32 to detect overflow/underflow"""
    a_u32 = (a_bits & 0xFFFF) << 16
    b_u32 = (b_bits & 0xFFFF) << 16
    a_f32 = struct.unpack("<f", struct.pack("<I", a_u32))[0]
    b_f32 = struct.unpack("<f", struct.pack("<I", b_u32))[0]

    result_f32 = a_f32 + b_f32

    # Handle special cases that can't be packed
    if math.isnan(result_f32):
        result_u32 = 0x7FC00000  # Canonical NaN
    elif math.isinf(result_f32):
        if result_f32 > 0:
            result_u32 = 0x7F800000  # +inf
        else:
            result_u32 = 0xFF800000  # -inf
    else:
        try:
            result_u32 = struct.unpack("<I", struct.pack("<f", result_f32))[0]
        except (OverflowError, struct.error):
            # Fallback for extreme values
            result_u32 = 0x7F800000 if result_f32 > 0 else 0xFF800000

    return result_f32, result_u32

def detect_overflow_underflow(a_bits, b_bits, result_bits):
    """Detect if overflow or underflow occurred during addition"""
    # Skip special cases (NaN, infinity, zero inputs)
    if is_nan(a_bits) or is_nan(b_bits):
        return 0, 0
    if is_infinity(a_bits) or is_infinity(b_bits):
        return 0, 0
    if is_zero(a_bits) and is_zero(b_bits):
        return 0, 0

    # Compute in float32 to see the "true" result before rounding
    result_f32, result_u32 = compute_add_in_float32(a_bits, b_bits)

    # Overflow = result became infinity but inputs were both finite
    overflow = is_infinity(result_bits)

    # Underflow = result rounded to zero/subnormal while inputs were normal
    a_is_normal = not (is_zero(a_bits) or is_subnormal(a_bits) or is_infinity(a_bits) or is_nan(a_bits))
    b_is_normal = not (is_zero(b_bits) or is_subnormal(b_bits) or is_infinity(b_bits) or is_nan(b_bits))

    underflow = (is_zero(result_bits) or is_subnormal(result_bits)) and a_is_normal and b_is_normal

    return int(overflow), int(underflow)

with open(OUTPUT_FILE, "w") as f:
    for i in range(N):
        a_bits = random_bf16_bits()
        b_bits = random_bf16_bits()

        # DAZ inputs - comment out these two lines to disable DAZ
        a_bits_daz = apply_daz(a_bits)
        b_bits_daz = apply_daz(b_bits)
        # To disable DAZ, uncomment these instead:
        # a_bits_daz = a_bits
        # b_bits_daz = b_bits

        # BF16 addition via PyTorch
        a_val = bf16_from_bits(a_bits_daz)
        b_val = bf16_from_bits(b_bits_daz)
        exp_val = (a_val + b_val).to(torch.bfloat16)

        exp_bits = bits_from_bf16(exp_val)

        # FTZ + NaN canonicalization - comment out to disable FTZ
        exp_bits = apply_ftz(exp_bits)
        exp_bits = canonicalize_nan(exp_bits)
        # To disable FTZ, comment out the apply_ftz line above

        # Detect overflow and underflow
        ovf, unf = detect_overflow_underflow(a_bits_daz, b_bits_daz, exp_bits)

        # Write: a b expected_result expected_ovf expected_unf
        f.write(f"{a_bits:04x} {b_bits:04x} {exp_bits:04x} {ovf} {unf}\n")
        
        if (i + 1) % 100000 == 0:
            print(f"Generated {i + 1} testcases")

print(f"Wrote {N} addition test cases to {OUTPUT_FILE}")