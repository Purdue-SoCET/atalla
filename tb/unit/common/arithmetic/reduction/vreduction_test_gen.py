import random
import torch

def tensor_to_hex(bf16_tensor):
    """Convert BF16 tensor to hex string"""
    uint_val = bf16_tensor.view(torch.int16).item() & 0xFFFF
    return f"{uint_val:04x}"

def hex_to_tensor(hex_str):
    """Convert hex string to BF16 tensor"""
    uint_val = int(hex_str, 16)
    int_tensor = torch.tensor(uint_val, dtype=torch.int16)
    return int_tensor.view(torch.bfloat16)

def is_subnormal(bf16_tensor):
    """Check if BF16 value is subnormal (exponent = 0, mantissa != 0)"""
    bits = bf16_tensor.view(torch.int16).item() & 0xFFFF
    exponent = (bits >> 7) & 0xFF
    mantissa = bits & 0x7F
    return (exponent == 0) and (mantissa != 0)

def is_nan(bf16_tensor):
    """Check if BF16 value is NaN (exponent = all 1s, mantissa != 0)"""
    return torch.isnan(bf16_tensor)

def is_negative_zero(bf16_tensor):
    """Check if BF16 value is negative zero"""
    bits = bf16_tensor.view(torch.int16).item() & 0xFFFF
    return bits == 0x8000

def normalize_value(bf16_tensor):
    """Treat subnormals and negative zero as +0, pass through everything else"""
    if is_subnormal(bf16_tensor) or is_negative_zero(bf16_tensor):
        return torch.tensor(0.0, dtype=torch.bfloat16)
    return bf16_tensor

def generate_bf16_vector(size=32):
    """Generate random BF16 values as tensors"""
    values = []
    for _ in range(size):
        # Generate random float in reasonable range and convert to BF16
        f = random.uniform(-100.0, 100.0)
        bf16_val = torch.tensor(f, dtype=torch.bfloat16)
        # Treat subnormals and negative zero as +0
        bf16_val = normalize_value(bf16_val)
        values.append(bf16_val)
    return values

def compute_reduction(bf16_values, reduction_type):
    """Compute reduction result in pure BF16 arithmetic over first 16 elements"""
    # Use first 16 elements and normalize them (subnormals and -0 -> +0)
    values = [normalize_value(v) for v in bf16_values[:16]]
    
    # Check if any input is NaN
    has_nan = any(is_nan(v) for v in values)
    
    # If any input is NaN, return NaN (canonical NaN for BF16: 0x7FC0)
    if has_nan:
        nan_bits = 0x7FC0
        return torch.tensor(nan_bits, dtype=torch.int16).view(torch.bfloat16)
    
    if reduction_type == 'sum':
        # Sequential sum in BF16
        result = values[0]
        for i in range(1, len(values)):
            result = result + values[i]
            result = normalize_value(result)  # Treat subnormal results and -0 as +0
        return result
    
    elif reduction_type == 'min':
        # Sequential min comparison
        result = values[0]
        for i in range(1, len(values)):
            result = torch.min(result, values[i])
        result = normalize_value(result)  # Normalize final result
        return result
    
    elif reduction_type == 'max':
        # Sequential max comparison
        result = values[0]
        for i in range(1, len(values)):
            result = torch.max(result, values[i])
        result = normalize_value(result)  # Normalize final result
        return result
    
    else:
        raise ValueError(f"Unknown reduction type: {reduction_type}")

def generate_testcase(test_id, reduction_type):
    """Generate a single test case"""
    # Generate random input vector (32 BF16 tensors)
    input_vector = generate_bf16_vector(32)
    
    # Generate random immediate (5 bits: 0-31)
    imm = random.randint(0, 31)
    
    # Generate random control bits (ensure clear and broadcast are not both 1)
    clear = random.choice([0, 1])
    if clear == 1:
        broadcast = 0
    else:
        broadcast = random.choice([0, 1])
    
    # Compute reduction result in BF16
    reduction_result = compute_reduction(input_vector, reduction_type)
    
    # Compute expected output
    if clear == 1:
        # Empty vector with only index imm having the result
        expected = [torch.tensor(0.0, dtype=torch.bfloat16)] * 32
        expected[imm] = reduction_result
    elif broadcast == 1:
        # All elements set to reduction result
        expected = [reduction_result] * 32
    else:
        # Copy input and replace index imm with result
        expected = input_vector.copy()
        expected[imm] = reduction_result
    
    return {
        'test_id': test_id,
        'reduction_type': reduction_type,
        'input_vector': input_vector,
        'imm': imm,
        'clear': clear,
        'broadcast': broadcast,
        'expected': expected
    }

