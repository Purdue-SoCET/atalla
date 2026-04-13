#!/usr/bin/env python3
"""
Emit individual figures from kernel_metrics.csv (no combined dashboard).

Plot-only transforms (CSV unchanged):
  - Drop maxpool, add.
  - Drop gemms baseline and CSV gemms pipelined; show gemms function metrics as "gemms pipelined".
  - Display: conv sa → conv; clearer layernorm labels.
  - Conv/GEMM variant packets + static slots are one combined figure (saved to both prior filenames).
  - Arithmetic intensity (arithmetic_intensity.png + compare twin axes): FLOPs / (bytes loaded + bytes written).
    CSV column used: "AI (load+store)". Narrow FLOPs/loads-only remains in CSV as "Arithmetic Intensity".
  - scheduling_metrics.png: full CSV row order; ``Packet Slot Util. %`` and
    ``Static packet rows`` / ``Ops executed (dynamic)`` (static image rows per dynamic op retired).
"""
from __future__ import annotations

import argparse
import csv
from pathlib import Path

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.lines import Line2D
from matplotlib.patches import Patch
from matplotlib.transforms import blended_transform_factory

# --- Dark blue + orange ---
BLUE = "#0b2f5c"
BLUE_MID = "#1e4d7b"
BLUE_LIGHT = "#3d6fa3"
ORANGE = "#e07020"
ORANGE_LIGHT = "#f4a261"
INK = "#0f172a"
GRID = "#cbd5e1"


def _style_axis(ax, *, grid_axis: str | None = "y") -> None:
    """Light grid on one axis only, drawn behind artists."""
    ax.set_facecolor("#ffffff")
    ax.set_axisbelow(True)
    ax.tick_params(colors=INK, labelsize=9)
    for sp in ax.spines.values():
        sp.set_color("#94a3b8")
        sp.set_linewidth(0.9)
    if grid_axis == "y":
        ax.grid(True, axis="y", linestyle="-", linewidth=0.75, alpha=0.4, color=GRID, zorder=0)
    elif grid_axis == "x":
        ax.grid(True, axis="x", linestyle="-", linewidth=0.75, alpha=0.4, color=GRID, zorder=0)
    else:
        ax.grid(False)


def _legend(ax, **kw):
    leg = ax.legend(
        frameon=True,
        fancybox=False,
        edgecolor="#94a3b8",
        facecolor="#f8fafc",
        fontsize=8,
        **kw,
    )
    leg.get_frame().set_alpha(0.96)


def load_rows(path: Path) -> list[dict[str, str]]:
    with path.open(newline="", encoding="utf-8") as f:
        return list(csv.DictReader(f))


def fval(row: dict, key: str) -> float:
    v = row.get(key, "").strip()
    if not v:
        return float("nan")
    return float(v)


def ival(row: dict, key: str) -> int:
    v = row.get(key, "").strip()
    if not v:
        return 0
    return int(float(v))


def ival_any(row: dict, *keys: str) -> int:
    for k in keys:
        v = row.get(k, "").strip()
        if v:
            return int(float(v))
    return 0


def shorten_label(s: str, max_len: int = 24) -> str:
    s = s.strip()
    return s if len(s) <= max_len else s[: max_len - 1] + "…"


def _annotate_vertical_bars_inside(
    ax,
    bars,
    values: list[float] | np.ndarray,
    *,
    value_fmt: str | None = None,
    colors: list[str] | None = None,
) -> None:
    """Draw value and optional % vs first bar centered inside each vertical bar."""
    vals = np.asarray(values, dtype=float)
    base = float(vals[0]) if len(vals) else 0.0

    def _fmt(h: float) -> str:
        if value_fmt is not None:
            return value_fmt.format(h)
        return f"{int(round(h))}"

    ymax = ax.get_ylim()[1] or 1.0

    for i, b in enumerate(bars):
        h = float(b.get_height())
        x = b.get_x() + b.get_width() / 2
        if i == 0:
            txt = _fmt(h)
        else:
            pct = (h - base) / base * 100 if base else 0.0
            txt = f"{_fmt(h)}\n({pct:+.1f}%)"
        fs = 7 if h < 0.12 * ymax else 8
        if h < 0.06 * ymax:
            fs = 6
        fill = (colors[i] if colors and i < len(colors) else BLUE).lstrip("#").lower()
        r, g, b = int(fill[0:2], 16), int(fill[2:4], 16), int(fill[4:6], 16)
        lum = 0.2126 * r + 0.7152 * g + 0.0722 * b
        tc = "#f8fafc" if lum < 130 else INK
        ax.text(x, h * 0.52, txt, ha="center", va="center", fontsize=fs, color=tc, fontweight="600", zorder=4)


