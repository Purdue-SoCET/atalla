import numpy as np
from .perf_metrics import PerfMetrics

class ScalarALU:
    """
    A scalar functional unit operating on INT32 operands.
    - num_lanes: number of parallel scalar ALU lanes
    """

    def __init__(self, num_lanes: int = 32, perf_metrics: PerfMetrics = None):
        self.num_lanes = int(num_lanes)
        self.perf_metrics = perf_metrics if perf_metrics is not None else PerfMetrics()

    def _count_flops(self, amount: int = 1):
        flop_inc = int(max(0, amount))
        self.perf_metrics.increment("flops_scalar", flop_inc)
        self.perf_metrics.increment("flops_total", flop_inc)

    @property
    def flops(self) -> int:
        return int(self.perf_metrics.get_metric("flops_scalar", 0))

    @staticmethod
    def _word_to_int32(x):
        """
        Reinterpret input as a 32-bit word, then view it as signed INT32.
        This preserves hardware-like wrap semantics for values stored as
        unsigned 32-bit register words.
        """
        return np.uint32(int(x) & 0xFFFFFFFF).view(np.int32).item()

    def _as_int32(self, x):
        if isinstance(x, np.ndarray):
            if np.issubdtype(x.dtype, np.integer):
                return x.astype(np.uint32).view(np.int32)
            return x.astype(np.int32)
        if isinstance(x, (int, np.integer)):
            return np.int32(self._word_to_int32(x))
        return np.int32(x)

    def _broadcast_scalar(self, x):
        if isinstance(x, (int, np.integer)):
            return np.full(self.num_lanes, self._word_to_int32(x), dtype=np.int32)
        x = np.asarray(x, dtype=np.int32)
        if x.size == 1:
            return np.full(self.num_lanes, x[0], dtype=np.int32)
        assert x.size == self.num_lanes, "Operand length must match num_lanes"
        return x

    # -------------------------
    # Arithmetic ops
    # -------------------------
    def add(self, a, b) -> np.ndarray:
        a_i32 = self._broadcast_scalar(a)
        b_i32 = self._broadcast_scalar(b)
        return (a_i32 + b_i32).astype(np.int32)

    def sub(self, a, b) -> np.ndarray:
        a_i32 = self._broadcast_scalar(a)
        b_i32 = self._broadcast_scalar(b)
        return (a_i32 - b_i32).astype(np.int32)

    def mul(self, a, b) -> np.ndarray:
        a_i32 = self._broadcast_scalar(a)
        b_i32 = self._broadcast_scalar(b)
        return (a_i32 * b_i32).astype(np.int32)

    def div(self, a, b) -> np.ndarray:
        a_i32 = self._broadcast_scalar(a)
        b_i32 = self._broadcast_scalar(b)
        if np.any(b_i32 == 0):
            raise ZeroDivisionError("INT32 division by zero in ScalarALU")
        # Python's // for negative numbers does floor; emulate C semantics (trunc toward zero) by using integer division via truncation
        res = np.trunc(a_i32.astype(np.float64) / b_i32.astype(np.float64)).astype(np.int32)
        return res

    def mod(self, a, b) -> np.ndarray:
        a_i32 = self._broadcast_scalar(a)
        b_i32 = self._broadcast_scalar(b)
        if np.any(b_i32 == 0):
            raise ZeroDivisionError("INT32 modulo by zero in ScalarALU")
        # Emulate C-like remainder (sign follows dividend): use np.mod with careful handling
        res = (a_i32 % b_i32).astype(np.int32)
        return res

    # -------------------------
    # Comparison ops (INT32)
    # -------------------------
    def slt(self, a, b) -> np.ndarray:
        """
        Signed comparison: result[i] = 1 if a[i] < b[i] (signed), else 0
        """
        a_i32 = self._broadcast_scalar(a).astype(np.int32)
        b_i32 = self._broadcast_scalar(b).astype(np.int32)
        return (a_i32 < b_i32).astype(np.int32)

    def sltu(self, a, b) -> np.ndarray:
        """
        Unsigned comparison: compare as uint32.
        result[i] = 1 if a_u32[i] < b_u32[i] (unsigned), else 0
        """
        a_u32 = self._broadcast_scalar(a).astype(np.uint32)
        b_u32 = self._broadcast_scalar(b).astype(np.uint32)
        return (a_u32 < b_u32).astype(np.int32)
    
    # -------------------------
    # Additional unsigned comparisons (INT32)
    # -------------------------
    def sgtu(self, a, b) -> np.ndarray:
        """
        Unsigned greater-than:
        result[i] = 1 if a_u32 > b_u32 else 0
        """
        a_u32 = self._broadcast_scalar(a).astype(np.uint32)
        b_u32 = self._broadcast_scalar(b).astype(np.uint32)
        return (a_u32 > b_u32).astype(np.int32)

    def sequ(self, a, b) -> np.ndarray:
        """
        Unsigned equality:
        result[i] = 1 if a_u32 == b_u32 else 0
        """
        a_u32 = self._broadcast_scalar(a).astype(np.uint32)
        b_u32 = self._broadcast_scalar(b).astype(np.uint32)
        return (a_u32 == b_u32).astype(np.int32)

    def sneu(self, a, b) -> np.ndarray:
        """
        Unsigned not-equal:
        result[i] = 1 if a_u32 != b_u32 else 0
        """
        a_u32 = self._broadcast_scalar(a).astype(np.uint32)
        b_u32 = self._broadcast_scalar(b).astype(np.uint32)
        return (a_u32 != b_u32).astype(np.int32)

    # -------------------------
    # Bitwise ops (INT32)
    # -------------------------
    def bit_or(self, a, b) -> np.ndarray:
        a_i32 = self._broadcast_scalar(a).astype(np.int32)
        b_i32 = self._broadcast_scalar(b).astype(np.int32)
        return np.bitwise_or(a_i32, b_i32).astype(np.int32)

    def bit_and(self, a, b) -> np.ndarray:
        a_i32 = self._broadcast_scalar(a).astype(np.int32)
        b_i32 = self._broadcast_scalar(b).astype(np.int32)
        return np.bitwise_and(a_i32, b_i32).astype(np.int32)

    def bit_xor(self, a, b) -> np.ndarray:
        a_i32 = self._broadcast_scalar(a).astype(np.int32)
        b_i32 = self._broadcast_scalar(b).astype(np.int32)
        return np.bitwise_xor(a_i32, b_i32).astype(np.int32)

    def bit_not(self, a) -> np.ndarray:
        a_i32 = self._broadcast_scalar(a).astype(np.int32)
        # bitwise_not on signed ints: operate on uint32 then view as int32 for consistent wrap
        return np.bitwise_not(a_i32.astype(np.uint32)).astype(np.int32)

    # -------------------------
    # Shifts (INT32)
    # -------------------------
    def shl(self, a, shift) -> np.ndarray:
        a_i32 = self._broadcast_scalar(a).astype(np.uint32)
        s = int(shift) if not isinstance(shift, (list, np.ndarray)) else np.asarray(shift, dtype=np.uint32)
        if isinstance(s, np.ndarray) and s.size != a_i32.size:
            if s.size == 1:
                s = np.full(a_i32.size, s.item(), dtype=np.uint32)
            else:
                raise ValueError("Shift amount must be scalar or same length as operands")
        return (a_i32 << s).astype(np.uint32).view(np.int32)

    def srl(self, a, shift) -> np.ndarray:
        a_u32 = self._broadcast_scalar(a).astype(np.uint32)
        s = int(shift) if not isinstance(shift, (list, np.ndarray)) else np.asarray(shift, dtype=np.uint32)
        if isinstance(s, np.ndarray) and s.size != a_u32.size:
            if s.size == 1:
                s = np.full(a_u32.size, s.item(), dtype=np.uint32)
            else:
                raise ValueError("Shift amount must be scalar or same length as operands")
        return (a_u32 >> s).astype(np.uint32).view(np.int32)

    def sra(self, a, shift) -> np.ndarray:
        a_i32 = self._broadcast_scalar(a).astype(np.int32)
        s = int(shift) if not isinstance(shift, (list, np.ndarray)) else np.asarray(shift, dtype=np.int32)
        if isinstance(s, np.ndarray) and s.size != a_i32.size:
            if s.size == 1:
                s = np.full(a_i32.size, s.item(), dtype=np.int32)
            else:
                raise ValueError("Shift amount must be scalar or same length as operands")
        return (a_i32 >> s).astype(np.int32)

    # ----------------------------------------------------
    # BF16 conversion helpers
    # ----------------------------------------------------
    def _to_bf16_array(self, x):
        """
        Convert input to a numpy array of uint16 BF16 bit-patterns.
        Accepts scalar float, numpy array of floats, or uint16 array.
        """
        if isinstance(x, (int, np.integer)):
            raise TypeError("BF16 ops require float or BF16 inputs, not int32")

        arr = np.asarray(x)

        # If already uint16, assume raw BF16 bits
        if arr.dtype == np.uint16:
            return arr.astype(np.uint16)

        # Otherwise treat as float32 input → convert to BF16
        arr = arr.astype(np.float32)
        return self._float32_to_bf16(arr)

    def _bf16_to_float32(self, bf16_arr):
        """
        bf16_arr: uint16 array → convert to float32
        """
        bf16_arr = bf16_arr.astype(np.uint16)

        # Shift into high 16 bits of uint32
        u32 = bf16_arr.astype(np.uint32) << 16
        return u32.view(np.float32)

    def _float32_to_bf16(self, f32_arr):
        """
        Convert float32 array to BF16 bit-patterns (uint16) using round-to-nearest-even.
        """
        as_u32 = f32_arr.view(np.uint32)
        lsb = (as_u32 >> 16) & 1             # sticky LSB for round-to-nearest-even
        rounding_bias = 0x7FFF + lsb
        as_u32 = as_u32 + rounding_bias
        return (as_u32 >> 16).astype(np.uint16)

    def _broadcast_bf16(self, x):
        """
        Broadcast BF16 scalar → lanes.
        Preserves BF16 bit patterns exactly.
        """
        bf = self._to_bf16_array(x)
        if bf.size == 1:
            return np.full(self.num_lanes, bf.item(), dtype=np.uint16)
        assert bf.size == self.num_lanes
        return bf
    
    # ----------------------------------------------------
    # BF16 arithmetic
    # ----------------------------------------------------
    def addbf(self, a, b):
        return (a + b)

    def subbf(self, a, b):
        return (a - b)

    def mulbf(self, a, b):
        return (a * b)

    def rcpbf(self, a, b=None):
        if np.any(a == 0.0):
            raise ZeroDivisionError("BF16 reciprocal of zero")
        return 1.0 / a

    # -------------------------
    # BF16 comparisons
    # -------------------------
    def sltbf(self, a, b):
        """
        Signed float comparison: (float32(A) < float32(B)) ? 1 : 0
        """
        return (a < b)

    def sltubf(self, a, b):
        """
        Unsigned comparison on raw BF16 bit-patterns.
        (treat BF16 as uint16 and compare)
        """
        return (a < b)

    # -------------------------
    # Unified dispatch interface
    # -------------------------
    def execute(self, op: str, a=None, b=None):
        op = op.lower()
        self._count_flops(1)
        if op == "add":
            return self.add(a, b)
        elif op == "sub":
            return self.sub(a, b)
        elif op == "mul":
            return self.mul(a, b)
        elif op == "div":
            return self.div(a, b)
        elif op == "mod":
            return self.mod(a, b)
        elif op == "or":
            return self.bit_or(a, b)
        elif op == "and":
            return self.bit_and(a, b)
        elif op == "xor":
            return self.bit_xor(a, b)
        elif op == "not":
            return self.bit_not(a)
        elif op == "shl":
            return self.shl(a, b)
        elif op == "srl":
            return self.srl(a, b)
        elif op == "sra":
            return self.sra(a, b)
        elif op == "slt":
            return self.slt(a, b)
        elif op == "sltu":
            return self.sltu(a, b)
        elif op == "addbf":
            return self.addbf(a, b)
        elif op == "subbf":
            return self.subbf(a, b)
        elif op == "mulbf":
            return self.mulbf(a, b)
        elif op == "rcpbf":
            return self.rcpbf(a, b)
        elif op == "sltbf":
            return self.sltbf(a, b)
        elif op == "sltubf":
            return self.sltubf(a, b)
        elif op == "sgtu":
            return self.sgtu(a, b)
        elif op == "sequ":
            return self.sequ(a, b)
        elif op == "sneu":
            return self.sneu(a, b)

        else:
            raise ValueError(f"Unknown scalar ALU op '{op}'")


