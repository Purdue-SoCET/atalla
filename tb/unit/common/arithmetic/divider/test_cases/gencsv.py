import torch

def generate_exhaustive_reciprocal_csv(filename):
    print(f"Generating exhaustive BF16 reciprocal tests with FTZ...")
    
    # 1. Generate 0 to 65535 as int32
    op_t = torch.arange(0, 65536, dtype=torch.int32)
    
    # --- HARDWARE MIMIC: INPUT FLUSH-TO-ZERO ---
    # In BF16, exponent is bits [14:7]. If it's 0, flush mantissa [6:0] to 0, keep sign [15].
    exp_mask = 0x7F80
    sign_mask = 0x8000
    
    is_subnormal_in = (op_t & exp_mask) == 0
    # If subnormal, mask out the mantissa to make it a true zero
    op_t_ftz = torch.where(is_subnormal_in, op_t & sign_mask, op_t)
    
    # 2. Cast to int16 and view as hardware BF16 floats
    op_bf = op_t_ftz.to(torch.int16).view(torch.bfloat16)
    
    # Create a tensor for 1.0 in bfloat16
    one_bf = torch.tensor(1.0, dtype=torch.bfloat16)
    
    # 3. Perform the perfect "Golden" reciprocal natively in PyTorch
    res_bf = one_bf / op_bf
    
    # 4. View result as int16, then cast back to int32 for bitwise ops
    res_ints = res_bf.view(torch.int16).to(torch.int32)
    
    # --- HARDWARE MIMIC: OUTPUT FLUSH-TO-ZERO ---
    is_subnormal_out = (res_ints & exp_mask) == 0
    # If result is subnormal, flush to zero (keeping the sign)
    res_ints_ftz = torch.where(is_subnormal_out, res_ints & sign_mask, res_ints)
    
    # Extract to standard Python lists for the formatting loop
    # Note: We use the original op_t list so the CSV input column matches the raw 16-bit vector exactly
    op_ints_list = op_t.tolist()
    res_ints_list = res_ints_ftz.tolist()
    
    # Write to the CSV file matching your Verilog $fscanf format (%h,%h\n)
    with open(filename, 'w') as f:
        for i in range(len(op_ints_list)):
            hin = f"{op_ints_list[i] & 0xFFFF:04x}"
            hr = f"{res_ints_list[i] & 0xFFFF:04x}"
            f.write(f"{hin},{hr}\n")
            
    print(f"Success! Wrote {len(op_ints_list)} test vectors to {filename}")

if __name__ == "__main__":
    generate_exhaustive_reciprocal_csv("recip_bf16_normal_tests_all.csv")