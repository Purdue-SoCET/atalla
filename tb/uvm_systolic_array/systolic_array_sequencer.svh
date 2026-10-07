// Sequencer for systolic array  
// Updated after transaction changed
// establishes connection between sequence and driver 
// Referred to UVM vlsiverify example for adder 

`ifndef SYSTOLIC_ARRAY_SEQUENCER_SVH
`define SYSTOLIC_ARRAY_SEQUENCER_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"

class systolic_array_sequencer #(parameter N = 4, parameter WIDTH = 16) extends uvm_sequencer #(systolic_array_transaction #(N, WIDTH));
  `uvm_component_utils(systolic_array_sequencer #(N, WIDTH))

  // constructor 
  function new(string name = "sequencer", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  // build phase 
  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if (!uvm_config_db#(virtual systolic_array_if)::get(this, "", "vif", vif)) begin
      `uvm_fatal(get_type_name(), "Virtual interface not found; not set at top level")
    end
  endfunction

endclass

`endif
