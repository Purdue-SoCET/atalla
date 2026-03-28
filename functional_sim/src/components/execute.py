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
from typing import Optional
from .gemm import SystolicArray, to_bf16
from .vector_lanes import VectorLanes
from .scalar import ScalarALU
from .convert_unit import MoveConvertUnit
from .perf_metrics import PerfMetrics

# ============================================================
# Mnemonic tables
# ============================================================

MNEMONIC_SCALAR = {
    "add.s": "add",
    "sub.s": "sub",
    "mul.s": "mul",
    "mod.s": "mod",
    "or.s":  "or",
    "and.s": "and",
    "xor.s": "xor",
    "not.s": "not",
    "sll.s": "shl",
    "srl.s": "srl",
    "sra.s": "sra",
    "slt.s":  "slt",
    "sltu.s": "sltu",
    "add.bf": "addbf",
    "sub.bf": "subbf",
    "mul.bf": "mulbf",
    "rcp.bf": "rcpbf",
    "slt.bf": "sltbf",
    "sltu.bf": "sltubf",
    "addi.s": "add",
    "subi.s": "sub",
    "muli.s": "mul",
    "divi.s": "div",
    "modi.s": "mod",
    "ori.s":  "or",
    "andi.s": "and",
    "xori.s": "xor",
    "slli.s": "shl",
    "srli.s": "srl",
    "srai.s": "sra",
    "slti.s":  "slt",
    "sltui.s": "sltu",
    "mgt.vv": "sgtu",
    "mlt.vv": "sltu",
    "meq.vv": "sequ",
    "mneq.vv": "sneu"
}

MNEMONIC_VECTOR = {
    "add.vv": "add",
    "sub.vv": "sub",
    "mul.vv": "mul",
    "div.vv": "div",
    "and.vv": "bw_and",
    "or.vv":  "bw_or",
    "xor.vv": "bw_xor",

    "addi.vi": "add_scalar",
    "subi.vi": "sub_scalar",
    "muli.vi": "mul_scalar",
    "expi.vi":  "exp",
    "sqrti.vi": "sqrt",
    "not.vi":  "bw_not",
    "shift.vi": "shl_scalar",
    "shift.vi": "shr_scalar",

    "rsum.vi":  "reduce_sum",
    "rmin.vi":  "reduce_min",
    "rmax.vi":  "reduce_max",

    "shift.vs": "shl_scalar",
    "shift.vs": "shr_scalar",
    "add.vs": "add_scalar",
    "sub.vs": "sub_scalar",
    "rsub.vs": "scalar_sub",
    "mul.vs": "mul_scalar",
    "div.vs": "div_scalar",
    
    "mgt.mvv":  "cmp_gt",
    "mlt.mvv":  "cmp_lt",
    "meq.mvv":  "cmp_eq",
    "mneq.mvv": "cmp_neq",

    "mgt.mvs": "cmp_gt",
    "mlt.mvs": "cmp_lt",
    "meq.mvs": "cmp_eq",
    "mneq.mvs": "cmp_neq",
}

MNEMONIC_MATMUL = {
    "gemm.vv": "matmul"
}

MNEMONIC_MOVECON = {
    "stbf.s": "int32_to_bf16",
    "bfts.s": "bf16_to_int32",
    "mov.vs": "vector_extract",       # vA + index → scalar
    "mov.ss": "scalar_broadcast",     # sA → VL-length vector
}

