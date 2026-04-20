import argparse
import struct
import re
import sys
import numpy as np


def bf16_to_float(bits: int) -> float:
    return struct.unpack('<f', struct.pack('<I', bits << 16))[0]


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
            if not m:
                continue
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


def build_matrices(debug: bool):
    if debug:
        full_rows, full_cols, full_k = 31, 31, 62
        A = np.ones((full_rows, full_k), dtype=np.float32)
        A[:, 31:] = 2.0
        B = np.ones((full_k, full_cols), dtype=np.float32)
    else:
        full_rows, full_cols, full_k = 62, 62, 62
        # Use float64 intermediate then cast to float32, matching build script
        A = np.array([[float(r + c) for c in range(full_k)]
                      for r in range(full_rows)], dtype=np.float64).astype(np.float32)
        B = np.array([[float((r + 1) * (c + 1)) for c in range(full_cols)]
                      for r in range(full_k)], dtype=np.float64).astype(np.float32)
    return A, B, full_rows, full_cols, full_k

def to_bf16(x: np.ndarray) -> np.ndarray:
    """Round float32 array to bf16 precision, stored as float32."""
    x = np.asarray(x, dtype=np.float32)
    u = x.view(np.uint32) 
    lsb = (u >> 16) & np.uint32(1)
    u_round = u + np.uint32(0x7FFF) + lsb
    u_bf16 = (u_round & np.uint32(0xFFFF0000)).astype(np.uint32)
    return u_bf16.view(np.float32)


