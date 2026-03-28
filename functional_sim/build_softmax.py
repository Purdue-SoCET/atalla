from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, List, Union
import struct
import os
import sys, re 
from pathlib import Path
import argparse
import numpy as np

from build import *
INVERT_OPCODES = name_to_opcode()
VIRTUAL_PACKET_SIZE = 4 
REAL_PACKET_SIZE = 4
RAW_VI_IMM_MNEMONICS = {"shift.vi", "rsum.vi", "rmin.vi", "rmax.vi"}
INSTR_BYTE_WIDTH = 6
INSTR_ADDR_STRIDE = REAL_PACKET_SIZE * INSTR_BYTE_WIDTH

IntLike = int
BytesLike = Union[bytes, bytearray, memoryview]

def encode_instruction(instr_dict):
    """
    Encodes an instruction dictionary into a 40-bit hexadecimal string.
    
    Args:
        instr_dict: Dictionary containing instruction fields like:
                   {'opcode': 22, 'rd': 2, 'rs1': 0, 'imm': 10}
                   Note: 'mnemonic' and 'type' are optional - will be looked up from opcode
    
    Returns:
        String: 10-character hexadecimal representation (40 bits)
    """
    opcode = instr_dict['opcode']
    
    # Look up instruction type from opcode table if not provided
    if 'type' in instr_dict:
        instr_type = instr_dict['type']
    else:
        if opcode not in OPCODES:
            raise ValueError(f"Unknown opcode: {opcode}")
        _, instr_type = OPCODES[opcode]
    
    # Initialize 40-bit instruction to 0
    instruction = 0
    
    # Opcode is always bits [6:0]
    instruction |= (opcode & 0x7F)
    
    # Encode based on instruction type
    if instr_type == "R":
        # R-Type: rd 7-14, rs1 15-22, rs2 23-30
        rd = instr_dict.get('rd', 0)
        rs1 = instr_dict.get('rs1', 0)
        rs2 = instr_dict.get('rs2', 0)
        
        instruction |= (rd & 0xFF) << 7
        instruction |= (rs1 & 0xFF) << 15
        instruction |= (rs2 & 0xFF) << 23
        
    elif instr_type == "BR":
        # BR-Type: incr-imm7 7-13, i1 14, rs1 15-22, rs2 23-30, imm9 31-39
        incr_imm = instr_dict.get('incr_imm', 0)
        imm1 = instr_dict.get('imm1', 0)
        rs1 = instr_dict.get('rs1', 0)
        rs2 = instr_dict.get('rs2', 0)
        imm9 = instr_dict.get('imm9', 0)
        
        instruction |= (incr_imm & 0x7F) << 7
        instruction |= (imm1 & 0x1) << 14
        instruction |= (rs1 & 0xFF) << 15
        instruction |= (rs2 & 0xFF) << 23
        instruction |= (imm9 & 0x1FF) << 31
        
    elif instr_type == "I":
        # I-Type: rd 7-14, rs1 15-22, imm12 23-34
        rd = instr_dict.get('rd', 0)
        rs1 = instr_dict.get('rs1', 0)
        imm12 = instr_dict.get('imm12', instr_dict.get('imm', 0))
        
        instruction |= (rd & 0xFF) << 7
        instruction |= (rs1 & 0xFF) << 15
        instruction |= (imm12 & 0xFFF) << 23
        
    elif instr_type == "M":
        # M-Type: rd 7-14, rs1 15-22, imm12 23-34
        rd = instr_dict.get('rd', 0)
        rs1 = instr_dict.get('rs1', 0)
        imm12 = instr_dict.get('imm12', instr_dict.get('imm', 0))
        
        instruction |= (rd & 0xFF) << 7
        instruction |= (rs1 & 0xFF) << 15
        instruction |= (imm12 & 0xFFF) << 23
        
    elif instr_type == "MI":
        # MI-Type: rd 7-14, imm25 15-39
        rd = instr_dict.get('rd', 0)
        imm25 = instr_dict.get('imm25', instr_dict.get('imm', 0))
        
        instruction |= (rd & 0xFF) << 7
        instruction |= (imm25 & 0x1FFFFFF) << 15
        
    elif instr_type == "S":
        # S-Type: special instructions, no operands
        pass
        
    elif instr_type == "VV":
        # VV-Type: vd 7-14, vs1 15-22, vs2 23-30, mask 31-34, sac 35-39
        vd = instr_dict.get('vd', 0)
        vs1 = instr_dict.get('vs1', 0)
        vs2 = instr_dict.get('vs2', 0)
        mask = instr_dict.get('mask', 0)
        sac = instr_dict.get('sac', 0)
        
        instruction |= (vd & 0xFF) << 7
        instruction |= (vs1 & 0xFF) << 15
        instruction |= (vs2 & 0xFF) << 23
        instruction |= (mask & 0xF) << 31
        instruction |= (sac & 0x1F) << 35
        
    elif instr_type == "VS":
        # VS-Type: vd 7-14, vs1 15-22, rs1 23-30, mask 31-34
        vd = instr_dict.get('vd', 0)
        vs1 = instr_dict.get('vs1', 0)
        rs1 = instr_dict.get('rs1', 0)
        mask = instr_dict.get('mask', 0)
        
        instruction |= (vd & 0xFF) << 7
        instruction |= (vs1 & 0xFF) << 15
        instruction |= (rs1 & 0xFF) << 23
        instruction |= (mask & 0xF) << 31
        
    elif instr_type == "VI":
        # VI-Type: vd 7-14, vs1 15-22, imm8 23-30, mask 31-34, imm5 35-39
        vd = instr_dict.get('vd', 0)
        vs1 = instr_dict.get('vs1', 0)
        imm8_1 = instr_dict.get('imm8_1', 0)
        mask = instr_dict.get('mask', 0)
        imm8_2 = instr_dict.get('imm8_2', 0)
        
        instruction |= (vd & 0xFF) << 7
        instruction |= (vs1 & 0xFF) << 15
        instruction |= (imm8_1 & 0xFF) << 23
        instruction |= (mask & 0xF) << 31
        instruction |= (imm8_2 & 0xFF) << 35
        
    elif instr_type == "VM":
        # VM-Type: vd 7-14, rs1 15-22, num_cols 23-27, num_rows 28-32, sid 33, rc 34, rc_id 35-39
        vd = instr_dict.get('vd', 0)
        rs1 = instr_dict.get('rs1', 0)
        num_cols = instr_dict.get('num_cols', 0)
        num_rows = instr_dict.get('num_rows', 0)
        sid = instr_dict.get('sid', 0)
        rc = instr_dict.get('rc', 0)
        rc_id = instr_dict.get('rc_id', 0)
        
        instruction |= (vd & 0xFF) << 7
        instruction |= (rs1 & 0xFF) << 15
        instruction |= (num_cols & 0x1F) << 23
        instruction |= (num_rows & 0x1F) << 28
        instruction |= (sid & 0x1) << 33
        instruction |= (rc & 0x1) << 34
        instruction |= (rc_id & 0x1F) << 35
        
    elif instr_type == "SDMA":
        # SDMA: rs1/rd1 7-14, rs2 15-22, num_cols 23-27, num_rows 28-32, sid 33
        rs1_rd1 = instr_dict.get('rs1', instr_dict.get('rd1', 0))
        rs2 = instr_dict.get('rs2', 0)
        num_cols = instr_dict.get('num_cols', 0)
        num_rows = instr_dict.get('num_rows', 0)
        sid = instr_dict.get('sid', 0)
        
        instruction |= (rs1_rd1 & 0xFF) << 7
        instruction |= (rs2 & 0xFF) << 15
        instruction |= (num_cols & 0x1F) << 23
        instruction |= (num_rows & 0x1F) << 28
        instruction |= (sid & 0x1) << 33
        
    elif instr_type == "MTS":
        # MTS: rd 7-14, vms 15-22
        rd = instr_dict.get('rd', 0)
        vms = instr_dict.get('vms', 0)
        
        instruction |= (rd & 0xFF) << 7
        instruction |= (vms & 0xFF) << 15
        
    elif instr_type == "STM":
        # STM: vmd 7-14, rs1 15-22
        vmd = instr_dict.get('vmd', 0)
        rs1 = instr_dict.get('rs1', 0)
        
        instruction |= (vmd & 0xFF) << 7
        instruction |= (rs1 & 0xFF) << 15

    elif instr_type == "VTS":
        imm8 = instr_dict.get('imm8', 0)
        vs1 = instr_dict.get('vs1', 0)
        rd = instr_dict.get('rd', 0)
        
        instruction |= (rd & 0xFF) << 7
        instruction |= (vs1 & 0xFF) << 15
        instruction |= (imm8 & 0xFF) << 23

    elif instr_type == "MVV":
        vmd = instr_dict.get('vmd', 0)
        vs1 = instr_dict.get('vs1', 0)
        vs2 = instr_dict.get('vs2', 0)
        mask = instr_dict.get('mask', 0)
        
        instruction |= (vmd & 0xF) << 7
        instruction |= (vs1 & 0xFF) << 11
        instruction |= (vs2 & 0xFF) << 19
        instruction |= (mask & 0xF) << 27

    elif instr_type == "MVS":
        vmd = instr_dict.get('vmd', 0)
        vs1 = instr_dict.get('vs1', 0)
        rs1 = instr_dict.get('rs1', 0)
        mask = instr_dict.get('mask', 0)
        
        instruction |= (vmd & 0xF) << 7
        instruction |= (vs1 & 0xFF) << 11
        instruction |= (rs1 & 0xFF) << 19
        instruction |= (mask & 0xF) << 27
    
    return format(instruction & ((1 << 48) - 1), '012x')
    

