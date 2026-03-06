`ifndef RESULT_COLLECTOR_IF_VH
`define RESULT_COLLECTOR_IF_VH
`include "vector_pkg.vh"

interface result_collector_if #(

);
    import vector_pkg::*;
    //input signals
    result_collector_in_t in;
    result_collector_out_t out;

    modport rcif (
        input in,
        output out
    );

endinterface
`endif