def _kernel_display_xtick(k: str) -> str:
    """Multiline x labels so long names are not truncated."""
    m = {
        "conv": "conv",
        "conv pipelined": "conv\npipelined",
        "conv pipelined unroll": "conv\npipelined\nunroll",
        "gemms": "gemms\nbaseline",
        "gemms pipelined": "gemms\npipelined",
        "gemms pipelined loop unroll": "gemms\npipelined\nloop unroll",
    }
    return m.get(k, shorten_label(k, 20))


DISPLAY_RENAME = {
    "conv sa": "conv",
    "layernorm (latency)": "layernorm latency",
    "layernorm (sequential)": "layernorm sequential",
}


def _relabel_row(r: dict) -> dict:
    out = dict(r)
    k = out.get("Kernel", "")
    if k in DISPLAY_RENAME:
        out["Kernel"] = DISPLAY_RENAME[k]
    return out


def prepare_plot_rows(rows: list[dict], *, include_gemms_baseline: bool = False) -> list[dict]:
    """
    Filter kernels and merge GEMM: use gemms function numbers as display 'gemms pipelined'.

    Baseline CSV row ``gemms`` is dropped by default (dedupe vs function/pipelined builds).
    Set ``include_gemms_baseline=True`` for figures where that anchor helps (e.g. loop reuse).
    """
    by = {r["Kernel"]: r for r in rows}
    synth: dict | None = None
    if "gemms function" in by:
        synth = dict(by["gemms function"])
        synth["Kernel"] = "gemms pipelined"

    out: list[dict] = []
    skip = {"maxpool", "add", "gemms pipelined"}
    if not include_gemms_baseline:
        skip.add("gemms")
    for r in rows:
        k = r["Kernel"]
        if k in skip:
            continue
        if k == "gemms function":
            if synth:
                out.append(_relabel_row(synth))
            continue
        out.append(_relabel_row(r))
    return out


def fig_work_vs_cost(rows: list[dict], out: Path) -> None:
    names = [r["Kernel"] for r in rows]
    flops = np.array([ival(r, "FLOPs (total)") for r in rows], dtype=float)
    pkt_ex = np.array([ival(r, "Packets executed") for r in rows], dtype=float)
    x = np.arange(len(names))
    fig, ax1 = plt.subplots(figsize=(12, 5.2))
    _style_axis(ax1, grid_axis="y")
    ax1.bar(x - 0.2, flops, 0.4, label="FLOPs (total)", color=BLUE, alpha=0.92, edgecolor="none", zorder=2)
    ax1.set_yscale("log")
    ax1.set_ylabel("FLOPs (total)", color=INK)
    ax1.set_xlabel("Kernel")
    ax1.set_xticks(x)
    ax1.set_xticklabels([shorten_label(n) for n in names], rotation=45, ha="right", fontsize=8)
    ax2 = ax1.twinx()
    ax2.set_axisbelow(True)
    ax2.patch.set_visible(False)
    ax2.grid(False)
    ax2.tick_params(axis="y", colors=ORANGE)
    ax2.plot(
        x,
        np.maximum(pkt_ex, 1),
        "o-",
        color=ORANGE,
        lw=1.5,
        ms=5,
        mfc=ORANGE_LIGHT,
        mec=ORANGE,
        label="Packets executed",
        zorder=3,
    )
    ax2.set_yscale("log")
    ax2.set_ylabel("Packets executed (dynamic)", color=ORANGE)
    ax1.set_title("Work vs packet fetches", fontsize=11, color=INK, pad=22)
    trans_x_axes_y = blended_transform_factory(ax1.transData, ax1.transAxes)
    y0, y_step = 1.012, 0.026
    for i in range(len(names)):
        ax1.text(
            x[i],
            y0 + y_step,
            f"{int(flops[i])}",
            transform=trans_x_axes_y,
            ha="center",
            va="bottom",
            fontsize=7.5,
            color=BLUE,
            clip_on=False,
        )
        ax1.text(
            x[i],
            y0,
            f"{int(pkt_ex[i])}",
            transform=trans_x_axes_y,
            ha="center",
            va="bottom",
            fontsize=7.5,
            color=ORANGE,
            clip_on=False,
        )
    h1, l1 = ax1.get_legend_handles_labels()
    h2, l2 = ax2.get_legend_handles_labels()
    _legend(ax1, handles=h1 + h2, labels=l1 + l2, loc="upper left")
    fig.subplots_adjust(bottom=0.14, top=0.80)
    fig.savefig(out, dpi=180, facecolor="white")
    plt.close(fig)


