`timescale 1ns/1ps

// FP16 Multiplier Testbench using Berkeley SoftFloat test vectors
//
// Generate test cases:
//   ./gen_testfloat_mul -n 1000000 > testfloat_cases_mul.csv
//
// Build & run (Verilator):
//   command-verilator --binary --timing -j 0 -Wno-lint \
//       mul_fp16_tb_softfloat.sv mul_fp16_MAC.sv wallacetree_11b_2c.sv \
//       adder_5b.sv fa.sv ha.sv
//   ./obj_dir/Vmul_fp16_tb_softfloat

/* verilator lint_off UNUSEDSIGNAL */
module mul_fp16_tb_softfloat;

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
    logic tb_start;
    logic [15:0] tb_result;
    logic tb_done;
    logic [15:0] exp;

    int pass_count, fail_count;

    mul_fp16_MAC dut (
        .clk(tb_clk),
        .nRST(tb_nrst),
        .start(tb_start),
        .stall(1'b0),
        .a(tb_a),
        .b(tb_b),
        .result(tb_result),
        .done(tb_done)
    );

    function automatic logic is_nan(input logic [15:0] val);
        return (val[14:10] == 5'b11111) && (val[9:0] != 10'b0);
    endfunction

    function automatic logic is_zero(input logic [15:0] val);
        return (val[14:0] == 15'b0);
    endfunction

    task automatic check_case(input string casename, input logic [15:0] expected);
        logic match;
        if (is_nan(tb_result) && is_nan(expected))
            match = 1'b1;
        else if (is_zero(tb_result) && is_zero(expected))
            match = 1'b1;
        else
            match = (tb_result === expected);

        if (!match) begin
            $display("FAIL %s: A=%h B=%h Got=%h Exp=%h",
                     casename, tb_a, tb_b, tb_result, expected);
            fail_count++;
        end else begin
            $display("PASS %s | A=%h B=%h -> %h",
                     casename, tb_a, tb_b, tb_result);
            pass_count++;
        end
    endtask

    // Wait for done pulse from DUT
    task automatic wait_done();
        @(posedge tb_clk);
        while (!tb_done) @(posedge tb_clk);
    endtask

    localparam logic [15:0] P_INF      = 16'h7C00;
    localparam logic [15:0] N_INF      = 16'hFC00;
    localparam logic [15:0] NAN        = 16'h7E00;
    localparam logic [15:0] P_ZERO     = 16'h0000;
    localparam logic [15:0] N_ZERO     = 16'h8000;
    localparam logic [15:0] ONE        = 16'h3C00;
    localparam logic [15:0] N_ONE      = 16'hBC00;
    localparam logic [15:0] TWO        = 16'h4000;
    localparam logic [15:0] THREE      = 16'h4200;
    localparam logic [15:0] FOUR       = 16'h4400;
    localparam logic [15:0] HALF       = 16'h3800; // 0.5
    localparam logic [15:0] MIN_SUB    = 16'h0001;
    localparam logic [15:0] MAX_FINITE = 16'h7BFF;

    integer fd;
    string header;
    logic [15:0] a, b, expected;

initial begin
    pass_count = 0;
    fail_count = 0;
    tb_nrst = 1'b0;
    tb_start = 1'b0;
    tb_a = 16'h0;
    tb_b = 16'h0;

    #(PERIOD * 2);
    tb_nrst = 1;
    #(PERIOD * 2);

    $display("--- Hardcoded FP16 Multiply Cases ---");

    // 1 * 1 = 1
    @(negedge tb_clk); tb_a = ONE; tb_b = ONE; tb_start = 1;
    @(negedge tb_clk); tb_start = 0;
    wait_done();
    check_case("1*1=1", ONE);
    #(PERIOD);

    // 2 * 2 = 4
    @(negedge tb_clk); tb_a = TWO; tb_b = TWO; tb_start = 1;
    @(negedge tb_clk); tb_start = 0;
    wait_done();
    check_case("2*2=4", FOUR);
    #(PERIOD);

    // 2 * 0.5 = 1
    @(negedge tb_clk); tb_a = TWO; tb_b = HALF; tb_start = 1;
    @(negedge tb_clk); tb_start = 0;
    wait_done();
    check_case("2*0.5=1", ONE);
    #(PERIOD);

    // 0 * 1 = 0
    @(negedge tb_clk); tb_a = P_ZERO; tb_b = ONE; tb_start = 1;
    @(negedge tb_clk); tb_start = 0;
    wait_done();
    check_case("0*1=0", P_ZERO);
    #(PERIOD);

    // -1 * 1 = -1
    @(negedge tb_clk); tb_a = N_ONE; tb_b = ONE; tb_start = 1;
    @(negedge tb_clk); tb_start = 0;
    wait_done();
    check_case("-1*1=-1", N_ONE);
    #(PERIOD);

    // -1 * -1 = 1
    @(negedge tb_clk); tb_a = N_ONE; tb_b = N_ONE; tb_start = 1;
    @(negedge tb_clk); tb_start = 0;
    wait_done();
    check_case("-1*-1=1", ONE);
    #(PERIOD);

    // Inf * 2 = Inf
    @(negedge tb_clk); tb_a = P_INF; tb_b = TWO; tb_start = 1;
    @(negedge tb_clk); tb_start = 0;
    wait_done();
    check_case("Inf*2=Inf", P_INF);
    #(PERIOD);

    // Inf * 0 = NaN
    @(negedge tb_clk); tb_a = P_INF; tb_b = P_ZERO; tb_start = 1;
    @(negedge tb_clk); tb_start = 0;
    wait_done();
    check_case("Inf*0=NaN", NAN);
    #(PERIOD);

    // NaN * 1 = NaN
    @(negedge tb_clk); tb_a = NAN; tb_b = ONE; tb_start = 1;
    @(negedge tb_clk); tb_start = 0;
    wait_done();
    check_case("NaN*1=NaN", NAN);
    #(PERIOD);

    // max * max = Inf (overflow)
    @(negedge tb_clk); tb_a = MAX_FINITE; tb_b = MAX_FINITE; tb_start = 1;
    @(negedge tb_clk); tb_start = 0;
    wait_done();
    check_case("max*max=Inf", P_INF);
    #(PERIOD);

    // DAZ: subnormal * 1 = 0
    @(negedge tb_clk); tb_a = MIN_SUB; tb_b = ONE; tb_start = 1;
    @(negedge tb_clk); tb_start = 0;
    wait_done();
    check_case("sub*1=0 (DAZ)", P_ZERO);
    #(PERIOD);

    $display("");
    $display("--- Berkeley SoftFloat Random Multiply Cases ---");

    fd = $fopen("testfloat_cases_mul.csv", "r");
    if (fd == 0) begin
        $display("WARNING: Could not open testfloat_cases_mul.csv");
        $display("Build & run gen_testfloat_mul to generate test vectors.");
    end else begin
        void'($fgets(header, fd));

        while (!$feof(fd)) begin
            int ret;
            ret = $fscanf(fd, "%h,%h,%h\n", a, b, expected);
            if (ret != 3) continue;

            @(negedge tb_clk);
            tb_start = 1;
            tb_a = a;
            tb_b = b;

            @(negedge tb_clk);
            tb_start = 0;

            wait_done();

            if (is_nan(tb_result) && is_nan(expected)) begin
                pass_count++;
            end else if (is_zero(tb_result) && is_zero(expected)) begin
                pass_count++;
            end else if (tb_result !== expected) begin
                $display("FAIL: A=%h B=%h Got=%h Exp=%h", a, b, tb_result, expected);
                fail_count++;
            end else begin
                pass_count++;
            end
        end

        $fclose(fd);
    end

    $display("");
    $display("=== Multiply Test Summary ===");
    $display("PASSED: %0d", pass_count);
    $display("FAILED: %0d", fail_count);

    if (fail_count == 0)
        $display("ALL TESTS PASSED!");
    else
        $display("SOME TESTS FAILED!");

    $finish;
end

endmodule
