"""
execute_unit_emu.py
Top-level Execute Unit combining SystolicArray, VectorLanes, ScalarALU.

Updated to include scalar & vector bitwise opcodes (Option A semantics for vector).
"""

import numpy as np

from gemm import SystolicArray, to_bf16
from vector_lanes import VectorLanes
from scalar import ScalarALU

# ------------------------------------------------
# FU selector (MSB 2 bits)
# ------------------------------------------------
FU_SCALAR  = 0b00
FU_VECTOR  = 0b01
FU_MATMUL  = 0b10

# ------------------------------------------------
# Scalar sub-opcodes (lower 6 bits)
# keep earlier codes 0x00..0x04
OP_SCALAR_ADD = 0x00
OP_SCALAR_SUB = 0x01
OP_SCALAR_MUL = 0x02
OP_SCALAR_DIV = 0x03
OP_SCALAR_MOD = 0x04
# scalar bitwise ops start at 0x10
OP_SCALAR_OR  = 0x10
OP_SCALAR_AND = 0x11
OP_SCALAR_XOR = 0x12
OP_SCALAR_NOT = 0x13
OP_SCALAR_SLL = 0x14
OP_SCALAR_SRL = 0x15
OP_SCALAR_SRA = 0x16

# ------------------------------------------------
# Vector sub-opcodes
OP_VEC_ADD   = 0x00
OP_VEC_SUB   = 0x01
OP_VEC_MUL   = 0x02
OP_VEC_DIV   = 0x03
OP_VEC_EXP   = 0x04
OP_VEC_SQRT  = 0x05
OP_VEC_REDUCE_SUM = 0x06
# vector bitwise codes
OP_VEC_BW_AND = 0x10
OP_VEC_BW_OR  = 0x11
OP_VEC_BW_XOR = 0x12
OP_VEC_BW_NOT = 0x13

# Matmul op
OP_MATMUL_MM = 0x00

# ============================================================
# Execute Unit
# ============================================================
class ExecuteUnit:
    def __init__(self,
                 vector_length: int = 32,
                 matmul_tile: int = 32,
                 num_scalar_lanes: int = 32):
        self.vl = int(vector_length)
        self.matmul_tile = int(matmul_tile)
        self.vec = VectorLanes(VL=self.vl)
        self.scalar = ScalarALU(num_lanes=num_scalar_lanes)
        self.matmul = SystolicArray(size=self.matmul_tile)

    @staticmethod
    def _decode_opcode(opcode: int):
        opcode_u = int(np.int8(opcode) & 0xFF)
        fu = (opcode_u >> 6) & 0b11
        subop = opcode_u & 0x3F
        return fu, subop

    def execute(self,
                opcode: int,
                # Matmul operands
                A: np.ndarray = None,
                B: np.ndarray = None,
                # Vector operands
                vA: np.ndarray = None,
                vB: np.ndarray = None,
                # Scalar operands
                sA=None,
                sB=None):
        fu, subop = self._decode_opcode(opcode)

        # SCALAR
        if fu == FU_SCALAR:
            if subop == OP_SCALAR_ADD:
                return self.scalar.add(sA, sB)
            elif subop == OP_SCALAR_SUB:
                return self.scalar.sub(sA, sB)
            elif subop == OP_SCALAR_MUL:
                return self.scalar.mul(sA, sB)
            elif subop == OP_SCALAR_DIV:
                return self.scalar.div(sA, sB)
            elif subop == OP_SCALAR_MOD:
                return self.scalar.mod(sA, sB)
            elif subop == OP_SCALAR_OR:
                return self.scalar.bit_or(sA, sB)
            elif subop == OP_SCALAR_AND:
                return self.scalar.bit_and(sA, sB)
            elif subop == OP_SCALAR_XOR:
                return self.scalar.bit_xor(sA, sB)
            elif subop == OP_SCALAR_NOT:
                return self.scalar.bit_not(sA)
            elif subop == OP_SCALAR_SLL:
                return self.scalar.shl(sA, sB)
            elif subop == OP_SCALAR_SRL:
                return self.scalar.srl(sA, sB)
            elif subop == OP_SCALAR_SRA:
                return self.scalar.sra(sA, sB)
            else:
                raise ValueError(f"Unknown scalar sub-op {subop}")

        # VECTOR (BF16)
        elif fu == FU_VECTOR:
            if subop == OP_VEC_ADD:
                return self.vec.add(vA, vB)
            elif subop == OP_VEC_SUB:
                return self.vec.sub(vA, vB)
            elif subop == OP_VEC_MUL:
                return self.vec.mul(vA, vB)
            elif subop == OP_VEC_DIV:
                return self.vec.div(vA, vB)
            elif subop == OP_VEC_EXP:
                return self.vec.exp(vA)
            elif subop == OP_VEC_SQRT:
                return self.vec.sqrt(vA)
            elif subop == OP_VEC_REDUCE_SUM:
                return self.vec.reduce_sum(vA)
            elif subop == OP_VEC_BW_AND:
                return self.vec.bitwise_and(vA, vB)
            elif subop == OP_VEC_BW_OR:
                return self.vec.bitwise_or(vA, vB)
            elif subop == OP_VEC_BW_XOR:
                return self.vec.bitwise_xor(vA, vB)
            elif subop == OP_VEC_BW_NOT:
                return self.vec.bitwise_not(vA)
            else:
                raise ValueError(f"Unknown vector sub-op {subop}")

        # MATMUL
        elif fu == FU_MATMUL:
            if subop == OP_MATMUL_MM:
                return self.matmul.matmul(A, B)
            else:
                raise ValueError(f"Unknown matmul sub-op {subop}")

        else:
            raise ValueError(f"Invalid FU selector {fu}")

