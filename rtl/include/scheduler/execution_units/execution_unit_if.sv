`ifndef EXECUTION_UNIT_IF_VH
`define EXECUTION_UNIT_IF_VH

interface execution_unit_if;

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

  //data struct from decode 2
  typedef struct packed {
    //control signals to guide the packet through the xbar
    logic alu_valid, control_valid, bf_add_valid, bf_sub_valid, bf_mult_valid, bf_slt_valid, bf_div_valid, s_div_valid, s_mod_valid, BF_to_int_valid, int_to_BF_valid, ld_valid, st_valid, halfword, sMult_valid;
    logic valid_in;
    //data signals
    logic [31:0] rs1_value, rs2_value;
    logic [7:0] rs1_idx, rdIn;
    logic [31:0] pc;
    logic [31:0] incr7;
    logic [31:0] imm;
    logic [6:0]  op;
  } in_DEC_t;

  typedef struct packed {
    logic valid_out;
    logic [31:0] data_out;
    logic [7:0] rdOut;
  } out_WB_t;

  in_DEC_t  slot_1, slot_2, slot_3, slot_4;
  in_DEC_t post_xbar_ex1, post_xbar_ex2, post_xbar_ex3, post_xbar_ex4, post_xbar_ex5;
  out_WB_t ex1, ex2, ex3, ex4, ex5;

  modport execution_units (
    input ready_WB_ex1, ready_WB_ex2, ready_WB_ex3, ready_WB_ex4, ready_WB_ex5, data_load, hit, slot_1, slot_2, slot_3, slot_4,
    output ready_DEC2_ex1, ready_DEC2_ex2, ready_DEC2_ex3, ready_DEC2_ex4, ready_DEC2_ex5, redirect_valid, redirect_target, WEN, REN, data_store, data_addr, ex1, ex2, ex3, ex4, ex5
  );

  modport tb (
    output ready_WB_ex1, ready_WB_ex2, ready_WB_ex3, ready_WB_ex4, ready_WB_ex5, data_load, hit, slot_1, slot_2, slot_3, slot_4,
    input ready_DEC2_ex1, ready_DEC2_ex2, ready_DEC2_ex3, ready_DEC2_ex4, ready_DEC2_ex5, redirect_valid, redirect_target, WEN, REN, data_store, data_addr, ex1, ex2, ex3, ex4, ex5
  );

endinterface

`endif