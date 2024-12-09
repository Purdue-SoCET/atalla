`ifndef FU_MATRIX_LS_IF_VH
`define FU_MATRIX_LS_IF_VH
`include "types_pkg.vh"

interface dispatch_if;
    import types_pkg::*;

    //Inputs to functional unit to stop the program
    logic flush, freeze;

    fetch_t fetch_p;

    //Inputs from Scratchpad letting the matrix functional unit that it got a hit
    logic mhit;

    word_t address, stride;
    
    modport DI (
        input mhit, flush, freeze,
        output address, stride
    );

endinterface
`endif
