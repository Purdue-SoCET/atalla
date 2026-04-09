#!/usr/bin/env python3
"""exp(-x) demo on BF16 (matches validate_build_generators.check_sigmoid).

Scratchpad tile 4×8; mul.vs + expi.vi. Scalar -1.0 uses ``lui.s`` (``li.s`` imm is 25-bit).
"""
from __future__ import annotations

import argparse
import os
from pathlib import Path

import numpy as np

from build import DRAMWriter, assemble_file, emit_test_format, render_testfile

ROWS = 4
WIDTH = 8
W_M1 = WIDTH - 1
H_M1 = ROWS - 1


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=None, help="Output test file")
    args = ap.parse_args()

    row_ops = "\n".join(
        f"""        vreg.ld $4, $9, {W_M1}, {H_M1}, 0, 1, {r}
        mul.vs  $4, $4, $11, 1
        expi.vi $4, $4, 0, 1
        vreg.st $4, $9, {W_M1}, {H_M1}, 0, 1, {r}"""
        for r in range(ROWS)
    )

    asm = f"""
        lw.s    $3, 0($0)
        lw.s    $8, 4($0)

        addi.s  $9, $0, 0
        scpad.ld $9, $3, {W_M1}, {H_M1}, 0

        addi.s  $255, $0, -1
        mv.stm  1, $255
        lui.s   $11, {0xBF800000 >> 7}

{row_ops}

        scpad.st $9, $8, {W_M1}, {H_M1}, 0
        halt.s
    """

    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    tensor = np.array(
        [
            [-4.0, -2.0, -1.0, -0.5, 0.5, 1.0, 2.0, 4.0],
            [-3.0, -1.5, -0.25, 0.25, 0.75, 1.5, 3.0, 6.0],
            [-5.0, -2.5, -1.25, 0.0, 1.25, 2.5, 5.0, 7.0],
            [-6.0, -3.0, -1.75, 0.1, 1.75, 3.0, 6.0, 8.0],
        ],
        dtype=np.float32,
    )

    INPUT_BASE = 0x00001000
    OUTPUT_BASE = 0x00001040

    img = DRAMWriter()
    for r in range(ROWS):
        for c in range(WIDTH):
            img.bf16(INPUT_BASE + 2 * (r * WIDTH + c), float(tensor[r, c]))

    img.u32(0x0, INPUT_BASE)
    img.u32(0x4, OUTPUT_BASE)
    data_text = img.render_data_mem(include_zeros=False)
    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
    else:
        print(final)


if __name__ == "__main__":
    main()
