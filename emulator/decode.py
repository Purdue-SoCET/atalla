"""
decode.py
----------
Decodes 160-bit VLIW packets into four 40-bit instructions.
Each instruction is decoded according to its type (R, I, BR, M, etc.).
"""


# --------------------------------------------
# Opcode Table
# --------------------------------------------
OPCODES = {
    # ---------------- R-Type ----------------
    0b0000001: ("add.s",   "R"),
    0b0000010: ("sub.s",   "R"),
    0b0000011: ("mul.s",   "R"),
    0b0000100: ("div.s",   "R"),
    0b0000101: ("mod.s",   "R"),
    0b0000110: ("or.s",    "R"),
    0b0000111: ("and.s",   "R"),
    0b0001000: ("xor.s",   "R"),
    0b0001001: ("sll.s",   "R"),
    0b0001010: ("srl.s",   "R"),
    0b0001011: ("sra.s",   "R"),
    0b0001100: ("slt.s",   "R"),
    0b0001101: ("sltu.s",  "R"),
    0b0001110: ("add.bf",  "R"),
    0b0001111: ("sub.bf",  "R"),
    0b0010000: ("mul.bf",  "R"),
    0b0010001: ("div.bf",  "R"),
    0b0010010: ("slt.bf",  "R"),
    0b0010011: ("sltu.bf", "R"),
    0b0010100: ("stbf.s",  "R"),
    0b0010101: ("bfts.s",  "R"),

    # ---------------- I-Type ----------------
    0b0010110: ("addi.s",  "I"),
    0b0010111: ("subi.s",  "I"),
    0b0011000: ("muli.s",  "I"),
    0b0011001: ("divi.s",  "I"),
    0b0011010: ("modi.s",  "I"),
    0b0011011: ("ori.s",   "I"),
    0b0011100: ("andi.s",  "I"),
    0b0011101: ("xori.s",  "I"),
    0b0011110: ("slli.s",  "I"),
    0b0011111: ("srli.s",  "I"),
    0b0100000: ("srai.s",  "I"),
    0b0100001: ("slti.s",  "I"),
    0b0100010: ("sltui.s", "I"),
    0b0101100: ("jalr",    "I"),  # jump and link register

    # ---------------- BR-Type ----------------
    0b0100011: ("beq.s",   "BR"),
    0b0100100: ("bne.s",   "BR"),
    0b0100101: ("blt.s",   "BR"),
    0b0100110: ("bge.s",   "BR"),
    0b0100111: ("bgt.s",   "BR"),
    0b0101000: ("ble.s",   "BR"),

    # ---------------- M-Type ----------------
    0b0101001: ("lw.s",    "M"),
    0b0101010: ("sw.s",    "M"),

    # ---------------- MI-Type ----------------
    0b0101011: ("jal",     "MI"),  # jump and link
    0b0101101: ("li.s",    "MI"),
    0b0101110: ("lui.s",   "MI"),

    # ---------------- S-Type ----------------
    0b0101111: ("nop.s",   "S"),
    0b0110000: ("halt.s",  "S"),
    0b0110001: ("barrier.s", "S"),

    # ---------------- VV-Type ----------------
    0b0110010: ("add.vv",  "VV"),
    0b0110011: ("sub.vv",  "VV"),
    0b0110100: ("mul.vv",  "VV"),
    0b0110101: ("div.vv",  "VV"),
    0b0110110: ("and.vv",  "VV"),
    0b0110111: ("or.vv",   "VV"),
    0b0111000: ("xor.vv",  "VV"),
    0b0111001: ("gemm.vv", "VV"),
    0b0111010: ("mgt.vv",  "VV"),
    0b0111011: ("mlt.vv",  "VV"),
    0b0111100: ("meq.vv",  "VV"),
    0b0111101: ("mneq.vv", "VV"),

    # ---------------- VI-Type ----------------
    0b0111110: ("addi.vi", "VI"),
    0b0111111: ("subi.vi", "VI"),
    0b1000000: ("muli.vi", "VI"),
    0b1000001: ("divi.vi", "VI"),
    0b1000010: ("expi.vi", "VI"),
    0b1000011: ("sqrti.vi","VI"),
    0b1000100: ("not.vi",  "VI"),
    0b1000101: ("shift.vi","VI"),
    0b1000110: ("lw.vi",   "VI"),
    0b1000111: ("rsum.vi", "VI"),
    0b1001000: ("rmin.vi", "VI"),
    0b1001001: ("rmax.vi", "VI"),
    0b1001111: ("vmov.vi", "VI"),

    # ---------------- VS-Type ----------------
    0b0111000: ("shift.vs","VS"),  # vector lane shift scalar reg
    0b1010000: ("add.vs", "VS"),
    0b1010001: ("sub.vs", "VS"),
    0b1010010: ("mul.vs", "VS"),
    0b1010011: ("div.vs", "VS"),
    0b1010100: ("mgt.vs", "VS"),
    0b1010101: ("mlt.vs", "VS"),
    0b1010110: ("meq.vs", "VS"),
    0b1010111: ("mneqi.vs","VS"),

    # ---------------- Mask/Move ----------------
    0b1001011: ("mv.mts", "MTS"),
    0b1001100: ("mv.stm", "STM"),

    # ---------------- VM-Type ----------------
    0b1001101: ("vreg.ld", "VM"),
    0b1001110: ("vreg.st", "VM"),
}


