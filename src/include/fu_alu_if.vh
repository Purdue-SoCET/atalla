`ifndef FU_ALU_IF_VH
`define FU_ALU_IF_VH

`include "cpu_types.vh"

interface fu_alu_if;
  import cpu_types::*;

  logic negative, overflow, zero, alu_enable;
  logic [3:0] aluop;
  //aluop_t aluop;
  word_t port_a, port_b, port_output;

  modport alu (
    input aluop, port_a, port_b, alu_enable,
    output  negative, overflow, port_output, zero
  );

  modport tb (
    input negative, overflow, port_output, zero,
    output aluop, port_a, port_b, alu_enable
  );
endinterface

`endif