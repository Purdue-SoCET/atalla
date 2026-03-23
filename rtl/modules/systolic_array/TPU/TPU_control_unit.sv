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
    output logic vector_out     // valid vector output
);

    localparam int IN_CNTR_W = $clog2(ADD_2_INPUT_LATENCY);
    localparam int OUT_CNTR_W = $clog2(MUL_LATENCY);
    localparam int TOTAL_DELAY = OUT_START + N;
    
    logic [$clog2(N + PIPELINE_DEPTH)-1:0] vector_cnt, next_vector_cnt; // How many vectors stored in input buffer
    logic [$clog2(N + PIPELINE_DEPTH):0] credits, next_credits;
    logic [NUM_GROUPS-1:0] group_en, next_group_en;
    logic [IN_CNTR_W-1:0] in_cnt, next_in_cnt;

    logic [N-1:0] next_out_wr_en;
    logic [$clog2(N+1)-1:0] pending_rows, next_pending_rows;
    logic [$clog2(N + PIPELINE_DEPTH + 1):0] output_vector_counter, next_output_vector_counter;
    
    logic [TOTAL_DELAY-1:0] shift_reg;

    always_ff @(posedge clk or negedge nRST) begin : input_buffer_reg
        if (!nRST) begin
            credits <= N + PIPELINE_DEPTH - 1;
            in_cnt <= '0;
            group_en <= '0;
            pending_rows <= '0;
            vector_cnt <= '0;

            shift_reg <= '0;
        end else begin
            credits <= next_credits;
            in_cnt <= next_in_cnt;
            group_en <= next_group_en;
            pending_rows <= next_pending_rows;
            vector_cnt <= next_vector_cnt;

            shift_reg <= {shift_reg[TOTAL_DELAY-1:0], group_en[0]};
        end
    end

    assign out_wr_en = shift_reg[TOTAL_DELAY-1:OUT_START];

    always_comb begin : input_buffer
        next_in_cnt = in_cnt;
        next_group_en = group_en;
        // next_credits = credits;

        if (in_cnt == (ADD_2_INPUT_LATENCY - 1)) begin
            next_in_cnt = 0;
            if (next_credits == 0 || next_vector_cnt == 0) begin    // No new Vector
                next_group_en = group_en << 1;

            end else if (|next_credits && |next_vector_cnt) begin   // New Vector
                next_group_en = (group_en << 1) | 1'b1;     
            end
        end else begin
            next_in_cnt = in_cnt + 1'b1;
        end
    end

    always_comb begin : next_credit_logic
        case ({vector_out, group_en[0]})
            2'b01: next_credits = (credits > 0) ? credits - 1'b1 : credits;
            2'b10: next_credits = (credits < (PIPELINE_DEPTH + N - 1)) ? credits + 1'b1 : credits;
            default: next_credits = credits;
        endcase
    end

    always_comb begin : in_rd_en_block
        in_rd_en = '0;
        for (int i = 0; i < NUM_GROUPS; i++) begin
            in_rd_en[i * GROUP_SIZE +: GROUP_SIZE] = {GROUP_SIZE{group_en[i]}};
        end
    end

    always_comb begin : Vector_Count
        case ({|vector_in, group_en[0]}) 
            2'b10: next_vector_cnt = vector_cnt + 1;
            2'b01: next_vector_cnt = vector_cnt - 1;
            default : next_vector_cnt = vector_cnt;
        endcase
    end

    always_comb begin : Pending_Rows
        case({group_en[0], out_wr_en[0]}) 
            2'b10: next_pending_rows = pending_rows + 1;
            2'b01: next_pending_rows = pending_rows - 1;
            default: next_pending_rows = pending_rows;
        endcase
    end

    assign ready_in = |next_credits;

    always_ff @(posedge clk, negedge nRST) begin: Output_Vector_Cnt
        if (!nRST) begin
            output_vector_counter <= '0;
        end else begin
            output_vector_counter <= next_output_vector_counter;
        end
    end

    always_comb begin
        case ({vector_done, rdone && ready_out})
            2'b01: next_output_vector_counter = (output_vector_counter > 0) ? output_vector_counter - 1 : output_vector_counter;
            2'b10: next_output_vector_counter = output_vector_counter + 1;
            default: next_output_vector_counter = output_vector_counter;
        endcase
    end

    assign out_rd_en = |next_output_vector_counter;
    assign vector_out = rdone && ready_out;

endmodule
