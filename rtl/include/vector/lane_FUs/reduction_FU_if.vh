`ifndef REDUCTION_FU_IF_VH
`define REDUCTION_FU_IF_VH
`include "vector_pkg.vh"

interface reduction_FU_if;
    import vector_pkg::*;

    vector_if_reduction_in_t in;
    vector_if_reduction_out_t out;

    modport ruif (
        input in,
        output out
    );

endinterface


`endif