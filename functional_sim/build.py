from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, List, Union
import struct
import os
import sys, re 
from pathlib import Path
import argparse
import numpy as np

load_tile_data = None
try:
    from .src.misc.opcode_table import OPCODES, name_to_opcode
except Exception:
    from src.misc.opcode_table import OPCODES, name_to_opcode

try:
    from .instruction_latency import latency as DEFAULT_LATENCY_MAP

except Exception:
    try:
        from instruction_latency import latency as DEFAULT_LATENCY_MAP
    except Exception:
        DEFAULT_LATENCY_MAP: Dict[str, int] = {}

INVERT_OPCODES = name_to_opcode()
VIRTUAL_PACKET_SIZE = 1 
REAL_PACKET_SIZE = 4
GRAPH_PACKET_WIDTH = REAL_PACKET_SIZE
RAW_VI_IMM_MNEMONICS = {"shift.vi", "rsum.vi", "rmin.vi", "rmax.vi"}
INSTR_BYTE_WIDTH = 6
INSTR_ADDR_STRIDE = REAL_PACKET_SIZE * INSTR_BYTE_WIDTH

MEM_LOAD_MNEMONICS = {
    "lw.s",
    "lhw.s",
    "vreg.ld",
    "scpad.ld",
    "lw.vi",
}
MEM_STORE_MNEMONICS = {
    "sw.s",
    "shw.s",
    "vreg.st",
    "scpad.st",
}
CONTROL_MNEMONICS = (
    {name.lower() for name, instr_type in OPCODES.values() if instr_type == "BR"}
    | {"jal", "jalr", "halt.s", "barrier.s", "ret"}
)

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
        # VM-Type: vd 7-14, rs1 15-22, num_cols 23-27, num_rows 28-32, sid 33, rc 34, rc_id 35-39, rc_id_is_reg 40
        vd = instr_dict.get('vd', 0)
        rs1 = instr_dict.get('rs1', 0)
        num_cols = instr_dict.get('num_cols', 0)
        num_rows = instr_dict.get('num_rows', 0)
        sid = instr_dict.get('sid', 0)
        rc = instr_dict.get('rc', 0)
        rc_id = instr_dict.get('rc_id', 0)
        rc_id_is_reg = int(instr_dict.get('rc_id_is_reg', False))
        
        instruction |= (vd & 0xFF) << 7
        instruction |= (rs1 & 0xFF) << 15
        instruction |= (num_cols & 0x1F) << 23
        instruction |= (num_rows & 0x1F) << 28
        instruction |= (sid & 0x1) << 33
        instruction |= (rc & 0x1) << 34
        instruction |= (rc_id & 0x1F) << 35
        instruction |= (rc_id_is_reg & 0x1) << 40
        
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
        # li.s rd, imm25  OR lui.s rd, imm25
        if len(ops) == 1:
            d["rd"] = 0
            imm_str = ops[0].strip()
        else:
            d["rd"] = parse_reg(ops[0])
            imm_str = ops[1].strip()

        if IMM_RE.match(imm_str):
            d["imm25"] = parse_int(imm_str)
        elif labels is not None and imm_str in labels:
            if pc is None:
                raise ValueError("Internal error: missing PC for label-based MI")
            d["imm25"] = labels[imm_str] - pc
        else:
            raise ValueError(f"Bad MI immediate or unknown label: {imm_str!r}")
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
        
        # FIXME: rc_id might eventually come from a register rather than an immediate
        # d["rc_id"] = parse_reg(ops[6])
        target_rc_id = ops[6].strip()
        if target_rc_id.startswith("$"):
            d["rc_id"] = parse_reg(target_rc_id)
            d["rc_id_is_reg"] = True
        else:
            d["rc_id"] = parse_int(target_rc_id)
            d["rc_id_is_reg"] = False
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

