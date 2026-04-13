from __future__ import annotations

import argparse
import os
import re
from dataclasses import dataclass, field
from pathlib import Path
from typing import Iterable

import build as base
from instruction_latency import latency

IMM_RE = re.compile(r"^[+-]?(?:0x[0-9a-fA-F]+|0b[01]+|\d+)$")
REG_RE = re.compile(r"^\$?[xv](\d+)$", re.IGNORECASE)
NORM_REG_RE = re.compile(r"^\$(\d+)$")
MASK_RE = re.compile(r"^\$?m(\d+)$", re.IGNORECASE)
MEM_RE = re.compile(
    r"^([+-]?(?:0x[0-9a-fA-F]+|0b[01]+|\d+))\(\s*(\$?[xv]\d+)\s*\)$",
    re.IGNORECASE,
)

IGNORED_DIRECTIVE_PREFIXES = (
    ".section",
    ".align",
    "global",
    "type",
)

MNEMONIC_ALIASES = {
    "beq": "beq.s",
    "bne": "bne.s",
    "blt": "blt.s",
    "bge": "bge.s",
    "bgt": "bgt.s",
    "ble": "ble.s",
    "lw": "lw.s",
    "sw": "sw.s",
    "lhw": "lhw.s",
    "shw": "shw.s",
    "li": "li.s",
    "lui": "lui.s",
    "addi": "addi.s",
    "subi": "subi.s",
    "muli": "muli.s",
    "divi": "divi.s",
    "modi": "modi.s",
    "ori": "ori.s",
    "andi": "andi.s",
    "xori": "xori.s",
    "slli": "slli.s",
    "srli": "srli.s",
    "srai": "srai.s",
    "slti": "slti.s",
    "sltui": "sltui.s",
    "nop": "nop.s",
    "halt": "halt.s",
    "sqrt_bf": "sqrt.bf",
    "rcp_bf": "rcp.bf",
    "stbf_s": "stbf.s",
    "bfts_s": "bfts.s",
    "add_bf": "add.bf",
    "sub_bf": "sub.bf",
    "mul_bf": "mul.bf",
    "slt_bf": "slt.bf",
}


@dataclass
class AsmInstr:
    mnemonic: str
    ops: list[str]
    comment: str
    labels: list[str] = field(default_factory=list)


@dataclass
class SchedInfo:
    idx: int
    mnemonic: str
    instr_type: str
    reads: set[str]
    writes: set[str]
    latency: int
    is_vector: bool
    is_memory: bool
    is_store: bool
    is_control: bool
    mem_key: tuple | None


MEMORY_MNEMONICS = {
    "lw.s",
    "sw.s",
    "lhw.s",
    "shw.s",
    "vreg.ld",
    "vreg.st",
    "scpad.ld",
    "scpad.st",
}
MEMORY_STORE_MNEMONICS = {"sw.s", "shw.s", "vreg.st", "scpad.st"}
VECTOR_TYPES = {"VV", "VI", "VS", "VM", "VTS", "MVV", "MVS"}
CONTROL_MNEMONICS = {"jal", "jalr", "halt.s", "ret"}
NORM_MEM_RE = re.compile(
    r"^([+-]?(?:0x[0-9a-fA-F]+|0b[01]+|\d+))\(\s*\$(\d+)\s*\)$",
    re.IGNORECASE,
)


def strip_comment(line: str) -> tuple[str, str]:
    if "#" in line:
        code, cmt = line.split("#", 1)
        return code.rstrip(), cmt.strip()
    return line.rstrip(), ""


def is_ignored_directive(code: str) -> bool:
    lowered = code.lower()
    return any(lowered.startswith(prefix) for prefix in IGNORED_DIRECTIVE_PREFIXES)


def normalize_mnemonic(mnemonic: str) -> str:
    m = mnemonic.strip().lower().replace("_", ".")
    return MNEMONIC_ALIASES.get(m, m)


def normalize_operand(op: str) -> str:
    s = op.strip()

    mem_m = MEM_RE.match(s)
    if mem_m:
        off = mem_m.group(1)
        base_reg = normalize_operand(mem_m.group(2))
        return f"{off}({base_reg})"

    reg_m = REG_RE.match(s)
    if reg_m:
        return f"${int(reg_m.group(1))}"

    mask_m = MASK_RE.match(s)
    if mask_m:
        return str(int(mask_m.group(1)))

    return s


