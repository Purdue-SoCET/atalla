`timescale 1ns/1ps
`include "execution_unit_if.sv"
`include "sMult_if.sv"
`include "control_if.sv"
`include "bfD_sD_bfInt_intBF_if.sv"
`include "bfA_bfM_bfS_bfSLT_if.sv"
`include "ld_st_unit_if.sv"

module execute_stage
(
    input logic clk, nRST,
    execution_unit_if.execution_units ex_if
);
    logic ex1_valid, ex2_valid, ex3_valid, ex4_valid, ex5_valid;
    control_if unit1_if ();
    bfD_sD_bfInt_intBF_if unit2_if ();
    bfA_bfM_bfS_bfSLT_if unit3_if ();
    sMult_if unit4_if ();
    ld_st_unit_if unit5_if ();

    xbar_4x5_exec_comb crossbar
    (
        .slot_1(ex_if.slot_1), .slot_2(ex_if.slot_2), .slot_3(ex_if.slot_3), .slot_4(ex_if.slot_4),
        .ex1_in(ex_if.post_xbar_ex1), .ex2_in(ex_if.post_xbar_ex2), .ex3_in(ex_if.post_xbar_ex3), .ex4_in(ex_if.post_xbar_ex4), .ex5_in(ex_if.post_xbar_ex5),
        .ex1_valid(ex1_valid), .ex2_valid(ex2_valid), .ex3_valid(ex3_valid), .ex4_valid(ex4_valid), .ex5_valid(ex5_valid)
    );

    alu_control UNIT_1 (.CLK(clk), .nRST(nRST), .portmap(unit1_if));
    div_bf_scalar_convert_wrapper UNIT_2 (.clk(clk), .nRST(nRST), .portmap(unit2_if));
    addsub_bf16_wrapper UNIT_3 (.clk(clk), .nRST(nRST), .portmap(unit3_if));
    mult_wrapper UNIT_4 (.clk(clk), .nRST(nRST), .portmap(unit4_if));
    ld_st_unit UNIT_5 (.clk(clk), .nRST(nRST), .ld_st_if(unit5_if));



endmodule