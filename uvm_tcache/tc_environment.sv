`ifndef TC_ENVIRONMENT_SV
`define TC_ENVIRONMENT_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "tc_scoreboard.sv"
`include "texture_mapping_unit/tc_tmu_active_agent.sv"
`include "texture_mapping_unit/tc_tmu_passive_agent.sv"
`include "memory/tc_mem_active_agent.sv"
`include "tc_if.sv"
`include "tc_predictor.sv"
`include "texture_mapping_unit/tc_tmu_transaction.sv"
`include "memory/tc_mem_transaction.sv"

class tc_environment extends uvm_env;
  `uvm_component_utils(tc_environment)

  tc_tmu_active_agent tmu_active_agent;
  tc_tmu_passive_agent tmu_passive_agent;
  tc_mem_active_agent mem_active_agent;
  tc_predictor pred;
  tc_scoreboard sb;

  function new(string name = "env", uvm_component parent = null);
		super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    tmu_active_agent = tc_tmu_active_agent::type_id::create("tmu_active_agent", this);
    tmu_passive_agent = tc_tmu_passive_agent::type_id::create("tmu_passive_agent", this);
    mem_active_agent = tc_mem_active_agent::type_id::create("mem_active_agent", this);
    
    pred = tc_predictor::type_id::create("tc_predictor", this);
    sb = tc_scoreboard::type_id::create("tc_scoreboard", this);
  endfunction

  function void connect_phase(uvm_phase phase);
    tmu_active_agent.mon.tc_ap.connect(pred.tmu_imp);

    pred.pred_ap.connect(sb.expected_tmu_ap);
    tmu_passive_agent.mon.tc_result_ap.connect(sb.actual_tmu_ap);
  endfunction

endclass

`endif


