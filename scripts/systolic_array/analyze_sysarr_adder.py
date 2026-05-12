import os
import sys
import glob
import matplotlib.pyplot as plt
from collections import defaultdict

# Run: python schmoo_data_aggregate.py <path_to_directory>

if len(sys.argv) < 2:
    print("Usage: python schmoo_data_aggregate.py <path_to_directory>")
    sys.exit(1)

target_dir = sys.argv[1]

print(f"Locating Schmoo result directories in {target_dir}...")

# Dictionary to hold grouped directories based on (Architecture, Mode)
groups = defaultdict(list)

# Discover directories and group them by Mode
all_dirs = glob.glob(os.path.join(target_dir, "schmoo_*"))
for d in all_dirs:
    if not os.path.isdir(d):
        continue
        
    basename = os.path.basename(d)
    parts = basename.split('_')
    mode = parts[-1] # Grabs 'Constrained' or 'Unconstrained'
    
    if "comparison" in basename:
        groups[('comparison', mode)].append(d)
    elif "adder_tree" in basename:
        groups[('tree', mode)].append(d)
    elif "fused_adder" in basename:
        groups[('fused', mode)].append(d)

if not groups:
    print(f"Error: No directories found matching 'schmoo_*' in {target_dir}.")
    sys.exit(1)

print(f"Found {len(all_dirs)} total data sets. Grouped into {len(groups)} testing modes.\n")

# --- Helper Functions ---

def parse_file(filepath):
    res = {'max_ulp': 0, 'avg_ulp': 0.0, 'ulp_gt_1': 0, 'passed': 0, 'total': 0, 'found': False}
    if not os.path.exists(filepath): 
        return res
    
    res['found'] = True
    with open(filepath, 'r') as f:
        for line in f:
            if "MAX ULP ERR:" in line: res['max_ulp'] = int(line.split(":")[1].strip())
            elif "AVG ULP ERR:" in line: res['avg_ulp'] = float(line.split(":")[1].strip())
            elif "ULP > 1:" in line: res['ulp_gt_1'] = int(line.split(":")[1].strip())
            elif "PASSED:" in line: res['passed'] = int(line.split(":")[1].strip())
            elif "TOTAL CASES:" in line: res['total'] = int(line.split(":")[1].strip())
    return res

def aggregate_data(directories, file_template, x_values):
    """Aggregates Max ULP, Average ULP, ULP > 1, and Pass Rates across multiple sets."""
    agg = {x: {'max': -1, 'avg_sum': 0.0, 'gt1': 0, 'pass': 0, 'tot': 0, 'count': 0} for x in x_values}
    
    for d in directories:
        for x in x_values:
            filepath = os.path.join(d, file_template.format(x))
            res = parse_file(filepath)
            if res['found']:
                agg[x]['max'] = max(agg[x]['max'], res['max_ulp'])
                agg[x]['avg_sum'] += res['avg_ulp']
                agg[x]['gt1'] += res['ulp_gt_1']
                agg[x]['pass'] += res['passed']
                agg[x]['tot'] += res['total']
                agg[x]['count'] += 1

    x_out, max_out, gt1_out, pass_out, avg_out = [], [], [], [], []
    for x in x_values:
        if agg[x]['count'] > 0:
            x_out.append(x)
            max_out.append(agg[x]['max'])
            gt1_out.append(agg[x]['gt1'])
            pass_out.append((agg[x]['pass'] / agg[x]['tot']) * 100 if agg[x]['tot'] > 0 else 0)
            avg_out.append(agg[x]['avg_sum'] / agg[x]['count'])

    return x_out, max_out, gt1_out, pass_out, avg_out

def add_labels(ax, x, y, format_str="{}", offset=(0,8)):
    """Added an offset parameter to prevent text overlapping on combined graphs."""
    for i, j in zip(x, y):
        ax.annotate(format_str.format(j), (i, j), textcoords="offset points", xytext=offset, ha='center', fontsize=8)

# --- Graphing Functions ---

