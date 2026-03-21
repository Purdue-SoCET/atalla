// sysarr_control_unit.sv
// rewrote it bc i couldnt get it to work on the other one sorry

module sysarr_control_unit #(
    parameter int N = 8,
    parameter int GROUP_SIZE = 1,
    parameter int ADD_2_INPUT_LATENCY = 2,
    parameter int ADD_4_INPUT_LATENCY = 0,
    parameter int MUL_LATENCY = 2
)(
    input logic clk, nRST,
    input logic sa_input_en,        // external write to input buffer this cycle
    input logic in_buffer_empty,    // lane0 of input buffer is empty (unused, kept for compat)
    input logic sa_output,          // credit return pulse (sa_valid_in)
    output logic [N-1:0] in_rd_en,
    output logic [N-1:0] out_wr_en, // unused, kept for interface compat
    output logic ready_in
);

    localparam int SKEW = ADD_2_INPUT_LATENCY;
    // Total read-out cycles: lane N-1 starts at (N-1)*SKEW, reads N times
    localparam int BATCH_CYCLES = (N - 1) * SKEW + N;

    // Credits: how many more input vectors we can accept 
    logic [$clog2(N+1):0] credits, next_credits;

    // Vector counter: how many vectors written since last batch start 
    logic [$clog2(N+1):0] vec_cnt, next_vec_cnt;

    // Batch read state 
    logic batch_active, next_batch_active;
    logic [$clog2(BATCH_CYCLES):0] rd_cycle, next_rd_cycle;

    always_comb begin
        next_credits = credits;
        next_vec_cnt = vec_cnt;
        next_batch_active = batch_active;
        next_rd_cycle = rd_cycle;
        in_rd_en = '0;

        if (sa_input_en) begin
            next_vec_cnt = vec_cnt + 1;
        end

        // credit logic 
        if (sa_input_en && credits > 0 && !sa_output)
            next_credits = credits - 1;
        else if (!(sa_input_en && credits > 0) && sa_output && credits < N)
            next_credits = credits + 1;
        // else: both or neither so no change

        if (!batch_active && next_vec_cnt >= N) begin
            next_batch_active = 1'b1;
            next_rd_cycle = '0;
            next_vec_cnt = '0;
        end

        // Batch read-out
        if (batch_active) begin
            for (int m = 0; m < N; m++) begin
                if (rd_cycle >= m * SKEW && rd_cycle < m * SKEW + N) begin
                    in_rd_en[m] = 1'b1;
                end
            end

            if (rd_cycle < BATCH_CYCLES - 1) begin
                next_rd_cycle = rd_cycle + 1;
            end else begin
                // Batch complete
                next_batch_active = 1'b0;
                next_rd_cycle = '0;
            end
        end
    end

    // registers
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            credits      <= N;
            vec_cnt      <= '0;
            batch_active <= 1'b0;
            rd_cycle     <= '0;
        end else begin
            credits      <= next_credits;
            vec_cnt      <= next_vec_cnt;
            batch_active <= next_batch_active;
            rd_cycle     <= next_rd_cycle;
        end
    end

    assign ready_in = (credits > 0) && !batch_active;
    assign out_wr_en = '0;

endmodule
