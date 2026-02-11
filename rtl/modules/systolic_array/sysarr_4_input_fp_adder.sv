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

    localparam NEW_MANT_WIDTH = 1 + MANTISSA_SIZE + PRECISION_BITS + 1;

    logic st1_a_s;
    logic st1_b_op, st1_c_op, st1_d_op;
    logic [EXPONENT_SIZE - 1:0] st1_a_e;
    
    logic [NEW_MANT_WIDTH - 1:0] st1_x_f, st1_y_f, st1_m_f, st1_n_f;

    logic st1_special_case;
    logic [15:0] st1_special_result;
    logic st2_special_case;
    logic [15:0] st2_special_result;

    logic [MANTISSA_SIZE + PRECISION_BITS + 2: 0] sum_i;
    logic result_s;
    logic [EXPONENT_SIZE - 1:0] a_e_out;
    logic [3:0] num_leading_zeros;
    logic [MANTISSA_SIZE + EXPONENT_SIZE :0] sum;
    logic [1:0] right_shift_radix;

    always_ff @( posedge clk, negedge nRST ) begin : output_registering
        if(~nRST) add.out <= '0;
        else add.out <= sum;
    end

    // Pipeline register to align special case signals with Stage 2 latency
    always_ff @(posedge clk, negedge nRST) begin
        if(!nRST) begin
            st2_special_case   <= 1'b0;
            st2_special_result <= '0;
        end else begin
            st2_special_case   <= st1_special_case;
            st2_special_result <= st1_special_result;
        end
    end

    add_4in_stage1 #(
        .MANTISSA(MANTISSA_SIZE), 
        .EXP(EXPONENT_SIZE), 
        .PRECISION(PRECISION_BITS)
    ) first_stage (
        .clk(clk),
        .n_rst(nRST),
        .a(add.a), 
        .b(add.b), 
        .c(add.c), 
        .d(add.d),
        .x_e_f(st1_a_e),
        .x_s_f(st1_a_s),
        .x_f(st1_x_f), 
        .y_shifted_f(st1_y_f), 
        .m_shifted_f(st1_m_f), 
        .n_shifted_f(st1_n_f),
        .y_op_f(st1_b_op), 
        .m_op_f(st1_c_op), 
        .n_op_f(st1_d_op),
        .special_case_f(st1_special_case),
        .special_result_f(st1_special_result)
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
        .b_sb(st1_y_f[0]), 
        .c_sb(st1_m_f[0]), 
        .d_sb(st1_n_f[0]),
        .a_e(st1_a_e),
        .a_f(st1_x_f[NEW_MANT_WIDTH-1:1]), 
        .b_f(st1_y_f[NEW_MANT_WIDTH-1:1]), 
        .c_f(st1_m_f[NEW_MANT_WIDTH-1:1]), 
        .d_f(st1_n_f[NEW_MANT_WIDTH-1:1]),
        .sum_i(sum_i),
        .result_s(result_s),
        .a_e_out(a_e_out),
        .num_leading_zeros(num_leading_zeros),
        .right_shift_radix(right_shift_radix) 
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
        .special_case(st2_special_case),
        .special_result(st2_special_result),
        .final_sum(sum),
        .right_shifts(right_shift_radix) 
    );

endmodule
