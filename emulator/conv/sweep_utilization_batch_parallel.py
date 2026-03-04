"""
Sweep layer parameters and plot PE utilization for BATCH-PARALLEL mapping.
Cols = batch (N), rows = kernel (K_flat). High util needs large N and large K_flat.
Optimal inputs differ from K-rows/C_out-cols: need N ≥ 32 for full column fill.
Run: python sweep_utilization_batch_parallel.py
"""
import numpy as np
import matplotlib.pyplot as plt
from im2col import SimConfig, utilization_batch_parallel

SZ = 32
ymax = 105


def sweep_n_bp(base_h=56, base_w=56, base_c=64, base_k=64, base_r=3, base_s=3):
    """Util vs N. Batch parallel needs N large to fill columns."""
    n_vals = [1, 2, 4, 8, 16, 32, 64, 128]
    utils = []
    for n in n_vals:
        cfg = SimConfig(N=n, H=base_h, W=base_w, C=base_c, K=base_k, R=base_r, S=base_s, stride=1, pad=0)
        u, _, _ = utilization_batch_parallel(cfg)
        utils.append(u * 100)
    return n_vals, utils


def sweep_cin_bp(base_n=64, base_h=56, base_w=56, base_k=64, base_r=3, base_s=3):
    """Util vs C_in. K_flat = R*S*C fills rows."""
    c_vals = [4, 8, 16, 32, 64, 128, 256]
    utils = []
    for c in c_vals:
        cfg = SimConfig(N=base_n, H=base_h, W=base_w, C=c, K=base_k, R=base_r, S=base_s, stride=1, pad=0)
        u, _, _ = utilization_batch_parallel(cfg)
        utils.append(u * 100)
    return c_vals, utils


def sweep_cout_bp(base_n=64, base_h=56, base_w=56, base_c=64, base_r=3, base_s=3):
    """Util vs C_out (K). For batch parallel, cols = N so C_out does not affect util (flat)."""
    k_vals = [2, 8, 16, 32, 64, 128, 256]
    utils = []
    for k in k_vals:
        cfg = SimConfig(N=base_n, H=base_h, W=base_w, C=base_c, K=k, R=base_r, S=base_s, stride=1, pad=0)
        u, _, _ = utilization_batch_parallel(cfg)
        utils.append(u * 100)
    return k_vals, utils


def sweep_kernel_size_bp_two_configs(base_h=56, base_w=56):
    """Util vs kernel size for (N=64, C=64) and (N=4, C=2)."""
    rs_vals = [(1, 1), (3, 3), (5, 5), (7, 7)]
    labels = ["1×1", "3×3", "5×5", "7×7"]
    u_big, u_small = [], []
    for (r, s) in rs_vals:
        cfg_big = SimConfig(N=64, H=base_h, W=base_w, C=64, K=64, R=r, S=s, stride=1, pad=0)
        cfg_small = SimConfig(N=4, H=base_h, W=base_w, C=2, K=2, R=r, S=s, stride=1, pad=0)
        ub, _, _ = utilization_batch_parallel(cfg_big)
        us, _, _ = utilization_batch_parallel(cfg_small)
        u_big.append(ub * 100)
        u_small.append(us * 100)
    return labels, u_big, u_small


def sweep_ifmap_bp(base_n=64, base_c=64, base_k=64, base_r=3, base_s=3):
    """Util vs ifmap H=W. Flat (same tile shape at every output position)."""
    hw_vals = [7, 14, 28, 56]  # keep small to avoid slow loops
    utils = []
    for h in hw_vals:
        cfg = SimConfig(N=base_n, H=h, W=h, C=base_c, K=base_k, R=base_r, S=base_s, stride=1, pad=0)
        u, _, _ = utilization_batch_parallel(cfg)
        utils.append(u * 100)
    return hw_vals, utils


