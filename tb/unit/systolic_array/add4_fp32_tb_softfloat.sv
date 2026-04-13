`timescale 1ns/1ps

// 4-input FP32 Adder Testbench using Berkeley SoftFloat test vectors
// Tests sysarr_4_input_fp_adder (3-stage pipelined CSA-based adder)
//
// updated w new cases !!
//
// how to gen test cases (or just dm Myles):
//   ./gen_testfloat4 -n 1000000 > testfloat_cases_4.csv    (ftz and daz)
//   ./gen_testfloat4 --no-daz > testfloat_cases_4.csv      (disable daz)
//   ./gen_testfloat4 --no-ftz > testfloat_cases_4.csv      (disable ftz)
// u can only use those commands if u clone soft float (shoot myles a dm if u want to compile new) 
// to run -> verilator -Irtl/include/systolic_array --binary -j 0 -Wall -Wno-fatal --timing --top-module add4_fp32_tb_softfloat tb/unit/systolic_array/add4_fp32_tb_softfloat.sv rtl/modules/systolic_array/sysarr_4_input_fp_adder.sv --trace

// to view waves -> gtkwave waves/add4_fp32_waves.vcd --save=waves/add4_fp32_debug.gtkw
// also creates file called test_failures.csv w all failed cases (input, exp, got)


`include "systolic_array_4_input_adder_if.vh"

