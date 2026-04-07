import numpy as np
import torch
import csv
import os

# --- TOGGLE SETTINGS ---
EXCLUDE_NANS = True  # Set to False to include NaNs in the final statistics
# -----------------------

# Helper functions for BF16 conversion
def int_to_bf16(n):
    """Converts a 16-bit integer (0x0000 to 0xFFFF) to a PyTorch BF16 tensor."""
    n32 = (np.array(n, dtype=np.uint32) << 16)
    f32 = n32.view(np.float32)
    return torch.from_numpy(f32).to(torch.bfloat16)

def bf16_to_int(x):
    """Converts a PyTorch BF16 tensor to its 16-bit integer representation."""
    f32 = x.to(torch.float32)
    n32 = f32.numpy().view(np.uint32)
    return (n32 >> 16).astype(np.uint16)

# Hardware simulation functions
def decompose_bits(x_int):
    """Decomposes a 16-bit BF16 integer representation into sign, mantissa (7-bit), and exponent (8-bit)."""
    sign = (x_int >> 15) & 0x1
    exp = (x_int >> 7) & 0xFF
    mant = x_int & 0x7F
    return sign, mant, exp

def mant_correction_sim(vect_bits, 
                      input_fraction=7, coefficient_fraction=4, constant_fraction=7, 
                      alpha1=0.21875000, beta1=0.4101562500, 
                      gamma1=2.835937500, gamma2=2.1679687500, 
                      mul_surplus_bits=1, not_surplus_bits=0):
    
    alpha = np.round(alpha1 * 2 ** coefficient_fraction).astype(np.int64)
    beta = np.round(beta1 * 2 ** coefficient_fraction).astype(np.int64)

    sum_fraction = int(max(input_fraction, constant_fraction))

    gamma_1_val = np.round(gamma1 * 2 ** constant_fraction).astype(np.int64) * 2 ** (sum_fraction - constant_fraction)
    gamma_2_val = np.round(gamma2 * 2 ** constant_fraction).astype(np.int64) * 2 ** (sum_fraction - constant_fraction)

    mant_add = (vect_bits & 0x7F).astype(np.int64) * 2 ** (sum_fraction - 7)
    res_add_1 = np.where(mant_add < 2 ** (sum_fraction - 1), mant_add + gamma_1_val, mant_add + gamma_2_val)
    
    mant_mul = (vect_bits & 0x7F).astype(np.int64) * 2 ** (mul_surplus_bits)
    res_mul_1 = np.where(mant_mul < 2 ** (mul_surplus_bits + input_fraction - 1), 
                         mant_mul * alpha, 
                         (beta * (2 ** (mul_surplus_bits + input_fraction) - mant_mul - 1)))

    res_mul_2 = (res_mul_1.astype(np.int64) * res_add_1.astype(np.int64)) >> int(sum_fraction + coefficient_fraction + mul_surplus_bits - not_surplus_bits)

    res = np.where(mant_add < 2 ** (sum_fraction - 1), 
                   res_mul_2, 
                   2 ** (7 + not_surplus_bits) - res_mul_2 - 1) >> not_surplus_bits

    res_bits = (vect_bits & 0xFF80) | (res.astype(np.uint16) & 0x7F)
    return res_bits

