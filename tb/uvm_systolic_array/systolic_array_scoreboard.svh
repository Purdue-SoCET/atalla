`ifndef SYSTOLIC_ARRAY_SCOREBOARD_SVH
`define SYSTOLIC_ARRAY_SCOREBOARD_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"
class systolic_array_scoreboard #(parameter N = 4, parameter WIDTH = 16) extends uvm_scoreboard;
    `uvm_component_param_utils(systolic_array_scoreboard #(N, WIDTH))
    

`endif