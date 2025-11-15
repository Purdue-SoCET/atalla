#This script generates all possible FP16 values and computes their sqaure roots and writes them to a CSV
#USEAGE: python3 sqrt_fp16_golden.py


import numpy as np
import csv

def fp16_to_hex(val):
    """Convert FP16 value to hexadecimal string"""
    bits = np.float16(val).view(np.uint16)
    return f"0x{bits:04X}"

def is_subnormal(bits):
    """Check if FP16 value (as uint16 bits) is subnormal"""
    exponent_raw = (bits >> 10) & 0x1F
    mantissa = bits & 0x3FF
    return exponent_raw == 0 and mantissa != 0

def is_negative(bits):
    """Check if value is negative (sign bit set)"""
    return (bits >> 15) & 0x1 == 1

def is_negative_zero(bits):
    """Check if value is -0"""
    return bits == 0x8000

def is_positive_zero(bits):
    """Check if value is +0"""
    return bits == 0x0000

def compute_sqrt_output(bits):
    """Compute square root output following the specified rules"""
    
    # Rule 3: -0 returns -0
    if is_negative_zero(bits):
        return 0x8000
    
    # +0 returns +0
    if is_positive_zero(bits):
        return 0x0000
    
    # Check if negative (but not -0, already handled above)
    # All negative numbers (including negative subnormals) return NaN
    if is_negative(bits):
        return 0x7D00
    
    # Rule 1: If input is positive subnormal, output 0
    if is_subnormal(bits):
        return 0x0000
    
    # Convert to float and compute sqrt
    x_val = bits.view(np.float16)
    
    # Check for +infinity (0x7C00) - should return +infinity
    if bits == 0x7C00:
        return 0x7C00
    
    result = np.sqrt(x_val)
    
    # Rule 2: If output is NaN, force to 0x7D00
    if np.isnan(result):
        return 0x7D00
    
    return np.float16(result).view(np.uint16)

# Generate CSV for ALL FP16 values (0x0000 to 0xFFFF)
csv_data = []
for i in range(0x10000):  # 0 to 65535
    bits = np.uint16(i)
    output_bits = compute_sqrt_output(bits)
    
    input_hex = f"0x{bits:04X}"
    output_hex = f"0x{output_bits:04X}"
    
    csv_data.append([input_hex, output_hex])

# Write to CSV file
with open('fp16_sqrt_full_sweep.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerow(['Input', 'Output'])
    writer.writerows(csv_data)