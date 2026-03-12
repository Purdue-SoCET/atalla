`timescale 1ns/1ps

// 8-input FP16 Adder Testbench using Berkeley SoftFloat test vectors
// Tests sysarr_n_input_fp_adder (internal FP32 accum, reduced to FP16)
//
// how to gen test cases:
//   ./gen_testfloat8 -n 1000000 > testfloat_cases_8.csv    (ftz and daz)
//
// // verilator -Irtl/include/systolic_array  --binary -j 0 -Wall -Wno-fatal --timing --top-module addn_8_fp32accum_fp16_tb_softfloat tb/unit/systolic_array/addn_8_fp32accum_fp16_tb_softfloat.sv rtl/modules/systolic_array/reducer.sv  rtl/modules/systolic_array/sysarr_n_input_fp_adder.sv --trace

/* verilator lint_off UNUSEDSIGNAL */
module addn_8_fp32accum_fp16_tb_softfloat;

    localparam NUM_INPUTS       = 8; // Parameterized for 8 inputs
    localparam PERIOD           = 2;
    localparam LATENCY          = 7;  // 3 pipeline stages + 1 output register
    localparam MANTISSA_SIZE    = 23; // Internal Accum Mantissa Width
    localparam EXPONENT_SIZE    = 8;  // Internal Accum Exponent Width
    localparam IN_MANTISSA_SIZE = 23; // Input/Output Mantissa Width 
    localparam IN_EXPONENT_SIZE = 8;  // Input/Output Exponent Width
    localparam PRECISION_BITS   = 1;

    logic tb_clk;
    logic tb_nrst;

    always begin
        tb_clk = 1'b0;
        #(PERIOD/2.0);
        tb_clk = 1'b1;
        #(PERIOD/2.0);
    end

    // Array for 8 inputs, matching the 16-bit (1+5+10) width
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

    // Updated task to handle 8 inputs
    task automatic test_case(
        input logic [15:0] a, input logic [15:0] b, input logic [15:0] c, input logic [15:0] d,
        input logic [15:0] e, input logic [15:0] f, input logic [15:0] g, input logic [15:0] h
    );
        @(negedge tb_clk);
        tb_in_data[0] = a; tb_in_data[1] = b; tb_in_data[2] = c; tb_in_data[3] = d;
        tb_in_data[4] = e; tb_in_data[5] = f; tb_in_data[6] = g; tb_in_data[7] = h;
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
            $display("failed test for %s: Got=%h Exp=%h", casename, tb_result, expected);
            $fwrite(fail_fd, "%h,%h,%h,%h,%h,%h,%h,%h,%h,%h\n", 
                tb_in_data[0], tb_in_data[1], tb_in_data[2], tb_in_data[3], 
                tb_in_data[4], tb_in_data[5], tb_in_data[6], tb_in_data[7], 
                expected, tb_result);
            fail_count++;
        end else begin
            $display("passed %s -> %h", casename, tb_result);
            pass_count++;
        end
    endtask

    function longint get_ulp_distance(logic [15:0] a, logic [15:0] b);
        longint int_a, int_b;
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
    localparam logic [15:0] MIN_SUB    = 16'b0_00000_0000000001;
    localparam logic [15:0] MAX_FINITE = 16'b0_11110_1111111111;

    integer fd;
    integer fail_fd;
    string header;
    logic [15:0] a, b, c, d, e, f, g, h, expected;
    int total_count;

initial begin
    $dumpfile("waves/addn_8_fp32accum_fp16_waves.vcd");
    $dumpvars(0, addn_8_fp32accum_fp16_tb_softfloat);

    fail_fd = $fopen("test_failures_8_pure_fp32accum_fp16.csv", "w");
    $fwrite(fail_fd, "in0,in1,in2,in3,in4,in5,in6,in7,expected,got\n");

    pass_count = 0; fail_count = 0; ulp_big_count = 0;
    total_ulp_diff = 0; total_count = 0;

    tb_nrst = 1'b0;
    for(int i=0; i<NUM_INPUTS; i++) tb_in_data[i] = 16'h0;

    #(PERIOD); tb_nrst = 1; #(PERIOD);

    $display("--- Hardcoded 8-input Addition Cases ---");

    // 8 ones = 8
    test_case(ONE, ONE, ONE, ONE, ONE, ONE, ONE, ONE); 
    exp = 16'b0100100000000000; 
    #(PERIOD * (LATENCY + 1)); check_case("8 * 1.0 = 8.0", exp); #(PERIOD);

    // 8 zeros = 0
    test_case(P_ZERO, P_ZERO, P_ZERO, P_ZERO, P_ZERO, P_ZERO, P_ZERO, P_ZERO); 
    exp = P_ZERO; 
    #(PERIOD * (LATENCY + 1)); check_case("8 * 0.0 = 0.0", exp); #(PERIOD);

    // Cancel out: 4*(1) + 4*(-1) = 0
    test_case(ONE, ONE, ONE, ONE, 16'b1_01111_0000000000, 16'b1_01111_0000000000, 16'b1_01111_0000000000, 16'b1_01111_0000000000); 
    exp = P_ZERO; 
    #(PERIOD * (LATENCY + 1)); check_case("4*(1) + 4*(-1) = 0", exp); #(PERIOD);

    // Infinity + anything = Infinity
    test_case(P_INF, ONE, ONE, ONE, ONE, ONE, ONE, ONE); 
    exp = P_INF; 
    #(PERIOD * (LATENCY + 1)); check_case("Inf + 7*1 = Inf", exp); #(PERIOD);

    // Pos Inf + Neg Inf = NaN
    test_case(P_INF, N_INF, ONE, ONE, ONE, ONE, ONE, ONE); 
    exp = NAN; 
    #(PERIOD * (LATENCY + 1)); check_case("+Inf + -Inf + 6*1 = NaN", exp); #(PERIOD);

    $display("");
    $display("--- Berkeley SoftFloat Random Test Cases ---");

    fd = $fopen("scripts/systolic_array/testfloat_cases_8_pure_fp32accum_fp16.csv", "r");
    if (fd == 0) begin
        $display("error: could not open testfloat_cases_8_pure_fp32accum_fp16.csv");
        $display("make sure you generated an 8-input CSV!"); 
        $finish;
    end

    void'($fgets(header, fd));

    while (!$feof(fd)) begin
        int ret;
        logic is_zero_result;
        
        // Scan 8 inputs + 1 expected
        ret = $fscanf(fd, "%h,%h,%h,%h,%h,%h,%h,%h,%h\n", a, b, c, d, e, f, g, h, expected);
        if (ret != 9) continue;

        total_count++;

        @(negedge tb_clk);
        tb_in_data[0] = a; tb_in_data[1] = b; tb_in_data[2] = c; tb_in_data[3] = d;
        tb_in_data[4] = e; tb_in_data[5] = f; tb_in_data[6] = g; tb_in_data[7] = h;

        #(PERIOD * LATENCY);  

        is_zero_result = (tb_result == 16'h0000 || tb_result == 16'h8000) &&
                         (expected == 16'h0000 || expected == 16'h8000);

        if (is_nan(tb_result) && is_nan(expected)) begin
            pass_count++;
        end else if (is_zero_result) begin
            pass_count++;
        end else if (tb_result !== expected) begin
            $fwrite(fail_fd, "%h,%h,%h,%h,%h,%h,%h,%h,%h,%h\n", a, b, c, d, e, f, g, h, expected, tb_result);
            fail_count++;
            
            if (fail_count <= 10) begin
                $display("FAIL: Got_fp16=%h, Got_fp32=%h, Exp=%h", tb_result, tb_raw_out, expected);
            end else if (fail_count == 11) begin
                $display("... (suppressing terminal output) ...");
            end

            ulp_diff = get_ulp_distance(tb_result, expected);
            total_ulp_diff += ulp_diff;
            
            if (ulp_diff >= 10 && ulp_big_count < 10) begin
                $display("FAIL ULP>=10: Got_fp16=%h, Exp=%h | ULP diff: %0d", tb_result, expected, ulp_diff);
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
    $display("Average ULP difference: %f", total_ulp_diff / (fail_count > 0 ? fail_count : 1));
    
    if (fail_count == 0) $display("ALL TESTS PASSED!");
    else                 $display("SOME TESTS FAILED!");

    $finish;
end

endmodule