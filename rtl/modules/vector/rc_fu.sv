// ------------------------------------------------------------
// rc_fu.sv
// Per-FU result collector
// ------------------------------------------------------------

`include "vector_if.vh"
`include "vector_types.vh"
import vector_pkg::*;

module rc_fu #(
    parameter int NUM_LANES_P = 16
) (
    input  logic                     CLK,
    input  logic                     nRST,

    // From lanes
    input  bf16_t                    lane_result   [NUM_LANES_P],
    input  logic                     lane_valid    [NUM_LANES_P],
    output logic                     lane_ready    [NUM_LANES_P],
    input  vsel_t                    lane_vd       [NUM_LANES_P],
    input  slice_idx_t               lane_elem_idx [NUM_LANES_P],
    input  logic                     lane_last     [NUM_LANES_P],  // not used for completion now

    // To WB buffer
    input  logic                     wb_ready,
    output logic                     wb_valid,
    output vreg_t                    wb_result,
    output vsel_t                    wb_vd
);

    // ------------------------------------------------------------
    // Locals
    // ------------------------------------------------------------
    localparam int ELEM_W   = $bits(bf16_t);
    // One full vector = VLMAX elements (from vector_pkg)
    localparam int TOTAL_ELEMS = NUM_LANES_P;  // 1 element per lane in current design/tests

    vreg_t     res_buffer;
    vsel_t     cur_vd;
    logic      have_vd;
    logic      is_full;

    // Count how many elements we have accepted into res_buffer
    int unsigned elem_count;

    // Backpressure: stall lanes when holding a full vector
    always_comb begin
        for (int l = 0; l < NUM_LANES_P; l++) begin
            lane_ready[l] = !is_full;
        end
    end

    // Outputs to WB
    assign wb_result = res_buffer;
    assign wb_vd     = cur_vd;
    assign wb_valid  = is_full;

    // ------------------------------------------------------------
    // Main collection logic
    // ------------------------------------------------------------
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            res_buffer <= '0;
            cur_vd     <= '0;
            have_vd    <= 1'b0;
            is_full    <= 1'b0;
            elem_count <= 0;
        end else begin
            // If we are holding a full vector, wait for WB handshake
            if (is_full) begin
                if (wb_valid && wb_ready) begin
                    // Vector consumed; get ready for next one
                    is_full    <= 1'b0;
                    have_vd    <= 1'b0;
                    elem_count <= 0;
                    // res_buffer / cur_vd will be overwritten by next vector
                end
            end else begin
                int unsigned writes_this_cycle;
                writes_this_cycle = 0;

                // Accept elements from any lanes that are valid
                for (int l = 0; l < NUM_LANES_P; l++) begin
                    if (lane_valid[l] && lane_ready[l]) begin
                        // Global flat index: {lane_bits, elem_idx_bits}
                        int unsigned gidx;
                        gidx = { l[$clog2(NUM_LANES_P)-1:0], lane_elem_idx[l] };

                        res_buffer[gidx*ELEM_W +: ELEM_W] <= lane_result[l];

                        writes_this_cycle++;

                        // Latch vd on first accepted element of the vector
                        if (!have_vd) begin
                            cur_vd  <= lane_vd[l];
                            have_vd <= 1'b1;
                        end
                    end
                end

                // Bump element count and decide if the vector is complete
                if (writes_this_cycle != 0) begin
                    int unsigned new_count;
                    new_count   = elem_count + writes_this_cycle;
                    elem_count <= new_count;

                    // When we've seen TOTAL_ELEMS elements, this vector is complete
                    if (new_count >= TOTAL_ELEMS) begin
                        is_full <= 1'b1;
                    end
                end
            end
        end
    end

endmodule