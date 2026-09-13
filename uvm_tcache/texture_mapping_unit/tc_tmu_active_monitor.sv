`ifndef TC_TMU_ACTIVE_MONITOR_SV
`define TC_TMU_ACTIVE_MONITOR_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "../tc_if.sv"

class tc_tmu_active_monitor extends uvm_monitor;
  `uvm_component_utils(tc_tmu_active_monitor)

  function new(string name, uvm_component parent = null);
    super.new(name, parent);
    // TODO: fill in analysis ports
  endfunction

  virtual function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if(!uvm_config_db#(virtual tc_if)::get(this, "", "tc_vif", vif)) begin
      `uvm_fatal("TMU_ACTIVE_MON", "No virtual interface specified for this monitor instance")
    end
  endfunction

  virtual task run_phase(uvm_phase phase);
    super.run_phase(phase);

    forever begin
      // TODO: fill in
    end
  endtask

endclass

`endif // TC_TMU_ACTIVE_MONITOR_SVH

