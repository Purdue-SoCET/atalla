`include "ddr_controller_if.sv"
`timescale 1 ns / 1 ps

module command_FSM_nb_tb();
    import dram_pkg::*;

    logic CLK, nRST;
    localparam PERIOD = 2;  // 2 ns clock period (500 MHz)
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
    cmd_fsm DUT(CLK, nRST, ddrif.command_fsm);

    // HELPER TASKS:

    // Reset Task
    task reset_dut;
        nRST = 1'b0;
        ddrif.bq_ready = '0;
        ddrif.bq_slot  = '{default: '0};
        ddrif.be_arb   = '0;
        ddrif.fsm_ref  = '0;
        ddrif.bq_bg    = '0;
        ddrif.bq_b     = '0;
        repeat(2) @(posedge CLK);
        nRST = 1'b1;
        @(posedge CLK);
    endtask

    // Drive a request into a specific bank queue slot
    task drive_bq_request(
        input int                        bank,
        input logic [ROW_BITS-1:0]       row,
        input logic [COLUMN_BITS-1:0]    col,
        input logic                      write,
        input logic [$clog2(ID_NUM)-1:0] id
    );
        ddrif.bq_slot[bank].row     = row;
        ddrif.bq_slot[bank].column  = col;
        ddrif.bq_slot[bank].write   = write;
        ddrif.bq_slot[bank].id_addr = id;
        ddrif.bq_ready[bank]        = 1'b1;
        ddrif.bq_bg                 = bank[3:2];
        ddrif.bq_b                  = bank[1:0];
    endtask

    // Clear a pending bank queue request
    task clear_bq_request(input int bank);
        ddrif.bq_ready[bank] = 1'b0;
        ddrif.bq_slot[bank]  = '0;
    endtask

    // Grant backend arbitration to a specific bank for one cycle
    task grant_bank(input int bank);
        ddrif.be_arb = (1 << bank);
        @(posedge CLK); #1;
        ddrif.be_arb = '0;
    endtask

    //==========================================================================
    // TRANSITION TESTS — each task exercises specific FSM edges
    //==========================================================================

    // T1: Read Closed Row
    //   IDLE -> ACT -> ACTing -> FSM_READ -> READing -> IDLE
    task test_read_closed_row(input int bank);
        test_case = $sformatf("T1 Read Closed Row (Bank %0d)", bank);
        drive_bq_request(.bank(bank), .row(15'h0010), .col(10'h020), .write(1'b0), .id(3'd1));
        @(posedge CLK);
        grant_bank(bank); // ACT -> ACTing
        repeat(tRCD + 1) @(posedge CLK);
        grant_bank(bank); // FSM_READ -> READing
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T2: Read Open Row (row 0x0010 already open)
    //   IDLE -> FSM_READ -> READing -> IDLE
    task test_read_open_row(input int bank);
        test_case = $sformatf("T2 Read Open Row (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        drive_bq_request(.bank(bank), .row(15'h0010), .col(10'h040), .write(1'b0), .id(3'd2));
        @(posedge CLK);
        grant_bank(bank); // FSM_READ -> READing
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T3: Write Closed Row
    //   IDLE -> ACT -> ACTing -> FSM_WRITE -> WRITEing -> IDLE
    task test_write_closed_row(input int bank);
        test_case = $sformatf("T3 Write Closed Row (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        drive_bq_request(.bank(bank), .row(15'h0020), .col(10'h010), .write(1'b1), .id(3'd5));
        @(posedge CLK);
        grant_bank(bank); // ACT -> ACTing
        repeat(tRCD + 1) @(posedge CLK);
        grant_bank(bank); // FSM_WRITE -> WRITEing
        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T4: Write Open Row (row 0x0020 already open)
    //   IDLE -> FSM_WRITE -> WRITEing -> IDLE
    task test_write_open_row(input int bank);
        test_case = $sformatf("T4 Write Open Row (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        drive_bq_request(.bank(bank), .row(15'h0020), .col(10'h030), .write(1'b1), .id(3'd6));
        @(posedge CLK);
        grant_bank(bank); // FSM_WRITE -> WRITEing
        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T5: Row Miss Read — open row A, then request row B read
    //   (row A open) IDLE -> PRE -> PREing -> ACT -> ACTing -> FSM_READ -> READing -> IDLE
    task test_row_miss_read(input int bank);
        test_case = $sformatf("T5 Row Miss Read (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        // First open row 0x00AA
        drive_bq_request(.bank(bank), .row(15'h00AA), .col(10'h001), .write(1'b0), .id(3'd0));
        @(posedge CLK);
        grant_bank(bank); // ACT -> ACTing
        repeat(tRCD + 1) @(posedge CLK);
        grant_bank(bank); // FSM_READ -> READing
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
        @(posedge CLK);
        // Now request different row 0x00BB — triggers PRE then ACT
        drive_bq_request(.bank(bank), .row(15'h00BB), .col(10'h002), .write(1'b0), .id(3'd1));
        @(posedge CLK);
        // IDLE -> PRE (row miss)
        grant_bank(bank); // PRE -> PREing
        repeat(tRP + 1) @(posedge CLK);
        // PREing -> ACT (bqready still high)
        grant_bank(bank); // ACT -> ACTing
        repeat(tRCD + 1) @(posedge CLK);
        // ACTing -> FSM_READ
        grant_bank(bank); // FSM_READ -> READing
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T6: Row Miss Write — open row A, then request row B write
    //   (row A open) IDLE -> PRE -> PREing -> ACT -> ACTing -> FSM_WRITE -> WRITEing -> IDLE
    task test_row_miss_write(input int bank);
        test_case = $sformatf("T6 Row Miss Write (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        // First open row 0x00CC
        drive_bq_request(.bank(bank), .row(15'h00CC), .col(10'h001), .write(1'b1), .id(3'd2));
        @(posedge CLK);
        grant_bank(bank); // ACT -> ACTing
        repeat(tRCD + 1) @(posedge CLK);
        grant_bank(bank); // FSM_WRITE -> WRITEing
        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
        @(posedge CLK);
        // Request different row 0x00DD — triggers PRE then ACT
        drive_bq_request(.bank(bank), .row(15'h00DD), .col(10'h002), .write(1'b1), .id(3'd3));
        @(posedge CLK);
        // IDLE -> PRE (row miss)
        grant_bank(bank); // PRE -> PREing
        repeat(tRP + 1) @(posedge CLK);
        // PREing -> ACT
        grant_bank(bank); // ACT -> ACTing
        repeat(tRCD + 1) @(posedge CLK);
        // ACTing -> FSM_WRITE
        grant_bank(bank); // FSM_WRITE -> WRITEing
        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T7: Refresh with no row open
    //   IDLE -> REF -> REFing -> IDLE
    task test_refresh_no_row(input int bank);
        test_case = $sformatf("T7 Refresh No Row (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        ddrif.fsm_ref = 1'b1;
        @(posedge CLK);
        ddrif.fsm_ref = 1'b0;
        @(posedge CLK); // IDLE -> REF
        grant_bank(bank); // REF -> REFing
        repeat(tRFC + 1) @(posedge CLK);
    endtask

    // T8: Refresh with row open — requires precharge first
    //   (row open) IDLE -> PRE -> PREing -> REF -> REFing -> IDLE
    task test_refresh_row_open(input int bank);
        test_case = $sformatf("T8 Refresh Row Open (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        // First open a row
        drive_bq_request(.bank(bank), .row(15'h0055), .col(10'h005), .write(1'b0), .id(3'd4));
        @(posedge CLK);
        grant_bank(bank); // ACT -> ACTing
        repeat(tRCD + 1) @(posedge CLK);
        grant_bank(bank); // FSM_READ -> READing
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
        @(posedge CLK);
        // Row 0x0055 is now open. Assert refresh.
        ddrif.fsm_ref = 1'b1;
        @(posedge CLK);
        ddrif.fsm_ref = 1'b0;
        @(posedge CLK); // IDLE -> PRE (ref_pending, row open)
        grant_bank(bank); // PRE -> PREing
        repeat(tRP + 1) @(posedge CLK);
        // PREing -> REF (ref_pending)
        grant_bank(bank); // REF -> REFing
        repeat(tRFC + 1) @(posedge CLK);
        // REFing -> IDLE
    endtask

    // T9: PREing -> IDLE (precharge done, no bqready, no ref_pending)
    task test_preing_to_idle(input int bank);
        test_case = $sformatf("T9 PREing to IDLE (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        // Open a row
        drive_bq_request(.bank(bank), .row(15'h0066), .col(10'h006), .write(1'b0), .id(3'd5));
        @(posedge CLK);
        grant_bank(bank); // ACT
        repeat(tRCD + 1) @(posedge CLK);
        grant_bank(bank); // READ
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
        @(posedge CLK);
        // Row open, request a different row to trigger PRE
        drive_bq_request(.bank(bank), .row(15'h0077), .col(10'h007), .write(1'b0), .id(3'd6));
        @(posedge CLK);
        // IDLE -> PRE (row miss)
        // Now clear the request before PREing finishes
        clear_bq_request(bank);
        grant_bank(bank); // PRE -> PREing
        repeat(tRP + 1) @(posedge CLK);
        // PREing done: no ref_pending, no bqready -> IDLE
    endtask

    // T10: Arbiter wait — FSM sits in ACT without arb for multiple cycles
    //   ACT -> ACT -> ACT (wait) -> ACTing
    task test_arb_wait_act(input int bank);
        test_case = $sformatf("T10 Arb Wait ACT (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        drive_bq_request(.bank(bank), .row(15'h0088), .col(10'h008), .write(1'b0), .id(3'd7));
        @(posedge CLK); // IDLE -> ACT
        // Wait several cycles without grant
        repeat(5) @(posedge CLK);
        grant_bank(bank); // ACT -> ACTing
        repeat(tRCD + 1) @(posedge CLK);
        grant_bank(bank); // FSM_READ -> READing
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T11: Arbiter wait — FSM sits in FSM_READ without arb
    task test_arb_wait_read(input int bank);
        test_case = $sformatf("T11 Arb Wait READ (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        // Open row first
        drive_bq_request(.bank(bank), .row(15'h0099), .col(10'h009), .write(1'b0), .id(3'd0));
        @(posedge CLK);
        grant_bank(bank); // ACT
        repeat(tRCD + 1) @(posedge CLK);
        // Now in FSM_READ — delay grant
        repeat(5) @(posedge CLK);
        grant_bank(bank); // FSM_READ -> READing
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T12: Arbiter wait — FSM sits in FSM_WRITE without arb
    task test_arb_wait_write(input int bank);
        test_case = $sformatf("T12 Arb Wait WRITE (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        drive_bq_request(.bank(bank), .row(15'h0099), .col(10'h00A), .write(1'b1), .id(3'd1));
        @(posedge CLK);
        // Row 0x0099 already open from T11 — IDLE -> FSM_WRITE (row hit)
        repeat(5) @(posedge CLK);
        grant_bank(bank); // FSM_WRITE -> WRITEing
        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T13: Arbiter wait — FSM sits in PRE without arb
    task test_arb_wait_pre(input int bank);
        test_case = $sformatf("T13 Arb Wait PRE (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        // Row 0x0099 still open. Request different row to trigger PRE.
        drive_bq_request(.bank(bank), .row(15'h00EE), .col(10'h00B), .write(1'b0), .id(3'd2));
        @(posedge CLK); // IDLE -> PRE (row miss)
        // Delay grant
        repeat(5) @(posedge CLK);
        grant_bank(bank); // PRE -> PREing
        repeat(tRP + 1) @(posedge CLK);
        // PREing -> ACT
        grant_bank(bank); // ACT -> ACTing
        repeat(tRCD + 1) @(posedge CLK);
        grant_bank(bank); // FSM_READ -> READing
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T14: Arbiter wait — FSM sits in REF without arb
    task test_arb_wait_ref(input int bank);
        test_case = $sformatf("T14 Arb Wait REF (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        ddrif.fsm_ref = 1'b1;
        @(posedge CLK);
        ddrif.fsm_ref = 1'b0;
        @(posedge CLK); // IDLE -> REF
        // Delay grant
        repeat(5) @(posedge CLK);
        grant_bank(bank); // REF -> REFing
        repeat(tRFC + 1) @(posedge CLK);
    endtask

    // T15: IDLE stays IDLE when nothing pending
    task test_idle_stays(input int bank);
        test_case = $sformatf("T15 IDLE Stays (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        // No bqready, no ref — FSM should remain IDLE
        repeat(5) @(posedge CLK);
    endtask

    // T16: Read after Write on same open row
    //   (row open) IDLE -> FSM_WRITE -> WRITEing -> IDLE -> FSM_READ -> READing -> IDLE
    task test_read_after_write(input int bank);
        test_case = $sformatf("T16 Read After Write (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        drive_bq_request(.bank(bank), .row(15'h0010), .col(10'h060), .write(1'b1), .id(3'd3));
        @(posedge CLK);
        grant_bank(bank); // FSM_WRITE -> WRITEing
        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
        @(posedge CLK);
        drive_bq_request(.bank(bank), .row(15'h0010), .col(10'h080), .write(1'b0), .id(3'd4));
        @(posedge CLK);
        grant_bank(bank); // FSM_READ -> READing
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T17: Write after Read on same open row
    task test_write_after_read(input int bank);
        test_case = $sformatf("T17 Write After Read (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        drive_bq_request(.bank(bank), .row(15'h0010), .col(10'h050), .write(1'b0), .id(3'd7));
        @(posedge CLK);
        grant_bank(bank); // FSM_READ -> READing
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
        @(posedge CLK);
        drive_bq_request(.bank(bank), .row(15'h0010), .col(10'h070), .write(1'b1), .id(3'd0));
        @(posedge CLK);
        grant_bank(bank); // FSM_WRITE -> WRITEing
        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T18: Refresh during pending request (ref_pending latches while in IDLE with bqready)
    task test_refresh_priority(input int bank);
        test_case = $sformatf("T18 Refresh Priority (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        drive_bq_request(.bank(bank), .row(15'h0011), .col(10'h011), .write(1'b0), .id(3'd5));
        ddrif.fsm_ref = 1'b1;
        @(posedge CLK);
        ddrif.fsm_ref = 1'b0;
        @(posedge CLK); // ref_pending takes priority -> REF (no row open)
        grant_bank(bank); // REF -> REFing
        repeat(tRFC + 1) @(posedge CLK);
        // REFing -> IDLE, then bqready still high -> ACT
        @(posedge CLK);
        grant_bank(bank); // ACT -> ACTing
        repeat(tRCD + 1) @(posedge CLK);
        grant_bank(bank); // FSM_READ -> READing
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T19: ACTing -> FSM_WRITE (write request after activate)
    task test_acting_to_write(input int bank);
        test_case = $sformatf("T19 ACTing to WRITE (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        drive_bq_request(.bank(bank), .row(15'h0022), .col(10'h022), .write(1'b1), .id(3'd6));
        @(posedge CLK);
        grant_bank(bank); // ACT -> ACTing
        repeat(tRCD + 1) @(posedge CLK);
        // ACTing -> FSM_WRITE (fsm_rw = 1)
        grant_bank(bank); // FSM_WRITE -> WRITEing
        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T20: ACTing -> FSM_READ (read request after activate)
    task test_acting_to_read(input int bank);
        test_case = $sformatf("T20 ACTing to READ (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        drive_bq_request(.bank(bank), .row(15'h0033), .col(10'h033), .write(1'b0), .id(3'd7));
        @(posedge CLK);
        grant_bank(bank); // ACT -> ACTing
        repeat(tRCD + 1) @(posedge CLK);
        // ACTing -> FSM_READ (fsm_rw = 0)
        grant_bank(bank); // FSM_READ -> READing
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    //==========================================================================
    // T21: Multi-bank concurrent commands interrupted by refresh
    //   Multiple FSMs are in various mid-command states when fsm_ref fires.
    //   Each FSM must finish its current command, then PRE (if row open), then REF.
    //==========================================================================
    task test_multibank_refresh_interrupt;
        test_case = "T21 Multi-Bank Refresh Interrupt";
        $display("\n[TEST] %s", test_case);
        reset_dut();

        // --- Phase 1: Launch commands on 6 banks simultaneously ---
        drive_bq_request(.bank(0),  .row(15'h0A00), .col(10'h001), .write(1'b0), .id(3'd0));
        drive_bq_request(.bank(3),  .row(15'h0B00), .col(10'h002), .write(1'b1), .id(3'd1));
        drive_bq_request(.bank(7),  .row(15'h0C00), .col(10'h003), .write(1'b0), .id(3'd2));
        drive_bq_request(.bank(10), .row(15'h0D00), .col(10'h004), .write(1'b1), .id(3'd3));
        drive_bq_request(.bank(12), .row(15'h0E00), .col(10'h005), .write(1'b0), .id(3'd4));
        @(posedge CLK);

        // Grant ACT for banks 0, 3, 7, 10
        grant_bank(0);
        grant_bank(3);
        grant_bank(7);
        grant_bank(10);

        // Wait for ACTing timers
        repeat(tRCD + 1) @(posedge CLK);

        // Grant bank 7 READ and bank 10 WRITE
        grant_bank(7);
        grant_bank(10);

        // --- Phase 2: Fire refresh while banks are mid-command ---
        $display("[INFO] Asserting fsm_ref — all FSMs must eventually refresh");
        ddrif.fsm_ref = 1'b1;
        @(posedge CLK);
        ddrif.fsm_ref = 1'b0;

        // --- Phase 3: Let banks 0 and 3 finish their pending commands ---
        repeat(2) @(posedge CLK);
        grant_bank(0);  // FSM_READ
        grant_bank(3);  // FSM_WRITE

        // Grant bank 12 its pending ACT
        grant_bank(12);

        // Wait for all timing states to expire
        repeat(tBURST + tWR + 5) @(posedge CLK);

        // Bank 12 ACTing finished — grant READ
        grant_bank(12);
        repeat(tRL + tBURST + 2) @(posedge CLK);

        // --- Phase 4: All banks see ref_pending ---
        clear_bq_request(0);
        clear_bq_request(3);
        clear_bq_request(7);
        clear_bq_request(10);
        clear_bq_request(12);
        repeat(2) @(posedge CLK);

        // Banks with open rows -> PRE
        grant_bank(0);
        grant_bank(3);
        grant_bank(7);
        grant_bank(10);
        grant_bank(12);

        repeat(tRP + 1) @(posedge CLK);

        // All -> REF, grant for REFing
        grant_bank(0);
        grant_bank(3);
        grant_bank(7);
        grant_bank(10);
        grant_bank(12);
        grant_bank(15);

        repeat(tRFC + 1) @(posedge CLK);

        $display("[INFO] Multi-bank refresh complete — all FSMs should be IDLE");
        repeat(5) @(posedge CLK);
    endtask

    //==========================================================================
    // Toggle Coverage Tests — exercise all bits of row, column, id, write
    //==========================================================================

    // T22: Walking-1 on row bits (read path)
    task test_toggle_row_bits(input int bank);
        test_case = $sformatf("T22 Toggle Row Bits (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        for (int i = 0; i < ROW_BITS; i++) begin
            reset_dut();
            drive_bq_request(.bank(bank), .row(15'b1 << i), .col(10'h000), .write(1'b0), .id(3'd0));
            @(posedge CLK);
            grant_bank(bank); // ACT
            repeat(tRCD + 1) @(posedge CLK);
            grant_bank(bank); // FSM_READ
            repeat(tRL + tBURST + 1) @(posedge CLK);
            @(posedge CLK);
            clear_bq_request(bank);
        end
    endtask

    // T23: Walking-1 on column bits (write path)
    task test_toggle_col_bits(input int bank);
        test_case = $sformatf("T23 Toggle Col Bits (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        for (int i = 0; i < COLUMN_BITS; i++) begin
            reset_dut();
            drive_bq_request(.bank(bank), .row(15'h0001), .col(10'b1 << i), .write(1'b1), .id(3'd0));
            @(posedge CLK);
            grant_bank(bank); // ACT
            repeat(tRCD + 1) @(posedge CLK);
            grant_bank(bank); // FSM_WRITE
            repeat(tBURST + tWR + 2) @(posedge CLK);
            @(posedge CLK);
            clear_bq_request(bank);
        end
    endtask

    // T24: All ID values (0-7) — toggles all 3 bits of id_addr
    task test_toggle_id_bits(input int bank);
        test_case = $sformatf("T24 Toggle ID Bits (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        for (int i = 0; i < ID_NUM; i++) begin
            reset_dut();
            drive_bq_request(.bank(bank), .row(15'h0002), .col(10'h010), .write(1'b0), .id(i[2:0]));
            @(posedge CLK);
            grant_bank(bank); // ACT
            repeat(tRCD + 1) @(posedge CLK);
            grant_bank(bank); // FSM_READ
            repeat(tRL + tBURST + 1) @(posedge CLK);
            @(posedge CLK);
            clear_bq_request(bank);
        end
    endtask

    // T25: Alternating bit patterns — covers bit-pair toggles
    task test_toggle_alternating(input int bank);
        test_case = $sformatf("T25 Toggle Alternating (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        // Pattern A: 0x5555 / 0x155 / id=5 / write=0
        reset_dut();
        drive_bq_request(.bank(bank), .row(15'h5555), .col(10'h155), .write(1'b0), .id(3'd5));
        @(posedge CLK);
        grant_bank(bank); // ACT
        repeat(tRCD + 1) @(posedge CLK);
        grant_bank(bank); // FSM_READ
        repeat(tRL + tBURST + 1) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);

        // Pattern B: 0x2AAA / 0x2AA / id=2 / write=1
        reset_dut();
        drive_bq_request(.bank(bank), .row(15'h2AAA), .col(10'h2AA), .write(1'b1), .id(3'd2));
        @(posedge CLK);
        grant_bank(bank); // ACT
        repeat(tRCD + 1) @(posedge CLK);
        grant_bank(bank); // FSM_WRITE
        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    // T26: All-ones patterns — ensures MSBs toggle high
    task test_toggle_all_ones(input int bank);
        test_case = $sformatf("T26 Toggle All-Ones (Bank %0d)", bank);
        $display("\n[TEST] %s", test_case);
        reset_dut();
        drive_bq_request(.bank(bank), .row(15'h7FFF), .col(10'h3FF), .write(1'b1), .id(3'd7));
        @(posedge CLK);
        grant_bank(bank); // ACT
        repeat(tRCD + 1) @(posedge CLK);
        grant_bank(bank); // FSM_WRITE
        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);
        clear_bq_request(bank);
    endtask

    //==========================================================================
    // T27: All 16 banks active simultaneously — round robin arb
    //   All bank queues populated at once with varied commands (no refresh).
    //   Banks are acked one at a time in ascending round-robin order through
    //   every stage of their command sequence.
    //==========================================================================
    task test_all_banks_round_robin;
        test_case = "T27 All Banks Round Robin";
        reset_dut();

        // --- Phase 1: Populate all 16 bank queues ---
        // Even banks get reads to unique rows, odd banks get writes
        for (int b = 0; b < BANK_NUM; b++) begin
            drive_bq_request(
                .bank  (b),
                .row   (15'(b * 'h100 + 'h10)), // unique row per bank
                .col   (10'(b * 'h20)),          // unique col per bank
                .write (b[0]),                    // even=read, odd=write
                .id    (b[$clog2(ID_NUM)-1:0])    // id = bank[2:0]
            );
        end
        @(posedge CLK);

        // All 16 FSMs should now be in ACT (closed rows after reset)

        // --- Phase 2: Round-robin ACT grants ---
        for (int b = 0; b < BANK_NUM; b++) begin
            grant_bank(b); // ACT -> ACTing
        end

        // Wait for all ACTing timers to expire
        repeat(tRCD + 1) @(posedge CLK);

        // --- Phase 3: Round-robin READ/WRITE grants ---
        // Even banks are in FSM_READ, odd banks are in FSM_WRITE
        for (int b = 0; b < BANK_NUM; b++) begin
            grant_bank(b); // FSM_READ/FSM_WRITE -> READing/WRITEing
        end

        // Wait for the longest timer to expire
        // Write timer: tBURST + tWR + 2 = 18, Read timer: tRL + tBURST + 1 = 16
        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);

        // All FSMs should be back in IDLE, pop should have fired for each
        for (int b = 0; b < BANK_NUM; b++) begin
            clear_bq_request(b);
        end

        // --- Phase 4: Second wave — drive new requests to open rows ---
        // Same rows are still activated, so these should be row hits
        // (IDLE -> FSM_READ/FSM_WRITE directly, no ACT needed)
        for (int b = 0; b < BANK_NUM; b++) begin
            drive_bq_request(
                .bank  (b),
                .row   (15'(b * 'h100 + 'h10)), // same row = row hit
                .col   (10'(b * 'h20 + 'h10)),  // different column
                .write (~b[0]),                   // flip: even=write, odd=read
                .id    (~b[$clog2(ID_NUM)-1:0])   // complement id
            );
        end
        @(posedge CLK);

        // FSMs should go directly to FSM_READ/FSM_WRITE (row hit)
        // Round-robin grants in reverse order for variety
        for (int b = BANK_NUM - 1; b >= 0; b--) begin
            grant_bank(b);
        end

        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);

        for (int b = 0; b < BANK_NUM; b++) begin
            clear_bq_request(b);
        end

        // --- Phase 5: Third wave — different rows to trigger row miss ---
        // Each bank has a row open; drive a request to a DIFFERENT row
        // (IDLE -> PRE -> PREing -> ACT -> ACTing -> READ/WRITE -> ...ing -> IDLE)
        for (int b = 0; b < BANK_NUM; b++) begin
            drive_bq_request(
                .bank  (b),
                .row   (15'(b * 'h100 + 'h20)), // different row = row miss
                .col   (10'(b * 'h20 + 'h08)),
                .write (b[0]),
                .id    (b[$clog2(ID_NUM)-1:0])
            );
        end
        @(posedge CLK);

        // All FSMs should be in PRE (row miss). Grant PRE round-robin.
        for (int b = 0; b < BANK_NUM; b++) begin
            grant_bank(b); // PRE -> PREing
        end

        repeat(tRP + 1) @(posedge CLK);

        // All FSMs now in ACT (PREing -> ACT since bqready is still high)
        for (int b = 0; b < BANK_NUM; b++) begin
            grant_bank(b); // ACT -> ACTing
        end

        repeat(tRCD + 1) @(posedge CLK);

        // Grant READ/WRITE
        for (int b = 0; b < BANK_NUM; b++) begin
            grant_bank(b);
        end

        repeat(tBURST + tWR + 2) @(posedge CLK);
        @(posedge CLK);

        for (int b = 0; b < BANK_NUM; b++) begin
            clear_bq_request(b);
        end

        repeat(5) @(posedge CLK);
    endtask

    //==========================================================================
    // Run full test suite on a single bank
    //==========================================================================
    task run_all_tests_on_bank(input int bank);
        $display("\n========== FULL SUITE: Bank %0d ==========", bank);

        // Start clean
        reset_dut();

        // Basic read/write paths (closed row)
        test_read_closed_row(bank);    // IDLE->ACT->ACTing->READ->READing->IDLE
        repeat(3) @(posedge CLK);

        test_read_open_row(bank);      // IDLE->READ->READing->IDLE (row hit)
        repeat(3) @(posedge CLK);

        test_read_after_write(bank);   // IDLE->WRITE->WRITEing->IDLE->READ->READing->IDLE
        repeat(3) @(posedge CLK);

        test_write_after_read(bank);   // IDLE->READ->READing->IDLE->WRITE->WRITEing->IDLE
        repeat(3) @(posedge CLK);

        reset_dut();

        test_write_closed_row(bank);   // IDLE->ACT->ACTing->WRITE->WRITEing->IDLE
        repeat(3) @(posedge CLK);

        test_write_open_row(bank);     // IDLE->WRITE->WRITEing->IDLE (row hit)
        repeat(3) @(posedge CLK);

        // Row miss paths
        reset_dut();

        test_row_miss_read(bank);      // PRE->PREing->ACT (row miss read)
        repeat(3) @(posedge CLK);

        reset_dut();

        test_row_miss_write(bank);     // PRE->PREing->ACT (row miss write)
        repeat(3) @(posedge CLK);

        // Precharge to idle (no pending request)
        reset_dut();

        test_preing_to_idle(bank);     // PREing->IDLE
        repeat(3) @(posedge CLK);

        // Refresh paths
        reset_dut();

        test_refresh_no_row(bank);     // IDLE->REF->REFing->IDLE
        repeat(3) @(posedge CLK);

        reset_dut();

        test_refresh_row_open(bank);   // IDLE->PRE->PREing->REF->REFing->IDLE
        repeat(3) @(posedge CLK);

        reset_dut();

        test_refresh_priority(bank);   // ref_pending + bqready => refresh first
        repeat(3) @(posedge CLK);

        // Arbiter wait paths
        reset_dut();

        test_arb_wait_act(bank);       // ACT->ACT (wait)
        repeat(3) @(posedge CLK);

        test_arb_wait_read(bank);      // FSM_READ->FSM_READ (wait)
        repeat(3) @(posedge CLK);

        test_arb_wait_write(bank);     // FSM_WRITE->FSM_WRITE (wait)
        repeat(3) @(posedge CLK);

        test_arb_wait_pre(bank);       // PRE->PRE (wait)
        repeat(3) @(posedge CLK);

        reset_dut();

        test_arb_wait_ref(bank);       // REF->REF (wait)
        repeat(3) @(posedge CLK);

        // IDLE hold
        reset_dut();

        test_idle_stays(bank);         // IDLE->IDLE
        repeat(3) @(posedge CLK);

        // Explicit ACTing exit paths
        reset_dut();

        test_acting_to_read(bank);     // ACTing->FSM_READ
        repeat(3) @(posedge CLK);

        reset_dut();

        test_acting_to_write(bank);    // ACTing->FSM_WRITE
        repeat(3) @(posedge CLK);
    endtask

    // Initial Block
    initial begin
        // Run full suite on every bank (all 16 FSMs)
        for (int b = 0; b < BANK_NUM; b++) begin
            run_all_tests_on_bank(b);
        end

        // Multi-bank concurrent refresh stress test
        test_multibank_refresh_interrupt();
        repeat(5) @(posedge CLK);

        // All 16 banks active with round-robin arbitration
        test_all_banks_round_robin();
        repeat(5) @(posedge CLK);

        // Toggle coverage tests (run on banks 0 and 15 for bg/b bit diversity)
        for (int b = 0; b < BANK_NUM; b += 15) begin
            test_toggle_row_bits(b);
            test_toggle_col_bits(b);
            test_toggle_id_bits(b);
            test_toggle_alternating(b);
            test_toggle_all_ones(b);
        end

        $stop;
    end

endmodule
