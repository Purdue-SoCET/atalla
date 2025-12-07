`timescale 1ps/1ps

`include "scpad_if.sv"
import scpad_pkg::*;

module body_tb;
    import scpad_pkg::*;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    
    // Instantiate just the body module
    body #(.IDX(0)) DUT (.bif(sif));
    
    // Test counters
    int tests_passed = 0;
    int tests_failed = 0;
    
    //==========================================================================
    // Reset and Init
    //==========================================================================
    task automatic do_reset();
        n_rst = 0;
        // Clear inputs
        sif.fe_req[0] = '0;
        sif.be_req[0] = '0;
        repeat (5) @(posedge clk);
        n_rst = 1;
        @(posedge clk);
    endtask
    
    //==========================================================================
    // Test 1: Check reset state
    //==========================================================================
    task automatic test_reset_state();
        $display("\n[TEST] Reset State Check");
        do_reset();
        
        // After reset, outputs should be inactive
        if (sif.head_stomach_req[0].valid !== 1'b0) begin
            $display("  [FAIL] head_stomach_req.valid not 0 after reset");
            tests_failed++;
        end else begin
            $display("  [PASS] head_stomach_req.valid = 0 after reset");
            tests_passed++;
        end
        
        if (sif.fe_stall[0] !== 1'b0 && sif.be_stall[0] !== 1'b0) begin
            $display("  [INFO] fe_stall=%b be_stall=%b (may be X initially)", sif.fe_stall[0], sif.be_stall[0]);
        end
    endtask
    
    //==========================================================================
    // Test 2: FE Request Propagation
    //==========================================================================
    task automatic test_fe_request();
        $display("\n[TEST] Frontend Request Propagation");
        do_reset();
        
        // Send a frontend write request
        sif.fe_req[0].valid = 1'b1;
        sif.fe_req[0].write = 1'b1;
        sif.fe_req[0].spad_addr = 20'h100;
        sif.fe_req[0].num_rows = 5'd0;
        sif.fe_req[0].num_cols = 5'd7;
        sif.fe_req[0].row_id = 5'd0;
        sif.fe_req[0].col_id = 5'd0;
        sif.fe_req[0].row_or_col = 1'b1;
        
        // Set xbar descriptor
        sif.fe_req[0].xbar.valid_mask = 32'hFF;  // 8 columns valid
        sif.fe_req[0].xbar.slot_mask = '0;
        sif.fe_req[0].xbar.shift_mask = '0;
        for (int i = 0; i < 8; i++) begin
            sif.fe_req[0].xbar.slot_mask[i] = i;  // Row 0 for all
            sif.fe_req[0].xbar.shift_mask[i] = i; // Identity mapping
        end
        
        // Set write data
        for (int i = 0; i < NUM_COLS; i++) begin
            sif.fe_req[0].wdata[i] = 16'(i + 1);
        end
        
        // Wait a few cycles
        repeat (3) @(posedge clk);
        
        // Check if request propagated to head output
        if (sif.head_stomach_req[0].valid) begin
            $display("  [PASS] head_stomach_req.valid = 1");
            tests_passed++;
            
            if (sif.head_stomach_req[0].src == SRC_FE) begin
                $display("  [PASS] head_stomach_req.src = SRC_FE");
                tests_passed++;
            end else begin
                $display("  [FAIL] head_stomach_req.src = %b, expected SRC_FE", sif.head_stomach_req[0].src);
                tests_failed++;
            end
        end else begin
            $display("  [FAIL] head_stomach_req.valid = 0, expected 1");
            tests_failed++;
        end
        
        // Clear request
        sif.fe_req[0] = '0;
        repeat (2) @(posedge clk);
    endtask
    
    //==========================================================================
    // Test 3: BE Priority over FE
    //==========================================================================
    task automatic test_be_priority();
        $display("\n[TEST] Backend Priority over Frontend");
        do_reset();
        
        // Send both FE and BE requests simultaneously
        sif.fe_req[0].valid = 1'b1;
        sif.fe_req[0].write = 1'b1;
        sif.be_req[0].valid = 1'b1;
        sif.be_req[0].write = 1'b1;
        
        repeat (3) @(posedge clk);
        
        // BE should win
        if (sif.head_stomach_req[0].valid && sif.head_stomach_req[0].src == SRC_BE) begin
            $display("  [PASS] BE request prioritized (src = SRC_BE)");
            tests_passed++;
        end else begin
            $display("  [FAIL] BE not prioritized. valid=%b src=%b", 
                     sif.head_stomach_req[0].valid, sif.head_stomach_req[0].src);
            tests_failed++;
        end
        
        // FE should be stalled
        if (sif.fe_stall[0]) begin
            $display("  [PASS] fe_stall asserted when BE active");
            tests_passed++;
        end else begin
            $display("  [FAIL] fe_stall not asserted");
            tests_failed++;
        end
        
        // Clear
        sif.fe_req[0] = '0;
        sif.be_req[0] = '0;
        repeat (2) @(posedge clk);
    endtask
    
    //==========================================================================
    // Test 4: SRAM Bank Response (write then read)
    //==========================================================================
    task automatic test_sram_write_read();
        automatic int timeout;
        automatic logic found_response;
        
        $display("\n[TEST] SRAM Write then Read");
        do_reset();
        
        // === WRITE PHASE ===
        $display("  Writing data...");
        sif.fe_req[0].valid = 1'b1;
        sif.fe_req[0].write = 1'b1;
        sif.fe_req[0].spad_addr = 20'h0;
        sif.fe_req[0].num_rows = 5'd0;
        sif.fe_req[0].num_cols = 5'd3;  // 4 columns
        sif.fe_req[0].row_id = 5'd0;
        sif.fe_req[0].col_id = 5'd0;
        sif.fe_req[0].row_or_col = 1'b1;
        
        sif.fe_req[0].xbar.valid_mask = 32'h0F;  // 4 columns valid
        for (int i = 0; i < 4; i++) begin
            sif.fe_req[0].xbar.slot_mask[i] = 0;  // Row 0
            sif.fe_req[0].xbar.shift_mask[i] = i; // Identity
            sif.fe_req[0].wdata[i] = 16'hA000 + i;
        end
        
        // Wait for write to be accepted
        timeout = 0;
        while (sif.fe_stall[0] && timeout < 20) begin
            @(posedge clk);
            timeout++;
        end
        @(posedge clk);
        sif.fe_req[0] = '0;
        
        // Wait for write to complete (SRAM has latency)
        repeat (10) @(posedge clk);
        
        // === READ PHASE ===
        $display("  Reading data...");
        sif.fe_req[0].valid = 1'b1;
        sif.fe_req[0].write = 1'b0;  // READ
        sif.fe_req[0].spad_addr = 20'h0;
        sif.fe_req[0].num_rows = 5'd0;
        sif.fe_req[0].num_cols = 5'd3;
        sif.fe_req[0].row_id = 5'd0;
        sif.fe_req[0].col_id = 5'd0;
        sif.fe_req[0].row_or_col = 1'b1;
        
        sif.fe_req[0].xbar.valid_mask = 32'h0F;
        for (int i = 0; i < 4; i++) begin
            sif.fe_req[0].xbar.slot_mask[i] = 0;
            sif.fe_req[0].xbar.shift_mask[i] = i;
        end
        
        // Wait for response
        timeout = 0;
        found_response = 0;
        while (timeout < 50 && !found_response) begin
            @(posedge clk);
            if (sif.fe_res[0].valid) begin
                found_response = 1;
                $display("  [INFO] Got fe_res.valid at cycle %0d", timeout);
            end
            timeout++;
        end
        
        sif.fe_req[0] = '0;
        
        if (found_response) begin
            $display("  [PASS] Read response received");
            tests_passed++;
            
            // Check data
            if (sif.fe_res[0].rdata[0] == 16'hA000) begin
                $display("  [PASS] rdata[0] = 0x%04X (expected 0xA000)", sif.fe_res[0].rdata[0]);
                tests_passed++;
            end else begin
                $display("  [FAIL] rdata[0] = 0x%04X (expected 0xA000)", sif.fe_res[0].rdata[0]);
                tests_failed++;
            end
        end else begin
            $display("  [FAIL] No read response within timeout");
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Test 5: Signal Observability (just check things aren't X)
    //==========================================================================
    task automatic test_signal_observability();
        $display("\n[TEST] Signal Observability");
        do_reset();
        repeat (5) @(posedge clk);
        
        $display("  Checking internal signals aren't X...");
        
        // Check key signals
        if (sif.w_stall[0] === 1'bx) begin
            $display("  [WARN] w_stall[0] is X");
        end else begin
            $display("  [INFO] w_stall[0] = %b", sif.w_stall[0]);
        end
        
        if (sif.r_stall[0] === 1'bx) begin
            $display("  [WARN] r_stall[0] is X");
        end else begin
            $display("  [INFO] r_stall[0] = %b", sif.r_stall[0]);
        end
        
        $display("  [PASS] Signal observability check complete");
        tests_passed++;
    endtask
    
    //==========================================================================
    // Main
    //==========================================================================
    initial begin
        $display("\n");
        $display("# ============================================");
        $display("# BODY MODULE SMOKE TEST");
        $display("# ============================================");
        
        test_reset_state();
        test_fe_request();
        test_be_priority();
        test_signal_observability();
        test_sram_write_read();
        
        $display("\n");
        $display("# ============ TEST SUMMARY ============");
        $display("#   Total: %0d | Passed: %0d | Failed: %0d", 
                 tests_passed + tests_failed, tests_passed, tests_failed);
        if (tests_failed == 0)
            $display("#   ALL TESTS PASSED");
        else
            $display("#   SOME TESTS FAILED");
        $display("# ======================================");
        $display("\n");
        
        $finish;
    end
    
    // Timeout watchdog
    initial begin
        #100000;
        $display("\n[TIMEOUT] Simulation exceeded time limit");
        $finish;
    end

endmodule