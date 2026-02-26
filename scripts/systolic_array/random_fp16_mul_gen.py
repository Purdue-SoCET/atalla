import numpy as np
import csv
import sys

N = int(sys.argv[1]) if len(sys.argv) > 1 else 500000
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
        return 0x7E00  # Canonical positive quiet NaN (matches hardware)
    return bits

def normalize_zero(bits):
    """Treat -0 and +0 as equivalent (both become +0)"""
    if (bits & 0x7FFF) == 0:
        return 0x0000
    return bits

def hardware_boundary_ftz(a_bits, b_bits, result_bits):
    """
    Handle FTZ boundary case: exp_a + exp_b == 15 (biased exp = 0 without carry).
    Must replicate Wallace tree truncation (13-bit result + round_loss) to match HW.
    """
    if (result_bits & 0x7FFF) != 0x0400:
        return result_bits  # Not the boundary case
    
    exp_a = (a_bits >> 10) & 0x1F
    exp_b = (b_bits >> 10) & 0x1F
    
    if exp_a == 0 or exp_b == 0:
        return result_bits
    
    # Replicate hardware: full multiply then WTM truncation
    full_a = (1 << 10) | (a_bits & 0x3FF)
    full_b = (1 << 10) | (b_bits & 0x3FF)
    product = full_a * full_b
    
    # WTM outputs: 13-bit result = product[20:8], round_loss = |product[7:0]
    # (product is 22 bits from 11x11 multiply, stored in 23-bit sum)
    wtm_result = (product >> 8) & 0x1FFF
    wtm_overflow = (product >> 21) & 1
    wtm_round_loss = (product & 0xFF) != 0
    
    biased_exp = exp_a + exp_b + wtm_overflow - 15
    if biased_exp > 0:
        return result_bits  # Not underflow
    
    # Extract guard/round/sticky from WTM outputs (same as mul_fp16_nolatch)
    if wtm_overflow:
        frac = (wtm_result >> 3) & 0x3FF
        guard = (wtm_result >> 2) & 1
        rnd = (wtm_result >> 1) & 1
        sticky = (wtm_result & 1) | wtm_round_loss
    else:
        frac = (wtm_result >> 2) & 0x3FF
        guard = (wtm_result >> 1) & 1
        rnd = wtm_result & 1
        sticky = wtm_round_loss
    
    round_up = guard & (rnd | sticky | (frac & 1))
    rounded = frac + round_up
    rounding_overflow = (rounded >> 10) & 1
    
    if biased_exp == 0 and rounding_overflow:
        return result_bits  # boundary_case: rounding pushes exp to 1, valid
    
    # Hardware flushes to zero
    return result_bits & 0x8000

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
        
        # Handle FTZ boundary cases (exp_sum == 15, rounding can't save it)
        exp_bits = hardware_boundary_ftz(a_daz, b_daz, exp_bits)
        
        exp_bits = canonicalize_nan(exp_bits)
        exp_bits = normalize_zero(exp_bits)
        
        writer.writerow([f"{a_bits:04x}", f"{b_bits:04x}", f"{exp_bits:04x}"])

print(f"Generated {N} FP16 multiplication test cases (with DAZ/FTZ) to random_mul_cases.csv")
