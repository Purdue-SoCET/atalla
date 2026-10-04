//monitor first draft
`ifndef SYSTOLIC_ARRAY_MONITOR_SV
`define SYSTOLIC_ARRAY_MONITOR_SV

import uvm_pkg::*;
`include "uvm_macros.svh"

class systolic_array_monitor #(parameter N = 4, parameter WIDTH = 16) extends uvm_monitor;

  `uvm_component_param_utils(systolic_array_monitor #(N, WIDTH))

  //virtual interface and analysis port
  virtual systolic_array_if #(N, WIDTH) vif; 
  uvm_analysis_port #(systolic_array_transaction #(N, WIDTH)) ap;

  function new(string name = "systolic_array_monitor", uvm_component parent = null);
    super.new(name, parent);
    ap = new("ap", this);
  endfunction

  function void build_phase (uvm_phase phase);
    super.build_phase(phase);

    if (!uvm_config_db#(virtual systolic_array_if #(N, WIDTH))::get(this, "", "vif", vif)) begin
      `uvm_fatal(get)type_name(), "Virtual interface not found in uvm_config_db")
    end
  endfunction

  task run_phase(uvm_phase phase);
    systolic_array_transaction #(N, WIDTH) trans;

    forever begin
      @(posedge vif.clk); //change to clk

      if (vif.monitor.weight_en || vif.monitor.input_en || vif.monitor.partial_en || vif.monitor.out_en) begin
        trans = systolic_array_transaction #(N, WIDTH)::type_id::create("trans");

        //inputs
        trans.weight_en = vif.monitor.weight_en;
        trans.input_en = vif.monitor.input_en;
        trans.partial_en = vif.monitor.partial_en;
        trans.row_in_en = vif.monitor.row_in_en;
        trans.row_ps_en = vif.monitor.row_ps_en;

        trans.array_in = vif.monitor.array_in;
        trans.array_in_partials = vif.monitor.array_in_partials;

        //outputs
        trans.out_en            = vif.monitor.out_en;
        trans.row_out           = vif.monitor.row_out;
        trans.array_output      = vif.monitor.array_output;
        trans.drained           = vif.monitor.drained;
        trans.fifo_has_space    = vif.monitor.fifo_has_space;

        ap.write(trans);
      end
    end
  endtask

endclass
`endif
