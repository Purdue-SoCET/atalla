// sysarr_TPU_control_unit.sv
// Parameterized Issue Timers for TPU Input buffer

module TPU_control_unit #(
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
    output logic [N-1:0] in_rd_en,
    output logic [N-1:0] out_wr_en,
    output logic ready_in
);

    localparam int IN_CNTR_W = $clog2(ADD_2_INPUT_LATENCY);
    localparam int OUT_CNTR_W = $clog2(MUL_LATENCY);

    logic [$clog2(N):0] credits, next_credits;
    logic [NUM_GROUPS-1:0] group_en, next_group_en;
    logic [IN_CNTR_W-1:0] in_cnt, next_in_cnt;

    logic [OUT_CNTR_W-1:0] out_cnt, next_out_cnt;
    logic [OUT_START-1:0] out_start_cnt, next_out_start_cnt;
    logic [N-1:0] next_out_wr_en;
    logic [$clog2(N+1)-1:0] pending_rows, next_pending_rows;

    always_ff @(posedge clk or negedge nRST) begin : input_buffer_reg
        if (!nRST) begin
            credits <= N;
            in_cnt <= '0;
            group_en <= '0;
            pending_rows <= '0;
        end else begin
            credits <= next_credits;
            in_cnt <= next_in_cnt;
            group_en <= next_group_en;
            pending_rows <= next_pending_rows;
        end
    end

    always_comb begin : input_buffer
        next_in_cnt = in_cnt;
        next_group_en = group_en;
        next_credits = credits;
        next_pending_rows = pending_rows;

        if (in_cnt == (ADD_2_INPUT_LATENCY - 1)) begin
            next_in_cnt = 0;
            if (credits == 0) begin
                next_group_en = next_group_en << 1;
            end else if (credits != 0 && !in_buffer_empty) begin
                next_group_en = (next_group_en << 1) | 1'b1;

                if (!sa_output) begin
                    next_credits = next_credits - 1'b1;
                end
                
                // Pending Rows
                next_pending_rows = pending_rows + 1'b1;
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

    always_ff @(posedge clk or negedge nRST) begin : output_buffer_reg
        if (!nRST) begin
            out_cnt <= '0;
            out_start_cnt <= '0;
            out_wr_en <= '0;
        end else begin
            out_cnt <= next_out_cnt;
            out_start_cnt <= next_out_start_cnt;
            out_wr_en <= next_out_wr_en;
        end
    end

    always_comb begin : output_buffer
        next_out_cnt = out_cnt;
        next_out_start_cnt = out_start_cnt;
        next_out_wr_en = out_wr_en;

        if ((|pending_rows) && (out_start_cnt < OUT_START - 1)) begin
            next_out_start_cnt = out_start_cnt + 1'b1;
        end else if (out_start_cnt == OUT_START - 1) begin
            next_out_start_cnt = out_start_cnt;
        end else begin
            next_out_start_cnt = '0;
        end

        if (out_start_cnt == OUT_START - 1) begin
            next_out_wr_en = (out_wr_en << 1) | (|pending_rows);
            next_pending_rows = pending_rows - 1'b1;
        end

        // if ((out_cnt == MUL_LATENCY - 1) && (out_start_cnt == OUT_START - 1)) begin
        //     next_out_cnt = '0;
        //     next_out_wr_en = (out_wr_en << 1) | (|pending_rows);
        //     next_pending_rows = pending_rows - 1'b1;
        // end else begin
        //     next_out_cnt = out_cnt + 1'b1;
        // end
    end

    assign ready_in = |credits;

endmodule