REG_RE = re.compile(r"^\$(?:x)?(\d+)$", re.IGNORECASE)
IMM_RE = re.compile(r"^[+-]?(?:0x[0-9a-fA-F]+|0b[01]+|\d+)$")
FLOAT_RE = re.compile(r"^[+-]?(?:\d+\.\d*|\.\d+|\d+)(?:[eE][+-]?\d+)?$")
MEM_RE = re.compile(r"^([+-]?(?:0x[0-9a-fA-F]+|0b[01]+|\d+))\(\s*\$(?:x)?(\d+)\s*\)$", re.IGNORECASE)
LABEL_RE = re.compile(r"^[A-Za-z_]\w*:$")

# ---- Label Branch Support Start ----
def parse_int(s: str) -> int:
    s = s.strip()
    if not IMM_RE.match(s):
        raise ValueError(f"Bad immediate: {s!r}")
    return int(s, 0)  # supports 123, 0x10, 0b1010, -4

def parse_number(s: str) -> float:
    s = s.strip()
    if IMM_RE.match(s):
        return float(int(s, 0))
    if FLOAT_RE.match(s):
        return float(s)
    raise ValueError(f"Bad numeric immediate: {s!r}")

def parse_reg(s: str) -> int:
    s = s.strip()
    m = REG_RE.match(s)
    if not m:
        raise ValueError(f"Bad register: {s!r} (expected $5 or $x5)")
    r = int(m.group(1))
    if not (0 <= r <= 255):
        raise ValueError(f"Register out of range (0..255): {r}")
    return r

