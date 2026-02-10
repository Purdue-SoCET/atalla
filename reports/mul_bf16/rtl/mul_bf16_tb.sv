// testbench for bf16 multiplier 
// Made My Mixuan Pan 
// Last Modified: 2/8, 2026
// gtkwave waves.vcd --save=mac_debug.gtkw
// Command: verilator --binary -j 0 -Wall -Wno-fatal mul_bf16_tb.sv mul_bf16.sv -Imodules -Itestbench -Iinclude --hierarchical --trace; ./obj_dir/Vmul_bf16_tb; gtkwave ../waves/mul_bf16_waves.vcd --save=waves/mul_bf16_debug.gtkw 
`timescale 1ns/1ps
module mul_bf16_tb;
    logic clk;
    logic nRST;
    logic start;
    logic [15:0] a;
    logic [15:0] b;
    logic [15:0] result;
    logic done, unf, ovf;

    // Declare variables at module level for Verilator compatibility
    int fd;
    int fd_out;
    int scanned;
    int total;
    int errors;
    logic [15:0] a_in;
    logic [15:0] b_in;
    logic [15:0] exp_result;
    int incorrect_unf, incorrect_ovf, incorrect_nan, expect_zero, expect_inf, expect_subnormal; 
    int diff_1b; // the difference between expected and actual is 1 bit (actual should be round up to 1)

    // instantiate DUT
    mul_bf16 DUT(
        .clk(clk),
        .nRST(nRST),
        .start(start),
        .a(a),
        .b(b),
        .result(result),
        .done(done), 
        .mul_ovf(ovf),
        .mul_unf(unf) 
    );

    // Clock
    initial clk = 0;
    always #5 clk = ~clk;

    initial begin
        $display("mul_bf16 TB starting");
        nRST = 0;
        start = 0;
        a = 16'h0000;
        b = 16'h0000;
        total = 0;
        errors = 0;
        #20; 
        nRST = 1;
        incorrect_unf = 0;
        incorrect_ovf = 0;
        diff_1b = 0;

        // create VCD for waveform viewing
        $dumpfile("mul_bf16_waves.vcd");
        $dumpvars(0, DUT);

        // open generated test file (3-column format: a b result)
        fd = $fopen("random_bf16_mul_cases.txt", "r");
        if (fd == 0) begin
            $display("ERROR: cannot open random_bf16_mul_cases.txt");
            $finish;
        end

        // open output file for results
        fd_out = $fopen("bf16_test_results.txt", "w");
        if (fd_out == 0) begin
            $display("ERROR: cannot open bf16_test_results.txt for writing");
            $fclose(fd);
            $finish;
        end

        // Write header to output file
        $fwrite(fd_out, "# BF16 Multiplier Test Results\n");
        $fwrite(fd_out, "# Format: a b expected actual status\n\n");

        while (!$feof(fd)) begin
            scanned = $fscanf(fd, "%h %h %h\n", a_in, b_in, exp_result);
            if (scanned == 3) begin
                a = a_in;
                b = b_in;
                start = 1;
                @(posedge clk);
                start = 0;
                // give DUT one more clock cycle to present result
                @(posedge clk);
                // Check only the result
                if (result !== exp_result) begin
                    errors = errors + 1;
                    incorrect_unf += {31'b0, result == 16'h0000 | result == 16'h8000}; // the output is 0 but it shouldn't be
                    incorrect_ovf += {31'b0, result[14:0] == 15'h7f80}; // the output is inf but it shouldn't be
                    incorrect_nan += {31'b0, result[14:0] == 15'h7fc0}; // the output is nan but it shouldn't be
                    expect_zero += {31'b0, exp_result == 16'h0000 || exp_result == 16'h8000};
                    expect_inf += {31'b0, exp_result[14:0] == 15'h7f80};
                    expect_subnormal += {31'b0, exp_result[14:0] == 15'h0080}; // the expected result is subnormal, which is the case where we had some issues before
                    diff_1b += {31'b0, (result == exp_result - 1)}; // the result is off by 1 bit, which means it's a rounding issue that we might want to investigate further
                    // Write failure to output file
                    $fwrite(fd_out, "%04h %04h %04h %04h FAIL\n", 
                            a, b, exp_result, result);
                end 

                total = total + 1;
                if ((total % 100000) == 0) begin
                    $display("Processed %0d tests, errors=%0d", total, errors);
                    $display("  Incorrect unf: %0d | Incorrect ovf: %0d | Expect Subnormals: %0d", incorrect_unf, incorrect_ovf, expect_subnormal);
                end
            end
        end

        // Write summary to output file
        $fwrite(fd_out, "\n# ========== SUMMARY ==========\n");
        $fwrite(fd_out, "# Total tests: %0d\n", total);
        $fwrite(fd_out, "# Total errors: %0d\n", errors);
        $fwrite(fd_out, "# Pass rate: %0.2f%%\n", 100.0 * (total - errors) / total);

        $display("========== SUMMARY ==========");
        $display("Total tests: %0d", total);
        $display("Total errors: %0d", errors);
        $display("Total 1-bit differences: %0d", diff_1b);
        $display("Pass rate: %0.2f%%", 100.0 * (total - errors) / total);
        
        $fclose(fd);
        $fclose(fd_out);
        $display("Results written to bf16_test_results.txt");
        $finish;
    end
endmodule
