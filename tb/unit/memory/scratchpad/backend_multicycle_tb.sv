`timescale 1ps/1ps

`include "scpad_if.sv"

// Test backend with multi-cycle SRAM latency (simulates body pipeline)
module backend_multicycle_tb;
    import scpad_pkg::*;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    backend #(.IDX(0)) DUT (.bshif(sif), .bbif(sif), .bdrif(sif));
    
    // Track be_req read requests in a queue to simulate multi-cycle latency
    typedef struct {
        logic valid;
        int row_id;
        int cycle_issued;
    } pending_req_t;
    
    localparam SRAM_LATENCY = 8;  // Match body latency (~8 cycles)
    pending_req_t pending_queue[$];
    
    int tests_passed = 0;
    int tests_failed = 0;
    
    //==========================================================================
    // Reset
    //==========================================================================
    task automatic do_reset();
        n_rst = 0;
        sif.sched_req[0] = '0;
        sif.dram_be_stall[0] = '0;
        sif.dram_be_res[0] = '0;
        sif.be_stall[0] = '0;
        sif.be_res[0] = '0;
        pending_queue.delete();
        repeat (5) @(posedge clk);
        n_rst = 1;
        @(posedge clk);
    endtask
    
    //==========================================================================
    // DMA STORE Test with multi-cycle SRAM latency
    //==========================================================================
    task automatic test_dma_store(input int num_rows, input int num_cols);
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;
        automatic int total_dram_writes = chunks_per_row * (num_rows + 1);
        automatic int be_req_read_count = 0;
        automatic int be_res_count = 0;
        automatic int dram_write_count = 0;
        automatic int timeout = 0;
        automatic int cycle = 0;
        
        $display("\n[TEST] DMA_STORE %0dx%0d (SRAM latency=%0d cycles)", 
                 num_rows+1, num_cols+1, SRAM_LATENCY);
        $display("  Expected: %0d be_req reads, %0d DRAM writes", num_rows+1, total_dram_writes);
        
        // Start DMA STORE
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b1;  // STORE = SRAM->DRAM
        sif.sched_req[0].spad_addr = 20'd0;
        sif.sched_req[0].dram_addr = 32'd0;
        sif.sched_req[0].num_rows = 5'(num_rows);
        sif.sched_req[0].num_cols = 5'(num_cols);
        sif.sched_req[0].scpad_id = '0;
        
        sif.dram_be_stall[0] = 1'b0;
        sif.be_stall[0] = 1'b0;
        sif.be_res[0] = '0;
        
        // Main loop
        while (!sif.sched_res[0].valid && timeout < 500) begin
            @(posedge clk);
            cycle++;
            
            // Capture be_req reads and queue them
            if (sif.be_req[0].valid && !sif.be_req[0].write) begin
                automatic pending_req_t req;
                req.valid = 1;
                req.row_id = sif.be_req[0].row_id;
                req.cycle_issued = cycle;
                pending_queue.push_back(req);
                be_req_read_count++;
                
                if (cycle < 30)
                    $display("  [%0d] be_req READ row=%0d (queued, %0d pending)", 
                             cycle, req.row_id, pending_queue.size());
            end
            
            // Check if any queued request is ready (latency elapsed)
            sif.be_res[0].valid = 1'b0;
            if (pending_queue.size() > 0) begin
                if (cycle >= pending_queue[0].cycle_issued + SRAM_LATENCY) begin
                    automatic pending_req_t req = pending_queue.pop_front();
                    
                    // Generate be_res
                    sif.be_res[0].valid = 1'b1;
                    sif.be_res[0].write = 1'b0;
                    for (int i = 0; i < NUM_COLS; i++)
                        sif.be_res[0].rdata[i] = 16'((req.row_id * 32) + i + 1);
                    
                    be_res_count++;
                    if (cycle < 50)
                        $display("  [%0d] be_res for row=%0d", cycle, req.row_id);
                end
            end
            
            // Count DRAM writes
            if (sif.be_dram_req[0].valid && sif.be_dram_req[0].write) begin
                dram_write_count++;
                if (cycle < 50)
                    $display("  [%0d] DRAM write #%0d", cycle, dram_write_count);
            end
            
            // Debug after inactivity
            if (timeout > 0 && timeout % 100 == 0) begin
                $display("  [%0d] STALL: be_req_reads=%0d be_res=%0d dram_writes=%0d/%0d pending=%0d",
                         cycle, be_req_read_count, be_res_count, dram_write_count, 
                         total_dram_writes, pending_queue.size());
                $display("    be_req.valid=%b be_stall=%b sched_res=%b",
                         sif.be_req[0].valid, sif.be_stall[0], sif.sched_res[0].valid);
            end
            
            timeout++;
        end
        
        // Cleanup
        sif.sched_req[0] = '0;
        sif.be_res[0] = '0;
        repeat (5) @(posedge clk);
        
        // Results
        $display("  Result: be_req_reads=%0d, be_res=%0d, dram_writes=%0d/%0d",
                 be_req_read_count, be_res_count, dram_write_count, total_dram_writes);
        
        if (dram_write_count == total_dram_writes && be_req_read_count == num_rows + 1) begin
            $display("  [PASS]");
            tests_passed++;
        end else begin
            $display("  [FAIL] Expected %0d be_req reads, %0d dram writes",
                     num_rows + 1, total_dram_writes);
            tests_failed++;
        end
    endtask
    
    //==========================================================================
    // Main
    //==========================================================================
    initial begin
        $display("\n");
        $display("# ============================================");
        $display("# BACKEND MULTI-CYCLE LATENCY TEST");
        $display("# ============================================");
        
        do_reset();
        test_dma_store(0, 0);   // 1x1
        
        do_reset();
        test_dma_store(0, 7);   // 1x8
        
        do_reset();
        test_dma_store(1, 7);   // 2x8
        
        do_reset();
        test_dma_store(3, 7);   // 4x8
        
        do_reset();
        test_dma_store(7, 7);   // 8x8
        
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