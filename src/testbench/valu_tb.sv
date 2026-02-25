// ------------------------------------------------------------
// tb_valu.sv
// Testbench for Vector Lane ALU
// Owner: Vedant Sharma
// ------------------------------------------------------------

`timescale 1ns/1ps

`include "valu_if.vh"
`include "vector_pkg.vh"

module valu_tb;

    import vector_pkg::*;

    // I want to add a lot more test cases in here and do a bunch of random testing, but for now I need to wrap this up quick as possible
    // thus adding basic test cases rn

    // Also there was quite a few permutations of all inputs that I had to check, 
    // so I simply made a Large verification plan and built this out w claude magic, looked through all of it and its logically correct
    // I don't like the fact that it did it through a bunch of different tasks but ig its more readable that way for other ppl. Just not how I like to tb :(

    // Clock + Reset
    logic CLK;
    logic nRST;

    initial CLK = 0;
    always #5 CLK = ~CLK;   // 100 MHz

    // Interface + DUT
    valu_if alu_if();

    valu dut (
        .CLK(CLK),
        .nRST(nRST),
        .alu_if(alu_if)
    );

    int test_num;
    int pass_count;
    int fail_count;
    string current_test;

    // BF16 constants for testing
    // Format: {sign[15], exp[14:7], mantissa[6:0]}
    // https://flop.evanau.dev/brainfloat-converter
    localparam logic [15:0] BF16_ZERO = 16'h0000;  // +0
    localparam logic [15:0] BF16_NEG_ZERO = 16'h8000;  // -0
    localparam logic [15:0] BF16_ONE = 16'h3F80;  // 1.0
    localparam logic [15:0] BF16_TWO = 16'h4000;  // 2.0
    localparam logic [15:0] BF16_THREE = 16'h4040;  // 3.0
    localparam logic [15:0] BF16_FOUR = 16'h4080;  // 4.0
    localparam logic [15:0] BF16_NEG_ONE = 16'hBF80;  // -1.0
    localparam logic [15:0] BF16_NEG_TWO = 16'hC000;  // -2.0
    localparam logic [15:0] BF16_HALF = 16'h3F00;  // 0.5

    // reset DUT
    task automatic reset_dut();
        nRST = 1'b0;
        alu_if.in.v1 = '0;
        alu_if.in.v2 = '0;
        alu_if.in.aluop = ALU_ADD;
        alu_if.in.rm = 1'b0;
        alu_if.in.mask = 1'b0;
        alu_if.in.valid_in = 1'b0;
        alu_if.in.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        nRST = 1'b1;
        @(posedge CLK);
    endtask

    // Will have tasks to check result, valid, ready

    task automatic check_result(
        input logic [15:0] expected,
        input string msg
    );
        if (alu_if.out.result === expected) begin
            $display("Passed %s: result = 0x%04h", msg, alu_if.out.result);
            pass_count++;
        end else begin
            $display("Failed %s: expected 0x%04h, got 0x%04h", msg, expected, alu_if.out.result);
            fail_count++;
        end
    endtask

    task automatic check_valid(
        input logic expected,
        input string msg
    );
        if (alu_if.out.valid_out === expected) begin
            $display("Passed %s: valid_out = %b", msg, alu_if.out.valid_out);
            pass_count++;
        end else begin
            $display("Failed %s: expected valid_out = %b, got %b", msg, expected, alu_if.out.valid_out);
            fail_count++;
        end
    endtask

    task automatic check_ready(
        input logic expected,
        input string msg
    );
        if (alu_if.out.ready_in === expected) begin
            $display("Passed %s: ready_in = %b", msg, alu_if.out.ready_in);
            pass_count++;
        end else begin
            $display("Failed %s: expected ready_in = %b, got %b", msg, expected, alu_if.out.ready_in);
            fail_count++;
        end
    endtask

    // Send a single operation and wait for result
    task automatic send_op(
        input logic [15:0] v1,
        input logic [15:0] v2,
        input alu_op_t op,
        input logic rm,
        input logic mask
    );
        alu_if.in.v1 = v1;
        alu_if.in.v2 = v2;
        alu_if.in.aluop = op;
        alu_if.in.rm = rm;
        alu_if.in.mask = mask;
        alu_if.in.valid_in = 1'b1;
        @(posedge CLK);
        alu_if.in.valid_in = 1'b0;
    endtask

    // Wait for valid output
    task automatic wait_for_valid();
        while (!alu_if.out.valid_out) begin
            @(posedge CLK);
        end
    endtask

    // Test sequence tasks
    // Phase 1: Reset Test
    task automatic test_reset();
        current_test = "Reset Test";
        $display("\n %s", current_test);
        
        reset_dut();
        
        check_valid(1'b0, "After reset, valid_out");
        check_ready(1'b1, "After reset, ready_in");
        
        if (alu_if.out.result === '0) begin
            $display("pass: After reset, result = 0");
            pass_count++;
        end else begin
            $display("fail: After reset, result should be 0, got 0x%04h", alu_if.out.result);
            fail_count++;
        end
    endtask

    // Phase 2: Basic Handshake
    task automatic test_basic_handshake();
        current_test = "Basic Handshake";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Send valid input
        alu_if.in.v1 = BF16_ONE;
        alu_if.in.v2 = BF16_ONE;
        alu_if.in.aluop = ALU_ADD;
        alu_if.in.rm = 1'b0;
        alu_if.in.mask = 1'b1;
        alu_if.in.valid_in = 1'b1;
        alu_if.in.ready_out = 1'b1;
        
        @(posedge CLK);
        alu_if.in.valid_in = 1'b0;
        
        // Check valid_out is low for 2 cycles (pipeline latency)
        check_valid(1'b0, "Cycle 1: valid_out should be 0");
        
        @(posedge CLK);
        check_valid(1'b0, "Cycle 2: valid_out should be 0");
        
        @(posedge CLK);
        check_valid(1'b1, "Cycle 3: valid_out should be 1");
        check_result(BF16_TWO, "1.0 + 1.0 = 2.0");
    endtask

    // Phase 3: Backpressure Test
    task automatic test_backpressure();
        current_test = "Backpressure Test";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Send first operation
        alu_if.in.v1 = BF16_ONE;
        alu_if.in.v2 = BF16_TWO;
        alu_if.in.aluop = ALU_ADD;
        alu_if.in.rm = 1'b0;
        alu_if.in.mask = 1'b1;
        alu_if.in.valid_in = 1'b1;
        alu_if.in.ready_out = 1'b1;
        
        @(posedge CLK);
        alu_if.in.valid_in = 1'b0;
        
        @(posedge CLK);
        @(posedge CLK);
        
        // Now valid_out should be 1, apply backpressure
        // Now valid_out should be 1, apply backpressure
        check_valid(1'b1, "Result ready");

        alu_if.in.ready_out = 1'b0;  // Stall!
        #1;  // Small delay for combinational logic to settle

        check_ready(1'b0, "Backpressure: ready_in should be 0");
        check_valid(1'b1, "Backpressure: valid_out should stay 1");
        check_result(BF16_THREE, "Result should hold (1.0 + 2.0 = 3.0)");

        @(posedge CLK);  // Now advance clock
        
        // Hold for a few cycles
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_THREE, "Result still held after stall");
        
        // Release backpressure
        alu_if.in.ready_out = 1'b1;
        @(posedge CLK);
        check_ready(1'b1, "After release: ready_in should be 1");
    endtask

    // Phase 4: In-flight completion, ty Jing totally forgot this would be a thing
    task automatic test_inflight_completion();
        current_test = "In-flight Completion";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Start first operation
        alu_if.in.v1 = BF16_TWO;
        alu_if.in.v2 = BF16_TWO;
        alu_if.in.aluop = ALU_ADD;
        alu_if.in.rm = 1'b0;
        alu_if.in.mask = 1'b1;
        alu_if.in.valid_in = 1'b1;
        alu_if.in.ready_out = 1'b1;
        
        @(posedge CLK);
        
        // Immediately drop valid (no second operation)
        alu_if.in.valid_in = 1'b0;
        alu_if.in.v1 = 16'h1234;  // Garbage to ensure don't use this
        alu_if.in.v2 = 16'h4312;
        
        @(posedge CLK);
        check_valid(1'b0, "Cycle 2: valid_out still 0");
        
        @(posedge CLK);
        check_valid(1'b1, "Cycle 3: First op should complete");
        check_result(BF16_FOUR, "2.0 + 2.0 = 4.0 (in-flight completed)");
        
        @(posedge CLK);
        check_valid(1'b0, "Cycle 4: No second op, valid_out should be 0");
    endtask

    // Phase 5: Mask Skip Test
    task automatic test_mask_skip();
        current_test = "Mask Skip Test";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Send with mask=0, rm=0 (should skip)
        alu_if.in.v1 = BF16_ONE;
        alu_if.in.v2 = BF16_TWO;
        alu_if.in.aluop = ALU_ADD;
        alu_if.in.rm = 1'b0;
        alu_if.in.mask = 1'b0;  // Masked off
        alu_if.in.valid_in = 1'b1;
        alu_if.in.ready_out = 1'b1;
        
        @(posedge CLK);
        alu_if.in.valid_in = 1'b0;
        
        @(posedge CLK);
        @(posedge CLK);
        
        check_valid(1'b1, "Masked op still produces valid");
        check_result(BF16_ZERO, "Masked off: result should be 0");
    endtask

    // Phase 6: ADD Tests
    task automatic test_add();
        current_test = "ADD Tests";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Test 1: 1.0 + 1.0 = 2.0
        send_op(BF16_ONE, BF16_ONE, ALU_ADD, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_TWO, "ADD: 1.0 + 1.0 = 2.0");
        
        @(posedge CLK);
        
        // Test 2: 2.0 + (-1.0) = 1.0
        send_op(BF16_TWO, BF16_NEG_ONE, ALU_ADD, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_ONE, "ADD: 2.0 + (-1.0) = 1.0");
        
        @(posedge CLK);
        
        // Test 3: 0 + 0 = 0
        send_op(BF16_ZERO, BF16_ZERO, ALU_ADD, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_ZERO, "ADD: 0 + 0 = 0");
    endtask

    // Phase 7: SUB Tests
    task automatic test_sub();
        current_test = "SUB Tests";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Test 1: 2.0 - 1.0 = 1.0
        send_op(BF16_TWO, BF16_ONE, ALU_SUB, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_ONE, "SUB: 2.0 - 1.0 = 1.0");
        
        @(posedge CLK);
        
        // Test 2: 1.0 - 2.0 = -1.0
        send_op(BF16_ONE, BF16_TWO, ALU_SUB, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_NEG_ONE, "SUB: 1.0 - 2.0 = -1.0");
        
        @(posedge CLK);
        
        // Test 3: 1.0 - 1.0 = 0
        send_op(BF16_ONE, BF16_ONE, ALU_SUB, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        // Could be +0 or -0, check either
        if (alu_if.out.result === BF16_ZERO || alu_if.out.result === BF16_NEG_ZERO) begin
            $display("Passed SUB: 1.0 - 1.0 = 0 (got 0x%04h)", alu_if.out.result);
            pass_count++;
        end else begin
            $display("Failed SUB: 1.0 - 1.0 expected 0, got 0x%04h", alu_if.out.result);
            fail_count++;
        end
    endtask

    // Phase 8: ADD/SUB with mask=0
    task automatic test_add_sub_masked();
        current_test = "ADD/SUB Masked Tests";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // ADD with mask=0
        send_op(BF16_ONE, BF16_TWO, ALU_ADD, 1'b0, 1'b0);
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_ZERO, "ADD masked: should be 0");
        
        @(posedge CLK);
        
        // SUB with mask=0
        send_op(BF16_TWO, BF16_ONE, ALU_SUB, 1'b0, 1'b0);
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_ZERO, "SUB masked: should be 0");
    endtask

    // Phase 9: MGT (Mask Greater Than) Tests
    task automatic test_mgt();
        current_test = "MGT Tests";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Test 1: 2.0 > 1.0 = 1
        send_op(BF16_TWO, BF16_ONE, ALU_MGT, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0001, "MGT: 2.0 > 1.0 = 1");
        
        @(posedge CLK);
        
        // Test 2: 1.0 > 2.0 = 0
        send_op(BF16_ONE, BF16_TWO, ALU_MGT, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0000, "MGT: 1.0 > 2.0 = 0");
        
        @(posedge CLK);
        
        // Test 3: 1.0 > 1.0 = 0 (equal, not greater)
        send_op(BF16_ONE, BF16_ONE, ALU_MGT, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0000, "MGT: 1.0 > 1.0 = 0");
        
        @(posedge CLK);
        
        // Test 4: -1.0 > -2.0 = 1
        send_op(BF16_NEG_ONE, BF16_NEG_TWO, ALU_MGT, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0001, "MGT: -1.0 > -2.0 = 1");
    endtask

    // Phase 10: MLT (Mask Less Than) Tests
    task automatic test_mlt();
        current_test = "MLT Tests";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Test 1: 1.0 < 2.0 = 1
        send_op(BF16_ONE, BF16_TWO, ALU_MLT, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0001, "MLT: 1.0 < 2.0 = 1");
        
        @(posedge CLK);
        
        // Test 2: 2.0 < 1.0 = 0
        send_op(BF16_TWO, BF16_ONE, ALU_MLT, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0000, "MLT: 2.0 < 1.0 = 0");
        
        @(posedge CLK);
        
        // Test 3: 1.0 < 1.0 = 0 (equal, not less)
        send_op(BF16_ONE, BF16_ONE, ALU_MLT, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0000, "MLT: 1.0 < 1.0 = 0");
    endtask

    // Phase 11: MEQ (Mask Equal) Tests
    task automatic test_meq();
        current_test = "MEQ Tests";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Test 1: 1.0 == 1.0 = 1
        send_op(BF16_ONE, BF16_ONE, ALU_MEQ, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0001, "MEQ: 1.0 == 1.0 = 1");
        
        @(posedge CLK);
        
        // Test 2: 1.0 == 2.0 = 0
        send_op(BF16_ONE, BF16_TWO, ALU_MEQ, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0000, "MEQ: 1.0 == 2.0 = 0");
        
        @(posedge CLK);
        
        // Test 3: +0 == -0 = 1 (special case!)
        send_op(BF16_ZERO, BF16_NEG_ZERO, ALU_MEQ, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0001, "MEQ: +0 == -0 = 1");
    endtask

    // Phase 12: MNEQ (Mask Not Equal) Tests
    task automatic test_mneq();
        current_test = "MNEQ Tests";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Test 1: 1.0 != 2.0 = 1
        send_op(BF16_ONE, BF16_TWO, ALU_MNEQ, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0001, "MNEQ: 1.0 != 2.0 = 1");
        
        @(posedge CLK);
        
        // Test 2: 1.0 != 1.0 = 0
        send_op(BF16_ONE, BF16_ONE, ALU_MNEQ, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0000, "MNEQ: 1.0 != 1.0 = 0");
        
        @(posedge CLK);
        
        // Test 3: +0 != -0 = 0 (special case!)
        send_op(BF16_ZERO, BF16_NEG_ZERO, ALU_MNEQ, 1'b0, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(16'h0000, "MNEQ: +0 != -0 = 0");
    endtask

    // Phase 13: Reduction MAX
    task automatic test_reduction_max();
        current_test = "Reduction MAX Tests";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Test 1: max(1.0, 2.0) = 2.0
        send_op(BF16_ONE, BF16_TWO, ALU_MGT, 1'b1, 1'b1);  // rm=1!
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_TWO, "Reduction MAX: max(1.0, 2.0) = 2.0");
        
        @(posedge CLK);
        
        // Test 2: max(2.0, 1.0) = 2.0
        send_op(BF16_TWO, BF16_ONE, ALU_MGT, 1'b1, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_TWO, "Reduction MAX: max(2.0, 1.0) = 2.0");
        
        @(posedge CLK);
        
        // Test 3: max(-1.0, -2.0) = -1.0
        send_op(BF16_NEG_ONE, BF16_NEG_TWO, ALU_MGT, 1'b1, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_NEG_ONE, "Reduction MAX: max(-1.0, -2.0) = -1.0");
    endtask

    // Phase 14: Reduction MIN
    task automatic test_reduction_min();
        current_test = "Reduction MIN Tests";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Test 1: min(1.0, 2.0) = 1.0
        send_op(BF16_ONE, BF16_TWO, ALU_MLT, 1'b1, 1'b1);  // rm=1!
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_ONE, "Reduction MIN: min(1.0, 2.0) = 1.0");
        
        @(posedge CLK);
        
        // Test 2: min(2.0, 1.0) = 1.0
        send_op(BF16_TWO, BF16_ONE, ALU_MLT, 1'b1, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_ONE, "Reduction MIN: min(2.0, 1.0) = 1.0");
        
        @(posedge CLK);
        
        // Test 3: min(-1.0, -2.0) = -2.0
        send_op(BF16_NEG_ONE, BF16_NEG_TWO, ALU_MLT, 1'b1, 1'b1);
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_NEG_TWO, "Reduction MIN: min(-1.0, -2.0) = -2.0");
    endtask

    // Phase 15: Reduction SUM
    task automatic test_reduction_sum();
        current_test = "Reduction SUM Tests";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Test 1: sum(1.0, 2.0) = 3.0 (same as ADD but with rm=1)
        send_op(BF16_ONE, BF16_TWO, ALU_ADD, 1'b1, 1'b1);  // rm=1!
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_THREE, "Reduction SUM: 1.0 + 2.0 = 3.0");
        
        @(posedge CLK);
        
        // Test 2: sum with mask=0 but rm=1 (should still compute!)
        send_op(BF16_ONE, BF16_ONE, ALU_ADD, 1'b1, 1'b0);  // mask=0, rm=1
        @(posedge CLK);
        @(posedge CLK);
        check_result(BF16_TWO, "Reduction SUM (mask=0, rm=1): should compute = 2.0");
    endtask

    // Phase 16: Back-to-back Operations
    task automatic test_back_to_back();
        current_test = "Back-to-back Operations";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Send continuous stream
        alu_if.in.aluop = ALU_ADD;
        alu_if.in.rm = 1'b0;
        alu_if.in.mask = 1'b1;
        alu_if.in.ready_out = 1'b1;
        
        // Op 1
        alu_if.in.v1 = BF16_ONE;
        alu_if.in.v2 = BF16_ONE;
        alu_if.in.valid_in = 1'b1;
        @(posedge CLK);
        
        // Op 2
        alu_if.in.v1 = BF16_TWO;
        alu_if.in.v2 = BF16_ONE;
        @(posedge CLK);
        
        // Op 3
        alu_if.in.v1 = BF16_THREE;
        alu_if.in.v2 = BF16_ONE;
        @(posedge CLK);
        
        alu_if.in.valid_in = 1'b0;
        
        // Wait for first result
        check_valid(1'b1, "B2B: First result ready");
        check_result(BF16_TWO, "B2B Op1: 1.0 + 1.0 = 2.0");
        
        @(posedge CLK);
        check_valid(1'b1, "B2B: Second result ready");
        check_result(BF16_THREE, "B2B Op2: 2.0 + 1.0 = 3.0");
        
        @(posedge CLK);
        check_valid(1'b1, "B2B: Third result ready");
        check_result(BF16_FOUR, "B2B Op3: 3.0 + 1.0 = 4.0");
    endtask

    // Phase 17: Mixed Stalls
    task automatic test_mixed_stalls();
        current_test = "Mixed Stalls";
        $display("\n %s", current_test);
        
        reset_dut();
        
        // Send first op
        send_op(BF16_ONE, BF16_ONE, ALU_ADD, 1'b0, 1'b1);
        
        @(posedge CLK);
        @(posedge CLK);
        
        // Result ready, stall it
        check_valid(1'b1, "Result 1 ready");
        alu_if.in.ready_out = 1'b0;
        
        // Try to send another op while stalled
        alu_if.in.v1 = BF16_TWO;
        alu_if.in.v2 = BF16_TWO;
        alu_if.in.valid_in = 1'b1;
        
        @(posedge CLK);
        check_ready(1'b0, "Stalled: ready_in = 0");
        check_result(BF16_TWO, "First result held");
        
        @(posedge CLK);
        @(posedge CLK);
        
        // Release stall
        alu_if.in.ready_out = 1'b1;
        @(posedge CLK);
        
        check_ready(1'b1, "Unstalled: ready_in = 1");
        
        // Clear input
        alu_if.in.valid_in = 1'b0;
        
        @(posedge CLK);
        @(posedge CLK);
        
        // Second op should now complete
        check_valid(1'b1, "Result 2 ready after unstall");
        check_result(BF16_FOUR, "Second result: 2.0 + 2.0 = 4.0");
    endtask

    // BF16 test vectors
    initial begin
        $display("\n");
        $display("Tb Start");

        test_num = 0;
        pass_count = 0;
        fail_count = 0;

        test_reset();
        test_basic_handshake();
        test_backpressure();
        test_inflight_completion();
        test_mask_skip();
        test_add();
        test_sub();
        test_add_sub_masked();
        test_mgt();
        test_mlt();
        test_meq();
        test_mneq();
        test_reduction_max();
        test_reduction_min();
        test_reduction_sum();
        test_back_to_back();
        test_mixed_stalls();

        // Summary
        $display("passed: %0d", pass_count);
        $display("failed: %0d", fail_count);

        if (fail_count == 0) begin
            $display("all tests passed!");
        end else begin
            $display("some tests failed!");
        end
        $finish;
    end
endmodule