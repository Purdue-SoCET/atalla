from opcode_table import OPCODES

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
    opcode = reverse_bits(opcode, 7)
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
    packet = int("0000000001100000011000000110000000000111000000000110000001100000011000000000011100000000011000000110000001100000000001110000000001100000011000000110000000000111", 2)
    decoded = decode_packet(packet)
    for i, d in enumerate(decoded):
        print(f"Instruction {i}: {d}")