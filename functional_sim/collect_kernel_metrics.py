#!/usr/bin/env python3
"""
Build each kernel .in, run the emulator once, and write a compact metrics table.

Semantics (read before interpreting Arithmetic Intensity):

  Bytes Loaded / Bytes Written — *only* BF16 bytes moved by sdma_load / sdma_store
  (GMEM <-> scratchpad). They do *not* include vreg.ld/st, scalar lw/sw, or reuse of
  data already in scratchpad. Kernels that load one tile then do many vector ops
  (e.g. softmax online) will show huge FLOPs per "byte loaded" — that is not a
  physical roofline; it means most compute is on on-chip state.

  FLOPs — model counters: scalar/vector ops add per-lane work; each gemm.vv counts
  2*32*32*32 MACs (one systolic tile) toward flops_matmul and flops_total even
  though the static ISA exposes one instruction per tile.

  Static packet rows / Slots / Static slots filled / Packet Slot Util. % — computed
  once from the whole scheduled instruction image (every instr-mem packet row).
  "Static packet rows" == floor(Slots/4) with packet_length=4; it is *not* dynamic.

  Static slots filled (non-NOP) — sum of non-nop.s instruction slots over that
  entire static image. It is *not* "instructions retired" and is not comparable
  to Static packet rows (rows vs slot count).

  Packets executed — how many times the main loop fetched and executed one PC
  packet (one instr-mem word = one packet of width packet_length). Loops re-fetch
  the same addresses, so this scales with dynamic control flow (often >> static rows).

  Ops executed (dynamic) — ``assembly_instructions_executed`` after run (one per
  non-nop.s op retired); ``instructions_executed`` is the same value in perf dumps.

  Packet metrics — static slot counts also populate ``packets_static_*`` and
  ``packet_slot_utilization_non_nop_packets_pct`` / ``packet_slot_utilization_executed_*``
  (see perf dump); the CSV below uses the compact static/dynamic columns only.

  Arithmetic Intensity = FLOPs_total / Bytes Loaded (DMA read bytes only).
  AI (load+store) = FLOPs_total / (Bytes Loaded + Bytes Written).

  Packing policy (default functional-sim / TA demos):
    **Structural / linear** emission is the default: ``assemble_file`` +
    ``emit_test_format`` (one assembled stmt per virtual row). Static slot metrics
    describe **legal packing density**, not cycles with SDMA or other long
    latencies materialized as NOP rows.

    User-facing modes (frozen; see functional_sim/README.md):
    - **Default:** linear / structural emission (correctness + static slot metrics).
    - **``--dag-pack``** (conv*): program-order wide packing + branch patch + BR10 preflight
      (no latency stall rows unless also ``--latency``).
    - **``--latency``** (branch-light kernels, or with ``--dag-pack`` on conv): experimental
      DAG ``ready`` times materialized as empty packet rows — can break BR10 on loops.

    Hidden deprecated CLI aliases still accepted: ``--graph`` (same as ``--latency``),
    ``--no-graph`` (redundant with default; errors if combined with ``--latency``).

    Research direction: basic-block–local DAG packing without stretching loop
    back-edges; model long latency in the simulator timeline, not static instr-mem.

Usage (from repo root functional_sim):
  PYTHONPATH=/path/to/atalla:/path/to/atalla/functional_sim \\
    python3 collect_kernel_metrics.py
  (writes out/kernel_metrics.csv by default; override with --csv PATH)
"""
from __future__ import annotations

import argparse
import csv
import json
import os
import subprocess
import sys
import tempfile
from pathlib import Path
from typing import Any

REPO_ROOT = Path(__file__).resolve().parent
ATALLA_ROOT = REPO_ROOT.parent

CSV_FIELDS = [
    "Kernel",
    "FLOPs (total)",
    "FLOPs matmul",
    "Static slots filled (non-NOP)",
    "Bytes Loaded",
    "Bytes Written",
    "Static packet rows",
    "Slots",
    "Packet Slot Util. %",
    "Packets executed",
    "Ops executed (dynamic)",
    "Arithmetic Intensity",
    "AI (load+store)",
]


def _pythonpath_env() -> dict[str, str]:
    env = os.environ.copy()
    extra = os.pathsep.join([str(ATALLA_ROOT), str(REPO_ROOT)])
    env["PYTHONPATH"] = extra + (os.pathsep + env["PYTHONPATH"] if env.get("PYTHONPATH") else "")
    return env


def _ensure_import_path() -> None:
    for p in (str(REPO_ROOT), str(ATALLA_ROOT)):
        if p not in sys.path:
            sys.path.insert(0, p)


