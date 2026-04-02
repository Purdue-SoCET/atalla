from __future__ import annotations

import argparse
import os
import struct
from pathlib import Path

import numpy as np

try:
    from .build import DRAMWriter, assemble_file, emit_test_format, render_testfile
except Exception:
    from build import DRAMWriter, assemble_file, emit_test_format, render_testfile


def bf16_to_f32(bits: int) -> np.float32:
    return np.float32(struct.unpack("<f", struct.pack("<I", (int(bits) & 0xFFFF) << 16))[0])


def q_bf16(arr: np.ndarray) -> np.ndarray:
    flat = arr.astype(np.float32).reshape(-1)
    out = np.empty_like(flat, dtype=np.float32)
    for i, v in enumerate(flat):
        u = struct.unpack("<I", struct.pack("<f", float(v)))[0]
        out[i] = bf16_to_f32((u >> 16) & 0xFFFF)
    return out.reshape(arr.shape)


def make_gemm_asm(rows: int, cols: int, cfg_base: int) -> str:
    cm1 = cols - 1
    rm1 = rows - 1
    return f"""
        addi.s  $20, $0, {cfg_base}
        lw.s    $2, 0($20)    # A_GMEM
        lw.s    $3, 4($20)    # A_SCPAD row
        lw.s    $4, 8($20)    # W_GMEM
        lw.s    $5, 12($20)   # W_SCPAD row
        lw.s    $6, 16($20)   # C_GMEM
        lw.s    $7, 20($20)   # C_SCPAD row

        scpad.ld $3, $2, {cm1}, {rm1}, 0
        scpad.ld $5, $4, {cm1}, {rm1}, 1

        addi.s  $8, $0, -1
        mv.stm  1, $8

        addi.s  $27, $0, 0
        addi.s  $28, $0, {rows}
wt_loop:
        bge.s   $27, $28, wt_done
        vreg.ld $10, $5, {cm1}, {rm1}, 1, 1, $27
        lw.vi   $10, $10, 0, 0
        addi.s  $27, $27, 1
        blt.s   $27, $28, wt_loop
wt_done:
        scpad.ld $7, $6, {cm1}, {rm1}, 1

        addi.s  $25, $0, 0
row_loop:
        bge.s   $25, $28, done
        vreg.ld $11, $3, {cm1}, {rm1}, 0, 1, $25
        vreg.ld $12, $7, {cm1}, {rm1}, 1, 1, $25
        gemm.vv $13, $11, $12, 0, 0
        vreg.st $13, $7, {cm1}, {rm1}, 1, 1, $25
        addi.s  $25, $25, 1
        blt.s   $25, $28, row_loop
done:
        scpad.st $7, $6, {cm1}, {rm1}, 1
        halt.s
    """


def read_data_mem_dump(path: Path) -> dict[int, int]:
    out: dict[int, int] = {}
    in_data = False
    for line in path.read_text().splitlines():
        if line.strip().upper() == "DATA MEM":
            in_data = True
            continue
        if not in_data or ":" not in line:
            continue
        a, v = [x.strip() for x in line.split(":", 1)]
        if len(v) != 8:
            continue
        out[int(a, 16)] = int(v, 16)
    return out


def read_bf16_matrix(dump: dict[int, int], base_addr: int, rows: int, cols: int) -> np.ndarray:
    out = np.zeros((rows, cols), dtype=np.float32)
    for r in range(rows):
        for c in range(cols):
            bits = dump.get(base_addr + 2 * (r * cols + c), 0) & 0xFFFF
            out[r, c] = bf16_to_f32(bits)
    return out


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/gemm.in"))
    ap.add_argument("--rows", type=int, default=20)
    ap.add_argument("--cols", type=int, default=20)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--compare_mem_dump", type=Path, default=None)
    args = ap.parse_args()

    rows = args.rows
    cols = args.cols
    if rows > 32 or cols > 32:
        raise ValueError("rows/cols must be <= 32")

    cfg_base = 0x3C
    a_addr = 0x1000
    w_addr = 0x2000
    c_addr = 0x3000
    a_sp = 0
    w_sp = 0
    c_sp = 0

    rng = np.random.default_rng(args.seed)
    A = rng.normal(0.0, 0.5, size=(rows, cols)).astype(np.float32)
    W = rng.normal(0.0, 0.5, size=(rows, cols)).astype(np.float32)
    C0 = np.zeros((rows, cols), dtype=np.float32)

    A_b = q_bf16(A)
    W_b = q_bf16(W)
    C0_b = q_bf16(C0)
    ref = q_bf16(A_b @ W_b + C0_b)

    asm = make_gemm_asm(rows, cols, cfg_base)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(cfg_base + 0, a_addr)
    img.u32(cfg_base + 4, a_sp)
    img.u32(cfg_base + 8, w_addr)
    img.u32(cfg_base + 12, w_sp)
    img.u32(cfg_base + 16, c_addr)
    img.u32(cfg_base + 20, c_sp)

    for r in range(rows):
        for c in range(cols):
            img.bf16(a_addr + 2 * (r * cols + c), float(A_b[r, c]))
            img.bf16(w_addr + 2 * (r * cols + c), float(W_b[r, c]))
            img.bf16(c_addr + 2 * (r * cols + c), float(C0_b[r, c]))

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)
    os.makedirs(args.output.parent, exist_ok=True)
    args.output.write_text(final)

    print(f"[INFO] Wrote kernel to {args.output}")
    print(f"[INFO] GEMM rows={rows}, cols={cols}")
    print(f"[INFO] Expected C (first row, first 8): {ref[0, :8]}")

    if args.compare_mem_dump is not None:
        dump = read_data_mem_dump(args.compare_mem_dump)
        sim = read_bf16_matrix(dump, c_addr, rows, cols)
        diff = np.abs(sim - ref)
        print(f"[COMPARE] max_abs_err={float(np.max(diff)):.6f}, mean_abs_err={float(np.mean(diff)):.6f}")


if __name__ == "__main__":
    main()

