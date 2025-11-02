`include "vreduction_alu_if.vh"
`include "vector_types.vh"

module valu_tb;
    import vector_pkg::*;

    parameter PERIOD = 10;
    logic CLK = 0, nRST;

    always #(PERIOD/2) CLK++;

    vreduction_alu_if alu_if ();
    valu DUT (.CLK(CLK), .nRST(nRST), .vraluif(alu_if));

    int casenum;
    string casename;

initial begin
    casenum = 0;
    casename = "nRST";

    nRST = 'b0;

    #(PERIOD);

    nRST = 1;

    // Wait 2 cycles for pipeline to clear after reset
    #(2*PERIOD);

    // ---------------- SUM (Addition) cases ----------------
    casenum = 1;
    casename = "Sum Case 1: Two Positive";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h3C00; // +1.0
    alu_if.value_b = 16'h4000; // +2.0
    #(2*PERIOD); // Wait 2 cycles for result
    // Expected: +3.0 = 16'h4200

    casenum = 2;
    casename = "Sum Case 2: Positive and Negative";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h4200; // +3.0
    alu_if.value_b = 16'hC000; // -2.0
    #(2*PERIOD);
    // Expected: +1.0 = 16'h3C00

    casenum = 3;
    casename = "Sum Case 3: Two Negative";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'hBC00; // -1.0
    alu_if.value_b = 16'hC000; // -2.0
    #(2*PERIOD);
    // Expected: -3.0 = 16'hC200

    casenum = 4;
    casename = "Sum Case 4: Zero Result";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h3C00; // +1.0
    alu_if.value_b = 16'hBC00; // -1.0
    #(2*PERIOD);
    // Expected: 0.0 = 16'h0000

    casenum = 5;
    casename = "Sum Case 5: Positive and Positive Infinity";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'h7C00; // +Inf
    #(2*PERIOD);
    // Expected: +Inf = 16'h7C00

    casenum = 6;
    casename = "Sum Case 6: Positive Infinity and Negative Infinity";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h7C00; // +Inf
    alu_if.value_b = 16'hFC00; // -Inf
    #(2*PERIOD);
    // Expected: NaN = 16'h7D00

    // ---------------- SUB (Subtraction) cases ----------------
    casenum = 7;
    casename = "Sub Case 1: Positive - Positive (result positive)";
    alu_if.alu_op = VR_SUB;
    alu_if.value_a = 16'h4200; // +3.0
    alu_if.value_b = 16'h3C00; // +1.0
    #(2*PERIOD);
    // Expected: +2.0 = 16'h4000

    casenum = 8;
    casename = "Sub Case 2: Positive - Positive (result negative)";
    alu_if.alu_op = VR_SUB;
    alu_if.value_a = 16'h3C00; // +1.0
    alu_if.value_b = 16'h4000; // +2.0
    #(2*PERIOD);
    // Expected: -1.0 = 16'hBC00

    casenum = 9;
    casename = "Sub Case 3: Positive - Negative";
    alu_if.alu_op = VR_SUB;
    alu_if.value_a = 16'h3C00; // +1.0
    alu_if.value_b = 16'hC000; // -2.0
    #(2*PERIOD);
    // Expected: +3.0 = 16'h4200

    casenum = 10;
    casename = "Sub Case 4: Negative - Positive";
    alu_if.alu_op = VR_SUB;
    alu_if.value_a = 16'hBC00; // -1.0
    alu_if.value_b = 16'h4000; // +2.0
    #(2*PERIOD);
    // Expected: -3.0 = 16'hC200

    casenum = 11;
    casename = "Sub Case 5: Same Values";
    alu_if.alu_op = VR_SUB;
    alu_if.value_a = 16'h4000; // +2.0
    alu_if.value_b = 16'h4000; // +2.0
    #(2*PERIOD);
    // Expected: 0.0 = 16'h0000

    casenum = 12;
    casename = "Sub Case 6: Positive - Positive Infinity";
    alu_if.alu_op = VR_SUB;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'h7C00; // +Inf
    #(2*PERIOD);
    // Expected: -Inf = 16'hFC00

    casenum = 13;
    casename = "Sub Case 7: Positive Infinity - Positive Infinity";
    alu_if.alu_op = VR_SUB;
    alu_if.value_a = 16'h7C00; // +Inf
    alu_if.value_b = 16'h7C00; // +Inf
    #(2*PERIOD);
    // Expected: NaN = 16'h7D00

    // ---------------- MIN cases ----------------
    casenum = 14;
    casename = "Min Case 1: Two Positive";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'h4000; // +2.0
    #(2*PERIOD);
    // Expected: +1.5 = 16'h3E00

    casenum = 15;
    casename = "Min Case 2: Two Negative";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'hBA00; // -0.75
    alu_if.value_b = 16'hC000; // -2.0
    #(2*PERIOD);
    // Expected: -2.0 = 16'hC000

    casenum = 16;
    casename = "Min Case 3: Positive and Negative";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'hBA00; // -0.75
    #(2*PERIOD);
    // Expected: -0.75 = 16'hBA00

    casenum = 17;
    casename = "Min Case 4: Positive and Positive Infinity";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'h7C00; // +Inf
    #(2*PERIOD);
    // Expected: +1.5 = 16'h3E00

    casenum = 18;
    casename = "Min Case 5: Negative and Negative Infinity";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'hBA00; // -0.75
    alu_if.value_b = 16'hFC00; // -Inf
    #(2*PERIOD);
    // Expected: -Inf = 16'hFC00

    // ---------------- MAX cases ----------------
    casenum = 19;
    casename = "Max Case 1: Two Positive";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'h4000; // +2.0
    #(2*PERIOD);
    // Expected: +2.0 = 16'h4000

    casenum = 20;
    casename = "Max Case 2: Two Negative";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'hBA00; // -0.75
    alu_if.value_b = 16'hC000; // -2.0
    #(2*PERIOD);
    // Expected: -0.75 = 16'hBA00

    casenum = 21;
    casename = "Max Case 3: Negative and Positive";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'hC000; // -2.0
    alu_if.value_b = 16'h3E00; // +1.5
    #(2*PERIOD);
    // Expected: +1.5 = 16'h3E00

    casenum = 22;
    casename = "Max Case 4: Positive and Positive Infinity";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'h7C00; // +Inf
    #(2*PERIOD);
    // Expected: +Inf = 16'h7C00

    casenum = 23;
    casename = "Max Case 5: Negative Infinity and Positive";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'hFC00; // -Inf
    alu_if.value_b = 16'h3E00; // +1.5
    #(2*PERIOD);
    // Expected: +1.5 = 16'h3E00

    // ---------------- NaN Handling ----------------
    casenum = 24;
    casename = "NaN Case 1: NaN + Positive";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h7D00; // NaN
    alu_if.value_b = 16'h4000; // +2.0
    #(2*PERIOD);
    // Expected: NaN = 16'h7D00

    casenum = 25;
    casename = "NaN Case 2: Positive - NaN";
    alu_if.alu_op = VR_SUB;
    alu_if.value_a = 16'h4000; // +2.0
    alu_if.value_b = 16'h7D00; // NaN
    #(2*PERIOD);
    // Expected: NaN = 16'h7D00

    casenum = 26;
    casename = "NaN Case 3: NaN MIN Positive";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'h7D00; // NaN
    alu_if.value_b = 16'h4000; // +2.0
    #(2*PERIOD);
    // Expected: NaN = 16'h7D00

    $display("All test cases completed!");
    $stop;

end
endmodule