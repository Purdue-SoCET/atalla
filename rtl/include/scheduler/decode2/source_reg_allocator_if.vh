// Navya Datla 2/23/2026
`ifndef SOURCE_REG_ALLOCATOR_IF_VH
`define SOURCE_REG_ALLOCATOR_IF_VH

`include "atalla_isa_types.vh"

interface source_reg_allocator_if
    import atalla_isa_pkg::*;
#(
    parameter NUM_INSTRUCTIONS = 4,
    parameter READ_PORTS       = 4
);

    // Packed instruction arrays
    decoded_scalar_instr_t [NUM_INSTRUCTIONS-1:0] instrs_in;
    decoded_scalar_instr_t [NUM_INSTRUCTIONS-1:0] instrs_out;

    // Packed read port arrays
    logic [READ_PORTS-1:0]                     REN;
    logic [READ_PORTS-1:0][SCALAR_REG_W-1:0]   rsel;
    logic [READ_PORTS-1:0][31:0]               rdata;
    
    modport allocator (
        input  instrs_in,
        output instrs_out,
        output REN,
        output rsel,
        input  rdata
    );

endinterface

`endif