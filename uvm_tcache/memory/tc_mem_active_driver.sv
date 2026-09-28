`ifndef TC_MEM_ACTIVE_DRIVER_SV
`define TC_MEM_ACTIVE_DRIVER_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "../tc_if.sv"
`include "tc_mem_transaction.sv"

class tc_mem_active_driver extends uvm_driver#(tc_mem_transaction);
  `uvm_component_utils(tc_mem_active_driver)

  virtual tc_if vif;

  function new(string name, uvm_component parent);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if (!uvm_config_db#(virtual tc_if)::get(this, "", "tc_vif", vif)) begin
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

  virtual task run_phase(uvm_phase phase);

    forever begin
      // TODO: fill in
    end

  endtask

endclass

`endif
