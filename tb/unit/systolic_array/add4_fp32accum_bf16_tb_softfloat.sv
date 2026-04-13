`timescale 1ns/1ps

// 4-input BF16 Adder Testbench using SoftFloat test vectors
// Tests sysarr_4_input_bf_adder (3-stage pipelined CSA-based adder)

/*

First run: 

verilator -Irtl/include/systolic_array --binary -j 0 -Wall -Wno-fatal --timing --top-module add4_fp32accum_bf16_tb_softfloat tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv rtl/modules/systolic_array/reducer.sv rtl/modules/systolic_array/sysarr_4_input_fp_adder.sv --trace

Then: ./obj_dir/Vadd4_fp32accum_bf16_tb_softfloat

Modify sysarr_4_input_fp_adder to another 4 input adder, and change latency, to test different adder pipelines
*/

`include "systolic_array_4_input_adder_if.vh"

/* verilator lint_off UNUSEDSIGNAL */
module add4_fp32accum_bf16_tb_softfloat;

    localparam PERIOD = 2;
    localparam LATENCY = 4;  // 3 pipeline stages + 1 output register

    logic tb_clk;
    logic tb_nrst;

    always begin
        tb_clk = 1'b0;
        #(PERIOD/2.0);
        tb_clk = 1'b1;
        #(PERIOD/2.0);
    end

    // Interface
    systolic_array_4_input_adder_if #(
        .EXPONENT_SIZE(8),
        .MANTISSA_SIZE(26),
        .IN_MANTISSA_SIZE(7),
        .IN_EXPONENT_SIZE(8),
        .PRECISION_BITS(0),
        .GRS(0)
    ) add_if();

    logic [15:0] tb_a, tb_b, tb_c, tb_d;
    logic [15:0] tb_result;
    logic [15:0] exp;

    int pass_count, fail_count; 
    longint total_ulp_diff;
    int ulp_big_count;
    int largest_ulp; 

    assign add_if.a = tb_a;
    assign add_if.b = tb_b;
    assign add_if.c = tb_c;
    assign add_if.d = tb_d;

    // DUT: BF16 4-input adder
    sysarr_4_input_fp_adder #(
        .EXPONENT_SIZE(8),
        .MANTISSA_SIZE(26),
        .IN_MANTISSA_SIZE(7),
        .IN_EXPONENT_SIZE(8),
        .PRECISION_BITS(0),
        .GRS(0)
    ) bf16adder (
        .clk(tb_clk),
        .nRST(tb_nrst),
        .add(add_if)
    );

    reducer #(.IN_EXP_W(8), .IN_MANT_W(23), .OUT_EXP_W(8), .OUT_MANT_W(7)) reduce (
        .fp_in(add_if.out), .fp_out(tb_result)
    );

    logic [15:0] a,b,c,d,expected;
    integer fd, total_count;
    string header;

    task automatic test_case(input logic [15:0] a_in, input logic [15:0] b_in,
                             input logic [15:0] c_in, input logic [15:0] d_in);
        @(negedge tb_clk);
        tb_a = a_in;
        tb_b = b_in;
        tb_c = c_in;
        tb_d = d_in;
    endtask

    function automatic logic is_nan(input logic [15:0] val);
        return (val[14:7] == 8'b11111111) && (val[6:0] != 7'b0); // BF16 NaN
    endfunction

    function longint get_ulp_distance(logic [15:0] a, logic [15:0] b);
        longint int_a, int_b;
        int_a = (a[15]) ? (64'h7FFFFFFF - a[14:0]) : (64'h80000000 + a[14:0]);
        int_b = (b[15]) ? (64'h7FFFFFFF - b[14:0]) : (64'h80000000 + b[14:0]);
        return (int_a > int_b) ? (int_a - int_b) : (int_b - int_a);
    endfunction

    task automatic check_case(input string casename, input logic [15:0] expected_val);
        logic match;
        longint ulp;
        if (is_nan(tb_result) && is_nan(expected_val)) begin
            match = 1'b1;
            ulp = 0;
        end else begin
            match = (tb_result === expected_val);
            ulp = get_ulp_distance(tb_result, expected_val);
        end

        total_ulp_diff += ulp;
        if (ulp > 1) ulp_big_count++;
        if (ulp > largest_ulp) largest_ulp = ulp;
        if (!match) begin
            if (fail_count < 10) begin
                $display("FAIL: %s | A=%h B=%h C=%h D=%h Got=%h Exp=%h AdderGot=%h | ULP=%0d",
                     casename, tb_a, tb_b, tb_c, tb_d, tb_result, expected_val, add_if.out, ulp);
            end
            fail_count++;
        end else begin
            pass_count++;
        end
    endtask

    // BF16 Constants
    localparam logic [15:0] P_INF   = 16'b0_11111111_0000000;
    localparam logic [15:0] N_INF   = 16'b1_11111111_0000000;
    localparam logic [15:0] NAN     = 16'b0_11111111_1000000;
    localparam logic [15:0] P_ZERO  = 16'b0_00000000_0000000;
    localparam logic [15:0] N_ZERO  = 16'b1_00000000_0000000;
    localparam logic [15:0] ONE     = 16'b0_01111111_0000000;
    localparam logic [15:0] TWO     = 16'b0_10000000_0000000;
    localparam logic [15:0] FOUR    = 16'b0_10000001_0000000;
    localparam logic [15:0] MIN_SUB = 16'b0_00000000_0000001;
    localparam logic [15:0] MAX_FINITE = 16'b0_11111110_1111111;

