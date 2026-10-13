`ifndef SYSTOLIC_ARRAY_TB_IF_SVH
`define SYSTOLIC_ARRAY_TB_IF_SVH

`include "gsau_control_unit_if.vh"

interface systolic_array_tb_if (
  input logic clk,
  input logic n_rst
);
  gsau_control_unit_if bus();

endinterface

`endif