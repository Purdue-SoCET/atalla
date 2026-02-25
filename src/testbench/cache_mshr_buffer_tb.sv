`timescale 1ps/1ps
`include "cache_types_pkg.svh"
localparam CLK_PERIOD = 10;

module cache_mshr_buffer_tb ();

    logic tb_clk;
    logic tb_nrst;
    logic tb_miss;
    logic [BANKS_LEN-1:0] tb_bank_id;
    in_mem_instr tb_mem_instr;
    logic tb_bank_free;
    mshr_reg tb_mshr_out;
    logic tb_stall;
    logic [UUID_SIZE-1:0] tb_mem_out_uuid;
    logic tb_buffer_empty;

    always begin
        tb_clk = 1'b0;
        #(CLK_PERIOD/2.0);
        tb_clk = 1'b1;
        #(CLK_PERIOD/2.0);
    end

    cache_mshr_buffer buffer (
        .CLK(tb_clk), 
        .nRST(tb_nrst), 
        .miss(tb_miss), 
        .bank_id(tb_bank_id),
        .mem_instr(tb_mem_instr), 
        .bank_free(tb_bank_free), 
        .uuid_out(tb_mem_out_uuid), 
        .mshr_out(tb_mshr_out), 
        .stall(tb_stall),
        .buffer_empty(tb_buffer_empty)
    );

    test PROG (
        .tb_clk(tb_clk), 
        .tb_nrst(tb_nrst), 
        .tb_miss(tb_miss), 
        .tb_bank_id(tb_bank_id),
        .tb_mem_instr(tb_mem_instr), 
        .tb_bank_free(tb_bank_free), 
        .tb_mem_out_uuid(tb_mem_out_uuid), 
        .tb_mshr_out(tb_mshr_out), 
        .tb_stall(tb_stall),
        .tb_buffer_empty(tb_buffer_empty)
    );

    bind cache_mshr_buffer confirm_uuid uuid_monitor (
        .CLK(CLK), 
        .nRST(nRST),
        .miss(miss), 
        .stall(stall),
        .uuid_out(uuid_out),
        .uuid(uuid)
    );

endmodule

