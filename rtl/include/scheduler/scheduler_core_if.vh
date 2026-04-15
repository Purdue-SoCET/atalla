//Navya Datla 2/12/2026

`include "atalla_isa_types.vh"
`include "vector_pkg.vh"
`include "scpad_pkg.sv"

interface scheduler_core_if #(
    parameter NUM_SCALAR_INSTRS = 4, 
    parameter NUM_VECTOR_INSTRS = 4,
    parameter NUM_SDMA_INSTRS = 4, 
    parameter SCALAR_REG_BITS = 8
    
);
    import atalla_isa_pkg::*;
    import vector_pkg::*;
    import scpad_pkg::*;

    //to dcache
    logic WEN, REN, mem_in_valid;
    logic [31:0] data_store, data_addr;

    //from dcache
    logic [31:0] data_load;
    logic hit, block_status;

    //fetch in
    logic ihit;
    instruction_packet_t iload; 
    logic ready; //op

    // decoded_vector_instr_t [NUM_VECTOR_INSTRUCTIONS-1:0] decoded_vector_instrs;
    // decoded_SDMA_instr_t [NUM_SDMA_INSTRUCTIONS-1:0] decoded_SDMA_instrs;

    vector_if_gsau_in_t gsau_in;
    vector_if_vlsu_in_t vlsu_in;
    vector_if_lanes_in_t lanes_in;
    vector_wb_in_t vector_wb_in;

    vector_if_wb_ready_t vector_if_wb_ready; //to vc

    logic [NUM_SDMA_INSTRS-1:0] [SCALAR_REG_BITS-1:0] SDMA_scalar_rs1s;
    logic [NUM_SDMA_INSTRS-1:0] SDMA_scalar_WEN;
  
    sched_req_t [NUM_SDMA_INSTRS-1:0] scpad_in;

    modport sc (
        output WEN, REN, mem_in_valid, data_store, data_addr,
        input data_load, hit, block_status,
        input ihit, iload, 
        output ready, 
        output lanes_in, vlsu_in, gsau_in, scpad_in, 
        input vector_wb_in, //from vc
        output vector_if_wb_ready, //back to vector core for write bank conflict prevention
        input SDMA_scalar_rs1s, SDMA_scalar_WEN //to dependency checker from scpad
    );
        
endinterface
