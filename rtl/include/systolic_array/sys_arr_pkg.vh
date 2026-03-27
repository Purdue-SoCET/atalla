`ifndef SYS_ARR_PKG_VH
`define SYS_ARR_PKG_VH

package sys_arr_pkg;
  parameter N = 32; // dimensions of the systolic array
  parameter DW = 16; // data width
  parameter DW_ACC = 32; // accumulator width
  parameter IS_FP16 = 0;    // 1 -> FP16, 0 -> BF16
endpackage

`endif