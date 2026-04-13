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


def unroll_layernorm(
    n: int,
    *,
    tile_addr_location: int,
    epsilon_location: int,
    sid: int,
    rsum_imm: int,
    sdma_full_cols: int | None = None,
    mask_reg: int = 1,
    row_reg_base: int = 64,
    halt: bool = True,
) -> str:
    if n < 1:
        raise ValueError("n must be >= 1")
    if n > 32:
        raise ValueError("n must be <= 32 (row index field is 5-bit)")
    if row_reg_base + n - 1 > 255:
        raise ValueError("n is too large for row register allocation")

    max_col_ind = n - 1
    max_row_ind = n - 1
    full_cols = n if sdma_full_cols is None else sdma_full_cols
    mask_val = (1 << n) - 1

    mean_acc_reg = 20
    mean_reg = 24
    var_acc_reg = 38
    denom_reg = 39

    # VM uses rs2 as row-number register; keep immutable row-id scalars separate.
    row_idx_base = 160
    row_idx_regs = [row_idx_base + i for i in range(n)]

    # Use high scalar regs for all non-rc_id state so n can scale to 32.
    addr_tbl_reg = 200
    gmem_base_reg = 201
    scpad_base_reg = 202
    epsilon_addr_reg = 203
    epsilon_reg = 204
    lane_mask_scalar_reg = 205
    inv_elems_reg = 206
    denom_rcp_reg = 207
    sdma_meta_reg = 208
    sdma_tmp_reg = 209

    row_regs = [row_reg_base + i for i in range(n)]
    tmp_rsum_reg = 11
    tmp_sq0_reg = 12
    tmp_sq1_reg = 13

    lines: list[str] = []
    append = lines.append

    append(f"addi.s   ${addr_tbl_reg}, $0, {tile_addr_location}       # load tile/scpad address table location")
    append(f"lw.s     ${gmem_base_reg}, 0(${addr_tbl_reg})                           # load gmem tile base address")
    append(f"lw.s     ${scpad_base_reg}, 4(${addr_tbl_reg})                           # load scratchpad tile base address")
    append("")
    append(f"addi.s   ${sdma_meta_reg}, $0, 0                           # clear SDMA metadata register")
    append(f"addi.s   ${sdma_tmp_reg}, $0, {sid & 0x3}                           # sid field")
    append(f"slli.s   ${sdma_tmp_reg}, ${sdma_tmp_reg}, 30                           # move sid to bits [31:30]")
    append(f"or.s     ${sdma_meta_reg}, ${sdma_meta_reg}, ${sdma_tmp_reg}")
    append(f"addi.s   ${sdma_tmp_reg}, $0, {max_row_ind & 0x1F}                           # num_rows field")
    append(f"slli.s   ${sdma_tmp_reg}, ${sdma_tmp_reg}, 25                           # move rows to bits [29:25]")
    append(f"or.s     ${sdma_meta_reg}, ${sdma_meta_reg}, ${sdma_tmp_reg}")
    append(f"addi.s   ${sdma_tmp_reg}, $0, {max_col_ind & 0x1F}                           # num_cols field")
    append(f"slli.s   ${sdma_tmp_reg}, ${sdma_tmp_reg}, 20                           # move cols to bits [24:20]")
    append(f"or.s     ${sdma_meta_reg}, ${sdma_meta_reg}, ${sdma_tmp_reg}")
    append(f"lui.s    ${sdma_tmp_reg}, {(full_cols & 0xFFFFF) >> 7}                           # low metadata payload (full matrix cols), high bits")
    append(f"addi.s   ${sdma_tmp_reg}, ${sdma_tmp_reg}, {(full_cols & 0x7F)}                           # low metadata payload (full matrix cols), low bits")
    append(f"or.s     ${sdma_meta_reg}, ${sdma_meta_reg}, ${sdma_tmp_reg}")
    append(f"scpad.ld ${scpad_base_reg}, ${gmem_base_reg}, ${sdma_meta_reg}       # load NxN tile from gmem to scratchpad")
    append("")
    append(f"addi.s   ${epsilon_addr_reg}, $0, {epsilon_location}          # load epsilon address")
    append(f"lw.s     ${epsilon_reg}, 0(${epsilon_addr_reg})                           # load epsilon")
    append(f"addi.s   ${inv_elems_reg}, $0, {n * n}                    # load total elements N^2")
    append(f"stbf.s   ${inv_elems_reg}, ${inv_elems_reg}, $0                        # convert total elements to fp32 bit-pattern")
    append(f"rcp.bf   ${inv_elems_reg}, ${inv_elems_reg}, $0                        # compute inv(N^2) directly")
    append("")
    if n == 32:
        append(f"addi.s   ${lane_mask_scalar_reg}, $0, -1                           # all 32 lanes enabled")
    else:
        append(f"lui.s    ${lane_mask_scalar_reg}, {mask_val >> 7}                          # load upper lane-enable mask bits")
        append(f"addi.s   ${lane_mask_scalar_reg}, ${lane_mask_scalar_reg}, {mask_val & 0x7f}                    # add lower lane-enable mask bits")
    append(f"mv.stm   {mask_reg}, ${lane_mask_scalar_reg}                       # write mask into mask register {mask_reg}")
    for row_i, idx_reg in enumerate(row_idx_regs):
        append(f"addi.s   ${idx_reg}, $0, {row_i}                       # immutable row-number register for row {row_i}")
    append("")

    append("############## PHASE 1: MEAN (unrolled + pipelined) ##############")
    append(f"sub.vv   ${mean_acc_reg}, ${mean_acc_reg}, ${mean_acc_reg}, {mask_reg}   # zero mean accumulator")
    append(f"vreg.ld  ${row_regs[0]}, ${scpad_base_reg}, ${row_idx_regs[0]}, {max_col_ind}, {sid}   # fetch row 0 into ${row_regs[0]}")

    for i in range(1, n):
        append(f"rsum.vi  ${tmp_rsum_reg}, ${row_regs[i - 1]}, {rsum_imm}, {mask_reg}         # reduction sum row {i - 1}")
        append(f"vreg.ld  ${row_regs[i]}, ${scpad_base_reg}, ${row_idx_regs[i]}, {max_col_ind}, {sid}  # load row {i} (pipelined with rsum)")
        append(f"add.vv   ${mean_acc_reg}, ${mean_acc_reg}, ${tmp_rsum_reg}, {mask_reg}   # accumulate partial sum of row {i - 1}")

    append(f"rsum.vi  ${tmp_rsum_reg}, ${row_regs[-1]}, {rsum_imm}, {mask_reg}         # reduce last row ({n - 1})")
    append(f"add.vv   ${mean_acc_reg}, ${mean_acc_reg}, ${tmp_rsum_reg}, {mask_reg}   # accumulate last partial sum")
    append(f"mul.vs   ${mean_reg}, ${mean_acc_reg}, ${inv_elems_reg}, {mask_reg}      # mean = total_sum * inv(N^2)")
    append("")

    append("############## PHASE 2: VARIANCE (unrolled + pipelined) ##############")
    append(f"sub.vv   ${var_acc_reg}, ${var_acc_reg}, ${var_acc_reg}, {mask_reg}   # zero variance accumulator")
    for i, row_reg in enumerate(row_regs):
        append(f"sub.vv   ${row_reg}, ${row_reg}, ${mean_reg}, {mask_reg}   # diff row {i} = row {i} - mean")

    active_sq_reg = tmp_sq0_reg
    next_sq_reg = tmp_sq1_reg
    append(f"mul.vv   ${active_sq_reg}, ${row_regs[0]}, ${row_regs[0]}, {mask_reg}   # square diff row 0")
    for i in range(1, n):
        append(f"mul.vv   ${next_sq_reg}, ${row_regs[i]}, ${row_regs[i]}, {mask_reg}   # square diff row {i} (pipelined)")
        append(f"rsum.vi  ${active_sq_reg}, ${active_sq_reg}, {rsum_imm}, {mask_reg}         # reduce squared diff row {i - 1}")
        append(f"add.vv   ${var_acc_reg}, ${var_acc_reg}, ${active_sq_reg}, {mask_reg}   # accumulate variance contribution row {i - 1}")
        active_sq_reg, next_sq_reg = next_sq_reg, active_sq_reg

    append(f"rsum.vi  ${active_sq_reg}, ${active_sq_reg}, {rsum_imm}, {mask_reg}         # reduce last squared diff row ({n - 1})")
    append(f"add.vv   ${var_acc_reg}, ${var_acc_reg}, ${active_sq_reg}, {mask_reg}   # accumulate last variance contribution")
    append(f"mul.vs   ${denom_reg}, ${var_acc_reg}, ${inv_elems_reg}, {mask_reg}      # variance = sum * inv(N^2)")
    append(f"add.vs   ${denom_reg}, ${denom_reg}, ${epsilon_reg}, {mask_reg}         # add epsilon for stability")
    append(f"vmov.vts ${denom_rcp_reg}, ${denom_reg}, 0                             # extract denominator lane 0 to scalar")
    append(f"sqrt.bf  ${denom_rcp_reg}, ${denom_rcp_reg}, $0                            # denominator = sqrt(variance + epsilon)")
    append(f"rcp.bf   ${denom_rcp_reg}, ${denom_rcp_reg}, $0                            # reciprocal(denominator)")
    append("")

    append("############## PHASE 3: NORMALIZE + STORE (unrolled + pipelined) ##############")
    append(f"mul.vs   ${row_regs[0]}, ${row_regs[0]}, ${denom_rcp_reg}, {mask_reg}              # normalize row 0 via reciprocal multiply")
    for i in range(1, n):
        append(f"mul.vs   ${row_regs[i]}, ${row_regs[i]}, ${denom_rcp_reg}, {mask_reg}              # normalize row {i} via reciprocal multiply")
        append(f"vreg.st  ${row_regs[i - 1]}, ${scpad_base_reg}, ${row_idx_regs[i - 1]}, {max_col_ind}, {sid}   # store normalized row {i - 1} (pipelined)")
    append(f"vreg.st  ${row_regs[-1]}, ${scpad_base_reg}, ${row_idx_regs[-1]}, {max_col_ind}, {sid}   # store last normalized row ({n - 1})")
    append("")
    append(f"scpad.st ${scpad_base_reg}, ${gmem_base_reg}, ${sdma_meta_reg}            # store NxN tile back to gmem")
    append("")
    if halt:
        append("halt.s")

    return "\n".join(f"        {line}" if line else "" for line in lines)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input", type=Path, default=None, help="Input assembly file")
    ap.add_argument("-o", "--output", type=Path, default='./layernorm.in', help="Output test file")
    ap.add_argument(
        "--latency",
        action="store_true",
        help="Experimental: DAG + greedy_pack with latency materialized as static rows.",
    )
    ap.add_argument("--graph", action="store_true", help=argparse.SUPPRESS)
    ap.add_argument("--no-graph", action="store_true", help=argparse.SUPPRESS)
    ap.add_argument("--data", type=Path, default=None,
                    help="Path to input tile CSV data file (N×N). If omitted, uses hardcoded defaults.")
    ap.add_argument("--n", type=int, default=32,
                    help="Tile dimension N for an N×N tile (default: 32; SDMA uses max index N-1≤31)")
    args = ap.parse_args()
    use_latency_pack = bool(args.latency or args.graph)
    if use_latency_pack and args.no_graph:
        ap.error("Do not combine --no-graph with --latency")

    N = args.n

    TILE_ADDR_LOCATION = 60 # 0x3c
    SCPAD_ADDR_LOCATION = TILE_ADDR_LOCATION + 4
    TILE_ADDR = 0xcafa
    SCPAD_ADDR = 0
    EPSILON_LOCATION = 20
    SID = 0
    RSUM_IMM = 64
    asm = unroll_layernorm(
        N,
        tile_addr_location=TILE_ADDR_LOCATION,
        epsilon_location=EPSILON_LOCATION,
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
    #-----------DEFAULT ADDRESS INITIALIZATIONS--------
    img.u32(TILE_ADDR_LOCATION, TILE_ADDR) # Place tile base address at address 0x3c
    img.u32(SCPAD_ADDR_LOCATION, SCPAD_ADDR)
    img.f32(EPSILON_LOCATION, 0)
    #-----------TILE INITIALIZATION----------
    base_addr = TILE_ADDR
    if args.data is not None:
        tile_values = load_tile_data(args.data, N)
    else:
        tile_values = [float(v) for v in range(N * N)]
    for i, val in enumerate(tile_values):
        addr = base_addr + (i * 2)
        img.bf16(addr, float(val))
    # -----------------------------------------
    
    
    data_text = img.render_data_mem(include_zeros=False)
    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
    else: 
        print(final)

if __name__ == "__main__":
    main()
    
