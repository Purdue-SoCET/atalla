"""
vector_lanes_emu.py
Functional emulator for a vector-lane Functional Unit (FU) operating on BF16 vectors.

Style & conventions:
- Single-file, testable module.
- BF16 semantics only (no FP32 support).
- Vector length (VL) default 32. Resource counts parameterized.
- Operations: add, sub, mul, div, exp, sqrt, reductions (sum, max, min).
- When resource count < VL, processing is partitioned into chunks of size `resource_count`
  and executed sequentially to emulate limited parallelism (functional correctness preserved).
"""

import numpy as np
from typing import Callable, Optional

# -------------------------
# BF16 helpers (same semantics as systolic module)
# -------------------------
def bf16_round(x: np.ndarray) -> np.ndarray:
    """
    Round float32 values to nearest BF16 and return as float32 values
    carrying BF16 precision. Tie-to-even rounding.
    """
    x_f32 = x.astype(np.float32)
    u = x_f32.view(np.uint32)
    lsb = (u >> 16) & np.uint32(1)
    add = np.uint32(0x7FFF) + lsb
    u_round = u + add
    u_bf16 = (u_round & np.uint32(0xFFFF0000)).astype(np.uint32)
    return u_bf16.view(np.float32)

def float32_to_bf16_trunc(x: np.ndarray) -> np.ndarray:
    """Truncate float32 to BF16 (no rounding), stored as float32."""
    u = x.astype(np.float32).view(np.uint32)
    u_bf16 = (u & np.uint32(0xFFFF0000)).astype(np.uint32)
    return u_bf16.view(np.float32)

def to_bf16(x: np.ndarray, rounding: bool = True) -> np.ndarray:
    """Convert a numpy array to BF16-emulated float32 values."""
    return bf16_round(x) if rounding else float32_to_bf16_trunc(x)

# -------------------------
# Helper: chunk iterator
# -------------------------
def iterate_chunks(length: int, chunk_size: int):
    """Yield (start, end) pairs that partition [0, length) into chunk_size slices."""
    if chunk_size <= 0:
        raise ValueError("chunk_size must be positive")
    for s in range(0, length, chunk_size):
        yield s, min(s + chunk_size, length)

