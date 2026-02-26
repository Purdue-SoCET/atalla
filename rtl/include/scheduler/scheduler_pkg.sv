`ifndef SCHEDULER_PKG_VH
`define SCHEDULER_PKG_VH
`include "atalla_isa_types.vh"


package scheduler_pkg;
    import atalla_isa_pkg::*;

    parameter RDATA_W = 32;
    parameter RIDX_W = 8;
    parameter SWRITE_PORTS = 4;
    parameter INSTR_W = 48;
    parameter NUM_INSTRUCTIONS = 4;

    typedef logic [RIDX_W-1:0] rsel_t;
    typedef logic [RDATA_W-1:0] rdat_t;
    typedef logic [INSTR_W-1:0] instr_t;

    typedef struct packed {
        rdat_t  [SWRITE_PORTS-1:0] data;
        rsel_t  [SWRITE_PORTS-1:0] rd; 
        logic   [SWRITE_PORTS-1:0] WEN;
    } EXEC_WB_LATCH;

    typedef struct packed {
        logic [31:0] pc;
        logic [31:0] pc_pred_addr_out;
        logic predict_taken_out;
    } DEC2_WB_LATCH_PC;

    typedef struct packed {
        instr_t [NUM_INSTRUCTIONS-1:0] scalar_instrs;
        word_t pc, pc_pred_addr;
        logic predict_taken;      
        
    } DEC1_DEC2_LATCH;

endpackage

`endif