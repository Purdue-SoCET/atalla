`ifndef SCOREBOARD_IF_VH
`define SCOREBOARD_IF_VH
`include "datapath_types.vh"

interface scoreboard_if;
    import datapath_pkg::*;

    // inputs
    fetch_t fetch;
    logic flush, freeze;

    wb_ctr_t wb;

    issue_t out;
    
    modport SB (
        input fetch, flush, freeze, wb, 
        output out
    );

    modport tb (
        input out,
        output fetch, flush, freeze, wb
    );
    

endinterface
`endif
