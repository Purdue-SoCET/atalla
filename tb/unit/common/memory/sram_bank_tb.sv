`timescale 1ps/1ps

module sram_bank_tb;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    // SRAM bank signals
    logic busy;
    logic ren, wen;
    logic [12:0] raddr, waddr;
    logic rdone, wdone;
    logic [15:0] rdata, wdata;
    
    // Instantiate SRAM bank
    sram_bank #(
        .READ_LATENCY(2), 
        .WRITE_LATENCY(2), 
        .HEIGHT(8192),  // 2^13
        .WIDTH(16)
    ) DUT (
        .clk(clk), 
        .n_rst(n_rst), 
        .busy(busy),
        .ren(ren),
        .raddr(raddr),
        .rdone(rdone),
        .rdata(rdata),
        .wen(wen),
        .waddr(waddr),
        .wdone(wdone),
        .wdata(wdata)
    );
    
    int tests_passed = 0;
    int tests_failed = 0;
    
    task automatic do_reset();
        n_rst = 0;
        ren = 0;
        wen = 0;
        raddr = 0;
        waddr = 0;
        wdata = 0;
        repeat (5) @(posedge clk);
        n_rst = 1;
        @(posedge clk);
    endtask
    
    //==========================================================================
    // Test: Simple write then read
    //==========================================================================
    initial begin
        $display("\n");
        $display("# ============================================");
        $display("# SRAM_BANK DIRECT TEST");
        $display("# ============================================\n");
        
        do_reset();
        
        // === WRITE ===
        $display("[TEST] Write 0xBEEF to address 0");
        waddr = 13'd0;
        wdata = 16'hBEEF;
        wen = 1;
        @(posedge clk);
        wen = 0;
        
        $display("  Waiting for wdone...");
        while (!wdone) @(posedge clk);
        $display("  [INFO] Write complete (wdone=1)");
        
        repeat (3) @(posedge clk);  // Gap
        
        // === READ ===
        $display("\n[TEST] Read from address 0");
        raddr = 13'd0;
        ren = 1;
        @(posedge clk);
        ren = 0;
        
        $display("  Waiting for rdone...");
        while (!rdone) @(posedge clk);
        $display("  [INFO] Read complete (rdone=1), rdata=0x%04X", rdata);
        
        if (rdata == 16'hBEEF) begin
            $display("  [PASS] Read data matches written data");
            tests_passed++;
        end else begin
            $display("  [FAIL] rdata=0x%04X, expected 0xBEEF", rdata);
            tests_failed++;
        end
        
        // === WRITE to different address ===
        repeat (3) @(posedge clk);
        $display("\n[TEST] Write 0xCAFE to address 100");
        waddr = 13'd100;
        wdata = 16'hCAFE;
        wen = 1;
        @(posedge clk);
        wen = 0;
        
        while (!wdone) @(posedge clk);
        $display("  [INFO] Write complete");
        
        repeat (3) @(posedge clk);
        
        // === READ from address 100 ===
        $display("\n[TEST] Read from address 100");
        raddr = 13'd100;
        ren = 1;
        @(posedge clk);
        ren = 0;
        
        while (!rdone) @(posedge clk);
        $display("  [INFO] rdata=0x%04X", rdata);
        
        if (rdata == 16'hCAFE) begin
            $display("  [PASS] Read data matches");
            tests_passed++;
        end else begin
            $display("  [FAIL] rdata=0x%04X, expected 0xCAFE", rdata);
            tests_failed++;
        end
        
        // === Verify address 0 still has BEEF ===
        repeat (3) @(posedge clk);
        $display("\n[TEST] Verify address 0 still has 0xBEEF");
        raddr = 13'd0;
        ren = 1;
        @(posedge clk);
        ren = 0;
        
        while (!rdone) @(posedge clk);
        $display("  [INFO] rdata=0x%04X", rdata);
        
        if (rdata == 16'hBEEF) begin
            $display("  [PASS] Address 0 unchanged");
            tests_passed++;
        end else begin
            $display("  [FAIL] rdata=0x%04X, expected 0xBEEF", rdata);
            tests_failed++;
        end
        
        $display("\n");
        $display("# ============ TEST SUMMARY ============");
        $display("#   Total: %0d | Passed: %0d | Failed: %0d", 
                 tests_passed + tests_failed, tests_passed, tests_failed);
        if (tests_failed == 0)
            $display("#   ALL TESTS PASSED");
        else
            $display("#   SOME TESTS FAILED");
        $display("# ======================================\n");
        
        $finish;
    end
    
    // Timeout
    initial begin
        #5000;
        $display("\n[TIMEOUT]\n");
        $finish;
    end

endmodule