def fig_memory_vs_compute(rows: list[dict], out: Path) -> None:
    names = [r["Kernel"] for r in rows]
    bl = np.array([ival(r, "Bytes Loaded") for r in rows], dtype=float)
    bw = np.array([ival(r, "Bytes Written") for r in rows], dtype=float)
    flops = np.array([ival(r, "FLOPs (total)") for r in rows], dtype=float)

    def _ops_or_fallback(r: dict) -> int:
        o = ival_any(r, "Ops executed (dynamic)")
        return o if o else ival_any(r, "Static slots filled (non-NOP)", "Instr Count")

    ops_dyn = np.array([_ops_or_fallback(r) for r in rows], dtype=float)
    fig, ax = plt.subplots(figsize=(8.5, 6.2))
    _style_axis(ax, grid_axis=None)
    sizes = 28 + 95 * (ops_dyn / (ops_dyn.max() or 1))
    sc = ax.scatter(
        bl,
        flops,
        s=sizes,
        c=bw,
        cmap="Blues",
        alpha=0.88,
        edgecolors=BLUE_MID,
        linewidths=0.5,
        zorder=2,
    )
    cbar = fig.colorbar(sc, ax=ax, shrink=0.55, pad=0.02)
    cbar.set_label("Bytes written (GMEM←SCPAD)", fontsize=8)
    cbar.ax.tick_params(labelsize=8)
    for i, n in enumerate(names):
        ax.annotate(
            shorten_label(n, 16),
            (bl[i], flops[i]),
            textcoords="offset points",
            xytext=(3, 3),
            fontsize=6.5,
            color=INK,
        )
    ax.set_xscale("log")
    ax.set_yscale("log")
    ax.set_xlabel("Bytes loaded (GMEM→SCPAD DMA, log scale)")
    ax.set_ylabel("FLOPs total (log scale)")
    ax.set_title("Memory traffic vs compute", fontsize=11, color=INK, pad=8)
    fig.text(
        0.5,
        0.01,
        "Marker size ∝ ops executed (dynamic). No grid (less clutter on log scatter).",
        ha="center",
        fontsize=7.5,
        color="#64748b",
    )
    fig.subplots_adjust(bottom=0.12)
    fig.savefig(out, dpi=180, facecolor="white")
    plt.close(fig)


def fig_compute_composition(rows: list[dict], out: Path) -> None:
    names = [shorten_label(r["Kernel"]) for r in rows]
    ft = np.array([ival(r, "FLOPs (total)") for r in rows], dtype=float)
    fm = np.array([ival(r, "FLOPs matmul") for r in rows], dtype=float)
    with np.errstate(divide="ignore", invalid="ignore"):
        pct_sys = np.where(ft > 0, 100.0 * fm / ft, 0.0)
    pct_vec = np.maximum(0.0, 100.0 - pct_sys)
    # y[j] aligns with names[j] and pct_sys[j]; invert_yaxis() puts rows[0] at the top.
    y = np.arange(len(names), dtype=float)
    fig, ax = plt.subplots(figsize=(9.5, max(5.0, 0.32 * len(names))))
    _style_axis(ax, grid_axis="x")
    ax.barh(y, pct_sys, height=0.72, color=BLUE, edgecolor="none", zorder=2)
    ax.barh(y, pct_vec, height=0.72, left=pct_sys, color=BLUE_LIGHT, edgecolor="none", zorder=2)
    for j, yi in enumerate(y):
        ps = float(pct_sys[j])
        if ps >= 2.5:
            ax.text(ps * 0.5, yi, f"{ps:.0f}%", va="center", ha="center", fontsize=7, color="#f8fafc", fontweight="600", zorder=3)
        elif ps > 0:
            ax.text(min(ps * 0.5, 1.2), yi, f"{ps:.0f}%", va="center", ha="left", fontsize=6, color="#f8fafc", zorder=3)
    ax.set_yticks(y)
    ax.set_yticklabels(names, fontsize=8)
    ax.invert_yaxis()
    ax.set_xlabel("Share of reported FLOPs (%)")
    ax.set_xlim(0, 100)
    ax.set_title("Compute composition", fontsize=11, color=INK, pad=8)
    fig.text(
        0.5,
        0.02,
        "matmul FLOPs from gemm.vv tile model; remainder = scalar + vector lane counters.",
        ha="center",
        fontsize=7.5,
        color="#64748b",
    )
    leg_handles = [
        Patch(facecolor=BLUE, edgecolor="none", label="Systolic (FLOPs matmul)"),
        Patch(facecolor=BLUE_LIGHT, edgecolor="none", label="Vector / scalar"),
    ]
    ax.legend(
        handles=leg_handles,
        loc="upper left",
        bbox_to_anchor=(1.01, 1.0),
        borderaxespad=0.0,
        frameon=True,
        fancybox=False,
        edgecolor="#94a3b8",
        facecolor="#f8fafc",
        fontsize=8,
    )
    fig.subplots_adjust(bottom=0.14, left=0.26, right=0.78)
    fig.savefig(out, dpi=180, facecolor="white")
    plt.close(fig)


