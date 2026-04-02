from functools import lru_cache

# --------------------------------------------
# Opcode Table
# --------------------------------------------
OPCODES = {
    # ---------------- R-Type ----------------
    0b0000001: ("add.s", "R"),
    0b0000010: ("sub.s", "R"),
    0b0000011: ("mul.s", "R"),
    0b0000100: ("div.s", "R"),
    0b0000101: ("mod.s", "R"),
    0b0000110: ("or.s", "R"),
    0b0000111: ("and.s", "R"),
    0b0001000: ("xor.s", "R"),
    0b0001001: ("sll.s", "R"),
    0b0001010: ("srl.s", "R"),
    0b0001011: ("sra.s", "R"),
    0b0001100: ("slt.s", "R"),
    0b0001101: ("sltu.s", "R"),
    0b0001110: ("bfts.s", "R"),
    0b0001111: ("add.bf", "R"),
    0b0010000: ("sub.bf", "R"),
    0b0010001: ("mul.bf", "R"),
    0b0010010: ("rcp.bf", "R"),
    0b0010011: ("slt.bf", "R"),
    0b0010100: ("sqrt.bf", "R"),
    0b0010101: ("stbf.s", "R"),

    # ---------------- I-Type ----------------
    0b0010110: ("addi.s", "I"),
    0b0010111: ("subi.s", "I"),
    0b0011000: ("muli.s", "I"),
    0b0011001: ("divi.s", "I"),
    0b0011010: ("modi.s", "I"),
    0b0011011: ("ori.s", "I"),
    0b0011100: ("andi.s", "I"),
    0b0011101: ("xori.s", "I"),
    0b0011110: ("slli.s", "I"),
    0b0011111: ("srli.s", "I"),
    0b0100000: ("srai.s", "I"),
    0b0100001: ("slti.s", "I"),
    0b0100010: ("sltui.s", "I"),
    0b0101110: ("jalr", "I"),

    # ---------------- BR-Type ----------------
    0b0100011: ("beq.s", "BR"),
    0b0100100: ("bne.s", "BR"),
    0b0100101: ("blt.s", "BR"),
    0b0100110: ("bge.s", "BR"),
    0b0100111: ("bgt.s", "BR"),
    0b0101000: ("ble.s", "BR"),

    # ---------------- M-Type ----------------
    0b0101001: ("lw.s", "M"),
    0b0101010: ("sw.s", "M"),
    0b0101011: ("lhw.s", "M"),
    0b0101100: ("shw.s", "M"),

    # ---------------- MI-Type ----------------
    0b0101101: ("jal", "MI"),
    0b0101111: ("li.s", "MI"),
    0b0110000: ("lui.s", "MI"),

    # ---------------- S-Type ----------------
    0b0110001: ("nop.s", "S"),
    0b0110010: ("halt.s", "S"),

    # ---------------- VV-Type ----------------
    0b0110011: ("add.vv", "VV"),
    0b0110100: ("sub.vv", "VV"),
    0b0110101: ("mul.vv", "VV"),
    0b0110110: ("gemm.vv", "VV"),

    # ---------------- VI-Type ----------------
    0b0110111: ("expi.vi", "VI"),
    0b0111000: ("lw.vi", "VI"),
    0b0111001: ("rsum.vi", "VI"),
    0b0111010: ("rmin.vi", "VI"),
    0b0111011: ("rmax.vi", "VI"),

    # ---------------- MVV-Type ----------------
    0b0111100: ("mgt.mvv", "MVV"),
    0b0111101: ("mlt.mvv", "MVV"),
    0b0111110: ("meq.mvv", "MVV"),
    0b0111111: ("mneq.mvv", "MVV"),

    # ---------------- MVS-Type ----------------
    0b1000000: ("mgt.mvs", "MVS"),
    0b1000001: ("mlt.mvs", "MVS"),
    0b1000010: ("meq.mvs", "MVS"),
    0b1000011: ("mneq.mvs", "MVS"),

    # ---------------- VM-Type ----------------
    0b1000100: ("vreg.ld", "VM"),
    0b1000101: ("vreg.st", "VM"),

    # ---------------- SCPD-Type ----------------
    0b1000110: ("scpad.ld", "SDMA"),
    0b1000111: ("scpad.st", "SDMA"),

    # ---------------- VTS-Type ----------------
    0b1001000: ("vmov.vts", "VTS"),

    # ---------------- Mask/Move ----------------
    0b1001001: ("mv.mts", "MTS"),
    0b1001010: ("mv.stm", "STM"),

    # ---------------- VS-Type ----------------
    0b1001011: ("add.vs", "VS"),
    0b1001100: ("sub.vs", "VS"),
    0b1001101: ("mul.vs", "VS"),

    # -------- Legacy Compatibility Extensions --------
    # Kept to support older build_* kernels while preserving updated ISA core.
    0b1001110: ("addi.vi", "VI"),
    0b1001111: ("subi.vi", "VI"),
    0b1010000: ("muli.vi", "VI"),
    0b1010001: ("sqrti.vi", "VI"),
    0b1010010: ("div.vv", "VV"),
    0b1010011: ("div.vs", "VS"),
    0b1010100: ("divi.vi", "VI"),
}

@lru_cache()
def name_to_opcode():
    return {name: (opcode, instr_type) for opcode, (name, instr_type) in OPCODES.items()}

