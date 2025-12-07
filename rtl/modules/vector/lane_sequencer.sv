//`include "vector_pkg.vh"
import vector_pkg::*;

// ----------------------------------------
// Lane sequencer
// ----------------------------------------
module lane_sequencer (
    input  logic           CLK,
    input  logic           nRST,
    input  lane_seq_in_t   lane_in,
    output lane_seq_out_t  lane_out
);
    // FSM states
    typedef enum logic { IDLE, BUSY } state_t;
    state_t     state, next_state;

    // Latched copy of input slice
    lane_seq_in_t  reg_slice;

    // Element index
    slice_idx_t    elem_idx_q, elem_idx_next;

    // Handshake
    logic          elem_accepted;
    logic          lane_ready;

    // Element is accepted when we are asserting valid and consumer is ready
    //assign elem_accepted = lane_out.valid && lane_in.ready;
    //assign elem_accepted = lane_out.valid && lane_in.ready && lane_out.mask_bit;
    assign elem_accepted = (state == BUSY) && lane_out.valid && lane_in.ready;


    // -----------------------------
    // Datapath: build lane_out
    // -----------------------------
    always_comb begin
        // Default all fields to 0
        lane_out = '0;

        lane_out.elem_idx = elem_idx_q;
        
        // Metadata passthrough
        lane_out.vd  = reg_slice.vd;
        lane_out.vop = reg_slice.vop;
        lane_out.rm  = reg_slice.rm;

        // Current element data
        lane_out.v1_elem  = reg_slice.v1[elem_idx_q];
        lane_out.v2_elem  = reg_slice.v2[elem_idx_q];
        lane_out.mask_bit = reg_slice.vmask[elem_idx_q];

        // Valid while we're busy on this slice
        // If you want to skip masked-off elements entirely, you can change this to:
        // lane_out.valid = (state == BUSY) && reg_slice.valid && lane_out.mask_bit;
        lane_out.valid = (state == BUSY) && reg_slice.valid;

        // lane_ready is computed by the FSM block below
        lane_out.lane_ready = lane_ready;
    end

    // -----------------------------
    // Sequential: state + index + slice latch
    // -----------------------------
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            state      <= IDLE;
            elem_idx_q <= '0;
            reg_slice  <= '0;
        end else begin
            state <= next_state;

            if (state == IDLE) begin
                // Always park at element 0 when idle
                elem_idx_q <= '0;

                // Only (re)latch slice when we actually start BUSY
                if (next_state == BUSY) begin
                    reg_slice <= lane_in;
                end
            end
            else if (state == BUSY && elem_accepted) begin
                elem_idx_q <= elem_idx_next;
            end
        end
    end


    // -----------------------------
    // Combinational: FSM + lane_ready
    // -----------------------------
    always_comb begin
        next_state    = state;
        elem_idx_next = elem_idx_q;
        lane_ready    = 1'b0;

        unique case (state)
            IDLE: begin
                // Ready to accept a new slice
                lane_ready = 1'b1;

                // Latch when producer asserts valid
                if (lane_in.valid) begin
                    next_state = BUSY;
                end
            end

            BUSY: begin
                // Not ready for a new slice while serializing current one
                lane_ready = 1'b0;

                if (elem_accepted) begin
                    if (elem_idx_q == SLICE_W - 1) begin
                        // Last element consumed, go idle
                        next_state = IDLE;
                    end else begin
                        // Move to next element
                        elem_idx_next = elem_idx_q + 1'b1;
                    end
                end
            end
        endcase
    end

endmodule
