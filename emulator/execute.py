"""
execute_unit_emu.py
Top-level Execute Unit for the hardware emulator.

Combines:
  - SystolicArray (BF16 matmul)
  - VectorLanes (BF16 vector ops with mask)
  - ScalarALU (INT32 scalar ops)
  - MoveConvertUnit (conversions & move operations)

Opcode format: INT8 (0-255)
  [7:6] = functional unit selector
      00 -> Scalar ALU
      01 -> Vector Lanes
      10 -> Matmul (Systolic)
      11 -> Move/Convert Unit

  [5:0] = specific sub-operation within the FU
"""

import numpy as np

from gemm import SystolicArray, to_bf16
from vector_lanes import VectorLanes
from scalar import ScalarALU
from move import MoveConvertUnit

# ============================================================
# Mnemonic tables
# ============================================================

MNEMONIC_SCALAR = {
    "add.s": "add",
    "sub.s": "sub",
    "mul.s": "mul",
    "div.s": "div",
    "mod.s": "mod",
    "or.s":  "or",
    "and.s": "and",
    "xor.s": "xor",
    "not.s": "not",
    "shl.s": "shl",
    "srl.s": "srl",
    "sra.s": "sra",
    "slt.s":  "slt",
    "sltu.s": "sltu",
}

MNEMONIC_VECTOR = {
    "add.vv": "add",
    "sub.vv": "sub",
    "mul.vv": "mul",
    "div.vv": "div",

    "add.vs": "add_scalar",
    "sub.vs": "sub_scalar",
    "rsub.vs": "scalar_sub",
    "mul.vs": "mul_scalar",
    "div.vs": "div_scalar",
    "rdiv.vs": "scalar_div",

    "and.vv": "bw_and",
    "or.vv":  "bw_or",
    "xor.vv": "bw_xor",
    "not.v":  "bw_not",

    "shl.vs": "shl_scalar",
    "shr.vs": "shr_scalar",

    "gt.vv":  "cmp_gt",
    "lt.vv":  "cmp_lt",
    "eq.vv":  "cmp_eq",
    "neq.vv": "cmp_neq",

    "sum.v":  "reduce_sum",
    "exp.v":  "exp",
    "sqrt.v": "sqrt",
}

MNEMONIC_MATMUL = {
    "mm.vv": "matmul"
}

MNEMONIC_MOVECON = {
    "stbf.s": "int32_to_bf16",
    "bfts.s": "bf16_to_int32",
    "mov.vs": "vector_extract",        # vA + index → scalar
    "mov.ss": "scalar_broadcast",     # sA → VL-length vector
}

# ============================================================
# Execute Unit
# ============================================================
class ExecuteUnit:
    def __init__(self,
                 vector_length: int = 32,
                 matmul_tile: int = 32,
                 num_scalar_lanes: int = 1):
        self.vl = int(vector_length)
        self.matmul_tile = int(matmul_tile)

        # instantiate sub-units
        self.vec = VectorLanes(VL=self.vl)
        self.scalar = ScalarALU(num_lanes=num_scalar_lanes)
        self.matmul = SystolicArray(size=self.matmul_tile)
        self.mov = MoveConvertUnit(default_VL=self.vl)

    # ----------------------------------------------------------
    # Decode helper
    # ----------------------------------------------------------
    @staticmethod
    def _decode_opcode(opcode: int):
        opcode_u = int(np.int8(opcode) & 0xFF)
        fu = (opcode_u >> 6) & 0b11
        subop = opcode_u & 0x3F
        return fu, subop

