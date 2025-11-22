/* Version 1: Only supports input size <= 32x32

This version works with variable kernel size, variable input channel, stride =1, 
no dilation and padding as long as input size <= 32x32.
*/

#include "conv_lib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// --- Hardware/Tiling Constants ---
#define SA_TM 32 
#define SA_TN 32 
#define SA_TK 32 
#define MAX_SPATIAL_TILE_DIM 64 

/*
================================================================================
 VECTOR CORE SIMULATION FUNCTIONS (Explicit Mask, Shift, Add)
================================================================================
*/

/**
 * @brief Simulates `mset.vi` (Mask Set) and shifting.
 * Creates a base mask and shifts it to the current column position.
 * User Logic: "Shift mask right by 1" (01110...)
 */
static void sim_vector_create_window_mask(bool* mask, int vector_len, int window_size, int shift_offset) {
    for (int i = 0; i < vector_len; i++) {
        int logical_pos = i - shift_offset;
        if (logical_pos >= 0 && logical_pos < window_size) {
            mask[i] = true; 
        } else {
            mask[i] = false;
        }
    }
}

/**
 * @brief Simulates `vshr.vv` (Vector Shift).
 * direction_left = TRUE  (v[i] = v[i+1]) -> Moves data to lower indices (Alignment)
 * direction_left = FALSE (v[i+1] = v[i]) -> Moves data to higher indices (Placement)
 */
static void sim_vector_shift(float* v_reg, int vector_len, int shift_amt, bool direction_left) {
    float temp[SA_TK]; 
    memset(temp, 0, vector_len * sizeof(float));

    for (int i = 0; i < vector_len; i++) {
        if (direction_left) {
            // Aligning: Shift Left (e.g., remove leading zeros)
            if (i + shift_amt < vector_len) {
                temp[i] = v_reg[i + shift_amt];
            }
        } else {
            // Placing: Shift Right (e.g., move to kernel row offset 3 or 6)
            if (i - shift_amt >= 0) {
                temp[i] = v_reg[i - shift_amt];
            }
        }
    }
    memcpy(v_reg, temp, vector_len * sizeof(float));
}

/**
 * @brief Simulates applying a mask to a register (AND operation).
 * Zeros out elements where mask is false.
 */
static void sim_vector_mask_apply(float* v_reg, int vector_len, bool* mask) {
    for (int i = 0; i < vector_len; i++) {
        if (!mask[i]) {
            v_reg[i] = 0.0f;
        }
    }
}

static void sim_vector_add(float* dest, float* src, int vector_len) {
    for (int i = 0; i < vector_len; i++) {
        dest[i] += src[i];
    }
}

/**
 * Loads a contiguous row from sc_RAW.
 */
static void sim_vector_load_row(float* v_reg, float* sc_RAW, int start_idx, int vector_len, int max_idx) {
    for (int i = 0; i < vector_len; i++) {
        // Safety check: don't read past the buffer (though tiling logic should prevent this)
        if (start_idx + i < max_idx) {
            v_reg[i] = sc_RAW[start_idx + i];
        } else {
            v_reg[i] = 0.0f;
        }
    }
}

/*
================================================================================
 LEVEL 1: Standard Functions (Flatten, SDMA)
================================================================================
*/
static float* flatten_kernels_to_B_matrix(KernelTensor* kernels) {
    int K_flat = kernels->cin * kernels->kh * kernels->kw;
    int N = kernels->cout; 
    float* B_matrix = (float*)malloc(K_flat * N * sizeof(float));
    if (!B_matrix) return NULL;

    for (int n_idx = 0; n_idx < N; n_idx++) {
        for (int k_idx = 0; k_idx < K_flat; k_idx++) {
            int k_flat_size = kernels->kh * kernels->kw;
            int c = k_idx / k_flat_size;
            int r = (k_idx % k_flat_size) / kernels->kw;
            int w = k_idx % kernels->kw;
            int kernel_idx = n_idx * (kernels->cin * k_flat_size) + c * k_flat_size + r * kernels->kw + w;
            B_matrix[k_idx * N + n_idx] = kernels->data[kernel_idx];
        }
    }
    return B_matrix;
}

static void load_spatial_tile(
    float* sc_RAW, TensorNCHW* input, int C_in, int H_load, int W_load, 
    int nchw_start_c, int nchw_start_h, int nchw_start_w)
{
    for (int c = 0; c < C_in; c++) {
        for (int h = 0; h < H_load; h++) {
            for (int w = 0; w < W_load; w++) {
                int global_c = nchw_start_c + c;
                int global_h = nchw_start_h + h;
                int global_w = nchw_start_w + w;
                int sc_idx = c * (H_load * W_load) + h * W_load + w;

                if (global_c < input->c && global_h >= 0 && global_h < input->h && global_w >= 0 && global_w < input->w) {
                    int in_idx = global_c * (input->h * input->w) + global_h * (input->w) + global_w;
                    sc_RAW[sc_idx] = input->data[in_idx];
                } else {
                    sc_RAW[sc_idx] = 0.0f;
                }
            }
        }
    }
}

