`ifndef FU_ALU_IF_VH
`define FU_ALU_IF_VH
<<<<<<< HEAD
`include "isa_types.vh"
=======
`include "cpu_types_pkg.vh"
`include "datapath_types.vh"
>>>>>>> 9c5d5014b5aa7fa94338db381e0464ca6fec6f65

interface fu_alu_if;
  import isa_pkg::*;

  logic negative, overflow, zero;
  logic [3:0] aluop;
  word_t port_a, port_b, port_output;

  modport alu (
    input aluop, port_a, port_b,
    output negative, overflow, port_output, zero
  );

  modport tb (
    input negative, overflow, port_output, zero,
    output aluop, port_a, port_b
  );

endinterface

`endif
