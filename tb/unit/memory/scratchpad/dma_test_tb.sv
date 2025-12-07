`timescale 1ps/1ps

`include "scpad_if.sv"

// Simple DMA test using initial block (not program block) for proper timing
module dma_test_tb;
    import scpad_pkg::*;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    scratchpad DUT (.sif(sif));
    
    int tests_passed = 0;
    int tests_failed = 0;
    
    task automatic do_reset();
        n_rst = 0;
        sif.vec_req[0] = '0;
        sif.vec_req[1] = '0;
        sif.sched_req[0] = '0;
        sif.sched_req[1] = '0;
        sif.dram_be_stall[0] = '0;
        sif.dram_be_stall[1] = '0;
        sif.dram_be_res[0] = '0;
        sif.dram_be_res[1] = '0;
        repeat (5) @(posedge clk);
        n_rst = 1;
        @(posedge clk);
    endtask
    
    //==========================================================================
    // DMA LOAD Test
    //==========================================================================
    task automatic test_dma_load(input int num_rows, input int num_cols);
        automatic int sram_writes = 0;
        automatic int dram_requests = 0;
        automatic int timeout = 0;
        automatic logic [7:0] req_id;
        automatic int row;
        automatic int sub;
        
        $display("\n[TEST] DMA_LOAD %0dx%0d", num_rows+1, num_cols+1);
        
        // Start DMA LOAD
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b0;  // LOAD = DRAM->SRAM
        sif.sched_req[0].spad_addr = 20'd0;
        sif.sched_req[0].dram_addr = 32'd0;
        sif.sched_req[0].num_rows = 5'(num_rows);
        sif.sched_req[0].num_cols = 5'(num_cols);
        sif.sched_req[0].scpad_id = '0;
        
        sif.dram_be_stall[0] = 1'b0;
        sif.dram_be_res[0] = '0;
        
        // Run until completion
        while (!sif.sched_res[0].valid && timeout < 500) begin
            @(posedge clk);
            
            // Debug first 20 cycles
            if (timeout < 20) begin
                $display("  [%0d] dram_req=%b be_req=%b(w=%b) sched_res=%b",
                    timeout,
                    sif.be_dram_req[0].valid,
                    sif.be_req[0].valid, sif.be_req[0].write,
                    sif.sched_res[0].valid);
            end
            
            // Respond to DRAM request IMMEDIATELY (same delta)
            if (sif.be_dram_req[0].valid) begin
                req_id = sif.be_dram_req[0].id;
                row = req_id[7:3];
                sub = req_id[2:0];
                
                dram_requests++;
                $display("    -> DRAM req #%0d (id=%0d row=%0d sub=%0d)", 
                         dram_requests, req_id, row, sub);
                
                sif.dram_be_res[0].valid = 1'b1;
                sif.dram_be_res[0].id = req_id;
                sif.dram_be_res[0].rdata = {
                    16'((row << 8) | (sub * 4 + 4)),
                    16'((row << 8) | (sub * 4 + 3)),
                    16'((row << 8) | (sub * 4 + 2)),
                    16'((row << 8) | (sub * 4 + 1))
                };
            end else begin
                sif.dram_be_res[0].valid = 1'b0;
            end
            
            // Count SRAM writes
            if (sif.be_req[0].valid && sif.be_req[0].write) begin
                sram_writes++;
                $display("    -> SRAM write #%0d", sram_writes);
            end
            
            timeout++;
        end
        
        // Cleanup
        sif.sched_req[0] = '0;
        sif.dram_be_res[0] = '0;
        repeat (5) @(posedge clk);
        
        // Check result
        if (sram_writes == (num_rows + 1)) begin
            $display("  [PASS] DRAM requests: %0d, SRAM writes: %0d/%0d", 
                     dram_requests, sram_writes, num_rows + 1);
            tests_passed++;
        end else begin
            $display("  [FAIL] SRAM writes: %0d/%0d (timeout=%0d)", 
                     sram_writes, num_rows + 1, timeout);
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Verify data with VEC read
    //==========================================================================
    task automatic verify_vec_read(input int row, input int expected_base);
        automatic int timeout = 0;
        
        sif.vec_req[0].valid = 1'b1;
        sif.vec_req[0].write = 1'b0;
        sif.vec_req[0].spad_addr = 20'd0;
        sif.vec_req[0].num_rows = 5'd0;
        sif.vec_req[0].num_cols = 5'd0;
        sif.vec_req[0].row_id = 5'(row);
        sif.vec_req[0].col_id = 5'd0;
        sif.vec_req[0].row_or_col = 1'b1;
        
        while (sif.fe_vec_stall[0]) @(posedge clk);
        @(posedge clk);
        sif.vec_req[0] = '0;
        
        while (!sif.vec_res[0].valid && timeout < 100) begin
            @(posedge clk);
            timeout++;
        end
        
        if (sif.vec_res[0].valid) begin
            $display("  VEC read row %0d: rdata[0]=0x%04X (expected 0x%04X)", 
                     row, sif.vec_res[0].rdata[0], expected_base);
        end else begin
            $display("  VEC read row %0d: TIMEOUT", row);
        end
    endtask
    
    //==========================================================================
    // Main
    //==========================================================================
    initial begin
        $display("\n");
        $display("# ============================================");
        $display("# DMA TEST (initial block, not program block)");
        $display("# ============================================");
        
        do_reset();
        
        // Test 1x1
        test_dma_load(0, 0);
        verify_vec_read(0, 16'h0001);
        
        do_reset();
        
        // Test 1x8
        test_dma_load(0, 7);
        verify_vec_read(0, 16'h0001);
        
        do_reset();
        
        // Test 4x8
        test_dma_load(3, 7);
        verify_vec_read(0, 16'h0001);
        verify_vec_read(1, 16'h0101);
        verify_vec_read(2, 16'h0201);
        verify_vec_read(3, 16'h0301);
        
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
        #500000;
        $display("\n[TIMEOUT]\n");
        $finish;
    end

endmodule