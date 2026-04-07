from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, List, Union
import struct
import os
import sys, re
from pathlib import Path
import argparse
import numpy as np

from src.misc.opcode_table import OPCODES, name_to_opcode
from build import *


def bf16_round(x: float) -> int:
    #using to calculate expected - same as logic in src files 
    u = struct.unpack("<I", struct.pack("<f", float(x)))[0]
    lsb = (u >> 16) & 1
    add = 0x7FFF + lsb
    u_round = (u + add) & 0xFFFFFFFF 
    u_bf16 = (u_round & 0xFFFF0000) >> 16
    return u_bf16 & 0xFFFF



    for row in range(ROWS):
        lines += [
            f"    addi.s  $27, $0, {row}",
            f"    vreg.ld $10, $3, {COLS}, {ROWS}, {SID0}, 1, $27",
            f"    lw.vi   $10, $10, 0, 0xf",
        ]
    lines.append(f"")
 
    lines += [
        f"    scpad.ld $22, $21, {COLS}, {ROWS}, {SID0}",
        f"    scpad.ld $23, $24, {COLS}, {ROWS}, {SID1}",
        f"",
    ]
    for tile in range(NUM_TILES):
 
        lines += [
            f"    addi.s  $27, $0, 0",
            f"    vreg.ld $4, $22, {COLS}, {ROWS}, {SID0}, 1, $27",
            f"    vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, $27",

        ]
 
        row = 0
        while row < ROWS:
            next_row = row + 1
 
            # grp1 :n
            lines.append(f"    gemm.vv $6, $4, $5, 0, 0")
 
            if next_row < ROWS:
                lines += [
                    f"    addi.s  $28, $0, {next_row}",
                    f"    vreg.ld $14, $22, {COLS}, {ROWS}, {SID0}, 1, $28",
                    f"    vreg.ld $15, $23, {COLS}, {ROWS}, {SID1}, 1, $28",
                ]

            lines += [
                f"    addi.s  $27, $0, {row}",
                f"    vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, $27",
            ]
 
            if next_row >= ROWS:
                row += 1
                continue
 
            #grp2 :n+1
            lines.append(f"    gemm.vv $6, $14, $15, 0, 0")
 
            next2_row = next_row + 1
            if next2_row < ROWS:
                lines += [
                    f"    addi.s  $28, $0, {next2_row}",
                    f"    vreg.ld $4, $22, {COLS}, {ROWS}, {SID0}, 1, $28",
                    f"    vreg.ld $5, $23, {COLS}, {ROWS}, {SID1}, 1, $28",
                ]
 
            lines += [
                f"    addi.s  $27, $0, {next_row}",
                f"    vreg.st $6, $23, {COLS}, {ROWS}, {SID1}, 1, $27",
            ]
 
            row += 2 
 
        if tile < NUM_TILES - 1:
            lines += [
                f"    addi.s  $21, $21, {TILE_BYTES}",
                f"    scpad.ld $22, $21, {COLS}, {ROWS}, {SID0}",
            ]
 

    lines += [
        f"    scpad.st $23, $24, {COLS}, {ROWS}, {SID1}",
        f"    halt.s",
    ]
 
    return "\n".join(lines)



def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path('tests/gemms.in'), help="Output test file")
    ap.add_argument("--no-graph", action="store_true", help="Disable dependency graph packet scheduling")

    args = ap.parse_args()

    # Change values here for parametrization:
    COLS      = 4
    ROWS      = 4
    NUM_TILES = 3
    TILE_BYTES = ROWS * COLS * 2   

    TILE_ADDR_LOCATION = 60

    WEIGHT_GMEM_ADDR  = 0x1000
    INPUT_GMEM_ADDR   = 0x2000
    OUTPUT_GMEM_ADDR  = 0x5000

    WEIGHT_SCPAD_ADDR = 0        
    INPUT_SCPAD_ADDR  = 1024    
    OUTPUT_SCPAD_ADDR = 2048

    SID0      = 0
    SID1      = 1




    asm = generate_unrolled_asm(
        ROWS=ROWS, COLS=COLS, NUM_TILES=NUM_TILES,
        TILE_ADDR_LOCATION=TILE_ADDR_LOCATION,
        WEIGHT_GMEM_ADDR=WEIGHT_GMEM_ADDR,
        INPUT_GMEM_ADDR=INPUT_GMEM_ADDR,
        OUTPUT_GMEM_ADDR=OUTPUT_GMEM_ADDR,
        WEIGHT_SCPAD_ADDR=WEIGHT_SCPAD_ADDR,
        INPUT_SCPAD_ADDR=INPUT_SCPAD_ADDR,
        OUTPUT_SCPAD_ADDR=OUTPUT_SCPAD_ADDR,
        SID0=SID0, SID1=SID1,
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
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(TILE_ADDR_LOCATION + 0,  WEIGHT_GMEM_ADDR)
    img.u32(TILE_ADDR_LOCATION + 4,  WEIGHT_SCPAD_ADDR)
    img.u32(TILE_ADDR_LOCATION + 8,  INPUT_GMEM_ADDR)
    img.u32(TILE_ADDR_LOCATION + 12, INPUT_SCPAD_ADDR)
    img.u32(TILE_ADDR_LOCATION + 16, OUTPUT_GMEM_ADDR)
    img.u32(TILE_ADDR_LOCATION + 20, OUTPUT_SCPAD_ADDR)


    W = np.array([[float(r + c) for c in range(COLS)]
              for r in range(ROWS)])
    WT = W.T
    for r in range(ROWS):
        for c in range(COLS):
            img.bf16(WEIGHT_GMEM_ADDR + (r * COLS + c) * 2, float(WT[r, c]))


    for t in range(NUM_TILES):
        base = INPUT_GMEM_ADDR + t * TILE_BYTES
        for r in range(ROWS):
            for c in range(COLS):
                img.bf16(base + (r * COLS + c) * 2, float((r + 1) * (t + 1)))


    for i in range(ROWS * COLS):
        img.bf16(OUTPUT_GMEM_ADDR + i * 2, 0.0)

    # expected
    col_sums = W.sum(axis=0)
    tile_sum = sum(t + 1 for t in range(NUM_TILES))
    base_row = col_sums * float(tile_sum)
    print("Expected C (Row-Major):")
    C_expected = np.zeros((ROWS, COLS))
    for r in range(ROWS):
        C_expected[r, :] = base_row * (r + 1)

    print(C_expected)
    print("W =")
    print(W)
    print()
    print("W^T (stored in gmem / loaded into systolic array) =")
    print(WT)
    print()

    print()
    print("\nExpected BF16 Hex (Column-Major / Bank-Interleaved):")
    for c in range(COLS):
        bank_hex = []
        for r in range(ROWS):
            f_val = float(C_expected[r, c])
            bits = bf16_round(f_val)
            bank_hex.append(f"0x{bits:04X}")
        print(f"Bank {c}: {bank_hex}")

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
    else:
        print(final)


if __name__ == "__main__":
    main()