def normalize_instruction(code: str) -> tuple[str, list[str]]:
    mnemonic, ops = base.split_mnemonic_operands(code)
    if not mnemonic:
        return "", []
    return normalize_mnemonic(mnemonic), [normalize_operand(op) for op in ops]


def _check_signed_25bit(value: int) -> None:
    lo = -(1 << 24)
    hi = (1 << 24) - 1
    if value < lo or value > hi:
        raise ValueError(f"jal offset {value} out of signed 25-bit range [{lo}, {hi}]")


def asm_to_instr_dict(
    mnemonic: str,
    ops: list[str],
    *,
    labels: dict[str, int] | None = None,
    pc: int | None = None,
) -> dict:
    # VV-type: compiler emits 4 operands (vd, vs1, vs2, mask) — pass through directly.
    if mnemonic in {"add.vv", "sub.vv", "mul.vv", "gemm.vv"} and len(ops) == 4:
        return base.asm_to_instr_dict(mnemonic, ops, labels=labels, pc=pc)

    # base assembler resolves labels for BR, but not for JAL immediates.
    if mnemonic == "jal" and len(ops) in (1, 2):
        if len(ops) == 1:
            rd = 0
            target = ops[0]
        else:
            rd = base.parse_reg(ops[0])
            target = ops[1]

        if labels is not None and target in labels:
            if pc is None:
                raise ValueError("Internal error: missing PC for label-based jal")
            imm = labels[target] - pc
        elif IMM_RE.match(target):
            imm = base.parse_int(target)
        else:
            raise ValueError(f"Unknown jal label: {target!r}")

        _check_signed_25bit(imm)
        opcode, instr_type = base.INVERT_OPCODES["jal"]
        return {
            "opcode": opcode,
            "type": instr_type,
            "rd": rd,
            "imm25": imm,
        }

    return base.asm_to_instr_dict(mnemonic, ops, labels=labels, pc=pc)


def parse_program(in_data: str) -> tuple[list[AsmInstr], dict[str, int]]:
    stop_markers = {"data mem", ".data"}
    instructions: list[AsmInstr] = []
    labels: dict[str, int] = {}
    pending_labels: list[str] = []

    for raw in in_data.splitlines():
        code, cmt = strip_comment(raw)
        code = code.strip()
        if not code:
            continue

        line_labels, code = base.parse_leading_labels(code)
        if line_labels:
            pending_labels.extend(line_labels)

        if not code:
            continue

        lowered = code.lower()
        if lowered in stop_markers:
            break

        if code.startswith(".") or is_ignored_directive(code):
            continue

        mnemonic, ops = normalize_instruction(code)
        if not mnemonic:
            continue

        idx = len(instructions)
        if pending_labels:
            for label in pending_labels:
                if label in labels:
                    raise ValueError(f"Duplicate label: {label}")
                labels[label] = idx

        comment = cmt if cmt else mnemonic
        instructions.append(AsmInstr(mnemonic=mnemonic, ops=ops, comment=comment, labels=list(pending_labels)))
        pending_labels.clear()

    return instructions, labels


def inject_main_bootstrap(
    instructions: list[AsmInstr], labels: dict[str, int]
) -> tuple[list[AsmInstr], dict[str, int]]:
    # Provide deterministic entry semantics for compiler-generated code:
    # call main and halt when main returns.
    if "main" not in labels:
        return instructions, labels

    bootstrap = [
        AsmInstr(mnemonic="jal", ops=["$1", "main"], comment="bootstrap.call_main"),
        AsmInstr(mnemonic="halt.s", ops=[], comment="bootstrap.halt"),
    ]

    shifted_labels = {name: idx + len(bootstrap) for name, idx in labels.items()}
    return bootstrap + instructions, shifted_labels


def is_control_mnemonic(mnemonic: str, instr_type: str) -> bool:
    return instr_type == "BR" or mnemonic in CONTROL_MNEMONICS


def _reg_scalar(reg: int | None) -> str | None:
    return f"s{reg}" if reg is not None else None


def _reg_vector(reg: int | None) -> str | None:
    return f"v{reg}" if reg is not None else None


