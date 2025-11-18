#include "conv_lib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// --- Hardware/Tiling Constants ---
#define SA_TM 32 // Systolic Array Height (Max output patches, M dim)
#define SA_TN 32 // Systolic Array Width (Max kernels, N dim)
#define SA_TK 32 // Systolic Array Reduction Dim (Max flat kernel chunk, K dim)

// Assuming a 30x30 output tile (O_T) from a 3x3 kernel (K=3, S=1), 
// the required input tile size T is T = O_T * S + K - 1 = 30*1 + 3 - 1 = 32.
// We set a safe maximum spatial tile size to support the largest possible required input
#define MAX_SPATIAL_TILE_DIM 64 

/*
================================================================================
 LEVEL 1: Kernel Flattening (Software Prep)
================================================================================
 
 Flattens the [C_out, C_in, K_h, K_w] kernel tensor into the B_matrix.
 [K_flat x C_out]. (No changes here, this is DRAM prep).
*/
static float* flatten_kernels_to_B_matrix(KernelTensor* kernels) {
    int K_flat = kernels->cin * kernels->kh * kernels->kw;
    int N = kernels->cout; 

    // B_matrix (GEMM B) has dims [K x N] == [K_flat x C_out]
    float* B_matrix = (float*)malloc(K_flat * N * sizeof(float));
    if (!B_matrix) return NULL;

    for (int n_idx = 0; n_idx < N; n_idx++) {
        for (int k_idx = 0; k_idx < K_flat; k_idx++) {
            
            int k_flat_size = kernels->kh * kernels->kw;
            int c = k_idx / k_flat_size;
            int r = (k_idx % k_flat_size) / kernels->kw;
            int w = k_idx % kernels->kw;
            
            int kernel_idx = n_idx * (kernels->cin * k_flat_size) + 
                             c * (k_flat_size) +                   
                             r * (kernels->kw) +                   
                             w;                                    
            
            B_matrix[k_idx * N + n_idx] = kernels->data[kernel_idx];
        }
    }
    return B_matrix;
}

/*
================================================================================
 LEVEL 1: Block Load (SDMA/DRAM -> Scratchpad)
================================================================================
 
 This simulates the `SDMA_LD` instruction. It loads a raw spatial tile
 (NCHW format chunk, including overlap/padding) from DRAM into `sc_RAW`.
*/
static void load_spatial_tile(
    float* sc_RAW,         // Destination spatial scratchpad buffer
    TensorNCHW* input,     // Global input tensor (DRAM)
    int C_in,              // Number of channels to load
    int H_load, int W_load, // Required spatial dimensions of the tile (e.g., 32x32)
    int nchw_start_c,      // Global start channel index
    int nchw_start_h,      // Global start height index
    int nchw_start_w)      // Global start width index
{
    // C x H_load x W_load elements are loaded.
    for (int c = 0; c < C_in; c++) {
        for (int h = 0; h < H_load; h++) {
            for (int w = 0; w < W_load; w++) {
                
                int global_c = nchw_start_c + c;
                int global_h = nchw_start_h + h;
                int global_w = nchw_start_w + w;

                int sc_idx = c * (H_load * W_load) + h * W_load + w;

                // --- Handles padding for edges that cross the input boundary ---
                if (global_c < input->c &&
                    global_h >= 0 && global_h < input->h &&
                    global_w >= 0 && global_w < input->w) 
                {
                    // Calculate global NCHW index (assuming batch 0)
                    int in_idx = global_c * (input->h * input->w) +
                                 global_h * (input->w) +
                                 global_w;
                    sc_RAW[sc_idx] = input->data[in_idx];
                } else {
                    // Pad with 0 for out-of-bounds access
                    sc_RAW[sc_idx] = 0.0f;
                }
            }
        }
    }
}


