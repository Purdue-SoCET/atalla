`ifndef TC_TMU_TRANSACTION_SV
`define TC_TMU_TRANSACTION_SV

import uvm_pkg::*;
`include "uvm_macros.svh"

class tc_tmu_transaction extends uvm_sequence_item;
  
  // Reset Input
  logic n_rst;

  // TMU Inputs
  logic v;
  logic u;
  logic tex_width;
  logic base_addr;

  // TMU Outputs
  logic hit_way;
  logic hit;

  // constraints

  `uvm_object_utils_begin(tc_tmu_transaction)
    `uvm_field_int(n_rst, UVM_DEFAULT)
    `uvm_field_int(v, UVM_DEFAULT)
    `uvm_field_int(u, UVM_DEFAULT)
    `uvm_field_int(tex_width, UVM_DEFAULT)
    `uvm_field_int(base_addr, UVM_DEFAULT)
    `uvm_field_int(hit_way, UVM_DEFAULT)
    `uvm_field_int(hit, UVM_DEFAULT)
  `uvm_object_utils_end

  function new(string name = "tc_tmu_transaction");
    super.new(name);
  endfunction: new

endclass

`endif
