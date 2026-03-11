`timescale 1ns/1ps


// ./obj_dir/VMAC_unit_tb
// gtkwave waves.vcd --save=mac_debug.gtkw

/* verilator lint_off UNUSEDSIGNAL */
module add_bf16_1C_tb;

    // Parameters
    localparam CLK_PERIOD = 1;

    // Testbench Signals
    logic tb_clk;
    logic tb_nrst;
    integer i;

    // Clk init
    always
    begin
        tb_clk = 1'b0;
        #(CLK_PERIOD/2.0);
        tb_clk = 1'b1;
        #(CLK_PERIOD/2.0);
    end
    
    logic [15:0] tb_a, tb_b;
    logic tb_start;
    logic [15:0] tb_result;
    logic tb_done, roundup;
    logic tb_overflow, tb_underflow, tb_invalid;
    int incorrect_ovf, incorrect_unf, incorrect_nan, expect_unf, expect_nan, expect_ovf, expect_subnormal;
    int incorrect_round_up, incorrect_round_down; 
    

    add_bf16_1C DUT (
        .clk(tb_clk),
        .nRST(tb_nrst),
        .bf1(tb_a),
        .bf2(tb_b),
        .start(tb_start), 
        .stall(1'b0), 
        .bf_out(tb_result),
        .overflow(tb_overflow),
        .underflow(tb_underflow),
        .invalid(tb_invalid), 
        .done(tb_done)
    );

    // File-driven test variables
    int fd;
    int fd_out;
    int scanned;
    int total = 0;
    int errors = 0;
    logic [15:0] a_in;
    logic [15:0] b_in;
    logic [15:0] exp_result;
    int exp_ovf;
    int exp_unf;
    logic pass;
    logic [7:0] expect_exp; 
    logic [6:0] expect_mantissa; 

    // separate exponent and mantissa bits for debugging 
    assign expect_exp = exp_result[14:7]; 
    assign expect_mantissa = exp_result[6:0]; 

    // Test sequence - file-driven
    initial begin
        a_in = 0; 
        b_in = 0; 
        incorrect_ovf = 0;
        incorrect_unf = 0;
        incorrect_nan = 0;
        expect_unf = 0;
        expect_ovf = 0;
        expect_subnormal = 0;
        incorrect_round_up = 0; 
        incorrect_round_down = 0; 

        // Initialize interface signals
        $dumpfile("waves/add_bf16_1C_waves.vcd");
        $dumpvars(0, add_bf16_1C_tb);
        tb_nrst = 0;
        #CLK_PERIOD;
        tb_nrst = 1;

        // open generated test file (format: a b expected ovf unf)
        fd = $fopen("testcases/random_bf16_add_cases.txt", "r");
        if (fd == 0) begin
            $display("ERROR: cannot open random_bf16_add_cases.txt");
            $finish;
        end

        // open output file for results
        fd_out = $fopen("result_output/bf16_add_1C_test_results.txt", "w");
        if (fd_out == 0) begin
            $display("ERROR: cannot open bf16_add_test_results.txt for writing");
            $fclose(fd);
            $finish;
        end

        // Write header to output file
        $fwrite(fd_out, "# BF16 Adder Test Results\n");
        $fwrite(fd_out, "# Format: a b expected actual incorrect_roundup_cnt incorrect_rounddown_cnt\n\n");

        // Run through file
        while (!$feof(fd)) begin
            scanned = $fscanf(fd, "%h %h %h %d %d\n", a_in, b_in, exp_result, exp_ovf, exp_unf);
            if (scanned >= 3) begin
                // drive inputs
                tb_a = a_in;
                tb_b = b_in;
                tb_start = 1;
                @(posedge tb_clk);
                tb_start = 0;
                @(posedge tb_clk);

                // Compare results
                // pass = (tb_result === exp_result) && (tb_overflow == exp_ovf[0]) && (tb_underflow == exp_unf[0]);
                pass = tb_result === exp_result; // === operates X and Z bitwise as well 

                if (!pass) begin
                    errors = errors + 1;
                    // incorrect_ovf += tb_overflow != exp_ovf[0]; 
                    // incorrect_unf += tb_underflow != exp_unf[0];
                    incorrect_ovf += {31'b0, tb_result[14:0] == 15'h7f80};  
                    incorrect_unf = {31'b0, tb_result[14:0] == 15'h0}; 
                    incorrect_nan = {31'b0, tb_result[14:0] == 16'h7fc0}; 
                    expect_nan += {31'b0, exp_result[14:0] == 15'h7fc0}; 
                    expect_unf += (exp_result == 16'h0000) || (exp_result == 16'h8000);
                    expect_ovf += (exp_result == 16'h7F80) || (exp_result == 16'hFF80);
                    incorrect_round_up += {31'b0, roundup}; 
                    incorrect_round_down += {31'b0, ~roundup}; 
                    
                    $fwrite(fd_out, "%04h %04h %04h %04h %0d %0d FAIL\n", a_in, b_in, exp_result, tb_result, incorrect_round_up, incorrect_round_down);
                end

                total = total + 1;
                if ((total % 100000) == 0) begin
                    $display("Processed %0d tests, errors=%0d", total, errors);
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
        $display("Pass rate: %0.2f%%", 100.0 * (total - errors) / total);
        $display("Incorrect output nan: %0d, Expected output nan: %0d\n", incorrect_nan, expect_nan); 
        $display("Incorrect output unf: %0d, Expected output unf: %0d\n", incorrect_unf, expect_unf); 
        $display("Incorrect output ovf: %0d, Expected output ovf: %0d\n", incorrect_ovf, expect_ovf); 
        $display("Number of incoorect roundup: %d\n", incorrect_round_up); 
        $display("Number of incoorect rounddown: %d\n", incorrect_round_down); 

        $fclose(fd);
        $fclose(fd_out);
        $display("Results written to bf16_add_test_results.txt");
        $finish;
    end

endmodule
// necessary blank last line for tb 