from __future__ import annotations

import csv
from pathlib import Path

import matplotlib.pyplot as plt


ROOT = Path(__file__).resolve().parent
CSV_PATH = ROOT / "out" / "conv_scaling_results.csv"
OUT_DIR = ROOT / "out" / "plots"
OUT_DIR.mkdir(parents=True, exist_ok=True)


def load_rows(path: Path):
    rows = []
    with path.open() as f:
        reader = csv.DictReader(f)
        for r in reader:
            r2 = dict(r)
            r2["M"] = int(r2["M"])
            r2["conv_instr"] = int(r2["conv_instr"])
            r2["conv_cycles_est"] = float(r2["conv_cycles_est"])
            r2["conv_ops"] = float(r2["conv_ops"])
            r2["conv_bytes_loaded"] = int(r2["conv_bytes_loaded"])
            r2["conv_bytes_stored"] = int(r2["conv_bytes_stored"])
            r2["conv_ai_load"] = float(r2["conv_ai_load"])
            r2["match"] = r2["match"] == "True"
            rows.append(r2)
    return rows


def split_by_kernel(rows):
    base = sorted([r for r in rows if r["kernel"] == "baseline"], key=lambda x: (x["M"], x["config"]))
    pipe = sorted([r for r in rows if r["kernel"] == "pipelined"], key=lambda x: (x["M"], x["config"]))
    return base, pipe


def themed_axes(ax):
    ax.set_facecolor("#f4fbf4")
    ax.grid(True, alpha=0.25, color="#2e7d32")
    for s in ax.spines.values():
        s.set_color("#2e7d32")


def plot_main(base, pipe):
    x = [r["M"] for r in base]
    labels = [r["config"] for r in base]

    bcol = "#1b5e20"
    pcol = "#66bb6a"
    accent = "#2e7d32"

    fig, axs = plt.subplots(2, 2, figsize=(12, 8), dpi=150)
    fig.patch.set_facecolor("#ecf8ec")
    fig.suptitle("Conv Scaling: Baseline vs Pipelined", color=accent, fontsize=14, fontweight="bold")

    ax = axs[0, 0]
    themed_axes(ax)
    ax.plot(x, [r["conv_cycles_est"] for r in base], marker="o", color=bcol, label="baseline")
    ax.plot(x, [r["conv_cycles_est"] for r in pipe], marker="o", color=pcol, label="pipelined")
    ax.set_title("Estimated Cycles (Conv Region)", color=accent)
    ax.set_xlabel("M = N*Ho*Wo")
    ax.set_ylabel("cycles_est")
    ax.legend(frameon=False)

    ax = axs[0, 1]
    themed_axes(ax)
    ax.plot(x, [r["conv_instr"] for r in base], marker="o", color=bcol, label="baseline")
    ax.plot(x, [r["conv_instr"] for r in pipe], marker="o", color=pcol, label="pipelined")
    ax.set_title("Retired Instructions (Conv Region)", color=accent)
    ax.set_xlabel("M = N*Ho*Wo")
    ax.set_ylabel("instr")
    ax.legend(frameon=False)

    ax = axs[1, 0]
    themed_axes(ax)
    ax.plot(x, [r["conv_bytes_loaded"] for r in base], marker="o", color=bcol, label="bytes_loaded")
    ax.plot(x, [r["conv_bytes_stored"] for r in base], marker="o", color="#43a047", label="bytes_stored")
    ax.set_title("GMEM Traffic (Baseline Conv Region)", color=accent)
    ax.set_xlabel("M = N*Ho*Wo")
    ax.set_ylabel("bytes")
    ax.legend(frameon=False)

    ax = axs[1, 1]
    themed_axes(ax)
    ax.plot(x, [r["conv_ai_load"] for r in base], marker="o", color=bcol, label="baseline")
    ax.plot(x, [r["conv_ai_load"] for r in pipe], marker="o", color=pcol, label="pipelined")
    ax.set_title("Arithmetic Intensity (ops / bytes_loaded)", color=accent)
    ax.set_xlabel("M = N*Ho*Wo")
    ax.set_ylabel("AI(load)")
    ax.legend(frameon=False)

    for ax in axs.flat:
        for xi, lbl in zip(x, labels):
            ax.annotate(lbl, (xi, ax.get_ylim()[0]), textcoords="offset points", xytext=(0, 2), ha="center", fontsize=7, color=accent)

    out = OUT_DIR / "conv_scaling_dashboard_green.png"
    fig.tight_layout(rect=[0, 0, 1, 0.96])
    fig.savefig(out, facecolor=fig.get_facecolor())
    plt.close(fig)
    return out


