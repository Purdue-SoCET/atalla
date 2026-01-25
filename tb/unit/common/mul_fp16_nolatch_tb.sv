`timescale 1ns/1ps

// Direct testbench for mul_fp16_nolatch (combinational, no clock)
/* verilator lint_off UNUSEDSIGNAL */
module mul_fp16_nolatch_tb;

    logic [15:0] tb_a, tb_b;
    logic [15:0] tb_result;
    logic [15:0] exp;
    
    int pass_count, fail_count;

    mul_fp16_nolatch dut (
        .a(tb_a), 
        .b(tb_b), 
        .result(tb_result)
    );

    // Check if value is NaN (exp=0x1F, mant!=0)
    function automatic logic is_nan(input logic [15:0] val);
        return (val[14:10] == 5'b11111) && (val[9:0] != 10'b0);
    endfunction

    // Check if value is zero (+0 or -0)
    function automatic logic is_zero(input logic [15:0] val);
        return (val[14:0] == 15'b0);
    endfunction

    task automatic check_case(input string casename, input logic [15:0] expected);
        logic match;
        if (is_nan(tb_result) && is_nan(expected)) begin
            match = 1'b1;
        end else if (is_zero(tb_result) && is_zero(expected)) begin
            match = 1'b1;
        end else begin
            match = (tb_result === expected);
        end
        
        if (!match) begin
            $display("Failed Test for %s: A=%h B=%h Got=%h Exp=%h", casename, tb_a, tb_b, tb_result, expected);
            fail_count++;
        end else begin
            $display("Passed %s | A=%h B=%h -> %h", casename, tb_a, tb_b, tb_result);
            pass_count++;
        end
    endtask
    
    localparam logic [15:0] P_INF      = 16'b0_11111_0000000000;
    localparam logic [15:0] N_INF      = 16'b1_11111_0000000000;
    localparam logic [15:0] NAN        = 16'b0_11111_0100000000;
    localparam logic [15:0] P_ZERO     = 16'b0_00000_0000000000;
    localparam logic [15:0] N_ZERO     = 16'b1_00000_0000000000;
    localparam logic [15:0] ONE        = 16'b0_01111_0000000000;
    localparam logic [15:0] N_ONE      = 16'b1_01111_0000000000;
    localparam logic [15:0] TWO        = 16'b0_10000_0000000000;
    localparam logic [15:0] HALF       = 16'b0_01110_0000000000;
    localparam logic [15:0] MAX_FINITE = 16'b0_11110_1111111111;

    integer fd;
    string header;
    logic [15:0] a, b, expected;

initial begin
    pass_count = 0;
    fail_count = 0;

    $display("=== Nolatch Module Direct Test ===");
    $display("");
    $display("--- Basic Arithmetic ---");

    // 1 * 1 = 1
    tb_a = ONE; tb_b = ONE; #1;
    check_case("1 * 1 = 1", ONE);

    // 2 * 2 = 4
    tb_a = TWO; tb_b = TWO; #1;
    check_case("2 * 2 = 4", 16'b0_10001_0000000000);

    // 2 * 0.5 = 1
    tb_a = TWO; tb_b = HALF; #1;
    check_case("2 * 0.5 = 1", ONE);

    // (-1) * 1 = -1
    tb_a = N_ONE; tb_b = ONE; #1;
    check_case("(-1) * 1 = -1", N_ONE);

    // (-1) * (-1) = 1
    tb_a = N_ONE; tb_b = N_ONE; #1;
    check_case("(-1) * (-1) = 1", ONE);

    $display("");
    $display("--- Zero Cases ---");

    tb_a = P_ZERO; tb_b = P_ZERO; #1;
    check_case("+0 * +0 = +0", P_ZERO);

    tb_a = P_ZERO; tb_b = ONE; #1;
    check_case("+0 * 1 = +0", P_ZERO);

    tb_a = N_ZERO; tb_b = ONE; #1;
    check_case("-0 * 1 = -0", N_ZERO);

    $display("");
    $display("--- Infinity Cases ---");

    tb_a = P_INF; tb_b = ONE; #1;
    check_case("+Inf * 1 = +Inf", P_INF);

    tb_a = P_INF; tb_b = P_ZERO; #1;
    check_case("+Inf * 0 = NaN", NAN);

    $display("");
    $display("--- NaN Propagation ---");

    tb_a = NAN; tb_b = ONE; #1;
    check_case("NaN * 1 = NaN", NAN);

    $display("");
    $display("--- Overflow Cases ---");

    tb_a = MAX_FINITE; tb_b = TWO; #1;
    check_case("max * 2 = +Inf", P_INF);

    $display("");
    $display("=== Random Test Cases from CSV ===");

    fd = $fopen("random_mul_cases.csv", "r");
    if (fd == 0) begin
        $display("ERROR: Could not open random_mul_cases.csv");
        $finish;
    end

    void'($fgets(header, fd));

    while (!$feof(fd)) begin
        int ret;
        logic is_zero_result;
        ret = $fscanf(fd, "%h,%h,%h\n", a, b, expected);
        if (ret != 3) continue;

        tb_a = a;
        tb_b = b;
        #1;

        is_zero_result = is_zero(tb_result) && is_zero(expected);

        if (is_nan(tb_result) && is_nan(expected)) begin
            pass_count++;
        end else if (is_zero_result) begin
            pass_count++;
        end else if (tb_result !== expected) begin
            $display("FAIL: A=%h B=%h Got=%h Exp=%h", a, b, tb_result, expected);
            fail_count++;
        end else begin
            pass_count++;
        end
    end

    $fclose(fd);

    $display("PASSED: %0d", pass_count);
    $display("FAILED: %0d", fail_count);
    
    if (fail_count == 0)
        $display("ALL TESTS PASSED!");
    else
        $display("SOME TESTS FAILED!");

    $finish;
end

endmodule
