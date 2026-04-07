import argparse
import struct
import re
import sys
import numpy as np


def bf16_to_float(bits: int) -> float:
    return struct.unpack('<f', struct.pack('<I', bits << 16))[0]


def read_output_mem(mem_file: str) -> dict:
    """
    Parse DATA MEM section of emulator output file.
    Each line: ADDR: VALUE  (stride-2, VALUE is a u16 bf16 in low bits)
    Returns {addr: u16_bits}.
    """
    mem = {}
    in_data = False
    with open(mem_file) as f:
        for line in f:
            line = line.strip()
            if line == 'DATA MEM':
                in_data = True
                continue
            if not in_data:
                continue
            m = re.match(r'([0-9A-Fa-f]+)\s*:\s*([0-9A-Fa-f]+)', line)
            if m:
                mem[int(m.group(1), 16)] = int(m.group(2), 16)
    return mem


def read_bf16(mem: dict, addr: int) -> float:
    word = mem.get(addr, 0)
    bits = word & 0xFFFF
    return bf16_to_float(bits)


def main():
    ap = argparse.ArgumentParser(description="Compare 1024x1024 GEMM emulator output vs float32 golden")
    ap.add_argument("--output_mem_file", required=True,
                    help="Path to emulator output_mem.out")
    args = ap.parse_args()

    TILE_ROWS  = 31
    TILE_COLS  = 31
    TILE_BYTES = TILE_ROWS * TILE_COLS * 2   # 1922

    FULL_ROWS = 1024
    FULL_COLS = 1024
    FULL_K    = 1024

    NUM_TILE_ROWS = (FULL_ROWS + TILE_ROWS - 1) // TILE_ROWS   # 34
    NUM_TILE_COLS = (FULL_COLS + TILE_COLS - 1) // TILE_COLS   # 34

    # Must match build script
    B_GMEM_BASE  = 0x0001_0000
    NUM_TILE_K   = (FULL_K + TILE_COLS - 1) // TILE_COLS       # 34
    A_GMEM_BASE  = B_GMEM_BASE + NUM_TILE_K * NUM_TILE_COLS * TILE_BYTES + 0x1000
    C_GMEM_BASE  = A_GMEM_BASE + NUM_TILE_ROWS * NUM_TILE_K  * TILE_BYTES + 0x1000

    print("=" * 60)
    print(f"FULL MODE: {FULL_ROWS}x{FULL_COLS}  tile grid {NUM_TILE_ROWS}x{NUM_TILE_COLS}")
    print(f"C_GMEM_BASE = 0x{C_GMEM_BASE:08X}")
    print("=" * 60)
    print()

    print("[GOLDEN] Building matrices and computing float32 reference...")
    A_full = np.array([[float(r + c) for c in range(FULL_K)]
                       for r in range(FULL_ROWS)], dtype=np.float32)
    B_full = np.array([[float((r + 1) * (c + 1)) for c in range(FULL_COLS)]
                       for r in range(FULL_K)], dtype=np.float32)
    # A_full = np.ones((FULL_ROWS, FULL_K), dtype=np.float32)
    # B_full = np.ones((FULL_K, FULL_COLS), dtype=np.float32)

    C_golden = A_full @ B_full
    print(f"  C[0,0]     = {C_golden[0,0]:.4f}")
    print(f"  C[-1,-1]   = {C_golden[-1,-1]:.4f}")
    print()

    try:
        mem = read_output_mem(args.output_mem_file)
    except FileNotFoundError:
        print(f"[ERROR] File not found: {args.output_mem_file}")
        sys.exit(1)

    print(f"[MEM] Loaded {len(mem)} words from {args.output_mem_file}")

    # Sanity: check C[0,0] tile first element
    sanity_val = mem.get(C_GMEM_BASE, 0) & 0xFFFF
    print(f"  Sanity: mem[0x{C_GMEM_BASE:08X}] = 0x{sanity_val:04X} = {bf16_to_float(sanity_val):.1f}")
    print()

    print("[RECONSTRUCT] Reading C tiles from emulator output...")
    C_emulator = np.zeros((FULL_ROWS, FULL_COLS), dtype=np.float32)

    for ti in range(NUM_TILE_ROWS):
        for tj in range(NUM_TILE_COLS):
            tile_idx  = ti * NUM_TILE_COLS + tj
            tile_base = C_GMEM_BASE + tile_idx * TILE_BYTES
            r0 = ti * TILE_ROWS
            c0 = tj * TILE_COLS
            rows_this = min(TILE_ROWS, FULL_ROWS - r0)
            cols_this = min(TILE_COLS, FULL_COLS - c0)
            for r in range(rows_this):
                for c in range(cols_this):
                    addr = tile_base + (r * TILE_COLS + c) * 2
                    C_emulator[r0 + r, c0 + c] = read_bf16(mem, addr)

    print(f"  C[0,0]     = {C_emulator[0,0]:.4f}")
    print(f"  C[-1,-1]   = {C_emulator[-1,-1]:.4f}")
    print()

    abs_diff  = np.abs(C_emulator - C_golden)
    rel_diff  = abs_diff / (np.abs(C_golden) + 1e-8)

    max_abs   = float(abs_diff.max())
    mean_abs  = float(abs_diff.mean())
    max_rel   = float(rel_diff.max())
    worst_idx = np.unravel_index(abs_diff.argmax(), abs_diff.shape)

    # 6% relative tolerance: covers bf16 store rounding across 34 k-tile accumulations
    rel_tol = 0.06
    abs_tol = max(1.0, float(np.abs(C_golden).mean()) * rel_tol)

    print(f"── Error Summary ───────────────────────────────────────")
    print(f"  Tolerance      : abs≤{abs_tol:.2f}  OR  rel≤{rel_tol*100:.1f}%")
    print(f"  Max  abs error : {max_abs:.4f}  at C{worst_idx}")
    print(f"  Mean abs error : {mean_abs:.4f}")
    print(f"  Max  rel error : {max_rel*100:.4f}%")
    print(f"  Golden  worst  : {C_golden[worst_idx]:.4f}")
    print(f"  Emulator worst : {C_emulator[worst_idx]:.4f}")

    print(f"\n── Per-tile Results ────────────────────────────────────")
    all_pass = True
    for ti in range(NUM_TILE_ROWS):
        for tj in range(NUM_TILE_COLS):
            r0 = ti * TILE_ROWS
            c0 = tj * TILE_COLS
            re_ = min(TILE_ROWS, FULL_ROWS - r0)
            ce_ = min(TILE_COLS, FULL_COLS - c0)
            t_abs = float(abs_diff[r0:r0+re_, c0:c0+ce_].max())
            t_rel = float(rel_diff[r0:r0+re_, c0:c0+ce_].max())
            passed = (t_abs <= abs_tol) or (t_rel <= rel_tol)
            status = "PASS" if passed else "FAIL"
            if not passed:
                all_pass = False
            print(f"  C[{ti:2d},{tj:2d}]: max_abs={t_abs:14.4f}  max_rel={t_rel*100:7.4f}%  {status}")

    if not all_pass:
        true_fails = np.argwhere((abs_diff > abs_tol) & (rel_diff > rel_tol))
        print(f"\n  {len(true_fails)} elements fail both tolerances (showing first 20):")
        for idx in true_fails[:20]:
            r, c = idx
            print(f"    C[{r:4d},{c:4d}]: "
                  f"golden={C_golden[r,c]:14.4f}  "
                  f"emulator={C_emulator[r,c]:14.4f}  "
                  f"abs={abs_diff[r,c]:.4f}  "
                  f"rel={rel_diff[r,c]*100:.4f}%")
        if len(true_fails) > 20:
            print(f"    ... and {len(true_fails)-20} more")

    print()
    if all_pass:
        print("[COMPARE] PASSED — emulator output matches golden reference")
        sys.exit(0)
    else:
        print("[COMPARE] FAILED — emulator output does not match golden")
        sys.exit(1)


if __name__ == "__main__":
    main()