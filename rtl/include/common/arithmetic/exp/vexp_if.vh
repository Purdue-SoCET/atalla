/*
    Interface for exp
    Owner: Jacob Walter
*/

`ifndef VEXP_IF_VH
`define VEXP_IF_VH
`include "vector_types.vh"

interface vexp_if;
    import vector_pkg::*;

    typedef struct packed {
        logic [15:0] operand;
        logic valid_in;
        logic ready_out;
    } sqrt_if_in_t;

    typedef struct packed {
        logic [15:0] result;
        logic valid_out;
        logic ready_in;
    } sqrt_if_out_t;

    sqrt_if_in_t in;
    sqrt_if_out_t out;
    
    modport exif (
        input in,
        output out
    );

endinterface
`endif