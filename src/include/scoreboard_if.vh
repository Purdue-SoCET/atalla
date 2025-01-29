`ifndef SCOREBOARD_IF_VH
`define SCOREBOARD_IF_VH
`include "datapath_types.vh"

interface scoreboard_if;
    import datapath_pkg::*;

    logic flush, freeze;
    wb_t wb;

    issue_t out;
    
    modport IS (
        input flush, freeze, wb,
        output out
    );

endinterface
`endif
