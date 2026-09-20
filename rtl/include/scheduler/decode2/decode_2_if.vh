// Navya Datla 2/23/2026

`include "atalla_isa_types.vh"

interface decode_2_if #(
    parameter NUM_SCALAR_INSTRUCTIONS = 4,
    parameter NUM_VECTOR_INSTRUCTIONS = 4,
    parameter NUM_SDMA_INSTRUCTIONS = 4,
    parameter SCALAR_WRITE_PORTS = 4, 
    parameter SCALAR_REG_BITS = 8, 
    parameter SCALAR_DATA_LENGTH = 32, 
    parameter VECTOR_WRITE_PORTS = 4, 
    parameter VECTOR_REG_BITS = 8,
    parameter VECTOR_LEN = 32, 
    parameter VECTOR_DATA_LEN = 16,
    parameter MASK_WRITE_PORTS = 2, 
    parameter MASK_REG_BITS = 4, 
    parameter MASK_DATA_LENGTH = 32
);
    import atalla_isa_pkg::*;
    
    // Packed instruction bundles
    instr_t                [NUM_SCALAR_INSTRUCTIONS-1:0] scalar_instrs;
    decoded_scalar_instr_t [NUM_SCALAR_INSTRUCTIONS-1:0] decoded_scalar_instrs;

    instr_t                [NUM_VECTOR_INSTRUCTIONS-1:0] vector_instrs;
    decoded_vector_instr_t [NUM_VECTOR_INSTRUCTIONS-1:0] decoded_vector_instrs;

    instr_t                [NUM_SDMA_INSTRUCTIONS-1:0] SDMA_instrs;
    decoded_SDMA_instr_t   [NUM_SDMA_INSTRUCTIONS-1:0] decoded_SDMA_instrs;

    logic ready_DEC2_ex1, ready_DEC2_ex2, ready_DEC2_ex3, ready_DEC2_ex4, ready_DEC2_ex5;
    logic vec_alu_ready, vec_mul_ready, vec_exp_ready, vec_reduction_ready, gsau_ready;
    logic movement_ready;
    logic [NUM_SDMA_INSTRUCTIONS-1:0] vlsu_ready; //one signal per scpad
    logic scpad_busy [NUM_SDMA_INSTRUCTIONS]; //one per scpad

    logic ready; // RAW hazards and structural hazards cleared 
    logic scalar_halt_ready, vector_halt_ready, mask_halt_ready;

    word_t pc_in, pc_out, pc_pred_addr_in, pc_pred_addr_out;
    logic  predict_taken_in, predict_taken_out;

    // SCALAR - WB
    logic [SCALAR_WRITE_PORTS-1:0]scalar_WB_WEN;
    logic [SCALAR_WRITE_PORTS-1:0][SCALAR_REG_BITS-1:0]    scalar_WB_wsel;
    logic [SCALAR_WRITE_PORTS-1:0][SCALAR_DATA_LENGTH-1:0] scalar_WB_wdata;

    // VECTOR - WB 
    logic [VECTOR_WRITE_PORTS-1:0][VECTOR_REG_BITS-1:0]                 vector_WB_wsel;
    logic [VECTOR_WRITE_PORTS-1:0]                                      vector_WB_WEN;
    logic [VECTOR_WRITE_PORTS-1:0][VECTOR_LEN-1:0][VECTOR_DATA_LEN-1:0] vector_WB_wdata;

    // MASK - WB
    logic [MASK_WRITE_PORTS-1:0][MASK_REG_BITS-1:0]     mask_WB_wsel;
    logic [MASK_WRITE_PORTS-1:0]                        mask_WB_WEN;
    logic [MASK_WRITE_PORTS-1:0][MASK_DATA_LENGTH-1:0]  mask_WB_wdata;
    
    // SCALAR - SDMA WB (this is just for clearing the bits bc it's not actually writing anything back)
    logic [NUM_SDMA_INSTRUCTIONS-1:0] scalar_SDMA_WB_WEN;
    logic [NUM_SDMA_INSTRUCTIONS-1:0][SCALAR_REG_BITS-1:0] scalar_SDMA_WB_wsel;

    modport dec (
        input  scalar_instrs, vector_instrs, SDMA_instrs,
        input  pc_in, pc_pred_addr_in, predict_taken_in,
        input  ready_DEC2_ex1, ready_DEC2_ex2, ready_DEC2_ex3, ready_DEC2_ex4, ready_DEC2_ex5,
        input vec_alu_ready, vec_mul_ready, vec_exp_ready, vec_reduction_ready, vlsu_ready, gsau_ready, scpad_busy, movement_ready,
        input scalar_WB_WEN, scalar_WB_wsel, scalar_WB_wdata,
        input vector_WB_wsel, vector_WB_WEN, vector_WB_wdata,
        input mask_WB_wsel, mask_WB_WEN, mask_WB_wdata,
        input scalar_SDMA_WB_WEN, scalar_SDMA_WB_wsel,

        output decoded_scalar_instrs, decoded_vector_instrs, decoded_SDMA_instrs,
        output pc_out, pc_pred_addr_out, predict_taken_out, 
        output ready, scalar_halt_ready, vector_halt_ready, mask_halt_ready
    );

    modport tb (
        input  decoded_scalar_instrs,
        output scalar_instrs
    );
    
endinterface