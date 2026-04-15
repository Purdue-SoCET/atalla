`ifndef LANE_IF_VH
`define LANE_IF_VH
`include "vector_pkg.vh"

interface lane_if #(

);
    import vector_pkg::*;

    lane_in_t in;
    lane_out_t out;

    modport lif (
        input in,
        output out
    );

    modport lane_in (
        input in
    );

    modport lane_out (
        output out
    );

    modport slicer (
        output in
    );
endinterface

`endif