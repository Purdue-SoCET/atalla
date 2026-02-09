`include "vector_if.vh"

// Expose internal performance signals via struct port
typedef struct packed {
    // VALU
    logic valu_work;
    logic valu_stall;
    logic valu_starve;

    // SQRT
    logic sqrt_work;
    logic sqrt_stall;
    logic sqrt_starve;

    // MUL
    logic mul_work;
    logic mul_stall;
    logic mul_starve;

    // DIV
    logic div_work;
    logic div_stall;
    logic div_starve;
} lane_perf_t;

module lane_wrapper (
    input logic CLK,
    input logic nRST,
    
    // Flattened or struct ports connecting to vector_if
    input  vector_pkg::lane_in_t  lane_in,
    input  logic                  valid_in_mask, // Controls valid_in bits
    output vector_pkg::lane_out_t lane_out,
    
    output lane_perf_t perf
);

    import vector_pkg::*;

    // Instantiate the interface
    vector_if vif();

    // Mask the valid_in bits based on control signal
    lane_in_t lane_in_masked;
    always_comb begin
        lane_in_masked = lane_in;
        // Broadcast mask to all 5 FUs
        lane_in_masked.valid_in = lane_in.valid_in & {5{valid_in_mask}};
    end

    // Drive interface from masked ports
    assign vif.lane_in = lane_in_masked;
    assign lane_out = vif.lane_out;

    // Instantiate Lane
    lane #(
        .LANE_ID(0)
    ) u_lane (
        .CLK(CLK),
        .nRST(nRST),
        .lif(vif.lane)
    );

    // -------------------------------------------------------------------------
    // Drive Performance Ports (Hierarchical Access)
    // -------------------------------------------------------------------------
    
    // VALU
    assign perf.valu_work       = u_lane.valu_fire_valid;
    assign perf.valu_stall      = (u_lane.valu_issue_valid && !u_lane.valu_sync_ready) || 
                                  (u_lane.valu_hold_valid  && !lane_in.ready_in[3'b000]);
    assign perf.valu_starve     = !u_lane.valu_seq_out.valid;

    // SQRT
    assign perf.sqrt_work       = u_lane.sqrt_fire_valid;
    assign perf.sqrt_stall      = (u_lane.sqrt_seq_out.valid && !u_lane.sqrt_sync_ready) || 
                                  (u_lane.sqrt_hold_valid  && !lane_in.ready_in[3'b010]);
    assign perf.sqrt_starve     = !u_lane.sqrt_seq_out.valid;

    // MUL
    assign perf.mul_work        = u_lane.mul_fire_valid;
    assign perf.mul_stall       = (u_lane.mul_seq_out.valid && !u_lane.mul_sync_ready) || 
                                  (u_lane.mul_hold_valid   && !lane_in.ready_in[3'b011]);
    assign perf.mul_starve      = !u_lane.mul_seq_out.valid;

    // DIV
    assign perf.div_work        = u_lane.div_fire_valid;
    assign perf.div_stall       = (u_lane.div_seq_out.valid && !u_lane.div_sync_ready) || 
                                  (u_lane.div_hold_valid   && !lane_in.ready_in[3'b100]);
    assign perf.div_starve      = !u_lane.div_seq_out.valid;

endmodule
