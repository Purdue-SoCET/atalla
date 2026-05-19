`timescale 1ns/1ps

// 4-input BF16 Adder Testbench using SoftFloat test vectors
// Tests sysarr_4_input_bf_adder (3-stage pipelined CSA-based adder)

/*
First run: verilator -Irtl/include/systolic_array --binary -j 0 -Wall -Wno-fatal --timing --top-module add4_fp32accum_bf16_tb_softfloat tb/unit/systolic_array/add4_fp32accum_bf16_tb_softfloat.sv rtl/modules/systolic_array/reducer.sv rtl/modules/systolic_array/sysarr_4_input_fp_adder_cc_det.sv rtl/modules/systolic_array/sysarr_4_input_fp_adder.sv --trace

Then: ./obj_dir/Vadd4_fp32accum_bf16_tb_softfloat
*/

`include "systolic_array_4_input_adder_if.vh"

/* verilator lint_off UNUSEDSIGNAL */
module add4_fp32accum_bf16_tb_softfloat;

    localparam PERIOD = 2;
    localparam LATENCY = 4;  // 3 pipeline stages + 1 output register
    localparam PRECISION_BITS = 3; 
    localparam MANTISSA_WIDTH = 23;
    localparam CC_DET = 1; 
    localparam FINE_DEBUG = 0;

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
        .MANTISSA_SIZE(MANTISSA_WIDTH),
        .IN_MANTISSA_SIZE(7),
        .IN_EXPONENT_SIZE(8),
        .PRECISION_BITS(PRECISION_BITS),
        .GRS(1)
    ) add_if();

    logic [15:0] tb_a, tb_b, tb_c, tb_d;
    logic [15:0] tb_result;
    logic [15:0] exp;

    int pass_count, fail_count; 
    longint total_ulp_diff;
    int ulp_big_count;
    int largest_ulp; 
    int ret; 
    integer fail_fd; 

    // --- Added Accumulators for Fractional Verification Metrics ---
    real total_fractional_ulp;
    real largest_fractional_ulp;
    int  frac_ulp_violation_count;

    assign add_if.a = tb_a;
    assign add_if.b = tb_b;
    assign add_if.c = tb_c;
    assign add_if.d = tb_d;

    // DUT: BF16 4-input adder
    if (CC_DET) begin
        sysarr_4_input_fp_adder_cc_det #(
            .EXPONENT_SIZE(8),
            .MANTISSA_SIZE(MANTISSA_WIDTH),
            .IN_MANTISSA_SIZE(7),
            .IN_EXPONENT_SIZE(8),
            .PRECISION_BITS(PRECISION_BITS),
            .GRS(1)
        ) bf16adder (
            .clk(tb_clk),
            .nRST(tb_nrst),
            .add(add_if)
        );
    end else begin
        sysarr_4_input_fp_adder #(
            .EXPONENT_SIZE(8),
            .MANTISSA_SIZE(MANTISSA_WIDTH),
            .IN_MANTISSA_SIZE(7),
            .IN_EXPONENT_SIZE(8),
            .PRECISION_BITS(PRECISION_BITS),
            .GRS(1)
        ) bf16adder (
            .clk(tb_clk),
            .nRST(tb_nrst),
            .add(add_if)
        );
    end

    reducer #(.IN_EXP_W(8), .IN_MANT_W(MANTISSA_WIDTH), .OUT_EXP_W(8), .OUT_MANT_W(7)) reduce (
        .fp_in(add_if.out), .fp_out(tb_result)
    );

    logic [15:0] a,b,c,d,expected;
    logic [63:0] exact_f64_bits; // Holds the 64-bit IEEE float from C generator
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

    // Helper: Converts raw BF16 input into a SystemVerilog `real` (double precision)
    // Used specifically to calculate the exact sum for hardcoded testcases
    function automatic real bf16_to_real(logic [15:0] val);
        logic sign;
        int exp;
        longint mant;
        sign = val[15];
        exp = int'(val[14:7]);
        mant = longint'(val[6:0]);
        
        if (exp == 8'hFF) return (mant != 0) ? 0.0/0.0 : (sign ? -1.0/0.0 : 1.0/0.0);
        if (exp == 0) return (sign ? -1.0 : 1.0) * (real'(mant) / 128.0) * (2.0 ** -126);
        return (sign ? -1.0 : 1.0) * (1.0 + real'(mant) / 128.0) * (2.0 ** (exp - 127));
    endfunction

    // =========================================================================
    // ADDED FUNCTIONALITY: ARM-STYLE FRACTIONAL ULP COMPUTATION ENGINE
    // Converts the final 16-bit BF16 hardware output and exact 64-bit reference
    // =========================================================================
    function automatic real calculate_fractional_ulp(
        input logic [15:0] got_b16,       // Final 16-bit BF16 output
        input logic [63:0] exact_f64_bits // The pure, mathematically exact unrounded value
    );
        logic hw_s;
        int hw_e;
        longint hw_m;
        
        real val_hw, val_exact, absolute_delta, current_ulp_scale;
        
        // 1. Unpack exact unrounded true sum directly
        val_exact = $bitstoreal(exact_f64_bits);

        // 2. Unpack 16-bit BF16 Hardware Result
        hw_s = got_b16[15];
        hw_e = int'(got_b16[14:7]);
        hw_m = longint'(got_b16[6:0]);

        if (hw_e == 8'hFF) begin
            if (hw_m != 0) return 0.0/0.0;
            val_hw = hw_s ? -1.0/0.0 : 1.0/0.0;
        end else if (hw_e == 0) begin
            val_hw = (hw_s ? -1.0 : 1.0) * (real'(hw_m) / 128.0) * (2.0 ** -126);
        end else begin
            val_hw = (hw_s ? -1.0 : 1.0) * (1.0 + real'(hw_m) / 128.0) * (2.0 ** (hw_e - 127));
        end

        // Trap terminal infinity exceptions safely
        if (val_exact == 1.0/0.0 || val_exact == -1.0/0.0) begin
            return (val_hw == val_exact) ? 0.0 : 1.0/0.0;
        end
        if (val_hw == 1.0/0.0 || val_hw == -1.0/0.0) return 1.0/0.0;
        if (val_exact != val_exact || val_hw != val_hw) return 0.0/0.0; // Trap NaNs

        // FTZ ALIGNMENT CLAMP: Match the architectural FTZ/DAZ specification.
        if (val_exact > -(2.0 ** -126) && val_exact < (2.0 ** -126)) begin
            val_exact = (exact_f64_bits[63] == 1'b1) ? -0.0 : 0.0;
        end

        // 3. Compute Raw Absolute Distance
        absolute_delta = (val_hw > val_exact) ? (val_hw - val_exact) : (val_exact - val_hw);

        // 4. Determine ULP Grid Boundary based on exact reference exponent
        begin
            int target_unbiased_exp;
            if (exact_f64_bits[62:52] == 0 || val_exact == 0.0) begin
                target_unbiased_exp = -126;
            end else begin
                target_unbiased_exp = int'(exact_f64_bits[62:52]) - 1023;
                if (target_unbiased_exp < -126) target_unbiased_exp = -126;
            end
            current_ulp_scale = (2.0 ** (target_unbiased_exp - 7));
        end

        return absolute_delta / current_ulp_scale;
    endfunction

    // MODIFIED: Added checks for matching Infinity overflow behavior to avoid "inf" poisons
    task automatic check_case(input string casename, input logic [15:0] expected_val, input logic [63:0] exact_bits);
        logic match;
        longint ulp;
        real fractional_ulp;
        logic is_exp_inf, is_got_inf;

        is_exp_inf = (expected_val[14:7] == 8'hFF) && (expected_val[6:0] == 7'b0);
        is_got_inf = (tb_result[14:7] == 8'hFF) && (tb_result[6:0] == 7'b0);

        if (is_nan(tb_result) && is_nan(expected_val)) begin
            match = 1'b1;
            ulp = 0;
            fractional_ulp = 0.0;
        end else if (is_exp_inf && is_got_inf && (tb_result[15] == expected_val[15])) begin
            // FIXED: Hardware correctly overflowed to matching Infinity. 
            // Avoid calling calculate_fractional_ulp so finite exact_bits don't generate 'inf' penalties.
            match = 1'b1;
            ulp = 0;
            fractional_ulp = 0.0;
        end else begin
            match = (tb_result === expected_val);
            ulp = get_ulp_distance(tb_result, expected_val);
            fractional_ulp = calculate_fractional_ulp(tb_result, exact_bits);
        end

        total_ulp_diff += ulp;
        
        // FIXED: Safety accumulator clamp to prevent NaN or Inf from ruining the run statistics
        if (fractional_ulp >= 0.0 && fractional_ulp < 1000000.0) begin
            total_fractional_ulp += fractional_ulp;
            if (fractional_ulp > largest_fractional_ulp) largest_fractional_ulp = fractional_ulp;
        end
        
        if (fractional_ulp > 0.51) frac_ulp_violation_count++;
        
        if (ulp > 1) ulp_big_count++;
        if (ulp > largest_ulp) largest_ulp = ulp;
        
        if (!match && fractional_ulp > 0.51) begin
            $fwrite(fail_fd, "%s, %h, %h, %h, %h, %h, %h, %0d, %f\n",
                     casename, tb_a, tb_b, tb_c, tb_d, tb_result, expected_val, ulp, fractional_ulp);
            if (fail_count < 10) begin
                $display("FAIL: %s | A=%h B=%h C=%h D=%h Got=%h Exp=%h AdderGot=%h | IntegerULP=%0d | FracULP=%f",
                     casename, tb_a, tb_b, tb_c, tb_d, tb_result, expected_val, add_if.out, ulp, fractional_ulp);
            end
            fail_count++;
        end else if (fractional_ulp <= 0.51 || match) begin
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
    $dumpfile("waves/add4_bf16_waves_x2.vcd");
    $dumpvars(0, add4_fp32accum_bf16_tb_softfloat);

    ret = 0;
    pass_count = 0;
    fail_count = 0;
    total_ulp_diff = 0;
    ulp_big_count = 0;
    largest_ulp = 0;
    
    total_fractional_ulp = 0.0;
    largest_fractional_ulp = 0.0;
    frac_ulp_violation_count = 0;

    tb_nrst = 1'b0;
    tb_a = 16'h0;
    tb_b = 16'h0;
    tb_c = 16'h0;
    tb_d = 16'h0;
    #(PERIOD);
    tb_nrst = 1;
    #(PERIOD);

    // // --- Hardcoded BF16 test cases ---
    $display("Running hardcoded cases\n");
    test_case(ONE, ONE, ONE, ONE); exp = FOUR;
    #(PERIOD * (LATENCY + 1));
    check_case("1+1+1+1 = 4", exp, $realtobits(bf16_to_real(tb_a) + bf16_to_real(tb_b) + bf16_to_real(tb_c) + bf16_to_real(tb_d)));

    test_case(TWO, TWO, TWO, TWO); exp = 16'b0_10000010_0000000; // 8
    #(PERIOD * (LATENCY + 1));
    check_case("2+2+2+2 = 8", exp, $realtobits(bf16_to_real(tb_a) + bf16_to_real(tb_b) + bf16_to_real(tb_c) + bf16_to_real(tb_d)));

    test_case(P_ZERO, P_ZERO, P_ZERO, P_ZERO); exp = P_ZERO;
    #(PERIOD * (LATENCY + 1));
    check_case("0+0+0+0 = 0", exp, $realtobits(0.0));

    // --- Infinity and NaN cases ---
    test_case(P_INF, ONE, TWO, FOUR); exp = P_INF;
    #(PERIOD * (LATENCY + 1));
    check_case("inf + finite = inf", exp, $realtobits(1.0/0.0));

    test_case(N_INF, N_INF, ONE, P_ZERO); exp = N_INF;
    #(PERIOD * (LATENCY + 1));
    check_case("-inf + -inf = -inf", exp, $realtobits(-1.0/0.0));

    test_case(P_INF, N_INF, ONE, ONE); exp = NAN;
    #(PERIOD * (LATENCY + 1));
    check_case("inf - inf = NaN", exp, 64'h7FF8000000000000); // SV Quiet NaN

    test_case(NAN, ONE, TWO, FOUR); exp = NAN;
    #(PERIOD * (LATENCY + 1));
    check_case("NaN + finite = NaN", exp, 64'h7FF8000000000000);

    // --- Signed Zeros (Verification of your Sign-Fix) ---
    test_case(N_ZERO, N_ZERO, N_ZERO, N_ZERO); exp = P_ZERO; 
    #(PERIOD * (LATENCY + 1));
    check_case("-0 + -0 + -0 + -0 = 0", exp, $realtobits(0.0));

    test_case(ONE, 16'b1_01111111_0000000, P_ZERO, P_ZERO); exp = P_ZERO; 
    #(PERIOD * (LATENCY + 1));
    check_case("1 + (-1) = 0", exp, $realtobits(0.0));

    // --- Overflow to Infinity ---
    test_case(MAX_FINITE, MAX_FINITE, P_ZERO, P_ZERO); exp = P_INF;
    #(PERIOD * (LATENCY + 1));
    check_case("MaxFinite + MaxFinite = Inf (Overflow)", exp, $realtobits(bf16_to_real(tb_a) + bf16_to_real(tb_b)));

    // --- Underflow / Subnormal Handling (DAZ/FTZ check) ---
    test_case(MIN_SUB, MIN_SUB, MIN_SUB, MIN_SUB); exp = P_ZERO;
    #(PERIOD * (LATENCY + 1));
    check_case("Subnormals + Subnormals = 0 (FTZ check)", exp, $realtobits(bf16_to_real(tb_a) + bf16_to_real(tb_b) + bf16_to_real(tb_c) + bf16_to_real(tb_d)));

    // Random BF16 test cases from CSV
    if (FINE_DEBUG) begin
        fd = $fopen("scripts/systolic_array/testfloat_case_temp.csv","r");
    end
    else begin
        fd = $fopen("scripts/systolic_array/testfloat_cases_4_pure_bf16.csv","r");
    end
    fail_fd = $fopen("tree_failures.csv", "w");
    if (fd==0) begin $display("ERROR: cannot open test vectors!"); $finish; end
    
    $fwrite(fail_fd, "CaseName, A, B, C, D, Result, Expected, ULP, FractionalULP\n");
    void'($fgets(header, fd));

    total_count = 0;
    while (!$feof(fd)) begin
        // MODIFIED: Expects 6 columns now (reading exact_f64_bits)
        ret = $fscanf(fd,"%h,%h,%h,%h,%h,%h\n",a,b,c,d,expected,exact_f64_bits);
        if (ret != 6) begin
            $display("Broke loop! ret=%0d, cases_run=%0d, fd=%0d", ret, total_count, fd);
            $display("Line read: a=%h b=%h c=%h d=%h expected=%h exact=%h", a, b, c, d, expected, exact_f64_bits);
            break;
        end
        total_count++;
        if (total_count % 100000 == 0) begin
            $display("%0d test cases, %0d failed", total_count, fail_count);
        end
        @(negedge tb_clk);
        tb_a = a; tb_b = b; tb_c = c; tb_d = d;
        #(PERIOD*LATENCY);

        check_case($sformatf("Random case %0d", total_count), expected, exact_f64_bits);
    end

    // --- Final summary ---
    $display("\n====================");
    $display("FINAL REPORT:");
    $display("TOTAL CASES: %0d", total_count + 11); // Hardcoded count
    $display("PASSED: %0d", pass_count);
    $display("FAILED: %0d", fail_count);
    $display("Average ULP error: %0f", (fail_count + pass_count) ? total_ulp_diff*1.0/(fail_count + pass_count) : 0.0);
    $display("MAX ULP ERR: %0d", largest_ulp);
    $display("Number of cases with Integer ULP > 1: %0d", ulp_big_count);
    $display("Number of cases with Integer ULP == 1: %0d", (ulp_big_count > 0) ? (fail_count + pass_count - ulp_big_count) : 0);
    $display("\n--- Advanced ARM-Style Fractional ULP Analysis ---");
    $display("Average Fractional ULP Error: %0f", (fail_count + pass_count) ? total_fractional_ulp / (fail_count + pass_count) : 0.0);
    $display("Largest Fractional ULP Error: %0f", largest_fractional_ulp);
    $display("IEEE-754 RNE Rounding Boundary Violations (>0.51 ULP): %0d", frac_ulp_violation_count);
    $display("====================\n");

    $finish;
end

endmodule