def to_twos_complement(x: int, bits: int) -> int:
    lo = -(1 << (bits - 1))
    hi = (1 << (bits - 1)) - 1
    if x < lo or x > hi:
        raise ValueError(f"Immediate {x} out of signed {bits}-bit range [{lo}, {hi}]")
    return x & ((1 << bits) - 1)

def split_br_imm(off: int) -> tuple[int, int, int]:
    imm17 = to_twos_complement(off, 17)
    incr_imm = imm17 & 0x7F
    imm1 = (imm17 >> 7) & 0x1
    imm9 = (imm17 >> 8) & 0x1FF
    return incr_imm, imm1, imm9

def split_imm16(off: int) -> tuple[int, int]:
    imm16 = to_twos_complement(off, 16)
    return imm16 & 0xFF, (imm16 >> 8) & 0xFF

def split_br_target_imm(delta_bytes: int) -> tuple[int, int]:
    if delta_bytes % 4 != 0:
        raise ValueError(f"Branch target offset must be 4-byte aligned, got {delta_bytes}")

    word_off = delta_bytes // 4
    if word_off < -512 or word_off > 511:
        raise ValueError(
            f"Branch target offset {delta_bytes} out of range; "
            f"must fit signed 10-bit words ([-2048, 2044] bytes)"
        )

    imm10 = word_off & 0x3FF
    imm1 = (imm10 >> 9) & 0x1
    imm9 = imm10 & 0x1FF
    return imm1, imm9

def parse_leading_labels(code: str) -> tuple[list[str], str]:
    labels: list[str] = []
    s = code.strip()

    while s:
        m = re.match(r"^([A-Za-z_]\w*):", s)
        if not m:
            break
        labels.append(m.group(1))
        s = s[m.end():].lstrip()

    return labels, s

def parse_incr_imm7(s: str) -> int:
    v = parse_int(s)
    if not (0 <= v <= 0x7F):
        raise ValueError(f"incr_imm out of range (0..127): {v}")
    return v


def strip_comment(line: str) -> tuple[str, str]:
    # Keep trailing comment for pretty output
    if "#" in line:
        code, cmt = line.split("#", 1)
        return code.rstrip(), cmt.strip()
    return line.rstrip(), ""

def strip_label(code: str) -> str:
    # Handles:
    #   label: add.s $1, $2, $3
    #   label:
    # We only strip if it looks like an identifier label.
    s = code.strip()
    if not s:
        return s

    first = s.split(None, 1)[0]
    if LABEL_RE.match(first):
        return s[len(first):].lstrip()

    # Also handle "label:add.s ..." (no space after colon)
    if ":" in s:
        left, right = s.split(":", 1)
        if re.match(r"^[A-Za-z_]\w*$", left.strip()):
            return right.lstrip()

    return s

def split_mnemonic_operands(code: str) -> tuple[str, list[str]]:
    s = code.strip()
    if not s:
        return "", []
    parts = s.split(None, 1)
    mnemonic = parts[0].lower()
    ops_str = parts[1] if len(parts) == 2 else ""
    # split by commas
    ops = [o.strip() for o in ops_str.split(",") if o.strip()]
    return mnemonic, ops

