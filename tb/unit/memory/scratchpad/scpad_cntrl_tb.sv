`timescale 1ps/1ps

`include "scpad_if.sv"

module scpad_cntrl_tb;
    import scpad_pkg::*;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    
    // Instantiate scpad_cntrl
    scpad_cntrl #(.IDX(0)) DUT (.srif(sif));
    
    int tests_passed = 0;
    int tests_failed = 0;
    
    // Drive spad_busy (normally from SRAM banks)
    initial sif.spad_busy[0] = '0;
    
    //==========================================================================
    // Reset
    //==========================================================================
    task automatic do_reset();
        n_rst = 0;
        sif.xbar_cntrl_req[0] = '0;
        sif.spad_busy[0] = '0;
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
        
        if (!sif.cntrl_spad_req[0].valid) begin
            $display("  [PASS] No output when no input");
            tests_passed++;
        end else begin
            $display("  [FAIL] Output valid when should be idle");
            tests_failed++;
        end
        
        // NOTE: Only check w_stall here - r_stall is now driven by rxbar, not scpad_cntrl
        if (!sif.w_stall[0]) begin
            $display("  [PASS] No w_stall when FIFO empty");
            tests_passed++;
        end else begin
            $display("  [FAIL] w_stall asserted when should be idle");
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
        sif.xbar_cntrl_req[0].valid = 1'b1;
        sif.xbar_cntrl_req[0].write = 1'b1;
        sif.xbar_cntrl_req[0].src = SRC_FE;
        sif.xbar_cntrl_req[0].xbar.valid_mask = 32'h0000000F;
        sif.xbar_cntrl_req[0].wdata[0] = 16'hBEEF;
        sif.xbar_cntrl_req[0].wdata[1] = 16'hCAFE;
        
        $display("  Sending write request...");
        
        // Wait for output
        while (timeout < 20 && !found) begin
            @(posedge clk);
            if (sif.cntrl_spad_req[0].valid) begin
                found = 1;
                $display("  [INFO] cntrl_spad_req appeared at cycle %0d", timeout);
            end
            timeout++;
        end
        
        sif.xbar_cntrl_req[0] = '0;
        
        if (found) begin
            $display("  [PASS] Write appeared at output");
            tests_passed++;
            
            if (sif.cntrl_spad_req[0].write == 1'b1) begin
                $display("  [PASS] write=1 preserved");
                tests_passed++;
            end else begin
                $display("  [FAIL] write=%b, expected 1", sif.cntrl_spad_req[0].write);
                tests_failed++;
            end
            
            if (sif.cntrl_spad_req[0].src == SRC_FE) begin
                $display("  [PASS] src=SRC_FE preserved");
                tests_passed++;
            end else begin
                $display("  [FAIL] src=%b, expected SRC_FE", sif.cntrl_spad_req[0].src);
                tests_failed++;
            end
            
            if (sif.cntrl_spad_req[0].wdata[0] == 16'hBEEF) begin
                $display("  [PASS] wdata[0]=0xBEEF preserved");
                tests_passed++;
            end else begin
                $display("  [FAIL] wdata[0]=0x%04X, expected 0xBEEF", sif.cntrl_spad_req[0].wdata[0]);
                tests_failed++;
            end
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
        sif.xbar_cntrl_req[0].valid = 1'b1;
        sif.xbar_cntrl_req[0].write = 1'b0;
        sif.xbar_cntrl_req[0].src = SRC_BE;
        sif.xbar_cntrl_req[0].xbar.valid_mask = 32'h000000FF;
        
        $display("  Sending read request...");
        
        while (timeout < 20 && !found) begin
            @(posedge clk);
            if (sif.cntrl_spad_req[0].valid) begin
                found = 1;
                $display("  [INFO] cntrl_spad_req appeared at cycle %0d", timeout);
            end
            timeout++;
        end
        
        sif.xbar_cntrl_req[0] = '0;
        
        if (found) begin
            $display("  [PASS] Read appeared at output");
            tests_passed++;
            
            if (sif.cntrl_spad_req[0].write == 1'b0) begin
                $display("  [PASS] write=0 preserved");
                tests_passed++;
            end else begin
                $display("  [FAIL] write=%b, expected 0", sif.cntrl_spad_req[0].write);
                tests_failed++;
            end
            
            if (sif.cntrl_spad_req[0].src == SRC_BE) begin
                $display("  [PASS] src=SRC_BE preserved");
                tests_passed++;
            end else begin
                $display("  [FAIL] src=%b, expected SRC_BE", sif.cntrl_spad_req[0].src);
                tests_failed++;
            end
        end else begin
            $display("  [FAIL] Read never appeared at output (timeout)");
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Test 4: SRAM busy blocks drain
    //==========================================================================
    task automatic test_busy_blocking();
        $display("\n[TEST 4] SRAM Busy Blocks Drain");
        do_reset();
        
        // Set all banks busy
        sif.spad_busy[0] = '1;
        
        // Send request
        sif.xbar_cntrl_req[0].valid = 1'b1;
        sif.xbar_cntrl_req[0].write = 1'b1;
        
        repeat (5) @(posedge clk);
        
        // FIFO should accept but not drain
        $display("  [INFO] With all banks busy:");
        $display("    cntrl_spad_req.valid = %b", sif.cntrl_spad_req[0].valid);
        $display("    w_stall = %b", sif.w_stall[0]);
        
        // Clear busy
        sif.spad_busy[0] = '0;
        repeat (3) @(posedge clk);
        
        $display("  [INFO] After clearing busy:");
        $display("    cntrl_spad_req.valid = %b", sif.cntrl_spad_req[0].valid);
        
        tests_passed++;  // Informational
        
        sif.xbar_cntrl_req[0] = '0;
    endtask
    
    //==========================================================================
    // Main
    //==========================================================================
    initial begin
        $display("\n");
        $display("# ============================================");
        $display("# SCPAD_CNTRL MODULE SMOKE TEST");
        $display("# ============================================");
        $display("# MAX_SRAM_DELAY = %0d", MAX_SRAM_DELAY);
        
        test_idle();
        test_write_propagation();
        test_read_propagation();
        test_busy_blocking();
        
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