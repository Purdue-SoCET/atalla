`ifndef CONTROL_IF_VH
`define CONTROL_IF_VH

interface control_if;

    // -----------------------------
    // Ready/Valid handshake signals
    // -----------------------------

    // -----------------------------
    // Inputs to resolve unit
    // -----------------------------
    logic predict_taken;
    logic [31:0] predict_pc;
    logic [6:0]  ctrl_opcode;

    logic [31:0] pc;
    logic [31:0] incr7;
    logic [31:0] imm;
    logic [7:0]  rd_idx_in;
    logic [7:0]  rs1_idx;
    logic [31:0] rs1_value; 
    logic [31:0] rs2_value;

    // -----------------------------
    // Outputs from resolve unit
    // -----------------------------
    logic        rd_write_en;
    logic [7:0]  rd_idx_out;
    logic [31:0] rd_value;

    logic        redirect_valid;
    logic [31:0] redirect_target;
    logic [31:0] pc_out;

    modport dut (
        input predict_pc, predict_taken,
        input  ctrl_opcode, rd_idx_in, rs1_idx, pc, imm, incr7, rs1_value, rs2_value,
        output rd_idx_out, rd_write_en, rd_value,
        output redirect_valid, redirect_target, pc_out
    );

    modport tb (
        output ctrl_opcode, rd_idx_in, rs1_idx, pc, imm, incr7, rs1_value, rs2_value,
        output predict_pc, predict_taken,
        input  rd_idx_out, rd_write_en, rd_value,
        input  redirect_valid, redirect_target, pc_out
    );

endinterface

`endif