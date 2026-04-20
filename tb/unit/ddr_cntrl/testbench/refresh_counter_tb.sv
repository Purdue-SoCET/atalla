`include "dram_pkg.svh"
`include "ddr_controller_if.sv"
`timescale 1ns/1ps

module refresh_counter_tb;
    import dram_pkg::*;

    logic CLK = 0, nRST;
    parameter PERIOD = 10;
    parameter N = $clog2(9 * tREFI) + 1;

    integer test_num = 0;
    integer errors   = 0;

    // clock
    always #(PERIOD/2) CLK++;

    ddr_controller_if ddrif();
    refresh_counter DUT(CLK, nRST, ddrif);

    // ----------------------------------------------------------------
    // Tasks
    // ----------------------------------------------------------------
    task reset_dut();
        begin
            nRST = 0;
            ddrif.rf_enable = 0;
            ddrif.rf_done   = 0;
            repeat(2) @(negedge CLK);
            nRST = 1;
            @(negedge CLK);
        end
    endtask

    task check_fsm_ref(
        input logic expected,
        input string msg
    );
        begin
            test_num++;
            if (ddrif.fsm_ref !== expected) begin
                $display("FAIL test %0d: %s | fsm_ref=%b, expected=%b @ T=%0t",
                         test_num, msg, ddrif.fsm_ref, expected, $time);
                errors++;
            end else begin
                $display("PASS test %0d: %s @ T=%0t", test_num, msg, $time);
            end
        end
    endtask

    // ----------------------------------------------------------------
    // Stimulus
    // ----------------------------------------------------------------
    initial begin
        // ============================================================
        // TEST 1: Reset values
        // ============================================================
        $display("\n=== TEST 1: Reset ===");
        reset_dut();
        check_fsm_ref(1'b0, "fsm_ref deasserted after reset");

        // ============================================================
        // TEST 2: Counter holds while rf_enable is low
        // ============================================================
        $display("\n=== TEST 2: Counter holds when disabled ===");
        ddrif.rf_enable = 0;
        ddrif.rf_done   = 0;
        repeat(10) @(negedge CLK);
        check_fsm_ref(1'b0, "fsm_ref stays low when counter disabled");

        // ============================================================
        // TEST 3: Counter increments when rf_enable goes high,
        //         fsm_ref asserts at tREFI
        // ============================================================
        $display("\n=== TEST 3: Normal count to tREFI ===");
        ddrif.rf_enable = 1;

        // Wait until just before the limit
        repeat(tREFI - 1) @(negedge CLK);
        check_fsm_ref(1'b0, "fsm_ref low one cycle before tREFI");

        @(negedge CLK);
        check_fsm_ref(1'b1, "fsm_ref asserts at tREFI");

        // ============================================================
        // TEST 4: rf_done when count == tREFI (not over limit)
        //         -> limit should reset to tREFI
        // ============================================================
        $display("\n=== TEST 4: rf_done at exactly tREFI ===");
        ddrif.rf_done = 1;
        @(negedge CLK);
        ddrif.rf_done = 0;

        // Counter should have been reset to 0
        check_fsm_ref(1'b0, "fsm_ref deasserted after rf_done");

        // Count up to tREFI again — limit should be full tREFI
        repeat(tREFI - 1) @(negedge CLK);
        check_fsm_ref(1'b0, "fsm_ref low before second tREFI");

        @(negedge CLK);
        check_fsm_ref(1'b1, "fsm_ref asserts at second tREFI");

        // ============================================================
        // TEST 5: rf_done when count > tREFI (overshoot)
        //         -> next limit should be reduced
        // ============================================================
        $display("\n=== TEST 5: Overshoot — rf_done after tREFI ===");
        // Let the counter overshoot by 10 cycles past tREFI
        repeat(10) @(negedge CLK);
        // count is now tREFI + 10, fsm_ref should still be high
        check_fsm_ref(1'b1, "fsm_ref still high during overshoot");

        ddrif.rf_done = 1;
        @(negedge CLK);
        ddrif.rf_done = 0;

        // Counter reset. New limit = tREFI - 10.
        check_fsm_ref(1'b0, "fsm_ref deasserted after overshoot rf_done");

        // Count up to the reduced limit (tREFI - 10 - 1 more since one cycle passed)
        repeat(tREFI - 10 - 2) @(negedge CLK);
        check_fsm_ref(1'b0, "fsm_ref low before reduced limit");

        @(negedge CLK);
        check_fsm_ref(1'b1, "fsm_ref asserts at reduced limit (tREFI-10)");

        // Complete the refresh immediately this time
        ddrif.rf_done = 1;
        @(negedge CLK);
        ddrif.rf_done = 0;

        // ============================================================
        // TEST 6: rf_done while count < tREFI (early refresh)
        //         -> limit should reset to tREFI
        // ============================================================
        $display("\n=== TEST 6: Early rf_done (count < tREFI) ===");
        // Count a few cycles
        repeat(20) @(negedge CLK);
        check_fsm_ref(1'b0, "fsm_ref low well before limit");

        ddrif.rf_done = 1;
        @(negedge CLK);
        ddrif.rf_done = 0;

        check_fsm_ref(1'b0, "fsm_ref low after early rf_done");

        // Verify limit was restored to tREFI
        repeat(tREFI - 1) @(negedge CLK);
        check_fsm_ref(1'b0, "fsm_ref low one before tREFI after early refresh");

        @(negedge CLK);
        check_fsm_ref(1'b1, "fsm_ref asserts at full tREFI after early refresh");

        // Clean up
        ddrif.rf_done = 1;
        @(negedge CLK);
        ddrif.rf_done = 0;

        // ============================================================
        // TEST 7: Disable mid-count (rf_enable goes low)
        // ============================================================
        $display("\n=== TEST 7: Disable mid-count ===");
        repeat(50) @(negedge CLK);
        ddrif.rf_enable = 0;
        repeat(20) @(negedge CLK);
        check_fsm_ref(1'b0, "fsm_ref stays low while counter frozen");

        // Re-enable and let it reach the limit
        ddrif.rf_enable = 1;
        repeat(tREFI - 50 - 1) @(negedge CLK);
        check_fsm_ref(1'b0, "fsm_ref low before reaching limit after re-enable");

        @(negedge CLK);
        check_fsm_ref(1'b1, "fsm_ref asserts after re-enable catches up");

        ddrif.rf_done = 1;
        @(negedge CLK);
        ddrif.rf_done = 0;

        // ============================================================
        // TEST 8: Reset in the middle of operation
        // ============================================================
        $display("\n=== TEST 8: Async reset mid-operation ===");
        repeat(100) @(negedge CLK);
        nRST = 0;
        @(negedge CLK);
        check_fsm_ref(1'b0, "fsm_ref deasserted after mid-op reset");
        nRST = 1;
        @(negedge CLK);

        // ============================================================
        // Summary
        // ============================================================
        $display("\n==============================");
        if (errors == 0)
            $display("ALL %0d TESTS PASSED", test_num);
        else
            $display("%0d / %0d TESTS FAILED", errors, test_num);
        $display("==============================\n");
        $stop;
    end

endmodule
