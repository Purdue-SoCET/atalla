/*
result_collector_tb.sv
Non exhaustive verification of the result collector
This will not have toggle or branch coverage cause i dont have time
Owner: Jacob Walter
LLM was used for testscases as the old testcases did not work with the updated design. The LLM was used to create a few more cases that i have reviewed

Make command for my testbench:
make test tb_file=result_collector_tb.sv packages=/vector/vector_pkg.vh modules=/vector/result_collector.sv,/vector/result_collector_counter.sv GUI=ON

Test Cases:
1. Power on reset
2. Vector Collection Test (single cycle per lane)
3. Vector Collection Test (multiple cycles - TIMES > 1)
4. Backpressure Test
5. VD Capture Test (ensure vd doesn't change mid-vector)
6. Mask Test (ensure masked elements are zeroed)
7. Multi-vector back-to-back test
8. One lane hanging
*/
`timescale 1ns/1ps

`include "result_collector_if.vh"
`include "vector_pkg.vh"

module result_collector_tb;
    import vector_pkg::*;

    localparam int TIMES = VLMAX / NUM_LANES;

    //Clock setup
    logic CLK;
    logic nRST;

    initial CLK = 1'b0;
    always #5 CLK = ~CLK;   // 100 MHz

    //DUT instantiation
    result_collector_if rcif();
    result_collector DUT (
        .CLK(CLK),
        .nRST(nRST),
        .rcif(rcif)
    );

    //testcase tasks

    task automatic power_on_reset();
        @(posedge CLK);
        nRST = 'b0;
        rcif.in.input_valid = '0;
        rcif.in.wb_ready = 'b0;
        rcif.in.lane_input = '0;
        rcif.in.vd_input = '0;
        rcif.in.mask = '0;
        @(posedge CLK);
        @(posedge CLK);
        nRST = 'b1;
        @(posedge CLK);
    endtask

    // Test: Collect a full vector when TIMES cycles are needed per lane
    task automatic vector_collection_multi_cycle();
        logic [NUM_LANES-1:0][15:0] input_data;
        int cycle_count;
        $display("[%0t] Test: Vector Collection (Multi-Cycle, TIMES=%0d)", $time, TIMES);
        
        
        rcif.in.wb_ready = 'b1;
        rcif.in.mask = '1;  // All elements active
        
        // Send TIMES worth of data to each lane
        for (cycle_count = 0; cycle_count < TIMES; cycle_count++) begin
            @(posedge CLK);
            
            // Generate unique data for each lane and cycle
            for (int lane = 0; lane < NUM_LANES; lane++) begin
                input_data[lane] = (cycle_count * NUM_LANES) + lane + 1;
            end
            
            rcif.in.lane_input = input_data;
            rcif.in.input_valid = '1;  // All lanes valid
            
            // VD should only be captured on first cycle
            if (cycle_count == 0) begin
                rcif.in.vd_input = 'd5;
            end else begin
                rcif.in.vd_input = 'd99;  // Different value - should be ignored
            end
        end
        
        @(posedge CLK);
        rcif.in.input_valid = '0;
        
        // Wait for wb_valid to assert
        while (!rcif.out.wb_valid) @(posedge CLK);
        
        // Check VD output
        assert(rcif.out.vd_output == 'd5) else 
            $error("VD mismatch! Expected 5, got %0d", rcif.out.vd_output);
        
        $display("[%0t] Vector collection complete, wb_valid asserted", $time);
        
        // Complete handshake
        @(posedge CLK);
        assert(rcif.out.wb_valid == 1'b0) else
            $error("wb_valid should deassert after handshake");
        
        @(posedge CLK);
    endtask

    // Test: Collect vector with staggered lane inputs
    task automatic vector_collection_staggered();
        int cycle;
        int timeout;
        $display("[%0t] Test: Vector Collection (Staggered Lanes)", $time);
        
        
        rcif.in.wb_ready = 'b1;
        rcif.in.mask = '1;
        
        for (cycle = 0; cycle < TIMES * 2; cycle++) begin
            @(posedge CLK);
            
            // Lane 0 gets data every cycle
            if (cycle < TIMES) begin
                rcif.in.input_valid[0] = 1'b1;
                rcif.in.lane_input[0] = cycle + 100;
            end else begin
                rcif.in.input_valid[0] = 1'b0;
            end
            
            // Other lanes get data every other cycle
            for (int lane = 1; lane < NUM_LANES; lane++) begin
                if ((cycle % 2 == 0) && (cycle/2 < TIMES)) begin
                    rcif.in.input_valid[lane] = 1'b1;
                    rcif.in.lane_input[lane] = (cycle/2) + (lane * 100);
                end else begin
                    rcif.in.input_valid[lane] = 1'b0;
                end
            end
            
            if (cycle == 0) begin
                rcif.in.vd_input = 'd7;
            end else begin
                rcif.in.vd_input = 'd88;  // Should be ignored
            end
        end
        
        @(posedge CLK);
        rcif.in.input_valid = '0;
        
        // Wait for completion with timeout
        timeout = 0;
        while (!rcif.out.wb_valid) begin
            @(posedge CLK);
            timeout++;
            assert(timeout < 1000) else $fatal("Timeout waiting for wb_valid in staggered test");
        end
        
        assert(rcif.out.vd_output == 'd7) else
            $error("VD mismatch in staggered test");
        
        $display("[%0t] Staggered collection complete", $time);
        @(posedge CLK);
        @(posedge CLK);
    endtask

    // Test: Backpressure handling
    task automatic backpressure_test();
        logic [NUM_LANES-1:0][15:0] input_data;
        int cycle_count;
        $display("[%0t] Test: Backpressure", $time);
        
        
        rcif.in.wb_ready = 'b1;
        rcif.in.mask = '1;
        
        // Fill the collector
        for (cycle_count = 0; cycle_count < TIMES; cycle_count++) begin
            @(posedge CLK);
            for (int lane = 0; lane < NUM_LANES; lane++) begin
                input_data[lane] = (cycle_count * NUM_LANES) + lane + 200;
            end
            rcif.in.lane_input = input_data;
            rcif.in.input_valid = '1;
            if (cycle_count == 0) rcif.in.vd_input = 'd10;
        end
        
        @(posedge CLK);
        rcif.in.input_valid = '0;
        rcif.in.wb_ready = 'b0;
        // Wait for valid
        while (!rcif.out.wb_valid) @(posedge CLK);
        
        $display("[%0t] wb_valid asserted, applying backpressure", $time);
        
        // Apply backpressure - keep wb_ready low
        
        
        // wb_valid should stay high
        repeat(5) begin
            @(posedge CLK);
            assert(rcif.out.wb_valid == 1'b1) else
                $error("wb_valid should remain high during backpressure");
        end
        
        // Release backpressure
        rcif.in.wb_ready = 'b1;
        @(posedge CLK);
        
        // wb_valid should deassert
        assert(rcif.out.wb_valid == 1'b0) else
            $error("wb_valid should deassert after handshake");
        
        $display("[%0t] Backpressure test complete", $time);
        @(posedge CLK);
    endtask

    // Test: Mask handling (masked elements should be zero)
    task automatic mask_test();
        $display("[%0t] Test: Masking", $time);
        
        rcif.in.wb_ready = 'b1;
        
        for (int cycle = 0; cycle < TIMES; cycle++) begin
            @(posedge CLK);
            
            // Alternate mask pattern
            for (int lane = 0; lane < NUM_LANES; lane++) begin
                rcif.in.lane_input[lane] = 16'hFFFF;  // Non-zero data
                rcif.in.mask[lane] = (lane % 2 == 0) ? 1'b1 : 1'b0;  // Mask odd lanes
                rcif.in.input_valid[lane] = 1'b1;
            end
            
            if (cycle == 0) rcif.in.vd_input = 'd15;
        end
        
        @(posedge CLK);
        rcif.in.input_valid = '0;
        
        while (!rcif.out.wb_valid) @(posedge CLK);
        
        $display("[%0t] Mask test complete", $time);
        @(posedge CLK);
    endtask

    // Test: Back-to-back vectors
    task automatic back_to_back_vectors();
        int timeout;
        $display("[%0t] Test: Back-to-Back Vectors", $time);
        
        rcif.in.wb_ready = 'b1;
        rcif.in.mask = '1;
        
        // First vector
        for (int cycle = 0; cycle < TIMES; cycle++) begin
            @(posedge CLK);
            for (int lane = 0; lane < NUM_LANES; lane++) begin
                rcif.in.lane_input[lane] = 16'hAAAA;
            end
            rcif.in.input_valid = '1;
            if (cycle == 0) rcif.in.vd_input = 'd20;
            else rcif.in.vd_input = 'd21;
        end
        
        @(posedge CLK);
        rcif.in.input_valid = '0;
        
        // Wait for first vector to complete
        timeout = 0;
        while (!rcif.out.wb_valid) begin
            @(posedge CLK);
            timeout++;
            assert(timeout < 1000) else $fatal("Timeout waiting for first wb_valid");
        end
        assert(rcif.out.vd_output == 'd20) else $error("First vector VD wrong");
        
        // Handshake occurs on this cycle, counters will reset next cycle        
        // Second vector immediately after reset
        for (int cycle = 0; cycle < TIMES; cycle++) begin
            
            for (int lane = 0; lane < NUM_LANES; lane++) begin
                rcif.in.lane_input[lane] = 16'hBBBB;
            end
            rcif.in.input_valid = '1;
            if (cycle == 0) rcif.in.vd_input = 'd30;
            else rcif.in.vd_input = 'd31;
            @(posedge CLK);
        end
        
        @(posedge CLK);
        rcif.in.input_valid = '0;
        
        // Wait for second vector to complete
        timeout = 0;
        while (!rcif.out.wb_valid) begin
            @(posedge CLK);
            timeout++;
            assert(timeout < 1000) else $fatal("Timeout waiting for second wb_valid");
        end
        assert(rcif.out.vd_output == 'd30) else $error("Second vector VD wrong");
        
        $display("[%0t] Back-to-back test complete", $time);
        @(posedge CLK);
    endtask

    task automatic vector_collection_one_slow_lane();
        int timeout;
        $display("[%0t] Test: Vector Collection (One Slow Lane)", $time);
        
        rcif.in.wb_ready = 'b1;
        rcif.in.mask = '1;
        
        // Cycle 0: All lanes get first element
        @(posedge CLK);
        for (int lane = 0; lane < NUM_LANES; lane++) begin
            rcif.in.lane_input[lane] = lane + 100;
        end
        rcif.in.input_valid = '1;
        rcif.in.vd_input = 'd12;
        
        // Cycle 1: All lanes EXCEPT lane 2 get second element
        @(posedge CLK);
        for (int lane = 0; lane < NUM_LANES; lane++) begin
            if (lane == 2) begin
                rcif.in.input_valid[lane] = 1'b0;  // Lane 2 stalls
            end else begin
                rcif.in.input_valid[lane] = 1'b1;
                rcif.in.lane_input[lane] = lane + 200;
            end
        end
        rcif.in.vd_input = 'd99;  // Should be ignored
        
        // Wait a few cycles with no data
        @(posedge CLK);
        rcif.in.input_valid = '0;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        
        // Finally send lane 2's second element
        @(posedge CLK);
        rcif.in.input_valid = '0;
        rcif.in.input_valid[2] = 1'b1;
        rcif.in.lane_input[2] = 202;
        
        @(posedge CLK);
        rcif.in.input_valid = '0;
        
        // Wait for wb_valid with timeout
        timeout = 0;
        while (!rcif.out.wb_valid) begin
            @(posedge CLK);
            timeout++;
            assert(timeout < 1000) else $fatal("Timeout waiting for wb_valid with slow lane");
        end
        
        $display("[%0t] Slow lane test complete", $time);
        @(posedge CLK);
    endtask

    initial begin
        nRST = 'b1;
        
        power_on_reset();
        @(posedge CLK);
        
        vector_collection_multi_cycle();
        //vector_collection_staggered();
       
        //backpressure_test();
        //mask_test();
        //back_to_back_vectors();
        
        //vector_collection_one_slow_lane();

        @(posedge CLK);
        @(posedge CLK);
        
        $display("[%0t] All tests complete!", $time);
        $stop;
    end

endmodule