#!/usr/bin/env python3
import matplotlib.pyplot as plt
from parse_qor import collect_data

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

if __name__ == '__main__':
    plot_area(collect_data('add_fp32_45nm'), 'add_fp32_45nm — Total Area vs Clock Speed', 'add_fp32_area.png')
    plot_area(collect_data('mul_bf_45nm'),   'mul_bf_45nm — Total Area vs Clock Speed',   'mul_bf_area.png')
