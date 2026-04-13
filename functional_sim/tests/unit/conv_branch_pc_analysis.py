#!/usr/bin/env python3
"""
Branch PC span for conv asm under ``greedy_pack_program_order``.

1) Documents the BR immediate limit enforced in ``build.split_br_target_imm`` and
   the decode field (imm1 + imm9 → byte offset).

2) For each conv generator asm (defaults matching ``build_conv*.py``), reports
   backward branch edges: source row PC, target row PC, delta bytes, and whether
   delta fits the ISA cap. Compares:

   - latency_stalls=False (structural pack, no empty rows for DAG time)
   - latency_stalls=True  (``build_dependency_graph`` ready times → empty packets)

Run (from ``functional_sim/``):

  python3 tests/unit/conv_branch_pc_analysis.py
"""
from __future__ import annotations

import sys
from pathlib import Path

FSIM = Path(__file__).resolve().parents[2]
if str(FSIM) not in sys.path:
    sys.path.insert(0, str(FSIM))

from build import (  # noqa: E402
    GRAPH_PACKET_WIDTH,
    INSTR_ADDR_STRIDE,
    build_dependency_graph,
    collect_branch_metadata,
    convert_instructions,
    assemble_file,
    greedy_pack_program_order,
    materialize_scheduled_instructions_tracked,
    DEFAULT_LATENCY_MAP,
)

# From build.split_br_target_imm: word_off = delta_bytes // 4, signed 10-bit.
BR_WORD_MIN, BR_WORD_MAX = -512, 511
BR_BYTE_MIN = BR_WORD_MIN * 4
BR_BYTE_MAX = BR_WORD_MAX * 4


def _stmt_pc_map(
    instrs: list[tuple[str, str]],
    packets: list[list[int]],
) -> dict[int, int]:
    tracked = materialize_scheduled_instructions_tracked(
        instrs,
        packets,
        packet_width=GRAPH_PACKET_WIDTH,
    )
    orig_to_pkt_pc: dict[int, int] = {}
    for pos, (_h, _c, oix) in enumerate(tracked):
        if oix is None:
            continue
        base = (pos // GRAPH_PACKET_WIDTH) * INSTR_ADDR_STRIDE
        if oix not in orig_to_pkt_pc:
            orig_to_pkt_pc[oix] = base
    return orig_to_pkt_pc


def _pack(asm: str, latency_stalls: bool) -> tuple[list[tuple[str, str]], list[list[int]], int]:
    instrs = assemble_file(asm)
    dep = convert_instructions(instrs)
    ready = (
        build_dependency_graph(dep, DEFAULT_LATENCY_MAP)
        if latency_stalls
        else [0] * len(dep)
    )
    packets = greedy_pack_program_order(dep, ready, max_width=GRAPH_PACKET_WIDTH)
    n_rows = len(packets)
    return instrs, packets, n_rows


def _backward_branch_report(
    asm: str,
    *,
    latency_stalls: bool,
    label: str,
) -> None:
    instrs, packets, n_rows = _pack(asm, latency_stalls)
    label_to_stmt, branch_targets = collect_branch_metadata(asm)
    if len(branch_targets) != len(instrs):
        print(f"  {label}: metadata mismatch")
        return
    stmt_pc = _stmt_pc_map(instrs, packets)
    print(f"  mode={label}  static_packet_rows={n_rows}  INSTR_ADDR_STRIDE={INSTR_ADDR_STRIDE}")

    for i, meta in enumerate(branch_targets):
        if meta is None:
            continue
        kind, lab = meta  # type: ignore[misc]
        if kind != "br":
            continue
        if lab not in label_to_stmt:
            continue
        tgt_stmt = label_to_stmt[lab]
        src_pc = stmt_pc.get(i)
        tgt_pc = stmt_pc.get(tgt_stmt)
        if src_pc is None or tgt_pc is None:
            continue
        delta = tgt_pc - src_pc
        if delta >= 0:
            continue
        ok = BR_BYTE_MIN <= delta <= BR_BYTE_MAX
        st = "OK" if ok else "OUT_OF_RANGE"
        print(
            f"    backward br  stmt[{i}] -> {lab!r} (stmt {tgt_stmt}): "
            f"src_pc=0x{src_pc:04X} tgt_pc=0x{tgt_pc:04X} delta={delta:+d} B  ({st})"
        )


def main() -> None:
    import build_conv as bc
    import build_conv_pipelined as bcp
    import build_conv_unrolled_pipelined as bcu

    N, H, W, C = 1, 6, 10, 3
    K, R, S = 4, 3, 3
    stride, pad = 1, 0
    Ho = (H + 2 * pad - R) // stride + 1
    Wo = (W + 2 * pad - S) // stride + 1
    K_flat = R * S * C
    M = N * Ho * Wo
    CFG = 0x3C

    print("BR immediate (as enforced by build.split_br_target_imm + decode BR imm)")
    print(
        f"  Word offset: signed 10-bit → [{BR_WORD_MIN}, {BR_WORD_MAX}] "
        f"(in 4-byte words)"
    )
    print(
        f"  Byte delta to target PC: [{BR_BYTE_MIN}, {BR_BYTE_MAX}] "
        f"(multiple of 4; matches decode sign_extend((imm10 << 2), 12))"
    )
    print()

    variants = [
        ("conv_sa", bc.make_conv_sa_asm(M, K_flat, K, CFG)),
        ("conv_pipelined", bcp.make_conv_sa_pipelined_asm(M, K_flat, K, CFG)),
        ("conv_unrolled_pipelined", bcu.make_conv_sa_unrolled_pipelined_asm(M, K_flat, K, CFG)),
    ]

    for name, asm in variants:
        print(f"{name}  (M={M} K_flat={K_flat} K={K})")
        _backward_branch_report(asm, latency_stalls=False, label="stalls_off")
        try:
            _backward_branch_report(asm, latency_stalls=True, label="stalls_on")
        except Exception as e:
            print(f"    stalls_on: pack/patch path error: {e}")
        print()

    print(
        "Note: stalls_on inserts empty packet rows until ready_time; static span grows\n"
        "and backward |delta| often exceeds the BR byte range — patch then fails."
    )


if __name__ == "__main__":
    main()
