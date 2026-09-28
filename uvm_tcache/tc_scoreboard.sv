`ifndef TC_SCOREBOARD_SV
`define TC_SCOREBOARD_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "texture_mapping_unit/tc_tmu_transaction.sv"
`include "memory/tc_mem_transaction.sv"

class tc_scoreboard extends uvm_scoreboard; // TODO: fill in
  `uvm_component_utils(tc_scoreboard)

  uvm_analysis_imp#(tc_tmu_transaction) expected_tmu_ap;
  uvm_analysis_imp#(tc_tmu_transaction) actual_tmu_ap;

  function new(string name, uvm_component parent);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
  endfunction

  function void connect_phase(uvm_phase phase);
  endfunction

  task run_phase(uvm_phase phase);
  endtask

  function void check_phase(uvm_phase phase);
  endfunction

  function void report_phase(uvm_phase phase);
  endfunction

endclass

`endif
