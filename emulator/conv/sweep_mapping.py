"""
Mapping & tiling analysis (separate from routing).

Figures (mapping_analysis.png):
  (a) ResNet-50: PE utilization per layer
  (b) ResNet-50: tiling breakdown (K-tiles × C_out-tiles)
  (c) Cross-model utilization comparison
  (d) Utilization loss decomposition (row vs col waste)

Run:  python sweep_mapping.py
"""
import numpy as np
import matplotlib.pyplot as plt
from math import ceil

SZ = 32

def layer_metrics(H, W, C_in, C_out, R, S, stride, pad, N=1):
    H_out = (H + 2*pad - R) // stride + 1
    W_out = (W + 2*pad - S) // stride + 1
    K_flat = R * S * C_in
    k_tiles = ceil(K_flat / SZ)
    c_tiles = ceil(C_out / SZ)
    row_util = K_flat / (k_tiles * SZ) * 100
    col_util = C_out / (c_tiles * SZ) * 100
    return {
        "H_out": H_out, "W_out": W_out, "K_flat": K_flat, "C_out": C_out,
        "k_tiles": k_tiles, "c_tiles": c_tiles,
        "util": row_util * col_util / 100,
        "row_util": row_util, "col_util": col_util,
        "last_k_fill": (K_flat % SZ or SZ) / SZ * 100,
        "last_c_fill": (C_out % SZ or SZ) / SZ * 100,
    }

RESNET50 = [
    ("conv1 7×7",       224,224,   3,  64, 7,7, 2,3),
    ("res2 1×1r",        56, 56,  64,  64, 1,1, 1,0),
    ("res2 3×3",         56, 56,  64,  64, 3,3, 1,1),
    ("res2 1×1e",        56, 56,  64, 256, 1,1, 1,0),
    ("res3 1×1r",        56, 56, 256, 128, 1,1, 2,0),
    ("res3 3×3",         28, 28, 128, 128, 3,3, 1,1),
    ("res3 1×1e",        28, 28, 128, 512, 1,1, 1,0),
    ("res4 1×1r",        28, 28, 512, 256, 1,1, 2,0),
    ("res4 3×3",         14, 14, 256, 256, 3,3, 1,1),
    ("res4 1×1e",        14, 14, 256,1024, 1,1, 1,0),
    ("res5 1×1r",        14, 14,1024, 512, 1,1, 2,0),
    ("res5 3×3",          7,  7, 512, 512, 3,3, 1,1),
    ("res5 1×1e",         7,  7, 512,2048, 1,1, 1,0),
]

VGG16 = [
    ("conv1_1",  224,224,   3,  64, 3,3, 1,1),
    ("conv1_2",  224,224,  64,  64, 3,3, 1,1),
    ("conv2_1",  112,112,  64, 128, 3,3, 1,1),
    ("conv2_2",  112,112, 128, 128, 3,3, 1,1),
    ("conv3_1",   56, 56, 128, 256, 3,3, 1,1),
    ("conv3_2",   56, 56, 256, 256, 3,3, 1,1),
    ("conv3_3",   56, 56, 256, 256, 3,3, 1,1),
    ("conv4_1",   28, 28, 256, 512, 3,3, 1,1),
    ("conv4_2",   28, 28, 512, 512, 3,3, 1,1),
    ("conv4_3",   28, 28, 512, 512, 3,3, 1,1),
    ("conv5_1",   14, 14, 512, 512, 3,3, 1,1),
    ("conv5_2",   14, 14, 512, 512, 3,3, 1,1),
    ("conv5_3",   14, 14, 512, 512, 3,3, 1,1),
]

