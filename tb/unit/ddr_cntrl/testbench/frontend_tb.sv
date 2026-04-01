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

    // Program block instantiation
    frontend_tb_prog PROG (
        .CLK(CLK),
        .nRST(nRST),
        .ddrif(ddrif),
        .test_case(test_case)
    );

endmodule

program frontend_tb_prog (
    ref logic CLK,
    ref logic nRST,
    ddr_controller_if ddrif,
    ref string test_case
);
    import dram_pkg::*;

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

    // AXI write handshake: hold valid until ready, then deassert
    task drive_write_request(
        input logic [31:0]                addr,
        input logic [$clog2(ID_NUM)-1:0]  id,
        input logic [2:0]                 len
    );
        ddrif.awvalid = 1'b1;
        ddrif.awaddr  = addr;
        ddrif.awid    = id;
        ddrif.awlen   = len;
        do @(posedge CLK); while (!ddrif.awready);
        // Hold valid one more cycle so always_ff captures the handshake
        @(posedge CLK);
        ddrif.awvalid = 1'b0;
        ddrif.awaddr  = '0;
        ddrif.awid    = '0;
        ddrif.awlen   = '0;
    endtask

    // AXI read handshake: hold valid until ready, then deassert
    task drive_read_request(
        input logic [31:0]                addr,
        input logic [$clog2(ID_NUM)-1:0]  id,
        input logic [2:0]                 len
    );
        ddrif.arvalid = 1'b1;
        ddrif.araddr  = addr;
        ddrif.arid    = id;
        ddrif.arlen   = len;
        do @(posedge CLK); while (!ddrif.arready);
        // Hold valid one more cycle so always_ff captures the handshake
        @(posedge CLK);
        ddrif.arvalid = 1'b0;
        ddrif.araddr  = '0;
        ddrif.arid    = '0;
        ddrif.arlen   = '0;
    endtask

    // Assert AXI write signals without waiting for handshake
    task set_write_request(
        input logic [31:0]                addr,
        input logic [$clog2(ID_NUM)-1:0]  id,
        input logic [2:0]                 len
    );
        ddrif.awvalid = 1'b1;
        ddrif.awaddr  = addr;
        ddrif.awid    = id;
        ddrif.awlen   = len;
    endtask

    // Assert AXI read signals without waiting for handshake
    task set_read_request(
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

    // AXI write handshake — drop valid immediately when ready seen (no extra hold)
    // Creates awready=1 && awvalid=0 comb evaluation for condition coverage
    task drive_write_no_hold(
        input logic [31:0]                addr,
        input logic [$clog2(ID_NUM)-1:0]  id,
        input logic [2:0]                 len
    );
        ddrif.awvalid = 1'b1;
        ddrif.awaddr  = addr;
        ddrif.awid    = id;
        ddrif.awlen   = len;
        do @(posedge CLK); while (!ddrif.awready);
        // Drop valid immediately — no extra hold
        ddrif.awvalid = 1'b0;
        ddrif.awaddr  = '0;
        ddrif.awid    = '0;
        ddrif.awlen   = '0;
    endtask

    // AXI read handshake — drop valid immediately when ready seen (no extra hold)
    task drive_read_no_hold(
        input logic [31:0]                addr,
        input logic [$clog2(ID_NUM)-1:0]  id,
        input logic [2:0]                 len
    );
        ddrif.arvalid = 1'b1;
        ddrif.araddr  = addr;
        ddrif.arid    = id;
        ddrif.arlen   = len;
        do @(posedge CLK); while (!ddrif.arready);
        // Drop valid immediately — no extra hold
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
        // Task holds awvalid until awready, then deasserts
        drive_write_request(32'h0000_1000, 3'd2, 3'd4);

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
        // Task holds arvalid until arready, then deasserts
        drive_read_request(32'h0000_2000, 3'd5, 3'd2);

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

        // Drive BOTH channels at the same time using fork/join
        fork
            drive_write_request(32'h0000_3000, 3'd1, 3'd3);
            drive_read_request(32'h0000_4000, 3'd6, 3'd1);
        join

        // Wait for arbiter to drain both entries via round-robin.
        repeat(10) @(posedge CLK);
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

        // Send STQ_DEPTH (8) write requests, each handshake completes.
        for (i = 0; i < STQ_DEPTH; i++) begin
            drive_write_request(
                .addr(32'h0000_1000 + (i * 32'h100)),
                .id  (i[2:0]),
                .len (3'd1)
            );
        end

        // 9th request — queue should be full, awready stays 0
        set_write_request(32'h0000_FFFF, 3'd7, 3'd1);
        @(posedge CLK);
        // awready should be 0 — STQ is full (taken==STQ_DEPTH).
        clear_write();

        // Let the arbiter drain
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

        // Send LQ_DEPTH (8) read requests, each handshake completes.
        for (i = 0; i < LQ_DEPTH; i++) begin
            drive_read_request(
                .addr(32'h0000_2000 + (i * 32'h100)),
                .id  (i[2:0]),
                .len (3'd2)
            );
        end

        // 9th request — queue full, arready stays 0
        set_read_request(32'h0000_FFFF, 3'd7, 3'd2);
        @(posedge CLK);
        // arready should be 0 — LQ is full.
        clear_read();

        // Let arbiter drain
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

        // Drive a write request (handshake completes — STQ has room)
        drive_write_request(32'h0000_5000, 3'd3, 3'd2);

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
            fork
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
            join

            // Let arbiter process both entries (2 pushes needed)
            repeat(10) @(posedge CLK);
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

        // Pre-load entries into STQ back-to-back
        drive_write_request(32'h0000_A000, 3'd0, 3'd1);
        drive_write_request(32'h0000_A100, 3'd1, 3'd1);
        drive_write_request(32'h0000_A200, 3'd2, 3'd3);

        // Let everything drain — arbiter processes while STQ adds entries,
        // creating simultaneous enqueue+dequeue opportunities.
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

        // 4 writes to different addresses mapping to different banks
        drive_write_request(32'h0000_0040, 3'd0, 3'd1);
        drive_write_request(32'h0000_2040, 3'd1, 3'd1);
        drive_write_request(32'h0000_4040, 3'd2, 3'd1);
        drive_write_request(32'h0000_6040, 3'd3, 3'd1);

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

        // Load entries into both queues simultaneously
        fork
            drive_write_request(32'h0000_B000, 3'd1, 3'd1);
            drive_read_request(32'h0000_C000, 3'd2, 3'd1);
        join

        // Load another round
        fork
            drive_write_request(32'h0000_B100, 3'd3, 3'd1);
            drive_read_request(32'h0000_C100, 3'd4, 3'd1);
        join

        // ASSERT RESET mid-operation
        nRST = 1'b0;
        repeat(2) @(posedge CLK);

        // RELEASE RESET
        nRST = 1'b1;
        @(posedge CLK);

        // Verify system works after reset — drive a fresh write
        drive_write_request(32'h0000_D000, 3'd0, 3'd1);

        // Let arbiter process the post-reset entry
        repeat(6) @(posedge CLK);
    endtask

    // ================================================================
    // CONSTRAINED RANDOM VERIFICATION CLASSES
    // ================================================================

    // Single AXI transaction descriptor
    class axi_txn;
        rand bit        is_write;
        rand bit [31:0] addr;
        rand bit [2:0]  id;
        rand bit [2:0]  len;

        // Keep addresses word-aligned (low 2 bits = 0)
        constraint c_align { addr[1:0] == 2'b00; }

        // Burst length 1–7
        constraint c_len { len inside {[1:7]}; }

        // ID range
        constraint c_id { id inside {[0:7]}; }
    endclass

    // Weighted transaction — bias toward writes or reads
    class axi_txn_write_heavy extends axi_txn;
        constraint c_rw { is_write dist { 1 := 80, 0 := 20 }; }
    endclass

    class axi_txn_read_heavy extends axi_txn;
        constraint c_rw { is_write dist { 1 := 20, 0 := 80 }; }
    endclass

    // Burst of transactions to stress fill/drain
    class axi_burst_seq;
        rand int unsigned num_txns;
        rand axi_txn txns[];

        constraint c_num { num_txns inside {[4:20]}; }
        constraint c_size { txns.size() == num_txns; }

        function void pre_randomize();
            txns = new[20]; // max size
            foreach (txns[i]) txns[i] = new();
        endfunction
    endclass

    // ================================================================
    // CONSTRAINED RANDOM TEST TASKS
    // ================================================================

    // Drive a single randomized transaction
    task drive_random_txn(axi_txn txn);
        if (txn.is_write)
            drive_write_request(txn.addr, txn.id, txn.len);
        else
            drive_read_request(txn.addr, txn.id, txn.len);
    endtask

    // TEST 11: Random mixed traffic
    task test_random_mixed;
        axi_txn txn;
        integer i;
        test_case = "Random Mixed Traffic";
        $display("\n[TEST] %s", test_case);

        txn = new();
        for (i = 0; i < 16; i++) begin
            assert(txn.randomize()) else $fatal("randomize failed");
            $display("  txn[%0d]: %s addr=%08h id=%0d len=%0d",
                     i, txn.is_write ? "WR" : "RD",
                     txn.addr, txn.id, txn.len);
            drive_random_txn(txn);
        end
        // Drain
        repeat(20) @(posedge CLK);
    endtask

    // TEST 12: Write-heavy burst
    task test_random_write_heavy;
        axi_txn_write_heavy txn;
        integer i;
        test_case = "Random Write-Heavy Burst";
        $display("\n[TEST] %s", test_case);

        txn = new();
        for (i = 0; i < 20; i++) begin
            assert(txn.randomize()) else $fatal("randomize failed");
            $display("  txn[%0d]: %s addr=%08h id=%0d len=%0d",
                     i, txn.is_write ? "WR" : "RD",
                     txn.addr, txn.id, txn.len);
            drive_random_txn(txn);
        end
        repeat(30) @(posedge CLK);
    endtask

    // TEST 13: Read-heavy burst
    task test_random_read_heavy;
        axi_txn_read_heavy txn;
        integer i;
        test_case = "Random Read-Heavy Burst";
        $display("\n[TEST] %s", test_case);

        txn = new();
        for (i = 0; i < 20; i++) begin
            assert(txn.randomize()) else $fatal("randomize failed");
            $display("  txn[%0d]: %s addr=%08h id=%0d len=%0d",
                     i, txn.is_write ? "WR" : "RD",
                     txn.addr, txn.id, txn.len);
            drive_random_txn(txn);
        end
        repeat(30) @(posedge CLK);
    endtask

    // TEST 14: Simultaneous random read + write streams
    task test_random_simultaneous;
        axi_txn wr_txn, rd_txn;
        integer i;
        test_case = "Random Simultaneous R+W";
        $display("\n[TEST] %s", test_case);

        wr_txn = new();
        rd_txn = new();
        for (i = 0; i < 10; i++) begin
            assert(wr_txn.randomize() with { is_write == 1; }) else $fatal("randomize failed");
            assert(rd_txn.randomize() with { is_write == 0; }) else $fatal("randomize failed");
            $display("  round[%0d]: WR addr=%08h id=%0d len=%0d | RD addr=%08h id=%0d len=%0d",
                     i, wr_txn.addr, wr_txn.id, wr_txn.len,
                     rd_txn.addr, rd_txn.id, rd_txn.len);
            fork
                drive_write_request(wr_txn.addr, wr_txn.id, wr_txn.len);
                drive_read_request(rd_txn.addr, rd_txn.id, rd_txn.len);
            join
            repeat(5) @(posedge CLK);
        end
        repeat(20) @(posedge CLK);
    endtask

    // TEST 15: Fill both queues with random data, overflow, then drain
    task test_random_fill_overflow;
        axi_txn txn;
        integer i;
        test_case = "Random Fill + Overflow";
        $display("\n[TEST] %s", test_case);

        txn = new();

        // Fill STQ to capacity with random writes
        $display("  Filling STQ...");
        for (i = 0; i < STQ_DEPTH; i++) begin
            assert(txn.randomize() with { is_write == 1; }) else $fatal("randomize failed");
            $display("    stq[%0d]: addr=%08h id=%0d len=%0d", i, txn.addr, txn.id, txn.len);
            drive_write_request(txn.addr, txn.id, txn.len);
        end

        // Attempt overflow — should deny
        assert(txn.randomize() with { is_write == 1; }) else $fatal("randomize failed");
        $display("  STQ overflow attempt: addr=%08h", txn.addr);
        set_write_request(txn.addr, txn.id, txn.len);
        @(posedge CLK);
        if (!ddrif.awready)
            $display("  PASS: STQ full, awready=0");
        else
            $display("  FAIL: STQ accepted 9th entry");
        clear_write();

        // Fill LQ to capacity with random reads
        $display("  Filling LQ...");
        for (i = 0; i < LQ_DEPTH; i++) begin
            assert(txn.randomize() with { is_write == 0; }) else $fatal("randomize failed");
            $display("    lq[%0d]: addr=%08h id=%0d len=%0d", i, txn.addr, txn.id, txn.len);
            drive_read_request(txn.addr, txn.id, txn.len);
        end

        // Attempt overflow — should deny
        assert(txn.randomize() with { is_write == 0; }) else $fatal("randomize failed");
        $display("  LQ overflow attempt: addr=%08h", txn.addr);
        set_read_request(txn.addr, txn.id, txn.len);
        @(posedge CLK);
        if (!ddrif.arready)
            $display("  PASS: LQ full, arready=0");
        else
            $display("  FAIL: LQ accepted 9th entry");
        clear_read();

        // Drain everything
        repeat(40) @(posedge CLK);
    endtask

    // TEST 16: Random traffic with random backpressure
    task test_random_backpressure;
        axi_txn txn;
        integer i;
        logic [BANK_NUM-1:0] rand_full;
        test_case = "Random Traffic + Backpressure";
        $display("\n[TEST] %s", test_case);

        txn = new();
        for (i = 0; i < 12; i++) begin
            // Randomize fe_full pattern each iteration
            assert(std::randomize(rand_full)) else $fatal("randomize failed");
            ddrif.fe_full = rand_full;
            $display("  round[%0d]: fe_full=%016b", i, rand_full);

            assert(txn.randomize()) else $fatal("randomize failed");
            drive_random_txn(txn);
            repeat(3) @(posedge CLK);
        end
        // Release backpressure and drain
        ddrif.fe_full = '0;
        repeat(30) @(posedge CLK);
    endtask

    // TEST 17: Random burst sequence
    task test_random_burst_seq;
        axi_burst_seq seq;
        integer i;
        test_case = "Random Burst Sequence";
        $display("\n[TEST] %s", test_case);

        seq = new();
        assert(seq.randomize()) else $fatal("randomize failed");
        $display("  Burst of %0d transactions", seq.num_txns);

        for (i = 0; i < seq.num_txns; i++) begin
            $display("  txn[%0d]: %s addr=%08h id=%0d len=%0d",
                     i, seq.txns[i].is_write ? "WR" : "RD",
                     seq.txns[i].addr, seq.txns[i].id, seq.txns[i].len);
            drive_random_txn(seq.txns[i]);
        end
        repeat(30) @(posedge CLK);
    endtask

    // ================================================================
    // CONDITION COVERAGE TESTS
    // ================================================================

    // TEST 18: LQ Simultaneous Enqueue + Dequeue
    //   Pre-load LQ then keep sending reads while arbiter drains,
    //   forcing arvalid && arready && grant_l && request_l on same cycle.
    task test_lq_simultaneous_enq_deq;
        test_case = "LQ Simultaneous Enqueue+Dequeue";
        $display("\n[TEST] %s", test_case);

        // Pre-load 3 entries into LQ
        drive_read_request(32'h0001_0000, 3'd0, 3'd1);
        drive_read_request(32'h0001_0100, 3'd1, 3'd1);
        drive_read_request(32'h0001_0200, 3'd2, 3'd1);

        // Continue driving reads while arbiter drains — creates
        // simultaneous enqueue+dequeue windows in LQ
        drive_read_request(32'h0001_0300, 3'd3, 3'd1);
        drive_read_request(32'h0001_0400, 3'd4, 3'd1);
        drive_read_request(32'h0001_0500, 3'd5, 3'd1);

        repeat(10) @(posedge CLK);
    endtask

    // TEST 19: Only STQ Requesting (request_l=0 throughout)
    //   Exercises arbiter pri logic with only request_s active.
    //   Forces pri=0,request_s=1 and pri=1,request_s=1 with request_l always 0.
    task test_only_stq_requesting;
        test_case = "Only STQ Requesting";
        $display("\n[TEST] %s", test_case);

        // Send several writes with NO reads — arbiter only sees request_s
        drive_write_request(32'h0002_0000, 3'd0, 3'd1);
        repeat(4) @(posedge CLK);
        drive_write_request(32'h0002_0100, 3'd1, 3'd2);
        repeat(4) @(posedge CLK);
        drive_write_request(32'h0002_0200, 3'd2, 3'd3);
        repeat(4) @(posedge CLK);
        drive_write_request(32'h0002_0300, 3'd3, 3'd1);
        repeat(8) @(posedge CLK);
    endtask

    // TEST 20: Only LQ Requesting (request_s=0 throughout)
    //   Exercises arbiter pri logic with only request_l active.
    //   Forces pri=0,request_l=1 and pri=1,request_l=1 with request_s always 0.
    task test_only_lq_requesting;
        test_case = "Only LQ Requesting";
        $display("\n[TEST] %s", test_case);

        // Send several reads with NO writes — arbiter only sees request_l
        drive_read_request(32'h0003_0000, 3'd0, 3'd1);
        repeat(4) @(posedge CLK);
        drive_read_request(32'h0003_0100, 3'd1, 3'd2);
        repeat(4) @(posedge CLK);
        drive_read_request(32'h0003_0200, 3'd2, 3'd3);
        repeat(4) @(posedge CLK);
        drive_read_request(32'h0003_0300, 3'd3, 3'd1);
        repeat(8) @(posedge CLK);
    endtask

    // TEST 21: Buffer Stall — buff_l.valid blocks grant_l
    //   Grant one LQ entry into buff_l, then block BQ push with fe_full.
    //   While buff_l.valid=1, a new request_l should NOT get granted.
    task test_buff_l_stall;
        test_case = "buff_l.valid Blocks grant_l";
        $display("\n[TEST] %s", test_case);

        // Drive a read so LQ has a request → arbiter grants into buff_l
        drive_read_request(32'h0004_0000, 3'd0, 3'd1);
        repeat(2) @(posedge CLK);

        // Now block ALL bank queues — buff_l can't push, stays valid
        ddrif.fe_full = {BANK_NUM{1'b1}};
        repeat(2) @(posedge CLK);

        // Drive another read — LQ accepts it but arbiter should NOT
        // re-grant because buff_l is still valid (stalled by fe_full)
        drive_read_request(32'h0004_0100, 3'd1, 3'd1);

        // Hold stall for several cycles so grant_l stays blocked
        repeat(6) @(posedge CLK);

        // Release backpressure — buff_l pushes, then new entry gets granted
        ddrif.fe_full = '0;
        repeat(8) @(posedge CLK);
    endtask

    // TEST 22: Buffer Stall — buff_s.valid blocks grant_s
    //   Same pattern as test 21 but for the store buffer.
    task test_buff_s_stall;
        test_case = "buff_s.valid Blocks grant_s";
        $display("\n[TEST] %s", test_case);

        // Drive a write so STQ has a request → arbiter grants into buff_s
        drive_write_request(32'h0005_0000, 3'd0, 3'd1);
        repeat(2) @(posedge CLK);

        // Block ALL bank queues
        ddrif.fe_full = {BANK_NUM{1'b1}};
        repeat(2) @(posedge CLK);

        // Drive another write — STQ accepts but arbiter can't re-grant
        drive_write_request(32'h0005_0100, 3'd1, 3'd1);

        // Hold stall
        repeat(6) @(posedge CLK);

        // Release
        ddrif.fe_full = '0;
        repeat(8) @(posedge CLK);
    endtask

    // TEST 23: Partial fe_full — Only Target Bank Blocked
    //   Block a specific bank while others are free. Arbiter has a
    //   valid buffer entry targeting the blocked bank → fe_write_bq
    //   should NOT assert. Then release that bank.
    task test_partial_fe_full;
        test_case = "Partial fe_full (Target Bank Blocked)";
        $display("\n[TEST] %s", test_case);

        // Block bank 0 only (fe_full[0] = 1)
        ddrif.fe_full = 16'h0001;

        // Drive a write targeting an address that maps to bank 0
        // Address 0x0000_0000 should map to BG=0, bank=0
        drive_write_request(32'h0000_0000, 3'd0, 3'd1);
        repeat(6) @(posedge CLK);
        // fe_write_bq should NOT fire — target bank is full

        // Now release bank 0
        ddrif.fe_full = '0;
        repeat(6) @(posedge CLK);
        // Now push should go through

        // Do the same with a read targeting a different blocked bank
        ddrif.fe_full = 16'h0002;  // block bank 1
        drive_read_request(32'h0000_0040, 3'd1, 3'd1);
        repeat(6) @(posedge CLK);

        ddrif.fe_full = '0;
        repeat(6) @(posedge CLK);
    endtask

    // TEST 24: Interleaved Single W/R (Toggle pri_bq)
    //   Alternate single write and single read with drain in between.
    //   Forces pri_bq to toggle each time between store and load buffers.
    task test_interleaved_wr;
        integer i;
        test_case = "Interleaved W/R (pri_bq Toggle)";
        $display("\n[TEST] %s", test_case);

        for (i = 0; i < 4; i++) begin
            // Write, wait for BQ push
            drive_write_request(32'h0006_0000 + (i * 32'h200), i[2:0], 3'd1);
            repeat(6) @(posedge CLK);

            // Read, wait for BQ push
            drive_read_request(32'h0006_0100 + (i * 32'h200), i[2:0] + 3'd4, 3'd1);
            repeat(6) @(posedge CLK);
        end
    endtask

    // TEST 25: Valid Held While Queue Full (awready stays 0)
    //   Fill STQ to capacity, then hold awvalid=1 for multiple cycles.
    //   Exercises `taken == STQ_DEPTH` making ready condition false.
    //   Also exercises LQ variant.
    task test_valid_while_full;
        integer i;
        test_case = "Valid Held While Queue Full";
        $display("\n[TEST] %s", test_case);

        // Fill STQ completely
        for (i = 0; i < STQ_DEPTH; i++) begin
            drive_write_request(32'h0007_0000 + (i * 32'h100), i[2:0], 3'd1);
        end

        // Hold awvalid for several cycles while full
        set_write_request(32'h0007_FF00, 3'd7, 3'd1);
        repeat(4) @(posedge CLK);
        // awready must remain 0 throughout — taken == STQ_DEPTH
        clear_write();

        // Let arbiter drain so queue empties
        repeat(20) @(posedge CLK);

        // Same for LQ
        for (i = 0; i < LQ_DEPTH; i++) begin
            drive_read_request(32'h0008_0000 + (i * 32'h100), i[2:0], 3'd1);
        end
        set_read_request(32'h0008_FF00, 3'd7, 3'd1);
        repeat(4) @(posedge CLK);
        clear_read();

        repeat(20) @(posedge CLK);
    endtask

    // TEST 26: Fill and Drain Both Queues to Empty
    //   Fill both queues, wait for complete drain, exercises
    //   taken_n==0 → request_n=0 in both STQ and LQ, and pointer wraps
    //   for both head and tail in both queues.
    task test_fill_drain_both;
        integer i;
        test_case = "Fill+Drain Both Queues to Empty";
        $display("\n[TEST] %s", test_case);

        // Fill both queues simultaneously
        fork
            begin
                for (i = 0; i < STQ_DEPTH; i++)
                    drive_write_request(32'h0009_0000 + (i * 32'h100), i[2:0], 3'd1);
            end
            begin
                for (i = 0; i < LQ_DEPTH; i++)
                    drive_read_request(32'h000A_0000 + (i * 32'h100), i[2:0], 3'd1);
            end
        join

        // Wait for arbiter to fully drain both queues
        // request_s and request_l should both go to 0
        repeat(40) @(posedge CLK);
    endtask

    // TEST 27: Back-to-Back Grants With Both Buffers Active
    //   Send one write + one read simultaneously so both buffers fill.
    //   Then repeat — exercises pri_bq toggling with both buffers valid.
    task test_both_buffers_active;
        integer i;
        test_case = "Both Arbiter Buffers Active";
        $display("\n[TEST] %s", test_case);

        for (i = 0; i < 4; i++) begin
            fork
                drive_write_request(32'h000B_0000 + (i * 32'h200), i[2:0], 3'd1);
                drive_read_request(32'h000B_0100 + (i * 32'h200), i[2:0] + 3'd4, 3'd1);
            join
            // Minimal drain time — forces both buffers to be valid simultaneously
            repeat(2) @(posedge CLK);
        end
        repeat(10) @(posedge CLK);
    endtask

    // TEST 28: Stalled Buffer Then Switch Priority
    //   Block store buffer with fe_full, then send reads to exercise
    //   pri_bq=1 with buff_l arriving while buff_s is stalled.
    task test_stalled_buffer_switch;
        test_case = "Stalled Buffer + Priority Switch";
        $display("\n[TEST] %s", test_case);

        // Block all banks
        ddrif.fe_full = {BANK_NUM{1'b1}};

        // Fill both buffers — write then read
        fork
            drive_write_request(32'h000C_0000, 3'd0, 3'd1);
            drive_read_request(32'h000C_0100, 3'd1, 3'd1);
        join
        repeat(4) @(posedge CLK);

        // Both buff_s and buff_l should be valid but stalled.
        // pri_bq toggles but can't push either.
        // Send more requests — queues accept but arbiter can't grant (buffers valid)
        fork
            drive_write_request(32'h000C_0200, 3'd2, 3'd1);
            drive_read_request(32'h000C_0300, 3'd3, 3'd1);
        join
        repeat(4) @(posedge CLK);

        // Partially release — only unblock a subset of banks
        ddrif.fe_full = 16'hFFFE;  // bank 0 free
        repeat(4) @(posedge CLK);

        // Fully release
        ddrif.fe_full = '0;
        repeat(12) @(posedge CLK);
    endtask

    // ================================================================
    // BRANCH / CONDITION / STATEMENT COVERAGE TESTS (ROUND 2)
    // ================================================================

    // TEST 29: Early Valid Drop — awready=1 && awvalid=0 comb evaluation
    //   Drop valid immediately on ready for both queues (no extra hold).
    //   In the reactive region, awvalid=0 while awready(reg)=1 still,
    //   causing the comb to evaluate: awready=T, awvalid=F (condition gap).
    task test_early_valid_drop;
        test_case = "Early Valid Drop (Condition Coverage)";
        $display("\n[TEST] %s", test_case);

        // STQ: early drop
        drive_write_no_hold(32'h0010_0000, 3'd0, 3'd1);
        repeat(6) @(posedge CLK);

        // LQ: early drop
        drive_read_no_hold(32'h0010_1000, 3'd1, 3'd2);
        repeat(6) @(posedge CLK);

        // Multiple early drops back-to-back
        drive_write_no_hold(32'h0010_2000, 3'd2, 3'd3);
        drive_write_no_hold(32'h0010_3000, 3'd3, 3'd1);
        repeat(4) @(posedge CLK);
        drive_read_no_hold(32'h0010_4000, 3'd4, 3'd2);
        drive_read_no_hold(32'h0010_5000, 3'd5, 3'd1);
        repeat(10) @(posedge CLK);
    endtask

    // TEST 30: Valid Pulse (1 cycle, no handshake)
    //   Assert awvalid/arvalid for exactly 1 cycle, deassert BEFORE
    //   ready goes high. Exercises awvalid=T→F transition with no capture,
    //   and awready_n=1 followed by awready=1 with awvalid=0 → no data taken.
    task test_valid_pulse_no_handshake;
        test_case = "Valid Pulse (No Handshake)";
        $display("\n[TEST] %s", test_case);

        // STQ: pulse awvalid for 1 cycle
        set_write_request(32'h0011_0000, 3'd0, 3'd1);
        @(posedge CLK);
        clear_write();
        // awready_n was set to 1 in the comb (awvalid=1, !awready=1, taken=0).
        // On next posedge: awready=1, but awvalid=0 → no data capture.
        repeat(3) @(posedge CLK);

        // LQ: pulse arvalid for 1 cycle
        set_read_request(32'h0011_1000, 3'd1, 3'd1);
        @(posedge CLK);
        clear_read();
        repeat(3) @(posedge CLK);

        // Another STQ pulse — verify queue still empty, state clean
        set_write_request(32'h0011_2000, 3'd2, 3'd2);
        @(posedge CLK);
        clear_write();
        repeat(3) @(posedge CLK);
    endtask

    // TEST 31: Handshake While Arbiter Grants Opposite Queue
    //   STQ handshake completes in the same cycle arbiter grants LQ.
    //   Exercises awvalid=1, awready=1, request_s=1, grant_s=0 (same-cycle condition).
    task test_handshake_during_opposite_grant;
        integer i;
        test_case = "Handshake During Opposite Grant";
        $display("\n[TEST] %s", test_case);

        // Pre-load both queues with entries
        drive_write_request(32'h0012_0000, 3'd0, 3'd1);
        drive_read_request(32'h0012_0100, 3'd1, 3'd1);

        // Now keep both channels busy — the arbiter alternates grants.
        // While it's granting LQ (grant_l=1, grant_s=0), drive a new write
        // so awvalid && awready happen simultaneously with grant_s=0.
        for (i = 0; i < 6; i++) begin
            fork
                drive_write_request(32'h0012_1000 + (i * 32'h100), i[2:0], 3'd1);
                drive_read_request(32'h0012_2000 + (i * 32'h100), i[2:0] + 3'd4, 3'd1);
            join
        end
        repeat(15) @(posedge CLK);
    endtask

    // TEST 32: Repeated Fill-Drain Cycles (Multiple Pointer Wraps)
    //   Fill STQ and LQ to capacity, fully drain, repeat 3 times.
    //   Each cycle wraps both head and tail pointers through all STQ_DEPTH values.
    task test_repeated_fill_drain;
        integer i, cycle;
        test_case = "Repeated Fill-Drain (Pointer Wraps)";
        $display("\n[TEST] %s", test_case);

        for (cycle = 0; cycle < 3; cycle++) begin
            $display("  Fill-drain cycle %0d", cycle);

            // Fill STQ to capacity
            for (i = 0; i < STQ_DEPTH; i++) begin
                drive_write_request(
                    32'h0013_0000 + (cycle * 32'h1000) + (i * 32'h100),
                    i[2:0], 3'd1
                );
            end

            // Fill LQ to capacity
            for (i = 0; i < LQ_DEPTH; i++) begin
                drive_read_request(
                    32'h0014_0000 + (cycle * 32'h1000) + (i * 32'h100),
                    i[2:0], 3'd1
                );
            end

            // Wait for full drain — need enough time for 16 entries through arbiter
            repeat(50) @(posedge CLK);
        end
    endtask

    // TEST 33: Single Entry Lifecycle (taken 0→1→0)
    //   Add exactly one entry, wait for complete drain, repeat for each queue.
    //   Cleanly exercises request_n = 0→1→0 transitions and taken_n/occ_n = 0→1→0.
    task test_single_entry_lifecycle;
        test_case = "Single Entry Lifecycle";
        $display("\n[TEST] %s", test_case);

        // STQ: add 1, drain completely
        drive_write_request(32'h0015_0000, 3'd0, 3'd1);
        repeat(8) @(posedge CLK);

        // STQ: add 1 more after empty, drain
        drive_write_request(32'h0015_0100, 3'd1, 3'd2);
        repeat(8) @(posedge CLK);

        // LQ: add 1, drain
        drive_read_request(32'h0015_1000, 3'd2, 3'd1);
        repeat(8) @(posedge CLK);

        // LQ: add 1 more after empty, drain
        drive_read_request(32'h0015_1100, 3'd3, 3'd2);
        repeat(8) @(posedge CLK);
    endtask

    // TEST 34: Sustained Dual-Queue Traffic
    //   Keep both queues continuously loaded for many cycles.
    //   Exercises all pri/pri_bq state transitions extensively.
    task test_sustained_dual_traffic;
        integer i;
        test_case = "Sustained Dual-Queue Traffic";
        $display("\n[TEST] %s", test_case);

        // Send 12 pairs of simultaneous R+W, minimal gaps
        for (i = 0; i < 12; i++) begin
            fork
                drive_write_request(32'h0016_0000 + (i * 32'h200), i[2:0], 3'd1);
                drive_read_request(32'h0016_0100 + (i * 32'h200), 3'((i+4) % 8), 3'd1);
            join
            // Minimal gap — keeps queues loaded while arbiter alternates
            @(posedge CLK);
        end
        repeat(20) @(posedge CLK);
    endtask

    // TEST 35: Dynamic fe_full Toggle During Buffer Push
    //   Load arbiter buffer, then toggle fe_full on/off rapidly.
    //   Exercises ~fe_full[bank] going T→F→T in the BQ push condition.
    task test_fe_full_toggle;
        integer i;
        test_case = "Dynamic fe_full Toggle";
        $display("\n[TEST] %s", test_case);

        // Drive a write — gets into STQ, arbiter grants into buff_s
        drive_write_request(32'h0017_0000, 3'd0, 3'd1);
        repeat(2) @(posedge CLK);

        // Toggle fe_full rapidly while buffer is valid
        for (i = 0; i < 6; i++) begin
            ddrif.fe_full = {BANK_NUM{1'b1}};  // block all
            @(posedge CLK);
            ddrif.fe_full = '0;                 // free all
            @(posedge CLK);
        end
        repeat(4) @(posedge CLK);

        // Same for LQ side
        drive_read_request(32'h0017_1000, 3'd1, 3'd1);
        repeat(2) @(posedge CLK);
        for (i = 0; i < 6; i++) begin
            ddrif.fe_full = {BANK_NUM{1'b1}};
            @(posedge CLK);
            ddrif.fe_full = '0;
            @(posedge CLK);
        end
        repeat(8) @(posedge CLK);
    endtask

    // TEST 36: Maximum Pressure — Both Full + All Blocked + Gradual Release
    //   Fill both queues, block all banks, then unblock banks one at a time.
    //   Exercises every stall path simultaneously plus gradual drain.
    task test_max_pressure;
        integer i;
        test_case = "Max Pressure (Full Queues + Blocked Banks)";
        $display("\n[TEST] %s", test_case);

        // Block all banks FIRST
        ddrif.fe_full = {BANK_NUM{1'b1}};

        // Fill both queues to capacity
        fork
            begin
                for (i = 0; i < STQ_DEPTH; i++)
                    drive_write_request(32'h0018_0000 + (i * 32'h100), i[2:0], 3'd1);
            end
            begin
                for (i = 0; i < LQ_DEPTH; i++)
                    drive_read_request(32'h0019_0000 + (i * 32'h100), i[2:0], 3'd1);
            end
        join

        // Attempt one more of each — should be denied (queues full)
        set_write_request(32'h0018_FF00, 3'd7, 3'd1);
        set_read_request(32'h0019_FF00, 3'd7, 3'd1);
        repeat(3) @(posedge CLK);
        clear_write();
        clear_read();

        // Stall for several cycles — all stall paths active
        repeat(6) @(posedge CLK);

        // Gradual release — unblock 4 banks at a time
        ddrif.fe_full = 16'hFFF0;
        repeat(6) @(posedge CLK);
        ddrif.fe_full = 16'hFF00;
        repeat(6) @(posedge CLK);
        ddrif.fe_full = 16'hF000;
        repeat(6) @(posedge CLK);
        ddrif.fe_full = '0;
        repeat(30) @(posedge CLK);
    endtask

    // TEST 37: Idle Period With Empty Queues
    //   After reset, just run for many cycles with no valid signals.
    //   Exercises: awvalid=F path in ready condition, taken_n=0 → request_n=0
    //   persistently, and all comb default assignments.
    task test_idle_empty;
        test_case = "Idle Empty Queues";
        $display("\n[TEST] %s", test_case);

        // Just idle — all inputs already cleared by reset_dut
        repeat(20) @(posedge CLK);
    endtask

    // TEST 38: Alternating Priority Grants
    //   Drive alternating single write then single read with immediate follow-up.
    //   After each grant completes, the priority flips. Verifies both pri=0→1
    //   and pri=1→0 transitions, and both pri_bq states with each buffer type.
    task test_alternating_priority;
        integer i;
        test_case = "Alternating Priority Grants";
        $display("\n[TEST] %s", test_case);

        for (i = 0; i < 6; i++) begin
            if (i % 2 == 0) begin
                // Even: write first, then read
                drive_write_request(32'h001A_0000 + (i * 32'h200), i[2:0], 3'd1);
                repeat(3) @(posedge CLK);
                drive_read_request(32'h001A_0100 + (i * 32'h200), 3'((i+4) % 8), 3'd1);
                repeat(3) @(posedge CLK);
            end else begin
                // Odd: read first, then write
                drive_read_request(32'h001A_0100 + (i * 32'h200), 3'((i+4) % 8), 3'd1);
                repeat(3) @(posedge CLK);
                drive_write_request(32'h001A_0000 + (i * 32'h200), i[2:0], 3'd1);
                repeat(3) @(posedge CLK);
            end
        end
        repeat(10) @(posedge CLK);
    endtask

    // TEST 39: Grant Denied — Wrong Priority
    //   Set up pri=1 (STQ turn) → drive only LQ requests. Arbiter should NOT
    //   grant LQ because ~pri=0. Then flip: pri=0 (LQ turn) with only STQ.
    //   Exercises (F,T,T) sub-case of grant conditions.
    task test_grant_denied_wrong_pri;
        test_case = "Grant Denied (Wrong Priority)";
        $display("\n[TEST] %s", test_case);

        // After reset, pri=0. Drive a write to make STQ request → pri toggles to 1.
        drive_write_request(32'h001B_0000, 3'd0, 3'd1);
        repeat(6) @(posedge CLK);

        // Now pri should be 1 (STQ's turn). Drive ONLY reads.
        // LQ requests but pri=1 means ~pri=0 → grant_l condition: ~pri=F → no LQ grant.
        // The arbiter should still eventually grant LQ because pri toggles based on rqst_select.
        drive_read_request(32'h001B_1000, 3'd1, 3'd1);
        repeat(4) @(posedge CLK);
        drive_read_request(32'h001B_1100, 3'd2, 3'd1);
        repeat(4) @(posedge CLK);

        // Flip scenario: get pri=0, then drive only writes
        reset_dut();
        // After reset, pri=0. Drive only reads to toggle pri if request_s triggers...
        // Actually after reset pri=0. Just drive writes directly.
        // pri=0 means grant_s checks pri=0=F → grant_s blocked. But pri toggles.
        drive_write_request(32'h001B_2000, 3'd3, 3'd1);
        repeat(4) @(posedge CLK);
        drive_write_request(32'h001B_2100, 3'd4, 3'd1);
        repeat(8) @(posedge CLK);
    endtask

    // TEST 40: Rapid Fire Same Queue
    //   Drive 8 writes as fast as possible (back-to-back handshakes).
    //   Then 8 reads as fast as possible. Exercises rapid taken/occ
    //   incrementing and pointer advancement without full drain between.
    task test_rapid_fire_same_queue;
        integer i;
        test_case = "Rapid Fire Same Queue";
        $display("\n[TEST] %s", test_case);

        // Rapid writes — don't wait for drain between entries
        for (i = 0; i < STQ_DEPTH; i++) begin
            drive_write_request(32'h001C_0000 + (i * 32'h100), i[2:0], 3'd1);
        end
        // Drain
        repeat(25) @(posedge CLK);

        // Rapid reads
        for (i = 0; i < LQ_DEPTH; i++) begin
            drive_read_request(32'h001C_1000 + (i * 32'h100), i[2:0], 3'd1);
        end
        repeat(25) @(posedge CLK);
    endtask

    // TEST 41: Write-Only Stress (No Reads At All)
    //   Only write traffic for an extended period.
    //   Exercises arbiter with request_l=0 throughout, pri_bq only
    //   toggling from buff_s.valid, grant_l never asserting.
    task test_write_only_stress;
        integer i;
        test_case = "Write-Only Stress";
        $display("\n[TEST] %s", test_case);

        for (i = 0; i < 16; i++) begin
            drive_write_request(32'h001D_0000 + (i * 32'h100), i[2:0], 3'd1);
            // Small gap to let arbiter process some entries
            if (i % 4 == 3) repeat(8) @(posedge CLK);
        end
        repeat(20) @(posedge CLK);
    endtask

    // TEST 42: Read-Only Stress (No Writes At All)
    //   Only read traffic for an extended period.
    //   Exercises arbiter with request_s=0 throughout, pri_bq only
    //   toggling from buff_l.valid, grant_s never asserting.
    task test_read_only_stress;
        integer i;
        test_case = "Read-Only Stress";
        $display("\n[TEST] %s", test_case);

        for (i = 0; i < 16; i++) begin
            drive_read_request(32'h001E_0000 + (i * 32'h100), i[2:0], 3'd1);
            if (i % 4 == 3) repeat(8) @(posedge CLK);
        end
        repeat(20) @(posedge CLK);
    endtask

    // TEST 43: Partial Queue Fill + Drain (Non-Power-of-2)
    //   Fill STQ to 5 entries (not full), drain. Fill LQ to 3 entries, drain.
    //   Exercises intermediate occupancy values and non-aligned pointer positions.
    task test_partial_fill_drain;
        integer i;
        test_case = "Partial Fill + Drain";
        $display("\n[TEST] %s", test_case);

        // STQ: fill 5 of 8
        for (i = 0; i < 5; i++)
            drive_write_request(32'h001F_0000 + (i * 32'h100), i[2:0], 3'd1);
        repeat(15) @(posedge CLK);

        // LQ: fill 3 of 8
        for (i = 0; i < 3; i++)
            drive_read_request(32'h001F_1000 + (i * 32'h100), i[2:0], 3'd1);
        repeat(10) @(posedge CLK);

        // STQ: fill 7 of 8 (near full but not full)
        for (i = 0; i < 7; i++)
            drive_write_request(32'h001F_2000 + (i * 32'h100), i[2:0], 3'd1);
        repeat(20) @(posedge CLK);

        // LQ: fill 1 of 8 (minimal)
        drive_read_request(32'h001F_3000, 3'd0, 3'd1);
        repeat(6) @(posedge CLK);
    endtask

    // TEST 44: Both Queues Request + fe_full on Target Bank Only
    //   Both queues submit entries mapping to the SAME target bank.
    //   Block that bank. Both arbiter buffers fill and stall on the same bank.
    //   Exercises both BQ push conditions with ~fe_full=F simultaneously.
    task test_both_stall_same_bank;
        test_case = "Both Queues Stall Same Bank";
        $display("\n[TEST] %s", test_case);

        // Block bank 0
        ddrif.fe_full = 16'h0001;

        // Drive write and read targeting bank 0
        fork
            drive_write_request(32'h0000_0000, 3'd0, 3'd1);
            drive_read_request(32'h0000_0000, 3'd1, 3'd1);
        join

        // Both buffers should load and stall (target bank 0 blocked)
        repeat(8) @(posedge CLK);

        // Unblock
        ddrif.fe_full = '0;
        repeat(8) @(posedge CLK);
    endtask

    // ================================================================
    // TARGETED CONDITION COVERAGE TESTS (ROUND 3)
    // ================================================================

    // TEST 45: LQ arvalid held while occ==LQ_DEPTH and arready=0
    //   Exercises the false sub-condition (occ != 8)=F inside the ready
    //   condition when arvalid=T and arready=F. The comb sees all three
    //   sub-expressions: arvalid=T, !arready=T, occ==8 → (occ!=8)=F.
    //   Same pattern for STQ (taken==8).
    task test_valid_at_full_no_ready;
        integer i;
        test_case = "Valid at Full (occ==DEPTH, no ready)";
        $display("\n[TEST] %s", test_case);

        // --- STQ ---
        // Fill to capacity; arbiter blocked so nothing drains.
        ddrif.fe_full = {BANK_NUM{1'b1}};
        for (i = 0; i < STQ_DEPTH; i++)
            drive_write_request(32'h0020_0000 + (i * 32'h100), i[2:0], 3'd1);

        // Now taken==8, awready(reg)=0. Assert awvalid → comb evaluates
        // awvalid=T, !awready=T, taken==8 → condition FALSE.
        set_write_request(32'h0020_FF00, 3'd7, 3'd1);
        repeat(3) @(posedge CLK);  // hold valid while full, ready stays 0
        clear_write();

        // Release so queue drains for next phase
        ddrif.fe_full = '0;
        repeat(30) @(posedge CLK);

        // --- LQ ---
        ddrif.fe_full = {BANK_NUM{1'b1}};
        for (i = 0; i < LQ_DEPTH; i++)
            drive_read_request(32'h0021_0000 + (i * 32'h100), i[2:0], 3'd1);

        // occ==8, arready(reg)=0. Assert arvalid.
        set_read_request(32'h0021_FF00, 3'd7, 3'd1);
        repeat(3) @(posedge CLK);
        clear_read();

        ddrif.fe_full = '0;
        repeat(30) @(posedge CLK);
    endtask

    // TEST 46: LQ request_l=1 but grant_l=0 (arbiter busy with STQ)
    //   Forces grant_l=F, request_l=T sub-condition of (grant_l && request_l).
    //   Load one read into LQ. Block arbiter with fe_full so buff_l stays valid.
    //   LQ still has request_l=1 from its entry but grant_l=0 (buff_l.valid blocks it).
    task test_lq_request_no_grant;
        test_case = "LQ request_l=1, grant_l=0";
        $display("\n[TEST] %s", test_case);

        // Drive a read → enters LQ, arbiter grants into buff_l.
        drive_read_request(32'h0022_0000, 3'd0, 3'd1);
        repeat(2) @(posedge CLK);

        // Block all banks — buff_l stays valid (can't push)
        ddrif.fe_full = {BANK_NUM{1'b1}};
        repeat(2) @(posedge CLK);

        // Drive another read — LQ enqueues it, request_l=1.
        // But grant_l=0 because ~buff_l.valid is false.
        drive_read_request(32'h0022_0100, 3'd1, 3'd1);

        // Hold for several cycles: request_l=1, grant_l=0 persists.
        repeat(8) @(posedge CLK);

        // Release
        ddrif.fe_full = '0;
        repeat(10) @(posedge CLK);
    endtask

    // TEST 47: LQ simultaneous R/W with one sub-condition false
    //   Need arvalid=T, arready=T, request_l=T, grant_l=F all at once.
    //   Pre-load LQ so request_l=1. Block arbiter (fe_full) so buff_l
    //   stays valid → grant_l=0. Then drive another arvalid handshake.
    //   Comb sees: arvalid=T, arready=T, grant_l=F, request_l=T.
    task test_lq_simrw_grant_blocked;
        test_case = "LQ Sim R/W: grant_l=0";
        $display("\n[TEST] %s", test_case);

        // Drive 2 reads to load LQ and fill buff_l
        drive_read_request(32'h0023_0000, 3'd0, 3'd1);
        drive_read_request(32'h0023_0100, 3'd1, 3'd1);
        repeat(2) @(posedge CLK);

        // Block all banks → buff_l can't push → grant_l stays 0
        ddrif.fe_full = {BANK_NUM{1'b1}};
        repeat(2) @(posedge CLK);

        // Drive another read — handshake will complete (LQ not full).
        // At the moment arvalid=1 && arready=1, we also have
        // request_l=1 (from queued entries) but grant_l=0 (buff_l valid).
        drive_read_request(32'h0023_0200, 3'd2, 3'd1);
        repeat(4) @(posedge CLK);

        // Release
        ddrif.fe_full = '0;
        repeat(12) @(posedge CLK);
    endtask

    // TEST 48: Arbiter pri=1 with only request_s (rqst_select[~pri]=rqst_select[0]=request_s)
    //   The RR condition is (pri && rqst_select[~pri]) || (~pri && rqst_select[pri]).
    //   To hit the first half independently: pri=1, request_s=1, request_l=0.
    //   After reset pri=0. One write makes arbiter grant STQ (pri flips to 1).
    //   Then send another write only (no reads) → pri=1, rqst_select={0,1}.
    task test_arb_pri1_request_s_only;
        test_case = "Arb pri=1, only request_s";
        $display("\n[TEST] %s", test_case);

        // After reset, pri=0.
        // Drive a read first to make pri toggle from 0→1.
        // (pri=0, rqst_select has request_l=1 → ~pri=1, rqst_select[1]=request_l=1
        //  → second half fires, pri toggles to 1)
        drive_read_request(32'h0024_0000, 3'd0, 3'd1);
        repeat(6) @(posedge CLK);  // drain

        // Now pri=1. Drive only writes — request_s=1, request_l=0.
        // rqst_select = {0,1}. First half: pri=1 && rqst_select[0]=request_s=1 → TRUE.
        drive_write_request(32'h0024_1000, 3'd1, 3'd1);
        repeat(4) @(posedge CLK);
        drive_write_request(32'h0024_1100, 3'd2, 3'd1);
        repeat(4) @(posedge CLK);
        drive_write_request(32'h0024_1200, 3'd3, 3'd1);
        repeat(8) @(posedge CLK);
    endtask

    // TEST 49: Arbiter grant_s blocked by buff_s.valid
    //   (pri && rqst_select[~pri] && ~buff_s.valid) at 66.66%.
    //   Need: pri=1, rqst_select[0]=request_s=1, buff_s.valid=1 (so ~buff_s.valid=F).
    //   Drive a write, let arbiter grant into buff_s. Block BQ with fe_full
    //   so buff_s stays valid. Drive another write so request_s=1.
    //   Now pri=1, request_s=1, buff_s.valid=1 → condition evaluates FALSE.
    task test_grant_s_blocked_buff_valid;
        test_case = "grant_s Blocked (buff_s.valid=1)";
        $display("\n[TEST] %s", test_case);

        // Get pri to 1: drive a read first.
        drive_read_request(32'h0025_0000, 3'd0, 3'd1);
        repeat(6) @(posedge CLK);  // drain, pri toggled to 1

        // Drive a write → goes into STQ, arbiter grants into buff_s.
        drive_write_request(32'h0025_1000, 3'd1, 3'd1);
        repeat(2) @(posedge CLK);

        // Block all banks — buff_s can't push, stays valid.
        ddrif.fe_full = {BANK_NUM{1'b1}};
        repeat(2) @(posedge CLK);

        // Drive another write — STQ has 2nd entry, request_s=1.
        // But buff_s.valid=1 → ~buff_s.valid=0 → grant_s condition is FALSE.
        drive_write_request(32'h0025_1100, 3'd2, 3'd1);

        // Sustain: pri=1, request_s=1, buff_s.valid=1 for several cycles.
        repeat(8) @(posedge CLK);

        // Release
        ddrif.fe_full = '0;
        repeat(12) @(posedge CLK);
    endtask

    // TEST 50: Neither Queue Requesting (both halves of RR OR false)
    //   Exercises: pri=1,rqst_select[0]=0 AND pri=0,rqst_select[1]=0.
    //   Both sub-conditions of the OR are false → condition evaluates FALSE.
    //   Just idle after reset with no requests.
    task test_no_requests;
        test_case = "No Requests (RR OR both false)";
        $display("\n[TEST] %s", test_case);

        // Idle — neither queue requests. rqst_select={0,0}.
        // pri=0: first half: pri=0 → F. second half: ~pri=1 && rqst_select[0]=0 → F.
        repeat(6) @(posedge CLK);

        // Now flip pri to 1 by sending and draining one read.
        drive_read_request(32'h0026_0000, 3'd0, 3'd1);
        repeat(8) @(posedge CLK);  // fully drain, pri=1

        // Idle again. pri=1: first half: pri=1 && rqst_select[0]=0 → F.
        // second half: ~pri=0 → F. Both false.
        repeat(6) @(posedge CLK);
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

        // ============================================================
        // CONSTRAINED RANDOM TESTS
        // ============================================================

        // Test 11: Random mixed read/write traffic
        reset_dut();
        test_random_mixed();
        repeat(5) @(posedge CLK);

        // Test 12: Write-heavy random burst
        reset_dut();
        test_random_write_heavy();
        repeat(5) @(posedge CLK);

        // Test 13: Read-heavy random burst
        reset_dut();
        test_random_read_heavy();
        repeat(5) @(posedge CLK);

        // Test 14: Simultaneous random R+W streams
        reset_dut();
        test_random_simultaneous();
        repeat(5) @(posedge CLK);

        // Test 15: Fill both queues with random data, overflow, drain
        reset_dut();
        test_random_fill_overflow();
        repeat(5) @(posedge CLK);

        // Test 16: Random traffic with random BQ backpressure
        reset_dut();
        test_random_backpressure();
        repeat(5) @(posedge CLK);

        // Test 17: Random burst sequence (variable length)
        reset_dut();
        test_random_burst_seq();
        repeat(5) @(posedge CLK);

        // ============================================================
        // CONDITION COVERAGE TESTS
        // ============================================================

        // Test 18: LQ simultaneous enqueue + dequeue
        reset_dut();
        test_lq_simultaneous_enq_deq();
        repeat(5) @(posedge CLK);

        // Test 19: Only STQ requesting (no reads)
        reset_dut();
        test_only_stq_requesting();
        repeat(5) @(posedge CLK);

        // Test 20: Only LQ requesting (no writes)
        reset_dut();
        test_only_lq_requesting();
        repeat(5) @(posedge CLK);

        // Test 21: buff_l.valid stall blocks grant_l
        reset_dut();
        test_buff_l_stall();
        repeat(5) @(posedge CLK);

        // Test 22: buff_s.valid stall blocks grant_s
        reset_dut();
        test_buff_s_stall();
        repeat(5) @(posedge CLK);

        // Test 23: Partial fe_full — target bank blocked
        reset_dut();
        test_partial_fe_full();
        repeat(5) @(posedge CLK);

        // Test 24: Interleaved W/R toggling pri_bq
        reset_dut();
        test_interleaved_wr();
        repeat(5) @(posedge CLK);

        // Test 25: Valid held while queue full
        reset_dut();
        test_valid_while_full();
        repeat(5) @(posedge CLK);

        // Test 26: Fill+drain both queues to empty
        reset_dut();
        test_fill_drain_both();
        repeat(5) @(posedge CLK);

        // Test 27: Both arbiter buffers active simultaneously
        reset_dut();
        test_both_buffers_active();
        repeat(5) @(posedge CLK);

        // Test 28: Stalled buffers + priority switch
        reset_dut();
        test_stalled_buffer_switch();
        repeat(5) @(posedge CLK);

        // ============================================================
        // BRANCH/CONDITION/STATEMENT COVERAGE TESTS (ROUND 2)
        // ============================================================

        // Test 29: Early valid drop — awready=1 && awvalid=0 comb path
        reset_dut();
        test_early_valid_drop();
        repeat(5) @(posedge CLK);

        // Test 30: Valid pulse — no handshake completes
        reset_dut();
        test_valid_pulse_no_handshake();
        repeat(5) @(posedge CLK);

        // Test 31: Handshake while arbiter grants opposite queue
        reset_dut();
        test_handshake_during_opposite_grant();
        repeat(5) @(posedge CLK);

        // Test 32: Repeated fill-drain for multiple pointer wraps
        reset_dut();
        test_repeated_fill_drain();
        repeat(5) @(posedge CLK);

        // Test 33: Single entry lifecycle (request 0→1→0)
        reset_dut();
        test_single_entry_lifecycle();
        repeat(5) @(posedge CLK);

        // Test 34: Sustained dual-queue traffic (all pri transitions)
        reset_dut();
        test_sustained_dual_traffic();
        repeat(5) @(posedge CLK);

        // Test 35: Dynamic fe_full toggle during buffer push
        reset_dut();
        test_fe_full_toggle();
        repeat(5) @(posedge CLK);

        // Test 36: Maximum pressure — full queues + all banks blocked
        reset_dut();
        test_max_pressure();
        repeat(5) @(posedge CLK);

        // Test 37: Idle with empty queues
        reset_dut();
        test_idle_empty();
        repeat(5) @(posedge CLK);

        // Test 38: Alternating priority grants
        reset_dut();
        test_alternating_priority();
        repeat(5) @(posedge CLK);

        // Test 39: Grant denied — wrong priority
        reset_dut();
        test_grant_denied_wrong_pri();
        repeat(5) @(posedge CLK);

        // Test 40: Rapid fire same queue
        reset_dut();
        test_rapid_fire_same_queue();
        repeat(5) @(posedge CLK);

        // Test 41: Write-only stress
        reset_dut();
        test_write_only_stress();
        repeat(5) @(posedge CLK);

        // Test 42: Read-only stress
        reset_dut();
        test_read_only_stress();
        repeat(5) @(posedge CLK);

        // Test 43: Partial fill + drain (non-power-of-2)
        reset_dut();
        test_partial_fill_drain();
        repeat(5) @(posedge CLK);

        // Test 44: Both queues stall on same bank
        reset_dut();
        test_both_stall_same_bank();
        repeat(5) @(posedge CLK);

        // ============================================================
        // TARGETED CONDITION COVERAGE TESTS (ROUND 3)
        // ============================================================

        // Test 45: arvalid held at full queue (occ/taken==DEPTH, ready=0)
        reset_dut();
        test_valid_at_full_no_ready();
        repeat(5) @(posedge CLK);

        // Test 46: LQ request_l=1 but grant_l=0
        reset_dut();
        test_lq_request_no_grant();
        repeat(5) @(posedge CLK);

        // Test 47: LQ sim R/W with grant_l blocked
        reset_dut();
        test_lq_simrw_grant_blocked();
        repeat(5) @(posedge CLK);

        // Test 48: Arb pri=1, only request_s (first half of RR OR)
        reset_dut();
        test_arb_pri1_request_s_only();
        repeat(5) @(posedge CLK);

        // Test 49: grant_s blocked by buff_s.valid
        reset_dut();
        test_grant_s_blocked_buff_valid();
        repeat(5) @(posedge CLK);

        // Test 50: No requests (both halves of RR OR false)
        reset_dut();
        test_no_requests();
        repeat(5) @(posedge CLK);

        $stop;
    end

endprogram