def fig_static_vs_dynamic_ops(rows: list[dict], out: Path) -> None:
    names = [r["Kernel"] for r in rows]
    static_s = np.array([ival_any(r, "Static slots filled (non-NOP)", "Instr Count") for r in rows], dtype=float)
    ops = np.array([ival_any(r, "Ops executed (dynamic)") or static_s[i] for i, r in enumerate(rows)], dtype=float)
    x = np.arange(len(names))
    w = 0.36
    fig, ax = plt.subplots(figsize=(12, 5.0))
    _style_axis(ax, grid_axis="y")
    ax.bar(x - w / 2, static_s, w, label="Static slots filled (non-NOP)", color=BLUE_LIGHT, edgecolor="none", zorder=2)
    ax.bar(x + w / 2, ops, w, label="Ops executed (dynamic)", color=BLUE, edgecolor="none", zorder=2)
    ax.set_xticks(x)
    ax.set_xticklabels([shorten_label(n) for n in names], rotation=45, ha="right", fontsize=7.5)
    ax.set_ylabel("Count")
    ax.set_yscale("log")
    ax.set_title("Static image vs dynamic retired ops", fontsize=11, color=INK, pad=8)
    _legend(ax, loc="upper left")
    fig.subplots_adjust(bottom=0.14)
    fig.savefig(out, dpi=180, facecolor="white")
    plt.close(fig)


def fig_loop_reuse_ratio(rows: list[dict], out: Path) -> None:
    names = [shorten_label(r["Kernel"]) for r in rows]
    static_s = np.array([ival_any(r, "Static slots filled (non-NOP)", "Instr Count") for r in rows], dtype=float)
    ops = np.array([ival_any(r, "Ops executed (dynamic)") or 0 for r in rows], dtype=float)
    with np.errstate(divide="ignore", invalid="ignore"):
        ratio = np.where(static_s > 0, ops / static_s, 0.0)
    order = np.argsort(ratio)
    fig, ax = plt.subplots(figsize=(8.5, max(4.5, 0.28 * len(names))))
    _style_axis(ax, grid_axis="x")
    y = np.arange(len(names))
    bar_colors = [BLUE if ratio[order[j]] >= 1.5 else BLUE_LIGHT for j in range(len(order))]
    bars = ax.barh(y, ratio[order], height=0.65, color=bar_colors, edgecolor="none", zorder=2)
    ax.set_yticks(y)
    ax.set_yticklabels([names[i] for i in order], fontsize=8)
    rmax = float(np.nanmax(ratio))
    for j, b in enumerate(bars):
        w = float(b.get_width())
        ax.text(w + 0.02 * max(rmax, 1.0), b.get_y() + b.get_height() / 2, f"{w:.2f}", va="center", fontsize=7, color=INK)
    ax.set_xlim(0, max(rmax * 1.12, 1.05))
    ax.set_xlabel("Ops executed / static slots filled")
    ax.axvline(1.0, color=ORANGE, linestyle="--", linewidth=1.1, alpha=0.95, label="1.0 (one pass)", zorder=1)
    ax.set_title("Loop reuse (dynamic / static)", fontsize=11, color=INK, pad=8)
    _legend(ax, loc="lower right")
    fig.subplots_adjust(left=0.28)
    fig.savefig(out, dpi=180, facecolor="white")
    plt.close(fig)


def fig_ops_per_packet(rows: list[dict], out: Path) -> None:
    names = [shorten_label(r["Kernel"]) for r in rows]
    ops = np.array([ival_any(r, "Ops executed (dynamic)") for r in rows], dtype=float)
    pex = np.array([ival(r, "Packets executed") for r in rows], dtype=float)
    with np.errstate(divide="ignore", invalid="ignore"):
        eff = np.where(pex > 0, ops / pex, 0.0)
    order = np.argsort(eff)
    fig, ax = plt.subplots(figsize=(8.5, max(4.5, 0.28 * len(names))))
    _style_axis(ax, grid_axis="x")
    y = np.arange(len(names))
    ax.barh(y, eff[order], height=0.65, color=BLUE, alpha=0.92, edgecolor="none", zorder=2)
    ax.set_yticks(y)
    ax.set_yticklabels([names[i] for i in order], fontsize=8)
    ax.set_xlabel("Ops retired per packet fetch")
    xmax = float(np.clip(max(eff.max() * 1.08, 1.05), 0.05, 1.15))
    ax.set_xlim(0, xmax)
    ax.axvline(1.0, color=ORANGE, linestyle="--", linewidth=1.1, label="1.0", zorder=1)
    ax.set_title("Packet efficiency", fontsize=11, color=INK, pad=8)
    fig.text(0.5, 0.02, "Low values → NOP-heavy packets (e.g. --latency static stalls).", ha="center", fontsize=7.5, color="#64748b")
    _legend(ax, loc="lower right")
    fig.subplots_adjust(left=0.28, bottom=0.12)
    fig.savefig(out, dpi=180, facecolor="white")
    plt.close(fig)


