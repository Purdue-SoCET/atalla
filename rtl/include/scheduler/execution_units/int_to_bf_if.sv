`ifndef INT_TO_BF_IF_VH
`define INT_TO_BF_IF_VH

interface int_to_bf_if;

    logic [31:0] inputInt;
    logic [7:0] rdIn;
    logic ready_out, valid_in;

    logic [15:0] outputBF;
    logic [7:0] rdOut;
    logic valid_out, ready_in;

    modport int_bf (
        input inputInt, ready_out, valid_in, rdIn,
        output outputBF, valid_out, ready_in, rdOut
    );

    modport tb (
        input outputBF, valid_out, ready_in, rdOut,
        output inputInt, ready_out, valid_in, rdIn
    );

endinterface
`endif