def plot_single_architecture(x, max_u, gt1_u, pass_r, avg_u, title, x_label, out_name, color):
    if not x: return
    fig, axs = plt.subplots(2, 2, figsize=(14, 10))
    fig.suptitle(title, fontsize=16, fontweight='bold')

    # Max ULP
    axs[0, 0].plot(x, max_u, marker='o', color=color, linestyle='-')
    axs[0, 0].set_title('Max ULP Error (Across Sets)')
    axs[0, 0].set_xlabel(x_label); axs[0, 0].set_ylabel('ULP'); axs[0, 0].set_xticks(x)
    add_labels(axs[0, 0], x, max_u, "{}")

    # Avg ULP
    axs[0, 1].plot(x, avg_u, marker='o', color=color, linestyle='-')
    axs[0, 1].set_title('Average ULP Error (Across Sets)')
    axs[0, 1].set_xlabel(x_label); axs[0, 1].set_ylabel('ULP'); axs[0, 1].set_xticks(x)
    add_labels(axs[0, 1], x, avg_u, "{:.6f}")

    # ULP > 1
    axs[1, 0].plot(x, gt1_u, marker='o', color=color, linestyle='-')
    axs[1, 0].set_title('Total Cases ULP > 1 (Across Sets)')
    axs[1, 0].set_xlabel(x_label); axs[1, 0].set_ylabel('Count'); axs[1, 0].set_xticks(x)
    add_labels(axs[1, 0], x, gt1_u, "{}")

    # Pass Rate
    axs[1, 1].plot(x, pass_r, marker='o', color=color, linestyle='-')
    axs[1, 1].set_title('Pass Rate (Across Sets)')
    axs[1, 1].set_xlabel(x_label); axs[1, 1].set_ylabel('Percentage (%)'); axs[1, 1].set_xticks(x)
    add_labels(axs[1, 1], x, pass_r, "{:.4f}%")

    for ax in axs.flat: ax.margins(y=0.15)
    plt.tight_layout(); fig.subplots_adjust(top=0.90)
    plt.savefig(out_name, dpi=300)
    print(f"  -> Exported: {out_name}")
    plt.close(fig)

def plot_combined_architectures(t_x, t_max, t_gt1, t_pass, t_avg, f_x, f_max, f_gt1, f_pass, f_avg, title, out_name):
    if not t_x and not f_x: return
    fig, axs = plt.subplots(2, 2, figsize=(14, 10))
    fig.suptitle(title, fontsize=16, fontweight='bold')
    x_label = 'Equivalent Hardware Base Width\n(Tree Mantissa 23-30 | Fused Precision 0-7)'

    # Map Fused Precision X-axis (0-7) to align with Tree Mantissa (23-30)
    f_x_mapped = [x + 23 for x in f_x]
    all_x = list(set(t_x + f_x_mapped))
    
    # 1. Max ULP
    axs[0,0].plot(t_x, t_max, marker='o', color='red', label='4-Input Tree')
    axs[0,0].plot(f_x_mapped, f_max, marker='x', color='blue', label='32-Input Fused')
    axs[0,0].set_title('Max ULP Error'); axs[0,0].set_xlabel(x_label); axs[0,0].set_xticks(all_x); axs[0,0].legend()
    add_labels(axs[0,0], t_x, t_max, "{}", offset=(0, 6))       # Tree labels slightly above
    add_labels(axs[0,0], f_x_mapped, f_max, "{}", offset=(0, -14)) # Fused labels slightly below
    
    # 2. Avg ULP
    axs[0,1].plot(t_x, t_avg, marker='o', color='red', label='4-Input Tree')
    axs[0,1].plot(f_x_mapped, f_avg, marker='x', color='blue', label='32-Input Fused')
    axs[0,1].set_title('Average ULP Error'); axs[0,1].set_xlabel(x_label); axs[0,1].set_xticks(all_x); axs[0,1].legend()
    add_labels(axs[0,1], t_x, t_avg, "{:.6f}", offset=(0, 6))
    add_labels(axs[0,1], f_x_mapped, f_avg, "{:.6f}", offset=(0, -14))

    # 3. ULP > 1
    axs[1,0].plot(t_x, t_gt1, marker='o', color='red', label='4-Input Tree')
    axs[1,0].plot(f_x_mapped, f_gt1, marker='x', color='blue', label='32-Input Fused')
    axs[1,0].set_title('Total Cases ULP > 1'); axs[1,0].set_xlabel(x_label); axs[1,0].set_xticks(all_x); axs[1,0].legend()
    add_labels(axs[1,0], t_x, t_gt1, "{}", offset=(0, 6))
    add_labels(axs[1,0], f_x_mapped, f_gt1, "{}", offset=(0, -14))

    # 4. Pass Rate
    axs[1,1].plot(t_x, t_pass, marker='o', color='red', label='4-Input Tree')
    axs[1,1].plot(f_x_mapped, f_pass, marker='x', color='blue', label='32-Input Fused')
    axs[1,1].set_title('Pass Rate (%)'); axs[1,1].set_xlabel(x_label); axs[1,1].set_xticks(all_x); axs[1,1].legend()
    add_labels(axs[1,1], t_x, t_pass, "{:.4f}%", offset=(0, 6))
    add_labels(axs[1,1], f_x_mapped, f_pass, "{:.4f}%", offset=(0, -14))

    for ax in axs.flat: ax.margins(y=0.15)
    plt.tight_layout(); fig.subplots_adjust(top=0.90)
    plt.savefig(out_name, dpi=300)
    print(f"  -> Exported: {out_name}")
    plt.close(fig)

