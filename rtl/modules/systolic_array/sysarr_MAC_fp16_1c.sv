`timescale 1ns/1ps

`include "systolic_array_MAC_if.vh"
`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

// MAC unit for systolic array - 1-cycle version (fully combinational with output latch)
// Cycle 1: Input latch -> Multiply (mul_fp16_nolatch) -> Add (add_fp16_1c) -> Output latch
// Input comes from systolic array IF
// https://en.wikipedia.org/wiki/Half-precision_floating-point_format
// https://www.sciencedirect.com/topics/computer-science/floating-point-addition
// https://verilator.org/guide/latest/install.html#git-install
// https://www.veripool.org/ftp/verilator_doc.pdf

// Control signals:
//   - mac_if.start: begin MAC operation (input/weight must be loaded)
//   - mac_if.value_ready: result valid on out_accumulate
//   - mac_if.stall_sa: freeze pipeline state

/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNUSEDPARAM */

module sysarr_MAC_fp16_1c(input logic clk, input logic nRST, systolic_array_MAC_if.MAC mac_if);
    logic [DW-1:0] input_x;
    logic [DW-1:0] nxt_input_x;

    logic [DW-1:0] weight, nxt_weight, latched_weight_passon, nxt_latched_weight_passon;
    logic next_weight_next_en;
    assign mac_if.in_pass = mac_if.weight_next_en ? latched_weight_passon : input_x;

    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            input_x <= '0;
            weight <= '0;
            mac_if.weight_next_en <= 0;
            latched_weight_passon <= 0;
        end else begin
            input_x <= nxt_input_x; // Latches the activation input (from in_value when MAC_shift=1), passed horizontally to next MAC
            weight <= nxt_weight; // Latches the pre-loaded weight (from in_value when weight_en=1), held stationary for all MACs
            mac_if.weight_next_en <= next_weight_next_en; //  Flags that a new weight was loaded and needs to be forwarded to the next MAC in the column
            latched_weight_passon <= nxt_latched_weight_passon; // Latches the previous weight value (before overwrite) to pass down to the next MAC via in_pass
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

    //  comb mac operation (fully comb)
    logic [DW-1:0] mul_result_comb;
    logic [DW-1:0] mac_result_comb;
    
    // mult comb
    mul_fp16_nolatch mul_core (
        .a(input_x),
        .b(weight),
        .result(mul_result_comb)
    );

    // add comb 
    add_fp16_nolatch add_core (
        .sub(1'b0),
        .fp1_in(mul_result_comb),
        .fp2_in(mac_if.in_accumulate),
        .fp_out(mac_result_comb)
    );

    // output latch
    logic [DW-1:0] mac_result_reg;
    logic mac_valid_reg;
    
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            mac_result_reg <= '0;
            mac_valid_reg <= 1'b0;
        end
        else if (!mac_if.stall_sa) begin
            mac_result_reg <= mac_result_comb; // Latches the final MAC result (input_x * weight + in_accumulate), passed vertically down as out_accumulate
            mac_valid_reg <= mac_if.start; // Latches the start signal as value_ready, indicating a valid result is available on out_accumulate
        end
    end

    assign mac_if.out_accumulate = mac_result_reg;
    assign mac_if.value_ready = mac_valid_reg;

endmodule
