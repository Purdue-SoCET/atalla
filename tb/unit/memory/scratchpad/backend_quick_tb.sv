`timescale 1ps/1ps

`include "scpad_if.sv"

module backend_quick_tb;
    import scpad_pkg::*;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    
    // Just backend
    backend #(.IDX(0)) DUT (.bshif(sif), .bbif(sif), .bdrif(sif));
    
    initial begin
        $display("\n# ============================================");
        $display("# BACKEND QUICK DEBUG TEST");
        $display("# ============================================\n");
        
        // Init
        n_rst = 0;
        sif.sched_req[0] = '0;
        sif.dram_be_stall[0] = '0;
        sif.dram_be_res[0] = '0;
        sif.be_stall[0] = '0;
        sif.be_res[0] = '0;
        
        repeat (5) @(posedge clk);
        n_rst = 1;
        @(posedge clk);
        
        $display("After reset:");
        $display("  be_dram_req.valid = %b", sif.be_dram_req[0].valid);
        $display("  be_req.valid = %b", sif.be_req[0].valid);
        
        // Send DMA LOAD request
        $display("\nSending DMA LOAD request (1x1)...");
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b0;  // LOAD = DRAM->SRAM
        sif.sched_req[0].spad_addr = 20'd0;
        sif.sched_req[0].dram_addr = 32'd0;
        sif.sched_req[0].num_rows = 5'd0;
        sif.sched_req[0].num_cols = 5'd0;
        sif.sched_req[0].scpad_id = '0;
        
        // Watch for DRAM request
        repeat (20) begin
            @(posedge clk);
            $display("  t=%0t: be_dram_req.valid=%b be_req.valid=%b be_req.write=%b sched_res.valid=%b",
                     $time, sif.be_dram_req[0].valid, sif.be_req[0].valid, 
                     sif.be_req[0].write, sif.sched_res[0].valid);
            
            // Respond to DRAM request
            if (sif.be_dram_req[0].valid) begin
                $display("    -> Got DRAM request! id=%0d", sif.be_dram_req[0].id);
                sif.dram_be_res[0].valid = 1'b1;
                sif.dram_be_res[0].id = sif.be_dram_req[0].id;
                sif.dram_be_res[0].rdata = {16'hDEAD, 16'hBEEF, 16'hCAFE, 16'hF00D};
            end else begin
                sif.dram_be_res[0].valid = 1'b0;
            end
            
            // Check for SRAM write
            if (sif.be_req[0].valid && sif.be_req[0].write) begin
                $display("    -> Got SRAM write! wdata[0]=0x%04X", sif.be_req[0].wdata[0]);
            end
        end
        
        $display("\n# ============================================\n");
        $finish;
    end

endmodule