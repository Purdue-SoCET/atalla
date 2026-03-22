`include "systolic_array_MAC_if.vh"
`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

// Parameterizable Mixed-Precision MAC PE: BF16 multiply -> FP32 accumulate
//
// LATENCY parameter selects pipeline depth:
//   LATENCY = 4 (default):
//     Cycle 1: BF16 inputs latched by mul_bf (registered multiplier)
//     Cycle 2: mul_bf done -> exact FP32 product ready (registered output)
//     Cycle 3: Latch mul result -> FP32 pipelined adder stage 1
//     Cycle 4: FP32 adder output -> value_ready
//     Uses: mul_bf (1c latched) + add_fp16 (2c pipelined)
//
//   LATENCY = 2:
//     Cycle 1: Combinational BF16 multiply -> latch FP32 product
//     Cycle 2: Combinational FP32 add -> value_ready
//     Uses: mul_bf_nolatch (comb) + add_fp16_nolatch (comb)
//
// Horizontal: 16-bit BF16 activations flow left-to-right (via mac_if)
// Vertical:   32-bit FP32 partial sums flow top-to-bottom (via mac_if)

/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNUSEDPARAM */

`timescale 1ns/1ps

module sysarr_MAC_bf #(
    parameter int LATENCY = 4  // 2 or 4
)(
    input logic clk,
    input logic nRST,
    systolic_array_MAC_if.MAC mac_if
);


    logic [DW-1:0] input_x, nxt_input_x;
    logic [DW-1:0] weight, nxt_weight;
    logic [DW-1:0] latched_weight_passon, nxt_latched_weight_passon;
    logic next_weight_next_en;

    assign mac_if.in_pass = mac_if.weight_next_en ? latched_weight_passon : input_x;

    always_ff @(posedge clk, negedge nRST) begin
        if (nRST == 1'b0) begin
            input_x <= '0;
            weight  <= '0;
            mac_if.weight_next_en <= 0;
            latched_weight_passon <= 0;
        end else begin
            input_x <= nxt_input_x;
            weight  <= nxt_weight;
            mac_if.weight_next_en <= next_weight_next_en;
            latched_weight_passon <= nxt_latched_weight_passon;
        end
    end

    always_comb begin
        nxt_input_x = input_x;
        nxt_weight  = weight;
        nxt_latched_weight_passon = latched_weight_passon;
        next_weight_next_en = mac_if.weight_en;

        if (mac_if.weight_en) begin
            nxt_weight = mac_if.in_value;
            nxt_latched_weight_passon = weight;
        end else if (mac_if.MAC_shift) begin
            nxt_input_x = mac_if.in_value;
        end
    end


    generate
    if (LATENCY == 4) begin : gen_4c

        // Stage 1-2: mul_bf has registered output (1-cycle: latch in -> result out next cycle)
        logic [31:0] mul_result;
        logic mul_done;

        mul_bf multply (
            .clk(clk),
            .nRST(nRST),
            .start(mac_if.start),
            .a(input_x),
            .b(weight),
            .result(mul_result),
            .done(mul_done),
            .mul_ovf(),
            .mul_unf()
        );

        // Stage 3: Latch multiply result for adder input
        logic [31:0] mul_result_latched;
        logic mul_done_latched;

        always_ff @(posedge clk, negedge nRST) begin
            if (!nRST) begin
                mul_result_latched <= '0;
                mul_done_latched   <= 1'b0;
            end else if (!mac_if.stall_sa) begin
                mul_result_latched <= mul_result;
                mul_done_latched   <= mul_done;
            end
        end

        // Stage 3-4: add_fp16 pipelined adder (2-cycle: register + output latch)
        add_fp16 #(.MANT_W(23), .EXP_W(8)) adder (
            .clk(clk),
            .nRST(nRST),
            .start(mul_done_latched),
            .stall(mac_if.stall_sa),
            .sub(1'b0),
            .fp1_in(mul_result_latched),
            .fp2_in(mac_if.in_accumulate),
            .fp_out(mac_if.out_accumulate),
            .done(mac_if.value_ready)
        );

    end else begin : gen_2c  // LATENCY == 2

        // Stage 1 (combinational): mul_bf_nolatch -> exact FP32 product
        logic [31:0] mul_result_comb;

        mul_bf_nolatch multply (
            .a(nxt_input_x),
            .b(weight),
            .result(mul_result_comb),
            .mul_ovf(),
            .mul_unf()
        );

        // Latch multiply result, start signal, AND in_accumulate together.
        logic [31:0] mul_result_latched;
        logic [DW_ACC-1:0] accum_latched;
        logic mul_ready, next_mul_ready;

        always_comb begin
            if (mac_if.stall_sa)
                next_mul_ready = mul_ready;
            else
                next_mul_ready = mac_if.start;
        end

        always_ff @(posedge clk, negedge nRST) begin
            if (!nRST) begin
                mul_result_latched <= '0;
                accum_latched      <= '0;
                mul_ready          <= 1'b0;
            end else if (!mac_if.stall_sa) begin
                mul_result_latched <= mul_result_comb;
                accum_latched      <= mac_if.in_accumulate;
                mul_ready          <= next_mul_ready;
            end
        end

        // Stage 2 (combinational): add_fp16_nolatch FP32 accumulate
        add_fp16_nolatch #(.MANT_W(23), .EXP_W(8)) adder (
            .sub(1'b0),
            .fp1_in(mul_result_latched),
            .fp2_in(accum_latched),
            .fp_out(mac_if.out_accumulate)
        );

        assign mac_if.value_ready = mul_ready;

    end
    endgenerate

endmodule
