module 4_input_fp_adder #(
    parameter MANTISSA_SIZE = 10,
    parameter EXPONENT_SIZE = 5,
    parameter PRECISION_BITS = 3
) (
    input logic clk, input logic nRST,
    systolic_array_4_input_adder_if.add add
);
    logic sum_first_stage;
    
    sysarr_4in_adder first_stage #(.MANTISSA_SIZE, .EXPONENT_SIZE, .PRECISION_BITS) (.clk, .nRST, .a(add.a), .b(add.b), .c(add.c), .d(add.d), .sum(sum_first_stage), );

endmodule