def emit_test_format(
    instrs: list[tuple[str, str]],
    *,
    virtual_packet_size: int = VIRTUAL_PACKET_SIZE,
) -> str:
    nop_hex = encode_instruction({"opcode": INVERT_OPCODES["nop.s"][0]}).upper()

    lines = []
    addr = 0
    i = 0
    while i < len(instrs):
        chunk = instrs[i:i+virtual_packet_size]
        hex_words = [h for (h, _) in chunk]
        comments = [c for (_, c) in chunk if c]

        while len(hex_words) < REAL_PACKET_SIZE:
            hex_words.append(nop_hex)

        comment = " | ".join(comments) if comments else ""
        cmt_str = f" # {comment}" if comment else ""

        lines.append(f"{addr:08X}: " + " ".join(hex_words) + cmt_str)

        addr += INSTR_ADDR_STRIDE
        i += virtual_packet_size

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
def _sign_extend(value: int, bits: int) -> int:
    sign = 1 << (bits - 1)
    return (value ^ sign) - sign


def _base_op(op: str) -> str:
    return op.lower().split(".", 1)[0]


def _is_memory_load(op: str) -> bool:
    op_norm = op.lower()
    return op_norm in MEM_LOAD_MNEMONICS or _base_op(op_norm) == "lw"


def _is_memory_store(op: str) -> bool:
    op_norm = op.lower()
    return op_norm in MEM_STORE_MNEMONICS or _base_op(op_norm) in {"sw", "sd", "shw"}


def _is_memory_op(op: str) -> bool:
    return _is_memory_load(op) or _is_memory_store(op)


def _is_control_op(op: str) -> bool:
    op_norm = op.lower()
    return op_norm in CONTROL_MNEMONICS or _base_op(op_norm) in {"j", "jal", "jalr", "ret", "halt", "barrier"}


