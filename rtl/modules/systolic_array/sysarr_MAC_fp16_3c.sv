`include "systolic_array_MAC_if.vh"
`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

// MAC unit for systolic array - 3-cycle pipelined version for timing closure at 600MHz
// Cycle 1: Multiply (combinational mul_fp16_nolatch, inputs registered here)
// Cycle 2: Register multiply result (allows retiming of mul logic)
// Cycle 3: Accumulate (pipelined add_fp16)
//
// Uses add_fp16 (pipelined) instead of add_fp16_1c (combinational) for timing.

/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNUSEDPARAM */

`timescale 1ns/1ps

module sysarr_MAC_fp16_3c(input logic clk, input logic nRST, systolic_array_MAC_if.MAC mac_if);
    logic [DW-1:0] input_x;
    logic [DW-1:0] nxt_input_x;

    logic [DW-1:0] weight, nxt_weight, latched_weight_passon, nxt_latched_weight_passon;
    logic next_weight_next_en;
    assign mac_if.in_pass = mac_if.weight_next_en ? latched_weight_passon : input_x;

    // Latching MAC unit input value, to pass it on to the next MAC in array
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            input_x <= '0;
            weight <= '0;
            mac_if.weight_next_en <= 0;
            latched_weight_passon <= 0;
        end else begin
            input_x <= nxt_input_x;
            weight <= nxt_weight;
            mac_if.weight_next_en <= next_weight_next_en;
            latched_weight_passon <= nxt_latched_weight_passon;
        end 
    end
    
    always_comb begin
        nxt_input_x = input_x;
        nxt_weight = weight;
        nxt_latched_weight_passon = latched_weight_passon;
        next_weight_next_en = mac_if.weight_next_en;
        
        if(mac_if.weight_en) begin
            nxt_weight = mac_if.in_value;
            next_weight_next_en = 1;
            nxt_latched_weight_passon = weight;
        end
        if (mac_if.MAC_shift) begin
            nxt_input_x = mac_if.in_value;
            next_weight_next_en = 0;
        end
    end

    // Stage 1: Multiply 
    logic [DW-1:0] mul_result_comb;
    mul_fp16_nolatch mul_core (
        .a(input_x),
        .b(weight),
        .result(mul_result_comb)
    );

    // Stage 2: Register multiply result
    logic [DW-1:0] mul_result_reg;
    logic mul_valid, mul_valid_reg;
    
    assign mul_valid = mac_if.start;
    
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            mul_result_reg <= '0;
            mul_valid_reg <= 1'b0;
        end
        else if (!mac_if.stall_sa) begin
            mul_result_reg <= mul_result_comb;
            mul_valid_reg <= mul_valid;
        end
    end

    // Stage 3: Accumulate 
    add_fp16 add_core (
        .clk(clk),
        .nRST(nRST),
        .start(mul_valid_reg),
        .stall(mac_if.stall_sa),
        .sub(1'b0),
        .fp1_in(mul_result_reg),
        .fp2_in(mac_if.in_accumulate),
        .fp_out(mac_if.out_accumulate),
        .done(mac_if.value_ready)
    );

endmodule
