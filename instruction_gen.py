import sys
from pathlib import Path

# Add the parent directory (src/) to the Python path
sys.path.insert(0, str(Path(__file__).parent.parent))

from opcode_table import OPCODES


def _mask(width: int) -> int:
    return (1 << width) - 1


def _set_bits(instruction: int, value: int, start_bit: int, width: int) -> int:
    """
    Insert `value` into `instruction` starting at `start_bit` with `width` bits.
    Bit numbering is LSB-first, inclusive of start_bit.
    """
    instruction |= (value & _mask(width)) << start_bit
    return instruction


def encode_instruction(instr_dict):
    """
    Encodes an instruction dictionary into a 40-bit hexadecimal string.

    Expected instruction width: 40 bits total
      bits [6:0] = opcode

    Type layouts from the updated format:

    R:
      [30:23] rs2
      [22:15] rs1
      [14:7]  rd
      [6:0]   opcode

    BR:
      [39:31] imm9
      [30:23] rs2
      [22:15] rs1_rd
      [14]    imm1
      [13:7]  incr_imm7
      [6:0]   opcode

    I / M:
      [34:23] imm12
      [22:15] rs1
      [14:7]  rd
      [6:0]   opcode

    MI:
      [39:15] imm25
      [14:7]  rd
      [6:0]   opcode

    VV:
      [34:31] mask
      [30:23] vs2
      [22:15] vs1
      [14:7]  vd
      [6:0]   opcode

    VS:
      [34:31] mask
      [30:23] rs1
      [22:15] vs1
      [14:7]  vd
      [6:0]   opcode

    VI:
      [34:31] mask
      [30:23] imm8
      [22:15] vs1
      [14:7]  vd
      [6:0]   opcode

    VTS:
      [30:23] imm8
      [22:15] vs1
      [14:7]  rd
      [6:0]   opcode

    VMV:
      [34:31] mask
      [30:23] vs2
      [22:15] vs1
      [14:11] vmd
      [6:0]   opcode

    VMS:
      [34:31] mask
      [30:23] rs1
      [22:15] vs1
      [14:11] vmd
      [6:0]   opcode

    MTS:
      [22:15] vms
      [14:7]  rd
      [6:0]   opcode

    STM:
      [22:15] rs1
      [14:11] vmd
      [6:0]   opcode

    VM:
      [33]    sid
      [32:28] num_cols
      [30:23] rs2   (row_number reg)
      [22:15] rs1
      [14:7]  vd
      [6:0]   opcode

    SDMA:
      [30:23] rs3   (metadata)
      [22:15] rs2   (DRAM address)
      [14:7]  rs1/rd1 (scratchpad addr)
      [6:0]   opcode
    """
    opcode = instr_dict["opcode"]

    if "type" in instr_dict:
        instr_type = instr_dict["type"]
    else:
        if opcode not in OPCODES:
            raise ValueError(f"Unknown opcode: {opcode}")
        _, instr_type = OPCODES[opcode]

    instruction = 0

    # opcode [6:0]
    instruction = _set_bits(instruction, opcode, 0, 7)

    if instr_type == "R":
        rd = instr_dict.get("rd", 0)
        rs1 = instr_dict.get("rs1", 0)
        rs2 = instr_dict.get("rs2", 0)

        instruction = _set_bits(instruction, rd, 7, 8)
        instruction = _set_bits(instruction, rs1, 15, 8)
        instruction = _set_bits(instruction, rs2, 23, 8)

    elif instr_type == "BR":
        incr_imm7 = instr_dict.get("incr_imm7", instr_dict.get("incr_imm", 0))
        imm1 = instr_dict.get("imm1", 0)

        # Shared field in new spec: "rs1 & rd"
        rs1_rd = instr_dict.get("rs1_rd", instr_dict.get("rs1", instr_dict.get("rd", 0)))
        rs2 = instr_dict.get("rs2", 0)
        imm9 = instr_dict.get("imm9", 0)

        instruction = _set_bits(instruction, incr_imm7, 7, 7)
        instruction = _set_bits(instruction, imm1, 14, 1)
        instruction = _set_bits(instruction, rs1_rd, 15, 8)
        instruction = _set_bits(instruction, rs2, 23, 8)
        instruction = _set_bits(instruction, imm9, 31, 9)

    elif instr_type == "I":
        rd = instr_dict.get("rd", 0)
        rs1 = instr_dict.get("rs1", 0)
        imm12 = instr_dict.get("imm12", instr_dict.get("imm", 0))

        instruction = _set_bits(instruction, rd, 7, 8)
        instruction = _set_bits(instruction, rs1, 15, 8)
        instruction = _set_bits(instruction, imm12, 23, 12)

    elif instr_type == "M":
        rd = instr_dict.get("rd", 0)
        rs1 = instr_dict.get("rs1", 0)
        imm12 = instr_dict.get("imm12", instr_dict.get("imm", 0))

        instruction = _set_bits(instruction, rd, 7, 8)
        instruction = _set_bits(instruction, rs1, 15, 8)
        instruction = _set_bits(instruction, imm12, 23, 12)

    elif instr_type == "MI":
        rd = instr_dict.get("rd", 0)
        imm25 = instr_dict.get("imm25", instr_dict.get("imm", 0))

        instruction = _set_bits(instruction, rd, 7, 8)
        instruction = _set_bits(instruction, imm25, 15, 25)

    elif instr_type == "S":
        # No operands
        pass

    elif instr_type == "VV":
        vd = instr_dict.get("vd", 0)
        vs1 = instr_dict.get("vs1", 0)
        vs2 = instr_dict.get("vs2", 0)
        mask = instr_dict.get("mask", 0)

        instruction = _set_bits(instruction, vd, 7, 8)
        instruction = _set_bits(instruction, vs1, 15, 8)
        instruction = _set_bits(instruction, vs2, 23, 8)
        instruction = _set_bits(instruction, mask, 31, 4)

    elif instr_type == "VS":
        vd = instr_dict.get("vd", 0)
        vs1 = instr_dict.get("vs1", 0)
        rs1 = instr_dict.get("rs1", 0)
        mask = instr_dict.get("mask", 0)

        instruction = _set_bits(instruction, vd, 7, 8)
        instruction = _set_bits(instruction, vs1, 15, 8)
        instruction = _set_bits(instruction, rs1, 23, 8)
        instruction = _set_bits(instruction, mask, 31, 4)

    elif instr_type == "VI":
        vd = instr_dict.get("vd", 0)
        vs1 = instr_dict.get("vs1", 0)
        imm8 = instr_dict.get("imm8", instr_dict.get("imm", 0))
        mask = instr_dict.get("mask", 0)

        instruction = _set_bits(instruction, vd, 7, 8)
        instruction = _set_bits(instruction, vs1, 15, 8)
        instruction = _set_bits(instruction, imm8, 23, 8)
        instruction = _set_bits(instruction, mask, 31, 4)

    elif instr_type == "VTS":
        rd = instr_dict.get("rd", 0)
        vs1 = instr_dict.get("vs1", 0)
        imm8 = instr_dict.get("imm8", instr_dict.get("imm", 0))

        instruction = _set_bits(instruction, rd, 7, 8)
        instruction = _set_bits(instruction, vs1, 15, 8)
        instruction = _set_bits(instruction, imm8, 23, 8)

    # Your opcode table uses MVV/MVS names; these correspond to the new VMV/VMS layouts.
    elif instr_type == "MVV":
        vmd = instr_dict.get("vmd", 0)
        vs1 = instr_dict.get("vs1", 0)
        vs2 = instr_dict.get("vs2", 0)
        mask = instr_dict.get("mask", 0)

        instruction = _set_bits(instruction, vmd, 11, 4)
        instruction = _set_bits(instruction, vs1, 15, 8)
        instruction = _set_bits(instruction, vs2, 23, 8)
        instruction = _set_bits(instruction, mask, 31, 4)

    elif instr_type == "MVS":
        vmd = instr_dict.get("vmd", 0)
        vs1 = instr_dict.get("vs1", 0)
        rs1 = instr_dict.get("rs1", 0)
        mask = instr_dict.get("mask", 0)

        instruction = _set_bits(instruction, vmd, 11, 4)
        instruction = _set_bits(instruction, vs1, 15, 8)
        instruction = _set_bits(instruction, rs1, 23, 8)
        instruction = _set_bits(instruction, mask, 31, 4)

    elif instr_type == "MTS":
        rd = instr_dict.get("rd", 0)
        vms = instr_dict.get("vms", 0)

        instruction = _set_bits(instruction, rd, 7, 8)
        instruction = _set_bits(instruction, vms, 15, 8)

    elif instr_type == "STM":
        vmd = instr_dict.get("vmd", 0)
        rs1 = instr_dict.get("rs1", 0)

        instruction = _set_bits(instruction, vmd, 11, 4)
        instruction = _set_bits(instruction, rs1, 15, 8)

    elif instr_type == "VM":
        vd = instr_dict.get("vd", 0)
        rs1 = instr_dict.get("rs1", 0)
        rs2 = instr_dict.get("rs2", 0)  # row_number reg
        num_cols = instr_dict.get("num_cols", 0)
        sid = instr_dict.get("sid", 0)

        instruction = _set_bits(instruction, vd, 7, 8)
        instruction = _set_bits(instruction, rs1, 15, 8)
        instruction = _set_bits(instruction, rs2, 23, 8)
        instruction = _set_bits(instruction, num_cols, 31, 5)
        instruction = _set_bits(instruction, sid, 36, 1)

    elif instr_type == "SDMA":
        # Shared scratchpad register field: rs1 and/or rd1
        rs1_rd1 = instr_dict.get("rs1_rd1", instr_dict.get("rs1", instr_dict.get("rd1", 0)))
        rs2 = instr_dict.get("rs2", 0)  # DRAM address
        rs3 = instr_dict.get("rs3", 0)  # metadata

        instruction = _set_bits(instruction, rs1_rd1, 7, 8)
        instruction = _set_bits(instruction, rs2, 15, 8)
        instruction = _set_bits(instruction, rs3, 23, 8)

    else:
        raise ValueError(f"Unsupported instruction type: {instr_type}")

    # 40 bits = 10 hex characters
    return format(instruction, "010x")