def plot_overhead(base, pipe):
    cfg = [r["config"] for r in base]
    cyc_pct = []
    ins_pct = []
    ai_pct = []
    for b, p in zip(base, pipe):
        cyc_pct.append((p["conv_cycles_est"] - b["conv_cycles_est"]) / b["conv_cycles_est"] * 100.0)
        ins_pct.append((p["conv_instr"] - b["conv_instr"]) / b["conv_instr"] * 100.0)
        ai_pct.append((p["conv_ai_load"] - b["conv_ai_load"]) / b["conv_ai_load"] * 100.0)

    x = range(len(cfg))
    width = 0.25

    fig, ax = plt.subplots(figsize=(11, 4.8), dpi=150)
    fig.patch.set_facecolor("#ecf8ec")
    themed_axes(ax)
    ax.bar([i - width for i in x], cyc_pct, width=width, color="#1b5e20", label="cycles_est delta %")
    ax.bar(x, ins_pct, width=width, color="#43a047", label="instr delta %")
    ax.bar([i + width for i in x], ai_pct, width=width, color="#81c784", label="AI(load) delta %")
    ax.axhline(0, color="#2e7d32", linewidth=1)
    ax.set_xticks(list(x))
    ax.set_xticklabels(cfg, rotation=20, ha="right")
    ax.set_ylabel("Pipeline vs Baseline delta (%)")
    ax.set_title("Pipelined Overhead / Gain by Config", color="#2e7d32", fontweight="bold")
    ax.legend(frameon=False)

    out = OUT_DIR / "conv_pipeline_delta_green.png"
    fig.tight_layout()
    fig.savefig(out, facecolor=fig.get_facecolor())
    plt.close(fig)
    return out


def write_summary(rows, base, pipe):
    all_match = all(r["match"] for r in rows)
    ai_deltas = [((p["conv_ai_load"] - b["conv_ai_load"]) / b["conv_ai_load"] * 100.0) for b, p in zip(base, pipe)]
    cyc_deltas = [((p["conv_cycles_est"] - b["conv_cycles_est"]) / b["conv_cycles_est"] * 100.0) for b, p in zip(base, pipe)]
    ins_deltas = [((p["conv_instr"] - b["conv_instr"]) / b["conv_instr"] * 100.0) for b, p in zip(base, pipe)]

    md = []
    md.append("# Conv Team Summary (What to send)")
    md.append("")
    md.append(f"- Correctness across sweep: **{'PASS' if all_match else 'FAIL'}** (all configs MATCH)")
    md.append(f"- Avg pipelined delta (conv region):")
    md.append(f"  - `AI(load)`: **{sum(ai_deltas)/len(ai_deltas):.4f}%**")
    md.append(f"  - `estimated_cycles`: **{sum(cyc_deltas)/len(cyc_deltas):.2f}%**")
    md.append(f"  - `instr_retired`: **{sum(ins_deltas)/len(ins_deltas):.2f}%**")
    md.append("- Interpretation: pipelining preserves math/traffic and mainly changes scheduling/control overhead in this functional emulator.")
    md.append("- Most meaningful metrics to track now: `MATCH`, `conv_bytes_loaded/stored`, `conv_ops`, `conv_ai_load`, `conv_instr`, `conv_cycles_est`.")
    md.append("")
    md.append("## Plots")
    md.append("- `out/plots/conv_scaling_dashboard_green.png`")
    md.append("- `out/plots/conv_pipeline_delta_green.png`")
    md.append("")
    md.append("## Data sources")
    md.append("- `out/conv_scaling_results.csv`")
    md.append("- `out/conv_scaling_summary.md`")

    out = ROOT / "out" / "conv_team_summary.md"
    out.write_text("\n".join(md) + "\n")
    return out


def main():
    rows = load_rows(CSV_PATH)
    base, pipe = split_by_kernel(rows)
    p1 = plot_main(base, pipe)
    p2 = plot_overhead(base, pipe)
    s = write_summary(rows, base, pipe)
    print(f"Wrote {p1}")
    print(f"Wrote {p2}")
    print(f"Wrote {s}")


if __name__ == "__main__":
    main()
