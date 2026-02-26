# Systolic Array

## Arithmetic Modules

### 4-Input Floating Point Adder

**Description**: The 4-input floating point adder performs fused addition of 4 floating point values. The HDL is parameterized to support various standard and non-standard floating point formats, including FP16, FP32, and BF16. 

**Block Diagram**: https://drive.google.com/file/d/1e_-s29tflHo5oTXHLiL5-CV9N0vuqOyr/view?usp=drive_link

**Code**: https://github.com/Purdue-SoCET/atalla/blob/4_input_fp_adder/rtl/modules/systolic_array/sysarr_4_input_fp_adder.sv

The adder contains three pipelined stages
1. Exponent Alignment and Mantissa Expansion
2. Stage 1 Addition
3. Stage 2 Addition, LZD, Exponent Recalculation, Mantissa Normalization, and Final Output

**Important Architecture Decisions**: The architecture was based on this IEEE paper (https://ieeexplore.ieee.org/document/11008646). The adder implements DAZ and FTZ logic for simplicity and speed. 

The exponent alignment stage determines the largest of the four input exponents and calculates the difference between it and the other three exponents. The mantissa is expanded with 22 precision bits and shifted according to the exponent differences. 

The second stage inverts the mantissas according to the sign bits of the original operands and performs a fused addition. The first stage of the addition uses a carry-save adder for speed. 

The third stage uses a ripple carry adder to finish the addition operation, and uses a tree-based LZD to detect leading zeroes. The mantissa is rounded to the original format using rounding to nearest, half to even logic. The exponent is recalculated based on LZD and rounding overflow, and the final output is compiled, taking into account special cases detected in the exponent alignment stage. 

**Verification**: 
 - The adder was verified through testing against the Berkeley Softfloat Library (https://github.com/ucb-bar/berkeley-softfloat-3). 
 - The testbenches can be found here: https://github.com/Purdue-SoCET/atalla/blob/4_input_fp_adder/tb/unit/systolic_array/. 
 - The test cases generation scripts can be found here: https://github.com/Purdue-SoCET/atalla/blob/4_input_fp_adder/scripts/systolic_array/. 

 **Reference Used**: https://ieeexplore.ieee.org/document/11008646