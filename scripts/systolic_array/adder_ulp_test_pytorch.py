import pandas as pd
import struct
import numpy as np
import matplotlib.pyplot as plt
import torch # Natively integrated PyTorch


# =============================================================================
# BF16 UTILITY FUNCTIONS
# =============================================================================

def bf16_to_scientific(hex_str):
    """
    Converts a BF16 hex string to a human-readable (exp|hex) format.
    Handles normalized numbers, zero, infinity, and NaN.
    """
    try:
        val = int(str(hex_str), 16)
    except (ValueError, TypeError):
        return "Invalid Hex"

    sign      = (val >> 15) & 0x01
    exp_bits  = (val >> 7)  & 0xFF
    mant_bits = val & 0x7F

    if exp_bits == 0 and mant_bits == 0:
        return "-0" if sign else "0"
    if exp_bits == 0xFF:
        if mant_bits == 0:
            return "-Inf" if sign else "+Inf"
        return "NaN"

    true_exp = exp_bits - 127
    sign_str = "-" if sign else ""
    return f"{sign_str}({true_exp}|{hex_str})"


def bf16_hex_to_float(hex_val):
    if pd.isna(hex_val):
        return np.nan
    try:
        val = int(str(hex_val), 16)
        return struct.unpack('>f', (val << 16).to_bytes(4, 'big'))[0]
    except Exception:
        return np.nan


def get_exp(hex_val):
    try:
        return (int(str(hex_val), 16) >> 7) & 0xFF
    except Exception:
        return 0


def get_ulp_dist(hex_hw, hex_ref, is_cc_failure=False):
    """
    Compute ULP distance in BF16 sign-magnitude space.
    Returns NaN for CC-path corruption cases where the distance is meaningless.
    """
    if is_cc_failure:
        return np.nan
    try:
        hw_int  = int(str(hex_hw),  16)
        ref_int = int(str(hex_ref), 16)

        def to_linear(v):
            sign = (v >> 15) & 0x1
            mag  = v & 0x7FFF
            return (0x8000 - mag) if sign else (0x8000 + mag)

        return abs(to_linear(hw_int) - to_linear(ref_int))
    except Exception:
        return np.nan


# =============================================================================
# MAIN ANALYSIS FUNCTION
# =============================================================================

