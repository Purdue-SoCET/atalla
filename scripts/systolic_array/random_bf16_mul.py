import torch
from pathlib import Path
import random
import struct

# BF16 multiplication test case generator with DAZ/FTZ
#
# NOTE: NumPy does NOT support bf16 natively. PyTorch (or tf) is required
# for proper BF16. NumPy only supports float16

# saving mixuan and vedant - Myles "Myles Querimit" Querimit

N = 1000000
SEED = 67

random.seed(SEED)
torch.manual_seed(SEED)

SCRIPT_DIR = Path(__file__).parent.resolve()
OUTPUT_FILE = SCRIPT_DIR / "random_bf16_mul_cases.txt"

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

def apply_daz(bits):
    return bits & 0x8000 if is_subnormal(bits) else bits

def apply_ftz(bits):
    return bits & 0x8000 if is_subnormal(bits) else bits

def is_nan(bits):
    exponent = (bits >> 7) & 0xFF
    mantissa = bits & 0x7F
    return exponent == 0xFF and mantissa != 0

def canonicalize_nan(bits):
    return bits | 0x0040 if is_nan(bits) else bits  # BF16 qNaN bit

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

        # BF16 multiplication via PyTorch
        a_val = bf16_from_bits(a_bits_daz)
        b_val = bf16_from_bits(b_bits_daz)
        exp_val = (a_val * b_val).to(torch.bfloat16)

        exp_bits = bits_from_bf16(exp_val)

        # FTZ + NaN canonicalization - comment out to disable FTZ
        exp_bits = apply_ftz(exp_bits)
        exp_bits = canonicalize_nan(exp_bits)
        # To disable FTZ, comment out the apply_ftz line above

        f.write(f"{a_bits:04x} {b_bits:04x} {exp_bits:04x}\n")
        
        if (i + 1) % 100000 == 0:
            print(f"Generated {i + 1} testcases")

print(f"Wrote {N} multiplication test cases to {OUTPUT_FILE}")
