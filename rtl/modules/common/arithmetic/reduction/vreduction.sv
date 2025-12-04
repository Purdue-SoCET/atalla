`include "vreduction_if.vh"
`include "vreduction_alu_if.vh"
`include "reduction_types.vh"

module vreduction #(
    parameter int LANES = 16
)(
    input logic CLK, nRST,
    vreduction_if.ruif vruif
);

    import reduction_pkg::*;
    
    logic busy, broadcast_registered, clear_registered;
    logic [4:0] imm_registered;
    logic [NUM_ELEMENTS-1:0][15:0] vector_registered, output_vector, output_vector_n;
    logic valid_out_reg;

    //we are ready if ready_out, and not ready until we output valid data again

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            busy <= 1'b0;
        end 
        else begin
            if (!busy && vruif.in.valid_in && vruif.out.ready_in) begin
                busy <= 1'b1;
            end
            if (busy && vruif.out.valid_out) begin
                busy <= 1'b0;
            end
        end
    end

    always_comb begin
        vruif.out.ready_in = (!busy) & vruif.in.ready_out;
    end

    //on a valid input, latch the input vector
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            vector_registered <= 'b0;
            broadcast_registered <= 'b0;
            clear_registered <= 'b0;
            imm_registered <= 'b0;
        end
        else begin
            if (vruif.in.valid_in & vruif.out.ready_in) begin
                vector_registered <= vruif.in.vector_input;
                broadcast_registered <= vruif.in.broadcast;
                clear_registered <= vruif.in.clear;
                imm_registered <= vruif.in.imm;
            end
        end
    end

    //on a valid input, run the reduction tree
    logic [15:0] rtree_result;
    logic rtree_done;
    reduction_tree #(
        .LANES(LANES)
    ) rTree (
        .CLK(CLK),
        .nRST(nRST),
        .data_in(vruif.in.lane_input),
        .alu_op(vruif.in.reduction_type),
        .valid_in(vruif.in.valid_in & vruif.out.ready_in),
        .data_out(rtree_result),
        .valid_out(rtree_done)
    );

    //when the tree is done, output masking and such
    
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            output_vector <= 'b0;
            valid_out_reg <= 1'b0;
        end
        else begin
            output_vector <= output_vector_n;
            valid_out_reg <= rtree_done;  // Delay valid by one cycle
        end
    end

    always_comb begin
        if (rtree_done) begin
            for (int i = 0; i < NUM_ELEMENTS; i++) begin
                if (clear_registered) begin
                    output_vector_n[i] = (i == imm_registered) ? rtree_result : 'b0;
                end
                else if (broadcast_registered) begin
                    output_vector_n[i] = rtree_result;
                end
                else begin
                    output_vector_n[i] = (i == imm_registered) ? rtree_result : vector_registered[i];
                end
            end
        end
        else begin
            output_vector_n = output_vector;
        end
    end

    assign vruif.out.vector_output = output_vector;
    assign vruif.out.valid_out = valid_out_reg;  // Use registered version
endmodule