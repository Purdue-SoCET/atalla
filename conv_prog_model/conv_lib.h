/*
  Saandiya
  mohan76@purdue.edu

  Atalla Convolution Library Header V1
*/

#ifndef CONV_LIB_H
#define CONV_LIB_H

/*
================================================================================
 1. Public Data Structures
================================================================================
*/

/**
 * @brief Represents a 4D Tensor in NCHW format (Batch, Channels, Height, Width).
 */
typedef struct {
    float* data; // Pointer to the data in global DRAM
    int n;       // Batch size
    int c;       // Channels
    int h;       // Height
    int w;       // Width
} TensorNCHW;

/**
 * @brief Represents a 4D Kernel tensor.
 * Format: [C_out, C_in, K_h, K_w]
 */
typedef struct {
    float* data; // Pointer to the data in global DRAM
    int cout;    // Output channels
    int cin;     // Input channels
    int kh;      // Kernel height
    int kw;      // Kernel width
} KernelTensor;

/**
 * @brief Parameters for the convolution operation.
 */
typedef struct {
    int stride;
    int padding;
    int dilation;
} ConvParams;

/*
================================================================================
 3. Hardware Intrinsic (Stub)
================================================================================
 
 This is the "Level 3: GEMM Function" you described.
 Your C code will call this. The compiler will replace this function
 call with the actual hardware instructions (e.g., `gemm.sa`).
 
 This function assumes data is already in on-chip SRAM/scratchpad.
 
 C_tile = A_tile * B_tile + C_tile
 (TMxTN) = (TMxTK) * (TKxTN) + (TMxTN)
*/
extern void atallax_gemmv(
    float* sc_C, // Pointer to C_tile in scratchpad [TM x TN]
    float* sc_A, // Pointer to A_tile in scratchpad [TM x TK]
    float* sc_B, // Pointer to B_tile in scratchpad [TK x TN]
    int TM,
    int TN,
    int TK
);

/*
================================================================================
 2. Public Library API
================================================================================
 
 This is the "Level 2: Conv" orchestrator.
 Users will call this function to run a convolution.
*/

/**
 * @brief Performs 2D convolution using the Atallax01 accelerator.
 * * This function orchestrates the entire operation:
 * 1. Flattens kernels (Level 1).
 * 2. Manages tiling and calls `im2col` on-the-fly (Level 1).
 * 3. Calls the `atallax_gemmv` hardware intrinsic (Level 3) in a loop.
 * * @param output The output tensor (pre-allocated).
 * @param input The input tensor.
 * @param kernel The kernel tensor.
 * @param params The convolution parameters (stride, padding, dilation).
 */
void conv2d_nchw(
    TensorNCHW* output,
    TensorNCHW* input,
    KernelTensor* kernel,
    ConvParams* params
);

#endif // CONV_LIB_H