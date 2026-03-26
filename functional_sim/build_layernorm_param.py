from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, List, Union
import struct
import os
import sys, re 
from pathlib import Path
import argparse
import numpy as np

from .build import *
from kernels.utils.dataloader import load_tile_data


def unroll_layernorm(
    n: int,
    *,
    tile_addr_location: int,
    epsilon_location: int,
    inv_layer_elems_location: int,
    sid: int,
    rsum_imm: int,
    mask_reg: int = 1,
    row_reg_base: int = 64,
) -> str:
    if n < 1:
        raise ValueError("n must be >= 1")
    if row_reg_base + n - 1 > 255:
        raise ValueError("n is too large for row register allocation")

    max_col_ind = n - 1
    max_row_ind = n - 1
    mask_val = (1 << n) - 1

    mean_acc_reg = 20
    mean_reg = 24
    var_acc_reg = 38
    denom_reg = 39

    row_regs = [row_reg_base + i for i in range(n)]
    tmp_rsum_reg = 11
    tmp_sq0_reg = 12
    tmp_sq1_reg = 13

    lines: list[str] = []
    append = lines.append

    append(f"addi.s   $1, $0, {tile_addr_location}       # load tile/scpad address table location into $1")
    append("lw.s     $2, 0($1)                           # load gmem tile base address into $2")
    append("lw.s     $3, 4($1)                           # load scratchpad tile base address into $3")
    append("")
    append(f"scpad.ld $3, $2, {max_col_ind}, {max_row_ind}, {sid}       # load NxN tile from gmem to scratchpad")
    append("")
    append(f"addi.s   $5, $0, {epsilon_location}          # load epsilon address into $5")
    append("lw.s     $4, 0($5)                           # load epsilon into $4")
    append(f"addi.s   $14, $0, {inv_layer_elems_location} # load inv(N^2) location into $14")
    append("lw.s     $14, 0($14)                         # load inv(N^2) as fp32 bit-pattern")
    append("")
    append(f"lui.s    $6, {mask_val >> 7}                          # load upper lane-enable mask bits into $6")
    append(f"addi.s   $6, $6, {mask_val & 0x7f}                    # add lower lane-enable mask bits into $6")
    append(f"mv.stm   {mask_reg}, $6                       # write mask into mask register {mask_reg}")
    append("")

    append("############## PHASE 1: MEAN (unrolled + pipelined) ##############")
    append(f"sub.vv   ${mean_acc_reg}, ${mean_acc_reg}, ${mean_acc_reg}, {mask_reg}, 0   # zero mean accumulator")
    append("addi.s   $7, $0, 0                            # i = 0")
    append(f"vreg.ld  ${row_regs[0]}, $3, {max_col_ind}, {max_row_ind}, {sid}, 1, $7  # fetch row 0 into ${row_regs[0]}")

    for i in range(1, n):
        append(f"rsum.vi  ${tmp_rsum_reg}, ${row_regs[i - 1]}, {rsum_imm}, {mask_reg}         # reduction sum row {i - 1}")
        append("addi.s   $7, $7, 1                            # i += 1")
        append(f"vreg.ld  ${row_regs[i]}, $3, {max_col_ind}, {max_row_ind}, {sid}, 1, $7  # load row {i} (pipelined with rsum)")
        append(f"add.vv   ${mean_acc_reg}, ${mean_acc_reg}, ${tmp_rsum_reg}, {mask_reg}, 0   # accumulate partial sum of row {i - 1}")

    append(f"rsum.vi  ${tmp_rsum_reg}, ${row_regs[-1]}, {rsum_imm}, {mask_reg}         # reduce last row ({n - 1})")
    append(f"add.vv   ${mean_acc_reg}, ${mean_acc_reg}, ${tmp_rsum_reg}, {mask_reg}, 0   # accumulate last partial sum")
    append(f"mul.vs   ${mean_reg}, ${mean_acc_reg}, $14, {mask_reg}      # mean = total_sum * inv(N^2)")
    append("")

    append("############## PHASE 2: VARIANCE (unrolled + pipelined) ##############")
    append(f"sub.vv   ${var_acc_reg}, ${var_acc_reg}, ${var_acc_reg}, {mask_reg}, 0   # zero variance accumulator")
    for i, row_reg in enumerate(row_regs):
        append(f"sub.vv   ${row_reg}, ${row_reg}, ${mean_reg}, {mask_reg}, 0   # diff row {i} = row {i} - mean")

    active_sq_reg = tmp_sq0_reg
    next_sq_reg = tmp_sq1_reg
    append(f"mul.vv   ${active_sq_reg}, ${row_regs[0]}, ${row_regs[0]}, {mask_reg}, 0   # square diff row 0")
    for i in range(1, n):
        append(f"mul.vv   ${next_sq_reg}, ${row_regs[i]}, ${row_regs[i]}, {mask_reg}, 0   # square diff row {i} (pipelined)")
        append(f"rsum.vi  ${active_sq_reg}, ${active_sq_reg}, {rsum_imm}, {mask_reg}         # reduce squared diff row {i - 1}")
        append(f"add.vv   ${var_acc_reg}, ${var_acc_reg}, ${active_sq_reg}, {mask_reg}, 0   # accumulate variance contribution row {i - 1}")
        active_sq_reg, next_sq_reg = next_sq_reg, active_sq_reg

    append(f"rsum.vi  ${active_sq_reg}, ${active_sq_reg}, {rsum_imm}, {mask_reg}         # reduce last squared diff row ({n - 1})")
    append(f"add.vv   ${var_acc_reg}, ${var_acc_reg}, ${active_sq_reg}, {mask_reg}, 0   # accumulate last variance contribution")
    append(f"mul.vs   ${denom_reg}, ${var_acc_reg}, $14, {mask_reg}      # variance = sum * inv(N^2)")
    append(f"add.vs   ${denom_reg}, ${denom_reg}, $4, {mask_reg}         # add epsilon for stability")
    append(f"sqrti.vi ${denom_reg}, ${denom_reg}, 0, {mask_reg}          # denominator = sqrt(variance + epsilon)")
    append("")

    append(f"vmov.vts $15, ${denom_reg}, 0                             # extract denominator lane 0 to scalar")
    append("rcp.bf   $15, $15, $0                            # reciprocal(denominator)")
    append("")

    append("############## PHASE 3: NORMALIZE + STORE (unrolled + pipelined) ##############")
    append(f"mul.vs   ${row_regs[0]}, ${row_regs[0]}, $15, {mask_reg}              # normalize row 0 via reciprocal multiply")
    append("addi.s   $9, $0, 0                              # store row index = 0")
    for i in range(1, n):
        append(f"mul.vs   ${row_regs[i]}, ${row_regs[i]}, $15, {mask_reg}              # normalize row {i} via reciprocal multiply")
        append(f"vreg.st  ${row_regs[i - 1]}, $3, {max_col_ind}, {max_row_ind}, {sid}, 1, $9   # store normalized row {i - 1} (pipelined)")
        append("addi.s   $9, $9, 1                              # advance store row index")
    append(f"vreg.st  ${row_regs[-1]}, $3, {max_col_ind}, {max_row_ind}, {sid}, 1, $9   # store last normalized row ({n - 1})")
    append("")
    append(f"scpad.st $3, $2, {max_col_ind}, {max_row_ind}, {sid}            # store NxN tile back to gmem")
    append("")
    append("halt.s")

    return "\n".join(f"        {line}" if line else "" for line in lines)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input", type=Path, default=None, help="Input assembly file")
    ap.add_argument("-o", "--output", type=Path, default='./layernorm.in', help="Output test file")
    ap.add_argument("--no-graph", action="store_true", help="Disable dependency graph packet scheduling")
    ap.add_argument("--data", type=Path, default=None,
                    help="Path to input tile CSV data file (N×N). If omitted, uses hardcoded defaults.")
    ap.add_argument("--n", type=int, default=4,
                    help="Tile dimension N for an N×N tile (default: 4)")
    args = ap.parse_args()

    N = args.n

    TILE_ADDR_LOCATION = 60 # 0x3c
    SCPAD_ADDR_LOCATION = TILE_ADDR_LOCATION + 4
    TILE_ADDR = 0xcafa
    SCPAD_ADDR = 0
    EPSILON_LOCATION = 20
    INV_LAYER_ELEMS_LOCATION = 24
    SID = 0
    LAYER_ELEMS = N * N
    RSUM_IMM = 64
    asm = unroll_layernorm(
        N,
        tile_addr_location=TILE_ADDR_LOCATION,
        epsilon_location=EPSILON_LOCATION,
        inv_layer_elems_location=INV_LAYER_ELEMS_LOCATION,
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
    #-----------DEFAULT ADDRESS INITIALIZATIONS--------
    img.u32(TILE_ADDR_LOCATION, TILE_ADDR) # Place tile base address at address 0x3c
    img.u32(SCPAD_ADDR_LOCATION, SCPAD_ADDR)
    img.f32(EPSILON_LOCATION, 0)
    img.f32(INV_LAYER_ELEMS_LOCATION, float(1.0 / LAYER_ELEMS))
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
    
