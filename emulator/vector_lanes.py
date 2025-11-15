"""
vector_lanes_emu.py
Functional emulator for a vector-lane Functional Unit (FU) operating on BF16 vectors.

BF16 bitwise ops operate on the underlying BF16 bit-patterns (uint16), per Option A.
"""

import numpy as np
from typing import Callable, Optional

# -------------------------
# BF16 helpers (same semantics as systolic module)
# -------------------------
def bf16_round(x: np.ndarray) -> np.ndarray:
    x_f32 = x.astype(np.float32)
    u = x_f32.view(np.uint32)
    lsb = (u >> 16) & np.uint32(1)
    add = np.uint32(0x7FFF) + lsb
    u_round = u + add
    u_bf16 = (u_round & np.uint32(0xFFFF0000)).astype(np.uint32)
    return u_bf16.view(np.float32)

def float32_to_bf16_trunc(x: np.ndarray) -> np.ndarray:
    u = x.astype(np.float32).view(np.uint32)
    u_bf16 = (u & np.uint32(0xFFFF0000)).astype(np.uint32)
    return u_bf16.view(np.float32)

def to_bf16(x: np.ndarray, rounding: bool = True) -> np.ndarray:
    return bf16_round(x) if rounding else float32_to_bf16_trunc(x)

# Helpers to extract and rebuild BF16 bit patterns
def bf16_to_uint16_bits(x: np.ndarray) -> np.ndarray:
    """
    Convert BF16-emulated float32 array to uint16 array representing BF16 raw bits.
    (Take top 16 bits of the float32 bitpattern.)
    """
    u32 = x.astype(np.float32).view(np.uint32)
    u16 = (u32 >> np.uint32(16)).astype(np.uint16)
    return u16

def uint16_bits_to_bf16(bits: np.ndarray) -> np.ndarray:
    """
    Convert uint16-bit BF16 raw bit patterns to BF16-emulated float32 values.
    (Place bits in top 16 bits of a uint32 and view as float32.)
    """
    bits_u16 = bits.astype(np.uint16)
    u32 = (bits_u16.astype(np.uint32) << np.uint32(16)).astype(np.uint32)
    return u32.view(np.float32)

# -------------------------
# Helper: chunk iterator
# -------------------------
def iterate_chunks(length: int, chunk_size: int):
    if chunk_size <= 0:
        raise ValueError("chunk_size must be positive")
    for s in range(0, length, chunk_size):
        yield s, min(s + chunk_size, length)

