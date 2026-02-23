`ifndef SMULT_IF_VH
`define SMULT_IF_VH

interface sMult_if;

    logic [31:0] input1, input2, imm;
    logic [7:0] rdIn;
    logic ready_in, valid_in, sMult, imm_src;

    logic [31:0] data_out;
    logic [7:0] rdOut;
    logic valid_out, ready_out;

    modport mainport (
        input input1, input2, rdIn, valid_in, sMult, ready_out, imm, imm_src,
        output data_out, valid_out, ready_in, rdOut
    );

    modport tb (
        input data_out, valid_out, ready_in, rdOut,
        output input1, input2, rdIn, valid_in, sMult, ready_out, imm, imm_src
    );

endinterface
`endif
