`timescale 1ns/1ps
`include "vector_pkg.vh"

module reduction_tree_tb;
    import vector_pkg::*;

    logic CLK = 0, nRST = 0;
    always #5 CLK = ~CLK;

    logic [NUM_LANES-1:0][ESZ-1:0] data_in;
    alu_op_t alu_op;
    logic valid_in;
    logic [ESZ-1:0] data_out;
    logic valid_out;

    reduction_tree test (.CLK(CLK), .nRST(nRST), .data_in(data_in), .alu_op(alu_op), .valid_in(valid_in), .data_out(data_out), .valid_out(valid_out)
    );

    int pass_n = 0, fail_n = 0;

    // BF16 helpers (integer bit manipulation; $shortrealtobits is unreliable here)
    function logic [15:0] r2bf(real r);
        logic [63:0] d;
        logic sign; 
        logic [10:0] e11; 
        logic [51:0] m52;
        d = $realtobits(r);
        sign = d[63]; e11 = d[62:52]; m52 = d[51:0];
        if (r == 0.0) return 16'h0000;
        return {sign, 8'(e11 - 1023 + 127), m52[51:45]};
    endfunction

    function real bf2r(logic [15:0] b);
        logic [63:0] d;
        logic sign;
        logic [7:0] e8;
        logic [6:0] m7;
        sign = b[15]; e8 = b[14:7]; m7 = b[6:0];
        if (e8 == 8'h00) return 0.0;
        d = {sign, 11'(e8 - 127 + 1023), m7, 45'b0};
        return $bitstoreal(d);
    endfunction

    task drive(input alu_op_t op, input real vals[16], input string name, input real expect_val, input real tol);
        real got;
        int  guard;
        begin
            // Present data and hold it; the tree registers data_in every cycle,
            // so clearing it early would flush zeros into the pipeline.
            for (int i = 0; i < 16; i++) data_in[i] = r2bf(vals[i]);
            alu_op = op;

            @(posedge CLK);
            valid_in = 1'b1;
            @(posedge CLK);
            valid_in = 1'b0;

            // wait for valid_out (bounded)
            guard = 0;
            while (valid_out !== 1'b1 && guard < 200) begin
                @(posedge CLK);
                guard++;
            end
            if (guard >= 200)
                $display("  TIMEOUT waiting for valid_out on %s", name);

            // valid_out leads data_out by one cycle in this design
            @(posedge CLK);
            #1;
            got = bf2r(data_out);

            if (got >= expect_val - tol && got <= expect_val + tol) begin
                $display("  PASS %-22s got=%10.4f expect=%10.4f (raw=0x%04h)", name, got, expect_val, data_out);
                pass_n++;
            end else begin
                $display("  FAIL %-22s got=%10.4f expect=%10.4f (raw=0x%04h)", name, got, expect_val, data_out);
                fail_n++;
            end
            repeat (6) @(posedge CLK);
        end
    endtask

    real v[16];

    initial begin
        valid_in = 0; alu_op = ALU_ADD;
        for (int i = 0; i < 16; i++) data_in[i] = '0;
        nRST = 0; repeat (4) @(posedge CLK); nRST = 1; repeat (2) @(posedge CLK);

        $display("\n=== reduction_tree numeric tests (BF16, 16 lanes) ===");

        // 1. sum of sixteen 1.0 = 16.0
        for (int i = 0; i < 16; i++) v[i] = 1.0;
        drive(ALU_ADD, v, "SUM 16x1.0", 16.0, 0.01);

        // 2. sum of 1..16 = 136
        for (int i = 0; i < 16; i++) v[i] = real'(i + 1);
        drive(ALU_ADD, v, "SUM 1..16", 136.0, 1.0);

        // 3. sum of 2.0 = 32
        for (int i = 0; i < 16; i++) v[i] = 2.0;
        drive(ALU_ADD, v, "SUM 16x2.0", 32.0, 0.01);

        // 4. sum with negatives: +1/-1 alternating = 0
        for (int i = 0; i < 16; i++) v[i] = (i % 2 == 0) ? 1.0 : -1.0;
        drive(ALU_ADD, v, "SUM alternating +-1", 0.0, 0.01);

        // 5. MIN of 1..16 = 1
        for (int i = 0; i < 16; i++) v[i] = real'(i + 1);
        drive(ALU_MLT, v, "MIN 1..16", 1.0, 0.01);

        // 6. MAX of 1..16 = 16
        for (int i = 0; i < 16; i++) v[i] = real'(i + 1);
        drive(ALU_MGT, v, "MAX 1..16", 16.0, 0.01);

        // 7. MIN with negatives
        for (int i = 0; i < 16; i++) v[i] = real'(i) - 8.0;   // -8..7
        drive(ALU_MLT, v, "MIN -8..7", -8.0, 0.01);

        // 8. MAX with negatives
        for (int i = 0; i < 16; i++) v[i] = real'(i) - 8.0;
        drive(ALU_MGT, v, "MAX -8..7", 7.0, 0.01);

        $display("\n=== RESULT: %0d passed, %0d failed ===\n", pass_n, fail_n);
        $finish;
    end
endmodule
