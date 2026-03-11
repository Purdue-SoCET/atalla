`timescale 1ns/1ps

// N-input FP16 Adder Testbench using Berkeley SoftFloat test vectors
// Tests sysarr_n_input_fp_adder (internal FP32 accum, reduced to FP16)
//
// how to gen test cases (or just dm Myles):
//   ./gen_testfloat4 -n 1000000 > testfloat_cases_4.csv    (ftz and daz)
//   ./gen_testfloat4 --no-daz > testfloat_cases_4.csv      (disable daz)
//   ./gen_testfloat4 --no-ftz > testfloat_cases_4.csv      (disable ftz)
//
// x verilator -Irtl/include/systolic_array  --binary -j 0 -Wall -Wno-fatal --timing --top-module addn_fp32accum_fp16_tb_softfloat tb/unit/systolic_array/addn_fp32accum_fp16_tb_softfloat.sv rtl/modules/systolic_array/reducer.sv  rtl/modules/systolic_array/sysarr_n_input_fp_adder.sv --trace

/* verilator lint_off UNUSEDSIGNAL */
module addn_fp32accum_fp16_tb_softfloat;

    localparam NUM_INPUTS       = 4; // Parameterized for N inputs
    localparam PERIOD           = 2;
    localparam LATENCY          = 4;  // 3 pipeline stages + 1 output register
    localparam MANTISSA_SIZE    = 23; // Internal Accum Mantissa Width
    localparam EXPONENT_SIZE    = 8;  // Internal Accum Exponent Width
    localparam IN_MANTISSA_SIZE = 10; // Input/Output Mantissa Width 
    localparam IN_EXPONENT_SIZE = 5;  // Input/Output Exponent Width
    localparam PRECISION_BITS   = 1;

    logic tb_clk;
    logic tb_nrst;

    always begin
        tb_clk = 1'b0;
        #(PERIOD/2.0);
        tb_clk = 1'b1;
        #(PERIOD/2.0);
    end

    // Array for N inputs, matching the 16-bit (1+5+10) width
    logic [NUM_INPUTS-1:0][15:0] tb_in_data;
    logic [31:0] tb_raw_out; // 32-bit intermediate from adder
    logic [15:0] tb_result;  // 16-bit final after reducer
    logic [15:0] exp;

    int pass_count, fail_count, off_by_one, off_by_two, off_by_five_plus, ulp_diff, ulp_big_count; 
    real total_ulp_diff; 

    // DUT Instantiation
    sysarr_n_input_fp_adder #(
        .NUM_INPUTS(NUM_INPUTS),
        .EXPONENT_SIZE(EXPONENT_SIZE),
        .MANTISSA_SIZE(MANTISSA_SIZE),
        .IN_MANTISSA_SIZE(IN_MANTISSA_SIZE),
        .IN_EXPONENT_SIZE(IN_EXPONENT_SIZE),
        .PRECISION_BITS(PRECISION_BITS)
    ) etchedfpNadder (
        .clk(tb_clk),
        .nRST(tb_nrst),
        .in_data(tb_in_data),
        .out_data(tb_raw_out)
    );

    reducer #(.IN_EXP_W(8), .IN_MANT_W(23), .OUT_EXP_W(5), .OUT_MANT_W(10)) reduce (
        .fp_in(tb_raw_out), .fp_out(tb_result)
    );

    task automatic test_case(input logic [15:0] a, input logic [15:0] b, input logic [15:0] c, input logic [15:0] d);
        @(negedge tb_clk);
        tb_in_data[0] = a;
        tb_in_data[1] = b;
        tb_in_data[2] = c;
        tb_in_data[3] = d;
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
            $display("failed test for %s: A=%h B=%h C=%h D=%h Got=%h Exp=%h",
                     casename, tb_in_data[0], tb_in_data[1], tb_in_data[2], tb_in_data[3], tb_result, expected);
            $fwrite(fail_fd, "%h,%h,%h,%h,%h,%h\n", tb_in_data[0], tb_in_data[1], tb_in_data[2], tb_in_data[3], expected, tb_result);
            fail_count++;
        end else begin
            $display("passed %s | A=%h B=%h C=%h D=%h -> %h",
                     casename, tb_in_data[0], tb_in_data[1], tb_in_data[2], tb_in_data[3], tb_result);
            pass_count++;
        end
    endtask

    function longint get_ulp_distance(logic [15:0] a, logic [15:0] b);
        longint int_a, int_b;

        // Convert bit pattern to a "continuous" integer scale
        int_a = (a[15]) ? (64'h7FFFFFFF - a[14:0]) : (64'h80000000 + a[14:0]);
        int_b = (b[15]) ? (64'h7FFFFFFF - b[14:0]) : (64'h80000000 + b[14:0]);

        if (int_a > int_b) return (int_a - int_b);
        else               return (int_b - int_a);
    endfunction

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
    integer fail_fd;
    string header;
    logic [15:0] a, b, c, d, expected;
    int total_count;

initial begin
    // waveform stuff
    $dumpfile("waves/addN_fp32accum_fp16_waves.vcd");
    $dumpvars(0, addN_fp32accum_fp16_tb_softfloat);

    // failure file
    fail_fd = $fopen("test_failures_pure_fp32accum_fp16.csv", "w");
    $fwrite(fail_fd, "a,b,c,d,expected,got\n");

    pass_count = 0;
    fail_count = 0;
    ulp_big_count = 0;
    total_ulp_diff = 0;
    total_count = 0;

    tb_nrst = 1'b0;
    for(int i=0; i<NUM_INPUTS; i++) tb_in_data[i] = 16'h0;

    #(PERIOD);
    tb_nrst = 1;
    #(PERIOD);

    $display("--- Hardcoded 4-input Addition Cases ---");

    test_case(ONE, ONE, ONE, ONE); exp = FOUR; #(PERIOD * (LATENCY + 1)); check_case("1+1+1+1 = 4", exp); #(PERIOD);
    test_case(TWO, TWO, TWO, TWO); exp = 16'b0100100000000000; #(PERIOD * (LATENCY + 1)); check_case("2+2+2+2 = 8", exp); #(PERIOD);
    test_case(P_ZERO, P_ZERO, P_ZERO, P_ZERO); exp = P_ZERO; #(PERIOD * (LATENCY + 1)); check_case("0+0+0+0 = 0", exp); #(PERIOD);
    test_case(ONE, P_ZERO, P_ZERO, P_ZERO); exp = ONE; #(PERIOD * (LATENCY + 1)); check_case("1+0+0+0 = 1", exp); #(PERIOD);
    test_case(P_INF, ONE, ONE, ONE); exp = P_INF; #(PERIOD * (LATENCY + 1)); check_case("Inf+1+1+1 = Inf", exp); #(PERIOD);
    test_case(P_INF, P_INF, ONE, ONE); exp = P_INF; #(PERIOD * (LATENCY + 1)); check_case("Inf+Inf+1+1 = Inf", exp); #(PERIOD);
    test_case(P_INF, N_INF, ONE, ONE); exp = NAN; #(PERIOD * (LATENCY + 1)); check_case("+Inf + -Inf + 1 + 1 = NaN", exp); #(PERIOD);
    test_case(NAN, ONE, ONE, ONE); exp = NAN; #(PERIOD * (LATENCY + 1)); check_case("NaN+1+1+1 = NaN", exp); #(PERIOD);
    test_case(MIN_SUB, MIN_SUB, ONE, ONE); exp = TWO; #(PERIOD * (LATENCY + 1)); check_case("sub+sub+1+1 = 2 (DAZ)", exp); #(PERIOD);
    test_case(MAX_FINITE, MAX_FINITE, MAX_FINITE, MAX_FINITE); exp = P_INF; #(PERIOD * (LATENCY + 1)); check_case("max+max+max+max = Inf", exp); #(PERIOD);
    test_case(ONE, 16'b1_01111_0000000000, ONE, 16'b1_01111_0000000000); exp = P_ZERO; #(PERIOD * (LATENCY + 1)); check_case("1+(-1)+1+(-1) = 0", exp); #(PERIOD);
    test_case(16'b1_10000_0000000000, 16'b1_10000_0000000000, 16'b1_10000_0000000000, 16'b1_10000_0000000000); exp = 16'b1100100000000000; #(PERIOD * (LATENCY + 1)); check_case("-2+-2+-2+-2 = -8", exp); #(PERIOD);

    $display("");
    $display("--- Berkeley SoftFloat Random Test Cases ---");

    fd = $fopen("scripts/systolic_array/testfloat_cases_4_pure_fp32accum_fp16.csv", "r");
    if (fd == 0) begin
        $display("error: could not open testfloat_cases_4_pure_fp32accum_fp16.csv");
        $display("make sure it is in the right directory! check tb for pathing"); 
        $finish;
    end

    void'($fgets(header, fd));

    while (!$feof(fd)) begin
        int ret;
        logic is_zero_result;
        ret = $fscanf(fd, "%h,%h,%h,%h,%h\n", a, b, c, d, expected);
        if (ret != 5) continue;

        total_count++;

        @(negedge tb_clk);
        tb_in_data[0] = a;
        tb_in_data[1] = b;
        tb_in_data[2] = c;
        tb_in_data[3] = d;

        #(PERIOD * LATENCY);  

        // Corrected zero check to compare against 16-bit zeros
        is_zero_result = (tb_result == 16'h0000 || tb_result == 16'h8000) &&
                         (expected == 16'h0000 || expected == 16'h8000);

        if (is_nan(tb_result) && is_nan(expected)) begin
            pass_count++;
        end else if (is_zero_result) begin
            pass_count++;
        end else if (tb_result !== expected) begin
            $fwrite(fail_fd, "%h,%h,%h,%h,%h,%h\n", a, b, c, d, expected, tb_result);
            fail_count++;
            
            if (fail_count <= 10) begin
                $display("FAIL: A=%h B=%h C=%h D=%h | Got_fp16=%h, Got_fp32=%h, Exp=%h", 
                         a, b, c, d, tb_result, tb_raw_out, expected);
            end else if (fail_count == 11) begin
                $display("... (suppressing further terminal output, all failures logged to test_failures.csv) ...");
            end

            ulp_diff = get_ulp_distance(tb_result, expected);
            total_ulp_diff += ulp_diff;
            
            if (ulp_diff >= 10 && ulp_big_count < 10) begin
                $display("FAIL: A=%h B=%h C=%h D=%h | Got_fp16=%h, Got_fp32=%h, Exp=%h", 
                         a, b, c, d, tb_result, tb_raw_out, expected);
                $display("ULP difference: %0d", ulp_diff);
                ulp_big_count++; 
            end
        end else begin
            pass_count++;
        end

        if (total_count % 100000 == 0)
            $display("progress: %0d tested (%0d pass, %0d fail)...", total_count, pass_count, fail_count);
    end

    $fclose(fd);
    $fclose(fail_fd);

    $display("");
    $display("=== test summary ===");
    $display("NUM_INPUTS: %0d", NUM_INPUTS);
    $display("PRECISION_BITS: %0d", PRECISION_BITS);
    $display("PASSED: %0d", pass_count);
    $display("FAILED: %0d", fail_count);
    $display("Average ULP difference: %f", total_ulp_diff / fail_count);
    $display("failure cases logged to: test_failures_pure_fp32accum_fp16.csv");

    if (fail_count == 0)
        $display("ALL TESTS PASSED!");
    else
        $display("SOME TESTS FAILED!");

    $finish;
end

endmodule