program test (
    input logic tb_clk,
    output logic tb_nrst,
    output logic tb_miss,
    output logic [BANKS_LEN-1:0] tb_bank_id,
    output in_mem_instr tb_mem_instr,
    output logic tb_bank_free,
    input [UUID_SIZE-1:0] tb_mem_out_uuid, 
    input mshr_reg tb_mshr_out,
    input logic tb_stall,
    input logic tb_buffer_empty
);

    task reset_dut;
        begin
            tb_nrst = 0;
            tb_miss = 0;
            tb_bank_id = 0;
            tb_mem_instr = '0;
            tb_bank_free = 0;
            @(posedge tb_clk);
            @(posedge tb_clk);
            tb_nrst = 1;
            @(posedge tb_clk);
        end
    endtask

    initial begin
        $info("Starting MSHR Buffer Testbench...");
        reset_dut();

        // Basic Queue Operations
        $info("Test 1: Basic Push/Pop");
        tb_miss = 1;
        tb_bank_id = 1;
        tb_mem_instr = '{addr: '{tag: 32'hAAAA, index: 32'd1, block_offset: 2'd0, byte_offset: 2'd0}, rw_mode: 0, store_value: 32'h0};
        @(posedge tb_clk);
        tb_miss = 0;
        
        // Wait and check empty status goes down
        if (tb_buffer_empty !== 0) $fatal(1, "Basic Push: Buffer should not be empty!");
        // Pop
        tb_bank_free = 1;
        @(posedge tb_clk);
        tb_bank_free = 0;
        if (tb_buffer_empty !== 1) $fatal(1, "Basic Pop: Buffer should be empty after pop!");

        // Queue Saturation and Stall Verification
        $info("Test 2: Saturation and Stall Verification");
        reset_dut();
        for (int i = 0; i < 8; i++) begin
            tb_miss = 1;
            tb_mem_instr = '{addr: '{tag: 32'h0000 + i, index: 32'd1, block_offset: 2'd0, byte_offset: 2'd0}, rw_mode: 0, store_value: 32'h0};
            @(posedge tb_clk);
        end
        // At this point, buffer should be full and stall should be 1
        tb_miss = 1;
        tb_mem_instr = '{addr: '{tag: 32'hDEAD, index: 32'd1, block_offset: 2'd0, byte_offset: 2'd0}, rw_mode: 0, store_value: 32'h0};
        #1; // Wait for comb logic to settle
        if (tb_stall !== 1) $fatal(1, "Saturation: Stall should be 1 when buffer is full!");
        
        // Wait next clock cycle, it shouldn't push DEAD
        @(posedge tb_clk);
        tb_miss = 0;

        // Drain the queue to make sure DEAD wasn't pushed and oldest isn't lost
        for (int i = 0; i < 8; i++) begin
            if (tb_mshr_out.block_addr.tag !== 32'h0000 + i) begin
                 $fatal(1, "Saturation: MSHR queue lost elements due to overwrite! Expected tag %x, got %x", 32'h0000 + i, tb_mshr_out.block_addr.tag);
            end
            tb_bank_free = 1;
            @(posedge tb_clk);
            tb_bank_free = 0;
        end
        if (tb_buffer_empty !== 1) $fatal(1, "Saturation: Buffer should be empty after drain!");

        // Secondary Miss Merging
        $info("Test 3: Secondary Miss Merging");
        reset_dut();
        // Insert a miss
        tb_miss = 1;
        tb_mem_instr = '{addr: '{tag: 32'hCCCC, index: 32'd2, block_offset: 2'd0, byte_offset: 2'd0}, rw_mode: 1, store_value: 32'h11111111};
        @(posedge tb_clk);
        
        // Secondary miss to same block, different offset
        tb_miss = 1;
        tb_mem_instr = '{addr: '{tag: 32'hCCCC, index: 32'd2, block_offset: 2'd1, byte_offset: 2'd0}, rw_mode: 1, store_value: 32'h22222222};
        
        #(CLK_PERIOD/4.0);
        // Verify rptr holds the merged line combinationally
        if (tb_mshr_out.write_status[0] !== 1 || tb_mshr_out.write_status[1] !== 1) $fatal(1, "Merging: write_status not merged correctly! Out: %b", tb_mshr_out.write_status);
        if (tb_mshr_out.write_block[0] !== 32'h11111111 || tb_mshr_out.write_block[1] !== 32'h22222222) $fatal(1, "Merging: write_block not merged correctly!");

        // Concurrent Push/Pop Collision
        $info("Test 4: Concurrent Push/Pop Collision");
        reset_dut();
        // Fill queue
        for (int i = 0; i < 8; i++) begin
            tb_miss = 1;
            tb_mem_instr = '{addr: '{tag: 32'hD000 + i, index: 32'd3, block_offset: 2'd0, byte_offset: 2'd0}, rw_mode: 0, store_value: 32'h0};
            @(posedge tb_clk);
        end

        // Queue is full
        tb_miss = 1;
        tb_bank_free = 1;
        tb_mem_instr = '{addr: '{tag: 32'hE000, index: 32'd4, block_offset: 2'd0, byte_offset: 2'd0}, rw_mode: 0, store_value: 32'h0};
        
        #1; 
        if (tb_stall !== 0) $fatal(1, "Concurrent: Stall should be 0 when bank_free is true!");

        @(posedge tb_clk);
        tb_miss = 0;
        tb_bank_free = 0;
        
        // After 1 posedge of concurrent push/pop, 1 was popped, 1 was pushed.
        // We should have 8 elements, the first being the 2nd we originally pushed (D001).
        for (int i = 1; i < 8; i++) begin
            if (tb_mshr_out.block_addr.tag !== 32'hD000 + i) $fatal(1, "Concurrent: Element %d overwritten! Expected %x got %x", i, 32'hD000 + i, tb_mshr_out.block_addr.tag);
            tb_bank_free = 1;
            @(posedge tb_clk);
            tb_bank_free = 0;
        end
        // The last element should be E000
        if (tb_mshr_out.block_addr.tag !== 32'hE000) $fatal(1, "Concurrent: New element overwritten! Expected E000 got %x", tb_mshr_out.block_addr.tag);
        
        // Wait one more cycle for empty
        tb_bank_free = 1;
        @(posedge tb_clk);
        tb_bank_free = 0;
        if (tb_buffer_empty !== 1) $fatal(1, "Concurrent: Buffer should be empty!");

        $info("All tests passed!");
    end
endprogram
