/**
  Saandiya
  mohan76@purdue.edu

  Atalla Convolution Library Main V2
* @brief Has Golden model to verify Atalla outputs
*/

#include "conv_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h> // For random seed

/*
================================================================================
 1. DUMMY HARDWARE SIMULATION (Level 3 GEMM)
================================================================================
*/
void atallax_gemmv(
    float* sc_C, // [TM x TN]
    float* sc_A, // [TM x TK]
    float* sc_B, // [TK x TN]
    int TM, int TN, int TK) 
{
    // Simple C-based GEMM
    for (int m = 0; m < TM; m++) { 
        for (int n = 0; n < TN; n++) { 
            float acc = sc_C[m * TN + n]; 
            for (int k = 0; k < TK; k++) {
                acc += sc_A[m * TK + k] * sc_B[k * TN + n];
            }
            sc_C[m * TN + n] = acc; 
        }
    }
}

/*
================================================================================
 2. GOLDEN MODEL (Reference Implementation)
================================================================================
 This is the standard, slow, nested-loop implementation of Conv2D.
 We use this to verify that the optimized library gives the correct answer.
*/
void golden_conv2d(
    TensorNCHW* output,
    TensorNCHW* input,
    KernelTensor* kernel,
    ConvParams* params)
{
    // Ensure dilation is valid
    int d = (params->dilation < 1) ? 1 : params->dilation;

    // Clear output
    int out_size = output->n * output->c * output->h * output->w;
    for (int i = 0; i < out_size; i++) output->data[i] = 0.0f;

    // 7 Nested Loops (Standard NCHW Conv)
    for (int n = 0; n < input->n; n++) {
        for (int cout = 0; cout < kernel->cout; cout++) {
            for (int oy = 0; oy < output->h; oy++) {
                for (int ox = 0; ox < output->w; ox++) {
                    
                    float acc = 0.0f;

                    for (int cin = 0; cin < input->c; cin++) {
                        for (int ky = 0; ky < kernel->kh; ky++) {
                            for (int kx = 0; kx < kernel->kw; kx++) {
                                
                                int iy = oy * params->stride - params->padding + ky * d;
                                int ix = ox * params->stride - params->padding + kx * d;

                                if (iy >= 0 && iy < input->h && ix >= 0 && ix < input->w) {
                                    int in_idx = n*(input->c*input->h*input->w) + cin*(input->h*input->w) + iy*(input->w) + ix;
                                    int k_idx = cout*(kernel->cin*kernel->kh*kernel->kw) + cin*(kernel->kh*kernel->kw) + ky*(kernel->kw) + kx;
                                    
                                    acc += input->data[in_idx] * kernel->data[k_idx];
                                }
                            }
                        }
                    }
                    
                    int out_idx = n*(output->c*output->h*output->w) + cout*(output->h*output->w) + oy*(output->w) + ox;
                    output->data[out_idx] = acc;
                }
            }
        }
    }
}

/*
================================================================================
 3. Helper Functions (Random, Print, Verify)
================================================================================
*/

void init_random_tensor(float* data, int size) {
    for (int i = 0; i < size; i++) {
        // Random float between -1.0 and 1.0
        data[i] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
    }
}

bool verify_results(TensorNCHW* t1, TensorNCHW* t2) {
    int size = t1->n * t1->c * t1->h * t1->w;
    float epsilon = 1e-4; // Tolerance for floating point errors
    bool passed = true;

    for (int i = 0; i < size; i++) {
        float diff = fabs(t1->data[i] - t2->data[i]);
        if (diff > epsilon) {
            printf("MISMATCH at index %d: Lib=%f, Gold=%f, Diff=%f\n", i, t1->data[i], t2->data[i], diff);
            passed = false;
            // Print first few failures only
            static int err_count = 0;
            if (++err_count > 5) return false; 
        }
    }
    return passed;
}

/*
================================================================================
 Main Function
================================================================================
*/
int main() {
    srand(time(NULL)); // Seed random generator

    // --- 1. Define Problem ---
    int H_in, W_in;
    int K_h, K_w;
    H_in = 128;
    K_h = 4;
    W_in = H_in;
    K_w = K_h;
    int C_in = 5; 
    int C_out = K_h; 

    ConvParams params;
    params.stride = 3;
    params.padding = 1;
    params.dilation = 1; //no dilation

    printf("Testing Conv2D: In[%dx%dx%d], Kern[%dx%d], OutCh[%d], S=%d, P=%d, D=%d\n",
           C_in, H_in, W_in, K_h, K_w, C_out, params.stride, params.padding, params.dilation);

    // --- 2. Allocate & Init Inputs ---
    TensorNCHW input = {0};
    input.n=1; input.c=C_in; input.h=H_in; input.w=W_in;
    input.data = (float*)malloc(1 * C_in * H_in * W_in * sizeof(float));
    init_random_tensor(input.data, 1 * C_in * H_in * W_in);

    KernelTensor kernel = {0};
    kernel.cout=C_out; kernel.cin=C_in; kernel.kh=K_h; kernel.kw=K_w;
    kernel.data = (float*)malloc(C_out * C_in * K_h * K_w * sizeof(float));
    init_random_tensor(kernel.data, C_out * C_in * K_h * K_w);

    // --- 3. Calculate Output Size ---
    // Use logic to handle dilation=0 edge case for sizing
    int d = (params.dilation < 1) ? 1 : params.dilation;
    int O_h = (H_in - (K_h - 1) * d - 1 + 2 * params.padding) / params.stride + 1;
    int O_w = (W_in - (K_w - 1) * d - 1 + 2 * params.padding) / params.stride + 1;

    TensorNCHW out_lib = {0};
    out_lib.n=1; out_lib.c=C_out; out_lib.h=O_h; out_lib.w=O_w;
    out_lib.data = (float*)malloc(1 * C_out * O_h * O_w * sizeof(float));

    TensorNCHW out_gold = {0};
    out_gold.n=1; out_gold.c=C_out; out_gold.h=O_h; out_gold.w=O_w;
    out_gold.data = (float*)malloc(1 * C_out * O_h * O_w * sizeof(float));

    // --- 4. Run Library Implementation ---
    printf("Running Library Conv2D...\n");
    conv2d_nchw(&out_lib, &input, &kernel, &params);

    // --- 5. Run Golden Model ---
    printf("Running Golden Model Conv2D...\n");
    golden_conv2d(&out_gold, &input, &kernel, &params);

    // --- 6. Verify ---
    printf("Verifying results...\n");
    if (verify_results(&out_lib, &out_gold)) {
        printf("\n[PASS] Library output matches Golden Model!\n");
    } else {
        printf("\n[FAIL] Library output mismatch.\n");
    }

    // Cleanup
    free(input.data); free(kernel.data); free(out_lib.data); free(out_gold.data);
    return 0;
}