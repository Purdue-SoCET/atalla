import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

def get_wavefront_profile(active_M, active_N, active_K, total_capacity):
    wave_depth = active_M + active_N - 1
    total_cycles = active_K + wave_depth
    profile = []
    
    for t in range(total_cycles):
        active_count = 0
        for r in range(active_M):
            for c in range(active_N):
                start = r + c
                end = start + active_K
                if start <= t < end:
                    active_count += 1
        profile.append(active_count)
    return np.array(profile)

def analyze():
    try:
        df = pd.read_csv('conv_prog_model/utilization_over_time.csv')
    except FileNotFoundError:
        print("Error: csv not found.")
        return

    print("Generating Streamed Simulation...")
    
    # Estimate length based on K (Streamed)
    estimated_len = len(df) * 32 * 2 
    global_timeline = np.zeros(estimated_len)
    current_issue_cycle = 0
    
    for index, row in df.iterrows():
        M = int(row['Active_M'])
        N = int(row['Active_N'])
        K = int(row['Active_K'])
        
        wave = get_wavefront_profile(M, N, K, 1024)
        wave_len = len(wave)
        
        if current_issue_cycle + wave_len >= len(global_timeline):
            global_timeline = np.pad(global_timeline, (0, wave_len * 2))
            
        global_timeline[current_issue_cycle : current_issue_cycle + wave_len] += wave
        
        # CONTINUOUS STREAM: Issue immediately after K work is done
        current_issue_cycle += K 

    last_idx = np.max(np.nonzero(global_timeline))
    final_timeline = global_timeline[:last_idx+50]
    final_pct = (final_timeline / 1024.0) * 100.0
    
    # Calculate Average
    avg_util = np.mean(final_pct)

    # 1. Timeline Plot
    plt.figure(figsize=(15, 6))
    plt.plot(final_pct, label='Pipelined Utilization', linewidth=1.5)
    plt.axhline(y=avg_util, color='r', linestyle='--', label=f'Avg: {avg_util:.2f}%')
    plt.title('Systolic Array Utilization (Weight Stationary Streamed)')
    plt.xlabel('Hardware Cycles')
    plt.ylabel('Active PEs (%)')
    plt.legend()
    plt.grid(True, alpha=0.3)
    plt.savefig('conv_prog_model/utilization_pipelined.png')
    print(f"Saved timeline. Streamed Avg: {avg_util:.2f}%")

    # 2. Heatmap Plot
    try:
        heatmap_data = pd.read_csv('conv_prog_model/pe_heatmap.csv', header=None).values
        plt.figure(figsize=(10, 8))
        
        # Use Viridis. Zero values (unused PEs) will be dark purple.
        sns.heatmap(heatmap_data, cmap='viridis', annot=False)
        
        plt.title('Systolic Array Weight Storage Heatmap (Active Weights)\nRows=Depth (K), Cols=Channels (N)')
        plt.xlabel('Output Channel (N)')
        plt.ylabel('Weight Depth Index (K)')
        plt.savefig('conv_prog_model/pe_heatmap.png')
        print("Saved heatmap to pe_heatmap.png")
    except Exception as e:
        print(e)

if __name__ == "__main__":
    analyze()