def _reg_mask(reg: int | None) -> str | None:
    return f"m{reg}" if reg is not None else None


def _parse_reg(op: str) -> int:
    return base.parse_reg(op)


def _parse_imm(op: str) -> int:
    return base.parse_int(op)


def _parse_mem_operand(op: str) -> tuple[int, int]:
    m = NORM_MEM_RE.match(op.replace(" ", ""))
    if not m:
        raise ValueError(f"Expected normalized memory operand imm($reg), got {op!r}")
    imm = _parse_imm(m.group(1))
    rs1 = int(m.group(2))
    return rs1, imm


def _latency_for(mnemonic: str) -> int:
    m = mnemonic.lower()
    base_name = m.split(".", 1)[0]
    for key in (m, base_name):
        if key in latency:
            try:
                return max(1, int(latency[key]))
            except (TypeError, ValueError):
                pass
    return 1


def _add_reg(target: set[str], reg: str | None) -> None:
    if reg is not None:
        target.add(reg)


def _build_sched_info(inst: AsmInstr, idx: int) -> SchedInfo:
    mnemonic = inst.mnemonic
    if mnemonic not in base.INVERT_OPCODES:
        raise ValueError(f"Unknown mnemonic for scheduling: {mnemonic!r}")

    _, instr_type = base.INVERT_OPCODES[mnemonic]
    reads: set[str] = set()
    writes: set[str] = set()
    mem_key = None

    if instr_type == "R":
        if mnemonic in ("nop.s", "halt.s"):
            pass
        else:
            _add_reg(reads, _reg_scalar(_parse_reg(inst.ops[1])))
            _add_reg(reads, _reg_scalar(_parse_reg(inst.ops[2])))
            _add_reg(writes, _reg_scalar(_parse_reg(inst.ops[0])))

    elif instr_type == "I":
        _add_reg(reads, _reg_scalar(_parse_reg(inst.ops[1])))
        _add_reg(writes, _reg_scalar(_parse_reg(inst.ops[0])))

    elif instr_type == "BR":
        rs1 = _parse_reg(inst.ops[0])
        _add_reg(reads, _reg_scalar(rs1))
        _add_reg(reads, _reg_scalar(_parse_reg(inst.ops[1])))
        # Emulator updates rs1 by incr_imm for BR instructions.
        _add_reg(writes, _reg_scalar(rs1))

    elif instr_type == "M":
        rd = _parse_reg(inst.ops[0])
        if len(inst.ops) == 2:
            rs1, imm = _parse_mem_operand(inst.ops[1])
        else:
            rs1 = _parse_reg(inst.ops[1])
            imm = _parse_imm(inst.ops[2])
        _add_reg(reads, _reg_scalar(rs1))
        mem_key = ("scalar_mem", rs1, imm)
        if mnemonic in {"sw.s", "shw.s"}:
            _add_reg(reads, _reg_scalar(rd))
        else:
            _add_reg(writes, _reg_scalar(rd))

    elif instr_type == "MI":
        if mnemonic == "jal":
            if len(inst.ops) == 1:
                rd = 0
            else:
                rd = _parse_reg(inst.ops[0])
            if rd != 0:
                _add_reg(writes, _reg_scalar(rd))
        elif mnemonic in {"li.s", "lui.s"} and inst.ops:
            _add_reg(writes, _reg_scalar(_parse_reg(inst.ops[0])))

    elif instr_type == "VV":
        _add_reg(writes, _reg_vector(_parse_reg(inst.ops[0])))
        _add_reg(reads, _reg_vector(_parse_reg(inst.ops[1])))
        _add_reg(reads, _reg_vector(_parse_reg(inst.ops[2])))
        if len(inst.ops) >= 4:
            _add_reg(reads, _reg_mask(_parse_imm(inst.ops[3])))

    elif instr_type == "VS":
        _add_reg(writes, _reg_vector(_parse_reg(inst.ops[0])))
        _add_reg(reads, _reg_vector(_parse_reg(inst.ops[1])))
        _add_reg(reads, _reg_scalar(_parse_reg(inst.ops[2])))
        if len(inst.ops) >= 4:
            _add_reg(reads, _reg_mask(_parse_imm(inst.ops[3])))

    elif instr_type == "VI":
        _add_reg(reads, _reg_vector(_parse_reg(inst.ops[1])))
        if mnemonic != "lw.vi":
            _add_reg(writes, _reg_vector(_parse_reg(inst.ops[0])))
            if len(inst.ops) >= 4:
                _add_reg(reads, _reg_mask(_parse_imm(inst.ops[3])))

    elif instr_type == "VM":
        vd = _parse_reg(inst.ops[0])
        rs1 = _parse_reg(inst.ops[1])
        if len(inst.ops) >= 5 and NORM_REG_RE.match(inst.ops[2]):
            rs2 = _parse_reg(inst.ops[2])
            num_cols = _parse_imm(inst.ops[3])
            sid = _parse_imm(inst.ops[4])
            mem_key = ("vreg_mem", sid, rs1, rs2, num_cols)
            _add_reg(reads, _reg_scalar(rs2))
        else:
            num_cols = _parse_imm(inst.ops[2])
            num_rows = _parse_imm(inst.ops[3])
            sid = _parse_imm(inst.ops[4])
            rc = _parse_imm(inst.ops[5]) if len(inst.ops) > 5 else 0
            rc_id = _parse_imm(inst.ops[6]) if len(inst.ops) > 6 else 0
            mem_key = ("vreg_mem", sid, rs1, num_cols, num_rows, rc, rc_id)
        _add_reg(reads, _reg_scalar(rs1))
        if mnemonic == "vreg.st":
            _add_reg(reads, _reg_vector(vd))
        else:
            _add_reg(writes, _reg_vector(vd))

    elif instr_type == "SDMA":
        rs1_rd1 = _parse_reg(inst.ops[0])
        rs2 = _parse_reg(inst.ops[1])
        if len(inst.ops) == 3 and NORM_REG_RE.match(inst.ops[2]):
            rs3 = _parse_reg(inst.ops[2])
            _add_reg(reads, _reg_scalar(rs3))
            mem_key = ("scpad_mem", rs1_rd1, rs2, rs3)
        else:
            num_cols = _parse_imm(inst.ops[2])
            num_rows = _parse_imm(inst.ops[3])
            sid = _parse_imm(inst.ops[4])
            mem_key = ("scpad_mem", sid, rs1_rd1, rs2, num_cols, num_rows)
        _add_reg(reads, _reg_scalar(rs1_rd1))
        _add_reg(writes, _reg_scalar(rs1_rd1))
        _add_reg(reads, _reg_scalar(rs2))

    elif instr_type == "MTS":
        _add_reg(writes, _reg_scalar(_parse_reg(inst.ops[0])))
        _add_reg(reads, _reg_mask(_parse_imm(inst.ops[1])))

    elif instr_type == "STM":
        _add_reg(writes, _reg_mask(_parse_imm(inst.ops[0])))
        _add_reg(reads, _reg_scalar(_parse_reg(inst.ops[1])))

    elif instr_type == "VTS":
        _add_reg(writes, _reg_scalar(_parse_reg(inst.ops[0])))
        _add_reg(reads, _reg_vector(_parse_reg(inst.ops[1])))

    elif instr_type == "MVV":
        _add_reg(writes, _reg_mask(_parse_imm(inst.ops[0])))
        _add_reg(reads, _reg_vector(_parse_reg(inst.ops[1])))
        _add_reg(reads, _reg_vector(_parse_reg(inst.ops[2])))
        _add_reg(reads, _reg_mask(_parse_imm(inst.ops[3])))

    elif instr_type == "MVS":
        _add_reg(writes, _reg_mask(_parse_imm(inst.ops[0])))
        _add_reg(reads, _reg_vector(_parse_reg(inst.ops[1])))
        _add_reg(reads, _reg_scalar(_parse_reg(inst.ops[2])))
        _add_reg(reads, _reg_mask(_parse_imm(inst.ops[3])))

    is_vector = instr_type in VECTOR_TYPES
    is_memory = mnemonic in MEMORY_MNEMONICS
    is_store = mnemonic in MEMORY_STORE_MNEMONICS
    is_control = is_control_mnemonic(mnemonic, instr_type)

    return SchedInfo(
        idx=idx,
        mnemonic=mnemonic,
        instr_type=instr_type,
        reads=reads,
        writes=writes,
        latency=_latency_for(mnemonic),
        is_vector=is_vector,
        is_memory=is_memory,
        is_store=is_store,
        is_control=is_control,
        mem_key=mem_key,
    )