def parse_perf_text(text: str) -> dict[str, float]:
    out: dict[str, float] = {}
    for line in text.splitlines():
        line = line.strip()
        if not line or ":" not in line:
            continue
        k, _, rest = line.partition(":")
        k, rest = k.strip(), rest.strip()
        try:
            out[k] = float(rest)
        except ValueError:
            pass
    return out


def run_build(script: str, out_in: Path, extra: list[str]) -> tuple[int, str]:
    cmd = [sys.executable, str(REPO_ROOT / script), "-o", str(out_in), *extra]
    p = subprocess.run(
        cmd,
        cwd=str(REPO_ROOT),
        check=False,
        env=_pythonpath_env(),
        capture_output=True,
        text=True,
    )
    err = (p.stderr or "") + (p.stdout or "")
    return p.returncode, err[-4000:]


def emulate_to_perf(in_path: Path, perf_path: Path, packet_length: int = 4) -> tuple[int, str]:
    _ensure_import_path()
    from src.components.execute import ExecuteUnit
    from src.components.scpad import Scratchpad
    from src.components.scalar_register_file import ScalarRegisterFile
    from src.components.vector_register_file import VectorRegisterFile
    from src.functional_sim import run
    from src.misc.memory import Memory

    mem = Memory(str(in_path))
    sregs = ScalarRegisterFile()
    mregs = ScalarRegisterFile(num_regs=16)
    vregs = VectorRegisterFile()
    sp0 = Scratchpad(slots_per_bank=32)
    sp1 = Scratchpad(slots_per_bank=32)
    eu = ExecuteUnit()
    perf_path.parent.mkdir(parents=True, exist_ok=True)
    junk = perf_path.with_suffix(".junk.out")
    try:
        run(
            mem,
            sregs,
            mregs,
            vregs,
            sp0,
            sp1,
            eu,
            0,
            packet_length,
            str(junk.with_suffix(".mem.out")),
            str(junk.with_suffix(".sreg.out")),
            str(junk.with_suffix(".vreg.out")),
            str(junk.with_suffix(".mreg.out")),
            str(junk.with_suffix(".sp0.out")),
            str(junk.with_suffix(".sp1.out")),
            str(perf_path),
            debug=False,
        )
    except Exception as e:
        return 1, f"{type(e).__name__}: {e}"
    return 0, ""


def perf_to_row(kernel: str, perf: dict[str, float]) -> dict[str, Any]:
    slots_total = int(perf.get("packet_slots_total", 0))
    filled = int(perf.get("packet_slots_filled", 0))
    pkt = slots_total // 4 if slots_total else 0
    util = perf.get("packet_slot_utilization_pct", 0.0)
    ops_dyn = int(perf.get("assembly_instructions_executed", perf.get("instructions_executed", 0)))
    return {
        "Kernel": kernel,
        "FLOPs (total)": int(perf.get("flops_total", 0)),
        "FLOPs matmul": int(perf.get("flops_matmul", 0)),
        "Static slots filled (non-NOP)": filled,
        "Bytes Loaded": int(perf.get("bytes_loaded", 0)),
        "Bytes Written": int(perf.get("bytes_written", 0)),
        "Static packet rows": pkt,
        "Slots": slots_total,
        "Packet Slot Util. %": round(util, 4),
        "Packets executed": int(perf.get("packets_executed", 0)),
        "Ops executed (dynamic)": ops_dyn,
        "Arithmetic Intensity": round(perf.get("arithmetic_intensity", 0.0), 6),
        "AI (load+store)": round(perf.get("arithmetic_intensity_load_store", 0.0), 6),
    }


# (label, build_script, extra_cli_args)
# Tile sizes default to 32×32 where ISA uses max index 31 in SDMA metadata.
KERNEL_SPECS: list[tuple[str, str, list[str]]] = [
    ("layernorm (latency)", "build_layernorm_param.py", ["--latency"]),
    ("layernorm (sequential)", "build_layernorm_param.py", []),
    ("softmax", "build_softmax.py", []),
    ("softmax online", "build_softmax_online.py", []),
    ("relu", "build_relu.py", []),
    ("sigmoid", "build_sigmoid.py", []),
    ("gemm", "build_gemm.py", []),
    ("gemm tiled", "build_gemm_tiled.py", []),
    ("conv tiled", "build_conv_tiled.py", []),
    ("gemms", "build_gemms.py", []),
    ("gemms function", "build_gemms_function.py", []),
    ("gemms pipelined", "build_gemms_pipelined.py", []),
    ("gemms pipelined loop unroll", "build_gemms_pipelined_loop_unroll.py", []),
    ("add", "build_add.py", []),
    ("maxpool", "build_maxpool.py", []),
    ("conv sa", "build_conv.py", []),
    ("conv sa dag-pack", "build_conv.py", ["--dag-pack"]),
    ("conv pipelined", "build_conv_pipelined.py", []),
    ("conv pipelined dag-pack", "build_conv_pipelined.py", ["--dag-pack"]),
    ("conv pipelined unroll", "build_conv_unrolled_pipelined.py", []),
    ("conv pipelined unroll dag-pack", "build_conv_unrolled_pipelined.py", ["--dag-pack"]),
    ("flash attention", "build_flash_attention.py", []),
    ("attention", "build_attention.py", []),
]


