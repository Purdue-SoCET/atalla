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
    input  fp16_t                    lane_result   [NUM_LANES_P],
    input  logic                     lane_valid    [NUM_LANES_P],
    output logic                     lane_ready    [NUM_LANES_P],
    input  vsel_t                    lane_vd       [NUM_LANES_P],
    input  slice_idx_t               lane_elem_idx [NUM_LANES_P],
    input  logic                     lane_last     [NUM_LANES_P],

    // To WB buffer
    input  logic                     wb_ready,
    output logic                     wb_valid,
    output vreg_t                    wb_result,
    output vsel_t                    wb_vd
);

    // ------------------------------------------------------------
    // Locals
    // ------------------------------------------------------------
    localparam int SLICE_W = $bits(slice_idx_t);
    localparam int ELEM_W  = $bits(fp16_t);

    // Renamed 'buf' to 'res_buffer' because 'buf' is a reserved keyword
    vreg_t     res_buffer;
    vsel_t     cur_vd;
    logic      have_vd;
    logic      is_full; // Renamed full -> is_full (optional, but safer style)

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
        end else begin
            if (is_full) begin
                // Hold until WB accepts the vector
                if (wb_valid && wb_ready) begin
                    is_full <= 1'b0;
                    have_vd <= 1'b0;
                end
            end else begin
                for (int l = 0; l < NUM_LANES_P; l++) begin
                    if (lane_valid[l] && lane_ready[l]) begin
                        // Inline index calculation (Function removed)
                        // Concatenate Lane bits + Element bits to get global flat index
                        int unsigned gidx;
                        gidx = { l[$clog2(NUM_LANES_P)-1:0], lane_elem_idx[l] };

                        // Write to the buffer
                        res_buffer[gidx*ELEM_W +: ELEM_W] <= lane_result[l];

                        // Latch vd on first element
                        if (!have_vd) begin
                            cur_vd  <= lane_vd[l];
                            have_vd <= 1'b1;
                        end

                        // Check for last element
                        if (lane_last[l]) begin
                            is_full <= 1'b1;
                        end
                    end
                end
            end
        end
    end

endmodule