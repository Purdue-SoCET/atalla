`include "vector_types.vh"
`include "vreduction_if.vh"
`include "vreduction_alu_if.vh"

module vreduction #(
    parameter int EXP_W = 5,
    parameter int FRAC_W = 10,
    parameter int LANES = 16

)(
    input logic CLK, nRST,
    vreduction_if.ruif vruif
);

    localparam int LEVELS = $clog2(LANES);
    localparam int PIPE_STAGES = 2 + 2*LEVELS + LEVELS - 1;
    import vector_pkg::*;

    reduction_tree #(
        .LANES(LANES)
    ) reduction_tree (
        .CLK(CLK),
        .nRST(nRST),
        .data_in(vruif.lane_input),
        .alu_op(vruif.reduction_type),
        .valid_in(vruif.input_valid),
        .data_out(tree_data_out),
        .valid_out(tree_valid_out)
    );

    //fifo for the input vector
    logic [15:0][NUM_ELEMENTS] vector_fifo_out;
    logic vector_fifo_full, vector_fifo_empty;
    sync_fifo #(
        .FIFODEPTH(PIPE_STAGES),
        .DATAWIDTH(16 * NUM_ELEMENTS)
    ) vector_fifo (
        .CLK(CLK),
        .nRST(nRST),
        .wr_en(vruif.input_valid),
        .din(vruif.vector_input),
        .shift(tree_valid_out),
        .dout(vector_fifo_out),
        .empty(vector_fifo_empty),
        .full(vector_fifo_full)
    );

    //signals fifo
    logic [4:0] imm_final;
    logic broadcast_final, clear_final;
    logic signals_fifo_full, signals_fifo_empty;

    sync_fifo #(
        .FIFODEPTH(PIPE_STAGES),
        .DATAWIDTH(7)
    ) signals_fifo (
        .CLK(CLK),
        .nRST(nRST),
        .wr_en(vruif.input_valid),
        .din({vruif.imm,vruif.broadcast,vruif.clear}),
        .shift(tree_valid_out),
        .dout({imm_final,broadcast_final,clear_final}),
        .empty(signals_fifo_empty),
        .full(signals_fifo_full)
    );

    logic[15:0] final_value;
    assign final_value = tree_data_out;
    logic [15:0][NUM_ELEMENTS-1:0] final_vector;

    always_comb begin
        for (int i = 0; i < NUM_ELEMENTS; i++) begin
            if (broadcast_final) begin
                final_vector[i] = final_value;
            end
            else if (clear_final) begin
                final_vector[i] = (i == int'(imm_final)) ? final_value : '0;
            end
            else begin
                final_vector[i] = (i == int'(imm_final)) ? final_value : vector_fifo_out[i];
            end
        end
    end

    logic [15:0][NUM_ELEMENTS-1:0] registered_output;
    logic   registered_valid;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            for (int i = 0; i < NUM_ELEMENTS; i++)
                registered_output[i] <= '{default: '0};
            registered_valid <= 1'b0;
        end else begin
            for (int i = 0; i < NUM_ELEMENTS; i++)
                registered_output[i] <= final_vector[i];
            registered_valid <= tree_valid_out;
        end
    end

    always_comb begin
        for (int i = 0; i < NUM_ELEMENTS; i++)
            vruif.vector_output[i] = registered_output[i];
        vruif.output_valid = registered_valid;
    end
    
endmodule