def _validate_packets(
    packets: list[list[int]],
    infos: list[SchedInfo],
    labels: dict[str, int],
) -> None:
    errors: list[str] = []
    expected = list(range(len(infos)))
    flat = [idx for packet in packets for idx in packet]

    if flat != expected:
        errors.append("Scheduled instruction order does not match original in-order sequence.")

    labeled_indices = set(labels.values())
    seen = set()

    for pkt_idx, packet in enumerate(packets):
        if len(packet) > base.REAL_PACKET_SIZE:
            errors.append(f"packet {pkt_idx} has width {len(packet)} > {base.REAL_PACKET_SIZE}")

        vector_count = 0
        memory_count = 0
        packet_reads: set[str] = set()
        packet_writes: set[str] = set()

        for slot, idx in enumerate(packet):
            if idx in seen:
                errors.append(f"instruction index {idx} appears in more than one packet")
                continue
            seen.add(idx)

            info = infos[idx]
            if idx in labeled_indices and slot != 0:
                errors.append(f"label target instruction {idx} is not at packet start")

            if info.is_control and (slot != 0 or len(packet) != 1):
                errors.append(f"control instruction {idx} is not isolated in its packet")

            if info.is_vector:
                vector_count += 1
            if info.is_memory:
                memory_count += 1

            for reg in info.reads:
                if reg in packet_writes:
                    errors.append(f"packet {pkt_idx} RAW hazard on {reg} at instruction {idx}")
            for reg in info.writes:
                if reg in packet_reads:
                    errors.append(f"packet {pkt_idx} WAR hazard on {reg} at instruction {idx}")
                if reg in packet_writes:
                    errors.append(f"packet {pkt_idx} WAW hazard on {reg} at instruction {idx}")

            packet_reads.update(info.reads)
            packet_writes.update(info.writes)

        if vector_count > 1:
            errors.append(f"packet {pkt_idx} has {vector_count} vector instructions")
        if memory_count > 1:
            errors.append(f"packet {pkt_idx} has {memory_count} memory instructions")

    if len(seen) != len(infos):
        missing = sorted(set(range(len(infos))) - seen)
        errors.append(f"missing scheduled instructions: {missing}")

    if errors:
        joined = "\n".join(f"- {e}" for e in errors[:40])
        extra = "" if len(errors) <= 40 else f"\n... {len(errors) - 40} more"
        raise ValueError(f"Packet validation failed:\n{joined}{extra}")


