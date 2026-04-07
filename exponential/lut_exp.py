import numpy as np
import torch
import csv
import os

# --- TOGGLE SETTINGS ---
EXCLUDE_NANS_STATS = True  # Set to False to include NaNs in the final statistics
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

# Table-Driven Simulation Class
class TableDrivenExpBF16:
    def __init__(self, table_bits=8):
        self.LOG2_E = 1.44269504089
        self.table_bits = table_bits
        self.table_size = 2 ** table_bits
        
        # Pre-compute Table (stored as BF16)
        indices = torch.arange(0, self.table_size, dtype=torch.float32)
        fractional_parts = indices / self.table_size
        lut_values = torch.pow(2.0, fractional_parts)
        self.lut = lut_values.to(torch.bfloat16)

    def forward_bits(self, x_bits):
        """Processes an array of uint16 bits and returns simulated result bits."""
        x = int_to_bf16(x_bits)
        
        # 1. Base-2 Transform: y = x * log2(e)
        y = x.to(torch.float32) * self.LOG2_E
        
        # 2. Integer Split: y = N + f
        N = torch.floor(y)
        f = y - N
        
        # 3. Table Lookup
        index = (f * self.table_size).to(torch.long)
        index = torch.clamp(index, min=0, max=self.table_size - 1)
        mantissa_approx = self.lut[index]
        
        # 4. Reconstruction with Saturation Guards
        # Handle extreme values to prevent ldexp overflow
        N_val = N.to(torch.float32)
        result = torch.ldexp(mantissa_approx.to(torch.float32), N.to(torch.int32))
        
        # Apply Saturation (+Inf for large x, 0.0 for large negative x)
        result = torch.where(N_val > 127, torch.tensor(float('inf')), result)
        result = torch.where(N_val < -150, torch.tensor(0.0), result)
        
        return bf16_to_int(result.to(torch.bfloat16))

def run_table_sweep(table_bits=8):
    TEST_SIZE = 65536
    all_bits = np.arange(TEST_SIZE, dtype=np.uint16)
    
    # Initialize model
    model = TableDrivenExpBF16(table_bits=table_bits)
    
    # 1. Compute PyTorch Reference
    input_tensors = int_to_bf16(all_bits)
    ref_exp = torch.exp(input_tensors)
    ref_bits = bf16_to_int(ref_exp)
    
    # 2. Compute Table-Driven Simulation
    print(f"Computing sweep for LUT size 2^{table_bits} ({2**table_bits} entries)...")
    hw_bits = model.forward_bits(all_bits)
    
    # 3. Calculate ULP Error
    ulp_error = np.abs(hw_bits.astype(np.int32) - ref_bits.astype(np.int32))
    
    # 4. Export to CSV
    csv_path = f"table_driven_sweep_{table_bits}bits.csv"
    input_floats = input_tensors.to(torch.float32).numpy()
    
    print(f"Exporting results to {csv_path}...")
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
            
    # 5. Report Statistics
    input_exp = (all_bits >> 7) & 0xFF
    input_mant = all_bits & 0x7F
    is_nan = (input_exp == 0xFF) & (input_mant != 0)
    
    if EXCLUDE_NANS_STATS:
        valid_mask = ~is_nan
        label = "excluding Input NaNs"
    else:
        valid_mask = np.ones(TEST_SIZE, dtype=bool)
        label = "including ALL patterns"
    
    filtered_errors = ulp_error[valid_mask]
    total_count = len(filtered_errors)
    max_ulp = np.max(filtered_errors)
    mean_ulp = np.mean(filtered_errors)
    accuracy = np.sum(filtered_errors == 0) / total_count * 100
    
    print(f"Sweep Statistics ({label}):")
    print(f"  Max ULP Error:  {max_ulp}")
    print(f"  Mean ULP Error: {mean_ulp:.4f}")
    print(f"  Exact Accuracy: {accuracy:.2f}%")
    print("-" * 40)

if __name__ == "__main__":
    for bits in range(22):
        run_table_sweep(table_bits=bits)