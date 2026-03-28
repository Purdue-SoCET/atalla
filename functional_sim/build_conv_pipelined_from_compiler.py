"""
Build a .in image for the compiled C pipelined convolution kernel.

Reads the ppci-generated .s file, converts notation to emulator format,
assembles + packetizes, and attaches the same DRAM data layout as
build_conv_pipelined.py so results are directly comparable.
"""
from __future__ import annotations

import re
import sys
from pathlib import Path
import argparse
import numpy as np

from build import assemble_file, emit_test_format, DRAMWriter, render_testfile

PPCI_ASM_PATH = Path("/home/asicfab/a/zhan4808/aihw-ppci-compiler/atalla_tests/conv_sa_pipelined.s")

SCALAR_REG_MAP = {f"x{i}": f"${i}" for i in range(34)}
SCALAR_REG_MAP["x33"] = "$33"
VEC_REG_MAP = {f"v{i}": f"${i}" for i in range(32)}
MASK_REG_MAP = {f"m{i}": str(i) for i in range(17)}

UNDERSCORE_TO_DOT = {
    "add_s": "add.s", "sub_s": "sub.s", "mul_s": "mul.s", "mod_s": "mod.s",
    "or_s": "or.s", "and_s": "and.s", "xor_s": "xor.s",
    "sll_s": "sll.s", "srl_s": "srl.s", "sra_s": "sra.s",
    "slt_s": "slt.s", "sltu_s": "sltu.s",
    "addi_s": "addi.s", "subi_s": "subi.s", "muli_s": "muli.s",
    "divi_s": "divi.s", "modi_s": "modi.s",
    "ori_s": "ori.s", "andi_s": "andi.s", "xori_s": "xori.s",
    "slli_s": "slli.s", "srli_s": "srli.s", "srai_s": "srai.s",
    "slti_s": "slti.s", "sltui_s": "sltui.s",
    "lw_s": "lw.s", "sw_s": "sw.s", "lhw_s": "lhw.s", "shw_s": "shw.s",
    "li_s": "li.s", "lui_s": "lui.s",
    "beq_s": "beq.s", "bne_s": "bne.s", "blt_s": "blt.s",
    "bge_s": "bge.s", "bgt_s": "bgt.s", "ble_s": "ble.s",
    "add_vv": "add.vv", "sub_vv": "sub.vv", "mul_vv": "mul.vv",
    "gemm_vv": "gemm.vv",
    "addi_vi": "addi.vi", "subi_vi": "subi.vi", "muli_vi": "muli.vi",
    "expi_vi": "expi.vi", "sqrti_vi": "sqrti.vi", "not_vi": "not.vi",
    "shift_vi": "shift.vi", "lw_vi": "lw.vi",
    "rsum_vi": "rsum.vi", "rmin_vi": "rmin.vi", "rmax_vi": "rmax.vi",
    "add_vs": "add.vs", "sub_vs": "sub.vs", "mul_vs": "mul.vs",
    "shift_vs": "shift.vs",
    "vreg_ld": "vreg.ld", "vreg_st": "vreg.st",
    "scpad_ld": "scpad.ld", "scpad_st": "scpad.st",
    "mv_stm": "mv.stm", "mv_mts": "mv.mts",
    "mgt_mvv": "mgt.mvv", "mlt_mvv": "mlt.mvv",
    "meq_mvv": "meq.mvv", "mneq_mvv": "mneq.mvv",
    "mgt_mvs": "mgt.mvs", "mlt_mvs": "mlt.mvs",
    "meq_mvs": "meq.mvs", "mneq_mvs": "mneq.mvs",
    "halt": "halt.s", "nop": "nop.s",
}

SKIP_DIRECTIVES = {".section", ".align", "global", "type"}

VV_MNEMONICS = {"add.vv", "sub.vv", "mul.vv", "gemm.vv", "and.vv", "or.vv", "xor.vv"}


def fixup_vv_sac(asm: str) -> str:
    """Append sac=0 to VV-type instructions that only have 4 operands."""
    out = []
    for line in asm.splitlines():
        stripped = line.strip()
        parts = stripped.split(None, 1)
        if len(parts) == 2 and parts[0] in VV_MNEMONICS:
            ops = [o.strip() for o in parts[1].split(",")]
            if len(ops) == 4:
                line = "        " + parts[0] + " " + ", ".join(ops) + ", 0"
        out.append(line)
    return "\n".join(out)


def convert_ppci_to_emulator(ppci_asm: str) -> str:
    lines = ppci_asm.splitlines()
    out = []
    for raw in lines:
        line = raw.strip()
        if not line:
            continue
        first_word = line.split()[0].rstrip(":")
        if first_word in SKIP_DIRECTIVES:
            continue
        if line.startswith("main_epilog:") or line.startswith("main:"):
            continue

        for us, dot in sorted(UNDERSCORE_TO_DOT.items(), key=lambda kv: -len(kv[0])):
            line = re.sub(r'\b' + re.escape(us) + r'\b', dot, line)

        for xr, dr in sorted(SCALAR_REG_MAP.items(), key=lambda kv: -len(kv[0])):
            line = re.sub(r'\b' + re.escape(xr) + r'\b', dr, line)
        for vr, dr in sorted(VEC_REG_MAP.items(), key=lambda kv: -len(kv[0])):
            line = re.sub(r'\b' + re.escape(vr) + r'\b', dr, line)
        for mr, dr in sorted(MASK_REG_MAP.items(), key=lambda kv: -len(kv[0])):
            line = re.sub(r'\b' + re.escape(mr) + r'\b', dr, line)

        out.append("        " + line)
    return "\n".join(out)


