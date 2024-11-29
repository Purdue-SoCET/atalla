// Matrix LS unit testbench
// tahan

// mapped needs this
`include "fu_matrix_ls_if.vh"

// mapped timing needs this. 1ns is too fast
`timescale 1 ns / 1 ns

module fu_matrix_ls_tb;

    fu_matrix_ls_if mlsif ();

    test PROG (mlsif);

    control_unit DUT(.fu_matrix_ls_if(mlsif));

endmodule