# ============================================================
# Execute Unit
# ============================================================
class ExecuteUnit:
    def __init__(self,
                 vector_length: int = 32,
                 matmul_tile: int = 32,
                 num_scalar_lanes: int = 1,
                 perf_metrics: Optional[PerfMetrics] = None):
        self.vl = int(vector_length)
        self.matmul_tile = int(matmul_tile)
        self.perf_metrics = perf_metrics if perf_metrics is not None else PerfMetrics()

        # instantiate sub-units
        self.vec = VectorLanes(VL=self.vl, perf_metrics=self.perf_metrics)
        self.scalar = ScalarALU(num_lanes=num_scalar_lanes, perf_metrics=self.perf_metrics)
        self.matmul = SystolicArray(size=self.matmul_tile, perf_metrics=self.perf_metrics)
        self.mov = MoveConvertUnit(default_VL=self.vl, perf_metrics=self.perf_metrics)

    def reset_flops(self):
        self.perf_metrics.set_metric("flops_total", 0)
        self.perf_metrics.set_metric("flops_scalar", 0)
        self.perf_metrics.set_metric("flops_vector", 0)
        self.perf_metrics.set_metric("flops_matmul", 0)
        self.vec.reset_flops()
        self.matmul.reset_flops()

    @property
    def flops(self) -> int:
        return int(self.perf_metrics.get_metric("flops_total", 0))

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
                sA=None, sB=None, slr=None,
                index: int = None,
                out_vl: int = None):

        instr = instr.strip().lower()

        # =======================================================
        # SCALAR
        # =======================================================
        if instr in MNEMONIC_SCALAR:
            op = MNEMONIC_SCALAR[instr]
            result = self.scalar.execute(op, sA, sB)
            if isinstance(result, np.ndarray) and result.size == 1:
                return result.item()
            return result

        # =======================================================
        # VECTOR
        # =======================================================
        if instr in MNEMONIC_VECTOR:
            return self.vec.execute(instr, vA, vB, sA, slr, mask)

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
    print("divi.s  =", EU.execute("divi.s", sA=20, sB=5))
    print("mod.s   =", EU.execute("mod.s", sA=22, sB=5))

    print("or.s    =", EU.execute("or.s",  sA=0b1010, sB=0b1100))
    print("and.s   =", EU.execute("and.s", sA=0b1010, sB=0b1100))
    print("xor.s   =", EU.execute("xor.s", sA=0b1010, sB=0b1100))
    print("not.s   =", EU.execute("not.s", sA=0b00001111))

    print("sll.s   =", EU.execute("sll.s", sA=5,  sB=1))
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

    print("add.vv (mask) =", EU.execute("add.vv", vA=vA, vB=vB))
    print("mul.vv (mask) =", EU.execute("mul.vv", vA=vA, vB=vB))

    print("add.vs        =", EU.execute("add.vs", vA=vA, sA=10))
    print("sub.vs        =", EU.execute("sub.vs", vA=vA, sA=10))
    print("rsub.vs       =", EU.execute("rsub.vs", vA=vA, sA=10))
    print("mul.vs        =", EU.execute("mul.vs", vA=vA, sA=10))

    print("and.vv        =", EU.execute("and.vv", vA=vA.view(np.int32), vB=vB.view(np.int32)))
    print("or.vv         =", EU.execute("or.vv",  vA=vA.view(np.int32), vB=vB.view(np.int32)))
    print("xor.vv        =", EU.execute("xor.vv", vA=vA.view(np.int32), vB=vB.view(np.int32)))
    print("not.vi         =", EU.execute("not.vi",  vA=vA.view(np.int32)))

    print("lshift.vs        =", EU.execute("lshift.vs", vA=vA.view(np.int32), sA=1))
    print("rshift.vs        =", EU.execute("rshift.vs", vA=vA.view(np.int32), sA=1))

    print("gt.vv         =", EU.execute("gt.vv", vA=vA, vB=vB))
    print("lt.vv         =", EU.execute("lt.vv", vA=vA, vB=vB))
    print("eq.vv         =", EU.execute("eq.vv", vA=vA, vB=vA))
    print("neq.vv        =", EU.execute("neq.vv", vA=vA, vB=vA+1))

    print("rsum.vi         =", EU.execute("rsum.vi", vA=vA))
    print("rmin.vi         =", EU.execute("rmin.vi", vA=vA))
    print("rmax.vi         =", EU.execute("rmax.vi", vA=vA))
    print("expi.vi         =", EU.execute("expi.vi", vA=np.ones(32, dtype=np.float32)))
    print("sqrti.vi        =", EU.execute("sqrti.vi", vA=np.arange(32, dtype=np.float32)))


    print("\n====================================================")
    print(" MATMUL (Systolic Array) — SMOKE TEST")
    print("====================================================")
    A = np.eye(32, dtype=np.float32)
    B = np.random.randn(32, 32).astype(np.float32)
    print("gemm.vv shape    =", EU.execute("gemm.vv", A=A, B=B).shape)


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
