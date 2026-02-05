// testbench for bf16 multiplier 
// Made My Mixuan Pan 
// Last Mdified: 2/3, 2026
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
    int errors_result;
    int errors_ovf;
    int errors_unf;
    logic [15:0] a_in;
    logic [15:0] b_in;
    logic [15:0] exp_in;
    logic exp_ovf;
    logic exp_unf;
    
    // Move these to module level too
    logic result_mismatch;
    logic ovf_mismatch;
    logic unf_mismatch;
    logic any_mismatch;

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
        errors_result = 0;
        errors_ovf = 0;
        errors_unf = 0;
        #20; 
        nRST = 1;

        // create VCD for waveform viewing
        $dumpfile("mul_bf16_waves.vcd");
        $dumpvars(0, DUT);

        // open generated test file
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
        $fwrite(fd_out, "# Format: a b expected actual exp_ovf exp_unf got_ovf got_unf status\n");
        $fwrite(fd_out, "# Status: PASS/FAIL_RESULT/FAIL_OVF/FAIL_UNF/FAIL_MULTIPLE\n\n");

        while (!$feof(fd)) begin
            scanned = $fscanf(fd, "%h %h %h %d %d\n", a_in, b_in, exp_in, exp_ovf, exp_unf);
            if (scanned == 5) begin
                a = a_in;
                b = b_in;
                start = 1;
                @(posedge clk);
                start = 0;
                // give DUT one more clock cycle to present result
                @(posedge clk);

                // Check all three outputs (now using module-level variables)
                result_mismatch = (result !== exp_in);
                ovf_mismatch = (ovf !== exp_ovf);
                unf_mismatch = (unf !== exp_unf);
                any_mismatch = result_mismatch || ovf_mismatch || unf_mismatch;

                if (any_mismatch) begin
                    errors = errors + 1;
                    if (result_mismatch) errors_result = errors_result + 1;
                    if (ovf_mismatch) errors_ovf = errors_ovf + 1;
                    if (unf_mismatch) errors_unf = errors_unf + 1;
                    
                    // $display("Mismatch %0d: a=%04h b=%04h", total, a, b);
                    // if (result_mismatch)
                    //     $display("  Result: expected=%04h got=%04h", exp_in[15:0], result);
                    // if (ovf_mismatch)
                    //     $display("  Overflow: expected=%0d got=%0d", exp_ovf, ovf);
                    // if (unf_mismatch)
                    //     $display("  Underflow: expected=%0d got=%0d", exp_unf, unf);
                    
                    // Write failure to output file
                    $fwrite(fd_out, "%04h %04h %04h %04h %0d %0d %0d %0d FAIL", 
                            a, b, exp_in, result, exp_ovf, exp_unf, ovf, unf);
                    if (result_mismatch) $fwrite(fd_out, "_RESULT");
                    if (ovf_mismatch) $fwrite(fd_out, "_OVF");
                    if (unf_mismatch) $fwrite(fd_out, "_UNF");
                    $fwrite(fd_out, "\n");
                end

                total = total + 1;
                if ((total % 100000) == 0) begin
                    $display("Processed %0d tests, errors=%0d (result=%0d ovf=%0d unf=%0d)", 
                             total, errors, errors_result, errors_ovf, errors_unf);
                end
            end
        end

        // Write summary to output file
        $fwrite(fd_out, "\n# ========== SUMMARY ==========\n");
        $fwrite(fd_out, "# Total tests: %0d\n", total);
        $fwrite(fd_out, "# Total errors: %0d\n", errors);
        $fwrite(fd_out, "# Result errors: %0d\n", errors_result);
        $fwrite(fd_out, "# Overflow flag errors: %0d\n", errors_ovf);
        $fwrite(fd_out, "# Underflow flag errors: %0d\n", errors_unf);
        $fwrite(fd_out, "# Pass rate: %0.2f%%\n", 100.0 * (total - errors) / total);

        $display("Done: total=%0d errors=%0d", total, errors);
        $display("  Result errors: %0d", errors_result);
        $display("  Overflow errors: %0d", errors_ovf);
        $display("  Underflow errors: %0d", errors_unf);
        $fclose(fd);
        $fclose(fd_out);
        $display("Results written to bf16_test_results.txt");
        $finish;
    end

endmodule


// `timescale 1ns/1ps
// // to run the testbench: verilator --binary -j 0 -Wall -Wno-fatal mul_bf16_tb.sv mul_bf16.sv -Imodules -Itestbench -Iinclude --hierarchical --trace; ./obj_dir/Vmul_bf16_tb; gtkwave ../waves/mul_bf16_waves.vcd --save=waves/mul_bf16_debug.gtkw 
// module mul_bf16_tb;
//     logic clk;
//     logic nRST;
//     logic start;
//     logic [15:0] a;
//     logic [15:0] b;
//     logic [15:0] result;
//     logic done, unf, ovf;

//     // Declare variables at module level for Verilator compatibility
//     int fd;
//     int fd_out;
//     int scanned;
//     int total;
//     int errors;
//     int errors_result;
//     int errors_ovf;
//     int errors_unf;
//     logic [15:0] a_in;
//     logic [15:0] b_in;
//     logic [15:0] exp_in;
//     logic exp_ovf;
//     logic exp_unf;

