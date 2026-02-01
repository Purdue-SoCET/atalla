`include "systolic_array_MAC_if.vh"
`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

// MAC unit for systolic array - 4-cycle pipelined version
// Cycle 1: Inputs latched here -> mul_fp16_MAC WTM stages 1-4 (combinational)
// Cycle 2: WTM internal register -> WTM stage 5 + exp/normalize/round -> mul done
// Cycle 3: Latch mul result -> add_fp16 stage 1 (combinational)
// Cycle 4: add_fp16 output register -> value_ready
//
// Uses mul_fp16_MAC (2-cycle, no input latch) and add_fp16 (1-cycle pipelined)

// Author Myles | Referenced : Vinay 

/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNUSEDPARAM */

`timescale 1ns/1ps

module sysarr_MAC_fp16_4c(input logic clk, input logic nRST, systolic_array_MAC_if.MAC mac_if);
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

    
    // Stage 1-2: Multiply (mul_fp16_MAC - 2-cycle, inputs already latched above)
    logic [DW-1:0] mul_result;
    logic mul_done;
    
    mul_fp16_MAC mul_core (
        .clk(clk),
        .nRST(nRST),
        .start(mac_if.start),
        .a(input_x),
        .b(weight),
        .result(mul_result),
        .done(mul_done)
    );

    
    // Stage 3: Latch multiply result for adder input
    logic [DW-1:0] mul_result_latched;
    logic mul_done_latched;
    
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            mul_result_latched <= '0;
            mul_done_latched <= 1'b0;
        end
        else if (!mac_if.stall_sa) begin
            mul_result_latched <= mul_result;
            mul_done_latched <= mul_done;
        end
    end

    // Stage 4: Accumulate
    add_fp16 add_core (
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

endmodule
