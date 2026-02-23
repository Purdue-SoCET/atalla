`include "vreduction_if.vh"
`include "vreduction_alu_if.vh"
`include "vector_pkg.vh"

module vreduction #(
    parameter int LANES = 16
)(
    input logic CLK, nRST,
    vreduction_if.ruif vruif
);
    import vector_pkg::*;
    
    vreg_t output_vec, output_vec_n;
    logic [ESZ-1:0] rtree_result;
    logic rtree_done;

    logic ready_in_r, ready_in_n;
    logic valid_out_r, valid_out_n;


    //run the reduction tree with registered alu_op

    reduction_tree rTree (
        .CLK(CLK),
        .nRST(nRST),
        .data_in(vruif.in.lane_input),
        .alu_op(vruif.in.reduction_type),
        .valid_in(vruif.in.valid_in & vruif.out.ready_in),
        .data_out(rtree_result),
        .valid_out(rtree_done)
    );

    //output vector creation
    always_ff @(posedge CLK, negedge nRST) begin : output_r
        if (!nRST) begin
            output_vec <= 'b0;
        end
        else begin
            output_vec <= output_vec_n;
        end
    end

    always_comb begin : output_comb
        output_vec_n = output_vec;
        if (rtree_done) begin
            for (int i = 0; i < NUM_ELEMENTS; i++) begin
                if (vruif.in.broadcast) begin
                    output_vec_n[i] = rtree_result;
                end
                else if (vruif.in.clear) begin
                    output_vec_n[i] = i == vruif.in.imm ? rtree_result : 'b0;
                end
                else begin
                    output_vec_n[i] = i == vruif.in.imm ? rtree_result : vruif.in.vector_input;
                end
            end
        end
    end

    assign vruif.out.vector_output = output_vec;

    always_ff @(posedge CLK, negedge nRST) begin : ready_in_seq
        if (!nRST) begin
            ready_in_r <= 'b1;
            valid_out_r <= 'b0;
        end
        else begin
            ready_in_r <= ready_in_n;
            valid_out_r <= valid_out_n;
        end
    end

    always_comb begin : ready_in_comb
        ready_in_n = ready_in_r;
        valid_out_n = valid_out_r;
        if (vruif.in.valid_in & vruif.out.ready_in) begin //if handshake deassert ready
            ready_in_n = 'b0;
        end
        if (rtree_done) begin //if the tree finishes, we have valid data
            valid_out_n = 'b1;
        end

        if (vruif.out.valid_out & vruif.in.ready_out) begin //when an output handshake happens we are no longer valid or ready
            ready_in_n = 'b1;
            valid_out_n = 'b0;
        end
    end

    assign vruif.out.ready_in = ready_in_r;
    assign vruif.out.valid_out = valid_out_r;

endmodule