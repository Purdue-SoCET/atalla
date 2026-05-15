import pandas as pd
import torch
import struct
import numpy as np
import matplotlib.pyplot as plt

def bf16_to_scientific(hex_str):
    """
    Converts a BF16 hex string to a human-readable 2^exp * mantissa format.
    Handles normalized numbers and true zero.
    """
    try:
        val = int(hex_str, 16)
    except ValueError:
        return "Invalid Hex"

    # BF16 Format: 1 sign bit, 8 exponent bits, 7 mantissa bits
    sign = (val >> 15) & 0x01
    exp_bits = (val >> 7) & 0xFF
    mant_bits = val & 0x7F

    # Handle Special Case: Zero
    if exp_bits == 0 and mant_bits == 0:
        return "0"

    # Handle Special Case: Infinity/NaN
    if exp_bits == 0xFF:
        if mant_bits == 0:
            return "-Inf" if sign else "+Inf"
        return "NaN"

    # Normalized Number Calculation
    # True Exponent = E - Bias (127)
    true_exp = exp_bits - 127
    
    # Mantissa = 1 + (fractional_bits / 2^7)
    mantissa = 1 + (mant_bits / 128.0)

    sign_str = "-" if sign else ""
    
    # Format to clean up trailing zeros for readability
    return f"{sign_str}({true_exp}|{hex_str})"

def bf16_hex_to_float(hex_val):
    if pd.isna(hex_val): return np.nan
    try:
        val = int(str(hex_val), 16)
        return struct.unpack('>f', (val << 16).to_bytes(4, 'big'))[0]
    except: return np.nan

def get_exp(hex_val):
    try: return (int(str(hex_val), 16) >> 7) & 0xFF
    except: return 0

def get_ulp_dist(hex_hw, hex_ref):
    try:
        hw_int, ref_int = int(str(hex_hw), 16), int(str(hex_ref), 16)
        def to_linear(v):
            sign, mag = (v >> 15) & 0x1, v & 0x7FFF
            return (0x8000 - mag) if sign else (0x8000 + mag)
        return abs(to_linear(hw_int) - to_linear(ref_int))
    except: return np.nan

