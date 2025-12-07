`timescale 1ps/1ps

`include "scpad_if.sv"
import scpad_pkg::*;

module head_tb;
    import scpad_pkg::*;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    
    // Instantiate just the head module
    head #(.IDX(0)) DUT (.hif(sif));
    
    // Test counters
    int tests_passed = 0;
    int tests_failed = 0;
    
    // Drive stall signals (normally from downstream)
    initial begin
        sif.w_stall[0] = 0;
        sif.r_stall[0] = 0;
    end
    
    //==========================================================================
    // Reset
    //==========================================================================
    task automatic do_reset();
        n_rst = 0;
        sif.fe_req[0] = '0;
        sif.be_req[0] = '0;
        sif.w_stall[0] = 0;
        sif.r_stall[0] = 0;
        repeat (5) @(posedge clk);
        n_rst = 1;
        @(posedge clk);
    endtask
    
    //==========================================================================
    // Test 1: No request -> no output
    //==========================================================================
    task automatic test_idle();
        $display("\n[TEST 1] Idle State");
        do_reset();
        repeat (3) @(posedge clk);
        
        if (sif.head_stomach_req[0].valid == 1'b0) begin
            $display("  [PASS] No output when no input");
            tests_passed++;
        end else begin
            $display("  [FAIL] Output valid when should be idle");
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Test 2: FE request passes through
    //==========================================================================
    task automatic test_fe_passthrough();
        $display("\n[TEST 2] FE Request Passthrough");
        do_reset();
        
        // Send FE request
        sif.fe_req[0].valid = 1'b1;
        sif.fe_req[0].write = 1'b1;
        sif.fe_req[0].wdata[0] = 16'hCAFE;
        
        repeat (2) @(posedge clk);
        
        if (sif.head_stomach_req[0].valid && sif.head_stomach_req[0].src == SRC_FE) begin
            $display("  [PASS] FE request passed through with src=SRC_FE");
            tests_passed++;
        end else begin
            $display("  [FAIL] FE request not passed. valid=%b src=%b", 
                     sif.head_stomach_req[0].valid, sif.head_stomach_req[0].src);
            tests_failed++;
        end
        
        // Check data preserved
        if (sif.head_stomach_req[0].wdata[0] == 16'hCAFE) begin
            $display("  [PASS] wdata preserved (0xCAFE)");
            tests_passed++;
        end else begin
            $display("  [FAIL] wdata = 0x%04X, expected 0xCAFE", sif.head_stomach_req[0].wdata[0]);
            tests_failed++;
        end
        
        sif.fe_req[0] = '0;
    endtask
    
    //==========================================================================
    // Test 3: BE request passes through
    //==========================================================================
    task automatic test_be_passthrough();
        $display("\n[TEST 3] BE Request Passthrough");
        do_reset();
        
        // Send BE request
        sif.be_req[0].valid = 1'b1;
        sif.be_req[0].write = 1'b0;  // read
        sif.be_req[0].spad_addr = 20'h12345;
        
        repeat (2) @(posedge clk);
        
        if (sif.head_stomach_req[0].valid && sif.head_stomach_req[0].src == SRC_BE) begin
            $display("  [PASS] BE request passed through with src=SRC_BE");
            tests_passed++;
        end else begin
            $display("  [FAIL] BE request not passed. valid=%b src=%b", 
                     sif.head_stomach_req[0].valid, sif.head_stomach_req[0].src);
            tests_failed++;
        end
        
        sif.be_req[0] = '0;
    endtask
    
    //==========================================================================
    // Test 4: BE priority over FE
    //==========================================================================
    task automatic test_be_priority();
        $display("\n[TEST 4] BE Priority over FE");
        do_reset();
        
        // Send both simultaneously
        sif.fe_req[0].valid = 1'b1;
        sif.fe_req[0].write = 1'b1;
        sif.be_req[0].valid = 1'b1;
        sif.be_req[0].write = 1'b0;
        
        repeat (2) @(posedge clk);
        
        if (sif.head_stomach_req[0].src == SRC_BE) begin
            $display("  [PASS] BE wins arbitration");
            tests_passed++;
        end else begin
            $display("  [FAIL] FE won instead of BE");
            tests_failed++;
        end
        
        // FE should be stalled
        if (sif.fe_stall[0]) begin
            $display("  [PASS] FE stalled while BE active");
            tests_passed++;
        end else begin
            $display("  [FAIL] FE not stalled");
            tests_failed++;
        end
        
        sif.fe_req[0] = '0;
        sif.be_req[0] = '0;
    endtask
    
    //==========================================================================
    // Test 5: Downstream stall blocks requests
    //==========================================================================
    task automatic test_stall_blocking();
        $display("\n[TEST 5] Downstream Stall Blocking");
        do_reset();
        
        // Assert downstream stall
        sif.w_stall[0] = 1;
        
        // Send FE request
        sif.fe_req[0].valid = 1'b1;
        
        repeat (3) @(posedge clk);
        
        // Should not grant while stalled
        if (!sif.head_stomach_req[0].valid) begin
            $display("  [PASS] Request blocked during stall");
            tests_passed++;
        end else begin
            $display("  [FAIL] Request passed despite stall");
            tests_failed++;
        end
        
        // FE should see stall
        if (sif.fe_stall[0]) begin
            $display("  [PASS] FE sees stall signal");
            tests_passed++;
        end else begin
            $display("  [FAIL] FE doesn't see stall");
            tests_failed++;
        end
        
        sif.w_stall[0] = 0;
        sif.fe_req[0] = '0;
    endtask
    
    //==========================================================================
    // Test 6: Sequential FE then BE
    //==========================================================================
    task automatic test_sequential();
        $display("\n[TEST 6] Sequential Requests");
        do_reset();
        
        // FE request
        sif.fe_req[0].valid = 1'b1;
        @(posedge clk);
        @(posedge clk);
        
        if (sif.head_stomach_req[0].src == SRC_FE) begin
            $display("  [PASS] First: FE request served");
            tests_passed++;
        end else begin
            $display("  [FAIL] First request wrong src");
            tests_failed++;
        end
        
        sif.fe_req[0] = '0;
        @(posedge clk);
        
        // BE request
        sif.be_req[0].valid = 1'b1;
        @(posedge clk);
        @(posedge clk);
        
        if (sif.head_stomach_req[0].src == SRC_BE) begin
            $display("  [PASS] Second: BE request served");
            tests_passed++;
        end else begin
            $display("  [FAIL] Second request wrong src");
            tests_failed++;
        end
        
        sif.be_req[0] = '0;
    endtask
    
    //==========================================================================
    // Main
    //==========================================================================
    initial begin
        $display("\n");
        $display("# ============================================");
        $display("# HEAD MODULE SMOKE TEST");
        $display("# ============================================");
        
        test_idle();
        test_fe_passthrough();
        test_be_passthrough();
        test_be_priority();
        test_stall_blocking();
        test_sequential();
        
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