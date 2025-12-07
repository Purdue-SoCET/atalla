`timescale 1ns/1ps

module valu_tb;

    // Clock and reset
    logic CLK;
    logic nRST;
    
    // Interface instantiation
    valu_if valuif();
    
    // DUT instantiation
    valu dut (
        .CLK(CLK),
        .nRST(nRST),
        .valuif(valuif)
    );
    
    // Clock generation (10ns period = 100MHz)
    initial begin
        CLK = 0;
        forever #5 CLK = ~CLK;
    end
    
    // Test variables
    int test_num;
    int errors;
    logic [15:0] expected_result;
    
    // BFloat16 helper function to create test values
    function logic [15:0] make_bf16(logic sign, logic [7:0] exp, logic [6:0] mant);
        return {sign, exp, mant};
    endfunction
    
    // NaN value
    function logic [15:0] make_nan();
        return {1'b0, 8'hFF, 7'h40}; // Quiet NaN
    endfunction
    
    // Task to apply inputs with handshaking
    task automatic apply_operation(
        input logic [15:0] op1,
        input logic [15:0] op2,
        input logic [1:0] alu_op_in,
        input logic wait_ready = 1
    );
        // Set inputs
        valuif.in.operand1 = op1;
        valuif.in.operand2 = op2;
        valuif.in.alu_op = alu_op_in;
        
        // Wait for ready_out if requested
        if (wait_ready) begin
            wait(valuif.out.ready_in == 1'b1);
        end

        // Pulse valid_in
        valuif.in.valid_in = 1'b1;
        @(posedge CLK);
        valuif.in.valid_in = 1'b0;
    endtask
    
    // Task to check output with handshaking
    task automatic check_output(
        input logic [15:0] expected,
        input string test_name
    );
        // Wait for valid output
        while (!valuif.out.valid_out) begin
            @(posedge CLK);
        end
        // @(posedge valuif.out.valid_out);

        // Set tb expected result
        expected_result = expected;
        
        // Check result
        if (valuif.out.result !== expected) begin
            $display("ERROR [%0d] %s: Expected %h, Got %h", 
                     test_num, test_name, expected, valuif.out.result);
            errors++;
        end else begin
            $display("PASS [%0d] %s: Result = %h", 
                     test_num, test_name, valuif.out.result);
        end
        
        // Acknowledge receipt (consumer ready)
        valuif.in.ready_out = 1'b1;
        @(posedge CLK);
        valuif.in.ready_out = 1'b0;
        expected_result = 0;
        test_num++;
    endtask
    
    // Task to clear inputs
    task automatic clear_inputs();
        valuif.in.operand1 = 16'h0;
        valuif.in.operand2 = 16'h0;
        valuif.in.alu_op = 2'b00;
        valuif.in.valid_in = 1'b0;
        valuif.in.ready_out = 1'b0;
    endtask
    
    // Main test sequence
    initial begin
        // Initialize
        test_num = 0;
        errors = 0;
        clear_inputs();
        nRST = 1'b0;
        
        // Reset sequence
        repeat(3) @(posedge CLK);
        nRST = 1'b1;
        repeat(2) @(posedge CLK);
        
        $display("\n=== Starting VALU Tests ===\n");
        
        // ========================================
        // Test 1: VALU_ADD - Simple Addition
        // ========================================
        $display("\n--- Test Group 1: VALU_ADD Operations ---");
        
        // 1.0 + 2.0 = 3.0
        // BF16: 1.0 = 0x3F80, 2.0 = 0x4000, 3.0 = 0x4040
        apply_operation(16'h3F80, 16'h4000, 2'b00);
        check_output(16'h4040, "ADD: 1.0 + 2.0");
        clear_inputs();
        @(posedge CLK);
        
        // 0.5 + 0.5 = 1.0
        // BF16: 0.5 = 0x3F00
        apply_operation(16'h3F00, 16'h3F00, 2'b00);
        check_output(16'h3F80, "ADD: 0.5 + 0.5");
        clear_inputs();
        @(posedge CLK);
        
        // ========================================
        // Test 2: VALU_SUB - Subtraction
        // ========================================
        $display("\n--- Test Group 2: VALU_SUB Operations ---");
        
        // 3.0 - 1.0 = 2.0
        apply_operation(16'h4040, 16'h3F80, 2'b01);
        check_output(16'h4000, "SUB: 3.0 - 1.0");
        clear_inputs();
        @(posedge CLK);
        
        // 2.0 - 2.0 = 0.0
        apply_operation(16'h4000, 16'h4000, 2'b01);
        check_output(16'h0000, "SUB: 2.0 - 2.0");
        clear_inputs();
        @(posedge CLK);
        
        // ========================================
        // Test 3: VALU_GT - Greater Than (Max)
        // ========================================
        $display("\n--- Test Group 3: VALU_GT Operations ---");
        
        // max(2.0, 1.0) = 2.0
        apply_operation(16'h4000, 16'h3F80, 2'b10);
        check_output(16'h4000, "GT: max(2.0, 1.0)");
        clear_inputs();
        @(posedge CLK);
        
        // max(1.0, 2.0) = 2.0
        apply_operation(16'h3F80, 16'h4000, 2'b10);
        check_output(16'h4000, "GT: max(1.0, 2.0)");
        clear_inputs();
        @(posedge CLK);
        
        // ========================================
        // Test 4: VALU_LT - Less Than (Min)
        // ========================================
        $display("\n--- Test Group 4: VALU_LT Operations ---");
        
        // min(2.0, 1.0) = 1.0
        apply_operation(16'h4000, 16'h3F80, 2'b11);
        check_output(16'h3F80, "LT: min(2.0, 1.0)");
        clear_inputs();
        @(posedge CLK);
        
        // min(1.0, 2.0) = 1.0
        apply_operation(16'h3F80, 16'h4000, 2'b11);
        check_output(16'h3F80, "LT: min(1.0, 2.0)");
        clear_inputs();
        @(posedge CLK);
        
        // ========================================
        // Test 5: NaN Handling
        // ========================================
        $display("\n--- Test Group 5: NaN Handling ---");
        
        // NaN + 1.0 = NaN
        apply_operation(make_nan(), 16'h3F80, 2'b00);
        check_output(16'h7FC0, "NaN: NaN + 1.0");
        clear_inputs();
        @(posedge CLK);
        
        // 1.0 + NaN = NaN
        apply_operation(16'h3F80, make_nan(), 2'b00);
        check_output(16'h7FC0, "NaN: 1.0 + NaN");
        clear_inputs();
        @(posedge CLK);
        
        // NaN in SUB operation
        apply_operation(make_nan(), 16'h4000, 2'b01);
        check_output(16'h7FC0, "NaN: NaN - 2.0");
        clear_inputs();
        @(posedge CLK);
        
        // ========================================
        // Test 6: Back-to-Back Operations
        // ========================================
        $display("\n--- Test Group 6: Back-to-Back Operations ---");
        
        // Issue multiple operations without clearing inputs
        apply_operation(16'h3F80, 16'h3F80, 2'b00); // 1.0 + 1.0 = 2.0
        apply_operation(16'h4000, 16'h3F80, 2'b01); // 2.0 - 1.0 = 1.0
        apply_operation(16'h4040, 16'h4000, 2'b10); // max(3.0, 2.0) = 3.0
        
        check_output(16'h4000, "Back-to-back 1: 1.0 + 1.0");
        check_output(16'h3F80, "Back-to-back 2: 2.0 - 1.0");
        check_output(16'h4040, "Back-to-back 3: max(3.0, 2.0)");
        
        clear_inputs();
        @(posedge CLK);
        
        // ========================================
        // Test 7: Handshaking - Consumer Not Ready
        // ========================================
        $display("\n--- Test Group 7: Handshaking Tests ---");
        
        // Apply operation
        apply_operation(16'h3F80, 16'h3F80, 2'b00);
        clear_inputs();
        
        // Wait for valid output
        while (!valuif.out.valid_out) @(posedge CLK);
        
        // Don't assert ready_out, apply another operation
        // This tests that valid_out stays high
        repeat(3) @(posedge CLK);
        
        if (valuif.out.valid_out) begin
            $display("PASS [%0d] Handshake: valid_out held until ready_out", test_num);
        end else begin
            $display("ERROR [%0d] Handshake: valid_out dropped without ready_out", test_num);
            errors++;
        end
        
        // Now acknowledge
        valuif.in.ready_out = 1'b1;
        @(posedge CLK);
        valuif.in.ready_out = 1'b0;
        test_num++;
        
        // ========================================
        // Test 8: Pipeline Flush
        // ========================================
        $display("\n--- Test Group 8: Reset During Operation ---");
        
        apply_operation(16'h4000, 16'h3F80, 2'b00);
        @(posedge CLK);
        
        // Assert reset
        nRST = 1'b0;
        repeat(2) @(posedge CLK);
        nRST = 1'b1;
        repeat(2) @(posedge CLK);
        
        if (!valuif.out.valid_out) begin
            $display("PASS [%0d] Reset: valid_out cleared on reset", test_num);
        end else begin
            $display("ERROR [%0d] Reset: valid_out not cleared", test_num);
            errors++;
        end
        test_num++;
        
        clear_inputs();
        @(posedge CLK);
        
        // ========================================
        // Test Summary
        // ========================================
        repeat(5) @(posedge CLK);
        
        $display("\n=== Test Summary ===");
        $display("Total Tests: %0d", test_num);
        $display("Errors: %0d", errors);
        
        if (errors == 0) begin
            $display("\n*** ALL TESTS PASSED ***\n");
        end else begin
            $display("\n*** TESTS FAILED ***\n");
        end
        
        $finish;
    end
    
    // Timeout watchdog
    initial begin
        #100000;
        $display("ERROR: Testbench timeout!");
        $finish;
    end
    
    // Optional: Waveform dumping
    initial begin
        $dumpfile("valu_tb.vcd");
        $dumpvars(0, valu_tb);
    end

endmodule