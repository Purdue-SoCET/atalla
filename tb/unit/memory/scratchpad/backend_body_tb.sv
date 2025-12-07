`timescale 1ps/1ps

`include "scpad_if.sv"

module backend_body_tb;
    import scpad_pkg::*;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    
    // All three: Frontend + Backend + Body
    frontend #(.IDX(0)) u_frontend (.fvif(sif), .fsif(sif));
    backend #(.IDX(0)) u_backend (.bshif(sif), .bbif(sif), .bdrif(sif));
    body #(.IDX(0)) u_body (.bif(sif));
    
    int sram_writes = 0;
    int dram_requests = 0;
    
    initial begin
        $display("\n# ============================================");
        $display("# FRONTEND + BACKEND + BODY INTEGRATION TEST");
        $display("# ============================================\n");
        
        // Init
        n_rst = 0;
        sif.sched_req[0] = '0;
        sif.dram_be_stall[0] = '0;
        sif.dram_be_res[0] = '0;
        sif.vec_req[0] = '0;  // Frontend input (not fe_req directly)
        
        repeat (5) @(posedge clk);
        n_rst = 1;
        @(posedge clk);
        
        $display("After reset:");
        $display("  be_stall = %b (driven by head)", sif.be_stall[0]);
        $display("  be_req.valid = %b", sif.be_req[0].valid);
        
        // Send DMA LOAD request (1x1)
        $display("\n=== DMA LOAD 1x1 ===");
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b0;  // LOAD = DRAM->SRAM
        sif.sched_req[0].spad_addr = 20'd0;
        sif.sched_req[0].dram_addr = 32'd0;
        sif.sched_req[0].num_rows = 5'd0;
        sif.sched_req[0].num_cols = 5'd0;
        sif.sched_req[0].scpad_id = '0;
        
        // Run until completion or timeout
        for (int cycle = 0; cycle < 100; cycle++) begin
            @(posedge clk);
            
            // Monitor key signals
            if (cycle < 30 || sif.be_dram_req[0].valid || sif.be_req[0].valid || sif.sched_res[0].valid) begin
                $display("  [%0d] dram_req=%b be_req=%b(w=%b) be_stall=%b head=%b sched_res=%b",
                    cycle,
                    sif.be_dram_req[0].valid,
                    sif.be_req[0].valid, sif.be_req[0].write,
                    sif.be_stall[0],
                    sif.head_stomach_req[0].valid,
                    sif.sched_res[0].valid);
            end
            
            // Respond to DRAM request
            if (sif.be_dram_req[0].valid) begin
                dram_requests++;
                $display("    -> DRAM request #%0d, id=%0d", dram_requests, sif.be_dram_req[0].id);
                sif.dram_be_res[0].valid = 1'b1;
                sif.dram_be_res[0].id = sif.be_dram_req[0].id;
                sif.dram_be_res[0].rdata = {16'h1004, 16'h1003, 16'h1002, 16'h1001};
            end else begin
                sif.dram_be_res[0].valid = 1'b0;
            end
            
            // Count SRAM writes (be_req going INTO body)
            if (sif.be_req[0].valid && sif.be_req[0].write) begin
                sram_writes++;
                $display("    -> SRAM write #%0d, wdata[0]=0x%04X", sram_writes, sif.be_req[0].wdata[0]);
            end
            
            // Check completion
            if (sif.sched_res[0].valid) begin
                $display("    -> DMA complete!");
                break;
            end
        end
        
        // Clear request
        sif.sched_req[0].valid = 1'b0;
        
        // Wait and verify data was written
        repeat (20) @(posedge clk);
        
        $display("\n=== VERIFY: Read back via VEC ===");
        sif.vec_req[0].valid = 1'b1;
        sif.vec_req[0].write = 1'b0;
        sif.vec_req[0].spad_addr = 20'd0;
        sif.vec_req[0].num_rows = 5'd0;
        sif.vec_req[0].num_cols = 5'd0;
        sif.vec_req[0].row_id = 5'd0;
        sif.vec_req[0].col_id = 5'd0;
        sif.vec_req[0].row_or_col = 1'b1;
        
        @(posedge clk);
        sif.vec_req[0] = '0;
        
        // Wait for response
        for (int i = 0; i < 50; i++) begin
            @(posedge clk);
            if (sif.vec_res[0].valid) begin
                $display("  VEC read response: rdata[0]=0x%04X", sif.vec_res[0].rdata[0]);
                break;
            end
        end
        
        $display("\n=== SUMMARY ===");
        $display("  DRAM requests: %0d", dram_requests);
        $display("  SRAM writes: %0d", sram_writes);
        
        if (sram_writes >= 1) begin
            $display("  [PASS] Frontend+Backend+Body DMA LOAD works!");
        end else begin
            $display("  [FAIL] No SRAM writes detected");
        end
        
        $display("\n# ============================================\n");
        $finish;
    end
    
    // Timeout
    initial begin
        #50000;
        $display("\n[TIMEOUT]\n");
        $finish;
    end

endmodule