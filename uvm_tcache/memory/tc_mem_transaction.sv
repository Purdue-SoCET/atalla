`ifndef TC_MEM_TRANSACTION_SV
`define TC_MEM_TRANSACTION_SV

import uvm_pkg::*;
`include "uvm_macros.svh"

class tc_mem_transaction extends uvm_sequence_item; // TODO: fill out
  
  // Reset Input
  logic n_rst;

  // MEM Inputs

  // MEM Outputs

  // cosntraints

  `uvm_object_utils_begin(tc_mem_transaction)

  `uvm_object_utils_end

  function new(string name = "tc_mem_transaction");
    super.new(name);
  endfunction: new

endclass

`endif
