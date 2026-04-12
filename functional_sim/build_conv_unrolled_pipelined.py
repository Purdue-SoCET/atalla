from __future__ import annotations

from pathlib import Path
import argparse
import numpy as np

try:
    from .build import (
        assemble_file,
        emit_test_format,
        emit_test_format_latency_program_order,
        DRAMWriter,
        render_testfile,
        emit_sdma_metadata_asm,
    )
except Exception:
    try:
        from functional_sim.build import (
            assemble_file,
            emit_test_format,
            emit_test_format_latency_program_order,
            DRAMWriter,
            render_testfile,
            emit_sdma_metadata_asm,
        )
    except Exception:
        from build import (
            assemble_file,
            emit_test_format,
            emit_test_format_latency_program_order,
            DRAMWriter,
            render_testfile,
            emit_sdma_metadata_asm,
        )


def make_conv_sa_unrolled_pipelined_asm(M: int, K_flat: int, K_out: int, cfg_base: int) -> str:
    k_out_m1 = K_out - 1
    sdma_a = "\n".join("        " + ln.strip() for ln in emit_sdma_metadata_asm(40, 41, 0, M, K_flat, K_flat).split("\n") if ln.strip())
    sdma_w = "\n".join("        " + ln.strip() for ln in emit_sdma_metadata_asm(40, 41, 1, K_flat, K_out, K_out).split("\n") if ln.strip())
    sdma_c = "\n".join("        " + ln.strip() for ln in emit_sdma_metadata_asm(40, 41, 1, M, K_out, K_out).split("\n") if ln.strip())
    return f"""
        addi.s  $20, $0, {cfg_base}
        lw.s    $2, 0($20)
        lw.s    $3, 4($20)
        lw.s    $4, 8($20)
        lw.s    $5, 12($20)
        lw.s    $6, 16($20)
        lw.s    $7, 20($20)
{sdma_a}
        scpad.ld $3, $2, $40
{sdma_w}
        scpad.ld $5, $4, $40

        lui.s   $8, 0xFFFFF
        addi.s  $8, $8, -1
        mv.stm  1, $8

        addi.s  $27, $0, 0
        addi.s  $28, $0, {K_out}
weight_loop:
        vreg.ld $10, $5, $27, {K_flat - 1}, 1
        lw.vi   $10, $10, 0, 1
        addi.s  $27, $27, 1
        blt.s   $27, $28, weight_loop

{sdma_c}
        scpad.ld $7, $6, $40

        addi.s  $27, $0, 0
        addi.s  $26, $0, {M}
        vreg.ld $4, $3, $27, {K_flat - 1}, 0
        vreg.ld $5, $7, $27, {k_out_m1}, 1
        addi.s  $28, $0, 1

main_loop_u4:
        gemm.vv $6, $4, $5, 1
        vreg.st $6, $7, $27, {k_out_m1}, 1
        addi.s  $27, $27, 1
        bge.s   $27, $26, done

        bge.s   $28, $26, skip_fetch_u1
        vreg.ld $14, $3, $28, {K_flat - 1}, 0
        vreg.ld $15, $7, $28, {k_out_m1}, 1
skip_fetch_u1:
        addi.s  $28, $28, 1

        gemm.vv $6, $14, $15, 1
        vreg.st $6, $7, $27, {k_out_m1}, 1
        addi.s  $27, $27, 1
        bge.s   $27, $26, done

        bge.s   $28, $26, skip_fetch_u2
        vreg.ld $16, $3, $28, {K_flat - 1}, 0
        vreg.ld $17, $7, $28, {k_out_m1}, 1
skip_fetch_u2:
        addi.s  $28, $28, 1

        gemm.vv $6, $16, $17, 1
        vreg.st $6, $7, $27, {k_out_m1}, 1
        addi.s  $27, $27, 1
        bge.s   $27, $26, done

        bge.s   $28, $26, skip_fetch_u3
        vreg.ld $18, $3, $28, {K_flat - 1}, 0
        vreg.ld $19, $7, $28, {k_out_m1}, 1
skip_fetch_u3:
        addi.s  $28, $28, 1

        gemm.vv $6, $18, $19, 1
        vreg.st $6, $7, $27, {k_out_m1}, 1
        addi.s  $27, $27, 1
        bge.s   $27, $26, done

        bge.s   $28, $26, skip_fetch_u0
        vreg.ld $4, $3, $28, {K_flat - 1}, 0
        vreg.ld $5, $7, $28, {k_out_m1}, 1
skip_fetch_u0:
        addi.s  $28, $28, 1
        blt.s   $27, $26, main_loop_u4

done:
{sdma_c}
        scpad.st $7, $6, $40
        halt.s
    """


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/conv_sa_unrolled_pipelined.in"))
    ap.add_argument("--N", type=int, default=1)
    ap.add_argument("--H", type=int, default=6)
    ap.add_argument("--W", type=int, default=10)
    ap.add_argument("--C", type=int, default=3)
    ap.add_argument("--K", type=int, default=4)
    ap.add_argument("--R", type=int, default=3)
    ap.add_argument("--S", type=int, default=3)
    ap.add_argument("--stride", type=int, default=1)
    ap.add_argument("--pad", type=int, default=0)
    ap.add_argument(
        "--dag-pack",
        action="store_true",
        help="Wide VLIW pack + BR patch + BR10 preflight (see build.emit_test_format_latency_program_order).",
    )
    ap.add_argument(
        "--latency",
        action="store_true",
        help="With --dag-pack: materialize latency stall rows (often breaks BR10 on loops).",
    )
    ap.add_argument(
        "--bb-local",
        action="store_true",
        help="With --dag-pack: experimental BB-local program-order packing.",
    )
    args = ap.parse_args()
    if args.latency and not args.dag_pack:
        ap.error("--latency requires --dag-pack")
    if args.bb_local and not args.dag_pack:
        ap.error("--bb-local requires --dag-pack")

    N, H, W, C = args.N, args.H, args.W, args.C
    K, R, S = args.K, args.R, args.S
    stride, pad = args.stride, args.pad

    Ho = (H + 2 * pad - R) // stride + 1
    Wo = (W + 2 * pad - S) // stride + 1
    K_flat = R * S * C
    M = N * Ho * Wo
    if K_flat > 32 or K > 32 or M > 32:
        raise ValueError("This conv builder supports only K_flat<=32, K<=32, M<=32.")

    CFG_BASE = 0x3C
    A_GMEM_ADDR, W_GMEM_ADDR, C_GMEM_ADDR = 0x1000, 0x2000, 0x3000
    A_SCPAD_ADDR, W_SCPAD_ADDR, C_SCPAD_ADDR = 1024, 0, 2048

    asm = make_conv_sa_unrolled_pipelined_asm(M, K_flat, K, CFG_BASE)
    instr_text = (
        emit_test_format_latency_program_order(
            asm,
            latency_stalls=args.latency,
            bb_local_pack=args.bb_local,
        )
        if args.dag_pack
        else emit_test_format(assemble_file(asm))
    )

    img = DRAMWriter()
    img.u32(CFG_BASE + 0, A_GMEM_ADDR)
    img.u32(CFG_BASE + 4, A_SCPAD_ADDR)
    img.u32(CFG_BASE + 8, W_GMEM_ADDR)
    img.u32(CFG_BASE + 12, W_SCPAD_ADDR)
    img.u32(CFG_BASE + 16, C_GMEM_ADDR)
    img.u32(CFG_BASE + 20, C_SCPAD_ADDR)

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
                        cols.extend([0.0] * C if (ih < 0 or ih >= H or iw < 0 or iw >= W) else ifmap_vals[n, ih, iw, :].tolist())
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

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(render_testfile(instr_text, img.render_data_mem(include_zeros=True)))


if __name__ == "__main__":
    main()

