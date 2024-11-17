`ifndef DISPATCH_IF_VH
`define DISPATCH_IF_VH
`include "types_pkg.vh"

interface dispatch_if;
    import types_pkg::*;

    //Inputs from fetch
    fetch_t fetch;

    // Inputs to latch
    logic flush, freeze;

    // Inputs from issue 
    logic [2:0] fu_busy;
    
    // Inputs from memory
    logic ihit;
    
    // Outputs of stage
    dispatch_t out;
    
    modport DI (
        input fetch, flush, freeze, fu_busy, ihit,
        output out
    );

endinterface
`endif
