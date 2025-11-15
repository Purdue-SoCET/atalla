"""
scalar_alu_emu.py
Functional INT32 scalar ALU for hardware emulator framework.
Supports parametric number of lanes executing:
    add, sub, mul, div, mod
All operations are strictly INT32.
"""

import numpy as np
from typing import List, Optional


class ScalarALU:
    """
    A scalar functional unit operating on INT32 operands.
    - num_lanes: number of parallel scalar ALU lanes
      (each lane executes one scalar op per call)
    """

    def __init__(self, num_lanes: int = 32):
        self.num_lanes = int(num_lanes)

    # -------------------------
    # Internal helpers
    # -------------------------
    def _as_int32(self, x):
        """Convert to numpy int32."""
        if isinstance(x, np.ndarray):
            return x.astype(np.int32)
        return np.int32(x)

    def _broadcast_scalar(self, x):
        """
        Ensure x is a vector of length num_lanes.
        Single scalar inputs get broadcast.
        """
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
        # Emulate INT32 behavior: divide-by-zero → raise exception
        if np.any(b_i32 == 0):
            raise ZeroDivisionError("INT32 division by zero in ScalarALU")
        return (a_i32 // b_i32).astype(np.int32)

    def mod(self, a, b) -> np.ndarray:
        a_i32 = self._broadcast_scalar(a)
        b_i32 = self._broadcast_scalar(b)
        if np.any(b_i32 == 0):
            raise ZeroDivisionError("INT32 modulo by zero in ScalarALU")
        return (a_i32 % b_i32).astype(np.int32)

    # -------------------------
    # Unified dispatch interface
    # -------------------------
    def execute(self, op: str, a, b) -> np.ndarray:
        """
        Unified execution entrypoint.
        op: 'add', 'sub', 'mul', 'div', 'mod'
        a, b: scalar or length-num_lanes INT32 vectors
        """
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
        else:
            raise ValueError(f"Unknown scalar ALU op '{op}'")


# -----------------------------------
# Convenience wrapper
# -----------------------------------
def scalar_alu_execute(op: str, a, b, num_lanes: int = 32) -> np.ndarray:
    """
    Utility wrapper to directly perform an ALU op.
    """
    alu = ScalarALU(num_lanes=num_lanes)
    return alu.execute(op, a, b)


# -----------------------------------
# Smoke test
# -----------------------------------
if __name__ == "__main__":
    alu = ScalarALU(num_lanes=4)
    print("add:", alu.add([1, 2, 3, 4], 10))
    print("sub:", alu.sub(20, [1, 2, 3, 4]))
    print("mul:", alu.mul([2, 3, 4, 5], [3, 4, 5, 6]))
    print("div:", alu.div([20, 30, 40, 50], [1, 2, 5, 10]))
    print("mod:", alu.mod([20, 30, 40, 50], [7, 6, 9, 8]))
