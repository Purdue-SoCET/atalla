from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, List, Union
import struct
import os
import sys, re
from pathlib import Path
import argparse
import numpy as np

from build import *
from kernels.utils.dataloader import load_tile_data


def unroll_softmax(
    n: int,
    *,
    tile_addr_location: int,
    sid: int,
    rsum_imm: int,
    mask_reg: int = 1,
    row_reg_base: int = 64,
) -> str:
    if n < 1:
        raise ValueError("n must be >= 1")
    if n > 32:
        raise ValueError("n must be <= 32 (vector mask / tile dimensions are 5-bit fields)")
    if row_reg_base + n - 1 > 255:
        raise ValueError("n is too large for row register allocation")

    max_col_ind = n - 1
    max_row_ind = n - 1
    mask_val = (1 << n) - 1

    # Main row registers
    row_regs = [row_reg_base + i for i in range(n)]

    # 4-entry rotating temp rings for reduction outputs.
    # This matches rmax.vi / rsum.vi latency = 4.
    max_vec_ring = [11, 12, 13, 14]
    sum_vec_ring = [15, 16, 17, 18]

    temp_vec_reg_set = set(max_vec_ring + sum_vec_ring)
    if any(r in temp_vec_reg_set for r in row_regs):
        raise ValueError("row_reg_base overlaps temp vector registers 11..18")

    # Per-row scalar temps to remove fake row-to-row deps in compute
    scalar_max_base = 192
    scalar_inv_sum_base = 224
    if scalar_inv_sum_base + n - 1 > 255:
        raise ValueError("n is too large for chosen scalar temp register layout")

    scalar_max_regs = [scalar_max_base + i for i in range(n)]
    scalar_inv_sum_regs = [scalar_inv_sum_base + i for i in range(n)]

    # Keep setup regs close to the original kernel style
    addr_tbl_reg = 1
    gmem_base_reg = 2
    scpad_base_reg = 3
    lane_mask_scalar_reg = 6

    # Original mutable row counters for vector load/store addressing
    load_row_reg = 7
    store_row_reg = 9

    lines: list[str] = []
    append = lines.append

    append(f"addi.s   ${addr_tbl_reg}, $0, {tile_addr_location}       # load tile/scpad address table location into ${addr_tbl_reg}")
    append(f"lw.s     ${gmem_base_reg}, 0(${addr_tbl_reg})                           # load gmem tile base address into ${gmem_base_reg}")
    append(f"lw.s     ${scpad_base_reg}, 4(${addr_tbl_reg})                           # load scratchpad base address into ${scpad_base_reg}")
    append("")
    append(f"scpad.ld ${scpad_base_reg}, ${gmem_base_reg}, {max_col_ind}, {max_row_ind}, {sid}       # load NxN tile from gmem to scratchpad")
    append("")

    if n == 32:
        append(f"addi.s   ${lane_mask_scalar_reg}, $0, -1                           # all 32 lanes enabled")
    else:
        append(f"lui.s    ${lane_mask_scalar_reg}, {mask_val >> 7}                          # load upper lane-enable mask bits")
        append(f"addi.s   ${lane_mask_scalar_reg}, ${lane_mask_scalar_reg}, {mask_val & 0x7f}                    # add lower lane-enable mask bits")
    append(f"mv.stm   {mask_reg}, ${lane_mask_scalar_reg}                       # write mask into mask register {mask_reg}")
    append("")

    append("############## PHASE 1: LOAD ROWS (keep original addressing style) ##############")
    append(f"addi.s   ${load_row_reg}, $0, 0                            # row load index = 0")
    append(f"vreg.ld  ${row_regs[0]}, ${scpad_base_reg}, {max_col_ind}, {max_row_ind}, {sid}, 1, ${load_row_reg}  # load row 0")
    for i in range(1, n):
        append(f"addi.s   ${load_row_reg}, ${load_row_reg}, 1                            # advance load row index")
        append(f"vreg.ld  ${row_regs[i]}, ${scpad_base_reg}, {max_col_ind}, {max_row_ind}, {sid}, 1, ${load_row_reg}  # load row {i}")
    append("")

    append("############## PHASE 2: MAX + SHIFT + EXP (pipelined like layernorm idea) ##############")
    for t in range(n + 6):
        if 0 <= t - 4 < n:
            row = t - 4
            slot = row % 4
            append(
                f"vmov.vts ${scalar_max_regs[row]}, ${max_vec_ring[slot]}, 0                  # extract row {row} max"
            )
        if 0 <= t - 5 < n:
            row = t - 5
            append(
                f"sub.vs   ${row_regs[row]}, ${row_regs[row]}, ${scalar_max_regs[row]}, {mask_reg}   # row {row} -= max"
            )
        if 0 <= t - 6 < n:
            row = t - 6
            append(
                f"expi.vi  ${row_regs[row]}, ${row_regs[row]}, 0, {mask_reg}         # exp(row {row} - max)"
            )
        if t < n:
            row = t
            slot = row % 4
            append(
                f"rmax.vi  ${max_vec_ring[slot]}, ${row_regs[row]}, 0, {mask_reg}         # row {row} max reduction"
            )
    append("")

    append("############## PHASE 3: SUM + EXTRACT + RCP (pipelined) ##############")
    for t in range(n + 5):
        if 0 <= t - 4 < n:
            row = t - 4
            slot = row % 4
            append(
                f"vmov.vts ${scalar_inv_sum_regs[row]}, ${sum_vec_ring[slot]}, 0              # extract row {row} sum"
            )
        if 0 <= t - 5 < n:
            row = t - 5
            append(
                f"rcp.bf   ${scalar_inv_sum_regs[row]}, ${scalar_inv_sum_regs[row]}, $0      # reciprocal(sum(row {row}))"
            )
        if t < n:
            row = t
            slot = row % 4
            append(
                f"rsum.vi  ${sum_vec_ring[slot]}, ${row_regs[row]}, {rsum_imm}, {mask_reg}         # row {row} exp sum"
            )
    append("")

    append("############## PHASE 4: NORMALIZE + STORE (keep original addressing style) ##############")
    append(f"addi.s   ${store_row_reg}, $0, 0                            # store row index = 0")
    append(f"mul.vs   ${row_regs[0]}, ${row_regs[0]}, ${scalar_inv_sum_regs[0]}, {mask_reg}   # normalize row 0")

    for i in range(1, n):
        append(
            f"mul.vs   ${row_regs[i]}, ${row_regs[i]}, ${scalar_inv_sum_regs[i]}, {mask_reg}   # normalize row {i}"
        )
        append(
            f"vreg.st  ${row_regs[i - 1]}, ${scpad_base_reg}, {max_col_ind}, {max_row_ind}, {sid}, 1, ${store_row_reg}   # store normalized row {i - 1}"
        )
        append(f"addi.s   ${store_row_reg}, ${store_row_reg}, 1                            # advance store row index")

    append(
        f"vreg.st  ${row_regs[-1]}, ${scpad_base_reg}, {max_col_ind}, {max_row_ind}, {sid}, 1, ${store_row_reg}   # store last normalized row ({n - 1})"
    )
    append("")
    append(f"scpad.st ${scpad_base_reg}, ${gmem_base_reg}, {max_col_ind}, {max_row_ind}, {sid}            # store NxN tile back to gmem")
    append("")
    append("halt.s")

    return "\n".join(f"        {line}" if line else "" for line in lines)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input", type=Path, default=None, help="Input assembly file")
    ap.add_argument("-o", "--output", type=Path, default="./softmax.in", help="Output test file")
    ap.add_argument(
        "--latency",
        action="store_true",
        help=(
            "Experimental: build_dependency_graph + greedy_pack (materializes latency wait "
            "rows in static .in). Default is linear emit_test_format."
        ),
    )
    ap.add_argument("--graph", action="store_true", help=argparse.SUPPRESS)
    ap.add_argument("--no-graph", action="store_true", help=argparse.SUPPRESS)
    ap.add_argument(
        "--data",
        type=Path,
        default=None,
        help="Path to input tile CSV data file (N×N). If omitted, uses hardcoded defaults.",
    )
    ap.add_argument("--n", type=int, default=32, help="Tile dimension N for an N×N tile (default: 32)")
    args = ap.parse_args()
    use_latency_pack = bool(args.latency or args.graph)
    if use_latency_pack and args.no_graph:
        ap.error("Do not combine --no-graph with --latency")

    N = args.n

    TILE_ADDR_LOCATION = 60  # 0x3c
    SCPAD_ADDR_LOCATION = TILE_ADDR_LOCATION + 4
    TILE_ADDR = 0xcafa
    SCPAD_ADDR = 0
    SID = 0
    RSUM_IMM = 64

    asm = unroll_softmax(
        N,
        tile_addr_location=TILE_ADDR_LOCATION,
        sid=SID,
        rsum_imm=RSUM_IMM,
    )

    instrs = assemble_file(asm)

    if use_latency_pack:
        dependency_instrs = convert_instructions(instrs)
        ready = build_dependency_graph(dependency_instrs, DEFAULT_LATENCY_MAP)
        packets = greedy_pack(dependency_instrs, ready, max_width=GRAPH_PACKET_WIDTH)
        scheduled = materialize_scheduled_instructions(
            instrs,
            packets,
            packet_width=GRAPH_PACKET_WIDTH,
        )
        instr_text = emit_test_format(
            scheduled,
            virtual_packet_size=GRAPH_PACKET_WIDTH,
        )
    else:
        instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(TILE_ADDR_LOCATION, TILE_ADDR)
    img.u32(SCPAD_ADDR_LOCATION, SCPAD_ADDR)

    base_addr = TILE_ADDR
    if args.data is not None:
        tile_values = load_tile_data(args.data, N)
    else:
        tile_values = [float(v) for v in range(N * N)]

    for i, val in enumerate(tile_values):
        addr = base_addr + (i * 2)
        img.bf16(addr, float(val))

    data_text = img.render_data_mem(include_zeros=False)
    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
    else:
        print(final)


if __name__ == "__main__":
    main()
