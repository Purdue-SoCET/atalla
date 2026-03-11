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
    task load_bank(
        input int bank_idx, 
        input fsm_t cmd, 
        input [ROW_BITS-1:0] row
    );
        begin
            ddrif.be_queue_ready[bank_idx] = 1'b1;
            ddrif.be_cmd[bank_idx]         = cmd;
            ddrif.be_slot[bank_idx].row    = row;
            $display("Time: %0t | Queuing Bank %0d: Cmd=%s", $time, bank_idx, cmd.name());
        end
    endtask

    initial begin 
        nRST = 1;
        ddrif.be_r           = '{default: '0};
        ddrif.be_c           = '{default: '0};
        ddrif.be_b           = '{default: '0};
        ddrif.be_bg          = '{default: '0};
        ddrif.be_cmd         = '{default: FSM_IDLE};
        ddrif.be_id          = '{default: '0};
        ddrif.be_queue_ready = '0; 

        reset_dut();
        
        // Example: Driving a request for Bank 0
        @(negedge CLK);
        ddrif.be_queue_ready[0] = 1'b1;
        ddrif.be_cmd[0]         = ACT;
        ddrif.be_r[0]           = 15'h1234;

        repeat(100) @(negedge CLK);

        $display("Done");
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