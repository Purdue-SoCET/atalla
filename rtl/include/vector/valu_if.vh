`ifndef VALU_IF_VH
`define VALU_IF_VH

`include "vector_pkg.vh"

interface valu_if;

    import vector_pkg::*;

    valu_if_in_t in;
    valu_if_out_t out;

    modport valu (
        input in,
        output out
    );

endinterface

`endif