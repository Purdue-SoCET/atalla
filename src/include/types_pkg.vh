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
    cu_t cu;
  } dispatch_t;

  typedef struct packed {
    cu_t cu; 
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
  } fust_m_row_t;

  typedef struct packed {
    fust_m_row_t [FU_M_W-1:0] op;
  } fust_m_t;

endpackage
`endif
