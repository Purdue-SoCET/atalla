#!/usr/bin/env python3
"""
gen_sdma_meminit.py — generate functional_mem preload for test_sdma.sv

Produces a raw binary file covering two contiguous 2MB memory regions:

  Bytes 0x000000 – 0x1FFFFF  (ROW_BASE  = 0x0000_0000)
  Bytes 0x200000 – 0x3FFFFF  (TILE_BASE = 0x0020_0000)

Both regions hold the same 1024×1024 int16 matrix, laid out row-major:
  element[row][col] = (row * MAT_COLS + col) & 0xFFFF

Each 8-byte beat packs 4 consecutive int16 elements (little-endian):
  beat[15:0]  = element at (col_base + 0)
  beat[31:16] = element at (col_base + 1)
  beat[47:32] = element at (col_base + 2)
  beat[63:48] = element at (col_base + 3)

Load into ramulator_sv_wrapper with:
  MEM_INIT_FILE = <output_path>
  MEM_INIT_TYPE = "bin"
  MEM_INIT_BASE = 0

Usage:
  python3 scripts/gen_sdma_meminit.py [output_path]
  output_path defaults to configs/sdma_meminit.bin
"""

import struct
import sys
import os

MAT_ROWS    = 1024
MAT_COLS    = 1024
ELEM_BYTES  = 2       # int16
BEAT_BYTES  = 8       # 64-bit AXI beat
ELEMS_PER_T = BEAT_BYTES // ELEM_BYTES   # 4 elements per beat
COL_GROUPS  = (MAT_COLS * ELEM_BYTES) // BEAT_BYTES  # 256 beats per row
ROW_BYTES   = MAT_COLS * ELEM_BYTES     # 2048 bytes per row

REGION_SIZE = MAT_ROWS * ROW_BYTES      # 2 MB = 0x200000


def pack_beat(row: int, col_base: int) -> int:
    """Pack 4 consecutive int16 elements into one little-endian 64-bit word."""
    val = 0
    for e in range(ELEMS_PER_T):
        elem = (row * MAT_COLS + col_base + e) & 0xFFFF
        val |= elem << (e * 16)
    return val


def generate_region() -> bytearray:
    """Return a bytearray of REGION_SIZE bytes for one 1024×1024 matrix."""
    buf = bytearray(REGION_SIZE)
    for row in range(MAT_ROWS):
        row_off = row * ROW_BYTES
        for cg in range(COL_GROUPS):
            beat = pack_beat(row, cg * ELEMS_PER_T)
            off  = row_off + cg * BEAT_BYTES
            struct.pack_into('<Q', buf, off, beat)
    return buf


def main() -> None:
    out_path = sys.argv[1] if len(sys.argv) > 1 else \
               os.path.join(os.path.dirname(__file__), '..', 'configs', 'sdma_meminit.bin')
    out_path = os.path.normpath(out_path)

    print(f"Generating SDMA meminit binary: {out_path}")
    print(f"  Matrix : {MAT_ROWS}x{MAT_COLS} int16  ({REGION_SIZE:,} bytes per region)")
    print(f"  Regions: ROW_BASE (0x000000) + TILE_BASE (0x200000)")
    print(f"  Total  : {2 * REGION_SIZE:,} bytes ({2 * REGION_SIZE / 1024 / 1024:.1f} MB)")

    region = generate_region()

    with open(out_path, 'wb') as f:
        f.write(region)   # ROW_BASE  @ 0x000000
        f.write(region)   # TILE_BASE @ 0x200000

    size = os.path.getsize(out_path)
    print(f"  Written: {size:,} bytes → {out_path}")


if __name__ == '__main__':
    main()
