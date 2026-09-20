`ifndef SCHEDULER_PKG_VH
`define SCHEDULER_PKG_VH
`include "atalla_isa_types.vh"


package scheduler_pkg;
    import atalla_isa_pkg::*;

    parameter SCALAR_DATA_LEN = 32;
    parameter RSEL_W = 8;
    parameter VSEL_W = 8;
    parameter MSEL_W = 4;
    parameter VEC_LEN = 32;
    parameter VEC_DATA_LEN = 16;
    parameter MASK_DATA_LEN = 32;
    parameter SWRITE_PORTS = 4;
    parameter VWRITE_PORTS = 4;
    parameter MWRITE_PORTS = 2;
    parameter INSTR_W = 48;
    parameter NUM_SCALAR_INSTRUCTIONS = 4;
    parameter NUM_VECTOR_INSTRUCTIONS = 4;
    parameter NUM_SDMA_INSTRUCTIONS = 4;

    typedef logic [INSTR_W-1:0] instr_t;
    typedef logic [RSEL_W-1:0] rsel_t;
    typedef logic [SCALAR_DATA_LEN-1:0] rdat_t;
    typedef logic [VSEL_W-1:0] vsel_t;
    typedef logic [VECTOR_LEN-1:0][VEC_DATA_LEN-1:0] vdat_t;
    typedef logic [MSEL_W-1:0] msel_t;
    typedef logic [MASK_DATA_LEN-1:0] mdat_t;

    typedef struct packed {
        rdat_t  [SWRITE_PORTS-1:0] s_data;
        rsel_t  [SWRITE_PORTS-1:0] s_rd; 
        logic   [SWRITE_PORTS-1:0] s_WEN;
        vdat_t [VWRITE_PORTS-1:0] v_data;
        vsel_t  [VWRITE_PORTS-1:0] v_rd;
        logic  [VWRITE_PORTS-1:0] v_WEN;
        mdat_t  [MWRITE_PORTS-1:0] m_data;
        msel_t  [MWRITE_PORTS-1:0] m_rd;
        logic  [MWRITE_PORTS-1:0] m_WEN;
        rsel_t [NUM_SDMA_INSTRUCTIONS-1:0] SDMA_s_rd; //rs1=rd for SDMA
        logic  [NUM_SDMA_INSTRUCTIONS-1:0] SDMA_s_WEN;
    } EXEC_WB_LATCH;

    typedef struct packed {
        logic [31:0] pc;
        logic [31:0] pc_pred_addr_out;
        logic predict_taken_out;
    } DEC2_WB_LATCH_PC;

    typedef struct packed {
        instr_t [NUM_SCALAR_INSTRUCTIONS-1:0] scalar_instrs;
        instr_t [NUM_VECTOR_INSTRUCTIONS-1:0] vector_instrs;
        instr_t [NUM_SDMA_INSTRUCTIONS-1:0] SDMA_instrs;
        word_t pc, pc_pred_addr;
        logic predict_taken;
        logic valid;
        
    } DEC1_DEC2_LATCH;

    typedef struct packed {
        decoded_vector_instr_t [NUM_VECTOR_INSTRUCTIONS-1:0] decoded_vector_instrs;
        decoded_SDMA_instr_t [NUM_SDMA_INSTRUCTIONS-1:0] decoded_SDMA_instrs;

    } DEC2_EX_VEC_SDMA_LATCH;

endpackage

`endif