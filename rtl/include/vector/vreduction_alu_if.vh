`ifndef VREDUCTION_ALU_IF_VH
`define VREDUCTION_ALU_IF_VH

interface vreduction_alu_if;

    logic [15:0] value_a, value_b, value_out;
    logic [1:0] alu_op;

    modport vralu (
        input value_a, value_b, alu_op,
        output value_out
    );
endinterface

`endif