/*
================================================================================
 LEVEL 2: Vector Transform (Fixed Negative Shift Logic)
================================================================================
*/
static void im2col_transform_scpad(
    float* sc_A, float* sc_RAW, ConvParams* params,
    int K_h, int K_w, int C_in,
    int O_h, int O_w, int i_start, int k_start, 
    int TM, int TK,
    int T_h, int T_w, int raw_tile_start_c, int raw_tile_start_h, int raw_tile_start_w,
    int M_limit_in_tile)
{
    int M_total_patches = O_h * O_w;
    int K_flat_size = C_in * K_h * K_w;
    int spatial_kernel_size = K_h * K_w;
    int sc_raw_size = C_in * T_h * T_w;

    // Temp registers
    bool v_mask[SA_TK];
    float v_row[SA_TK];   
    float v_accum[SA_TK]; 

    for (int m = 0; m < TM; m++) {
        int global_patch_idx = i_start + m;
        // if (global_patch_idx >= M_total_patches) {
        //     memset(&sc_A[m * TK], 0, TK * sizeof(float));
        //     continue;
        // }
        if (global_patch_idx >= (O_h * O_w) || m >= M_limit_in_tile) {
            memset(&sc_A[m * TK], 0, TK * sizeof(float));
            continue;
        }

        memset(v_accum, 0, TK * sizeof(float));

        int o_h = global_patch_idx / O_w;
        int o_w = global_patch_idx % O_w;
        
        int global_in_h_start = o_h * params->stride - params->padding;
        int global_in_w_start = o_w * params->stride - params->padding;
        
        int local_h_start = global_in_h_start - raw_tile_start_h;
        int local_w_start = global_in_w_start - raw_tile_start_w;

        // Calculate range of channels involved in this k-chunk
        // We need to be careful to check any channel that MIGHT overlap
        // Simply iterating start to end is safest.
        int start_channel = k_start / spatial_kernel_size;
        int end_channel = (k_start + TK + K_w) / spatial_kernel_size; // Look slightly ahead for straddlers

        for (int c = start_channel; c <= end_channel; c++) {
            if (c >= C_in) break;

            int tile_c = c - raw_tile_start_c;
            if (tile_c < 0) continue;

            for (int kh = 0; kh < K_h; kh++) {
                int row_start_offset = tile_c * (T_h * T_w) + (local_h_start + kh) * T_w;
                // 1. LOAD ROW
                // int row_idx_in_scraw = tile_c * (T_h * T_w) + (local_h_start + kh) * T_w;
                // // Safe check for row index validity
                // if (row_idx_in_scraw < 0 || row_idx_in_scraw >= (C_in * T_h * T_w)) continue;
                
                sim_vector_load_row(v_row, sc_RAW, row_start_offset + local_w_start, TK, sc_raw_size);

                // 2. MASK & ALIGN (Standard sliding window logic)
                sim_vector_create_window_mask(v_mask, TK, K_w, 0); // Shift 0
                sim_vector_mask_apply(v_row, TK, v_mask);
                sim_vector_shift(v_row, TK, 0, true); //0

                // 3. PLACE (Shift Right OR Left based on offset)
                int global_k_index = c * spatial_kernel_size + kh * K_w;
                int placement_shift = global_k_index - k_start;

                if (placement_shift >= 0) {
                    // Standard Case: Row starts inside this vector
                    if (placement_shift < TK) {
                        sim_vector_shift(v_row, TK, placement_shift, false); // Right Shift
                        sim_vector_add(v_accum, v_row, TK);
                    }
                } else {
                    // Straddle Case: Row started in previous vector, tail is here.
                    // placement_shift is negative (e.g., -2).
                    // We need to shift LEFT by 2 to bring the tail to index 0.
                    int left_shift_amt = -placement_shift;
                    if (left_shift_amt < K_w) { // Only valid if some part of the row remains
                        sim_vector_shift(v_row, TK, left_shift_amt, true); // Left Shift
                        sim_vector_add(v_accum, v_row, TK);
                    }
                }
            }
        }

        memcpy(&sc_A[m * TK], v_accum, TK * sizeof(float));
    }
}

