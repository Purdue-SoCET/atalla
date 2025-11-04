`include "vreduction_alu_if.vh"
`include "vector_types.vh"

module vreduction_alu_tb;
    import vector_pkg::*;

    parameter PERIOD = 10;
    logic CLK = 0, nRST;

    always #(PERIOD/2) CLK++;

    vreduction_alu_if alu_if ();
    vreduction_alu DUT (.CLK(CLK), .nRST(nRST), .vraluif(alu_if));

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

    // ---------------- MIN cases ----------------
    casenum = 1;
    casename = "Min Case 1: Two Positive";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'h4000; // +2.0
    #(2*PERIOD); // Wait 2 cycles for result

    casenum = 2;
    casename = "Min Case 2: Two Negative";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'hBA00; // -0.75
    alu_if.value_b = 16'hC000; // -2.0
    #(2*PERIOD);

    casenum = 3;
    casename = "Min Case 3: Positive and Negative";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'hBA00; // -0.75
    #(2*PERIOD);

    casenum = 4;
    casename = "Min Case 4: Positive and Positive Infinity";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'h7C00; // +Inf
    #(2*PERIOD);

    casenum = 5;
    casename = "Min Case 5: Negative and Positive Infinity";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'hBA00; // -0.75
    alu_if.value_b = 16'h7C00; // +Inf
    #(2*PERIOD);

    casenum = 6;
    casename = "Min Case 6: Positive and Negative Infinity";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'hFC00; // -Inf
    #(2*PERIOD);

    casenum = 7;
    casename = "Min Case 7: Negative and Negative Infinity";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'hBA00; // -0.75
    alu_if.value_b = 16'hFC00; // -Inf
    #(2*PERIOD);

    casenum = 8;
    casename = "Min Case 8: Negative Infinity and Positive Infinity";
    alu_if.alu_op = VR_MIN;
    alu_if.value_a = 16'hFC00; // -Inf
    alu_if.value_b = 16'h7C00; // +Inf
    #(2*PERIOD);

    // ---------------- MAX cases ----------------
    casenum = 9;
    casename = "Max Case 1: Two Positive";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'h4000; // +2.0
    #(2*PERIOD);

    casenum = 10;
    casename = "Max Case 2: Two Negative";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'hBA00; // -0.75
    alu_if.value_b = 16'hC000; // -2.0
    #(2*PERIOD);

    casenum = 11;
    casename = "Max Case 3: Negative and Positive";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'hC000; // -2.0
    alu_if.value_b = 16'h3E00; // +1.5
    #(2*PERIOD);

    casenum = 12;
    casename = "Max Case 4: Positive and Positive Infinity";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'h7C00; // +Inf
    #(2*PERIOD);

    casenum = 13;
    casename = "Max Case 5: Negative and Positive Infinity";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'hBA00; // -0.75
    alu_if.value_b = 16'h7C00; // +Inf
    #(2*PERIOD);

    casenum = 14;
    casename = "Max Case 6: Positive and Negative Infinity";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'hFC00; // -Inf
    #(2*PERIOD);

    casenum = 15;
    casename = "Max Case 7: Negative and Negative Infinity";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'hBA00; // -0.75
    alu_if.value_b = 16'hFC00; // -Inf
    #(2*PERIOD);

    casenum = 16;
    casename = "Max Case 8: Positive Infinity and Negative Infinity";
    alu_if.alu_op = VR_MAX;
    alu_if.value_a = 16'h7C00; // +Inf
    alu_if.value_b = 16'hFC00; // -Inf
    #(2*PERIOD);

    // ---------------- SUM cases ----------------
    casenum = 17;
    casename = "Sum Case 1: Two Positive";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h3C00; // +1.0
    alu_if.value_b = 16'h4000; // +2.0
    #(2*PERIOD); // Expected: +3.0 (16'h4200)

    casenum = 18;
    casename = "Sum Case 2: Two Negative";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'hBC00; // -1.0
    alu_if.value_b = 16'hC000; // -2.0
    #(2*PERIOD); // Expected: -3.0 (16'hC200)

    casenum = 19;
    casename = "Sum Case 3: Positive and Negative (Result Positive)";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h4000; // +2.0
    alu_if.value_b = 16'hBC00; // -1.0
    #(2*PERIOD); // Expected: +1.0 (16'h3C00)

    casenum = 20;
    casename = "Sum Case 4: Positive and Negative (Result Negative)";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h3C00; // +1.0
    alu_if.value_b = 16'hC000; // -2.0
    #(2*PERIOD); // Expected: -1.0 (16'hBC00)

    casenum = 21;
    casename = "Sum Case 5: Zero and Positive";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h0000; // +0.0
    alu_if.value_b = 16'h3E00; // +1.5
    #(2*PERIOD); // Expected: +1.5 (16'h3E00)

    casenum = 22;
    casename = "Sum Case 6: Zero and Negative";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h0000; // +0.0
    alu_if.value_b = 16'hBE00; // -1.5
    #(2*PERIOD); // Expected: -1.5 (16'hBE00)

    casenum = 23;
    casename = "Sum Case 7: Positive and Positive Infinity";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h3E00; // +1.5
    alu_if.value_b = 16'h7C00; // +Inf
    #(2*PERIOD); // Expected: +Inf (16'h7C00)

    casenum = 24;
    casename = "Sum Case 8: Negative and Negative Infinity";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'hBA00; // -0.75
    alu_if.value_b = 16'hFC00; // -Inf
    #(2*PERIOD); // Expected: -Inf (16'hFC00)

    casenum = 25;
    casename = "Sum Case 9: Positive Infinity and Negative Infinity";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h7C00; // +Inf
    alu_if.value_b = 16'hFC00; // -Inf
    #(2*PERIOD); // Expected: NaN (16'h7E00 or similar)

    casenum = 26;
    casename = "Sum Case 10: Small Numbers";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h2800; // +0.0625 (2^-4)
    alu_if.value_b = 16'h2C00; // +0.125 (2^-3)
    #(2*PERIOD); // Expected: +0.1875 (16'h3000)

    casenum = 27;
    casename = "Sum Case 11: Values Cancelling to Zero";
    alu_if.alu_op = VR_SUM;
    alu_if.value_a = 16'h3C00; // +1.0
    alu_if.value_b = 16'hBC00; // -1.0
    #(2*PERIOD); // Expected: 0.0 (16'h0000)

    $stop;

end
endmodule