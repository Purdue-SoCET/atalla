#!/usr/bin/env python3
"""Sigmoid kernel test generator (shared assembler + encodings from build.py)."""
from __future__ import annotations

import argparse
import os
from pathlib import Path

import numpy as np

from build import DRAMWriter, assemble_file, emit_test_format, render_testfile

_MC = 31
_N = 32


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=None, help="Output test file")
    args = ap.parse_args()

    # Vector div was removed from ISA; this generator needs a rewrite using
    # currently supported ops before it can emit valid assembly.
    raise NotImplementedError(
        "build_sigmoid.py still depends on removed div.vv; rewrite required."
    )

    # Keep the assembly skeleton for future rewrite (currently unreachable due
    # NotImplementedError above). Vector division has been removed from ISA.
    row_ops = ""

    asm_pipeline = f"""
        addi.s  $1, $0, 4
        addi.s  $7, $0, 8
        lw.s    $3, 0($0)
        lw.s    $8, 4($0)
        addi.s  $9, $0, 0

        scpad.ld $9, $3, {_MC}, {_MC}, 0

        addi.s  $255, $0, -1
        mv.stm  1, $255

        li.s    $5, 0x3f800000
        li.s    $11, 0xbf800000
        add.vs  $2, $10, $5, 1

{row_ops}

        scpad.st $9, $8, {_MC}, {_MC}, 0
        halt.s
    """

    instrs = assemble_file(asm_pipeline)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    rng = np.random.default_rng(1)
    tensor = rng.standard_normal((_N, _N)).astype(np.float32)

    INPUT_BASE = 0x00001000
    OUTPUT_BASE = 0x00002000
    addr = INPUT_BASE
    for x in tensor.flatten(order="C"):
        img.bf16(addr, float(x))
        addr += 2

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
