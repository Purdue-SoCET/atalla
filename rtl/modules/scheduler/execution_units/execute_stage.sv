`timescale 1ns/1ps
`include "execution_unit_if.sv"
`include "sMult_if.sv"
`include "control_if.sv"
`include "bfD_sD_bfInt_intBF_if.sv"
`include "bfA_bfM_bfS_bfSLT_if.sv"
`include "ld_st_unit_if.sv"
`include "atalla_isa_types.vh"
import execution_unit_types_pkg::*;
import atalla_isa_pkg::*;

module execute_stage
(
    input logic clk, nRST,
    execution_unit_if.execution_units ex_if
);
    logic ex1_valid, ex2_valid, ex3_valid, ex4_valid, ex5_valid;
    logic n_halt_latch, halt_latch;

    assign ex_if.halt_out = halt_latch;

    always_comb begin
        if(ex_if.halt == 1) begin
            n_halt_latch = 1'b1;
        end
        else begin
            n_halt_latch = halt_latch;
        end
    end

    always_ff @( posedge clk, negedge nRST ) begin
        if(!nRST) begin
            halt_latch <= 1'b0;
        end else begin
            halt_latch <= n_halt_latch;
        end
    end

    execution_unit_types_pkg::in_DEC2_EX_t post_xbar_ex1, post_xbar_ex2, post_xbar_ex3, post_xbar_ex4, post_xbar_ex5;
    alu_control_if unit1_if ();
    bfD_sD_bfInt_intBF_if unit2_if ();
    bfA_bfM_bfS_bfSLT_if unit3_if ();
    sMult_if unit4_if ();
    ld_st_unit_if unit5_if ();

    xbar_4x5_exec_comb crossbar
    (
        .slot_1(ex_if.DEC2_inputs[0]), .slot_2(ex_if.DEC2_inputs[1]), .slot_3(ex_if.DEC2_inputs[2]), .slot_4(ex_if.DEC2_inputs[3]),
        .ex1_in(post_xbar_ex1), .ex2_in(post_xbar_ex2), .ex3_in(post_xbar_ex3), .ex4_in(post_xbar_ex4), .ex5_in(post_xbar_ex5),
        .ex1_valid(ex1_valid), .ex2_valid(ex2_valid), .ex3_valid(ex3_valid), .ex4_valid(ex4_valid), .ex5_valid(ex5_valid)
    );

    alu_control UNIT_1 (.CLK(clk), .nRST(nRST), .portmap(unit1_if));
    div_bf_scalar_convert_wrapper UNIT_2 (.clk(clk), .nRST(nRST), .portmap(unit2_if));
    addsub_bf16_wrapper UNIT_3 (.clk(clk), .nRST(nRST), .portmap(unit3_if));
    mult_wrapper UNIT_4 (.clk(clk), .nRST(nRST), .portmap(unit4_if));
    ld_st_unit UNIT_5 (.CLK(clk), .nRST(nRST), .ld_st_if(unit5_if));


    //UNIT_1 CONNECTIONS
    //inputs
    assign unit1_if.rs1_value = post_xbar_ex1.rs1_value;
    assign unit1_if.rs2_value = post_xbar_ex1.rs2_value;
    assign unit1_if.rs1_idx = post_xbar_ex1.rs1_idx;
    assign unit1_if.rdIn = post_xbar_ex1.rdIn;
    assign unit1_if.valid_in = ex1_valid;
    assign unit1_if.pc = ex_if.pc;
    assign unit1_if.predict_pc = ex_if.pc_pred_addr_out;
    assign unit1_if.predict_taken = ex_if.predict_taken_out;
    assign unit1_if.incr7 = post_xbar_ex1.incr7;
    assign unit1_if.imm = post_xbar_ex1.imm;
    assign unit1_if.op = post_xbar_ex1.op;
    assign unit1_if.scalar_type_enable = post_xbar_ex1.scalar_type_enable;
    //outputs
    assign ex_if.ex1.valid_out = unit1_if.valid_out;
    assign ex_if.ex1.data_out = unit1_if.rd_value;
    assign ex_if.ex1.rdOut = unit1_if.rdOut;
    //ready handshake
    assign unit1_if.ready_out = ex_if.ready_WB_ex1;
    assign ex_if.ready_DEC2_ex1 = unit1_if.ready_in;
    //branch side
    assign ex_if.redirect_valid = unit1_if.redirect_valid;
    assign ex_if.redirect_target = unit1_if.redirect_target;
    /////
    assign ex_if.pc_out = unit1_if.pc_out;
    /////

    //UNIT_2 CONNECTIONS
    //inputs
    assign unit2_if.input1 = post_xbar_ex2.rs1_value;
    assign unit2_if.input2 = post_xbar_ex2.rs2_value;
    assign unit2_if.rdIn = post_xbar_ex2.rdIn;
    assign unit2_if.valid_in = ex2_valid;
    assign unit2_if.scalar_type_enable = post_xbar_ex2.scalar_type_enable;
    assign unit2_if.imm = post_xbar_ex2.imm;
    assign unit2_if.imm_src = post_xbar_ex2.imm_src;
    //outputs
    assign ex_if.ex2.valid_out = unit2_if.valid_out;
    assign ex_if.ex2.data_out = unit2_if.data_out;
    assign ex_if.ex2.rdOut = unit2_if.rdOut;
    //ready handshake
    assign unit2_if.ready_out = ex_if.ready_WB_ex2;
    assign ex_if.ready_DEC2_ex2 = unit2_if.ready_in;

    //UNIT_3 CONNECTIONS
    //inputs
    assign unit3_if.bf1_in = post_xbar_ex3.rs1_value[15:0];
    assign unit3_if.bf2_in = post_xbar_ex3.rs2_value[15:0];
    assign unit3_if.rdIn = post_xbar_ex3.rdIn;
    assign unit3_if.valid_in = ex3_valid;
    assign unit3_if.scalar_type_enable = post_xbar_ex3.scalar_type_enable;
    //outputs
    assign ex_if.ex3.valid_out = unit3_if.valid_out;
    assign ex_if.ex3.data_out = {16'b0, unit3_if.bf_out};
    assign ex_if.ex3.rdOut = unit3_if.rdOut;
    //ready handshake
    assign unit3_if.ready_out = ex_if.ready_WB_ex3;
    assign ex_if.ready_DEC2_ex3 = unit3_if.ready_in;

    //UNIT_4 CONNECTIONS
    //inputs
    assign unit4_if.input1 = post_xbar_ex4.rs1_value;
    assign unit4_if.input2 = post_xbar_ex4.rs2_value;
    assign unit4_if.rdIn = post_xbar_ex4.rdIn;
    assign unit4_if.valid_in = ex4_valid;
    assign unit4_if.scalar_type_enable = post_xbar_ex4.scalar_type_enable;
    assign unit4_if.imm = post_xbar_ex4.imm;
    assign unit4_if.imm_src = post_xbar_ex4.imm_src;
    //outputs
    assign ex_if.ex4.valid_out = unit4_if.valid_out;
    assign ex_if.ex4.data_out = unit4_if.data_out;
    assign ex_if.ex4.rdOut = unit4_if.rdOut;
    //ready handshake
    assign unit4_if.ready_out = ex_if.ready_WB_ex4;
    assign ex_if.ready_DEC2_ex4 = unit4_if.ready_in;

    //UNIT_5 CONNECTIONS
    //inputs
    assign unit5_if.data_in = post_xbar_ex5.rs1_value;
    assign unit5_if.addr = post_xbar_ex5.imm;
    assign unit5_if.rdIn = post_xbar_ex5.rdIn;
    assign unit5_if.valid_in = ex5_valid;
    assign unit5_if.scalar_type_enable = post_xbar_ex5.scalar_type_enable;
    assign unit5_if.halfWord = post_xbar_ex5.halfWord;
    //outputs
    assign ex_if.ex5.valid_out = unit5_if.valid_out;
    assign ex_if.ex5.data_out = unit5_if.data_out;
    assign ex_if.ex5.rdOut = unit5_if.rdOut;
    //ready handshake
    assign unit5_if.ready_out = ex_if.ready_WB_ex5;
    assign ex_if.ready_DEC2_ex5 = unit5_if.ready_in;
    //D$ signals
    assign unit5_if.data_load = ex_if.data_load;
    assign unit5_if.hit = ex_if.hit;
    assign unit5_if.block_status = ex_if.block_status;
    assign ex_if.WEN = unit5_if.WEN;
    assign ex_if.REN = unit5_if.REN;
    assign ex_if.mem_in_valid = unit5_if.mem_in_valid;
    assign ex_if.data_store = unit5_if.data_store;
    assign ex_if.data_addr = unit5_if.data_addr;

endmodule