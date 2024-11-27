`ifndef ISSUE_IF_VH
`define ISSUE_IF_VH
`include "datapath_types.vh"

interface issue_if;
    import datapath_pkg::*;

    //Inputs from dispatch
    dispatch_t dispatch;
    //TODO: add the n_fu signals from dispatch output

    // Inputs to latch
    logic flush, freeze;

    // Inputs from writeback
    wb_t wb;
    
    // Outputs of stage
    issue_t out;
    
    modport IS (
        input dispatch, flush, freeze, wb,
        output out
    );

endinterface
`endif
