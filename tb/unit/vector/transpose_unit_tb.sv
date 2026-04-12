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

    // --- Test Task ---
    task automatic run_transpose_test(input int num_rows);
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
                end
            end

            @(posedge CLK);
            tif.tb.in.pop_req = 0;
            
            // Small delay to let the FSM transition out of DONE
            repeat(2) @(posedge CLK);
        end
        
        $display("[%0t] --- TEST PASSED: %0d x %0d ---\n", $time, num_rows, VEC_LEN);
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

        // --- Execute Tests ---
        run_transpose_test(2);  // Your original test case
        run_transpose_test(8);  // Mid-size test
        run_transpose_test(32); // Full matrix test

        for (int i = 1; i <= 32; i++) begin
            run_transpose_test(i); // loop through everything
        end


        $display("[%0t] All configured tests complete.", $time);
        $finish;
    end

endmodule