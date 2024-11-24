`ifndef TYPES_PKG_VH
`define TYPES_PKG_VH

package types_pkg;
  // all our instruction params
  parameter WORD_W = 32;
  parameter REG_W  = 5;
  parameter MATRIX_W = 4;

  parameter FU_S_W = 2;
  parameter FU_M_W = 1;

  typedef logic [REG_W-1:0] regbits_t;
  typedef logic [MATRIX_W-1:0] mbits_t;

  typedef logic [FU_S_W-1:0] fu_sbits_t;
  typedef logic [FU_M_W-1:0] fu_mbits_t;
 
  // defines the Function Units
  typdef enum logic [FU_S_W-1:0] {
    ALU,
    LD_ST,
    BRANCH
  } fu_scalar;

  typdef enum logic [FU_M_W-1:0] {
    LD_ST,
    GEMM
  } fu_matrix;

  // Pipeline Stage Structs
  typedef struct packed {
    logic hazard;

    // control signals
    
  } dispatch_t;

  typedef struct packed {
    logic [3:0] alu_op;
    logic [3:0] stride;
    logic halt;
    logic i_flag; 
    logc reg_write; 
    logic jalr;
    logic jal;
    scalar_mem_t s_mem_type;
    branch_t branch_type;
    word_t imm;
    utype_t u_type;
    matrix_mem_t 
    fu_scalar fu_s;
    fu_matrix fu_m
    matrix_mem_t m_mem_type;
    logic [3:0] matrix_rd;
    logic [3:0] matrix_rs1
  } issue_t;

  typedef struct packed {
    logic busy;
    regbits_t r;
    regbits_t r1;
    regbits_t r2;
    fu_sbits_t t1;
    fu_sbits_t t2;
  } fust_s_row_t;

  typedef struct packed {
    fust_s_row_t [FU_S_W-1:0] op;
  } fust_s_t;

  typedef struct packed {
    logic busy;
    mbits_t r;
    mbits_t r1;
    mbits_t r2;
    mbits_t r3;
    fu_mbits_t t1;
    fu_mbits_t t2;
    fu_mbits_t t3;
  } fust_m_ldst_row_t;

  typedef struct packed {
    fust_m_row_t [FU_M_W-1:0] op;
  } fust_m_t;

  typedef enum logic [2:0] {
    BEQ, 
    BNE, 
    BNE,
    BLT,
    BGE,
    BLTU,
    BGEU,
  } branch_t;

  typedef enum logic [1:0] {
    STORE,
    LOAD,
    MEM_TO_REG
  } scalar_mem_t; // 

  typedef enum logic [1:0] {
    STORE,
    LOAD
  } matrix_mem_t; // load or store for matrix ld_st fu

  typedef enum logic [2:0] {
    LOAD,
    ADD // not using it but here still 
  } utype_t;

endpackage
`endif