/*
================================================================================
 LEVEL 2: Vector Transform (Scratchpad -> Scratchpad/Vector Core)
================================================================================
 
 This function executes the explicit im2col transformation on data already
 loaded into the scratchpad (`sc_RAW`), filling the GEMM input matrix (`sc_A`).
 
 The C code here represents the VLIW Vector Instructions (Masking, Shifting, Adding).
 
*/
static void im2col_transform_scpad(
    float* sc_A,           // Destination Toeplitz Scratchpad [TM x TK]
    float* sc_RAW,         // Source Spatial Scratchpad [C_in x T_h x T_w]
    ConvParams* params,
    int K_h, int K_w, int C_in,
    int O_h, int O_w,      // Full output dimensions
    int i_start,           // Global patch row start (0..M)
    int k_start,           // Global flat kernel index start (0..K)
    int TM, int TK,
    int T_h, int T_w,      // Spatial dimensions of sc_RAW buffer
    int raw_tile_start_c,  // Starting channel index of the loaded raw tile
    int raw_tile_start_h,  // Starting height index of the loaded raw tile
    int raw_tile_start_w)  // Starting width index of the loaded raw tile
{
    int K_flat_size = C_in * K_h * K_w;
    int M_total_patches = O_h * O_w;

    // Loop over rows of sc_A (m) -> This is the output patch index
    for (int m = 0; m < TM; m++) {
        int global_patch_idx = i_start + m;

        // Pad rows of A that are out of bounds of the total output
        if (global_patch_idx >= M_total_patches) {
            memset(&sc_A[m * TK], 0, TK * sizeof(float));
            continue;
        }

        // Find the (o_h, o_w) coordinate of this patch in the output map
        int o_h = global_patch_idx / O_w;
        int o_w = global_patch_idx % O_w;

        // Find the top-left (h, w) of this patch in the *GLOBAL* input tensor
        int global_in_h_start = o_h * params->stride - params->padding;
        int global_in_w_start = o_w * params->stride - params->padding;

        // Loop over cols of sc_A (k) -> This is the flat kernel elem index
        for (int k = 0; k < TK; k++) {
            int global_k_idx = k_start + k;

            // Pad columns of A (kernel elements) that are out of bounds of the total flat kernel
            if (global_k_idx >= K_flat_size) {
                sc_A[m * TK + k] = 0.0f;
                continue;
            }

            // Deconstruct global_k_idx into (channel, kernel_h, kernel_w)
            int k_h_x_k_w = K_h * K_w;
            int c = global_k_idx / k_h_x_k_w;
            int kh = (global_k_idx % k_h_x_k_w) / K_w;
            int kw = global_k_idx % K_w;

            // Find the absolute (h, w) in the GLOBAL input tensor
            int global_in_h = global_in_h_start + kh * params->dilation;
            int global_in_w = global_in_w_start + kw * params->dilation;
            
            // --- Map global NCHW index to LOCAL sc_RAW index ---
            
            // Channel: c is the local channel (since we loaded a sequential block of C_in)
            
            // Height/Width: Find offset from the tile's starting global coordinates
            int local_h = global_in_h - raw_tile_start_h;
            int local_w = global_in_w - raw_tile_start_w;
            
            // Check if this required pixel is actually within the loaded sc_RAW tile bounds
            if (c >= raw_tile_start_c && c < raw_tile_start_c + C_in && // Channel check
                local_h >= 0 && local_h < T_h &&
                local_w >= 0 && local_w < T_w) 
            {
                // This is the read operation the vector core performs (shift/mask)
                int raw_idx = c * (T_h * T_w) + local_h * T_w + local_w;
                sc_A[m * TK + k] = sc_RAW[raw_idx];
            } else {
                // If the required pixel is NOT in the *current* loaded spatial tile, it's a padding zero
                // (This scenario should only happen if tiling logic is wrong, but safety first)
                sc_A[m * TK + k] = 0.0f;
            }
        }
    }
}


/*
================================================================================
 Helper functions (SDMA Load/Store)
================================================================================
*/
static void load_b_tile(float* sc_B, float* B_global, int K, int N,
                 int k_start, int j_start, int TK, int TN) {
    // (No change, loads kernel tile)
    for (int r = 0; r < TK; r++) {
        for (int c = 0; c < TN; c++) {
            int global_r = k_start + r;
            int global_c = j_start + c;
            if (global_r < K && global_c < N) {
                sc_B[r * TN + c] = B_global[global_r * N + global_c];
            } else {
                sc_B[r * TN + c] = 0.0f;
            }
        }
    }
}

static void store_c_tile(TensorNCHW* output, float* sc_C, int O_h, int O_w,
                  int i_start, int j_start, int TM, int TN) {
    // (No change, stores output tile)
    for (int r = 0; r < TM; r++) { 
        for (int c = 0; c < TN; c++) { 

            int global_patch_idx = i_start + r;
            int global_out_ch = j_start + c;

            if (global_patch_idx < (O_h * O_w) && global_out_ch < output->c) {
                
                int o_h = global_patch_idx / O_w;
                int o_w = global_patch_idx % O_w;

                int out_idx = global_out_ch * (output->h * output->w) +
                              o_h * (output->w) +
                              o_w;
                output->data[out_idx] = sc_C[r * TN + c];
            }
        }
    }
}