def asm_to_instr_dict(
    mnemonic: str,
    ops: list[str],
    *,
    labels: dict[str, int] | None = None,
    pc: int | None = None,
) -> dict:
    if mnemonic not in INVERT_OPCODES:
        raise ValueError(f"Unknown mnemonic: {mnemonic}")

    opcode, instr_type = INVERT_OPCODES[mnemonic]   # ensure INVERT_OPCODES has (opcode,type)
    d = {"opcode": opcode, "type": instr_type}

    if instr_type == "R":
        d["rd"]  = parse_reg(ops[0])
        d["rs1"] = parse_reg(ops[1])
        d["rs2"] = parse_reg(ops[2])
        return d

    if instr_type in ("I",):
        # addi.s rd, rs1, imm12
        d["rd"]  = parse_reg(ops[0])
        d["rs1"] = parse_reg(ops[1])
        d["imm12"] = parse_int(ops[2])
        return d

    if instr_type == "M":
        # Your encoder has rd/rs1/imm12 only.
        # Convention:
        #   lw.s rd, imm(rs1)  -> rd=dest
        #   sw.s rs, imm(rs1)  -> rd=source (stored value)  <-- important!
        reg0 = parse_reg(ops[0])

        if len(ops) == 2:
            m = MEM_RE.match(ops[1].replace(" ", ""))
            if not m:
                raise ValueError(f"{mnemonic} expected imm(rs1), got {ops[1]!r}")
            imm = parse_int(m.group(1))
            rs1 = int(m.group(2))
        else:
            rs1 = parse_reg(ops[1])
            imm = parse_int(ops[2])

        d["rd"] = reg0        # for lw: dest, for sw: source (by convention)
        d["rs1"] = rs1
        d["imm12"] = imm
        return d

    if instr_type == "BR":
        # Legacy:
        #   beq.s rs1, rs2, packed_off
        # Label-aware:
        #   beq.s rs1, rs2, target_label[, incr_imm]
        #   beq.s rs1, rs2, target_offset_bytes[, incr_imm]
        if len(ops) not in (3, 4):
            raise ValueError(f"{mnemonic} expects 3 or 4 operands")

        d["rs1"] = parse_reg(ops[0])
        d["rs2"] = parse_reg(ops[1])
        target = ops[2].strip()

        if len(ops) == 3 and IMM_RE.match(target):
            # Keep old packed-immediate behavior for compatibility.
            packed_off = parse_int(target)
            incr_imm, imm1, imm9 = split_br_imm(packed_off)
        else:
            if labels is not None and target in labels:
                if pc is None:
                    raise ValueError("Internal error: missing PC for label-based branch")
                delta_bytes = labels[target] - pc
            elif IMM_RE.match(target):
                delta_bytes = parse_int(target)
            else:
                raise ValueError(f"Unknown branch label: {target!r}")

            imm1, imm9 = split_br_target_imm(delta_bytes)
            incr_imm = parse_incr_imm7(ops[3]) if len(ops) == 4 else 0

        d["incr_imm"] = incr_imm
        d["imm1"] = imm1
        d["imm9"] = imm9
        return d

    if instr_type == "MI":
        # jal rd, imm25  OR jal imm25 (rd defaults 0)
        if len(ops) == 1:
            d["rd"] = 0
            d["imm25"] = parse_int(ops[0])
        else:
            d["rd"] = parse_reg(ops[0])
            d["imm25"] = parse_int(ops[1])
        return d

    if instr_type == "VI":
        # VI format supports two immediate encodings:
        # 1) arithmetic/scalar-style .vi ops use BF16-encoded immediate payload
        # 2) control-style .vi ops (shift/rsum/rmin/rmax) use raw immediate bits
        d["vd"]  = parse_reg(ops[0])
        d["vs1"] = parse_reg(ops[1])
        if mnemonic in RAW_VI_IMM_MNEMONICS:
            imm16 = parse_int(ops[2]) & 0xFFFF
        else:
            imm16 = _bf16_bits(parse_number(ops[2]))
        lo, hi = split_imm16(imm16)
        d["imm8_1"] = lo
        d["imm8_2"] = hi
        if len(ops) >= 4:
            d["mask"] = parse_int(ops[3])
        return d

    if instr_type == "VV":
        # add.vv vd, vs1, vs2, mask, sac
        d["vd"] = parse_reg(ops[0])
        d["vs1"] = parse_reg(ops[1])
        d["vs2"] = parse_reg(ops[2])
        d["mask"] = parse_int(ops[3])
        d["sac"] = parse_int(ops[4])
        return d

    if instr_type == "VS":
        # add.vs vd, vs1, rs1, mask
        d["vd"] = parse_reg(ops[0])
        d["vs1"] = parse_reg(ops[1])
        d["rs1"] = parse_reg(ops[2])
        d["mask"] = parse_int(ops[3])
        return d

    if instr_type == "VM":
        # vreg.ld vd, rs1, num_cols, num_rows, sid, rc, rc_id
        d["vd"] = parse_reg(ops[0])
        d["rs1"] = parse_reg(ops[1])
        d["num_cols"] = parse_int(ops[2])
        d["num_rows"] = parse_int(ops[3])
        d["sid"] = parse_int(ops[4])
        d["rc"] = parse_int(ops[5])
        d["rc_id"] = parse_int(ops[6])
        return d

    if instr_type == "SDMA":
        # scpad.ld rs1, rs2, num_cols, num_rows, sid
        d["rs1"] = parse_reg(ops[0])
        d["rs2"] = parse_reg(ops[1])
        d["num_cols"] = parse_int(ops[2])
        d["num_rows"] = parse_int(ops[3])
        d["sid"] = parse_int(ops[4])
        return d

    if instr_type == "MTS":
        # mv.mts rd, vms
        d["rd"] = parse_reg(ops[0])
        d["vms"] = parse_int(ops[1])
        return d

    if instr_type == "STM":
        # mv.stm vmd, rs1
        d["vmd"] = parse_int(ops[0])
        d["rs1"] = parse_reg(ops[1])
        return d

    if instr_type == "MVV":
        # mgt.mvv vmd, vs1, vs2, mask
        d["vmd"] = parse_int(ops[0])
        d["vs1"] = parse_reg(ops[1])
        d["vs2"] = parse_reg(ops[2])
        d["mask"] = parse_int(ops[3])
        return d

    if instr_type == "MVS":
        # mgt.mvs vmd, vs1, rs1, mask
        d["vmd"] = parse_int(ops[0])
        d["vs1"] = parse_reg(ops[1])
        d["rs1"] = parse_reg(ops[2])
        d["mask"] = parse_int(ops[3])
        return d

    if instr_type == "VTS":
        # vmov.vts rd, vs1, imm8
        d["rd"]  = parse_reg(ops[0])
        d["vs1"] = parse_reg(ops[1])
        d["imm8"] = parse_int(ops[2])
        return d

    if instr_type == "S":
        if ops:
            raise ValueError(f"{mnemonic} takes no operands")
        return d

    raise NotImplementedError(f"Type {instr_type} not implemented yet for {mnemonic}")


