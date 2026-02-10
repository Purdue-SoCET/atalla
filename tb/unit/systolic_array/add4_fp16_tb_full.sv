`timescale 1ns/1ps

// 4-input FP16 Addition Testbench with DAZ/FTZ support
// Run: verilator --binary -j 0 -Wall -Wno-fatal add4_fp16_tb_full.sv add4_fp16.sv add_fp16.sv left_shift.sv --trace
// Then: ./obj_dir/Vadd4_fp16_tb_full

/* verilator lint_off UNUSEDSIGNAL */
module add4_fp16_tb_full;

    localparam PERIOD = 2;

    logic tb_clk;
    logic tb_nrst;

    always begin
        tb_clk = 1'b0;
        #(PERIOD/2.0);
        tb_clk = 1'b1;
        #(PERIOD/2.0);
    end

    logic [15:0] tb_a, tb_b, tb_c, tb_d;
    logic tb_start;
    logic [15:0] tb_result;
    logic tb_done;
    logic [15:0] exp;

    int pass_count, fail_count;

    add4_fp16 dut (
        .clk(tb_clk),
        .nRST(tb_nrst),
        .start(tb_start),
        .stall(1'b0),
        .a(tb_a),
        .b(tb_b),
        .c(tb_c),
        .d(tb_d),
        .fp_out(tb_result),
        .done(tb_done)
    );

    task automatic test_case(input logic [15:0] a, input logic [15:0] b,
                             input logic [15:0] c, input logic [15:0] d);
        @(negedge tb_clk);
        tb_start = 0;
        tb_a = a;
        tb_b = b;
        tb_c = c;
        tb_d = d;
        @(negedge tb_clk);
        tb_start = 1;
    endtask

    function automatic logic is_nan(input logic [15:0] val);
        return (val[14:10] == 5'b11111) && (val[9:0] != 10'b0);
    endfunction

    task automatic check_case(input string casename, input logic [15:0] expected);
        logic match;
        if (is_nan(tb_result) && is_nan(expected)) begin
            match = 1'b1;
        end else begin
            match = (tb_result === expected);
        end

        if (!match) begin
            $display("Failed Test for %s: A=%h B=%h C=%h D=%h Got=%h Exp=%h",
                     casename, tb_a, tb_b, tb_c, tb_d, tb_result, expected);
            fail_count++;
        end else begin
            $display("Passed %s | A=%h B=%h C=%h D=%h -> %h",
                     casename, tb_a, tb_b, tb_c, tb_d, tb_result);
            pass_count++;
        end
    endtask

    localparam logic [15:0] P_INF      = 16'b0_11111_0000000000;
    localparam logic [15:0] N_INF      = 16'b1_11111_0000000000;
    localparam logic [15:0] NAN        = 16'b0_11111_0100000000;
    localparam logic [15:0] P_ZERO     = 16'b0_00000_0000000000;
    localparam logic [15:0] N_ZERO     = 16'b1_00000_0000000000;
    localparam logic [15:0] ONE        = 16'b0_01111_0000000000;
    localparam logic [15:0] TWO        = 16'b0_10000_0000000000;
    localparam logic [15:0] THREE      = 16'b0_10000_1000000000;
    localparam logic [15:0] FOUR       = 16'b0_10001_0000000000;
    localparam logic [15:0] MIN_SUB    = 16'b0_00000_0000000001;
    localparam logic [15:0] MAX_FINITE = 16'b0_11110_1111111111;

    integer fd;
    string header;
    logic [15:0] a, b, c, d, expected;

initial begin
    pass_count = 0;
    fail_count = 0;
    tb_nrst = 1'b0;
    tb_start = 1'b0;
    tb_a = 16'h0;
    tb_b = 16'h0;
    tb_c = 16'h0;
    tb_d = 16'h0;

    #(PERIOD);
    tb_nrst = 1;
    #(PERIOD);

    $display("--- Hardcoded 4-input Addition Cases ---");

    // Basic: 1+1+1+1 = 4
    test_case(ONE, ONE, ONE, ONE);
    exp = FOUR;
    #(PERIOD * 3);  // 2 cycles latency + margin
    check_case("1+1+1+1 = 4", exp);
    #(PERIOD);

    // 2+2+2+2 = 8
    test_case(TWO, TWO, TWO, TWO);
    exp = 16'b0_10010_0000000000;  // 8
    #(PERIOD * 3);
    check_case("2+2+2+2 = 8", exp);
    #(PERIOD);

    // Zero cases: 0+0+0+0 = 0
    test_case(P_ZERO, P_ZERO, P_ZERO, P_ZERO);
    exp = P_ZERO;
    #(PERIOD * 3);
    check_case("0+0+0+0 = 0", exp);
    #(PERIOD);

    // Mixed zeros: 1+0+0+0 = 1
    test_case(ONE, P_ZERO, P_ZERO, P_ZERO);
    exp = ONE;
    #(PERIOD * 3);
    check_case("1+0+0+0 = 1", exp);
    #(PERIOD);

    // Infinity: Inf+1+1+1 = Inf
    test_case(P_INF, ONE, ONE, ONE);
    exp = P_INF;
    #(PERIOD * 3);
    check_case("Inf+1+1+1 = Inf", exp);
    #(PERIOD);

    // Inf + Inf + 1 + 1 = Inf
    test_case(P_INF, P_INF, ONE, ONE);
    exp = P_INF;
    #(PERIOD * 3);
    check_case("Inf+Inf+1+1 = Inf", exp);
    #(PERIOD);

    // +Inf + -Inf in same branch = NaN propagates
    test_case(P_INF, N_INF, ONE, ONE);
    exp = NAN;
    #(PERIOD * 3);
    check_case("+Inf + -Inf + 1 + 1 = NaN", exp);
    #(PERIOD);

    // NaN propagation
    test_case(NAN, ONE, ONE, ONE);
    exp = NAN;
    #(PERIOD * 3);
    check_case("NaN+1+1+1 = NaN", exp);
    #(PERIOD);

    // DAZ: subnormal inputs flushed
    test_case(MIN_SUB, MIN_SUB, ONE, ONE);
    exp = TWO;  // DAZ: subnormals -> 0, so 0+0+1+1 = 2
    #(PERIOD * 3);
    check_case("sub+sub+1+1 = 2 (DAZ)", exp);
    #(PERIOD);

    // Overflow: max+max+max+max = Inf
    test_case(MAX_FINITE, MAX_FINITE, MAX_FINITE, MAX_FINITE);
    exp = P_INF;
    #(PERIOD * 3);
    check_case("max+max+max+max = Inf", exp);
    #(PERIOD);

    // Cancellation: 1 + (-1) + 1 + (-1) = 0
    test_case(ONE, 16'b1_01111_0000000000, ONE, 16'b1_01111_0000000000);
    exp = P_ZERO;
    #(PERIOD * 3);
    check_case("1+(-1)+1+(-1) = 0", exp);
    #(PERIOD);

    // Negative sum: -2 + -2 + -2 + -2 = -8
    test_case(16'b1_10000_0000000000, 16'b1_10000_0000000000,
              16'b1_10000_0000000000, 16'b1_10000_0000000000);
    exp = 16'b1_10010_0000000000;  // -8
    #(PERIOD * 3);
    check_case("-2+-2+-2+-2 = -8", exp);
    #(PERIOD);

    $display("");
    $display("--- Random Test Cases from CSV ---");

    fd = $fopen("scripts/systolic_array/random_cases_4.csv", "r");
    if (fd == 0) begin
        $display("ERROR: Could not open random_cases_4.csv - run: python3 random_fp16gen4.py");
        $finish;
    end

    // Skip header
    void'($fgets(header, fd));

    while (!$feof(fd)) begin
        int ret;
        logic is_zero_result;
        ret = $fscanf(fd, "%h,%h,%h,%h,%h\n", a, b, c, d, expected);
        if (ret != 5) continue;

        @(negedge tb_clk);
        tb_start = 1;
        tb_a = a;
        tb_b = b;
        tb_c = c;
        tb_d = d;

        @(negedge tb_clk);
        tb_start = 0;

        #(PERIOD * 2);  // Wait 2 cycles for result

        is_zero_result = (tb_result == 16'h0000 || tb_result == 16'h8000) &&
                         (expected == 16'h0000 || expected == 16'h8000);

        if (is_nan(tb_result) && is_nan(expected)) begin
            pass_count++;
        end else if (is_zero_result) begin
            pass_count++;
        end else if (tb_result !== expected) begin
            $display("FAIL: A=%h B=%h C=%h D=%h Got=%h Exp=%h", a, b, c, d, tb_result, expected);
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
