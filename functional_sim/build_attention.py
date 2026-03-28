from __future__ import annotations

import struct, os, math
from pathlib import Path
import argparse
import numpy as np

from build import *


def bf16_to_f32(bits: int) -> float:
    return struct.unpack("<f", struct.pack("<I", (bits & 0xFFFF) << 16))[0]


def f32_to_bf16(x: float) -> int:
    u = struct.unpack("<I", struct.pack("<f", float(x)))[0]
    lsb = (u >> 16) & 1
    u_round = (u + 0x7FFF + lsb) & 0xFFFFFFFF
    return (u_round >> 16) & 0xFFFF


def bf16_matmul(A, B):
    M, K = A.shape
    _, N = B.shape
    C = np.zeros((M, N), dtype=np.float32)
    for i in range(M):
        for j in range(N):
            acc = 0.0
            for k in range(K):
                a = bf16_to_f32(f32_to_bf16(A[i, k]))
                b = bf16_to_f32(f32_to_bf16(B[k, j]))
                acc += a * b
            C[i, j] = acc
    return C


def bf16_softmax(X):
    rows, cols = X.shape
    out = np.zeros_like(X)
    for r in range(rows):
        row = np.array([bf16_to_f32(f32_to_bf16(X[r, c])) for c in range(cols)])
        mx = np.max(row)
        e = np.exp(row - mx)
        s = np.sum(e)
        out[r] = e / s
    return out


