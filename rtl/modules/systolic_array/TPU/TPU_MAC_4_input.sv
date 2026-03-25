`include "systolic_array_4_input_adder_if.vh"

import sys_arr_pkg::*;

module TPU_MAC_4_input #(
    localparam int ACC_WIDTH = IS_FP16 ? DW : DW_ACC,
    localparam int MANTISSA_SIZE = IS_FP16 ? 10 : 23,
    localparam int EXPONENT_SIZE = IS_FP16 ? 5 : 8
)(
    input logic clk, nRST,
    input logic [3:0][DW-1:0] in,
    input logic [ACC_WIDTH-1:0] psum_in,
    input logic weight_en,
    output logic [ACC_WIDTH-1:0] out
);

// TODO: Check if psum buffer is necessary
// TODO: Update the latency, or make it inside the package file
localparam int ADD_4_INPUT_LATENCY = 2;
localparam int MUL_LATENCY = 2;
localparam int DELAY_TO_PSUM = MUL_LATENCY + ADD_4_INPUT_LATENCY;

// logic [DELAY_TO_PSUM-1:0][DW-1:0] psum_buffer;
logic [3:0][ACC_WIDTH-1:0] mul_out;
logic [ACC_WIDTH-1:0] add_4_input_out;

systolic_array_4_input_adder_if  #( .MANTISSA_SIZE(MANTISSA_SIZE),
                                    .EXPONENT_SIZE(EXPONENT_SIZE),
                                    .IN_MANTISSA_SIZE(MANTISSA_SIZE),
                                    .IN_EXPONENT_SIZE(EXPONENT_SIZE)) add_4_input_if();

generate
    genvar i;
    for (i = 0; i < 4; i++) begin: mul_cells

            TPU_mul_cell #(
                // .IS_FP16(IS_FP16)
            ) u_mul_cell (
                .clk(clk),
                .nRST(nRST),
                .in(in[i]),
                .weight_en(weight_en),
                .result(mul_out[i])
            );
    end
endgenerate

assign add_4_input_if.a = mul_out[0];
assign add_4_input_if.b = mul_out[1];
assign add_4_input_if.c = mul_out[2];
assign add_4_input_if.d = mul_out[3];
assign add_4_input_out = add_4_input_if.out;

generate

    if (IS_FP16) begin  
        add_fp16_4_input u_adder_fp16_4_input (
            .clk(clk),
            .nRST(nRST),
            .add(add_4_input_if)
        );
    end else begin
        sysarr_4_input_fp_adder #(
            .MANTISSA_SIZE(MANTISSA_SIZE),
            .EXPONENT_SIZE(EXPONENT_SIZE),
            .IN_MANTISSA_SIZE(MANTISSA_SIZE),
            .IN_EXPONENT_SIZE(EXPONENT_SIZE)
        ) u_sysarr_4_input_fp_adder (
            .clk(clk),
            .nRST(nRST),
            .add(add_4_input_if)
        );
    end
 

    add_fp16_1c #(
        .MANT_W(MANTISSA_SIZE),
        .EXP_W(EXPONENT_SIZE)
    ) u_add_fp16_1c (
        .clk(clk),
        .nRST(nRST),
        .sub(1'b0),
        .fp1_in(add_4_input_out),
        .fp2_in(psum_in),
        .fp_out(out)
    );

    // if (IS_FP16) begin: fp16_adders
    //     add_fp16 u_add_fp16(
    //         .clk(clk),
    //         .nRST(nRST),
    //         .start(1'b1),
    //         .sub(1'b0),
    //         .stall(1'b0),
    //         .fp1_in(add_4_input_out),
    //         // .fp2_in(psum_buffer[DELAY_TO_PSUM-1]),
    //         .fp2_in(psum_in),
    //         .fp_out(out),
    //         .done()
    //     );
    // end else begin: bf16_adder
    //     add_fp16_1c #(
    //         .MANT_W(23),
    //         .EXP_W(8)
    //     ) u_add_fp16_1c (
    //         .clk(clk),
    //         .nRST(nRST),
    //         .sub(1'b0),
    //         .fp1_in(add_4_input_out),
    //         .fp2_in(psum_in),
    //         .fp_out(out)
    //     );
    // end
endgenerate

endmodule