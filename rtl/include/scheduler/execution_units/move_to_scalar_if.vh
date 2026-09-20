`ifndef MOVE_TO_SCALAR_IF_VH
`define MOVE_TO_SCALAR_IF_VH
`include "atalla_isa_types.vh"

interface move_to_scalar_if;
    import atalla_isa_pkg::*;

    logic valid_in, valid_out;
    logic ready_WB;
    logic [7:0] rdIn, rdOut;
    word_t data_in;
    word_t data_out;
    logic d2_ready;
    
    modport mainport (
        input valid_in, rdIn, data_in, ready_WB, 
        output valid_out, rdOut, data_out, d2_ready
    );


endinterface
`endif