def analyze_hardware_results(file_path):
    df = pd.read_csv(file_path, skipinitialspace=True)
    df.columns = df.columns.str.strip()

    # Hardware Constraint: Your internal datapath width [cite: 2, 13]
    RTL_WINDOW = 27 

    # 1. Full Data Conversion
    for col in ['A', 'B', 'C', 'D', 'Expected', 'Result']:
        df[f'{col}_f'] = df[col].apply(bf16_hex_to_float)
        if col in ['A', 'B', 'C', 'D']:
            df[f'{col}_e'] = df[col].apply(get_exp)
            df[f'{col}_s'] = df[col].apply(lambda x: (int(str(x), 16) >> 15) & 0x1 if not pd.isna(x) else 0)

    # 2. Advanced Input Analysis
    def analyze_inputs(row):
        exps = [row['A_e'], row['B_e'], row['C_e'], row['D_e']]
        max_e = max(exps)
        
        # Count operands lost in the shifter [cite: 54, 55]
        shifted_out = sum(1 for e in exps if (max_e - e) >= RTL_WINDOW)
        
        # Detect Massive Cancellation: Max magnitude vs final result [cite: 592, 593]
        max_in_mag = max(abs(row['A_f']), abs(row['B_f']), abs(row['C_f']), abs(row['D_f']))
        cancellation = (abs(row['Expected_f']) < (max_in_mag * 0.01)) if max_in_mag > 0 else False
        
        # Sign Mismatch Check (Logic 185) [cite: 80, 83, 104]
        # Check if the hardware result sign bit matches the expected sign bit
        hw_s = (int(str(row['Result']), 16) >> 15) & 0x1 if not pd.isna(row['Result']) else 0
        ref_s = (int(str(row['Expected']), 16) >> 15) & 0x1 if not pd.isna(row['Expected']) else 0
        sign_mismatch = (hw_s != ref_s)
        
        return pd.Series([max_e, shifted_out, cancellation, sign_mismatch], 
                         index=['Max_Exp', 'Shifted_Out_Count', 'Massive_Cancellation', 'Sign_Mismatch'])

    df[['Max_Exp', 'Shifted_Out_Count', 'Massive_Cancellation', 'Sign_Mismatch']] = df.apply(analyze_inputs, axis=1)

    # 3. Compliance and ULP Metrics
    RTOL, ATOL = 1.6e-02, 1e-05
    df['ULP_Dist'] = df.apply(lambda r: get_ulp_dist(r['Result'], r['Expected']), axis=1)
    df['Observed_Diff'] = (df['Result_f'] - df['Expected_f']).abs()
    df['Rel_Err'] = (df['Observed_Diff'] / (df['Expected_f'].abs() + 1e-12))

    # NaN/Inf Matching (Strict Compliance)
    is_nan_match = df['Result_f'].isna() & df['Expected_f'].isna()
    is_inf_match = np.isinf(df['Result_f']) & np.isinf(df['Expected_f']) & (np.sign(df['Result_f']) == np.sign(df['Expected_f']))
    df['Failed'] = ~(is_nan_match | is_inf_match) & (df['Observed_Diff'] > (ATOL + RTOL * df['Expected_f'].abs()))

    # 4. Granular Hardware Bug Classification
    def classify_failure(row):
        if not row['Failed']: return "PASS"
        if row['Sign_Mismatch'] and row['ULP_Dist'] < 100: return "Sign Bit Logic (Stage 2/3)"
        if row['Massive_Cancellation'] and row['Shifted_Out_Count'] > 0: return "Precision Oblivion (Aligner Shift)"
        if row['Result'] == '0000' and row['Expected'] != '0000': return "Zero Clamping Trap (Stage 3)"
        if row['ULP_Dist'] > 1000: return "Exponent/LZD Misalignment"
        return "Rounding/Sticky Bit Drift"

    df['Failure_Mode'] = df.apply(classify_failure, axis=1)

    # --- PRINT EXTENDED REPORT ---
    print(f"\n=======================================================")
    print(f"       RTL DEEP-DIVE DIAGNOSTIC REPORT")
    print(f"=======================================================")
    print(f"Total Cases:     {len(df)}")
    print(f"Compliance:      {(1 - df['Failed'].mean())*100:.3f}%")
    print(f"Max ULP Dist:    {df['ULP_Dist'].max():.0f}")
    print(f"Max Rel Error:   {df['Rel_Err'].max():.4%}")
    
    print("\n--- Failure Breakdown by Hardware Block ---")
    if df['Failed'].any():
        print(df[df['Failed']]['Failure_Mode'].value_counts())
    else:
        print("No compliance failures detected.")

    print("\n--- Top 10 Worst-Case Failures ---")
    hex_cols = ['A', 'B', 'C', 'D', 'Result', 'Expected']
    df_readable = df.copy()
    df_readable[hex_cols] = df[hex_cols].applymap(bf16_to_scientific)
    worst = df_readable[df_readable['Failed']].sort_values(by='ULP_Dist', ascending=False).head(10)
    print(worst[['CaseName', 'A', 'B', 'C', 'D', 'Result', 'Expected', 'ULP_Dist', 'Rel_Err']])

    # --- ERROR SCATTER PLOT ---
    plt.figure(figsize=(10, 6))
    plt.scatter(df['Expected_f'], df['Rel_Err'], c=df['Failed'], cmap='coolwarm', alpha=0.5)
    plt.axhline(y=RTOL, color='r', linestyle='--', label='PyTorch RTOL (1.6e-2)')
    plt.yscale('log')
    plt.xlabel('Expected Magnitude')
    plt.ylabel('Relative Error (Log Scale)')
    plt.title('Adder Accuracy across Dynamic Range')
    plt.grid(True, which="both", ls="-", alpha=0.2)
    plt.show()

    return df

if __name__ == "__main__":
    df_results = analyze_hardware_results("/Users/aryankarani/Documents/GitHub/atalla/tree_failures.csv")