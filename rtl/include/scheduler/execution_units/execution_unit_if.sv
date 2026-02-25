`ifndef EXECUTION_UNIT_IF_VH
`define EXECUTION_UNIT_IF_VH
`include "atalla_isa_types.vh"

package execution_unit_types_pkg;
  import atalla_isa_pkg::*;
  typedef struct packed {
    //control signals to guide the packet through the xbar
    scalar_fu_enable_t scalar_type_enable;
    logic valid_in, imm_src;
    logic halfWord;
    //data signals
    logic [31:0] rs1_value, rs2_value;
    logic [7:0] rs1_idx, rdIn;
    logic [31:0] incr7;
    logic [31:0] imm;
    logic [6:0]  op;
  } in_DEC2_EX_t;

  typedef struct packed {
    logic valid_out;
    logic [31:0] data_out;
    logic [7:0] rdOut;
  } out_WB_t;

endpackage

interface execution_unit_if # (
  parameter NUM_INSTRUCTIONS = 4
);
  import execution_unit_types_pkg::*;

  //control signals to decode 2
  logic ready_DEC2_ex1, ready_DEC2_ex2, ready_DEC2_ex3, ready_DEC2_ex4, ready_DEC2_ex5;
  //control signals from WB
  logic ready_WB_ex1, ready_WB_ex2, ready_WB_ex3, ready_WB_ex4, ready_WB_ex5;
  //branch output
  logic redirect_valid;
  logic [31:0] redirect_target;
  //from dcache
  logic [31:0] data_load;
  logic hit;
  //to dcache 
  logic WEN, REN;
  logic [31:0] data_store, data_addr;
  //halt
  logic halt;
  //branch stuff
  logic [31:0] pc, pc_pred_addr_out;
  logic predict_taken_out;

  in_DEC2_EX_t [NUM_INSTRUCTIONS-1:0] DEC2_inputs;
  out_WB_t ex1, ex2, ex3, ex4, ex5;

  modport execution_units (
    input ready_WB_ex1, ready_WB_ex2, ready_WB_ex3, ready_WB_ex4, ready_WB_ex5, 
    input data_load, hit, 
    input DEC2_inputs, halt, pc, pc_pred_addr_out, predict_taken_out,
    output ready_DEC2_ex1, ready_DEC2_ex2, ready_DEC2_ex3, ready_DEC2_ex4, ready_DEC2_ex5,
    output redirect_valid, redirect_target, WEN, REN, data_store, data_addr,
    output ex1, ex2, ex3, ex4, ex5
  );

  modport tb (
    output ready_WB_ex1, ready_WB_ex2, ready_WB_ex3, ready_WB_ex4, ready_WB_ex5, 
    output data_load, hit, 
    output DEC2_inputs, halt, pc, pc_pred_addr_out, predict_taken_out,
    input ready_DEC2_ex1, ready_DEC2_ex2, ready_DEC2_ex3, ready_DEC2_ex4, ready_DEC2_ex5,
    input redirect_valid, redirect_target, WEN, REN, data_store, data_addr,
    input ex1, ex2, ex3, ex4, ex5
  );

endinterface

`endif