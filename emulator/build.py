from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, List, Optional, Union
import struct
import os
import sys, re 
from pathlib import Path
import argparse
import numpy as np

from src.misc.opcode_table import OPCODES, name_to_opcode

INVERT_OPCODES = name_to_opcode()
VIRTUAL_PACKET_SIZE = 1
REAL_PACKET_SIZE = 4

# Default latency (cycles) for VLIW scheduling; load/stores often have higher latency.
DEFAULT_LATENCY_MAP = {
    "lw.s": 2, "sw.s": 2, "lhw.s": 2, "shw.s": 2,
    "jal": 1, "jalr": 1,
}

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
MEM_RE = re.compile(r"^([+-]?(?:0x[0-9a-fA-F]+|0b[01]+|\d+))\(\s*\$(?:x)?(\d+)\s*\)$", re.IGNORECASE)
LABEL_RE = re.compile(r"^[A-Za-z_]\w*:$")

def parse_int(s: str) -> int:
    s = s.strip()
    if not IMM_RE.match(s):
        raise ValueError(f"Bad immediate: {s!r}")
    return int(s, 0)  # supports 123, 0x10, 0b1010, -4

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



def asm_to_instr_dict(mnemonic: str, ops: list[str]) -> dict:
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
        # beq.s rs1, rs2, off
        d["rs1"] = parse_reg(ops[0])
        d["rs2"] = parse_reg(ops[1])
        off = parse_int(ops[2])
        incr_imm, imm1, imm9 = split_br_imm(off)
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
        # addi.vi vd, vs1, imm16 [, mask]
        d["vd"]  = parse_reg(ops[0])
        d["vs1"] = parse_reg(ops[1])
        imm16 = parse_int(ops[2])
        lo, hi = split_imm16(imm16)
        d["imm8_1"] = lo
        d["imm8_2"] = hi
        if len(ops) >= 4:
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


def get_deps_from_instr_dict(mnemonic: str, d: dict) -> tuple[str, List[int], List[int], Union[tuple, None]]:
    """
    Derive (op, dsts, srcs, mem_key) from mnemonic and the dict produced by asm_to_instr_dict.
    dsts/srcs are integer register numbers for hazard analysis; mem_key is (rs1, imm12) or None.
    """
    op = mnemonic
    dsts: List[int] = []
    srcs: List[int] = []
    mem_key = None
    instr_type = d.get("type", "S")

    if instr_type == "R":
        dsts = [d["rd"]]
        srcs = [d["rs1"], d["rs2"]]
    elif instr_type in ("I",):
        dsts = [d["rd"]]
        srcs = [d["rs1"]]
    elif instr_type == "M":
        dsts = [d["rd"]] if mnemonic.startswith("lw") or mnemonic.startswith("lhw") else []
        srcs = [d["rs1"]]
        mem_key = (d["rs1"], d["imm12"])
    elif instr_type == "BR":
        srcs = [d["rs1"], d["rs2"]]
    elif instr_type == "MI":
        if d.get("rd", 0) != 0:
            dsts = [d["rd"]]
    elif instr_type == "S":
        pass
    elif instr_type == "VTS":
        dsts = [d["rd"]]
        srcs = [d["vs1"]]
    elif instr_type in ("VV", "VS", "VI", "VM", "MVV", "MVS"):
        vd = d.get("vd") if "vd" in d else d.get("vmd")
        if vd is not None:
            dsts.append(vd)
        for k in ("vs1", "vs2", "rs1"):
            if k in d and d[k] is not None:
                srcs.append(d[k])
    elif instr_type == "SDMA":
        srcs = [d.get("rs1", d.get("rd1", 0)), d["rs2"]]
    elif instr_type in ("MTS", "STM"):
        if "rd" in d:
            dsts = [d["rd"]]
        if "vms" in d:
            srcs = [d["vms"]]
        elif "vmd" in d:
            dsts = [d["vmd"]]
        if "rs1" in d:
            srcs.append(d["rs1"])
    else:
        for k in ("rd", "vd", "vmd"):
            if k in d:
                dsts.append(d[k])
        for k in ("rs1", "rs2", "vs1", "vs2"):
            if k in d:
                srcs.append(d[k])

    return op, dsts, srcs, mem_key

def vliw_packetizer(asm_str, latency_map):
    
def _is_control_op(mnemonic: str) -> bool:
    if mnemonic in ("jal", "jalr"):
        return True
    if mnemonic.startswith("b") and mnemonic.endswith(".s"):
        return True
    return False


def _is_mem_op(mnemonic: str) -> bool:
    return mnemonic.startswith("lw") or mnemonic.startswith("sw") or mnemonic.startswith("sd") or mnemonic.startswith("lh") or mnemonic.startswith("sh")


