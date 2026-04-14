`timescale 1ns/1ps

/*
    32-Input BF16 Tree Testbench
    Architecture:
      - Stage 1: 8 x 4-input Adders (BF16 in, FP32 out)
      - Stage 2: 2 x 4-input Adders (FP32 in, FP32 out)
      - Stage 3: 1 x 4-input Adder  (FP32 in, FP32 out - 2 ports used)
      - Final: Reducer (FP32 to BF16)
*/

/* Test: verilator -Irtl/include/systolic_array --binary -j 0 -Wall -Wno-fatal --timing --top-module add32_fp32accum_bf16_tb_softfloat tb/unit/systolic_array/add32_fp32accum_bf16_tb_softfloat.sv rtl/modules/systolic_array/reducer.sv rtl/modules/systolic_array/sysarr_4_input_fp_adder.sv --trace */

`include "systolic_array_4_input_adder_if.vh"

module add32_fp32accum_bf16_tb_softfloat;

    // --- Timing and Precision Params ---
    localparam PERIOD = 2;
    // S1(3) + S2(3) + S3(3) + Reducer(1) = 10
    localparam LATENCY = 10; 
    localparam GRS = 1;
    localparam PRECISION_BITS = 3;

    localparam MANTISSA_SIZE = 23;

    logic tb_clk;
    logic tb_nrst;

    // Clock Generation
    always begin
        tb_clk = 1'b0;
        #(PERIOD/2.0);
        tb_clk = 1'b1;
        #(PERIOD/2.0);
    end

    // --- Signals and Interfaces ---
    logic [15:0] inputs [31:0];
    logic [15:0] tb_result;
    logic [15:0] exp;

    // Diagnostics
    int pass_count, fail_count; 
    longint total_ulp_diff;
    int ulp_big_count;
    int largest_ulp; 
    integer fail_fd;
    
    // Internal Tree Interfaces
    systolic_array_4_input_adder_if #(.EXPONENT_SIZE(8), .MANTISSA_SIZE(MANTISSA_SIZE), .IN_MANTISSA_SIZE(7), .IN_EXPONENT_SIZE(8)) stage1_if [7:0] ();
    systolic_array_4_input_adder_if #(.EXPONENT_SIZE(8), .MANTISSA_SIZE(MANTISSA_SIZE), .IN_MANTISSA_SIZE(MANTISSA_SIZE), .IN_EXPONENT_SIZE(8)) stage2_if [1:0] ();
    systolic_array_4_input_adder_if #(.EXPONENT_SIZE(8), .MANTISSA_SIZE(MANTISSA_SIZE), .IN_MANTISSA_SIZE(MANTISSA_SIZE), .IN_EXPONENT_SIZE(8)) stage3_if ();

    // --- DUT Instantiations ---

    // STAGE 1: 8 Adders (BF16 to FP32)
    generate
        for (genvar i = 0; i < 8; i++) begin : gen_s1
            sysarr_4_input_fp_adder #(
                .EXPONENT_SIZE(8), .MANTISSA_SIZE(MANTISSA_SIZE),
                .IN_MANTISSA_SIZE(7), .IN_EXPONENT_SIZE(8),
                .PRECISION_BITS(PRECISION_BITS), .GRS(GRS)
            ) adder_s1 (
                .clk(tb_clk), .nRST(tb_nrst), .add(stage1_if[i])
            );
            assign stage1_if[i].a = inputs[i*4 + 0];
            assign stage1_if[i].b = inputs[i*4 + 1];
            assign stage1_if[i].c = inputs[i*4 + 2];
            assign stage1_if[i].d = inputs[i*4 + 3];
        end
    endgenerate

    // STAGE 2: 2 Adders (FP32 to FP32)
    generate
        for (genvar j = 0; j < 2; j++) begin : gen_s2
            sysarr_4_input_fp_adder #(
                .EXPONENT_SIZE(8), .MANTISSA_SIZE(MANTISSA_SIZE),
                .IN_MANTISSA_SIZE(MANTISSA_SIZE), .IN_EXPONENT_SIZE(8),
                .PRECISION_BITS(PRECISION_BITS), .GRS(GRS)
            ) adder_s2 (
                .clk(tb_clk), .nRST(tb_nrst), .add(stage2_if[j])
            );
            assign stage2_if[j].a = stage1_if[j*4 + 0].out;
            assign stage2_if[j].b = stage1_if[j*4 + 1].out;
            assign stage2_if[j].c = stage1_if[j*4 + 2].out;
            assign stage2_if[j].d = stage1_if[j*4 + 3].out;
        end
    endgenerate

    // STAGE 3: Final 2-input reduction (using 4-input module)
    sysarr_4_input_fp_adder #(
        .EXPONENT_SIZE(8), .MANTISSA_SIZE(MANTISSA_SIZE),
        .IN_MANTISSA_SIZE(MANTISSA_SIZE), .IN_EXPONENT_SIZE(8),
        .PRECISION_BITS(PRECISION_BITS), .GRS(GRS)
    ) adder_s3 (
        .clk(tb_clk), .nRST(tb_nrst), .add(stage3_if)
    );
    assign stage3_if.a = stage2_if[0].out;
    assign stage3_if.b = stage2_if[1].out;
    assign stage3_if.c = 32'h0;
    assign stage3_if.d = 32'h0;

    // Output Reduction to BF16
    reducer #(.IN_EXP_W(8), .IN_MANT_W(MANTISSA_SIZE), .OUT_EXP_W(8), .OUT_MANT_W(7)) final_reduce (
        .fp_in(stage3_if.out), .fp_out(tb_result)
    );

    // --- Helper Functions and Tasks ---

    function automatic logic is_nan(input logic [15:0] val);
        return (val[14:7] == 8'hFF) && (val[6:0] != 7'h0);
    endfunction

    function automatic longint get_ulp_distance(logic [15:0] a, logic [15:0] b);
        longint int_a, int_b;
        int_a = (a[15]) ? (64'h7FFFFFFF - a[14:0]) : (64'h80000000 + a[14:0]);
        int_b = (b[15]) ? (64'h7FFFFFFF - b[14:0]) : (64'h80000000 + b[14:0]);
        return (int_a > int_b) ? (int_a - int_b) : (int_b - int_a);
    endfunction

    task automatic check_case(input string casename, input logic [15:0] expected_val);
        logic match;
        longint ulp;
        if (is_nan(tb_result) && is_nan(expected_val)) begin
            match = 1'b1;
            ulp = 0;
        end else begin
            match = (tb_result === expected_val);
            ulp = get_ulp_distance(tb_result, expected_val);
        end

        total_ulp_diff += ulp;
        if (ulp > 1) ulp_big_count++;
        if (ulp > largest_ulp) largest_ulp = int'(ulp);
        
        if (!match) begin
            if (fail_count < 20) begin
                $display("FAIL: %s | Got=%h Exp=%h | ULP=%0d", casename, tb_result, expected_val, ulp);
            end

            if (fail_fd != 0) begin
                for (int k = 0; k < 32; k++) $fwrite(fail_fd, "%h,", inputs[k]);
                $fwrite(fail_fd, "%h,%h,%0d\n", expected_val, tb_result, ulp);
            end
            fail_count++;
        end else begin
            pass_count++;
        end
    endtask

    // --- Main Test Process ---
    integer fd, total_count;
    string header;

    initial begin
        $dumpfile("waves/add32_bf16_tree.vcd");
        $dumpvars(0, add32_fp32accum_bf16_tb);

        // Reset
        tb_nrst = 1'b0;
        for(int i=0; i<32; i++) inputs[i] = 16'h0;
        #(PERIOD * 5);
        tb_nrst = 1'b1;
        #(PERIOD * 2);

        $display("Starting 32-input Tree Simulation...");

        fd = $fopen("scripts/systolic_array/testfloat_cases_32_pure_bf16.csv", "r");
        if (fd == 0) begin
            $display("ERROR: Cannot open test vectors file!");
            $finish;
        end

        fail_fd = $fopen("tree_failures.csv", "w");
        if (fail_fd == 0) begin
            $display("ERROR: Could not create tree_failures.csv");
        end else begin
            // Write header: i0, i1 ... i31, expected, got, ulp
            for (int k = 0; k < 32; k++) $fwrite(fail_fd, "i%0d,", k);
            $fwrite(fail_fd, "expected,got,ulp\n");
        end

        // Skip CSV Header
        void'($fgets(header, fd));
        total_count = 0;

        while (!$feof(fd)) begin
            logic [15:0] csv_in [31:0];
            logic [15:0] csv_exp;
            int ret;

            // Scans 32 inputs and 1 expected result
            ret = $fscanf(fd, "%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h,%h\n",
                csv_in[0],  csv_in[1],  csv_in[2],  csv_in[3],  csv_in[4],  csv_in[5],  csv_in[6],  csv_in[7],
                csv_in[8],  csv_in[9],  csv_in[10], csv_in[11], csv_in[12], csv_in[13], csv_in[14], csv_in[15],
                csv_in[16], csv_in[17], csv_in[18], csv_in[19], csv_in[20], csv_in[21], csv_in[22], csv_in[23],
                csv_in[24], csv_in[25], csv_in[26], csv_in[27], csv_in[28], csv_in[29], csv_in[30], csv_in[31],
                csv_exp);

            if (ret != 33) continue;

            @(negedge tb_clk);
            for(int k=0; k<32; k++) inputs[k] = csv_in[k];
            
            // Wait for full pipeline traversal
            #(PERIOD * LATENCY);

            check_case($sformatf("Row %0d", total_count), csv_exp);
            total_count++;

            if (total_count % 100000 == 0) 
                $display("Processed %0d cases...", total_count);
        end

        // --- Final Report ---
        $display("\n========================================");
        $display("SIMULATION FINISHED");
        $display("TOTAL CASES: %0d", total_count);
        $display("PASSED:      %0d", pass_count);
        $display("FAILED:      %0d", fail_count);
        if (total_count > 0) begin
            $display("AVG ULP ERR: %0f", total_ulp_diff * 1.0 / total_count);
        end
        $display("MAX ULP ERR: %0d", largest_ulp);
        $display("ULP > 1:     %0d", ulp_big_count);
        $display("========================================\n");

        $fclose(fd);
        if (fail_fd != 0) $fclose(fail_fd);
        $finish;
    end

endmodule