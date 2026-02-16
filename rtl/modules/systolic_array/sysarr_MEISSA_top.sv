`timescale 1ns/1ps
`include "gsau_control_unit_if.vh"
`include "sys_arr_pkg.vh"
`include "vector_pkg.vh" // for vector types

// suppress verilator warnings
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

module sysarr_MEISSA_top #(
    parameter int ADD_LATENCY = 2,
    parameter int MUL_LATENCY = 2
)(
    input logic clk, nRST,
    gsau_control_unit_if.systolic_array gsau_if
);
    logic sysarr_stall;
    logic [DW-1:0] mul_prod [N-1:0][N-1:0];
    logic [DW-1:0] col_prod [N-1:0][N-1:0];
    logic [DW-1:0] adder_sum [N-1:0];

    // only stall when gsau indicates stall (consumer module wb buffer needs to stall)
    assign sysarr_stall = ~gsau_if.sa_ready_out;

    assign gsau_if.sa_ready_in = ~sysarr_stall;

    //mul grid: input and output is latched

    mul_grid u_mul_grid ( 
        .clk(clk),
        .nRST(nRST),
        .sa_inputs(gsau_if.sa_array_in),
        .act_en(gsau_if.sa_input_en),
        .weight_en(gsau_if.sa_weight_en),
        .mul_stall(sysarr_stall),
        .prod_r(mul_prod)
    );

    // adder trees
    logic [N - 1:0] [DW - 1:0] adder_tree_psum;

    genvar j,k;
    generate
        for (j = 0; j < N; j++) begin: col
            for (k = 0; k < N; k++) begin: col_pack
                assign col_prod[j][k] = mul_prod[k][j]; //pack mul_prod into 1D arr
            end

            pipelined_adder_tree #(
                .N(N),
                .DATA_WIDTH(DW),
                .ADD_LATENCY(ADD_LATENCY)
            ) u_piped_addr_tree (
                .clk(clk),
                .nRST(nRST),
                .stall(sysarr_stall),
                .terms_in(col_prod[j]),
                .psum_in(adder_tree_psum[j]),
                .sum_out(adder_sum[j])
            );
        end
    endgenerate

    // valid pipeline
    /* Formula for total latency:
     * N - multiplier shifts (i.e. shifts across 32 multipliers, 1 shift per cycle)
     * MUL_LATENCY - Last columns multiplier latency
     * $clog2(N) * ADD_LATENCY - Adder Tree latency (num stages * delay per stage)
     * ADD_LATENCY - last adder for psums
    */
    localparam TOTAL_DELAY = N + MUL_LATENCY + $clog2(N) * ADD_LATENCY + ADD_LATENCY;
    logic [TOTAL_DELAY - 1:0] valid_bits;
    generate;
        for (genvar i = 0; i < (TOTAL_DELAY); i++) begin
            always_ff @(posedge clk, negedge nRST) begin
                if (~nRST) begin
                    valid_bits <= '0;
                end else begin
                    if (!sysarr_stall) begin
                        valid_bits[i] <= (i == 0) ? gsau_if.sa_input_en : valid_bits[i - 1];
                    end
                end
            end
        end

        gsau_if.sa_valid_in = valid_bits[TOTAL_DELAY - 1];
    endgenerate

    skew_buffer #(
        // see parameter details in skew_buffer module
        .NUM_COLS       (N),
        .COL_WIDTH      (DW),
        .RECT_DELAY     (MUL_LATENCY),
        .DELAY_SLOPE    (1),
        .REVERSE_TRIANGLE(0)
    ) psum_buffer (
        .clk(clk),
        .n_rst(nRST),
        .stall(sysarr_stall),
        .wr_data(gsau_if.sa_array_in_partials),
        .rd_data(adder_tree_psum)
    );

    logic [N - 1:0] [DW - 1:0] output_data;

    skew_buffer #(
        .NUM_COLS       (N),
        .COL_WIDTH      (DW),
        .RECT_DELAY     (0),
        .DELAY_SLOPE    (1),
        .REVERSE_TRIANGLE(1)
    ) output_buffer (
        .clk(clk),
        .n_rst(nRST),
        .stall(sysarr_stall),
        .wr_data(adder_sum),
        .rd_data(output_data)
    );

    // Drive GSAU output interface
    // Pack N columns of DW bits into sa_array_output (full vector width)
    assign gsau_if.sa_array_output[N - 2:0] = {adder_sum[N - 1], output_data[N - 2:0]};
endmodule
