`ifndef TC_TMU_ACTIVE_MONITOR_SV
`define TC_TMU_ACTIVE_MONITOR_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "../tc_if.sv"
`include "tc_tmu_transaction.sv"

typedef virtual tc_if tc_vif_t;

class tc_tmu_active_monitor extends uvm_monitor;
  `uvm_component_utils(tc_tmu_active_monitor)

  uvm_analysis_port#(tc_tmu_transaction) tc_ap;

  tc_vif_t vif;

  function new(string name, uvm_component parent = null);
    super.new(name, parent);
    tc_ap = new("tc_ap", this);
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
      tc_tmu_transaction tx = tc_tmu_transaction::type_id::create("tx");

      while (vif.tmu_valid == 1'b0) @(negedge vif.clk);

      tx.s = vif.s;
      tx.t = vif.t;
      tx.tex_width = vif.tex_width;
      tx.tex_height = vif.tex_height;
      tx.base_addr = vif.base_addr;
      tx.tmu_valid = vif.tmu_valid;

      tc_ap.write(tx);
    end
  endtask

endclass

`endif // TC_TMU_ACTIVE_MONITOR_SVH