def assemble_file(in_data: str) -> list[tuple[str, str]]:
    out = []
    stop_markers = {"data mem", ".data"}
    labels: dict[str, int] = {}
    parsed_lines: list[tuple[int, str, str]] = []
    pc = 0

    for raw in in_data.splitlines():
        code, cmt = strip_comment(raw)
        code = code.strip()

        if not code:
            continue

        line_labels, code = parse_leading_labels(code)
        for label in line_labels:
            if label in labels:
                raise ValueError(f"Duplicate label: {label}")
            labels[label] = pc

        if not code:
            continue

        lowered = code.lower()
        if lowered in stop_markers:
            break

        # ignore typical directives
        if code.startswith("."):
            continue

        parsed_lines.append((pc, code, cmt))
        pc += INSTR_ADDR_STRIDE

    for pc, code, cmt in parsed_lines:
        mnemonic, ops = split_mnemonic_operands(code)
        if not mnemonic:
            continue

        instr_dict = asm_to_instr_dict(mnemonic, ops, labels=labels, pc=pc)
        hex48 = encode_instruction(instr_dict).upper()
        if len(hex48) != 12:
            raise ValueError(f"encode_instruction returned {hex48!r} (expected 12 hex chars)")
        out.append((hex48, cmt))

    return out
# ---- Label Branch Support End ----

def emit_test_format(instrs: list[tuple[str, str]]) -> str:
    nop_hex = encode_instruction({"opcode": INVERT_OPCODES["nop.s"][0]}).upper()

    lines = []
    addr = 0
    i = 0
    while i < len(instrs):
        chunk = instrs[i:i+VIRTUAL_PACKET_SIZE]
        hex_words = [h for (h, _) in chunk]
        comments = [c for (_, c) in chunk if c]

        while len(hex_words) < REAL_PACKET_SIZE:
            hex_words.append(nop_hex)

        # Prefer comment from first real instruction, or join if you want
        comment = comments[0] if comments else ""
        cmt_str = f" # {comment}" if comment else ""

        lines.append(f"{addr:08X}: " + " ".join(hex_words) + cmt_str)

        addr += INSTR_ADDR_STRIDE
        i += VIRTUAL_PACKET_SIZE

    return "\n".join(lines)