def greedy_pack(
    instructions: List[tuple],
    ready_time: List[int],
    max_width: int = 4,
    latency_map: Optional[Dict[str, int]] = None,
) -> List[List[int]]:
    """
    Pack instructions into VLIW packets. Each instruction is (op, dsts, srcs, mem_key)
    with dsts/srcs as list of int (reg numbers). Returns list of packets (each packet
    is a list of instruction indices into instructions).
    """
    if not instructions:
        return []
    latency_map = latency_map or {}
    scheduled = [False] * len(instructions)
    current_cycle = 0
    packets: List[List[int]] = []

    while not all(scheduled):
        packet: List[int] = []
        packet_reads: set = set()
        packet_writes: set = set()
        mem_in_packet = False

        for i in range(len(instructions)):
            if scheduled[i] or ready_time[i] > current_cycle:
                continue
            op, dsts, srcs, mem_key = instructions[i]

            if _is_control_op(op):
                if len(packet) == 0:
                    packet.append(i)
                    scheduled[i] = True
                break

            if _is_mem_op(op) and mem_in_packet:
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
            packet_reads.update(srcs)
            packet_writes.update(dsts)
            if _is_mem_op(op):
                mem_in_packet = True
            scheduled[i] = True
            if len(packet) >= max_width:
                break

        packets.append(packet if packet else [])
        current_cycle += 1

    return packets


def build_vliw_packets(
    instructions: List[tuple],
    encoded: List[tuple],
    max_width: int = 4,
    latency_map: Optional[Dict[str, int]] = None,
) -> List[List[tuple]]:
    """
    Split instructions into basic blocks (using block_start flags), run dependency
    analysis and greedy packing per block, and return list of packets. Each packet
    is a list of (hex48, cmt) of length max_width (nop-padded).
    Entry format: (mnemonic, ops, instr_dict, cmt, block_start).
    """
    if not instructions or not encoded:
        return []
    latency_map = latency_map or DEFAULT_LATENCY_MAP
    nop_hex = encode_instruction({"opcode": INVERT_OPCODES["nop.s"][0]}).upper()

    # Build blocks: each entry is (mnemonic, ops, instr_dict, cmt, block_start)
    blocks: List[List[tuple]] = []
    current: List[tuple] = []
    for i, entry in enumerate(instructions):
        if len(entry) >= 5 and entry[4]:  # block_start
            if current:
                blocks.append(current)
            current = []
        current.append((i, entry))

    if current:
        blocks.append(current)

    all_packets: List[List[tuple]] = []
    for block in blocks:
        block_indices = [idx for idx, _ in block]
        block_entries = [e for _, e in block]
        deps = [
            get_deps_from_instr_dict(entry[0], entry[2])
            for entry in block_entries
        ]
        ready_time = build_dependency_graph(deps, latency_map, single_lsu=True)
        packet_indices = greedy_pack(deps, ready_time, max_width, latency_map)

        for pkt in packet_indices:
            hex_cmt = [encoded[block_indices[j]] for j in pkt]
            while len(hex_cmt) < max_width:
                hex_cmt.append((nop_hex, ""))
            all_packets.append(hex_cmt)

    return all_packets

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

        is_load = op.startswith("lw") or op.startswith("lh") #added lh and sh since they are defined as memory operations in line 474
        is_store = op.startswith("sw") or op.startswith("sd") or op.startswith("sh")
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


def assemble_file(
    in_data: str, enable_vliw: bool = False
) -> Union[List[tuple], List[List[tuple]]]:
    """
    Assemble instructions from assembly text.
    If enable_vliw=False, returns flat list of (hex48, cmt).
    If enable_vliw=True, returns list of packets (each packet is list of (hex48, cmt), nop-padded to REAL_PACKET_SIZE).
    """
    instructions: List[tuple] = []  # (mnemonic, ops, instr_dict, cmt, block_start)
    stop_markers = {"data mem", ".data"}
    next_block_start = True

    for raw in in_data.splitlines():
        code, cmt = strip_comment(raw)
        code_stripped = strip_label(code)

        if not code_stripped.strip():
            # Blank or label-only line (e.g. "L_end:")
            if raw.strip().endswith(":") or (":" in raw and re.match(r"^[A-Za-z_]\w*:\s*$", raw.strip().split("#")[0].strip())):
                next_block_start = True
            continue

        if code_stripped.strip().lower() in stop_markers:
            break

        if code_stripped.strip().startswith("."):
            continue

        mnemonic, ops = split_mnemonic_operands(code_stripped)
        if not mnemonic:
            continue

        block_start = next_block_start
        next_block_start = _is_control_op(mnemonic)

        instr_dict = asm_to_instr_dict(mnemonic, ops)
        instructions.append((mnemonic, ops, instr_dict, cmt, block_start))

    if not instructions:
        return []

    encoded = []
    for entry in instructions:
        mnemonic, ops, instr_dict, cmt = entry[0], entry[1], entry[2], entry[3]
        hex48 = encode_instruction(instr_dict).upper()
        if len(hex48) != 12:
            raise ValueError(f"encode_instruction returned {hex48!r} (expected 12 hex chars)")
        encoded.append((hex48, cmt))

    if not enable_vliw:
        return encoded

    packets = build_vliw_packets(instructions, encoded, max_width=REAL_PACKET_SIZE, latency_map=DEFAULT_LATENCY_MAP)
    return packets

