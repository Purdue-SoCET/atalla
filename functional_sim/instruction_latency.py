try:
    from .src.misc.opcode_table import OPCODES
except ImportError:
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
    "barrier": 1,

    # Memory
    "lw": 3,
    "lhw": 3,
    "sw": 1,
    "shw": 1,

    # Vector ALU
    "add": 1,
    "sub": 1,
    "and": 1,
    "or": 1,
    "xor": 1,
    "mgt": 1,
    "mlt": 1,
    "meq": 1,
    "mneq": 1,
    "shift": 1,
    "not": 1,
    "mv": 1,
    "vmov": 1,

    # Vector long latency
    "mul": 3,
    "muli": 3,
    "expi": 8,
    "sqrti": 8,
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
    "vreg.ld": 3,
    "vreg.st": 1,
    "scpad.ld": 3,
    "scpad.st": 1,
    "lw.vi": 3,
}

latency = dict(BASE_LATENCY)
for mnemonic, _ in OPCODES.values():
    op = mnemonic.lower()
    base = op.split(".", 1)[0]
    latency[op] = MNEMONIC_LATENCY.get(op, BASE_LATENCY.get(base, 1))
