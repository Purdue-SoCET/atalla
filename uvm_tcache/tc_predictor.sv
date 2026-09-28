`ifndef TC_PREDICTOR_SV
`define TC_PREDICTOR_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "texture_mapping_unit/tc_tmu_transaction.sv"
`include "memory/tc_mem_transaction.sv"

class tc_predictor extends uvm_component;
  `uvm_component_utils(tc_predictor)

  uvm_analysis_imp#(tc_tmu_transaction) tmu_imp;
  uvm_analysis_port#(tc_tmu_transaction) pred_ap;

  function new(string name, uvm_component parent);
    super.new(name,parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    tmu_imp = new("tmu_imp", this);
    pred_ap = new("pred_ap", this);
  endfunction

  function void write_tmu(tc_tmu_transaction tmu_t);
  endfunction

endclass

`endif