def _check_endian(endian: str) -> str:
    if endian not in ("little", "big"):
        raise ValueError("endian must be 'little' or 'big'")
    return endian


def _mask_u(nbytes: int) -> int:
    return (1 << (8 * nbytes)) - 1


def _int_to_bytes(value: int, nbytes: int, *, signed: bool, endian: str) -> bytes:
    # Range-check like Python int.to_bytes would
    lo = -(1 << (8 * nbytes - 1)) if signed else 0
    hi = (1 << (8 * nbytes - (1 if signed else 0))) - 1 if signed else (1 << (8 * nbytes)) - 1
    if value < lo or value > hi:
        raise ValueError(f"value {value} out of range for {'i' if signed else 'u'}{nbytes*8}")
    return int(value).to_bytes(nbytes, byteorder=endian, signed=signed)


def _f32_bits(x: float) -> int:
    return struct.unpack("<I", struct.pack("<f", float(x)))[0]


def _bf16_bits(x: float) -> int:
    # bfloat16 = top 16 bits of float32
    return (_f32_bits(x) >> 16) & 0xFFFF


@dataclass
class DRAMWriter:
    endian: str = "little"
    allow_overwrite: bool = True

    _bytes: Dict[int, int] = field(default_factory=dict)  # byte_addr -> [0..255]

    def __post_init__(self) -> None:
        self.endian = _check_endian(self.endian)

    # ---------------------------
    # Low-level byte operations
    # ---------------------------
    def write_bytes(self, addr: int, data: BytesLike) -> None:
        addr = int(addr)
        b = bytes(data)
        for i, v in enumerate(b):
            a = addr + i
            if (not self.allow_overwrite) and (a in self._bytes) and (self._bytes[a] != v):
                raise ValueError(f"Overwrite at byte addr 0x{a:08X}: {self._bytes[a]:02X} -> {v:02X}")
            self._bytes[a] = v

    def write_zeros(self, addr: int, nbytes: int) -> None:
        self.write_bytes(addr, b"\x00" * int(nbytes))

    # ---------------------------
    # Integer typed writes
    # ---------------------------
    def write_u(self, addr: int, value: IntLike, nbytes: int) -> None:
        self.write_bytes(addr, _int_to_bytes(int(value), int(nbytes), signed=False, endian=self.endian))

    def write_i(self, addr: int, value: IntLike, nbytes: int) -> None:
        self.write_bytes(addr, _int_to_bytes(int(value), int(nbytes), signed=True, endian=self.endian))

    def u8(self, addr: int, v: int) -> None:  self.write_u(addr, v, 1)
    def u16(self, addr: int, v: int) -> None: self.write_u(addr, v, 2)
    def u32(self, addr: int, v: int) -> None: self.write_u(addr, v, 4)
    def u64(self, addr: int, v: int) -> None: self.write_u(addr, v, 8)

    def i8(self, addr: int, v: int) -> None:  self.write_i(addr, v, 1)
    def i16(self, addr: int, v: int) -> None: self.write_i(addr, v, 2)
    def i32(self, addr: int, v: int) -> None: self.write_i(addr, v, 4)
    def i64(self, addr: int, v: int) -> None: self.write_i(addr, v, 8)

    # ---------------------------
    # Float typed writes
    # ---------------------------
    def f32(self, addr: int, x: float) -> None:
        b = struct.pack("<f" if self.endian == "little" else ">f", float(x))
        self.write_bytes(addr, b)

    def f64(self, addr: int, x: float) -> None:
        b = struct.pack("<d" if self.endian == "little" else ">d", float(x))
        self.write_bytes(addr, b)

    def bf16(self, addr: int, x: float) -> None:
        # Store as 16-bit value in memory (byte-addressed)
        self.u16(addr, _bf16_bits(x))

    def f16(self, addr: int, x: float) -> None:
        if np is None:
            raise RuntimeError("numpy is required for f16() (float16 conversion)")
        v = np.float16(x)
        # Ensure endian matches configuration
        dt = np.dtype(np.float16).newbyteorder("<" if self.endian == "little" else ">")
        b = np.array(v, dtype=dt).tobytes()
        self.write_bytes(addr, b)


    def numpy(self, addr: int, arr, *, order: str = "C") -> None:
        if np is None:
            raise RuntimeError("numpy is required for numpy() bulk writes")
        if not isinstance(arr, np.ndarray):
            arr = np.asarray(arr)

        # Normalize dtype endianness to match configured endian
        target = "<" if self.endian == "little" else ">"
        dt = arr.dtype
        if dt.byteorder not in ("=", "|", target):
            arr = arr.astype(dt.newbyteorder(target), copy=False)

        b = arr.tobytes(order=order)
        self.write_bytes(addr, b)


    def _word_addrs(self, *, stride: int = 2) -> List[int]:
        if not self._bytes:
            return []
        if stride <= 0:
            raise ValueError("stride must be positive")
        mn = min(self._bytes.keys())
        mx = max(self._bytes.keys())
        # Emit overlapping 32-bit words at even-byte boundaries by default.
        # This preserves bf16 placement in output (e.g., words starting at 0x2, 0x4, ...).
        start = mn - (mn % stride)
        end = mx - (mx % stride)
        return list(range(start, end + stride, stride))

    def to_u32_words(self, *, include_zeros: bool = False, stride: int = 2) -> Dict[int, int]:
        out: Dict[int, int] = {}
        for wa in self._word_addrs(stride=stride):
            bs = [self._bytes.get(wa + i, 0) for i in range(4)]
            if self.endian == "little":
                w = bs[0] | (bs[1] << 8) | (bs[2] << 16) | (bs[3] << 24)
            else:
                w = bs[3] | (bs[2] << 8) | (bs[1] << 16) | (bs[0] << 24)

            if include_zeros or w != 0:
                out[wa] = w & 0xFFFFFFFF
        return out

    def render_data_mem(self, *, include_zeros: bool = False, stride: int = 2) -> str:
        words = self.to_u32_words(include_zeros=include_zeros, stride=stride)
        lines = [f"{addr:08X}: {val:08X}" for addr, val in sorted(words.items())]
        return "\n".join(lines)