def _iter_block_starts(
    infos: Iterable[SchedInfo],
    labels: dict[str, int],
    n_instructions: int,
) -> set[int]:
    starts = {0}
    starts.update(labels.values())
    for info in infos:
        if info.is_control and (info.idx + 1) < n_instructions:
            starts.add(info.idx + 1)
    return starts


def _can_admit(
    info: SchedInfo,
    current_packet: list[int],
    packet_reads: set[str],
    packet_writes: set[str],
    packet_vector_count: int,
    packet_memory_count: int,
    labeled_indices: set[int],
) -> bool:
    if len(current_packet) >= base.REAL_PACKET_SIZE:
        return False
    if info.idx in labeled_indices and current_packet:
        return False
    if info.is_control:
        return len(current_packet) == 0
    if info.is_vector and packet_vector_count >= 1:
        return False
    if info.is_memory and packet_memory_count >= 1:
        return False

    for reg in info.reads:
        if reg in packet_writes:
            return False
    for reg in info.writes:
        if reg in packet_reads or reg in packet_writes:
            return False
    return True


def schedule_program(instructions: list[AsmInstr], labels: dict[str, int]) -> tuple[list[int], list[list[int]]]:
    infos = [_build_sched_info(inst, idx) for idx, inst in enumerate(instructions)]
    block_starts = _iter_block_starts(infos, labels, len(instructions))
    labeled_indices = set(labels.values())

    reg_ready: dict[str, int] = {}
    reg_read_ready: dict[str, int] = {}  # tracks when reads complete (WAR)
    store_ready: dict[tuple, int] = {}
    last_mem_cycle = -1

    issue_cycle = [0 for _ in range(len(instructions))]
    packets: list[list[int]] = []
    current_cycle = 0
    current_packet: list[int] = []
    packet_reads: set[str] = set()
    packet_writes: set[str] = set()
    packet_vector_count = 0
    packet_memory_count = 0

    def flush_packet() -> None:
        nonlocal current_cycle, current_packet, packet_reads, packet_writes, packet_vector_count, packet_memory_count
        if not current_packet:
            return
        packets.append(current_packet)
        current_packet = []
        packet_reads = set()
        packet_writes = set()
        packet_vector_count = 0
        packet_memory_count = 0
        current_cycle += 1

    def insert_empty_cycle() -> None:
        nonlocal current_cycle
        packets.append([])
        current_cycle += 1

    for info in infos:
        if info.idx in block_starts and current_packet:
            flush_packet()

        earliest = 0
        for reg in info.reads:
            earliest = max(earliest, reg_ready.get(reg, 0))
        for reg in info.writes:
            # WAW: wait for prior writes to complete
            earliest = max(earliest, reg_ready.get(reg, 0))
            # WAR: wait for prior reads to complete before overwriting
            earliest = max(earliest, reg_read_ready.get(reg, 0))
        if info.is_memory:
            earliest = max(earliest, last_mem_cycle + 1)
            if info.mem_key is not None:
                earliest = max(earliest, store_ready.get(info.mem_key, 0))

        while current_cycle < earliest:
            if current_packet:
                flush_packet()
            else:
                insert_empty_cycle()

        while not _can_admit(
            info,
            current_packet,
            packet_reads,
            packet_writes,
            packet_vector_count,
            packet_memory_count,
            labeled_indices,
        ):
            flush_packet()
            while current_cycle < earliest:
                insert_empty_cycle()

        current_packet.append(info.idx)
        packet_reads.update(info.reads)
        packet_writes.update(info.writes)
        if info.is_vector:
            packet_vector_count += 1
        if info.is_memory:
            packet_memory_count += 1
        issue_cycle[info.idx] = current_cycle

        ready = current_cycle + info.latency
        for reg in info.reads:
            reg_read_ready[reg] = max(reg_read_ready.get(reg, 0), current_cycle + 1)
        for reg in info.writes:
            reg_ready[reg] = max(reg_ready.get(reg, 0), ready)
        if info.is_memory:
            last_mem_cycle = current_cycle
            if info.is_store and info.mem_key is not None:
                store_ready[info.mem_key] = max(store_ready.get(info.mem_key, 0), ready)

        if info.is_control or len(current_packet) >= base.REAL_PACKET_SIZE:
            flush_packet()

    if current_packet:
        flush_packet()

    _validate_packets(packets, infos, labels)
    return issue_cycle, packets


