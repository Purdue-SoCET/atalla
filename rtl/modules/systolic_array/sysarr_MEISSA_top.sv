`timescale 1ns/1ps
`include "systolic_array_MEISSA_if.vh"
`include "gsau_control_unit_if.vh"
`include "sys_arr_pkg.vh"

/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

module sysarr_MEISSA_top (
    input logic clk, nRST,
    gsau_control_unit_if.systolic_array gsau_if
);

    //mul grid

    //adder trees

    //output fifo

endmodule