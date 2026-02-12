`timescale 1ns / 1ps

`include "scalar_alu_if.sv"
`include "scalar_alu.sv"

module scalar_alu_tb;

    logic CLK;
    logic nRST;

    // Instantiate interface
    scalar_alu_if salu_if();

    // DUT
    scalar_alu dut (
        .CLK   (CLK),
        .nRST  (nRST),
        .salu_if(salu_if.dut)
    );

    // Clock generation
    initial CLK = 0;
    always #5 CLK = ~CLK;

    // -------------------------
    // Task: send instruction
    // -------------------------
    task send_op(
        input [31:0] a,
        input [31:0] b,
        input [31:0] imm,
        input [6:0]  op,
        input [7:0]  rd
    );
    begin
        salu_if.srcA     = a;
        salu_if.srcB     = b;
        salu_if.imm      = imm;
        salu_if.salu_op  = op;
        salu_if.rdIn     = rd;
        salu_if.valid_in = 1;

        wait (salu_if.ready_out == 1);  // wait until DUT ready
        @(posedge CLK);

        salu_if.valid_in = 0;
    end
    endtask


    // -------------------------
    // Monitor
    // -------------------------
    always @(posedge CLK) begin
        if (salu_if.valid_out && salu_if.ready_in) begin
            $display("[WB] rd=%0d rdResult=%0d (0x%08h) time=%0t",
                     salu_if.rdOut,
                     salu_if.rdResult,
                     salu_if.rdResult,
                     $time);
        end
    end


    // -------------------------
    // Test sequence
    // -------------------------
    initial begin
        // init
        salu_if.valid_in  = 0;
        salu_if.ready_in  = 1;   // writeback ready
        salu_if.srcA      = 0;
        salu_if.srcB      = 0;
        salu_if.imm       = 0;
        salu_if.salu_op   = 0;
        salu_if.rdIn      = 0;

        nRST = 0;
        repeat(5) @(posedge CLK);
        nRST = 1;

        // -----------------
        // R-type test
        // -----------------
        $display("---- R-type ADD test ----");
        send_op(10, 20, 0, 7'b0000001, 5);  // add.s
        repeat(2) @(posedge CLK);

        $display("---- R-type SLT test ----");
        send_op(-5, 3, 0, 7'b0001100, 6);   // slt.s
        repeat(2) @(posedge CLK);

        // -----------------
        // I-type test
        // -----------------
        $display("---- I-type ADDI test ----");
        send_op(100, 0, 50, 7'b0010110, 7); // addi.s
        repeat(2) @(posedge CLK);

        $display("---- I-type SLLI test ----");
        send_op(1, 0, 4, 7'b0011110, 8);    // slli.s
        repeat(2) @(posedge CLK);

        // -----------------
        // Stall test
        // -----------------
        $display("---- Stall test ----");
        salu_if.ready_in = 0;   // block writeback

        send_op(7, 8, 0, 7'b0000001, 9); // add.s

        repeat(3) @(posedge CLK);

        salu_if.ready_in = 1;   // release stall
        repeat(3) @(posedge CLK);

        $display("---- TEST DONE ----");
        $finish;
    end

endmodule
