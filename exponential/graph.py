import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os

# --- TOGGLE SETTINGS ---
EXCLUDE_NANS_STATS = True  # Set to False to include NaNs in the avg/worst calculation
# -----------------------

def plot_ulp_errors(csv_path, output_plot, title_prefix):
    if not os.path.exists(csv_path):
        print(f"Error: {csv_path} not found. Please run the sweep script first.")
        return

    print(f"Loading {csv_path}...")
    df = pd.read_csv(csv_path)

    # 1. Pre-processing for numeric conversion
    # Ensure Input_Float and ULP_Error are numeric
    df['Input_Float_Num'] = pd.to_numeric(df['Input_Float'], errors='coerce')
    df['ULP_Error'] = pd.to_numeric(df['ULP_Error'], errors='coerce')

    # 2. Calculate Statistics based on toggle
    if EXCLUDE_NANS_STATS:
        # A value is NaN if the Input_Float conversion resulted in NaN
        # (This covers strings like 'nan' in the CSV)
        stats_df = df.dropna(subset=['Input_Float_Num'])
        label_suffix = "(Excl. NaNs)"
    else:
        stats_df = df
        label_suffix = "(Incl. NaNs)"

    avg_ulp = stats_df['ULP_Error'].mean()
    max_ulp = stats_df['ULP_Error'].max()

    # 3. Filter data for the actual plot 
    # (Matplotlib cannot plot infinite or NaN coordinates)
    plot_data = df.dropna(subset=['Input_Float_Num', 'ULP_Error'])
    plot_data = plot_data[np.isfinite(plot_data['Input_Float_Num'])]

    # 4. Create the plot
    fig, ax = plt.subplots(figsize=(12, 7))
    
    ax.scatter(plot_data['Input_Float_Num'], plot_data['ULP_Error'], 
                alpha=0.5, s=1, color='blue', label='ULP Error')

    # 5. Formatting Axes
    # Use symmetric log scale to handle BF16 range ($10^{-41}$ to $10^{40}$)
    ax.set_xscale('symlog', linthresh=1e-1) 
    
    # Rotate labels to prevent overlap
    plt.xticks(rotation=45, ha='right')
    
    ax.set_title(f'{title_prefix} BF16 Exponential Unit: ULP Error vs Input Value', fontsize=14, pad=20)
    ax.set_xlabel('Input Value (BF16)', fontsize=12)
    ax.set_ylabel('ULP Error (Bit Distance)', fontsize=12)
    ax.grid(True, which="both", ls="-", alpha=0.2)
    ax.axvline(0, color='black', lw=1)

    # 6. Add Text Box with Stats
    stats_text = (f"Average ULP: {avg_ulp:.4f}\n"
                  f"Worst ULP: {max_ulp}\n"
                  f"NaNs: {label_suffix}")
    
    props = dict(boxstyle='round', facecolor='white', alpha=0.8, edgecolor='gray')
    ax.text(0.02, 0.95, stats_text, transform=ax.transAxes, fontsize=11,
            verticalalignment='top', bbox=props)

    # 7. Final Layout Adjustment
    plt.tight_layout()
    
    plt.savefig(output_plot, dpi=300)
    print(f"Plot saved successfully to {output_plot}")

def plot_combined_table_driven(csv_paths, output_plot):
    fig, ax = plt.subplots(figsize=(12, 7))
    
    # Use a color map for distinct colors
    colors = plt.cm.tab10(np.linspace(0, 1, max(10, len(csv_paths))))

    for i, csv_path in enumerate(csv_paths):
        if not os.path.exists(csv_path):
            print(f"Warning: {csv_path} not found. Skipping.")
            continue

        print(f"Loading {csv_path} for combined plot...")
        df = pd.read_csv(csv_path)
        df['Input_Float_Num'] = pd.to_numeric(df['Input_Float'], errors='coerce')
        df['ULP_Error'] = pd.to_numeric(df['ULP_Error'], errors='coerce')

        plot_data = df.dropna(subset=['Input_Float_Num', 'ULP_Error'])
        plot_data = plot_data[np.isfinite(plot_data['Input_Float_Num'])]

        # Extract bit size for label if possible
        import re
        match = re.search(r'(\d+)bits', csv_path)
        bit_label = f"LUT ({match.group(1)} bits)" if match else csv_path
        
        ax.scatter(plot_data['Input_Float_Num'], plot_data['ULP_Error'], 
                    alpha=0.4, s=1, color=colors[i % 10], label=bit_label)

    ax.set_xscale('symlog', linthresh=1e-1) 
    plt.xticks(rotation=45, ha='right')
    
    ax.set_title('LUT (4-8 bits) BF16 Exponential Unit: ULP Error vs Input Value', fontsize=14, pad=20)
    ax.set_xlabel('Input Value (BF16)', fontsize=12)
    ax.set_ylabel('ULP Error (Bit Distance)', fontsize=12)
    ax.grid(True, which="both", ls="-", alpha=0.3)
    ax.axvline(0, color='black', lw=1)
    
    # Increase marker size in legend for visibility
    ax.legend(markerscale=10, loc='upper right')
    
    plt.tight_layout()
    plt.savefig(output_plot, dpi=300)
    print(f"Combined plot saved successfully to {output_plot}")

if __name__ == "__main__":
    # plot_ulp_errors("pytorch_sweep_results.csv", "pytorch_ulp_error_plot.png", "PyTorch")
    # plot_ulp_errors("bitwise_sweep_results.csv", "bitwise_ulp_error_plot.png", "expp")
    # for i in range(22):
    #     plot_ulp_errors(f"table_driven_sweep_{i}bits.csv", f"table_driven_{i}bits_ulp_error_plot.png", f"LUT ({i} bits)")
    plot_combined_table_driven([f"table_driven_sweep_{k}bits.csv" for k in range(4, 9)], "table_driven_combined_4_8bits.png")