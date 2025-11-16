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

    logic [15:0] test_set1[24:0];
    logic [15:0] test_set2[24:0];
    logic [15:0] expected_out[24:0];

    
    // Declaring some local parameters for special values here for easy reference
    localparam logic [15:0] QNAN = 16'h7FC0; // Quiet NaN, need to ask if we want to sNaN support, I dont believe its needed tho
    localparam logic [15:0] POS_INF = 16'h7F80; // Positive Infinity
    localparam logic [15:0] NEG_INF = 16'hFF80; // Negative Infinity
    localparam logic [15:0] POS_ZERO = 16'h0000; // Positive Zero
    localparam logic [15:0] NEG_ZERO = 16'h8000; // Negative Zero
    localparam logic [15:0] MAX_POS = 16'h7F7F; // Max Normal Number
    localparam logic [15:0] MAX_NEG = 16'hFF7F; // Max Negative Normal Number

    integer idx = 0; // lowkey why didnt i think of this earlier, wouldve saved SOOOOO much time
    // Test sequence
    initial begin
        // Initialize interface signals
        // #yoinked this from my buddies in systolic array teehee
        $dumpfile("systolic_array_utils/waves/add_bf16_waves.vcd");
        $dumpvars();
        tb_nrst = 0;
        #CLK_PERIOD;
        tb_nrst = 1;

        /* 

        I'm revamping this TB to have more comprehensive test cases for BF16 addition
        I honestly don't want to change the way tasks are structured here so imma just
        follow the same format as before but with correct BF16 values and expected outputs

        ***Current Concern: We havent reclarified how we are rounding again,
            back in fp16, we did DAZ/FTZ. Looking at googles TPU doc, it seems like
            they do use FTZ for BF16 as well, but not DAZ. 
            They also mention round to nearest even, which i believe we are trying to currently support
            So imma assume FTZ and round to nearest even for now***

        To whom ir may concern please note that some of the previous test cases had incorrect expected outputs
        for BF16 addition, so I've corrected those as well.

        Test Cases Included:
        0. Basic Normal Addition
        1. Signed Zero Behavior
        2. Infinity Handling
        3. NaN Handling
        4. Overflow Handling
        5. Underflow Handling
        6. Different Exponent Addition (alignment stress test)
        7. Cancellation Cases

        If any additional test cases are needed please let me know @vedant_sharma :)

        #vedanttheverifier LOL
        */

        // *****
        // 0. Basic Normal Addition:
        // *****

        // Test case 0: Normal addition (1.5 + 2.5 = 4.0)
        // This TB is correct vals.

        test_set1[idx] = 16'h3FC0;  // 1.5 in BF16
        test_set2[idx] = 16'h4020;  // 2.5 in BF16
        expected_out[idx] = 16'h4080; // Expected: 4.0 in BF16
        idx++;

        // Test case 1: Addition with different exponents (32.0 + 0.5 = 32.5)
        // This TB is now correct vals.

        test_set1[idx] = 16'h4200;  // 32.0 (exponent=132)
        test_set2[idx] = 16'h3F00;  // 0.5 (exponent=126)
        expected_out[idx] = 16'h4202; // Expected: 32.5 (had to change this cause is was 4204 before)
        idx++;

        // Test case 2: Adding numbers with same exponents (8.0 + 8.0 = 16.0)
        // This TB is correct vals.

        test_set1[idx] = 16'h4100;  // 8.0 (exponent=129)
        test_set2[idx] = 16'h4100;  // 8.0 (exponent=129)
        expected_out[idx] = 16'h4180; // Expected: 16.0
        idx++;

        // Test case 3: Different exponent (1024.0 + 1.0 = 1025.0)
        // *Note*: Changed this test case to use 8.0, cause if you do 1.0, then the expected output becomes 1025.0 which cannot be represented in BF16.
        // next possible interval step is by 8, also p sure that this tb was using fp16 vals for some of the cases so imma go thru and check each one lol
        // This TB is now correct vals.

        test_set1[idx] = 16'h4480;  // 1024.0 (exponent=137)
        test_set2[idx] = 16'h4100;  // 8.0 (exponent=130)
        expected_out[idx] = 16'h4481; // Expected: 1032.0
        idx++;


        // *****
        // 1. Signed Zero Behavior:
        // *****
        
        // Test case 4: Zero + zero = zero
        // This TB is correct vals.

        test_set1[idx] = POS_ZERO; // 0.0
        test_set2[idx] = POS_ZERO; // 0.0
        expected_out[idx] = POS_ZERO; // Expected: 0.0
        idx++;
        
        // Test case 5: Negative zero + positive zero (should be 0.0)
        // This TB is correct vals.

        // Warning!: RTL is currently failing this case! 
        // -0.0 + +0.0 should be +0.0 but RTL is giving -0.0

        test_set1[idx] = NEG_ZERO; // -0.0
        test_set2[idx] = POS_ZERO; // +0.0
        expected_out[idx] = POS_ZERO; // Expected: 0.0
        idx++;

        // Test case 6: Negative zero + Negative zero (should be (-)0.0)
        // This TB is correct vals.

        test_set1[idx] = NEG_ZERO; // -0.0
        test_set2[idx] = NEG_ZERO; // -0.0
        expected_out[idx] = NEG_ZERO; // Expected: -0.0
        idx++;

        // Test case 7: Positive zero + Some finite value (+x + 0 = +x)
        // This TB is correct vals.

        test_set1[idx] = POS_ZERO; // 0.0
        test_set2[idx] = 16'h4100; // 8.0
        expected_out[idx] = 16'h4100; // Expected: 8.0
        idx++;


        // *****
        // 2. Infinity Handling:
        // *****

        // Test case 8: Positive infinity + finite number = infinity
        // This TB is correct vals.

        test_set1[idx] = POS_INF; // +Infinity
        test_set2[idx] = 16'h4080; // 4.0
        expected_out[idx] = POS_INF; // Expected: +infinity
        idx++;
        
        // Test case 9: Positive infinity + negative infinity = NaN (invalid)
        // This TB is correct vals.

        // Warning!: RTL is currently failing this case! 
        // +inf + -inf should be NaN but RTL is giving a version of infinity?! 

        test_set1[idx] = POS_INF; // +Infinity
        test_set2[idx] = NEG_INF; // -Infinity
        expected_out[idx] = QNAN; // Expected: NaN (or result depends on implementation)
        idx++;

        // Test case 10: Negative infinity + finite negative number = negative infinity
        // This TB is correct vals.

        test_set1[idx] = NEG_INF; // -Infinity
        test_set2[idx] = 16'h4080; // 4.0
        expected_out[idx] = NEG_INF; // Expected: -infinity
        idx++;

        // Test case 11: Negative infinity + negative infinity = negative infinity
        // This TB is correct vals.

        // Warning!: RTL is currently failing this case! 
        // -inf + -inf should be -inf but RTL is giving 8000 (- zero)

        test_set1[idx] = NEG_INF; // -Infinity
        test_set2[idx] = NEG_INF; // -Infinity
        expected_out[idx] = NEG_INF; // Expected: -infinity
        idx++;

        // Test case 12: Positive infinity + positive infinity = positive infinity
        // This TB is correct vals.

        // Warning!: RTL is currently failing this case! 
        // Inf + Inf should be Inf but RTL is giving 0000

        test_set1[idx] = POS_INF; // +Infinity
        test_set2[idx] = POS_INF; // +Infinity
        expected_out[idx] = POS_INF; // Expected: +infinity
        idx++;


        // *****
        // 3. NaN Handling:
        // *****

        // Test case 13: NaN + any number = NaN
        // This TB is correct vals.

        test_set1[idx] = QNAN; // NaN
        test_set2[idx] = 16'h3F80; // 1.0
        expected_out[idx] = QNAN; // Expected: NaN
        idx++;

        // Test case 14: NaN + NaN = NaN
        // This TB is correct vals.
        
        // Warning!: RTL is currently failing this case! 
        // This is so odd, obviosly anytime you process NaN in add, it should return NaN but RTL is giving 0040, a subnormal instead


        test_set1[idx] = QNAN; // NaN
        test_set2[idx] = QNAN; // NaN
        expected_out[idx] = QNAN; // Expected: NaN
        idx++;


        // *****
        // 4. Overflow Handling:
        // *****

        // Test case 15: Overflow case (maximum normal number + large positive)
        // This TB is now correct vals.

        // Warning!: RTL is currently failing this case! 
        // it should be pos inf but RTL is giving some other value (ie. 7fbf)

        test_set1[idx] = MAX_POS;  // Near max BF16 value (~3.39e38)
        test_set2[idx] = 16'h7F00;  // Large positive number (~3.39e38)
        expected_out[idx] = POS_INF; // Expected: overflow to +infinity (0x7F80)
        idx++;

        // Test case 16: Negative overflow (-max - max)
        // This TB is correct vals.

        // Warning!: RTL is currently failing this case! 
        // -inf should be sign and exp all 1s mantissa 0s but RTL is giving all 1s for everthing ie. ffff

        test_set1[idx] = MAX_NEG;  // -max (~-3.39e38)
        test_set2[idx] = MAX_NEG;  // -max (~-3.39e38)
        expected_out[idx] = NEG_INF; // Expected: overflow to -infinity (0xFF80)
        idx++;

        
        // *****
        // 5. Underflow Handling:
        // *****

        // Test case 17: Adding denormalized numbers (2*min_normal ≈ 2*1.17e-38)
        // This TB is correct vals.

        test_set1[idx] = 16'h0080;  // Minimum normal BF16 (~1.17e-38)
        test_set2[idx] = 16'h0080;  // Minimum normal BF16
        expected_out[idx] = 16'h0100; // Expected: 2*min_normal
        idx++;

        // Test case 18: Testing subnormals (should result in a subnormal, which FTZ to 0)
        // This TB is correct vals.

        // Warning!: RTL is currently failing this case! 
        // This ones rlly weird it adds up to a really high positive value?! 7d00

        test_set1[idx] = 16'h0001; // Smallest subnormal
        test_set2[idx] = 16'h0001; // Smallest subnormal
        expected_out[idx] = POS_ZERO; // Expected: 0.0 due to FTZ
        idx++;

        // Test case 19: Adding two numbers of opposite sign but close magnitudes that result in subnormal (should underflow to zero, ie FTZ behavior)
        // This TB is correct vals.

        // Warning!: RTL is currently failing this case! 
        // This ones rlly weird it adds up to a really high positive value?! 7d00
        
        test_set1[idx] = 16'h0081; // Small normal number
        test_set2[idx] = 16'h8080; // Negative number close in magnitude
        expected_out[idx] = POS_ZERO; // Expected: 0.0 due to FTZ
        idx++;


        // *****
        // 6. Different Exponent Addition (alignment stress test):
        // *****

        // Test case 20: Adding very small to large number (1e8 + 1e-8 ≈ 1e8)
        // This TB is correct vals.

        test_set1[idx] = 16'h7000;  // Large number (~1.5e9)
        test_set2[idx] = 16'h3000;  // Very small number (~5.9e-39)
        expected_out[idx] = 16'h7000; // Expected: large number (small is lost due to precision)
        idx++;

        // Test case 21: Large number + small subnormal (should equal large number with DAZ)
        // This TB is correct vals.

        test_set1[idx] = 16'h5A00; // Large number (~1.0e10)
        test_set2[idx] = 16'h0001; // Smallest subnormal
        expected_out[idx] = 16'h5A00; // Expected: large number
        idx++;


        // *****
        // 7. Cancellation Cases:
        // *****

        // Test case 22: Cancellation leading to zero (2.0 + (-2.0) = 0.0)
        // This TB is correct vals.

        // Warning!: RTL is currently failing this case!

        test_set1[idx] = 16'h4000;   // +2.0
        test_set2[idx] = 16'hC000;   // -2.0
        expected_out[idx] = POS_ZERO;
        idx++;

        // Test case 23: Cancellation with remainder (32.0 + (-31.5) = 0.5)
        // This TB is correct vals.

        test_set1[idx] = 16'h4200;  // 32.0
        test_set2[idx] = 16'hC1FC;  // -31.5
        expected_out[idx] = 16'h3F00; // Expected: 0.5
        idx++;
        
        // Test case 24: Mixed signs with larger magnitude negative (-2.0 + 1.0 = -1.0)
        // This TB is correct vals.

        test_set1[idx] = 16'hC000;  // -2.0
        test_set2[idx] = 16'h3F80;  // 1.0
        expected_out[idx] = 16'hBF80; // Expected: -1.0
        idx++;


        @(posedge tb_clk);
        tb_start = 0;

        // Test pattern: Continuous stream of instructions with all 14 test cases
        for(i = 0; i < idx; i++) begin
            @(posedge tb_clk);
            tb_start = 1'b0;
            tb_a = test_set1[i];
            tb_b = test_set2[i];
            tb_start = 1'b1;
            @(posedge tb_clk);
            tb_start = 1'b0;
            @(posedge tb_clk);
            
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
            //if (i == 1 || i == 6) begin // Test cases 2 and 7 (overflow cases)
            //    if (!tb_overflow)
            //        $display("WARNING: Expected overflow flag for test case %0d", i);
            //end
        end
        #CLK_PERIOD;
        $finish;
    end

endmodule
