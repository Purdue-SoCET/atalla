`include "dram_pkg.svh"
`include "ddr_controller_if.sv"
`timescale 1ns/1ps
// be_r, be_c, be_b, be_bg, be_cmd, be_id, be_queue_ready

module nb_barb_tb;
    import dram_pkg::*;

    logic CLK, nRST;
    parameter PERIOD = 10;

    // clock
    always #(PERIOD/2) CLK++;
    
    ddr_controller_if ddrif();
    nb_barb DUT(CLK, nRST, ddrif);

    // test PROG(CLK, nRST, ddrif);

    // bind nb_barb nb_barb_prop barb_monitor(CLK, nRST, ddrif);

    task reset_dut();
        begin
            nRST = 0;
            repeat (5) @(negedge CLK);
            nRST = 1;
        end
    endtask

    // Load a specific bank with a command
    task drive_bank_request(
        input int bank_id,
        input fsm_t cmd,
        input [ROW_BITS-1:0] row,
        input [COLUMN_BITS-1:0] col,
        input [$clog2(ID_NUM)-1:0] id
    );
        begin
            ddrif.be_queue_ready[bank_id] = 1'b1; // Setting the bit for this bank
            ddrif.be_cmd[bank_id]         = cmd;
            ddrif.be_r[bank_id]           = row;
            ddrif.be_c[bank_id]           = col;
            ddrif.be_id[bank_id]          = id;
            $display("T=%0t | Bank %0d Ready: Cmd=%s, Row=%h", $time, bank_id, cmd.name(), row);
        end
    endtask

    initial begin  
        // 1. Initialization
        nRST = 1;
        ddrif.be_queue_ready = '0;
        ddrif.be_cmd         = '{default: FSM_IDLE};
        ddrif.be_r           = '0;
        ddrif.be_c           = '0;
        ddrif.be_id          = '0;
        reset_dut();

        // --- PHASE 1: Sequential Barrel Rolling ---
        $display("\n--- Starting Sequential Test ---");
        drive_bank_request(0, ACT, 15'h1111, 10'h001, 4'h0);
        drive_bank_request(1, ACT, 15'h2222, 10'h002, 4'h1);
        drive_bank_request(2, ACT, 15'h3333, 10'h003, 4'h2);

        // Wait for Bank 0 to be serviced (be_arb points to the winning bank)
        wait(ddrif.be_arb == 0);
        @(negedge CLK);
        ddrif.be_queue_ready[0] = 0; // Clear bank 0 request

        // --- PHASE 2: OOO Jump Logic ---
        // While roller is moving toward Bank 1, Bank 12 becomes ready (Out of Order)
        $display("\n--- Triggering OOO Jump to Bank 12 ---");
        drive_bank_request(12, FSM_READ, 15'hAAAA, 10'h0AA, 4'hF);

        // Verify the arbiter jumps to Bank 12
        wait(ddrif.be_arb == 12);
        $display("T=%0t | SUCCESS: Arbiter jumped to Bank 12", $time);
        
        @(negedge CLK);
        ddrif.be_queue_ready[12] = 0; // Clear bank 12

        // --- PHASE 3: The Return ---
        // The roller should now return to the next sequential value (Bank 1)
        wait(ddrif.be_arb == 1);
        $display("T=%0t | SUCCESS: Arbiter returned to sequential Bank 1", $time);
        
        @(negedge CLK);
        ddrif.be_queue_ready[1] = 0;

        @(negedge CLK);
        $display("\n--- All DRAM behavior tests passed ---");
        $finish;
    end

endmodule

/* program test(
    input logic CLK, nRST, 
    ddr_controller_if.backend_arb barb
);
        task reset_dut();
        begin
            nRST = 0;
            repeat (5) @(negedge CLK);
            nRST = 1;
        end
    endtask

    initial begin 
        nRST = 1;
        reset_dut();
        repeat(100) @(negedge CLK);

        $display ("Coverage = %0.2f %%", nbcg.get_inst_coverage());
        $finish;
    end

endprogram */