def fig_arithmetic_intensity(rows: list[dict], out: Path) -> None:
    names = [shorten_label(r["Kernel"]) for r in rows]
    ai = np.array([fval(r, "AI (load+store)") for r in rows])
    order = np.argsort(ai)
    fig, ax = plt.subplots(figsize=(8.5, max(4.5, 0.28 * len(names))))
    _style_axis(ax, grid_axis="x")
    y = np.arange(len(names))
    bars = ax.barh(y, ai[order], height=0.65, color=BLUE_MID, alpha=0.92, edgecolor="none", zorder=2)
    ax.set_yticks(y)
    ax.set_yticklabels([names[i] for i in order], fontsize=8)
    ax.set_xlabel("FLOPs / bytes loaded (GMEM→SCPAD only)")
    ax.set_xscale("log")
    ax.set_title("Arithmetic intensity", fontsize=11, color=INK, pad=8)
    for j, b in enumerate(bars):
        w = float(ai[order[j]])
        if not np.isfinite(w) or w <= 0:
            continue
        ax.text(w * 1.08, b.get_y() + b.get_height() / 2, f"{w:.3g}", va="center", fontsize=7, color=INK)
    lo, hi = ax.get_xlim()
    ax.set_xlim(lo, hi * 1.2)
    fig.subplots_adjust(left=0.28, bottom=0.1)
    fig.savefig(out, dpi=180, facecolor="white")
    plt.close(fig)


def fig_layernorm_latency_vs_sequential(raw_rows: list[dict], out: Path) -> None:
    """Uses original CSV kernel names (before plot relabel)."""
    by = {r.get("Kernel", "").strip(): r for r in raw_rows}
    g_key, s_key = "layernorm (latency)", "layernorm (sequential)"
    if g_key not in by or s_key not in by:
        print("[plot] skip layernorm_latency_vs_sequential.png: missing latency or sequential row")
        return
    g, s = by[g_key], by[s_key]
    fig, axes = plt.subplots(1, 3, figsize=(10.8, 4.35))
    metrics: list[tuple[str, float, float, str]] = [
        (
            "Static packet rows",
            float(ival_any(g, "Static packet rows", "Packet")),
            float(ival_any(s, "Static packet rows", "Packet")),
            "count",
        ),
        (
            "Packets executed",
            float(ival(g, "Packets executed")),
            float(ival(s, "Packets executed")),
            "count",
        ),
        (
            "Packet slot util. %",
            fval(g, "Packet Slot Util. %"),
            fval(s, "Packet Slot Util. %"),
            "%",
        ),
    ]
    cats = ["layernorm latency", "layernorm sequential"]
    cols = [BLUE, ORANGE]
    for ax, (title, vg, vs, yu) in zip(axes, metrics):
        _style_axis(ax, grid_axis="y")
        bars = ax.bar(cats, [vg, vs], color=cols, edgecolor="none", zorder=2, width=0.55)
        if yu == "%":
            _annotate_vertical_bars_inside(ax, bars, [vg, vs], value_fmt="{:.1f}", colors=cols)
        else:
            _annotate_vertical_bars_inside(ax, bars, [vg, vs], colors=cols)
        ax.set_title(title, fontsize=10, color=INK, pad=6)
        ax.tick_params(axis="x", rotation=12)
        if yu == "%":
            ax.set_ylabel("%")
        else:
            ax.set_ylabel("Count")
    fig.suptitle("Layernorm --latency vs layernorm sequential", fontsize=12, color=INK, y=1.0)
    fig.text(
        0.5,
        0.01,
        "Same layernorm math; FLOPs and DMA bytes should match. Latency: DAG greedy_pack with static stall rows. Sequential: asm order.",
        ha="center",
        fontsize=7.5,
        color="#64748b",
    )
    fig.subplots_adjust(bottom=0.2, wspace=0.38, top=0.88, left=0.06, right=0.99)
    fig.savefig(out, dpi=180, facecolor="white")
    plt.close(fig)


