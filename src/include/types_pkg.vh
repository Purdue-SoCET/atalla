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

endpackage
`endif
