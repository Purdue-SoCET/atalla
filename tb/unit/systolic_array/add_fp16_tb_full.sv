`timescale 1ns/1ps

// FP16 Addition Testbench with DAZ/FTZ support
// Prerequisites: Generate test cases first:
//   python3 scripts/systolic_array/random_fpgen.py
// then u run verilator --binary -j 0 -Wall -Wno-fatal tb/unit/systolic_array/add_fp16_tb_full.sv rtl/modules/systolic_array/add_fp16.sv rtl/modules/systolic_array/left_shift.sv --trace
// Then run: ./obj_dir/Vadd_fp16_tb_full

module add_fp16_tb_full;

    localparam PERIOD = 2;

    logic tb_clk;
    logic tb_nrst;

    always begin
        tb_clk = 1'b0;
        #(PERIOD/2.0);
        tb_clk = 1'b1;
        #(PERIOD/2.0);
    end
    
    logic [15:0] tb_a, tb_b;
    logic tb_start, tb_sub;
    logic [15:0] tb_result;
    logic tb_done;
    logic [15:0] exp;
    logic [15:0] tb_b_adjusted;
    
    int pass_count, fail_count;

    // Handle subtraction by negating b
    assign tb_b_adjusted = tb_sub ? {~tb_b[15], tb_b[14:0]} : tb_b;

    add_fp16 dut (
        .clk(tb_clk), 
        .nRST(tb_nrst), 
        .start(tb_start), 
        .stall(1'b0),
        .fp1_in(tb_a), 
        .fp2_in(tb_b_adjusted), 
        .fp_out(tb_result), 
        .done(tb_done)
    );

    task automatic test_case(input logic [15:0] a, input logic [15:0] b, input logic is_sub);
        @(negedge tb_clk);
        tb_start = 0;
        tb_a = a;
        tb_b = b;
        tb_sub = is_sub;
        @(negedge tb_clk);
        tb_start = 1;
    endtask

    // Check if value is NaN (exp=0x1F, mant!=0)
    function automatic logic is_nan(input logic [15:0] val);
        return (val[14:10] == 5'b11111) && (val[9:0] != 10'b0);
    endfunction

    task automatic check_case(input string casename, input logic [15:0] expected);
        logic match;
        // NaN comparison: any NaN matches any NaN (ignore payload)
        if (is_nan(tb_result) && is_nan(expected)) begin
            match = 1'b1;
        end else begin
            match = (tb_result === expected);
        end
        
        if (!match) begin
            $display("Failed Test for %s: A=%h B=%h SUB=%b Got=%h Exp=%h", casename, tb_a, tb_b, tb_sub, tb_result, expected);
            fail_count++;
        end else begin
            $display("Passed %s | A=%h B=%h SUB=%b -> %h", casename, tb_a, tb_b, tb_sub, tb_result);
            pass_count++;
        end
    endtask
    
    localparam logic [15:0] P_INF      = 16'b0_11111_0000000000;
    localparam logic [15:0] N_INF      = 16'b1_11111_0000000000;
    localparam logic [15:0] NAN        = 16'b0_11111_0100000000;  // Quiet NaN
    localparam logic [15:0] P_ZERO     = 16'b0_00000_0000000000;
    localparam logic [15:0] N_ZERO     = 16'b1_00000_0000000000;
    localparam logic [15:0] ONE        = 16'b0_01111_0000000000;
    localparam logic [15:0] TWO        = 16'b0_10000_0000000000;
    localparam logic [15:0] MIN_SUB    = 16'b0_00000_0000000001;  // Smallest subnormal
    localparam logic [15:0] MAX_FINITE = 16'b0_11110_1111111111;

    integer fd;
    string header;
    string line;
    logic [15:0] a, b, expected;

initial begin
    pass_count = 0;
    fail_count = 0;
    tb_nrst = 1'b0;
    tb_start = 1'b0;
    tb_sub = 1'b0;
    tb_a = 16'h0;
    tb_b = 16'h0;

    #(PERIOD);
    tb_nrst = 1;
    #(PERIOD);

    $display("--- hardcoded addition cases ---");

    // Basic arithmetic
    test_case(ONE, ONE, 0);
    exp = TWO;
    #(PERIOD);
    check_case("1 + 1 = 2", exp);
    #(PERIOD);

    test_case(16'b1_10000_1000000000, 16'b0_10000_0000000000, 0);  // -3 + 2
    exp = 16'b1_01111_0000000000;  // -1
    #(PERIOD);
    check_case("(-3) + 2 = -1", exp);
    #(PERIOD);

    // Zero cases
    test_case(P_ZERO, P_ZERO, 0);
    exp = P_ZERO;
    #(PERIOD);
    check_case("+0 + +0 = +0", exp);
    #(PERIOD);

    test_case(P_ZERO, N_ZERO, 0);
    exp = P_ZERO;
    #(PERIOD);
    check_case("+0 + -0 = +0", exp);
    #(PERIOD);

    test_case(ONE, P_ZERO, 0);
    exp = ONE;
    #(PERIOD);
    check_case("1 + 0 = 1", exp);
    #(PERIOD);

    // Infinity cases
    test_case(P_INF, ONE, 0);
    exp = P_INF;
    #(PERIOD);
    check_case("+Inf + 1 = +Inf", exp);
    #(PERIOD);

    test_case(P_INF, P_INF, 0);
    exp = P_INF;
    #(PERIOD);
    check_case("+Inf + +Inf = +Inf", exp);
    #(PERIOD);

    test_case(N_INF, N_INF, 0);
    exp = N_INF;
    #(PERIOD);
    check_case("-Inf + -Inf = -Inf", exp);
    #(PERIOD);

    test_case(P_INF, N_INF, 0);
    exp = NAN;
    #(PERIOD);
    check_case("+Inf + -Inf = NaN", exp);
    #(PERIOD);

    // NaN propagation
    test_case(NAN, ONE, 0);
    exp = NAN;
    #(PERIOD);
    check_case("NaN + 1 = NaN", exp);
    #(PERIOD);

    // DAZ: Subnormal inputs flushed to zero
    test_case(MIN_SUB, ONE, 0);
    exp = ONE;  // DAZ: MIN_SUB -> 0, so 0 + 1 = 1
    #(PERIOD);
    check_case("subnormal + 1 = 1 (DAZ)", exp);
    #(PERIOD);

    test_case(MIN_SUB, MIN_SUB, 0);
    exp = P_ZERO;  // DAZ: both -> 0, so 0 + 0 = 0
    #(PERIOD);
    check_case("subnormal + subnormal = 0 (DAZ)", exp);
    #(PERIOD);

    test_case(TWO, MIN_SUB, 0);
    exp = TWO;  // DAZ: MIN_SUB -> 0, so 2 + 0 = 2
    #(PERIOD);
    check_case("2 + subnormal = 2 (DAZ)", exp);
    #(PERIOD);

    // Overflow to infinity
    test_case(MAX_FINITE, MAX_FINITE, 0);
    exp = P_INF;
    #(PERIOD);
    check_case("max + max = +Inf (overflow)", exp);
    #(PERIOD);

    test_case(16'b1_11110_1111111111, 16'b1_11110_1111111111, 0);  // -max + -max
    exp = N_INF;
    #(PERIOD);
    check_case("-max + -max = -Inf (overflow)", exp);
    #(PERIOD);

    // Exact cancellation
    test_case(16'b0_10000_1000000000, 16'b1_10000_1000000000, 0);  // 3 + (-3)
    exp = P_ZERO;
    #(PERIOD);
    check_case("x + (-x) = +0 (cancellation)", exp);
    #(PERIOD);

    // Sign preservation
    test_case(TWO, TWO, 0);
    exp = 16'b0_10001_0000000000;  // 4
    #(PERIOD);
    check_case("+2 + +2 = +4", exp);
    #(PERIOD);

    test_case(16'b1_10000_0000000000, 16'b1_10000_0000000000, 0);  // -2 + -2
    exp = 16'b1_10001_0000000000;  // -4
    #(PERIOD);
    check_case("-2 + -2 = -4", exp);
    #(PERIOD);

    $display("");
    $display("=== Manual Subtraction Test Cases ===");

    // Basic subtraction
    test_case(TWO, ONE, 1);  // 2 - 1
    exp = ONE;
    #(PERIOD);
    check_case("2 - 1 = 1", exp);
    #(PERIOD);

    test_case(ONE, TWO, 1);  // 1 - 2
    exp = 16'b1_01111_0000000000;  // -1
    #(PERIOD);
    check_case("1 - 2 = -1", exp);
    #(PERIOD);

    test_case(16'b0_10000_1000000000, 16'b0_10000_0000000000, 1);  // 3 - 2
    exp = ONE;
    #(PERIOD);
    check_case("3 - 2 = 1", exp);
    #(PERIOD);

    // Subtraction resulting in zero
    test_case(TWO, TWO, 1);  // 2 - 2
    exp = P_ZERO;
    #(PERIOD);
    check_case("2 - 2 = 0", exp);
    #(PERIOD);

    // Subtraction with infinity
    test_case(P_INF, ONE, 1);  // +Inf - 1
    exp = P_INF;
    #(PERIOD);
    check_case("+Inf - 1 = +Inf", exp);
    #(PERIOD);

    test_case(P_INF, P_INF, 1);  // +Inf - +Inf
    exp = NAN;
    #(PERIOD);
    check_case("+Inf - +Inf = NaN", exp);
    #(PERIOD);

    test_case(P_INF, N_INF, 1);  // +Inf - (-Inf) = +Inf + +Inf
    exp = P_INF;
    #(PERIOD);
    check_case("+Inf - -Inf = +Inf", exp);
    #(PERIOD);

    // Subtraction with NaN
    test_case(NAN, ONE, 1);
    exp = NAN;
    #(PERIOD);
    check_case("NaN - 1 = NaN", exp);
    #(PERIOD);

    $display("");
    $display("--- Random Test Cases from CSV ---");

    fd = $fopen("scripts/systolic_array/random_cases.csv", "r");
    if (fd == 0) begin
        $display("ERROR: Could not open scripts/systolic_array/random_cases.csv");
        $display("       Run: python3 scripts/systolic_array/random_fpgen.py");
        $finish;
    end

    // Skip header
    void'($fgets(header, fd));

    while (!$feof(fd)) begin
        int ret, sub_flag;
        logic is_zero_result;
        ret = $fscanf(fd, "%h,%h,%d,%h\n", a, b, sub_flag, expected);
        if (ret != 4) continue;

        @(negedge tb_clk);
        tb_start = 1;
        tb_a = a;
        tb_b = b;
        tb_sub = sub_flag;

        @(negedge tb_clk);
        tb_start = 0;
        #(PERIOD);

        // Check if both result and expected are zeros (either +0 or -0)
        is_zero_result = (tb_result == 16'h0000 || tb_result == 16'h8000) &&
                         (expected == 16'h0000 || expected == 16'h8000);

        // NaN-aware comparison, and accept +0/-0 equivalence
        if (is_nan(tb_result) && is_nan(expected)) begin
            pass_count++;
        end else if (is_zero_result) begin
            pass_count++;  // +0 and -0 are equivalent for our purposes
        end else if (tb_result !== expected) begin
            $display("FAIL: A=%h B=%h SUB=%d Got=%h Exp=%h", a, b, sub_flag, tb_result, expected);
            fail_count++;
        end else begin
            pass_count++;
        end
    end

    $fclose(fd);

    $display("");
    $display("=== Test Summary ===");
    $display("PASSED: %0d", pass_count);
    $display("FAILED: %0d", fail_count);
    
    if (fail_count == 0)
        $display("ALL TESTS PASSED!");
    else
        $display("SOME TESTS FAILED!");

    $finish;
end

endmodule
