def is_packet_independent_check(decoded_packet):
    """
    Ensures instructions inside a VLIW packet do NOT share any registers
    across scalar, vector, or mask register files.

    ANY overlap (read-read is OK, but any read/write/write-read/write-write
    involving the same register) makes the packet illegal.
    """

    # Track which registers appear at all in *any* operand position
    scalar_used = set()
    vector_used = set()
    mask_used = set()

    def add_scalar(reg):
        if reg in scalar_used:
            return False
        scalar_used.add(reg)
        return True

    def add_vector(reg):
        if reg in vector_used:
            return False
        vector_used.add(reg)
        return True

    def add_mask(reg):
        if reg in mask_used:
            return False
        mask_used.add(reg)
        return True

    # ----------------------------
    # Extract all operands per instruction
    # ----------------------------
    for instr in decoded_packet:

        # ---- scalar regs ----
        for key in ("rs1", "rs2", "rd"):
            if key in instr:
                if not add_scalar(instr[key]):
                    return False

        # ---- vector regs ----
        for key in ("vs1", "vs2", "vd", "vmd", "vms"):
            if key in instr:
                if not add_vector(instr[key]):
                    return False

        # ---- mask regs ----
        if "mask" in instr:
            if not add_mask(instr["mask"]):
                return False

        if "mask_dest" in instr:   # if your ISA later writes masks
            if not add_mask(instr["mask_dest"]):
                return False

    return True
    