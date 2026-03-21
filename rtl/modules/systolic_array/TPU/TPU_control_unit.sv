// sysarr_TPU_control_unit.sv
// Parameterized Issue Timers for TPU Input buffer

module TPU_control_unit #(
    parameter int N = 32,
    parameter int GROUP_SIZE = 4,
    parameter int ADD_2_INPUT_LATENCY = 2,
    parameter int ADD_4_INPUT_LATENCY = 2,
    parameter int MUL_LATENCY = 2,
    parameter int PIPELINE_DEPTH,
    localparam int NUM_GROUPS = N / GROUP_SIZE,
    localparam int OUT_START = MUL_LATENCY + ADD_4_INPUT_LATENCY + (NUM_GROUPS * ADD_2_INPUT_LATENCY)

)(
    input logic clk, nRST,
    input logic in_buffer_empty,
    input logic vector_in,
    input logic ready_out,
    input logic rdone,
    input logic vector_done,
    output logic [N-1:0] in_rd_en,
    output logic [N-1:0] out_wr_en,
    output logic ready_in,
    output logic out_rd_en,
    output logic vector_out
);

    localparam int IN_CNTR_W = $clog2(ADD_2_INPUT_LATENCY);
    localparam int OUT_CNTR_W = $clog2(MUL_LATENCY);
    
    logic [$clog2(N + PIPELINE_DEPTH)-1:0] vector_cnt, next_vector_cnt; // How many vectors stored in input buffer
    logic [$clog2(N + PIPELINE_DEPTH):0] credits, next_credits;
    logic [NUM_GROUPS-1:0] group_en, next_group_en;
    logic [IN_CNTR_W-1:0] in_cnt, next_in_cnt;

    logic [OUT_CNTR_W-1:0] out_cnt, next_out_cnt;
    logic [$clog2(OUT_START + 1):0] out_start_cnt, next_out_start_cnt;
    logic [N-1:0] next_out_wr_en;
    logic [$clog2(N+1)-1:0] pending_rows, next_pending_rows;
    logic [$clog2(N + PIPELINE_DEPTH + 1):0] output_vector_counter, next_output_vector_counter;
    logic sa_valid_in;

    always_ff @(posedge clk or negedge nRST) begin : input_buffer_reg
        if (!nRST) begin
            credits <= N + PIPELINE_DEPTH;
            in_cnt <= '0;
            group_en <= '0;
            pending_rows <= '0;
            vector_cnt <= '0;
        end else begin
            credits <= next_credits;
            in_cnt <= next_in_cnt;
            group_en <= next_group_en;
            pending_rows <= next_pending_rows;
            vector_cnt <= next_vector_cnt;
        end
    end

    always_comb begin : input_buffer
        next_in_cnt = in_cnt;
        next_group_en = group_en;
        next_credits = credits;

        if (in_cnt == (ADD_2_INPUT_LATENCY - 1)) begin
            next_in_cnt = 0;
            if (credits == 0 || vector_cnt == 0) begin
                next_group_en = group_en << 1;
                if (sa_valid_in && ready_out) begin
                    next_credits = credits + 1'b1;
                end
            end else if (|credits && |vector_cnt) begin
                next_group_en = (group_en << 1) | 1'b1;

                if (!sa_valid_in && ready_out) begin
                    next_credits = credits - 1'b1;
                end
                
            end else begin
                if (sa_valid_in && ready_out) begin
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

        if ((|pending_rows) && (out_start_cnt < OUT_START)) begin
            next_out_start_cnt = out_start_cnt + 1'b1;
        end else if ((out_start_cnt == OUT_START && |pending_rows)) begin
            next_out_start_cnt = out_start_cnt;
        end else begin
            next_out_start_cnt = '0;
        end

        if (out_start_cnt == OUT_START) begin
            next_out_wr_en = (out_wr_en << 1) | (|pending_rows);
        end else begin
            next_out_wr_en = out_wr_en << 1;
        end
    end

    always_comb begin : Vector_Count
        case ({|vector_in, next_group_en[0]}) 
            2'b10: next_vector_cnt = vector_cnt + 1;
            2'b01: next_vector_cnt = vector_cnt - 1;
            default : next_vector_cnt = vector_cnt;
        endcase
    end

    always_comb begin : Pending_Rows
        case({next_group_en[0], next_out_wr_en[0]}) 
            2'b10: next_pending_rows = pending_rows + 1;
            2'b01: next_pending_rows = pending_rows - 1;
            default: next_pending_rows = pending_rows;
        endcase
    end

    assign ready_in = |credits;

    always_ff @(posedge clk, negedge nRST) begin: Output_Vector_Cnt
        if (!nRST) begin
            output_vector_counter <= '0;
        end else begin
            output_vector_counter <= next_output_vector_counter;
            sa_valid_in <= |output_vector_counter;
        end
    end

    always_comb begin
        case ({out_wr_en[N - 1], |output_vector_counter && ready_out})
            2'b01: next_output_vector_counter = (output_vector_counter > 0) ? output_vector_counter - 1 : output_vector_counter;
            2'b10: next_output_vector_counter = output_vector_counter + 1;
            default: next_output_vector_counter = output_vector_counter;
        endcase
        out_rd_en = |output_vector_counter;
        vector_out = sa_valid_in && ready_out;
    end

endmodule
