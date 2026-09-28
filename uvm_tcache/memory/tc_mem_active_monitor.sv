// tc_mem_active_monitor.svh
`ifndef TC_MEM_ACTIVE_MONITOR_SV
`define TC_MEM_ACTIVE_MONITOR_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "../tc_if.sv"
`include "tc_mem_transaction.sv"

typedef virtual tc_if tc_mem_vif_t;

class tc_mem_active_monitor extends uvm_monitor;
  `uvm_component_utils(tc_mem_active_monitor)

  tc_mem_vif_t vif;

  function new(string name, uvm_component parent = null);
    super.new(name, parent);
  endfunction

  virtual function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if(!uvm_config_db#(virtual tc_if)::get(this, "", "tc_vif", vif)) begin
      `uvm_fatal("Monitor", "No virtual interface specified for this monitor instance")
    end
  endfunction

  virtual task run_phase(uvm_phase phase);
    super.run_phase(phase);

    forever begin
      // TODO: fill in
	  end

  endtask

endclass

`endif // TC_MEM_ACTIVE_MONITOR_SV

