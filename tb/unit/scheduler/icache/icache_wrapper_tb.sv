// `timescale 1ns/1ps
// `include "caches_pkg.sv"

// module tb_icache_wrapper;

//     // --- Parameters ---
//     parameter ADDR_WIDTH    = 32;
//     parameter INSTR_WIDTH   = 160;
//     parameter ROB_DEPTH     = 16;
//     parameter FRQ_DEPTH     = 8;
//     parameter MRQ_DEPTH     = 8;
//     parameter CACHE_RW_SIZE = 512;
//     parameter NUM_BANKS     = 1; 
    
//     // --- Clock & Reset ---
//     logic clk;
//     logic rst_n;

//     // --- CPU Fetch Interface ---
//     logic                   cpu_fetch_valid;
//     logic [ADDR_WIDTH-1:0]  cpu_fetch_pc;
//     logic                   cpu_fetch_ready;

//     // --- CPU Receive Interface ---
//     logic                   cpu_instr_valid;
//     logic [INSTR_WIDTH-1:0] cpu_instr_data;
//     logic [ADDR_WIDTH-1:0]  cpu_instr_pc;
//     logic                   cpu_instr_ready;

//     // --- Main Memory Interface ---
//     logic [NUM_BANKS-1:0]                       ram_mem_REN;
//     logic [NUM_BANKS-1:0]                       ram_mem_WEN;
//     logic [NUM_BANKS-1:0][ADDR_WIDTH-1:0]       ram_mem_addr;
//     logic [NUM_BANKS-1:0][CACHE_RW_SIZE-1:0]    ram_mem_store;
//     logic [NUM_BANKS-1:0][CACHE_RW_SIZE-1:0]    ram_mem_data;
//     logic [NUM_BANKS-1:0]                       ram_mem_complete;

//     // --- DUT Instantiation ---
//     icache_wrapper #(
//         .ADDR_WIDTH(ADDR_WIDTH),
//         .INSTR_WIDTH(INSTR_WIDTH),
//         .ROB_DEPTH(ROB_DEPTH),
//         .FRQ_DEPTH(FRQ_DEPTH),
//         .MRQ_DEPTH(MRQ_DEPTH)
//     ) dut (
//         .clk(clk),
//         .rst_n(rst_n),
//         .cpu_fetch_valid(cpu_fetch_valid),
//         .cpu_fetch_pc(cpu_fetch_pc),
//         .cpu_fetch_ready(cpu_fetch_ready),
//         .cpu_instr_valid(cpu_instr_valid),
//         .cpu_instr_data(cpu_instr_data),
//         .cpu_instr_pc(cpu_instr_pc),
//         .cpu_instr_ready(cpu_instr_ready),
//         .ram_mem_REN(ram_mem_REN),
//         .ram_mem_WEN(ram_mem_WEN),
//         .ram_mem_addr(ram_mem_addr),
//         .ram_mem_store(ram_mem_store),
//         .ram_mem_data(ram_mem_data),
//         .ram_mem_complete(ram_mem_complete)
//     );

//     // --- Clock Generation ---
//     initial begin
//         clk = 0;
//         forever #5 clk = ~clk; // 100 MHz clock
//     end

//     // --- Simulated Main Memory (Latency Model) ---
//     parameter MEM_LATENCY = 20;
//     logic [7:0] mem_timer [NUM_BANKS-1:0];
//     logic       mem_busy  [NUM_BANKS-1:0];
//     logic [ADDR_WIDTH-1:0] mem_addr_latch [NUM_BANKS-1:0];

//     always_ff @(posedge clk or negedge rst_n) begin
//         if (!rst_n) begin
//             for (int i=0; i<NUM_BANKS; i++) begin
//                 mem_busy[i] <= 0;
//                 ram_mem_complete[i] <= 0;
//             end
//         end else begin
//             for (int i=0; i<NUM_BANKS; i++) begin
//                 if (ram_mem_REN[i] && !mem_busy[i]) begin
//                     mem_busy[i] <= 1;
//                     mem_timer[i] <= MEM_LATENCY;
//                     mem_addr_latch[i] <= ram_mem_addr[i];
//                 end
                
//                 if (mem_busy[i]) begin
//                     if (mem_timer[i] == 0) begin
//                         ram_mem_complete[i] <= 1'b1;
//                         for (int w=0; w<16; w++) begin
//                             ram_mem_data[i][w*32 +: 32] <= mem_addr_latch[i] + (w*4);
//                         end
//                         mem_busy[i] <= 1'b0;
//                     end else begin
//                         ram_mem_complete[i] <= 1'b0;
//                         mem_timer[i] <= mem_timer[i] - 1;
//                     end
//                 end else begin
//                     ram_mem_complete[i] <= 1'b0;
//                 end
//             end
//         end
//     end

//     // --- CPU Fetch Task ---
//     task issue_fetch(input logic [ADDR_WIDTH-1:0] pc);
//         begin
//             @(posedge clk);
//             while (!cpu_fetch_ready) @(posedge clk);
//             cpu_fetch_valid <= 1'b1;
//             cpu_fetch_pc    <= pc;
//             @(posedge clk);
//             cpu_fetch_valid <= 1'b0;
//         end
//     endtask

//     // --- Monitor: CPU Receive Logic ---
//     always_ff @(posedge clk or negedge rst_n) begin
//         if (!rst_n) begin
//             cpu_instr_ready <= 1'b1;
//         end else if (cpu_instr_valid && cpu_instr_ready) begin
//             $display("[TIME: %0t] CPU Received PC: 0x%0h | Data: 0x%0h", $time, cpu_instr_pc, cpu_instr_data);
//         end
//     end

//     // --- Main Test Sequence ---
//     initial begin
//         $display("==================================================");
//         $display("   STARTING I-CACHE WRAPPER TESTBENCH");
//         $display("==================================================");

//         cpu_fetch_valid = 0;
//         cpu_fetch_pc = 0;
//         rst_n = 0;
        
//         repeat(5) @(posedge clk);
//         rst_n = 1;
//         repeat(2) @(posedge clk);

//         $display("\n[TEST 1] Issuing Single Aligned Fetch (PC = 0x0)");
//         issue_fetch(32'h0000_0000);
//         wait(cpu_instr_valid);
//         @(posedge clk); 

//         $display("\n[TEST 2] Issuing Unaligned Split Fetch (PC = 0x30 / 48d)");
//         issue_fetch(32'h0000_0030);
//         wait(cpu_instr_valid);
//         @(posedge clk);

//         $display("\n[TEST 3] Bursting 6 requests into the pipeline");
//         fork
//             begin
//                 issue_fetch(32'h0000_0100); 
//                 issue_fetch(32'h0000_0114); 
//                 issue_fetch(32'h0000_0128); 
//                 issue_fetch(32'h0000_013C); 
//                 issue_fetch(32'h0000_0150); 
//                 issue_fetch(32'h0000_0164); 
//             end
//         join

//         repeat(6) begin
//             wait(cpu_instr_valid);
//             @(posedge clk);
//         end

//         $display("\n==================================================");
//         $display("   TESTBENCH COMPLETE");
//         $display("==================================================");
//         #100;
//         $finish;
//     end

//     // --- Timeout Watchdog ---
//     initial begin
//         #50000;
//         $display("\n[ERROR] Simulation Timeout! The pipeline likely hung due to a deadlock.");
//         $finish;
//     end

// endmodule