def render_testfile(instr_lines: str, dram_render: str) -> str:
    parts: List[str] = []

    parts.append(instr_lines.strip("\n"))

    parts.append("") 
    parts.append(".data")
    parts.append("")
    parts.append(dram_render)

    return "\n".join([p for p in parts if p is not None]).rstrip() + "\n"
def convert_instructions(instructions_old):
    #input = hex, comment output = op, dsts, srcs, mem_key
    instructions = []
    for instr, comment in instructions_old:
        if(comment):
            operation = comment.split()[0]
        else:
            operation = "nop.s"
        instructions.append((operation, [], [], None))
    return instructions

def build_dependency_graph(instructions, latency_map, single_lsu=True):
    last_write = {}
    last_mem_cycle = -1
    last_store_at = {}
    ready_time = [0 for _ in range(len(instructions))]

    for i in range(len(instructions)):
        op, dsts, srcs, mem_key = instructions[i] 
        start = 0
        for s in srcs:
            if s in last_write:
                if last_write[s] > start:
                    start = last_write[s]

        is_load = op.startswith("lw")
        is_store = op.startswith("sw") or op.startswith("sd")
        is_mem = is_load or is_store

        if single_lsu and is_mem:
            if last_mem_cycle + 1 > start:
                start = last_mem_cycle + 1

        if is_mem and mem_key is not None:
            if is_load:
                if mem_key in last_store_at and last_store_at[mem_key] > start:
                    start = last_store_at[mem_key]
            else:
                if mem_key in last_store_at and last_store_at[mem_key] > start:
                    start = last_store_at[mem_key]

        ready_time[i] = start

        latency = latency_map.get(op, 1)
        for d in dsts:
            last_write[d] = start + latency

        if is_mem:
            last_mem_cycle = start
            if is_store and mem_key is not None:
                last_store_at[mem_key] = start + latency

    return ready_time


def greedy_pack(instructions, ready_time, max_width=4):
    packets = []
    scheduled = [False for _ in range(len(instructions))]
    current_cycle = 0
    

    def is_control(op):
        if op in {"j", "jal", "jalr"}:
            return True
        if op.startswith("b"):
            return True
        return False

    while not all(scheduled):
        packet = []
        packet_reads = set()
        packet_writes = set()
        mem_in_packet = False
        count = 0

        for i in range(len(instructions)):
            op, dsts, srcs, mem_key = instructions[i]
            if scheduled[i]:
                continue
            if ready_time[i] > current_cycle:
                continue

            if is_control(op):
                if count == 0:
                    packet.append(i)
                    scheduled[i] = True
                break

            is_mem = op.startswith("lw") or op.startswith("sw") or op.startswith("sd")
            if mem_in_packet and is_mem:
                continue

            hazard = False
            for s in srcs:
                if s in packet_writes:
                    hazard = True
                    break
            for d in dsts:
                if d in packet_writes or d in packet_reads:
                    hazard = True
                    break
            if hazard:
                continue

            packet.append(i)
            for s in srcs:
                packet_reads.add(s)
            for d in dsts:
                packet_writes.add(d)
            if is_mem:
                mem_in_packet = True
            scheduled[i] = True
            count += 1
            if count == max_width:
                break

        if len(packet) == 0:
            packets.append([])
            current_cycle += 1
            continue

        packets.append(packet)
        current_cycle += 1

    return packets

