from __future__ import annotations

import argparse
import csv
from pathlib import Path


NOP_WORD = "00000000002F"


def analyze_image(path: Path) -> dict:
    packet_count = 0
    total_slots = 0
    nop_slots = 0
    non_nop_slots = 0
    hist = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0}

    with path.open() as f:
        for line in f:
            s = line.strip()
            if not s:
                continue
            su = s.upper()
            if su.startswith("DATA MEM") or su.startswith(".DATA"):
                break
            if ":" not in s:
                continue
            _, rhs = s.split(":", 1)
            words = [w.strip().upper() for w in rhs.strip().split()[:4]]
            words = [w for w in words if len(w) == 12]
            if not words:
                continue
            packet_count += 1
            valid = 0
            for w in words:
                total_slots += 1
                if w == NOP_WORD:
                    nop_slots += 1
                else:
                    non_nop_slots += 1
                    valid += 1
            hist[valid] = hist.get(valid, 0) + 1

    util = (100.0 * non_nop_slots / total_slots) if total_slots else 0.0
    return {
        "image": path.name,
        "packet_count": packet_count,
        "total_slots": total_slots,
        "non_nop_slots": non_nop_slots,
        "nop_slots": nop_slots,
        "util_percent": util,
        "packet_hist": hist,
    }


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--images", nargs="+", default=["conv_sa.in", "conv_sa_pipelined.in"])
    ap.add_argument("--out_csv", type=Path, default=Path("out/conv_packet_fill.csv"))
    ap.add_argument("--out_md", type=Path, default=Path("out/conv_packet_fill_report.md"))
    args = ap.parse_args()

    root = Path(__file__).resolve().parent
    rows = [analyze_image(root / img) for img in args.images]

    args.out_csv.parent.mkdir(parents=True, exist_ok=True)
    with args.out_csv.open("w", newline="") as f:
        writer = csv.writer(f)
        writer.writerow(
            [
                "image",
                "packet_count",
                "total_slots",
                "non_nop_slots",
                "nop_slots",
                "util_percent",
                "packets_0_useful",
                "packets_1_useful",
                "packets_2_useful",
                "packets_3_useful",
                "packets_4_useful",
            ]
        )
        for r in rows:
            h = r["packet_hist"]
            writer.writerow(
                [
                    r["image"],
                    r["packet_count"],
                    r["total_slots"],
                    r["non_nop_slots"],
                    r["nop_slots"],
                    f"{r['util_percent']:.4f}",
                    h.get(0, 0),
                    h.get(1, 0),
                    h.get(2, 0),
                    h.get(3, 0),
                    h.get(4, 0),
                ]
            )

    lines = []
    lines.append("# Conv Packet Fill Report")
    lines.append("")
    lines.append("`functional_sim` packet occupancy for generated conv images.")
    lines.append("")
    lines.append("| image | packets | total_slots | non_nop_slots | nop_slots | utilization_% |")
    lines.append("|---|---:|---:|---:|---:|---:|")
    for r in rows:
        lines.append(
            f"| {r['image']} | {r['packet_count']} | {r['total_slots']} | "
            f"{r['non_nop_slots']} | {r['nop_slots']} | {r['util_percent']:.4f} |"
        )
    lines.append("")
    lines.append("## Packet histogram (useful instructions per 4-slot packet)")
    lines.append("")
    lines.append("| image | 0 useful | 1 useful | 2 useful | 3 useful | 4 useful |")
    lines.append("|---|---:|---:|---:|---:|---:|")
    for r in rows:
        h = r["packet_hist"]
        lines.append(
            f"| {r['image']} | {h.get(0,0)} | {h.get(1,0)} | {h.get(2,0)} | {h.get(3,0)} | {h.get(4,0)} |"
        )
    lines.append("")
    lines.append("Interpretation: utilization near 25% indicates mostly 1 real instruction + 3 NOPs per packet.")
    args.out_md.write_text("\n".join(lines) + "\n")

    print(f"Wrote {args.out_csv}")
    print(f"Wrote {args.out_md}")


if __name__ == "__main__":
    main()
