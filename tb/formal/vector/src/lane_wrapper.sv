`include "vector_if.vh"

// Expose internal performance signals via struct port
typedef struct packed {
    // VALU
    logic valu_busy;
    logic valu_issue;
    logic valu_fire;
    logic valu_stall_fifo;
    logic valu_stall_wb;
    
    // SQRT
    logic sqrt_busy;
    logic sqrt_issue;
    logic sqrt_fire;
    logic sqrt_stall_fifo;
    logic sqrt_stall_wb;
    
    // MUL
    logic mul_busy;
    logic mul_issue;
    logic mul_fire;
    logic mul_stall_fifo;
    logic mul_stall_wb;
    
    // DIV
    logic div_busy;
    logic div_issue;
    logic div_fire;
    logic div_stall_fifo;
    logic div_stall_wb;
} lane_perf_t;

module lane_wrapper (
    input logic CLK,
    input logic nRST,
    
    // Flattened or struct ports connecting to vector_if
    input  vector_pkg::lane_in_t  lane_in,
    output vector_pkg::lane_out_t lane_out,
    
    output lane_perf_t perf
);

    import vector_pkg::*;

    // Instantiate the interface
    vector_if vif();

    // Drive interface from ports
    assign vif.lane_in = lane_in;
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
    assign perf.valu_busy       = !u_lane.valu_seq_out.lane_ready;
    assign perf.valu_issue      = u_lane.valu_seq_out.valid;
    assign perf.valu_fire       = u_lane.valu_fire_valid;
    assign perf.valu_stall_fifo = u_lane.valu_issue_valid && !u_lane.valu_sync_ready;
    assign perf.valu_stall_wb   = u_lane.valu_hold_valid  && !lane_in.ready_in[3'b000]; // VALU=0

    // SQRT
    assign perf.sqrt_busy       = !u_lane.sqrt_seq_out.lane_ready;
    assign perf.sqrt_issue      = u_lane.sqrt_seq_out.valid;
    assign perf.sqrt_fire       = u_lane.sqrt_fire_valid;
    assign perf.sqrt_stall_fifo = u_lane.sqrt_seq_out.valid && !u_lane.sqrt_sync_ready;
    assign perf.sqrt_stall_wb   = u_lane.sqrt_hold_valid  && !lane_in.ready_in[3'b010]; // SQRT=2

    // MUL
    assign perf.mul_busy        = !u_lane.mul_seq_out.lane_ready;
    assign perf.mul_issue       = u_lane.mul_seq_out.valid;
    assign perf.mul_fire        = u_lane.mul_fire_valid;
    assign perf.mul_stall_fifo  = u_lane.mul_seq_out.valid && !u_lane.mul_sync_ready;
    assign perf.mul_stall_wb    = u_lane.mul_hold_valid   && !lane_in.ready_in[3'b011]; // MUL=3

    // DIV
    assign perf.div_busy        = !u_lane.div_seq_out.lane_ready;
    assign perf.div_issue       = u_lane.div_seq_out.valid;
    assign perf.div_fire        = u_lane.div_fire_valid;
    assign perf.div_stall_fifo  = u_lane.div_seq_out.valid && !u_lane.div_sync_ready;
    assign perf.div_stall_wb    = u_lane.div_hold_valid   && !lane_in.ready_in[3'b100]; // DIV=4

endmodule
