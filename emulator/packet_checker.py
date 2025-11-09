import itertools

# -----------------------------
# Example instruction metadata
# -----------------------------
instr_set = {
    "SCALAR_ALU_R": {"fu": "ALU.S", "sr_ports": 2, "vr_ports": 0, "mr_ports": 0, "excl": [""]},
    "SCALAR_MULT_R": {"fu": "MULT.S", "sr_ports": 2, "vr_ports": 0, "mr_ports": 0, "excl": [""]},
    "SCALAR_DIV/MOD_R": {"fu": "DIV.S", "sr_ports": 2, "vr_ports": 0, "mr_ports": 0, "excl": [""]},
    "SCALAR_ALU_I": {"fu": "ALU.S", "sr_ports": 1, "vr_ports": 0, "mr_ports": 0, "excl": [""]},
    "SCALAR_MULT_I": {"fu": "MULT.S", "sr_ports": 1, "vr_ports": 0, "mr_ports": 0, "excl": [""]},
    "SCALAR_DIV/MOD_I": {"fu": "DIV.S", "sr_ports": 1, "vr_ports": 0, "mr_ports": 0, "excl": [""]},
    "BRANCH": {"fu": "CONTROL", "sr_ports": 2, "vr_ports": 0, "mr_ports": 0, "excl": [""]},
    "MEM.S": {"fu": "MEM.S", "sr_ports": 1, "vr_ports": 0, "mr_ports": 0, "excl": [""]},
    "JAL": {"fu": "CONTROL", "sr_ports": 0, "vr_ports": 0, "mr_ports": 0, "excl": [""]},
    "JALR": {"fu": "CONTROL", "sr_ports": 1, "vr_ports": 0, "mr_ports": 0, "excl": [""]},
    "LUI": {"fu": "ALU.S", "sr_ports": 0, "vr_ports": 0, "mr_ports": 0, "excl": [""]},

    "VECTOR_ALU_VV": {"fu": "ALU.V", "sr_ports": 0, "vr_ports": 2, "mr_ports": 1, "excl": [""]},
    "VECTOR_MULT_VV": {"fu": "MULT.V", "sr_ports": 0, "vr_ports": 2, "mr_ports": 1, "excl": [""]},
    "VECTOR_DIV_VV": {"fu": "DIV.V", "sr_ports": 0, "vr_ports": 2, "mr_ports": 1, "excl": [""]},
    "VECTOR_ALU_VI": {"fu": "ALU.V", "sr_ports": 0, "vr_ports": 1, "mr_ports": 1, "excl": [""]},
    "VECTOR_MULT_VI": {"fu": "MULT.V", "sr_ports": 0, "vr_ports": 1, "mr_ports": 1, "excl": [""]},
    "VECTOR_DIV_VI": {"fu": "DIV.V", "sr_ports": 0, "vr_ports": 1, "mr_ports": 1, "excl": [""]},
    "VECTOR_EXP_VI": {"fu": "EXP.V", "sr_ports": 0, "vr_ports": 1, "mr_ports": 1, "excl": [""]},
    "VECTOR_SQRT_VI": {"fu": "SQRT.V", "sr_ports": 0, "vr_ports": 1, "mr_ports": 1, "excl": [""]},
    "VECTOR_ALU_VS": {"fu": "ALU.V", "sr_ports": 1, "vr_ports": 1, "mr_ports": 1, "excl": [""]},
    "VECTOR_MULT_VS": {"fu": "MULT.V", "sr_ports": 1, "vr_ports": 1, "mr_ports": 1, "excl": [""]},
    "VECTOR_DIV_VS": {"fu": "DIV.V", "sr_ports": 1, "vr_ports": 1, "mr_ports": 1, "excl": [""]},
    "VECTOR_ALU_VI_REDUCTION": {"fu": "ALU.V", "sr_ports": 0, "vr_ports": 1, "mr_ports": 0, "excl": [""]},
    "GEMM": {"fu": "GEMM", "sr_ports": 0, "vr_ports": 2, "mr_ports": 0, "excl": [""]},
    "LOAD_W_GEMM": {"fu": "GEMM", "sr_ports": 0, "vr_ports": 1, "mr_ports": 0, "excl": [""]},
    "SHIFT_VS": {"fu": "SHIFT", "sr_ports": 1, "vr_ports": 1, "mr_ports": 0, "excl": [""]},
    "SHIFT_VI": {"fu": "SHIFT", "sr_ports": 0, "vr_ports": 1, "mr_ports": 0, "excl": [""]},
    "VREG_LD": {"fu": "VEC_MEM", "sr_ports": 2, "vr_ports": 0, "mr_ports": 1, "excl": [""]},
    "VREG_ST": {"fu": "VEC_MEM", "sr_ports": 2, "vr_ports": 1, "mr_ports": 1, "excl": [""]},

    "WBMTOS": {"fu": "WBMTOS", "sr_ports": 0, "vr_ports": 0, "mr_ports": 1, "excl": [""]},
    "WBSTOM": {"fu": "WBSTOM", "sr_ports": 1, "vr_ports": 0, "mr_ports": 0, "excl": [""]},
    "VMOV": {"fu": "WBVTOS", "sr_ports": 0, "vr_ports": 1, "mr_ports": 0, "excl": [""]},

    #"NOP": {"fu": "NONE", "sr_ports": 0, "vr_ports": 0, "mr_ports": 0, "excl": [""]},
    "halt.s": {"fu": "NONE", "sr_ports": 4, "vr_ports": 4, "mr_ports": 2, "excl": ["jal", "li.s", "lui.s"]},
    "fence.s": {"fu": "NONE", "sr_ports": 4, "vr_ports": 4, "mr_ports": 2, "excl": ["jal", "li.s", "lui.s"]}


}

