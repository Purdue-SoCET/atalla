// ------------------------------------------------------------
// result_collector.sv
// Collect per-lane FU results into full vectors per FU
// ------------------------------------------------------------
`include "vector_if.vh"
`include "vector_pkg.vh"

module result_collector (
    input  logic               CLK,
    input  logic               nRST,
    vector_if.result_collector rcif
);
    import vector_pkg::*;

    result_collector_in_t  rc_in;
    result_collector_out_t rc_out;

    // Hook to interface (adjust field names if your modport differs)
    assign rc_in       = rcif.rc_in;
    assign rcif.rc_out = rc_out;

    // ----------------------------------------------------------------
    // One rc_fu per FU
    // ----------------------------------------------------------------
    generate
        for (genvar fu = 0; fu < LANE_FU_COUNT; fu++) begin : GEN_FU

            // Per-lane views for this FU
            // Note: These are unpacked arrays (memories), fitting for the loops below
            bf16_t      lane_result   [NUM_LANES];
            logic       lane_valid    [NUM_LANES];
            logic       lane_ready    [NUM_LANES];
            vsel_t      lane_vd       [NUM_LANES];
            slice_idx_t lane_elem_idx [NUM_LANES];
            logic       lane_last     [NUM_LANES];

            // WB ready for this FU: take lane 0’s ready_in as representative
            logic wb_ready_fu;
            assign wb_ready_fu = rc_in.ready_in[0][fu];

            // Slice out per-lane signals
            for (genvar ln = 0; ln < NUM_LANES; ln++) begin : GEN_LANE
                assign lane_result   [ln] = rc_in.result   [ln][fu];
                assign lane_valid    [ln] = rc_in.valid_in [ln][fu];
                assign lane_vd       [ln] = rc_in.vd       [ln][fu];
                assign lane_elem_idx [ln] = rc_in.elem_idx [ln][fu];
                assign lane_last     [ln] = rc_in.last     [ln][fu];
            end

            // Per-FU collector that completes when it sees lane_last = 1
            rc_fu #(
                .NUM_LANES_P(NUM_LANES)
            ) u_rc_fu (
                .CLK          (CLK),
                .nRST         (nRST),
                .lane_result  (lane_result),
                .lane_valid   (lane_valid),
                .lane_ready   (lane_ready),
                .lane_vd      (lane_vd),
                .lane_elem_idx(lane_elem_idx),
                .lane_last    (lane_last),
                .wb_ready     (wb_ready_fu),
                .wb_valid     (rc_out.valid_o[fu]),
                .wb_result    (rc_out.result [fu]),
                .wb_vd        (rc_out.vd     [fu])
            );

            assign rc_out.ready_in[fu] = & { >> {lane_ready} };

        end
    endgenerate

endmodule