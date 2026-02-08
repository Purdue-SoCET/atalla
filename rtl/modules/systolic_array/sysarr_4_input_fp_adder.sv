`include "systolic_array_4_input_adder_if.vh"

module sysarr_4_input_fp_adder #(
    parameter MANTISSA_SIZE = 10,
    parameter EXPONENT_SIZE = 5,
    parameter PRECISION_BITS = 3
) (
    input logic clk, 
    input logic nRST,
    systolic_array_4_input_adder_if.add add
);

    logic st1_a_s;
    logic st1_b_op, st1_c_op, st1_d_op;
    logic st1_b_sb, st1_c_sb, st1_d_sb;
    logic [EXPONENT_SIZE - 1:0] st1_a_e;
    logic [MANTISSA_SIZE + PRECISION_BITS : 0] st1_a_f, st1_b_f, st1_c_f, st1_d_f;

    logic [MANTISSA_SIZE + PRECISION_BITS : 0] sum_i;
    logic result_s;
    logic [EXPONENT_SIZE - 1:0] a_e_out;
    logic [3:0] num_leading_zeros;
    logic sticky_bit;

    sysarr_4in_adder #(
        .MANTISSA_SIZE(MANTISSA_SIZE), 
        .EXPONENT_SIZE(EXPONENT_SIZE), 
        .PRECISION_BITS(PRECISION_BITS)
    ) first_stage (
        .clk(clk),
        .nRST(nRST),
        .a(add.a), 
        .b(add.b), 
        .c(add.c), 
        .d(add.d),
        .a_s(st1_a_s),
        .b_op(st1_b_op), 
        .c_op(st1_c_op), 
        .d_op(st1_d_op),
        .b_sb(st1_b_sb), 
        .c_sb(st1_c_sb), 
        .d_sb(st1_d_sb),
        .a_e_out(st1_a_e),
        .a_f(st1_a_f), 
        .b_f(st1_b_f), 
        .c_f(st1_c_f), 
        .d_f(st1_d_f)
    );
    
    sysarr_4inp_fp_adder_2nd_pipeline_state #(
        .MANTISSA_SIZE(MANTISSA_SIZE), 
        .EXPONENT_SIZE(EXPONENT_SIZE), 
        .PRECISION_BITS(PRECISION_BITS)
    ) second_stage (
        .clk(clk),
        .nRST(nRST),
        .a_s(st1_a_s),
        .b_op(st1_b_op), 
        .c_op(st1_c_op), 
        .d_op(st1_d_op),
        .b_sb(st1_b_sb), 
        .c_sb(st1_c_sb), 
        .d_sb(st1_d_sb),
        .a_e(st1_a_e),
        .a_f(st1_a_f), 
        .b_f(st1_b_f), 
        .c_f(st1_c_f), 
        .d_f(st1_d_f),
        .sum_i(sum_i),
        .result_s(result_s),
        .a_e_out(a_e_out),
        .num_leading_zeros(num_leading_zeros),
        .sticky_bit(sticky_bit)
    );

    add_fp_4input_stage3 #(
        .MANTISSA_SIZE(MANTISSA_SIZE), 
        .EXPONENT_SIZE(EXPONENT_SIZE), 
        .PRECISION_BITS(PRECISION_BITS)
    ) third_stage (
        .clk(clk),
        .nRST(nRST),
        .leading_zeros(num_leading_zeros),
        .sum(sum_i),
        .sign(result_s),
        .exponent(a_e_out),
        .sticky_in(sticky_bit),
        .special_case(1'b0),
        .special_result('0),
        .final_sum(add.out)
    );

endmodule