def _decode_instruction_for_graph(hex_word: str) -> tuple[str, list[str], list[str], object]:
    raw = int(hex_word, 16)
    opcode = raw & 0x7F
    if opcode not in OPCODES:
        return "nop.s", [], [], None

    mnemonic, instr_type = OPCODES[opcode]
    dsts: list[str] = []
    srcs: list[str] = []
    mem_key = None

    def r(reg: int) -> str:
        return f"r{reg}"

    def v(reg: int) -> str:
        return f"v{reg}"

    if instr_type == "R":
        rd = (raw >> 7) & 0xFF
        rs1 = (raw >> 15) & 0xFF
        rs2 = (raw >> 23) & 0xFF
        dsts = [r(rd)]
        srcs = [r(rs1), r(rs2)]

    elif instr_type == "I":
        rd = (raw >> 7) & 0xFF
        rs1 = (raw >> 15) & 0xFF
        dsts = [r(rd)]
        srcs = [r(rs1)]

    elif instr_type == "M":
        rd = (raw >> 7) & 0xFF
        rs1 = (raw >> 15) & 0xFF
        imm12 = _sign_extend((raw >> 23) & 0xFFF, 12)
        if _is_memory_load(mnemonic):
            dsts = [r(rd)]
            srcs = [r(rs1)]
            mem_key = (r(rs1), imm12)
        elif _is_memory_store(mnemonic):
            srcs = [r(rd), r(rs1)]
            mem_key = (r(rs1), imm12)
        else:
            dsts = [r(rd)]
            srcs = [r(rs1)]

    elif instr_type == "BR":
        rs1 = (raw >> 15) & 0xFF
        rs2 = (raw >> 23) & 0xFF
        srcs = [r(rs1), r(rs2)]

    elif instr_type == "MI":
        rd = (raw >> 7) & 0xFF
        if rd != 0:
            dsts = [r(rd)]

    elif instr_type == "VV":
        vd = (raw >> 7) & 0xFF
        vs1 = (raw >> 15) & 0xFF
        vs2 = (raw >> 23) & 0xFF
        dsts = [v(vd)]
        srcs = [v(vs1), v(vs2)]

    elif instr_type == "VS":
        vd = (raw >> 7) & 0xFF
        vs1 = (raw >> 15) & 0xFF
        rs1 = (raw >> 23) & 0xFF
        dsts = [v(vd)]
        srcs = [v(vs1), r(rs1)]

    elif instr_type == "VI":
        vd = (raw >> 7) & 0xFF
        vs1 = (raw >> 15) & 0xFF
        dsts = [v(vd)]
        srcs = [v(vs1)]

    elif instr_type == "VM":
        vd = (raw >> 7) & 0xFF
        rs1 = (raw >> 15) & 0xFF
        rc_id_is_reg = (raw >> 40) & 0x1
        rc_id_reg = (raw >> 35) & 0x1F
        if _is_memory_store(mnemonic):
            srcs = [v(vd), r(rs1)]
        else:
            dsts = [v(vd)]
            srcs = [r(rs1)]
        if rc_id_is_reg:
            srcs.append(r(rc_id_reg))
        mem_key = (r(rs1), "vreg")

    elif instr_type == "SDMA":
        rs1_rd1 = (raw >> 7) & 0xFF
        rs2 = (raw >> 15) & 0xFF
        if _is_memory_store(mnemonic):
            srcs = [r(rs1_rd1), r(rs2)]
        else:
            dsts = [r(rs1_rd1)]
            srcs = [r(rs1_rd1), r(rs2)]
        mem_key = (r(rs2), "scpad")

    elif instr_type == "MTS":
        rd = (raw >> 7) & 0xFF
        vms = (raw >> 15) & 0xFF
        dsts = [r(rd)]
        srcs = [v(vms)]

    elif instr_type == "STM":
        vmd = (raw >> 7) & 0xFF
        rs1 = (raw >> 15) & 0xFF
        dsts = [v(vmd)]
        srcs = [r(rs1)]

    elif instr_type == "VTS":
        rd = (raw >> 7) & 0xFF
        vs1 = (raw >> 15) & 0xFF
        dsts = [r(rd)]
        srcs = [v(vs1)]

    elif instr_type == "MVV":
        vmd = (raw >> 7) & 0xF
        vs1 = (raw >> 11) & 0xFF
        vs2 = (raw >> 19) & 0xFF
        dsts = [v(vmd)]
        srcs = [v(vs1), v(vs2)]

    elif instr_type == "MVS":
        vmd = (raw >> 7) & 0xF
        vs1 = (raw >> 11) & 0xFF
        rs1 = (raw >> 19) & 0xFF
        dsts = [v(vmd)]
        srcs = [v(vs1), r(rs1)]

    return mnemonic, dsts, srcs, mem_key


def convert_instructions(instructions_old: list[tuple[str, str]]) -> list[tuple[str, list[str], list[str], object]]:
    return [_decode_instruction_for_graph(hex_word) for hex_word, _ in instructions_old]


def _op_latency(op: str, latency_map: Dict[str, int]) -> int:
    op_norm = op.lower()
    op_base = _base_op(op_norm)

    for key in (op_norm, op_base):
        if key in latency_map:
            try:
                return max(1, int(latency_map[key]))
            except (TypeError, ValueError):
                pass

    if _is_memory_load(op_norm):
        return 3
    if _is_memory_store(op_norm):
        return 1
    if _is_control_op(op_norm):
        return 1
    if op_base in {"mul", "muli"}:
        return 3
    if op_base in {"div", "divi", "mod", "modi", "expi", "sqrti", "gemm"}:
        return 8
    return 1


def build_dependency_graph(
    instructions: list[tuple[str, list[str], list[str], object]],
    latency_map: Dict[str, int],
    single_lsu: bool = True,
) -> list[int]:
    last_write: Dict[str, int] = {}
    last_mem_cycle = -1
    last_store_at: Dict[object, int] = {}
    ready_time = [0 for _ in range(len(instructions))]

    for i, (op, dsts, srcs, mem_key) in enumerate(instructions):
        start = 0
        for s in srcs:
            if s in last_write and last_write[s] > start:
                start = last_write[s]

        is_load = _is_memory_load(op)
        is_store = _is_memory_store(op)
        is_mem = is_load or is_store

        if single_lsu and is_mem and (last_mem_cycle + 1 > start):
            start = last_mem_cycle + 1

        if is_mem and mem_key is not None:
            if mem_key in last_store_at and last_store_at[mem_key] > start:
                start = last_store_at[mem_key]

        ready_time[i] = start

        op_latency = _op_latency(op, latency_map)
        for d in dsts:
            last_write[d] = start + op_latency

        if is_mem:
            last_mem_cycle = start
            if is_store and mem_key is not None:
                last_store_at[mem_key] = start + op_latency

    return ready_time


