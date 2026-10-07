// agent for systolic array
// holds and connects driver, sequencer, and monitor instances 
`ifndef SYSTOLIC_ARRAY_AGENT_SVH
`define SYSTOLIC_ARRAY_AGENT_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"

class systolic_array_agent #(parameter N = 4, parameter WIDTH = 16) extends uvm_agent;
  `uvm_component_param_utils(systolic_array_agent #(N, WIDTH))

  // not sure about instantiations using typedefs (got rid or syntax issue)
  typedef systolic_array_driver #(N, WIDTH) driver_type;
  typedef systolic_array_sequencer #(N, WIDTH) sequencer_type;
  typedef systolic_array_monitor #(N, WIDTH) monitor_type;

  driver_type driver;
  sequencer_type sequencer;
  monitor_type monitor;

  function new(string name = "sequencer", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    if (get_is_active == UVM_ACTIVE) begin
      driver  = systolic_array_driver #(N, WIDTH)::type_id::create("driver", this);
      sequencer = systolic_array_sequencer #(N, WIDTH)::type_id::create("sequencer", this);
    end

    monitor = systolic_array_monitor #(N, WIDTH)::type_id::create("monitor", this);
  endfunction

  function void connect_phase(uvm_phase phase);
    super.connect_phase(phase);
    if (get_is_active == UVM_ACTIVE) begin
      drv.seq_item_port.connect(seqr.seq_item_export);
    end
  endfunction

endclass

`endif