def fig_static_packet_rows_vs_executed(rows: list[dict], out: Path) -> None:
    names = [r["Kernel"] for r in rows]
    spr = np.array([ival_any(r, "Static packet rows", "Packet") for r in rows], dtype=float)
    pex = np.array([ival(r, "Packets executed") for r in rows], dtype=float)
    x = np.arange(len(names))
    w = 0.36
    fig, ax = plt.subplots(figsize=(12, 5.0))
    _style_axis(ax, grid_axis="y")
    ax.bar(x - w / 2, spr, w, label="Static packet rows", color=BLUE_LIGHT, edgecolor="none", zorder=2)
    ax.bar(x + w / 2, pex, w, label="Packets executed", color=ORANGE, alpha=0.88, edgecolor="none", zorder=2)
    ax.set_xticks(x)
    ax.set_xticklabels([shorten_label(n) for n in names], rotation=45, ha="right", fontsize=7.5)
    ax.set_ylabel("Count")
    ax.set_yscale("log")
    ax.set_title("Instruction image width vs dynamic fetches", fontsize=11, color=INK, pad=8)
    _legend(ax, loc="upper left")
    fig.subplots_adjust(bottom=0.14)
    fig.savefig(out, dpi=180, facecolor="white")
    plt.close(fig)


def fig_scheduling_metrics(rows: list[dict[str, str]], out: Path) -> None:
    """Unfiltered CSV rows: static slot utilization and static packet rows per dynamic op retired.

    Top: ``Packet Slot Util. %`` from the CSV (static image). Bottom: ``Static packet rows`` /
    ``Ops executed (dynamic)`` — not ``Packets executed``; the denominator is dynamic ops retired
    (``assembly_instructions_executed`` / ``instructions_executed`` in the perf dump), same as
    ``collect_kernel_metrics.perf_to_row``.
    """
    names: list[str] = []
    util: list[float] = []
    overhead: list[str] = []
    ratio: list[float] = []

    for r in rows:
        k = r.get("Kernel", "").strip()
        try:
            spr = float(r["Static packet rows"])
            ops = float(r["Ops executed (dynamic)"])
            u = float(r["Packet Slot Util. %"])
        except (KeyError, ValueError):
            continue
        names.append(k)
        util.append(u)
        ro = spr / ops if ops else 0.0
        ratio.append(ro)
        if "layernorm (latency)" in k:
            overhead.append("DAG+pack+latency bubbles")
        elif "dag-pack" in k:
            overhead.append("conv dag-pack (structural PO)")
        elif k == "layernorm (sequential)" or (u >= 24.99 and u <= 25.01 and ro >= 0.99):
            overhead.append("linear / default ~25%")
        else:
            overhead.append("other")

    if not names:
        print("[plot] skip scheduling_metrics: no valid rows")
        return

    colors = {
        "DAG+pack+latency bubbles": "#c026d3",
        "conv dag-pack (structural PO)": "#059669",
        "linear / default ~25%": "#64748b",
        "other": "#ea580c",
    }
    c_list = [colors.get(o, "#64748b") for o in overhead]

    fig, (ax0, ax1) = plt.subplots(2, 1, figsize=(11, 7), sharex=True)
    _style_axis(ax0, grid_axis="y")
    _style_axis(ax1, grid_axis="y")
    x = range(len(names))
    ax0.bar(x, util, color=c_list, edgecolor="white", linewidth=0.5)
    ax0.axhline(25.0, color="#94a3b8", linestyle="--", linewidth=1, label="25% (1 op / 4-slot row)")
    ax0.set_ylabel("Packet slot util. % (static)")
    ax0.set_title("Static scheduling metrics by kernel (from kernel_metrics.csv)")
    ax0.legend(loc="upper right", fontsize=8)
    umax = max(util) if util else 0.0
    ax0.set_ylim(0, max(umax * 1.15, 1e-6))

    ax1.bar(x, ratio, color=c_list, edgecolor="white", linewidth=0.5)
    ax1.axhline(1.0, color="#94a3b8", linestyle="--", linewidth=1, label="1.0 (one static row per dynamic op)")
    ax1.set_ylabel("Static packet rows / dynamic ops")
    ax1.set_xlabel("Kernel")
    ax1.legend(loc="upper right", fontsize=8)

    ax1.set_xticks(list(x))
    ax1.set_xticklabels(names, rotation=55, ha="right", fontsize=7)

    handles = [Patch(facecolor=colors[k], label=k) for k in colors]
    fig.legend(handles=handles, loc="lower center", ncol=2, fontsize=8, frameon=False)
    plt.subplots_adjust(bottom=0.28, top=0.92)
    out.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(out, dpi=180, facecolor="white")
    plt.close(fig)


