`ifndef ALU_CONTROL_IF_VH
`define ALU_CONTROL_IF_VH

interface alu_control_if;

    logic [31:0] rs1_value, rs2_value;
    logic [7:0] rs1_idx, rdIn;
    logic ready_in, valid_in;
    logic [31:0] pc;
    logic [31:0] incr7;
    logic [31:0] imm;
    logic [6:0]  ctrl_opcode;
    logic [6:0]  salu_op;

    logic [7:0] rdOut;
    logic valid_out, ready_out;
    logic [31:0] rd_value;
    logic redirect_valid;
    logic [31:0] redirect_target;

    modport mainport (
        input rs1_value, rs2_value, rs1_idx, rdIn, ready_out, valid_in, pc, incr7, imm, ctrl_opcode, salu_op,
        output rd_value, valid_out, ready_in, rdOut, less_than, redirect_valid, redirect_target
    );

    modport tb (
        input rd_value, valid_out, ready_in, rdOut, less_than, redirect_valid, redirect_target,
        output rs1_value, rs2_value, rs1_idx, rdIn, ready_out, valid_in, pc, incr7, imm, ctrl_opcode, salu_op
    );

endinterface
`endif
