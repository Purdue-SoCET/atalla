"""
systolic_array_emu.py
Functional 2D systolic-array style matrix multiply emulator (BF16 semantics).
Consistent module style for hardware functional emulation framework.
"""

import numpy as np
from typing import Tuple

# -------------------------
# BF16 helpers
# -------------------------
def bf16_round(x: np.ndarray) -> np.ndarray:
    """
    Round float32 values to nearest BF16 and return as float32 values
    carrying BF16 precision. Uses tie-to-even rounding.
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
    """Convert float32 ndarray to BF16-emulated float32 ndarray."""
    return bf16_round(x) if rounding else float32_to_bf16_trunc(x)

# -------------------------
# SystolicArray class
# -------------------------
class SystolicArray:
    """
    Functional emulator for a 2D systolic array used for matrix multiply.

    - size: tile dimension (e.g., 32)
    - bf16_rounding: whether BF16 conversion uses rounding-to-nearest-even (True) or truncation (False)
    - Accumulation is always performed in BF16 precision
    """

    def __init__(self, size: int = 32, bf16_rounding: bool = True):
        self.size = int(size)
        self.bf16_rounding = bool(bf16_rounding)

    def _quantize_weights(self, B_tile: np.ndarray) -> np.ndarray:
        """Quantize weight tile into BF16 semantics (stored as float32)."""
        return to_bf16(B_tile.astype(np.float32), rounding=self.bf16_rounding)

    def _quantize_activations(self, A_block: np.ndarray) -> np.ndarray:
        """Quantize activation block into BF16 semantics (stored as float32)."""
        return to_bf16(A_block.astype(np.float32), rounding=self.bf16_rounding)

    def compute_tile(self, A_tile: np.ndarray, B_tile: np.ndarray) -> np.ndarray:
        """
        Compute product of A_tile (m x k) and B_tile (k x n) with BF16 semantics.
        Returns C_tile (m x n), accumulated in BF16 precision.
        """
        m, k1 = A_tile.shape
        k2, n = B_tile.shape
        assert k1 == k2, "K dimension mismatch"

        A_q = self._quantize_activations(A_tile)
        B_q = self._quantize_weights(B_tile)

        # Multiply and quantize result to BF16
        local = A_q @ B_q
        return to_bf16(local, rounding=self.bf16_rounding)

    def matmul(self, A: np.ndarray, B: np.ndarray) -> np.ndarray:
        """
        Full matrix multiply using systolic tiling.
        - A: (M, K)
        - B: (K, N)
        Returns C: (M, N) accumulated in BF16 precision.
        """
        M, K = A.shape
        K2, N = B.shape
        assert K == K2

        C = np.zeros((M, N), dtype=np.float32)
        t = self.size

        for i0 in range(0, M, t):
            i1 = min(i0 + t, M)
            for j0 in range(0, N, t):
                j1 = min(j0 + t, N)
                psum = np.zeros((i1 - i0, j1 - j0), dtype=np.float32)

                for k0 in range(0, K, t):
                    k1 = min(k0 + t, K)
                    A_blk = A[i0:i1, k0:k1].astype(np.float32)
                    B_blk = B[k0:k1, j0:j1].astype(np.float32)

                    C_contrib = self.compute_tile(A_blk, B_blk)
                    psum_q = to_bf16(psum, rounding=self.bf16_rounding)
                    psum = to_bf16(psum_q + C_contrib, rounding=self.bf16_rounding)

                C[i0:i1, j0:j1] = psum

        return C

# -------------------------
# Functional wrapper
# -------------------------
def systolic_mm(A: np.ndarray, B: np.ndarray, size: int = 32, bf16_rounding: bool = True) -> np.ndarray:
    """
    Convenience wrapper: perform matrix multiply A @ B using SystolicArray emulator.
    """
    sa = SystolicArray(size=size, bf16_rounding=bf16_rounding)
    return sa.matmul(A, B)

# -------------------------
# Quick smoke-test
# -------------------------
if __name__ == "__main__":
    np.random.seed(0)
    M, K, N = 64, 96, 48
    A = (np.random.randn(M, K) * 0.05).astype(np.float32)
    B = (np.random.randn(K, N) * 0.05).astype(np.float32)

    C_sa = systolic_mm(A, B, size=32, bf16_rounding=True)
    # baseline: quantize inputs, multiply, quantize final
    A_q = to_bf16(A)
    B_q = to_bf16(B)
    C_baseline = to_bf16(A_q @ B_q)

    print("max abs diff vs baseline:", float(np.max(np.abs(C_sa - C_baseline))))
    print("max abs diff vs float32 matmul:", float(np.max(np.abs(C_sa - (A @ B)))))
