import os
import sys
import glob
import matplotlib.pyplot as plt

# Run: python schmoo_data_analyze_avg.py <path_to_directory>

# Check for command line argument
if len(sys.argv) < 2:
    print("Usage: python schmoo_data_analyze.py <path_to_directory>")
    sys.exit(1)

target_dir = sys.argv[1]

print(f"Locating Schmoo result directories in {target_dir}...")
# Find all folders matching the pattern in the target directory
search_pattern = os.path.join(target_dir, "schmoo_adder_tree_*")
result_dirs = glob.glob(search_pattern)

if not result_dirs:
    print(f"Error: No directories found matching 'schmoo_adder_tree_*' in {target_dir}.")
    sys.exit(1)

print(f"Found {len(result_dirs)} data sets. Generating individual graphs...")

mantissas = list(range(23, 31))

# Helper function to add data labels to the points
def add_labels(ax, x, y, format_str="{}"):
    for i, j in zip(x, y):
        ax.annotate(format_str.format(j), 
                    (i, j), 
                    textcoords="offset points", 
                    xytext=(0,8),
                    ha='center',
                    fontsize=9)

# Loop through every directory found
for d in result_dirs:
    # Use basename to avoid mangling the rest of the path string
    seed = os.path.basename(d).replace("schmoo_adder_tree_", "")
    print(f"Processing data for seed: {seed}...")
    
    # Initialize lists to store extracted data FOR THIS RUN ONLY
    max_ulp = []
    avg_ulp = []
    ulp_gt_1 = []
    pass_percent = []

    # Read and parse each file in the current directory
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
                    # Extract values based on the specific final report format
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
            
        # Append to our data lists
        max_ulp.append(cur_max)
        avg_ulp.append(cur_avg)
        ulp_gt_1.append(cur_ulp_gt_1)
        
        # Calculate percentage
        percentage = (cur_passed / cur_total) * 100
        pass_percent.append(percentage)

    # Create a 2x2 grid of subplots for this specific seed
    fig, axs = plt.subplots(2, 2, figsize=(14, 10))
    fig.suptitle(f'Systolic Array FP32 Accumulator BF16 Diagnostics vs. Mantissa Size\n(Seed: {seed})', fontsize=16, fontweight='bold')

    # 1. Max ULP Error Graph
    axs[0, 0].plot(mantissas, max_ulp, marker='o', color='red', linestyle='-')
    axs[0, 0].set_title('Max ULP Error')
    axs[0, 0].set_xlabel('Mantissa Size')
    axs[0, 0].set_ylabel('ULP')
    axs[0, 0].set_xticks(mantissas)
    add_labels(axs[0, 0], mantissas, max_ulp, "{}")

    # 2. Average ULP Error Graph
    axs[0, 1].plot(mantissas, avg_ulp, marker='o', color='orange', linestyle='-')
    axs[0, 1].set_title('Average ULP Error')
    axs[0, 1].set_xlabel('Mantissa Size')
    axs[0, 1].set_ylabel('ULP')
    axs[0, 1].set_xticks(mantissas)
    axs[0, 1].ticklabel_format(useOffset=False, style='plain', axis='y')
    add_labels(axs[0, 1], mantissas, avg_ulp, "{:.6f}") 

    # 3. ULP > 1 Count Graph
    axs[1, 0].plot(mantissas, ulp_gt_1, marker='o', color='purple', linestyle='-')
    axs[1, 0].set_title('Cases where ULP > 1')
    axs[1, 0].set_xlabel('Mantissa Size')
    axs[1, 0].set_ylabel('Count')
    axs[1, 0].set_xticks(mantissas)
    add_labels(axs[1, 0], mantissas, ulp_gt_1, "{}")

    # 4. Pass Percentage Graph
    axs[1, 1].plot(mantissas, pass_percent, marker='o', color='green', linestyle='-')
    axs[1, 1].set_title('Pass Percentage')
    axs[1, 1].set_xlabel('Mantissa Size')
    axs[1, 1].set_ylabel('Percentage (%)')
    axs[1, 1].set_xticks(mantissas)
    axs[1, 1].ticklabel_format(useOffset=False, style='plain', axis='y')
    add_labels(axs[1, 1], mantissas, pass_percent, "{:.4f}%") 

    # Add dynamic padding to the Y-axis of all subplots so labels don't clip
    for ax in axs.flat:
        ax.margins(y=0.15) 

    # Adjust layout to prevent overlapping text
    plt.tight_layout()
    fig.subplots_adjust(top=0.90) 

    # Save the figure with the seed in the filename
    out_filename = f"schmoo_results_{seed}.png"
    plt.savefig(out_filename, dpi=300)
    print(f"  -> Graph saved as {out_filename}")
    
    # CRITICAL: Close the figure so it doesn't overlap with the next loop's graph
    plt.close(fig)

print("\nAll batch graphs generated successfully!")