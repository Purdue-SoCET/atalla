`timescale 1ns/1ps
// adder_8b_tb.sv
// Exhaustive testbench for adder_8b used in BF16 multiplier exponent path.
// Rewritten to match DUT semantics:
//   - internal signed math uses (exp - 128)
//   - sum output uses (exp1 + exp2 + carry) - 127
//   - ovf/unf use two's-complement overflow detection on signed (exp-128) add
//   - underflow has DUT-specific gating: ((carry!=1) || (sum!=8'hFF))
//
// Made by: Mixuan Pan (rewritten by assistant per your request)
// Last Modified: 02/09/2026
//
// Example command: verilator --binary -j 0 -Wall -Wno-fatal adder_8b_tb.sv adder_8b.sv -Imodules -Itestbench -Iinclude --hierarchical --trace; ./obj_dir/Vadder_8b_tb; gtkwave ../waves/adder_8b_waves.vcd --save=waves/adder_8b_debug.gtkw 

module adder_8b_tb;
  logic        carry;
  logic [7:0]  exp1;
  logic [7:0]  exp2;
  logic [7:0]  sum;
  logic        ovf;
  logic        unf;

  // DUT
  adder_8b DUT (
    .carry(carry),
    .exp1(exp1),
    .exp2(exp2),
    .sum(sum),
    .ovf(ovf),
    .unf(unf)
  );

  // bookkeeping
  int f;
  int total;
  int errors;
  int ovf_mismatches;
  int unf_mismatches;
  int sum_mismatches;

  // expected
  logic [7:0] expected_sum;
  logic       expected_ovf;
  logic       expected_unf;

  // helper: build expected values exactly per DUT intent
  task automatic compute_expected(
    input  logic       in_carry,
    input  logic [7:0]  in_exp1,
    input  logic [7:0]  in_exp2,
    output logic [7:0]  out_sum,
    output logic        out_ovf,
    output logic        out_unf
  );
    // Signed representations used by DUT for overflow/underflow detection
    int signed e1;
    int signed e2;
    int signed esum;

    begin
      // Match DUT’s internal signed conversion:
      // r_exp = {1'b0, exp} - 9'b1000_0000  (i.e., exp - 128)
      e1 = {23'b0, $signed({1'b0, in_exp1})} - 128;
      e2 = {23'b0, $signed({1'b0, in_exp2})} - 128;
      esum = e1 + e2;

      // Match DUT output sum:
      // sum = (exp1 + exp2 + carry) - 127  (8-bit wrap)
      out_sum = (in_exp1 + in_exp2 + {7'b0, in_carry}) - 8'd127;

      // Two's-complement overflow detection on esum relative to operands:
      // ovf: two non-negative -> negative result
      // unf: two negative -> non-negative result (then DUT adds a gating condition)
      out_ovf = (esum < 0) && (e1 >= 0) && (e2 >= 0);

      // DUT underflow gating:
      // unf = ((carry != 1) || (sum != 8'hFF)) && (~r_sum[8] && r_exp1[8] && r_exp2[8]);
      // The sign-change underflow condition is: esum >= 0 with e1<0 and e2<0
      out_unf = (esum >= 0) && (e1 < 0) && (e2 < 0);
      if (!((in_carry != 1'b1) || (out_sum != 8'hFF))) begin
        out_unf = 1'b0;
      end
    end
  endtask

  initial begin
    $display("adder_8b TB starting (exhaustive)");

    carry = 0;
    exp1  = 8'h00;
    exp2  = 8'h00;

    total = 0;
    errors = 0;
    ovf_mismatches = 0;
    unf_mismatches = 0;
    sum_mismatches = 0;

    // waves
    $dumpfile("adder_8b_waves.vcd");
    $dumpvars(0, adder_8b_tb);
    $dumpvars(0, DUT);

    // error log
    f = $fopen("adder_8b_errors.txt", "w");
    if (f == 0) begin
      $display("Error: Could not open adder_8b_errors.txt for writing.");
      $finish;
    end

    $fwrite(f, "# 8b Adder (BF16 exponent path) Exhaustive TB Errors\n");
    $fwrite(f, "# Fields: carry exp1 exp2 | exp_sum_expected ovf_expected unf_expected | exp_sum_got ovf_got unf_got\n\n");

    for (int i = 0; i <= 1; i++) begin
      for (int j = 0; j <= 255; j++) begin
        for (int k = 0; k <= 255; k++) begin
          carry = i[0];
          exp1  = j[7:0];
          exp2  = k[7:0];

          #1; // settle comb

          compute_expected(carry, exp1, exp2, expected_sum, expected_ovf, expected_unf);

          // Compare
          if (sum !== expected_sum || ovf !== expected_ovf || unf !== expected_unf) begin
            errors++;

            if (sum !== expected_sum) sum_mismatches++;
            if (ovf !== expected_ovf) ovf_mismatches++;
            if (unf !== expected_unf) unf_mismatches++;

            $fwrite(f,
              "ERROR: carry=%0d exp1=%0d(0x%02h) exp2=%0d(0x%02h) | exp_sum_exp=%0d(0x%02h) ovf_exp=%0d unf_exp=%0d | exp_sum_got=%0d(0x%02h) ovf_got=%0d unf_got=%0d\n",
              carry, exp1, exp1, exp2, exp2,
              expected_sum, expected_sum, expected_ovf, expected_unf,
              sum, sum, ovf, unf
            );
          end

          total++;
          if ((total % 50000) == 0) begin
            $display("Processed %0d tests | errors=%0d (sum=%0d, ovf=%0d, unf=%0d)",
              total, errors, sum_mismatches, ovf_mismatches, unf_mismatches
            );
          end
        end
      end
    end

    // Summary
    $fwrite(f, "\n# ========== SUMMARY ==========\n");
    $fwrite(f, "# Total tests:      %0d\n", total);
    $fwrite(f, "# Total errors:     %0d\n", errors);
    $fwrite(f, "# Sum mismatches:   %0d\n", sum_mismatches);
    $fwrite(f, "# OVF mismatches:   %0d\n", ovf_mismatches);
    $fwrite(f, "# UNF mismatches:   %0d\n", unf_mismatches);
    $fwrite(f, "# Pass rate:        %.4f%%\n", (100.0 * (total - errors)) / total);

    $display("========== SUMMARY ==========");
    $display("Total tests:    %0d", total);
    $display("Total errors:   %0d", errors);
    $display("Sum mismatches: %0d", sum_mismatches);
    $display("OVF mismatches: %0d", ovf_mismatches);
    $display("UNF mismatches: %0d", unf_mismatches);
    $display("Pass rate:      %.4f%%", (100.0 * (total - errors)) / total);

    $fclose(f);
    $display("Results written to adder_8b_errors.txt");
    $finish;
  end
endmodule
