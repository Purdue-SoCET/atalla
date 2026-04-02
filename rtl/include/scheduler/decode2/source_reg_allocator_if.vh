// Navya Datla 2/23/2026
`ifndef SOURCE_REG_ALLOCATOR_IF_VH
`define SOURCE_REG_ALLOCATOR_IF_VH

`include "atalla_isa_types.vh"

interface source_reg_allocator_if
    import atalla_isa_pkg::*;
#(
    parameter NUM_SCALAR_INSTRUCTIONS = 4,
    parameter NUM_VECTOR_INSTRUCTIONS = 4,
    parameter NUM_SDMA_INSTRUCTIONS = 2,
    parameter SCALAR_READ_PORTS       = 4, 
    parameter VECTOR_READ_PORTS       = 4,
    parameter MASK_READ_PORTS         = 2
);

    // Packed instruction arrays
    decoded_scalar_instr_t [NUM_SCALAR_INSTRUCTIONS-1:0] scalar_instrs_in;
    decoded_scalar_instr_t [NUM_SCALAR_INSTRUCTIONS-1:0] scalar_instrs_out;

    decoded_vector_instr_t [NUM_VECTOR_INSTRUCTIONS-1:0] vector_instrs_in;
    decoded_vector_instr_t [NUM_VECTOR_INSTRUCTIONS-1:0] vector_instrs_out;

    decoded_SDMA_instr_t [NUM_SDMA_INSTRUCTIONS-1:0] sdma_instrs_in;
    decoded_SDMA_instr_t [NUM_SDMA_INSTRUCTIONS-1:0] sdma_instrs_out;

    // Packed read port arrays
    logic [SCALAR_READ_PORTS-1:0]                     scalar_REN;
    logic [SCALAR_READ_PORTS-1:0][SCALAR_REG_W-1:0]   scalar_rsel;
    logic [SCALAR_READ_PORTS-1:0][31:0]               scalar_rdata;

    logic [VECTOR_READ_PORTS-1:0]                     vector_REN;
    logic [VECTOR_READ_PORTS-1:0][VECTOR_REG_W-1:0]   vector_rsel;
    logic [VECTOR_READ_PORTS-1:0][VECTOR_LEN-1:0][15:0] vector_rdata;

    logic [MASK_READ_PORTS-1:0]                     mask_REN;
    logic [MASK_READ_PORTS-1:0][MASK_REG_W-1:0]     mask_rsel;
    logic [MASK_READ_PORTS-1:0][31:0]               mask_rdata;
    
    modport allocator (
        input  scalar_instrs_in,
        input vector_instrs_in,
        input sdma_instrs_in,
        output scalar_instrs_out,
        output vector_instrs_out,
        output sdma_instrs_out,
        output scalar_REN,
        output scalar_rsel,
        input  scalar_rdata, 
        output vector_REN,
        output vector_rsel,
        input  vector_rdata,
        output mask_REN,
        output mask_rsel,
        input  mask_rdata
    );

endinterface

`endif