/*
    Interface signals for the Matrix Load Store
*/
`ifndef MATRIX_LS_IF_VH
`define MATRIX_LS_IF_VH

// types
`include "datapath_types.vh"
`include "isa_types.vh"

interface matrix_ls_if;
// import types
import datapath_pkg::*;
import isa_pkg::*;

// Signals

/*
    Inputs: 
    enable: From issue queue
    ls_in: Load or Store
    rd_in: destination reg
    rs_in: source reg
    stride_in: stride
    imm_in   : immediate
    mhit: Scratchpad ready
*/

logic           mhit;
logic           enable;
logic [1:0]     ls_in;
logic [4:0]     rd_in;
logic [10:0]    imm_in;
word_t          stride_in, rs_in;

/*
    Outputs: 
    stride_out: stride
    ls_out: Load or store to Scratchpad
    imm_out: Immediate to Scratchpad
    rd_out: Matrix Reg destination (to Scratchpad)
    rs_out: Matrix Reg Source (to Scratchpad)
    done: done signal to Issue Queue
*/

logic           done;
logic [1:0]     ls_out;
logic [4:0]     rd_out;
logic [10:0]    imm_out;
word_t          address, stride_out;

// LS Matrix Port Map
modport mls (
    input   mhit, enable, ls_in, rd_in, rs_in, stride_in, imm_in,
    output  done, ls_out, rd_out, address, stride_out
);

endinterface

`endif //FU_MATRIX_LS_IF_VH
