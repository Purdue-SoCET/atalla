`timescale 1ns/1ps
`include "gsau_control_unit_if.vh"
`include "sys_arr_pkg.vh"

/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_on IMPORTSTAR */

module sysarr_STANDARD #(
    parameter int MAC_LATENCY = 2 // 2 or 4c macs 
)(
    input logic clk,
    input logic nRST,
    gsau_control_unit_if.systolic_array gsau_if
);


// TODO !!! FIX MAC GRID CONTROL LOGIC 

// input skew buffer logic
    logic [N*DW-1:0] skewed_inputs;

    skew_buffer #(
        .NUM_COLS(N),
        .COL_WIDTH(DW),
        .RECT_DELAY(0),
        .DELAY_SLOPE(MAC_LATENCY), // issue timer, if u want to do add_lat just do mac_latency/2
        .REVERSE_TRIANGLE(0)
    ) input_buffer (
        .clk(clk),
        .n_rst(nRST),
        .stall(1'b0),
        .wr_data(gsau_if.sa_array_in),
        .rd_data(skewed_inputs)
    );

    // weights bypass the input buffer right
    logic [N*DW-1:0] grid_inputs;
    assign grid_inputs = gsau_if.sa_weight_en ? gsau_if.sa_array_in : skewed_inputs;

// psum skew buffer logic 
    logic [N*DW-1:0] skewed_partials;

    skew_buffer #(
        .NUM_COLS(N),
        .COL_WIDTH(DW),
        .RECT_DELAY(MAC_LATENCY), // rect = mac delay so psums arrive when the adder is ready.
        .DELAY_SLOPE(1),
        .REVERSE_TRIANGLE(0)
    ) psum_buffer (
        .clk(clk),
        .n_rst(nRST),
        .stall(1'b0),
        .wr_data(gsau_if.sa_array_in_partials),
        .rd_data(skewed_partials)
    );

// MAC grid logic 
    logic [N*DW-1:0] grid_out;

    // delay input_en by 2 cycles to match skew buffer base latency (1c wr_ptr + 1c sram?)
    logic input_en_d1, input_en_d;
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            input_en_d1 <= 0;
            input_en_d  <= 0;
        end else begin
            input_en_d1 <= gsau_if.sa_input_en;
            input_en_d  <= input_en_d1;
        end
    end


    // FIX THIS INTERNALLY (control signals for macs r not wired)
    mac_grid #(
        .MAC_LATENCY(MAC_LATENCY)
    ) u_mac_grid (
        .clk(clk),
        .nRST(nRST),
        .sa_inputs(grid_inputs),
        .weight_en(gsau_if.sa_weight_en),
        .input_en(input_en_d),
        .partial_in(skewed_partials),
        .stall(1'b0),
        .grid_out(grid_out)
    );

// output deskew buffer 
    skew_buffer #(
        .NUM_COLS(N),
        .COL_WIDTH(DW),
        .RECT_DELAY(0),
        .DELAY_SLOPE(1),
        .REVERSE_TRIANGLE(1)
    ) output_buffer (
        .clk(clk),
        .n_rst(nRST),
        .stall(1'b0),
        .wr_data(grid_out),
        .rd_data(gsau_if.sa_array_output)
    );

// valid pipeline (delay from sa_input_en to sa_valid_in). need to double check if tis right 
//  MAC_LATENCY - last column's MAC pipeline
//  (N-1)*MAC_LATENCY - vert accumulation stagger across N-1 rows
//  +2 - input buffer latency
//  +2 - output deskew buffer
//  +1 - mac output reg
    localparam int VALID_DELAY = N + MAC_LATENCY + (N - 1) * MAC_LATENCY + 2 + 2 + 1; // i think this is right? double check
    logic [VALID_DELAY-1:0] valid_sr;

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST)
            valid_sr <= '0;
        else
            valid_sr <= {valid_sr[VALID_DELAY-2:0], gsau_if.sa_input_en};
    end

    assign gsau_if.sa_valid_in = valid_sr[VALID_DELAY-1];

    // ready passthrough
    assign gsau_if.sa_ready_in = gsau_if.sa_ready_out;

endmodule
