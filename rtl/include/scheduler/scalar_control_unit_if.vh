//Navya Datla 2/12/2026

`include "atalla_isa_types.vh"

interface scalar_control_unit_if #(
    parameter NUM_INSTRUCTIONS = 4
);
    import atalla_isa_pkg::*;
    
    // Input: Bundle of instructions from fetch
    instr_t [NUM_INSTRUCTIONS-1:0] scalar_instrs;
    decoded_scalar_instr_t [NUM_INSTRUCTIONS-1:0] decoded_scalar_instrs;
    
    modport cu (
        input scalar_instrs,
        output decoded_scalar_instrs
    );

    modport tb (
        input decoded_scalar_instrs,
        output scalar_instrs
    );
    
endinterface