def build_pc_maps(
    packets: list[list[int]], labels: dict[str, int]
) -> tuple[dict[int, int], dict[str, int]]:
    idx_to_pc: dict[int, int] = {}
    for pkt_idx, packet in enumerate(packets):
        pc = pkt_idx * base.INSTR_ADDR_STRIDE
        for idx in packet:
            idx_to_pc[idx] = pc

    label_to_pc: dict[str, int] = {}
    for label, idx in labels.items():
        if idx not in idx_to_pc:
            raise ValueError(f"Label {label!r} points to unscheduled instruction index {idx}")
        label_to_pc[label] = idx_to_pc[idx]

    return idx_to_pc, label_to_pc


def relocate_and_encode(
    instructions: list[AsmInstr], packets: list[list[int]], labels: dict[str, int]
) -> dict[int, str]:
    idx_to_pc, label_to_pc = build_pc_maps(packets, labels)
    encoded: dict[int, str] = {}

    for packet in packets:
        for idx in packet:
            inst = instructions[idx]
            pc = idx_to_pc[idx]
            instr_dict = asm_to_instr_dict(inst.mnemonic, inst.ops, labels=label_to_pc, pc=pc)
            hex40 = base.encode_instruction(instr_dict).upper()
            if len(hex40) != 10:
                raise ValueError(f"encode_instruction returned {hex40!r} (expected 10 hex chars)")
            encoded[idx] = hex40

    return encoded


