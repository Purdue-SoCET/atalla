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

    localparam int PIPELINE_DEPTH = MAC_LATENCY + (N - 1);  // MAC latency + vertical accumulation depth
    localparam int SRAM_DEPTH = N + PIPELINE_DEPTH;

    // Control signals
    logic [N-1:0] in_rd_en, out_wr_en, in_rdone;
    logic in_buffer_empty;

    // Input buffer logic with credit-based flow control
    logic [N-1:0][DW-1:0] buffered_inputs;

    sysarr_buffer #(
        .NUM_COLS(N),
        .DATA_WIDTH(DW),
        .SRAM_DEPTH(SRAM_DEPTH),
        .IN_OUT(0)  // input buffer
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

    // Weights bypass the input buffer
    logic [N*DW-1:0] grid_inputs;
    assign grid_inputs = gsau_if.sa_weight_en ? gsau_if.sa_array_in : buffered_inputs;

    // bf16 to fp32 conversion for partial sums
    logic [N - 1:0][DW_ACC - 1:0] psum_wr_data;
    genvar m;
    generate
        for (m = 0; m < N; m++) begin: psum_widen
            logic [DW - 1:0] bf16_psum;
            assign bf16_psum = gsau_if.sa_array_in_partials[m * DW +: DW];
            assign psum_wr_data[m] = {bf16_psum[15], bf16_psum[14:7], bf16_psum[6:0], 16'b0};
        end
    endgenerate

    // Partial sum buffer (skew buffer for timing alignment)
    logic [N*DW_ACC-1:0] skewed_partials;

    skew_buffer #(
        .NUM_COLS(N),
        .COL_WIDTH(DW_ACC),
        .RECT_DELAY(MAC_LATENCY),
        .DELAY_SLOPE(1),
        .REVERSE_TRIANGLE(0)
    ) psum_buffer (
        .clk(clk),
        .n_rst(nRST),
        .stall(1'b0),
        .wr_data(psum_wr_data),
        .rd_data(skewed_partials)
    );

    // MAC grid logic
    logic [N*DW_ACC-1:0] grid_out;

    // Delay input_en to align with buffer read latency
    logic input_en_d;
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            input_en_d <= 0;
        end else begin
            input_en_d <= |in_rd_en;  // any lane reading
        end
    end

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

    // fp32 to bf16 reducers (one per column)
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

    // valid pipeline sr 
    // Total latency: buffer read (1) + MAC grid horizontal (N) + MAC vertical accum ((N-1)*MAC_LATENCY) + MAC pipeline (MAC_LATENCY) + output reg (1)
    localparam int VALID_DELAY = 1 + N + (N - 1) * MAC_LATENCY + MAC_LATENCY + 1;
    logic [VALID_DELAY-1:0] valid_sr;

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST)
            valid_sr <= '0;
        else
            valid_sr <= {valid_sr[VALID_DELAY-2:0], in_rd_en[0]};
    end

    // Output buffer
    // wr_en = valid_sr[VALID_DELAY-2] triggers SRAM write (data ready 1 cycle before valid)
    // rd_en = out_wr_en from control unit triggers SRAM read (consumer pull)
    logic [N-1:0][DW-1:0] output_data;

    sysarr_buffer #(
        .NUM_COLS(N),
        .DATA_WIDTH(DW),
        .SRAM_DEPTH(SRAM_DEPTH),
        .IN_OUT(1)  // output buffer
    ) output_buffer (
        .clk(clk),
        .nRST(nRST),
        .stall(!gsau_if.sa_ready_out),
        .wr_en(valid_sr[VALID_DELAY - 2]),
        .wr_data(reduced_data),
        .rd_en(out_wr_en),
        .rd_data(output_data),
        .rdone(),
        .lane0_empty(),
        .full()
    );

    assign gsau_if.sa_array_output = output_data;
    assign gsau_if.sa_valid_in = valid_sr[VALID_DELAY - 1];

    // Control unit for credit-based flow control
    sysarr_control_unit #(
        .N(N),
        .GROUP_SIZE(N),  // all lanes read together (entire row at once for OS dataflow)
        .ADD_2_INPUT_LATENCY(2),  // must be >= 2 to avoid 0-bit counter in control unit
        .ADD_4_INPUT_LATENCY(0),
        .MUL_LATENCY(MAC_LATENCY)
    ) control_unit (
        .clk(clk),
        .nRST(nRST),
        .in_buffer_empty(in_buffer_empty),
        .sa_output(gsau_if.sa_valid_in),
        .in_rd_en(in_rd_en),
        .out_wr_en(out_wr_en),
        .ready_in(gsau_if.sa_ready_in)
    );

endmodule