def strip_prologue_epilogue(asm_lines: list[str]) -> list[str]:
    """Remove compiler function prologue/epilogue (stack frame setup/teardown)."""
    filtered = []
    in_epilog = False
    for line in asm_lines:
        stripped = line.strip()
        if "main_epilog:" in stripped:
            in_epilog = True
            continue
        if in_epilog:
            continue
        if any(stripped.startswith(p) for p in [
            "addi.s $2, $2,",  # sp adjust
            "sw.s $1,",        # save ra
            "sw.s $8,",        # save fp
            "addi.s $8, $2,",  # set fp
            "lw.s $1,",        # restore ra
            "lw.s $8,",        # restore fp
            "jalr $0,$1,",     # return
            "jalr $0, $1,",    # return (with space)
        ]):
            continue
        filtered.append(line)
    return filtered


INSTR_BYTE_WIDTH = 6
REAL_PACKET_SIZE = 4
ADDR_STRIDE = REAL_PACKET_SIZE * INSTR_BYTE_WIDTH


def resolve_jal_labels(asm: str) -> str:
    """Resolve jal $0, label to jal $0, byte_offset. Keep label defs for branch resolution."""
    lines = asm.splitlines()

    labels: dict[str, int] = {}
    entries: list[tuple[int, str, bool]] = []  # (pc, raw_line, is_label_only)
    pc = 0
    for raw in lines:
        stripped = raw.strip()
        if not stripped:
            entries.append((pc, raw, True))
            continue
        m = re.match(r'^([A-Za-z_]\w*):(.*)$', stripped)
        if m:
            labels[m.group(1)] = pc
            rest = m.group(2).strip()
            if rest:
                entries.append((pc, raw, False))
                pc += ADDR_STRIDE
            else:
                entries.append((pc, raw, True))
            continue
        entries.append((pc, raw, False))
        pc += ADDR_STRIDE

    out = []
    for pc, raw, is_label_only in entries:
        if is_label_only:
            out.append(raw)
            continue
        stripped = raw.strip()
        m = re.match(r'(.*?)(jal\s+\$0\s*,\s*)([A-Za-z_]\w*)(.*)', stripped)
        if m:
            target_label = m.group(3)
            if target_label in labels:
                delta = labels[target_label] - pc
                out.append("        jal $0, " + str(delta))
            # else: drop jal to missing label (dead code after halt)
            continue
        out.append(raw)
    return "\n".join(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input", type=Path, default=PPCI_ASM_PATH)
    ap.add_argument("-o", "--output", type=Path, default=Path("tests/conv_sa_pipelined_compiled.in"))
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

    N, H, W, C_ch = args.N, args.H, args.W, args.C
    K, R, S = args.K, args.R, args.S
    stride, pad = args.stride, args.pad

    Ho = (H + 2 * pad - R) // stride + 1
    Wo = (W + 2 * pad - S) // stride + 1
    K_flat = R * S * C_ch
    M = N * Ho * Wo

    CFG_BASE = 0x3C
    A_GMEM_ADDR = 0x00001000
    W_GMEM_ADDR = 0x00002000
    C_GMEM_ADDR = 0x00003000

    ppci_asm = args.input.read_text()
    emu_asm = convert_ppci_to_emulator(ppci_asm)

    emu_lines = strip_prologue_epilogue(emu_asm.splitlines())
    emu_asm_clean = "\n".join(emu_lines)
    emu_asm_clean = resolve_jal_labels(emu_asm_clean)

    emu_asm_clean = fixup_vv_sac(emu_asm_clean)

    print("=== Converted assembly (emulator format) ===")
    print(emu_asm_clean)
    print("=== End ===\n")

    instrs = assemble_file(emu_asm_clean)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    img.u32(CFG_BASE + 0, A_GMEM_ADDR)
    img.u32(CFG_BASE + 4, 0)
    img.u32(CFG_BASE + 8, W_GMEM_ADDR)
    img.u32(CFG_BASE + 12, 0)
    img.u32(CFG_BASE + 16, C_GMEM_ADDR)
    img.u32(CFG_BASE + 20, 0)

    ifmap_vals = np.arange(N * H * W * C_ch, dtype=np.float32).reshape(N, H, W, C_ch)
    weight_vals = (np.arange(R * S * C_ch * K, dtype=np.float32) + 100.0).reshape(R, S, C_ch, K)

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
                            cols.extend([0.0] * C_ch)
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
    print(f"Wrote {args.output}")


if __name__ == "__main__":
    main()
