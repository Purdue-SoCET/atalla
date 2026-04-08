from __future__ import annotations

import argparse
import os
import struct
from pathlib import Path

import numpy as np

from src.misc.opcode_table import OPCODES, name_to_opcode
from build import *


def bf16_round(x: float) -> int:
    u = struct.unpack("<I", struct.pack("<f", float(x)))[0]
    lsb = (u >> 16) & 1
    add = 0x7FFF + lsb
    u_round = (u + add) & 0xFFFFFFFF
    u_bf16 = (u_round & 0xFFFF0000) >> 16
    return u_bf16 & 0xFFFF


def generate_unrolled_asm(
    *,
    N: int,
    SDMA_IDX: int,
    NUM_TILES: int,
    TILE_BYTES: int,
    TILE_ADDR_LOCATION: int,
    SID0: int,
    SID1: int,
) -> str:
    """Pipelined GEMM row loop fully unrolled (same algorithm as build_gemms_pipelined)."""
    L: list[str] = []
    a = L.append

    a("        lui.s   $20, 0")
    a(f"        addi.s  $20, $0, {TILE_ADDR_LOCATION}")
    a("")
    a("        lw.s    $2, 0($20)   # Weight GMEM")
    a("        lw.s    $3, 4($20)   # Weight SCPAD")
    a("        lw.s    $21, 8($20)  # Input GMEM")
    a("        lw.s    $22, 12($20) # Input SCPAD")
    a("        lw.s    $24, 16($20) # Output GMEM")
    a("        lw.s    $23, 20($20) # Output SCPAD")
    a("")
    a(f"        scpad.ld $3, $2, {SDMA_IDX}, {SDMA_IDX}, {SID0}")
    a("")
    a("        lui.s   $6, 0")
    a("        addi.s  $6, $6, 0xf")
    a("        mv.stm  1, $6")
    a("")
    a("        addi.s  $27, $0, 0")
    a(f"        addi.s  $28, $0, {N}")
    a("    weights_loop:")
    a("        vreg.ld $10, $3, {mc}, {mc}, {sid0}, 1, $27".format(mc=SDMA_IDX, sid0=SID0))
    a("        lw.vi   $10, $10, 0, 0xf")
    a("        addi.s  $27, $27, 1")
    a("        blt.s   $27, $28, weights_loop")
    a("")
    a(f"        scpad.ld $22, $21, {SDMA_IDX}, {SDMA_IDX}, {SID0}")
    a(f"        scpad.ld $23, $24, {SDMA_IDX}, {SDMA_IDX}, {SID1}")
    a("")
    a("        addi.s  $25, $0, 0")
    a(f"        addi.s  $29, $0, {NUM_TILES}")
    a("    tile_loop:")
    a("        addi.s  $27, $0, 0")
    a(f"        vreg.ld $4, $22, {SDMA_IDX}, {SDMA_IDX}, {SID0}, 1, $27")
    a(f"        vreg.ld $5, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $27")
    a("")

    row = 0
    while row < N:
        next_row = row + 1
        a("        gemm.vv $6, $4, $5, 0, 0")
        if next_row < N:
            a(f"        addi.s  $28, $0, {next_row}")
            a(f"        vreg.ld $14, $22, {SDMA_IDX}, {SDMA_IDX}, {SID0}, 1, $28")
            a(f"        vreg.ld $15, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $28")
        a(f"        addi.s  $27, $0, {row}")
        a(f"        vreg.st $6, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $27")
        a("")

        if next_row >= N:
            row += 1
            continue

        a("        gemm.vv $6, $14, $15, 0, 0")
        next2_row = next_row + 1
        if next2_row < N:
            a(f"        addi.s  $28, $0, {next2_row}")
            a(f"        vreg.ld $4, $22, {SDMA_IDX}, {SDMA_IDX}, {SID0}, 1, $28")
            a(f"        vreg.ld $5, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $28")
        a(f"        addi.s  $27, $0, {next_row}")
        a(f"        vreg.st $6, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $27")
        a("")
        row += 2

    a("        addi.s  $25, $25, 1")
    a("        bge.s   $25, $29, tile_loop_done")
    a(f"        addi.s  $21, $21, {TILE_BYTES}")
    a(f"        scpad.ld $22, $21, {SDMA_IDX}, {SDMA_IDX}, {SID0}")
    a("        jal     $0, tile_loop")
    a("    tile_loop_done:")
    a(f"        scpad.st $23, $24, {SDMA_IDX}, {SDMA_IDX}, {SID1}")
    a("        halt.s")
    return "\n".join(L)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/gemms.in"), help="Output test file")
    args = ap.parse_args()

    N = 32
    SDMA_IDX = N - 1
    NUM_TILES = 3
    TILE_BYTES = N * N * 2
    TILE_ADDR_LOCATION = 60

    WEIGHT_GMEM_ADDR = 0x1000
    INPUT_GMEM_ADDR = 0x2000
    OUTPUT_GMEM_ADDR = 0x5000
    WEIGHT_SCPAD_ADDR = 0
    INPUT_SCPAD_ADDR = 1024
    OUTPUT_SCPAD_ADDR = 2048
    SID0 = 0
    SID1 = 1

    asm = generate_unrolled_asm(
        N=N,
        SDMA_IDX=SDMA_IDX,
        NUM_TILES=NUM_TILES,
        TILE_BYTES=TILE_BYTES,
        TILE_ADDR_LOCATION=TILE_ADDR_LOCATION,
        SID0=SID0,
        SID1=SID1,
    )

    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(TILE_ADDR_LOCATION + 0, WEIGHT_GMEM_ADDR)
    img.u32(TILE_ADDR_LOCATION + 4, WEIGHT_SCPAD_ADDR)
    img.u32(TILE_ADDR_LOCATION + 8, INPUT_GMEM_ADDR)
    img.u32(TILE_ADDR_LOCATION + 12, INPUT_SCPAD_ADDR)
    img.u32(TILE_ADDR_LOCATION + 16, OUTPUT_GMEM_ADDR)
    img.u32(TILE_ADDR_LOCATION + 20, OUTPUT_SCPAD_ADDR)

    W = np.array([[float(r + c) for c in range(N)] for r in range(N)])
    WT = W.T
    for r in range(N):
        for c in range(N):
            img.bf16(WEIGHT_GMEM_ADDR + (r * N + c) * 2, float(WT[r, c]))

    for t in range(NUM_TILES):
        base = INPUT_GMEM_ADDR + t * TILE_BYTES
        for r in range(N):
            for c in range(N):
                img.bf16(base + (r * N + c) * 2, float((r + 1) * (t + 1)))

    for i in range(N * N):
        img.bf16(OUTPUT_GMEM_ADDR + i * 2, 0.0)

    col_sums = W.sum(axis=0)
    tile_sum = sum(t + 1 for t in range(NUM_TILES))
    base_row = col_sums * float(tile_sum)
    C_expected = np.zeros((N, N))
    for r in range(N):
        C_expected[r, :] = base_row * (r + 1)
    print("Expected C (Row-Major):")
    print(C_expected)

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)
    os.makedirs(args.output.parent, exist_ok=True)
    args.output.write_text(final)


if __name__ == "__main__":
    main()