/*
================================================================================
 LEVEL 2: Conv2D Orchestrator (Public API Implementation)
================================================================================
 
 This function is the main orchestrator, driving the explicit two-step load/transform
 and calling the SA intrinsic.
*/
void conv2d_nchw(
    TensorNCHW* output,
    TensorNCHW* input,
    KernelTensor* kernel,
    ConvParams* params) 
{
    // --- 1. Calculate Dimensions & GEMM Dims (M, N, K) ---
    if (input->n > 1) { /* error check */ return; }

    int O_h = (input->h - (kernel->kh - 1) * params->dilation - 1 + 2 * params->padding) / params->stride + 1;
    int O_w = (input->w - (kernel->kw - 1) * params->dilation - 1 + 2 * params->padding) / params->stride + 1;

    output->n = input->n; output->c = kernel->cout; output->h = O_h; output->w = O_w;
    memset(output->data, 0, output->n * output->c * O_h * O_w * sizeof(float));

    int M = O_h * O_w;        // Num patches 
    int N = kernel->cout;     // Num output channels 
    int K = kernel->cin * kernel->kh * kernel->kw; // Flat patch/kernel size 

    const int TM = SA_TM;
    const int TN = SA_TN;
    const int TK = SA_TK;

    // The output tile dimensions (O_T) based on TM (e.g. 30, since 32 input patches gives 30x30 output)
    // We determine the maximum number of output patches (O_T_h) that fit into TM
    int O_T_h = TM;
    int O_T_w = TM;

    // Required spatial input tile dimensions (T_h, T_w) to cover O_T_h/O_T_w output patches
    // T = (O - 1) * S + K_eff
    int K_eff_h = (kernel->kh - 1) * params->dilation + 1;
    int K_eff_w = (kernel->kw - 1) * params->dilation + 1;

    // Corrected spatial size calculation:
    int T_h_req = (O_T_h - 1) * params->stride + K_eff_h;
    int T_w_req = (O_T_w - 1) * params->stride + K_eff_w;

    // Use the required size, but cap it at MAX_SPATIAL_TILE_DIM for buffer allocation
    int T_h = T_h_req;
    int T_w = T_w_req;
    if (T_h > MAX_SPATIAL_TILE_DIM || T_w > MAX_SPATIAL_TILE_DIM) { /* error: spatial tile too big */ return; }

    // --- 2. Level 1: Flatten Kernels (Software Prep) ---
    float* B_matrix_flat = flatten_kernels_to_B_matrix(kernel);
    if (!B_matrix_flat) { /* error */ return; }

    // --- 3. Allocate Scratchpad Buffers ---
    // Note: O_T_h * O_T_w is the maximum number of patches this tile can calculate.
    int patches_per_tile = O_T_h * O_T_w; 
    float sc_A[patches_per_tile * TK]; 
    float sc_B[TK * TN]; 
    float sc_C[patches_per_tile * TN];
    // This is the new scratchpad buffer for the raw spatial tile
    float sc_RAW[kernel->cin * T_h * T_w]; 

    // --- 4. Main Tiling Loop (Orchestration) ---
    for (int i = 0; i < M; i += patches_per_tile) { // Loop over M (patches) in steps of patches_per_tile
        for (int j = 0; j < N; j += TN) { // Loop over N (output channels) in steps of TN

            // 4.1. Determine Spatial Input Start (Handles Overlap)
            // The starting pixel of the input block required to compute output patch i.
            // i / O_w is the global row index of the first output patch in this tile.
            int in_h_start_global = (i / O_w) * params->stride - params->padding; 
            int in_w_start_global = (i % O_w) * params->stride - params->padding; 
            
            // 4.2. **LEVEL 1: Block Load (SDMA_LD)**
            // Load the entire raw spatial block needed for the current patches_per_tile
            load_spatial_tile(sc_RAW, input, kernel->cin, T_h, T_w, 
                              0, // Start channel (currently always 0, for simplicity)
                              in_h_start_global, 
                              in_w_start_global);
            
            // Zero-out the C accumulator tile in scratchpad
            memset(sc_C, 0, patches_per_tile * TN * sizeof(float));

            for (int k = 0; k < K; k += TK) { // Loop over K (reduction dim) in steps of TK
                
                // 4.3. Load B_tile (kernels) [TK x TN] (SDMA_LD)
                load_b_tile(sc_B, B_matrix_flat, K, N, k, j, TK, TN);

                // 4.4. **LEVEL 2: Vector Transform (VM_LD + VV_*)**
                // Transform the raw spatial data into the required im2col format
                im2col_transform_scpad(sc_A, sc_RAW, params,
                                       kernel->kh, kernel->kw, kernel->cin,
                                       O_h, O_w, i, k, TM, TK,
                                       T_h, T_w,
                                       0, in_h_start_global, in_w_start_global);
                
                // 4.5. **LEVEL 3: Execute SA Intrinsic (GEMMV)**
                atallax_gemmv(sc_C, sc_A, sc_B, TM, TN, TK);
            }

            // 4.6. Store C_tile (SDMA_ST)
            store_c_tile(output, sc_C, O_h, O_w, i, j, TM, TN);
        }
    }

    // --- 5. Clean up ---
    free(B_matrix_flat);
}