def collect_one(label: str, script: str, extra: list[str], work: Path) -> dict[str, Any]:
    stem = "".join(c if c.isalnum() else "_" for c in label)[:80]
    in_path = work / f"{stem}.in"
    perf_path = work / f"{stem}.perf"
    row: dict[str, Any] = {k: "" for k in CSV_FIELDS}
    row["Kernel"] = label
    row["_status"] = "ok"
    row["_error"] = ""

    rc, msg = run_build(script, in_path, extra)
    if rc != 0:
        row["_status"] = "build_failed"
        row["_error"] = msg.strip()
        return row

    rc, msg = emulate_to_perf(in_path, perf_path)
    if rc != 0:
        row["_status"] = "emu_failed"
        row["_error"] = msg.strip()
        return row

    perf = parse_perf_text(perf_path.read_text())
    row.update(perf_to_row(label, perf))
    return row


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument(
        "--csv",
        type=Path,
        default=Path("out/kernel_metrics.csv"),
        help="Output CSV path (default: out/kernel_metrics.csv)",
    )
    ap.add_argument("--json", type=Path, default=None, help="Optional JSON dump path")
    ap.add_argument(
        "--kernels",
        type=str,
        default="all",
        help='Comma-separated labels (exact match) or "all"',
    )
    args = ap.parse_args()

    os.chdir(REPO_ROOT)

    if args.kernels.strip().lower() == "all":
        specs = KERNEL_SPECS
    else:
        want = {x.strip() for x in args.kernels.split(",") if x.strip()}
        specs = [s for s in KERNEL_SPECS if s[0] in want]
        missing = want - {s[0] for s in specs}
        if missing:
            print("Unknown kernel labels:", ", ".join(sorted(missing)), file=sys.stderr)
            sys.exit(1)

    rows: list[dict[str, Any]] = []
    with tempfile.TemporaryDirectory(prefix="kmetrics_") as tmp:
        work = Path(tmp)
        for label, script, extra in specs:
            print(label, flush=True)
            row = collect_one(label, script, extra, work)
            if row.get("_status") != "ok":
                err = (row.get("_error") or "").strip()
                if err:
                    print(f"  -> {row.get('_status')}: {err[:500]}", file=sys.stderr)
            rows.append(row)

    if args.json:
        args.json.parent.mkdir(parents=True, exist_ok=True)
        args.json.write_text(json.dumps(rows, indent=2) + "\n")

    args.csv.parent.mkdir(parents=True, exist_ok=True)
    with args.csv.open("w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=CSV_FIELDS, extrasaction="ignore")
        w.writeheader()
        for r in rows:
            if r.get("_status") == "ok":
                w.writerow({k: r.get(k, "") for k in CSV_FIELDS})
            else:
                w.writerow(
                    {
                        "Kernel": f"{r.get('Kernel', '')} [{r.get('_status')}]",
                        "FLOPs (total)": "",
                        "FLOPs matmul": "",
                        "Static slots filled (non-NOP)": "",
                        "Bytes Loaded": "",
                        "Bytes Written": "",
                        "Static packet rows": "",
                        "Slots": "",
                        "Packet Slot Util. %": "",
                        "Packets executed": "",
                        "Ops executed (dynamic)": "",
                        "Arithmetic Intensity": "",
                        "AI (load+store)": "",
                    }
                )
    print(f"Wrote CSV: {args.csv.resolve()}", file=sys.stderr)

    bad = [r for r in rows if r.get("_status") != "ok"]
    if bad:
        print(
            f"[warn] {len(bad)}/{len(rows)} kernels failed (see CSV ERROR rows or _error in JSON)",
            file=sys.stderr,
        )


if __name__ == "__main__":
    main()