//     // instantiate DUT (explicit port mapping for simulator compatibility)
//     mul_bf16 DUT(
//         .clk(clk),
//         .nRST(nRST),
//         .start(start),
//         .a(a),
//         .b(b),
//         .result(result),
//         .done(done), 
//         .mul_ovf(ovf),
//         .mul_unf(unf) 
//     );

//     // Clock
//     initial clk = 0;
//     always #5 clk = ~clk;

//     initial begin
//         $display("mul_bf16 TB starting");
//         nRST = 0;
//         start = 0;
//         a = 16'h0000;
//         b = 16'h0000;
//         total = 0;
//         errors = 0;
//         errors_result = 0;
//         errors_ovf = 0;
//         errors_unf = 0;
//         #20; 
//         nRST = 1;

//         // open generated test file
//         fd = $fopen("bf16_mul_3_row_test.txt", "r");
//         if (fd == 0) begin
//             $display("ERROR: cannot open bf16_mul_3_row_test.txt");
//             $finish;
//         end

//         // open output file for results
//         fd_out = $fopen("bf16_test_results.txt", "w");
//         if (fd_out == 0) begin
//             $display("ERROR: cannot open bf16_test_results.txt for writing");
//             $fclose(fd);
//             $finish;
//         end

//         // Write header to output file
//         $fwrite(fd_out, "# BF16 Multiplier Test Results\n");
//         $fwrite(fd_out, "# Format: a b expected actual exp_ovf exp_unf got_ovf got_unf status\n");
//         $fwrite(fd_out, "# Status: PASS/FAIL_RESULT/FAIL_OVF/FAIL_UNF/FAIL_MULTIPLE\n\n");

//         while (!$feof(fd)) begin
//             scanned = $fscanf(fd, "%h %h %h %d %d\n", a_in, b_in, exp_in, exp_ovf, exp_unf);
//             if (scanned == 5) begin
//                 a = a_in;
//                 b = b_in;
//                 start = 1;
//                 @(posedge clk);
//                 start = 0;
//                 // give DUT one more clock cycle to present result
//                 @(posedge clk);

//                 // Check all three outputs
//                 logic result_mismatch = (result !== exp_in);
//                 logic ovf_mismatch = (ovf !== exp_ovf);
//                 logic unf_mismatch = (unf !== exp_unf);
//                 logic any_mismatch = result_mismatch || ovf_mismatch || unf_mismatch;

//                 if (any_mismatch) begin
//                     errors = errors + 1;
//                     if (result_mismatch) errors_result = errors_result + 1;
//                     if (ovf_mismatch) errors_ovf = errors_ovf + 1;
//                     if (unf_mismatch) errors_unf = errors_unf + 1;
                    
//                     // $display("Mismatch %0d: a=%04h b=%04h", total, a, b);
//                     // if (result_mismatch)
//                     //     $display("  Result: expected=%04h got=%04h", exp_in[15:0], result);
//                     // if (ovf_mismatch)
//                     //     $display("  Overflow: expected=%0d got=%0d", exp_ovf, ovf);
//                     // if (unf_mismatch)
//                     //     $display("  Underflow: expected=%0d got=%0d", exp_unf, unf);
                    
//                     // Write failure to output file
//                     $fwrite(fd_out, "%04h %04h %04h %04h %0d %0d %0d %0d FAIL", 
//                             a, b, exp_in, result, exp_ovf, exp_unf, ovf, unf);
//                     if (result_mismatch) $fwrite(fd_out, "_RESULT");
//                     if (ovf_mismatch) $fwrite(fd_out, "_OVF");
//                     if (unf_mismatch) $fwrite(fd_out, "_UNF");
//                     $fwrite(fd_out, "\n");
//                 end

//                 total = total + 1;
//                 if ((total % 100000) == 0) begin
//                     $display("Processed %0d tests, errors=%0d (result=%0d ovf=%0d unf=%0d)", 
//                              total, errors, errors_result, errors_ovf, errors_unf);
//                 end
//             end
//         end

//         // Write summary to output file
//         $fwrite(fd_out, "\n# ========== SUMMARY ==========\n");
//         $fwrite(fd_out, "# Total tests: %0d\n", total);
//         $fwrite(fd_out, "# Total errors: %0d\n", errors);
//         $fwrite(fd_out, "# Result errors: %0d\n", errors_result);
//         $fwrite(fd_out, "# Overflow flag errors: %0d\n", errors_ovf);
//         $fwrite(fd_out, "# Underflow flag errors: %0d\n", errors_unf);
//         $fwrite(fd_out, "# Pass rate: %0.2f%%\n", 100.0 * (total - errors) / total);

//         $display("Done: total=%0d errors=%0d", total, errors);
//         $display("  Result errors: %0d", errors_result);
//         $display("  Overflow errors: %0d", errors_ovf);
//         $display("  Underflow errors: %0d", errors_unf);
//         $fclose(fd);
//         $fclose(fd_out);
//         $display("Results written to bf16_test_results.txt");
//         $finish;
//     end

// endmodule
