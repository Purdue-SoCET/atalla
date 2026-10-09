`ifndef TC_TMU_TRANSACTION_SV
`define TC_TMU_TRANSACTION_SV

import uvm_pkg::*;
`include "uvm_macros.svh"

class tc_tmu_transaction extends uvm_sequence_item;
  
  // Reset Input
  logic n_rst;

  // TMU Inputs
  logic [3:0][S_T_WIDTH-1:0] s;
  logic [3:0][S_T_WIDTH-1:0] t;
  logic [3:0][TEXEL_WIDTH-1:0] tex_width;
  logic [3:0][TEXEL_HEIGHT-1:0] tex_height;
  logic [3:0][ADDR_WIDTH-1:0] base_addr;
  logic tmu_valid;

  // TMU Outputs
  logic cache_ready;
  logic [3:0][TEXEL_RETURN_WIDTH-1:0] texel_return;

  // constraints
  `uvm_object_utils_begin(tc_tmu_transaction)
    `uvm_field_int(n_rst, UVM_DEFAULT)
    `uvm_field_int(s, UVM_DEFAULT)
    `uvm_field_int(t, UVM_DEFAULT)
    `uvm_field_int(tex_width, UVM_DEFAULT)
    `uvm_field_int(tex_height, UVM_DEFAULT)
    `uvm_field_int(base_addr, UVM_DEFAULT)
    `uvm_field_int(tmu_valid, UVM_DEFAULT)
    `uvm_field_int(cache_ready, UVM_DEFAULT)
    `uvm_field_int(texel_return, UVM_DEFAULT)
  `uvm_object_utils_end

  function new(string name = "tc_tmu_transaction");
    super.new(name);
  endfunction: new

endclass

`endif
