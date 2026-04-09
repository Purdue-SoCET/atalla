//Navya Datla 2/12/2026

`include "atalla_isa_types.vh"

interface vector_control_unit_if #(
    parameter NUM_INSTRUCTIONS = 4
);
    import atalla_isa_pkg::*;
    
    // Input: Bundle of instructions from fetch
    instr_t [NUM_INSTRUCTIONS-1:0] vector_instrs;
    decoded_vector_instr_t [NUM_INSTRUCTIONS-1:0] decoded_vector_instrs;
    
    modport cu (
        input vector_instrs,
        output decoded_vector_instrs
    );

    modport tb (
        input decoded_vector_instrs,
        output vector_instrs
    );
    
endinterface