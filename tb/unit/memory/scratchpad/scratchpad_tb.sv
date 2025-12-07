`timescale 1ps/1ps

`include "scpad_if.sv"

// Fixed scratchpad testbench using initial block (not program block)
// Program blocks have different timing semantics that cause DRAM responses
// to arrive one cycle too late.

module scratchpad_tb;
    import scpad_pkg::*;
    
    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    scratchpad DUT (.sif(sif));
    
    // Test tracking
    int total_tests = 0;
    int passed_tests = 0;
    int failed_tests = 0;
    string current_test_type;
    int current_num_rows;
    int current_num_cols;
    
    //==========================================================================
    // Helper Tasks
    //==========================================================================
    
    task automatic report_error(string msg);
        $display("[FAIL] %s | Matrix: %0dx%0d (num_rows=%0d, num_cols=%0d) | %s", 
                 current_test_type, current_num_rows+1, current_num_cols+1,
                 current_num_rows, current_num_cols, msg);
        failed_tests++;
        total_tests++;
    endtask
    
    task automatic report_success(string msg);
        $display("[PASS] %s | Matrix: %0dx%0d | %s", 
                 current_test_type, current_num_rows+1, current_num_cols+1, msg);
        passed_tests++;
        total_tests++;
    endtask
    
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
    // Vector Core Interface Tasks
    //==========================================================================
    
    // Send a single vector write request (one row at a time)
    task automatic vec_write_row(
        input int row_id,
        input int num_cols,
        input logic [SCPAD_ADDR_WIDTH-1:0] base_addr
    );
        automatic int stall_timeout = 0;
        
        // Set up vec_req for a row-major write
        sif.vec_req[0].valid = 1'b1;
        sif.vec_req[0].write = 1'b1;
        sif.vec_req[0].spad_addr = base_addr;
        sif.vec_req[0].num_rows = 5'(0);  // Single row
        sif.vec_req[0].num_cols = 5'(num_cols);
        sif.vec_req[0].row_id = 5'(row_id);
        sif.vec_req[0].col_id = 5'(0);
        sif.vec_req[0].row_or_col = 1'b1;  // Row-major
        
        // Generate write data: row*32 + col + 1
        for (int col = 0; col < NUM_COLS; col++) begin
            sif.vec_req[0].wdata[col] = 16'((row_id * 32) + col + 1);
        end
        
        // Wait for stall to clear, with timeout
        while (sif.fe_vec_stall[0] && stall_timeout < 200) begin
            @(posedge clk);
            stall_timeout++;
        end
        @(posedge clk);
        
        // Clear request
        sif.vec_req[0].valid = 1'b0;
    endtask
    
    // Send a single vector read request (one row at a time)
    task automatic vec_read_row(
        input int row_id,
        input int num_cols,
        input logic [SCPAD_ADDR_WIDTH-1:0] base_addr,
        output logic [ELEM_BITS-1:0] rdata [NUM_COLS],
        output logic success
    );
        automatic int timeout = 0;
        
        // Set up vec_req for a row-major read
        sif.vec_req[0].valid = 1'b1;
        sif.vec_req[0].write = 1'b0;
        sif.vec_req[0].spad_addr = base_addr;
        sif.vec_req[0].num_rows = 5'(0);
        sif.vec_req[0].num_cols = 5'(num_cols);
        sif.vec_req[0].row_id = 5'(row_id);
        sif.vec_req[0].col_id = 5'(0);
        sif.vec_req[0].row_or_col = 1'b1;
        sif.vec_req[0].wdata = '0;
        
        // Wait for stall to clear
        while (sif.fe_vec_stall[0]) @(posedge clk);
        @(posedge clk);
        sif.vec_req[0].valid = 1'b0;
        
        // Wait for response
        success = 1'b0;
        while (!sif.vec_res[0].valid && timeout < 100) begin
            @(posedge clk);
            timeout++;
        end
        
        if (sif.vec_res[0].valid) begin
            for (int i = 0; i < NUM_COLS; i++) begin
                rdata[i] = sif.vec_res[0].rdata[i];
            end
            success = 1'b1;
        end
    endtask
    
    //==========================================================================
    // Phase 1: Vector Core Write + Read Tests
    //==========================================================================
    
    task automatic test_vec_write_read(
        input int num_rows,
        input int num_cols
    );
        automatic logic [ELEM_BITS-1:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;
        automatic logic [SCPAD_ADDR_WIDTH-1:0] base_addr = 20'h0;
        
        current_test_type = "VEC_WR_RD";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        // Write all rows
        for (int row = 0; row <= num_rows; row++) begin
            vec_write_row(row, num_cols, base_addr);
            // Small delay between rows
            repeat(2) @(posedge clk);
        end
        
        // Wait for writes to complete
        repeat(10) @(posedge clk);
        
        // Read all rows and verify
        for (int row = 0; row <= num_rows; row++) begin
            vec_read_row(row, num_cols, base_addr, rdata, success);
            
            if (!success) begin
                errors++;
            end else begin
                // Verify data
                for (int col = 0; col <= num_cols; col++) begin
                    automatic logic [15:0] expected = 16'((row * 32) + col + 1);
                    if (rdata[col] !== expected) begin
                        errors++;
                    end
                end
            end
            
            repeat(2) @(posedge clk);
        end
        
        if (errors == 0)
            report_success($sformatf("Wrote and read %0d rows", num_rows + 1));
        else
            report_error($sformatf("%0d errors", errors));
    endtask
    
    //==========================================================================
    // Phase 2: DMA LOAD Tests (DRAM -> SRAM)
    //==========================================================================
    
    task automatic test_dma_load(
        input int num_rows,
        input int num_cols
    );
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;
        automatic int total_requests = chunks_per_row * (num_rows + 1);
        automatic int response_count = 0;
        automatic int sram_writes = 0;
        automatic int timeout = 0;
        automatic logic [7:0] req_id;
        automatic int row, sub;
        
        current_test_type = "DMA_LOAD";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
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
        
        @(posedge clk);
        
        // Main response loop
        while (!sif.sched_res[0].valid && timeout < 500) begin
            @(posedge clk);
            
            // Respond to DRAM requests (immediate - same delta cycle)
            if (sif.be_dram_req[0].valid) begin
                req_id = sif.be_dram_req[0].id;
                row = req_id[7:3];
                sub = req_id[2:0];
                
                // Generate response data
                sif.dram_be_res[0].valid = 1'b1;
                sif.dram_be_res[0].id = req_id;
                sif.dram_be_res[0].rdata = {
                    16'((row << 8) | (sub * 4 + 4)),
                    16'((row << 8) | (sub * 4 + 3)),
                    16'((row << 8) | (sub * 4 + 2)),
                    16'((row << 8) | (sub * 4 + 1))
                };
                response_count++;
            end else begin
                sif.dram_be_res[0].valid = 1'b0;
            end
            
            // Count SRAM writes
            if (sif.be_req[0].valid && sif.be_req[0].write) begin
                sram_writes++;
            end
            
            timeout++;
        end
        
        // Cleanup
        sif.dram_be_res[0] = '0;
        sif.sched_req[0].valid = 1'b0;
        repeat (5) @(posedge clk);
        
        if (sram_writes == (num_rows + 1))
            report_success($sformatf("DRAM responses: %0d, SRAM writes: %0d", response_count, sram_writes));
        else
            report_error($sformatf("SRAM writes: %0d/%0d", sram_writes, num_rows + 1));
    endtask
    
    //==========================================================================
    // Phase 2: DMA STORE Tests (SRAM -> DRAM)
    //==========================================================================
    
    task automatic test_dma_store(
        input int num_rows,
        input int num_cols
    );
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;
        automatic int total_dram_writes = chunks_per_row * (num_rows + 1);
        automatic int sram_read_count = 0;
        automatic int sram_write_count = 0;
        automatic int dram_write_count = 0;
        automatic int be_res_count = 0;
        automatic int be_req_any_count = 0;
        automatic int timeout = 0;
        automatic logic [ELEM_BITS-1:0] dummy_rdata [NUM_COLS];
        automatic logic dummy_success;
        automatic int last_activity = 0;
        
        current_test_type = "DMA_STORE";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        // First, write some data via vector interface
        for (int row = 0; row <= num_rows; row++) begin
            vec_write_row(row, num_cols, 20'd0);
            repeat(5) @(posedge clk);
        end
        repeat(50) @(posedge clk);
        
        // Start DMA STORE
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b1;  // STORE = SRAM->DRAM
        sif.sched_req[0].spad_addr = 20'd0;
        sif.sched_req[0].dram_addr = 32'd0;
        sif.sched_req[0].num_rows = 5'(num_rows);
        sif.sched_req[0].num_cols = 5'(num_cols);
        sif.sched_req[0].scpad_id = '0;
        
        sif.dram_be_stall[0] = 1'b0;
        
        // Check for immediate combinational be_req (before first clock edge)
        #1; // Small delay to let combinational logic settle
        if (sif.be_req[0].valid) begin
            be_req_any_count++;
            if (!sif.be_req[0].write) begin
                sram_read_count++;
            end
        end
        
        @(posedge clk);
        
        // Main loop
        while (!sif.sched_res[0].valid && timeout < 500) begin
            @(posedge clk);
            
            // Debug stall signals only when stalls occur (disabled for now)
            // if (num_rows >= 3 && timeout < 30) begin
            //     if (sif.w_stall[0] || sif.r_stall[0])
            //         $display("  [DEBUG] t=%0d: STALLS w=%b r=%b",
            //                  timeout, sif.w_stall[0], sif.r_stall[0]);
            // end
            
            // Count ALL be_req activity
            if (sif.be_req[0].valid) begin
                be_req_any_count++;
                if (!sif.be_req[0].write) begin
                    sram_read_count++;
                    last_activity = timeout;
                end else begin
                    sram_write_count++;
                end
            end
            
            // Count be_res
            if (sif.be_res[0].valid) begin
                be_res_count++;
            end
            
            // Count DRAM writes
            if (sif.be_dram_req[0].valid && sif.be_dram_req[0].write) begin
                dram_write_count++;
                last_activity = timeout;
            end
            
            // Debug: print after no activity for a while
            if (timeout == last_activity + 50 && timeout > 50) begin
                $display("  [DEBUG] DMA_STORE %0dx%0d stalled at t=%0d: dram_writes=%0d/%0d",
                         num_rows+1, num_cols+1, timeout, dram_write_count, total_dram_writes);
            end
            
            timeout++;
        end
        
        // Cleanup
        sif.sched_req[0].valid = 1'b0;
        repeat (5) @(posedge clk);
        
        if (dram_write_count == total_dram_writes)
            report_success($sformatf("be_req(r=%0d,w=%0d), DRAM writes: %0d", 
                           sram_read_count, sram_write_count, dram_write_count));
        else
            report_error($sformatf("be_req(r=%0d,w=%0d), DRAM writes: %0d/%0d (timeout=%0d)", 
                         sram_read_count, sram_write_count, dram_write_count, total_dram_writes, timeout));
    endtask
    
    //==========================================================================
    // Phase 3: DMA LOAD then Vector Read (end-to-end)
    //==========================================================================
    
    task automatic test_dma_load_then_vec_read(
        input int num_rows,
        input int num_cols
    );
        automatic logic [ELEM_BITS-1:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;
        automatic int total_requests = chunks_per_row * (num_rows + 1);
        automatic int response_count = 0;
        automatic int timeout = 0;
        automatic logic [7:0] req_id;
        automatic int row, sub;
        
        current_test_type = "DMA_LOAD_VEC_RD";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        // Step 1: DMA LOAD to fill SRAM
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b0;
        sif.sched_req[0].spad_addr = 20'd0;
        sif.sched_req[0].dram_addr = 32'd0;
        sif.sched_req[0].num_rows = 5'(num_rows);
        sif.sched_req[0].num_cols = 5'(num_cols);
        sif.sched_req[0].scpad_id = '0;
        
        sif.dram_be_stall[0] = 1'b0;
        sif.dram_be_res[0] = '0;
        
        @(posedge clk);
        
        while (!sif.sched_res[0].valid && timeout < 500) begin
            @(posedge clk);
            
            if (sif.be_dram_req[0].valid) begin
                req_id = sif.be_dram_req[0].id;
                row = req_id[7:3];
                sub = req_id[2:0];
                
                // Data pattern: value = (row << 8) | (sub*4 + elem + 1)
                // This maps to: row*32 + col + 1 when unpacked
                sif.dram_be_res[0].valid = 1'b1;
                sif.dram_be_res[0].id = req_id;
                sif.dram_be_res[0].rdata = {
                    16'((row << 8) | (sub * 4 + 4)),
                    16'((row << 8) | (sub * 4 + 3)),
                    16'((row << 8) | (sub * 4 + 2)),
                    16'((row << 8) | (sub * 4 + 1))
                };
                response_count++;
            end else begin
                sif.dram_be_res[0].valid = 1'b0;
            end
            
            timeout++;
        end
        
        sif.dram_be_res[0] = '0;
        sif.sched_req[0].valid = 1'b0;
        
        // Wait for DMA to fully complete
        repeat(10) @(posedge clk);
        
        // Step 2: Vector Core reads the data back
        for (int r = 0; r <= num_rows; r++) begin
            vec_read_row(r, num_cols, 20'd0, rdata, success);
            
            if (!success) begin
                errors++;
            end else begin
                // Verify data: expect (row << 8) | (col + 1)
                for (int c = 0; c <= num_cols; c++) begin
                    automatic logic [15:0] expected = 16'((r << 8) | (c + 1));
                    if (rdata[c] !== expected) begin
                        errors++;
                    end
                end
            end
            
            repeat(2) @(posedge clk);
        end
        
        if (errors == 0)
            report_success($sformatf("DMA loaded %0d chunks, Vec read %0d rows", response_count, num_rows + 1));
        else
            report_error($sformatf("%0d errors", errors));
    endtask

    //==========================================================================
    // Phase 4: Vector Write then DMA STORE (Vec Core -> SRAM -> DRAM)
    //==========================================================================
    
    task automatic test_vec_write_then_dma_store(
        input int num_rows,
        input int num_cols
    );
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;
        automatic int total_dram_writes = chunks_per_row * (num_rows + 1);
        automatic int dram_write_count = 0;
        automatic int timeout = 0;
        automatic logic [SCPAD_ADDR_WIDTH-1:0] base_addr = 20'h100;  // Non-zero base
        
        current_test_type = "VEC_WR_DMA_ST";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        // Step 1: Vector Core writes data to SRAM
        for (int row = 0; row <= num_rows; row++) begin
            vec_write_row(row, num_cols, base_addr);
            repeat(2) @(posedge clk);
        end
        
        repeat(10) @(posedge clk);
        
        // Step 2: DMA STORE reads from SRAM and writes to DRAM
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b1;  // STORE
        sif.sched_req[0].spad_addr = base_addr;
        sif.sched_req[0].dram_addr = 32'h1000;
        sif.sched_req[0].num_rows = 5'(num_rows);
        sif.sched_req[0].num_cols = 5'(num_cols);
        sif.sched_req[0].scpad_id = '0;
        
        sif.dram_be_stall[0] = 1'b0;
        
        @(posedge clk);
        
        while (!sif.sched_res[0].valid && timeout < 500) begin
            @(posedge clk);
            
            // Count DRAM writes (data verification is complex due to packing)
            if (sif.be_dram_req[0].valid && sif.be_dram_req[0].write) begin
                dram_write_count++;
            end
            
            timeout++;
        end
        
        sif.sched_req[0].valid = 1'b0;
        repeat(5) @(posedge clk);
        
        if (dram_write_count == total_dram_writes)
            report_success($sformatf("Vec wrote %0d rows, DMA stored %0d chunks", num_rows+1, dram_write_count));
        else
            report_error($sformatf("%0d/%0d DRAM writes", dram_write_count, total_dram_writes));
    endtask

    //==========================================================================
    // Phase 5: Non-zero Base Address Tests
    //==========================================================================
    
    task automatic test_vec_write_read_offset(
        input int num_rows,
        input int num_cols,
        input logic [SCPAD_ADDR_WIDTH-1:0] base_addr
    );
        automatic logic [ELEM_BITS-1:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;
        
        current_test_type = "VEC_WR_RD_OFFSET";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        // Write all rows at offset
        for (int row = 0; row <= num_rows; row++) begin
            // Custom write with offset-based pattern
            sif.vec_req[0].valid = 1'b1;
            sif.vec_req[0].write = 1'b1;
            sif.vec_req[0].spad_addr = base_addr;
            sif.vec_req[0].num_rows = 5'(0);
            sif.vec_req[0].num_cols = 5'(num_cols);
            sif.vec_req[0].row_id = 5'(row);
            sif.vec_req[0].col_id = 5'(0);
            sif.vec_req[0].row_or_col = 1'b1;
            
            for (int col = 0; col < NUM_COLS; col++) begin
                sif.vec_req[0].wdata[col] = 16'(base_addr[7:0] + row * 32 + col);
            end
            
            while (sif.fe_vec_stall[0]) @(posedge clk);
            @(posedge clk);
            sif.vec_req[0].valid = 1'b0;
            repeat(2) @(posedge clk);
        end
        
        repeat(10) @(posedge clk);
        
        // Read and verify
        for (int row = 0; row <= num_rows; row++) begin
            vec_read_row(row, num_cols, base_addr, rdata, success);
            
            if (!success) begin
                errors++;
            end else begin
                for (int col = 0; col <= num_cols; col++) begin
                    automatic logic [15:0] expected = 16'(base_addr[7:0] + row * 32 + col);
                    if (rdata[col] !== expected) begin
                        errors++;
                    end
                end
            end
            repeat(2) @(posedge clk);
        end
        
        if (errors == 0)
            report_success($sformatf("Base=0x%0h, wrote/read %0d rows", base_addr, num_rows+1));
        else
            report_error($sformatf("%0d errors at base=0x%0h", errors, base_addr));
    endtask

    //==========================================================================
    // Phase 6: Back-to-Back Operations (Pipeline Stress)
    //==========================================================================
    
    task automatic test_back_to_back_writes(
        input int num_rows
    );
        automatic logic [ELEM_BITS-1:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;
        automatic int num_cols = 31;  // 32 columns (full width)
        
        current_test_type = "BACK2BACK_WR";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        // Rapid-fire writes with NO delay between rows
        for (int row = 0; row <= num_rows; row++) begin
            sif.vec_req[0].valid = 1'b1;
            sif.vec_req[0].write = 1'b1;
            sif.vec_req[0].spad_addr = 20'h0;
            sif.vec_req[0].num_rows = 5'(0);
            sif.vec_req[0].num_cols = 5'(num_cols);
            sif.vec_req[0].row_id = 5'(row);
            sif.vec_req[0].col_id = 5'(0);
            sif.vec_req[0].row_or_col = 1'b1;
            
            for (int col = 0; col < NUM_COLS; col++) begin
                sif.vec_req[0].wdata[col] = 16'(row * 100 + col);
            end
            
            // Wait ONLY for stall to clear - no extra cycles
            while (sif.fe_vec_stall[0]) @(posedge clk);
            @(posedge clk);
        end
        
        sif.vec_req[0].valid = 1'b0;
        repeat(20) @(posedge clk);
        
        // Verify all rows
        for (int row = 0; row <= num_rows; row++) begin
            vec_read_row(row, num_cols, 20'h0, rdata, success);
            
            if (!success) begin
                errors++;
            end else begin
                for (int col = 0; col <= num_cols; col++) begin
                    if (rdata[col] !== 16'(row * 100 + col)) begin
                        errors++;
                    end
                end
            end
            repeat(2) @(posedge clk);
        end
        
        if (errors == 0)
            report_success($sformatf("Rapid-fire %0d rows OK", num_rows+1));
        else
            report_error($sformatf("%0d errors in %0d rows", errors, num_rows+1));
    endtask

    //==========================================================================
    // Phase 7: Interleaved FE/BE Priority Test
    //==========================================================================
    
    task automatic test_fe_be_priority();
        automatic int fe_stall_count = 0;
        automatic int be_req_count = 0;
        automatic int timeout = 0;
        automatic logic dma_done = 0;
        
        current_test_type = "FE_BE_PRIORITY";
        current_num_rows = 3;
        current_num_cols = 7;
        
        // Start DMA LOAD (BE path)
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b0;
        sif.sched_req[0].spad_addr = 20'd0;
        sif.sched_req[0].dram_addr = 32'd0;
        sif.sched_req[0].num_rows = 5'd3;
        sif.sched_req[0].num_cols = 5'd7;
        sif.sched_req[0].scpad_id = '0;
        
        // Simultaneously try to send FE request
        sif.vec_req[0].valid = 1'b1;
        sif.vec_req[0].write = 1'b1;
        sif.vec_req[0].spad_addr = 20'h200;  // Different address
        sif.vec_req[0].num_rows = 5'(0);
        sif.vec_req[0].num_cols = 5'd7;
        sif.vec_req[0].row_id = 5'd0;
        sif.vec_req[0].col_id = 5'd0;
        sif.vec_req[0].row_or_col = 1'b1;
        for (int i = 0; i < NUM_COLS; i++) sif.vec_req[0].wdata[i] = 16'hBEEF;
        
        @(posedge clk);
        
        // Monitor for a while
        while (!dma_done && timeout < 300) begin
            @(posedge clk);
            
            // Respond to DRAM requests
            if (sif.be_dram_req[0].valid) begin
                sif.dram_be_res[0].valid = 1'b1;
                sif.dram_be_res[0].id = sif.be_dram_req[0].id;
                sif.dram_be_res[0].rdata = 64'hDEADBEEF_CAFEBABE;
                be_req_count++;
            end else begin
                sif.dram_be_res[0].valid = 1'b0;
            end
            
            // Count FE stalls (indicates BE has priority)
            if (sif.fe_vec_stall[0]) begin
                fe_stall_count++;
            end
            
            if (sif.sched_res[0].valid) dma_done = 1;
            timeout++;
        end
        
        sif.sched_req[0].valid = 1'b0;
        sif.vec_req[0].valid = 1'b0;
        sif.dram_be_res[0] = '0;
        
        repeat(5) @(posedge clk);
        
        // FE should have been stalled at least once if BE has priority
        if (fe_stall_count > 0)
            report_success($sformatf("FE stalled %0d cycles (BE priority OK), %0d DRAM reqs", fe_stall_count, be_req_count));
        else
            report_error($sformatf("FE never stalled - BE priority may not work"));
    endtask

    //==========================================================================
    // Phase 8: Large Matrix Tests
    //==========================================================================
    
    task automatic test_large_matrix_vec(
        input int num_rows,
        input int num_cols
    );
        automatic logic [ELEM_BITS-1:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;
        automatic logic [SCPAD_ADDR_WIDTH-1:0] base_addr = 20'h800;  // Different from stress tests
        
        current_test_type = "LARGE_VEC";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        // Write - use same timing as test_vec_write_read which passes
        for (int row = 0; row <= num_rows; row++) begin
            // Custom write at different base
            sif.vec_req[0].valid = 1'b1;
            sif.vec_req[0].write = 1'b1;
            sif.vec_req[0].spad_addr = base_addr;
            sif.vec_req[0].num_rows = 5'(0);
            sif.vec_req[0].num_cols = 5'(num_cols);
            sif.vec_req[0].row_id = 5'(row);
            sif.vec_req[0].col_id = 5'(0);
            sif.vec_req[0].row_or_col = 1'b1;
            
            for (int col = 0; col < NUM_COLS; col++) begin
                sif.vec_req[0].wdata[col] = 16'(row * 32 + col + 1);
            end
            
            while (sif.fe_vec_stall[0]) @(posedge clk);
            @(posedge clk);
            sif.vec_req[0].valid = 1'b0;
            repeat(2) @(posedge clk);
        end
        
        repeat(10) @(posedge clk);
        
        // Read and verify
        for (int row = 0; row <= num_rows; row++) begin
            vec_read_row(row, num_cols, base_addr, rdata, success);
            
            if (!success) errors++;
            else begin
                for (int col = 0; col <= num_cols; col++) begin
                    if (rdata[col] !== 16'(row * 32 + col + 1)) errors++;
                end
            end
            repeat(2) @(posedge clk);
        end
        
        if (errors == 0)
            report_success($sformatf("Large %0dx%0d matrix OK", num_rows+1, num_cols+1));
        else
            report_error($sformatf("%0d errors", errors));
    endtask
    
    //==========================================================================
    // Test Suites
    //==========================================================================
    
    task automatic run_vec_tests();
        $display("\n======== VECTOR CORE TESTS ========\n");
        
        do_reset();
        test_vec_write_read(0, 0);   // 1x1
        
        do_reset();
        test_vec_write_read(0, 3);   // 1x4
        
        do_reset();
        test_vec_write_read(0, 7);   // 1x8
        
        do_reset();
        test_vec_write_read(0, 31);  // 1x32
        
        do_reset();
        test_vec_write_read(3, 7);   // 4x8
        
        do_reset();
        test_vec_write_read(7, 7);   // 8x8
        
        do_reset();
        test_vec_write_read(7, 31);  // 8x32
        
        do_reset();
        test_vec_write_read(31, 31); // 32x32 (full size)
    endtask
    
    task automatic run_dma_tests();
        $display("\n======== DMA TESTS ========\n");
        
        // DMA LOAD tests
        do_reset();
        test_dma_load(0, 0);   // 1x1
        
        do_reset();
        test_dma_load(0, 7);   // 1x8
        
        do_reset();
        test_dma_load(3, 7);   // 4x8
        
        do_reset();
        test_dma_load(7, 7);   // 8x8
        
        do_reset();
        test_dma_load(7, 31);  // 8x32
        
        // DMA STORE tests
        do_reset();
        test_dma_store(0, 0);  // 1x1
        
        do_reset();
        test_dma_store(0, 7);  // 1x8
        
        do_reset();
        test_dma_store(3, 7);  // 4x8
        
        do_reset();
        test_dma_store(7, 7);  // 8x8
        
        do_reset();
        test_dma_store(7, 31); // 8x32
    endtask
    
    task automatic run_integration_tests();
        $display("\n======== INTEGRATION TESTS ========\n");
        
        // DMA LOAD followed by Vector Read
        do_reset();
        test_dma_load_then_vec_read(0, 7);   // 1x8
        
        do_reset();
        test_dma_load_then_vec_read(3, 7);   // 4x8
        
        do_reset();
        test_dma_load_then_vec_read(7, 31);  // 8x32
        
        // Vector Write followed by DMA STORE
        do_reset();
        test_vec_write_then_dma_store(0, 7);  // 1x8
        
        do_reset();
        test_vec_write_then_dma_store(3, 7);  // 4x8
        
        do_reset();
        test_vec_write_then_dma_store(7, 31); // 8x32
    endtask
    
    task automatic run_address_tests();
        $display("\n======== ADDRESS OFFSET TESTS ========\n");
        
        // Non-zero base addresses
        do_reset();
        test_vec_write_read_offset(3, 31, 20'h100);  // 4x32 at offset 0x100
        
        do_reset();
        test_vec_write_read_offset(7, 31, 20'h200);  // 8x32 at offset 0x200
        
        do_reset();
        test_vec_write_read_offset(15, 31, 20'h400); // 16x32 at offset 0x400
    endtask
    
    task automatic run_stress_tests();
        $display("\n======== STRESS TESTS ========\n");
        
        // Back-to-back operations
        do_reset();
        test_back_to_back_writes(15);  // 16 rapid-fire rows
        
        do_reset();
        test_back_to_back_writes(31);  // 32 rapid-fire rows (full)
        
        // FE/BE priority test
        do_reset();
        test_fe_be_priority();
    endtask
    
    task automatic run_large_matrix_tests();
        $display("\n======== LARGE MATRIX TESTS ========\n");
        
        do_reset();
        test_large_matrix_vec(15, 31);  // 16x32
        
        do_reset();
        test_large_matrix_vec(31, 15);  // 32x16
        
        do_reset();
        test_large_matrix_vec(31, 31);  // 32x32 (full size)
    endtask
    
    task automatic print_summary();
        $display("\n");
        $display("============ TEST SUMMARY ============");
        $display("  Total: %0d | Passed: %0d | Failed: %0d", total_tests, passed_tests, failed_tests);
        if (failed_tests == 0) $display("  ALL TESTS PASSED");
        else $display("  SOME TESTS FAILED");
        $display("======================================\n");
    endtask
    
    //==========================================================================
    // Main - Using initial block (NOT program block!)
    //==========================================================================
    initial begin
        $display("\n===== SCRATCHPAD FULL SYSTEM TEST SUITE =====\n");
        
        // Phase 1: Vector Core path
        run_vec_tests();
        
        // Phase 2: DMA path
        run_dma_tests();
        
        // Phase 3: Integration (DMA + Vec)
        run_integration_tests();
        
        // Phase 4: Address offset tests
        run_address_tests();
        
        // Phase 5: Stress tests
        run_stress_tests();
        
        // Phase 6: Large matrix tests
        run_large_matrix_tests();
        
        print_summary();
        
        if (failed_tests > 0) begin
            $display("FATAL: Test suite failed with %0d failures", failed_tests);
        end
        $finish;
    end
    
    // Timeout watchdog
    initial begin
        #2000000;  // Increased timeout for 32x32 tests
        $display("\n[TIMEOUT] Simulation exceeded time limit\n");
        $finish;
    end

endmodule