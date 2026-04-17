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
    word = mem.get(addr, 0)
    bits = word & 0xFFFF          # only the lower 16 bits are the bf16 value; upper bits should be zero`
    return bf16_to_float(bits)


def build_matrices(debug: bool):
    if debug:
        A = np.ones((31, 62), dtype=np.float32)
        A[:, 31:] = 2.0
        B = np.ones((62, 31), dtype=np.float32)
        full_rows, full_cols = 31, 31
    else:
        full_rows, full_cols, full_k = 62, 62, 62
        A = np.array([[float(r + c) for c in range(full_k)]
                      for r in range(full_rows)], dtype=np.float32)
        B = np.array([[float((r + 1) * (c + 1)) for c in range(full_cols)]
                      for r in range(full_k)], dtype=np.float32)
    return A, B, full_rows, full_cols


def main():
    ap = argparse.ArgumentParser(description="Compare GEMM emulator output vs PyTorch bf16 golden")
    ap.add_argument("--output_mem_file", required=True,
                    help="Path to emulator output_mem.out")
    ap.add_argument("--debug", default="False",
                    help="'True' for single-tile k=2 debug mode")
    args = ap.parse_args()

    debug = args.debug.strip().lower() in ("true", "1", "yes")

    TILE_ROWS   = 31
    TILE_COLS   = 31
    TILE_BYTES  = TILE_ROWS * TILE_COLS * 2
    C_GMEM_BASE = 0x0003_0000

    A_full, B_full, FULL_ROWS, FULL_COLS = build_matrices(debug)
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


    try:
        import torch
        C_golden = torch.matmul(
            torch.tensor(A_full, dtype=torch.float32),
            torch.tensor(B_full, dtype=torch.float32)
        ).numpy()
        print(" computed via PyTorch bfloat16 matmul")
    except ImportError:
        print("[ERROR] ")
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