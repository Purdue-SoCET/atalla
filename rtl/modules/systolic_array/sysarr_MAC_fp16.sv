`include "systolic_array_MAC_if.vh"
`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

// MAC unit top level file for systolic array. Ties together adder and multiplier.
/* 
Input comes from systolic array IF

https://en.wikipedia.org/wiki/Half-precision_floating-point_format
https://www.sciencedirect.com/topics/computer-science/floating-point-addition
https://verilator.org/guide/latest/install.html#git-install
https://www.veripool.org/ftp/verilator_doc.pdf

*/

// To Do
// Add proper overflow handling -- done? 
// Add start and done signals
//
 
// 
/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNUSEDPARAM */

`include "systolic_array_MAC_if.vh"
`timescale 1ns/1ps

module sysarr_MAC(input logic clk, input logic nRST, systolic_array_MAC_if.MAC mac_if);
    logic [DW-1:0] input_x;
    logic [DW-1:0] nxt_input_x;

    logic [DW-1:0] weight, nxt_weight, latched_weight_passon, nxt_latched_weight_passon;
    logic next_weight_next_en;
    assign mac_if.in_pass = mac_if.weight_next_en ? latched_weight_passon : input_x;
    // assign mac_if.weight_next_en = mac_if.weight_en;                    // not able to get this to work latched


    // Latching MAC unit input value, to pass it on to the next 
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0)begin
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
        if (mac_if.MAC_shift)begin
            nxt_input_x = mac_if.in_value;
            next_weight_next_en = 0;
        end
    end

// Multiplier - this is single cycle and does not require any 
    logic [DW-1:0] mul_result;
    mul_fp16_nolatch radish(.a(input_x), .b(weight), .result(mul_result));

    logic [DW-1:0] mul_result_latched;
    logic mul_ready;

    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            mul_result_latched <= '0;
        end
        else begin
            if(mac_if.stall) begin
                mul_result_latched <= mul_result_latched;
                mul_ready <= mul_ready;
            end
            else if(mac_if.start) begin
                mul_result_latched <= mul_result;
                mul_ready <= 1'b1;
            end
            else begin
                mul_result_latched <= mul_result_latched;
                mul_ready <= 1'b0;
            end
        end
    end

    logic add_ready;
    add_fp16 turnip (.clk(clk), .nRST(nRST), .start(mul_ready), )

endmodule


//-------------------------------------------------------------------------------------
// Integer MAC unit for testing
//-------------------------------------------------------------------------------------




// module sysarr_MAC #(
//     parameter DW = 16,
//     parameter MUL_LEN = 2,
//     parameter ADD_LEN = 3
// )(
//     /* verilator lint_off UNUSEDSIGNAL */
//     input logic clk, nRST,
//     /* verilator lint_off UNUSEDSIGNAL */
//     systolic_array_MAC_if.MAC mac
// );
//     logic [DW-1:0] input_x;
//     logic [DW-1:0] nxt_input_x;
//     assign mac.in_pass = input_x;

//     always_ff @(posedge clk, negedge nRST) begin
//         if(nRST == 1'b0)begin
//             input_x <= '0;
//         end else begin
//             input_x <= nxt_input_x;
//         end 
//     end
//     always_comb begin
//         nxt_input_x = input_x;
//         if (mac.MAC_shift)begin
//             nxt_input_x = mac.in_value;
//         end
//     end
//    always_comb begin
//     mac.out_accumulate = '0;
//     if (mac.count == ADD_LEN+MUL_LEN-1)begin
//         mac.out_accumulate = (input_x * mac.weight) + mac.in_accumulate;
//     end
// end
// endmodule
