"""
Sweep layer parameters and plot PE utilization (K-rows / C_out-cols mapping).
Generates graphs: util vs C_out, C_in, N, kernel size, ifmap size.
Run: python sweep_utilization.py
"""
import numpy as np
import matplotlib.pyplot as plt
from im2col import SimConfig, utilization_k_rows_n_cols

SZ = 32  # array size


def sweep_cout(base_n=1, base_h=56, base_w=56, base_c=64, base_r=3, base_s=3):
    """Util vs C_out (K)."""
    k_vals = [2, 4, 8, 16, 32, 64, 96, 128, 256]
    utils = []
    for k in k_vals:
        cfg = SimConfig(N=base_n, H=base_h, W=base_w, C=base_c, K=k, R=base_r, S=base_s, stride=1, pad=0)
        u, _, _ = utilization_k_rows_n_cols(cfg)
        utils.append(u)
    return k_vals, utils


def sweep_cin(base_n=1, base_h=56, base_w=56, base_k=64, base_r=3, base_s=3):
    """Util vs C_in (C). K_flat = R*S*C so affects row tiling."""
    c_vals = [4, 8, 16, 32, 64, 128, 256]
    utils = []
    for c in c_vals:
        cfg = SimConfig(N=base_n, H=base_h, W=base_w, C=c, K=base_k, R=base_r, S=base_s, stride=1, pad=0)
        u, _, _ = utilization_k_rows_n_cols(cfg)
        utils.append(u)
    return c_vals, utils


def sweep_n(base_h=56, base_w=56, base_c=64, base_k=64, base_r=3, base_s=3):
    """Util vs batch N. For k_rows_n_cols, util is independent of N (M cancels)."""
    n_vals = [1, 2, 4, 8, 16, 32, 64]
    utils = []
    for n in n_vals:
        cfg = SimConfig(N=n, H=base_h, W=base_w, C=base_c, K=base_k, R=base_r, S=base_s, stride=1, pad=0)
        u, _, _ = utilization_k_rows_n_cols(cfg)
        utils.append(u)
    return n_vals, utils


def sweep_kernel_size_two_configs(base_n=1, base_h=56, base_w=56):
    """Util vs kernel size for (C=64, K=64) and (C=2, K=2). K_flat = R*S*C."""
    rs_vals = [(1, 1), (3, 3), (5, 5), (7, 7)]
    labels = ["1×1", "3×3", "5×5", "7×7"]
    utils_64, utils_2 = [], []
    for (r, s) in rs_vals:
        cfg64 = SimConfig(N=base_n, H=base_h, W=base_w, C=64, K=64, R=r, S=s, stride=1, pad=0)
        cfg2 = SimConfig(N=base_n, H=base_h, W=base_w, C=2, K=2, R=r, S=s, stride=1, pad=0)
        u64, _, _ = utilization_k_rows_n_cols(cfg64)
        u2, _, _ = utilization_k_rows_n_cols(cfg2)
        utils_64.append(u64 * 100)
        utils_2.append(u2 * 100)
    return labels, utils_64, utils_2


def sweep_ifmap_size(base_n=1, base_c=64, base_k=64, base_r=3, base_s=3):
    """Util vs ifmap H=W. For k_rows_n_cols, util is independent of H,W (M cancels)."""
    hw_vals = [7, 14, 28, 56, 112, 224]
    utils = []
    for h in hw_vals:
        cfg = SimConfig(N=base_n, H=h, W=h, C=base_c, K=base_k, R=base_r, S=base_s, stride=1, pad=0)
        u, _, _ = utilization_k_rows_n_cols(cfg)
        utils.append(u)
    return hw_vals, utils


