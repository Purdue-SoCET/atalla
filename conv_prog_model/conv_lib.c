/**
  Saandiya
  mohan76@purdue.edu

  Atalla Convolution Library V3
* @brief Supports variable input size, variable input channels, variable kernel size, variable stride, no dilation and padding.
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
#define SCPAD_DIM 32

/*
================================================================================
 VECTOR CORE SIMULATION FUNCTIONS (Explicit Mask, Shift, Add)
================================================================================
*/

/**
 * @brief Simulates `mset.vi`. Creates a mask for the valid window (e.g. 111000...).
 */
static void sim_vector_create_window_mask(bool* mask, int vector_len, int window_size) {
    for (int i = 0; i < vector_len; i++) {
        // Window is always at index 0 because we align the LOAD address.
        mask[i] = (i < window_size);
    }
}

/**
 * @brief Simulates `shift.vs`. 
 * Left = Align (move to index 0). Right = Place (move to flat index).
 */
static void sim_vector_shift(float* v_reg, int vector_len, int shift_amt, bool direction_left) {
    float temp[SA_TK]; 
    memset(temp, 0, vector_len * sizeof(float));
    for (int i = 0; i < vector_len; i++) {
        if (direction_left) {
            if (i + shift_amt < vector_len) temp[i] = v_reg[i + shift_amt];
        } else {
            if (i - shift_amt >= 0) temp[i] = v_reg[i - shift_amt];
        }
    }
    memcpy(v_reg, temp, vector_len * sizeof(float));
}

/**
 * @brief Simulates applying a mask. Zeros out masked elements.
 */
static void sim_vector_mask_apply(float* v_reg, int vector_len, bool* mask) {
    for (int i = 0; i < vector_len; i++) {
        if (!mask[i]) v_reg[i] = 0.0f;
    }
}

/**
 * @brief Simulates `vadd.vv`. Accumulates result.
 */
static void sim_vector_add(float* dest, float* src, int vector_len) {
    for (int i = 0; i < vector_len; i++) {
        dest[i] += src[i];
    }
}

/**
 * Loads a contiguous row from sc_RAW.
 */
static void sim_vector_load_row_safe(float* v_reg, float* sc_RAW, int start_idx, int vector_len, int valid_pixels_remaining) {
    for (int i = 0; i < vector_len; i++) {
        // If we are within the valid width of the current row, load data.
        // Otherwise, load padding 0 (do NOT wrap to next row).
        if (i < valid_pixels_remaining) {
            v_reg[i] = sc_RAW[start_idx + i];
        } else {
            v_reg[i] = 0.0f;
        }
    }
}

