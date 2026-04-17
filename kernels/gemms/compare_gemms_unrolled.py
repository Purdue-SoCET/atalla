import argparse, re, struct, sys
import numpy as np


def bf16_to_float(bits: int) -> float:
    return struct.unpack("<f", struct.pack("<I", bits << 16))[0]


def read_output_mem(path: str) -> dict:
    mem, in_data = {}, False
    pat = re.compile(r"([0-9A-Fa-f]+)\s*:\s*([0-9A-Fa-f]+)")
    with open(path) as fh:
        for line in fh:
            line = line.strip()
            if line == "DATA MEM":
                in_data = True
                continue
            if not in_data:
                continue
            m = pat.match(line)
            if m:
                mem[int(m.group(1), 16)] = int(m.group(2), 16)
    return mem


def read_bf16_at(mem: dict, addr: int) -> float:
    return bf16_to_float(mem.get(addr, 0) & 0xFFFF)


def build_golden(rows: int, cols: int) -> np.ndarray:
    try:
        import torch
    except ImportError:
        print("pytorch error")
        sys.exit(1)
    W   = torch.tensor([[float(r+c) for c in range(cols)] for r in range(rows)],
                       dtype=torch.bfloat16)
    inp = torch.tensor([[float(r+1) for c in range(cols)] for r in range(rows)],
                       dtype=torch.bfloat16)
    return torch.matmul(W.T, inp).to(torch.float32).numpy()


def main():
    ap = argparse.ArgumentParser(
        description="Compare 31x31 GEMM emulator output vs PyTorch bfloat16 golden")
    ap.add_argument("--output_mem_file", required=True)
    ap.add_argument("--abs_tol", type=float, default=None)
    ap.add_argument("--rel_tol", type=float, default=0.02)
    args = ap.parse_args()

    ROWS        = 31   
    COLS        = 31
    OUTPUT_GMEM = 0x5000

    print("=" * 60)
    print(f"{ROWS}×{COLS} single-tile GEMM  —  emulator vs PyTorch bfloat16")
    print("=" * 60)

    C_golden = build_golden(ROWS, COLS)
    last = ROWS - 1
    print(f"\n[GOLDEN]")
    print(f"  C[0,0]        = {C_golden[0,0]:.4f}")
    print(f"  C[0,{last}]    = {C_golden[0,last]:.4f}")
    print(f"  C[{last},0]    = {C_golden[last,0]:.4f}")
    print(f"  C[{last},{last}] = {C_golden[last,last]:.4f}")

    try:
        mem = read_output_mem(args.output_mem_file)
    except FileNotFoundError:
        print(f"\n[ERROR] File not found: {args.output_mem_file}")
        sys.exit(1)
    print(f"\n[MEM]  Loaded {len(mem)} words from '{args.output_mem_file}'")

    C_emu = np.zeros((ROWS, COLS), dtype=np.float32)
    for r in range(ROWS):
        for c in range(COLS):
            C_emu[r, c] = read_bf16_at(mem, OUTPUT_GMEM + (r*COLS+c)*2)

    print(f"\n[EMULATOR]")
    print(f"  C[0,0]        = {C_emu[0,0]:.4f}")
    print(f"  C[0,{last}]    = {C_emu[0,last]:.4f}")
    print(f"  C[{last},0]    = {C_emu[last,0]:.4f}")
    print(f"  C[{last},{last}] = {C_emu[last,last]:.4f}")

    abs_diff = np.abs(C_emu - C_golden)
    rel_diff = abs_diff / (np.abs(C_golden) + 1e-8)
    worst    = np.unravel_index(abs_diff.argmax(), abs_diff.shape)

    abs_tol = args.abs_tol or max(1.0, float(np.abs(C_golden).mean()) * args.rel_tol)
    rel_tol = args.rel_tol

    print(f"\n[ERROR METRICS]")
    print(f"  Tolerances  : abs ≤ {abs_tol:.2f}  OR  rel ≤ {rel_tol*100:.1f}%")
    print(f"  Max abs err : {abs_diff.max():.4f}  at C{worst}")
    print(f"  Mean abs err: {abs_diff.mean():.4f}")
    print(f"  Max rel err : {rel_diff.max()*100:.4f}%")
    print(f"  Golden worst: {C_golden[worst]:.4f}")
    print(f"  Emu   worst : {C_emu[worst]:.4f}")

    fail_mask  = ~((abs_diff <= abs_tol) | (rel_diff <= rel_tol))
    fail_count = int(fail_mask.sum())
    total      = ROWS * COLS

    print(f"\n[RESULTS]  {total-fail_count}/{total} elements pass")

    if fail_count:
        print(f"\n  First 20 failures:")
        for r, c in np.argwhere(fail_mask)[:20]:
            print(f"    C[{r:2d},{c:2d}]  golden={C_golden[r,c]:12.4f}"
                  f"  emu={C_emu[r,c]:12.4f}"
                  f"  abs={abs_diff[r,c]:.4f}  rel={rel_diff[r,c]*100:.4f}%")
        if fail_count > 20:
            print(f"    … and {fail_count-20} more")

    print()
    if fail_count == 0:
        print("[COMPARE] PASSED")
        sys.exit(0)
    else:
        print("[COMPARE] FAILED")
        sys.exit(1)


if __name__ == "__main__":
    main()