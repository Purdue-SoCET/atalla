#!/usr/bin/env python3
"""
BF16 Hex to Detailed Format Converter using PyTorch
Usage: python bf16_decoder.py <hex_value>
Example: python bf16_decoder.py 0x4040
"""

import torch
import struct
import sys

def bf16_hex_to_float(hex_val):
    """Convert BF16 hex to float32 value using PyTorch"""
    # Remove 0x prefix if present
    if isinstance(hex_val, str):
        hex_val = hex_val.replace('0x', '').replace('0X', '')
        bits = int(hex_val, 16)
    else:
        bits = hex_val
    
    # Ensure 16-bit value
    bits = bits & 0xFFFF
    
    # Expand to float32 by shifting left 16 bits
    u32 = bits << 16
    f32 = struct.unpack('<f', struct.pack('<I', u32))[0]
    
    # Convert to PyTorch bfloat16 and back to get canonical representation
    torch_bf16 = torch.tensor(f32, dtype=torch.bfloat16)
    canonical_f32 = torch_bf16.to(torch.float32).item()
    
    return canonical_f32, bits

def decode_bf16(bits):
    """Decode BF16 bit pattern into components"""
    sign = (bits >> 15) & 0x1
    exponent = (bits >> 7) & 0xFF
    mantissa = bits & 0x7F
    
    return sign, exponent, mantissa

def classify_bf16(bits):
    """Classify the BF16 value"""
    sign, exponent, mantissa = decode_bf16(bits)
    
    if exponent == 0:
        if mantissa == 0:
            return "Zero"
        else:
            return "Subnormal"
    elif exponent == 0xFF:
        if mantissa == 0:
            return "Infinity"
        else:
            # Check if quiet or signaling NaN
            if mantissa & 0x40:
                return "NaN (Quiet)"
            else:
                return "NaN (Signaling)"
    else:
        return "Normal"

def format_binary(value, bits):
    """Format binary with underscores for readability"""
    binary = format(value, f'0{bits}b')
    return binary

def print_bf16_details(hex_input):
    """Print detailed information about a BF16 value"""
    try:
        value, bits = bf16_hex_to_float(hex_input)
        sign, exponent, mantissa = decode_bf16(bits)
        classification = classify_bf16(bits)
        
        # Format output
        print("=" * 60)
        print(f"BF16 Hex Input: 0x{bits:04X}")
        print("=" * 60)
        
        # Binary representation
        print(f"\nBinary: {format_binary(bits, 16)}")
        print(f"        {'S':^1} {'Exponent':^8} {'Mantissa':^7}")
        print(f"        {format_binary(sign, 1):^1} {format_binary(exponent, 8):^8} {format_binary(mantissa, 7):^7}")
        
        # Components
        print(f"\nComponents:")
        print(f"  Sign:     {sign} ({'negative' if sign else 'positive'})")
        print(f"  Exponent: {exponent:3d} (0x{exponent:02X}, 0b{format_binary(exponent, 8)})")
        print(f"  Mantissa: {mantissa:3d} (0x{mantissa:02X}, 0b{format_binary(mantissa, 7)})")
        
        # Classification
        print(f"\nClassification: {classification}")
        
        # Value interpretation
        print(f"\nValue Interpretation:")
        if classification == "Zero":
            print(f"  {'-0.0' if sign else '+0.0'}")
        elif classification == "Infinity":
            print(f"  {'-∞' if sign else '+∞'}")
        elif classification.startswith("NaN"):
            print(f"  NaN (Not a Number)")
        elif classification == "Subnormal":
            # Subnormal: (-1)^sign × 2^-126 × (0.mantissa)
            mantissa_val = mantissa / 128.0  # 2^7 = 128
            unbiased_exp = -126
            actual_value = (-1)**sign * (2**unbiased_exp) * mantissa_val
            print(f"  Subnormal value: {actual_value:.6e}")
            print(f"  Formula: (-1)^{sign} × 2^{unbiased_exp} × (0.{format_binary(mantissa, 7)})")
        else:  # Normal
            # Normal: (-1)^sign × 2^(exp-127) × (1.mantissa)
            unbiased_exp = exponent - 127
            mantissa_val = 1.0 + (mantissa / 128.0)  # Implicit leading 1
            actual_value = (-1)**sign * (2**unbiased_exp) * mantissa_val
            print(f"  Normal value: {actual_value:.6e}")
            print(f"  Formula: (-1)^{sign} × 2^{unbiased_exp} × (1.{format_binary(mantissa, 7)})")
        
        # PyTorch conversion
        print(f"\nPyTorch Conversion:")
        print(f"  Float32 value: {value}")
        print(f"  Scientific:    {value:.6e}")
        
        # Show PyTorch tensor representation
        torch_bf16 = torch.tensor(value, dtype=torch.bfloat16)
        print(f"  PyTorch tensor: {torch_bf16}")
        
        # Additional info for special values
        if classification == "Subnormal":
            print(f"\n⚠️  DAZ (Denormals-Are-Zero): Would flush to {'-0' if sign else '+0'}")
        
        print("=" * 60)
        
    except ValueError as e:
        print(f"Error: Invalid hex input '{hex_input}': {e}")
    except Exception as e:
        print(f"Error: {e}")

def batch_decode(hex_list):
    """Decode multiple BF16 values"""
    for hex_val in hex_list:
        print_bf16_details(hex_val)
        print()

def interactive_mode():
    """Interactive mode for continuous decoding"""
    print("BF16 Decoder - Interactive Mode")
    print("Enter BF16 hex values (e.g., 0x4040 or 4040)")
    print("Type 'quit' or 'exit' to stop\n")
    
    while True:
        try:
            user_input = input("BF16 Hex> ").strip()
            if user_input.lower() in ['quit', 'exit', 'q']:
                print("Goodbye!")
                break
            if not user_input:
                continue
            
            print_bf16_details(user_input)
            print()
        except KeyboardInterrupt:
            print("\nGoodbye!")
            break
        except EOFError:
            print("\nGoodbye!")
            break

def main():
    if len(sys.argv) < 2:
        print("Usage: python bf16_decoder.py <hex_value> [hex_value2 ...]")
        print("   or: python bf16_decoder.py -i  (interactive mode)")
        print("\nExamples:")
        print("  python bf16_decoder.py 0x4040")
        print("  python bf16_decoder.py 4040")
        print("  python bf16_decoder.py 0x7f80 0x0001 0x7fc0")
        print("  python bf16_decoder.py -i")
        sys.exit(1)
    
    # Interactive mode
    if sys.argv[1] == '-i' or sys.argv[1] == '--interactive':
        interactive_mode()
    # Batch mode
    elif len(sys.argv) > 2:
        batch_decode(sys.argv[1:])
    # Single value
    else:
        print_bf16_details(sys.argv[1])

if __name__ == "__main__":
    main()