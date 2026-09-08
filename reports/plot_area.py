#!/usr/bin/env python3
import matplotlib.pyplot as plt
from parse_qor import collect_data
from parse_qor import write_table

UM2_TO_MM2 = 1e-6

def plot_area(rows, title, filename):
    freqs = [r[0] for r in rows]
    areas = [float(r[1]['total_area']) * UM2_TO_MM2 for r in rows]

    fig, ax = plt.subplots(figsize=(10, 5))
    ax.plot(freqs, areas, 'o-', color='tab:blue', markersize=5)
    ax.set_xlabel('Clock Speed (MHz)')
    ax.set_ylabel('Total Area (mm²)')
    ax.set_title(title)
    ax.grid(True, alpha=0.3)
    fig.tight_layout()
    fig.savefig(filename, dpi=150)
    plt.close(fig)
    print(f'Saved {filename}')

def plot_power(rows, title, filename):
    freqs = [r[0] for r in rows]
    powers = [float(r[1]['total_power']) for r in rows]

    fig, ax = plt.subplots(figsize=(10, 5))
    ax.plot(freqs, powers, 'o-', color='tab:orange', markersize=5)
    ax.set_xlabel('Clock Speed (MHz)')
    ax.set_ylabel('Total Power (nW)')
    ax.set_title(title)
    ax.grid(True, alpha=0.3)
    fig.tight_layout()
    fig.savefig(filename, dpi=150)
    plt.close(fig)
    print(f'Saved {filename}')

if __name__ == '__main__':
    data = collect_data('/home/asicfab/a/karania/atalla/reports/sysarr_32_input_fp_adder_best_shmoo/sysarr_32_TOP_path_16_2_addCfg_1_alignTree_00010_alignReg_1')
    plot_area(data, 'sysarr_32_input_fp_adder_best — Total Area vs Clock Speed', 'sysarr_32_input_fp_adder_best_area.png')
    plot_power(data, 'sysarr_32_input_fp_adder_best — Total Power vs Clock Speed', 'sysarr_32_input_fp_adder_best_power.png')
    with open('qor_summary_sysarr_32_input_fp_adder_best.md', 'w') as f:
        f.write('# QoR Summary\n\n')
        write_table(f, 'sysarr_32_input_fp_adder_best', data)