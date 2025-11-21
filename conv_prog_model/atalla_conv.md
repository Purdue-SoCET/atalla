# Atalla Convolution Library
Goal: Development of a Convolution Library for Atalla

## Strategy
### 1. Atalla specific code
- This is where the programming model will be defined
- Cannot be compiled using gcc
- Vector granularity
- mset, shift, add - ISA instructions

### 2. CPU version (C code)
- Equivalent to Atalla specific code
- Proof of concept for convolution flow
- Can be compiled using gcc
- Element granularity
- Basic functions that are used for convolution will be created/defined.
- Memory allocations/ tiling

### 3. Python implementation (golden model)
- To check correctness purposes (test plan)
- Results must be equal to C implementation
- Using PyTorch, TensorFlow, numpy

## Flow
1. API Entry Point: User calls conv2d(input, weight, bias, params).
2. Parameter Validation: Check strides, padding, dilation, and data types.
3. Tiling & Layout Transformation:
    - Input and kernel tiling in software
4. Data Layout: Define expected input format (NCHW vs NHWC).
5. Convolution function 
    - Construction of Toeplitz matrix
    - Initially we planned to use if statements for creating masks, for example:
    ```if(i>=0 && i <3){ //i is thread_id }```
    - But it doesn't work with Atalla because we dont have thread ID.
    - Hence, we'll pass in values of the mask instead of the number of elements.
    - We will follow something similar to RISCV Vector instructions.
    - Using explicit masking (RVV style) rather than thread-based conditionals.
    - If there are uneven number of elements (given 32 max elements in the vector), we will take the remainder    ```(Total_Elements % Vector_Length)``` and compute that remainder first, and then loop through the rest using a full mask.
6. Execution: gemmv

## Further optimizations
1. Support for arbitary input channels, kernels
2. Support for arbitary dilation, stride, padding
3. Loop unrolling / Software pipelining

## Timeline
Week 13-14: Finish basic convolution library (skeleton & naive implementation) & golden model  
Week 15: Implement support for arbitary input channels, kernels, stride  
Week 16: Final Report

## Current progress
- As of 11/21 Friday - my convolution library works with fixed kernel size 3x3, fixed input size (32,64,96,128,1024,...), variable input channel, stride = 1, no dilation and padding
