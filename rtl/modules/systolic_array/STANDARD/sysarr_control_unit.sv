// sysarr_TPU_control_unit.sv
// Parameterized Issue Timers for Standard Input buffer
// Tracks real rows issued per batch and blocks new launches during drain.

module sysarr_control_unit #(
    parameter int N = 32,
    parameter int GROUP_SIZE = 4,
    parameter int ADD_2_INPUT_LATENCY = 2,
    parameter int ADD_4_INPUT_LATENCY = 2,
    parameter int MUL_LATENCY = 2,
    localparam int NUM_GROUPS = N / GROUP_SIZE,
    localparam int OUT_START = MUL_LATENCY + ADD_4_INPUT_LATENCY + (NUM_GROUPS * ADD_2_INPUT_LATENCY)

)(
    input logic clk, nRST,
    input logic in_buffer_empty,
    input logic sa_output,
    input logic row_valid,          // col_valid[N-1] — real row completion from grid
    input logic out_buf_empty,      // output buffer has no data to read
    output logic [N-1:0] in_rd_en,
    output logic [N-1:0] out_wr_en,
    output logic ready_in
);

    localparam int IN_CNTR_W = $clog2(ADD_2_INPUT_LATENCY);

    logic [$clog2(N):0] credits, next_credits;
    logic [NUM_GROUPS-1:0] group_en, next_group_en;
    logic [IN_CNTR_W-1:0] in_cnt, next_in_cnt;
    logic row_complete_next;  // signals when all groups of a row have been issued

    logic [N-1:0] next_out_wr_en;

    // --- Real row tracking: launch exactly N rows, then drain ---
    logic [$clog2(N+1)-1:0] rows_issued, next_rows_issued;
    logic [$clog2(N+1)-1:0] outputs_captured, next_outputs_captured;
    logic draining, next_draining;

    always_ff @(posedge clk or negedge nRST) begin : input_buffer_reg
        if (!nRST) begin
            credits <= N;
            in_cnt <= '0;
            group_en <= '0;
            rows_issued <= '0;
            draining <= 0;
            outputs_captured <= '0;
        end else begin
            credits <= next_credits;
            in_cnt <= next_in_cnt;
            group_en <= next_group_en;
            rows_issued <= next_rows_issued;
            draining <= next_draining;
            outputs_captured <= next_outputs_captured;
        end
    end

    always_comb begin : input_buffer
        next_in_cnt = in_cnt;
        next_group_en = group_en;
        next_credits = credits;
        next_rows_issued = rows_issued;
        next_draining = draining;
        next_outputs_captured = outputs_captured;
        row_complete_next = 0;

        // During drain, count row_valid pulses (real grid completion).
        // After N outputs captured, batch is done.
        // Stay in drain until buffer is empty — prevents re-reading stale data.
        if (draining && row_valid) begin
            next_outputs_captured = outputs_captured + 1'b1;
            next_credits = credits + 1'b1;
            if (outputs_captured + 1 == N[$clog2(N+1)-1:0]) begin
                // All N outputs captured — operation complete.
                next_outputs_captured = '0;
            end
        end
        // Exit drain only when buffer is empty (all stale data consumed or flushed)
        if (draining && in_buffer_empty && outputs_captured == 0 && rows_issued == N[$clog2(N+1)-1:0]) begin
            next_draining = 0;
            next_rows_issued = '0;
        end

        if (in_cnt == (ADD_2_INPUT_LATENCY - 1)) begin
            next_in_cnt = 0;
            if (credits == 0 || draining) begin
                // No credits or draining: stall input side
                next_group_en = next_group_en << 1;
                if (sa_output && !draining) begin
                    next_credits = credits + 1'b1;
                end
            end else if (credits != 0 && !in_buffer_empty && !draining) begin
                next_group_en = (next_group_en << 1) | 1'b1;

                // Check if this completes a full row (all groups issued)
                row_complete_next = (next_group_en == (1 << (NUM_GROUPS - 1)));
                
                if (row_complete_next) begin
                    next_rows_issued = rows_issued + 1'b1;
                    // If this was the Nth row, enter drain mode
                    if (rows_issued + 1 == N[$clog2(N+1)-1:0]) begin
                        next_draining = 1;
                    end
                end

                if (row_complete_next && !sa_output) begin
                    next_credits = credits - 1'b1;
                end else if (row_complete_next && sa_output) begin
                    next_credits = credits;
                end else if (!row_complete_next && sa_output) begin
                    next_credits = credits + 1'b1;
                end
            end else begin
                if (sa_output && !draining) begin
                    next_credits = credits + 1'b1;
                end
            end
        end else begin
            next_in_cnt = in_cnt + 1'b1;
        end
    end

    always_comb begin : in_rd_en_block
        in_rd_en = '0;
        for (int i = 0; i < NUM_GROUPS; i++) begin
            in_rd_en[i * GROUP_SIZE +: GROUP_SIZE] = {GROUP_SIZE{group_en[i]}};
        end
    end

    // Output buffer read logic — availability-gated, not timer-based
    // Reads are gated by real output-buffer occupancy (!out_buf_empty).
    logic [$clog2(N+1)-1:0] out_reads_sched, next_out_reads_sched;
    logic out_read_armed, next_out_read_armed;
    logic out_batch_read_done, next_out_batch_read_done;
    logic out_read_en;

    always_ff @(posedge clk or negedge nRST) begin : output_buffer_reg
        if (!nRST) begin
            out_wr_en            <= '0;
            out_reads_sched      <= '0;
            out_read_armed       <= 1'b0;
            out_batch_read_done  <= 1'b0;
        end else begin
            out_wr_en            <= next_out_wr_en;
            out_reads_sched      <= next_out_reads_sched;
            out_read_armed       <= next_out_read_armed;
            out_batch_read_done  <= next_out_batch_read_done;
        end
    end

    always_comb begin : output_buffer
        next_out_wr_en           = '0;
        next_out_reads_sched     = out_reads_sched;
        next_out_read_armed      = out_read_armed;
        next_out_batch_read_done = out_batch_read_done;

        // Clear batch_read_done when row_valid goes low (batch over),
        // allowing re-arm for the next batch.
        if (!row_valid && out_batch_read_done)
            next_out_batch_read_done = 1'b0;

        // Arm the read side on the first row_valid pulse of a batch,
        // but only if we haven't already completed reads for this batch.
        if (row_valid && !out_read_armed && !out_batch_read_done)
            next_out_read_armed = 1'b1;

        // Issue a read when: armed, buffer has data, and we haven't
        // scheduled N reads yet.
        out_read_en = out_read_armed && !out_buf_empty
                      && (out_reads_sched < N[$clog2(N+1)-1:0]);

        if (out_read_en) begin
            next_out_wr_en = {N{1'b1}};
            next_out_reads_sched = out_reads_sched + 1'b1;
            if (out_reads_sched + 1 == N[$clog2(N+1)-1:0]) begin
                // All N reads scheduled — disarm and mark batch done
                next_out_read_armed      = 1'b0;
                next_out_reads_sched     = '0;
                next_out_batch_read_done = 1'b1;
            end
        end
    end

    assign ready_in = |credits && !draining;

endmodule
