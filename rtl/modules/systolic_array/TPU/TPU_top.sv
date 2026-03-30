
import sys_arr_pkg::*;

module TPU_top #(
    parameter int ADD_2_INPUT_LATENCY = 1,
    parameter int ADD_4_INPUT_LATENCY = 3,
    parameter int MUL_LATENCY = 2,
    parameter int GROUP_SIZE = 4,

    localparam int PIPELINE_DEPTH = MUL_LATENCY + ADD_4_INPUT_LATENCY + $clog2(N / GROUP_SIZE) * ADD_2_INPUT_LATENCY,
    localparam int PSUM_WIDTH = IS_FP16 ? DW : DW_ACC
)(
    input logic clk, nRST,
    gsau_control_unit_if.systolic_array gsau_if
);

    logic [N/4-1:0][N-1:0][4*DW-1:0] in_pipe;
    logic [N/4:0][N-1:0][PSUM_WIDTH-1:0] psum_pipe;
    // logic [N/4:0][N-1:0][DW-1:0] next_psum_pipe;
    logic [N/4-1:0][N-1:0] weight_en_pipe;

    logic [N-1:0][DW-1:0] in_vector;
    // logic [N-1:0][PSUM_WIDTH-1:0] psum_vector;

    logic [N-1:0][DW-1:0] output_buffer_out;

    logic [N-1:0] in_rd_en, out_wr_en, in_rdone;
    logic in_buffer_empty, out_rd_en, weight_delay, rdone, vector_done;

    always_ff @ (posedge clk, negedge nRST) begin
        if(!nRST) begin
            weight_delay <= '0;
        end
        else begin
            weight_delay <= gsau_if.sa_weight_en;
        end
    end

    // TODO: Instantiate control logic module
    TPU_control_unit #(
        .N(N),
        .GROUP_SIZE(4),
        .ADD_2_INPUT_LATENCY(ADD_2_INPUT_LATENCY),
        .ADD_4_INPUT_LATENCY(ADD_4_INPUT_LATENCY),
        .MUL_LATENCY(MUL_LATENCY),
        .PIPELINE_DEPTH(PIPELINE_DEPTH)
    ) control_unit (
        .clk(clk),
        .nRST(nRST),
        .in_buffer_empty(in_buffer_empty),
        .vector_in(gsau_if.sa_input_en),
        .rdone(rdone),
        .vector_done(vector_done),
        .ready_out(gsau_if.sa_ready_out),
        .in_rd_en(in_rd_en),
        .out_wr_en(out_wr_en),
        .ready_in(gsau_if.sa_ready_in),
        .out_rd_en(out_rd_en),
        .vector_out(gsau_if.sa_valid_in)
    );

    // TODO: Instantiate input buffer

    input_buffer #(
        .NUM_COLS(N),
        .DATA_WIDTH(DW),
        .SRAM_DEPTH(N + PIPELINE_DEPTH)
    ) u_input_buffer (
        .clk(clk),
        .nRST(nRST),
        .stall(1'b0),
        .wr_en(gsau_if.sa_input_en),
        .wr_data(gsau_if.sa_array_in),
        .rd_en(in_rd_en),
        .rd_data(in_vector),
        .rdone(in_rdone),
        .lane0_empty(in_buffer_empty)
    );

genvar k;
    generate
        for(k=0; k < N; k++) begin
            assign psum_pipe[0][k] = '0;
        end
    endgenerate



    // TODO: Connect pipes to output of input buffer
    // assign in_vector = gsau_if.sa_array_in;
    // assign psum_vector = gsau_if.sa_array_in_partials;

    genvar i, j;
    generate
        for (i = 0; i < N / 4; i++) begin: row
            for(j = 0; j < N; j++) begin: col
                always_ff @ (posedge clk, negedge nRST) begin : in_pipe_register
                    if (!nRST) begin
                        /* verilator lint_off WIDTHCONCAT */
                        in_pipe[i][j] <= '0;
                        /* verilator lint_on WIDTHCONCAT */
                    end else begin
                        if(j == 0) begin
                            if (gsau_if.sa_weight_en) begin
                                in_pipe[i][0] <= gsau_if.sa_array_in[i * 4 * DW +: 4 * DW];
                            end else begin
                                in_pipe[i][0] <= {in_vector[i * 4 + 3], in_vector[i * 4 + 2], in_vector[i * 4 + 1], in_vector[i * 4]};
                            end
                        end else begin
                            in_pipe[i][j] <= in_pipe[i][j-1];
                        end
                    end
                end

                always_ff @ (posedge clk, negedge nRST) begin :weight_en_pipe_register
                    if(!nRST) begin
                        weight_en_pipe <= '0;
                    end
                    else begin
                        if(j == 0) begin
                            if (gsau_if.sa_weight_en) begin
                                if (j == 0) begin
                                    weight_en_pipe[i][0] <= 1'b1;
                                end
                                else begin
                                    weight_en_pipe[i][j] <= weight_en_pipe[i][j-1];
                                end
                            end
                        end
                    end
                end

                TPU_MAC_4_input #(
                    // .IS_FP16(IS_FP16)
                ) u_mac_4_input (
                    .clk(clk),
                    .nRST(nRST),
                    .in(in_pipe[i][j]),
                    .psum_in(psum_pipe[i][j]),
                    .weight_en(weight_delay),
                    .out(psum_pipe[i +  1][j])
                );

                // if (IS_FP16) begin
                //     TPU_MAC_4_input #(
                //         // .IS_FP16(IS_FP16)
                //     ) u_mac_4_input (
                //         .clk(clk),
                //         .nRST(nRST),
                //         .in(in_pipe[i][j]),
                //         .psum_in(psum_pipe[i][j]),
                //         .weight_en(weight_delay),
                //         .out(psum_pipe[i+1][j])
                //     );
                // end else begin
                //     TPU_MAC_4_input #(
                //         // .IS_FP16(IS_FP16)
                //     ) u_mac_4_input (
                //         .clk(clk),
                //         .nRST(nRST),
                //         .in(in_pipe[i][j]),
                //         .psum_in(psum_pipe[i][j]),
                //         .weight_en(weight_delay),
                //         .out(psum_pipe[i +  1][j])
                //     );
                // end
            end
        end
    endgenerate

    logic [N - 1:0][DW - 1:0] reduced_data;

    genvar r;
    generate
        if (!IS_FP16) begin
            for (r = 0; r < N; r++) begin: reduce
                reducer #(
                    .IN_EXP_W(8),
                    .IN_MANT_W(23),
                    .OUT_EXP_W(8),
                    .OUT_MANT_W(7)
                ) u_reducer (
                    .fp_in(psum_pipe[N / 4][r]),
                    .fp_out(reduced_data[r])
                );
            end 
        end
    endgenerate

    /* Formula for total latency:
     * +1 from gsau_if.sa_array_in to input buffer write latency
     * +1 from control unit to start issue
     * +1 from input buffer read latency
     * ADD_2_INPUT_LATENCY * (N/4-1) - last element staggering delay
     * N - multiplier grid shifts (i.e. shifts across 32 multipliers, 1 shift per cycle) + 1 for input registering (may change)
     * MUL_LATENCY - first multiplier latency
     * ADD_4_INPUT_LATENCY - last 4 input adder latency
     * ADD_2_INPUT_LATENCY - last 2 input adder latency
     * +1 from sram write latency
     Actual delay will be +1 from sram read latency
    */
    localparam TOTAL_DELAY = ADD_2_INPUT_LATENCY * (N/4-1) + N + MUL_LATENCY + ADD_4_INPUT_LATENCY + ADD_2_INPUT_LATENCY + 4;
    logic [TOTAL_DELAY - 1:0] valid_bits;

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            valid_bits <= '0;
        end else begin
            valid_bits <= {valid_bits[TOTAL_DELAY - 1 : 0], in_rd_en[0]};
        end
    end

    generate
        if (IS_FP16) begin
            output_buffer #(
                .NUM_COLS(N),
                .DATA_WIDTH(DW),
                .SRAM_DEPTH(N + PIPELINE_DEPTH)
            ) u_output_buffer (
                .clk(clk),
                .nRST(nRST),
                .stall(!gsau_if.sa_ready_out),
                .wr_en(out_wr_en),
                .wr_data(psum_pipe[N / 4]),
                .rd_en(out_rd_en),
                .rd_data(gsau_if.sa_array_output),
                .vector_done(vector_done),
                .rdone(rdone)
            );
        end else begin
            output_buffer #(
                .NUM_COLS(N),
                .DATA_WIDTH(DW),
                .SRAM_DEPTH(N + PIPELINE_DEPTH)
            ) u_output_buffer (
                .clk(clk),
                .nRST(nRST),
                .stall(!gsau_if.sa_ready_out),
                .wr_en(out_wr_en),
                .wr_data(reduced_data),
                .rd_en(out_rd_en),
                .rd_data(gsau_if.sa_array_output),
                .vector_done(vector_done),
                .rdone(rdone)
            );
        end
    endgenerate

endmodule