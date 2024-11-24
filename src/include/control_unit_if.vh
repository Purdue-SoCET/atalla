
// need to include matrix related instructions, gemm, ld.m, sw.m

`ifndef CONTROL_UNIT_IF_VH
`define CONTROL_UNIT_IF_VH

`include "types_pkg.vh"
`include "cpu_types.vh"

interface control_unit_if;

  // import types
  import types_pkg::*;
  import cpu_types::*;
  
  // logic [2:0] mem_type, branch_type;
  // logic [1:0] u_type;
  // logic [5:0] b_type;

  logic [3:0] alu_op;
  logic [4:0] stride;
  logic halt, i_flag, reg_write, jalr, jal, mem_to_reg;
  scalar_mem_t s_mem_type;
  branch_t branch_type;
  word_t imm, instr;
  utype_t u_type;
  fu_scalar fu_s;
  fu_matrix fu_m;
  matrix_mem_t m_mem_type;
  logic [3:0] matrix_rd, matrix_rs1;

  modport cu (
    input instr,
    output halt, i_flag, mem_to_reg, s_mem_type, reg_write, jalr, jal, u_type, alu_op, branch_type, imm, stride, fu_s, fu_m, m_mem_type, matrix_rd, matrix_rs1
  );

  modport tb (
    input halt, i_flag, mem_to_reg, s_mem_type, reg_write, jalr, jal, u_type, alu_op, branch_type, imm, stride, fu_s, fu_m, m_mem_type, matrix_rd, matrix_rs1,
    output instr
  );

endinterface
`endif //CONTROL_UNIT_IF_VH