# -------------------------
# VectorLanes class
# -------------------------
class VectorLanes:
    """
    Functional Vector Lanes emulator.

    Parameters
    ----------
    VL : int
        Vector length (default 32).
    adders : int
        Number of add lanes (default VL).
    multipliers : int
        Number of multiply lanes (default VL).
    dividers : int
        Number of divide lanes (default VL).
    exps : int
        Number of exponential units (default VL).
    sqrts : int
        Number of sqrt units (default VL).
    reducers : int
        Number of elements processed by reduction per step (default VL).
    bf16_rounding : bool
        Whether to use BF16 rounding-to-nearest (True) or truncation (False).
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
        # default resource counts = VL
        self.adders = int(adders) if adders is not None else self.VL
        self.multipliers = int(multipliers) if multipliers is not None else self.VL
        self.dividers = int(dividers) if dividers is not None else self.VL
        self.exps = int(exps) if exps is not None else self.VL
        self.sqrts = int(sqrts) if sqrts is not None else self.VL
        self.reducers = int(reducers) if reducers is not None else self.VL
        self.bf16_rounding = bool(bf16_rounding)

        # sanity
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

    # ---- Internal quantize helpers ----
    def _q(self, x: np.ndarray) -> np.ndarray:
        """Quantize array to BF16-emulated float32 using configured rounding policy."""
        return to_bf16(x.astype(np.float32), rounding=self.bf16_rounding)

    def _ensure_vec(self, v: np.ndarray) -> np.ndarray:
        """Ensure the input is 1D and length == VL (or allow shorter vectors)."""
        arr = np.asarray(v, dtype=np.float32)
        if arr.ndim == 0:
            arr = arr.reshape((1,))
        return arr

    # ---- Element-wise operations ----
    def _elementwise_op(self, a: np.ndarray, b: np.ndarray, op: Callable[[np.ndarray, np.ndarray], np.ndarray], resources: int) -> np.ndarray:
        """
        Generic elementwise op that respects `resources` parallel lanes by processing
        chunks of size `resources`.
        """
        a = self._ensure_vec(a)
        b = self._ensure_vec(b)
        if a.shape != b.shape:
            # allow broadcasting if one is scalar
            if a.size == 1:
                a = np.full_like(b, a.item())
            elif b.size == 1:
                b = np.full_like(a, b.item())
            else:
                raise ValueError("Shapes must match for elementwise op (or one operand scalar)")

        L = a.size
        out = np.empty_like(a, dtype=np.float32)

        # Operands are quantized per-lane before operation to emulate BF16 operand precision
        # We process in chunks of `resources`
        for s, e in iterate_chunks(L, resources):
            a_chunk = self._q(a[s:e])
            b_chunk = self._q(b[s:e])
            # perform op in float32, then quantize result to BF16
            r = op(a_chunk, b_chunk)
            out[s:e] = self._q(r)

        return out

    def add(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        """Element-wise a + b (BF16 semantics)."""
        return self._elementwise_op(a, b, lambda x, y: x + y, self.adders)

    def sub(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        """Element-wise a - b (BF16 semantics)."""
        return self._elementwise_op(a, b, lambda x, y: x - y, self.adders)

    def mul(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        """Element-wise a * b (BF16 semantics)."""
        return self._elementwise_op(a, b, lambda x, y: x * y, self.multipliers)

    def div(self, a: np.ndarray, b: np.ndarray, eps: float = 1e-6) -> np.ndarray:
        """
        Element-wise a / b (BF16 semantics).
        Avoid divide-by-zero by adding a small epsilon to denominator for emulator.
        """
        # define safe divide
        def safe_div(x, y):
            # y may have zeros; add small eps but keep BF16 semantics
            y_safe = np.where(np.abs(y) < eps, np.sign(y) * eps + eps, y)
            return x / y_safe

        return self._elementwise_op(a, b, safe_div, self.dividers)

    def exp(self, a: np.ndarray) -> np.ndarray:
        """Element-wise exponential (BF16 semantics)."""
        a = self._ensure_vec(a)
        L = a.size
        out = np.empty_like(a, dtype=np.float32)
        for s, e in iterate_chunks(L, self.exps):
            a_chunk = self._q(a[s:e])
            r = np.exp(a_chunk.astype(np.float32))
            out[s:e] = self._q(r)
        return out

    def sqrt(self, a: np.ndarray) -> np.ndarray:
        """Element-wise square-root (BF16 semantics)."""
        a = self._ensure_vec(a)
        L = a.size
        out = np.empty_like(a, dtype=np.float32)
        for s, e in iterate_chunks(L, self.sqrts):
            a_chunk = self._q(a[s:e])
            # clip negative inputs to zero for real sqrt behavior (emulator choice)
            a_clip = np.where(a_chunk < 0.0, 0.0, a_chunk)
            r = np.sqrt(a_clip.astype(np.float32))
            out[s:e] = self._q(r)
        return out

    # ---- Reductions ----
    def reduce_sum(self, a: np.ndarray) -> np.ndarray:
        """
        Reduction sum across the vector producing a single BF16 scalar.
        When reducers < VL we reduce in chunks, quantizing partial sums to BF16 every step.
        """
        a = self._ensure_vec(a)
        L = a.size
        # first quantize inputs
        q = self._q(a)
        # process in chunks of size reducers accumulating in BF16 semantics each step
        partial = None
        for s, e in iterate_chunks(L, self.reducers):
            chunk_sum = np.sum(q[s:e].astype(np.float32), dtype=np.float32)
            chunk_sum_q = to_bf16(np.array([chunk_sum]), rounding=self.bf16_rounding)[0]
            if partial is None:
                partial = chunk_sum_q
            else:
                # accumulate in BF16 (quantize both operands then add and quantize)
                partial = to_bf16(np.array([partial + chunk_sum_q]), rounding=self.bf16_rounding)[0]
        return np.array(partial, dtype=np.float32)

    def reduce_max(self, a: np.ndarray) -> np.ndarray:
        """Reduction max across the vector producing a single BF16 scalar."""
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
        """Reduction min across the vector producing a single BF16 scalar."""
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

# -------------------------
# Convenience functional wrapper
# -------------------------
def make_vector_lanes(VL: int = 32, **resources) -> VectorLanes:
    """
    Create a VectorLanes instance with VL and resource overrides provided as keyword args.
    Example: make_vector_lanes(32, adders=16, multipliers=8)
    """
    return VectorLanes(VL=VL, **resources)

# -------------------------
# Quick smoke-test
# -------------------------
if __name__ == "__main__":
    np.random.seed(1)
    VL = 32
    # create FU with fewer multipliers to demonstrate chunking
    vl = make_vector_lanes(VL=VL, adders=32, multipliers=8, dividers=4, exps=8, sqrts=8, reducers=8, bf16_rounding=True)

    a = (np.random.randn(VL) * 0.1).astype(np.float32)
    b = (np.random.randn(VL) * 0.1).astype(np.float32)

    print("add diff vs numpy:", np.max(np.abs(vl.add(a, b) - to_bf16(a + b))))
    print("mul diff vs numpy:", np.max(np.abs(vl.mul(a, b) - to_bf16(a * b))))
    print("div diff vs numpy (safe):", np.max(np.abs(vl.div(a, b) - to_bf16(a / (b + 1e-6)))))
    print("exp diff vs numpy:", np.max(np.abs(vl.exp(a) - to_bf16(np.exp(to_bf16(a))))))
    print("sqrt diff vs numpy:", np.max(np.abs(vl.sqrt(a) - to_bf16(np.sqrt(np.clip(to_bf16(a), 0, None))))))
    print("reduce_sum:", vl.reduce_sum(a))
    print("reduce_max:", vl.reduce_max(a))
    print("reduce_min:", vl.reduce_min(a))
