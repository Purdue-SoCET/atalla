`ifndef VREDUCTION_ALU_IF_VH
`define VREDUCTION_ALU_IF_VH
`include "vector_pkg.vh"

interface vreduction_alu_if;
    import vector_pkg::*;
    
    logic [15:0] value_a, value_b, value_out;
    alu_op_t alu_op;

    modport vralu (
        input value_a, value_b, alu_op,
        output value_out
    );
endinterface

`endif