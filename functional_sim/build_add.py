from __future__ import annotations

import argparse
import os
from pathlib import Path

import numpy as np

try:
    from .build import DRAMWriter, assemble_file, emit_test_format, render_testfile
except Exception:
    from build import DRAMWriter, assemble_file, emit_test_format, render_testfile


def make_add_asm(rows: int, width: int) -> str:
    w_m1 = width - 1
    h_m1 = rows - 1
    return f"""
        addi.s  $1, $0, 60
        lw.s    $2, 0($1)           # A_GMEM
        lw.s    $3, 4($1)           # B_GMEM
        lw.s    $4, 8($1)           # C_GMEM

        addi.s  $10, $0, 0
        scpad.ld $10, $2, {w_m1}, {h_m1}, 0   # A -> SP0
        scpad.ld $10, $3, {w_m1}, {h_m1}, 1   # B -> SP1

        addi.s  $20, $0, -1
        mv.stm  1, $20                         # mask1 = all lanes

        addi.s  $25, $0, 0
        addi.s  $26, $0, {rows}
row_loop:
        bge.s   $25, $26, row_done
        vreg.ld $40, $10, {w_m1}, {h_m1}, 0, 1, $25
        vreg.ld $41, $10, {w_m1}, {h_m1}, 1, 1, $25
        add.vv  $42, $40, $41, 1, 0
        vreg.st $42, $10, {w_m1}, {h_m1}, 0, 1, $25
        addi.s  $25, $25, 1
        blt.s   $25, $26, row_loop
row_done:
        scpad.st $10, $4, {w_m1}, {h_m1}, 0
        halt.s
    """


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/add.in"))
    ap.add_argument("--rows", type=int, default=32)
    ap.add_argument("--width", type=int, default=32)
    ap.add_argument("--seed", type=int, default=42)
    args = ap.parse_args()

    rows, width = args.rows, args.width
    if width > 32:
        raise ValueError("width must be <= 32")
    if rows < 1 or width < 1:
        raise ValueError("rows and width must be >= 1")

    ADDR_TABLE = 60
    A_GMEM = 0x1000
    B_GMEM = 0x1080
    C_GMEM = 0x1100

    rng = np.random.default_rng(args.seed)
    A = rng.standard_normal((rows, width)).astype(np.float32)
    B = rng.standard_normal((rows, width)).astype(np.float32)

    asm = make_add_asm(rows, width)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(ADDR_TABLE + 0, A_GMEM)
    img.u32(ADDR_TABLE + 4, B_GMEM)
    img.u32(ADDR_TABLE + 8, C_GMEM)
    for r in range(rows):
        for c in range(width):
            img.bf16(A_GMEM + (r * width + c) * 2, float(A[r, c]))
            img.bf16(B_GMEM + (r * width + c) * 2, float(B[r, c]))
    for i in range(rows * width):
        img.bf16(C_GMEM + i * 2, 0.0)

    final = render_testfile(instr_text, img.render_data_mem(include_zeros=True))
    os.makedirs(args.output.parent, exist_ok=True)
    args.output.write_text(final)
    print(f"Wrote {args.output}")


if __name__ == "__main__":
    main()

