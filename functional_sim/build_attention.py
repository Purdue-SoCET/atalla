#!/usr/bin/env python3
# n×n BF16 QKV-style attention (SDMA tile layout); default emit_test_format, optional --latency (DAG greedy_pack); fused LN + precomputed attn_ref demo → build_attention_fused_layernorm.py.
from __future__ import annotations

import argparse
import os
from pathlib import Path

import numpy as np

try:
    from .build import (
        assemble_file,
        emit_test_format,
        DRAMWriter,
        render_testfile,
        emit_sdma_metadata_asm,
        convert_instructions,
        build_dependency_graph,
        greedy_pack,
        materialize_scheduled_instructions,
        DEFAULT_LATENCY_MAP,
        GRAPH_PACKET_WIDTH,
    )
except Exception:
    try:
        from functional_sim.build import (
            assemble_file,
            emit_test_format,
            DRAMWriter,
            render_testfile,
            emit_sdma_metadata_asm,
            convert_instructions,
            build_dependency_graph,
            greedy_pack,
            materialize_scheduled_instructions,
            DEFAULT_LATENCY_MAP,
            GRAPH_PACKET_WIDTH,
        )
    except Exception:
        from build import (
            assemble_file,
            emit_test_format,
            DRAMWriter,
            render_testfile,
            emit_sdma_metadata_asm,
            convert_instructions,
            build_dependency_graph,
            greedy_pack,
            materialize_scheduled_instructions,
            DEFAULT_LATENCY_MAP,
            GRAPH_PACKET_WIDTH,
        )


def make_attention_asm(n: int, cfg_base: int) -> str:
    mc = n - 1
    row_bytes = n * 2
    sdma_q_row = "\n".join(
        "        " + ln.strip()
        for ln in emit_sdma_metadata_asm(40, 41, 0, 1, n, n).split("\n")
        if ln.strip()
    )
    sdma_k_tile = "\n".join(
        "        " + ln.strip()
        for ln in emit_sdma_metadata_asm(42, 43, 1, n, n, n).split("\n")
        if ln.strip()
    )
    sdma_v_tile = "\n".join(
        "        " + ln.strip()
        for ln in emit_sdma_metadata_asm(44, 45, 0, n, n, n).split("\n")
        if ln.strip()
    )
    sdma_o_row = "\n".join(
        "        " + ln.strip()
        for ln in emit_sdma_metadata_asm(46, 47, 0, 1, n, n).split("\n")
        if ln.strip()
    )
    return f"""
        addi.s  $1, $0, {cfg_base}
        lw.s    $2, 0($1)      # Q
        lw.s    $3, 4($1)      # K
        lw.s    $4, 8($1)      # V
        lw.s    $5, 12($1)     # O
        lw.s    $6, 16($1)     # SP0 base
        lw.s    $7, 20($1)     # SP1 base (K)

        li.s    $8, -1
        mv.stm  1, $8
        addi.s  $25, $0, 0
        addi.s  $26, $0, {n}
        add.s   $21, $0, $2
        add.s   $22, $0, $5

{sdma_k_tile}
        scpad.ld $7, $3, $42

row_loop:
        addi.s  $27, $0, 0
        addi.s  $28, $0, {n}
kload:
        vreg.ld $10, $7, $27, {mc}, 1
        lw.vi   $10, $10, 0, 1
        addi.s  $27, $27, 1
        blt.s   $27, $28, kload

{sdma_q_row}
        scpad.ld $6, $21, $40
        addi.s  $27, $0, 0
        vreg.ld $11, $6, $27, {mc}, 0
        sub.vv   $12, $12, $12, 1
        gemm.vv $12, $11, $12, 1

        rmax.vi $13, $12, 64, 1
        vmov.vts $14, $13, 0
        sub.vs  $12, $12, $14, 1
        expi.vi $12, $12, 0, 1
        rsum.vi $15, $12, 64, 1
        vmov.vts $16, $15, 0
        rcp.bf  $16, $16, $0
        mul.vs  $12, $12, $16, 1

{sdma_v_tile}
        scpad.ld $6, $4, $44
        addi.s  $27, $0, 0
        addi.s  $28, $0, {n}
vload:
        vreg.ld $10, $6, $27, {mc}, 0
        lw.vi   $10, $10, 0, 1
        addi.s  $27, $27, 1
        blt.s   $27, $28, vload

        sub.vv   $17, $17, $17, 1
        gemm.vv $17, $12, $17, 1

        addi.s  $27, $0, 0
        vreg.st $17, $6, $27, {mc}, 0
{sdma_o_row}
        scpad.st $6, $22, $46

        addi.s  $21, $21, {row_bytes}
        addi.s  $22, $22, {row_bytes}
        addi.s  $25, $25, 1
        blt.s   $25, $26, row_loop
        halt.s
    """


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/attention.in"))
    ap.add_argument("--n", type=int, default=32)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument(
        "--latency",
        action="store_true",
        help="Experimental: DAG + greedy_pack with latency rows in static .in.",
    )
    ap.add_argument("--graph", action="store_true", help=argparse.SUPPRESS)
    ap.add_argument("--no-graph", action="store_true", help=argparse.SUPPRESS)
    args = ap.parse_args()
    use_latency_pack = bool(args.latency or args.graph)
    if use_latency_pack and args.no_graph:
        ap.error("Do not combine --no-graph with --latency")
    n = args.n
    if n < 1 or n > 32:
        raise ValueError("build_attention supports 1 <= n <= 32.")

    CFG_BASE = 0x40
    Q_ADDR, K_ADDR, V_ADDR, O_ADDR = 0x1000, 0x3000, 0x5000, 0x7000
    Q_SPAD, M_SPAD = 0, 1024

    asm = make_attention_asm(n, CFG_BASE)
    instrs = assemble_file(asm)
    if use_latency_pack:
        dependency_instrs = convert_instructions(instrs)
        ready = build_dependency_graph(dependency_instrs, DEFAULT_LATENCY_MAP)
        packets = greedy_pack(dependency_instrs, ready, max_width=GRAPH_PACKET_WIDTH)
        scheduled = materialize_scheduled_instructions(
            instrs, packets, packet_width=GRAPH_PACKET_WIDTH
        )
        instr_text = emit_test_format(scheduled, virtual_packet_size=GRAPH_PACKET_WIDTH)
    else:
        instr_text = emit_test_format(instrs)

    rng = np.random.default_rng(args.seed)
    Q = rng.standard_normal((n, n)).astype(np.float32)
    K = rng.standard_normal((n, n)).astype(np.float32)
    V = rng.standard_normal((n, n)).astype(np.float32)

    img = DRAMWriter()
    img.u32(CFG_BASE + 0, Q_ADDR)
    img.u32(CFG_BASE + 4, K_ADDR)
    img.u32(CFG_BASE + 8, V_ADDR)
    img.u32(CFG_BASE + 12, O_ADDR)
    img.u32(CFG_BASE + 16, Q_SPAD)
    img.u32(CFG_BASE + 20, M_SPAD)
    for i, v in enumerate(Q.reshape(-1)):
        img.bf16(Q_ADDR + i * 2, float(v))
    for i, v in enumerate(K.T.reshape(-1)):
        img.bf16(K_ADDR + i * 2, float(v))
    for i, v in enumerate(V.reshape(-1)):
        img.bf16(V_ADDR + i * 2, float(v))
    for i in range(n * n):
        img.bf16(O_ADDR + i * 2, 0.0)

    os.makedirs(args.output.parent, exist_ok=True)
    args.output.write_text(render_testfile(instr_text, img.render_data_mem(include_zeros=True)))


if __name__ == "__main__":
    main()
