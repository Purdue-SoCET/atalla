#include "conv_lib.h"
#include <stdio.h>
#include <stdlib.h>

/*
================================================================================
 DUMMY HARDWARE SIMULATION (for testing only)
================================================================================
 
 This is the C-based simulation of your Level 3 `gemm.sa` hardware.
*/
void atallax_gemmv(
    float* sc_C, // [TM x TN]
    float* sc_A, // [TM x TK]
    float* sc_B, // [TK x TN]
    int TM, int TN, int TK) 
{
    // Simple C-based GEMM (Matrix Multiplication)
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
 Helper function to print a tensor
================================================================================
*/
void print_tensor(TensorNCHW* t, const char* name) {
    printf("Tensor: %s (Shape: %d, %d, %d, %d)\n", name, t->n, t->c, t->h, t->w);
    for (int n = 0; n < t->n; n++) {
        for (int c = 0; c < t->c; c++) {
            printf("--- Channel %d ---\n", c);
            for (int h = 0; h < t->h; h++) {
                for (int w = 0; w < t->w; w++) {
                    int idx = n * (t->c * t->h * t->w) + 
                              c * (t->h * t->w) + 
                              h * (t->w) + w;
                    printf("%8.2f ", t->data[idx]);
                }
                printf("\n");
            }
        }
    }
    printf("--------------------------------------\n");
}


/*
================================================================================
 Main function for Multi-Channel Test
================================================================================
*/
int main() {
    // --- 1. Define Problem (Multi-Channel) ---
    // 5x5 input, 2 input channels, 3x3 kernel, 2 output channels
    int H_in = 5, W_in = 5, C_in = 2; // C_in = 2
    int K_h = 3, K_w = 3, C_out = 2; // C_out = 2

    ConvParams params;
    params.stride = 1;
    params.padding = 0;
    params.dilation = 1; // no dilation

    // --- 2. Calculate Output Dimensions ---
    int O_h = (H_in - (K_h - 1) * params.dilation - 1 + 2 * params.padding) / params.stride + 1; // == 3
    int O_w = (W_in - (K_w - 1) * params.dilation - 1 + 2 * params.padding) / params.stride + 1; // == 3

    // --- 3. Allocate Tensors ---
    TensorNCHW input = {0};
    input.n = 1; input.c = C_in; input.h = H_in; input.w = W_in;
    input.data = (float*)malloc(1 * C_in * H_in * W_in * sizeof(float));

    KernelTensor kernel = {0};
    kernel.cout = C_out; kernel.cin = C_in; kernel.kh = K_h; kernel.kw = K_w;
    kernel.data = (float*)malloc(C_out * C_in * K_h * K_w * sizeof(float));
    
    TensorNCHW output = {0};
    // CRUCIAL: Initialize output dimensions based on calculation, not input default.
    output.n = 1;
    output.c = C_out;
    output.h = O_h; // Sets to 3
    output.w = O_w; // Sets to 3
    output.data = (float*)calloc(output.n * output.c * output.h * output.w, sizeof(float));

    // --- 4. Fill with Data ---
    // Input Channel 0: 0, 1, 2, ..., 24
    for (int i = 0; i < H_in * W_in; i++) input.data[i] = (float)i;
    // Input Channel 1: 100, 101, 102, ..., 124
    for (int i = 0; i < H_in * W_in; i++) input.data[25 + i] = (float)(100 + i);


    /*
    Kernel Setup (C_out x C_in x K_h x K_w): 2 x 2 x 3 x 3 = 36 total elements
    K0 uses C0 (Identity); K1 uses C1 (Identity)
    */
    // Zero all kernel weights
    for (int i = 0; i < C_out * C_in * K_h * K_w; i++) kernel.data[i] = 0.0f;

    // Kernel 0 (Output C0) x Input C0: Set center weight to 1.0
    // Index: Co=0, Ci=0, Kh=1, Kw=1 => 4
    kernel.data[4] = 1.0f; 

    // Kernel 1 (Output C1) x Input C1: Set center weight to 1.0
    // Index: Co=1, Ci=1, Kh=1, Kw=1 => 18 + 9 + 3 + 1 = 31
    int k1_c1_idx = 1 * (2*9) + 1 * 9 + 1 * 3 + 1;
    kernel.data[k1_c1_idx] = 1.0f; 

    printf("Input Tensor:\n");
    print_tensor(&input, "Input");
    
    // --- 5. Run Convolution ---
    printf("Calling conv2d_nchw library function...\n");
    conv2d_nchw(&output, &input, &kernel, &params);
    printf("Convolution complete.\n\n");

    // --- 6. Print Output ---
    print_tensor(&output, "Output");
    
    // --- 7. Free Memory ---
    free(input.data);
    free(kernel.data);
    free(output.data);

    return 0;
}