def analyze_hardware_results(file_path):
    df = pd.read_csv(file_path, skipinitialspace=True)
    df.columns = df.columns.str.strip()

    # Internal datapath width (aligner window)
    RTL_WINDOW = 27

    # CONFIGURATION FOR ML VERIFICATION
    # True: Catches vanishing numbers (100% relative error drops) by forcing strict relative checks.
    # False: Uses default PyTorch compliance rules (allows absolute errors up to 1e-5).
    STRICT_ML_MODE = True 

    # -------------------------------------------------------------------------
    # 1. Full Data Conversion
    # -------------------------------------------------------------------------
    for col in ['A', 'B', 'C', 'D', 'Expected', 'Result']:
        df[f'{col}_f'] = df[col].apply(bf16_hex_to_float)
        if col in ['A', 'B', 'C', 'D']:
            df[f'{col}_e'] = df[col].apply(get_exp)
            df[f'{col}_s'] = df[col].apply(
                lambda x: (int(str(x), 16) >> 15) & 0x1
                if not pd.isna(x) else 0
            )

    # -------------------------------------------------------------------------
    # 2. AdderGot rounding pattern analysis
    # -------------------------------------------------------------------------
    if 'AdderGot' in df.columns:
        df['AdderGot_lower'] = df['AdderGot'].apply(
            lambda x: int(str(x), 16) & 0xFFFF if pd.notna(x) else np.nan
        )
        df['Is_Halfway']     = df['AdderGot_lower'] == 0x8000
        df['Is_Above_Half']  = df['AdderGot_lower'] >  0x8000
    else:
        df['AdderGot_lower'] = np.nan
        df['Is_Halfway']     = False
        df['Is_Above_Half']  = False

    # -------------------------------------------------------------------------
    # 3. Advanced Input Analysis
    # -------------------------------------------------------------------------
    def analyze_inputs(row):
        exps  = [row['A_e'], row['B_e'], row['C_e'], row['D_e']]
        max_e = max(exps)

        # Operands completely lost in the aligner shifter
        shifted_out = sum(1 for e in exps if (max_e - e) >= RTL_WINDOW)

        # Massive cancellation: output magnitude << largest input magnitude
        max_in_mag   = max(abs(row['A_f']), abs(row['B_f']),
                           abs(row['C_f']), abs(row['D_f']))
        cancellation = (
            abs(row['Expected_f']) < (max_in_mag * 0.01)
        ) if max_in_mag > 0 else False

        # Sign mismatch between hardware result and reference
        hw_s  = (int(str(row['Result']),   16) >> 15) & 0x1 \
                if not pd.isna(row['Result'])   else 0
        ref_s = (int(str(row['Expected']), 16) >> 15) & 0x1 \
                if not pd.isna(row['Expected']) else 0
        sign_mismatch = (hw_s != ref_s)

        return pd.Series(
            [max_e, shifted_out, cancellation, sign_mismatch],
            index=['Max_Exp', 'Shifted_Out_Count',
                   'Massive_Cancellation', 'Sign_Mismatch']
        )

    df[['Max_Exp', 'Shifted_Out_Count',
        'Massive_Cancellation', 'Sign_Mismatch']] = df.apply(analyze_inputs, axis=1)

    # -------------------------------------------------------------------------
    # 4. Compliance and ULP Metrics (NATIVE PYTORCH TRANSLATION)
    # -------------------------------------------------------------------------
    # PyTorch native default tolerances for bfloat16
    RTOL = 1.6e-02
    ATOL = 1e-15 if STRICT_ML_MODE else 1e-05

    # Prepare PyTorch Tensors for mathematical compliance evaluation
    res_np = df['Result_f'].fillna(float('nan')).values
    exp_np = df['Expected_f'].fillna(float('nan')).values

    res_tensor = torch.tensor(res_np, dtype=torch.float32).to(torch.bfloat16)
    exp_tensor = torch.tensor(exp_np, dtype=torch.float32).to(torch.bfloat16)

    # Execute torch.isclose element-wise logic natively
    torch_close = torch.isclose(res_tensor, exp_tensor, rtol=RTOL, atol=ATOL, equal_nan=True)
    df['Torch_Close'] = torch_close.numpy()

    # Re-map original formatting classes
    is_nan_match = df['Result_f'].isna()  & df['Expected_f'].isna()
    is_inf_match = (
        np.isinf(df['Result_f'])   &
        np.isinf(df['Expected_f']) &
        (np.sign(df['Result_f']) == np.sign(df['Expected_f']))
    )

    df['Near_Zero_Expected'] = df['Expected_f'] == 0.0

    df['CC_Failure'] = (
        df['Near_Zero_Expected'] &
        (df['Result_f'] != 0.0) &
        ~is_nan_match &
        ~is_inf_match
    )

    # Relative error tracking
    df['Rel_Err'] = np.where(
        df['Near_Zero_Expected'],
        np.nan,
        (df['Result_f'] - df['Expected_f']).abs() /
        df['Expected_f'].abs().clip(lower=1e-37)
    )
    df['Rel_Err'] = df['Rel_Err'].clip(lower=0)

    df['Observed_Diff'] = (df['Result_f'] - df['Expected_f']).abs()
    
    # Normalized error boundaries based on the assigned torch layout
    df['Norm_Err'] = df['Observed_Diff'] / (ATOL + RTOL * df['Expected_f'].abs())

    # PyTorch compliance assessment override
    df['Failed'] = df['CC_Failure'] | (~df['Torch_Close'])

    df['ULP_Dist'] = df.apply(
        lambda r: get_ulp_dist(r['Result'], r['Expected'],
                               is_cc_failure=bool(r['CC_Failure'])), axis=1
    )

    # -------------------------------------------------------------------------
    # 5. Granular Hardware Bug Classification
    # -------------------------------------------------------------------------
    def classify_failure(row):
        if not row['Failed']:
            return "PASS"

        if row['CC_Failure']:
            return "CC Path Corruption (Exponent Wraparound)"

        if row['Sign_Mismatch'] and row['ULP_Dist'] >= 0x8000:
            return "Sign Bit Logic (Stage 2/3)"

        if row['Massive_Cancellation'] and row['Shifted_Out_Count'] > 0:
            return "Precision Oblivion (Aligner Shift)"

        if (str(row['Result']) == '0000' or str(row['Result']) == '0') and str(row['Expected']) != '0000':
            return "Zero Clamping Trap (Stage 3)"

        if pd.notna(row['ULP_Dist']) and row['ULP_Dist'] > 1000:
            return "Exponent/LZD Misalignment"

        if row.get('Is_Halfway', False):
            return "Rounding/Sticky Bit Drift (Exact Halfway — RNE Failure)"

        return "Rounding/Sticky Bit Drift"

    df['Failure_Mode'] = df.apply(classify_failure, axis=1)

    # -------------------------------------------------------------------------
    # 6. Extended Report Output
    # -------------------------------------------------------------------------
    n_failed = df['Failed'].sum()
    n_cc     = df['CC_Failure'].sum()

    print(f"\n=======================================================")
    print(f"       RTL DEEP-DIVE DIAGNOSTIC REPORT (PYTORCH ENGINE)")
    print(f"=======================================================")
    print(f"Total Cases:          {len(df)}")
    print(f"Compliance:           {(1 - df['Failed'].mean()) * 100:.3f}%")
    print(f"Total Failures:       {n_failed}")
    print(f"  CC Path Corruptions:{n_cc}  (ULP stat excluded — wrong number class)")
    print(f"Max ULP Dist:         {df['ULP_Dist'].max():.0f}  (NaN = CC failures excluded)")
    print(f"Max Rel Error:        {df['Rel_Err'].max():.4%}  (NaN = near-zero expected excluded)")

    print("\n--- Failure Breakdown by Hardware Block ---")
    if df['Failed'].any():
        print(df[df['Failed']]['Failure_Mode'].value_counts().to_string())
    else:
        print("No compliance failures detected under current PyTorch configuration.")

    print(f"\n--- Near-Zero Expected Cases (excluded from Rel_Err) ---")
    print(f"Count: {df['Near_Zero_Expected'].sum()}  (of which {n_cc} are CC path corruptions)")

    if 'AdderGot' in df.columns:
        print(f"\n--- Rounding Pattern (from AdderGot lower 16 bits) ---")
        print(f"Exact halfway (0x8000):        {df['Is_Halfway'].sum()}")
        print(f"Above halfway (>0x8000):       {df['Is_Above_Half'].sum()}")
        print(f"Halfway + Failed:              "
              f"{(df['Is_Halfway'] & df['Failed']).sum()}")
        print(f"Above-half + Failed:           "
              f"{(df['Is_Above_Half'] & df['Failed']).sum()}")

    print("\n--- Top 10 Worst-Case Failures (by ULP, CC excluded) ---")
    hex_cols    = ['A', 'B', 'C', 'D', 'Result', 'Expected']
    df_readable = df.copy()
    df_readable[hex_cols] = df[hex_cols].map(bf16_to_scientific)
    worst = (
        df_readable[df_readable['Failed']]
        .sort_values(by='ULP_Dist', ascending=False)
        .head(10)
    )
    if len(worst):
        print(worst[['CaseName', 'A', 'B', 'C', 'D',
                     'Result', 'Expected', 'ULP_Dist', 'Rel_Err',
                     'Failure_Mode']].to_string())
    else:
        print("Empty DataFrame")

    print("\n--- CC Path Corruption Cases ---")
    cc_cases = df_readable[df_readable['CC_Failure']]
    if len(cc_cases):
        print(cc_cases[['CaseName', 'A', 'B', 'C', 'D',
                         'Result', 'Expected',
                         'Massive_Cancellation']].to_string())
    else:
        print("None.")

    print("\n--- Top 5 Highest Relative Error Cases ---")
    top_rel = df_readable[~df_readable['Near_Zero_Expected']].nlargest(5, 'Rel_Err')
    print(top_rel[['CaseName', 'A', 'B', 'C', 'D',
                   'Result', 'Expected', 'ULP_Dist', 'Rel_Err',
                   'Massive_Cancellation', 'Shifted_Out_Count',
                   'Is_Halfway']].to_string())

    print("\n--- Coverage Gaps ---")
    print(f"Subnormal inputs:      "
          f"{((df['A_e']==0)|(df['B_e']==0)|(df['C_e']==0)|(df['D_e']==0)).sum()}")
    print(f"Max exponent spread:   "
          f"{(df['Max_Exp'] - df[['A_e','B_e','C_e','D_e']].min(axis=1)).max()}")
    print(f"All-shifted-out cases: {(df['Shifted_Out_Count'] == 3).sum()}")
    print(f"Mixed-sign inputs:     "
          f"{((df['A_s']+df['B_s']+df['C_s']+df['D_s']).between(1,3)).sum()}")

    # -------------------------------------------------------------------------
    # 7. Error Scatter Plot
    # -------------------------------------------------------------------------
    plot_df = df[~df['Near_Zero_Expected'] & df['Rel_Err'].notna()].copy().reset_index(drop=True)
    cc_plot_df = df[df['CC_Failure']].copy()

    fig, ax = plt.subplots(figsize=(11, 6))

    scatter = ax.scatter(
        plot_df['Expected_f'].values,
        plot_df['Rel_Err'].values,
        c=plot_df['Failed'].astype(int).values,
        cmap='coolwarm',
        vmin=0, vmax=1,
        alpha=0.6, s=18,
        label='Calculated Points' # FIXED: Label added to clear UserWarning
    )

    if len(cc_plot_df):
        ax.scatter(
            [0] * len(cc_plot_df),     
            [1.0] * len(cc_plot_df),  
            marker='X', color='darkorange', s=80, zorder=5,
            label=f'CC Path Corruption ({len(cc_plot_df)} cases)'
        )
        for _, r in cc_plot_df.iterrows():
            ax.annotate(
                f"Got {r['Result']}",
                xy=(0, 1.0),
                xytext=(8, 4), textcoords='offset points',
                fontsize=7, color='darkorange'
            )

    ax.set_yscale('log')
    ax.set_ylim(bottom=1e-5) 
    ax.set_xlabel('Expected Magnitude')
    ax.set_ylabel('Relative Error (Log Scale)')
    ax.set_title('BF16 Adder Accuracy across Dynamic Range\n'
                 '(PyTorch Validation Mode)')
    ax.legend(fontsize=8)
    ax.grid(True, which="both", ls="-", alpha=0.2)
    plt.colorbar(scatter, ax=ax, label='Failed (1=red, 0=blue)')
    plt.tight_layout()
    plt.show()

    return df


# =============================================================================
if __name__ == "__main__":
    df_results = analyze_hardware_results(
        "/Users/aryankarani/Documents/GitHub/atalla/tree_failures.csv"
    )