/* verilator lint_off UNUSEDSIGNAL */
module add4_fp32_tb_softfloat;

    localparam PERIOD = 2;
    localparam LATENCY = 4;  // 3 pipeline stages + 1 output register
    localparam PRECISION_BITS = 3;
    localparam EXPONENT_SIZE = 8;
    localparam MANTISSA_SIZE = 23; 
    localparam GRS = 1; 

    logic tb_clk;
    logic tb_nrst;

    always begin
        tb_clk = 1'b0;
        #(PERIOD/2.0);
        tb_clk = 1'b1;
        #(PERIOD/2.0);
    end

    // interface
    systolic_array_4_input_adder_if #(
        .MANTISSA_SIZE(MANTISSA_SIZE),
        .EXPONENT_SIZE(EXPONENT_SIZE),
        .IN_MANTISSA_SIZE(MANTISSA_SIZE),
        .IN_EXPONENT_SIZE(EXPONENT_SIZE),
        .PRECISION_BITS(PRECISION_BITS),
        .GRS(GRS)
    ) add_if();

    logic [31:0] tb_a, tb_b, tb_c, tb_d;
    logic [31:0] tb_result;
    logic [31:0] exp;

    int pass_count, fail_count;
    real total_ulp_error;  
    int largest_ulp; 
    int total_count;

    // con testbench signals to interface
    assign add_if.a = tb_a;
    assign add_if.b = tb_b;
    assign add_if.c = tb_c;
    assign add_if.d = tb_d;
    assign tb_result = add_if.out;

    // DUT
    sysarr_4_input_fp_adder #(
        .MANTISSA_SIZE(MANTISSA_SIZE),
        .EXPONENT_SIZE(EXPONENT_SIZE),
        .IN_MANTISSA_SIZE(MANTISSA_SIZE),
        .IN_EXPONENT_SIZE(EXPONENT_SIZE),
        .PRECISION_BITS(PRECISION_BITS),
        .GRS(GRS)
    ) etchedfp4adder (
        .clk(tb_clk),
        .nRST(tb_nrst),
        .add(add_if)
    );

    function int get_ulp_err(logic [31:0] hw_bits, logic [31:0] ref_bits);
        // 1. Handle exact bit match
        if (hw_bits == ref_bits) return 0;

        // 2. Handle NaN: If either is NaN, ULP is undefined (return -1 or max int)
        // FP32 NaN: Exponent is all 1s (bits 30:23) and Mantissa is non-zero (bits 22:0)
        if ((hw_bits[30:23] == 8'hFF && hw_bits[22:0] != 0) || 
            (ref_bits[30:23] == 8'hFF && ref_bits[22:0] != 0)) begin
            return -1; 
        end

        // 3. Handle Sign: If signs differ, ULP distance is massive. 
        // Usually, you treat this as a functional failure.
        if (hw_bits[31] != ref_bits[31]) begin
            return 2147483647; // Max signed 32-bit int
        end

        // 4. Calculate ULP
        // For same-signed numbers, the ULP distance is just the 
        // integer difference of the bit patterns.
        if (hw_bits > ref_bits) 
            return int'(hw_bits - ref_bits);
        else 
            return int'(ref_bits - hw_bits);

    endfunction

    task automatic test_case(input logic [31:0] a, input logic [31:0] b, input logic [31:0] c, input logic [31:0] d);
        @(negedge tb_clk);
        tb_a = a;
        tb_b = b;
        tb_c = c;
        tb_d = d;
    endtask

    function automatic logic is_nan(input logic [31:0] val);
        return (val[30:23] == 8'b11111111) && (val[22:0] != 23'b0);
    endfunction

    task automatic check_case(input string casename, input logic [31:0] expected);
        logic match;
        if (is_nan(tb_result) && is_nan(expected)) begin
            match = 1'b1;
        end else begin
            match = (tb_result === expected);
        end

        if (!match) begin
            $display("failed test for %s: A=%h B=%h C=%h D=%h Got=%h Exp=%h",
                     casename, tb_a, tb_b, tb_c, tb_d, tb_result, expected);
            $fwrite(fail_fd, "%h,%h,%h,%h,%h,%h\n", tb_a, tb_b, tb_c, tb_d, expected, tb_result);
            fail_count++;
        end else begin
            $display("passed %s | A=%h B=%h C=%h D=%h -> %h",
                     casename, tb_a, tb_b, tb_c, tb_d, tb_result);
            pass_count++;
        end
    endtask

    localparam logic [31:0] P_INF      = 32'b0_11111111_00000000000000000000000;
    localparam logic [31:0] N_INF      = 32'b1_11111111_00000000000000000000000;
    localparam logic [31:0] NAN        = 32'b0_11111111_10000000000000000000000;
    localparam logic [31:0] P_ZERO     = 32'b0_00000000_00000000000000000000000;
    localparam logic [31:0] N_ZERO     = 32'b1_00000000_00000000000000000000000;
    localparam logic [31:0] ONE        = 32'b0_01111111_00000000000000000000000;
    localparam logic [31:0] TWO        = 32'b0_10000000_00000000000000000000000;
    localparam logic [31:0] THREE      = 32'b0_10000000_10000000000000000000000;
    localparam logic [31:0] FOUR       = 32'b0_10000001_00000000000000000000000;
    localparam logic [31:0] MIN_SUB    = 32'b0_00000000_00000000000000000000001;
    localparam logic [31:0] MAX_FINITE = 32'b0_11111110_11111111111111111111111;

    integer fd;
    integer fail_fd;
    string header;
    logic [31:0] a, b, c, d, expected;

initial begin
    // waveform stuff
    $dumpfile("waves/add4_fp32_waves.vcd");
    $dumpvars(0, add4_fp32_tb_softfloat);

    // failure file
    fail_fd = $fopen("test_failures_pure_fp32.csv", "w");
    $fwrite(fail_fd, "a,b,c,d,expected,got\n");

    pass_count = 0;
    fail_count = 0;
    total_ulp_error = 0; 
    tb_nrst = 1'b0;
    tb_a = 32'h0;
    tb_b = 32'h0;
    tb_c = 32'h0;
    tb_d = 32'h0;
    total_count = 0;

    #(PERIOD);
    tb_nrst = 1;
    #(PERIOD);

    $display("--- Hardcoded 4-input Addition Cases ---");

    // Basic: 1+1+1+1 = 4
    test_case(ONE, ONE, ONE, ONE);
    exp = FOUR;
    #(PERIOD * (LATENCY + 1));
    check_case("1+1+1+1 = 4", exp);
    #(PERIOD);

    // 2+2+2+2 = 8
    test_case(TWO, TWO, TWO, TWO);
    exp = 32'b0_10000010_00000000000000000000000;
    #(PERIOD * (LATENCY + 1));
    check_case("2+2+2+2 = 8", exp);
    #(PERIOD);

    // Zero cases: 0+0+0+0 = 0
    test_case(P_ZERO, P_ZERO, P_ZERO, P_ZERO);
    exp = P_ZERO;
    #(PERIOD * (LATENCY + 1));
    check_case("0+0+0+0 = 0", exp);
    #(PERIOD);

    // Mixed zeros: 1+0+0+0 = 1
    test_case(ONE, P_ZERO, P_ZERO, P_ZERO);
    exp = ONE;
    #(PERIOD * (LATENCY + 1));
    check_case("1+0+0+0 = 1", exp);
    #(PERIOD);

    // Infinity: Inf+1+1+1 = Inf
    test_case(P_INF, ONE, ONE, ONE);
    exp = P_INF;
    #(PERIOD * (LATENCY + 1));
    check_case("Inf+1+1+1 = Inf", exp);
    #(PERIOD);

    // Inf + Inf + 1 + 1 = Inf
    test_case(P_INF, P_INF, ONE, ONE);
    exp = P_INF;
    #(PERIOD * (LATENCY + 1));
    check_case("Inf+Inf+1+1 = Inf", exp);
    #(PERIOD);

    // +Inf + -Inf in same branch = NaN propagates
    test_case(P_INF, N_INF, ONE, ONE);
    exp = NAN;
    #(PERIOD * (LATENCY + 1));
    check_case("+Inf + -Inf + 1 + 1 = NaN", exp);
    #(PERIOD);

    // NaN propagation
    test_case(NAN, ONE, ONE, ONE);
    exp = NAN;
    #(PERIOD * (LATENCY + 1));
    check_case("NaN+1+1+1 = NaN", exp);
    #(PERIOD);

    // DAZ: subnormal inputs flushed
    test_case(MIN_SUB, MIN_SUB, ONE, ONE);
    exp = TWO;  // DAZ: subnormals -> 0, so 0+0+1+1 = 2
    #(PERIOD * (LATENCY + 1));
    check_case("sub+sub+1+1 = 2 (DAZ)", exp);
    #(PERIOD);

    // Overflow: max+max+max+max = Inf
    test_case(MAX_FINITE, MAX_FINITE, MAX_FINITE, MAX_FINITE);
    exp = P_INF;
    #(PERIOD * (LATENCY + 1));
    check_case("max+max+max+max = Inf", exp);
    #(PERIOD);

    // Cancellation: 1 + (-1) + 1 + (-1) = 0
    test_case(ONE, 32'b1_01111111_00000000000000000000000, ONE, 32'b1_01111111_00000000000000000000000);
    exp = P_ZERO;
    #(PERIOD * (LATENCY + 1));
    check_case("1+(-1)+1+(-1) = 0", exp);
    #(PERIOD);

    // Negative sum: -2 + -2 + -2 + -2 = -8
    test_case(32'b1_10000000_00000000000000000000000, 32'b1_10000000_00000000000000000000000,
              32'b1_10000000_00000000000000000000000, 32'b1_10000000_00000000000000000000000);
    exp = 32'b1_10000010_00000000000000000000000;
    #(PERIOD * (LATENCY + 1));
    check_case("-2+-2+-2+-2 = -8", exp);
    #(PERIOD);

    $display("");
    $display("--- Berkeley SoftFloat Random Test Cases ---");

    fd = $fopen("scripts/systolic_array/testfloat_cases_4_pure_fp32.csv", "r");
    if (fd == 0) begin
        $display("error: could not open testfloat_cases_4_pure.csv");
        $display("make sure it is in the right directory! check tb for pathing"); 
        $finish;
    end

    // skip header
    void'($fgets(header, fd));

    while (!$feof(fd)) begin
        int ret;
        logic is_zero_result;
        ret = $fscanf(fd, "%h,%h,%h,%h,%h\n", a, b, c, d, expected);
        if (ret != 5) continue;

        total_count++;

        @(negedge tb_clk);
        tb_a = a;
        tb_b = b;
        tb_c = c;
        tb_d = d;

        #(PERIOD * LATENCY);  // wait for pipeline latency lmk if this is right so i can edit it 

        // relaxation for zero 
        is_zero_result = (tb_result == 32'h00000000 || tb_result == 32'h80000000) &&
                         (expected == 32'h00000000 || expected == 32'h80000000);

        if (is_nan(tb_result) && is_nan(expected)) begin
            pass_count++;
        end else if (is_zero_result) begin
            pass_count++;
        end else if (tb_result !== expected) begin
            // log to fail file
            $fwrite(fail_fd, "%h,%h,%h,%h,%h,%h\n", a, b, c, d, expected, tb_result);
            fail_count++;
            total_ulp_error += get_ulp_err(tb_result, expected);
            if (get_ulp_err(tb_result, expected) > largest_ulp) begin
                largest_ulp = get_ulp_err(tb_result, expected);
            end
            // only print first 10 failures to terminal u can change if u want
            if (fail_count <= 10 || get_ulp_err(tb_result, expected) > 1000) begin
                $display("FAIL: A=%h B=%h C=%h D=%h | Got=%h Exp=%h, ULP Diff: %0d", 
                         a, b, c, d, tb_result, expected, get_ulp_err(tb_result, expected));
            end else if (fail_count == 11) begin
                $display("... (suppressing further terminal output, all failures logged to test_failures.csv) ...");
            end

        end else begin
            pass_count++;
        end

        // prog every 100k
        if (total_count % 100000 == 0)
            $display("progress: %0d tested (%0d pass, %0d fail)...", total_count, pass_count, fail_count);
    end

    $fclose(fd);
    $fclose(fail_fd);

    $display("");
    $display("=== test summary ===");
    $display("PRECISION BITS: %0d", PRECISION_BITS);
    $display("PASSED: %0d", pass_count);
    $display("FAILED: %0d", fail_count);
    $display("AVERAGE ULP ERROR: %f", total_ulp_error / total_count);
    $display("LARGEST ULP ERROR: %0d", largest_ulp);
    // $display("OFF-BY-TWO: %0d", off_by_two);
    // $display("OFF-BY-TWO-PLUS: %0d", off_by_five_plus);
    $display("failure cases logged to: test_failures_pure.csv");

    if (fail_count == 0)
        $display("ALL TESTS PASSED!");
    else
        $display("SOME TESTS FAILED!");

    $finish;
end

endmodule
