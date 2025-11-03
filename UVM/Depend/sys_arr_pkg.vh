`ifndef SYS_ARR_PKG_VH
`define SYS_ARR_PKG_VH

package sys_arr_pkg;
  parameter N = 4; // dimensions of the systolic array
  parameter DW = 16; // data width
  parameter SIZE = 4; // dimensions of the systolic array
  typedef enum {PH_IDLE, PH_INPUT, PH_PSUM, PH_IANDSUM, PH_OUTPUT} phase_e;

endpackage

`endif
