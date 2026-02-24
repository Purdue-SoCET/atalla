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

    // Run a single stimulus vector and check expected outputs
    task automatic run_case(
        input logic [6:0]  op,
        input logic [31:0] pc,
        input logic [31:0] imm,
        input logic [31:0] incr7,
        input logic [7:0]  rd_idx_in,
        input logic [7:0]  rs1_idx,
        input logic [31:0] rs1_val,
        input logic [31:0] rs2_val,
        input logic        pred_taken,
        input logic [31:0] pred_pc
    );
    logic taken;
    logic [31:0] expected_target;
    logic expected_redirect;
    logic [31:0] expected_rd_val;
    begin
        // Drive inputs
        ctrl_if.ctrl_opcode = op;
        ctrl_if.pc          = pc;
        ctrl_if.imm         = imm;
        ctrl_if.incr7       = incr7;
        ctrl_if.rd_idx_in   = rd_idx_in;
        ctrl_if.rs1_idx     = rs1_idx;
        ctrl_if.rs1_value   = rs1_val;
        ctrl_if.rs2_value   = rs2_val;
        ctrl_if.predict_taken = pred_taken;
        ctrl_if.predict_pc  = pred_pc;

        // compute expected taken for branches
        unique case (op)
            OP_BEQ: taken = (rs1_val == rs2_val);
            OP_BNE: taken = (rs1_val != rs2_val);
            OP_BLT: taken = ($signed(rs1_val) < $signed(rs2_val));
            OP_BGE: taken = ($signed(rs1_val) >= $signed(rs2_val));
            OP_BGT: taken = ($signed(rs1_val) > $signed(rs2_val));
            OP_BLE: taken = ($signed(rs1_val) <= $signed(rs2_val));
            default: taken = 1'b0;
        endcase

        // expected rd value when rd write enabled for branches
        expected_rd_val = rs1_val + incr7;

        // expected redirect target
        if (op == OP_JAL) begin
            expected_target = pc + imm;
            expected_redirect = !(pred_taken && (pred_pc == expected_target));
        end else if (op == OP_JALR) begin
            expected_target = rs1_val + imm;
            expected_redirect = !(pred_taken && (pred_pc == expected_target));
        end else begin
            // branches
            if (taken) expected_target = pc + imm; else expected_target = pc + 32'd4;
            expected_redirect = (pred_taken != taken) || (pred_taken && (pred_pc != expected_target));
        end

        // Let combinational outputs settle
        #1;

        // Checks
        if (ctrl_if.redirect_valid !== expected_redirect) begin
            $display("FAIL redirect_valid mismatch: op=%b pc=%h imm=%h pred_t=%0d pred_pc=%h taken=%0d -> got=%0d expect=%0d", op, pc, imm, pred_taken, pred_pc, taken, ctrl_if.redirect_valid, expected_redirect);
            $fatal(1);
        end
        if (ctrl_if.redirect_valid && (ctrl_if.redirect_target !== expected_target)) begin
            $display("FAIL redirect_target mismatch: got=%h expect=%h", ctrl_if.redirect_target, expected_target);
            $fatal(1);
        end

        // rd write expectations (per design branches and jumps write rd)
        if (op == OP_JAL || op == OP_JALR) begin
            if (!ctrl_if.rd_write_en) begin $display("FAIL rd_write_en expected for jump"); $fatal(1); end
            if (ctrl_if.rd_value !== (pc + 32'd4)) begin $display("FAIL rd_value for jump: got=%h expect=%h", ctrl_if.rd_value, pc+32'd4); $fatal(1); end
        end else if (op == OP_BEQ || op == OP_BNE || op == OP_BLT || op == OP_BGE || op == OP_BGT || op == OP_BLE) begin
            if (!ctrl_if.rd_write_en) begin $display("FAIL rd_write_en expected for branch"); $fatal(1); end
            if (ctrl_if.rd_value !== expected_rd_val) begin $display("FAIL rd_value for branch: got=%h expect=%h", ctrl_if.rd_value, expected_rd_val); $fatal(1); end
            if (ctrl_if.rd_idx_out !== rs1_idx) begin $display("FAIL rd_idx_out for branch: got=%0d expect=%0d", ctrl_if.rd_idx_out, rs1_idx); $fatal(1); end
        end

        $display("PASS op=%b pc=%h imm=%h pred_t=%0d pred_pc=%h -> redirect=%0d target=%h rd_we=%0d rd_val=%h", op, pc, imm, pred_taken, pred_pc, ctrl_if.redirect_valid, ctrl_if.redirect_target, ctrl_if.rd_write_en, ctrl_if.rd_value);
    end
    endtask

    initial begin
        // Init
        nRST = 1'b0;
        ctrl_if.valid_in  = 1'b1;
        ctrl_if.ready_in  = 1'b1;

        // defaults
        ctrl_if.ctrl_opcode = '0;
        ctrl_if.pc = '0;
        ctrl_if.imm = '0;
        ctrl_if.incr7 = '0;
        ctrl_if.rd_idx_in = '0;
        ctrl_if.rs1_idx = '0;
        ctrl_if.rs1_value = '0;
        ctrl_if.rs2_value = '0;
        ctrl_if.predict_taken = 1'b0;
        ctrl_if.predict_pc = 32'd0;

        #12;
        nRST = 1'b1;

        // Tests: branches and jumps with prediction/misprediction
        // 1) BEQ: actual taken, predicted not taken -> redirect
        run_case(OP_BEQ, 32'h0000_1000, 32'h0000_0010, 32'h4, 8'd0, 8'd3, 32'h5, 32'h5, 1'b0, 32'd0);

        // 2) BEQ: actual not taken, predicted not taken -> no redirect
        run_case(OP_BEQ, 32'h0000_2000, 32'h0000_0020, 32'h4, 8'd0, 8'd3, 32'h6, 32'h7, 1'b0, 32'd0);

        // 3) BEQ: actual taken, predicted taken and correct target -> no redirect
        run_case(OP_BEQ, 32'h0000_3000, 32'h0000_0030, 32'h4, 8'd0, 8'd3, 32'h9, 32'h9, 1'b1, 32'h00003000 + 32'h00000030);

        // 4) BEQ: actual taken, predicted taken but wrong target -> redirect
        run_case(OP_BEQ, 32'h0000_4000, 32'h0000_0040, 32'h8, 8'd0, 8'd4, 32'hA, 32'hA, 1'b1, 32'hdead_beef);

        // 5) JAL: predicted correct -> no redirect
        run_case(OP_JAL, 32'h0000_5000, 32'h0000_0050, 32'h0, 8'd5, 8'd1, 32'h0, 32'h0, 1'b1, 32'h00005000 + 32'h00000050);

        // 6) JALR: predicted wrong -> redirect
        run_case(OP_JALR, 32'h0000_6000, 32'h0000_0008, 32'h0, 8'd6, 8'd2, 32'h0000_7000, 32'h0, 1'b1, 32'h0000_0000);

        $display("All tests passed");
        #10 $finish;
    end

endmodule