if __name__ == "__main__":
    # Example tests
    nop = {"opcode": 0b0110001, "rs1": 0, "rd": 0, "rs2": 0}
    halt = {"opcode": 0b0110010, "rs1": 0, "rd": 0, "rs2": 0}
    st_wd_200 = {"opcode": 0b0101010, "rs1": 0, "rd": 1, "imm12": 200}


    #reg 1 of sdma will be 0

    #for reg 2 of sdma
    addi_1 = {"opcode": 0b0010110, "rs1": 0, "imm12": 200, "rd": 2}

    #for reg 3 of sdma
    # 00 00000 11111 0000000000000 0011111
    lui = {"opcode": 0b0110000, "imm25": 253952, "rd": 3}
    addi_2 = {"opcode": 0b0010110, "rs1": 3, "imm12": 31, "rd": 3}

    #sdma
    sdma = {"opcode": 0b1000110, "rs3": 3, "rs2": 2, "rs1": 1}

    #for reg 2 of vec load
    addi_3 = {"opcode": 0b0010110, "rs1": 0, "imm12": 0, "rd": 4}

    #vector load
    vload = {"opcode": 0b1000100, "sid": 0, "num_cols": 31, "rs2": 4, "rs1": 1, "vd": 1}

    print(f"addi_1 {encode_instruction(addi_1)}")
    print(f"lui {encode_instruction(lui)}")
    print(f"addi_2 {encode_instruction(addi_2)}")
    print(f"sdma {encode_instruction(sdma)}")
    print(f"nop {encode_instruction(nop)}")
    print(f"halt {encode_instruction(halt)}")
    print(f"vload {encode_instruction(vload)}")
    print(f"addi_3 {encode_instruction(addi_3)}")