def emit_packet_format(
    packets: list[list[int]],
    instructions: list[AsmInstr],
    encoded: dict[int, str],
) -> str:
    nop_hex = base.encode_instruction({"opcode": base.INVERT_OPCODES["nop.s"][0]}).upper()
    lines: list[str] = []

    for pkt_idx, packet in enumerate(packets):
        addr = pkt_idx * base.INSTR_ADDR_STRIDE
        words = [encoded[idx] for idx in packet]
        while len(words) < base.REAL_PACKET_SIZE:
            words.append(nop_hex)

        comment = ""
        for idx in packet:
            c = instructions[idx].comment
            if c:
                comment = c
                break

        suffix = f" # {comment}" if comment else ""
        lines.append(f"{addr:08X}: " + " ".join(words) + suffix)

    return "\n".join(lines)


def expand_large_li(
    instructions: list[AsmInstr], labels: dict[str, int]
) -> tuple[list[AsmInstr], dict[str, int]]:
    """Expand li.s with immediates that don't fit in 25-bit signed to lui.s + addi.s."""
    lo, hi = -(1 << 24), (1 << 24) - 1
    new_instrs: list[AsmInstr] = []
    new_labels: dict[str, int] = {}
    old_to_new: dict[int, int] = {}

    for old_idx, inst in enumerate(instructions):
        new_idx = len(new_instrs)
        old_to_new[old_idx] = new_idx

        if inst.mnemonic == "li.s" and len(inst.ops) == 2:
            imm = _parse_imm(inst.ops[1])
            if imm < lo or imm > hi:
                upper = (imm >> 7) & 0x1FFFFFF
                lower = imm & 0x7F
                if lower >= 64:
                    lower -= 128
                    upper += 1
                rd = inst.ops[0]
                new_instrs.append(AsmInstr(
                    mnemonic="lui.s", ops=[rd, str(upper)],
                    comment=inst.comment, labels=inst.labels[:]))
                new_instrs.append(AsmInstr(
                    mnemonic="addi.s", ops=[rd, rd, str(lower)],
                    comment="", labels=[]))
                continue

        new_instrs.append(inst)

    for label, old_idx in labels.items():
        new_labels[label] = old_to_new[old_idx]

    return new_instrs, new_labels


def compile_asm(in_data: str) -> tuple[str, list[int], list[list[int]]]:
    """Schedule and encode compiler-oriented assembly into a packetized ``.in`` text image.

    Pre-parse expansions (ISA is **encoded** 5-operand VM / 3-operand SDMA; other mnemonics
    use the current ISA from ``opcode_table``):

    - **VM:** legacy **7-operand** `vreg.{ld,st}` text → **5-operand** form
      (`expand_vreg_seven_operand_asm` in ``build.py``). New asm should emit 5 operands.
    - **SDMA:** **5-operand** `scpad.{ld,st}` shorthand → metadata in ``rs3`` + 3-operand form.

    Then: parse → optional main bootstrap → ``expand_large_li`` → ``schedule_program``
    (latency + structural hazards: ≤1 vector mem op per packet, etc.) → encode.
    """
    in_data = base.expand_vreg_seven_operand_asm(in_data)
    in_data = base.expand_scpad_five_operand_asm(in_data)
    instructions, labels = parse_program(in_data)
    instructions, labels = inject_main_bootstrap(instructions, labels)
    instructions, labels = expand_large_li(instructions, labels)
    ready, packets = schedule_program(instructions, labels)
    encoded = relocate_and_encode(instructions, packets, labels)
    instr_text = emit_packet_format(packets, instructions, encoded)
    final = base.render_testfile(instr_text, "")
    return final, ready, packets


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--input", type=Path, default=None, help="Input assembly file")
    ap.add_argument("-o", "--output", type=Path, default=None, help="Output test file")
    args = ap.parse_args()

    if args.input is None:
        raise ValueError("build_compiler.py requires --input")

    asm = args.input.read_text()
    final, ready, packets = compile_asm(asm)

    print("ready:", ready)
    print("packets:", packets)

    if args.output is not None:
        os.makedirs(args.output.parent, exist_ok=True)
        args.output.write_text(final)
    else:
        print(final)


if __name__ == "__main__":
    main()
