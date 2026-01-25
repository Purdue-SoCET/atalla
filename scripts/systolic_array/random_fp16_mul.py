import numpy as np
import csv

N = 500000
np.random.seed(42)

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
    """DAZ: Flush subnormal inputs to zero, preserve sign"""
    if is_subnormal(bits):
        return bits & 0x8000
    return bits

def apply_ftz(bits):
    """FTZ: Flush subnormal outputs to zero, preserve sign"""
    if is_subnormal(bits):
        return bits & 0x8000
    return bits

def is_nan(bits):
    exponent = (bits >> 10) & 0x1F
    mantissa = bits & 0x3FF
    return exponent == 0x1F and mantissa != 0

def canonicalize_nan(bits):
    if is_nan(bits):
        return bits | 0x0200  # Set quiet NaN bit
    return bits

with open("random_mul_cases.csv", "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["a", "b", "expected"])

    for _ in range(N):
        a_bits = random_fp16_bits()
        b_bits = random_fp16_bits()
        
        # DAZ: flush subnormal inputs to zero
        a_daz = apply_daz(a_bits)
        b_daz = apply_daz(b_bits)
        
        a_val = fp16_from_bits(a_daz)
        b_val = fp16_from_bits(b_daz)
        exp_val = np.float16(a_val * b_val)

        exp_bits = bits_from_fp16(exp_val)
        
        # FTZ: flush subnormal outputs to zero
        exp_bits = apply_ftz(exp_bits)
        
        exp_bits = canonicalize_nan(exp_bits)
        
        writer.writerow([f"{a_bits:04x}", f"{b_bits:04x}", f"{exp_bits:04x}"])

print(f"Generated {N} FP16 multiplication test cases (with DAZ/FTZ) to random_mul_cases.csv")
