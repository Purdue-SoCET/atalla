import numpy as np
import struct

# BF16 helpers (simulate bf16 by truncating float32 mantissa)
def float32_to_bf16_array(x: np.ndarray) -> np.ndarray:
    """Convert float32 numpy array to simulated bf16 stored as float32 values
    (i.e., values rounded/truncated to BF16 precision but stored in float32 dtype)."""
    x_f32 = x.astype(np.float32)
    # view as uint32, zero lower 16 bits of mantissa (rounding towards nearest even not implemented; using truncation)
    u = x_f32.view(np.uint32)
    # Keep sign(1) exponent(8) top 7 mantissa bits => top 16 bits preserved
    u_bf16 = (u & 0xFFFF0000).astype(np.uint32)
    # reinterpret as float32 (this gives a float32 with bf16 precision)
    return u_bf16.view(np.float32)

def bf16_round(x: np.ndarray) -> np.ndarray:
    """Round to nearest BF16 (implementing round-to-nearest-even)."""
    # Add 0x00007FFF + ((u >> 16) & 1) for tie-to-even rounding then zero lower 16 bits.
    x_f32 = x.astype(np.float32)
    u = x_f32.view(np.uint32)
    lsb = (u >> 16) & 1
    add = np.uint32(0x7FFF) + lsb
    u_round = u + add
    u_bf16 = (u_round & 0xFFFF0000).astype(np.uint32)
    return u_bf16.view(np.float32)

def to_bf16(x: np.ndarray, rounding=True) -> np.ndarray:
    return bf16_round(x) if rounding else float32_to_bf16_array(x)

# Systolic array (A and B inputs, C output)
def systolic_mm(A: np.ndarray, B: np.ndarray, tile=32, bf16_rounding=True):
    """
    Multiply A @ B using a functional 32x32 systolic-array style tiling.
    - A: (M, K)
    - B: (K, N)
    - tile: PE array size (32)
    Returns: C (M, N) using simulated BF16 arithmetic inside the systolic tiles,
             accumulating in BF16 (partial sums stored in BF16-emulated float32)
    Emulates: PEs store weight tile (B_tile).
    MAC done in BF16 precision (i.e., operands are cast to bf16, multiply
    in float32 but operands truncated to bf16 first, and result truncated back to bf16
    after accumulation step).
    """
    M, K = A.shape
    K2, N = B.shape
    assert K == K2, "Inner dimensions must match"

    # Output
    C = np.zeros((M, N), dtype=np.float32)

    # We'll process output in tiles of (tile x tile)
    for i0 in range(0, M, tile):
        i1 = min(i0 + tile, M)
        for j0 in range(0, N, tile):
            j1 = min(j0 + tile, N)
            # initialize partial sums for this output tile (shape: (i1-i0, j1-j0))
            psum = np.zeros((i1 - i0, j1 - j0), dtype=np.float32)
            # Tile over K (the reduction dimension), streaming 1 activation-vector of length tile each time
            for k0 in range(0, K, tile):
                k1 = min(k0 + tile, K)

                # Load weight tile into PEs (B_tile stored inside PEs)
                # B_tile shape: (k1-k0, j1-j0) — weights along K x output_cols
                B_tile = B[k0:k1, j0:j1].astype(np.float32)
                B_tile_bf16 = to_bf16(B_tile, rounding=bf16_rounding)

                # For each row in A tile (i0:i1), we stream A values across the k-block
                A_block = A[i0:i1, k0:k1].astype(np.float32)
                A_block_bf16 = to_bf16(A_block, rounding=bf16_rounding)
                # Contribution of this Kth block: psum += A_block @ B_tile

                # Local product
                local_prod = A_block_bf16 @ B_tile_bf16  # shape (i1-i0, j1-j0)

                # Accumulation: add local product to psum
                local_prod_bf16 = to_bf16(local_prod, rounding=bf16_rounding)
                psum_bf16 = to_bf16(psum, rounding=bf16_rounding)
                psum = to_bf16(psum_bf16 + local_prod_bf16, rounding=bf16_rounding)

            # write back tile
            C[i0:i1, j0:j1] = psum

    return C

# --- Small test to check ---
#if __name__ == "__main__":
#    np.random.seed(42)
#    M, K, N = 96, 128, 80  # arbitrary sizes (not necessarily multiples of 32)
#    A = (np.random.randn(M, K) * 0.1).astype(np.float32)
#    B = (np.random.randn(K, N) * 0.1).astype(np.float32)
#
#    C_syst = systolic_mm(A, B, tile=32, bf16_rounding=True)
#    # For baseline, emulate BF16 by quantizing inputs and computing matmul in float32
#    A_bf16 = to_bf16(A)
#    B_bf16 = to_bf16(B)
#    C_baseline = to_bf16(A_bf16 @ B_bf16)

#   # Compare
#    diff = np.max(np.abs(C_syst - C_baseline))
#    print("Max abs difference vs baseline BF16 matmul:", diff)
#    print("Max abs difference vs full float32 matmul:", np.max(np.abs(C_syst - (A @ B))))
