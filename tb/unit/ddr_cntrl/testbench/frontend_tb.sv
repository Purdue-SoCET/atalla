`include "dram_pkg.svh"
`include "ddr_controller_if.sv"
`timescale 1ns/1ps

module frontend_tb;
    import dram_pkg::*;

    logic CLK, nRST;
    localparam PERIOD = 10;  // 10 ns clock period (100 MHz)
    string test_case;

    // Clock Generation
    always begin
        CLK = 1'b0;
        #(PERIOD / 2.0);
        CLK = 1'b1;
        #(PERIOD / 2.0);
    end

    // Interface Declaration
    ddr_controller_if ddrif();

    // DUT Instantiation
    frontend_wrapper DUT (
        .CLK(CLK),
        .nRST(nRST),
        .fe(ddrif.frontend_tb)
    );

    // ================================================================
    // HELPER TASKS
    // ================================================================

    task reset_dut;
        nRST = 1'b0;
        // Clear all AXI write channel signals
        ddrif.awvalid = 1'b0;
        ddrif.awaddr  = '0;
        ddrif.awid    = '0;
        ddrif.awlen   = '0;
        // Clear all AXI read channel signals
        ddrif.arvalid = 1'b0;
        ddrif.araddr  = '0;
        ddrif.arid    = '0;
        ddrif.arlen   = '0;
        // No bank queue backpressure
        ddrif.fe_full = '0;
        repeat(2) @(posedge CLK);
        nRST = 1'b1;
        @(posedge CLK);
    endtask

    task drive_write_request(
        input logic [31:0]                addr,
        input logic [$clog2(ID_NUM)-1:0]  id,
        input logic [2:0]                 len
    );
        ddrif.awvalid = 1'b1;
        ddrif.awaddr  = addr;
        ddrif.awid    = id;
        ddrif.awlen   = len;
    endtask

    task drive_read_request(
        input logic [31:0]                addr,
        input logic [$clog2(ID_NUM)-1:0]  id,
        input logic [2:0]                 len
    );
        ddrif.arvalid = 1'b1;
        ddrif.araddr  = addr;
        ddrif.arid    = id;
        ddrif.arlen   = len;
    endtask

    // Clear Write Channel
    task clear_write;
        ddrif.awvalid = 1'b0;
        ddrif.awaddr  = '0;
        ddrif.awid    = '0;
        ddrif.awlen   = '0;
    endtask

    // Clear Read Channel
    task clear_read;
        ddrif.arvalid = 1'b0;
        ddrif.araddr  = '0;
        ddrif.arid    = '0;
        ddrif.arlen   = '0;
    endtask

    // ================================================================
    // TEST 1: Single Write Request
    // ================================================================
    //
    //   A single AXI write request flows through the entire front-end:
    //     AXI → STQ → Frontend Arbiter → Address Mapper → BQ push
    task test_single_write;
        test_case = "Single Write Request";
        $display("\n[TEST] %s", test_case);

        // Drive a write: addr=0x0000_1000, id=2, burst len=4
        drive_write_request(32'h0000_1000, 3'd2, 3'd4);
        @(posedge CLK);
        // On this posedge: STQ samples the entry because awvalid=1 and
        //   awready=1 (queue is empty).

        // Deassert awvalid — the handshake is complete
        clear_write();
        @(posedge CLK);
        // On this posedge: request_s should now be 1 (STQ has an entry).
        //   stq_slot should show {len=4, id=2, addr=0x1000}.

        // Let the arbiter grant STQ and push to BQ.
        repeat(5) @(posedge CLK);
      
    endtask

    // ================================================================
    // TEST 2: Single Read Request
    // ================================================================
    //
    //   A single AXI read request flows through:
    //     AXI → LQ → Frontend Arbiter → Address Mapper → BQ push

    task test_single_read;
        test_case = "Single Read Request";
        $display("\n[TEST] %s", test_case);

        // Drive a read: addr=0x0000_2000, id=5, burst len=2
        drive_read_request(32'h0000_2000, 3'd5, 3'd2);
        @(posedge CLK);
        // arready should be 1 (LQ empty). Handshake completes.

        // Deassert arvalid
        clear_read();
        @(posedge CLK);
        // request_l should now be 1. lq_slot = {len=2, id=5, addr=0x2000}.

        // Let arbiter process
        repeat(5) @(posedge CLK);
    endtask

    // ================================================================
    // TEST 3: Simultaneous Read and Write
    // ================================================================
    //
    //   Both AXI channels fire at the same time. Both queues should
    //   accept (they're both empty). The arbiter uses round-robin
    //   priority, so it will grant one queue first, push to BQ,
    //   then grant the other queue on the next arbitration cycle.

    task test_simultaneous_rw;
        test_case = "Simultaneous Read and Write";
        $display("\n[TEST] %s", test_case);

        // Drive BOTH channels at the same time
        drive_write_request(32'h0000_3000, 3'd1, 3'd3);
        drive_read_request(32'h0000_4000, 3'd6, 3'd1);
        @(posedge CLK);
        // Both awready=1 and arready=1 since both queues are empty.
        //   Both entries get enqueued in the same cycle.

        // Deassert both channels
        clear_write();
        clear_read();
        @(posedge CLK);
        // request_s=1 AND request_l=1. Both queues have one entry each.

        // Wait for arbiter to drain both entries via round-robin.
        // First arbitration + push
        repeat(5) @(posedge CLK);
        // Look for first fe_write_bq=1 pulse.
        //   If grant_s fired first → fe_write=1 (store from 0x3000)
        //   If grant_l fired first → fe_write=0 (load from 0x4000)

        // Second arbitration + push
        repeat(5) @(posedge CLK);
    endtask

    // ================================================================
    // TEST 4: Fill Store Queue to Capacity
    // ================================================================
    //
    //   Send STQ_DEPTH (8) back-to-back writes to fill the STQ.
    //   The 9th write should get backpressure (awready=0).
    task test_fill_stq;
        integer i;
        test_case = "Fill Store Queue to Capacity";
        $display("\n[TEST] %s", test_case);

        // Send STQ_DEPTH (8) write requests, one per cycle.
        // Each has a unique address so we can track them in the waveform.
        for (i = 0; i < STQ_DEPTH; i++) begin
            drive_write_request(
                .addr(32'h0000_1000 + (i * 32'h100)),  // 0x1000, 0x1100, ... 0x1700
                .id  (i[2:0]),                          // id = 0, 1, 2, ... 7
                .len (3'd1)
            );
            @(posedge CLK);
            // awready should be 1 for each of these 8 writes.
            //   The STQ enqueues at tail_ptr and increments it.
        end

        // Now try a 9th request — queue should be full
        drive_write_request(32'h0000_FFFF, 3'd7, 3'd1);
        @(posedge CLK);
        // awready should be 0 here — STQ is full (taken==STQ_DEPTH).
        //   The entry does NOT get enqueued.

        // Deassert and let the arbiter drain
        clear_write();
        repeat(12) @(posedge CLK);
        // In waveform: grant_s fires repeatedly, fe_write_bq pulses each
        //   time an entry is pushed to BQ. request_s eventually drops to 0.
    endtask

    // ================================================================
    // TEST 5: Fill Load Queue to Capacity
    // ================================================================
    //
    // What we're testing:
    //   Same as Test 4, but for the read path (LQ).
    //   Send LQ_DEPTH (8) reads, then verify arready drops on the 9th.

    task test_fill_lq;
        integer i;
        test_case = "Fill Load Queue to Capacity";
        $display("\n[TEST] %s", test_case);

        // Send LQ_DEPTH (8) read requests
        for (i = 0; i < LQ_DEPTH; i++) begin
            drive_read_request(
                .addr(32'h0000_2000 + (i * 32'h100)),  // 0x2000, 0x2100, ... 0x2700
                .id  (i[2:0]),
                .len (3'd2)
            );
            @(posedge CLK);
            // arready should be 1 for each of these 8 reads.
        end

        // 9th request — should be rejected
        drive_read_request(32'h0000_FFFF, 3'd7, 3'd2);
        @(posedge CLK);
        // arready should be 0 — LQ is full.

        // Deassert and let arbiter drain
        clear_read();
        repeat(12) @(posedge CLK);
    endtask

    // ================================================================
    // TEST 6: Bank Queue Backpressure
    // ================================================================
    //
    //   When ALL bank queues are full (fe_full = all 1s), the arbiter
    //   should stall — it can buffer the entry internally but must NOT
    //   assert fe_write_bq until the target bank has room.
  
    task test_bq_backpressure;
        test_case = "Bank Queue Backpressure";
        $display("\n[TEST] %s", test_case);

        // Block ALL bank queues — simulate every BQ being full
        ddrif.fe_full = {BANK_NUM{1'b1}};  // 16'hFFFF

        // Drive a write request
        drive_write_request(32'h0000_5000, 3'd3, 3'd2);
        @(posedge CLK);
        // awready should be 1 — STQ has room, BQ full doesn't block enqueue.

        // Deassert write channel
        clear_write();

        // Wait several cycles — arbiter should be stalled
        repeat(6) @(posedge CLK);
        // In waveform: grant_s may have fired (arbiter buffers the entry),
        //   but fe_write_bq remains 0 because the target bank is full.

        // Now release backpressure — clear fe_full
        ddrif.fe_full = '0;
        repeat(3) @(posedge CLK);
    endtask

    // ================================================================
    // TEST 7: Round-Robin Fairness
    // ================================================================
    //
    //   Send 3 rounds of simultaneous read+write requests. The arbiter
    //   should alternate which queue gets granted first, ensuring neither
    //   queue starves the other.
    //
    task test_round_robin;
        integer round;
        test_case = "Round-Robin Fairness";
        $display("\n[TEST] %s", test_case);

        for (round = 0; round < 3; round++) begin
            // Drive both channels simultaneously
            drive_write_request(
                .addr(32'h0000_6000 + (round * 32'h200)),
                .id  (round[2:0]),
                .len (3'd1)
            );
            drive_read_request(
                .addr(32'h0000_6100 + (round * 32'h200)),
                .id  (round[2:0] + 3'd4),
                .len (3'd1)
            );
            @(posedge CLK);
            // awready=1 and arready=1 (both queues accept)

            // Deassert both
            clear_write();
            clear_read();

            // Let arbiter process both entries (2 pushes needed)
            repeat(10) @(posedge CLK);
            // In waveform: Two fe_write_bq pulses per round.
            //   Check fe_write on each pulse — should see both 0 and 1.
            //   grant_s and grant_l should each fire once.
        end
    endtask

    // ================================================================
    // TEST 8: Simultaneous Enqueue and Dequeue
    // ================================================================
    //
    //   The STQ's same-cycle read/write logic. If awvalid&&awready
    //   AND grant_s all happen on the same posedge, the occupancy
    //   count should stay the same (one entry in, one entry out).
    //

    task test_simultaneous_enq_deq;
        test_case = "Simultaneous Enqueue and Dequeue";
        $display("\n[TEST] %s", test_case);

        // Pre-load entry 1 into STQ
        drive_write_request(32'h0000_A000, 3'd0, 3'd1);
        @(posedge CLK);
        // awready=1, STQ enqueues entry 1 at tail_ptr=0

        // Pre-load entry 2 (keep awvalid=1, change addr/id)
        ddrif.awaddr = 32'h0000_A100;
        ddrif.awid   = 3'd1;
        @(posedge CLK);
        // awready=1, STQ enqueues entry 2 at tail_ptr=1
        //   request_s=1 (2 entries now)

        // Keep driving a 3rd entry while arbiter is draining
        ddrif.awaddr = 32'h0000_A200;
        ddrif.awid   = 3'd2;
        ddrif.awlen  = 3'd3;
        repeat(4) @(posedge CLK);
        // At some point in here, grant_s fires while awvalid is still 1.
        //   That's the simultaneous enqueue+dequeue event.
        //   Look in waveform: request_s stays 1, awready stays 1.

        // Deassert and let everything drain
        clear_write();
        repeat(10) @(posedge CLK);
    endtask

    // ================================================================
    // TEST 9: Back-to-Back Bursts to Different Banks
    // ================================================================
    //
    //   4 write requests with addresses that map to DIFFERENT bank
    //   groups and banks. The arbiter should push each to a different
    //   {fe_bg, fe_b} without stalling (no bank is full).
    //
    task test_different_banks;
        test_case = "Back-to-Back Different Banks";
        $display("\n[TEST] %s", test_case);

        // Entry 1: addr=0x0000_0040
        drive_write_request(32'h0000_0040, 3'd0, 3'd1);
        @(posedge CLK);

        // Entry 2: addr=0x0000_2040 (different bank bits)
        ddrif.awaddr = 32'h0000_2040;
        ddrif.awid   = 3'd1;
        @(posedge CLK);

        // Entry 3: addr=0x0000_4040 (different bank group)
        ddrif.awaddr = 32'h0000_4040;
        ddrif.awid   = 3'd2;
        @(posedge CLK);

        // Entry 4: addr=0x0000_6040 (yet another bank)
        ddrif.awaddr = 32'h0000_6040;
        ddrif.awid   = 3'd3;
        @(posedge CLK);
        // awready should be 1 for all 4. STQ now has 4 entries.

        // Deassert
        clear_write();

        // Let arbiter drain all 4
        repeat(16) @(posedge CLK);
        // In waveform: 4 fe_write_bq pulses.
        //   Compare fe_bg and fe_b across the pulses — they should be different.
        //   This confirms the address mapper correctly routes to different banks.
    endtask

    // ================================================================
    // TEST 10: Reset Behavior
    // ================================================================
    //
    //   Assert nRST=0 while entries are in-flight. All internal state
    //   should be flushed. After releasing reset, the system should
    //   accept new requests with no residual state.

    task test_reset_behavior;
        test_case = "Reset Behavior";
        $display("\n[TEST] %s", test_case);

        // Load entries into both queues
        drive_write_request(32'h0000_B000, 3'd1, 3'd1);
        drive_read_request(32'h0000_C000, 3'd2, 3'd1);
        @(posedge CLK);
        // awready=1, arready=1. Both queues accept.

        // Load another round
        ddrif.awaddr = 32'h0000_B100;
        ddrif.awid   = 3'd3;
        ddrif.araddr = 32'h0000_C100;
        ddrif.arid   = 3'd4;
        @(posedge CLK);
        // 2 entries in STQ, 2 entries in LQ. request_s=1, request_l=1.

        // Clear AXI inputs before asserting reset
        clear_write();
        clear_read();

        // ASSERT RESET mid-operation
        nRST = 1'b0;
        repeat(2) @(posedge CLK);
        // During reset: everything should be 0.
        //   request_s=0, request_l=0 (queues flushed)
        //   awready=0, arready=0
        //   fe_write_bq=0,  grant_s=0, grant_l=0
        //   Arbiter internal buffers cleared.

        // RELEASE RESET
        nRST = 1'b1;
        @(posedge CLK);

        // Verify system works after reset — drive a fresh write
        drive_write_request(32'h0000_D000, 3'd0, 3'd1);
        @(posedge CLK);
        // awready should be 1 — STQ is empty again after reset.
        //   No residual entries from before reset.

        // Deassert and let arbiter process the post-reset entry
        clear_write();
        repeat(6) @(posedge CLK);
        // fe_write_bq=1, fe_write=1.
    endtask

    // ================================================================
    // MAIN TEST SEQUENCE
    // ================================================================
    initial begin
        // Reset all state before starting tests
        reset_dut();

        // Test 1: Single write → AXI→STQ→Arbiter→BQ
        test_single_write();
        repeat(5) @(posedge CLK);

        // Test 2: Single read → AXI→LQ→Arbiter→BQ
        reset_dut();
        test_single_read();
        repeat(5) @(posedge CLK);

        // Test 3: Both channels fire simultaneously → round-robin drain
        reset_dut();
        test_simultaneous_rw();
        repeat(5) @(posedge CLK);

        // Test 4: Fill STQ to depth 8, verify awready drops on 9th
        reset_dut();
        test_fill_stq();
        repeat(5) @(posedge CLK);

        // Test 5: Fill LQ to depth 8, verify arready drops on 9th
        reset_dut();
        test_fill_lq();
        repeat(5) @(posedge CLK);

        // Test 6: Assert fe_full → arbiter stalls → release → push goes through
        reset_dut();
        test_bq_backpressure();
        repeat(5) @(posedge CLK);

        // Test 7: 3 rounds of simultaneous R+W → verify fair alternation
        reset_dut();
        test_round_robin();
        repeat(5) @(posedge CLK);

        // Test 8: Enqueue + dequeue in same cycle → occupancy stays steady
        reset_dut();
        test_simultaneous_enq_deq();
        repeat(5) @(posedge CLK);

        // Test 9: 4 writes to different addresses → different BG/B per push
        reset_dut();
        test_different_banks();
        repeat(5) @(posedge CLK);

        // Test 10: Reset mid-operation → clean state → resume
        reset_dut();
        test_reset_behavior();
        repeat(5) @(posedge CLK);

        $stop;
    end

endmodule
