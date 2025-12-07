`timescale 1ps/1ps

`include "scpad_if.sv"
import scpad_pkg::*;

module frontend_tb;
    localparam CLK_PERIOD = 10; 
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;
    
    scpad_if sif(clk, n_rst);
    frontend #(.IDX(0)) DUT (.fvif(sif), .fsif(sif));
    
    initial begin
        n_rst = 0;
        repeat (5) @(posedge clk);
        n_rst = 1;
    end

    //==========================================================================
    // Program Block
    //==========================================================================
    program test (scpad_if sif);
        localparam CLK_PERIOD = 10;
        import scpad_pkg::*;
        
        // Test tracking
        int total_tests = 0;
        int passed_tests = 0;
        int failed_tests = 0;
        
        //======================================================================
        // Helper Tasks
        //======================================================================
        
        task automatic report_error(string test_name, string msg);
            $display("[FAIL] %s | %s", test_name, msg);
            failed_tests++;
        endtask
        
        task automatic report_success(string test_name, string msg);
            $display("[PASS] %s | %s", test_name, msg);
            passed_tests++;
        endtask
        
        //======================================================================
        // Test: Request Pass-through
        //======================================================================
        
        task automatic test_request_passthrough();
            automatic int errors = 0;
            
            $display("\n--- Test: Request Pass-through ---");
            
            // Clear stall
            sif.fe_stall[0] = 1'b0;
            
            // Send a request
            sif.vec_req[0].valid = 1'b1;
            sif.vec_req[0].write = 1'b1;
            sif.vec_req[0].spad_addr = 20'h00100;
            sif.vec_req[0].num_rows = 5'd3;
            sif.vec_req[0].num_cols = 5'd7;
            sif.vec_req[0].row_id = 5'd0;
            sif.vec_req[0].col_id = 5'd0;
            sif.vec_req[0].row_or_col = 1'b1;
            for (int i = 0; i < NUM_COLS; i++)
                sif.vec_req[0].wdata[i] = 16'(i + 1);
            
            #1; // Let combinational logic settle
            
            // Check fe_req mirrors vec_req (except xbar which comes from swizzle)
            if (sif.fe_req[0].valid !== 1'b1) begin
                $display("  ERROR: fe_req.valid mismatch");
                errors++;
            end
            if (sif.fe_req[0].write !== 1'b1) begin
                $display("  ERROR: fe_req.write mismatch");
                errors++;
            end
            if (sif.fe_req[0].spad_addr !== 20'h00100) begin
                $display("  ERROR: fe_req.spad_addr mismatch - got 0x%05h", sif.fe_req[0].spad_addr);
                errors++;
            end
            if (sif.fe_req[0].num_rows !== 5'd3) begin
                $display("  ERROR: fe_req.num_rows mismatch");
                errors++;
            end
            if (sif.fe_req[0].num_cols !== 5'd7) begin
                $display("  ERROR: fe_req.num_cols mismatch");
                errors++;
            end
            
            // Check wdata pass-through
            for (int i = 0; i < NUM_COLS; i++) begin
                if (sif.fe_req[0].wdata[i] !== 16'(i + 1)) begin
                    $display("  ERROR: fe_req.wdata[%0d] mismatch - got 0x%04h, expected 0x%04h",
                             i, sif.fe_req[0].wdata[i], 16'(i + 1));
                    errors++;
                end
            end
            
            @(posedge sif.clk);
            sif.vec_req[0] = '0;
            
            total_tests++;
            if (errors == 0)
                report_success("Request Pass-through", "All fields passed correctly");
            else
                report_error("Request Pass-through", $sformatf("%0d errors", errors));
        endtask
        
        //======================================================================
        // Test: Swizzle XBar Descriptor Generation
        //======================================================================
        
        task automatic test_swizzle_xbar();
            automatic int errors = 0;
            
            $display("\n--- Test: Swizzle XBar Generation ---");
            
            sif.fe_stall[0] = 1'b0;
            
            // Test row-major access (row_or_col = 1)
            sif.vec_req[0].valid = 1'b1;
            sif.vec_req[0].write = 1'b0;
            sif.vec_req[0].spad_addr = 20'h00000;
            sif.vec_req[0].num_rows = 5'd0;   // 1 row
            sif.vec_req[0].num_cols = 5'd7;   // 8 columns
            sif.vec_req[0].row_id = 5'd0;
            sif.vec_req[0].col_id = 5'd0;
            sif.vec_req[0].row_or_col = 1'b1;
            sif.vec_req[0].wdata = '0;
            
            #1;
            
            // Check that xbar descriptor was generated (not all zeros)
            if (sif.fe_req[0].xbar.valid_mask == '0) begin
                $display("  ERROR: xbar.valid_mask is all zeros");
                errors++;
            end
            
            // For row_or_col=1, num_cols=7, valid_mask should have bits 0-7 set
            // (bank_id <= num_cols means banks 0-7 are valid, i.e. 8 columns)
            for (int i = 0; i < NUM_COLS; i++) begin
                automatic logic expected_valid = (i <= 7);
                if (sif.fe_req[0].xbar.valid_mask[i] !== expected_valid) begin
                    $display("  ERROR: xbar.valid_mask[%0d] = %b, expected %b", 
                             i, sif.fe_req[0].xbar.valid_mask[i], expected_valid);
                    errors++;
                end
            end
            
            $display("  xbar.valid_mask = 0x%08h", sif.fe_req[0].xbar.valid_mask);
            $display("  xbar.shift_mask[0] = %0d", sif.fe_req[0].xbar.shift_mask[0]);
            $display("  xbar.slot_mask[0] = %0d", sif.fe_req[0].xbar.slot_mask[0]);
            
            @(posedge sif.clk);
            sif.vec_req[0] = '0;
            
            total_tests++;
            if (errors == 0)
                report_success("Swizzle XBar", "XBar descriptor generated correctly");
            else
                report_error("Swizzle XBar", $sformatf("%0d errors", errors));
        endtask
        
        //======================================================================
        // Test: Response Pass-through
        //======================================================================
        
        task automatic test_response_passthrough();
            automatic int errors = 0;
            
            $display("\n--- Test: Response Pass-through ---");
            
            // Drive fe_res
            sif.fe_res[0].valid = 1'b1;
            sif.fe_res[0].write = 1'b0;
            for (int i = 0; i < NUM_COLS; i++)
                sif.fe_res[0].rdata[i] = 16'((i * 32) + 1);
            
            #1;
            
            // Check vec_res mirrors fe_res
            if (sif.vec_res[0].valid !== 1'b1) begin
                $display("  ERROR: vec_res.valid mismatch");
                errors++;
            end
            if (sif.vec_res[0].write !== 1'b0) begin
                $display("  ERROR: vec_res.write mismatch");
                errors++;
            end
            
            for (int i = 0; i < NUM_COLS; i++) begin
                if (sif.vec_res[0].rdata[i] !== 16'((i * 32) + 1)) begin
                    $display("  ERROR: vec_res.rdata[%0d] mismatch", i);
                    errors++;
                end
            end
            
            @(posedge sif.clk);
            sif.fe_res[0] = '0;
            
            total_tests++;
            if (errors == 0)
                report_success("Response Pass-through", "Response passed correctly");
            else
                report_error("Response Pass-through", $sformatf("%0d errors", errors));
        endtask
        
        //======================================================================
        // Test: Stall Propagation
        //======================================================================
        
        task automatic test_stall_propagation();
            automatic int errors = 0;
            
            $display("\n--- Test: Stall Propagation ---");
            
            // Assert fe_stall
            sif.fe_stall[0] = 1'b1;
            #1;
            
            // Check fe_vec_stall is asserted
            if (sif.fe_vec_stall[0] !== 1'b1) begin
                $display("  ERROR: fe_vec_stall not asserted when fe_stall=1");
                errors++;
            end
            
            // Deassert fe_stall
            sif.fe_stall[0] = 1'b0;
            #1;
            
            // Check fe_vec_stall is deasserted
            if (sif.fe_vec_stall[0] !== 1'b0) begin
                $display("  ERROR: fe_vec_stall not deasserted when fe_stall=0");
                errors++;
            end
            
            total_tests++;
            if (errors == 0)
                report_success("Stall Propagation", "Stall propagated correctly");
            else
                report_error("Stall Propagation", $sformatf("%0d errors", errors));
        endtask
        
        //======================================================================
        // Test: Different Row/Col Modes
        //======================================================================
        
        task automatic test_row_col_modes();
            automatic int errors = 0;
            
            $display("\n--- Test: Row vs Column Major Modes ---");
            
            sif.fe_stall[0] = 1'b0;
            
            // Test column-major access (row_or_col = 0)
            sif.vec_req[0].valid = 1'b1;
            sif.vec_req[0].write = 1'b0;
            sif.vec_req[0].spad_addr = 20'h00000;
            sif.vec_req[0].num_rows = 5'd3;   // 4 rows
            sif.vec_req[0].num_cols = 5'd0;   // 1 column
            sif.vec_req[0].row_id = 5'd0;
            sif.vec_req[0].col_id = 5'd2;     // Column 2
            sif.vec_req[0].row_or_col = 1'b0; // Column-major
            sif.vec_req[0].wdata = '0;
            
            #1;
            
            // For row_or_col=0, num_rows=3, valid_mask should have bits 0-3 set
            // (bank_id <= num_rows means banks 0-3 are valid, i.e. 4 rows)
            for (int i = 0; i < NUM_COLS; i++) begin
                automatic logic expected_valid = (i <= 3);
                if (sif.fe_req[0].xbar.valid_mask[i] !== expected_valid) begin
                    $display("  ERROR: col-major xbar.valid_mask[%0d] = %b, expected %b", 
                             i, sif.fe_req[0].xbar.valid_mask[i], expected_valid);
                    errors++;
                end
            end
            
            $display("  Column-major: xbar.valid_mask = 0x%08h", sif.fe_req[0].xbar.valid_mask);
            
            @(posedge sif.clk);
            sif.vec_req[0] = '0;
            
            total_tests++;
            if (errors == 0)
                report_success("Row/Col Modes", "Both modes generate correct masks");
            else
                report_error("Row/Col Modes", $sformatf("%0d errors", errors));
        endtask
        
        //======================================================================
        // Test: Multiple Rows with Swizzle
        //======================================================================
        
        task automatic test_multiple_rows();
            automatic int errors = 0;
            
            $display("\n--- Test: Multiple Row IDs ---");
            
            sif.fe_stall[0] = 1'b0;
            
            // Test with different row_id values
            for (int row = 0; row < 4; row++) begin
                sif.vec_req[0].valid = 1'b1;
                sif.vec_req[0].write = 1'b0;
                sif.vec_req[0].spad_addr = 20'h00000;
                sif.vec_req[0].num_rows = 5'd3;
                sif.vec_req[0].num_cols = 5'd7;
                sif.vec_req[0].row_id = 5'(row);
                sif.vec_req[0].col_id = 5'd0;
                sif.vec_req[0].row_or_col = 1'b1;
                
                #1;
                
                // Verify row_id is passed through
                if (sif.fe_req[0].row_id !== 5'(row)) begin
                    $display("  ERROR: row_id mismatch for row %0d", row);
                    errors++;
                end
                
                // slot_mask[0] should equal spad_addr + row_id = row
                if (sif.fe_req[0].xbar.slot_mask[0] !== row) begin
                    $display("  ERROR: slot_mask[0] = %0d, expected %0d for row %0d", 
                             sif.fe_req[0].xbar.slot_mask[0], row, row);
                    errors++;
                end
                
                @(posedge sif.clk);
            end
            
            sif.vec_req[0] = '0;
            
            total_tests++;
            if (errors == 0)
                report_success("Multiple Rows", "All row IDs handled correctly");
            else
                report_error("Multiple Rows", $sformatf("%0d errors", errors));
        endtask
        
        //======================================================================
        // Summary
        //======================================================================
        
        task automatic print_summary();
            $display("\n");
            $display("============ TEST SUMMARY ============");
            $display("  Total: %0d | Passed: %0d | Failed: %0d", total_tests, passed_tests, failed_tests);
            if (failed_tests == 0) $display("  ALL TESTS PASSED");
            else $display("  SOME TESTS FAILED");
            $display("======================================\n");
        endtask
        
        //======================================================================
        // Main
        //======================================================================
        initial begin
            // Initialize
            sif.vec_req[0] = '0;
            sif.vec_req[1] = '0;
            sif.fe_stall[0] = '0;
            sif.fe_stall[1] = '0;
            sif.fe_res[0] = '0;
            sif.fe_res[1] = '0;
            
            @(posedge sif.n_rst);
            #(CLK_PERIOD);
            
            $display("\n===== FRONTEND UNIT TEST SUITE =====\n");
            
            test_request_passthrough();
            test_swizzle_xbar();
            test_response_passthrough();
            test_stall_propagation();
            test_row_col_modes();
            test_multiple_rows();
            
            print_summary();
            if (failed_tests > 0) $fatal(1, "Test suite failed with %0d failures", failed_tests);
            $finish;
        end
        
    endprogram
    
    test PROG (.sif(sif));
    
endmodule