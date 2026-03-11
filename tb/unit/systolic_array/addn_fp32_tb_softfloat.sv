`timescale 1ns/1ps

// N-input FP32 Adder Testbench using Berkeley SoftFloat test vectors
// Tests sysarr_n_input_fp_adder 
//
// how to gen test cases:
//   ./gen_testfloat4 -n 1000000 > testfloat_cases_4.csv    (ftz and daz)
//   ./gen_testfloat4 --no-daz > testfloat_cases_4.csv      (disable daz)
//   ./gen_testfloat4 --no-ftz > testfloat_cases_4.csv      (disable ftz)

/* verilator lint_off UNUSEDSIGNAL */
module addn_fp32_tb_softfloat;

    localparam NUM_INPUTS     = 4; // Parameterized for N inputs!
    localparam PERIOD         = 2;
    localparam LATENCY        = 4;  // 3 pipeline stages + 1 output register
    localparam PRECISION_BITS = 50;
    localparam EXPONENT_SIZE  = 8;
    localparam MANTISSA_SIZE  = 23; 
    // IN_MANTISSA/EXP size assumed to match standard FP32 for this TB
    localparam IN_MANTISSA_SIZE = 23; 
    localparam IN_EXPONENT_SIZE = 8;  

    logic tb_clk;
    logic tb_nrst;

    always begin
        tb_clk = 1'b0;
        #(PERIOD/2.0);
        tb_clk = 1'b1;
        #(PERIOD/2.0);
    end

    // Using a packed array for the N-input module instead of the old hardcoded interface
    logic [NUM_INPUTS-1:0][31:0] tb_in_data;
    logic [31:0] tb_result;
    logic [31:0] exp;

    int pass_count, fail_count, off_by_one, off_by_two, off_by_five_plus, diff; 

    // DUT Instantiation
    sysarr_n_input_fp_adder #(
        .NUM_INPUTS(NUM_INPUTS),
        .MANTISSA_SIZE(MANTISSA_SIZE),
        .EXPONENT_SIZE(EXPONENT_SIZE),
        .IN_MANTISSA_SIZE(IN_MANTISSA_SIZE),
        .IN_EXPONENT_SIZE(IN_EXPONENT_SIZE),
        .PRECISION_BITS(PRECISION_BITS)
    ) dut (
        .clk(tb_clk),
        .nRST(tb_nrst),
        .in_data(tb_in_data),
        .out_data(tb_result)
    );

    // Helper task to assign 4 inputs specifically for our current testfile setup
    task automatic test_case(input logic [31:0] a, input logic [31:0] b, input logic [31:0] c, input logic [31:0] d);
        @(negedge tb_clk);
        tb_in_data[0] = a;
        tb_in_data[1] = b;
        tb_in_data[2] = c;
        tb_in_data[3] = d;
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
                     casename, tb_in_data[0], tb_in_data[1], tb_in_data[2], tb_in_data[3], tb_result, expected);
            $fwrite(fail_fd, "%h,%h,%h,%h,%h,%h\n", tb_in_data[0], tb_in_data[1], tb_in_data[2], tb_in_data[3], expected, tb_result);
            fail_count++;
        end else begin
            $display("passed %s | A=%h B=%h C=%h D=%h -> %h",
                     casename, tb_in_data[0], tb_in_data[1], tb_in_data[2], tb_in_data[3], tb_result);
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
    int total_count;

initial begin
    // waveform stuff
    $dumpfile("waves/addN_fp32_waves.vcd");
    $dumpvars(0, addN_fp32_tb_softfloat);

    // failure file
    fail_fd = $fopen("test_failures_pure_fp32.csv", "w");
    $fwrite(fail_fd, "a,b,c,d,expected,got\n");

    pass_count = 0;
    fail_count = 0;
    off_by_one = 0; 
    off_by_two = 0; 
    off_by_five_plus = 0;
    total_count = 0;

    tb_nrst = 1'b0;
    for(int i=0; i<NUM_INPUTS; i++) tb_in_data[i] = 32'h0;

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
        $display("error: could not open testfloat_cases_4_pure_fp32.csv");
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
        tb_in_data[0] = a;
        tb_in_data[1] = b;
        tb_in_data[2] = c;
        tb_in_data[3] = d;

        #(PERIOD * LATENCY);  

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
            // only print first 10 failures to terminal
            if (fail_count <= 10) begin
                $display("FAIL: A=%h B=%h C=%h D=%h | Got=%h Exp=%h", 
                         a, b, c, d, tb_result, expected);
            end else if (fail_count == 11) begin
                $display("... (suppressing further terminal output, all failures logged to test_failures_pure_fp32.csv) ...");
            end

            diff = int'(tb_result) - int'(expected);
            // Check for off-by-one/two
            if ((diff == 1 || diff == -1)) begin
                off_by_one++;
            end else if ((diff == 2 || diff == -2)) begin
                off_by_two++;
            end
            else if (diff >= 2 || diff <= -2) begin
                off_by_five_plus++;
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
    $display("NUM_INPUTS: %0d", NUM_INPUTS);
    $display("PRECISION BITS: %0d", PRECISION_BITS);
    $display("PASSED: %0d", pass_count);
    $display("FAILED: %0d", fail_count);
    $display("OFF-BY-ONE: %0d", off_by_one);
    $display("OFF-BY-TWO: %0d", off_by_two);
    $display("OFF-BY-TWO-PLUS: %0d", off_by_five_plus);
    $display("failure cases logged to: test_failures_pure_fp32.csv");

    if (fail_count == 0)
        $display("ALL TESTS PASSED!");
    else
        $display("SOME TESTS FAILED!");

    $finish;
end

endmodule