def get_bits(value, high, low):
    """
    Extract bits [high:low] from a value and reverse them.

    Parameters
    ----------
    value : int
        The integer from which to extract bits.
    high : int
        The index of the most significant bit (MSB) in the field.
    low : int
        The index of the least significant bit (LSB) in the field.

    Returns
    -------
    int
        The extracted and bit-reversed value.

    """
    width = high - low + 1
    mask = (1 << width) - 1
    return reverse_bits((value >> low) & mask, width)


def reverse_bits(value, length):
    """
    Reverse the bits of a given integer.

    Parameters
    ----------
    value : int
        The integer to reverse.
    length : int
        The number of bits to consider in reversal.

    Returns
    -------
    int
        Bit-reversed integer.
    """
    reversed_value = 0
    for i in range(length):
        # Extract the i-th bit from the right
        bit = (value >> i) & 1
        # Set it at the reversed position
        reversed_value |= bit << (length - 1 - i)
    return reversed_value


def decode_instruction(instr):
    """
    Decode a single 40-bit instruction.

    Parameters
    ----------
    instr : int
        A 40-bit instruction as an integer.

    Returns
    -------
    dict
        A dictionary containing decoded fields, including 'opcode', 'mnemonic',
        'type', and other fields specific to the instruction type.
        
    """
    # All instructions: opcode = bits 0-6
    opcode = get_bits(instr, 6, 0)
    # print("opcode: " + str(bin(opcode)))
    if opcode not in OPCODES:
        return {"opcode": opcode, "type": "UNKNOWN", "raw": instr}

    mnemonic, instr_type = OPCODES[opcode]
    decoded = {"opcode": opcode, "mnemonic": mnemonic, "type": instr_type}

    if instr_type == "R":
        # R-Type: rd 7-14, rs1 15-22, rs2 23-30
        decoded.update({
            "rd":  get_bits(instr, 14, 7),
            "rs1": get_bits(instr, 22, 15),
            "rs2": get_bits(instr, 30, 23)
        })


