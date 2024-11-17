`ifndef FU_ALU_IF_VH
`define FU_ALU_IF_VH

`include "types_pkg.vh"

interface fu_alu_if;
  import types_pkg::*;

  logic negative, overflow, zero, enable;
  logic [3:0] aluop;
  //aluop_t aluop;
  word_t port_a, port_b, port_output;

  modport alu (
    input aluop, port_a, port_b, alu_enable
    output  negative, overflow, port_output, zero
  );

  modport tb (
    input negative, overflow, port_output, zero,
    output aluop, port_a, port_b, alu_enable
  );
endinterface

`endif