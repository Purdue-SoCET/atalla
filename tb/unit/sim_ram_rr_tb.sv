`timescale 1ns/1ps

module sim_ram_rr_tb;

    localparam int ADDR_WIDTH = 32;
    localparam int MEM_BYTES  = 64;
    localparam bit BIG_ENDIAN = 1'b1;   // 1 = big-endian, 0 = little-endian

    logic                  clk;
    logic                  rst_n;

    // I-cache interface
    logic                  ic_req_valid;
    logic                  ic_req_we;
    logic [ADDR_WIDTH-1:0] ic_req_addr;
    logic [31:0]           ic_req_wdata;
    logic [31:0]           ic_resp_rdata;
    logic                  ic_resp_hit;

    // D-cache interface
    logic                  dc_req_valid;
    logic                  dc_req_we;
    logic [ADDR_WIDTH-1:0] dc_req_addr;
    logic [31:0]           dc_req_wdata;
    logic [31:0]           dc_resp_rdata;
    logic                  dc_resp_hit;

    logic [31:0] exp_word0;
    logic [31:0] exp_word1;
    logic [31:0] exp_word2;
    logic [31:0] exp_word3;

    // DUT
    sim_ram_rr_32 #(
        .ADDR_WIDTH (ADDR_WIDTH),
        .MEM_BYTES  (MEM_BYTES),
        .INIT_FILE  ("tb/unit/mem_files/init_mem.hex"),
        .INIT_IS_HEX(1'b1),
        .DUMP_FILE  ("tb/unit/mem_files/final_mem.hex"),
        .BIG_ENDIAN (BIG_ENDIAN)
    ) dut (
        .clk          (clk),
        .rst_n        (rst_n),

        .ic_req_valid (ic_req_valid),
        .ic_req_we    (ic_req_we),
        .ic_req_addr  (ic_req_addr),
        .ic_req_wdata (ic_req_wdata),
        .ic_resp_rdata(ic_resp_rdata),
        .ic_resp_hit  (ic_resp_hit),

        .dc_req_valid (dc_req_valid),
        .dc_req_we    (dc_req_we),
        .dc_req_addr  (dc_req_addr),
        .dc_req_wdata (dc_req_wdata),
        .dc_resp_rdata(dc_resp_rdata),
        .dc_resp_hit  (dc_resp_hit)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    task clear_inputs;
        begin
            ic_req_valid = 1'b0;
            ic_req_we    = 1'b0;
            ic_req_addr  = '0;
            ic_req_wdata = '0;

            dc_req_valid = 1'b0;
            dc_req_we    = 1'b0;
            dc_req_addr  = '0;
            dc_req_wdata = '0;
        end
    endtask

    task check_value(
        input string who,
        input logic hit,
        input logic [31:0] got,
        input logic [31:0] expected
    );
        begin
            if (!hit) begin
                $display("[%0t] ERROR: %s expected hit=1 but got hit=0",
                         $time, who);
            end
            else if (got !== expected) begin
                $display("[%0t] ERROR: %s expected 0x%08h but got 0x%08h",
                         $time, who, expected, got);
            end
            else begin
                $display("[%0t] PASS : %s got expected value 0x%08h",
                         $time, who, got);
            end
        end
    endtask

    task icache_read(
        input  logic [31:0] addr,
        input  logic [31:0] expected
    );
        begin
            @(negedge clk);
            ic_req_valid = 1'b1;
            ic_req_we    = 1'b0;
            ic_req_addr  = addr;
            ic_req_wdata = 32'h0;

            @(posedge clk);
            #1;
            $display("[%0t] ICACHE READ  addr=0x%08h hit=%0d rdata=0x%08h",
                     $time, addr, ic_resp_hit, ic_resp_rdata);
            check_value("ICACHE READ", ic_resp_hit, ic_resp_rdata, expected);

            @(negedge clk);
            ic_req_valid = 1'b0;
            ic_req_addr  = '0;
        end
    endtask

    task dcache_read(
        input  logic [31:0] addr,
        input  logic [31:0] expected
    );
        begin
            @(negedge clk);
            dc_req_valid = 1'b1;
            dc_req_we    = 1'b0;
            dc_req_addr  = addr;
            dc_req_wdata = 32'h0;

            @(posedge clk);
            #1;
            $display("[%0t] DCACHE READ  addr=0x%08h hit=%0d rdata=0x%08h",
                     $time, addr, dc_resp_hit, dc_resp_rdata);
            check_value("DCACHE READ", dc_resp_hit, dc_resp_rdata, expected);

            @(negedge clk);
            dc_req_valid = 1'b0;
            dc_req_addr  = '0;
        end
    endtask

    task dcache_write(
        input logic [31:0] addr,
        input logic [31:0] data
    );
        begin
            @(negedge clk);
            dc_req_valid = 1'b1;
            dc_req_we    = 1'b1;
            dc_req_addr  = addr;
            dc_req_wdata = data;

            @(posedge clk);
            #1;
            $display("[%0t] DCACHE WRITE addr=0x%08h hit=%0d wdata=0x%08h",
                     $time, addr, dc_resp_hit, data);

            if (!dc_resp_hit) begin
                $display("[%0t] ERROR: DCACHE WRITE expected hit=1 but got hit=0",
                         $time);
            end

            @(negedge clk);
            dc_req_valid = 1'b0;
            dc_req_we    = 1'b0;
            dc_req_addr  = '0;
            dc_req_wdata = '0;
        end
    endtask

    task simultaneous_read(
        input logic [31:0] ic_addr,
        input logic [31:0] dc_addr
    );
        begin
            @(negedge clk);
            ic_req_valid = 1'b1;
            ic_req_we    = 1'b0;
            ic_req_addr  = ic_addr;

            dc_req_valid = 1'b1;
            dc_req_we    = 1'b0;
            dc_req_addr  = dc_addr;

            @(posedge clk);
            #1;
            $display("[%0t] BOTH READ    ic_addr=0x%08h dc_addr=0x%08h | ic_hit=%0d ic_rdata=0x%08h | dc_hit=%0d dc_rdata=0x%08h",
                     $time, ic_addr, dc_addr,
                     ic_resp_hit, ic_resp_rdata,
                     dc_resp_hit, dc_resp_rdata);

            @(negedge clk);
            ic_req_valid = 1'b0;
            ic_req_addr  = '0;
            dc_req_valid = 1'b0;
            dc_req_addr  = '0;
        end
    endtask

    task bad_read_test(input logic [31:0] addr);
        begin
            @(negedge clk);
            dc_req_valid = 1'b1;
            dc_req_we    = 1'b0;
            dc_req_addr  = addr;

            @(posedge clk);
            #1;
            $display("[%0t] BAD READ     addr=0x%08h hit=%0d rdata=0x%08h",
                     $time, addr, dc_resp_hit, dc_resp_rdata);

            @(negedge clk);
            dc_req_valid = 1'b0;
            dc_req_addr  = '0;
        end
    endtask

    initial begin
        clear_inputs();
        rst_n = 1'b0;

        if (BIG_ENDIAN) begin
            exp_word0 = 32'hDEADBEEF;
            exp_word1 = 32'h12345678;
            exp_word2 = 32'h44332211;
            exp_word3 = 32'hAABBCCDD;
        end
        else begin
            exp_word0 = 32'hEFBEADDE;
            exp_word1 = 32'h78563412;
            exp_word2 = 32'h11223344;
            exp_word3 = 32'hDDCCBBAA;
        end

        $display("==================================================");
        $display("Starting sim_ram_rr_32 testbench");
        $display("BIG_ENDIAN = %0d", BIG_ENDIAN);
        $display("==================================================");

        repeat (2) @(posedge clk);
        rst_n = 1'b1;
        $display("[%0t] Reset released", $time);

        // Initial reads from file contents
        icache_read(32'h0000_0000, exp_word0);
        dcache_read(32'h0000_0004, exp_word1);
        dcache_read(32'h0000_0008, exp_word2);
        icache_read(32'h0000_000C, exp_word3);

        // Write and read back
        dcache_write(32'h0000_0010, 32'hCAFEBABE);
        dcache_read (32'h0000_0010, 32'hCAFEBABE);
        icache_read (32'h0000_0010, 32'hCAFEBABE);

        // Simultaneous reads to observe arbitration
        simultaneous_read(32'h0000_0000, 32'h0000_0004);
        simultaneous_read(32'h0000_0000, 32'h0000_0004);

        // Bad accesses
        bad_read_test(32'h0000_0002); // unaligned
        bad_read_test(32'h0000_0100); // out of range for MEM_BYTES=64

        $display("==================================================");
        $display("Testbench complete");
        $display("Memory should dump at simulation exit");
        $display("==================================================");

        #20;
        $finish;
    end

endmodule