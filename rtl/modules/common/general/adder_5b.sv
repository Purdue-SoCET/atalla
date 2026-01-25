//By            : Joe Nasti
//Last Updated  : 1/23/2024 by Myles Querimit - Fixed ovf and unf
//
//Module summary:
//    Adds two unsigned 5 bit integers with ofset of 16 and signals if there is an over/underflow
//Inputs:
//    exp1/2 - 5 bit values to be summed
//Outputs:
//    sum    - 5 bit result of addition regardless of ovf/unf
//    ovf    - signal overflow has occurred
//    unf    - signal underflow has occurred

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
