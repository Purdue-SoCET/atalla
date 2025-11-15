"""
move_convert_emu.py
Move & Conversion Unit for emulator.

Operations (numeric conversion semantics - Option A):
  - int32_to_bf16(int32 or array) -> bf16-emulated float32 (values converted numerically)
  - bf16_to_int32(bf16 array) -> int32 (numeric conversion via truncation toward zero)
  - vector_extract(vector, index) -> single BF16-emulated float32 value (vector element at index)
  - scalar_broadcast_to_vector(scalar, VL) -> BF16-emulated float32 vector of length VL

Style matches other emulator modules (self-contained BF16 helpers).
"""

import numpy as np
from typing import Optional, Union


# -------------------------
# BF16 helpers (self-contained)
# -------------------------
def bf16_round(x: np.ndarray) -> np.ndarray:
    """Round float32 values to nearest BF16 (tie-to-even)."""
    x_f32 = x.astype(np.float32)
    u = x_f32.view(np.uint32)
    lsb = (u >> 16) & np.uint32(1)
    add = np.uint32(0x7FFF) + lsb
    u_round = u + add
    u_bf16 = (u_round & np.uint32(0xFFFF0000)).astype(np.uint32)
    return u_bf16.view(np.float32)


def float32_to_bf16_trunc(x: np.ndarray) -> np.ndarray:
    """Truncate float32 to BF16 (no rounding)."""
    u = x.astype(np.float32).view(np.uint32)
    u_bf16 = (u & np.uint32(0xFFFF0000)).astype(np.uint32)
    return u_bf16.view(np.float32)


def to_bf16(x: np.ndarray, rounding: bool = True) -> np.ndarray:
    """Convert values to BF16-emulated float32 values."""
    return bf16_round(x) if rounding else float32_to_bf16_trunc(x)


# -------------------------
# Move & Conversion Unit
# -------------------------
class MoveConvertUnit:
    """
    Move & Conversion functional unit.

    Numeric conversions only (Option A):
      - INT32 -> BF16: numeric conversion (int -> float -> bf16)
      - BF16 -> INT32: numeric conversion (trunc toward zero)
    """

    def __init__(self, default_VL: int = 32, bf16_rounding: bool = True):
        self.default_VL = int(default_VL)
        self.bf16_rounding = bool(bf16_rounding)

    # -------------------------
    # INT32 -> BF16 (numeric)
    # -------------------------
    def int32_to_bf16(self, x: Union[int, np.ndarray]) -> np.ndarray:
        """
        Convert INT32 scalar or array to BF16-emulated float32 numeric values.
        - x: int or array-like
        Returns: numpy array of dtype float32 containing BF16-quantized values.
        """
        arr = np.asarray(x, dtype=np.int32)
        # numeric convert: int -> float32 -> bf16-quantize
        f = arr.astype(np.float32)
        return to_bf16(f, rounding=self.bf16_rounding)

    # -------------------------
    # BF16 -> INT32 (numeric conversion)
    # -------------------------
    def bf16_to_int32(self, bf16_arr: np.ndarray) -> np.ndarray:
        """
        Convert BF16-emulated float32 values to INT32 via numeric conversion.
        Rounds toward zero (truncation).
        - bf16_arr: numpy array containing BF16-emulated float32 values (or float32)
        Returns: numpy array of dtype int32
        """
        f = np.asarray(bf16_arr, dtype=np.float32)
        # numeric truncation toward zero
        i = np.trunc(f.astype(np.float32)).astype(np.int32)
        return i

    # -------------------------
    # Vector -> Scalar (extract element)
    # -------------------------
    def vector_extract(self, vec: np.ndarray, index: int) -> np.float32:
        """
        Extract element vec[index] and return it as BF16-emulated float32 scalar.
        Index supports negative indexing like Python.
        """
        v = np.asarray(vec, dtype=np.float32)
        if v.ndim != 1:
            raise ValueError("vector_extract expects a 1D vector")
        L = v.size
        # normalize negative indices
        if index < 0:
            index = L + index
        if not (0 <= index < L):
            raise IndexError(f"index {index} out of range for vector length {L}")
        # quantize and return single element as BF16-emulated float32
        q = to_bf16(v, rounding=self.bf16_rounding)
        return np.array(q[index], dtype=np.float32)

    # -------------------------
    # Scalar -> Vector (broadcast)
    # -------------------------
    def scalar_broadcast_to_vector(self, scalar: Union[int, float, np.ndarray], VL: Optional[int] = None) -> np.ndarray:
        """
        Broadcast scalar to a vector of length VL (default default_VL).
        If scalar is INT32 (numpy int type or Python int), convert numerically to BF16.
        If scalar is float (or BF16-emulated float32), quantize to BF16 and broadcast.
        Returns BF16-emulated float32 vector of length VL.
        """
        vl = int(VL) if VL is not None else self.default_VL

        # If scalar is array-like with length matching vl, just quantize/broadcast elementwise.
        if isinstance(scalar, (list, tuple, np.ndarray)):
            arr = np.asarray(scalar)
            if arr.size == vl:
                # quantize each element (assume float semantics if floats, else convert ints->float)
                if np.issubdtype(arr.dtype, np.integer):
                    f = arr.astype(np.float32)
                    return to_bf16(f, rounding=self.bf16_rounding)
                else:
                    return to_bf16(arr.astype(np.float32), rounding=self.bf16_rounding)
            if arr.size == 1:
                scalar = arr.item()

        # Scalar path
        if isinstance(scalar, (int, np.integer)):
            # numeric convert int -> float -> bf16
            f = np.float32(int(scalar))
            vec = np.full(vl, f, dtype=np.float32)
            return to_bf16(vec, rounding=self.bf16_rounding)
        else:
            # treat as float (or bf16-emulated float32)
            f = np.float32(scalar)
            vec = np.full(vl, f, dtype=np.float32)
            return to_bf16(vec, rounding=self.bf16_rounding)


# -------------------------
# Quick smoke-test
# -------------------------
if __name__ == "__main__":
    np.random.seed(0)
    mcu = MoveConvertUnit(default_VL=8, bf16_rounding=True)

    # INT32 -> BF16
    ints = np.array([1, -3, 256, 1024], dtype=np.int32)
    bf = mcu.int32_to_bf16(ints)
    print("INT32 -> BF16 (quantized):", bf)

    # BF16 -> INT32
    recovered_ints = mcu.bf16_to_int32(bf)
    print("BF16 -> INT32 (trunc):", recovered_ints)

    # Vector extract
    vec = np.linspace(1.0, 8.0, 8).astype(np.float32)
    elem = mcu.vector_extract(vec, 3)
    print("vector_extract index 3:", elem)

    # Scalar broadcast to BF16 vector
    broadcast = mcu.scalar_broadcast_to_vector(5, VL=8)
    print("scalar_broadcast (5) ->", broadcast)