# --- Main Logic ---

for (arch, mode), dirs in groups.items():
    print(f"Processing '{arch}' architecture | Data Mode: {mode} ({len(dirs)} sets)")
    
    if arch == 'comparison':
        t_dirs = [os.path.join(d, "adder_tree") for d in dirs]
        f_dirs = [os.path.join(d, "fused_adder") for d in dirs]
        
        # Aggregate Data
        t_x, t_max, t_gt1, t_pass, t_avg = aggregate_data(t_dirs, "output_mantissa_{}.txt", range(23, 31))
        f_x, f_max, f_gt1, f_pass, f_avg = aggregate_data(f_dirs, "output_precision_{}.txt", range(0, 8))
        
        # Export Combined Graph
        plot_combined_architectures(
            t_x, t_max, t_gt1, t_pass, t_avg, 
            f_x, f_max, f_gt1, f_pass, f_avg, 
            f"Comparison ({mode}) - Tree vs Fused Architectures", 
            f"graph_comparison_combined_{mode}.png"
        )
        
        # Export Separated Graphs
        plot_single_architecture(t_x, t_max, t_gt1, t_pass, t_avg, f"Comparison ({mode}) - Tree Adder Only", "Mantissa Size", f"graph_comparison_tree_separated_{mode}.png", 'red')
        plot_single_architecture(f_x, f_max, f_gt1, f_pass, f_avg, f"Comparison ({mode}) - Fused Adder Only", "Precision Bits", f"graph_comparison_fused_separated_{mode}.png", 'blue')
        
    elif arch == 'tree':
        t_x, t_max, t_gt1, t_pass, t_avg = aggregate_data(dirs, "output_mantissa_{}.txt", range(23, 31))
        plot_single_architecture(t_x, t_max, t_gt1, t_pass, t_avg, f"Tree Adder Only ({mode})", "Mantissa Size", f"graph_tree_only_{mode}.png", 'red')
        
    elif arch == 'fused':
        f_x, f_max, f_gt1, f_pass, f_avg = aggregate_data(dirs, "output_precision_{}.txt", range(0, 8))
        plot_single_architecture(f_x, f_max, f_gt1, f_pass, f_avg, f"Fused Adder Only ({mode})", "Precision Bits", f"graph_fused_only_{mode}.png", 'blue')
        
    print()

print("All aggregation and graphing complete!")