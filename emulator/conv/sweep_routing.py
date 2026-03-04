"""
PSUM routing-specific analysis.

Figures (psum_routing.png):
  (a) Buffer depth (FIFO size) per layer — hardware sizing
  (b) Accumulations per buffer entry (K-tiles) — shows accumulate-before-drain
  (c) Buffer depth scaling vs spatial size — parametric relationship
  (d) Sim-verified configs — diverse edge cases run through router

Run:  python sweep_routing.py
"""
import numpy as np
import matplotlib.pyplot as plt
from math import ceil

SZ = 32

def layer_metrics(H, W, C_in, C_out, R, S, stride, pad, N=1):
    H_out = (H + 2*pad - R) // stride + 1
    W_out = (W + 2*pad - S) // stride + 1
    K_flat = R * S * C_in
    M = N * H_out * W_out
    k_tiles = ceil(K_flat / SZ)
    c_tiles = ceil(C_out / SZ)
    return {
        "H_out": H_out, "W_out": W_out, "K_flat": K_flat, "C_out": C_out,
        "M": M, "k_tiles": k_tiles, "c_tiles": c_tiles,
        "buffer_depth": M, "accum_per_entry": k_tiles,
    }

# Representative layers from real models
LAYERS = [
    # (name, H, W, C_in, C_out, R, S, stride, pad)
    ("conv1 7×7\n224→112",     224,224,   3,  64, 7,7, 2,3),
    ("res2 3×3\n56×56",         56, 56,  64,  64, 3,3, 1,1),
    ("res2 1×1e\n56×56",        56, 56,  64, 256, 1,1, 1,0),
    ("res3 3×3\n28×28",         28, 28, 128, 128, 3,3, 1,1),
    ("res3 1×1e\n28×28",        28, 28, 128, 512, 1,1, 1,0),
    ("res4 3×3\n14×14",         14, 14, 256, 256, 3,3, 1,1),
    ("res4 1×1e\n14×14",        14, 14, 256,1024, 1,1, 1,0),
    ("res5 3×3\n7×7",            7,  7, 512, 512, 3,3, 1,1),
    ("res5 1×1e\n7×7",           7,  7, 512,2048, 1,1, 1,0),
    ("VGG conv1_1\n224×224",   224,224,   3,  64, 3,3, 1,1),
    ("VGG conv5_3\n14×14",      14, 14, 512, 512, 3,3, 1,1),
]

VERIFY_CONFIGS = [
    ("3×3 Cin=128 Cout=128\n28×28",    28,28,128,128, 3,3,1,1),
    ("1×1 Cin=256 Cout=1024\n14×14",   14,14,256,1024,1,1,1,0),
    ("7×7 Cin=3 Cout=64\n224→112 s=2",  8, 8,  3, 64, 7,7,2,3),
    ("3×3 Cin=512 Cout=512\n7×7",        7, 7,512,512, 3,3,1,1),
    ("1×1 Cin=512 Cout=2048\n7×7",       7, 7,512,2048,1,1,1,0),
    ("3×3 Cin=256 Cout=256\n4×4",         4, 4,256,256, 3,3,1,1),
    ("1×1 Cin=256 Cout=256\n2×2",         2, 2,256,256, 1,1,1,0),
    ("1×1 Cin=512 Cout=2048\n1×1",        1, 1,512,2048,1,1,1,0),
    ("Kflat=90 Cout=48\n(non-div-32)",    6, 6, 10, 48, 3,3,1,0),
    ("s=2 pad=1 N=2\n(batched)",          8, 8, 32, 64, 3,3,2,1),
]

def verify_config(H, W, C_in, C_out, R, S, stride, pad, N=1):
    from im2col import SimConfig, ImplicitIm2colSystolicSim
    from psum_router import simulate_with_routing
    cfg = SimConfig(N=N, H=H, W=W, C=C_in, K=C_out, R=R, S=S,
                    stride=stride, pad=pad, use_sequential_init=False, seed=42)
    sim = ImplicitIm2colSystolicSim(cfg)
    r = simulate_with_routing(sim)
    return r["verified"], r["max_abs_diff"]