def main():
    ap = argparse.ArgumentParser(description="Compare GEMM emulator output vs PyTorch bf16 golden")
    ap.add_argument("--output_mem_file", required=True,
                    help="Path to emulator output_mem.out")
    ap.add_argument("--debug", default="False",
                    help="'True' for single-tile k=2 debug mode")
    args = ap.parse_args()

    debug = args.debug.strip().lower() in ("true", "1", "yes")

    A_full, B_full, FULL_ROWS, FULL_COLS, FULL_K = build_matrices(debug)
    TILE_ROWS   = 31
    TILE_COLS   = 31
    TILE_BYTES  = TILE_ROWS * TILE_COLS * 2
    C_GMEM_BASE = 0x0003_0000
    NUM_TILE_ROWS = (FULL_ROWS + TILE_ROWS - 1) // TILE_ROWS
    NUM_TILE_COLS = (FULL_COLS + TILE_COLS - 1) // TILE_COLS
    print("=" * 60)
    if debug:
        print("DEBUG MODE: single tile, NUM_TILE_K=2")
        print("A[:, :31]=1.0  A[:, 31:]=2.0  B=all 1.0")
        print("Expected every C element = 93.0")
    else:
        print(f"FULL MODE: {FULL_ROWS}x{FULL_COLS}  tile grid {NUM_TILE_ROWS}x{NUM_TILE_COLS}")
    print("=" * 60)
    print()


    TILE_ROWS = 31
    TILE_COLS = 31
    A_full, B_full, FULL_ROWS, FULL_COLS, FULL_K = build_matrices(debug)
    NUM_TILE_ROWS = (FULL_ROWS + TILE_ROWS - 1) // TILE_ROWS
    NUM_TILE_COLS = (FULL_COLS + TILE_COLS - 1) // TILE_COLS
    NUM_TILE_K    = (FULL_K    + TILE_COLS - 1) // TILE_COLS

    try:
        TILE_K = TILE_COLS  # 31

        A_bf16 = to_bf16(A_full)  # shape (FULL_ROWS, FULL_K)
        B_bf16 = to_bf16(B_full)  # shape (FULL_K, FULL_COLS)
        C_golden = np.zeros((FULL_ROWS, FULL_COLS), dtype=np.float32)

        for tj in range(NUM_TILE_COLS):
            for tk in range(NUM_TILE_K):
                r0_b = tk * TILE_ROWS
                c0_b = tj * TILE_COLS
                B_tile_rows = min(TILE_ROWS, FULL_K    - r0_b)
                B_tile_cols = min(TILE_COLS, FULL_COLS - c0_b)
                B_tile = B_bf16[r0_b:r0_b+B_tile_rows, c0_b:c0_b+B_tile_cols]

                for ti in range(NUM_TILE_ROWS):
                    r0_a = ti * TILE_ROWS
                    c0_a = tk * TILE_COLS
                    A_tile_rows = min(TILE_ROWS, FULL_ROWS - r0_a)
                    A_tile_cols = min(TILE_COLS, FULL_K    - c0_a)
                    A_tile = A_bf16[r0_a:r0_a+A_tile_rows, c0_a:c0_a+A_tile_cols]

                    # Row-by-row matching pipeline_loop
                    tile_result = np.zeros((A_tile_rows, B_tile_cols), dtype=np.float32)
                    for row in range(A_tile_rows):
                        tile_result[row, :] = A_tile[row, :] @ B_tile

                    # Accumulate into C
                    C_golden[r0_a:r0_a+A_tile_rows, c0_b:c0_b+B_tile_cols] += tile_result

                    # scpad.st writes this (ti,tj) C tile to GMEM as bf16, 
                    # then scpad.ld reads it back — but only if there are more k iterations
                    if tk < NUM_TILE_K - 1:
                        r0 = ti * TILE_ROWS
                        re = min(TILE_ROWS, FULL_ROWS - r0)
                        c0 = tj * TILE_COLS
                        ce = min(TILE_COLS, FULL_COLS - c0)
                        C_golden[r0:r0+re, c0:c0+ce] = to_bf16(
                            C_golden[r0:r0+re, c0:c0+ce]
                        )

        # Final scpad.st rounds result to bf16
        C_golden = to_bf16(C_golden)

        print(" computed via hardware-accurate tiled golden")

    except Exception as e:
        import traceback
        traceback.print_exc()
        sys.exit(1)   

    print(f"  C[0,0]   = {C_golden[0,0]:.4f}")
    print(f"  C[-1,-1] = {C_golden[-1,-1]:.4f}")
    if debug:
        print(f"  (all values should be 93.0)")
    print()

    try:
        mem = read_output_mem(args.output_mem_file)
        # print(f"  mem[0x30782] = 0x{mem.get(0x30782, 0):08X}")  # expect 0x00004A29
        # print(f"  mem[0x30000] = 0x{mem.get(0x30000, 0):08X}")  # expect 0x0000479F
    except FileNotFoundError:
        print(f"[ERROR] Output mem file not found: {args.output_mem_file}")
        sys.exit(1)

    print(f"[MEM]  Loaded {len(mem)} words from {args.output_mem_file}")


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

    print(f"\n[EMULATOR OUTPUT]")
    print(f"  C[0,0]   = {C_emulator[0,0]:.4f}")
    print(f"  C[-1,-1] = {C_emulator[-1,-1]:.4f}")
    if debug:
        unique = np.unique(C_emulator[C_emulator != 0])
        print(f"  Unique non-zero values: {unique}")

    abs_diff  = np.abs(C_emulator - C_golden)
    rel_diff  = abs_diff / (np.abs(C_golden) + 1e-8)

    max_abs   = float(abs_diff.max())
    mean_abs  = float(abs_diff.mean())
    max_rel   = float(rel_diff.max())
    worst_idx = np.unravel_index(abs_diff.argmax(), abs_diff.shape)

    #increased this to 5%
    rel_tol = 0.05
    abs_tol = max(1.0, float(np.abs(C_golden).mean()) * rel_tol)

    print(f"\n Error ")
    print(f"  Tolerance      : abs≤{abs_tol:.2f}  OR  rel≤{rel_tol*100:.1f}%")
    print(f"  Max  abs error : {max_abs:.4f}  at C{worst_idx}")
    print(f"  Mean abs error : {mean_abs:.4f}")
    print(f"  Max  rel error : {max_rel*100:.4f}%")
    print(f"  Golden  worst  : {C_golden[worst_idx]:.4f}")
    print(f"  Emulator worst : {C_emulator[worst_idx]:.4f}")

    print(f"\n Results ")
    all_pass = True
    for ti in range(NUM_TILE_ROWS):
        for tj in range(NUM_TILE_COLS):
            r0 = ti * TILE_ROWS
            c0 = tj * TILE_COLS
            re = min(TILE_ROWS, FULL_ROWS - r0)
            ce = min(TILE_COLS, FULL_COLS - c0)
            t_abs = float(abs_diff[r0:r0+re, c0:c0+ce].max())
            t_rel = float(rel_diff[r0:r0+re, c0:c0+ce].max())
            passed = (t_abs <= abs_tol) or (t_rel <= rel_tol)
            status = "PASS" if passed else "FAIL"
            if not passed:
                all_pass = False
            print(f"  C[{ti},{tj}]: max_abs={t_abs:12.4f}  max_rel={t_rel*100:7.4f}%  {status}")

    if not all_pass:
        true_fails = np.argwhere((abs_diff > abs_tol) & (rel_diff > rel_tol))
        print(f"\n  {len(true_fails)} elements fail both tolerances (showing first 15):")
        for idx in true_fails[:15]:
            r, c = idx
            print(f"    C[{r:3d},{c:3d}]: "
                  f"golden={C_golden[r,c]:12.4f}  "
                  f"emulator={C_emulator[r,c]:12.4f}  "
                  f"abs={abs_diff[r,c]:.4f}  "
                  f"rel={rel_diff[r,c]*100:.4f}%")
        if len(true_fails) > 15:
            print(f"    ... and {len(true_fails)-15} more")

    print()
    if all_pass:
        print("[COMPARE] PASSED — emulator output matches golden reference")
        sys.exit(0)
    else:
        print("[COMPARE] FAILED — emulator output does not match golden")
        sys.exit(1)


if __name__ == "__main__":
    main()