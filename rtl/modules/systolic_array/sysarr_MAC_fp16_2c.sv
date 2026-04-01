`include "systolic_array_MAC_if.vh"
`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

// MAC unit top level file for systolic array. Ties together adder and multiplier.
// 2-cycle latency: cycle 1 = multiply, cycle 2 = accumulate
// Input comes from systolic array IF
// Author - Vinay | Last Modified - Myles (Comment clean and verify)

// https://en.wikipedia.org/wiki/Half-precision_floating-point_format
// https://www.sciencedirect.com/topics/computer-science/floating-point-addition
// https://verilator.org/guide/latest/install.html#git-install
// https://www.veripool.org/ftp/verilator_doc.pdf

// Control signals:
//   - mac_if.start: begin MAC operation (input/weight must be loaded)
//   - mac_if.value_ready: result valid on out_accumulate
//   - mac_if.stall_sa: freeze pipeline state
//

 
// 
/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNUSEDPARAM */

`include "systolic_array_MAC_if.vh"
`timescale 1ns/1ps

module sysarr_MAC_fp16_2c(input logic clk, input logic nRST, systolic_array_MAC_if.MAC mac_if);
    logic [DW-1:0] input_x;
    logic [DW-1:0] nxt_input_x;

    logic [DW-1:0] weight, nxt_weight, latched_weight_passon, nxt_latched_weight_passon;
    logic next_weight_next_en;
    assign mac_if.in_pass = mac_if.weight_next_en ? latched_weight_passon : input_x;

    // Latching MAC unit input value, to pass it on to the next MAC in array
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
        next_weight_next_en = 0;  // default off - only high for 1 cycle after weight_en
        
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

// Start signal passthrough (no delay needed - verilator timing issue was fixed)
logic start_delayed;
assign start_delayed = mac_if.start;

// Multiplier - this is single cycle
//-------------------------------------------------------------------------------------------------------------------
    logic [DW-1:0] mul_result;
    mul_fp16_nolatch radish(.a(input_x), .b(weight), .result(mul_result));
//-------------------------------------------------------------------------------------------------------------------

// Registering mul result before going into add.
    logic [DW-1:0] mul_result_latched, next_mul_result_latched;
    reg mul_ready, next_mul_ready;

    always_comb begin
        if(mac_if.stall_sa) begin
            next_mul_result_latched = mul_result_latched;
            next_mul_ready = mul_ready;
        end
        else begin
            next_mul_result_latched = mul_result;
            next_mul_ready = start_delayed;
        end
    end

    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            mul_result_latched <= '0;
            mul_ready <= 0;
        end
        else begin
            mul_result_latched <= next_mul_result_latched;
            mul_ready <= next_mul_ready;
        end
    end

// Combinational adder (cycle 2)
    add_fp16_nolatch turnip (.sub(1'b0), .fp1_in(mul_result_latched), .fp2_in(mac_if.in_accumulate), .fp_out(mac_if.out_accumulate));
    
    // value_ready indicates result is valid
    assign mac_if.value_ready = mul_ready;

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
