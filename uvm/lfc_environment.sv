`ifndef LFC_ENVIRONMENT_SV
`define LFC_ENVIRONMENT_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_scoreboard.sv"
`include "lfc_cpu_active_agent.sv"
`include "lfc_cpu_passive_agent.sv"
`include "lfc_ram_active_agent.sv"
`include "lfc_ram_passive_agent.sv"
`include "lfc_if.sv"
`include "lfc_predictor.sv"
`include "lfc_coverage.sv"
`include "lfc_cpu_transaction.sv"
`include "lfc_ram_transaction.sv"
`include "lfc_uuid_transaction.sv"

class lfc_environment #(parameter NUM_BANKS = 4) extends uvm_env;
  `uvm_component_utils(lfc_environment)

  /*// Agents
  lfc_cpu_active_agent   cpu_active_ag;
  lfc_cpu_passive_agent  cpu_passive_ag;
  lfc_ram_active_agent   ram_active_ag;
  lfc_ram_passive_agent  ram_passive_ag;

  // Predictor & Scoreboard
  lfc_predictor      pred;
  lfc_scoreboard     sb;

  // Create components
  cpu_active_ag  = lfc_cpu_active_agent ::type_id::create("cpu_active_ag",  this);
  cpu_passive_ag = lfc_cpu_passive_agent ::type_id::create("cpu_passive_ag", this);
  ram_active_ag  = lfc_ram_active_agent ::type_id::create("ram_active_ag",  this);
  ram_passive_ag = lfc_ram_passive_agent ::type_id::create("ram_passive_ag", this);

  pred = lfc_predictor ::type_id::create("pred", this);
  sb   = lfc_scoreboard ::type_id::create("sb",   this);*/

  lfc_cpu_active_agent cpu_active_agent;
  lfc_cpu_passive_agent cpu_passive_agent;
  lfc_ram_active_agent ram_active_agent;
  lfc_ram_passive_agent ram_passive_agent;
  lfc_predictor pred;
  lfc_coverage cov;
  lfc_scoreboard sb;

  function new(string name = "env", uvm_component parent = null);
		super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    cpu_active_agent = lfc_cpu_active_agent::type_id::create("cpu_active_agent", this);
    cpu_passive_agent = lfc_cpu_passive_agent::type_id::create("cpu_passive_agent", this);
    ram_active_agent = lfc_ram_active_agent::type_id::create("ram_active_agent", this);
    ram_passive_agent = lfc_ram_passive_agent#(NUM_BANKS)::type_id::create("ram_passive_agent", this);
    
    pred = lfc_predictor::type_id::create("lfc_predictor", this);
    cov = lfc_coverage::type_id::create("lfc_coverage", this);
    sb = lfc_scoreboard::type_id::create("lfc_scoreboard", this);
  endfunction

  function void connect_phase(uvm_phase phase);
    // cpu_active_agent.mon.lfc_ap.connect(pred.pred_cpu_aep);
    cpu_passive_agent.mon.result_ap.connect(sb.actual_cpu_export);
    pred.pred_cpu_ap.connect(sb.expected_cpu_export);

    for (int b = 0; b < NUM_BANKS; b++) begin
      ram_passive_agent.mon.result_ap[b].connect(sb.actual_ram_req_export[b]);
      pred.pred_ram_req_ap[b].connect(sb.expected_ram_req_export[b]);
    end

    ram_active_agent.mon.lfc_ap.connect(sb.actual_ram_cmp_export);
    pred.pred_ram_cmp_ap.connect(sb.expected_ram_cmp_export);

    cpu_active_agent.mon.lfc_ap.connect(pred.cpu_imp);
    cpu_active_agent.mon.lfc_ap.connect(cov.cpu_imp);
    ram_active_agent.mon.lfc_ap.connect(pred.ram_imp);

    // UUID cross-time linkage check (block_status completion events)
    cpu_passive_agent.mon.block_status_ap.connect(sb.actual_uuid_cmp_export);

    /*ARCHITECTURAL BOUNDARY EXCEPTION: active monitor -> scoreboard
    Normally active components connect only to the predictor. This connection is an intentional exception: the active monitor captures (bank, uuid) at miss time 
    (after posedge, outputs settled) and sends it directly to the scoreboard for UUID cross-time linkage verification. No other active->scoreboard connections exist. */
    cpu_active_agent.mon.uuid_miss_ap.connect(sb.actual_miss_export);

  endfunction

endclass

`endif


