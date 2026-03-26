from __future__ import annotations

import argparse
import csv
import json
import re
import subprocess
from pathlib import Path


CONFIGS = [
    {"name": "cfg1_small", "N": 1, "H": 4, "W": 4, "C": 3, "K": 4, "R": 3, "S": 3, "stride": 1, "pad": 0},
    {"name": "cfg2_med", "N": 1, "H": 5, "W": 5, "C": 3, "K": 8, "R": 3, "S": 3, "stride": 1, "pad": 0},
    {"name": "cfg3_medplus", "N": 1, "H": 6, "W": 6, "C": 3, "K": 8, "R": 3, "S": 3, "stride": 1, "pad": 0},
    {"name": "cfg4_large", "N": 1, "H": 7, "W": 7, "C": 3, "K": 8, "R": 3, "S": 3, "stride": 1, "pad": 0},
    {"name": "cfg5_batch2", "N": 2, "H": 5, "W": 5, "C": 3, "K": 8, "R": 3, "S": 3, "stride": 1, "pad": 0},
]


def run_cmd(cmd: list[str], cwd: Path) -> str:
    p = subprocess.run(cmd, cwd=str(cwd), text=True, capture_output=True)
    if p.returncode != 0:
        raise RuntimeError(f"Command failed ({' '.join(cmd)}):\n{p.stdout}\n{p.stderr}")
    return p.stdout


def parse_rel_err(validate_stdout: str) -> tuple[float, bool]:
    m = re.search(r"rel_err=([0-9eE+\-.]+)\)", validate_stdout)
    rel_err = float(m.group(1)) if m else float("nan")
    status_match = re.search(r"^(MATCH|MISMATCH)\b", validate_stdout, flags=re.MULTILINE)
    is_match = (status_match.group(1) == "MATCH") if status_match else False
    return rel_err, is_match


def run_one_kernel(emulator_dir: Path, build_script: str, cfg: dict, tag: str) -> dict:
    out_in = f"{cfg['name']}_{tag}.in"
    metrics_json = emulator_dir / "out" / f"{cfg['name']}_{tag}_metrics.json"
    args = [
        "--N", str(cfg["N"]),
        "--H", str(cfg["H"]),
        "--W", str(cfg["W"]),
        "--C", str(cfg["C"]),
        "--K", str(cfg["K"]),
        "--R", str(cfg["R"]),
        "--S", str(cfg["S"]),
        "--stride", str(cfg["stride"]),
        "--pad", str(cfg["pad"]),
    ]

    run_cmd(["python3", build_script, "-o", out_in, *args], emulator_dir)
    run_cmd(
        ["python3", "run.py", "--input_file", out_in, "--metrics_json", str(metrics_json.relative_to(emulator_dir))],
        emulator_dir,
    )
    vout = run_cmd(
        ["python3", "validate_conv_vs_pytorch.py", "--mem", "out/output_mem.out", *args],
        emulator_dir,
    )
    rel_err, match = parse_rel_err(vout)

    metrics = json.loads(metrics_json.read_text())
    whole = metrics["whole_run"]
    conv = metrics["conv_region"]
    ho = (cfg["H"] + 2 * cfg["pad"] - cfg["R"]) // cfg["stride"] + 1
    wo = (cfg["W"] + 2 * cfg["pad"] - cfg["S"]) // cfg["stride"] + 1
    m = cfg["N"] * ho * wo
    k_flat = cfg["R"] * cfg["S"] * cfg["C"]

    return {
        "kernel": tag,
        "config": cfg["name"],
        "N": cfg["N"], "H": cfg["H"], "W": cfg["W"], "C": cfg["C"], "K": cfg["K"], "R": cfg["R"], "S": cfg["S"],
        "stride": cfg["stride"], "pad": cfg["pad"],
        "M": m, "K_flat": k_flat, "Ho": ho, "Wo": wo,
        "match": match,
        "rel_err": rel_err,
        "whole_instr": whole["instr_retired"],
        "whole_ops": whole["ops_modeled"],
        "whole_cycles_est": whole["estimated_cycles"],
        "whole_bytes_loaded": whole["bytes_loaded"],
        "whole_bytes_stored": whole["bytes_stored"],
        "whole_ai_load": whole["arithmetic_intensity_loaded"],
        "conv_instr": conv["instr_retired"],
        "conv_ops": conv["ops_modeled"],
        "conv_cycles_est": conv["estimated_cycles"],
        "conv_bytes_loaded": conv["bytes_loaded"],
        "conv_bytes_stored": conv["bytes_stored"],
        "conv_ai_load": conv["arithmetic_intensity_loaded"],
    }


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--output_csv", type=Path, default=Path("out/conv_scaling_results.csv"))
    ap.add_argument("--output_md", type=Path, default=Path("out/conv_scaling_summary.md"))
    args = ap.parse_args()

    emulator_dir = Path(__file__).resolve().parent
    rows: list[dict] = []
    for cfg in CONFIGS:
        rows.append(run_one_kernel(emulator_dir, "build_conv.py", cfg, "baseline"))
        rows.append(run_one_kernel(emulator_dir, "build_conv_pipelined.py", cfg, "pipelined"))

    args.output_csv.parent.mkdir(parents=True, exist_ok=True)
    with args.output_csv.open("w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
        w.writeheader()
        w.writerows(rows)

    # Compact markdown summary table (conv-region focus).
    lines = [
        "# Conv Functional Scaling Summary",
        "",
        "| cfg | kernel | M | K_flat | match | rel_err | conv_instr | conv_cycles_est | conv_bytes_loaded | conv_ai_load |",
        "|---|---|---:|---:|---|---:|---:|---:|---:|---:|",
    ]
    for r in rows:
        lines.append(
            f"| {r['config']} | {r['kernel']} | {r['M']} | {r['K_flat']} | "
            f"{'MATCH' if r['match'] else 'MISMATCH'} | {r['rel_err']:.6e} | "
            f"{r['conv_instr']} | {r['conv_cycles_est']:.1f} | {r['conv_bytes_loaded']} | {r['conv_ai_load']:.6f} |"
        )
    args.output_md.write_text("\n".join(lines) + "\n")

    print(f"Wrote {args.output_csv}")
    print(f"Wrote {args.output_md}")


if __name__ == "__main__":
    main()
