`ifndef TYPES_PKG_VH
`define TYPES_PKG_VH

package types_pkg;
  // all our instruction params
  parameter WORD_W = 32;
 
  // defines the Function Units
  typdef enum logic [1:0] {
    ALU,
    LD_ST,
    BRANCH
  } fu_scalar;

  typdef enum logic [1:0] {
    LD_ST,
    GEMM
  } fu_matrix;

  // Pipeline Stage Structs
  typedef struct packed {
    //TODO: control signals
    logic [2:0] fu_index;
  } dispatch_t

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
