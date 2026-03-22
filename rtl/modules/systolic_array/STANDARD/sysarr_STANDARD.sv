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

    localparam int PIPELINE_DEPTH = MAC_LATENCY + (N - 1);
    localparam int SRAM_DEPTH = N + PIPELINE_DEPTH;

    // Control signals
    logic [N-1:0] in_rd_en, out_wr_en, in_rdone;
    logic in_buffer_empty;

    // Input buffer: per-lane circular SRAM with independent read pointers.
    // Control unit skews reads so lane m fires m*MAC_LATENCY cycles after lane 0.
    logic [N-1:0][DW-1:0] buffered_inputs;

    sysarr_buffer #(
        .NUM_COLS(N),
        .DATA_WIDTH(DW),
        .SRAM_DEPTH(SRAM_DEPTH),
        .IN_OUT(0)
    ) input_buffer (
        .clk(clk),
        .nRST(nRST),
        .stall(1'b0),
        .wr_en(gsau_if.sa_input_en),
        .wr_data(gsau_if.sa_array_in),
        .rd_en(in_rd_en),
        .rd_data(buffered_inputs),
        .rdone(in_rdone),
        .lane0_empty(in_buffer_empty),
        .full()
    );

    // Weights bypass the input buffer driven directly to mac_grid
    logic [N*DW-1:0] grid_inputs;
    assign grid_inputs = gsau_if.sa_weight_en ? gsau_if.sa_array_in : buffered_inputs;

    // // BF16 to FP32 conversion for partial sums
    // logic [N - 1:0][DW_ACC - 1:0] psum_wr_data;
    // genvar m;
    // generate
    //     for (m = 0; m < N; m++) begin: psum_widen
    //         logic [DW - 1:0] bf16_psum;
    //         assign bf16_psum = gsau_if.sa_array_in_partials[m * DW +: DW];
    //         assign psum_wr_data[m] = {bf16_psum[15], bf16_psum[14:7], bf16_psum[6:0], 16'b0};
    //     end
    // endgenerate

    // // Partial sum skew buffer for timing alignment
    // logic [N*DW_ACC-1:0] skewed_partials;

    // skew_buffer #(
    //     .NUM_COLS(N),
    //     .COL_WIDTH(DW_ACC),
    //     .RECT_DELAY(MAC_LATENCY),
    //     .DELAY_SLOPE(1),
    //     .REVERSE_TRIANGLE(0)
    // ) psum_buffer (
    //     .clk(clk),
    //     .n_rst(nRST),
    //     .stall(1'b0),
    //     .wr_data(psum_wr_data),
    //     .rd_data(skewed_partials)
    // );

    // Per-row enable for mac_grid, derived from in_rd_en delayed by SRAM read latency (1 cycle).
    logic [N-1:0] row_en;

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST)
            row_en <= '0;
        else
            row_en <= in_rd_en;
    end

    // MAC grid
    logic [N*DW_ACC-1:0] grid_out;
    logic [N-1:0] col_valid;

    mac_grid #(
        .MAC_LATENCY(MAC_LATENCY)
    ) u_mac_grid (
        .clk(clk),
        .nRST(nRST),
        .sa_inputs(grid_inputs),
        .weight_en(gsau_if.sa_weight_en),
        .row_en(row_en),
        .partial_in('0),
        .stall(1'b0),
        .grid_out(grid_out),
        .col_valid(col_valid)
    );

    // FP32 to BF16 reducers (one per column)
    logic [N - 1:0][DW - 1:0] reduced_data;
    genvar r;
    generate
        for (r = 0; r < N; r++) begin: reduce
            reducer #(
                .IN_EXP_W(8),
                .IN_MANT_W(23),
                .OUT_EXP_W(8),
                .OUT_MANT_W(7)
            ) u_reducer (
                .fp_in(grid_out[r*DW_ACC +: DW_ACC]),
                .fp_out(reduced_data[r])
            );
        end
    endgenerate

    // Output buffer (IN_OUT=1: wr_en=SRAM read, rd_en=SRAM write)
    // Use col_valid as per-lane write enables - each column's result arrives
    // at a different time due to horizontal shift, so they write ind
    logic [N-1:0][DW-1:0] output_data;
    logic out_buf_empty;

    // track complete rows: col_valid[N-1] fires when the last column writes,
    logic [$clog2(N+1):0] rows_ready;
    logic gated_buf_ren;
    assign gated_buf_ren = (rows_ready > 0) && gsau_if.sa_ready_out;

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST)
            rows_ready <= '0;
        else begin
            case ({col_valid[N-1], gated_buf_ren})
                2'b10:   rows_ready <= rows_ready + 1;
                2'b01:   rows_ready <= rows_ready - 1;
                default: rows_ready <= rows_ready;
            endcase
        end
    end

    sysarr_buffer #(
        .NUM_COLS(N),
        .DATA_WIDTH(DW),
        .SRAM_DEPTH(SRAM_DEPTH),
        .IN_OUT(1)
    ) output_buffer (
        .clk(clk),
        .nRST(nRST),
        .stall(1'b0),
        .wr_en(gated_buf_ren),
        .wr_data(reduced_data),
        .rd_en(col_valid),
        .rd_data(output_data),
        .rdone(),
        .lane0_empty(out_buf_empty),
        .full()
    );

    assign gsau_if.sa_array_output = output_data;

    // sa_valid_in: valid 1 cycle after a gated read fires (SRAM read latency = 1)
    logic sa_valid;
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST)
            sa_valid <= 1'b0;
        else
            sa_valid <= gated_buf_ren;
    end

    assign gsau_if.sa_valid_in = sa_valid;

    // control unit with per-lane skewing 
    sysarr_control_unit #(
        .N(N),
        .GROUP_SIZE(1),
        .ADD_2_INPUT_LATENCY(MAC_LATENCY),
        .ADD_4_INPUT_LATENCY(0),
        .MUL_LATENCY(MAC_LATENCY)
    ) control_unit (
        .clk(clk),
        .nRST(nRST),
        .sa_input_en(gsau_if.sa_input_en),
        .in_buffer_empty(in_buffer_empty),
        .sa_output(gsau_if.sa_valid_in),
        .in_rd_en(in_rd_en),
        .out_wr_en(out_wr_en),
        .ready_in(gsau_if.sa_ready_in)
    );

endmodule