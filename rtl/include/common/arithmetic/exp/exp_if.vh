/*
    Interface for exp
    Owner: Jacob Walter
*/

`ifndef EXP_IF_VH
`define EXP_IF_VH
`include "vector_types.vh"



interface exp_if;
    import vector_pkg::*;
    localparam ESZ = 16;

    typedef struct packed {
        logic [ESZ-1:0] operand;
        logic valid_in;
        logic ready_out;
    } exp_if_in_t;

    typedef struct packed {
        logic [ESZ-1:0] result;
        logic valid_out;
        logic ready_in;
    } exp_if_out_t;

    exp_if_in_t in;
    exp_if_out_t out;
    
    modport exif (
        input in,
        output out
    );

endinterface
`endif