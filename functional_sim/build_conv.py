from __future__ import annotations

from pathlib import Path
import argparse
import numpy as np

from build import assemble_file, emit_test_format, DRAMWriter, render_testfile


def make_conv_sa_asm(M: int, K_flat: int, K_out: int, cfg_base: int) -> str:
    k_out_m1 = K_out - 1
    asm = f"""
        lui.s   $20, 0
        addi.s  $20, $0, {cfg_base}
        lw.s    $2, 0($20)
        lw.s    $3, 4($20)
        lw.s    $4, 8($20)
        lw.s    $5, 12($20)
        lw.s    $6, 16($20)
        lw.s    $7, 20($20)

        scpad.ld $3, $2, {K_flat - 1}, {M - 1}, 0
        scpad.ld $5, $4, {K_out - 1}, {K_flat - 1}, 1

        lui.s   $8, 0xFFFFF
        addi.s  $8, $8, -1
        mv.stm  1, $8

        addi.s  $27, $0, 0
        addi.s  $28, $0, {K_out}
weight_loop:
        add.s   $15, $0, $27
        vreg.ld $10, $15, 0, {K_flat - 1}, 1, 0, 0
        lw.vi   $10, $10, 0, 0
        addi.s  $27, $27, 1
        blt.s   $27, $28, weight_loop

        # W is in SA now; SP1 rows can be reused for C.
        scpad.ld $7, $6, {K_out - 1}, {M - 1}, 1

        addi.s  $25, $0, 0
        addi.s  $26, $0, {M}
m_loop:
        beq.s   $25, $26, end_m
        add.s   $13, $3, $25
        vreg.ld $4, $13, {K_flat - 1}, {M}, 0, 1, 0
        add.s   $14, $7, $25
        vreg.ld $5, $14, {k_out_m1}, {M}, 1, 1, 0
        gemm.vv $6, $4, $5, 0, 0
        vreg.st $6, $14, {k_out_m1}, {M}, 1, 1, 0
        addi.s  $25, $25, 1
        blt.s   $25, $26, m_loop
end_m:
        scpad.st $7, $6, {K_out - 1}, {M - 1}, 1
        halt.s
    """
    return asm


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/conv_sa.in"))
    ap.add_argument("--N", type=int, default=1)
    ap.add_argument("--H", type=int, default=4)
    ap.add_argument("--W", type=int, default=4)
    ap.add_argument("--C", type=int, default=3)
    ap.add_argument("--K", type=int, default=4)
    ap.add_argument("--R", type=int, default=3)
    ap.add_argument("--S", type=int, default=3)
    ap.add_argument("--stride", type=int, default=1)
    ap.add_argument("--pad", type=int, default=0)
    args = ap.parse_args()

    N, H, W, C = args.N, args.H, args.W, args.C
    K, R, S = args.K, args.R, args.S
    stride, pad = args.stride, args.pad

    Ho = (H + 2 * pad - R) // stride + 1
    Wo = (W + 2 * pad - S) // stride + 1
    if Ho <= 0 or Wo <= 0:
        raise ValueError("Invalid H/W/R/S/stride/pad combination: Ho/Wo must be positive.")

    K_flat = R * S * C
    M = N * Ho * Wo
    if K_flat > 32 or K > 32 or M > 32:
        raise ValueError("This conv builder supports only K_flat<=32, K<=32, M<=32.")

    CFG_BASE = 0x3C
    A_GMEM_ADDR = 0x00001000
    W_GMEM_ADDR = 0x00002000
    C_GMEM_ADDR = 0x00003000

    asm = make_conv_sa_asm(M=M, K_flat=K_flat, K_out=K, cfg_base=CFG_BASE)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(CFG_BASE + 0, A_GMEM_ADDR)
    img.u32(CFG_BASE + 4, 0)
    img.u32(CFG_BASE + 8, W_GMEM_ADDR)
    img.u32(CFG_BASE + 12, 0)
    img.u32(CFG_BASE + 16, C_GMEM_ADDR)
    img.u32(CFG_BASE + 20, 0)

    ifmap_vals = np.arange(N * H * W * C, dtype=np.float32).reshape(N, H, W, C)
    weight_vals = (np.arange(R * S * C * K, dtype=np.float32) + 100.0).reshape(R, S, C, K)

    A_rows = []
    for n in range(N):
        for oh in range(Ho):
            for ow in range(Wo):
                cols = []
                for r in range(R):
                    for s in range(S):
                        ih = oh * stride + r - pad
                        iw = ow * stride + s - pad
                        if ih < 0 or ih >= H or iw < 0 or iw >= W:
                            cols.extend([0.0] * C)
                        else:
                            cols.extend(ifmap_vals[n, ih, iw, :].tolist())
                A_rows.append(cols)
    A_mat = np.array(A_rows, dtype=np.float32)
    W_flat = weight_vals.reshape(K_flat, K)

    for m_idx in range(M):
        for k_idx in range(K_flat):
            img.bf16(A_GMEM_ADDR + 2 * (m_idx * K_flat + k_idx), float(A_mat[m_idx, k_idx]))
    for r_idx in range(K_flat):
        for c_idx in range(K):
            img.bf16(W_GMEM_ADDR + 2 * (r_idx * K + c_idx), float(W_flat[r_idx, c_idx]))
    for m_idx in range(M):
        for k_idx in range(K):
            img.bf16(C_GMEM_ADDR + 2 * (m_idx * K + k_idx), 0.0)

    data_text = img.render_data_mem(include_zeros=True)
    final = render_testfile(instr_text, data_text)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(final)


if __name__ == "__main__":
    main()
