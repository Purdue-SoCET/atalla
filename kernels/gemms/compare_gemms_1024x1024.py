import argparse
import struct
import re
import sys
import numpy as np


def bf16_to_float(bits: int) -> float:
    return struct.unpack('<f', struct.pack('<I', bits << 16))[0]

def to_bf16(x: np.ndarray) -> np.ndarray:
    x = np.asarray(x, dtype=np.float32)
    u = x.view(np.uint32).copy()
    lsb = (u >> 16) & np.uint32(1)
    u_round = u + np.uint32(0x7FFF) + lsb
    u_bf16 = (u_round & np.uint32(0xFFFF0000)).astype(np.uint32)
    return u_bf16.view(np.float32)

def read_output_mem(mem_file: str) -> dict:
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
    ba = int(addr)
    wa = ba & ~3
    w = mem.get(wa, 0)
    if ba & 2:
        bits = (w >> 16) & 0xFFFF
    else:
        bits = w & 0xFFFF
    if bits == 0 and wa not in mem and ba in mem:
        bits = mem.get(ba, 0) & 0xFFFF
    return bf16_to_float(bits)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--output_mem_file", required=True)
    args = ap.parse_args()

    TILE_ROWS  = 31
    TILE_COLS  = 31
    TILE_BYTES = TILE_ROWS * TILE_COLS * 2

    FULL_ROWS = 1024
    FULL_COLS = 1024
    FULL_K    = 1024

    NUM_TILE_ROWS = (FULL_ROWS + TILE_ROWS - 1) // TILE_ROWS
    NUM_TILE_COLS = (FULL_COLS + TILE_COLS - 1) // TILE_COLS
    NUM_TILE_K    = (FULL_K   + TILE_COLS - 1) // TILE_COLS

    B_GMEM_BASE = 0x0001_0000
    A_GMEM_BASE = B_GMEM_BASE + NUM_TILE_K * NUM_TILE_COLS * TILE_BYTES + 0x1000
    C_GMEM_BASE = A_GMEM_BASE + NUM_TILE_ROWS * NUM_TILE_K * TILE_BYTES + 0x1000

    print("=" * 60)
    print(f"FULL MODE: {FULL_ROWS}x{FULL_COLS}  tile grid {NUM_TILE_ROWS}x{NUM_TILE_COLS}")
    print(f"C_GMEM_BASE = 0x{C_GMEM_BASE:08X}")
    print("=" * 60)
    print()

    # ── Step 1: read emulator output ──────────────────────────────
    print("[MEM] Reading emulator output...")
    try:
        mem = read_output_mem(args.output_mem_file)
    except FileNotFoundError:
        print(f"[ERROR] File not found: {args.output_mem_file}")
        sys.exit(1)
    print(f"  Loaded {len(mem)} words")

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

    print(f"  C[0,0]   = {C_emulator[0,0]:.4f}")
    print(f"  C[-1,-1] = {C_emulator[-1,-1]:.4f}")
    print()

    # ── Step 2: build bf16-accurate tiled golden ──────────────────
    print("[GOLDEN] Building bf16-accurate tiled golden...")
    rows_a = np.arange(FULL_ROWS, dtype=np.float32)
    cols_a = np.arange(FULL_K,    dtype=np.float32)
    A_bf16 = to_bf16(rows_a[:, None] + cols_a[None, :])

    rows_b = np.arange(1, FULL_K    + 1, dtype=np.float32)
    cols_b = np.arange(1, FULL_COLS + 1, dtype=np.float32)
    B_bf16 = to_bf16(rows_b[:, None] * cols_b[None, :])

    C_golden = np.zeros((FULL_ROWS, FULL_COLS), dtype=np.float32)

    for tj in range(NUM_TILE_COLS):
        print(f"  Golden tj={tj}/{NUM_TILE_COLS}...", flush=True)
        for tk in range(NUM_TILE_K):
            r0_b = tk * TILE_ROWS
            c0_b = tj * TILE_COLS
            B_tile = B_bf16[r0_b:min(r0_b+TILE_ROWS, FULL_K),
                            c0_b:min(c0_b+TILE_COLS, FULL_COLS)]

            for ti in range(NUM_TILE_ROWS):
                r0_a = ti * TILE_ROWS
                c0_a = tk * TILE_COLS
                A_tile = A_bf16[r0_a:min(r0_a+TILE_ROWS, FULL_ROWS),
                                c0_a:min(c0_a+TILE_COLS, FULL_K)]

                tile_result = A_tile @ B_tile

                r_end = min(r0_a + TILE_ROWS, FULL_ROWS)
                c_end = min(c0_b + TILE_COLS, FULL_COLS)
                C_golden[r0_a:r_end, c0_b:c_end] += tile_result

                if tk < NUM_TILE_K - 1:
                    C_golden[r0_a:r_end, c0_b:c_end] = to_bf16(
                        C_golden[r0_a:r_end, c0_b:c_end]
                    )

    C_golden = to_bf16(C_golden)
    print(f"  C[0,0]   = {C_golden[0,0]:.4f}")
    print(f"  C[-1,-1] = {C_golden[-1,-1]:.4f}")
    print()

    # ── Step 3: compare ───────────────────────────────────────────
    abs_diff  = np.abs(C_emulator - C_golden)
    rel_diff  = abs_diff / (np.abs(C_golden) + 1e-8)

    max_abs   = float(abs_diff.max())
    mean_abs  = float(abs_diff.mean())
    max_rel   = float(rel_diff.max())
    worst_idx = np.unravel_index(abs_diff.argmax(), abs_diff.shape)

    rel_tol = 0.01
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
            r0 = ti * TILE_ROWS;  re_ = min(TILE_ROWS, FULL_ROWS - r0)
            c0 = tj * TILE_COLS;  ce_ = min(TILE_COLS, FULL_COLS - c0)
            t_abs = float(abs_diff[r0:r0+re_, c0:c0+ce_].max())
            t_rel = float(rel_diff[r0:r0+re_, c0:c0+ce_].max())
            passed = (t_abs <= abs_tol) or (t_rel <= rel_tol)
            if not passed:
                all_pass = False
            status = "PASS" if passed else "FAIL"
            print(f"  C[{ti:2d},{tj:2d}]: max_abs={t_abs:14.4f}  max_rel={t_rel*100:7.4f}%  {status}")

    if not all_pass:
        true_fails = np.argwhere((abs_diff > abs_tol) & (rel_diff > rel_tol))
        print(f"\n  {len(true_fails)} elements fail both tolerances (first 20):")
        for idx in true_fails[:20]:
            r, c = idx
            print(f"    C[{r:4d},{c:4d}]: golden={C_golden[r,c]:14.4f}  "
                  f"emulator={C_emulator[r,c]:14.4f}  "
                  f"rel={rel_diff[r,c]*100:.4f}%")

    print()
    if all_pass:
        print("[COMPARE] PASSED — emulator output matches golden reference")
        sys.exit(0)
    else:
        print("[COMPARE] FAILED — emulator output does not match golden")
        sys.exit(1)


if __name__ == "__main__":
    main()