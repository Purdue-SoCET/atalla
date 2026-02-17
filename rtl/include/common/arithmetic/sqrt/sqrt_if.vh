`ifndef SQRT_IF_SV
`define SQRT_IF_SV
`include "sqrt_types.vh"

interface sqrt_if;
    import sqrt_pkg::*;

    sqrt_if_in_t in;
    sqrt_if_out_t out;

    modport srif (
        input in,
        output out
    );


endinterface  



`endif