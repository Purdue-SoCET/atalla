
import sys_arr_pkg::*;

module TPU_top #(
    parameter int ADD_2_INPUT_LATENCY = 2,
    parameter int ADD_4_INPUT_LATENCY = 2,
    parameter int MUL_LATENCY = 2
)(
    input logic clk, nRST,
    gsau_control_unit_if.systolic_array gsau_if
);

    logic [N/4-1:0][N-1:0][4*DW-1:0] in_pipe;
    logic [N/4-1:0][N-1:0][DW-1:0] psum_pipe;
    logic [N/4-1:0][N-1:0][DW-1:0] next_psum_pipe;
    logic [N/4-1:0][N-1:0] weight_en_pipe;

    logic [N-1:0][DW-1:0] in_vector;
    logic [N-1:0][DW-1:0] psum_vector;

    logic [N-1:0][DW-1:0] output_buffer_out;

    logic [N-1:0] in_rd_en, out_wr_en;
    logic in_buffer_empty;

    // TODO: Instantiate control logic module
    TPU_control_unit #(
        .N(N),
        .GROUP_SIZE(4),
        .ADD_2_INPUT_LATENCY(ADD_2_INPUT_LATENCY),
        .ADD_4_INPUT_LATENCY(ADD_4_INPUT_LATENCY),
        .MUL_LATENCY(MUL_LATENCY)
    ) control_unit (
        .clk(clk),
        .nRST(nRST),
        .in_buffer_empty(in_buffer_empty),
        .sa_output(gsau_if.sa_valid_in),
        .in_rd_en(in_rd_en),
        .out_wr_en(out_wr_en),
        .ready_in(gsau_if.sa_ready_in)
    );

    // TODO: Instantiate input buffer
    TPU_buffer #(
        .NUM_COLS(N),
        .DATA_WIDTH(DW),
        .IN_OUT(0)
    ) input_buffer (
        .clk(clk),
        .nRST(nRST),
        .wr_en(gsau_if.sa_input_en),
        .wr_data(gsau_if.sa_array_in),
        .rd_en(in_rd_en),
        .rd_data(in_vector),
        .lane0_empty(in_buffer_empty),
        .full()
    );


    // TODO: Connect pipes to output of input buffer
    // assign in_vector = gsau_if.sa_array_in;
    // assign psum_vector = gsau_if.sa_array_in_partials;

    genvar i, j;
    generate
        for (i = 0; i < N / 4; i++) begin: row
            for(j = 0; j < N; j++) begin: col
                always_ff @ (posedge clk, negedge nRST) begin : in_pipe_register
                    if (!nRST) begin
                        in_pipe <= '0;
                    end else begin
                        if(j == 0) begin
                            // TODO: registering first input probably won't be necessary
                            if (|in_rd_en) begin
                                in_pipe[i][0] <= in_vector[i * 4 * DW +: 4 * DW];
                            end else if (gsau_if.weight_en) begin
                                in_pipe[i][0] <= gsau_if.sa_array_in[i * 4 * DW +: 4 * DW];
                            end else begin
                                in_pipe[i][0] <= '0;
                            end
                        end else begin
                            in_pipe[i][j] <= in_pipe[i][j-1];
                        end
                    end
                end

                always_ff @ (posedge clk, negedge nRST) begin : psum_pipe_register
                    if (!nRST) begin
                        psum_pipe <= '0;
                    end else begin
                        if(j == 0) begin
                            // TODO: registering first psum probably won't be necessary
                            psum_pipe[i][0] <= psum_vector[i];
                        end else begin
                            psum_pipe[i][j] <= next_psum_pipe[i][j-1];
                        end
                    end
                end

                TPU_MAC_4_input #(
                    .IS_FP16(1)
                ) u_mac_4_input (
                    .clk(clk),
                    .nRST(nRST),
                    .in(in_pipe[i][j]),
                    .psum_in(psum_pipe[i][j]),
                    .weight_en(weight_en_pipe[i][j]),
                    .out(next_psum_pipe[i][j])
                );
            end
        end
    endgenerate

    // TODO: verify total latency for a vector ready to be outputted
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
            // if (!sysarr_stall) begin
            //     valid_bits <= {valid_bits[TOTAL_DELAY - 1 : 0], gsau_if.sa_input_en};
            // end
            valid_bits <= {valid_bits[TOTAL_DELAY - 1 : 0], gsau_if.sa_input_en};
        end
    end

    // TODO: Weight Loading
    
    // Output buffer
    //TODO: Comment explanation
    TPU_buffer #(
        .NUM_COLS(N),
        .DATA_WIDTH(DW),
        .IN_OUT(1)
    ) output_buffer (
        .clk(clk),
        .nRST(nRST),
        .wr_en(valid_bits[TOTAL_DELAY - 1]),
        .wr_data(next_psum_pipe[N - 1]),
        .rd_en(out_wr_en),
        .rd_data(gsau_if.sa_array_output),
        .lane0_empty(),
        .full()
    );

    // Always ready
    assign gsau_if.sa_ready_in = 1'b1;
    // Outputs
    assign gsau_if.sa_valid_in = valid_bits[TOTAL_DELAY - 1];
    assign gsau_if.sa_array_out = output_buffer_out;

endmodule