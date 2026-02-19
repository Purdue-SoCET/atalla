`ifndef CONTROL_IF_VH
`define CONTROL_IF_VH

interface control_if;

    // -----------------------------
    // Ready/Valid handshake signals
    // -----------------------------

    logic        valid_in;
    logic        ready_out;  

    logic        valid_out;
    logic        ready_in;   

    // -----------------------------
    // Inputs to resolve unit
    // -----------------------------
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

    modport dut (
        input  valid_in, ready_in,
        input  ctrl_opcode, rd_idx_in, rs1_idx, pc, imm, incr7, rs1_value, rs2_value,
        output ready_out, valid_out,
        output rd_idx_out, rd_write_en, rd_value,
        output redirect_valid, redirect_target
    );

    modport tb (
        output valid_in, ready_in,
        output ctrl_opcode, rd_idx_in, rs1_idx, pc, imm, incr7, rs1_value, rs2_value,
        input  ready_out, valid_out,
        input  rd_idx_out, rd_write_en, rd_value,
        input  redirect_valid, redirect_target
    );

endinterface

`endif