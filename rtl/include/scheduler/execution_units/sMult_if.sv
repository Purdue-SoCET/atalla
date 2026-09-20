`ifndef SMULT_IF_VH
`define SMULT_IF_VH
`include "atalla_isa_types.vh"

interface sMult_if;
    import atalla_isa_pkg::*;

    logic [31:0] input1, input2, imm;
    logic [7:0] rdIn;
    logic ready_in, valid_in, imm_src;
    scalar_fu_enable_t scalar_type_enable;

    logic [31:0] data_out;
    logic [7:0] rdOut;
    logic valid_out, ready_out;

    modport mainport (
        input input1, input2, rdIn, valid_in, scalar_type_enable, ready_out, imm, imm_src,
        output data_out, valid_out, ready_in, rdOut
    );

    modport tb (
        input data_out, valid_out, ready_in, rdOut,
        output input1, input2, rdIn, valid_in, scalar_type_enable, ready_out, imm, imm_src
    );

endinterface
`endif