CHALLENGING = [
    ("1×1 Cin=16 K=32",    8, 8, 16, 32, 1,1, 1,0),
    ("1×1 Cin=8 K=16",     4, 4,  8, 16, 1,1, 1,0),
    ("3×3 Cin=16 K=16",    4, 4, 16, 16, 3,3, 1,1),
    ("3×3 Cin=3 K=32 s2",  8, 8,  3, 32, 3,3, 2,1),
    ("1×1 Cin=3 K=16",     7, 7,  3, 16, 1,1, 1,0),
    ("5×5 Cin=3 K=16",     7, 7,  3, 16, 5,5, 1,2),
    ("3×3 Cin=64 K=64",    4, 4, 64, 64, 3,3, 1,1),
    ("3×3 Cin=256 K=256",  2, 2,256,256, 3,3, 1,1),
]

STAGE_COLORS = {
    "conv1": "#4e79a7", "res2": "#59a14f", "res3": "#edc949",
    "res4": "#f28e2b", "res5": "#e15759",
}

def stage_color(name):
    for prefix, c in STAGE_COLORS.items():
        if name.startswith(prefix):
            return c
    return "#999"


def main():
    fig = plt.figure(figsize=(18, 13))
    gs = fig.add_gridspec(2, 2, hspace=0.4, wspace=0.35)

    # ── (a) ResNet-50 utilization ───────────────────────────────────────
    ax_a = fig.add_subplot(gs[0, 0])
    r_metrics = [layer_metrics(*p) for _, *p in RESNET50]
    r_names = [n for n, *_ in RESNET50]
    r_utils = [m["util"] for m in r_metrics]
    r_colors = [stage_color(n) for n in r_names]

    y_a = np.arange(len(r_names))
    ax_a.barh(y_a, r_utils, color=r_colors, edgecolor="white", linewidth=0.5)
    ax_a.set_yticks(y_a)
    ax_a.set_yticklabels(r_names, fontsize=7.5)
    ax_a.invert_yaxis()
    ax_a.set_xlabel("PE Utilization (%)")
    ax_a.set_xlim(0, 110)
    ax_a.axvline(100, color="black", linewidth=0.5, linestyle="--", alpha=0.5)
    for i, (u, m) in enumerate(zip(r_utils, r_metrics)):
        ax_a.text(u + 0.5, i, f"{u:.0f}%  {m['H_out']}×{m['W_out']}  K={m['K_flat']}",
                  va="center", fontsize=6, color="#333")
    ax_a.set_title("(a) ResNet-50: PE Utilization per Layer\nK-rows / C_out-cols, N=1 inference", fontsize=10)
    ax_a.grid(axis="x", alpha=0.2)

    # ── (b) Tiling breakdown ────────────────────────────────────────────
    ax_b = fig.add_subplot(gs[0, 1])
    y_b = np.arange(len(r_names))
    w = 0.35
    k_tiles = [m["k_tiles"] for m in r_metrics]
    c_tiles = [m["c_tiles"] for m in r_metrics]
    ax_b.barh(y_b - w/2, k_tiles, w, label="K-tiles (rows)", color="#4e79a7", edgecolor="white")
    ax_b.barh(y_b + w/2, c_tiles, w, label="C_out-tiles (cols)", color="#f28e2b", edgecolor="white")
    ax_b.set_yticks(y_b)
    ax_b.set_yticklabels(r_names, fontsize=7.5)
    ax_b.invert_yaxis()
    ax_b.set_xlabel("Number of tiles")
    for i in range(len(r_names)):
        ax_b.text(k_tiles[i] + 0.3, i - w/2,
                  f"last: {r_metrics[i]['last_k_fill']:.0f}%", va="center", fontsize=5.5, color="#4e79a7")
        ax_b.text(c_tiles[i] + 0.3, i + w/2,
                  f"last: {r_metrics[i]['last_c_fill']:.0f}%", va="center", fontsize=5.5, color="#f28e2b")
    ax_b.legend(fontsize=8, loc="lower right")
    ax_b.set_title("(b) ResNet-50: Tiling Breakdown\n# tiles + last-tile fill rate", fontsize=10)
    ax_b.grid(axis="x", alpha=0.2)

    # ── (c) Cross-model utilization ─────────────────────────────────────
    ax_c = fig.add_subplot(gs[1, 0])
    rng = np.random.default_rng(0)
    model_data = [
        ("ResNet-50", RESNET50, "#4e79a7"),
        ("VGG-16", VGG16, "#59a14f"),
        ("Challenging\n(small Cin/Cout)", CHALLENGING, "#e15759"),
    ]
    for i, (label, layers, color) in enumerate(model_data):
        utils = [layer_metrics(*p)["util"] for _, *p in layers]
        x = np.ones(len(utils)) * i + rng.uniform(-0.15, 0.15, len(utils))
        ax_c.scatter(x, utils, color=color, s=40, alpha=0.7, edgecolor="white", linewidth=0.4, zorder=3)
        ax_c.hlines(np.mean(utils), i-0.3, i+0.3, color=color, linewidth=2, zorder=4)
        ax_c.text(i+0.35, np.mean(utils), f"mean {np.mean(utils):.0f}%", fontsize=7, va="center", color=color)
        ax_c.text(i+0.35, np.min(utils)-1.5, f"min {np.min(utils):.0f}%", fontsize=7, va="top", color=color)

    ax_c.set_xticks(range(len(model_data)))
    ax_c.set_xticklabels([d[0] for d in model_data], fontsize=8)
    ax_c.set_ylabel("PE Utilization (%)")
    ax_c.set_ylim(0, 110)
    ax_c.axhline(100, color="black", linewidth=0.5, linestyle="--", alpha=0.5)
    ax_c.set_title("(c) Cross-Model Utilization\neach dot = one conv layer", fontsize=10)
    ax_c.grid(axis="y", alpha=0.2)

    # ── (d) Utilization loss decomposition ──────────────────────────────
    ax_d = fig.add_subplot(gs[1, 1])
    all_layers = list(RESNET50) + list(VGG16) + list(CHALLENGING)
    row_u = [layer_metrics(*p)["row_util"] for _, *p in all_layers]
    col_u = [layer_metrics(*p)["col_util"] for _, *p in all_layers]
    colors_d = (["#4e79a7"] * len(RESNET50) +
                ["#59a14f"] * len(VGG16) +
                ["#e15759"] * len(CHALLENGING))
    ax_d.scatter(row_u, col_u, c=colors_d, s=50, alpha=0.7, edgecolor="white", linewidth=0.4, zorder=3)
    ax_d.set_xlabel("Row efficiency (K_flat / padded K)")
    ax_d.set_ylabel("Col efficiency (C_out / padded C_out)")
    ax_d.set_xlim(0, 105)
    ax_d.set_ylim(0, 105)
    ax_d.axhline(100, color="black", linewidth=0.3, linestyle="--", alpha=0.3)
    ax_d.axvline(100, color="black", linewidth=0.3, linestyle="--", alpha=0.3)
    from matplotlib.patches import Patch
    ax_d.legend(handles=[
        Patch(color="#4e79a7", label="ResNet-50"),
        Patch(color="#59a14f", label="VGG-16"),
        Patch(color="#e15759", label="Challenging"),
    ], fontsize=7, loc="lower left")
    ax_d.set_title("(d) Utilization Loss: Row vs Col Efficiency\nbottom-left = both dimensions waste PEs", fontsize=10)
    ax_d.grid(True, alpha=0.2)

    fig.suptitle(
        "Mapping & Tiling Analysis — K-rows / C_out-cols\n"
        "32×32 systolic array, N=1 inference",
        fontsize=13, fontweight="bold", y=0.995,
    )
    fig.savefig("mapping_analysis.png", dpi=150, bbox_inches="tight")
    fig.savefig("mapping_analysis.pdf", bbox_inches="tight")
    plt.close(fig)
    print("Saved mapping_analysis.png/pdf")


if __name__ == "__main__":
    main()
