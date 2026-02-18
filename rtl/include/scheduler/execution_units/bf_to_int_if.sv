`ifndef BF_TO_INT_IF_VH
`define BF_TO_INT_IF_VH

interface bf_to_int_if;

    logic [15:0] inputBF;

    logic [31:0] outputInt;

    modport bf_int (
        input inputBF,
        output outputInt
    );

    modport tb (
        input outputInt,
        output inputBF
    );

endinterface
`endif
