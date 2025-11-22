/*
    Chase Johnson
    Interface signals for add/sub vector module
*/

`ifndef VEXP_IF_VH
`define VEXP_IF_VH
`include "vector_types.vh"
`include "vector_if.vh"

interface vexp_if;
    import vector_pkg::*;

    //Inputs for Vector Exp Module
    logic [15:0] operand, result;
    logic valid_in, valid_out, ready_in, ready_out;

    
    modport vexp (
        input operand, valid_in, ready_out,
        output result, valid_out, ready_in
    );

    modport tb (
        input result, valid_out, ready_in,
        output operand, valid_in, ready_out
    );

endinterface
`endif

