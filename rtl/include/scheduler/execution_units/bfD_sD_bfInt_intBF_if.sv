`ifndef BFD_SD_BFINT_INTBF_IF_VH
`define BFD_SD_BFINT_INTBF_IF_VH

interface bfD_sD_bfInt_intBF_if;

    logic [31:0] input1, input2;
    logic [7:0] rdIn;
    logic ready_in, valid_in, bf_div, s_div, s_mod, BF_to_int, int_to_BF;

    logic [31:0] data_out;
    logic [7:0] rdOut;
    logic valid_out, ready_out;

    modport mainport (
        input input1, input2, rdIn, valid_in, bf_div, s_div, s_mod, BF_to_int, int_to_BF, ready_out,
        output data_out, valid_out, ready_in, rdOut
    );

    modport tb (
        input data_out, valid_out, ready_in, rdOut,
        output input1, input2, rdIn, valid_in, bf_div, s_div, s_mod, BF_to_int, int_to_BF, ready_out
    );

endinterface
`endif
