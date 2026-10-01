`timescale 1ns/1ps

module transpose_unit_tb;
    // --- Parameters ---
    localparam int VEC_LEN = 32;
    localparam int DATA_W  = 16;
    localparam PERIOD = 10;

    // --- Signals ---
    logic CLK = 0; 
    logic nRST;

    // Interface Instantiation
    transpose_unit_if #(.VEC_LEN(VEC_LEN), .DATA_W(DATA_W)) tif();

    // DUT Instantiation
    transpose_unit DUT (
        .CLK(CLK), 
        .nRST(nRST), 
        .tif(tif.transpose)
    );

    // Scoreboard
    logic [DATA_W-1:0] expected_matrix [VEC_LEN-1:0][VEC_LEN-1:0];

    // Clock Generation
    always #(PERIOD/2) CLK = ~CLK;

    // Global Status Counters
    int total_errors = 0;
    int tests_passed = 0;
    int tests_failed = 0;

    // Helper Task: Report Results
    function void report_test_result(string test_name, int errors);
        if (errors == 0) begin
            $display("[%0t] >> PASS: %s", $time, test_name);
            tests_passed++;
        end else begin
            $display("[%0t] >> FAIL: %s (%0d errors encountered)", $time, test_name, errors);
            tests_failed++;
            total_errors += errors;
        end
    endfunction

    // --- Test Task ---
    task automatic run_transpose_test(input int num_rows);
        int local_errors = 0;
        string t_name = $sformatf("Transpose %0dx%0d", num_rows, VEC_LEN);
        $display("\n[%0t] --- STARTING TEST: %0d x %0d ---", $time, num_rows, VEC_LEN);
        
        // 1. Clear Scoreboard
        for(int i = 0; i < VEC_LEN; i++) begin
            for(int j = 0; j < VEC_LEN; j++) begin
                expected_matrix[i][j] = '0;
            end
        end

        // 2. PUSH PHASE
        for (int r = 0; r < num_rows; r++) begin
            wait (tif.tb.out.ready_in)
            
            tif.tb.in.push_req = 1;
            tif.tb.in.valid_in = 1;
            
            for (int c = 0; c < VEC_LEN; c++) begin
                // Data Pattern: (Row index in upper byte, Col index in lower byte)
                logic [DATA_W-1:0] val = (r << 8) | c;
                tif.tb.in.vec_in[c] = val;
                expected_matrix[r][c] = val;
            end
            
            wait (!tif.tb.out.ready_in);
            tif.tb.in.push_req = 0;
            tif.tb.in.valid_in = 0;
        end

        $display("[%0t] PUSH complete. Waiting for internal pipeline...", $time);

        // 3. POP PHASE
        for (int col_idx = 0; col_idx < VEC_LEN; col_idx++) begin
            tif.tb.in.pop_req = 1;
            
            // Wait for valid_out (accounts for SRAM + Clos latency)
            while (!tif.tb.out.valid_out) @(posedge CLK);
            
            // Compare output vector against scoreboard
            for (int row_idx = 0; row_idx < num_rows; row_idx++) begin
                if (tif.tb.out.vec_out[row_idx] !== expected_matrix[row_idx][col_idx]) begin
                    $error("[%0t] Mismatch! Col %0d, Elem %0d | Exp: %h, Got: %h", 
                            $time, col_idx, row_idx, expected_matrix[row_idx][col_idx], tif.tb.out.vec_out[row_idx]);
                    local_errors++;
                end
            end

            @(posedge CLK);
            tif.tb.in.pop_req = 0;
            
            // Small delay to let the FSM transition out of DONE
            repeat(2) @(posedge CLK);
        end
        
        $display("[%0t] --- TEST PASSED: %0d x %0d ---\n", $time, num_rows, VEC_LEN);
        report_test_result(t_name, local_errors);
    endtask

    task automatic run_backpressure_test(input int num_rows);
        int local_errors = 0;
        string t_name = $sformatf("Backpressure %0dx%0d", num_rows, VEC_LEN);
        $display("\n[%0t] --- STARTING BACKPRESSURE TEST: %0d x %0d ---", $time, num_rows, VEC_LEN);
        
        // 1. PUSH PHASE (Normal Load)
        for (int r = 0; r < num_rows; r++) begin
            wait (tif.tb.out.ready_in);
            tif.tb.in.push_req = 1;
            tif.tb.in.valid_in = 1;
            for (int c = 0; c < VEC_LEN; c++) begin
                logic [DATA_W-1:0] val = (r << 8) | c;
                tif.tb.in.vec_in[c] = val;
                expected_matrix[r][c] = val;
            end
            wait (!tif.tb.out.ready_in);
            tif.tb.in.push_req = 0;
            tif.tb.in.valid_in = 0;
        end

        // 2. POP PHASE WITH BACKPRESSURE
        for (int col_idx = 0; col_idx < VEC_LEN; col_idx++) begin
            // Randomly apply backpressure before requesting
            if ($urandom_range(0, 1)) begin
                tif.tb.in.ready_out = 0;
                repeat($urandom_range(1, 5)) @(posedge CLK);
                tif.tb.in.ready_out = 1;
            end

            tif.tb.in.pop_req = 1;
            
            // Wait for valid_out
            while (!tif.tb.out.valid_out) @(posedge CLK);
            
            // Check data
            for (int row_idx = 0; row_idx < num_rows; row_idx++) begin
                if (tif.tb.out.vec_out[row_idx] !== expected_matrix[row_idx][col_idx]) begin
                    $error("[%0t] Mismatch under pressure! Col %0d | Exp: %h, Got: %h", 
                            $time, col_idx, expected_matrix[row_idx][col_idx], tif.tb.out.vec_out[row_idx]);
                    local_errors++;
                end
            end

            @(posedge CLK);
            tif.tb.in.pop_req = 0;
            repeat(2) @(posedge CLK);
        end
        
        $display("[%0t] --- BACKPRESSURE TEST PASSED ---\n", $time);
        report_test_result(t_name, local_errors);
    endtask

    // --- Main Simulation Block ---
    initial begin
        // Reset sequence
        nRST = 0;
        tif.tb.in = '0;
        tif.tb.in.ready_out = 1; // Always ready to consume output

        repeat (10) @(posedge CLK);
        nRST = 1;
        repeat (5) @(posedge CLK);

        $display("\n--- STARTING TEST SUITE ---");
        for (int i = 1; i <= 32; i++) run_transpose_test(i);
        for (int i = 1; i <= 32; i++) run_backpressure_test(i);

        // Final Summary Report
        $display("\n========================================");
        $display("          FINAL SIMULATION REPORT        ");
        $display("========================================");
        $display("  Total Tests Run:    %0d", (tests_passed + tests_failed));
        $display("  Tests Passed:       %0d", tests_passed);
        $display("  Tests Failed:       %0d", tests_failed);
        $display("  Total Data Errors:  %0d", total_errors);
        $display("========================================\n");
        
        if (total_errors == 0) $display("RESULT: ALL TESTS PASSED\n");
        else $display("RESULT: TEST SUITE FAILED\n");



        $finish;
    end

endmodule