#TODO: check whether to << 2 or nah
    elif instr_type == "I":
        # I-Type: rd 7-14, rs1 15-22, imm12 23-34
        decoded.update({
            "rd":  get_bits(instr, 14, 7),
            "rs1": get_bits(instr, 22, 15),
            "imm": sign_extend(get_bits(instr, 34, 23), 12)
        })

    elif instr_type == "BR":
        # BR-Type: incr-imm7 7-13, i1 14, rs1 15-22, rs2 23-30, imm9 31-39
        imm1 = get_bits(instr, 14, 14)
        imm9 = get_bits(instr, 39, 31)
        decoded.update({
            "incr_imm": get_bits(instr, 13, 7),
            "rs1": get_bits(instr, 22, 15),
            "rs2": get_bits(instr, 30, 23),
            "imm": sign_extend((((imm1 << 9) | imm9) << 2), 10) #shift left to word align
        })

    elif instr_type == "M":
        # M-Type: rd 7-14, rs1 15-22, imm12 23-34
        decoded.update({
            "rd":  get_bits(instr, 14, 7),
            "rs1": get_bits(instr, 22, 15),
            "imm": sign_extend(get_bits(instr, 34, 23), 12)
        })

    elif instr_type == "MI":
        # MI-Type: rd 7-14, imm25 15-39
        decoded.update({
            "rd":  get_bits(instr, 14, 7),
            "imm": sign_extend(get_bits(instr, 39, 15) << 2, 25) #shift left to word align
        })

    elif instr_type == "S":
        # S-Type: special instructions, no operands
        decoded.update({"info": "no operands"})

    elif instr_type == "VV":
        # VV-Type: vd 7-14, vs1 15-22, vs2 23-30, mask 31-34, sac 35-39
        decoded.update({
            "vd": get_bits(instr, 14, 7),
            "vs1": get_bits(instr, 22, 15),
            "vs2": get_bits(instr, 30, 23),
            "mask": get_bits(instr, 34, 31),
            "sac": get_bits(instr, 39, 35)
        })

    elif instr_type == "VS":
        # VS-Type: vd 7-14, vs1 15-22, rs1 23-30, mask 31-34
        decoded.update({
            "vd": get_bits(instr, 14, 7),
            "vs1": get_bits(instr, 22, 15),
            "rs1": get_bits(instr, 30, 23),
            "mask": get_bits(instr, 34, 31)
        })

    elif instr_type == "VI":
        # VI-Type: vd 7-14, vs1 15-22, imm8 23-30, mask 31-34, imm5 35-39
        imm8 = get_bits(instr, 30, 23)
        imm5 = get_bits(instr, 39, 35)
        decoded.update({
            "vd": get_bits(instr, 14, 7),
            "vs1": get_bits(instr, 22, 15),
            "mask": get_bits(instr, 34, 31),
            "imm": (imm8 < 5) | imm5
        })

    elif instr_type == "VM":
        # VM-Type: vd 7-14, rs1 15-22, tile r/c count 23-27, rc 28, sp 29-30, mask 31-34, rc_id 35-39
        decoded.update({
            "vd": get_bits(instr, 14, 7),
            "rs1": get_bits(instr, 22, 15),
            "tile_rc": get_bits(instr, 27, 23),
            "rc": get_bits(instr, 28, 28),
            "sp": get_bits(instr, 30, 29),
            "mask": get_bits(instr, 34, 31),
            "rc_id": get_bits(instr, 39, 35)
        })

    elif instr_type == "SDMA": 
        decoded.update({
            "rs1/rd1": get_bits(instr, 14, 7),
            "rs2": get_bits(instr, 22, 15),
            "num_rows": get_bits(instr, 27, 23),
            "num_cols": get_bits(instr, 32, 28),
            "sid": get_bits(instr, 33, 33)

        })

    elif instr_type == "MTS": 
        decoded.update({
            "rd": get_bits(instr, 14, 7),
            "vms": get_bits(instr, 22, 15)
        })

    elif instr_type == "STM": 
        decoded.update({
            "vmd": get_bits(instr, 14, 7),
            "rs1": get_bits(instr, 22, 15)
        })

    else:
        decoded.update({"raw": instr})

    return decoded



# --------------------------------------------
# Packet decode
# --------------------------------------------
def decode_packet(packet, packet_length = 4):
    """
    Decode a 160-bit packet into individual 40-bit instructions.

    Parameters
    ----------
    packet : int
        The 160-bit packet as an integer.
    packet_length : int, optional
        Number of 40-bit instructions (default=4).

    Returns
    -------
    list of dict
        List of decoded instruction dictionaries.
    """
    instructions = []
    for i in range(packet_length):
        shift = (3 - i) * 40  # Extract top instruction first
        instr = (packet >> shift) & ((1 << 40) - 1)
        # print(instr)
        decoded = decode_instruction(instr)
        decoded["slot"] = i
        instructions.append(decoded)
    return instructions


# --------------------------------------------
# Helper: sign extension
# --------------------------------------------
def sign_extend(value, bits):
    """
    Sign-extend an integer.

    Parameters
    ----------
    value : int
        The integer to extend.
    bits : int
        The bit width of the value.

    Returns
    -------
    int
        Sign-extended integer.
    """
    sign_bit = 1 << (bits - 1)
    return (value ^ sign_bit) - sign_bit


# --------------------------------------------
# Example test
# --------------------------------------------
if __name__ == "__main__":
    # Example: 160-bit packet (0 - and.s (x3 = x3 & x3) | 1 - and.s (x3 = x3 & x3) | 2 - and.s (x3 = x3 & x3) | 3 - and.s (x3 = x3 & x3))
    packet = int("0000000000000000000000000110000001110000 000000000110000001100000011000000111000000000000011000000110000001100000011100000000000001100000011000000110000001110000", 2)
    decoded = decode_packet(packet)
    print(decoded)
    for i, d in enumerate(decoded):
        print(f"Instruction {i}: {d}")
