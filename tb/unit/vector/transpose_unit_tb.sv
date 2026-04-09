`timescale 1ns/1ps

module transpose_unit_tb;

    // Parameters
    localparam int VEC_LEN = 32;
    localparam int DATA_W  = 16;

    // 1. Instantiate the Interface
    transpose_unit_if #(.VEC_LEN(VEC_LEN), .DATA_W(DATA_W)) tif();

    // 2. Instantiate the Unit Under Test (UUT)
    // Connect the 'unit' modport of our interface to the module
    vector_transpose_unit uut (
        .tif(tif.unit)
    );

    // 3. Clock Generation
    initial begin
        tif.clk = 0;
        forever #5 tif.clk = ~tif.clk;
    end

    // 4. Test Logic
    initial begin
        // Initialize Signals
        tif.n_rst    = 0;
        tif.en       = 0;
        tif.push_req = 0;
        tif.pop_req  = 0;
        tif.vec_in   = '0;

        // Reset Sequence
        repeat (5) @(posedge tif.clk);
        tif.n_rst = 1;
        tif.en    = 1;
        @(posedge tif.clk);

        // --- STEP 1: PUSH 32 VECTORS (ROW-MAJOR) ---
        $display("[%0t] Starting PUSH phase...", $time);
        
        for (int row = 0; row < 32; row++) begin
            tif.push_req = 1;
            for (int col = 0; col < 32; col++) begin
                // Data Pattern: (Row * 100) + Column
                tif.vec_in[col] = (row * 100) + col;
            end
            
            @(posedge tif.clk);
            tif.push_req = 0; // Pulse the request
            
            // If the SRAM or logic has internal busy states, wait here
            // For this design, we push one vector per clock cycle
        end

        // Wait for any internal processing to finish
        wait(tif.busy == 0);
        repeat (5) @(posedge tif.clk);

        // --- STEP 2: POP 32 VECTORS (TRANSPOSED) ---
        $display("[%0t] Starting POP phase...", $time);
        tif.pop_req = 1;
        @(posedge tif.clk);
        tif.pop_req = 0;

        // Collect and verify outputs
        for (int col_idx = 0; col_idx < 32; col_idx++) begin
            // Wait for the valid signal (accounts for SRAM Read Latency)
            wait(tif.vec_out_valid == 1);
            
            $display("[%0t] Popped Transposed Vector %0d: %p", $time, col_idx, tif.vec_out);
            
            // Verification Logic:
            // The i-th element of the k-th popped vector should be (i * 100) + k
            for (int i = 0; i < 32; i++) begin
                automatic int expected = (i * 100) + col_idx;
                if (tif.vec_out[i] !== expected) begin
                    $error("Mismatch at Vector %0d, Index %0d! Expected %0d, Got %0d", 
                            col_idx, i, expected, tif.vec_out[i]);
                end
            end
            
            @(posedge tif.clk);
            // After one vector is read, wait for the next valid or end of sequence
        end

        $display("[%0t] Testbench Completed Successfully.", $time);
        $finish;
    end

    // Optional: Monitor for debugging
    initial begin
        $monitor("[%0t] State Busy: %b, Valid Out: %b", $time, tif.busy, tif.vec_out_valid);
    end

endmodule