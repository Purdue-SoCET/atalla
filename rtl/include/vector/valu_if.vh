`ifndef VALU_IF_VH
`define VALU_IF_VH

// VALU interface definition
interface valu_if #(
    parameter int EXP_WIDTH = 8,
    parameter int MANT_WIDTH = 7
);
    localparam int WIDTH = EXP_WIDTH + MANT_WIDTH;

    import vector_pkg::*;
    
    // Input signals (from producer to VALU)
    struct packed {
        logic valid_in;
        logic ready_out;
        logic [WIDTH:0] operand1;
        logic [WIDTH:0] operand2;
        logic [1:0] alu_op;
    } in;
    
    // Output signals (from VALU to consumer)
    struct packed {
        logic valid_out;
        logic ready_in;
        logic [WIDTH:0] result;
    } out;
    
    // Modport for VALU module
    modport valu (
        input  in,
        output out
    );
    
endinterface

`endif // VALU_IF_VH