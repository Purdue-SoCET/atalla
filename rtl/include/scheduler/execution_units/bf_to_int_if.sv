`ifndef BF_TO_INT_IF_VH
`define BF_TO_INT_IF_VH

interface bf_to_int_if;

    logic [15:0] inputBF;
    logic [7:0] rdIn;
    logic ready_out, valid_in;

    logic [31:0] outputInt;
    logic [7:0] rdOut;
    logic valid_out, ready_in;

    modport bf_int (
        input inputBF, ready_out, valid_in, rdIn,
        output outputInt, valid_out, ready_in, rdOut
    );

    modport tb (
        input outputInt, valid_out, ready_in, rdOut,
        output inputBF, ready_out, valid_in, rdIn
    );

endinterface
`endif
