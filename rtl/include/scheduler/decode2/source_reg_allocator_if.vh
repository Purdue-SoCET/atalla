//Navya Datla 2/23/2026
`ifndef SOURCE_REG_ALLOCATOR_IF_VH
`define SOURCE_REG_ALLOCATOR_IF_VH

`include "atalla_isa_types.vh"

interface source_reg_allocator_if
    import atalla_isa_pkg::*;
#(
    parameter NUM_INSTRUCTIONS = 4,
    parameter READ_PORTS       = 4
);

    decoded_scalar_instr_t instrs_in  [NUM_INSTRUCTIONS];
    decoded_scalar_instr_t instrs_out [NUM_INSTRUCTIONS];

    logic                         REN   [READ_PORTS];
    logic [SCALAR_REG_W-1:0]      rsel  [READ_PORTS];
    logic [31:0]                  rdata [READ_PORTS];
    
    modport allocator (
        input  instrs_in,
        output instrs_out,
        output REN,
        output rsel,
        input  rdata
    );

endinterface

`endif