# ============================================================
# Smoke Test (expanded to include all subops)
# ============================================================

if __name__ == "__main__":
    EU = ExecuteUnit()

    print("===== SCALAR INT32 TESTS =====")

    # scalar operands
    sA = 10
    sB = 3

    print("Scalar add:", EU.execute((FU_SCALAR << 6) | OP_SCALAR_ADD, sA=sA, sB=sB))
    print("Scalar sub:", EU.execute((FU_SCALAR << 6) | OP_SCALAR_SUB, sA=sA, sB=sB))
    print("Scalar mul:", EU.execute((FU_SCALAR << 6) | OP_SCALAR_MUL, sA=sA, sB=sB))
    print("Scalar div:", EU.execute((FU_SCALAR << 6) | OP_SCALAR_DIV, sA=sA, sB=sB))
    print("Scalar mod:", EU.execute((FU_SCALAR << 6) | OP_SCALAR_MOD, sA=sA, sB=sB))

    print("Scalar bitwise or:",  EU.execute((FU_SCALAR << 6) | OP_SCALAR_OR,  sA=sA, sB=sB))
    print("Scalar bitwise and:", EU.execute((FU_SCALAR << 6) | OP_SCALAR_AND, sA=sA, sB=sB))
    print("Scalar bitwise xor:", EU.execute((FU_SCALAR << 6) | OP_SCALAR_XOR, sA=sA, sB=sB))
    print("Scalar bitwise not:", EU.execute((FU_SCALAR << 6) | OP_SCALAR_NOT, sA=sA))

    print("Scalar SLL:", EU.execute((FU_SCALAR << 6) | OP_SCALAR_SLL, sA=sA, sB=1))
    print("Scalar SRL:", EU.execute((FU_SCALAR << 6) | OP_SCALAR_SRL, sA=sA, sB=1))
    print("Scalar SRA:", EU.execute((FU_SCALAR << 6) | OP_SCALAR_SRA, sA=sA, sB=1))

    print("\n===== VECTOR BF16 TESTS =====")

    VL = 32
    vA = np.linspace(1, 32, VL).astype(np.float32)
    vB = np.linspace(32, 1, VL).astype(np.float32)

    print("Vector add:", EU.execute((FU_VECTOR << 6) | OP_VEC_ADD, vA=vA, vB=vB))
    print("Vector sub:", EU.execute((FU_VECTOR << 6) | OP_VEC_SUB, vA=vA, vB=vB))
    print("Vector mul:", EU.execute((FU_VECTOR << 6) | OP_VEC_MUL, vA=vA, vB=vB))
    print("Vector div:", EU.execute((FU_VECTOR << 6) | OP_VEC_DIV, vA=vA, vB=vB))
    print("Vector exp:", EU.execute((FU_VECTOR << 6) | OP_VEC_EXP, vA=vA))
    print("Vector sqrt:", EU.execute((FU_VECTOR << 6) | OP_VEC_SQRT, vA=vA))
    print("Vector reduce-sum:", EU.execute((FU_VECTOR << 6) | OP_VEC_REDUCE_SUM, vA=vA))

    print("Vector bitwise and:", EU.execute((FU_VECTOR << 6) | OP_VEC_BW_AND, vA=vA, vB=vB))
    print("Vector bitwise or:",  EU.execute((FU_VECTOR << 6) | OP_VEC_BW_OR,  vA=vA, vB=vB))
    print("Vector bitwise xor:", EU.execute((FU_VECTOR << 6) | OP_VEC_BW_XOR, vA=vA, vB=vB))
    print("Vector bitwise not:", EU.execute((FU_VECTOR << 6) | OP_VEC_BW_NOT, vA=vA))

    print("\n===== MATMUL (SYSTOLIC ARRAY) TEST =====")

    A = np.random.randn(32, 32).astype(np.float32)
    B = np.random.randn(32, 32).astype(np.float32)

    C = EU.execute((FU_MATMUL << 6) | OP_MATMUL_MM, A=A, B=B)
    print("Matmul output shape:", C.shape)
    print("Matmul sample:", C[0, :4])