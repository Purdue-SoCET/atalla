import os
import sys
import glob
import matplotlib.pyplot as plt

# Check for command line argument
if len(sys.argv) < 2:
    print("Usage: python schmoo_data_analyze_avg.py <path_to_directory>")
    sys.exit(1)

target_dir = sys.argv[1]

print(f"Locating Schmoo result directories in {target_dir}...")
search_pattern = os.path.join(target_dir, "schmoo_adder_tree_*")
result_dirs = glob.glob(search_pattern)

if not result_dirs:
    print(f"Error: No directories found matching 'schmoo_adder_tree_*' in {target_dir}.")
    sys.exit(1)

num_sets = len(result_dirs)
print(f"Found {num_sets} data sets. Aggregating data...")

mantissas = list(range(23, 31))

# Initialize a dictionary to hold all the raw data before aggregating
raw_data = {m: {'max': [], 'avg': [], 'gt_1': [], 'pass_rates': []} for m in mantissas}

# 1. Parse data from all folders
for d in result_dirs:
    for m in mantissas:
        filepath = os.path.join(d, f"output_mantissa_{m}.txt")
        
        cur_max = 0
        cur_avg = 0.0
        cur_ulp_gt_1 = 0
        cur_passed = 0
        cur_total = 1  
        
        if os.path.exists(filepath):
            with open(filepath, 'r') as f:
                for line in f:
                    if "MAX ULP ERR:" in line:
                        cur_max = int(line.split(":")[1].strip())
                    elif "AVG ULP ERR:" in line:
                        cur_avg = float(line.split(":")[1].strip())
                    elif "ULP > 1:" in line:
                        cur_ulp_gt_1 = int(line.split(":")[1].strip())
                    elif "PASSED:" in line:
                        cur_passed = int(line.split(":")[1].strip())
                    elif "TOTAL CASES:" in line:
                        cur_total = int(line.split(":")[1].strip())
        else:
            print(f"  Warning: {filepath} not found. Using 0 for missing data.")
            
        # Store values for this specific mantissa
        raw_data[m]['max'].append(cur_max)
        raw_data[m]['avg'].append(cur_avg)
        raw_data[m]['gt_1'].append(cur_ulp_gt_1)
        raw_data[m]['pass_rates'].append((cur_passed / cur_total) * 100)

# 2. Calculate the metrics
overall_max_ulp = []
avg_avg_ulp = []
total_ulp_gt_1 = []  # Changed from avg to total
avg_pass_percent = []

for m in mantissas:
    overall_max_ulp.append(max(raw_data[m]['max']))
    avg_avg_ulp.append(sum(raw_data[m]['avg']) / num_sets)
    # Sum the values instead of averaging
    total_ulp_gt_1.append(sum(raw_data[m]['gt_1']))
    avg_pass_percent.append(sum(raw_data[m]['pass_rates']) / num_sets)

print("Generating aggregated graphs...")

# 3. Create the 2x2 grid of subplots
fig, axs = plt.subplots(2, 2, figsize=(14, 10))
fig.suptitle(f'Systolic Array FP32 Accumulator BF16 Diagnostics vs. Mantissa Size\n(Aggregated across {num_sets} datasets, Constrained Exponent)', fontsize=16, fontweight='bold')

# Helper function to add data labels to the points
def add_labels(ax, x, y, format_str="{}"):
    for i, j in zip(x, y):
        ax.annotate(format_str.format(j), 
                    (i, j), 
                    textcoords="offset points", 
                    xytext=(0,8), 
                    ha='center',
                    fontsize=9)

# Graph 1: Overall Max ULP
axs[0, 0].plot(mantissas, overall_max_ulp, marker='o', color='red', linestyle='-')
axs[0, 0].set_title('Overall Max ULP Error')
axs[0, 0].set_xlabel('Mantissa Size')
axs[0, 0].set_ylabel('ULP')
axs[0, 0].set_xticks(mantissas)
add_labels(axs[0, 0], mantissas, overall_max_ulp, "{}")

# Graph 2: Average of Average ULP
axs[0, 1].plot(mantissas, avg_avg_ulp, marker='o', color='orange', linestyle='-')
axs[0, 1].set_title('Average of Avg ULP Error')
axs[0, 1].set_xlabel('Mantissa Size')
axs[0, 1].set_ylabel('ULP')
axs[0, 1].set_xticks(mantissas)
axs[0, 1].ticklabel_format(useOffset=False, style='plain', axis='y')
add_labels(axs[0, 1], mantissas, avg_avg_ulp, "{:.6f}") 

# Graph 3: Total ULP > 1 Count
axs[1, 0].plot(mantissas, total_ulp_gt_1, marker='o', color='purple', linestyle='-')
axs[1, 0].set_title('Total Cases where ULP > 1')
axs[1, 0].set_xlabel('Mantissa Size')
axs[1, 0].set_ylabel('Count')
axs[1, 0].set_xticks(mantissas)
# Format as a whole integer since it's a sum
add_labels(axs[1, 0], mantissas, total_ulp_gt_1, "{}")

# Graph 4: Average Pass Percentage
axs[1, 1].plot(mantissas, avg_pass_percent, marker='o', color='green', linestyle='-')
axs[1, 1].set_title('Average Pass Percentage')
axs[1, 1].set_xlabel('Mantissa Size')
axs[1, 1].set_ylabel('Percentage (%)')
axs[1, 1].set_xticks(mantissas)
axs[1, 1].ticklabel_format(useOffset=False, style='plain', axis='y')
add_labels(axs[1, 1], mantissas, avg_pass_percent, "{:.4f}%") 

# Add dynamic padding to the Y-axis of all subplots so labels don't clip
for ax in axs.flat:
    ax.margins(y=0.15) 

# Adjust layout
plt.tight_layout()
fig.subplots_adjust(top=0.90) 

# Save the combined aggregated figure
out_filename = "schmoo_aggregated_results.png"
plt.savefig(out_filename, dpi=300)
print(f"Graph saved as {out_filename}")
plt.show()