def main():
    fig, axes = plt.subplots(2, 3, figsize=(12, 8))

    # Util vs N (main driver for batch parallel)
    ax = axes[0, 0]
    x, u = sweep_n_bp()
    ax.plot(x, u, "o-", color="green")
    ax.set_xlabel("Batch size (N)")
    ax.set_ylabel("Utilization (%)")
    ax.set_title("Util vs N (fixed C=K=64, 3×3)\ncols = N → need N≥32 for 100%")
    ax.set_ylim(0, ymax)
    ax.axhline(y=100, color="gray", linestyle="--", alpha=0.5)
    ax.axvline(x=32, color="gray", linestyle=":", alpha=0.5)
    ax.grid(True, alpha=0.3)

    # Util vs C_in (K_flat = R*S*C fills rows)
    ax = axes[0, 1]
    x, u = sweep_cin_bp()
    ax.plot(x, u, "o-", color="green")
    ax.set_xlabel("C_in (C)")
    ax.set_ylabel("Utilization (%)")
    ax.set_title("Util vs C_in (fixed N=64, K=64, 3×3)")
    ax.set_ylim(0, ymax)
    ax.axhline(y=100, color="gray", linestyle="--", alpha=0.5)
    ax.grid(True, alpha=0.3)

    # Util vs C_out — flat (cols = N, not K)
    ax = axes[0, 2]
    x, u = sweep_cout_bp()
    util_k = u[0]
    ax.plot(x, u, "o-", color="green")
    ax.set_xlabel("C_out (K)")
    ax.set_ylabel("Utilization (%)")
    ax.set_title(f"Util vs C_out (flat at {util_k:.1f}% — cols=N not K)")
    ax.set_ylim(0, ymax)
    ax.axhline(y=100, color="gray", linestyle="--", alpha=0.5)
    ax.grid(True, alpha=0.3)

    # Util vs kernel size
    ax = axes[1, 0]
    labels, u_big, u_small = sweep_kernel_size_bp_two_configs()
    x = np.arange(len(labels))
    w = 0.35
    ax.bar(x - w / 2, u_big, w, label="N=64, C=K=64", color="green", alpha=0.8, edgecolor="black")
    ax.bar(x + w / 2, u_small, w, label="N=4, C=K=2", color="gold", edgecolor="black")
    ax.set_xticks(x)
    ax.set_xticklabels(labels)
    ax.set_xlabel("Kernel R×S")
    ax.set_ylabel("Utilization (%)")
    ax.set_title("Util vs kernel size (H=W=56)")
    ax.set_ylim(0, ymax)
    ax.axhline(y=100, color="gray", linestyle="--", alpha=0.5)
    ax.legend(fontsize=8)
    ax.grid(True, alpha=0.3, axis="y")

    # Util vs ifmap size — flat
    ax = axes[1, 1]
    x, u = sweep_ifmap_bp()
    util_hw = u[0]
    ax.plot(x, u, "o-", color="green")
    ax.set_xlabel("IFMap H=W")
    ax.set_ylabel("Utilization (%)")
    ax.set_title(f"Util vs IFMap size (flat at {util_hw:.1f}%)")
    ax.set_ylim(0, ymax)
    ax.axhline(y=100, color="gray", linestyle="--", alpha=0.5)
    ax.grid(True, alpha=0.3)

    # Heatmap: N × C_in (fixed K=64, H=W=14, R=S=3 — small H,W for fast eval)
    ax = axes[1, 2]
    n_vals = [1, 8, 16, 32, 64]
    c_vals = [16, 32, 64, 128]
    grid = np.zeros((len(n_vals), len(c_vals)))
    for i, n in enumerate(n_vals):
        for j, c in enumerate(c_vals):
            cfg = SimConfig(N=n, H=14, W=14, C=c, K=64, R=3, S=3, stride=1, pad=0)
            u, _, _ = utilization_batch_parallel(cfg)
            grid[i, j] = u * 100
    im = ax.imshow(grid, cmap="Greens", vmin=0, vmax=100, aspect="auto")
    ax.set_xticks(range(len(c_vals)))
    ax.set_yticks(range(len(n_vals)))
    ax.set_xticklabels(c_vals)
    ax.set_yticklabels(n_vals)
    ax.set_xlabel("C_in")
    ax.set_ylabel("N (batch)")
    ax.set_title("Util % (N × C_in)\nK=64, H=W=14, R=S=3")
    plt.colorbar(im, ax=ax, label="Util %")

    plt.suptitle("Batch-parallel mapping (32×32): rows=K_flat, cols=N", fontsize=12)
    plt.tight_layout()
    out_path = "utilization_sweep_batch_parallel.png"
    plt.savefig(out_path, dpi=120)
    plt.close()
    print(f"Saved {out_path}")
    return out_path


if __name__ == "__main__":
    main()