def _variant_fig_combined(
    rows: list[dict],
    labels: list[str],
    title: str,
    subtitle: str,
    out_paths: list[Path],
) -> None:
    sub = [r for r in rows if r["Kernel"] in labels]
    if len(sub) != len(labels):
        found = {r["Kernel"] for r in sub}
        missing = [k for k in labels if k not in found]
        raise SystemExit(f"Missing kernels in CSV: {missing}")
    order_map = {k: i for i, k in enumerate(labels)}
    sub.sort(key=lambda r: order_map[r["Kernel"]])
    kernels = [r["Kernel"] for r in sub]
    pex = np.array([ival(r, "Packets executed") for r in sub], dtype=float)
    st = np.array([ival_any(r, "Static slots filled (non-NOP)", "Instr Count") for r in sub], dtype=float)

    x = np.arange(len(kernels))
    xtick = [_kernel_display_xtick(k) for k in kernels]
    cols_p = [BLUE] + [ORANGE] * (len(kernels) - 1)
    cols_s = [BLUE_LIGHT] + [ORANGE_LIGHT] * (len(kernels) - 1)

    fig, (ax0, ax1) = plt.subplots(2, 1, figsize=(7.5, 6.35), sharex=True)
    for ax in (ax0, ax1):
        _style_axis(ax, grid_axis="y")

    bars_p = ax0.bar(x, pex, width=0.62, color=cols_p, edgecolor="none", alpha=0.92, zorder=2)
    ax0.set_ylabel("Packets executed", color=INK)
    ax0.set_title(title, fontsize=11, color=INK, pad=6)
    _annotate_vertical_bars_inside(ax0, bars_p, pex, colors=cols_p)

    bars_s = ax1.bar(x, st, width=0.62, color=cols_s, edgecolor="none", alpha=0.92, zorder=2)
    ax1.set_ylabel("Static slots (non-NOP)", color=INK)
    ax1.set_xticks(x)
    ax1.set_xticklabels(xtick, fontsize=8.5)
    _annotate_vertical_bars_inside(ax1, bars_s, st, colors=cols_s)

    fig.text(0.5, 0.02, subtitle, ha="center", fontsize=7.5, color="#64748b")
    fig.subplots_adjust(bottom=0.12, hspace=0.26, top=0.93)
    for p in out_paths:
        fig.savefig(p, dpi=180, facecolor="white")
    plt.close(fig)


def fig_variant_compare(
    rows: list[dict],
    labels: list[str],
    *,
    title: str,
    foot_caption: str,
    out: Path,
    missing_name: str,
) -> None:
    """Grouped packets + static slots vs twin-axis AI; same layout as conv/gemm compare."""
    sub = [r for r in rows if r["Kernel"] in labels]
    if len(sub) != len(labels):
        print(f"[plot] skip {out.name}: missing row(s) for {missing_name}")
        return
    order_map = {k: i for i, k in enumerate(labels)}
    sub.sort(key=lambda r: order_map[r["Kernel"]])
    pex = np.array([ival(r, "Packets executed") for r in sub], dtype=float)
    st = np.array([ival_any(r, "Static slots filled (non-NOP)", "Instr Count") for r in sub], dtype=float)
    flops = np.array([ival(r, "FLOPs (total)") for r in sub], dtype=float)
    bl = np.array([ival(r, "Bytes Loaded") for r in sub], dtype=float)
    bw = np.array([ival(r, "Bytes Written") for r in sub], dtype=float)
    with np.errstate(divide="ignore", invalid="ignore"):
        denom = bl + bw
        ai = np.where(denom > 0, flops / denom, np.nan)

    x = np.arange(len(labels))
    w = 0.32 if len(labels) >= 3 else 0.36
    fig, ax = plt.subplots(figsize=(8.0, 4.85) if len(labels) >= 3 else (7.6, 4.85))
    _style_axis(ax, grid_axis="y")
    c_p = [BLUE] + [ORANGE] * (len(labels) - 1)
    c_s = [BLUE_LIGHT] + [ORANGE_LIGHT] * (len(labels) - 1)
    b1 = ax.bar(x - w / 2, pex, w, color=c_p, edgecolor="none", alpha=0.92, zorder=2)
    b2 = ax.bar(x + w / 2, st, w, color=c_s, edgecolor="none", alpha=0.92, zorder=2)
    ax.set_xticks(x)
    ax.set_xticklabels([_kernel_display_xtick(k) for k in labels], fontsize=8.5)
    ax.set_ylabel("Count")
    ytop = max(float(pex.max()), float(st.max())) * 1.12
    ax.set_ylim(0, ytop)

    _annotate_vertical_bars_inside(ax, b1, pex, colors=c_p)
    _annotate_vertical_bars_inside(ax, b2, st, colors=c_s)

    ax2 = ax.twinx()
    ax2.set_axisbelow(True)
    ax2.patch.set_visible(False)
    ax2.grid(False)
    ax2.plot(x, ai, "s-", color=INK, lw=1.35, ms=8, mfc=ORANGE_LIGHT, mec=ORANGE, zorder=5)
    ax2.set_ylabel("AI (FLOPs / (load+write))", color=INK)
    ax2.tick_params(axis="y", colors=INK)
    ai_max = float(np.nanmax(ai)) if np.any(np.isfinite(ai)) else 0.0
    ax2.set_ylim(0, max(ai_max * 1.2, 1e-12))
    for i, xi in enumerate(x):
        if np.isfinite(ai[i]):
            ax2.annotate(
                f"{ai[i]:.3g}",
                (xi, ai[i]),
                xytext=(0, 10),
                textcoords="offset points",
                ha="center",
                fontsize=7.5,
                color=INK,
                zorder=6,
            )

    ax.set_title(title, fontsize=11, color=INK, pad=8)
    h = [
        Patch(facecolor=BLUE, edgecolor="none", label="Packets executed"),
        Patch(facecolor=BLUE_LIGHT, edgecolor="none", label="Static slots filled"),
        Line2D([0], [0], color=ORANGE, marker="s", linestyle="-", markersize=7, label="AI (load+store)"),
    ]
    fig.subplots_adjust(bottom=0.36, top=0.9)
    fig.legend(
        handles=h,
        loc="upper center",
        ncol=3,
        bbox_to_anchor=(0.5, 0.28),
        fontsize=8,
        frameon=True,
        edgecolor="#94a3b8",
    )
    fig.text(0.5, 0.06, foot_caption, ha="center", fontsize=7, color="#64748b")
    fig.savefig(out, dpi=180, facecolor="white")
    plt.close(fig)


