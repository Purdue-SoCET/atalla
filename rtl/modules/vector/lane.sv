// Vector Lane Module ============================================
// Author: Joseph Ghanem
// Email: jghanem@purdue.edu
// Vector Lane
// Issue Length = 1
// Commit Length = 1
// ========================================================================
`include "vector_if.vh"
`include "vector_pkg.vh"

module lane #(
)(
    input logic CLK, nRST,
    vector_if.lane lif
); 
    import vector_pkg::*;
    import sqrt_pkg::*;

    // ------------------------------------------------------------
    // SQRT interface + BF16 SQRT FU
    // ------------------------------------------------------------
    sqrt_if sqrt_bus();

    sqrt_bf16 u_sqrt_bf16 (
        .CLK  (CLK),
        .nRST (nRST),
        .srif (sqrt_bus)
    );

    // ------------------------------------------------------------
    // SQRT sequencer side
    // ------------------------------------------------------------

    // Per-issue-slot inputs produced by sequencer
    lane_sqrt_in_t lane_sqrt_in [LANE_ISSUE_BW];

    // Element index into the slice (0 .. SLICE_W-1)
    logic [SLICE_ID_W-1:0] sqrt_elem_idx;

    // Input handshake: element is accepted when the FU takes it
    wire sqrt_elem_accepted = sqrt_bus.in.valid_in && sqrt_bus.in.ready_out;

    // Instantiate generic lane_sequencer for SQRT
    lane_sequencer #(
        .FU_KIND      (3'b010),  // SQRT
        .USE_V2       (1'b0),
        .lane_fu_in_t (lane_sqrt_in_t)
    ) u_lane_seq_sqrt (
        .CLK             (CLK),
        .nRST            (nRST),
        .lane_in         (lif.lane_in),      // <-- change if your lane_in name differs
        .lane_fu_in      (lane_sqrt_in),
        .elem_idx        (sqrt_elem_idx),
        .fu_elem_accepted(sqrt_elem_accepted)
    );

    // ------------------------------------------------------------
    // FU stage: drive scalar sqrt_bf16 from sequencer outputs
    // ------------------------------------------------------------

    // For now, only use issue slot 0 for SQRT
    localparam int SQRT_SLOT = 0;

    // Always ready to consume SQRT results for now
    assign sqrt_bus.out.ready_in = 1'b1;

    always_comb begin
        // Default: no request to SQRT
        sqrt_bus.in.operand   = '0;
        sqrt_bus.in.valid_in  = 1'b0;
        // NOTE: ready_out is driven *by* sqrt_bf16, so we do NOT assign it here.

        // If this slot has a SQRT op and this element is active, fire it
        if (lane_sqrt_in[SQRT_SLOT].mask &&
            lane_sqrt_in[SQRT_SLOT].fu_in.valid_data_in[sqrt_elem_idx]) begin

            sqrt_bus.in.operand  = lane_sqrt_in[SQRT_SLOT].fu_in.input_val[sqrt_elem_idx];
            sqrt_bus.in.valid_in = 1'b1;
        end
    end


    /*
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