# ============================================================
# NEW EXECUTE FUNCTION
# ============================================================

    def execute(self,
                instr: str,
                A=None, B=None,
                vA=None, vB=None, mask=None,
                sA=None, sB=None,
                index: int = None,
                out_vl: int = None):

        instr = instr.strip().lower()

        # =======================================================
        # SCALAR
        # =======================================================
        if instr in MNEMONIC_SCALAR:
            op = MNEMONIC_SCALAR[instr]

            if op == "add":  return self.scalar.add(sA, sB)
            if op == "sub":  return self.scalar.sub(sA, sB)
            if op == "mul":  return self.scalar.mul(sA, sB)
            if op == "div":  return self.scalar.div(sA, sB)
            if op == "mod":  return self.scalar.mod(sA, sB)

            if op == "or":   return self.scalar.bit_or(sA, sB)
            if op == "and":  return self.scalar.bit_and(sA, sB)
            if op == "xor":  return self.scalar.bit_xor(sA, sB)
            if op == "not":  return self.scalar.bit_not(sA)

            if op == "shl":  return self.scalar.shl(sA, sB)
            if op == "srl":  return self.scalar.srl(sA, sB)
            if op == "sra":  return self.scalar.sra(sA, sB)

            if op == "slt":  return self.scalar.slt(sA, sB)
            if op == "sltu": return self.scalar.sltu(sA, sB)

            raise ValueError(f"Unhandled scalar op '{instr}'")

        # =======================================================
        # VECTOR
        # =======================================================
        if instr in MNEMONIC_VECTOR:
            op = MNEMONIC_VECTOR[instr]

            if op == "add":           return self.vec.add(vA, vB)
            if op == "sub":           return self.vec.sub(vA, vB)
            if op == "mul":           return self.vec.mul(vA, vB)
            if op == "div":           return self.vec.div(vA, vB)

            if op == "add_scalar":    return self.vec.add_scalar(vA, sA)
            if op == "sub_scalar":    return self.vec.sub_scalar(vA, sA)
            if op == "scalar_sub":    return self.vec.scalar_sub(sA, vA)
            if op == "mul_scalar":    return self.vec.mul_scalar(vA, sA)
            if op == "div_scalar":    return self.vec.div_scalar(vA, sA)
            if op == "scalar_div":    return self.vec.scalar_div(sA, vA)

            if op == "bw_and":        return self.vec.bitwise_and(vA, vB)
            if op == "bw_or":         return self.vec.bitwise_or(vA, vB)
            if op == "bw_xor":        return self.vec.bitwise_xor(vA, vB)
            if op == "bw_not":        return self.vec.bitwise_not(vA)

            if op == "shl_scalar":    return self.vec.shl_scalar(vA, int(sA))
            if op == "shr_scalar":    return self.vec.shr_scalar(vA, int(sA))

            if op == "cmp_gt":        return self.vec.cmp_gt(vA, vB)
            if op == "cmp_lt":        return self.vec.cmp_lt(vA, vB)
            if op == "cmp_eq":        return self.vec.cmp_eq(vA, vB)
            if op == "cmp_neq":       return self.vec.cmp_neq(vA, vB)

            if op == "reduce_sum":    return self.vec.reduce_sum(vA)
            if op == "exp":           return self.vec.exp(vA)
            if op == "sqrt":          return self.vec.sqrt(vA)

            raise ValueError(f"Unhandled vector op '{instr}'")

        # =======================================================
        # MATMUL
        # =======================================================
        if instr in MNEMONIC_MATMUL:
            return self.matmul.matmul(A, B)

        # =======================================================
        # MOVE / CONVERSION
        # =======================================================
        if instr in MNEMONIC_MOVECON:
            op = MNEMONIC_MOVECON[instr]

            if op == "int32_to_bf16":
                return self.mov.int32_to_bf16(sA)

            if op == "bf16_to_int32":
                return self.mov.bf16_to_int32(vA)

            if op == "vector_extract":
                if index is None:
                    raise ValueError("mov.vs requires index= argument")
                return self.mov.vector_extract(vA, index)

            if op == "scalar_broadcast":
                target_vl = out_vl if out_vl is not None else self.vl
                return self.mov.scalar_broadcast_to_vector(sA, VL=target_vl)

            raise ValueError(f"Unhandled move/convert op '{instr}'")

        raise ValueError(f"Unknown instruction mnemonic '{instr}'")        