if __name__ == "__main__":
    
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input", type=Path, default=None, help="Input assembly file")
    ap.add_argument("-o", "--output", type=Path, default=None, help="Output test file")
    args = ap.parse_args()

    demo_asm = """
        lui.s   $1, 0
        addi.s  $1, $0, 60

        lw.s    $2, 0($1)          # $2 = TILE_ADDR
        lw.s    $3, 4($1)          # $3 = SCPAD_ADDR
        scpad.ld $3, $2, 4, 4, 0

        # mask1 = 0x0000000F  (enable lanes 0..3 only)
        addi.s  $4, $0, 15
        mv.stm  1, $4

        # mask2 = 0xFFFFFFF0  (enable lanes 4..31 only)
        addi.s  $5, $0, -16
        mv.stm  2, $5

        # ---------------- row 0 (rc_id MUST be 0..3) ----------------
        vreg.ld  $10, $3, 4, 4, 0, 1, 0
        sub.vv   $10, $10, $10, 2, 0      # clear lanes 4..31

        rmax.vi  $11, $10, 0, 1
        vmov.vts $1, $11, 0
        sub.vs   $10, $10, $1, 1
        expi.vi  $12, $10, 0, 1
        rsum.vi  $13, $12, 64, 1          # 64 = broadcast reduction result
        vmov.vts $6, $13, 0               # use $6 (NOT $2)
        div.vs   $10, $12, $6, 1
        vreg.st  $10, $3, 4, 4, 0, 1, 0

        # ---------------- row 1 ----------------
        vreg.ld  $10, $3, 4, 4, 0, 1, 1
        sub.vv   $10, $10, $10, 2, 0

        rmax.vi  $11, $10, 0, 1
        vmov.vts $1, $11, 0
        sub.vs   $10, $10, $1, 1
        expi.vi  $12, $10, 0, 1
        rsum.vi  $13, $12, 64, 1
        vmov.vts $6, $13, 0
        div.vs   $10, $12, $6, 1
        vreg.st  $10, $3, 4, 4, 0, 1, 1

        # ---------------- row 2 ----------------
        vreg.ld  $10, $3, 4, 4, 0, 1, 2
        sub.vv   $10, $10, $10, 2, 0

        rmax.vi  $11, $10, 0, 1
        vmov.vts $1, $11, 0
        sub.vs   $10, $10, $1, 1
        expi.vi  $12, $10, 0, 1
        rsum.vi  $13, $12, 64, 1
        vmov.vts $6, $13, 0
        div.vs   $10, $12, $6, 1
        vreg.st  $10, $3, 4, 4, 0, 1, 2

        # ---------------- row 3 ----------------
        vreg.ld  $10, $3, 4, 4, 0, 1, 3
        sub.vv   $10, $10, $10, 2, 0

        rmax.vi  $11, $10, 0, 1
        vmov.vts $1, $11, 0
        sub.vs   $10, $10, $1, 1
        expi.vi  $12, $10, 0, 1
        rsum.vi  $13, $12, 64, 1
        vmov.vts $6, $13, 0
        div.vs   $10, $12, $6, 1
        vreg.st  $10, $3, 4, 4, 0, 1, 3

        scpad.st $3, $2, 4, 4, 0          # store back to TILE_ADDR using $2
        halt.s

    """

    asm = args.input.read_text() if args.input is not None else demo_asm
    instrs = assemble_file(asm)       

    instructions = convert_instructions(instrs)
    ready = build_dependency_graph(convert_instructions(instrs), DEFAULT_LATENCY_MAP)

    packets = greedy_pack(instructions, ready)

    print("ready:", ready)
    print("packets:", packets)

    scheduled = []
    for packet in packets:
        for i in packet:
            scheduled.append(instrs[i])

    instr_text = emit_test_format(scheduled)

    if args.input is None:
        img = DRAMWriter() 
        # Memory layout for softmax test
        # mem[0x0]   = address of tile in memory (0xCAFA)
        # mem[0x4]   = scratchpad address (1)
        # mem[0xCAFA] onwards = tile data
        
        TILE_ADDR = 0xCAFA
        SCPAD_ADDR = 1
        ARG_BASE = 60  # must match: addi.s $1, $0, 60

        img.u32(ARG_BASE + 0, TILE_ADDR)   # mem[60] = tile base address
        img.u32(ARG_BASE + 4, SCPAD_ADDR)# Store scratchpad address
        
        # Initialize 4x4 tile with values 1.0 to 16.0
        base_addr = TILE_ADDR
        tile_values = list(range(1, 17))  # 1 to 16
        for i, val in enumerate(tile_values):
            addr = base_addr + (i * 2)  # Each BF16 is 2 bytes
            img.bf16(addr, float(val))
        
        data_text = img.render_data_mem(include_zeros=False)
    else:
        data_text = ""

    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
    else: 
        print(final)
