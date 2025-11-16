"""
scalar_alu_emu.py
Functional INT32 scalar ALU for hardware emulator framework.
Supports parametric number of lanes executing:
    add, sub, mul, div, mod, bitwise ops, shifts
All operations are strictly INT32.
"""

import numpy as np

class ScalarALU:
    """
    A scalar functional unit operating on INT32 operands.
    - num_lanes: number of parallel scalar ALU lanes
    """

    def __init__(self, num_lanes: int = 32):
        self.num_lanes = int(num_lanes)

    def _as_int32(self, x):
        if isinstance(x, np.ndarray):
            return x.astype(np.int32)
        return np.int32(x)

    def _broadcast_scalar(self, x):
        if isinstance(x, (int, np.integer)):
            return np.full(self.num_lanes, np.int32(x), dtype=np.int32)
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

    # -------------------------
    # Unified dispatch interface
    # -------------------------
    def execute(self, op: str, a=None, b=None):
        op = op.lower()
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