# ============================================================
# Smoke Test (expanded to include move/convert tests)
# ============================================================
if __name__ == "__main__":
    EU = ExecuteUnit()

    print("====================================================")
    print(" SCALAR ALU — SMOKE TESTS (INT32)")
    print("====================================================")   
    print("add.s   =", EU.execute("add.s", sA=10, sB=4))
    print("sub.s   =", EU.execute("sub.s", sA=10, sB=4))
    print("mul.s   =", EU.execute("mul.s", sA=10, sB=4))
    print("div.s   =", EU.execute("div.s", sA=20, sB=5))
    print("mod.s   =", EU.execute("mod.s", sA=22, sB=5))

    print("or.s    =", EU.execute("or.s",  sA=0b1010, sB=0b1100))
    print("and.s   =", EU.execute("and.s", sA=0b1010, sB=0b1100))
    print("xor.s   =", EU.execute("xor.s", sA=0b1010, sB=0b1100))
    print("not.s   =", EU.execute("not.s", sA=0b00001111))

    print("shl.s   =", EU.execute("shl.s", sA=5,  sB=1))
    print("srl.s   =", EU.execute("srl.s", sA=8,  sB=1))
    print("sra.s   =", EU.execute("sra.s", sA=-8, sB=1))

    print("slt.s   =", EU.execute("slt.s",  sA=-3, sB=2))
    print("sltu.s  =", EU.execute("sltu.s", sA=3,  sB=5))


    print("\n====================================================")
    print(" VECTOR LANES — SMOKE TESTS (BF16 masked + unmasked)")
    print("====================================================")

    vA = np.arange(0, 32).astype(np.float32)
    vB = np.ones(32, dtype=np.float32) * 2
    mask = np.zeros(32, dtype=np.float32); mask[:16] = 1.0  # first 16 active

    print("add.vv        =", EU.execute("add.vv", vA=vA, vB=vB))
    print("sub.vv        =", EU.execute("sub.vv", vA=vA, vB=vB))
    print("mul.vv        =", EU.execute("mul.vv", vA=vA, vB=vB))
    print("div.vv        =", EU.execute("div.vv", vA=vA+1, vB=vB))

    print("add.vv (mask) =", EU.execute("add.vv", vA=vA, vB=vB))
    print("mul.vv (mask) =", EU.execute("mul.vv", vA=vA, vB=vB))

    print("add.vs        =", EU.execute("add.vs", vA=vA, sA=10))
    print("sub.vs        =", EU.execute("sub.vs", vA=vA, sA=10))
    print("rsub.vs       =", EU.execute("rsub.vs", vA=vA, sA=10))
    print("mul.vs        =", EU.execute("mul.vs", vA=vA, sA=10))
    print("div.vs        =", EU.execute("div.vs", vA=vA+1, sA=10))
    print("rdiv.vs       =", EU.execute("rdiv.vs", vA=vA+1, sA=10))

    print("and.vv        =", EU.execute("and.vv", vA=vA.view(np.int32), vB=vB.view(np.int32)))
    print("or.vv         =", EU.execute("or.vv",  vA=vA.view(np.int32), vB=vB.view(np.int32)))
    print("xor.vv        =", EU.execute("xor.vv", vA=vA.view(np.int32), vB=vB.view(np.int32)))
    print("not.v         =", EU.execute("not.v",  vA=vA.view(np.int32)))

    print("shl.vs        =", EU.execute("shl.vs", vA=vA.view(np.int32), sA=1))
    print("shr.vs        =", EU.execute("shr.vs", vA=vA.view(np.int32), sA=1))

    print("gt.vv         =", EU.execute("gt.vv", vA=vA, vB=vB))
    print("lt.vv         =", EU.execute("lt.vv", vA=vA, vB=vB))
    print("eq.vv         =", EU.execute("eq.vv", vA=vA, vB=vA))
    print("neq.vv        =", EU.execute("neq.vv", vA=vA, vB=vA+1))

    print("sum.v         =", EU.execute("sum.v", vA=vA))
    print("exp.v         =", EU.execute("exp.v", vA=np.ones(32, dtype=np.float32)))
    print("sqrt.v        =", EU.execute("sqrt.v", vA=np.arange(32, dtype=np.float32)))


    print("\n====================================================")
    print(" MATMUL (Systolic Array) — SMOKE TEST")
    print("====================================================")
    A = np.eye(32, dtype=np.float32)
    B = np.random.randn(32, 32).astype(np.float32)
    print("mm.vv shape    =", EU.execute("mm.vv", A=A, B=B).shape)


    print("\n====================================================")
    print(" MOVE / CONVERT — SMOKE TESTS")
    print("====================================================")

    # scalar → BF16
    x = np.array([1, 2, 3, 4], dtype=np.int32)
    bf = EU.execute("stbf.s", sA=x)
    print("stbf.s:", bf)

    # BF16 → scalar int
    print("bfts.s:", EU.execute("bfts.s", vA=bf))

    # vector extract → scalar
    print("mov.vs:", EU.execute("mov.vs", vA=vA, index=5))

    # scalar broadcast → vector
    print("mov.ss:", EU.execute("mov.ss", sA=99))