`ifndef REDUCTION_FU_IF_VH
`define REDUCTION_FU_IF_VH
`include "vector_pkg.vh"

interface reduction_FU_if;
    import vector_pkg::*;

    reduction_FU_in_t in;
    functional_unit_out_t out;

    modport ruif (
        input in,
        output out
    );

endinterface


`endif