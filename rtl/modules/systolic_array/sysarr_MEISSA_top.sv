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
    // logic sysarr_stall;
    logic [N - 1:0][N - 1:0][DW_ACC - 1:0] mul_prod;
    logic [N - 1:0][N - 1:0][DW - 1:0] col_prod;
    logic [N - 1:0][DW_ACC - 1:0] adder_sum;

    // logic [N - 1:0][DW - 1:0] partial_flipped;
    // logic [N - 1:0][DW - 1:0] partial_sram_out;
    // logic [N - 1:0][DW - 1:0] partial_reverted;

    // logic [N - 1:0][DW_ACC - 1:0] psum_buffer_out;

    logic rdone, vector_done;

    // Credit-based flow control — ready_in driven by output buffer credits
    // (replaces old pass-through: assign gsau_if.sa_ready_in = gsau_if.sa_ready_out)

    //mul grid: input and output is latched

    mul_grid #(
        .FP_BF(0)
    )u_mul_grid (
        .clk(clk),
        .nRST(nRST),
        .sa_inputs(gsau_if.sa_array_in),
        .act_en(gsau_if.sa_input_en),
        .weight_en(gsau_if.sa_weight_en),
        .mul_stall(1'b0),
        .prod_r(mul_prod)
    );

    // // adder trees
    // logic [N - 1:0] [DW - 1:0] adder_tree_psum;

    genvar j,k;
    generate
        for (j = 0; j < N; j++) begin: col
            /*for (k = 0; k < N; k++) begin: col_pack
                assign col_prod[j][k] = mul_prod[k][j]; //pack mul_prod into 1D arr
            end */

            pipelined_adder_tree #(
                .N(N),
                .DATA_WIDTH(DW_ACC),
                .FP_BF(0) // bf16 = 0, fp16 = 1
            ) u_piped_addr_tree (
                .clk(clk),
                .nRST(nRST),
                .stall(1'b0),
                .terms_in(mul_prod[j]),
                .psum_in(),
                .sum_out(adder_sum[j])
            );
        end
    endgenerate


    // fp32 to bf16 reducers (one p col)
    // before output skew buffer
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
                .fp_in(adder_sum[r]),
                .fp_out(reduced_data[r])
            );
        end
        endgenerate

    // valid pipeline
    /* Formula for total latency:
     * N - multiplier shifts (i.e. shifts across 32 multipliers, 1 shift per cycle) + 1 for output registering
     * MUL_LATENCY - Last columns multiplier latency
     * $clog2(N) * ADD_LATENCY - Adder Tree latency (num stages * delay per stage)
     * ADD_LATENCY - last adder for psums
     * +1 from sram read/write latency
     * +1 from sram rpt 1 behind wpt
    */
    //localparam TOTAL_DELAY = N + MUL_LATENCY + $clog2(N) * ADD_LATENCY + 1;
    //logic [TOTAL_DELAY - 1:0] valid_bits;
    // generate;
    //     for (genvar i = 0; i < (TOTAL_DELAY); i++) begin
    //         always_ff @(posedge clk, negedge nRST) begin
    //             if (~nRST) begin
    //                 valid_bits <= '0;
    //             end else begin
    //                 if (!sysarr_stall) begin
    //                     valid_bits[i] <= (i == 0) ? gsau_if.sa_input_en : valid_bits[i - 1];
    //                 end
    //             end
    //         end
    //     end

    //     gsau_if.sa_valid_in = valid_bits[TOTAL_DELAY - 1];
    // endgenerate

    // shift register for result valid signal to GSAU
    /*
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            valid_bits <= '0;
        end else begin
            // if (!sysarr_stall) begin
            //     valid_bits <= {valid_bits[TOTAL_DELAY - 1 : 0], gsau_if.sa_input_en};
            // end
            valid_bits <= {valid_bits[TOTAL_DELAY - 1 : 0], gsau_if.sa_input_en};
        end
    end

    assign gsau_if.sa_valid_in = valid_bits[TOTAL_DELAY - 1];
    */
    // // flip the order of partial sums for reverse triangle delay
    // genvar l;
    // generate
    //     for (l = 0; l < N; l++) begin : FLIP_PARTIAL
    //         assign partial_flipped[l] = gsau_if.sa_array_in_partials[(N-1-l)*DW +: DW];
    //     end
    // endgenerate

    // // revert order for parital sums
    // genvar m;
    // generate
    //     for (m = 0; m < N; m++) begin : REVERT_PARTIAL
    //         assign partial_reverted[m] = partial_sram_out[N - m - 1];
    //     end
    // endgenerate

    /*
    skew_buffer #(
        // see parameter details in skew_buffer module
        .NUM_COLS       (N),
        .COL_WIDTH      (DW),
        .RECT_DELAY     (MUL_LATENCY + (ADD_LATENCY * $clog2(N)) - 1), // latency for first columns add tree to have valid result
        .DELAY_SLOPE    (1),
        .REVERSE_TRIANGLE(0)
    ) psum_buffer (
        .clk(clk),
        .n_rst(nRST),
        .stall(1'b0),
        .wr_data(gsau_if.sa_array_in_partials),
        .rd_data(psum_buffer_out)
    ); */

    logic [N - 1:0] [DW - 1:0] output_data;

    /*
    skew_buffer #(
        .NUM_COLS       (N),
        .COL_WIDTH      (DW),
        .RECT_DELAY     (0),
        .DELAY_SLOPE    (1),
        .REVERSE_TRIANGLE(1)
    ) output_buffer (
        .clk(clk),
        .n_rst(nRST),
        .stall(1'b0),
        .wr_data(adder_sum),
        .rd_data(output_data)
    ); */

    logic [$clog2(N + PIPELINE_DEPTH) - 1:0] credits, next_credits;

    localparam int PIPELINE_DEPTH = MUL_LATENCY + $clog2(N) * ADD_LATENCY;
    localparam int OUTPUT_READ_ENABLE = N;
    localparam int TOTAL_DELAY = PIPELINE_DEPTH + OUTPUT_READ_ENABLE + 2; // 2 because extra flags, valid bit & read enable

    logic [TOTAL_DELAY - 1:0] shift_reg;
    // shift register
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            shift_reg <= '0;
            credits <= PIPELINE_DEPTH + N - 1;
        end else begin
            shift_reg <= {shift_reg[TOTAL_DELAY - 2 : 0], gsau_if.sa_input_en};
            credits <= next_credits;
        end
    end

    always_comb begin
        case ({gsau_if.sa_valid_in, gsau_if.sa_input_en})
            2'b10 : next_credits = credits < (PIPELINE_DEPTH + N - 1) ? credits + 1 : credits;
            // 2'b01 : next_credits = (credits == 0) ? 0 : credits - 1;
            2'b01 : next_credits = credits - 1;
            // if 2'b11 or 2'b00, number of credits stays the same
            default : next_credits = credits;
        endcase
    end

    assign gsau_if.sa_ready_in = |next_credits;
    // assign gsau_if.sa_valid_in = shift_reg[TOTAL_DELAY - 1];


    /*
    logic [N-1:0] out_wr_en;

    MEISSA_control_unit #(
        .N(N),
        .GROUP_SIZE(1),
        .ADD_2_INPUT_LATENCY(ADD_LATENCY),
        .MUL_LATENCY(MUL_LATENCY)
    ) control_unit (
        .clk(clk),
        .nRST(nRST),
        .sa_output_valid(gsau_if.sa_valid_in),
        .sa_input_en(gsau_if.sa_input_en),
        .out_wr_en(out_wr_en),
        .ready_in(gsau_if.sa_ready_in)
    ); */
    /*
    logic [PIPELINE_DELAY - 1:0] pipe_valid_bits;

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            pipe_valid_bits <= '0;
        end else begin
            // if (!sysarr_stall) begin
            //     valid_bits <= {valid_bits[TOTAL_DELAY - 1 : 0], gsau_if.sa_input_en};
            // end
            pipe_valid_bits <= {pipe_valid_bits[PIPELINE_DELAY - 1 : 0], gsau_if.sa_input_en};
        end
    end
    */
    /*
    logic wr_en_msb;
    always_ff @(posedge clk, negedge nRST) begin
        if (~nRST) begin
            wr_en_msb <= '0;
            gsau_if.sa_valid_in <= '0;
        end else begin
            wr_en_msb <= out_wr_en[N - 1];
            gsau_if.sa_valid_in <= wr_en_msb;
        end
    end */

    logic [$clog2(N + PIPELINE_DEPTH) - 1:0] special_counter, next_special_counter;

    always_ff @ (posedge clk, negedge nRST) begin
        if(!nRST) begin
            special_counter <= '0;
        end else begin
            special_counter <= next_special_counter;
        end
    end

    // assign gsau_if.sa_valid_in = sa_valid_in & gsau_if.sa_ready_out;

    always_comb begin
        case ({vector_done, gsau_if.sa_valid_in})
            2'b01: next_special_counter = (special_counter > 0) ? special_counter - 1 : special_counter;
            2'b10: next_special_counter = special_counter + 1;
            default: next_special_counter = special_counter;
        endcase 
    end


    // TPU_buffer #(
    //     .NUM_COLS(N),
    //     .DATA_WIDTH(DW),
    //     .SRAM_DEPTH(N + PIPELINE_DEPTH),
    //     .IN_OUT(1) // output
    // ) output_buffer (
    //     .clk(clk),
    //     .nRST(nRST),
    //     .stall(!gsau_if.sa_ready_out),
    //     .wr_en(|special_counter),
    //     .wr_data(reduced_data),
    //     .rd_en(shift_reg[TOTAL_DELAY - 3 : PIPELINE_DEPTH]), // width of N bits
    //     .rd_data(output_data),
    //     .rdone(),
    //     .lane0_empty(),
    //     .full()
    // );

    output_buffer #(
        .NUM_COLS(N),
        .DATA_WIDTH(DW),
        .SRAM_DEPTH(N + PIPELINE_DEPTH)
    ) u_output_buffer (
        .clk(clk),
        .nRST(nRST),
        .stall(!gsau_if.sa_ready_out),
        .wr_en(shift_reg[TOTAL_DELAY - 3 : PIPELINE_DEPTH]),
        .wr_data(reduced_data),
        .rd_en(|next_special_counter),
        .rd_data(output_data),
        .vector_done(vector_done),
        .rdone(rdone)
    );

    assign gsau_if.sa_valid_in = rdone && gsau_if.sa_ready_out;

    // Drive GSAU output interface
    // Pack N columns of DW bits into sa_array_output (full vector width)
    // assign gsau_if.sa_array_output = {adder_sum[N - 1], output_data[N - 2:0]};
    assign gsau_if.sa_array_output = output_data;
endmodule