# -------------------------
# VectorLanes class
# -------------------------
class VectorLanes:
    """
    Functional Vector Lanes emulator with BF16 semantics.
    """

    def __init__(
        self,
        VL: int = 32,
        adders: Optional[int] = None,
        multipliers: Optional[int] = None,
        dividers: Optional[int] = None,
        exps: Optional[int] = None,
        sqrts: Optional[int] = None,
        reducers: Optional[int] = None,
        bf16_rounding: bool = True,
    ):
        self.VL = int(VL)
        self.adders = int(adders) if adders is not None else self.VL
        self.multipliers = int(multipliers) if multipliers is not None else self.VL
        self.dividers = int(dividers) if dividers is not None else self.VL
        self.exps = int(exps) if exps is not None else self.VL
        self.sqrts = int(sqrts) if sqrts is not None else self.VL
        self.reducers = int(reducers) if reducers is not None else self.VL
        self.bf16_rounding = bool(bf16_rounding)

        for name, val in [
            ("VL", self.VL),
            ("adders", self.adders),
            ("multipliers", self.multipliers),
            ("dividers", self.dividers),
            ("exps", self.exps),
            ("sqrts", self.sqrts),
            ("reducers", self.reducers),
        ]:
            if val <= 0:
                raise ValueError(f"{name} must be positive integer")

    def _q(self, x: np.ndarray) -> np.ndarray:
        return to_bf16(x.astype(np.float32), rounding=self.bf16_rounding)

    def _ensure_vec(self, v: np.ndarray) -> np.ndarray:
        arr = np.asarray(v, dtype=np.float32)
        if arr.ndim == 0:
            arr = arr.reshape((1,))
        return arr

    def _elementwise_op(self, a: np.ndarray, b: np.ndarray, op: Callable[[np.ndarray, np.ndarray], np.ndarray], resources: int) -> np.ndarray:
        a = self._ensure_vec(a)
        b = self._ensure_vec(b)
        if a.shape != b.shape:
            if a.size == 1:
                a = np.full_like(b, a.item())
            elif b.size == 1:
                b = np.full_like(a, b.item())
            else:
                raise ValueError("Shapes must match for elementwise op (or one operand scalar)")

        L = a.size
        out = np.empty_like(a, dtype=np.float32)

        for s, e in iterate_chunks(L, resources):
            a_chunk = self._q(a[s:e])
            b_chunk = self._q(b[s:e])
            r = op(a_chunk, b_chunk)
            out[s:e] = self._q(r)

        return out

    # ---- arithmetic ops ----
    def add(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        return self._elementwise_op(a, b, lambda x, y: x + y, self.adders)

    def sub(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        return self._elementwise_op(a, b, lambda x, y: x - y, self.adders)

    def mul(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        return self._elementwise_op(a, b, lambda x, y: x * y, self.multipliers)

    def div(self, a: np.ndarray, b: np.ndarray, eps: float = 1e-6) -> np.ndarray:
        def safe_div(x, y):
            y_safe = np.where(np.abs(y) < eps, np.sign(y) * eps + eps, y)
            return x / y_safe
        return self._elementwise_op(a, b, safe_div, self.dividers)

    def exp(self, a: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        L = a.size
        out = np.empty_like(a, dtype=np.float32)
        for s, e in iterate_chunks(L, self.exps):
            a_chunk = self._q(a[s:e])
            r = np.exp(a_chunk.astype(np.float32))
            out[s:e] = self._q(r)
        return out

    def sqrt(self, a: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        L = a.size
        out = np.empty_like(a, dtype=np.float32)
        for s, e in iterate_chunks(L, self.sqrts):
            a_chunk = self._q(a[s:e])
            a_clip = np.where(a_chunk < 0.0, 0.0, a_chunk)
            r = np.sqrt(a_clip.astype(np.float32))
            out[s:e] = self._q(r)
        return out
    
    def add_scalar(self, a: np.ndarray, s: float) -> np.ndarray:
        return self._elementwise_op(a, np.array([s], dtype=np.float32),
                                    lambda x, y: x + y, self.adders)

    def sub_scalar(self, a: np.ndarray, s: float) -> np.ndarray:
        # elementwise: a - s
        return self._elementwise_op(a, np.array([s], dtype=np.float32),
                                    lambda x, y: x - y, self.adders)

    def scalar_sub(self, s: float, a: np.ndarray) -> np.ndarray:
        # scalar - vector
        return self._elementwise_op(np.array([s], dtype=np.float32), a,
                                    lambda x, y: x - y, self.adders)

    def mul_scalar(self, a: np.ndarray, s: float) -> np.ndarray:
        return self._elementwise_op(a, np.array([s], dtype=np.float32),
                                    lambda x, y: x * y, self.multipliers)

    def div_scalar(self, a: np.ndarray, s: float, eps: float = 1e-6) -> np.ndarray:
        # a / s
        return self._elementwise_op(a, np.array([s], dtype=np.float32),
                                    lambda x, y: x / (np.where(np.abs(y) < eps,
                                                               np.sign(y)*eps + eps, y)),
                                    self.dividers)

    def scalar_div(self, s: float, a: np.ndarray, eps: float = 1e-6) -> np.ndarray:
        # s / a
        return self._elementwise_op(np.array([s], dtype=np.float32), a,
                                    lambda x, y: x / (np.where(np.abs(y) < eps,
                                                               np.sign(y)*eps + eps, y)),
                                    self.dividers)

    # --------------------------------------------------------
    # Vector << scalar   and   Vector >> scalar (logical shifts)
    # --------------------------------------------------------
    def shl_scalar(self, a: np.ndarray, s: int) -> np.ndarray:
        a = self._ensure_vec(a)
        out = np.empty_like(a, dtype=np.float32)

        for start, end in iterate_chunks(a.size, self.adders):
            a_chunk = self._q(a[start:end])
            bits = bf16_to_uint16_bits(a_chunk)
            shifted = (bits.astype(np.uint16) << np.uint16(s)).astype(np.uint16)
            out[start:end] = uint16_bits_to_bf16(shifted)

        return out

    def shr_scalar(self, a: np.ndarray, s: int) -> np.ndarray:
        a = self._ensure_vec(a)
        out = np.empty_like(a, dtype=np.float32)

        for start, end in iterate_chunks(a.size, self.adders):
            a_chunk = self._q(a[start:end])
            bits = bf16_to_uint16_bits(a_chunk)
            shifted = (bits.astype(np.uint16) >> np.uint16(s)).astype(np.uint16)
            out[start:end] = uint16_bits_to_bf16(shifted)

        return out
    
    # --------------------------------------------------------
    # Vector–Vector comparison ops
    # Output: BF16 1.0 (true) or 0.0 (false)
    # --------------------------------------------------------
    def cmp_gt(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        b = self._ensure_vec(b)
        mask = (a > b).astype(np.float32)
        return self._q(mask)

    def cmp_lt(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        b = self._ensure_vec(b)
        mask = (a < b).astype(np.float32)
        return self._q(mask)

    def cmp_eq(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        b = self._ensure_vec(b)
        mask = (a == b).astype(np.float32)
        return self._q(mask)

    def cmp_neq(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        b = self._ensure_vec(b)
        mask = (a != b).astype(np.float32)
        return self._q(mask)

    # ---- reductions ----
    def reduce_sum(self, a: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        L = a.size
        q = self._q(a)
        partial = None
        for s, e in iterate_chunks(L, self.reducers):
            chunk_sum = np.sum(q[s:e].astype(np.float32), dtype=np.float32)
            chunk_sum_q = to_bf16(np.array([chunk_sum]), rounding=self.bf16_rounding)[0]
            if partial is None:
                partial = chunk_sum_q
            else:
                partial = to_bf16(np.array([partial + chunk_sum_q]), rounding=self.bf16_rounding)[0]
        return np.array(partial, dtype=np.float32)

    def reduce_max(self, a: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        q = self._q(a)
        cur = None
        for s, e in iterate_chunks(q.size, self.reducers):
            chunk_max = np.max(q[s:e].astype(np.float32))
            chunk_max_q = to_bf16(np.array([chunk_max]), rounding=self.bf16_rounding)[0]
            if cur is None:
                cur = chunk_max_q
            else:
                cur = to_bf16(np.array([max(cur, chunk_max_q)]), rounding=self.bf16_rounding)[0]
        return np.array(cur, dtype=np.float32)

    def reduce_min(self, a: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        q = self._q(a)
        cur = None
        for s, e in iterate_chunks(q.size, self.reducers):
            chunk_min = np.min(q[s:e].astype(np.float32))
            chunk_min_q = to_bf16(np.array([chunk_min]), rounding=self.bf16_rounding)[0]
            if cur is None:
                cur = chunk_min_q
            else:
                cur = to_bf16(np.array([min(cur, chunk_min_q)]), rounding=self.bf16_rounding)[0]
        return np.array(cur, dtype=np.float32)

    # ---- BF16 bitwise ops on underlying BF16 bit-patterns ----
    def _bitwise_elementwise(self, a: np.ndarray, b: Optional[np.ndarray], op_bits: Callable[[np.ndarray, np.ndarray], np.ndarray], resources: int) -> np.ndarray:
        """
        Generic elementwise bitwise op that works on BF16 raw 16-bit patterns.
        If b is None (unary op like NOT), it applies op_bits to single-input (b not used).
        """
        a = self._ensure_vec(a)
        if b is None:
            b = np.zeros_like(a, dtype=np.float32)  # placeholder ignored by op_bits for unary where not needed
        else:
            b = self._ensure_vec(b)

        if a.shape != b.shape:
            if a.size == 1:
                a = np.full_like(b, a.item())
            elif b.size == 1:
                b = np.full_like(a, b.item())
            else:
                raise ValueError("Shapes must match for bitwise op (or one operand scalar)")

        L = a.size
        out = np.empty_like(a, dtype=np.float32)

        for s, e in iterate_chunks(L, resources):
            a_chunk = self._q(a[s:e])
            b_chunk = self._q(b[s:e]) if b is not None else None

            a_bits = bf16_to_uint16_bits(a_chunk)
            b_bits = bf16_to_uint16_bits(b_chunk) if b is not None else None

            if b_bits is None:
                res_bits = op_bits(a_bits, None)
            else:
                res_bits = op_bits(a_bits, b_bits)

            out[s:e] = uint16_bits_to_bf16(res_bits)

        return out

    def bitwise_and(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        return self._bitwise_elementwise(a, b, lambda x, y: np.bitwise_and(x, y), self.adders)

    def bitwise_or(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        return self._bitwise_elementwise(a, b, lambda x, y: np.bitwise_or(x, y), self.adders)

    def bitwise_xor(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        return self._bitwise_elementwise(a, b, lambda x, y: np.bitwise_xor(x, y), self.adders)

    def bitwise_not(self, a: np.ndarray) -> np.ndarray:
        return self._bitwise_elementwise(a, None, lambda x, _: np.bitwise_not(x), self.adders)

# -------------------------
# Convenience functional wrapper
# -------------------------
def make_vector_lanes(VL: int = 32, **resources) -> VectorLanes:
    return VectorLanes(VL=VL, **resources)

# -------------------------
# Quick smoke-test
# -------------------------
if __name__ == "__main__":
    np.random.seed(1)
    VL = 8
    vl = make_vector_lanes(VL=VL, adders=4, multipliers=4, dividers=4, exps=4, sqrts=4, reducers=4, bf16_rounding=True)

    a = (np.random.randn(VL) * 0.1).astype(np.float32)
    b = (np.random.randn(VL) * 0.1).astype(np.float32)

    print("add diff vs numpy:", np.max(np.abs(vl.add(a, b) - to_bf16(a + b))))
    print("bitwise_and bits (raw):", bf16_to_uint16_bits(vl.bitwise_and(a, b)))
    print("bitwise_not bits (raw):", bf16_to_uint16_bits(vl.bitwise_not(a)))