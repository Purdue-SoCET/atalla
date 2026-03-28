import numpy as np
from typing import Callable, Optional
from .perf_metrics import PerfMetrics

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
        exps: Optional[int] = None,
        sqrts: Optional[int] = None,
        reducers: Optional[int] = None,
        bf16_rounding: bool = True,
        debug: bool = False,
        perf_metrics: Optional[PerfMetrics] = None
    ):
        self.VL = int(VL)
        self.adders = int(adders) if adders is not None else self.VL
        self.multipliers = int(multipliers) if multipliers is not None else self.VL
        self.exps = int(exps) if exps is not None else self.VL
        self.sqrts = int(sqrts) if sqrts is not None else self.VL
        self.reducers = int(reducers) if reducers is not None else self.VL
        self.bf16_rounding = bool(bf16_rounding)
        self.debug = bool(debug)
        self.perf_metrics = perf_metrics if perf_metrics is not None else PerfMetrics()
        
        for name, val in [
            ("VL", self.VL),
            ("adders", self.adders),
            ("multipliers", self.multipliers),
            ("exps", self.exps),
            ("sqrts", self.sqrts),
            ("reducers", self.reducers),
        ]:
            if val <= 0:
                raise ValueError(f"{name} must be positive integer")

    def reset_flops(self):
        self.perf_metrics.set_metric("flops_vector", 0)

    def _count_flops(self, work_items: int) -> None:
        flop_inc = int(max(0, work_items))
        self.perf_metrics.increment("flops_vector", flop_inc)
        self.perf_metrics.increment("flops_total", flop_inc)

    @property
    def flops(self) -> int:
        return int(self.perf_metrics.get_metric("flops_vector", 0))

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
        self._count_flops(L)
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

    def div(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        return self._elementwise_op(a, b, lambda x, y: np.where(y != 0, x / y, 0.0), self.multipliers)

    def exp(self, a: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        L = a.size
        self._count_flops(L)
        out = np.empty_like(a, dtype=np.float32)
        for s, e in iterate_chunks(L, self.exps):
            a_chunk = self._q(a[s:e])
            r = np.exp(a_chunk.astype(np.float32))
            out[s:e] = self._q(r)
        return out

    def sqrt(self, a: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        L = a.size
        self._count_flops(L)
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

    def div_scalar(self, a: np.ndarray, s: float) -> np.ndarray:
        return self._elementwise_op(a, np.array([s], dtype=np.float32),
                                    lambda x, y: np.where(y != 0, x / y, 0.0), self.multipliers)

    # --------------------------------------------------------
    # Vector << scalar   and   Vector >> scalar (logical shifts)
    # --------------------------------------------------------
    def shl_scalar(self, a: np.ndarray, s: int) -> np.ndarray:
        a = self._ensure_vec(a)
        shift = int(s)

        if shift < 0:
            return self.shr_scalar(a, -shift)

        out = np.zeros_like(a)

        lane_n = a.shape[-1]
        if shift == 0:
            out[...] = a
            return out
        if shift >= lane_n:
            return out

        # "left" = toward lower lane indices (index decreases)
        out[..., :-shift] = a[..., shift:]
        return out


    def shr_scalar(self, a: np.ndarray, s: int) -> np.ndarray:
        a = self._ensure_vec(a)
        shift = int(s)

        if shift < 0:
            return self.shl_scalar(a, -shift)

        out = np.zeros_like(a)

        lane_n = a.shape[-1]
        if shift == 0:
            out[...] = a
            return out
        if shift >= lane_n:
            return out

        # "right" = toward higher lane indices (index increases)
        out[..., shift:] = a[..., :-shift]
        return out



    
    # --------------------------------------------------------
    # Vector–Vector comparison ops
    # Output: BF16 1.0 (true) or 0.0 (false)
    # --------------------------------------------------------
    def cmp_gt(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        b = self._ensure_vec(b)
        self._count_flops(a.size)
        mask = (a > b).astype(np.float32)
        return self._q(mask)

    def cmp_lt(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        b = self._ensure_vec(b)
        self._count_flops(a.size)
        mask = (a < b).astype(np.float32)
        return self._q(mask)

    def cmp_eq(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        b = self._ensure_vec(b)
        self._count_flops(a.size)
        mask = (a == b).astype(np.float32)
        return self._q(mask)

    def cmp_neq(self, a: np.ndarray, b: np.ndarray) -> np.ndarray:
        a = self._ensure_vec(a)
        b = self._ensure_vec(b)
        self._count_flops(a.size)
        mask = (a != b).astype(np.float32)
        return self._q(mask)
    

    # --------------------------------------------------------
    # Vector–Scalar comparison ops (VS)
    # Output: BF16 1.0 (true) or 0.0 (false)
    # --------------------------------------------------------
    def cmp_gt_vs(self, a: np.ndarray, rs1) -> np.ndarray:
        a = self._ensure_vec(a)
        rs1 = np.float32(rs1)
        self._count_flops(a.size)
        mask = (a > rs1).astype(np.float32)
        return self._q(mask)

    def cmp_lt_vs(self, a: np.ndarray, rs1) -> np.ndarray:
        a = self._ensure_vec(a)
        rs1 = np.float32(rs1)
        self._count_flops(a.size)
        mask = (a < rs1).astype(np.float32)
        return self._q(mask)

    def cmp_eq_vs(self, a: np.ndarray, rs1) -> np.ndarray:
        a = self._ensure_vec(a)
        rs1 = np.float32(rs1)
        self._count_flops(a.size)
        mask = (a == rs1).astype(np.float32)
        return self._q(mask)

    def cmp_neq_vs(self, a: np.ndarray, rs1) -> np.ndarray:
        a = self._ensure_vec(a)
        rs1 = np.float32(rs1)
        self._count_flops(a.size)
        mask = (a != rs1).astype(np.float32)
        return self._q(mask)


    # ---- reductions ----
    def _bit_is_set(self, mask: int, i: int) -> bool:
        if self.debug: print(((int(mask) >> i) & 1) == 1)
        return ((int(mask) >> i) & 1) == 1


    def reduce_sum(self, a: np.ndarray, mask: int) -> np.ndarray:
        a = self._ensure_vec(a)
        q = self._q(a).astype(np.float32, copy=False)
        L = q.size
        self._count_flops(L)
        R = int(self.reducers)

        if R <= 0:
            raise ValueError(f"reducers must be > 0, got {R}")

        # treat mask as unsigned so negatives don't sign-extend
        mask_u = int(mask) & ((1 << min(R, 32)) - 1) if R < 32 else (int(mask) & 0xFFFFFFFF)

        partial = np.float32(0.0)
        enabled_any = False

        # Split [0, L) into R nearly-equal contiguous chunks
        for step in range(R):
            if ((mask_u >> step) & 1) == 0:
                continue

            s = (step * L) // R
            e = ((step + 1) * L) // R
            if s >= e:  # happens if R > L
                continue

            partial += np.sum(q[s:e], dtype=np.float32)
            enabled_any = True

        return np.array(partial if enabled_any else 0.0, dtype=np.float32)


    def reduce_max(self, a: np.ndarray, mask: int) -> np.ndarray:
        a = self._ensure_vec(a)
        q = self._q(a).astype(np.float32, copy=False)
        L = q.size
        self._count_flops(L)
        R = int(self.reducers)

        if R <= 0:
            raise ValueError(f"reducers must be > 0, got {R}")

        # treat mask as unsigned so negatives don't sign-extend
        mask_u = int(mask) & ((1 << min(R, 32)) - 1) if R < 32 else (int(mask) & 0xFFFFFFFF)

        cur = -np.inf
        enabled_any = False

        for step in range(R):
            if ((mask_u >> step) & 1) == 0:
                continue

            s = (step * L) // R
            e = ((step + 1) * L) // R
            if s >= e:  # can happen if R > L
                continue

            chunk_max = float(np.max(q[s:e]))
            if chunk_max > cur:
                cur = chunk_max
            enabled_any = True

        return np.array(cur if enabled_any else -np.inf, dtype=np.float32)


    def reduce_min(self, a: np.ndarray, mask: int) -> np.ndarray:
        a = self._ensure_vec(a)
        q = self._q(a).astype(np.float32, copy=False)
        L = q.size
        self._count_flops(L)
        R = int(self.reducers)

        if R <= 0:
            raise ValueError(f"reducers must be > 0, got {R}")

        # treat mask as unsigned so negatives don't sign-extend
        mask_u = int(mask) & ((1 << min(R, 32)) - 1) if R < 32 else (int(mask) & 0xFFFFFFFF)

        cur = np.inf
        enabled_any = False

        for step in range(R):
            if ((mask_u >> step) & 1) == 0:
                continue

            s = (step * L) // R
            e = ((step + 1) * L) // R
            if s >= e:  # can happen if R > L
                continue

            chunk_min = float(np.min(q[s:e]))
            if chunk_min < cur:
                cur = chunk_min
            enabled_any = True

        return np.array(cur if enabled_any else np.inf, dtype=np.float32)


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
        self._count_flops(L)
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
    # Unified dispatch interface
    # -------------------------
    def execute(self, op: str, vA=None, vB=None, sA=None, slr=None, mask=None):
        new_op = op[:op.rfind(".")]
        type = op[op.rfind("."):]
        if(type == ".vv" or type == ".mvv"):
            if new_op == "add":           return self.add(vA, vB)
            if new_op == "sub":           return self.sub(vA, vB)
            if new_op == "mul":           return self.mul(vA, vB)
            if new_op == "div":           return self.div(vA, vB)
            if new_op == "and":        return self.bitwise_and(vA, vB)
            if new_op == "or":         return self.bitwise_or(vA, vB)
            if new_op == "xor":        return self.bitwise_xor(vA, vB)
            if new_op == "not":        return self.bitwise_not(vA)
            if new_op == "mgt":        return self.cmp_gt(vA, vB)
            if new_op == "mlt":        return self.cmp_lt(vA, vB)
            if new_op == "meq":        return self.cmp_eq(vA, vB)
            if new_op == "mneq":       return self.cmp_neq(vA, vB)
            else:
                raise ValueError(f"Unknown vector op '{new_op}'")
        elif(type == ".vi"):
            if new_op == "addi":    return self.add_scalar(vA, sA)
            if new_op == "subi":    return self.sub_scalar(vA, sA)
            #if new_op == "scalar_sub":    return self.scalar_sub(sA, vA)
            if new_op == "muli":    return self.mul_scalar(vA, sA)
            #if new_op == "scalar_div":    return self.scalar_div(sA, vA)
            if new_op == "expi":           return self.exp(vA)
            if new_op == "sqrti":          return self.sqrt(vA)
            if new_op == "not":        return self.bitwise_not(vA)
            if new_op == "shift":    
                if(slr):
                    return self.shr_scalar(vA, int(sA))
                else:
                    return self.shl_scalar(vA, int(sA))
            if new_op == "rsum":    return self.reduce_sum(vA, mask=mask)
            if new_op == "rmin":    return self.reduce_min(vA, mask=mask)
            if new_op == "rmax":    return self.reduce_max(vA, mask=mask)
            else:
                raise ValueError(f"Unknown vector op '{new_op}'")
        elif(type == ".vs" or type == ".mvs"):
            if new_op == "shift":    
                if(slr):
                    return self.shr_scalar(vA, int(sA))
                else:
                    return self.shl_scalar(vA, int(sA))
            if new_op == "add":    return self.add_scalar(vA, sA)
            if new_op == "sub":    return self.sub_scalar(vA, sA)
            if new_op == "mul":    return self.mul(vA, sA)
            if new_op == "div":    return self.div_scalar(vA, sA)
            if new_op == "mgt":        return self.cmp_gt_vs(vA, sA)
            if new_op == "mlt":        return self.cmp_lt_vs(vA, sA)
            if new_op == "meq":        return self.cmp_eq_vs(vA, sA)
            if new_op == "mneq":       return self.cmp_neq_vs(vA, sA)
            else:
                raise ValueError(f"Unknown vector op '{new_op}'")
        else:
            raise ValueError(f"Unknown vector type '{type}'")

# -------------------------
# Convenience functional wrapper
# -------------------------
def make_vector_lanes(VL: int = 32, **resources) -> VectorLanes:
    return VectorLanes(VL=VL, **resources)

# -------------------------
# Quick smoke-test
# -------------------------
if __name__ == "__main__":
    VL = 8
    V = VectorLanes(VL=VL)

    # test vectors
    vA = np.array([1, 2, 3, 4, 5, 6, 7, 8], dtype=np.float32)
    vB = np.array([8, 7, 6, 5, 4, 3, 2, 1], dtype=np.float32)
    s  = 3.0

    print("===== VECTOR–VECTOR ARITHMETIC =====")
    print("add        =", V.execute("add", vA=vA, vB=vB))
    print("sub        =", V.execute("sub", vA=vA, vB=vB))
    print("mul        =", V.execute("mul", vA=vA, vB=vB))

    print("\n===== VECTOR–SCALAR ARITHMETIC =====")
    print("add_scalar =", V.execute("add_scalar", vA=vA, sA=s))
    print("sub_scalar =", V.execute("sub_scalar", vA=vA, sA=s))
    print("scalar_sub =", V.execute("scalar_sub", vA=vA, sA=s))
    print("mul_scalar =", V.execute("mul_scalar", vA=vA, sA=s))

    print("\n===== BITWISE OPS (BF16 bit-level) =====")
    print("bw_and     =", V.execute("bw_and", vA=vA, vB=vB))
    print("bw_or      =", V.execute("bw_or",  vA=vA, vB=vB))
    print("bw_xor     =", V.execute("bw_xor", vA=vA, vB=vB))
    print("bw_not     =", V.execute("bw_not", vA=vA))

    print("\n===== SHIFTS (on BF16 bit patterns) =====")
    print("shl_scalar =", V.execute("shl_scalar", vA=vA, sA=1))
    print("shr_scalar =", V.execute("shr_scalar", vA=vA, sA=1))

    print("\n===== COMPARISONS =====")
    print("cmp_gt     =", V.execute("cmp_gt",  vA=vA, vB=vB))
    print("cmp_lt     =", V.execute("cmp_lt",  vA=vA, vB=vB))
    print("cmp_eq     =", V.execute("cmp_eq",  vA=vA, vB=vA))
    print("cmp_neq    =", V.execute("cmp_neq", vA=vA, vB=vA))

    print("\n===== REDUCTIONS =====")
    print("reduce_sum =", V.execute("reduce_sum", vA=vA))
    print("reduce_min =", V.execute("reduce_min", vA=vA))
    print("reduce_max =", V.execute("reduce_max", vA=vA))

    print("\n===== EXP & SQRT =====")
    print("exp        =", V.execute("exp", vA=vA))
    print("sqrt       =", V.execute("sqrt", vA=vA))

    print("\n===== ALL TESTS COMPLETED =====")