def hw_exponentiate(x_bits):
    """Simulates the hardware exponentiation unit for a 16-bit BF16 input."""
    a_fraction = 14
    a = np.round(1 / np.log(2) * 2 ** a_fraction).astype(np.int64)

    sign, mant, exp = decompose_bits(x_bits)
    mant_comp = (2 ** 7 + mant).astype(np.int32)
    max_exp = 127
    
    shift_ge = (exp.astype(np.int32) - max_exp)
    mask_ge = (exp >= max_exp)
    
    safe_shift = np.clip(shift_ge, -30, 40)
    shm = np.zeros_like(x_bits, dtype=np.int64)
    shm[mask_ge] = (mant_comp[mask_ge].astype(np.int64) * a) << safe_shift[mask_ge]
    shm[~mask_ge] = (mant_comp[~mask_ge].astype(np.int64) * a) >> (-safe_shift[~mask_ge])
    
    is_overflow = (shift_ge > 40)
    
    shm = (shm >> a_fraction) + ((shm >> (a_fraction - 1)) & 1)
    shm = np.where(sign == 1, -shm, shm)
    
    nm = shm & 0x7F
    ne = (shm >> 7) + 127
    
    # Overflow/Underflow Fix: Differentiate based on sign
    ne = np.where(is_overflow, np.where(sign == 0, 255, -128), ne)
    
    quant_score = ((ne.astype(np.uint32) << 7) + nm.astype(np.uint32)).astype(np.uint16)
    exp_c_bits = mant_correction_sim(quant_score)

    is_subnormal = (ne <= 0) & (ne > -8)
    sub_mant = (2**7 | nm) >> (1 - ne.astype(np.int32))
    sub_bits = (sub_mant.astype(np.uint16) & 0x7F)
    
    res = np.where(ne >= 255, 0x7F80, exp_c_bits) 
    res = np.where(is_subnormal, sub_bits, res)
    res = np.where(ne <= -8, 0x0000, res)
    
    input_is_nan = (exp == 0xFF) & (mant != 0)
    input_is_inf = (exp == 0xFF) & (mant == 0)
    
    res = np.where(input_is_nan, x_bits, res)
    res = np.where(input_is_inf, np.where(sign == 0, 0x7F80, 0x0000), res)

    return res.astype(np.uint16)

def run_sweep():
    TEST_SIZE = 65536
    print(f"Starting full sweep of all {TEST_SIZE} BF16 bit patterns...")
    all_bits = np.arange(TEST_SIZE, dtype=np.uint16)
    
    input_tensors = int_to_bf16(all_bits)
    ref_exp = torch.exp(input_tensors)
    ref_bits = bf16_to_int(ref_exp)
    hw_bits = hw_exponentiate(all_bits)
    
    ulp_error = np.abs(hw_bits.astype(np.int32) - ref_bits.astype(np.int32))
    
    csv_path = "pytorch_sweep_results.csv"
    print(f"Exporting results to {csv_path}...")
    input_floats = input_tensors.to(torch.float32).numpy()
    with open(csv_path, mode='w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(["Hex", "Input_Float", "HW_Result_Hex", "Ref_Result_Hex", "ULP_Error"])
        for i in range(TEST_SIZE):
            writer.writerow([
                f"0x{all_bits[i]:04x}",
                f"{input_floats[i]:.6e}",
                f"0x{hw_bits[i]:04x}",
                f"0x{ref_bits[i]:04x}",
                ulp_error[i]
            ])
            
    # --- Statistics Logic with Toggle ---
    input_sign, input_mant, input_exp = decompose_bits(all_bits)
    
    if EXCLUDE_NANS:
        is_nan = (input_exp == 0xFF) & (input_mant != 0)
        valid_mask = ~is_nan
        label = "excluding Input NaNs"
    else:
        valid_mask = np.ones(TEST_SIZE, dtype=bool)
        label = "including ALL patterns"
    
    filtered_errors = ulp_error[valid_mask]
    total_count = len(filtered_errors)
    
    max_ulp = np.max(filtered_errors)
    mean_ulp = np.mean(filtered_errors)
    correct_count = np.sum(filtered_errors == 0)
    within_1_ulp = np.sum(filtered_errors <= 1)
    
    print(f"\nSweep Statistics ({total_count} values, {label}):")
    print(f"Max ULP Error:  {max_ulp}")
    print(f"Mean ULP Error: {mean_ulp:.4f}")
    print(f"Exactly correct (0 ULP): {correct_count} / {total_count} ({correct_count/total_count*100:.2f}%)")
    print(f"Within 1 ULP:            {within_1_ulp} / {total_count} ({within_1_ulp/total_count*100:.2f}%)")
    
    print(f"\nError Distribution ({label}):")
    for e in range(min(max_ulp + 1, 11)):
        count = np.sum(filtered_errors == e)
        print(f"  {e} ULP: {count}")
    if max_ulp >= 11:
        count = np.sum(filtered_errors >= 11)
        print(f"  >= 11 ULP: {count}")

if __name__ == "__main__":
    run_sweep()