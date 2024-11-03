
// need to include matrix related instructions, gemm, ld.m, sw.m

`ifndef CONTROL_UNIT_IF_VH
`define CONTROL_UNIT_IF_VH

`include "types_pkg.vh"

interface control_unit_if;
  // import types
  import types_pkg::*;

  logic [2:0] mem_type, branch_type;
  logic [3:0] alu_op;
  logic [5:0] b_type;
  logic [1:0] u_type;
  logic halt_pre, i_flag, reg_write, jalr, jal;
  word_t imm, instr;

  modport ctrl (
    input instr,
    output halt_pre, b_type, i_flag, mem_type, reg_write, jalr, jal, u_type, alu_op, branch_type, imm
  );

  modport tb (
    input halt_pre, b_type, i_flag, mem_type, reg_write, jalr, jal, u_type, alu_op, branch_type, imm,
    output instr
  );



endinterface

`endif //CONTROL_UNIT_IF_VH