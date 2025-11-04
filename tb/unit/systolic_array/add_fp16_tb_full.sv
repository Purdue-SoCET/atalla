`timescale 1ns/1ps


// ./obj_dir/VMAC_unit_tb
// gtkwave waves.vcd --save=mac_debug.gtkw

// to run this: verilator --binary -j 0 -Wall -Wno-fatal mul_fp16_tb -Imodules -Itestbench -Iinclude --hierarchical --trace; ./obj_dir/Vmul_fp16_tb; gtkwave waves/add_fp16_waves.vcd --save=waves/add_fp16_debug.gtkw


/* verilator lint_off UNUSEDSIGNAL */
module add_fp16_tb_full;

    // Parameters
    localparam PERIOD = 2;

    // Testbench Signals
    logic tb_clk;
    logic tb_nrst;
    integer i;

    // tb_clk init
    always
    begin
        tb_clk = 1'b0;
        #(PERIOD/2.0);
        tb_clk = 1'b1;
        #(PERIOD/2.0);
    end
    
    logic [15:0] tb_a, tb_b;
    logic tb_start;
    logic [15:0] tb_result;
    logic tb_done;

    logic [15:0] exp;
    int casenum;
    string casename;
    logic done_testing;

    add_fp16 bob (.clk(tb_clk), .nRST(tb_nrst), .start(tb_start), .fp1_in(tb_a), .fp2_in(tb_b), .fp_out(tb_result));//, .output_ready(tb_done));

    // add_fp16 bob (.tb_clk(tb_tb_clk), .nRST(tb_nrst), .start(tb_start), .a(tb_a), .b(tb_b), .result(tb_result), .done(tb_done));

    logic [15:0] test_set1[9:0];
    logic [15:0] test_set2[9:0];
    logic [15:0] test_set3[9:0];

    task automatic test_case(
        input logic [15:0] a,
        input logic [15:0] b,
        input logic sub);
    begin

        @(negedge tb_clk);

        tb_start = 0;
        tb_a = a;
        tb_b = b;

        @(negedge tb_clk);

        tb_start = 1;
    end
    endtask //automatic

    task automatic check_case(
        input string casename,
        input logic [15:0] expected);
    begin
        if (tb_result !== expected) begin
            $display("Failed Test for %s: A=%h B=%h Got=%h Exp=%h", casename, tb_a, tb_b, tb_result, expected);
        end
        else begin
            $display("Passed %s | A=%h B=%h Got=%h Exp=%h", casename, tb_a, tb_b, tb_result, expected);
        end
    end
    endtask
    
    localparam logic [15:0] P_INF = 16'b0_11111_0000000000,
    N_INF   = 16'b1_11111_0000000000,
    NAN = 16'b0_11111_0100000000,
    P_ZERO = 16'b0_00000_0000000000,
    N_ZERO = 16'b1_00000_0000000000,
    ONE = 16'b0_01111_0000000000,
    TWO = 16'b0_10000_0000000000,
    MIN = 16'b0_00000_0000000001,
    MAX_FINITE= 16'b0_11110_1111111111;

    integer fd;                 // file descriptor
    string header;              // to skip first line
    string a_str, b_str, exp_str;
    int sub;
    logic [15:0] a, b, expected;


    // Test sequence

initial begin
        tb_nrst = '0;

    #(PERIOD);

    tb_nrst = 1;

    test_case(ONE, ONE, 0);
    exp = 16'b0_10000_0000000000;
    #(PERIOD);
    check_case("1 + 1 = 2", exp);
    #(PERIOD);

    test_case(16'b1_10000_1000000000, 16'b0_10000_0000000000, 0);
    exp = 16'b1_01111_0000000000;
    #(PERIOD);
    check_case("(-3) + 2 = -1", exp);
    #(PERIOD);

    // ---------------- Zeroes ----------------
    test_case(P_ZERO, P_ZERO, 0);
    exp = P_ZERO;
    #(PERIOD);
    check_case("+0 + +0", exp);
    #(PERIOD);

    test_case(P_ZERO, N_ZERO, 0);
    exp = P_ZERO;
    #(PERIOD);
    check_case("+0 + -0", exp);
    #(PERIOD);

    test_case(ONE, P_ZERO, 0);
    exp = ONE;
    #(PERIOD);
    check_case("+x + 0", exp);
    #(PERIOD);

    // ---------------- Infinities ----------------
    test_case(P_INF, ONE, 0);
    exp = P_INF;
    #(PERIOD);
    check_case("+Inf + finite", exp);
    #(PERIOD);

    test_case(P_INF, P_INF, 0);
    exp = P_INF;
    #(PERIOD);
    check_case("+Inf + +Inf", exp);
    #(PERIOD);

    test_case(N_INF, N_INF, 0);
    exp = N_INF;
    #(PERIOD);
    check_case("-Inf + -Inf", exp);
    #(PERIOD);

    test_case(P_INF, N_INF, 0);
    exp = NAN;
    #(PERIOD);
    check_case("+Inf + -Inf = NaN", exp);
    #(PERIOD);

    // ---------------- NaN ----------------
    test_case(NAN, ONE, 0);
    exp = NAN;
    #(PERIOD);
    check_case("NaN + 1 = NaN", exp);
    #(PERIOD);

    // ---------------- Subnormals ----------------
    test_case(MIN, ONE, 0);
    exp = ONE;
    #(PERIOD);
    check_case("subnormal + 1 ≈ 1", exp);
    #(PERIOD);

    test_case(MIN, MIN, 0);
    exp = P_ZERO; // changed to 0, cause of DAZ
    #(PERIOD);
    check_case("subnormal + subnormal", exp);
    #(PERIOD);

    test_case(TWO, MIN, 0);
    exp = TWO; // Doesn't change as DAZ means we treat subnormals as zero
    #(PERIOD);
    check_case("large_x + subnormal ≈ large_x", exp);
    #(PERIOD);

    // ---------------- Overflow / Underflow ----------------
    test_case(MAX_FINITE, MAX_FINITE, 0);
    exp = P_INF;
    #(PERIOD);
    check_case("overflow: max + max = +Inf", exp);
    #(PERIOD);

    test_case(16'b1_11110_1111111111, 16'b1_11110_1111111111, 0);
    exp = N_INF;
    #(PERIOD);
    check_case("overflow: -max + -max = -Inf", exp);
    #(PERIOD);

    // ---------------- Cancellation ----------------
    test_case(16'b0_10000_1000000000, 16'b1_10000_1000000000, 0);
    exp = P_ZERO;
    #(PERIOD);
    check_case("+x + (-x) = +0", exp);
    #(PERIOD);

    // ---------------- Sign checks ----------------
    test_case(16'b0_10000_0000000000, 16'b0_10000_0000000000, 0);
    exp = 16'b0_10001_0000000000;
    #(PERIOD);
    check_case("+a + +b = +", exp);
    #(PERIOD);

    test_case(16'b1_10000_0000000000, 16'b1_10000_0000000000, 0);
    exp = 16'b1_10001_0000000000;
    #(PERIOD);
    check_case("-a + -b = -", exp);
    #(PERIOD);
// end


// initial begin
    #10ns;

    fd = $fopen("tb/unit/systolic_array/adder_testcases.csv", "r");
    if (fd == 0) begin
        $fatal("ERROR: Could not open random_cases.csv");
    end
    else begin
        $display("Opened random_cases.csv for reading.");
    end

    // Skip header row ("a,b,sub,expected")
    void'($fgets(header, fd));

    // Read until end of file
    // Read format: hex_a,hex_b,sub,hex_expected
    while (!$feof(fd)) begin
        int ret;
        ret = $fscanf(fd, "%h,%h,%d,%h\n", a, b, sub, expected);
        if (ret != 4) begin
            $display("Skipping line (ret=%0d)", ret);
            continue;
        end

        // Apply to DUT
        @(negedge tb_clk);
        tb_start = 1;
        tb_a = a;
        tb_b = b;

        @(negedge tb_clk);
        tb_start = 0;
        #(PERIOD);

        // Compare result
        if (tb_result !== expected)
            $display("Fail: A=%h  B=%h  SUB=%0d → Got=%h  Exp=%h", a, b, sub, tb_result, expected);
        else
            $display("Pass: A=%h  B=%h  SUB=%0d → %h", a, b, sub, tb_result);
    end

    $fclose(fd);
    $finish;;
end

    
endmodule
