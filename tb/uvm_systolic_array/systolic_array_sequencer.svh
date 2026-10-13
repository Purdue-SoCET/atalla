// Sequencer for systolic array  
// Updated after transaction changed
// establishes connection between sequence and driver 
// Referred to UVM vlsiverify example for adder 

`ifndef SYSTOLIC_ARRAY_SEQUENCER_SVH
`define SYSTOLIC_ARRAY_SEQUENCER_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"

class systolic_array_sequencer #(parameter N = 4, parameter WIDTH = 16) extends uvm_sequencer #(systolic_array_transaction #(N, WIDTH));
  `uvm_component_param_utils(systolic_array_sequencer #(N, WIDTH))

  // constructor 
  function new(string name = "sequencer", uvm_component parent = null);
    super.new(name, parent);
  endfunction
  
endclass

`endif
