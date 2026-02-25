import torch
from pathlib import Path
import random
import struct
import math

# BF16 multiplication test case generator with DAZ/FTZ
#
# NOTE: NumPy does NOT support bf16 natively. PyTorch (or tf) is required
# for proper BF16. NumPy only supports float16

# saving mixuan and vedant - Myles "Myles Querimit" Querimit
# thank you Myles - Mixuan "Mixuan Pan" Pan 

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

def compute_mul_in_float32(a_bits, b_bits):
    """Perform multiplication in float32 to detect overflow/underflow"""
    a_u32 = (a_bits & 0xFFFF) << 16
    b_u32 = (b_bits & 0xFFFF) << 16
    a_f32 = struct.unpack("<f", struct.pack("<I", a_u32))[0]
    b_f32 = struct.unpack("<f", struct.pack("<I", b_u32))[0]
    
    result_f32 = a_f32 * b_f32
    
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
    """Detect if overflow or underflow occurred during multiplication"""
    # Skip special cases (NaN, infinity, zero inputs)
    if is_nan(a_bits) or is_nan(b_bits):
        return 0, 0  # NaN propagation doesn't count as overflow/underflow
    if is_infinity(a_bits) or is_infinity(b_bits):
        return 0, 0  # Infinity inputs don't count
    if is_zero(a_bits) or is_zero(b_bits):
        return 0, 0  # Zero inputs don't count
    
    # Compute in float32 to see the "true" result before rounding
    result_f32, result_u32 = compute_mul_in_float32(a_bits, b_bits)
    
    # Check if result is infinity (overflow)
    # Overflow = result became infinity but inputs were both finite
    overflow = is_infinity(result_bits)
    
    # Check if result is zero/subnormal (underflow)
    # Underflow = result became zero/subnormal but inputs were both non-zero normal
    # Only count as underflow if inputs were normal (not subnormal)
    a_is_normal = not (is_zero(a_bits) or is_subnormal(a_bits) or is_infinity(a_bits) or is_nan(a_bits))
    b_is_normal = not (is_zero(b_bits) or is_subnormal(b_bits) or is_infinity(b_bits) or is_nan(b_bits))
    
    underflow = (is_zero(result_bits) or is_subnormal(result_bits)) and a_is_normal and b_is_normal
    
    return int(overflow), int(underflow)

def bf16_mul_hw(a_bits: int, b_bits: int, daz: bool=True, ftz: bool=True) -> int:
    """
    Emulates 2 input bf16 multiplier
    """
    # DAZ inputs
    if daz:
        a_bits = apply_daz(a_bits)
        b_bits = apply_daz(b_bits)

    # BF16 multiplication via PyTorch
    a = bf16_from_bits(a_bits)
    b = bf16_from_bits(b_bits)
    y = (a * b).to(torch.bfloat16)

    y_bits = bits_from_bf16(y)

    # FTZ + NaN canonicalization
    if ftz:
        y_bits = apply_ftz(y_bits)
    y_bits = canonicalize_nan(y_bits)

    return y_bits

def bf16_add_hw(a_bits: int, b_bits: int, daz: bool=True, ftz: bool=True) -> int:
    if daz:
        a_bits = apply_daz(a_bits)
        b_bits = apply_daz(b_bits)

    a = bf16_from_bits(a_bits)
    b = bf16_from_bits(b_bits)

    # BF16 add via PyTorch
    y = (a + b).to(torch.bfloat16)
    y_bits = bits_from_bf16(y)

    if ftz:
        y_bits = apply_ftz(y_bits)
    y_bits = canonicalize_nan(y_bits)

    return y_bits