def main():
    fig, axes = plt.subplots(2, 3, figsize=(12, 8))
    ymax = 105  # cap just above 100 so 100% points are visible

    # Util vs C_out
    ax = axes[0, 0]
    x, u = sweep_cout()
    ax.plot(x, [v * 100 for v in u], "o-", color="green")
    ax.set_xlabel("C_out (K)")
    ax.set_ylabel("Utilization (%)")
    ax.set_title("Util vs C_out (fixed C=64, 3×3)")
    ax.set_ylim(0, ymax)
    ax.axhline(y=100, color="gray", linestyle="--", alpha=0.5)
    ax.grid(True, alpha=0.3)

    # Util vs C_in
    ax = axes[0, 1]
    x, u = sweep_cin()
    ax.plot(x, [v * 100 for v in u], "o-", color="green")
    ax.set_xlabel("C_in (C)")
    ax.set_ylabel("Utilization (%)")
    ax.set_title("Util vs C_in (fixed K=64, 3×3)")
    ax.set_ylim(0, ymax)
    ax.grid(True, alpha=0.3)

    # Util vs N — flat because util = (sum k_tile*n_tile) / (num_tiles*sz²); M cancels
    ax = axes[0, 2]
    x, u = sweep_n()
    util_n = u[0] * 100
    ax.plot(x, [v * 100 for v in u], "o-", color="green")
    ax.set_xlabel("Batch size (N)")
    ax.set_ylabel("Utilization (%)")
    ax.set_title(f"Util vs N (flat at {util_n:.1f}% — M cancels)")
    ax.set_ylim(0, ymax)
    ax.axhline(y=100, color="gray", linestyle="--", alpha=0.5)
    ax.grid(True, alpha=0.3)

    # Util vs kernel size — two configs: C=K=64 (often 100%) vs C=K=2 (K_flat varies)
    ax = axes[1, 0]
    labels, u64, u2 = sweep_kernel_size_two_configs()
    x = np.arange(len(labels))
    w = 0.35
    ax.bar(x - w / 2, u64, w, label="C=64, K=64", color="green", alpha=0.8, edgecolor="black")
    ax.bar(x + w / 2, u2, w, label="C=2, K=2", color="gold", edgecolor="black")
    ax.set_xticks(x)
    ax.set_xticklabels(labels)
    ax.set_xlabel("Kernel R×S")
    ax.set_ylabel("Utilization (%)")
    ax.set_title("Util vs kernel size (H=W=56)")
    ax.set_ylim(0, ymax)
    ax.axhline(y=100, color="gray", linestyle="--", alpha=0.5)
    ax.legend(fontsize=8)
    ax.grid(True, alpha=0.3, axis="y")

    # Util vs ifmap size — flat; util determined by K_flat and C_out only
    ax = axes[1, 1]
    x, u = sweep_ifmap_size()
    util_hw = u[0] * 100
    ax.plot(x, [v * 100 for v in u], "o-", color="green")
    ax.set_xlabel("IFMap H=W")
    ax.set_ylabel("Utilization (%)")
    ax.set_title(f"Util vs IFMap size (flat at {util_hw:.1f}% — M cancels)")
    ax.set_ylim(0, ymax)
    ax.axhline(y=100, color="gray", linestyle="--", alpha=0.5)
    ax.grid(True, alpha=0.3)

    # 2D: C_in × C_out (heatmap); state fixed params
    ax = axes[1, 2]
    c_in_vals = [16, 32, 64, 128, 256]
    c_out_vals = [16, 32, 64, 128, 256]
    grid = np.zeros((len(c_in_vals), len(c_out_vals)))
    for i, c in enumerate(c_in_vals):
        for j, k in enumerate(c_out_vals):
            cfg = SimConfig(N=1, H=56, W=56, C=c, K=k, R=3, S=3, stride=1, pad=0)
            u, _, _ = utilization_k_rows_n_cols(cfg)
            grid[i, j] = u * 100
    im = ax.imshow(grid, cmap="Greens", vmin=0, vmax=100, aspect="auto")
    ax.set_xticks(range(len(c_out_vals)))
    ax.set_yticks(range(len(c_in_vals)))
    ax.set_xticklabels(c_out_vals)
    ax.set_yticklabels(c_in_vals)
    ax.set_xlabel("C_out")
    ax.set_ylabel("C_in")
    ax.set_title("Util % (C_in × C_out)\nN=1, H=W=56, R=S=3")
    plt.colorbar(im, ax=ax, label="Util %")

    plt.suptitle("K-rows / C_out-cols mapping (32×32 array)", fontsize=12)
    plt.tight_layout()
    out_path = "utilization_sweep.png"
    plt.savefig(out_path, dpi=120)
    plt.close()
    print(f"Saved {out_path}")
    return out_path


if __name__ == "__main__":
    main()
