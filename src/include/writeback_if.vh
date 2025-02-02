/*
    Interface signals for the Writeback Module
*/

`ifndef WRITEBACK_IF_VH
`define WRITEBACK_IF_VH
`include "datapath_types.vh"

interface writeback_if;
    import datapath_pkg::*;

    // Inputs from Functional Units
    // 
    // Outputs of stage
    wb_t wb;
    
    modport IS (
        input dispatch, flush, freeze, wb,
        output out
    );

endinterface
`endif

