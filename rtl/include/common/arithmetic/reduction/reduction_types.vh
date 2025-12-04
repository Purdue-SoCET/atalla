`ifndef REDUCTION_TYPES_H
`define REDUCTION_TYPES_H

package reduction_pkg;

    parameter LANES = 16;
    parameter NUM_ELEMENTS = 32;

    typedef struct packed {
        logic [NUM_ELEMENTS-1:0][15:0] vector_input;
        logic [LANES-1:0][15:0] lane_input;
        logic [4:0] imm;
        logic clear, broadcast, valid_in, ready_out;
        logic [1:0] reduction_type;
    } reduction_if_in_t;

    typedef struct packed {
        logic [NUM_ELEMENTS-1:0][15:0] vector_output;
        logic valid_out, ready_in;
    } reduction_if_out_t;

    typedef enum logic [1:0] {
        VR_MAX = 2'b00,
        VR_MIN = 2'b01,
        VR_SUM = 2'b10,
        VR_SUB = 2'b11
    } reduction_op;

endpackage

`endif