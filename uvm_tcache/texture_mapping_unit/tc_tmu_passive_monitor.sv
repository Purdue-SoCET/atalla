`ifndef TC_TMU_PASSIVE_MONITOR_SV
`define TC_TMU_PASSIVE_MONITOR_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "../tc_if.sv"
`include "tc_tmu_transaction.sv"

class tc_tmu_passive_monitor extends uvm_monitor;
  `uvm_component_utils(tc_tmu_passive_monitor)

  uvm_analysis_port#(tc_tmu_transaction) tc_result_ap;

  tc_vif_t vif;

  function new(string name, uvm_component parent = null);
    super.new(name, parent);
    tc_result_ap = new("tc_result_ap", this);
  endfunction

  virtual function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if(!uvm_config_db#(virtual tc_if)::get(this, "", "tc_vif", vif)) begin
      `uvm_fatal("TMU_PASSIVE_MON", "No virtual interface specified for this monitor instance")
    end
  endfunction

  virtual task run_phase(uvm_phase phase);
    super.run_phase(phase);

    forever begin
      tc_tmu_transaction tx;

      if(vif.cache_ready) begin
        tx.cache_ready = 1'b1;
        tx.texel_return = vif.texel_return;
      end

      tc_result_ap.write(tx);

      @(negedge vif.clk);
    end
  endtask

endclass

`endif // TC_TMU_PASSIVE_MONITOR_SVH
