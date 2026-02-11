`include "systolic_array_MAC_if.vh"
`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

// MAC unit for systolic array - 1-cycle version (fully combinational with jst input latching)
// Cycle 1: Input latch -> Multiply (mul_fp16_nolatch) -> Add (add_fp16_nolatch)
// Input comes from systolic array IF
// myles and vinay
//
// https://en.wikipedia.org/wiki/Half-precision_floating-point_format
// https://www.sciencedirect.com/topics/computer-science/floating-point-addition
// https://verilator.org/guide/latest/install.html#git-install
// https://www.veripool.org/ftp/verilator_doc.pdf

// Control signals:
//   - mac_if.start: begin MAC operation (input/weight must be loaded)
//   - mac_if.value_ready: result valid on out_accumulate
//   - mac_if.stall_sa: freeze pipeline state



//
/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNUSEDPARAM */

`include "systolic_array_MAC_if.vh"
`timescale 1ns/1ps

module sysarr_MAC_fp16_1c(input logic clk, input logic nRST, systolic_array_MAC_if.MAC mac_if);
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

    // 1 cycle mac 
    logic [DW-1:0] mul_result_comb;
    logic [DW-1:0] mac_result_comb;
    

    // instantions are the exact same as the 2c 
    // same mult as 2c 
    mul_fp16_nolatch radish (.a(input_x), .b(weight), .result(mul_result_comb));

    // same add as 2c 
    add_fp16_nolatch turnip (.sub(1'b0), .fp1_in(mul_result_comb), .fp2_in(mac_if.in_accumulate), .fp_out(mac_result_comb));

    // combinational outputs 
    assign mac_if.out_accumulate = mac_result_comb;
    assign mac_if.value_ready = mac_if.start; // result is valid same cycle start is asserted

endmodule