# -----------------------------------
# Convenience wrapper
# -----------------------------------
def scalar_alu_execute(op: str, a, b, num_lanes: int = 32) -> np.ndarray:
    alu = ScalarALU(num_lanes=num_lanes)
    return alu.execute(op, a, b)


# -----------------------------------
# Smoke test
# -----------------------------------
if __name__ == "__main__":
    alu = ScalarALU(num_lanes=1)
    print("add:", alu.add(4, 10))
    print(type(alu.add(1, 10)))
    print("bit_and:", alu.bit_and(3, 3))
    print("not:", alu.bit_not(7))
    print("shl:", alu.shl(1, 2))
    print("srl:", alu.srl(0x8000, 1))
    print("sra:", alu.sra(-2, 1))
    print("addbf:", alu.execute("addbf", [1.0], [2.0]))
    print("subbf:", alu.execute("subbf", [5.5], [1.25]))
    print("mulbf:", alu.execute("mulbf", [3.0], [4.0]))
    print("rcpbf:", alu.execute("rcpbf", [8.0]))
    print("sltbf:", alu.execute("sltbf", [1.0], [2.0]))
    print("sltubf:", alu.execute("sltubf", np.uint16([0x3f80]), np.uint16([0x4000])))
    print("sgtu:", alu.execute("sgtu", [-1], [0])) 
    print("sequ:", alu.execute("sequ", [10], [10]))
    print("sneu:", alu.execute("sneu", [10], [20]))