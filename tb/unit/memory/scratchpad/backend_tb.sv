`timescale 1ps/1ps

`include "scpad_if.sv"
import scpad_pkg::*;

module backend_tb;
    localparam CLK_PERIOD = 10; 
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    scpad_if bif(clk, n_rst);
    backend #(.IDX(0)) DUT (.bshif(bif), .bbif(bif), .bdrif(bif));
    initial begin
        n_rst = 0;
        repeat (5) @(posedge clk);
        n_rst = 1;
    end
    
    // Simple 1-cycle delay DRAM response model (active when dram_stall_test_active is set)
    logic dram_stall_test_active;  // Driven by program
    logic [7:0] dram_resp_id_reg;
    logic dram_resp_valid_reg;
    
    always_ff @(posedge clk or negedge n_rst) begin
        if (!n_rst) begin
            dram_resp_valid_reg <= 0;
            dram_resp_id_reg <= 0;
        end else if (dram_stall_test_active) begin
            // Simple FF: capture request, output as response next cycle
            dram_resp_valid_reg <= bif.be_dram_req[0].valid;
            dram_resp_id_reg <= bif.be_dram_req[0].id;
        end else begin
            // Clear when not active
            dram_resp_valid_reg <= 0;
            dram_resp_id_reg <= 0;
        end
    end
    
    // Generate response data from ID
    wire [4:0] resp_row = dram_resp_id_reg[7:3];
    wire [2:0] resp_sub = dram_resp_id_reg[2:0];
    wire [63:0] resp_rdata = {
        16'((resp_row << 8) | (resp_sub * 4 + 4)),
        16'((resp_row << 8) | (resp_sub * 4 + 3)),
        16'((resp_row << 8) | (resp_sub * 4 + 2)),
        16'((resp_row << 8) | (resp_sub * 4 + 1))
    };
    
    // Simple 1-cycle delay SRAM response model for STORE tests
    logic sram_stall_test_active;  // Driven by program
    logic sram_resp_valid_reg;
    logic [4:0] sram_resp_row_reg;
    
    always_ff @(posedge clk or negedge n_rst) begin
        if (!n_rst) begin
            sram_resp_valid_reg <= 0;
            sram_resp_row_reg <= 0;
        end else if (sram_stall_test_active) begin
            // Capture read requests (valid && !write), output response next cycle
            sram_resp_valid_reg <= bif.be_req[0].valid && !bif.be_req[0].write;
            sram_resp_row_reg <= bif.be_req[0].row_id;
        end else begin
            sram_resp_valid_reg <= 0;
            sram_resp_row_reg <= 0;
        end
    end
    
    test PROG (.bif(bif), 
               .dram_stall_test_active(dram_stall_test_active),
               .dram_resp_valid_reg(dram_resp_valid_reg), 
               .dram_resp_id_reg(dram_resp_id_reg),
               .resp_rdata(resp_rdata),
               .sram_stall_test_active(sram_stall_test_active),
               .sram_resp_valid_reg(sram_resp_valid_reg),
               .sram_resp_row_reg(sram_resp_row_reg)); 
endmodule

