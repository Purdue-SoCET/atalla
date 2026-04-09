//Navya Datla 2/12/2026

`include "atalla_isa_types.vh"

interface scheduler_core_if #(
    parameter NUM_SCALAR_INSTRS = 4, 
    parameter NUM_VECTOR_INSTRS = 4,
    parameter NUM_SDMA_INSTRS = 4
    
);
    import atalla_isa_pkg::*;

    //to dcache
    logic WEN, REN, mem_in_valid;
    logic [31:0] data_store, data_addr;

    //from dcache
    logic [31:0] data_load;
    logic hit, block_status;

    //fetch in
    logic iwait;
    instruction_packet_t iload; 
    logic ready; //op

    decoded_vector_instr_t [NUM_VECTOR_INSTRUCTIONS-1:0] decoded_vector_instrs;
    decoded_SDMA_instr_t [NUM_SDMA_INSTRUCTIONS-1:0] decoded_SDMA_instrs;

    modport sc (
        output WEN, REN, mem_in_valid, data_store, data_addr,
        input data_load, hit, block_status,
        input iwait, iload, 
        output ready, 
        output decoded_vector_instrs, decoded_SDMA_instrs
    );
        
endinterface
