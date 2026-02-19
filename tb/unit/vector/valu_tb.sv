`timescale 1ns/1ps

`include "valu_if.vh"
`include "vector_pkg.vh"

module valu_tb;

    import vector_pkg::*;

    // I want to add a lot more test cases in here and do a bunch of random testing, but for now I need to wrap this up quick as possible
    // thus adding basic test cases rn

    // Clock + Reset
    logic CLK;
    logic nRST;

    always #5 CLK = ~CLK;   // 100 MHz

    // Interface + DUT
    valu_if alu_if();

    valu dut (
        .CLK(CLK),
        .nRST(nRST),
        .valuif(alu_if)
    );

    // BF16 constants for testing
    localparam BF_ZERO = 16'h0000;
    localparam BF_NEG0 = 16'h8000;
    localparam BF_ONE = 16'h3F80;
    localparam BF_TWO = 16'h4000;
    localparam BF_NEG1 = 16'hBF80;

    task run_test(
    input logic [15:0] v1,
    input logic [15:0] v2,
    input aluop_e op,
    input logic rm,
    input logic [15:0] expected,
    input string name
    );

    begin
        @(posedge CLK);

        // Drive inputs
        alu_if.in.v1 <= v1;
        alu_if.in.v2 <= v2;
        alu_if.in.aluop <= op;
        alu_if.in.rm <= rm;
        alu_if.in.mask <= 1'b1;
        alu_if.in.valid_in <= 1'b1;

        // Check ready
        if (!alu_if.out.ready_in) begin
        $display("Error: %s not accepted (ready_in=0)", name);
        end

        @(posedge CLK);
        alu_if.in.valid_in <= 1'b0;

        // Fixed 2-cycle latency
        @(posedge CLK);
        @(posedge CLK);

        if (!alu_if.out.valid_out) begin
        $display("Error: %s valid_out not asserted", name);
        end
        else if (alu_if.out.result !== expected) begin
        $display("Failed: %s, Got %h Expected %h", name, alu_if.out.result, expected);
        end
        else begin
        $display("Passed: %s", name);
        end
    end
    endtask

    // BF16 test vectors
    initial begin
        CLK = 0;
        nRST = 0;

        // Default inputs
        alu_if.in.valid_in = 0;
        alu_if.in.v1 = 0;
        alu_if.in.v2 = 0;
        alu_if.in.aluop = ALU_ADD;
        alu_if.in.rm = 0;
        alu_if.in.mask = 1;
        alu_if.in.ready_out = 1;

        // Reset
        repeat (5) @(posedge CLK);
        nRST = 1;
        @(posedge CLK);

        // TEST 1: Ready propagation
        $display("TEST 1: Ready propagation");

        alu_if.in.ready_out = 0;
        @(posedge CLK);

        if (alu_if.out.ready_in !== 0)
            $display("FAILED: ready propagation");
        else
            $display("PASSED: ready propagation");

        alu_if.in.ready_out = 1;
        @(posedge CLK);

        // TEST 2: Do not accept when ready=0
        $display("TEST 2: Not accepted when ready=0");

        alu_if.in.ready_out = 0;

        @(posedge CLK);
        alu_if.in.valid_in <= 1;
        alu_if.in.v1 <= BF_ONE;
        alu_if.in.v2 <= BF_ONE;
        alu_if.in.aluop <= ALU_ADD;

        @(posedge CLK);
        alu_if.in.valid_in <= 0;

        repeat (3) @(posedge CLK);

        if (alu_if.out.valid_out)
            $display("FAILED: Operation accepted when ready=0");
        else
            $display("PASSED: Not accepted when ready=0");

        alu_if.in.ready_out = 1;
        @(posedge CLK);

        // TEST 3: Arithmetic
        run_test(BF_ONE, BF_ONE, ALU_ADD, 0, BF_TWO, "ADD 1+1");
        run_test(BF_TWO, BF_ONE, ALU_SUB, 0, BF_ONE, "SUB 2-1");

        // TEST 4: Logical
        run_test(16'hAAAA, 16'h5555, ALU_AND, 0, 16'h0000, "AND");
        run_test(16'hAAAA, 16'h5555, ALU_OR,  0, 16'hFFFF, "OR");
        run_test(16'hAAAA, 16'h5555, ALU_XOR, 0, 16'hFFFF, "XOR");
        run_test(16'hAAAA, 16'h0000, ALU_NOT, 0, 16'h5555, "NOT");

        // TEST 5: Compare
        run_test(BF_TWO, BF_ONE, ALU_MGT, 0, 16'h0001, "2 > 1");
        run_test(BF_ONE, BF_TWO, ALU_MLT, 0, 16'h0001, "1 < 2");
        run_test(BF_ONE, BF_ONE, ALU_MEQ, 0, 16'h0001, "1 == 1");

        // TEST 6: Reduction
        run_test(BF_TWO, BF_ONE, ALU_MGT, 1, BF_TWO, "MAX(2,1)");
        run_test(BF_TWO, BF_ONE, ALU_MLT, 1, BF_ONE, "MIN(2,1)");

        // TEST 7: Back-to-back
        $display("TEST 7: Back-to-back");

        @(posedge CLK);
        alu_if.in.valid_in <= 1;
        alu_if.in.v1 <= BF_ONE;
        alu_if.in.v2 <= BF_ONE;
        alu_if.in.aluop <= ALU_ADD;

        @(posedge CLK);
        alu_if.in.v1 <= BF_TWO;
        alu_if.in.v2 <= BF_ONE;
        alu_if.in.aluop <= ALU_SUB;

        @(posedge CLK);
        alu_if.in.valid_in <= 0;

        // First result
        repeat (2) @(posedge CLK);
        if (alu_if.out.result !== BF_TWO)
            $display("FAILED: B2B first result");
        else
            $display("PASSED: B2B first result");

        // Second result
        @(posedge CLK);
        if (alu_if.out.result !== BF_ONE)
            $display("FAILED: B2B second result");
        else
            $display("PASSED: B2B second result");

        // TEST 8: Valid gap
        $display("TEST 8: Valid gap");

        run_test(BF_ONE, BF_ONE, ALU_ADD, 0, BF_TWO, "Gap ADD");

        $display("TEST COMPLETE");
        #20;
        $finish;
    end
endmodule