def generate_special_cases():
    """Generate hardcoded test cases with NaN and Inf values"""
    special_tests = []
    
    # Create special values
    nan_val = torch.tensor(float('nan'), dtype=torch.bfloat16)
    pos_inf = torch.tensor(float('inf'), dtype=torch.bfloat16)
    neg_inf = torch.tensor(float('-inf'), dtype=torch.bfloat16)
    pos_zero = torch.tensor(0.0, dtype=torch.bfloat16)
    neg_zero = torch.tensor(-0.0, dtype=torch.bfloat16)
    one = torch.tensor(1.0, dtype=torch.bfloat16)
    
    test_configs = [
        # NaN tests - NaN should propagate
        ('sum', [nan_val] + [one] * 15 + [pos_zero] * 16, 5, 0, 0, "NaN in sum"),
        ('min', [nan_val] + [one] * 15 + [pos_zero] * 16, 10, 0, 0, "NaN in min"),
        ('max', [nan_val] + [one] * 15 + [pos_zero] * 16, 15, 0, 0, "NaN in max"),
        
        # NaN with broadcast
        ('sum', [nan_val] + [one] * 15 + [pos_zero] * 16, 3, 0, 1, "NaN broadcast"),
        
        # NaN with clear
        ('sum', [nan_val] + [one] * 15 + [pos_zero] * 16, 7, 1, 0, "NaN clear"),
        
        # Positive infinity tests
        ('sum', [pos_inf] + [one] * 15 + [pos_zero] * 16, 2, 0, 0, "pos_inf in sum"),
        ('min', [pos_inf] + [one] * 15 + [pos_zero] * 16, 8, 0, 0, "pos_inf in min"),
        ('max', [pos_inf] + [one] * 15 + [pos_zero] * 16, 12, 0, 0, "pos_inf in max"),
        
        # Negative infinity tests
        ('sum', [neg_inf] + [one] * 15 + [pos_zero] * 16, 4, 0, 0, "neg_inf in sum"),
        ('min', [neg_inf] + [one] * 15 + [pos_zero] * 16, 9, 0, 0, "neg_inf in min"),
        ('max', [neg_inf] + [one] * 15 + [pos_zero] * 16, 14, 0, 0, "neg_inf in max"),
        
        # Inf + Inf (same sign) = Inf
        ('sum', [pos_inf, pos_inf] + [pos_zero] * 14 + [pos_zero] * 16, 6, 0, 0, "inf+inf same sign"),
        
        # Inf + (-Inf) = NaN (indeterminate)
        ('sum', [pos_inf, neg_inf] + [pos_zero] * 14 + [pos_zero] * 16, 11, 0, 0, "inf+(-inf) = NaN"),
        
        # Mixed: some infinities with broadcast
        ('max', [neg_inf, pos_inf] + [one] * 14 + [pos_zero] * 16, 20, 0, 1, "inf broadcast"),
        
        # Zero handling (both -0 and +0 should be treated as +0)
        ('sum', [pos_zero] * 16 + [one] * 16, 0, 0, 0, "all +zeros sum"),
        ('sum', [neg_zero] * 16 + [one] * 16, 1, 0, 0, "all -zeros sum (treated as +0)"),
        ('min', [neg_zero, pos_zero] + [one] * 14 + [pos_zero] * 16, 2, 0, 0, "min of -0 and +0"),
        ('max', [neg_zero, pos_zero] + [one] * 14 + [pos_zero] * 16, 3, 0, 0, "max of -0 and +0"),
    ]
    
    for reduction_type, input_vals, imm, clear, broadcast, description in test_configs:
        input_vector = input_vals
        reduction_result = compute_reduction(input_vector, reduction_type)
        
        # Compute expected output
        if clear == 1:
            expected = [torch.tensor(0.0, dtype=torch.bfloat16)] * 32
            expected[imm] = reduction_result
        elif broadcast == 1:
            expected = [reduction_result] * 32
        else:
            expected = input_vector.copy()
            expected[imm] = reduction_result
        
        special_tests.append({
            'test_id': len(special_tests),
            'reduction_type': reduction_type,
            'input_vector': input_vector,
            'imm': imm,
            'clear': clear,
            'broadcast': broadcast,
            'expected': expected,
            'description': description
        })
    
    return special_tests

def write_testcases(num_tests_per_type=50):
    """Generate test cases and write to files"""
    
    reduction_types = ['sum', 'min', 'max']
    test_id = 0
    
    with open('inputs.txt', 'w') as inp_file, \
         open('expected.txt', 'w') as exp_file:
        
        # First, add hardcoded special value test cases
        print("Generating hardcoded special value test cases...")
        special_cases = generate_special_cases()
        for tc in special_cases:
            # Convert tensors to hex for writing
            input_hex = [tensor_to_hex(v) for v in tc['input_vector']]
            expected_hex = [tensor_to_hex(v) for v in tc['expected']]
            
            # Write input line
            input_line = ' '.join(input_hex)
            input_line += f" {tc['imm']:05b} {tc['clear']} {tc['broadcast']} {tc['reduction_type']}\n"
            inp_file.write(input_line)
            
            # Write expected line
            expected_line = ' '.join(expected_hex) + '\n'
            exp_file.write(expected_line)
            
            test_id += 1
        
        # Then generate random test cases
        print(f"Generating {num_tests_per_type} random test cases per reduction type...")
        for reduction_type in reduction_types:
            for _ in range(num_tests_per_type):
                tc = generate_testcase(test_id, reduction_type)
                
                # Convert tensors to hex for writing
                input_hex = [tensor_to_hex(v) for v in tc['input_vector']]
                expected_hex = [tensor_to_hex(v) for v in tc['expected']]
                
                # Write input line
                input_line = ' '.join(input_hex)
                input_line += f" {tc['imm']:05b} {tc['clear']} {tc['broadcast']} {reduction_type}\n"
                inp_file.write(input_line)
                
                # Write expected line
                expected_line = ' '.join(expected_hex) + '\n'
                exp_file.write(expected_line)
                
                test_id += 1
    
    print(f"Generated {test_id} total test cases")
    print(f"  - {len(special_cases)} special value test cases (NaN, Inf)")
    print(f"  - {num_tests_per_type} random tests per reduction type (sum, min, max)")
    print(f"  - Input file: inputs.txt")
    print(f"  - Expected file: expected.txt")
    print(f"\nNote: Requires PyTorch (pip install torch)")

def main():
    # Set random seed for reproducibility (optional)
    random.seed(42)
    torch.manual_seed(42)
    
    # Generate test cases
    write_testcases(num_tests_per_type=50)

if __name__ == '__main__':
    main()