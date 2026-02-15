`ifndef FUNCTIONAL_UNIT_IF_VH
`define FUNCTIONAL_UNIT_IF_VH
`include "vector_pkg.vh"

interface functional_unit_if #(

);
    import vector_pkg::*;
    //input signals
    functional_unit_in_t in;
    functional_unit_out_t out;

    modport fuif (
        input in,
        output out
    );

endinterface


`endif