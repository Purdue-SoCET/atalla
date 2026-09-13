`ifndef TC_TMU_ACTIVE_DRIVER_SV
`define TC_TMU_ACTIVE_DRIVER_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "tc_if.sv"
`include "tc_tmu_transaction"

class tc_tmu_active_driver extends uvm_driver#(tc_tmu_transaction);
  `uvm_component_utils(tc_tmu_active_driver)

  virtual tc_if vif;

  function new(string name, uvm_component parent);
      super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      if(!uvm_config_db#(virtual tc_if)::get(this, "", "tc_vif", vif)) begin
          `uvm_fatal("Driver", "No virtual interface specified for this test instance");
      end
  endfunction

  task DUT_reset();
      @(posedge vif.clk);
      vif.n_rst = 0;
      @(posedge vif.clk);
      vif.n_rst = 1;
      @(posedge vif.clk);
  endtask

  task run_phase(uvm_phase phase);
    forever begin
      // TODO: fill out
    end
  endtask

endclass

`endif
