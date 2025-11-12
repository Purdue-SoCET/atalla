`timescale 1ns/1ps


// ./obj_dir/VMAC_unit_tb
// gtkwave waves.vcd --save=mac_debug.gtkw

// to run this: verilator --binary -j 0 -Wall -Wno-fatal add_bf16_tb.sv add_bf16.sv -Imodules -Itestbench -Iinclude --hierarchical --trace; ./obj_dir/Vadd_bf16_tb; gtkwave waves/add_bf16_waves.vcd --save=waves/add_bf16_debug.gtkw


/* verilator lint_off UNUSEDSIGNAL */
module add_bf16_tb;

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

    add_bf16 bob (
        .clk(tb_clk),
        .nRST(tb_nrst),
        .bf1_in(tb_a),
        .bf2_in(tb_b),
        .bf_out(tb_result),
        .overflow(tb_overflow),
        .underflow(tb_underflow),
        .invalid(tb_invalid)
    );

    logic [15:0] test_set1[13:0];
    logic [15:0] test_set2[13:0];
    logic [15:0] expected_out[13:0];

    
    // Test sequence
    initial begin
        // Initialize interface signals
        $dumpfile("systolic_array_utils/waves/add_bf16_waves.vcd");
        $dumpvars();
        tb_nrst = 0;
        #CLK_PERIOD;
        tb_nrst = 1;

        // Test case 1: Normal addition (1.5 + 2.5 = 4.0)
        test_set1[0] = 16'h3FC0;  // 1.5 in BF16
        test_set2[0] = 16'h4020;  // 2.5 in BF16
        expected_out[0] = 16'h4080; // Expected: 4.0 in BF16
        
        // Test case 2: Overflow case (maximum normal number + large positive)
        test_set1[1] = 16'h7F7F;  // Near max BF16 value (~3.39e38)
        test_set2[1] = 16'h7F00;  // Large positive number (~3.39e38)
        expected_out[1] = 16'h7F80; // Expected: overflow to +infinity (0x7F80)
        
        // Test case 3: Different exponent (1024.0 + 1.0 = 1025.0)
        test_set1[2] = 16'h6400;  // 1024.0 (exponent=128)
        test_set2[2] = 16'h3F80;  // 1.0 (exponent=127)
        expected_out[2] = 16'h6401; // Expected: 1025.0
        
        // Test case 4: Addition with different exponents (32.0 + 0.5 = 32.5)
        test_set1[3] = 16'h4200;  // 32.0 (exponent=132)
        test_set2[3] = 16'h3F00;  // 0.5 (exponent=126)
        expected_out[3] = 16'h4204; // Expected: 32.5
        
        // Test case 5: Adding very small to large number (1e8 + 1e-8 ≈ 1e8)
        test_set1[4] = 16'h7000;  // Large number (~1.5e9)
        test_set2[4] = 16'h3000;  // Very small number (~5.9e-39)
        expected_out[4] = 16'h7000; // Expected: large number (small is lost due to precision)
        
        // Test case 6: Near zero result (1.0 + (-1.0) = 0.0)
        test_set1[5] = 16'h3F80;  // 1.0
        test_set2[5] = 16'hBF80;  // -1.0
        expected_out[5] = 16'h0000; // Expected: 0.0
        
        // Test case 7: Negative overflow (-max - max)
        test_set1[6] = 16'hFF7F;  // -max (~-3.39e38)
        test_set2[6] = 16'hFF7F;  // -max (~-3.39e38)
        expected_out[6] = 16'hFF80; // Expected: overflow to -infinity (0xFF80)
        
        // Test case 8: Adding numbers with same exponents (8.0 + 8.0 = 16.0)
        test_set1[7] = 16'h4100;  // 8.0 (exponent=129)
        test_set2[7] = 16'h4100;  // 8.0 (exponent=129)
        expected_out[7] = 16'h4180; // Expected: 16.0
        
        // Test case 9: Mixed signs with larger magnitude negative (-2.0 + 1.0 = -1.0)
        test_set1[8] = 16'hC000;  // -2.0
        test_set2[8] = 16'h3F80;  // 1.0
        expected_out[8] = 16'hBF80; // Expected: -1.0
        
        // Test case 10: Adding denormalized numbers (2*min_normal ≈ 2*1.17e-38)
        test_set1[9] = 16'h0080;  // Minimum normal BF16 (~1.17e-38)
        test_set2[9] = 16'h0080;  // Minimum normal BF16
        expected_out[9] = 16'h0100; // Expected: 2*min_normal
        
        // Test case 11: Positive infinity + finite number = infinity
        test_set1[10] = 16'h7F80; // +Infinity
        test_set2[10] = 16'h4080; // 4.0
        expected_out[10] = 16'h7F80; // Expected: +infinity
        
        // Test case 12: Positive infinity + negative infinity = NaN (invalid)
        test_set1[11] = 16'h7F80; // +Infinity
        test_set2[11] = 16'hFF80; // -Infinity
        expected_out[11] = 16'h7FC0; // Expected: NaN (or result depends on implementation)
        
        // Test case 13: Zero + zero = zero
        test_set1[12] = 16'h0000; // 0.0
        test_set2[12] = 16'h0000; // 0.0
        expected_out[12] = 16'h0000; // Expected: 0.0
        
        // Test case 14: Negative zero + positive zero (should be 0.0)
        test_set1[13] = 16'h8000; // -0.0
        test_set2[13] = 16'h0000; // +0.0
        expected_out[13] = 16'h0000; // Expected: 0.0

        @(posedge tb_clk);
        tb_start = 0;

        // Test pattern: Continuous stream of instructions with all 14 test cases
        for(i = 0; i < 14; i++) begin
            tb_start = 1'b0;
            tb_a = test_set1[i];
            tb_b = test_set2[i];
            tb_start = 1'b1;
            #CLK_PERIOD;
            tb_start = 1'b0;
            #CLK_PERIOD;
            
            // Print test case results with expected output
            $display("========================================");
            $display("Test Case %0d:", i);
            $display("Input A:       %h", tb_a);
            $display("Input B:       %h", tb_b);
            $display("Expected Out:  %h", expected_out[i]);
            $display("Actual Result: %h", tb_result);
            $display("Match: %s", (tb_result == expected_out[i]) ? "PASS" : "FAIL");
            $display("Flags - Overflow: %b, Underflow: %b, Invalid: %b", 
                    tb_overflow, tb_underflow, tb_invalid);
            $display("========================================");
            
            // Check for expected overflow cases
            if (i == 1 || i == 6) begin // Test cases 2 and 7 (overflow cases)
                if (!tb_overflow)
                    $display("WARNING: Expected overflow flag for test case %0d", i);
            end
            
            #CLK_PERIOD;
        end
        #CLK_PERIOD;
        $finish;
    end

endmodule
