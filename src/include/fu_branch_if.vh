`include "cpu_types.vh"

interface fu_branch_if;
  import cpu_types::*;

  logic branch, branch_gate_sel, branch_outcome;
  logic [1:0] branch_type;
  word_t reg_a, reg_b, current_pc, updated_pc, imm;

  modport br (
    input branch, branch_type, branch_gate_sel, reg_a, reg_b, current_pc, imm,
    output branch_outcome, updated_pc
  );

  modport tb (
    output branch_outcome, updated_pc,
    input branch, branch_type, branch_gate_sel, reg_a, reg_b, current_pc, imm
  );
endinterface