/*
================================================================================
 Helpers & Orchestrator (Same as before)
================================================================================
*/
static void load_b_tile(float* sc_B, float* B_global, int K, int N, int k_start, int j_start, int TK, int TN) {
    for (int r = 0; r < TK; r++) {
        for (int c = 0; c < TN; c++) {
            int global_r = k_start + r; int global_c = j_start + c;
            sc_B[r * TN + c] = (global_r < K && global_c < N) ? B_global[global_r * N + global_c] : 0.0f;
        }
    }
}
static void store_c_tile(TensorNCHW* output, float* sc_C, int O_h, int O_w, int i_start, int j_start, int TM, int TN) {
    for (int r = 0; r < TM; r++) { for (int c = 0; c < TN; c++) { 
        int p_idx = i_start + r; int ch = j_start + c;
        if (p_idx < O_h * O_w && ch < output->c) 
            output->data[ch * output->h * output->w + (p_idx/O_w)*output->w + (p_idx%O_w)] = sc_C[r * TN + c];
    }}
}

void conv2d_nchw(TensorNCHW* output, TensorNCHW* input, KernelTensor* kernel, ConvParams* params) {
    if (params->dilation < 1) params->dilation = 1;
    if (input->n > 1) return;

    int O_h = (input->h - (kernel->kh - 1) * params->dilation - 1 + 2 * params->padding) / params->stride + 1;
    int O_w = (input->w - (kernel->kw - 1) * params->dilation - 1 + 2 * params->padding) / params->stride + 1;
    output->n = 1; output->c = kernel->cout; output->h = O_h; output->w = O_w;
    memset(output->data, 0, output->n * output->c * O_h * O_w * sizeof(float));

    int M = O_h * O_w; int N = kernel->cout; int K = kernel->cin * kernel->kh * kernel->kw; 
    int TM = SA_TM, TN = SA_TN, TK = SA_TK;
    int O_T_h = TM, O_T_w = TM; // 32x32 tile size for loading

    //int T_h = 32, T_w = 32; // Fixed tile size for this specific logic check
    // Calculate Spatial Tile Size for 32x32 block of output
    int K_eff_h = (kernel->kh - 1) * params->dilation + 1;
    int K_eff_w = (kernel->kw - 1) * params->dilation + 1;
    int T_h_req = (O_T_h - 1) * params->stride + K_eff_h;
    int T_w_req = (O_T_w - 1) * params->stride + K_eff_w;
    int T_h = (T_h_req > 32) ? T_h_req : 32;
    int T_w = (T_w_req > 32) ? T_w_req : 32;
    if (T_h > MAX_SPATIAL_TILE_DIM || T_w > MAX_SPATIAL_TILE_DIM) return;
    float* B_matrix = flatten_kernels_to_B_matrix(kernel);
    int patches_per_tile = O_T_h * O_T_w;
    float sc_A[TM*TK]; 
    float sc_B[TK*TN]; 
    float sc_C[TM*TN]; 
    float sc_RAW[kernel->cin*T_h*T_w];

    // Outer loop 'i': Steps by the Load Tile Size
    for (int i = 0; i < M; i += patches_per_tile) {
        
        for (int j = 0; j < N; j += TN) {
            int in_h = (i/O_w)*params->stride - params->padding;
            int in_w = (i%O_w)*params->stride - params->padding;
            
            // Load the LARGE spatial tile once
            load_spatial_tile(sc_RAW, input, kernel->cin, T_h, T_w, 0, in_h, in_w);
            
            // Inner loop 'ii': Process the Loaded Tile in batches of TM (32)
            // We iterate from 0 to 1024 in steps of 32
            for (int ii = 0; ii < patches_per_tile; ii += TM) {
                int current_patch_global = i + ii;
                
                // Don't process past the total image or the tile end
                if (current_patch_global >= M) break;

                memset(sc_C, 0, TM * TN * sizeof(float));

                for (int k = 0; k < K; k += TK) {
                    load_b_tile(sc_B, B_matrix, K, N, k, j, TK, TN);
                    
                    // Pass 'ii' as relative offset within the tile? No, im2col takes global.
                    // We pass global 'current_patch_global'.
                    // BUT sc_RAW loaded based on 'i'. im2col needs to know this.
                    // passed 'i' as raw_tile_start reference.
                    // Also pass remaining patches in this tile to avoid OOB
                    int patches_left = patches_per_tile - ii;
                    int m_limit = (patches_left > TM) ? TM : patches_left;

                    im2col_transform_scpad(sc_A, sc_RAW, params, kernel->kh, kernel->kw, kernel->cin, 
                                         O_h, O_w, current_patch_global, k, TM, TK, T_h, T_w, 
                                         0, in_h, in_w, m_limit);
                                         
                    atallax_gemmv(sc_C, sc_A, sc_B, TM, TN, TK);
                }
                store_c_tile(output, sc_C, O_h, O_w, current_patch_global, j, TM, TN);
            }
        }
    }
    free(B_matrix);
}