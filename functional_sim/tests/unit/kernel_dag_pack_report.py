#!/usr/bin/env python3
"""
Exercise ``build_dependency_graph`` and ``greedy_pack`` on asm from each kernel builder.

Run from repo root or functional_sim (cwd must allow ``import build``):

  python tests/unit/kernel_dag_pack_report.py

Columns:
  - ``asm``: whether ``assemble_file`` succeeded.
  - ``DAG``: ``build_dependency_graph`` ran (register / LSU / store-order edges).
  - ``pack0``: ``greedy_pack`` with ``ready = [0,...]`` (ILP reordering allowed;
    does **not** preserve branch semantics — structural hazard check only).
  - ``pack*``: ``greedy_pack`` with real ``ready`` from the DAG (latency-aware).
  - ``ok0`` / ``ok*``: custom validator (packet width, ≤1 mem op/packet, RAW/WAR/WAW,
    isolated control) + start-cycle ≥ ready_time for that pack run.

Kernels without a small ``make_*_asm`` here show ``SKIP`` (no integrated asm hook).
"""
from __future__ import annotations

import sys
from pathlib import Path
from typing import Callable

FSIM = Path(__file__).resolve().parents[2]
if str(FSIM) not in sys.path:
    sys.path.insert(0, str(FSIM))

from build import (  # noqa: E402
    DEFAULT_LATENCY_MAP,
    GRAPH_PACKET_WIDTH,
    _is_control_op,
    _is_memory_op,
    assemble_file,
    build_dependency_graph,
    convert_instructions,
    greedy_pack,
)


def _insn_start_cycles(packets: list[list[int]]) -> dict[int, int]:
    c = 0
    m: dict[int, int] = {}
    for pkt in packets:
        if not pkt:
            c += 1
            continue
        for idx in pkt:
            m[idx] = c
        c += 1
    return m


def _validate_packets(
    dep: list[tuple[str, list[str], list[str], object]],
    packets: list[list[int]],
    ready: list[int],
    *,
    max_w: int = GRAPH_PACKET_WIDTH,
) -> None:
    seen: set[int] = set()
    for pkt in packets:
        if not pkt:
            continue
        if len(pkt) > max_w:
            raise AssertionError(f"packet width {len(pkt)} > {max_w}")
        reads: set[str] = set()
        writes: set[str] = set()
        mem_n = 0
        for slot, idx in enumerate(pkt):
            op, dsts, srcs, _ = dep[idx]
            if idx in seen:
                raise AssertionError(f"duplicate idx {idx}")
            seen.add(idx)
            if _is_control_op(op):
                if len(pkt) != 1 or slot != 0:
                    raise AssertionError("control must be alone in packet")
            if _is_memory_op(op):
                mem_n += 1
            for s in srcs:
                if s in writes:
                    raise AssertionError(f"RAW idx {idx} {s}")
            for d in dsts:
                if d in reads:
                    raise AssertionError(f"WAR idx {idx} {d}")
                if d in writes:
                    raise AssertionError(f"WAW idx {idx} {d}")
            reads.update(srcs)
            writes.update(dsts)
        if mem_n > 1:
            raise AssertionError(">1 memory op in packet")
    if seen != set(range(len(dep))):
        raise AssertionError(f"missing indices {set(range(len(dep))) - seen}")

    start = _insn_start_cycles(packets)
    if len(start) != len(dep):
        raise AssertionError("empty packets left gaps in scheduling")
    for i, r in enumerate(ready):
        if start[i] < r:
            raise AssertionError(f"insn {i} starts {start[i]} < ready {r}")


