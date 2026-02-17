`ifndef ADDSUB_BF16_WRAPPER_IF_VH
`define ADDSUB_BF16_WRAPPER_IF_VH

interface addsub_bf16_wrapper_if;

    logic [15:0] bf1_in, bf2_in;
    logic [7:0] rdIn;
    logic ready_in, valid_in, add_sub;

    logic [15:0] bf_out;
    logic [7:0] rdOut;
    logic valid_out, ready_out;

    modport bf16_addsub (
        input bf1_in, bf2_in, rdIn, valid_in, add_sub, ready_out,
        output bf_out, valid_out, ready_in, rdOut
    );

    modport tb (
        input bf_out, valid_out, ready_in, rdOut,
        output bf1_in, bf2_in, rdIn, valid_in, add_sub, ready_out
    );

endinterface
`endif
