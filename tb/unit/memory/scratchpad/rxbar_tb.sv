`timescale 1ps/1ps

`include "scpad_if.sv"

module rxbar_tb;
    import scpad_pkg::*;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    
    // Instantiate rxbar
    rxbar #(.IDX(0)) DUT (.rif(sif));
    
    int tests_passed = 0;
    int tests_failed = 0;
    
    // NOTE: r_stall is now driven internally by rxbar (when response FIFO is full)
    // Testbench no longer needs to drive it
    
    //==========================================================================
    // Reset
    //==========================================================================
    task automatic do_reset();
        n_rst = 0;
        sif.spad_xbar_req[0] = '0;
        // r_stall is driven by rxbar, not testbench
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
        
        if (!sif.stomach_tail_res[0].valid) begin
            $display("  [PASS] No output when no input");
            tests_passed++;
        end else begin
            $display("  [FAIL] Output valid when should be idle (valid=%b)", sif.stomach_tail_res[0].valid);
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Test 2: Read response propagation
    //==========================================================================
    task automatic test_read_propagation();
        automatic int timeout = 0;
        automatic logic found = 0;
        
        $display("\n[TEST 2] Read Response Propagation");
        do_reset();
        
        // Send read response from SRAM
        sif.spad_xbar_req[0].valid = 1'b1;
        sif.spad_xbar_req[0].write = 1'b0;
        sif.spad_xbar_req[0].src = SRC_FE;
        for (int i = 0; i < NUM_COLS; i++) begin
            sif.spad_xbar_req[0].rdata[i] = 16'hA000 + i;
        end
        
        $display("  Sending read response: rdata[0]=0x%04X, rdata[1]=0x%04X", 
                 sif.spad_xbar_req[0].rdata[0], sif.spad_xbar_req[0].rdata[1]);
        
        // Wait for output
        while (timeout < 20 && !found) begin
            @(posedge clk);
            if (sif.stomach_tail_res[0].valid) begin
                found = 1;
                $display("  [INFO] stomach_tail_res appeared at cycle %0d", timeout);
            end
            timeout++;
        end
        
        if (found) begin
            $display("  [PASS] Response appeared at output");
            tests_passed++;
            
            if (sif.stomach_tail_res[0].write == 1'b0) begin
                $display("  [PASS] write=0 preserved");
                tests_passed++;
            end else begin
                $display("  [FAIL] write=%b, expected 0", sif.stomach_tail_res[0].write);
                tests_failed++;
            end
            
            if (sif.stomach_tail_res[0].src == SRC_FE) begin
                $display("  [PASS] src=SRC_FE preserved");
                tests_passed++;
            end else begin
                $display("  [FAIL] src=%b, expected SRC_FE", sif.stomach_tail_res[0].src);
                tests_failed++;
            end
            
            // Check rdata (identity permutation for NAIVE)
            $display("  [INFO] rdata[0]=0x%04X rdata[1]=0x%04X", 
                     sif.stomach_tail_res[0].rdata[0], sif.stomach_tail_res[0].rdata[1]);
            
            if (sif.stomach_tail_res[0].rdata[0] == 16'hA000) begin
                $display("  [PASS] rdata[0]=0xA000 preserved");
                tests_passed++;
            end else begin
                $display("  [FAIL] rdata[0]=0x%04X, expected 0xA000", sif.stomach_tail_res[0].rdata[0]);
                tests_failed++;
            end
        end else begin
            $display("  [FAIL] Response never appeared at output (timeout)");
            tests_failed++;
        end
        
        sif.spad_xbar_req[0] = '0;
    endtask
    
    //==========================================================================
    // Test 3: BE source propagation
    //==========================================================================
    task automatic test_be_source();
        automatic int timeout = 0;
        automatic logic found = 0;
        
        $display("\n[TEST 3] BE Source Propagation");
        do_reset();
        
        sif.spad_xbar_req[0].valid = 1'b1;
        sif.spad_xbar_req[0].write = 1'b0;
        sif.spad_xbar_req[0].src = SRC_BE;
        sif.spad_xbar_req[0].rdata[0] = 16'hDEAD;
        
        while (timeout < 20 && !found) begin
            @(posedge clk);
            if (sif.stomach_tail_res[0].valid) found = 1;
            timeout++;
        end
        
        if (found && sif.stomach_tail_res[0].src == SRC_BE) begin
            $display("  [PASS] src=SRC_BE preserved");
            tests_passed++;
        end else begin
            $display("  [FAIL] src=%b, expected SRC_BE", sif.stomach_tail_res[0].src);
            tests_failed++;
        end
        
        sif.spad_xbar_req[0] = '0;
    endtask
    
    //==========================================================================
    // Test 4: Multiple consecutive responses
    //==========================================================================
    task automatic test_consecutive();
        automatic int count = 0;
        
        $display("\n[TEST 4] Consecutive Responses");
        do_reset();
        
        // Send 3 consecutive responses, checking outputs each cycle
        for (int i = 0; i < 3; i++) begin
            sif.spad_xbar_req[0].valid = 1'b1;
            sif.spad_xbar_req[0].write = 1'b0;
            sif.spad_xbar_req[0].src = SRC_FE;
            sif.spad_xbar_req[0].rdata[0] = 16'h1000 + i;
            @(posedge clk);
            // Check for output DURING write phase (pipeline behavior)
            if (sif.stomach_tail_res[0].valid) begin
                $display("  [INFO] Got response with rdata[0]=0x%04X (during write)", sif.stomach_tail_res[0].rdata[0]);
                count++;
            end
        end
        sif.spad_xbar_req[0] = '0;
        $display("  [DEBUG] Input cleared, count so far: %0d", count);
        
        // Continue checking for remaining outputs
        repeat (10) begin
            @(posedge clk);
            if (sif.stomach_tail_res[0].valid) begin
                $display("  [INFO] Got response with rdata[0]=0x%04X (after clear)", sif.stomach_tail_res[0].rdata[0]);
                count++;
            end
        end
        
        $display("  [INFO] Total received: %0d responses", count);
        if (count >= 3) begin
            $display("  [PASS] All responses received");
            tests_passed++;
        end else begin
            $display("  [FAIL] Only %0d/3 responses received", count);
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Main
    //==========================================================================
    initial begin
        $display("\n");
        $display("# ============================================");
        $display("# RXBAR MODULE SMOKE TEST");
        $display("# ============================================");
        $display("# XBAR_TYPE = %s, XBAR_LATENCY = %0d", XBAR_TYPE, XBAR_LATENCY);
        
        test_idle();
        test_read_propagation();
        test_be_source();
        test_consecutive();
        
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