def main() -> None:
    ap = argparse.ArgumentParser(description="Individual kernel metric figures (blue/orange, filtered rows).")
    ap.add_argument("--csv", type=Path, default=Path("out/kernel_metrics.csv"))
    ap.add_argument("--out-dir", type=Path, default=Path("out/plots"))
    args = ap.parse_args()
    raw = load_rows(args.csv)
    if not raw:
        raise SystemExit("No rows in CSV")
    args.out_dir.mkdir(parents=True, exist_ok=True)
    o = args.out_dir

    fig_layernorm_latency_vs_sequential(raw, o / "layernorm_latency_vs_sequential.png")
    fig_scheduling_metrics(raw, o / "scheduling_metrics.png")

    rows = prepare_plot_rows(raw)

    fig_work_vs_cost(rows, o / "work_vs_cost.png")
    fig_memory_vs_compute(rows, o / "memory_vs_compute.png")
    fig_compute_composition(rows, o / "compute_composition.png")
    fig_static_vs_dynamic_ops(rows, o / "static_vs_dynamic_ops.png")
    fig_loop_reuse_ratio(
        prepare_plot_rows(raw, include_gemms_baseline=True),
        o / "loop_reuse_ratio.png",
    )
    fig_ops_per_packet(rows, o / "ops_per_packet.png")
    fig_arithmetic_intensity(rows, o / "arithmetic_intensity.png")
    fig_static_packet_rows_vs_executed(rows, o / "static_packet_rows_vs_executed.png")

    fig_variant_compare(
        rows,
        ["conv", "conv pipelined", "conv pipelined unroll"],
        title="Conv variant kernels (static vs runtime)",
        foot_caption=(
            "AI = FLOPs / (bytes loaded + bytes written). Same im2col: M=32, K_flat=27, K=4. "
            "Blue = baseline conv; orange = pipelined variants."
        ),
        out=o / "conv_compare.png",
        missing_name="conv variants",
    )
    fig_variant_compare(
        raw,
        ["gemms", "gemms pipelined", "gemms pipelined loop unroll"],
        title="GEMM variant kernels (static vs runtime)",
        foot_caption=(
            "AI = FLOPs / (bytes loaded + bytes written). 32×32 tiles, same problem. "
            "Blue = baseline gemms; orange = pipelined then loop-unrolled pipeline. % vs first bar."
        ),
        out=o / "gemm_compare.png",
        missing_name="GEMM variants",
    )

    _variant_fig_combined(
        raw,
        ["gemms", "gemms pipelined", "gemms pipelined loop unroll"],
        "GEMM variants (packets and static)",
        "32×32 tiles. Order: baseline gemms, pipelined, loop-unrolled. % vs first bar.",
        [o / "gemm_variants_packets_indexed.png", o / "gemm_variants_static_slots.png"],
    )
    _variant_fig_combined(
        rows,
        ["conv", "conv pipelined", "conv pipelined unroll"],
        "Conv variants (packets and static)",
        "im2col M=32, K_flat=27, K=4. First bar = conv; % vs first bar.",
        [o / "conv_variants_packets_indexed.png", o / "conv_variants_static_slots.png"],
    )

    fig_static_packet_rows_vs_executed(rows, o / "static_vs_dynamic.png")

    print("Wrote individual figures to:", o.resolve())


if __name__ == "__main__":
    main()
