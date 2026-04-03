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
        sif.fe_vec_res_stall[0] = '0;
        sif.fe_vec_res_stall[1] = '0;
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
        
        // Generate write data: row*32 + col + 1
        for (int col = 0; col < NUM_COLS; col++) begin
            sif.vec_req[0].wdata[col] = 16'((row_id * 32) + col + 1);
        end
        
        // Present data on posedge, then check stall
        do begin
            @(posedge clk);
            stall_timeout++;
        end while (sif.fe_vec_stall[0] && stall_timeout < 200);
        
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
        sif.vec_req[0].wdata = '0;
        
        // Present then check stall (do-while)
        do @(posedge clk); while (sif.fe_vec_stall[0]);
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
        sif.sched_req[0].full_num_cols = 20'(num_cols);
        sif.sched_req[0].scpad_id = '0;
        
        sif.dram_be_stall[0] = 1'b0;
        sif.dram_be_res[0] = '0;
        
        
        // Main response loop
        do begin
            @(posedge clk); #1;
            sif.sched_req[0].valid = 1'b0;
            
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
        end while (sif.sched_stall[0] && timeout < 500);
        
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
        sif.sched_req[0].full_num_cols = 20'(num_cols);
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
        
        
        // Main loop
        do begin
            @(posedge clk); #1;
            sif.sched_req[0].valid = 1'b0;
            
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
        end while (sif.sched_stall[0] && timeout < 500);
        
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
        sif.sched_req[0].full_num_cols = 20'(num_cols);
        sif.sched_req[0].scpad_id = '0;
        
        sif.dram_be_stall[0] = 1'b0;
        sif.dram_be_res[0] = '0;
        
        
        do begin
            @(posedge clk); #1;
            sif.sched_req[0].valid = 1'b0;
            
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
        end while (sif.sched_stall[0] && timeout < 500);
        
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
        sif.sched_req[0].full_num_cols = 20'(num_cols);
        sif.sched_req[0].scpad_id = '0;
        
        sif.dram_be_stall[0] = 1'b0;
        
        
        do begin
            @(posedge clk); #1;
            sif.sched_req[0].valid = 1'b0;
            
            // Count DRAM writes (data verification is complex due to packing)
            if (sif.be_dram_req[0].valid && sif.be_dram_req[0].write) begin
                dram_write_count++;
            end
            
            timeout++;
        end while (sif.sched_stall[0] && timeout < 500);
        
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
            
            for (int col = 0; col < NUM_COLS; col++) begin
                sif.vec_req[0].wdata[col] = 16'(base_addr[7:0] + row * 32 + col);
            end
            
            do @(posedge clk); while (sif.fe_vec_stall[0]);
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
            
            for (int col = 0; col < NUM_COLS; col++) begin
                sif.vec_req[0].wdata[col] = 16'(row * 100 + col);
            end
            
            // Wait ONLY for stall to clear - no extra cycles
            do @(posedge clk); while (sif.fe_vec_stall[0]);
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
        sif.sched_req[0].full_num_cols = 20'd7;
        sif.sched_req[0].scpad_id = '0;
        
        // Simultaneously try to send FE request
        sif.vec_req[0].valid = 1'b1;
        sif.vec_req[0].write = 1'b1;
        sif.vec_req[0].spad_addr = 20'h200;  // Different address
        sif.vec_req[0].num_rows = 5'(0);
        sif.vec_req[0].num_cols = 5'd7;
        sif.vec_req[0].row_id = 5'd0;
        for (int i = 0; i < NUM_COLS; i++) sif.vec_req[0].wdata[i] = 16'hBEEF;
        
        @(posedge clk);
        sif.sched_req[0].valid = 1'b0;
        
        // Monitor for a while
        while (!dma_done && timeout < 300) begin
            @(posedge clk); #1;
            
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
            
            if (!sif.sched_stall[0]) dma_done = 1;
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
            
            for (int col = 0; col < NUM_COLS; col++) begin
                sif.vec_req[0].wdata[col] = 16'(row * 32 + col + 1);
            end
            
            do @(posedge clk); while (sif.fe_vec_stall[0]);
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
    // Scratchpad[1] Helper Tasks
    //==========================================================================

    task automatic vec_write_row_ch1(
        input int row_id,
        input int num_cols,
        input logic [SCPAD_ADDR_WIDTH-1:0] base_addr,
        input int data_seed
    );
        automatic int stall_timeout = 0;
        sif.vec_req[1].valid = 1'b1;
        sif.vec_req[1].write = 1'b1;
        sif.vec_req[1].spad_addr = base_addr;
        sif.vec_req[1].num_rows = 5'(0);
        sif.vec_req[1].num_cols = 5'(num_cols);
        sif.vec_req[1].row_id = 5'(row_id);
        for (int col = 0; col < NUM_COLS; col++)
            sif.vec_req[1].wdata[col] = 16'(data_seed + row_id * 32 + col);
        do begin
            @(posedge clk);
            stall_timeout++;
        end while (sif.fe_vec_stall[1] && stall_timeout < 200);
        sif.vec_req[1].valid = 1'b0;
    endtask

    task automatic vec_read_row_ch1(
        input int row_id,
        input int num_cols,
        input logic [SCPAD_ADDR_WIDTH-1:0] base_addr,
        output logic [ELEM_BITS-1:0] rdata [NUM_COLS],
        output logic success
    );
        automatic int timeout = 0;
        sif.vec_req[1].valid = 1'b1;
        sif.vec_req[1].write = 1'b0;
        sif.vec_req[1].spad_addr = base_addr;
        sif.vec_req[1].num_rows = 5'(0);
        sif.vec_req[1].num_cols = 5'(num_cols);
        sif.vec_req[1].row_id = 5'(row_id);
        sif.vec_req[1].wdata = '0;
        do @(posedge clk); while (sif.fe_vec_stall[1]);
        sif.vec_req[1].valid = 1'b0;
        success = 1'b0;
        while (!sif.vec_res[1].valid && timeout < 100) begin
            @(posedge clk);
            timeout++;
        end
        if (sif.vec_res[1].valid) begin
            for (int i = 0; i < NUM_COLS; i++) rdata[i] = sif.vec_res[1].rdata[i];
            success = 1'b1;
        end
    endtask

    //==========================================================================
    // Phase 9: Dual-Scratchpad Concurrent Operation
    //==========================================================================

    task automatic test_dual_scratchpad();
        automatic logic [ELEM_BITS-1:0] rdata0 [NUM_COLS];
        automatic logic [ELEM_BITS-1:0] rdata1 [NUM_COLS];
        automatic logic success0, success1;
        automatic int errors = 0;
        automatic int num_rows = 3;
        automatic int num_cols = 7;

        current_test_type = "DUAL_SPAD";
        current_num_rows = num_rows;
        current_num_cols = num_cols;

        // Interleave writes to scpad[0] and scpad[1]
        for (int row = 0; row <= num_rows; row++) begin
            // Drive both channels on the same cycle
            sif.vec_req[0].valid = 1'b1;
            sif.vec_req[0].write = 1'b1;
            sif.vec_req[0].spad_addr = 20'h0;
            sif.vec_req[0].num_rows = 5'(0);
            sif.vec_req[0].num_cols = 5'(num_cols);
            sif.vec_req[0].row_id = 5'(row);
            for (int col = 0; col < NUM_COLS; col++)
                sif.vec_req[0].wdata[col] = 16'(16'hA000 + row * 32 + col);

            sif.vec_req[1].valid = 1'b1;
            sif.vec_req[1].write = 1'b1;
            sif.vec_req[1].spad_addr = 20'h0;
            sif.vec_req[1].num_rows = 5'(0);
            sif.vec_req[1].num_cols = 5'(num_cols);
            sif.vec_req[1].row_id = 5'(row);
            for (int col = 0; col < NUM_COLS; col++)
                sif.vec_req[1].wdata[col] = 16'(16'hB000 + row * 32 + col);

            // Wait for both stalls to clear
            do @(posedge clk); while (sif.fe_vec_stall[0] || sif.fe_vec_stall[1]);
            sif.vec_req[0].valid = 1'b0;
            sif.vec_req[1].valid = 1'b0;
            repeat(3) @(posedge clk);
        end

        repeat(10) @(posedge clk);

        // Read back from both and verify independently
        for (int row = 0; row <= num_rows; row++) begin
            vec_read_row(row, num_cols, 20'h0, rdata0, success0);
            vec_read_row_ch1(row, num_cols, 20'h0, rdata1, success1);

            if (!success0 || !success1) begin
                errors++;
            end else begin
                for (int col = 0; col <= num_cols; col++) begin
                    if (rdata0[col] !== 16'(16'hA000 + row * 32 + col)) errors++;
                    if (rdata1[col] !== 16'(16'hB000 + row * 32 + col)) errors++;
                end
            end
            repeat(2) @(posedge clk);
        end

        if (errors == 0)
            report_success($sformatf("Both spads 4x8 concurrent write/read OK"));
        else
            report_error($sformatf("%0d errors in dual-spad", errors));
    endtask

    //==========================================================================
    // Phase 10: DRAM Response Reordering
    //==========================================================================

    task automatic test_dram_reorder();
        automatic int num_rows = 3;
        automatic int num_cols = 7;
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;  // 2
        automatic int total_requests = chunks_per_row * (num_rows + 1);  // 8
        automatic int response_count = 0;
        automatic int timeout = 0;
        automatic logic [ELEM_BITS-1:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;

        // Queue to hold pending requests for reordering
        logic [7:0]  pending_ids [$];
        logic [63:0] pending_data [$];

        current_test_type = "DRAM_REORDER";
        current_num_rows = num_rows;
        current_num_cols = num_cols;

        // Start DMA LOAD
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b0;
        sif.sched_req[0].spad_addr = 20'd0;
        sif.sched_req[0].dram_addr = 32'd0;
        sif.sched_req[0].num_rows = 5'(num_rows);
        sif.sched_req[0].num_cols = 5'(num_cols);
        sif.sched_req[0].full_num_cols = 20'(num_cols);
        sif.sched_req[0].scpad_id = '0;
        sif.dram_be_stall[0] = 1'b0;
        sif.dram_be_res[0] = '0;


        do begin
            @(posedge clk); #1;
            sif.sched_req[0].valid = 1'b0;

            // Collect requests into queue
            if (sif.be_dram_req[0].valid) begin
                automatic logic [7:0] rid = sif.be_dram_req[0].id;
                automatic int r = rid[7:3];
                automatic int s = rid[2:0];
                automatic logic [63:0] d = {
                    16'((r << 8) | (s * 4 + 4)),
                    16'((r << 8) | (s * 4 + 3)),
                    16'((r << 8) | (s * 4 + 2)),
                    16'((r << 8) | (s * 4 + 1))
                };
                pending_ids.push_back(rid);
                pending_data.push_back(d);
            end

            // When we have 2+ pending, respond with the OLDEST first  
            // (which reverses the natural order within each pair)
            // This tests id-based reassembly
            if (pending_ids.size() >= 2) begin
                sif.dram_be_res[0].valid = 1'b1;
                sif.dram_be_res[0].id = pending_ids[0];
                sif.dram_be_res[0].rdata = pending_data[0];
                pending_ids.delete(0);
                pending_data.delete(0);
                response_count++;
            end else if (pending_ids.size() == 1 && timeout > 100) begin
                // Flush last one
                sif.dram_be_res[0].valid = 1'b1;
                sif.dram_be_res[0].id = pending_ids[0];
                sif.dram_be_res[0].rdata = pending_data[0];
                pending_ids.delete(0);
                pending_data.delete(0);
                response_count++;
            end else begin
                sif.dram_be_res[0].valid = 1'b0;
            end

            timeout++;
        end while (sif.sched_stall[0] && timeout < 800);

        // Flush remaining
        while (pending_ids.size() > 0) begin
            @(posedge clk);
            sif.dram_be_res[0].valid = 1'b1;
            sif.dram_be_res[0].id = pending_ids[0];
            sif.dram_be_res[0].rdata = pending_data[0];
            pending_ids.delete(0);
            pending_data.delete(0);
            response_count++;
        end
        @(posedge clk);
        sif.dram_be_res[0] = '0;
        sif.sched_req[0].valid = 1'b0;
        repeat(10) @(posedge clk);

        // Vector read to verify data integrity
        for (int row = 0; row <= num_rows; row++) begin
            vec_read_row(row, num_cols, 20'h0, rdata, success);
            if (!success) begin
                errors++;
            end else begin
                for (int col = 0; col <= num_cols; col++) begin
                    if (rdata[col] !== 16'((row << 8) | (col + 1))) errors++;
                end
            end
            repeat(2) @(posedge clk);
        end

        if (errors == 0)
            report_success($sformatf("Reordered %0d DRAM responses, data intact", response_count));
        else
            report_error($sformatf("%0d data errors after reorder", errors));
    endtask

    //==========================================================================
    // Phase 11: DRAM Stall Injection
    //==========================================================================

    task automatic test_dram_stall_injection();
        automatic int num_rows = 3;
        automatic int num_cols = 7;
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;
        automatic int total_requests = chunks_per_row * (num_rows + 1);
        automatic int response_count = 0;
        automatic int stall_cycles = 0;
        automatic int timeout = 0;
        automatic logic [ELEM_BITS-1:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;

        current_test_type = "DRAM_STALL";
        current_num_rows = num_rows;
        current_num_cols = num_cols;

        // Start DMA LOAD
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b0;
        sif.sched_req[0].spad_addr = 20'd0;
        sif.sched_req[0].dram_addr = 32'd0;
        sif.sched_req[0].num_rows = 5'(num_rows);
        sif.sched_req[0].num_cols = 5'(num_cols);
        sif.sched_req[0].full_num_cols = 20'(num_cols);
        sif.sched_req[0].scpad_id = '0;
        sif.dram_be_stall[0] = 1'b0;
        sif.dram_be_res[0] = '0;


        do begin
            @(posedge clk); #1;
            sif.sched_req[0].valid = 1'b0;

            // Inject stall every 3 cycles for 2 cycles
            // dram_be_stall = "don't send me new requests" — does NOT block responses
            if (timeout % 5 < 2) begin
                sif.dram_be_stall[0] = 1'b1;
                stall_cycles++;
            end else begin
                sif.dram_be_stall[0] = 1'b0;
            end

            // Always respond to DRAM requests regardless of stall
            if (sif.be_dram_req[0].valid) begin
                automatic logic [7:0] rid = sif.be_dram_req[0].id;
                automatic int r = rid[7:3];
                automatic int s = rid[2:0];
                sif.dram_be_res[0].valid = 1'b1;
                sif.dram_be_res[0].id = rid;
                sif.dram_be_res[0].rdata = {
                    16'((r << 8) | (s * 4 + 4)),
                    16'((r << 8) | (s * 4 + 3)),
                    16'((r << 8) | (s * 4 + 2)),
                    16'((r << 8) | (s * 4 + 1))
                };
                response_count++;
            end else begin
                sif.dram_be_res[0].valid = 1'b0;
            end

            timeout++;
        end while (sif.sched_stall[0] && timeout < 800);

        sif.dram_be_stall[0] = 1'b0;
        sif.dram_be_res[0] = '0;
        sif.sched_req[0].valid = 1'b0;
        repeat(10) @(posedge clk);

        // Vector read to verify data after stall recovery
        for (int row = 0; row <= num_rows; row++) begin
            vec_read_row(row, num_cols, 20'h0, rdata, success);
            if (!success) begin
                errors++;
            end else begin
                for (int col = 0; col <= num_cols; col++) begin
                    if (rdata[col] !== 16'((row << 8) | (col + 1))) errors++;
                end
            end
            repeat(2) @(posedge clk);
        end

        if (errors == 0)
            report_success($sformatf("Survived %0d stall cycles, %0d responses OK", stall_cycles, response_count));
        else
            report_error($sformatf("%0d data errors after stall injection", errors));
    endtask

    //==========================================================================
    // Phase 12: DMA STORE Data Verification
    //==========================================================================

    task automatic test_dma_store_data_verify();
        automatic int num_rows = 3;
        automatic int num_cols = 7;
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;
        automatic int total_dram_writes = chunks_per_row * (num_rows + 1);
        automatic int dram_write_count = 0;
        automatic int data_errors = 0;
        automatic int timeout = 0;

        // Track expected order by sequential counter
        automatic int cur_row = 0;
        automatic int cur_sub = 0;

        current_test_type = "DMA_ST_DATA";
        current_num_rows = num_rows;
        current_num_cols = num_cols;

        // Write known data via vector interface: pattern = row*32 + col + 1
        for (int row = 0; row <= num_rows; row++) begin
            vec_write_row(row, num_cols, 20'h0);
            repeat(5) @(posedge clk);
        end
        repeat(50) @(posedge clk);

        // Start DMA STORE
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b1;
        sif.sched_req[0].spad_addr = 20'd0;
        sif.sched_req[0].dram_addr = 32'h2000;
        sif.sched_req[0].num_rows = 5'(num_rows);
        sif.sched_req[0].num_cols = 5'(num_cols);
        sif.sched_req[0].full_num_cols = 20'(num_cols);
        sif.sched_req[0].scpad_id = '0;
        sif.dram_be_stall[0] = 1'b0;


        do begin
            @(posedge clk); #1;
            sif.sched_req[0].valid = 1'b0;

            // Check DRAM write data content — use DRAM address to decode position
            if (sif.be_dram_req[0].valid && sif.be_dram_req[0].write) begin
                automatic logic [63:0] expected_data;
                automatic int base_col;

                // Decode from DRAM address: each chunk = 8 bytes (4 elements * 2 bytes)
                // dram_addr = base + row * row_bytes + sub * 8
                // But simpler: use sequential counter since backend sends in order
                base_col = cur_sub * 4;

                expected_data = {
                    16'(cur_row * 32 + base_col + 4),
                    16'(cur_row * 32 + base_col + 3),
                    16'(cur_row * 32 + base_col + 2),
                    16'(cur_row * 32 + base_col + 1)
                };

                if (sif.be_dram_req[0].wdata !== expected_data) begin
                    data_errors++;
                    if (data_errors <= 3)
                        $display("  [DEBUG] DMA_ST_DATA mismatch: row=%0d sub=%0d got=0x%016h exp=0x%016h",
                                 cur_row, cur_sub, sif.be_dram_req[0].wdata, expected_data);
                end
                dram_write_count++;

                // Advance sequential tracker
                cur_sub++;
                if (cur_sub >= chunks_per_row) begin
                    cur_sub = 0;
                    cur_row++;
                end
            end

            timeout++;
        end while (sif.sched_stall[0] && timeout < 500);

        sif.sched_req[0].valid = 1'b0;
        repeat(5) @(posedge clk);

        if (dram_write_count == total_dram_writes && data_errors == 0)
            report_success($sformatf("%0d DRAM writes, all data verified", dram_write_count));
        else
            report_error($sformatf("%0d/%0d writes, %0d data errors", dram_write_count, total_dram_writes, data_errors));
    endtask

    //==========================================================================
    // Phase 13: Reset Mid-Operation
    //==========================================================================

    task automatic test_reset_mid_operation();
        automatic int num_rows = 3;
        automatic int num_cols = 7;
        automatic int timeout = 0;
        automatic logic [ELEM_BITS-1:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;

        current_test_type = "RST_MID_OP";
        current_num_rows = num_rows;
        current_num_cols = num_cols;

        // Start DMA LOAD
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b0;
        sif.sched_req[0].spad_addr = 20'd0;
        sif.sched_req[0].dram_addr = 32'd0;
        sif.sched_req[0].num_rows = 5'(num_rows);
        sif.sched_req[0].num_cols = 5'(num_cols);
        sif.sched_req[0].full_num_cols = 20'(num_cols);
        sif.sched_req[0].scpad_id = '0;
        sif.dram_be_stall[0] = 1'b0;
        sif.dram_be_res[0] = '0;

        @(posedge clk);

        // Let a few DRAM responses through
        repeat(10) begin
            @(posedge clk);
            if (sif.be_dram_req[0].valid) begin
                sif.dram_be_res[0].valid = 1'b1;
                sif.dram_be_res[0].id = sif.be_dram_req[0].id;
                sif.dram_be_res[0].rdata = 64'hDEAD_BEEF_CAFE_BABE;
            end else begin
                sif.dram_be_res[0].valid = 1'b0;
            end
        end

        // Assert reset mid-transfer
        do_reset();

        // After reset, scratchpad should accept new requests cleanly
        // Write new data and verify it reads back
        for (int row = 0; row <= num_rows; row++) begin
            vec_write_row(row, num_cols, 20'h0);
            repeat(2) @(posedge clk);
        end
        repeat(10) @(posedge clk);

        for (int row = 0; row <= num_rows; row++) begin
            vec_read_row(row, num_cols, 20'h0, rdata, success);
            if (!success) begin
                errors++;
            end else begin
                for (int col = 0; col <= num_cols; col++) begin
                    if (rdata[col] !== 16'(row * 32 + col + 1)) errors++;
                end
            end
            repeat(2) @(posedge clk);
        end

        if (errors == 0)
            report_success($sformatf("Reset during DMA, then clean write/read OK"));
        else
            report_error($sformatf("%0d errors after mid-op reset", errors));
    endtask

    //==========================================================================
    // Phase 14: Toggle Coverage Sweep (Randomized)
    //==========================================================================

    task automatic test_random_sweep();
        automatic logic [ELEM_BITS-1:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;
        automatic int total_patterns = 0;
        automatic int num_rows, num_cols;
        automatic logic [SCPAD_ADDR_WIDTH-1:0] base_addr;

        current_test_type = "RAND_SWEEP";
        current_num_rows = 0;
        current_num_cols = 0;

        for (int trial = 0; trial < 8; trial++) begin
            // Pseudorandom sizes: use golden ratio hashing for variety
            num_rows = ((trial * 13 + 5) % 16);   // 0..15
            num_cols = ((trial * 7  + 3) % 32);    // 0..31
            base_addr = 20'((trial * 256) % 2048);

            current_num_rows = num_rows;
            current_num_cols = num_cols;

            // Write
            for (int row = 0; row <= num_rows; row++) begin
                sif.vec_req[0].valid = 1'b1;
                sif.vec_req[0].write = 1'b1;
                sif.vec_req[0].spad_addr = base_addr;
                sif.vec_req[0].num_rows = 5'(0);
                sif.vec_req[0].num_cols = 5'(num_cols);
                sif.vec_req[0].row_id = 5'(row);
                for (int col = 0; col < NUM_COLS; col++)
                    sif.vec_req[0].wdata[col] = 16'(trial * 1000 + row * 32 + col);
                do @(posedge clk); while (sif.fe_vec_stall[0]);
                sif.vec_req[0].valid = 1'b0;
            end
            repeat(5) @(posedge clk);

            // Read and verify
            for (int row = 0; row <= num_rows; row++) begin
                vec_read_row(row, num_cols, base_addr, rdata, success);
                if (!success) begin
                    errors++;
                end else begin
                    for (int col = 0; col <= num_cols; col++) begin
                        if (rdata[col] !== 16'(trial * 1000 + row * 32 + col)) errors++;
                    end
                end
            end
            total_patterns++;
            do_reset();
        end

        current_num_rows = 15;
        current_num_cols = 31;
        if (errors == 0)
            report_success($sformatf("%0d random patterns all verified", total_patterns));
        else
            report_error($sformatf("%0d errors across %0d patterns", errors, total_patterns));
    endtask
    
    //==========================================================================
    // Phase 12: Concurrent Read+Write Tests (dual FIFO verification)
    //==========================================================================

    // Test: DMA writes to region B while vector core reads from region A.
    // With dual FIFOs in scpad_cntrl, reads and writes overlap in SRAM.
    // With a single FIFO, reads would serialize behind writes.
    task automatic test_concurrent_dma_write_vec_read();
        automatic logic [ELEM_BITS-1:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;
        automatic int vec_read_cycles = 0;
        automatic int dma_done = 0;
        automatic int vec_done = 0;
        automatic int timeout = 0;
        automatic int num_cols = 7;
        automatic int dma_rows = 7;  // 8 rows of DMA — takes many cycles
        automatic int vec_read_rows = 3;  // 4 rows to read back

        current_test_type = "CONC_DMA_WR_VEC_RD";
        current_num_rows = dma_rows;
        current_num_cols = num_cols;

        // Step 1: Pre-load region A (addr 0x000) via vector writes
        for (int row = 0; row <= vec_read_rows; row++) begin
            sif.vec_req[0].valid = 1'b1;
            sif.vec_req[0].write = 1'b1;
            sif.vec_req[0].spad_addr = 20'h0;
            sif.vec_req[0].num_rows = 5'(0);
            sif.vec_req[0].num_cols = 5'(num_cols);
            sif.vec_req[0].row_id = 5'(row);
            for (int col = 0; col < NUM_COLS; col++)
                sif.vec_req[0].wdata[col] = 16'(16'hA000 + row * 32 + col);
            do @(posedge clk); while (sif.fe_vec_stall[0]);
            sif.vec_req[0].valid = 1'b0;
        end
        repeat(10) @(posedge clk);

        // Step 2: Start DMA LOAD to region B (addr 0x200) — this takes many cycles
        // Simultaneously issue vector reads from region A
        fork
            // DMA thread: load 8 rows to region B
            begin
                automatic int resp_count = 0;
                automatic int dma_timeout = 0;
                sif.sched_req[0].valid = 1'b1;
                sif.sched_req[0].write = 1'b0;  // DMA LOAD (DRAM→SRAM, i.e. SRAM write)
                sif.sched_req[0].spad_addr = 20'h200;
                sif.sched_req[0].dram_addr = 32'd0;
                sif.sched_req[0].num_rows = 5'(dma_rows);
                sif.sched_req[0].num_cols = 5'(num_cols);
                sif.sched_req[0].full_num_cols = 20'(num_cols);
                sif.sched_req[0].scpad_id = '0;
                sif.dram_be_stall[0] = 1'b0;

                do begin
                    @(posedge clk); #1;
                    sif.sched_req[0].valid = 1'b0;
                    if (sif.be_dram_req[0].valid) begin
                        automatic logic [7:0] rid = sif.be_dram_req[0].id;
                        automatic int r = rid[7:3];
                        automatic int s = rid[2:0];
                        sif.dram_be_res[0].valid = 1'b1;
                        sif.dram_be_res[0].id = rid;
                        sif.dram_be_res[0].rdata = {
                            16'(16'hB000 + r * 32 + s * 4 + 3),
                            16'(16'hB000 + r * 32 + s * 4 + 2),
                            16'(16'hB000 + r * 32 + s * 4 + 1),
                            16'(16'hB000 + r * 32 + s * 4 + 0)
                        };
                        resp_count++;
                    end else begin
                        sif.dram_be_res[0].valid = 1'b0;
                    end
                    dma_timeout++;
                end while (sif.sched_stall[0] && dma_timeout < 500);
                sif.sched_req[0].valid = 1'b0;
                sif.dram_be_res[0] = '0;
                dma_done = 1;
            end

            // Vector read thread: read region A while DMA is in progress
            begin
                automatic int start_time;
                // Small delay to let DMA get started first
                repeat(5) @(posedge clk);
                start_time = $time;

                for (int row = 0; row <= vec_read_rows; row++) begin
                    vec_read_row(row, num_cols, 20'h0, rdata, success);
                    if (!success) begin
                        errors++;
                    end else begin
                        for (int col = 0; col <= num_cols; col++) begin
                            if (rdata[col] !== 16'(16'hA000 + row * 32 + col)) begin
                                errors++;
                            end
                        end
                    end
                end
                vec_read_cycles = ($time - start_time) / CLK_PERIOD;
                vec_done = 1;
            end
        join

        // Step 3: Verify region B (DMA data) is also correct
        repeat(10) @(posedge clk);
        for (int row = 0; row <= dma_rows; row++) begin
            vec_read_row(row, num_cols, 20'h200, rdata, success);
            if (!success) begin
                errors++;
            end else begin
                for (int col = 0; col <= num_cols; col++) begin
                    if (rdata[col] !== 16'(16'hB000 + row * 32 + col))
                        errors++;
                end
            end
        end

        if (errors == 0)
            report_success($sformatf("Vec reads completed in %0d cycles while DMA active, both regions correct", vec_read_cycles));
        else
            report_error($sformatf("%0d errors in concurrent DMA write + vec read", errors));
    endtask

    // Test: Rapid alternating FE writes and FE reads to different addresses.
    // With dual FIFOs, a read issued right after a write doesn't wait for
    // the write's SRAM latency — they go to separate FIFOs and overlap.
    task automatic test_concurrent_interleaved_rw();
        automatic logic [ELEM_BITS-1:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;
        automatic int num_cols = 31;

        current_test_type = "CONC_INTERLEAVE";
        current_num_rows = 7;
        current_num_cols = num_cols;

        // Pre-load 8 rows at addr 0x000 with known data
        for (int row = 0; row < 8; row++) begin
            sif.vec_req[0].valid = 1'b1;
            sif.vec_req[0].write = 1'b1;
            sif.vec_req[0].spad_addr = 20'h0;
            sif.vec_req[0].num_rows = 5'(0);
            sif.vec_req[0].num_cols = 5'(num_cols);
            sif.vec_req[0].row_id = 5'(row);
            for (int col = 0; col < NUM_COLS; col++)
                sif.vec_req[0].wdata[col] = 16'(16'hC000 + row * 32 + col);
            do @(posedge clk); while (sif.fe_vec_stall[0]);
            sif.vec_req[0].valid = 1'b0;
        end
        repeat(10) @(posedge clk);

        // Interleave: write row N to addr 0x400, then immediately read row N from addr 0x000
        // The read should not be blocked by the write's SRAM latency
        for (int row = 0; row < 8; row++) begin
            // Write to region B
            sif.vec_req[0].valid = 1'b1;
            sif.vec_req[0].write = 1'b1;
            sif.vec_req[0].spad_addr = 20'h400;
            sif.vec_req[0].num_rows = 5'(0);
            sif.vec_req[0].num_cols = 5'(num_cols);
            sif.vec_req[0].row_id = 5'(row);
            for (int col = 0; col < NUM_COLS; col++)
                sif.vec_req[0].wdata[col] = 16'(16'hD000 + row * 32 + col);
            do @(posedge clk); while (sif.fe_vec_stall[0]);
            sif.vec_req[0].valid = 1'b0;

            // Immediately read from region A
            vec_read_row(row, num_cols, 20'h0, rdata, success);
            if (!success) begin
                errors++;
            end else begin
                for (int col = 0; col <= num_cols; col++) begin
                    if (rdata[col] !== 16'(16'hC000 + row * 32 + col))
                        errors++;
                end
            end
        end

        repeat(10) @(posedge clk);

        // Verify region B writes also completed correctly
        for (int row = 0; row < 8; row++) begin
            vec_read_row(row, num_cols, 20'h400, rdata, success);
            if (!success) begin
                errors++;
            end else begin
                for (int col = 0; col <= num_cols; col++) begin
                    if (rdata[col] !== 16'(16'hD000 + row * 32 + col))
                        errors++;
                end
            end
        end

        if (errors == 0)
            report_success("8 interleaved write+read pairs, both regions correct");
        else
            report_error($sformatf("%0d errors in interleaved R+W", errors));
    endtask

    // Test: Verify no data corruption when reads and writes target the SAME
    // bank but different rows. This is the concurrent access stress case.
    task automatic test_concurrent_same_bank_diff_row();
        automatic logic [ELEM_BITS-1:0] rdata [NUM_COLS];
        automatic logic success;
        automatic int errors = 0;
        automatic int num_cols = 31;

        current_test_type = "CONC_SAME_BANK";
        current_num_rows = 3;
        current_num_cols = num_cols;

        // Pre-load rows 0-3 at addr 0x000
        for (int row = 0; row < 4; row++) begin
            sif.vec_req[0].valid = 1'b1;
            sif.vec_req[0].write = 1'b1;
            sif.vec_req[0].spad_addr = 20'h0;
            sif.vec_req[0].num_rows = 5'(0);
            sif.vec_req[0].num_cols = 5'(num_cols);
            sif.vec_req[0].row_id = 5'(row);
            for (int col = 0; col < NUM_COLS; col++)
                sif.vec_req[0].wdata[col] = 16'(16'hE000 + row * 32 + col);
            do @(posedge clk); while (sif.fe_vec_stall[0]);
            sif.vec_req[0].valid = 1'b0;
        end
        repeat(10) @(posedge clk);

        // Write row 4-7 (same banks, different rows) while reading rows 0-3
        for (int i = 0; i < 4; i++) begin
            // Write row i+4
            sif.vec_req[0].valid = 1'b1;
            sif.vec_req[0].write = 1'b1;
            sif.vec_req[0].spad_addr = 20'h0;
            sif.vec_req[0].num_rows = 5'(0);
            sif.vec_req[0].num_cols = 5'(num_cols);
            sif.vec_req[0].row_id = 5'(i + 4);
            for (int col = 0; col < NUM_COLS; col++)
                sif.vec_req[0].wdata[col] = 16'(16'hF000 + (i + 4) * 32 + col);
            do @(posedge clk); while (sif.fe_vec_stall[0]);
            sif.vec_req[0].valid = 1'b0;

            // Read row i (same bank, different row — concurrent in SRAM)
            vec_read_row(i, num_cols, 20'h0, rdata, success);
            if (!success) begin
                errors++;
            end else begin
                for (int col = 0; col <= num_cols; col++) begin
                    if (rdata[col] !== 16'(16'hE000 + i * 32 + col))
                        errors++;
                end
            end
        end

        repeat(10) @(posedge clk);

        // Verify the written rows are also correct
        for (int row = 4; row < 8; row++) begin
            vec_read_row(row, num_cols, 20'h0, rdata, success);
            if (!success) begin
                errors++;
            end else begin
                for (int col = 0; col <= num_cols; col++) begin
                    if (rdata[col] !== 16'(16'hF000 + row * 32 + col))
                        errors++;
                end
            end
        end

        if (errors == 0)
            report_success("Same-bank concurrent R+W to different rows, no corruption");
        else
            report_error($sformatf("%0d errors in same-bank concurrent R+W", errors));
    endtask

    task automatic run_concurrent_rw_tests();
        $display("\n======== CONCURRENT R+W TESTS (dual FIFO) ========\n");

        do_reset();
        test_concurrent_dma_write_vec_read();

        do_reset();
        test_concurrent_interleaved_rw();

        do_reset();
        test_concurrent_same_bank_diff_row();
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
        test_dma_load(0, 1);   // 1x2  (num_cols[1:0]=01 → mask=0011)

        do_reset();
        test_dma_load(0, 2);   // 1x3  (num_cols[1:0]=10 → mask=0111)
        
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
        test_dma_store(0, 1);  // 1x2  (num_cols[1:0]=01)

        do_reset();
        test_dma_store(0, 2);  // 1x3  (num_cols[1:0]=10)
        
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
        test_dma_load_then_vec_read(0, 1);   // 1x2  (partial mask 0011)

        do_reset();
        test_dma_load_then_vec_read(0, 2);   // 1x3  (partial mask 0111)

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

    task automatic run_dual_spad_tests();
        $display("\n======== DUAL-SCRATCHPAD TESTS ========\n");

        do_reset();
        test_dual_scratchpad();
    endtask

    task automatic run_dram_robustness_tests();
        $display("\n======== DRAM ROBUSTNESS TESTS ========\n");

        do_reset();
        test_dram_reorder();

        do_reset();
        test_dram_stall_injection();
    endtask

    task automatic run_dma_store_data_tests();
        $display("\n======== DMA STORE DATA VERIFICATION ========\n");

        do_reset();
        test_dma_store_data_verify();
    endtask

    task automatic run_reset_tests();
        $display("\n======== RESET MID-OPERATION TESTS ========\n");

        do_reset();
        test_reset_mid_operation();
    endtask

    task automatic run_random_sweep_tests();
        $display("\n======== RANDOM TOGGLE SWEEP ========\n");

        do_reset();
        test_random_sweep();
    endtask
    
    //==========================================================================
    // Phase 13: Full Matrix Stride Tests (full_num_cols != num_cols)
    //==========================================================================

    // Verifies DRAM address computation uses full_num_cols (full matrix width)
    // as the row stride, not num_cols (tile width). This catches the bug where
    // loading a small tile from a large matrix would read wrong rows.
    task automatic test_dma_load_stride(
        input int num_rows,
        input int num_cols,
        input int full_cols,      // full matrix column count (0-based)
        input int dram_base
    );
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;
        automatic int response_count = 0;
        automatic int addr_errors = 0;
        automatic int timeout = 0;
        automatic logic [7:0] req_id;
        automatic int row, sub;
        automatic logic [31:0] expected_addr;
        automatic logic [31:0] actual_addr;

        current_test_type = "STRIDE_LOAD";
        current_num_rows = num_rows;
        current_num_cols = num_cols;

        // Start DMA LOAD with full_num_cols != num_cols
        sif.sched_req[0].valid = 1'b1;
        sif.sched_req[0].write = 1'b0;
        sif.sched_req[0].spad_addr = 20'd0;
        sif.sched_req[0].dram_addr = 32'(dram_base);
        sif.sched_req[0].num_rows = 5'(num_rows);
        sif.sched_req[0].num_cols = 5'(num_cols);
        sif.sched_req[0].full_num_cols = 20'(full_cols);
        sif.sched_req[0].scpad_id = '0;

        sif.dram_be_stall[0] = 1'b0;
        sif.dram_be_res[0] = '0;


        do begin
            @(posedge clk); #1;
            sif.sched_req[0].valid = 1'b0;

            if (sif.be_dram_req[0].valid) begin
                req_id = sif.be_dram_req[0].id;
                row = req_id[7:3];
                sub = req_id[2:0];

                // Verify DRAM address uses full matrix stride
                actual_addr = sif.be_dram_req[0].dram_addr;
                expected_addr = dram_base + row * (full_cols + 1) + sub * 4;

                if (actual_addr !== expected_addr) begin
                    $display("[STRIDE] Row %0d Sub %0d: addr=0x%08h expected=0x%08h (stride=%0d)",
                             row, sub, actual_addr, expected_addr, full_cols + 1);
                    addr_errors++;
                end

                // Respond with dummy data
                sif.dram_be_res[0].valid = 1'b1;
                sif.dram_be_res[0].id = req_id;
                sif.dram_be_res[0].rdata = {16'(row*4+4), 16'(row*4+3), 16'(row*4+2), 16'(row*4+1)};
                response_count++;
            end else begin
                sif.dram_be_res[0].valid = 1'b0;
            end

            timeout++;
        end while (sif.sched_stall[0] && timeout < 500);

        sif.dram_be_res[0] = '0;
        sif.sched_req[0].valid = 1'b0;
        repeat (5) @(posedge clk);

        if (addr_errors == 0)
            report_success($sformatf("Tile %0dx%0d in %0d-col matrix, stride=%0d, %0d DRAM reqs verified",
                           num_rows+1, num_cols+1, full_cols+1, full_cols+1, response_count));
        else
            report_error($sformatf("%0d address errors (tile %0dx%0d in %0d-col matrix)",
                         addr_errors, num_rows+1, num_cols+1, full_cols+1));
    endtask

    task automatic run_stride_tests();
        $display("\n======== FULL MATRIX STRIDE TESTS ========\n");

        // 4x8 tile from a 64-column matrix
        do_reset();
        test_dma_load_stride(3, 7, 63, 32'h0000);

        // 4x8 tile from a 128-column matrix at offset
        do_reset();
        test_dma_load_stride(3, 7, 127, 32'h1000);

        // 8x16 tile from a 256-column matrix
        do_reset();
        test_dma_load_stride(7, 15, 255, 32'h0000);

        // 1x4 tile from a 512-column matrix (single row, stride irrelevant but should still work)
        do_reset();
        test_dma_load_stride(0, 3, 511, 32'h2000);

        // 4x4 tile from a 1024-column matrix at non-zero base
        do_reset();
        test_dma_load_stride(3, 3, 1023, 32'h4000);

        // 8x32 tile from a 256-column matrix (tile cols == 32 but matrix is wider)
        do_reset();
        test_dma_load_stride(7, 31, 255, 32'h0000);

        // 32x32 tile from a 32-column matrix (full_num_cols == num_cols, sanity check)
        do_reset();
        test_dma_load_stride(31, 31, 31, 32'h0000);

        // 2x8 tile from a large 4096-column matrix
        do_reset();
        test_dma_load_stride(1, 7, 4095, 32'h0000);
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

        // Phase 7: Dual-scratchpad concurrent
        run_dual_spad_tests();

        // Phase 8: DRAM robustness (reorder + stall injection)
        run_dram_robustness_tests();

        // Phase 9: DMA STORE data content verification
        run_dma_store_data_tests();

        // Phase 10: Reset mid-operation
        run_reset_tests();

        // Phase 11: Random toggle coverage sweep
        run_random_sweep_tests();

        // Phase 12: Concurrent R+W (dual FIFO verification)
        run_concurrent_rw_tests();

        // Phase 13: Full matrix stride (full_num_cols != num_cols)
        run_stride_tests();
        
        print_summary();
        
        if (failed_tests > 0) begin
            $display("FATAL: Test suite failed with %0d failures", failed_tests);
        end
        $finish;
    end
    
    // Timeout watchdog
    initial begin
        #5000000;  // Increased timeout for full test suite
        $display("\n[TIMEOUT] Simulation exceeded time limit\n");
        $finish;
    end

endmodule