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
    logic [1:0] reduction_type_registered;
    logic [NUM_ELEMENTS-1:0][15:0] vector_registered, output_vector;
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

    //on a valid input, latch all control signals and data
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            vector_registered <= 'b0;
            broadcast_registered <= 'b0;
            clear_registered <= 'b0;
            imm_registered <= 'b0;
            reduction_type_registered <= 'b0;
        end
        else begin
            if (vruif.in.valid_in & vruif.out.ready_in) begin
                vector_registered <= vruif.in.vector_input;
                broadcast_registered <= vruif.in.broadcast;
                clear_registered <= vruif.in.clear;
                imm_registered <= vruif.in.imm;
                reduction_type_registered <= vruif.in.reduction_type;
            end
        end
    end

    //run the reduction tree with registered alu_op
    logic [15:0] rtree_result;
    logic rtree_done;
    reduction_tree #(
        .LANES(LANES)
    ) rTree (
        .CLK(CLK),
        .nRST(nRST),
        .data_in(vruif.in.lane_input),
        .alu_op(reduction_type_registered),  // Use registered version that stays stable
        .valid_in(vruif.in.valid_in & vruif.out.ready_in),
        .data_out(rtree_result),
        .valid_out(rtree_done)
    );

    //when the tree is done, update output vector
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            output_vector <= 'b0;
            valid_out_reg <= 1'b0;
        end
        else begin
            if (rtree_done) begin
                // Update output_vector directly when tree is done
                for (int i = 0; i < NUM_ELEMENTS; i++) begin
                    if (clear_registered) begin
                        output_vector[i] <= (i == imm_registered) ? rtree_result : 'b0;
                    end
                    else if (broadcast_registered) begin
                        output_vector[i] <= rtree_result;
                    end
                    else begin
                        output_vector[i] <= (i == imm_registered) ? rtree_result : vector_registered[i];
                    end
                end
                valid_out_reg <= 1'b1;
            end
            else begin
                valid_out_reg <= 1'b0;
            end
        end
    end

    assign vruif.out.vector_output = output_vector;
    assign vruif.out.valid_out = valid_out_reg;
endmodule