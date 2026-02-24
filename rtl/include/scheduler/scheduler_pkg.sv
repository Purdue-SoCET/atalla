`ifndef SCHEDULER_PKG_VH
`define SCHEDULER_PKG_VH

package scheduler_pkg;
    parameter RDATA_W = 32;
    parameter RIDX_W = 8;
    parameter SWRITE_PORTS = 4;

    typedef logic [RIDX_W-1:0] rsel_t;
    typedef logic [RDATA_W-1:0] rdat_t;

    typedef struct packed {
        rdat_t  [SWRITE_PORTS-1:0] data;
        rsel_t  [SWRITE_PORTS-1:0] rd; 
        logic   [SWRITE_PORTS-1:0] WEN;
    } EXEC_WB_LATCH;

    typedef struct packed {
        logic [31:0] pc;
        logic [31:0] pc_pred_addr_out;
        logic predict_taken_out
    } DEC2_WB_LATCH_PC;

endpackage

`endif