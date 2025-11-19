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
    ```if(i>=0 && i <3){ //i is thread_id
    }```
    - But it doesn't work with Atalla because we dont have thread ID.
    - Hence, we'll pass in values of the mask instead of the number of elements.
    - We will follow something similar to RISCV Vector instructions.
    - Explicit mask creation - because no thread id - RVV
    - If there are uneven number of elements (given 32 max elements in the vector), we will take the remainder (Total_Elements % Vector_Length) and compute that remainder first, and then loop through the rest using a full mask.
6. Execution: gemmv

## Further optimizations
1. Support for arbitary input/output channels, kernels
2. Support for arbitary dilation, stride
3. Loop unrolling / Software pipelining

## Timeline
Week 13-14: Finish basic convolution library (skeleton & naive implementation) & golden model
Week 15: Implement support for arbitary input/output channels, kernels, dilation, stride
Week 16: Final Report