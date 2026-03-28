from __future__ import annotations

import argparse
import csv
import hashlib
from pathlib import Path


NOP_WORD = "00000000002f"


def parse_perf_file(path: Path) -> dict[str, float]:
    out: dict[str, float] = {}
    for line in path.read_text().splitlines():
        if ":" not in line:
            continue
        k, v = [x.strip() for x in line.split(":", 1)]
        try:
            out[k] = float(v)
        except ValueError:
            continue
    return out


def parse_instr_image(path: Path) -> dict[str, float | str]:
    packets = 0
    slots = 0
    useful = 0
    words: list[str] = []

    for line in path.read_text().splitlines():
        s = line.strip()
        if s == ".data":
            break
        if ":" not in s:
            continue
        left, right = [x.strip() for x in s.split(":", 1)]
        if len(left) != 8:
            continue
        toks = right.split()
        if len(toks) != 4:
            continue
        packets += 1
        for t in toks:
            if len(t) == 12:
                w = t.lower()
                slots += 1
                words.append(w)
                if w != NOP_WORD:
                    useful += 1

    digest = hashlib.sha256("".join(words).encode()).hexdigest()[:16]
    util = useful / slots if slots else 0.0
    return {
        "packets": packets,
        "slots": slots,
        "useful_slots": useful,
        "slot_utilization": util,
        "instr_sha16": digest,
    }


def parse_data_mem(path: Path) -> dict[int, int]:
    mem: dict[int, int] = {}
    in_data = False
    for line in path.read_text().splitlines():
        s = line.strip()
        if s.upper().startswith("DATA MEM"):
            in_data = True
            continue
        if not in_data or ":" not in s:
            continue
        a, v = [x.strip() for x in s.split(":", 1)]
        try:
            mem[int(a, 16)] = int(v, 16)
        except ValueError:
            continue
    return mem


def ofmap_hash_from_mem(path: Path, ofmap_base: int, m_count: int, k_count: int) -> str:
    mem = parse_data_mem(path)
    vals: list[int] = []
    for i in range(m_count * k_count):
        vals.append(mem.get(ofmap_base + 2 * i, 0) & 0xFFFF)
    payload = "".join(f"{x:04x}" for x in vals).encode()
    return hashlib.sha256(payload).hexdigest()[:16]


