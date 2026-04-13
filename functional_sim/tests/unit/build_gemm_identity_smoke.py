from __future__ import annotations

import struct
import sys
from pathlib import Path

import numpy as np

EMU_DIR = Path(__file__).resolve().parents[3]
if str(EMU_DIR) not in sys.path:
    sys.path.insert(0, str(EMU_DIR))

from functional_sim.build import DRAMWriter, assemble_file, emit_test_format, render_testfile


def emit_load_imm(reg: int, value: int) -> list[str]:
    upper = value >> 7
    lower = value & 0x7F
    return [f"lui.s   ${reg}, {upper}", f"addi.s  ${reg}, ${reg}, {lower}"]


def emit_sdma_ctl(reg: int, num_cols: int, num_rows: int, sid: int) -> list[str]:
    ctl = ((sid & 0x3) << 30) | ((num_rows & 0x1F) << 25) | ((num_cols & 0x1F) << 20)
    return emit_load_imm(reg, ctl)


def bf16_to_f32(bits: int) -> np.float32:
    return np.float32(struct.unpack("<f", struct.pack("<I", (bits & 0xFFFF) << 16))[0])


def q_bf16(arr: np.ndarray) -> np.ndarray:
    flat = arr.astype(np.float32).reshape(-1)
    out = np.empty_like(flat, dtype=np.float32)
    for i, v in enumerate(flat):
        bits = struct.unpack("<I", struct.pack("<f", float(v)))[0] >> 16
        out[i] = bf16_to_f32(bits)
    return out.reshape(arr.shape)


def build_program(q_addr: int, w_addr: int, o_addr: int) -> str:
    lines: list[str] = []
    lines.append("addi.s  $8, $0, -1")
    lines.append("mv.stm  1, $8")
    for _ in range(32):
        lines.append("lw.vi   $0, $0, 0, 0")

    lines.append("addi.s  $46, $0, 0")
    lines.append("addi.s  $47, $0, 1")
    lines.extend(emit_sdma_ctl(49, 31, 31, 0))
    lines.extend(emit_sdma_ctl(50, 31, 0, 0))

    lines.extend(emit_load_imm(2, w_addr))
    lines.append("scpad.ld $46, $2, $49")
    for rr in reversed(range(32)):
        lines.append(f"addi.s  $7, $0, {rr}")
        lines.append("vreg.ld $20, $46, 31, 31, 0, 1, $7")
        lines.append("lw.vi   $20, $20, 0, 0")

    lines.extend(emit_load_imm(2, q_addr))
    lines.append("scpad.ld $46, $2, $50")
    lines.extend(emit_load_imm(2, o_addr))
    lines.append("scpad.ld $47, $2, $50")

    lines.append("addi.s  $7, $0, 0")
    lines.append("vreg.ld $10, $46, 31, 0, 0, 1, $7")
    lines.append("vreg.ld $11, $47, 31, 0, 0, 1, $7")
    lines.append("gemm.vv $12, $10, $11, 0, 0")
    lines.append("vreg.st $12, $47, 31, 0, 0, 1, $7")

    lines.extend(emit_load_imm(2, o_addr))
    lines.append("scpad.st $47, $2, $50")
    lines.append("halt.s")
    return "\n".join(lines) + "\n"


def read_dump_word_map(path: Path) -> dict[int, int]:
    out: dict[int, int] = {}
    in_data = False
    for line in path.read_text().splitlines():
        if line.strip().upper() == "DATA MEM":
            in_data = True
            continue
        if not in_data or ":" not in line:
            continue
        addr_s, val_s = [x.strip() for x in line.split(":", 1)]
        if len(val_s) != 8:
            continue
        out[int(addr_s, 16)] = int(val_s, 16)
    return out


def main() -> None:
    out_path = Path(__file__).with_name("gemm_identity_smoke.in")
    q_addr = 0x1000
    w_addr = 0x2000
    o_addr = 0x3000

    q = q_bf16(np.arange(1, 33, dtype=np.float32).reshape(1, 32))
    w = np.eye(32, dtype=np.float32)
    z = np.zeros((1, 32), dtype=np.float32)

    asm = build_program(q_addr, w_addr, o_addr)
    instrs = assemble_file(asm)
    instr_text = emit_test_format(instrs)

    img = DRAMWriter()
    for c in range(32):
        img.bf16(q_addr + c * 2, float(q[0, c]))
        img.bf16(o_addr + c * 2, 0.0)
    for r in range(32):
        for c in range(32):
            img.bf16(w_addr + 2 * (r * 32 + c), float(w[r, c]))

    out_path.write_text(render_testfile(instr_text, img.render_data_mem(include_zeros=True)))
    print(f"Wrote {out_path}")


if __name__ == "__main__":
    main()
