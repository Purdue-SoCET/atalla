from __future__ import annotations

from pathlib import Path
import sys

EMU_DIR = Path(__file__).resolve().parents[3]
if str(EMU_DIR) not in sys.path:
    sys.path.insert(0, str(EMU_DIR))

from functional_sim.build import DRAMWriter, assemble_file, emit_test_format, render_testfile
from functional_sim.src.components.decode import decode_instruction

ASM_PATH = Path(__file__).with_name("branching_smoke.asm")
OUT_PATH = Path(__file__).with_name("branching_smoke.txt")


def _check_branch(instr_hex: str, *, mnemonic: str, imm: int, incr_imm: int) -> None:
    decoded = decode_instruction(int(instr_hex, 16))
    if decoded.get("mnemonic") != mnemonic:
        raise AssertionError(
            f"Expected {mnemonic}, got {decoded.get('mnemonic')} for {instr_hex}"
        )
    if decoded.get("imm") != imm:
        raise AssertionError(
            f"Expected branch imm={imm}, got imm={decoded.get('imm')} for {instr_hex}"
        )
    if decoded.get("incr_imm") != incr_imm:
        raise AssertionError(
            f"Expected incr_imm={incr_imm}, got incr_imm={decoded.get('incr_imm')} for {instr_hex}"
        )


def main() -> None:
    asm = ASM_PATH.read_text()
    instrs = assemble_file(asm)

    # Program shape:
    # 0:addi, 1:addi, 2:addi, 3:subi, 4:bne->loop, 5:beq->fail, 6:halt, 7:addi, 8:halt
    if len(instrs) != 9:
        raise AssertionError(f"Expected 9 instructions, got {len(instrs)}")

    _check_branch(instrs[4][0], mnemonic="bne.s", imm=-48, incr_imm=0)
    _check_branch(instrs[5][0], mnemonic="beq.s", imm=48, incr_imm=5)

    instr_lines = emit_test_format(instrs)
    data_lines = DRAMWriter().render_data_mem(include_zeros=False)
    OUT_PATH.write_text(render_testfile(instr_lines, data_lines))

    print("PASS: branching label assembly smoke test")
    print(f"Wrote: {OUT_PATH}")


if __name__ == "__main__":
    main()
