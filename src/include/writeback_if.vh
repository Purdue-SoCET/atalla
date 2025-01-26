/*
    Interface signals for the Writeback Module
*/
`ifndef WRITEBACK_IF_VH
`define WRITEBACK_IF_VH

// types
`include "datapath_types.vh"
`include "isa_types.vh"

interface writeback_if;
// import types
import datapath_pkg::*;
import isa_pkg::*;

// Signals

/*
    Inputs: 
    done_load: Done Signal for the Load FU
    done_alu:  Done Signal for the ALU FU
    alu_output: Output of ALU
    alu_rd: Destination Reg of ALU
    load_output: output of load
    load_rd: Destination Reg of Load FU
*/

logic           done_load, done_alu;
word_t          alu_output, load_output;
regbits_t       alu_rd, load_rd;

/*
    Outputs: 
    rd_sel: destination register select
    rd_data: destination register data
*/

regbits_t       rd_sel;
word_t          rd_data;

// LS Matrix Port Map
modport wb (
    input   done_load, done_alu, alu_output, load_output, alu_rd, load_rd,
    output  rd_sel, rd_data
);

endinterface

`endif //FU_MATRIX_LS_IF_VH