def _row(
    label: str,
    asm_fn: Callable[[], str] | None,
) -> tuple[str, str, str, str, str, str, str]:
    if asm_fn is None:
        return label, "SKIP", "—", "—", "—", "—", "—"
    try:
        instrs = assemble_file(asm_fn())
    except Exception as e:
        return label, f"FAIL({e.__class__.__name__})", "—", "—", "—", "—", "—"
    n = len(instrs)
    if n == 0:
        return label, "ok", "empty", "—", "—", "—", "—"
    dep = convert_instructions(instrs)
    dag_cell = "ok"
    try:
        ready_dag = build_dependency_graph(dep, DEFAULT_LATENCY_MAP)
    except Exception as e:
        dag_cell = f"FAIL({e.__class__.__name__})"
        ready_dag = [0] * len(dep)

    ready0 = [0] * len(dep)

    def try_pack(label_p: str, ready: list[int]) -> str:
        try:
            pk = greedy_pack(dep, ready, max_width=GRAPH_PACKET_WIDTH)
            _validate_packets(dep, pk, ready)
            return "ok"
        except Exception as e:
            return f"FAIL({e.__class__.__name__}: {e})"

    p0 = try_pack("0", ready0)
    pd = try_pack("*", ready_dag) if dag_cell == "ok" else "—"

    ok0 = "yes" if p0 == "ok" else "no"
    okd = "yes" if pd == "ok" else ("—" if pd == "—" else "no")

    return label, "ok", dag_cell, p0, pd, ok0, okd


def main() -> None:
    import build_add as ba
    import build_attention as batt
    import build_conv as bc
    import build_conv_pipelined as bcp
    import build_conv_tiled as bct
    import build_conv_unrolled_pipelined as bcu
    import build_gemm as bg
    import build_gemm_tiled as bgt
    import build_maxpool as bm

    rows: list[tuple[str, str, str, str, str, str, str]] = [
        _row(
            "conv_sa",
            lambda: bc.make_conv_sa_asm(M=1, K_flat=27, K_out=4, cfg_base=0x3C),
        ),
        _row(
            "conv_pipelined",
            lambda: bcp.make_conv_sa_pipelined_asm(M=1, K_flat=27, K_out=4, cfg_base=0x3C),
        ),
        _row(
            "conv_unrolled_pipelined",
            lambda: bcu.make_conv_sa_unrolled_pipelined_asm(1, 27, 4, 0x3C),
        ),
        _row(
            "attention",
            lambda: batt.make_attention_asm(4, 0x40),
        ),
        _row(
            "gemm",
            lambda: bg.make_gemm_asm(4, 4, 0x20),
        ),
        _row(
            "add",
            lambda: ba.make_add_asm(4, 8),
        ),
        _row(
            "maxpool",
            lambda: bm.make_maxpool_asm(8, 8, 2, 2),
        ),
        _row(
            "gemm_tiled",
            lambda: bgt.make_tiled_gemm_asm(4, 4, 4),
        ),
        _row(
            "conv_tiled",
            lambda: bct.make_tiled_conv_asm(M=4, K_flat=8, K_out=4),
        ),
    ]

    try:
        from build_softmax import unroll_softmax

        rows.append(
            _row(
                "softmax (unroll n=4)",
                lambda: unroll_softmax(
                    4,
                    tile_addr_location=60,
                    sid=0,
                    rsum_imm=64,
                ),
            )
        )
    except Exception as e:
        rows.append((f"softmax (import {e.__class__.__name__})", "SKIP", "—", "—", "—", "—", "—"))

    try:
        from build_layernorm_param import unroll_layernorm

        rows.append(
            _row(
                "layernorm_param (unroll n=4)",
                lambda: unroll_layernorm(
                    4,
                    tile_addr_location=60,
                    epsilon_location=20,
                    sid=0,
                    rsum_imm=64,
                ),
            )
        )
    except Exception as e:
        rows.append(
            (f"layernorm_param (import {e.__class__.__name__})", "SKIP", "—", "—", "—", "—", "—")
        )

    hdr = (
        f"{'kernel':<28} {'asm':^6} {'DAG':^6} {'pack0':^8} {'pack*':^8} "
        f"{'haz0':^5} {'haz*':^5}"
    )
    print(hdr)
    print("-" * len(hdr))
    for r in rows:
        print(f"{r[0]:<28} {r[1]:^6} {r[2]:^6} {r[3]:^8} {r[4]:^8} {r[5]:^5} {r[6]:^5}")

    fails = sum(1 for r in rows if "FAIL" in "".join(r[1:]))
    if fails:
        raise SystemExit(f"FAIL: {fails} row(s) with errors (see table)")


if __name__ == "__main__":
    main()
