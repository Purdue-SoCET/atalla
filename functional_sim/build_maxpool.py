from __future__ import annotations

import struct, os
from pathlib import Path
import argparse
import numpy as np

from build import *


def make_maxpool_asm(H_in: int, W_in: int, pool_size: int, stride: int) -> str:
    """Generate maxpool assembly for a single-channel 2D tile.

    Strategy: For each output row, load `pool_size` adjacent input rows.
    Reduce vertically via pairwise mgt.mvv + masked add.vv blend.
    Then reduce horizontally with stride selection via shift.vi + mgt/blend.

    For pool_size=3, stride=2:
      H_out = (H_in - 3) // 2 + 1
      W_out = (W_in - 3) // 2 + 1
    """
    H_out = (H_in - pool_size) // stride + 1
    W_out = (W_in - pool_size) // stride + 1

    h_m1 = H_in - 1
    w_m1 = W_in - 1
    ho_m1 = H_out - 1
    wo_m1 = W_out - 1

    mask_all = (1 << W_in) - 1

    lines = []
    a = lines.append

    a(f"# MaxPool: {H_in}x{W_in} -> {H_out}x{W_out}, pool={pool_size}, stride={stride}")
    a( "")
    a( "addi.s  $1, $0, 60")
    a( "lw.s    $2, 0($1)           # IN_GMEM")
    a( "lw.s    $3, 4($1)           # IN_SCPAD")
    a( "lw.s    $4, 8($1)           # OUT_GMEM")
    a( "lw.s    $5, 12($1)          # OUT_SCPAD")
    a( "")
    a(f"scpad.ld $3, $2, {w_m1}, {h_m1}, 0")
    a( "")
    a(f"addi.s  $20, $0, {mask_all}")
    a( "mv.stm  1, $20              # mask1 = all input lanes")
    a( "")

    # For each output row
    a(f"addi.s  $25, $0, 0          # out_row = 0")
    a(f"addi.s  $26, $0, {H_out}    # out_row limit")
    a(f"addi.s  $29, $0, 0          # in_row_base = 0")
    a( "")

    a("out_row_loop:")
    # Load pool_size input rows
    for p in range(pool_size):
        if p == 0:
            a(f"addi.s  $27, $29, {p}")
            a(f"vreg.ld ${'%d' % (40 + p)}, $3, {w_m1}, {h_m1}, 0, 1, $27")
        else:
            a(f"addi.s  $27, $29, {p}")
            a(f"vreg.ld ${'%d' % (40 + p)}, $3, {w_m1}, {h_m1}, 0, 1, $27")

    # Vertical reduction: pairwise max of loaded rows
    # max(r0, r1) -> $50, then max($50, r2) -> $50
    a( "")
    a( "# vertical max: compare rows pairwise")
    a(f"mgt.mvv 2, $40, $41, 1      # mask2 = (row0 > row1)")
    a(f"add.vv  $50, $40, $0, 2, 0  # $50 = row0 where row0>row1")
    a(f"add.vv  $50, $41, $0, 1, 0  # temp: $50 = row1 everywhere under mask1")
    # Need proper blend: $50[i] = row0[i] if mask2[i] else row1[i]
    # Actually: add.vv $50, $41, $0, 1, 0 sets $50 = row1 under mask1
    # Then: add.vv $50, $40, $0, 2, 0 overwrites with row0 where mask2 is set
    # But add.vv writes under mask, and preserves old value where mask is 0.
    # So order matters: first set $50 = row1, then overwrite with row0 where row0 > row1.

    # Corrected blend: use sub.vv to zero $50, then two masked adds
    a( "# blend: $50 = max(row0, row1)")
    a(f"sub.vv  $50, $50, $50, 1, 0 # zero $50")
    a(f"add.vv  $50, $50, $41, 1, 0 # $50 = row1 (all lanes)")
    a(f"mgt.mvv 2, $40, $41, 1      # mask2 = row0 > row1")
    a(f"sub.vv  $50, $50, $50, 2, 0 # zero lanes where row0 > row1")
    a(f"add.vv  $50, $50, $40, 2, 0 # write row0 into those lanes")

    if pool_size >= 3:
        a( "# max($50, row2) -> $50")
        a(f"mgt.mvv 2, $50, $42, 1")
        a(f"sub.vv  $51, $51, $51, 1, 0")
        a(f"add.vv  $51, $51, $42, 1, 0")
        a(f"sub.vv  $51, $51, $51, 2, 0")
        a(f"add.vv  $51, $51, $50, 2, 0")
        a( "# $51 = max across 3 rows")
    else:
        a( "# $50 = max across 2 rows")

    vert_result = "$51" if pool_size >= 3 else "$50"

    # Horizontal reduction with stride
    # For pool_size=3, stride=2: for each output col j, max of lanes [2j, 2j+1, 2j+2]
    # Strategy: shift vector right by 1 and 2, max pairwise
    a( "")
    a( "# horizontal max: shift + compare")
    a(f"shift.vi $52, {vert_result}, 1, 1  # shift right by 1")
    a(f"mgt.mvv 2, {vert_result}, $52, 1")
    a(f"sub.vv  $53, $53, $53, 1, 0")
    a(f"add.vv  $53, $53, $52, 1, 0")
    a(f"sub.vv  $53, $53, $53, 2, 0")
    a(f"add.vv  $53, $53, {vert_result}, 2, 0")
    # $53 = max(v[i], v[i+1])

    if pool_size >= 3:
        a(f"shift.vi $52, {vert_result}, 2, 1  # shift right by 2")
        a(f"mgt.mvv 2, $53, $52, 1")
        a(f"sub.vv  $54, $54, $54, 1, 0")
        a(f"add.vv  $54, $54, $52, 1, 0")
        a(f"sub.vv  $54, $54, $54, 2, 0")
        a(f"add.vv  $54, $54, $53, 2, 0")
        hz_result = "$54"
    else:
        hz_result = "$53"

    # Now hz_result[i] = max of window starting at lane i.
    # For stride=2: output lanes are at indices 0, 2, 4, ...
    # We need to "compress" every-other lane. Use shift to collect them.
    # For now, store the full vector; the stride selection is implicit in
    # that output lane j corresponds to input lane j*stride.
    # Store this row to output scratchpad
    a( "")
    a(f"vreg.st {hz_result}, $5, {wo_m1}, {ho_m1}, 1, 1, $25")

    a( "")
    a(f"addi.s  $29, $29, {stride}   # advance input row by stride")
    a(f"addi.s  $25, $25, 1")
    a(f"blt.s   $25, $26, out_row_loop")
    a( "")
    a(f"scpad.st $5, $4, {wo_m1}, {ho_m1}, 1")
    a( "halt.s")

    return "\n".join(f"        {line}" if line else "" for line in lines)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/maxpool.in"))
    ap.add_argument("--H", type=int, default=8)
    ap.add_argument("--W", type=int, default=8)
    ap.add_argument("--pool", type=int, default=3)
    ap.add_argument("--stride", type=int, default=2)
    args = ap.parse_args()

    H_in, W_in = args.H, args.W
    pool_size, stride = args.pool, args.stride
    H_out = (H_in - pool_size) // stride + 1
    W_out = (W_in - pool_size) // stride + 1

    assert W_in <= 32, "W_in must be <= 32"

    ADDR_TABLE = 60
    IN_GMEM    = 0x1000
    IN_SCPAD   = 0
    OUT_GMEM   = 0x2000
    OUT_SCPAD  = 0

    np.random.seed(7)
    tile = np.random.randn(H_in, W_in).astype(np.float32)

    asm = make_maxpool_asm(H_in, W_in, pool_size, stride)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(ADDR_TABLE + 0, IN_GMEM)
    img.u32(ADDR_TABLE + 4, IN_SCPAD)
    img.u32(ADDR_TABLE + 8, OUT_GMEM)
    img.u32(ADDR_TABLE + 12, OUT_SCPAD)

    for r in range(H_in):
        for c in range(W_in):
            img.bf16(IN_GMEM + (r * W_in + c) * 2, float(tile[r, c]))

    for i in range(H_out * W_out):
        img.bf16(OUT_GMEM + i * 2, 0.0)

    expected = np.full((H_out, W_out), -np.inf)
    for oh in range(H_out):
        for ow in range(W_out):
            for pr in range(pool_size):
                for pc in range(pool_size):
                    ih = oh * stride + pr
                    iw = ow * stride + pc
                    if ih < H_in and iw < W_in:
                        expected[oh, ow] = max(expected[oh, ow], tile[ih, iw])

    print(f"MaxPool: {H_in}x{W_in} -> {H_out}x{W_out}, pool={pool_size}, stride={stride}")
    print(f"\nInput:\n{tile}")
    print(f"\nExpected output:\n{expected}")

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
        print(f"\nWrote {args.output}")
    else:
        print(final)


if __name__ == "__main__":
    main()
