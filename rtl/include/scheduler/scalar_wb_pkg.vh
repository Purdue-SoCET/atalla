`ifndef SCALAR_WB_PKG_VH
`define SCALAR_WB_PKG_VH

package scalar_wb_pkg;
    parameter RDATA_W = 32;
    parameter NUM_FU = 9;
    parameter RIDX_W = 8;
    parameter SWRITE_PORTS = 4;

    typedef logic [RIDX_W-1:0] rsel_t;
    typedef logic [RDATA_W-1:0] rdat_t;

    typedef struct packed {
        rdat_t  [NUM_FU-1:0] data;
        logic   [NUM_FU-1:0] ready_in;  // from WB buffer
        logic   [NUM_FU-1:0] valid_in;  // from execute
        rsel_t  [NUM_FU-1:0] rd; 
    } scalar_wb_in_t;

    typedef struct packed {
        rdat_t  [SWRITE_PORTS-1:0] data;
        rsel_t  [SWRITE_PORTS-1:0] rd; 
        logic   [SWRITE_PORTS-1:0] WEN;
    } scalar_wb_out_t;

endpackage

`endif