`ifndef BFD_SD_BFINT_INTBF_IF_VH
`define BFD_SD_BFINT_INTBF_IF_VH
`include "atalla_isa_types.vh"

interface bfD_sD_bfInt_intBF_if;
    import atalla_isa_pkg::*;

    logic [31:0] input1, input2, imm;
    logic [7:0] rdIn;
    logic ready_in, valid_in, imm_src;
    scalar_fu_enable_t scalar_type_enable;

    logic [31:0] data_out;
    logic [7:0] rdOut;
    logic valid_out, ready_out, mask_ready_out;

    logic to_mask_in, to_mask_out;

    modport mainport (
        input input1, input2, rdIn, valid_in, scalar_type_enable, ready_out, mask_ready_out, imm, imm_src, to_mask_in,
        output data_out, valid_out, ready_in, rdOut, to_mask_out
    );

    modport tb (
        input data_out, valid_out, ready_in, rdOut, to_mask_out,
        output input1, input2, rdIn, valid_in, scalar_type_enable, ready_out, mask_ready_out, imm, imm_src, to_mask_in
    );

endinterface
`endif