def make_attention_asm(S: int, d: int) -> str:
    s_m1 = S - 1
    d_m1 = d - 1
    mask_val = (1 << S) - 1

    return f"""
        # ============ ATTENTION: softmax(Q*K^T / sqrt(d)) * V ============
        # S={S}, d={d}
        # Register map:
        #   $1  = address table base (60)
        #   $2  = Q_GMEM_ADDR
        #   $3  = Q_SCPAD (0, SID0)
        #   $4  = KT_GMEM_ADDR
        #   $5  = KT_SCPAD (fixed offset in SID0)
        #   $6  = V_GMEM_ADDR
        #   $7  = V_SCPAD (fixed offset in SID0)
        #   $8  = OUT_GMEM_ADDR
        #   $9  = OUT_SCPAD (0, SID1)
        #   $14 = SCALE_ADDR / scale value
        #   $15 = scratch scalar
        #   $16 = SCORES_SCPAD (SID1)
        #   $20 = mask value for mv.stm
        #   $25 = row loop counter
        #   $26 = row loop limit (S)
        #   $27 = weight load loop counter
        #   $28 = weight load loop limit
        #   $10 = vreg for weight load / softmax scratch
        #   $11 = vreg for rmax result
        #   $12 = vreg for exp result
        #   $13 = vreg for rsum result
        #   $30 = vreg for Q row / attn row
        #   $31 = vreg for accumulator (zeros for first gemm)
        #   $32 = vreg for scores row

        # load address table
        addi.s  $1, $0, 60

        lw.s    $2, 0($1)           # Q_GMEM
        lw.s    $3, 4($1)           # Q_SCPAD = 0
        lw.s    $4, 8($1)           # KT_GMEM
        lw.s    $5, 12($1)          # KT_SCPAD
        lw.s    $6, 16($1)          # V_GMEM
        lw.s    $7, 20($1)          # V_SCPAD
        lw.s    $8, 24($1)          # OUT_GMEM
        lw.s    $9, 28($1)          # OUT_SCPAD = 0
        lw.s    $16, 32($1)         # SCORES_SCPAD
        lw.s    $14, 36($1)         # SCALE value (f32 bits -> scalar)

        # load Q tile (SxD) into SP0 at Q_SCPAD
        scpad.ld $3, $2, {d_m1}, {s_m1}, 0

        # load K^T tile (DxS) into SP0 at KT_SCPAD
        scpad.ld $5, $4, {s_m1}, {d_m1}, 0

        # set up mask1: enable lanes 0..S-1
        addi.s  $20, $0, {mask_val}
        mv.stm  1, $20

        # ========== STEP 1: scores = Q * K^T (SxD * DxS -> SxS) ==========
        # Load K^T rows into systolic array
        addi.s  $27, $0, 0
        addi.s  $28, $0, {d}

kt_load_loop:
        bge.s   $27, $28, kt_load_done
        vreg.ld $10, $5, {s_m1}, {d_m1}, 0, 1, $27
        lw.vi   $10, $10, 0, 0xf
        addi.s  $27, $27, 1
        blt.s   $27, $28, kt_load_loop

kt_load_done:
        # Compute scores: for each Q row, gemm.vv -> scores row in SP1
        addi.s  $25, $0, 0
        addi.s  $26, $0, {S}

        # zero accumulator vector
        sub.vv  $31, $31, $31, 1, 0

scores_row_loop:
        vreg.ld $30, $3, {d_m1}, {s_m1}, 0, 1, $25
        gemm.vv $32, $30, $31, 0, 0
        vreg.st $32, $16, {s_m1}, {s_m1}, 1, 1, $25

        addi.s  $25, $25, 1
        blt.s   $25, $26, scores_row_loop

        # ========== STEP 2: scale scores by 1/sqrt(d) ==========
        addi.s  $25, $0, 0

scale_row_loop:
        vreg.ld $32, $16, {s_m1}, {s_m1}, 1, 1, $25
        mul.vs  $32, $32, $14, 1
        vreg.st $32, $16, {s_m1}, {s_m1}, 1, 1, $25

        addi.s  $25, $25, 1
        blt.s   $25, $26, scale_row_loop

        # ========== STEP 3: row-wise softmax on scores ==========
        addi.s  $25, $0, 0

softmax_row_loop:
        vreg.ld $10, $16, {s_m1}, {s_m1}, 1, 1, $25

        rmax.vi  $11, $10, 0, 1
        vmov.vts $15, $11, 0
        sub.vs   $10, $10, $15, 1
        expi.vi  $12, $10, 0, 1
        rsum.vi  $13, $12, 64, 1
        vmov.vts $15, $13, 0
        div.vs   $10, $12, $15, 1

        vreg.st $10, $16, {s_m1}, {s_m1}, 1, 1, $25

        addi.s  $25, $25, 1
        blt.s   $25, $26, softmax_row_loop

        # ========== STEP 4: output = attn * V (SxS * SxD -> SxD) ==========
        # Load V tile (SxD) into SP0 at V_SCPAD
        scpad.ld $7, $6, {d_m1}, {s_m1}, 0

        # Load V rows into systolic array
        addi.s  $27, $0, 0
        addi.s  $28, $0, {S}

v_load_loop:
        bge.s   $27, $28, v_load_done
        vreg.ld $10, $7, {d_m1}, {s_m1}, 0, 1, $27
        lw.vi   $10, $10, 0, 0xf
        addi.s  $27, $27, 1
        blt.s   $27, $28, v_load_loop

v_load_done:
        # Compute output: for each attn row, gemm.vv -> output row
        addi.s  $25, $0, 0
        sub.vv  $31, $31, $31, 1, 0

output_row_loop:
        vreg.ld $30, $16, {s_m1}, {s_m1}, 1, 1, $25
        gemm.vv $32, $30, $31, 0, 0
        vreg.st $32, $9, {d_m1}, {s_m1}, 1, 1, $25

        addi.s  $25, $25, 1
        blt.s   $25, $26, output_row_loop

        # Store output from SP1 to DRAM
        scpad.st $9, $8, {d_m1}, {s_m1}, 1

        halt.s
    """


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/attention.in"))
    ap.add_argument("--S", type=int, default=4, help="Sequence length (<=32)")
    ap.add_argument("--d", type=int, default=4, help="Head dimension (<=32)")
    args = ap.parse_args()

    S = args.S
    d = args.d
    assert S <= 32 and d <= 32, "S and d must be <= 32"

    ADDR_TABLE = 60
    Q_GMEM     = 0x1000
    Q_SCPAD    = 0
    KT_GMEM    = 0x2000
    KT_SCPAD   = 512
    V_GMEM     = 0x3000
    V_SCPAD    = 1024
    OUT_GMEM   = 0x4000
    OUT_SCPAD  = 0
    SCORES_SCPAD = 0
    SCALE_ADDR = 0x0100

    inv_sqrt_d = 1.0 / math.sqrt(d)

    np.random.seed(42)
    Q  = np.random.randn(S, d).astype(np.float32) * 0.5
    K  = np.random.randn(S, d).astype(np.float32) * 0.5
    V  = np.random.randn(S, d).astype(np.float32) * 0.5
    KT = K.T

    asm = make_attention_asm(S, d)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()

    img.u32(ADDR_TABLE + 0,  Q_GMEM)
    img.u32(ADDR_TABLE + 4,  Q_SCPAD)
    img.u32(ADDR_TABLE + 8,  KT_GMEM)
    img.u32(ADDR_TABLE + 12, KT_SCPAD)
    img.u32(ADDR_TABLE + 16, V_GMEM)
    img.u32(ADDR_TABLE + 20, V_SCPAD)
    img.u32(ADDR_TABLE + 24, OUT_GMEM)
    img.u32(ADDR_TABLE + 28, OUT_SCPAD)
    img.u32(ADDR_TABLE + 32, SCORES_SCPAD)

    scale_bits = struct.unpack("<I", struct.pack("<f", inv_sqrt_d))[0]
    img.u32(ADDR_TABLE + 36, scale_bits)

    for r in range(S):
        for c in range(d):
            img.bf16(Q_GMEM + (r * d + c) * 2, float(Q[r, c]))

    for r in range(d):
        for c in range(S):
            img.bf16(KT_GMEM + (r * S + c) * 2, float(KT[r, c]))

    for r in range(S):
        for c in range(d):
            img.bf16(V_GMEM + (r * d + c) * 2, float(V[r, c]))

    for i in range(S * d):
        img.bf16(OUT_GMEM + i * 2, 0.0)

    scores = bf16_matmul(Q, KT) * inv_sqrt_d
    attn_weights = bf16_softmax(scores)
    expected = bf16_matmul(attn_weights, V)

    print(f"Attention: S={S}, d={d}, scale=1/sqrt({d})={inv_sqrt_d:.4f}")
    print(f"\nQ =\n{Q}")
    print(f"\nK^T =\n{KT}")
    print(f"\nV =\n{V}")
    print(f"\nScores (Q*K^T*scale) =\n{scores}")
    print(f"\nAttn weights (softmax) =\n{attn_weights}")
    print(f"\nExpected output =\n{expected}")

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
