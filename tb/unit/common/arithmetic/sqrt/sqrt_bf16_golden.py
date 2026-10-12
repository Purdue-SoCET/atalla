# This script generates all possible BF16 values, computes their square roots,
# and writes the results to a CSV file as a golden reference.
# USAGE: python3 sqrt_bf16_golden.py

import numpy as np
import csv
import struct

def bf16_to_float32(bf16_bits):
    """Convert a 16-bit BF16 value (uint16) to float32"""
    # BF16: 1 sign bit, 8 exponent bits, 7 mantissa bits
    # Place BF16 bits in the upper 16 bits of a float32
    bits_32 = np.uint32(bf16_bits) << 16
    return np.frombuffer(bits_32.tobytes(), dtype=np.float32)[0]

def float32_to_bf16(val):
    """Convert float32 to BF16 (uint16) with truncation (no rounding)"""
    bits_32 = np.frombuffer(np.float32(val).tobytes(), dtype=np.uint32)[0]
    bf16_bits = np.uint16(bits_32 >> 16)
    return bf16_bits

def bf16_to_hex(bits):
    """Convert BF16 bits to hex string"""
    return f"0x{bits:04X}"

def is_subnormal(bits):
    """Check if BF16 value is subnormal"""
    exponent_raw = (bits >> 7) & 0xFF
    mantissa = bits & 0x7F
    return exponent_raw == 0 and mantissa != 0

def is_negative(bits):
    """Check if sign bit is set"""
    return (bits >> 15) & 1 == 1

def is_negative_zero(bits):
    """Check for -0"""
    return bits == 0x8000

def is_positive_zero(bits):
    """Check for +0"""
    return bits == 0x0000

def compute_sqrt_output(bits):
    """Compute BF16 sqrt following special rules"""
    
    # -0 → -0
    if is_negative_zero(bits):
        return np.uint16(0x8000)
    
    # +0 → +0
    if is_positive_zero(bits):
        return np.uint16(0x0000)
    
    # Negative values (excluding -0) → NaN (canonical)
    if is_negative(bits):
        return np.uint16(0x7FC0)  # canonical quiet NaN for BF16
    
    # Positive subnormals → 0
    if is_subnormal(bits):
        return np.uint16(0x0000)
    
    # +Inf → +Inf
    if bits == 0x7F80:
        return np.uint16(0x7F80)
    
    # Convert to float, compute sqrt
    val = bf16_to_float32(bits)
    result = np.sqrt(val)
    
    # NaN result → canonical NaN
    if np.isnan(result):
        return np.uint16(0x7FC0)
    
    # Convert result to BF16 bits
    return float32_to_bf16(result)

# Generate all 2^16 BF16 bit patterns
csv_data = []
for i in range(0x10000):
    bits = np.uint16(i)
    output_bits = compute_sqrt_output(bits)
    
    input_hex = bf16_to_hex(bits)
    output_hex = bf16_to_hex(output_bits)
    
    csv_data.append([input_hex, output_hex])

# Write results to CSV
with open('bf16_sqrt_full_sweep.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(['Input', 'Output'])
    writer.writerows(csv_data)

print("✅ Generated bf16_sqrt_full_sweep.csv successfully.")
