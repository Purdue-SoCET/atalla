`ifndef VREDUCTION_IF_VH
`define VREDUCTION_IF_VH

`include "vector_types.vh"



interface vreduction_if #(
    parameter LANES = 16
);
    import vector_pkg::*;

    logic [LANES-1:0][15:0] lane_input;
    logic [NUM_ELEMENTS-1:0][15:0] vector_input;
    logic [NUM_ELEMENTS-1:0][15:0] vector_output;
    logic [1:0] reduction_type;
    logic input_valid, output_valid, clear, broadcast;
    logic [4:0] imm;
    logic input_ready, writeback_ready;
    
    modport ruif (
        input vector_input, lane_input, imm, reduction_type, clear, broadcast, input_valid, writeback_ready,
        output vector_output, output_valid, input_ready
    );
endinterface

`endif