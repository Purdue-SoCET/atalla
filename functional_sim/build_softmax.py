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

    row_regs = [row_reg_base + i for i in range(n)]

    max_vec_reg = 11
    sum_vec_reg = 12
    scalar_max_reg = 15
    scalar_inv_sum_reg = 16

    lines: list[str] = []
    append = lines.append

    append(f"addi.s   $1, $0, {tile_addr_location}       # load tile/scpad address table location into $1")
    append("lw.s     $2, 0($1)                           # load gmem tile base address into $2")
    append("lw.s     $3, 4($1)                           # load scratchpad tile base address into $3")
    append("")
    append(f"scpad.ld $3, $2, {max_col_ind}, {max_row_ind}, {sid}       # load NxN tile from gmem to scratchpad")
    append("")
    append(f"lui.s    $6, {mask_val >> 7}                          # load upper lane-enable mask bits into $6")
    append(f"addi.s   $6, $6, {mask_val & 0x7f}                    # add lower lane-enable mask bits into $6")
    append(f"mv.stm   {mask_reg}, $6                       # write mask into mask register {mask_reg}")
    append("")

    append("############## PHASE 1: LOAD ROWS (unrolled) ##############")
    append("addi.s   $7, $0, 0                            # row load index = 0")
    append(f"vreg.ld  ${row_regs[0]}, $3, {max_col_ind}, {max_row_ind}, {sid}, 1, $7  # load row 0 into ${row_regs[0]}")
    for i in range(1, n):
        append("addi.s   $7, $7, 1                            # advance load row index")
        append(f"vreg.ld  ${row_regs[i]}, $3, {max_col_ind}, {max_row_ind}, {sid}, 1, $7  # load row {i} into ${row_regs[i]}")
    append("")

    append("############## PHASE 2: SOFTMAX + STORE (unrolled + pipelined) ##############")
    append(f"rmax.vi  ${max_vec_reg}, ${row_regs[0]}, 0, {mask_reg}         # row 0 max reduction")
    append(f"vmov.vts ${scalar_max_reg}, ${max_vec_reg}, 0                  # extract row 0 max")
    append(f"sub.vs   ${row_regs[0]}, ${row_regs[0]}, ${scalar_max_reg}, {mask_reg}   # row 0 -= max")
    append(f"expi.vi  ${row_regs[0]}, ${row_regs[0]}, 0, {mask_reg}         # exp(row 0 - max)")
    append(f"rsum.vi  ${sum_vec_reg}, ${row_regs[0]}, {rsum_imm}, {mask_reg}         # row 0 exp sum")
    append(f"vmov.vts ${scalar_inv_sum_reg}, ${sum_vec_reg}, 0              # extract row 0 sum")
    append(f"rcp.bf   ${scalar_inv_sum_reg}, ${scalar_inv_sum_reg}, $0      # reciprocal(sum(row 0))")
    append(f"mul.vs   ${row_regs[0]}, ${row_regs[0]}, ${scalar_inv_sum_reg}, {mask_reg}   # normalize row 0")
    append("addi.s   $9, $0, 0                            # store row index = 0")

    for i in range(1, n):
        append(f"rmax.vi  ${max_vec_reg}, ${row_regs[i]}, 0, {mask_reg}         # row {i} max reduction")
        append(f"vmov.vts ${scalar_max_reg}, ${max_vec_reg}, 0                  # extract row {i} max")
        append(f"sub.vs   ${row_regs[i]}, ${row_regs[i]}, ${scalar_max_reg}, {mask_reg}   # row {i} -= max")
        append(f"expi.vi  ${row_regs[i]}, ${row_regs[i]}, 0, {mask_reg}         # exp(row {i} - max)")
        append(f"rsum.vi  ${sum_vec_reg}, ${row_regs[i]}, {rsum_imm}, {mask_reg}         # row {i} exp sum")
        append(f"vmov.vts ${scalar_inv_sum_reg}, ${sum_vec_reg}, 0              # extract row {i} sum")
        append(f"rcp.bf   ${scalar_inv_sum_reg}, ${scalar_inv_sum_reg}, $0      # reciprocal(sum(row {i}))")
        append(f"mul.vs   ${row_regs[i]}, ${row_regs[i]}, ${scalar_inv_sum_reg}, {mask_reg}   # normalize row {i}")
        append(f"vreg.st  ${row_regs[i - 1]}, $3, {max_col_ind}, {max_row_ind}, {sid}, 1, $9   # store normalized row {i - 1}")
        append("addi.s   $9, $9, 1                            # advance store row index")

    append(f"vreg.st  ${row_regs[-1]}, $3, {max_col_ind}, {max_row_ind}, {sid}, 1, $9   # store last normalized row ({n - 1})")
    append("")
    append(f"scpad.st $3, $2, {max_col_ind}, {max_row_ind}, {sid}            # store NxN tile back to gmem")
    append("")
    append("halt.s")

    return "\n".join(f"        {line}" if line else "" for line in lines)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input", type=Path, default=None, help="Input assembly file")
    ap.add_argument("-o", "--output", type=Path, default='./softmax.in', help="Output test file")
    ap.add_argument("--no-graph", action="store_true", help="Disable dependency graph packet scheduling")
    ap.add_argument("--data", type=Path, default=None,
                    help="Path to input tile CSV data file (N×N). If omitted, uses hardcoded defaults.")
    ap.add_argument("--n", type=int, default=32,
                    help="Tile dimension N for an N×N tile (default: 32)")
    args = ap.parse_args()

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

    if args.no_graph:
        instr_text = emit_test_format(instrs)
    else:
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
