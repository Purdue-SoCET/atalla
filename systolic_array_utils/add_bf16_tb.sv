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
        .start(tb_start),
        .bf1_in(tb_a),
        .bf2_in(tb_b),
        .bf_out(tb_result),
        .overflow(tb_overflow),
        .underflow(tb_underflow),
        .invalid(tb_invalid)
    );

    logic [15:0] test_set1[9:0];
    logic [15:0] test_set2[9:0];
    logic [15:0] test_set3[9:0];

    
    // Test sequence
    initial begin
        // Initialize interface signals
        $dumpfile("systolic_array_utils/waves/add_bf16_waves.vcd");
        $dumpvars();
        tb_nrst = 0;
        #CLK_PERIOD;
        tb_nrst = 1;

        // Test case 1: Normal addition (1.5 + 2.5 = 4.0)
        test_set1[0] = 16'h3FC0; // 1.5 in BF16
        test_set2[0] = 16'h4040; // 2.5 in BF16
        
        // Test case 2: Overflow case (maximum normal number + large positive)
        test_set1[1] = 16'h7F7F; // Near max BF16 value
        test_set2[1] = 16'h7F00; // Large positive number
        
        // Test case 3: Different exponent (1024 + 1 = 1025)
        test_set1[2] = 16'h6400; // 1024
        test_set2[2] = 16'h3F80; // 1.0
        
        // Test case 4: Subtraction with different exponents
        test_set1[3] = 16'h4200; // 32.0
        test_set2[3] = 16'h3F00; // 0.5
        
        // Test case 5: Adding very small to large number
        test_set1[4] = 16'h7000; // Large number
        test_set2[4] = 16'h3000; // Very small number
        
        // Test case 6: Near zero result (1.0 - 1.0)
        test_set1[5] = 16'h3F80; // 1.0
        test_set2[5] = 16'hBF80; // -1.0
        
        // Test case 7: Negative overflow (-max - max)
        test_set1[6] = 16'hFF7F; // -max
        test_set2[6] = 16'hFF7F; // -max
        
        // Test case 8: Adding numbers with same exponents
        test_set1[7] = 16'h4100; // 8.0
        test_set2[7] = 16'h4100; // 8.0
        
        // Test case 9: Mixed signs with larger magnitude negative
        test_set1[8] = 16'hC000; // -2.0
        test_set2[8] = 16'h3F80; // 1.0
        
        // Test case 10: Adding denormalized numbers
        test_set1[9] = 16'h0080; // Small denorm
        test_set2[9] = 16'h0080; // Small denorm

        @(posedge tb_clk);
        tb_start = 0;

        // Test pattern 2: Continuous stream of instructions
        for(i = 0; i < 10; i++) begin
            tb_start = 1'b0;
            tb_a = test_set1[i];
            tb_b = test_set2[i];
            tb_start = 1'b1;
            #CLK_PERIOD;
            tb_start = 1'b0;
            #CLK_PERIOD;
            
            // Print test case results
            $display("Test Case %0d:", i);
            $display("Input A: %h (%b)", tb_a, tb_a);
            $display("Input B: %h (%b)", tb_b, tb_b);
            $display("Result:  %h (%b)", tb_result, tb_result);
            $display("Flags - Overflow: %b, Underflow: %b, Invalid: %b", 
                    tb_overflow, tb_underflow, tb_invalid);
            $display("----------------------------------------");
            
            // Expected overflow cases
            if (i == 1 || i == 6) begin // Test cases 2 and 7
                if (!tb_overflow)
                    $display("ERROR: Expected overflow flag for test case %0d", i);
            end
            
            #CLK_PERIOD;
        end
        #CLK_PERIOD;
        // @(negedge tb_done);
        $finish;
    end

endmodule
