from __future__ import annotations

import argparse
import os
from pathlib import Path

import numpy as np

try:
    from .build import DRAMWriter, assemble_file, emit_test_format, render_testfile
except Exception:
    from build import DRAMWriter, assemble_file, emit_test_format, render_testfile


def make_maxpool_asm(h_in: int, w_in: int, pool_size: int, stride: int) -> str:
    if pool_size != 2 or stride != 2:
        raise ValueError("Current maxpool kernel supports pool=2, stride=2 only.")

    h_out = (h_in - pool_size) // stride + 1
    w_m1 = w_in - 1
    h_in_m1 = h_in - 1
    h_out_m1 = h_out - 1
    mask_all = (1 << w_in) - 1 if w_in < 32 else (1 << 32) - 1
    if w_in >= 32:
        mask_load = """
        addi.s  $20, $0, -1
        mv.stm  1, $20              # mask1 = all lanes (32-wide)"""
    else:
        mask_load = f"""
        lui.s   $20, {mask_all >> 7}
        addi.s  $20, $20, {mask_all & 0x7F}
        mv.stm  1, $20              # mask1 = active width lanes"""

    return f"""
        addi.s  $1, $0, 60
        lw.s    $2, 0($1)           # IN_GMEM
        lw.s    $3, 4($1)           # IN_SCPAD row
        lw.s    $4, 8($1)           # OUT_GMEM
        lw.s    $5, 12($1)          # OUT_SCPAD row

        scpad.ld $3, $2, {w_m1}, {h_in_m1}, 0
{mask_load}

        li.s    $6, 0
        mul.vs  $60, $10, $6, 1     # zero vector (no addi.vi)
        addi.s  $25, $0, 0          # out_row
        addi.s  $26, $0, {h_out}    # out_row limit
        addi.s  $29, $0, 0          # in_row_base

out_row_loop:
        bge.s   $25, $26, out_done
        vreg.ld $40, $3, {w_m1}, {h_in_m1}, 0, 1, $29
        addi.s  $27, $29, 1
        vreg.ld $41, $3, {w_m1}, {h_in_m1}, 0, 1, $27

        add.vv  $50, $40, $60, 1, 0
        mgt.mvv 2, $41, $40, 1
        add.vv  $50, $41, $60, 2, 0
        vreg.st $50, $5, {w_m1}, {h_out_m1}, 1, 1, $25

        addi.s  $29, $29, {stride}
        addi.s  $25, $25, 1
        blt.s   $25, $26, out_row_loop
out_done:
        scpad.st $5, $4, {w_m1}, {h_out_m1}, 1
        halt.s
    """


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/maxpool.in"))
    ap.add_argument("--H", type=int, default=32)
    ap.add_argument("--W", type=int, default=32)
    ap.add_argument("--pool", type=int, default=2)
    ap.add_argument("--stride", type=int, default=2)
    ap.add_argument("--seed", type=int, default=7)
    args = ap.parse_args()

    h_in, w_in = args.H, args.W
    if w_in > 32:
        raise ValueError("W must be <= 32")
    h_out = (h_in - args.pool) // args.stride + 1
    if h_out < 1:
        raise ValueError("Invalid H/pool/stride combination")

    ADDR_TABLE = 60
    IN_GMEM = 0x1000
    IN_SCPAD = 0
    OUT_GMEM = 0x2000
    OUT_SCPAD = 0

    rng = np.random.default_rng(args.seed)
    tile = rng.standard_normal((h_in, w_in)).astype(np.float32)

    asm = make_maxpool_asm(h_in, w_in, args.pool, args.stride)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(ADDR_TABLE + 0, IN_GMEM)
    img.u32(ADDR_TABLE + 4, IN_SCPAD)
    img.u32(ADDR_TABLE + 8, OUT_GMEM)
    img.u32(ADDR_TABLE + 12, OUT_SCPAD)
    for r in range(h_in):
        for c in range(w_in):
            img.bf16(IN_GMEM + (r * w_in + c) * 2, float(tile[r, c]))
    for i in range(h_out * w_in):
        img.bf16(OUT_GMEM + i * 2, 0.0)

    final = render_testfile(instr_text, img.render_data_mem(include_zeros=True))
    os.makedirs(args.output.parent, exist_ok=True)
    args.output.write_text(final)
    print(f"Wrote {args.output}")


if __name__ == "__main__":
    main()

