`ifndef LANE_SEQUENCER_IF_VH
`define LANE_SEQUENCER_IF_VH

`include "vector_pkg.vh"

interface lane_sequencer_if;

    import vector_pkg::*;

    lane_sequencer_if_in_t in;
    lane_sequencer_if_out_t out;

    modport lane_sequencer(
        input in,
        output out
    );
  
endinterface
`endif