def greedy_pack(
    instructions: list[tuple[str, list[str], list[str], object]],
    ready_time: list[int],
    max_width: int = GRAPH_PACKET_WIDTH,
) -> list[list[int]]:
    packets: list[list[int]] = []
    scheduled = [False for _ in range(len(instructions))]
    current_cycle = 0

    while not all(scheduled):
        packet: list[int] = []
        packet_reads: set[str] = set()
        packet_writes: set[str] = set()
        mem_in_packet = False
        count = 0

        for i, (op, dsts, srcs, _) in enumerate(instructions):
            if scheduled[i]:
                continue
            if ready_time[i] > current_cycle:
                continue

            if _is_control_op(op):
                if any(not scheduled[j] for j in range(i)):
                    break
                if count == 0:
                    packet.append(i)
                    scheduled[i] = True
                break

            is_mem = _is_memory_op(op)
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


def materialize_scheduled_instructions(
    instrs: list[tuple[str, str]],
    packets: list[list[int]],
    *,
    packet_width: int = GRAPH_PACKET_WIDTH,
) -> list[tuple[str, str]]:
    nop_hex = encode_instruction({"opcode": INVERT_OPCODES["nop.s"][0]}).upper()
    nop_entry = (nop_hex, "")
    scheduled: list[tuple[str, str]] = []

    for packet in packets:
        if not packet:
            scheduled.extend([nop_entry] * packet_width)
            continue

        for idx in packet:
            scheduled.append(instrs[idx])
        scheduled.extend([nop_entry] * (packet_width - len(packet)))

    return scheduled

if __name__ == "__main__":
    
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input", type=Path, default=None, help="Input assembly file")
    ap.add_argument("-o", "--output", type=Path, default=None, help="Output test file")
    ap.add_argument("--no-graph", action="store_true", help="Disable dependency graph packet scheduling")
    args = ap.parse_args()

    demo_asm = """
        lw.s    $1, 0($0)        # $1 = *(0x0) = 0x100
        lw.s    $2, 0($1)        # $2 = *(0x100)
        addi.s  $2, $2, 1        # $2++
        sw.s    $2, 0($1)        # *(0x100) = $2
        lw.s    $3, 0($1)        # $3 = *(0x100) (should match)
        halt.s
    """

    asm = args.input.read_text() if args.input is not None else demo_asm
    instrs = assemble_file(asm)
    if args.no_graph:
        instr_text = emit_test_format(instrs)
    else:
        dependency_instrs = convert_instructions(instrs)
        ready = build_dependency_graph(dependency_instrs, DEFAULT_LATENCY_MAP)
        packets = greedy_pack(dependency_instrs, ready, max_width=GRAPH_PACKET_WIDTH)
        scheduled = materialize_scheduled_instructions(
            instrs,
            packets,
            packet_width=GRAPH_PACKET_WIDTH,
        )
        instr_text = emit_test_format(
            scheduled,
            virtual_packet_size=GRAPH_PACKET_WIDTH,
        )

    if args.input is None:
        img = DRAMWriter() 
        #  mem[0x0] -> 0x100
        img.u32(0x0000_0000, 0x0000_0100)
        #  mem[0x100] -> 5 (expect becomes 6)
        img.u32(0x0000_0100, 0x0000_0005)
        data_text = img.render_data_mem(include_zeros=False)
    else:
        data_text = ""

    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
    else: 
        print(final)
