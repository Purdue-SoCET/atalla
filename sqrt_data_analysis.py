import numpy as np
import matplotlib.pyplot as plt
import csv

def hex_to_fp16(hex_str):
    """Convert hex string to FP16 value"""
    # Remove 0x prefix if present
    if hex_str.startswith('0x') or hex_str.startswith('0X'):
        hex_str = hex_str[2:]
    bits = int(hex_str, 16)
    return np.uint16(bits).view(np.float16)

def hex_to_bits(hex_str):
    """Convert hex string to uint16 bits"""
    if hex_str.startswith('0x') or hex_str.startswith('0X'):
        hex_str = hex_str[2:]
    return int(hex_str, 16)

# Read the CSV file
input_vals = []
expected_vals = []
output_vals = []
ulp_errors = []

with open('sqrt_test_results.csv', 'r') as f:
    reader = csv.DictReader(f)
    for row in reader:
        input_hex = row['Input']
        expected_hex = row['Expected']
        output_hex = row['Output']
        ulp = int(row['ULP'])
        
        # Convert to FP16 values
        inp = hex_to_fp16(input_hex)
        exp = hex_to_fp16(expected_hex)
        out = hex_to_fp16(output_hex)
        
        # Only plot finite values for visualization
        if np.isfinite(inp) and np.isfinite(exp) and np.isfinite(out):
            input_vals.append(float(inp))
            expected_vals.append(float(exp))
            output_vals.append(float(out))
            ulp_errors.append(ulp)

# Convert to numpy arrays
input_vals = np.array(input_vals)
expected_vals = np.array(expected_vals)
output_vals = np.array(output_vals)
ulp_errors = np.array(ulp_errors)

# Create figure with subplots
fig, axes = plt.subplots(2, 2, figsize=(14, 10))

# Plot 1: Expected vs Output
ax1 = axes[0, 0]
ax1.scatter(expected_vals, output_vals, alpha=0.3, s=1)
ax1.plot([expected_vals.min(), expected_vals.max()], 
         [expected_vals.min(), expected_vals.max()], 'r--', linewidth=2, label='Perfect Match')
ax1.set_xlabel('Expected Output')
ax1.set_ylabel('Actual Output')
ax1.set_title('Expected vs Actual Output')
ax1.legend()
ax1.grid(True, alpha=0.3)

# Plot 2: Error (Output - Expected)
ax2 = axes[0, 1]
errors = output_vals - expected_vals
ax2.scatter(input_vals, errors, alpha=0.3, s=1)
ax2.axhline(y=0, color='r', linestyle='--', linewidth=2)
ax2.set_xlabel('Input Value')
ax2.set_ylabel('Error (Output - Expected)')
ax2.set_title('Absolute Error vs Input')
ax2.grid(True, alpha=0.3)

# Plot 3: ULP Error Distribution
ax3 = axes[1, 0]
unique_ulps, counts = np.unique(ulp_errors, return_counts=True)
ax3.bar(unique_ulps, counts, width=0.8)
ax3.set_xlabel('ULP Error')
ax3.set_ylabel('Count')
ax3.set_title('ULP Error Distribution')
ax3.grid(True, alpha=0.3, axis='y')

# Plot 4: ULP Error vs Input
ax4 = axes[1, 1]
ax4.scatter(input_vals, ulp_errors, alpha=0.3, s=1)
ax4.axhline(y=0, color='r', linestyle='--', linewidth=2)
ax4.set_xlabel('Input Value')
ax4.set_ylabel('ULP Error')
ax4.set_title('ULP Error vs Input')
ax4.grid(True, alpha=0.3)

plt.tight_layout()

# Print statistics
print("\n=== Statistics ===")
print(f"Total test cases: {len(ulp_errors)}")
print(f"Perfect matches (ULP=0): {np.sum(ulp_errors == 0)} ({100*np.sum(ulp_errors == 0)/len(ulp_errors):.2f}%)")
print(f"Max ULP error: {np.max(np.abs(ulp_errors))}")
print(f"Mean ULP error: {np.mean(ulp_errors):.4f}")
print(f"Mean absolute ULP error: {np.mean(np.abs(ulp_errors)):.4f}")

# Show worst cases
worst_indices = np.argsort(np.abs(ulp_errors))[-10:]
print("\n=== Top 10 Worst Cases ===")
for idx in reversed(worst_indices):
    print(f"Input: {input_vals[idx]:.6f}, Expected: {expected_vals[idx]:.6f}, "
          f"Got: {output_vals[idx]:.6f}, ULP Error: {ulp_errors[idx]}")

plt.savefig('sqrt_results_analysis.png', dpi=150, bbox_inches='tight')
print("\nPlot saved as 'sqrt_results_analysis.png'")
plt.show()