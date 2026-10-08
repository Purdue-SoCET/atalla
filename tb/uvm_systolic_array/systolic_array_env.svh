`ifndef SYSTOLIC_ARRAY_ENV_SVH
`define SYSTOLIC_ARRAY_ENV_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"

//declare env 
class systolic_array_env #(
  parameter N = 4,
  parameter WIDTH = 16
) extends uvm_env;

  `uvm_component_param_utils(systolic_array_env #(N, WIDTH))

  //declare agent and scoreboard
  systolic_array_agent #(N, WIDTH) agent;
  systolic_array_scoreboard #(N, WIDTH) scoreboard;

  //constructor def
  function new (
    string name = "systolic_array_env", 
    uvm_component_parent = null
  );
    super.new(name, parent);
  endfunction

  //create agent and scoreboard
  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    
    agent = systolic_array_agent #(N, WIDTH)::type_id::create("agent", this);

    scoreboard = systolic_array_scoreboard #(N, WIDTH)::type_id::create("scoreboard", this);
  endfunction

  //connect monitor to scoreboard
  function void connect_phase(uvm_phase phase);
    super.connect_phase(phase);

  endfunction

endclass
`endif
