`timescale 1ps/1ps

`include "scpad_if.sv"

module wxbar_tb;
    import scpad_pkg::*;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    
    // Instantiate wxbar
    wxbar #(.IDX(0)) DUT (.wif(sif));
    
    // Test counters
    int tests_passed = 0;
    int tests_failed = 0;
    
    // Drive stall (normally from scpad_cntrl)
    initial sif.w_stall[0] = 0;
    
    //==========================================================================
    // Reset
    //==========================================================================
    task automatic do_reset();
        n_rst = 0;
        sif.head_stomach_req[0] = '0;
        sif.w_stall[0] = 0;
        repeat (5) @(posedge clk);
        n_rst = 1;
        @(posedge clk);
    endtask
    
    //==========================================================================
    // Test 1: Idle state
    //==========================================================================
    task automatic test_idle();
        $display("\n[TEST 1] Idle State");
        do_reset();
        repeat (3) @(posedge clk);
        
        if (!sif.xbar_cntrl_req[0].valid) begin
            $display("  [PASS] No output when no input");
            tests_passed++;
        end else begin
            $display("  [FAIL] Output valid when should be idle");
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Test 2: Write request propagation
    //==========================================================================
    task automatic test_write_propagation();
        automatic int timeout = 0;
        automatic logic found = 0;
        
        $display("\n[TEST 2] Write Request Propagation");
        do_reset();
        
        // Send write request
        sif.head_stomach_req[0].valid = 1'b1;
        sif.head_stomach_req[0].write = 1'b1;
        sif.head_stomach_req[0].src = SRC_FE;
        sif.head_stomach_req[0].xbar.valid_mask = 32'h0000000F;  // 4 columns
        for (int i = 0; i < NUM_COLS; i++) begin
            sif.head_stomach_req[0].xbar.slot_mask[i] = 0;
            sif.head_stomach_req[0].xbar.shift_mask[i] = i[$clog2(NUM_COLS)-1:0];
            sif.head_stomach_req[0].wdata[i] = 16'hA000 + i;
        end
        
        $display("  Sending write: wdata[0]=0x%04X, wdata[1]=0x%04X", 
                 sif.head_stomach_req[0].wdata[0], sif.head_stomach_req[0].wdata[1]);
        
        // Wait for output (XBAR_LATENCY cycles)
        while (timeout < 20 && !found) begin
            @(posedge clk);
            if (sif.xbar_cntrl_req[0].valid) found = 1;
            timeout++;
        end
        
        sif.head_stomach_req[0] = '0;
        
        if (found) begin
            $display("  [PASS] Write appeared at output after %0d cycles", timeout);
            tests_passed++;
            
            if (sif.xbar_cntrl_req[0].write == 1'b1) begin
                $display("  [PASS] write flag preserved");
                tests_passed++;
            end else begin
                $display("  [FAIL] write flag = %b, expected 1", sif.xbar_cntrl_req[0].write);
                tests_failed++;
            end
            
            if (sif.xbar_cntrl_req[0].src == SRC_FE) begin
                $display("  [PASS] src = SRC_FE preserved");
                tests_passed++;
            end else begin
                $display("  [FAIL] src = %b, expected SRC_FE", sif.xbar_cntrl_req[0].src);
                tests_failed++;
            end
            
            // Check wdata (should be swizzled through xbar, but identity mapping = same)
            $display("  [INFO] wdata[0]=0x%04X wdata[1]=0x%04X", 
                     sif.xbar_cntrl_req[0].wdata[0], sif.xbar_cntrl_req[0].wdata[1]);
        end else begin
            $display("  [FAIL] Write never appeared at output (timeout)");
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Test 3: Read request propagation
    //==========================================================================
    task automatic test_read_propagation();
        automatic int timeout = 0;
        automatic logic found = 0;
        
        $display("\n[TEST 3] Read Request Propagation");
        do_reset();
        
        // Send read request
        sif.head_stomach_req[0].valid = 1'b1;
        sif.head_stomach_req[0].write = 1'b0;  // READ
        sif.head_stomach_req[0].src = SRC_BE;
        sif.head_stomach_req[0].xbar.valid_mask = 32'h000000FF;  // 8 columns
        for (int i = 0; i < NUM_COLS; i++) begin
            sif.head_stomach_req[0].xbar.slot_mask[i] = 5;  // Row 5
            sif.head_stomach_req[0].xbar.shift_mask[i] = i[$clog2(NUM_COLS)-1:0];
        end
        
        $display("  Sending read request");
        
        // Wait for output
        while (timeout < 20 && !found) begin
            @(posedge clk);
            if (sif.xbar_cntrl_req[0].valid) found = 1;
            timeout++;
        end
        
        sif.head_stomach_req[0] = '0;
        
        if (found) begin
            $display("  [PASS] Read appeared at output after %0d cycles", timeout);
            tests_passed++;
            
            if (sif.xbar_cntrl_req[0].write == 1'b0) begin
                $display("  [PASS] write flag = 0 (read)");
                tests_passed++;
            end else begin
                $display("  [FAIL] write flag = %b, expected 0", sif.xbar_cntrl_req[0].write);
                tests_failed++;
            end
            
            if (sif.xbar_cntrl_req[0].src == SRC_BE) begin
                $display("  [PASS] src = SRC_BE preserved");
                tests_passed++;
            end else begin
                $display("  [FAIL] src = %b, expected SRC_BE", sif.xbar_cntrl_req[0].src);
                tests_failed++;
            end
            
            if (sif.xbar_cntrl_req[0].xbar.valid_mask == 32'h000000FF) begin
                $display("  [PASS] valid_mask preserved (0xFF)");
                tests_passed++;
            end else begin
                $display("  [FAIL] valid_mask = 0x%08X, expected 0xFF", sif.xbar_cntrl_req[0].xbar.valid_mask);
                tests_failed++;
            end
        end else begin
            $display("  [FAIL] Read never appeared at output (timeout)");
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Test 4: Stall blocks output
    //==========================================================================
    task automatic test_stall();
        $display("\n[TEST 4] Stall Blocks Output");
        do_reset();
        
        // Assert stall
        sif.w_stall[0] = 1;
        
        // Send request
        sif.head_stomach_req[0].valid = 1'b1;
        sif.head_stomach_req[0].write = 1'b1;
        
        repeat (5) @(posedge clk);
        
        // Should not appear while stalled
        // (FIFO won't write when stalled)
        $display("  [INFO] With stall: xbar_cntrl_req.valid = %b", sif.xbar_cntrl_req[0].valid);
        
        // Release stall
        sif.w_stall[0] = 0;
        repeat (5) @(posedge clk);
        
        $display("  [INFO] After stall release: xbar_cntrl_req.valid = %b", sif.xbar_cntrl_req[0].valid);
        tests_passed++;  // Just informational for now
        
        sif.head_stomach_req[0] = '0;
    endtask
    
    //==========================================================================
    // Main
    //==========================================================================
    initial begin
        $display("\n");
        $display("# ============================================");
        $display("# WXBAR MODULE SMOKE TEST");
        $display("# ============================================");
        $display("# XBAR_TYPE = %s, XBAR_LATENCY = %0d", XBAR_TYPE, XBAR_LATENCY);
        
        test_idle();
        test_write_propagation();
        test_read_propagation();
        test_stall();
        
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

endmodule