`timescale 1ps/1ps

`include "scpad_if.sv"
import scpad_pkg::*;

module tail_tb;
    import scpad_pkg::*;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    
    // Instantiate just the tail module
    tail #(.IDX(0)) DUT (.tif(sif));
    
    // Test counters
    int tests_passed = 0;
    int tests_failed = 0;
    
    //==========================================================================
    // Reset
    //==========================================================================
    task automatic do_reset();
        n_rst = 0;
        sif.stomach_tail_res[0] = '0;
        repeat (5) @(posedge clk);
        n_rst = 1;
        @(posedge clk);
    endtask
    
    //==========================================================================
    // Test 1: No input -> no output
    //==========================================================================
    task automatic test_idle();
        $display("\n[TEST 1] Idle State");
        do_reset();
        repeat (3) @(posedge clk);
        
        if (!sif.fe_res[0].valid && !sif.be_res[0].valid) begin
            $display("  [PASS] No output when no input");
            tests_passed++;
        end else begin
            $display("  [FAIL] Output valid when should be idle");
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Test 2: FE response routing
    //==========================================================================
    task automatic test_fe_response();
        $display("\n[TEST 2] FE Response Routing");
        do_reset();
        
        // Send response destined for FE
        sif.stomach_tail_res[0].valid = 1'b1;
        sif.stomach_tail_res[0].write = 1'b0;  // read response
        sif.stomach_tail_res[0].src = SRC_FE;
        sif.stomach_tail_res[0].rdata[0] = 16'hBEEF;
        sif.stomach_tail_res[0].rdata[1] = 16'hCAFE;
        
        // Wait for latch
        repeat (3) @(posedge clk);
        
        if (sif.fe_res[0].valid) begin
            $display("  [PASS] FE response valid");
            tests_passed++;
            
            if (sif.fe_res[0].rdata[0] == 16'hBEEF) begin
                $display("  [PASS] FE rdata[0] = 0xBEEF");
                tests_passed++;
            end else begin
                $display("  [FAIL] FE rdata[0] = 0x%04X, expected 0xBEEF", sif.fe_res[0].rdata[0]);
                tests_failed++;
            end
        end else begin
            $display("  [FAIL] FE response not valid");
            tests_failed++;
        end
        
        if (!sif.be_res[0].valid) begin
            $display("  [PASS] BE response not asserted (correct routing)");
            tests_passed++;
        end else begin
            $display("  [FAIL] BE response incorrectly asserted");
            tests_failed++;
        end
        
        sif.stomach_tail_res[0] = '0;
    endtask
    
    //==========================================================================
    // Test 3: BE response routing
    //==========================================================================
    task automatic test_be_response();
        $display("\n[TEST 3] BE Response Routing");
        do_reset();
        
        // Send response destined for BE
        sif.stomach_tail_res[0].valid = 1'b1;
        sif.stomach_tail_res[0].write = 1'b0;
        sif.stomach_tail_res[0].src = SRC_BE;
        sif.stomach_tail_res[0].rdata[0] = 16'hDEAD;
        
        repeat (3) @(posedge clk);
        
        if (sif.be_res[0].valid) begin
            $display("  [PASS] BE response valid");
            tests_passed++;
            
            if (sif.be_res[0].rdata[0] == 16'hDEAD) begin
                $display("  [PASS] BE rdata[0] = 0xDEAD");
                tests_passed++;
            end else begin
                $display("  [FAIL] BE rdata[0] = 0x%04X, expected 0xDEAD", sif.be_res[0].rdata[0]);
                tests_failed++;
            end
        end else begin
            $display("  [FAIL] BE response not valid");
            tests_failed++;
        end
        
        if (!sif.fe_res[0].valid) begin
            $display("  [PASS] FE response not asserted (correct routing)");
            tests_passed++;
        end else begin
            $display("  [FAIL] FE response incorrectly asserted");
            tests_failed++;
        end
        
        sif.stomach_tail_res[0] = '0;
    endtask
    
    //==========================================================================
    // Test 4: Write response (valid only, no rdata check)
    //==========================================================================
    task automatic test_write_response();
        $display("\n[TEST 4] Write Response");
        do_reset();
        
        // Send write completion to FE
        sif.stomach_tail_res[0].valid = 1'b1;
        sif.stomach_tail_res[0].write = 1'b1;  // write response
        sif.stomach_tail_res[0].src = SRC_FE;
        
        repeat (3) @(posedge clk);
        
        if (sif.fe_res[0].valid) begin
            $display("  [PASS] Write completion acknowledged");
            tests_passed++;
        end else begin
            $display("  [FAIL] Write completion not acknowledged");
            tests_failed++;
        end
        
        sif.stomach_tail_res[0] = '0;
    endtask
    
    //==========================================================================
    // Main
    //==========================================================================
    initial begin
        $display("\n");
        $display("# ============================================");
        $display("# TAIL MODULE SMOKE TEST");
        $display("# ============================================");
        
        test_idle();
        test_fe_response();
        test_be_response();
        test_write_response();
        
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