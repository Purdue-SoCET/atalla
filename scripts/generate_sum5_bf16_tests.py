import torch
from pathlib import Path
import random
import struct
import math

# BF16 sum of 5 inputs test case generator with DAZ/FTZ
#
# Based on generate_add_bf16_tests.py

N = 1000000
SEED = 68  # Different seed from the original

random.seed(SEED)
torch.manual_seed(SEED)

SCRIPT_DIR = Path(__file__).parent.resolve()
OUTPUT_FILE = SCRIPT_DIR / "random_bf16_sum5_cases.txt"

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

with open(OUTPUT_FILE, "w") as f:
    for i in range(N):
        # Generate 5 random BF16 inputs
        input_bits = [random_bf16_bits() for _ in range(5)]

        # Apply DAZ to inputs
        daz_input_bits = [apply_daz(bits) for bits in input_bits]

        # Convert to BF16 tensors
        input_vals = [bf16_from_bits(bits) for bits in daz_input_bits]

        # Compute sum
        sum_val = sum(input_vals).to(torch.bfloat16)

        # Get bits of sum
        exp_bits = bits_from_bf16(sum_val)

        # Apply FTZ and NaN canonicalization
        exp_bits = apply_ftz(exp_bits)
        exp_bits = canonicalize_nan(exp_bits)

        # Write: input1 input2 input3 input4 input5 expected_sum
        line = ' '.join(f"{bits:04x}" for bits in input_bits) + f" {exp_bits:04x}\n"
        f.write(line)
        
        if (i + 1) % 100000 == 0:
            print(f"Generated {i + 1} testcases")

print(f"Wrote {N} sum of 5 test cases to {OUTPUT_FILE}")