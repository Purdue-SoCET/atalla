import numpy as np
import csv
from pathlib import Path

N = 500000
np.random.seed(67)

SCRIPT_DIR = Path(__file__).parent.resolve()
OUTPUT_FILE = SCRIPT_DIR / "random_cases_4.csv"

def random_fp16_bits():
    return np.random.randint(0, 0x10000)

def fp16_from_bits(bits):
    return np.frombuffer(np.uint16(bits).tobytes(), dtype=np.float16)[0]

def bits_from_fp16(val):
    return np.frombuffer(val.tobytes(), dtype=np.uint16)[0]

def is_subnormal(bits):
    exp = (bits >> 10) & 0x1F
    man = bits & 0x3FF
    return exp == 0 and man != 0

def apply_daz(bits):
    return (bits & 0x8000) if is_subnormal(bits) else bits

def apply_ftz(bits):
    return (bits & 0x8000) if is_subnormal(bits) else bits

def is_nan(bits):
    exp = (bits >> 10) & 0x1F
    man = bits & 0x3FF
    return exp == 0x1F and man != 0

def canonicalize_nan(bits):
    return (bits | 0x0200) if is_nan(bits) else bits

def hw_like_add_bits(a_bits, b_bits):
    """Emulate hardware add: DAZ inputs, compute, FTZ + qNaN output"""
    a_bits = apply_daz(a_bits)
    b_bits = apply_daz(b_bits)
    
    a_val = fp16_from_bits(a_bits)
    b_val = fp16_from_bits(b_bits)
    
    y_val = np.float16(a_val + b_val)
    y_bits = bits_from_fp16(y_val)
    
    y_bits = apply_ftz(y_bits)
    y_bits = canonicalize_nan(y_bits)
    return y_bits

with open(OUTPUT_FILE, "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["a", "b", "c", "d", "expected"])

    for _ in range(N):
        a = random_fp16_bits()
        b = random_fp16_bits()
        c = random_fp16_bits()
        d = random_fp16_bits()

        # Tree order: (a+b) + (c+d)
        ab = hw_like_add_bits(a, b)
        cd = hw_like_add_bits(c, d)
        y = hw_like_add_bits(ab, cd)

        w.writerow([f"{a:04x}", f"{b:04x}", f"{c:04x}", f"{d:04x}", f"{y:04x}"])

print(f"Wrote {N} cases to {OUTPUT_FILE}")
