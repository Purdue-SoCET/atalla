import torch
import csv
from pathlib import Path
import random
import struct

# Swapped to PyTorch for proper BF16 support
# Raw bit manipulation is done via Python struct (NOT Torch) to avoid overflow issues

N = 1000000
SEED = 67

random.seed(SEED)
torch.manual_seed(SEED)

# Get script directory and set output path
SCRIPT_DIR = Path(__file__).parent.resolve()
OUTPUT_FILE = SCRIPT_DIR / "random_bf16_cases.csv"

# Random BF16 bit generator
def random_bf16_bits():
    return random.getrandbits(16)

# BF16 bits -> torch.bfloat16
def bf16_from_bits(bits):
    bits = bits & 0xFFFF

    # Place BF16 in upper 16 bits of FP32
    u32 = bits << 16

    # Bitcast uint32 -> float32 using struct
    f32 = struct.unpack("<f", struct.pack("<I", u32))[0]

    # Convert to torch.bfloat16
    return torch.tensor(f32, dtype=torch.float32).to(torch.bfloat16)

# torch.bfloat16 -> BF16 bits
def bits_from_bf16(val):
    # Convert to float32
    f32 = val.to(torch.float32).item()

    # Bitcast float32 -> uint32
    u32 = struct.unpack("<I", struct.pack("<f", f32))[0]

    # Extract upper 16 bits
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

with open(OUTPUT_FILE, "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["a", "b", "sub", "expected"])

    for _ in range(N):
        a_bits = random_bf16_bits()
        b_bits = random_bf16_bits()
        sub = random.randint(0, 1)  # 0 = add, 1 = sub

        # DAZ inputs
        a_bits_daz = apply_daz(a_bits)
        b_bits_daz = apply_daz(b_bits)

        # Subtraction via sign flip
        if sub:
            b_bits_daz ^= 0x8000

        # BF16 arithmetic via PyTorch
        a_val = bf16_from_bits(a_bits_daz)
        b_val = bf16_from_bits(b_bits_daz)
        exp_val = (a_val + b_val).to(torch.bfloat16)

        exp_bits = bits_from_bf16(exp_val)

        # FTZ + NaN canonicalization
        exp_bits = apply_ftz(exp_bits)
        exp_bits = canonicalize_nan(exp_bits)

        writer.writerow([f"{a_bits:04x}", f"{b_bits:04x}", sub, f"{exp_bits:04x}"])

print(f"Generated {N} test cases to {OUTPUT_FILE}")