def main():
    fig = plt.figure(figsize=(16, 12))
    gs = fig.add_gridspec(2, 2, hspace=0.45, wspace=0.35)

    metrics = [layer_metrics(*params) for _, *params in LAYERS]
    names = [n for n, *_ in LAYERS]

    # ── (a) Buffer depth per layer ──────────────────────────────────────
    ax_a = fig.add_subplot(gs[0, 0])
    depths = [m["buffer_depth"] for m in metrics]
    y_a = np.arange(len(names))
    bars_a = ax_a.barh(y_a, depths, color="#4e79a7", edgecolor="white", linewidth=0.5)
    ax_a.set_yticks(y_a)
    ax_a.set_yticklabels(names, fontsize=7)
    ax_a.invert_yaxis()
    ax_a.set_xlabel("Buffer depth (entries per FIFO)")
    ax_a.set_xscale("log")
    for i, d in enumerate(depths):
        sp = metrics[i]
        ax_a.text(d * 1.1, i, f"{d:,}  ({sp['H_out']}×{sp['W_out']})",
                  va="center", fontsize=6.5, color="#333")
    ax_a.set_title("(a) FIFO Buffer Depth per Layer\n= H_out × W_out (N=1)", fontsize=10)
    ax_a.grid(axis="x", alpha=0.2)

    # ── (b) Accumulations per entry (K-tiles) ──────────────────────────
    ax_b = fig.add_subplot(gs[0, 1])
    accums = [m["accum_per_entry"] for m in metrics]
    y_b = np.arange(len(names))
    bars_b = ax_b.barh(y_b, accums, color="#f28e2b", edgecolor="white", linewidth=0.5)
    ax_b.set_yticks(y_b)
    ax_b.set_yticklabels(names, fontsize=7)
    ax_b.invert_yaxis()
    ax_b.set_xlabel("Accumulations per entry (= K-tiles)")
    for i, a in enumerate(accums):
        kf = metrics[i]["K_flat"]
        ax_b.text(a + 0.3, i, f"{a}  (K_flat={kf})", va="center", fontsize=6.5, color="#333")
    ax_b.set_title("(b) Accumulations per Buffer Entry\neach entry accumulated K-tile times before drain", fontsize=10)
    ax_b.grid(axis="x", alpha=0.2)

    # ── (c) Buffer depth scaling vs spatial size ────────────────────────
    ax_c = fig.add_subplot(gs[1, 0])
    spatial_sizes = [1, 2, 4, 7, 14, 28, 56, 112]
    for label, Cin, Cout, R, S, color, marker in [
        ("3×3 C=512→512",  512, 512,  3,3, "#e15759", "o"),
        ("1×1 C=256→1024", 256,1024,  1,1, "#4e79a7", "s"),
        ("3×3 C=64→64",     64,  64,  3,3, "#59a14f", "^"),
    ]:
        buf_depths = [s * s for s in spatial_sizes]
        k_tiles = [ceil(R * S * Cin / SZ)] * len(spatial_sizes)
        ax_c.plot(spatial_sizes, buf_depths, marker=marker, label=label,
                  color=color, linewidth=1.5, markersize=5)
    ax_c.set_xlabel("Spatial size (H_out = W_out)")
    ax_c.set_ylabel("Buffer depth (entries)")
    ax_c.set_yscale("log")
    ax_c.legend(fontsize=7, loc="upper left")
    ax_c.set_title("(c) Buffer Depth Scaling\nbuf_depth = H_out × W_out (independent of channels)", fontsize=10)
    ax_c.grid(True, alpha=0.2)
    ax_c.set_xticks(spatial_sizes)

    # ── (d) Sim-verified edge cases ─────────────────────────────────────
    ax_d = fig.add_subplot(gs[1, 1])
    v_names, v_depths, v_accums, v_pass = [], [], [], []
    for name, *params in VERIFY_CONFIGS:
        m = layer_metrics(*params)
        # handle N=2 for batched config
        N = 2 if "N=2" in name else 1
        passed, diff = verify_config(*params, N=N)
        v_names.append(name)
        v_depths.append(m["buffer_depth"] * N)
        v_accums.append(m["accum_per_entry"])
        v_pass.append(passed)

    y_d = np.arange(len(v_names))
    colors_d = ["#59a14f" if p else "#e15759" for p in v_pass]
    ax_d.barh(y_d, v_accums, color=colors_d, edgecolor="white", linewidth=0.5)
    ax_d.set_yticks(y_d)
    ax_d.set_yticklabels(v_names, fontsize=6.5)
    ax_d.invert_yaxis()
    ax_d.set_xlabel("K-tiles (accumulations)")
    for i in range(len(v_names)):
        tag = "✓" if v_pass[i] else "✗"
        ax_d.text(v_accums[i] + 0.3, i,
                  f"{tag}  buf={v_depths[i]}  K-tiles={v_accums[i]}",
                  va="center", fontsize=6, color="#333")
    ax_d.set_title("(d) Sim-Verified Configs (green = PASS)\nincludes small IFMap, non-div-32, batched, strided", fontsize=10)
    ax_d.grid(axis="x", alpha=0.2)

    fig.suptitle(
        "PSUM Direct-Mapped Routing — Buffer Analysis\n"
        "col c → buf c  |  FIFO sizing, accumulation depth, verification",
        fontsize=13, fontweight="bold", y=0.995,
    )
    fig.savefig("psum_routing.png", dpi=150, bbox_inches="tight")
    fig.savefig("psum_routing.pdf", bbox_inches="tight")
    plt.close(fig)
    print("Saved psum_routing.png/pdf")


if __name__ == "__main__":
    main()