/*
================================================================================
 LEVEL 1: Standard Functions
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
 LEVEL 2: Vector Transform (Mask -> Shift -> Add)
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
    int K_flat_size = C_in * K_h * K_w;
    int spatial_kernel_size = K_h * K_w;

    // Temp registers
    bool v_mask[SA_TK];
    float v_row[SA_TK];   
    float v_accum[SA_TK]; 

    // Loop over M (Patches)
    for (int m = 0; m < TM; m++) {
        int global_patch_idx = i_start + m;
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

        int start_channel = k_start / spatial_kernel_size;
        int end_channel = (k_start + TK + K_w) / spatial_kernel_size;

        for (int c = start_channel; c <= end_channel; c++) {
            if (c >= C_in) break;
            int tile_c = c - raw_tile_start_c;
            if (tile_c < 0) continue;

            for (int kh = 0; kh < K_h; kh++) {
                // 1. Calculate Aligned Load Address
                // Point directly to the start of the window (local_w_start)
                int row_idx_in_scraw = tile_c * (T_h * T_w) + (local_h_start + kh) * T_w;
                int load_addr = row_idx_in_scraw + local_w_start;

                // 2. Boundary Check
                // How many valid pixels remain in this row starting from local_w_start?
                // If local_w_start = 30 and T_w = 32, we have 2 valid pixels (30, 31).
                // Any load beyond that must be 0.
                int valid_pixels = T_w - local_w_start;
                if (valid_pixels < 0) valid_pixels = 0;

                // 3. LOAD (Hardware: load from scpad)
                sim_vector_load_row_safe(v_row, sc_RAW, load_addr, TK, valid_pixels);

                // 4. MASK (Hardware: mset.vi)
                // Since we aligned the load, the data starts at index 0. Mask the first K_w elements.
                sim_vector_create_window_mask(v_mask, TK, K_w);
                sim_vector_mask_apply(v_row, TK, v_mask);
                
                // 5. PLACE SHIFT (Hardware: shift.vs)
                // Shift the window to its final position in the flat kernel vector.
                int global_k_index = c * spatial_kernel_size + kh * K_w;
                int placement_shift = global_k_index - k_start;

                if (placement_shift >= 0) {
                    if (placement_shift < TK) {
                        sim_vector_shift(v_row, TK, placement_shift, false); // Shift Right
                        sim_vector_add(v_accum, v_row, TK);
                    }
                } else {
                    // Straddle Case: Row started in previous vector chunk.
                    // Shift Left to bring the tail end to the front.
                    int left_shift_amt = -placement_shift;
                    if (left_shift_amt < K_w) { 
                        sim_vector_shift(v_row, TK, left_shift_amt, true); // Shift Left
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
 Helpers & Orchestrator
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

    int N = kernel->cout; int K = kernel->cin * kernel->kh * kernel->kw; 
    int TM = SA_TM, TN = SA_TN, TK = SA_TK;

    int T_h = SCPAD_DIM; // 32
    int T_w = SCPAD_DIM; // 32

    // Calculate Output Block Size fitting in 32x32 Input
    int K_eff_h = (kernel->kh - 1) * params->dilation + 1;
    int K_eff_w = (kernel->kw - 1) * params->dilation + 1;
    
    // Equation for 32x32 Scratchpad limit
    int BLK_H = (T_h - K_eff_h) / params->stride + 1; //step size calculation
    int BLK_W = (T_w - K_eff_w) / params->stride + 1;
    if (BLK_H < 1) BLK_H = 1;
    if (BLK_W < 1) BLK_W = 1;

    float* B_matrix = flatten_kernels_to_B_matrix(kernel);
    float* sc_RAW = (float*)malloc(kernel->cin * T_h * T_w * sizeof(float));
    if (!sc_RAW) { free(B_matrix); return; }

    float sc_A[TM * TK]; 
    float sc_B[TK * TN]; 
    float sc_C[TM * TN];

    int patches_per_block = BLK_H * BLK_W;

    for (int h_out = 0; h_out < O_h; h_out += BLK_H) { //overlapping tile logic
        for (int w_out = 0; w_out < O_w; w_out += BLK_W) {
            
            int in_h = h_out * params->stride - params->padding; // Calculate Start Address
            int in_w = w_out * params->stride - params->padding;

            load_spatial_tile(sc_RAW, input, kernel->cin, T_h, T_w, 0, in_h, in_w); //32x32 tiles

            for (int j = 0; j < N; j += TN) {
                
                // Process patches in batches of TM (32)
                for (int ii = 0; ii < patches_per_block; ii += TM) {
                    int patches_remaining = patches_per_block - ii;
                    int current_batch_size = (patches_remaining > TM) ? TM : patches_remaining;

                    memset(sc_C, 0, TM * TN * sizeof(float));

                    for (int k = 0; k < K; k += TK) {
                        load_b_tile(sc_B, B_matrix, K, N, k, j, TK, TN);
                        
                        // Fill sc_A row-by-row for valid patches
                        for (int m = 0; m < current_batch_size; m++) {
                            int local_patch_idx = ii + m; 
                            int r_local = local_patch_idx / BLK_W;
                            int c_local = local_patch_idx % BLK_W;
                            int current_patch_global = (h_out + r_local) * O_w + (w_out + c_local);

                            // Skip if this patch in the block is outside the image
                            if ((h_out + r_local) >= O_h || (w_out + c_local) >= O_w) {
                                memset(&sc_A[m * TK], 0, TK * sizeof(float));
                                continue;
                            }

                            // Call vector transform for THIS specific patch 'm'
                            im2col_transform_scpad(&sc_A[m * TK], sc_RAW, params, kernel->kh, kernel->kw, kernel->cin, 
                                                 O_h, O_w, current_patch_global, k, 
                                                 1, TK, T_h, T_w, 0, in_h, in_w, 1);
                        }
                        // gemm.vv
                        atallax_gemmv(sc_C, sc_A, sc_B, TM, TN, TK);
                    }
                    
                    // Store results
                    for (int m = 0; m < current_batch_size; m++) {
                         int local_patch_idx = ii + m; 
                         int r_local = local_patch_idx / BLK_W;
                         int c_local = local_patch_idx % BLK_W;
                         int current_patch_global = (h_out + r_local) * O_w + (w_out + c_local);
                         
                         if ((h_out + r_local) >= O_h || (w_out + c_local) >= O_w) continue;
                         
                         int p_idx = current_patch_global;
                         for (int c = 0; c < TN; c++) {
                             int ch = j + c;
                             if (ch < output->c) {
                                 output->data[ch * output->h * output->w + p_idx] = sc_C[m * TN + c];
                             }
                         }
                    }
                }
            }
        }
    }
    free(sc_RAW);
    free(B_matrix);
}
