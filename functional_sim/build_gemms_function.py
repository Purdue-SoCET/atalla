from __future__ import annotations

import argparse
import os
import struct
from pathlib import Path

import numpy as np

from build import *


def bf16_round(x: float) -> int:
    u = struct.unpack("<I", struct.pack("<f", float(x)))[0]
    lsb = (u >> 16) & 1
    add = 0x7FFF + lsb
    u_round = (u + add) & 0xFFFFFFFF
    u_bf16 = (u_round & 0xFFFF0000) >> 16
    return u_bf16 & 0xFFFF


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/gemms.in"), help="Output test file")
    args = ap.parse_args()

    # 32×32 tiles; 5-bit SDMA max index = 31 (same as build_gemms.py).
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

    asm = f"""
        addi.s  $1, $0, {TILE_ADDR_LOCATION}
        jal     $31, gemm_func

        halt.s

    gemm_func:

        lw.s    $2,  0($1)     # Weight GMEM
        lw.s    $3,  4($1)     # Weight SCPAD
        lw.s    $21, 8($1)     # Input  GMEM
        lw.s    $22, 12($1)    # Input  SCPAD
        lw.s    $24, 16($1)    # Output GMEM
        lw.s    $23, 20($1)    # Output SCPAD

        scpad.ld $3, $2, {SDMA_IDX}, {SDMA_IDX}, {SID0}

        lui.s   $6, 0
        addi.s  $6, $6, 0xf
        mv.stm  1, $6

        addi.s  $27, $0, 0
        addi.s  $28, $0, {N}

    gf_weights_loop:
        vreg.ld $10, $3, {SDMA_IDX}, {SDMA_IDX}, {SID0}, 1, $27
        lw.vi   $10, $10, 0, 0xf
        addi.s  $27, $27, 1
        blt.s   $27, $28, gf_weights_loop

        scpad.ld $22, $21, {SDMA_IDX}, {SDMA_IDX}, {SID0}
        scpad.ld $23, $24, {SDMA_IDX}, {SDMA_IDX}, {SID1}

        addi.s  $25, $0, 0
        addi.s  $29, $0, {NUM_TILES}

    gf_tile_loop:
        addi.s  $27, $0, 0
        vreg.ld $4, $22, {SDMA_IDX}, {SDMA_IDX}, {SID0}, 1, $27
        vreg.ld $5, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $27

        addi.s  $28, $0, 1
        addi.s  $26, $0, {N}

    gf_pipeline_loop:
        gemm.vv $6, $4, $5, 0, 0

        bge.s   $28, $26, gf_skip_fetch_2
        vreg.ld $14, $22, {SDMA_IDX}, {SDMA_IDX}, {SID0}, 1, $28
        vreg.ld $15, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $28

    gf_skip_fetch_2:
        vreg.st $6, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $27

        addi.s  $27, $27, 1
        addi.s  $28, $28, 1

        bge.s   $27, $26, gf_pipeline_done

        gemm.vv $6, $14, $15, 0, 0

        bge.s   $28, $26, gf_skip_fetch_1
        vreg.ld $4, $22, {SDMA_IDX}, {SDMA_IDX}, {SID0}, 1, $28
        vreg.ld $5, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $28

    gf_skip_fetch_1:
        vreg.st $6, $23, {SDMA_IDX}, {SDMA_IDX}, {SID1}, 1, $27

        addi.s  $27, $27, 1
        addi.s  $28, $28, 1
        blt.s   $27, $26, gf_pipeline_loop

    gf_pipeline_done:
        addi.s  $25, $25, 1
        bge.s   $25, $29, gf_tile_loop_done
        addi.s  $21, $21, {TILE_BYTES}
        scpad.ld $22, $21, {SDMA_IDX}, {SDMA_IDX}, {SID0}
        blt.s   $25, $29, gf_tile_loop

    gf_tile_loop_done:
        scpad.st $23, $24, {SDMA_IDX}, {SDMA_IDX}, {SID1}

        jalr    $0, $31, 0
    """

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
