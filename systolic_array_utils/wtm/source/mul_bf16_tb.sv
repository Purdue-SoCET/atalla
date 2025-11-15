`timescale 1ns/1ps
// the expected output values were generated using the test_bf16_mul.py script found in the same directory.

// ./obj_dir/VMAC_unit_tb
// gtkwave waves.vcd --save=mac_debug.gtkw

// to run this: verilator --binary -j 0 -Wall -Wno-fatal mul_bf16_tb.sv mul_bf16.sv -Imodules -Itestbench -Iinclude --hierarchical --trace; ./obj_dir/Vmul_bf16_tb; gtkwave waves/mul_bf16_waves.vcd --save=waves/mul_bf16_debug.gtkw


/* verilator lint_off UNUSEDSIGNAL */
module mul_bf16_tb;

    // Parameters
    localparam CLK_PERIOD = 1;

    // Testbench Signals
    logic tb_clk;
    logic tb_nrst;
    integer i;

    // Clk init
    always
    begin
        tb_clk = 1'b0;
        #(CLK_PERIOD/2.0);
        tb_clk = 1'b1;
        #(CLK_PERIOD/2.0);
    end
    
    logic [15:0] tb_a, tb_b;
    logic tb_start;
    logic [15:0] tb_result;
    logic tb_done;
    logic tb_overflow, tb_underflow, tb_invalid;

    mul_bf16 bob (
        .clk(tb_clk),
        .nRST(tb_nrst),
        .bf1_in(tb_a),
        .bf2_in(tb_b),
        .start(tb_start),
        .bf_out(tb_result),
        .overflow(tb_overflow),
        .underflow(tb_underflow),
        .invalid(tb_invalid),
        .done(tb_done)
    );

    logic [15:0] test_set1[12:0];
    logic [15:0] test_set2[12:0];
    logic [15:0] test_set3[12:0];
    logic [15:0] expected_out[12:0];

    
    // Test sequence
    initial begin
        // Initialize interface signals
        $dumpfile("systolic_array_utils/waves/mul_bf16_waves.vcd");
        $dumpvars();
        tb_nrst = 0;
        #CLK_PERIOD;
        tb_nrst = 1;

        // Test case 1: Normal addition (1.5 + 2.5 = 4.0)
        test_set1[0] = 16'h4720; // 1.5 in BF16
        test_set2[0] = 16'h41c1; // 2.5 in BF16
        expected_out[0] = 16'h4971; // 4.0 in BF16
        
        // Test case 2: Overflow case (maximum normal number + large positive)
        test_set1[1] = 16'h7F7F; // Near max BF16 value
        test_set2[1] = 16'h7F00; // Large positive number
        expected_out[1] = 16'h7F80; // Overflow result (inf) 

        // Test case 3: Different exponent (1024 + 1 = 1025)
        test_set1[2] = 16'h4491; // 1024
        test_set2[2] = 16'h4620; // 1.0
        expected_out[2] = 16'h4b35; // 1025
        
        // Test case 4: Subtraction with different exponents
        test_set1[3] = 16'h487e; // 32.0
        test_set2[3] = 16'h4849; // 0.5
        expected_out[3] = 16'h5147; // 31.5
        
        // Test case 5: Adding very small to large number
        test_set1[4] = 16'h456f; // Large number
        test_set2[4] = 16'h46fd; // Very small number
        expected_out[4] = 16'h4cec; // Should be approx equal to large number
        
        // Test case 6: Near zero result (1.0 - 1.0)
        test_set1[5] = 16'h3F80; // 1.0
        test_set2[5] = 16'hBF80; // -1.0
        expected_out[5] = 16'h3f80; // 0.0
        
        // Test case 7: Negative overflow (-max - max)
        test_set1[6] = 16'hFF7F; // -max
        test_set2[6] = 16'hFF7F; // -max
        expected_out[6] = 16'h7F80; // -inf
        
        // Test case 8: Adding numbers with same exponents
        test_set1[7] = 16'h4854; // 8.0
        test_set2[7] = 16'h463c; // 8.0
        expected_out[7] = 16'h4f1c; // 16.0 
        
        // Test case 9: Mixed signs with larger magnitude negative
        test_set1[8] = 16'h458b; // -2.0
        test_set2[8] = 16'h4420; // 1.0
        expected_out[8] = 16'h4a2e; // -1.0
        
        // Test case 10: Adding denormalized numbers
        test_set1[9] = 16'h403f; // Small denorm
        test_set2[9] = 16'h3ff3; // Small denorm
        expected_out[9] = 16'h40b5; // Resulting denorm

        test_set1[10] = 16'h489e; // Small denorm
        test_set2[10] = 16'h435c; // Small denorm
        expected_out[10] = 16'h4c88; // Resulting denorm

        test_set1[11] = 16'h47e0; // Small denorm
        test_set2[11] = 16'h40b1; // Small denorm
        expected_out[11] = 16'h491b; // Resulting denorm

        test_set1[12] = 16'h48f0; // Small denorm
        test_set2[12] = 16'h43fa; // Small denorm
        expected_out[12] = 16'h4d6a; // Resulting denorm
        
        @(posedge tb_clk);
        tb_start = 1'b0;

        // Test pattern: stream of test vectors
        for(i = 0; i < 13; i++) begin
            // Setup inputs for current test
            tb_a = test_set1[i];
            tb_b = test_set2[i];
            
            // Wait for rising edge and assert start for exactly 1 cycle
            @(posedge tb_clk);
            tb_start = 1'b1;
            
            @(posedge tb_clk);
            tb_start = 1'b0;
            
            // Wait for done pulse from DUT (done will be 1 for one cycle when result is ready)
            @(posedge tb_done);
            
            // Now result is ready; capture and display it
            $display("Test Case %0d:", i);
            $display("Input A: %h (%b)", tb_a, tb_a);
            $display("Input B: %h (%b)", tb_b, tb_b);
            $display("Expected: %h (%b)", expected_out[i], expected_out[i]);
            $display("Result:  %h (%b)", tb_result, tb_result);
            $display("Flags - Overflow: %b, Underflow: %b, Invalid: %b", 
                    tb_overflow, tb_underflow, tb_invalid);
            
            // Check for mismatches
            if (tb_result !== expected_out[i]) begin
                $display("ERROR: Result mismatch! Expected %h, got %h", expected_out[i], tb_result);
            end
            
            // Expected overflow cases
            if (i == 1 || i == 6) begin // Test cases 1 and 6 (0-indexed)
                if (!tb_overflow) begin
                    $display("ERROR: Expected overflow flag for test case %0d", i);
                end
            end
            
            $display("----------------------------------------");
            
            // Small delay before setting up next test (avoid tight loop)
            @(posedge tb_clk);
        end
        
        // Wait a few cycles then finish
        #(5 * CLK_PERIOD);
        $finish;
    end

endmodule
