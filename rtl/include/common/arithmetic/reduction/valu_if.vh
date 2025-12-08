`ifndef VALU_IF_VH
`define VALU_IF_VH


interface valu_if;

    logic [15:0] operand1, operand2, result;
    logic [1:0] alu_op;
    logic ready_in, ready_out, valid_in, valid_out;

    modport valu (
        input operand1, operand2, alu_op, valid_in, ready_out,
        output result, valid_out, ready_in
    );
endinterface

`endif