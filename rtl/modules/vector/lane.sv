// Vector Lane Module ============================================
// Author: Joseph Ghanem
// Email: jghanem@purdue.edu
// Vector Lane
// Issue Length = 1
// Commit Length = 1
// ========================================================================
`include "vector_if.vh"
`include "vector_types.vh"

module lane #(
)(
    input logic CLK, nRST,
    vector_if.lane lif
); 
    import vector_pkg::*;
    
    logic [SLICE_ID_W:0] alu_iter, exp_iter, sqrt_iter, mul_iter, div_iter;

    // Pipeline Interface Instantiation
    // sqrt_in, sqrt_out
    vector_if.sequence_alu seq_alu ();
    vector_if.alu_wb alu_wb ();

    // ALU Sequence Stage
    assign alu_valid = ((alu_global_idx < lif.lane_in.vl) || (lif.lane_in.vm && lif.lane_in.vmask[alu_iter]));
    assign alu_iter = (salu.alu_iter_o) ? salu.alu_iter_o + 1: `0;
    assign alu_global_idx = lif.lane_in.global_idx + alu_iter;

    // Lane ALU Execute stage
    sequence_ex alu (
        iter, valid, global_idx, alu_in
    );

    alu alu (CLK, nRST, alu_in);
    assign alu_ready = (salu.alu_iter_o == SLICE_W-1);
    assign lif.lane_out.reduction = (lif.lane_in.rm && alu_ready) ? alu.reduction : 0;


    // SQRT =============================================================
    sqrt_if.srif srif ();
    
    lane_sqrt_in_t [SLICE_W-1:0] lane_sqrt_in;
    sqrt_out_t [SLICE_W-1:0] sqrt_out;

    // SQRT Sequence Stage
    always_comb begin
        for (int i = 0; i < LANE_ISSUE_BW; i++) begin
            if (lif.lane_in.valid_in[i] == SQRT) begin
                for(int j = 0; j < SLICE_W; j++) begin
                    lane_sqrt_in.sqrt_in.input_val[j] =  lif.lane_in.v1[i][j];
                    lane_sqrt_in.sqrt_in.valid_data_in[j] = lif.lane_in.mask[i][j];
                    lane_sqrt_in.mask[j] = lif.lane_in.mask[i][j];
                    lane_sqrt_in.vd[j] = lif.lane_in.vd[i][j];
                end
            end else begin
                lane_sqrt_in.sqrt_in.input_val[j] = '0;
                lane_sqrt_in.sqrt_in.valid_data_in[j] = '0;
                lane_sqrt_in.mask[j] = '0;
                lane_sqrt_in.vd[j] = '0;
            end
        end
    end

    assign sqrt_iter = (srif.sqrt_out.valid_data_out && sqrt_iter != SLICE_W-1) ? sqrt.sqrt_iter_o + 1: sqrt_iter;
    latch sr_sx (CLK, nRST, sqrt_in[sqrt_iter], sx_o);

    // SQRT Execute Stage
    srif.sqrt_in = sx_o.sqrt_in;
    sqrt sqrt (CLK, nRST, srif);

    // Send to WB arbiter
    



    // to WB arbiter
    // send ready, iter, gloval_idx, vd, result

    // WB Arbiter
    

    /*
    counter_exp
    pipeline_exp
    exp
    pipeline_exp_wb

    counter_sqrt
    pipeline_sqrt
    sqrt
    pipeline_sqrt_wb

    counter_mul
    pipeline_mul
    mul
    pipeline_mul_wb

    counter_div
    pipeline_div
    div
    pipeline_div_wb

    wb_arbiter inpute GVLS
    */
    
endmodule
