//Navya Datla 2/23/2026

`include "atalla_isa_types.vh"

interface decode_2_if #(
    parameter NUM_INSTRUCTIONS = 4, 
    parameter WRITE_PORTS = 4, 
    parameter SCALAR_REG_BITS = 8, 
    parameter DATA_BITS = 5
);
    import atalla_isa_pkg::*;
    
    // Input: Bundle of instructions from fetch
    instr_t scalar_instrs [NUM_INSTRUCTIONS];
    decoded_scalar_instr_t decoded_scalar_instrs [NUM_INSTRUCTIONS];

    instr_t vector_instrs [NUM_INSTRUCTIONS];
    decoded_vector_instr_t decoded_vector_instrs [NUM_INSTRUCTIONS];

    instr_t SDMA_instrs [NUM_INSTRUCTIONS];
    decoded_SDMA_instr_t decoded_SDMA_instrs [NUM_INSTRUCTIONS];

    logic ready_DEC2_ex1, ready_DEC2_ex2, ready_DEC2_ex3, ready_DEC2_ex4, ready_DEC2_ex5;
    logic ready; //RAW hazards and structural hazards cleared 
    word_t pc_in, pc_out, pc_pred_addr_in, pc_pred_addr_out;
    logic predict_taken_in, predict_taken_out;

    logic                           scalar_WB_WEN [WRITE_PORTS];
    logic [SCALAR_REG_BITS-1:0] scalar_WB_wsel [WRITE_PORTS];
    logic [31:0]       scalar_WB_wdata [WRITE_PORTS];

    logic scalar_SDMA_WEN;
    logic [SCALAR_REG_BITS-1:0] scalar_SDMA_wsel;


    modport dec (
        input  scalar_instrs, vector_instrs, SDMA_instrs, pc_in, pc_pred_addr_in, predict_taken_in,
        input  ready_DEC2_ex1, ready_DEC2_ex2, ready_DEC2_ex3, ready_DEC2_ex4, ready_DEC2_ex5,
        input  scalar_WB_WEN, scalar_WB_wsel, scalar_WB_wdata, scalar_SDMA_wsel, scalar_SDMA_WEN,
        output decoded_scalar_instrs, decoded_vector_instrs, decoded_SDMA_instrs,
        output pc_out, pc_pred_addr_out, predict_taken_out, 
        output ready
    );

    modport tb (
        input decoded_scalar_instrs,
        output scalar_instrs
    );
    
endinterface
