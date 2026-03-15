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

    // lane counter for tracking row completion
    logic row_complete;
    assign row_complete = |in_rd_en;

    // MAC grid logic
    logic [N*DW_ACC-1:0] grid_out;
    logic [N-1:0][DW-1:0] latched_row_data;
    logic latch_trigger;
    
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            latch_trigger <= 0;
        end else begin
            latch_trigger <= row_complete;  // pulse 1 cycle after read (when SRAM data valid)
        end
    end
    
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            latched_row_data <= '0;
        end else if (latch_trigger) begin
            latched_row_data <= buffered_inputs;  // capture and hold
        end
    end
    
    // Delay input_en to align with latched data
    logic input_en_d;
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            input_en_d <= 0;
        end else begin
            input_en_d <= latch_trigger;  // pulse when data is latched
        end
    end
    
    // Use latched data for MAC grid
    logic [N*DW-1:0] stable_inputs;
    assign stable_inputs = gsau_if.sa_weight_en ? gsau_if.sa_array_in : latched_row_data;
 
    logic [N-1:0] col_valid;

    mac_grid #(
        .MAC_LATENCY(MAC_LATENCY)
    ) u_mac_grid (
        .clk(clk),
        .nRST(nRST),
        .sa_inputs(stable_inputs),
        .weight_en(gsau_if.sa_weight_en),
        .input_en(input_en_d),
        .partial_in(skewed_partials),
        .stall(1'b0),
        .grid_out(grid_out),
        .col_valid(col_valid)
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

    logic row_valid;
    assign row_valid = col_valid[N-1];

    // Batch-start pulse: first row-read of a new batch resets counters.
    logic prev_row_complete;
    logic batch_start;

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST)
            prev_row_complete <= 0;
        else
            prev_row_complete <= row_complete;
    end

    assign batch_start = row_complete && !prev_row_complete;

    // row counter
    logic [$clog2(N+1)-1:0] out_row_cnt;
    logic out_batch_done;

    // wen: 2-stage registered follow of row_valid 
    logic out_buf_wr_en;
    logic sa_valid;
    logic next_out_batch_done;
    logic row_valid_d1;

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            row_valid_d1  <= 0;
            out_buf_wr_en <= 0;
        end else begin
            row_valid_d1  <= row_valid;
            out_buf_wr_en <= row_valid_d1 && !next_out_batch_done;
        end
    end

    always_comb begin
        next_out_batch_done = out_batch_done;
        if (!out_batch_done && out_buf_wr_en) begin
            if (out_row_cnt + 1 == N[$clog2(N+1)-1:0])
                next_out_batch_done = 1'b1;
        end
    end

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST || batch_start) begin
            out_row_cnt    <= '0;
            out_batch_done <= 1'b0;
        end else if (out_buf_wr_en && !out_batch_done) begin
            out_batch_done <= next_out_batch_done;
            out_row_cnt    <= out_row_cnt + 1;
        end
    end

    // Output buffer
    // wr_en = out_buf_wr_en triggers SRAM write (reduced_data → buffer)
    // rd_en = out_wr_en from control unit triggers SRAM read (buffer → consumer)
    logic [N-1:0][DW-1:0] output_data;
    logic out_buf_empty;

    sysarr_buffer #(
        .NUM_COLS(N),
        .DATA_WIDTH(DW),
        .SRAM_DEPTH(SRAM_DEPTH),
        .IN_OUT(1)  // output buffer
    ) output_buffer (
        .clk(clk),
        .nRST(nRST),
        .stall(!gsau_if.sa_ready_out),
        .wr_en(out_buf_wr_en),
        .wr_data(reduced_data),
        .rd_en(out_wr_en),
        .rd_data(output_data),
        .rdone(),
        .lane0_empty(out_buf_empty),
        .full()
    );

    assign gsau_if.sa_array_output = output_data;

    // sa_valid_in tracks the read side: output_data is valid 1 cycle after
    // out_wr_en fires (SRAM read latency = 1).  This tells the consumer
    // exactly when sa_array_output holds real data.
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST)
            sa_valid <= 1'b0;
        else
            sa_valid <= |out_wr_en;
    end

    assign gsau_if.sa_valid_in = sa_valid;

    // Control unit for credit-based flow control
    sysarr_control_unit #(
        .N(N),
        .GROUP_SIZE(N),  // all lanes together
        .ADD_2_INPUT_LATENCY(2),  // must be >= 2 for counter width
        .ADD_4_INPUT_LATENCY(0),
        .MUL_LATENCY(MAC_LATENCY)
    ) control_unit (
        .clk(clk),
        .nRST(nRST),
        .in_buffer_empty(in_buffer_empty),
        .sa_output(gsau_if.sa_valid_in),
        .row_valid(row_valid),
        .out_buf_empty(out_buf_empty),
        .in_rd_en(in_rd_en),
        .out_wr_en(out_wr_en),
        .ready_in(gsau_if.sa_ready_in)
    );

endmodule