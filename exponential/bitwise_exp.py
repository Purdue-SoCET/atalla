import numpy as np
import torch
import csv
import os

# --- TOGGLE SETTINGS ---
EXCLUDE_NANS = True  # Set to False to include NaNs in the final statistics
# -----------------------

# Helper functions for BF16 conversion (used for Reference and CSV display only)
def int_to_bf16(n):
    """Converts a 16-bit integer to a PyTorch BF16 tensor for reference."""
    n32 = (np.array(n, dtype=np.uint32) << 16)
    f32 = n32.view(np.float32)
    return torch.from_numpy(f32).to(torch.bfloat16)

def bf16_to_int(x):
    """Converts a PyTorch BF16 tensor to its 16-bit integer representation."""
    f32 = x.to(torch.float32)
    n32 = f32.numpy().view(np.uint32)
    return (n32 >> 16).astype(np.uint16)

# Raw Bitwise Hardware Simulation Logic
def bf16_exp_bitwise(x_int):
    """
    Corrected bitwise simulation of the BF16 exponentiation unit.
    """
    # 1. Decomposition
    sign = (x_int >> 15) & 0x1
    exp = (x_int >> 7) & 0xFF
    mant = x_int & 0x7F

    # 2. Special Cases
    if exp == 0xFF:
        if mant != 0: return x_int  # NaN
        return 0x7F80 if sign == 0 else 0x0000 # +/- Inf

    # 3. Scaling by 1/ln(2) [Constant: 23637 = round(1/ln(2) * 2^14)]
    A_CONSTANT = 23637
    A_FRACTION = 14
    
    mant_comp = (1 << 7) | mant
    shift_val = exp - 127
    
    if shift_val >= 0:
        safe_shift = min(shift_val, 40)
        shm = (mant_comp * A_CONSTANT) << safe_shift
    else:
        safe_shift = min(-shift_val, 30)
        shm = (mant_comp * A_CONSTANT) >> safe_shift

    # Round to Nearest
    round_bit = (shm >> (A_FRACTION - 1)) & 1
    shm_final = (shm >> A_FRACTION) + round_bit
    if sign == 1: shm_final = -shm_final

    # 4. Decompose scaled value into Exponent and Mantissa Fraction
    nm = shm_final & 0x7F
    ne = (shm_final >> 7) + 127

    # 5. Handle Extreme Overflow
    if shift_val > 40:
        ne = 255 if sign == 0 else -128

    # 6. Piecewise Linear Mantissa Correction (The Fix is here: nm << 1)
    ALPHA, BETA = 4, 7
    GAMMA1, GAMMA2 = 363, 278
    
    if nm < 64:
        res_add = nm + GAMMA1
        res_mul = (nm << 1) * ALPHA  # Added surplus shift << 1
        res_final = (res_mul * res_add) >> 12
    else:
        res_add = nm + GAMMA2
        res_mul = BETA * (255 - (nm << 1) - 1) # Surplus shift already here
        res_final = 127 - ((res_mul * res_add) >> 12)

    # 7. Final Saturation and Subnormal Logic
    if ne >= 255: return 0x7F80
    
    if 0 >= ne > -8:
        # For subnormals, we use the corrected mantissa bits
        explicit_mant = (1 << 7) | (res_final & 0x7F)
        return (explicit_mant >> (1 - ne)) & 0x7F
        
    if ne <= -8: return 0x0000

    return ((ne & 0xFF) << 7) | (res_final & 0x7F)

def run_sweep():
    TEST_SIZE = 65536
    print(f"Starting full bitwise sweep of all {TEST_SIZE} BF16 bit patterns...")
    all_bits = np.arange(TEST_SIZE, dtype=np.uint16)
    
    # Compute PyTorch reference
    input_tensors = int_to_bf16(all_bits)
    ref_exp = torch.exp(input_tensors)
    ref_bits = bf16_to_int(ref_exp)
    
    # Compute HW Simulation using bitwise function
    print("Computing Bitwise HW Simulation...")
    hw_bits = np.array([bf16_exp_bitwise(int(b)) for b in all_bits], dtype=np.uint16)
    
    # Calculate ULP Error
    ulp_error = np.abs(hw_bits.astype(np.int32) - ref_bits.astype(np.int32))
    
    # Export to CSV
    csv_path = "bitwise_sweep_results.csv"
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
            
    # --- Statistics Logic ---
    input_exp = (all_bits >> 7) & 0xFF
    input_mant = all_bits & 0x7F
    
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
    
    print(f"\nBitwise Sweep Statistics ({total_count} values, {label}):")
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