def write_csv(rows: list[dict[str, str | int | float]], out_csv: Path) -> None:
    out_csv.parent.mkdir(parents=True, exist_ok=True)
    headers = [
        "variant",
        "packets",
        "useful_slots",
        "slot_utilization",
        "instr_sha16",
        "flops_total",
        "bytes_loaded",
        "arithmetic_intensity",
        "ofmap_sha16",
        "matches_baseline_ofmap",
    ]
    with out_csv.open("w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=headers)
        w.writeheader()
        for r in rows:
            w.writerow(r)


def write_markdown(rows: list[dict[str, str | int | float]], out_md: Path) -> None:
    out_md.parent.mkdir(parents=True, exist_ok=True)
    lines = [
        "# Conv pipeline proof summary",
        "",
        "| Variant | Packets | Useful Slots | Slot Util | Instr SHA16 | FLOPs | Bytes Loaded | AI | Ofmap SHA16 | Ofmap = Baseline |",
        "|---|---:|---:|---:|---|---:|---:|---:|---|---|",
    ]
    for r in rows:
        lines.append(
            f"| {r['variant']} | {r['packets']} | {r['useful_slots']} | {float(r['slot_utilization']):.3f} | "
            f"{r['instr_sha16']} | {float(r['flops_total']):.0f} | {float(r['bytes_loaded']):.0f} | "
            f"{float(r['arithmetic_intensity']):.6f} | {r['ofmap_sha16']} | {r['matches_baseline_ofmap']} |"
        )
    lines.extend(
        [
            "",
            "Notes:",
            "- Distinct instruction SHA values prove a different binary instruction stream.",
            "- Matching ofmap SHA values prove functional equivalence.",
            "- These perf counters are functional-sim counters, not cycle-accurate timing.",
            "",
        ]
    )
    out_md.write_text("\n".join(lines))


def write_plot(rows: list[dict[str, str | int | float]], out_png: Path) -> bool:
    try:
        import matplotlib.pyplot as plt  # type: ignore[import-not-found]
    except Exception:
        return False

    labels = [str(r["variant"]) for r in rows]
    packets = [int(r["packets"]) for r in rows]
    ais = [float(r["arithmetic_intensity"]) for r in rows]

    fig, axes = plt.subplots(1, 2, figsize=(10, 4))
    fig.suptitle("Conv pipeline proof (functional_sim)")

    axes[0].bar(labels, packets, color=["#2e7d32", "#43a047", "#66bb6a"])
    axes[0].set_title("Instruction packets")
    axes[0].set_ylabel("count")
    axes[0].grid(axis="y", alpha=0.25)

    axes[1].bar(labels, ais, color=["#1b5e20", "#2e7d32", "#43a047"])
    axes[1].set_title("Arithmetic intensity")
    axes[1].set_ylabel("flops / byte")
    axes[1].grid(axis="y", alpha=0.25)

    for ax in axes:
        ax.tick_params(axis="x", rotation=15)

    fig.tight_layout()
    out_png.parent.mkdir(parents=True, exist_ok=True)
    fig.savefig(out_png, dpi=180)
    plt.close(fig)
    return True


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out_csv", type=Path, default=Path("out/conv_pipeline_proof.csv"))
    ap.add_argument("--out_md", type=Path, default=Path("out/conv_pipeline_proof.md"))
    ap.add_argument("--out_png", type=Path, default=Path("out/conv_pipeline_proof.png"))
    ap.add_argument("--ofmap_base", type=lambda x: int(x, 0), default=0x3000)
    ap.add_argument("--M", type=int, default=4, help="Output rows (N*Ho*Wo)")
    ap.add_argument("--K", type=int, default=4, help="Output channels")
    args = ap.parse_args()

    variants = [
        {
            "name": "baseline",
            "instr": Path("tests/conv_sa.in"),
            "perf": Path("out/output_perf_baseline.out"),
            "mem": Path("out/output_mem_baseline.out"),
        },
        {
            "name": "pipelined",
            "instr": Path("tests/conv_sa_pipelined.in"),
            "perf": Path("out/output_perf_pipelined.out"),
            "mem": Path("out/output_mem_pipelined.out"),
        },
        {
            "name": "unrolled_pipelined",
            "instr": Path("tests/conv_sa_unrolled_pipelined.in"),
            "perf": Path("out/output_perf_unrolled.out"),
            "mem": Path("out/output_mem_unrolled.out"),
        },
    ]

    rows: list[dict[str, str | int | float]] = []
    baseline_hash = ""
    for v in variants:
        instr_stats = parse_instr_image(v["instr"])
        perf = parse_perf_file(v["perf"])
        ofmap_hash = ofmap_hash_from_mem(v["mem"], args.ofmap_base, args.M, args.K)
        if v["name"] == "baseline":
            baseline_hash = ofmap_hash

        rows.append(
            {
                "variant": v["name"],
                "packets": int(instr_stats["packets"]),
                "useful_slots": int(instr_stats["useful_slots"]),
                "slot_utilization": float(instr_stats["slot_utilization"]),
                "instr_sha16": str(instr_stats["instr_sha16"]),
                "flops_total": float(perf.get("flops_total", 0.0)),
                "bytes_loaded": float(perf.get("bytes_loaded", 0.0)),
                "arithmetic_intensity": float(perf.get("arithmetic_intensity", 0.0)),
                "ofmap_sha16": ofmap_hash,
                "matches_baseline_ofmap": "",
            }
        )

    for r in rows:
        r["matches_baseline_ofmap"] = "yes" if str(r["ofmap_sha16"]) == baseline_hash else "no"

    write_csv(rows, args.out_csv)
    write_markdown(rows, args.out_md)
    plotted = write_plot(rows, args.out_png)

    print(f"Wrote CSV: {args.out_csv}")
    print(f"Wrote MD : {args.out_md}")
    if plotted:
        print(f"Wrote PNG: {args.out_png}")
    else:
        print("PNG skipped (matplotlib unavailable).")


if __name__ == "__main__":
    main()
