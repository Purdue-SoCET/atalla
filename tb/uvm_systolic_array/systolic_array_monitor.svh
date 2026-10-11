`ifndef SYSTOLIC_ARRAY_MONITOR_SVH
`define SYSTOLIC_ARRAY_MONITOR_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"

class systolic_array_monitor extends uvm_monitor;

  `uvm_component_utils(systolic_array_monitor)

  virtual systolic_array_tb_if vif;

  uvm_analysis_port #(gsau_sa_observation) ap;

  function new(
    string name = "systolic_array_monitor",
    uvm_component parent = null
  );
    super.new(name, parent);
    ap = new("ap", this);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    if (!uvm_config_db#(virtual systolic_array_tb_if)::get(
        this, "", "vif", vif)) begin
      `uvm_fatal(
        get_type_name(),
        "Virtual interface not found in uvm_config_db"
      )
    end
  endfunction

  task run_phase(uvm_phase phase);
    gsau_sa_observation trans;
    longint unsigned cycle;

    cycle = 0;

    forever begin
      @(posedge vif.clk);

      trans = gsau_sa_observation::type_id::create("trans");

      trans.cycle = cycle;
      trans.n_rst = vif.n_rst;

      // Inputs 
      trans.array_in         = vif.bus.sa_array_in;
      trans.array_in_partials = vif.bus.sa_array_in_partials;

      trans.input_en         = vif.bus.sa_input_en;
      trans.weight_en        = vif.bus.sa_weight_en;
      trans.partial_en       = vif.bus.sa_partial_en;
      trans.ready_out        = vif.bus.sa_ready_out;

      // Outputs 
      trans.array_output     = vif.bus.sa_array_output;
      trans.valid_in         = vif.bus.sa_valid_in;
      trans.ready_in         = vif.bus.sa_ready_in;

      ap.write(trans);

      cycle++;
    end
  endtask

endclass

`endif
