//monitor first draft
'ifndef SYSTOLIC_ARRAY_MONITOR_SV
'define SYSTOLIC_ARRAY_MONITOR_SV

import uvm_pkg::*;
'include "uvm.macros.svh"

class systolic_array_monitor #(parameter N = 4, parameter WIDTh = 16) extends uvm_monitor;

  'uvm_component_param_utils(systolic_array_monitor #(N, WIDTH))

  //virtual interface and analysis port
  virtual systolic_array_if #(N, WIDTH) vif; 
  uvm_analysis_port #(systolic_array_transaction #(N, WIDTH)) ap;

  function new(string name = "systolic_array_monitor", uvm_component parent = null);
    super.new(name, parent);
    ap = new("ap", this);
  endfunction

  function void build_phase (uvm_phase phase);
    super.build_phase(phase);

    if (!uvm_config_db##(virtual systolic_array_if #(N, WIDTH))::get(this, "", "vif", vif)) begin
      'uvm_fatal(get)type_name(), "Virtual interface not found in uvm_config_db")
    end
  endfunction
      
