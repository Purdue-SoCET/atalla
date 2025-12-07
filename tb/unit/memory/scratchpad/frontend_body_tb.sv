`timescale 1ps/1ps

`include "scpad_if.sv"

module frontend_body_tb;
    import scpad_pkg::*;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    
    // Instantiate frontend + body
    frontend #(.IDX(0)) u_frontend (.fvif(sif), .fsif(sif));
    body #(.IDX(0)) u_body (.bif(sif));
    
    int tests_passed = 0;
    int tests_failed = 0;
    
    //==========================================================================
    // Reset
    //==========================================================================
    task automatic do_reset();
        n_rst = 0;
        sif.vec_req[0] = '0;
        sif.be_req[0] = '0;
        repeat (5) @(posedge clk);
        n_rst = 1;
        @(posedge clk);
    endtask
    
    //==========================================================================
    // Write a row via vec_req
    //==========================================================================
    task automatic vec_write_row(
        input int row_id,
        input int num_cols,
        input logic [15:0] base_data
    );
        $display("  Writing row %0d with %0d cols, base_data=0x%04X", row_id, num_cols+1, base_data);
        
        sif.vec_req[0].valid = 1'b1;
        sif.vec_req[0].write = 1'b1;
        sif.vec_req[0].spad_addr = 20'h0;
        sif.vec_req[0].num_rows = 5'd0;
        sif.vec_req[0].num_cols = 5'(num_cols);
        sif.vec_req[0].row_id = 5'(row_id);
        sif.vec_req[0].col_id = 5'd0;
        sif.vec_req[0].row_or_col = 1'b1;
        
        for (int i = 0; i < NUM_COLS; i++) begin
            sif.vec_req[0].wdata[i] = base_data + i;
        end
        
        // Wait for stall to clear
        while (sif.fe_vec_stall[0]) @(posedge clk);
        @(posedge clk);
        sif.vec_req[0] = '0;
        
        // Wait for write to complete
        repeat (15) @(posedge clk);
    endtask
    
    //==========================================================================
    // Read a row via vec_req (with debug)
    //==========================================================================
    task automatic vec_read_row(
        input int row_id,
        input int num_cols,
        output logic [15:0] rdata [NUM_COLS],
        output logic success,
        input logic debug = 0
    );
        automatic int timeout = 0;
        automatic int stall_cycles = 0;
        
        $display("  Reading row %0d with %0d cols", row_id, num_cols+1);
        
        sif.vec_req[0].valid = 1'b1;
        sif.vec_req[0].write = 1'b0;
        sif.vec_req[0].spad_addr = 20'h0;
        sif.vec_req[0].num_rows = 5'd0;
        sif.vec_req[0].num_cols = 5'(num_cols);
        sif.vec_req[0].row_id = 5'(row_id);
        sif.vec_req[0].col_id = 5'd0;
        sif.vec_req[0].row_or_col = 1'b1;
        
        if (debug) begin
            $display("    Request sent, checking state BEFORE clock...");
            $display("    vec_req.valid=%b fe_vec_stall=%b fe_stall=%b",
                     sif.vec_req[0].valid, sif.fe_vec_stall[0], sif.fe_stall[0]);
            $display("    w_stall=%b r_stall=%b", sif.w_stall[0], sif.r_stall[0]);
        end
        
        // Wait for stall to clear (with timeout)
        while (sif.fe_vec_stall[0] && stall_cycles < 100) begin
            @(posedge clk);
            stall_cycles++;
            if (debug) $display("    [stall %0d] fe_vec_stall=%b", stall_cycles, sif.fe_vec_stall[0]);
        end
        if (stall_cycles >= 100) begin
            $display("    WARN: stall timeout");
        end
        if (stall_cycles > 0) begin
            $display("    Stalled for %0d cycles", stall_cycles);
        end
        
        @(posedge clk);
        
        if (debug) begin
            $display("    After 1 clock: fe_req.valid=%b head_stomach_req.valid=%b",
                     sif.fe_req[0].valid, sif.head_stomach_req[0].valid);
        end
        
        sif.vec_req[0] = '0;
        
        // Wait for response
        success = 0;
        while (timeout < 100) begin
            @(posedge clk);
            if (debug && timeout < 20) begin
                $display("    [%0d] fe_req=%b head=%b wxbar=%b cntrl=%b sram=%b rxbar=%b tail=%b res=%b",
                    timeout,
                    sif.fe_req[0].valid,
                    sif.head_stomach_req[0].valid,
                    sif.xbar_cntrl_req[0].valid,
                    sif.cntrl_spad_req[0].valid,
                    sif.spad_xbar_req[0].valid,
                    sif.stomach_tail_res[0].valid,
                    sif.fe_res[0].valid,
                    sif.vec_res[0].valid);
            end
            if (sif.vec_res[0].valid) begin
                for (int i = 0; i < NUM_COLS; i++)
                    rdata[i] = sif.vec_res[0].rdata[i];
                success = 1;
                return;
            end
            timeout++;
        end
        $display("    WARN: response timeout after %0d cycles", timeout);
    endtask
    
    //==========================================================================
    // Test: Simple 1x1 write/read
    //==========================================================================
    task automatic test_1x1();
        automatic logic [15:0] rdata [NUM_COLS];
        automatic logic success;
        
        $display("\n[TEST] 1x1 Write/Read");
        do_reset();
        
        vec_write_row(0, 0, 16'h1000);
        vec_read_row(0, 0, rdata, success);
        
        if (!success) begin
            $display("  [FAIL] No response");
            tests_failed++;
        end else if (rdata[0] == 16'h1000) begin
            $display("  [PASS] rdata[0]=0x%04X", rdata[0]);
            tests_passed++;
        end else begin
            $display("  [FAIL] rdata[0]=0x%04X, expected 0x1000", rdata[0]);
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Test: 1x4 write/read
    //==========================================================================
    task automatic test_1x4();
        automatic logic [15:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;
        
        $display("\n[TEST] 1x4 Write/Read");
        do_reset();
        
        vec_write_row(0, 3, 16'h2000);  // num_cols=3 means 4 columns
        vec_read_row(0, 3, rdata, success);
        
        if (!success) begin
            $display("  [FAIL] No response");
            tests_failed++;
            return;
        end
        
        for (int i = 0; i <= 3; i++) begin
            $display("  rdata[%0d] = 0x%04X (expected 0x%04X)", i, rdata[i], 16'h2000 + i);
            if (rdata[i] != 16'h2000 + i) errors++;
        end
        
        if (errors == 0) begin
            $display("  [PASS]");
            tests_passed++;
        end else begin
            $display("  [FAIL] %0d errors", errors);
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Test: 1x8 write/read
    //==========================================================================
    task automatic test_1x8();
        automatic logic [15:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;
        
        $display("\n[TEST] 1x8 Write/Read");
        do_reset();
        
        vec_write_row(0, 7, 16'h3000);  // num_cols=7 means 8 columns
        vec_read_row(0, 7, rdata, success);
        
        if (!success) begin
            $display("  [FAIL] No response");
            tests_failed++;
            return;
        end
        
        for (int i = 0; i <= 7; i++) begin
            $display("  rdata[%0d] = 0x%04X (expected 0x%04X)", i, rdata[i], 16'h3000 + i);
            if (rdata[i] != 16'h3000 + i) errors++;
        end
        
        if (errors == 0) begin
            $display("  [PASS]");
            tests_passed++;
        end else begin
            $display("  [FAIL] %0d errors", errors);
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Test: Multiple rows
    //==========================================================================
    task automatic test_4x4();
        automatic logic [15:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;
        
        $display("\n[TEST] 4x4 Write/Read (4 separate rows)");
        do_reset();
        
        // Write 4 rows
        for (int r = 0; r < 4; r++) begin
            vec_write_row(r, 3, 16'(r * 256 + 16'h4000));
        end
        
        // Extra wait for writes to complete
        repeat (20) @(posedge clk);
        
        // Read back and verify
        for (int r = 0; r < 4; r++) begin
            // Enable debug for all rows to see pattern
            vec_read_row(r, 3, rdata, success, 1);
            
            if (!success) begin
                $display("  [FAIL] No response for row %0d", r);
                $display("    fe_req.valid=%b head_stomach_req.valid=%b", 
                         sif.fe_req[0].valid, sif.head_stomach_req[0].valid);
                $display("    cntrl_spad_req.valid=%b spad_xbar_req.valid=%b",
                         sif.cntrl_spad_req[0].valid, sif.spad_xbar_req[0].valid);
                $display("    stomach_tail_res.valid=%b fe_res.valid=%b",
                         sif.stomach_tail_res[0].valid, sif.fe_res[0].valid);
                errors++;
                continue;
            end
            
            for (int c = 0; c <= 3; c++) begin
                automatic logic [15:0] expected = 16'(r * 256 + 16'h4000 + c);
                if (rdata[c] != expected) begin
                    $display("  Row %0d Col %0d: got 0x%04X, expected 0x%04X", r, c, rdata[c], expected);
                    errors++;
                end
            end
            
            // Wait between reads to let pipeline drain
            repeat (5) @(posedge clk);
        end
        
        if (errors == 0) begin
            $display("  [PASS] All 4 rows verified");
            tests_passed++;
        end else begin
            $display("  [FAIL] %0d errors", errors);
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Debug: Trace signals during write
    //==========================================================================
    task automatic test_debug_trace();
        $display("\n[TEST] Debug Trace - Watch signal flow");
        do_reset();
        
        $display("  Sending write request...");
        sif.vec_req[0].valid = 1'b1;
        sif.vec_req[0].write = 1'b1;
        sif.vec_req[0].spad_addr = 20'h0;
        sif.vec_req[0].num_rows = 5'd0;
        sif.vec_req[0].num_cols = 5'd3;  // 4 cols
        sif.vec_req[0].row_id = 5'd0;
        sif.vec_req[0].col_id = 5'd0;
        sif.vec_req[0].row_or_col = 1'b1;
        sif.vec_req[0].wdata[0] = 16'hAAAA;
        sif.vec_req[0].wdata[1] = 16'hBBBB;
        sif.vec_req[0].wdata[2] = 16'hCCCC;
        sif.vec_req[0].wdata[3] = 16'hDDDD;
        
        repeat (3) @(posedge clk);
        
        $display("  vec_req.valid = %b", sif.vec_req[0].valid);
        $display("  fe_req.valid = %b", sif.fe_req[0].valid);
        $display("  fe_req.xbar.valid_mask = 0x%08X", sif.fe_req[0].xbar.valid_mask);
        $display("  fe_req.xbar.slot_mask[0] = %0d", sif.fe_req[0].xbar.slot_mask[0]);
        $display("  fe_req.xbar.slot_mask[1] = %0d", sif.fe_req[0].xbar.slot_mask[1]);
        $display("  fe_req.xbar.slot_mask[2] = %0d", sif.fe_req[0].xbar.slot_mask[2]);
        $display("  fe_req.xbar.slot_mask[3] = %0d", sif.fe_req[0].xbar.slot_mask[3]);
        $display("  fe_req.wdata[0] = 0x%04X", sif.fe_req[0].wdata[0]);
        $display("  fe_req.wdata[1] = 0x%04X", sif.fe_req[0].wdata[1]);
        
        sif.vec_req[0] = '0;
        
        $display("  [INFO] Debug trace complete");
        tests_passed++;
    endtask
    
    //==========================================================================
    // Main
    //==========================================================================
    initial begin
        $display("\n");
        $display("# ============================================");
        $display("# FRONTEND + BODY INTEGRATION TEST");
        $display("# ============================================");
        
        test_debug_trace();
        test_1x1();
        test_1x4();
        test_1x8();
        test_4x4();
        
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
    
    // Timeout
    initial begin
        #100000;
        $display("\n[TIMEOUT]\n");
        $finish;
    end

endmodule