program test (
    scpad_if.backend_tb bif,
    output logic dram_stall_test_active,
    input logic dram_resp_valid_reg,
    input logic [7:0] dram_resp_id_reg,
    input logic [63:0] resp_rdata,
    output logic sram_stall_test_active,
    input logic sram_resp_valid_reg,
    input logic [4:0] sram_resp_row_reg
);
    localparam CLK_PERIOD = 10;
    import scpad_pkg::*;

    // Test tracking
    int total_tests = 0;
    int passed_tests = 0;
    int failed_tests = 0;
    
    // Current test context
    int current_num_rows;
    int current_num_cols;
    string current_test_type;

    // Verification tracking
    int sram_rows_received, sram_rows_expected, sram_errors;
    int store_be_req_count, store_dram_req_count, store_errors;
    logic [15:0] expected_row_data [32];

    //==========================================================================
    // Utility Functions
    //==========================================================================
    task automatic report_error(string msg);
        $display("[FAIL] %s | Matrix: %0dx%0d (num_rows=%0d, num_cols=%0d) | %s", 
                 current_test_type, current_num_rows+1, current_num_cols+1,
                 current_num_rows, current_num_cols, msg);
        failed_tests++;
    endtask

    task automatic report_success(string msg);
        $display("[PASS] %s | Matrix: %0dx%0d | %s", 
                 current_test_type, current_num_rows+1, current_num_cols+1, msg);
        passed_tests++;
    endtask

    task schedule_request(
        logic valid, logic write,
        logic [SCPAD_ADDR_WIDTH-1:0] spad_addr,
        logic [DRAM_ADDR_WIDTH-1:0] dram_addr,
        logic [MAX_DIM_WIDTH-1:0] num_rows,
        logic [MAX_DIM_WIDTH-1:0] num_cols,
        logic [SCPAD_ID_WIDTH-1:0] scpad_id
    );
        bif.sched_req[scpad_id].valid = valid;
        bif.sched_req[scpad_id].write = write;
        bif.sched_req[scpad_id].spad_addr = spad_addr;
        bif.sched_req[scpad_id].dram_addr = dram_addr;
        bif.sched_req[scpad_id].num_rows = num_rows;
        bif.sched_req[scpad_id].num_cols = num_cols;
        // For backend tests, full_num_cols == num_cols (tile is the full matrix)
        bif.sched_req[scpad_id].full_num_cols = FULL_MATRIX_DIM_WIDTH'(num_cols);
        bif.sched_req[scpad_id].scpad_id = scpad_id;
    endtask

    function automatic logic [3:0] calc_expected_mask(int num_cols, int sub_id, int num_requests);
        if (sub_id == num_requests) begin
            case (num_cols[1:0])
                2'b00: return 4'b0001;
                2'b01: return 4'b0011;
                2'b10: return 4'b0111;
                2'b11: return 4'b1111;
            endcase
        end else return 4'b1111;
    endfunction

    function automatic logic [31:0] calc_expected_addr(logic [31:0] base_addr, int num_cols, int row_id, int sub_id);
        if (num_cols == 31) return base_addr + {row_id[4:0], sub_id[2:0], 2'b00};
        else return base_addr + row_id * (num_cols + 1) + {sub_id[2:0], 2'b00};
    endfunction

    function automatic logic [31:0] calc_expected_store_addr(logic [31:0] base_addr, int num_cols, int sched_counter, int sub_id);
        if (num_cols == 31) return base_addr + {sched_counter[4:0], sub_id[2:0], 2'b00};
        else return base_addr + sched_counter * (num_cols + 1) + {sub_id[2:0], 2'b00};
    endfunction

    task automatic clear_expected_row();
        for (int i = 0; i < 32; i++) expected_row_data[i] = 16'h0000;
    endtask

    task automatic store_expected_data(int sub_id, logic [63:0] rdata, logic [3:0] mask);
        int base_elem = sub_id * 4;
        if (mask[0]) expected_row_data[base_elem + 0] = rdata[15:0];
        if (mask[1]) expected_row_data[base_elem + 1] = rdata[31:16];
        if (mask[2]) expected_row_data[base_elem + 2] = rdata[47:32];
        if (mask[3]) expected_row_data[base_elem + 3] = rdata[63:48];
    endtask

    // Verify be_req output (SRAM write from LOAD operation)
    task automatic verify_be_req_write(int expected_row, int num_cols, logic [SCPAD_ADDR_WIDTH-1:0] base_spad_addr);
        automatic int errors = 0;
        automatic logic [SCPAD_ADDR_WIDTH-1:0] expected_spad_addr;
        automatic scpad_data_t actual_wdata;
        
        expected_spad_addr = base_spad_addr + (expected_row << ROW_SHIFT);
        actual_wdata = bif.be_req[0].wdata;
        
        if (bif.be_req[0].spad_addr !== expected_spad_addr) begin
            $display("    [BE_REQ ERROR] Row %0d: spad_addr mismatch - Got 0x%05h, Expected 0x%05h",
                     expected_row, bif.be_req[0].spad_addr, expected_spad_addr);
            errors++;
        end
        
        if (bif.be_req[0].valid !== 1'b1) begin
            $display("    [BE_REQ ERROR] Row %0d: valid not asserted", expected_row);
            errors++;
        end
        
        if (bif.be_req[0].write !== 1'b1) begin
            $display("    [BE_REQ ERROR] Row %0d: write not asserted (should be 1 for SRAM write)", expected_row);
            errors++;
        end
        
        // Check wdata elements
        for (int elem = 0; elem <= num_cols; elem++) begin
            if (actual_wdata[elem] !== expected_row_data[elem]) begin
                $display("    [BE_REQ ERROR] Row %0d, Element %0d: wdata mismatch - Got 0x%04h, Expected 0x%04h",
                         expected_row, elem, actual_wdata[elem], expected_row_data[elem]);
                errors++;
            end
        end
        
        sram_errors += errors;
    endtask

    //==========================================================================
    // LOAD: DRAM Read -> be_req Write to SRAM
    //==========================================================================
    task automatic dram_results_with_full_check();
        automatic int chunks = (bif.sched_req[0].num_cols + 1 + 3) / 4;
        automatic int total_requests = chunks * (bif.sched_req[0].num_rows + 1);
        automatic int num_cols = bif.sched_req[0].num_cols;
        automatic int num_rows = bif.sched_req[0].num_rows;
        automatic int num_req_per_row = num_cols >> 2;
        automatic logic [31:0] base_dram_addr = bif.sched_req[0].dram_addr;
        automatic logic [SCPAD_ADDR_WIDTH-1:0] base_spad_addr = bif.sched_req[0].spad_addr;
        
        automatic int request_count = 0;
        automatic int dram_errors = 0;
        automatic logic [31:0] expected_addr;
        automatic logic [3:0] expected_mask;
        automatic logic [7:0] expected_id;
        automatic int expected_row, expected_sub;
        automatic logic [63:0] rdata_to_send;
        automatic int timeout_counter = 0;
        
        sram_rows_received = 0;
        sram_rows_expected = num_rows + 1;
        sram_errors = 0;
        clear_expected_row();
        
        begin
            // Latch sdma_done across loops since it's a one-cycle pulse
            automatic logic done_seen = 0;
            
            // Wait for one clock edge to let backend latch sched_req,
            // then drop valid so it doesn't re-accept after completion.
            @(posedge bif.clk);
            #1;
            bif.sched_req[0].valid = 1'b0;
            
            // Send DRAM responses
            for (int i = 0; i < total_requests + 1; i++) begin
                
                // Check for be_req writes FIRST
                if (bif.be_req[0].valid && bif.be_req[0].write) begin
                    verify_be_req_write(sram_rows_received, num_cols, base_spad_addr);
                    sram_rows_received++;
                    clear_expected_row();
                end
                
                // Capture sdma_done if it pulses during this cycle
                if (bif.sdma_done[0]) done_seen = 1;
                
                bif.dram_be_res[0].valid = bif.be_dram_req[0].valid;
                bif.dram_be_res[0].write = bif.be_dram_req[0].write;
                bif.dram_be_res[0].id    = bif.be_dram_req[0].id;
                bif.dram_be_res[0].dram_vector_mask = bif.be_dram_req[0].dram_vector_mask;
                
                if (bif.be_dram_req[0].valid) begin
                    request_count++;
                    expected_row = (request_count - 1) / chunks;
                    expected_sub = (request_count - 1) % chunks;
                    
                    expected_addr = calc_expected_addr(base_dram_addr, num_cols, expected_row, expected_sub);
                    expected_mask = calc_expected_mask(num_cols, expected_sub, num_req_per_row);
                    expected_id = {expected_row[4:0], expected_sub[2:0]};
                    
                    // Verify DRAM request
                    if (bif.be_dram_req[0].dram_addr !== expected_addr) begin
                        $display("  [DRAM ERROR] Req %0d: Addr - Got 0x%08h, Expected 0x%08h",
                                 request_count, bif.be_dram_req[0].dram_addr, expected_addr);
                        dram_errors++;
                    end
                    
                    rdata_to_send = {
                        16'((expected_row << 8) | (expected_sub * 4 + 4)),
                        16'((expected_row << 8) | (expected_sub * 4 + 3)),
                        16'((expected_row << 8) | (expected_sub * 4 + 2)),
                        16'((expected_row << 8) | (expected_sub * 4 + 1))
                    };
                    store_expected_data(expected_sub, rdata_to_send, expected_mask);
                    bif.dram_be_res[0].rdata = rdata_to_send;
                end else begin
                    bif.dram_be_res[0].rdata = 64'h0;
                end
                #(CLK_PERIOD);
            end
            
            bif.dram_be_res[0] = '0;
            
            // Wait for completion (or short-circuit if done already pulsed)
            timeout_counter = 0;
            while (!done_seen && bif.sdma_done[0] !== 1'b1) begin
                if (bif.be_req[0].valid && bif.be_req[0].write) begin
                    verify_be_req_write(sram_rows_received, num_cols, base_spad_addr);
                    sram_rows_received++;
                    clear_expected_row();
                end
                if (bif.sdma_done[0]) done_seen = 1;
                #(CLK_PERIOD);
                timeout_counter++;
                if (timeout_counter > 200) break;
            end
            
            if (bif.be_req[0].valid && bif.be_req[0].write && sram_rows_received < sram_rows_expected) begin
                verify_be_req_write(sram_rows_received, num_cols, base_spad_addr);
                sram_rows_received++;
            end
            
            #(CLK_PERIOD/2);
            bif.sched_req[0].valid = 1'b0;
            #(CLK_PERIOD/2);
            #(CLK_PERIOD);
            
            if (sram_rows_received !== sram_rows_expected) begin
                $display("  [COUNT ERROR] be_req writes: Got %0d, Expected %0d", sram_rows_received, sram_rows_expected);
                sram_errors++;
            end
            
            total_tests++;
            if (dram_errors == 0 && sram_errors == 0)
                report_success($sformatf("DRAM: %0d reqs | BE_REQ: %0d writes", request_count, sram_rows_received));
            else
                report_error($sformatf("DRAM: %0d errs | BE_REQ: %0d errs", dram_errors, sram_errors));
        end
    endtask

    //==========================================================================
    // STORE: be_req Read from SRAM -> DRAM Write
    // 
    // TIMING MODEL (registered sram_res in queue, 1-cycle SRAM latency):
    //   Cycle N:   be_req row 0 appears (combinational)
    //   Cycle N+1: be_res row 0 set (1-cycle SRAM latency)
    //   Cycle N+2: Queue registers sram_res_valid, computes nxt_fifo_tail
    //   Cycle N+3: FIFO entry captured, DRAM write appears
    //
    // Uses 2-stage pipeline: pending -> active to ensure proper timing
    //==========================================================================
    task automatic sram_store_with_full_check();
        automatic int num_cols = bif.sched_req[0].num_cols;
        automatic int num_rows = bif.sched_req[0].num_rows;
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;
        automatic int total_dram_writes = chunks_per_row * (num_rows + 1);
        automatic int num_req_per_row = num_cols >> 2;
        automatic logic [31:0] base_dram_addr = bif.sched_req[0].dram_addr;
        automatic logic [SCPAD_ADDR_WIDTH-1:0] base_spad_addr = bif.sched_req[0].spad_addr;
        
        automatic int be_req_errors = 0;
        automatic int dram_req_errors = 0;
        automatic int rows_requested = 0;
        automatic int dram_writes_seen = 0;
        automatic logic [31:0] expected_addr;
        automatic logic [3:0] expected_mask;
        automatic int timeout_counter = 0;
        
        // 2-stage response pipeline for proper timing with registered queue
        automatic logic response_pending = 0;
        automatic logic response_active = 0;
        automatic int pending_row = 0;
        automatic int active_row = 0;
        
        localparam int LANES = 32;
        
        store_be_req_count = 0;
        store_dram_req_count = 0;
        
        begin
            bif.be_res[0] = '0;
            response_pending = 0;
            response_active = 0;
            
            // Latch sdma_done across loops since it's a one-cycle pulse
            begin
                automatic logic done_seen = 0;
            
            // Sample be_req combinationally on the acceptance cycle BEFORE
            // any clock edge advances uuid. The backend drives be_req.valid=1
            // for row 0 the moment sched_req.valid arrives (busy=0, uuid=0).
            #0;
            if (bif.be_req[0].valid && !bif.be_req[0].write) begin
                automatic logic [SCPAD_ADDR_WIDTH-1:0] expected_spad_addr;
                store_be_req_count++;
                expected_spad_addr = base_spad_addr + (rows_requested << ROW_SHIFT);
                
                if (bif.be_req[0].spad_addr !== expected_spad_addr) begin
                    $display("  [BE_REQ RD ERROR] Row %0d: spad_addr - Got 0x%05h, Expected 0x%05h",
                             rows_requested, bif.be_req[0].spad_addr, expected_spad_addr);
                    be_req_errors++;
                end
                
                response_pending = 1;
                pending_row = rows_requested;
                rows_requested++;
            end
            
            // Now wait for the posedge (FF latches), then drop valid so
            // the backend doesn't re-accept after completion.
            @(posedge bif.clk);
            #1;
            bif.sched_req[0].valid = 1'b0;
            
            // Promote initial pending to active
            if (response_pending) begin
                response_active = 1;
                active_row = pending_row;
                response_pending = 0;
            end
            
            // Main loop
            while (dram_writes_seen < total_dram_writes) begin
                
                // Check for new be_req BEFORE advancing time, so we catch
                // the combinational pulse on the current cycle
                if (bif.be_req[0].valid && !bif.be_req[0].write && rows_requested <= num_rows) begin
                    automatic logic [SCPAD_ADDR_WIDTH-1:0] expected_spad_addr;
                    store_be_req_count++;
                    expected_spad_addr = base_spad_addr + (rows_requested << ROW_SHIFT);
                    
                    if (bif.be_req[0].spad_addr !== expected_spad_addr) begin
                        $display("  [BE_REQ RD ERROR] Row %0d: spad_addr - Got 0x%05h, Expected 0x%05h",
                                 rows_requested, bif.be_req[0].spad_addr, expected_spad_addr);
                        be_req_errors++;
                    end
                    
                    response_pending = 1;
                    pending_row = rows_requested;
                    rows_requested++;
                end
                
                #(CLK_PERIOD);
                
                // Capture sdma_done if it pulses during this cycle
                if (bif.sdma_done[0]) done_seen = 1;
                
                // Output be_res for active response
                if (response_active) begin
                    bif.be_res[0].valid = 1'b1;
                    bif.be_res[0].write = 1'b0;
                    for (int elem = 0; elem < LANES; elem++)
                        bif.be_res[0].rdata[elem] = 16'((active_row * 32) + elem + 1);
                    response_active = 0;
                end else begin
                    bif.be_res[0].valid = 1'b0;
                    bif.be_res[0].rdata = '0;
                end
                
                // Check for DRAM write
                if (bif.be_dram_req[0].valid && bif.be_dram_req[0].write) begin
                    automatic int current_row = dram_writes_seen / chunks_per_row;
                    automatic int current_sub = dram_writes_seen % chunks_per_row;
                    store_dram_req_count++;
                    
                    expected_addr = calc_expected_store_addr(base_dram_addr, num_cols, current_row, current_sub);
                    expected_mask = calc_expected_mask(num_cols, current_sub, num_req_per_row);
                    
                    if (bif.be_dram_req[0].dram_addr !== expected_addr) begin
                        $display("  [DRAM WR ERROR] Write %0d: Addr - Got 0x%08h, Expected 0x%08h",
                                 dram_writes_seen, bif.be_dram_req[0].dram_addr, expected_addr);
                        dram_req_errors++;
                    end
                    if (bif.be_dram_req[0].dram_vector_mask !== expected_mask) begin
                        $display("  [DRAM WR ERROR] Write %0d: Mask - Got 4'b%04b, Expected 4'b%04b",
                                 dram_writes_seen, bif.be_dram_req[0].dram_vector_mask, expected_mask);
                        dram_req_errors++;
                    end
                    
                    // Verify wdata
                    begin
                        automatic int base_elem = current_sub * 4;
                        automatic logic [15:0] actual_elem [4];
                        automatic logic [15:0] expected_elem;
                        
                        actual_elem[0] = bif.be_dram_req[0].wdata[15:0];
                        actual_elem[1] = bif.be_dram_req[0].wdata[31:16];
                        actual_elem[2] = bif.be_dram_req[0].wdata[47:32];
                        actual_elem[3] = bif.be_dram_req[0].wdata[63:48];
                        
                        for (int e = 0; e < 4; e++) begin
                            if (expected_mask[e]) begin
                                expected_elem = 16'((current_row * 32) + base_elem + e + 1);
                                if (actual_elem[e] !== expected_elem) begin
                                    $display("  [DRAM WR ERROR] Write %0d, Elem %0d: wdata - Got 0x%04h, Expected 0x%04h",
                                             dram_writes_seen, e, actual_elem[e], expected_elem);
                                    dram_req_errors++;
                                end
                            end
                        end
                    end
                    
                    dram_writes_seen++;
                end
                
                // Promote pending -> active
                if (response_pending) begin
                    response_active = 1;
                    active_row = pending_row;
                    response_pending = 0;
                end
                
                timeout_counter++;
                if (timeout_counter > 5000) begin
                    $display("  [TIMEOUT] Store timeout after %0d cycles", timeout_counter);
                    break;
                end
            end
            
            // Drain remaining responses
            while (response_pending || response_active) begin
                #(CLK_PERIOD);
                if (bif.sdma_done[0]) done_seen = 1;
                if (response_active) begin
                    bif.be_res[0].valid = 1'b1;
                    bif.be_res[0].write = 1'b0;
                    for (int elem = 0; elem < LANES; elem++)
                        bif.be_res[0].rdata[elem] = 16'((active_row * 32) + elem + 1);
                    response_active = 0;
                end else begin
                    bif.be_res[0].valid = 1'b0;
                end
                if (response_pending) begin
                    response_active = 1;
                    active_row = pending_row;
                    response_pending = 0;
                end
            end
            
            // Wait for completion (or short-circuit if done already pulsed)
            bif.be_res[0] = '0;
            timeout_counter = 0;
            while (!done_seen && bif.sdma_done[0] !== 1'b1) begin
                if (bif.sdma_done[0]) done_seen = 1;
                #(CLK_PERIOD);
                timeout_counter++;
                if (timeout_counter > 500) begin
                    $display("  [TIMEOUT] Waiting for sched_res after %0d cycles", timeout_counter);
                    break;
                end
            end
            end // close done_seen begin block
            
            schedule_request(1'b0, 1'b0, 20'd0, 32'd0, 5'b0, 5'b0, 1'b0);
            bif.be_res[0] = '0;
            #(CLK_PERIOD * 2);
            
            if (store_be_req_count !== (num_rows + 1)) begin
                be_req_errors++;
            end
            if (dram_writes_seen !== total_dram_writes) begin
                dram_req_errors++;
            end
            
            total_tests++;
            store_errors = be_req_errors + dram_req_errors;
            if (store_errors == 0)
                report_success($sformatf("BE_REQ: %0d reads | DRAM: %0d writes", store_be_req_count, dram_writes_seen));
            else
                report_error($sformatf("BE_REQ: %0d errs | DRAM: %0d errs", be_req_errors, dram_req_errors));
        end
    endtask

    //==========================================================================
    // Test Wrappers
    //==========================================================================
    task automatic scpad_load_all_dims(); 
        current_test_type = "LOAD";
        $display("\n======== LOAD tests for all matrix sizes ========\n");
        for (int i = 0; i < 32; i++) begin
            for (int j = 0; j < 32; j++) begin
                current_num_rows = i; current_num_cols = j;
                schedule_request(1'b1, 1'b0, 20'd0, 32'd0, 5'(i), 5'(j), 1'b0);
                dram_results_with_full_check();
            end
            if ((i + 1) % 8 == 0) $display("--- Completed %0d/32 row iterations ---", i + 1);
        end
    endtask

    task automatic scpad_store_all_dims();
        current_test_type = "STORE";
        $display("\n======== STORE tests for all matrix sizes ========\n");
        for (int i = 0; i < 32; i++) begin
            for (int j = 0; j < 32; j++) begin
                current_num_rows = i; current_num_cols = j;
                schedule_request(1'b1, 1'b1, 20'd0, 32'd0, 5'(i), 5'(j), 1'b0);
                sram_store_with_full_check();
            end
            if ((i + 1) % 8 == 0) $display("--- Completed %0d/32 row iterations ---", i + 1);
        end
    endtask

    task automatic scpad_load_specific(int num_rows, int num_cols);
        current_test_type = "LOAD"; current_num_rows = num_rows; current_num_cols = num_cols;
        $display("\nTesting LOAD: %0dx%0d", num_rows+1, num_cols+1);
        schedule_request(1'b1, 1'b0, 20'd0, 32'd0, 5'(num_rows), 5'(num_cols), 1'b0);
        dram_results_with_full_check();
    endtask

    task automatic scpad_store_specific(int num_rows, int num_cols);
        current_test_type = "STORE"; current_num_rows = num_rows; current_num_cols = num_cols;
        $display("\nTesting STORE: %0dx%0d", num_rows+1, num_cols+1);
        schedule_request(1'b1, 1'b1, 20'd0, 32'd0, 5'(num_rows), 5'(num_cols), 1'b0);
        sram_store_with_full_check();
    endtask

    // Tests with different base addresses
    task automatic scpad_load_with_addr(int num_rows, int num_cols, logic [19:0] spad_addr, logic [31:0] dram_addr);
        current_test_type = "LOAD"; current_num_rows = num_rows; current_num_cols = num_cols;
        $display("\nTesting LOAD: %0dx%0d @ spad=0x%05h, dram=0x%08h", num_rows+1, num_cols+1, spad_addr, dram_addr);
        schedule_request(1'b1, 1'b0, spad_addr, dram_addr, 5'(num_rows), 5'(num_cols), 1'b0);
        dram_results_with_full_check();
    endtask

    task automatic scpad_store_with_addr(int num_rows, int num_cols, logic [19:0] spad_addr, logic [31:0] dram_addr);
        current_test_type = "STORE"; current_num_rows = num_rows; current_num_cols = num_cols;
        $display("\nTesting STORE: %0dx%0d @ spad=0x%05h, dram=0x%08h", num_rows+1, num_cols+1, spad_addr, dram_addr);
        schedule_request(1'b1, 1'b1, spad_addr, dram_addr, 5'(num_rows), 5'(num_cols), 1'b0);
        sram_store_with_full_check();
    endtask

    // Test various base address combinations
    task automatic test_base_addresses();
        // spad_addr must be 64-aligned (row boundary, ROW_BYTES), dram_addr can be any 4-byte aligned
        $display("\n======== BASE ADDRESS TESTS ========\n");
        
        // LOAD with various addresses
        current_test_type = "LOAD";
        $display("--- LOAD with different base addresses ---");
        scpad_load_with_addr(0, 0,   20'h00040, 32'h00001000);  // 1x1 @ spad row 1, dram 0x1000
        scpad_load_with_addr(1, 3,   20'h00080, 32'h00002000);  // 2x4 @ spad row 2, dram 0x2000
        scpad_load_with_addr(3, 7,   20'h00200, 32'h80000000);  // 4x8 @ spad row 8, dram high addr
        scpad_load_with_addr(7, 15,  20'h00400, 32'hDEAD0000);  // 8x16 @ spad row 16
        scpad_load_with_addr(15, 31, 20'h007C0, 32'hCAFE0000);  // 16x32 @ spad row 31
        scpad_load_with_addr(31, 31, 20'h00800, 32'hFFFF0000);  // 32x32 @ spad row 32
        
        // STORE with various addresses  
        current_test_type = "STORE";
        $display("\n--- STORE with different base addresses ---");
        scpad_store_with_addr(0, 0,   20'h00040, 32'h00001000);  // 1x1 @ spad row 1, dram 0x1000
        scpad_store_with_addr(1, 3,   20'h00080, 32'h00002000);  // 2x4 @ spad row 2, dram 0x2000
        scpad_store_with_addr(3, 7,   20'h00200, 32'h80000000);  // 4x8 @ spad row 8, dram high addr
        scpad_store_with_addr(7, 15,  20'h00400, 32'hDEAD0000);  // 8x16 @ spad row 16
        scpad_store_with_addr(15, 31, 20'h007C0, 32'hCAFE0000);  // 16x32 @ spad row 31
        scpad_store_with_addr(31, 31, 20'h00800, 32'hFFFF0000);  // 32x32 @ spad row 32
        
        // Edge case: max addresses
        $display("\n--- Edge case addresses ---");
        scpad_load_with_addr(0, 0,   20'hFFFC0, 32'hFFFFFFF0);   // Near max spad, near max dram
        scpad_store_with_addr(0, 0,  20'hFFFC0, 32'hFFFFFFF0);
    endtask

    // All dimensions with varied base addresses
    task automatic scpad_load_all_dims_with_addrs();
        automatic logic [19:0] spad_base;
        automatic logic [31:0] dram_base;
        current_test_type = "LOAD";
        $display("\n======== LOAD tests (all dims, varied addresses) ========\n");
        for (int i = 0; i < 32; i++) begin
            for (int j = 0; j < 32; j++) begin
                // Rotate through different base addresses
                // spad_addr: use different row-aligned bases (multiples of 32)
                spad_base = 20'(((i * 32 + j) % 16) << ROW_SHIFT);  // row-aligned bases
                dram_base = 32'(((i * 32 + j) % 8) << 12);  // 0x0000, 0x1000, 0x2000, ... 0x7000
                current_num_rows = i; current_num_cols = j;
                schedule_request(1'b1, 1'b0, spad_base, dram_base, 5'(i), 5'(j), 1'b0);
                dram_results_with_full_check();
            end
            if ((i + 1) % 8 == 0) $display("--- Completed %0d/32 row iterations ---", i + 1);
        end
    endtask

    task automatic scpad_store_all_dims_with_addrs();
        automatic logic [19:0] spad_base;
        automatic logic [31:0] dram_base;
        current_test_type = "STORE";
        $display("\n======== STORE tests (all dims, varied addresses) ========\n");
        for (int i = 0; i < 32; i++) begin
            for (int j = 0; j < 32; j++) begin
                // Rotate through different base addresses
                // spad_addr: use different row-aligned bases (multiples of 32)
                spad_base = 20'(((i * 32 + j) % 16) << ROW_SHIFT);  // row-aligned bases
                dram_base = 32'(((i * 32 + j) % 8) << 12);  // 0x0000, 0x1000, 0x2000, ... 0x7000
                current_num_rows = i; current_num_cols = j;
                schedule_request(1'b1, 1'b1, spad_base, dram_base, 5'(i), 5'(j), 1'b0);
                sram_store_with_full_check();
            end
            if ((i + 1) % 8 == 0) $display("--- Completed %0d/32 row iterations ---", i + 1);
        end
    endtask

    //==========================================================================
    // STALL TESTS
    //==========================================================================

    // LOAD with be_stall: SRAM controller can't accept writes
    // Tests that operation completes correctly after stall is released
    task automatic test_load_with_be_stall();
        automatic int num_rows = 3;
        automatic int num_cols = 7;  // 4x8 matrix, 2 chunks per row = 8 DRAM requests
        automatic int chunks = (num_cols + 1 + 3) / 4;
        automatic int total_requests = chunks * (num_rows + 1);
        automatic int response_count = 0;
        automatic int stall_start_resp = 2;  // Stall after 2 DRAM responses (row 0 complete)
        automatic int stall_cycles = 5;
        automatic int timeout = 0;
        automatic int row, sub;
        automatic int stall_counter = 0;
        automatic logic stall_done = 0;  // Only stall once
        
        // FIFO for pending requests (DRAM receives requests, queues them, responds later)
        automatic logic [7:0] pending_ids [0:15];  // Queue of pending request IDs
        automatic int pending_head = 0;  // Next to respond
        automatic int pending_tail = 0;  // Next to enqueue
        automatic int pending_count = 0;
        automatic int captured_count = 0;  // Total requests captured
        automatic logic [7:0] resp_id;
        automatic logic [63:0] resp_rdata;
        automatic logic be_stall_at_start;  // Capture be_stall at start of each cycle
        
        current_test_type = "LOAD_BE_STALL";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        schedule_request(1'b1, 1'b0, 20'd0, 32'd0, 5'(num_rows), 5'(num_cols), 1'b0);
        sram_rows_received = 0;
        sram_errors = 0;
        clear_expected_row();
        bif.be_stall[0] = 1'b0;
        bif.dram_be_res[0] = '0;
        
        @(posedge bif.clk);
        
        // Main loop - check exit condition AFTER processing each cycle
        timeout = 0;
        while (timeout < 300) begin
            // Capture be_stall at START of cycle (before we potentially change it)
            // This is what the DUT saw at the clock edge
            be_stall_at_start = bif.be_stall[0];
            
            // Default: no response this cycle
            bif.dram_be_res[0].valid = 1'b0;
            
            // FIRST: Stall state machine - do this early so be_stall changes take effect
            if (!stall_done) begin
                if (!bif.be_stall[0] && response_count >= stall_start_resp) begin
                    bif.be_stall[0] = 1'b1;
                    stall_counter = 0;
                end else if (bif.be_stall[0]) begin
                    stall_counter++;
                    if (stall_counter >= stall_cycles) begin
                        bif.be_stall[0] = 1'b0;
                        stall_done = 1;
                    end
                end
            end
            
            // SECOND: Send response from FIFO head (only if not stalled)
            if (pending_count > 0 && !bif.be_stall[0]) begin
                resp_id = pending_ids[pending_head];
                pending_head = (pending_head + 1) % 16;
                pending_count--;
                
                // Decode row/sub from the request ID
                row = resp_id[7:3];  // uuid (row)
                sub = resp_id[2:0];  // sub_uuid (chunk within row)
                resp_rdata = {
                    16'((row << 8) | (sub * 4 + 4)),
                    16'((row << 8) | (sub * 4 + 3)),
                    16'((row << 8) | (sub * 4 + 2)),
                    16'((row << 8) | (sub * 4 + 1))
                };
                
                bif.dram_be_res[0].valid = 1'b1;
                bif.dram_be_res[0].id = resp_id;
                bif.dram_be_res[0].rdata = resp_rdata;
                response_count++;
            end
            
            // THIRD: Capture incoming requests into FIFO (limit to total_requests)
            if (bif.be_dram_req[0].valid && pending_count < 16 && captured_count < total_requests) begin
                pending_ids[pending_tail] = bif.be_dram_req[0].id;
                pending_tail = (pending_tail + 1) % 16;
                pending_count++;
                captured_count++;
            end
            
            // FOURTH: Count SRAM writes
            if (bif.be_req[0].valid && bif.be_req[0].write) begin
                sram_rows_received++;
                clear_expected_row();
                
                // Check: be_req writes should NOT happen if stall was active at START of cycle
                if (be_stall_at_start) begin
                    sram_errors++;
                end
            end
            
            // Check exit condition AFTER processing this cycle
            if (bif.sdma_done[0]) break;
            
            @(posedge bif.clk);
            timeout++;
        end
        
        // Cleanup
        bif.dram_be_res[0] = '0;
        bif.be_stall[0] = 1'b0;
        schedule_request(1'b0, 1'b0, 20'd0, 32'd0, 5'b0, 5'b0, 1'b0);
        #(CLK_PERIOD * 2);
        
        total_tests++;
        if (sram_errors == 0 && sram_rows_received == (num_rows + 1))
            report_success($sformatf("Stall handled correctly, %0d SRAM rows", sram_rows_received));
        else
            report_error($sformatf("errors=%0d, rows=%0d/%0d", sram_errors, sram_rows_received, num_rows+1));
    endtask

    // LOAD with dram_be_stall: DRAM controller can't accept requests
    // Queue should stop popping, operation should complete after stall released
    task automatic test_load_with_dram_stall();
        automatic int num_rows = 3;
        automatic int num_cols = 7;
        automatic int chunks = (num_cols + 1 + 3) / 4;
        automatic int total_requests = chunks * (num_rows + 1);
        automatic int response_count = 0;
        automatic int stall_start_req = 2;
        automatic int stall_cycles = 5;
        automatic int timeout = 0;
        automatic int stall_counter = 0;
        automatic logic stall_done = 0;
        automatic int captured_count = 0;
        
        current_test_type = "LOAD_DRAM_STALL";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        schedule_request(1'b1, 1'b0, 20'd0, 32'd0, 5'(num_rows), 5'(num_cols), 1'b0);
        sram_rows_received = 0;
        sram_errors = 0;
        bif.dram_be_stall[0] = 1'b0;
        bif.dram_be_res[0] = '0;
        
        // Enable the FF-based DRAM model
        dram_stall_test_active = 1;
        
        // Main loop
        timeout = 0;
        while (timeout < 300) begin
            @(posedge bif.clk);
            #1;
            
            // Wire the FF model outputs to dram_be_res
            bif.dram_be_res[0].valid = dram_resp_valid_reg;
            bif.dram_be_res[0].id = dram_resp_id_reg;
            bif.dram_be_res[0].rdata = resp_rdata;
            
            // Track responses and captures
            if (dram_resp_valid_reg) response_count++;
            if (bif.be_dram_req[0].valid) captured_count++;
            
            // Stall state machine
            if (!stall_done) begin
                if (!bif.dram_be_stall[0] && response_count >= stall_start_req) begin
                    bif.dram_be_stall[0] = 1'b1;
                    stall_counter = 0;
                end else if (bif.dram_be_stall[0]) begin
                    stall_counter++;
                    if (stall_counter >= stall_cycles) begin
                        bif.dram_be_stall[0] = 1'b0;
                        stall_done = 1;
                    end
                end
            end
            
            // Count SRAM writes
            if (bif.be_req[0].valid && bif.be_req[0].write) begin
                sram_rows_received++;
            end
            
            // Check exit condition
            if (bif.sdma_done[0]) break;
            
            timeout++;
        end
        
        // Cleanup
        dram_stall_test_active = 0;
        bif.dram_be_res[0] = '0;
        bif.dram_be_stall[0] = 1'b0;
        schedule_request(1'b0, 1'b0, 20'd0, 32'd0, 5'b0, 5'b0, 1'b0);
        #(CLK_PERIOD * 2);
        
        total_tests++;
        if (sram_rows_received == (num_rows + 1))
            report_success($sformatf("Stall handled correctly, %0d SRAM rows", sram_rows_received));
        else
            report_error($sformatf("rows=%0d/%0d", sram_rows_received, num_rows+1));
    endtask

    // STORE with be_stall: SRAM controller can't accept read requests
    // Backend should stop sending be_req reads while stalled
    task automatic test_store_with_be_stall();
        automatic int num_rows = 3;
        automatic int num_cols = 7;
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;
        automatic int total_dram_writes = chunks_per_row * (num_rows + 1);
        automatic int be_req_count = 0;
        automatic int dram_write_count = 0;
        automatic int response_count = 0;
        automatic int stall_after_responses = 2;
        automatic int stall_cycles = 5;
        automatic int stall_counter = 0;
        automatic logic stall_done = 0;
        automatic int errors = 0;
        automatic int timeout = 0;
        automatic logic be_stall_at_start;
        
        current_test_type = "STORE_BE_STALL";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        schedule_request(1'b1, 1'b1, 20'd0, 32'd0, 5'(num_rows), 5'(num_cols), 1'b0);
        bif.be_stall[0] = 1'b0;
        bif.be_res[0] = '0;
        
        // Enable the FF-based SRAM model
        sram_stall_test_active = 1;
        
        // Main loop
        timeout = 0;
        while (timeout < 300) begin
            @(posedge bif.clk);
            #1;
            
            // Capture stall state at start of cycle
            be_stall_at_start = bif.be_stall[0];
            
            // Wire the FF model outputs to be_res
            bif.be_res[0].valid = sram_resp_valid_reg;
            for (int i = 0; i < 32; i++)
                bif.be_res[0].rdata[i] = 16'((sram_resp_row_reg * 32) + i + 1);
            
            // Track responses
            if (sram_resp_valid_reg) response_count++;
            
            // Track be_req reads
            if (bif.be_req[0].valid && !bif.be_req[0].write) begin
                be_req_count++;
                if (be_stall_at_start) errors++;
            end
            
            // Track DRAM writes
            if (bif.be_dram_req[0].valid && bif.be_dram_req[0].write) begin
                dram_write_count++;
            end
            
            // Stall state machine
            if (!stall_done) begin
                if (!bif.be_stall[0] && response_count >= stall_after_responses) begin
                    bif.be_stall[0] = 1'b1;
                    stall_counter = 0;
                end else if (bif.be_stall[0]) begin
                    stall_counter++;
                    if (stall_counter >= stall_cycles) begin
                        bif.be_stall[0] = 1'b0;
                        stall_done = 1;
                    end
                end
            end
            
            // Check exit condition
            if (bif.sdma_done[0]) break;
            
            timeout++;
        end
        
        // Cleanup
        sram_stall_test_active = 0;
        bif.be_res[0] = '0;
        bif.be_stall[0] = 1'b0;
        schedule_request(1'b0, 1'b0, 20'd0, 32'd0, 5'b0, 5'b0, 1'b0);
        #(CLK_PERIOD * 2);
        
        total_tests++;
        if (errors == 0 && dram_write_count == total_dram_writes)
            report_success($sformatf("Stall handled, %0d DRAM writes", dram_write_count));
        else
            report_error($sformatf("errors=%0d, DRAM writes=%0d/%0d", errors, dram_write_count, total_dram_writes));
    endtask

    // STORE with dram_be_stall: DRAM controller can't accept writes
    // Queue should hold data until stall released
    task automatic test_store_with_dram_stall();
        automatic int num_rows = 3;
        automatic int num_cols = 7;
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;
        automatic int total_dram_writes = chunks_per_row * (num_rows + 1);
        automatic int dram_write_count = 0;
        automatic int stall_after_writes = 2;
        automatic int stall_cycles = 5;
        automatic int stall_counter = 0;
        automatic logic stall_done = 0;
        automatic int timeout = 0;
        
        current_test_type = "STORE_DRAM_STALL";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        schedule_request(1'b1, 1'b1, 20'd0, 32'd0, 5'(num_rows), 5'(num_cols), 1'b0);
        bif.dram_be_stall[0] = 1'b0;
        bif.be_res[0] = '0;
        
        // Enable the FF-based SRAM model
        sram_stall_test_active = 1;
        
        // Main loop
        timeout = 0;
        while (timeout < 300) begin
            @(posedge bif.clk);
            #1;
            
            // Wire the FF model outputs to be_res
            bif.be_res[0].valid = sram_resp_valid_reg;
            for (int i = 0; i < 32; i++)
                bif.be_res[0].rdata[i] = 16'((sram_resp_row_reg * 32) + i + 1);
            
            // Track DRAM writes — only count when not stalled (accepted by memory)
            if (bif.be_dram_req[0].valid && bif.be_dram_req[0].write && !bif.dram_be_stall[0]) begin
                dram_write_count++;
            end
            
            // Stall state machine
            if (!stall_done) begin
                if (!bif.dram_be_stall[0] && dram_write_count >= stall_after_writes) begin
                    bif.dram_be_stall[0] = 1'b1;
                    stall_counter = 0;
                end else if (bif.dram_be_stall[0]) begin
                    stall_counter++;
                    if (stall_counter >= stall_cycles) begin
                        bif.dram_be_stall[0] = 1'b0;
                        stall_done = 1;
                    end
                end
            end
            
            // Check exit condition
            if (bif.sdma_done[0]) break;
            
            timeout++;
        end
        
        // Cleanup
        sram_stall_test_active = 0;
        bif.be_res[0] = '0;
        bif.dram_be_stall[0] = 1'b0;
        schedule_request(1'b0, 1'b0, 20'd0, 32'd0, 5'b0, 5'b0, 1'b0);
        #(CLK_PERIOD * 2);
        
        total_tests++;
        if (dram_write_count == total_dram_writes)
            report_success($sformatf("Stall handled, %0d DRAM writes", dram_write_count));
        else
            report_error($sformatf("DRAM writes=%0d/%0d", dram_write_count, total_dram_writes));
    endtask

    // Run all stall tests
    task automatic test_all_stall_signals();
        $display("\n======== STALL SIGNAL TESTS ========\n");
        
        test_load_with_be_stall();
        test_load_with_dram_stall();
        test_store_with_be_stall();
        test_store_with_dram_stall();
        
        $display("\n======== FIFO FULL TESTS ========\n");
        test_store_fifo_full();
        test_load_fifo_full();
    endtask

    // STORE with extended DRAM stall to fill the request queue (FIFO full condition)
    // This tests lines 112-120 in dram_request_queue.sv where fifo_tail + 1 == fifo_head
    // Based on test_store_with_dram_stall but with longer stall to ensure queue fills
    task automatic test_store_fifo_full();
        automatic int num_rows = 31;   // 32 rows
        automatic int num_cols = 31;   // 32 cols = 8 chunks per row
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;  // 8 chunks per row
        automatic int total_dram_writes = chunks_per_row * (num_rows + 1);  // 256 total
        automatic int dram_write_count = 0;
        automatic int stall_after_writes = 2;  // Stall early
        automatic int stall_cycles = 50;       // Hold stall long enough to fill queue (depth=32)
        automatic int stall_counter = 0;
        automatic logic stall_done = 0;
        automatic int timeout = 0;
        
        current_test_type = "STORE_FIFO_FULL";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        schedule_request(1'b1, 1'b1, 20'd0, 32'd0, 5'(num_rows), 5'(num_cols), 1'b0);
        bif.dram_be_stall[0] = 1'b0;
        bif.be_res[0] = '0;
        
        // Enable the FF-based SRAM model
        sram_stall_test_active = 1;
        
        // Main loop
        timeout = 0;
        while (timeout < 1000) begin
            @(posedge bif.clk);
            #1;
            
            // After first cycle, deassert valid so backend doesn't re-accept
            if (timeout > 0) bif.sched_req[0].valid = 1'b0;
            
            // Wire the FF model outputs to be_res
            bif.be_res[0].valid = sram_resp_valid_reg;
            for (int i = 0; i < 32; i++)
                bif.be_res[0].rdata[i] = 16'((sram_resp_row_reg * 32) + i + 1);
            
            // Track DRAM writes — only count when not stalled (accepted by memory)
            if (bif.be_dram_req[0].valid && bif.be_dram_req[0].write && !bif.dram_be_stall[0]) begin
                dram_write_count++;
            end
            
            // Stall state machine - stall early, hold long to fill queue
            if (!stall_done) begin
                if (!bif.dram_be_stall[0] && dram_write_count >= stall_after_writes) begin
                    bif.dram_be_stall[0] = 1'b1;
                    stall_counter = 0;
                end else if (bif.dram_be_stall[0]) begin
                    stall_counter++;
                    if (stall_counter >= stall_cycles) begin
                        bif.dram_be_stall[0] = 1'b0;
                        stall_done = 1;
                    end
                end
            end
            
            // Check exit condition
            if (bif.sdma_done[0]) break;
            
            timeout++;
        end
        
        // Cleanup
        sram_stall_test_active = 0;
        bif.be_res[0] = '0;
        bif.dram_be_stall[0] = 1'b0;
        schedule_request(1'b0, 1'b0, 20'd0, 32'd0, 5'b0, 5'b0, 1'b0);
        #(CLK_PERIOD * 2);
        
        total_tests++;
        if (dram_write_count == total_dram_writes)
            report_success($sformatf("FIFO full tested, %0d DRAM writes, stall=%0d cycles", dram_write_count, stall_cycles));
        else
            report_error($sformatf("DRAM writes=%0d/%0d", dram_write_count, total_dram_writes));
    endtask

    // LOAD with DRAM stalled to fill the request queue (FIFO full condition on read path)
    // Backend sends DRAM read requests, but DRAM is stalled so they queue up
    // This tests the same fifo_full condition but for LOAD operations
    task automatic test_load_fifo_full();
        automatic int num_rows = 31;   // 32 rows
        automatic int num_cols = 31;   // 32 cols = 8 chunks per row = 256 total requests
        automatic int chunks_per_row = (num_cols + 1 + 3) / 4;
        automatic int total_requests = chunks_per_row * (num_rows + 1);
        automatic int sram_rows_received = 0;
        automatic int stall_after_reqs = 2;   // Stall early
        automatic int stall_cycles = 50;      // Hold stall long enough to fill queue
        automatic int stall_counter = 0;
        automatic logic stall_done = 0;
        automatic int dram_req_count = 0;
        automatic int timeout = 0;
        
        current_test_type = "LOAD_FIFO_FULL";
        current_num_rows = num_rows;
        current_num_cols = num_cols;
        
        schedule_request(1'b1, 1'b0, 20'd0, 32'd0, 5'(num_rows), 5'(num_cols), 1'b0);
        bif.dram_be_stall[0] = 1'b0;
        bif.dram_be_res[0] = '0;
        
        // Enable the FF-based DRAM model
        dram_stall_test_active = 1;
        
        // Main loop
        timeout = 0;
        while (timeout < 1500) begin
            @(posedge bif.clk);
            #1;
            
            // After first cycle, deassert valid so backend doesn't re-accept
            if (timeout > 0) bif.sched_req[0].valid = 1'b0;
            
            // Wire the FF model outputs to dram_be_res
            bif.dram_be_res[0].valid = dram_resp_valid_reg;
            bif.dram_be_res[0].id = dram_resp_id_reg;
            bif.dram_be_res[0].rdata = resp_rdata;
            
            // Count DRAM requests from backend
            if (bif.be_dram_req[0].valid && !bif.be_dram_req[0].write) begin
                dram_req_count++;
            end
            
            // Count SRAM writes
            if (bif.be_req[0].valid && bif.be_req[0].write) begin
                sram_rows_received++;
            end
            
            // Stall state machine - stall dram_be_stall to fill the request queue
            if (!stall_done) begin
                if (!bif.dram_be_stall[0] && dram_req_count >= stall_after_reqs) begin
                    bif.dram_be_stall[0] = 1'b1;
                    stall_counter = 0;
                end else if (bif.dram_be_stall[0]) begin
                    stall_counter++;
                    if (stall_counter >= stall_cycles) begin
                        bif.dram_be_stall[0] = 1'b0;
                        stall_done = 1;
                    end
                end
            end
            
            // Check exit condition
            if (bif.sdma_done[0]) break;
            
            timeout++;
        end
        
        // Cleanup
        dram_stall_test_active = 0;
        bif.dram_be_res[0] = '0;
        bif.dram_be_stall[0] = 1'b0;
        schedule_request(1'b0, 1'b0, 20'd0, 32'd0, 5'b0, 5'b0, 1'b0);
        #(CLK_PERIOD * 2);
        
        total_tests++;
        if (sram_rows_received == (num_rows + 1))
            report_success($sformatf("FIFO full tested, %0d DRAM reqs, %0d SRAM writes", dram_req_count, sram_rows_received));
        else
            report_error($sformatf("SRAM writes=%0d/%0d, DRAM reqs=%0d", sram_rows_received, num_rows + 1, dram_req_count));
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
    // Main
    //==========================================================================
    initial begin
        dram_stall_test_active = 0;  // Initialize FF model as inactive
        sram_stall_test_active = 0;  // Initialize SRAM FF model as inactive
        bif.dram_be_stall[0] = '0; bif.sched_req[0] = '0; bif.dram_be_res[0] = '0;
        bif.be_stall[0] = '0; bif.be_res[0] = '0;
        bif.dram_be_stall[1] = '0; bif.sched_req[1] = '0; bif.dram_be_res[1] = '0;
        bif.be_stall[1] = '0; bif.be_res[1] = '0;
        
        @(posedge bif.n_rst);
        #(CLK_PERIOD);

        $display("\n===== BACKEND AUTOMATED TEST SUITE =====");
        $display("Data patterns: row*32 + col + 1\n");

        $display("=== LOAD CORNER CASES ===");
        scpad_load_specific(0, 0);   // 1x1
        scpad_load_specific(0, 3);   // 1x4
        scpad_load_specific(0, 7);   // 1x8
        scpad_load_specific(0, 31);  // 1x32
        scpad_load_specific(1, 0);   // 2x1
        scpad_load_specific(31, 31); // 32x32

        $display("\n=== STORE CORNER CASES ===");
        scpad_store_specific(0, 0);    // 1x1
        scpad_store_specific(0, 3);    // 1x4
        scpad_store_specific(0, 7);    // 1x8
        scpad_store_specific(0, 31);   // 1x32
        scpad_store_specific(1, 0);    // 2x1
        scpad_store_specific(31, 31);  // 32x32

        // Full suites
        scpad_load_all_dims();
        scpad_store_all_dims();

        // Base address coverage
        test_base_addresses();

        // Full suites with varied addresses (2048 tests each)
        scpad_load_all_dims_with_addrs();
        scpad_store_all_dims_with_addrs();

        // Stall signal tests
        test_all_stall_signals();

        print_summary();
        if (failed_tests > 0) $fatal(1, "Test suite failed with %0d failures", failed_tests);
        $finish;
    end
endprogram