def emit_test_format(instrs: List[tuple]) -> str:
    """Emit one line per VIRTUAL_PACKET_SIZE instructions (sequential packing, no VLIW)."""
    nop_hex = encode_instruction({"opcode": INVERT_OPCODES["nop.s"][0]}).upper()

    lines = []
    addr = 0
    i = 0
    while i < len(instrs):
        chunk = instrs[i : i + VIRTUAL_PACKET_SIZE]
        hex_words = [h for (h, _) in chunk]
        comments = [c for (_, c) in chunk if c]

        while len(hex_words) < REAL_PACKET_SIZE:
            hex_words.append(nop_hex)

        comment = comments[0] if comments else ""
        cmt_str = f" # {comment}" if comment else ""

        lines.append(f"{addr:08X}: " + " ".join(hex_words) + cmt_str)

        addr += 0x18
        i += VIRTUAL_PACKET_SIZE

    return "\n".join(lines)


def emit_test_format_from_packets(packets: List[List[tuple]]) -> str:
    """Emit one line per VLIW packet (each packet is already list of (hex48, cmt) padded to REAL_PACKET_SIZE)."""
    lines = []
    addr = 0
    for pkt in packets:
        hex_words = [h for (h, _) in pkt]
        comments = [c for (_, c) in pkt if c]
        comment = comments[0] if comments else ""
        cmt_str = f" # {comment}" if comment else ""
        lines.append(f"{addr:08X}: " + " ".join(hex_words) + cmt_str)
        addr += 0x18
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


    def _word_addrs(self) -> List[int]:
        if not self._bytes:
            return []
        mn = min(self._bytes.keys())
        mx = max(self._bytes.keys())
        start = mn & ~0x3
        end = (mx & ~0x3)
        return list(range(start, end + 4, 4))

    def to_u32_words(self, *, include_zeros: bool = False) -> Dict[int, int]:
        out: Dict[int, int] = {}
        for wa in self._word_addrs():
            bs = [self._bytes.get(wa + i, 0) for i in range(4)]
            if self.endian == "little":
                w = bs[0] | (bs[1] << 8) | (bs[2] << 16) | (bs[3] << 24)
            else:
                w = bs[3] | (bs[2] << 8) | (bs[1] << 16) | (bs[0] << 24)

            if include_zeros or w != 0:
                out[wa] = w & 0xFFFFFFFF
        return out

    def render_data_mem(self, *, include_zeros: bool = False) -> str:
        words = self.to_u32_words(include_zeros=include_zeros)
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

if __name__ == "__main__":
    
    ap = argparse.ArgumentParser()
    ap.add_argument("-o", "--output", type=Path, default=None, help="Output test file")
    ap.add_argument("--vliw", action="store_true", help="Enable VLIW packing with dependency analysis")
    args = ap.parse_args()

    asm = """
        lw.s    $1, 0($0)        # $1 = *(0x0) = 0x100
        lw.s    $2, 0($1)        # $2 = *(0x100)
        addi.s  $2, $2, 1        # $2++
        sw.s    $2, 0($1)        # *(0x100) = $2
        lw.s    $3, 0($1)        # $3 = *(0x100) (should match)
        halt.s
    """

    instrs = assemble_file(asm, enable_vliw=args.vliw)
    if instrs and isinstance(instrs[0], list):
        instr_text = emit_test_format_from_packets(instrs)
    else:
        instr_text = emit_test_format(instrs)

    img = DRAMWriter() 

    #  mem[0x0] -> 0x100
    img.u32(0x0000_0000, 0x0000_0100)

    #  mem[0x100] -> 5 (expect becomes 6)
    img.u32(0x0000_0100, 0x0000_0005)

    data_text = img.render_data_mem(include_zeros=False)

    final = render_testfile(instr_text, data_text)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
    else: 
        print(final)
