`include "dram_pkg.svh"
`include "ddr_controller_if.sv"
`timescale 1ns/1ps

module init_state_tb;
    import dram_pkg::*;

    logic CLK = 0, nRST;
    parameter PERIOD = 10;

    always #(PERIOD/2) CLK++;

    ddr_controller_if ddrif();
    init_state DUT(CLK, nRST, ddrif);

    task reset_dut();
        begin
            nRST = 0;
            ddrif.init_start = 0;
            repeat(2) @(negedge CLK);
            nRST = 1;
            @(negedge CLK);
        end
    endtask

    initial begin
        $display("\n=== Init State FSM Testbench ===");

        // Reset
        reset_dut();
        assert(ddrif.init_state == POWER_UP) else $error("Expected POWER_UP after reset");
        assert(ddrif.init_done == 0) else $error("Expected init_done=0 after reset");
        $display("T=%0t | Reset complete, state=%s", $time, ddrif.init_state.name());

        // Assert init_start to kick off the sequence
        @(negedge CLK);
        ddrif.init_start = 1;
        $display("T=%0t | init_start asserted", $time);

        // Monitor state transitions until init_done
        fork
            begin : WATCHDOG
                repeat(5000) @(posedge CLK);
                $error("TIMEOUT: init_done never asserted within 5000 cycles");
                $stop;
            end

            begin : MONITOR
                dram_state_t prev_state;
                prev_state = POWER_UP;
                forever begin
                    @(posedge CLK);
                    if (ddrif.init_state != prev_state) begin
                        $display("T=%0t | State transition: %s -> %s",
                                 $time, prev_state.name(), ddrif.init_state.name());
                        prev_state = ddrif.init_state;
                    end
                    if (ddrif.init_done) begin
                        $display("T=%0t | init_done asserted in state %s",
                                 $time, ddrif.init_state.name());
                        disable WATCHDOG;
                        disable MONITOR;
                    end
                end
            end
        join

        // Let it sit a few cycles after done
        repeat(5) @(negedge CLK);

        $display("\n=== Init State FSM Test Complete ===\n");
        $stop;
    end

endmodule