initial begin
    $dumpfile("waves/add4_bf16_waves.vcd");
    $dumpvars(0, add4_bf16_tb_softfloat);

    pass_count = 0;
    fail_count = 0;
    total_ulp_diff = 0;
    ulp_big_count = 0;
    largest_ulp = 0;
    tb_nrst = 1'b0;
    tb_a = 16'h0;
    tb_b = 16'h0;
    tb_c = 16'h0;
    tb_d = 16'h0;
    #(PERIOD);
    tb_nrst = 1;
    #(PERIOD);

    // --- Hardcoded BF16 test cases ---
    test_case(ONE, ONE, ONE, ONE); exp = FOUR;
    #(PERIOD * (LATENCY + 1));
    check_case("1+1+1+1 = 4", exp);

    test_case(TWO, TWO, TWO, TWO); exp = 16'b0_10000010_0000000; // 8
    #(PERIOD * (LATENCY + 1));
    check_case("2+2+2+2 = 8", exp);

    test_case(P_ZERO, P_ZERO, P_ZERO, P_ZERO); exp = P_ZERO;
    #(PERIOD * (LATENCY + 1));
    check_case("0+0+0+0 = 0", exp);

    // --- Infinity and NaN cases ---
    test_case(P_INF, ONE, TWO, FOUR); exp = P_INF;
    #(PERIOD * (LATENCY + 1));
    check_case("inf + finite = inf", exp);

    test_case(N_INF, N_INF, ONE, P_ZERO); exp = N_INF;
    #(PERIOD * (LATENCY + 1));
    check_case("-inf + -inf = -inf", exp);

    test_case(P_INF, N_INF, ONE, ONE); exp = NAN;
    #(PERIOD * (LATENCY + 1));
    check_case("inf - inf = NaN", exp);

    test_case(NAN, ONE, TWO, FOUR); exp = NAN;
    #(PERIOD * (LATENCY + 1));
    check_case("NaN + finite = NaN", exp);

    // --- Signed Zeros (Verification of your Sign-Fix) ---
    test_case(N_ZERO, N_ZERO, N_ZERO, N_ZERO); exp = P_ZERO; // Assuming your fix to force +0
    #(PERIOD * (LATENCY + 1));
    check_case("-0 + -0 + -0 + -0 = 0", exp);

    test_case(ONE, 16'b1_01111111_0000000, P_ZERO, P_ZERO); exp = P_ZERO; 
    #(PERIOD * (LATENCY + 1));
    check_case("1 + (-1) = 0", exp);

    // --- Overflow to Infinity ---
    // Adding Max Finite values should trigger your (final_exp_calc >= MAX_EXP) logic
    test_case(MAX_FINITE, MAX_FINITE, P_ZERO, P_ZERO); exp = P_INF;
    #(PERIOD * (LATENCY + 1));
    check_case("MaxFinite + MaxFinite = Inf (Overflow)", exp);

    // --- Underflow / Subnormal Handling (DAZ/FTZ check) ---
    // If your hardware flushes subnormals, this should result in 0
    test_case(MIN_SUB, MIN_SUB, MIN_SUB, MIN_SUB); exp = P_ZERO;
    #(PERIOD * (LATENCY + 1));
    check_case("Subnormals + Subnormals = 0 (FTZ check)", exp);


    // --- Extreme Range: Max Finite Addition ---
    // MAX_FINITE + MAX_FINITE should result in P_INF (0x7f80)
    test_case(MAX_FINITE, MAX_FINITE, P_ZERO, P_ZERO); exp = P_INF;
    #(PERIOD * (LATENCY + 1));
    check_case("Overflow to Infinity", exp);

    // Random BF16 test cases from CSV
    fd = $fopen("scripts/systolic_array/testfloat_cases_4_pure_bf16.csv","r");
    if (fd==0) begin $display("ERROR: cannot open test vectors!"); $finish; end

    void'($fgets(header, fd));
    total_count = 0;
    while (!$feof(fd)) begin
        int ret = $fscanf(fd,"%h,%h,%h,%h,%h\n",a,b,c,d,expected);
        if (ret != 5) continue;
        total_count++;
        if (total_count % 100000 == 0) begin
            $display("%0d test cases, %0d failed", total_count, fail_count);
        end
        @(negedge tb_clk);
        tb_a = a; tb_b = b; tb_c = c; tb_d = d;
        #(PERIOD*LATENCY);

        check_case($sformatf("Random case %0d", total_count), expected);
    end

    // --- Final summary ---
    $display("\n====================");
    $display("TOTAL CASES: %0d", total_count + 12); // 3 hardcoded
    $display("PASS: %0d", pass_count);
    $display("FAIL: %0d", fail_count);
    $display("Average ULP error: %0f", (fail_count + pass_count) ? total_ulp_diff*1.0/(fail_count + pass_count) : 0.0);
    $display("Largest ULP error: %0d", largest_ulp);
    $display("Number of cases with ULP > 1: %0d", ulp_big_count);
    $display("====================\n");

    $finish;
end

endmodule
