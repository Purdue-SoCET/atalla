// FP16 exponent adder (bias-15 removal).
//
// Timing: comb only
//
// Module summary:
//    Adds two unsigned 5-bit exponents with bias offset of 15
//    and signals overflow/underflow.
// Inputs:
//    carry  - carry-in from mantissa multiply overflow
//    exp1/2 - 5-bit biased exponents
// Outputs:
//    sum    - 5-bit result (raw_sum - 15)
//    ovf    - result exponent >= 31 (Inf/NaN range)
//    unf    - result exponent <= 0 (zero/subnormal range)

`timescale 1ns/1ps

module adder_5b (
    input        carry,
    input  [4:0] exp1,
    input  [4:0] exp2,
    output [4:0] sum,
    output       ovf,
    output       unf
);

    // Use 6-bit arithmetic to avoid wraparound issues
    logic [5:0] raw_sum;
    
    // Raw sum without bias adjustment (max value: 31 + 31 + 1 = 63)
    assign raw_sum = {1'b0, exp1} + {1'b0, exp2} + {5'b0, carry};
    assign sum = raw_sum[4:0] - 5'd15;
    assign ovf = (raw_sum >= 6'd46); // ovf : raw_sum >= 46 means result exponent >= 31 (Inf/NaN range)
    assign unf = (raw_sum <= 6'd15);  // unf: raw_sum <= 15 means result exponent <= 0 (zero/subnormal range)

endmodule
