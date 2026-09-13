`ifndef TC_TMU_TRANSACTION_SV
`define TC_TMU_TRANSACTION_SV

import uvm_pkg::*;
`include "uvm_macros.svh"

class tc_tmu_transaction extends uvm_sequence_item; // TODO: fill out
  
  // Reset Input
  logic n_rst;

  // TMU Inputs

  // TMU Outputs

  // cosntraints

  `uvm_object_utils_begin(tc_tmu_transaction)

  `uvm_object_utils_end

  function new(string name = "tc_tmu_transaction");
    super.new(name);
  endfunction: new

endclass

`endif
