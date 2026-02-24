`ifndef ALU_CONTROL_IF_VH
`define ALU_CONTROL_IF_VH
`include "atalla_isa_types.vh"

interface alu_control_if;
    import atalla_isa_pkg::*;

    logic [31:0] rs1_value, rs2_value;
    logic [7:0] rs1_idx, rdIn;
    logic ready_in, valid_in;
    logic [31:0] pc;
    logic predict_taken;
    logic [31:0] predict_pc;
    logic [31:0] incr7;
    logic [31:0] imm;
    logic [6:0]  op;
    scalar_fu_enable_t scalar_type_enable;

    logic [7:0] rdOut;
    logic valid_out, ready_out;
    logic [31:0] rd_value;
    logic redirect_valid;
    logic [31:0] redirect_target;

    modport mainport (
        input rs1_value, rs2_value, rs1_idx, rdIn, ready_out, valid_in, pc, incr7, imm, op, scalar_type_enable, predict_taken, predict_pc,
        output rd_value, valid_out, ready_in, rdOut, redirect_valid, redirect_target
    );

    modport tb (
        input rd_value, valid_out, ready_in, rdOut, redirect_valid, redirect_target,
        output rs1_value, rs2_value, rs1_idx, rdIn, ready_out, valid_in, pc, incr7, imm, op, scalar_type_enable, predict_taken, predict_pc
    );

endinterface
`endif
