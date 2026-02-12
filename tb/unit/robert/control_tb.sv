`timescale 1ns / 1ps

`include "control_if.sv"
`include "control.sv"

module control_tb;

    logic CLK;
    logic nRST;

    // Instantiate interface
    control_if ctrl_if();

    // DUT
    control dut (
        .CLK    (CLK),
        .nRST   (nRST),
        .ctrl_if(ctrl_if.dut)
    );

    // Clock generation
    initial CLK = 0;
    always #5 CLK = ~CLK;

    // Opcodes (same as DUT)
    localparam logic [6:0] OP_BEQ  = 7'b0100011;
    localparam logic [6:0] OP_BNE  = 7'b0100100;
    localparam logic [6:0] OP_BLT  = 7'b0100101;
    localparam logic [6:0] OP_BGE  = 7'b0100110;
    localparam logic [6:0] OP_BGT  = 7'b0100111;
    localparam logic [6:0] OP_BLE  = 7'b0101000;

    localparam logic [6:0] OP_JAL  = 7'b0101011;
    localparam logic [6:0] OP_JALR = 7'b0101100;

    // Simple stimulus task
    task automatic apply(
        input logic [6:0]  op,
        input logic [31:0] pc,
        input logic [31:0] imm,
        input logic [31:0] incr7,
        input logic [7:0]  rd_idx,
        input logic [7:0]  rs1_idx,
        input logic [31:0] rs1_val,
        input logic [31:0] rs2_val
    );
    begin
        ctrl_if.ctrl_opcode = op;
        ctrl_if.pc          = pc;
        ctrl_if.imm         = imm;
        ctrl_if.incr7       = incr7;
        ctrl_if.rd_idx_in   = rd_idx;
        ctrl_if.rs1_idx     = rs1_idx;
        ctrl_if.rs1_value   = rs1_val;
        ctrl_if.rs2_value   = rs2_val;

        // Let comb settle
        #1;

        $display("T=%0t op=%b pc=%h imm=%h rs1=%h rs2=%h incr7=%h | rd_we=%0d rd_idx=%0d rd_val=%h | redir=%0d target=%h",
                 $time, op, pc, imm, rs1_val, rs2_val, incr7,
                 ctrl_if.rd_write_en, ctrl_if.rd_idx_out, ctrl_if.rd_value,
                 ctrl_if.redirect_valid, ctrl_if.redirect_target);
    end
    endtask

    initial begin
        
        // Init
        nRST = 1'b0;

        // Handshake: always valid/ready
        ctrl_if.valid_in = 1'b1;
        ctrl_if.ready_in = 1'b1;

        // Default inputs
        ctrl_if.ctrl_opcode = '0;
        ctrl_if.pc          = '0;
        ctrl_if.imm         = '0;
        ctrl_if.incr7       = '0;
        ctrl_if.rd_idx_in   = '0;
        ctrl_if.rs1_idx     = '0;
        ctrl_if.rs1_value   = '0;
        ctrl_if.rs2_value   = '0;

        // Release reset
        #12;
        nRST = 1'b1;

        // -----------------------------
        // Tests
        // -----------------------------

        // JAL: rd = PC+4, redirect=PC+imm
        apply(OP_JAL,  32'h0000_1000, 32'h0000_0040, 32'h0, 8'd5, 8'd1, 32'h1111, 32'h2222);
        // Expect: rd_we=1 rd_idx=5 rd_val=0x1004, redirect=1 target=0x1040

        // JALR: rd = PC+4, redirect=rs1+imm
        apply(OP_JALR, 32'h0000_2000, 32'h0000_0008, 32'h0, 8'd7, 8'd2, 32'h0000_3000, 32'h9999);
        // Expect: rd_we=1 rd_idx=7 rd_val=0x2004, redirect=1 target=0x3008

        // BEQ taken: (rs1==rs2) redirect, and write rs1_idx with rs1+incr7
        apply(OP_BEQ,  32'h0000_4000, 32'h0000_0010, 32'h0000_0007, 8'd9, 8'd3, 32'h0000_0011, 32'h0000_0011);
        // Expect: rd_we=1 rd_idx=3 rd_val=0x18, redirect=1 target=0x4010

        // BEQ not taken: no redirect, but still write rs1 update (per your ISA)
        apply(OP_BEQ,  32'h0000_5000, 32'h0000_0020, 32'h0000_0007, 8'd9, 8'd3, 32'h0000_0011, 32'h0000_0012);
        // Expect: rd_we=1 rd_idx=3 rd_val=0x18, redirect=0 target=0x5020 (target value still computed, valid=0)

        // BLT taken (signed): -1 < 1 => taken
        apply(OP_BLT,  32'h0000_6000, 32'h0000_0030, 32'h0000_0007, 8'd0, 8'd4, 32'hFFFF_FFFF, 32'h0000_0001);

        // BGE taken (signed): 5 >= 5 => taken
        apply(OP_BGE,  32'h0000_7000, 32'h0000_0040, 32'h0000_0007, 8'd0, 8'd6, 32'h0000_0005, 32'h0000_0005);

        #20;
        $finish;
    end

endmodule
