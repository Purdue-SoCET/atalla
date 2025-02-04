// Writeback unit testbench
// tahan

// mapped needs this
`include "writeback_if.vh"

// mapped timing needs this. 1ns is too fast
`timescale 1 ns / 1 ns

module writeback_tb;

    writeback_if wbif ();

    test PROG (wbif);

    control_unit DUT(.writeback_if(wbif));

endmodule