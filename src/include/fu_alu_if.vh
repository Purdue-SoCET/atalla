`include "cpu_types.vh"

interface fu_alu_if;
  import cpu_types::*;

  logic negative, overflow, zero;
  // logic alu_enable;
  logic [3:0] aluop;
  word_t port_a, port_b, port_output;

  modport alu (
    input aluop, port_a, port_b,
    output  negative, overflow, port_output, zero
  );

  modport tb (
    input negative, overflow, port_output, zero,
    output aluop, port_a, port_b
  );
endinterface