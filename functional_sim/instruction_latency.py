from src.misc.opcode_table import OPCODES

# Base latency defaults used by the graph dependency scheduler.
# Keys are base op names (before ".suffix"), plus a few explicit full mnemonic
# overrides added below.
BASE_LATENCY = {
    # Scalar ALU
    "add": 1,
    "sub": 1,
    "or": 1,
    "and": 1,
    "xor": 1,
    "sll": 1,
    "srl": 1,
    "sra": 1,
    "slt": 1,
    "sltu": 1,
    "addi": 1,
    "subi": 1,
    "ori": 1,
    "andi": 1,
    "xori": 1,
    "slli": 1,
    "srli": 1,
    "srai": 1,
    "slti": 1,
    "sltui": 1,
    "li": 1,
    "lui": 1,
    "stbf": 1,
    "bfts": 1,
    "rcp": 8,

    # Scalar long latency
    "mul": 3,
    "muli": 3,
    "div": 8,
    "divi": 8,
    "mod": 8,
    "modi": 8,
    "sqrt": 8,

    # Control
    "beq": 1,
    "bne": 1,
    "blt": 1,
    "bge": 1,
    "bgt": 1,
    "ble": 1,
    "jal": 1,
    "jalr": 1,
    "nop": 1,
    "halt": 1,

    # Memory
    "lw": 3,
    "lhw": 3,
    "sw": 1,
    "shw": 1,

    # Vector ALU
    "add": 1,
    "sub": 1,
    "mgt": 1,
    "mlt": 1,
    "meq": 1,
    "mneq": 1,
    "mv": 1,
    "vmov": 1,

    # Vector long latency
    "mul": 3,
    "div": 8,
    "expi": 8,
    "rsum": 4,
    "rmin": 4,
    "rmax": 4,
    "gemm": 16,

    # Vector/scpad data movement
    "vreg": 3,
    "scpad": 3,
}

# Full mnemonic overrides when load/store directions differ on same base op.
MNEMONIC_LATENCY = {
    # Scheduler-core latencies from ISA -- Atalla - scheduler core lats + groupings
    "add.s": 1,
    "sub.s": 1,
    "or.s": 1,
    "and.s": 1,
    "xor.s": 1,
    "sll.s": 1,
    "srl.s": 1,
    "sra.s": 1,
    "bfts.s": 1,
    "add.bf": 1,
    "sub.bf": 1,
    "mul.s": 2,
    "muli.s": 2,
    "div.s": 66,
    "divi.s": 66,
    "mod.s": 66,
    "modi.s": 66,
    "mul.bf": 1,
    "rcp.bf": 11,
    "sqrt.bf": 11,
    "stbf.s": 1,
    "addi.s": 1,
    "subi.s": 1,
    "ori.s": 1,
    "andi.s": 1,
    "xori.s": 1,
    "slli.s": 1,
    "srli.s": 1,
    "srai.s": 1,
    "jalr.s": 1,
    "beq.s": 1,
    "bne.s": 1,
    "blt.s": 1,
    "bge.s": 1,
    "bgt.s": 1,
    "ble.s": 1,
    "jal": 1,
    "lui.s": 1,
    # 4-cycle cache-hit behavior for scalar memory ops.
    "lw.s": 4,
    "sw.s": 4,
    "lhw.s": 4,
    "shw.s": 4,
    # Vector-core latencies
    "add.vv": 5,
    "sub.vv": 5,
    "add.vs": 5,
    "sub.vs": 5,
    "mgt.mvv": 5,
    "mlt.mvv": 5,
    "meq.mvv": 5,
    "mneq.mvv": 5,
    "mgt.mvs": 5,
    "mlt.mvs": 5,
    "meq.mvs": 5,
    "mneq.mvs": 5,
    "mul.vv": 4,
    "mul.vs": 4,
    "expi.vi": 6,
    "rsum.vi": 20,
    "rmin.vi": 20,
    "rmax.vi": 20,
    "gemm.vv": 40, # MEISSA 2
    "mv.mts": 1, 
    "mv.stm": 1, 
    "vmov.vts": 1, 

    "vreg.ld": 15,
    "vreg.st": 2,
    "scpad.ld": 520, # 512 for DDR, 8 for AXI
    "scpad.st": 520, # 512 for DDR, 8 for AXI
    "lw.vi": 0, #  no dependency latency.
}

latency = dict(BASE_LATENCY)
for mnemonic, _ in OPCODES.values():
    op = mnemonic.lower()
    base = op.split(".", 1)[0]
    latency[op] = MNEMONIC_LATENCY.get(op, BASE_LATENCY.get(base, 1))
