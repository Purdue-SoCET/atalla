from ..misc.opcode_table import OPCODES


INSTR_BITS = 40
PACKET_WIDTH = 4


def get_bits(value, high, low):
    width = high - low + 1
    mask = (1 << width) - 1
    return (value >> low) & mask


def sign_extend(value, bits):
    sign_bit = 1 << (bits - 1)
    return (value & (sign_bit - 1)) - (value & sign_bit)


def decode_instruction(instr):
    opcode = get_bits(instr, 6, 0)
    if opcode not in OPCODES:
        return {"opcode": opcode, "mnemonic": "unknown", "type": "UNKNOWN", "raw": instr}

    mnemonic, instr_type = OPCODES[opcode]
    decoded = {"opcode": opcode, "mnemonic": mnemonic, "type": instr_type}

    if instr_type == "R":
        decoded.update(
            {
                "rd": get_bits(instr, 14, 7),
                "rs1": get_bits(instr, 22, 15),
                "rs2": get_bits(instr, 30, 23),
            }
        )

    elif instr_type == "I":
        decoded.update(
            {
                "rd": get_bits(instr, 14, 7),
                "rs1": get_bits(instr, 22, 15),
                "imm": sign_extend(get_bits(instr, 34, 23), 12),
            }
        )

    elif instr_type == "BR":
        imm1 = get_bits(instr, 14, 14)
        imm9 = get_bits(instr, 39, 31)
        decoded.update(
            {
                "incr_imm": get_bits(instr, 13, 7),
                "rs1": get_bits(instr, 22, 15),
                "rs2": get_bits(instr, 30, 23),
                "imm": sign_extend((((imm1 << 9) | imm9) << 2), 12),
            }
        )

    elif instr_type == "M":
        decoded.update(
            {
                "rd": get_bits(instr, 14, 7),
                "rs1": get_bits(instr, 22, 15),
                "imm": sign_extend(get_bits(instr, 34, 23), 12),
            }
        )

    elif instr_type == "MI":
        decoded.update(
            {
                "rd": get_bits(instr, 14, 7),
                "imm": sign_extend(get_bits(instr, 39, 15), 25),
            }
        )

    elif instr_type == "VV":
        decoded.update(
            {
                "vd": get_bits(instr, 14, 7),
                "vs1": get_bits(instr, 22, 15),
                "vs2": get_bits(instr, 30, 23),
                "mask": get_bits(instr, 34, 31),
            }
        )

    elif instr_type == "VS":
        decoded.update(
            {
                "vd": get_bits(instr, 14, 7),
                "vs1": get_bits(instr, 22, 15),
                "rs1": get_bits(instr, 30, 23),
                "mask": get_bits(instr, 34, 31),
            }
        )

    elif instr_type == "VI":
        decoded.update(
            {
                "vd": get_bits(instr, 14, 7),
                "vs1": get_bits(instr, 22, 15),
                "imm": get_bits(instr, 30, 23),
                "mask": get_bits(instr, 34, 31),
            }
        )

    elif instr_type == "VTS":
        decoded.update(
            {
                "rd": get_bits(instr, 14, 7),
                "vs1": get_bits(instr, 22, 15),
                "imm8": get_bits(instr, 30, 23),
            }
        )

    elif instr_type == "VMV":
        decoded.update(
            {
                "vmd": get_bits(instr, 10, 7),
                "vs1": get_bits(instr, 22, 15),
                "vs2": get_bits(instr, 30, 23),
                "mask": get_bits(instr, 34, 31),
            }
        )

    elif instr_type == "VMS":
        decoded.update(
            {
                "vmd": get_bits(instr, 10, 7),
                "vs1": get_bits(instr, 22, 15),
                "rs1": get_bits(instr, 30, 23),
                "mask": get_bits(instr, 34, 31),
            }
        )

    elif instr_type == "MTS":
        decoded.update(
            {
                "rd": get_bits(instr, 14, 7),
                "vms": get_bits(instr, 18, 15),
            }
        )

    elif instr_type == "STM":
        decoded.update(
            {
                "vmd": get_bits(instr, 10, 7),
                "rs1": get_bits(instr, 22, 15),
            }
        )

    elif instr_type == "VM":
        decoded.update(
            {
                "vd": get_bits(instr, 14, 7),
                "rs1": get_bits(instr, 22, 15),
                "rs2": get_bits(instr, 30, 23),
                "num_cols": get_bits(instr, 35, 31),
                "sid": get_bits(instr, 37, 36),
            }
        )

    elif instr_type == "SDMA":
        decoded.update(
            {
                "rs1/rd1": get_bits(instr, 14, 7),
                "rs2": get_bits(instr, 22, 15),
                "rs3": get_bits(instr, 30, 23),
            }
        )

    else:
        decoded.update({"raw": instr})

    return decoded


def decode_packet(packet, packet_length=PACKET_WIDTH, debug=False):
    instructions = []
    for i in range(packet_length):
        shift = ((packet_length - 1) - i) * INSTR_BITS
        instr = (packet >> shift) & ((1 << INSTR_BITS) - 1)
        decoded = decode_instruction(instr)
        decoded["slot"] = i
        instructions.append(decoded)
    return instructions


if __name__ == "__main__":
    packet = int(
        "0000000001100000011000000110000000000111000000000110000001100000011000000000011100000000011000000110000001100000000001110000000001100000011000000110000000000111",
        2,
    )
    decoded = decode_packet(packet)
    for i, d in enumerate(decoded):
        print(f"Instruction {i}: {d}")
