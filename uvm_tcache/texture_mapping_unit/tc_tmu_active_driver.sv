`ifndef TC_TMU_ACTIVE_DRIVER_SV
`define TC_TMU_ACTIVE_DRIVER_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "../tc_if.sv"
`include "tc_tmu_transaction.sv"

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
    tc_tmu_transaction req_item;

    DUT_reset(); 
    forever begin
      seq_item_port.get_next_item(req_item);

      vif.s = req_item.s;
      vif.t = req_item.t;
      vif.tex_width = req_item.tex_width;
      vif.tex_height = req_item.tex_height;
      vif.base_addr = req_item.base_addr;
      vif.tmu_valid = 1'b1;

      @(posedge vif.clk);
      vif.tmu_valid = 1'b0; // assumption is that tcache latches inputs after 1 cycle
      @(posedge vif.clk);

      seq_item_port.item_done();
    end
  endtask

endclass

`endif