# functional unit limits (max instructions of each FU per packet)
fu_limits = {
    "ALU.S": 1,
    "MEM.S": 1,
    "CONTROL": 1,
    "MULT.S": 1,
    "DIV.S": 1,
    "ALU.V": 1,
    "MULT.V": 1,
    "DIV.V": 1,
    "EXP.V": 1,
    "SQRT.V": 1,
    "GEMM": 1,
    "VEC_MEM": 2,
    "SHIFT": 1,
    "WBMTOS": 1,
    "WBSTOM": 1,
    "WBVTOS": 1,
    "NONE": 4  # NOPs are always allowed
}

# register file port limits
sr_limit = 4
vr_limit = 4
mr_limit = 2  # mask register file port limit

# Fixed packet width
packet_width = 4

# -----------------------------
# Validation helper
# -----------------------------
def is_valid_packet(packet, instrs, fu_limits, sr_limit, vr_limit, mr_limit):
    fu_usage = {fu: 0 for fu in fu_limits}
    sr_used = 0
    vr_used = 0
    mr_used = 0

    for instr in packet:
        meta = instrs[instr]
        fu_usage[meta["fu"]] += 1
        sr_used += meta["sr_ports"]
        vr_used += meta["vr_ports"]
        mr_used += meta["mr_ports"]

    # Functional unit limits
    for fu, used in fu_usage.items():
        if used > fu_limits.get(fu, 0):
            return False

    # Register file port limits
    if sr_used > sr_limit or vr_used > vr_limit or mr_used > mr_limit:
        return False

    # Exclusion rules
    for i, instr_a in enumerate(packet):
        for instr_b in packet[i + 1:]:
            if instr_b in instrs[instr_a]["excl"]:
                return False

    return True

# -----------------------------
# Enumerate valid packets
# -----------------------------
def enumerate_vliw_packets(instrs, packet_width, fu_limits, sr_limit, vr_limit, mr_limit):
    instr_names = list(instrs.keys())
    valid_packets = set()

    for combo in itertools.combinations_with_replacement(instr_names, packet_width):
        if is_valid_packet(combo, instrs, fu_limits, sr_limit, vr_limit, mr_limit):
            key = tuple(sorted(combo))  # unordered equivalence
            valid_packets.add(key)

    return sorted(valid_packets)

# -----------------------------
# Main
# -----------------------------
packets = enumerate_vliw_packets(instr_set, packet_width, fu_limits, sr_limit, vr_limit, mr_limit)

with open("vliw_packets.txt", "w") as f:
    for i, pkt in enumerate(packets, 1):
        f.write(f"{i:4d}: {pkt}\n")

print(f"Wrote {len(packets)} valid 4-wide packets to vliw_packets.txt")