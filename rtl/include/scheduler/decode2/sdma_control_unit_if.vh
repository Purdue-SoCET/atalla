//Navya Datla 2/12/2026

`include "atalla_isa_types.vh"

interface sdma_control_unit_if #(
    parameter NUM_INSTRUCTIONS = 4
);
    import atalla_isa_pkg::*;
    
    // Input: Bundle of instructions from fetch
    instr_t [NUM_INSTRUCTIONS-1:0] sdma_instrs;
    decoded_SDMA_instr_t [NUM_INSTRUCTIONS-1:0] decoded_sdma_instrs;
    
    modport cu (
        input sdma_instrs,
        output decoded_sdma_instrs
    );

    modport tb (
        input decoded_sdma_instrs,
        output sdma_instrs
    );
    
endinterface
