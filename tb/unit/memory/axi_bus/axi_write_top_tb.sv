`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

class axi_write_txn;
    rand mid_t master;
    // AW Channel constraints & metadata
    rand logic [AWID-1:0]   awid;
    rand logic [AWADDR-1:0] awaddr;
    rand logic [AWLEN-1:0]  awlen;
    logic [AWSIZE-1:0]      awsize = 3'b011;
    logic [AWBURST-1:0]     awburst = 2'b01;
    // W Channel Arrays
    rand logic [WID-1:0]   wid[];
    rand logic [WDATA-1:0] wdata[];
    rand logic [WSTRB-1:0] wstrb[];
    logic                  wlast[]; // Generated automatically, not randomized
    constraint num_beats_match {
        wid.size()   == awlen + 1;
        wdata.size() == awlen + 1;
        wstrb.size() == awlen + 1;
    }
    constraint id_match {
        foreach (wid[i]) wid[i] == awid;
    }
    constraint valid_master {
        master inside {SP0, SP1, DCACHE};
    }
    constraint legal_lengths {
        awlen inside {[0:7]}; 
    }
    function void post_randomize();
        wlast = new[awlen + 1];
        foreach (wlast[i]) begin
            wlast[i] = (i == awlen); // Only true on the final beat
        end
    endfunction
endclass

// ---------------------------------------------------------
// Unified Driver & Testbench Module
// ---------------------------------------------------------
module axi_write_top_tb ();
    parameter CLK_PERIOD = 10;

    logic CLK = 0, nRST;
    string test_case = ""; 

    always #(CLK_PERIOD/2) CLK = ~CLK;

    axi_bus_if busif(.CLK(CLK), .nRST(nRST));
    axi_write_top DUT (.CLK(CLK), .nRST(nRST), .wr_path_if(busif));

    // --- Helper Tasks ---
    task reset_dut();
        test_case = "RESET ON DUT";
        nRST = 0;
        clear_all_masters();
        busif.aw_o_ready <= 1'b0;
        busif.w_o_ready  <= 1'b0;
        
        repeat(3) @(posedge CLK);
        nRST = 1;
        $display("TB: Reset released");
        repeat(2) @(posedge CLK);
    endtask

    task clear_all_masters();
        busif.sp0_i_valid <= 1'b0; busif.aw_sp0_i <= '0; busif.w_sp0_i <= '0;
        busif.sp1_i_valid <= 1'b0; busif.aw_sp1_i <= '0; busif.w_sp1_i <= '0;
        busif.d_i_valid   <= 1'b0; busif.aw_d_i   <= '0; busif.w_d_i   <= '0;
    endtask

    // --- Core Master Driver (New Lockstep Logic) ---
    task automatic drive_master_transaction(axi_write_txn txn);
        int beat_idx = 0;

        // 1. Setup Phase: Drive Valid, AW metadata, and Beat 0
        @(posedge CLK);
        case (txn.master)
            SP0: begin
                busif.sp0_i_valid <= 1'b1;
                busif.aw_sp0_i.addr <= txn.awaddr; busif.aw_sp0_i.len <= txn.awlen;
                busif.w_sp0_i.data  <= txn.wdata[0]; busif.w_sp0_i.last <= txn.wlast[0];
            end
            SP1: begin
                busif.sp1_i_valid <= 1'b1;
                busif.aw_sp1_i.addr <= txn.awaddr; busif.aw_sp1_i.len <= txn.awlen;
                busif.w_sp1_i.data  <= txn.wdata[0]; busif.w_sp1_i.last <= txn.wlast[0];
            end
            DCACHE: begin
                busif.d_i_valid <= 1'b1;
                busif.aw_d_i.addr <= txn.awaddr; busif.aw_d_i.len <= txn.awlen;
                busif.w_d_i.data  <= txn.wdata[0]; busif.w_d_i.last <= txn.wlast[0];
            end
        endcase
        // 2. Wait for Handshake (Valid & Ready)
        case (txn.master)
            SP0:    do @(posedge CLK); while (!(busif.sp0_i_valid && busif.sp0_wr_ready));
            SP1:    do @(posedge CLK); while (!(busif.sp1_i_valid && busif.sp1_wr_ready));
            DCACHE: do @(posedge CLK); while (!(busif.d_i_valid   && busif.d_wr_ready));
        endcase

        // 3. Drop Valid immediately after handshake
        case (txn.master)
            SP0:    busif.sp0_i_valid <= 1'b0;
            SP1:    busif.sp1_i_valid <= 1'b0;
            DCACHE: busif.d_i_valid   <= 1'b0;
        endcase
        // 4. Stream remaining beats in lockstep (if any)
        for (beat_idx = 1; beat_idx <= txn.awlen; beat_idx++) begin
            // FIX 2: Drive the new beat IMMEDIATELY (no posedge wait here at the top)
            case (txn.master)
                SP0: begin
                    busif.w_sp0_i.data <= txn.wdata[beat_idx];
                    busif.w_sp0_i.last <= txn.wlast[beat_idx];
                end
                SP1: begin
                    busif.w_sp1_i.data <= txn.wdata[beat_idx];
                    busif.w_sp1_i.last <= txn.wlast[beat_idx];
                end
                DCACHE: begin
                    busif.w_d_i.data <= txn.wdata[beat_idx];
                    busif.w_d_i.last <= txn.wlast[beat_idx];
                end
            endcase
            // NOW wait for the clock edge to sample the beat we just put on the bus
            @(posedge CLK); 
        end
        // Wait one more cycle for the final beat (or the single beat) to be sampled, then clear
        if (txn.awlen == 0) @(posedge CLK);
        clear_all_masters();
    endtask

    // --- Subordinate Observer ---
    // The subordinate side is unchanged, so we expect standard distinct valid/ready signaling here
    task automatic observe_subordinate_transaction(axi_write_txn txn, output bit pass);
        int w_beats_seen = 0;
        bit aw_seen = 0;
        pass = 1;

        // Set Subordinate to be ready to accept data
        busif.aw_o_ready <= 1'b1;
        busif.w_o_ready  <= 1'b1;

        fork
            // Thread 1: Watch AW Channel
            begin
                do @(posedge CLK); while (!(busif.aw_o_valid && busif.aw_o_ready));
                aw_seen = 1;
                if (busif.aw_o.len != txn.awlen) begin
                    $error("[%s] AWLEN mismatch. Exp: %0d, Obs: %0d", test_case, txn.awlen, busif.aw_o.len);
                    pass = 0;
                end
            end
            
            // Thread 2: Watch W Channel
            begin
                while (w_beats_seen <= txn.awlen) begin
                    do @(posedge CLK); while (!(busif.w_o_valid && busif.w_o_ready));
                    
                    if (busif.w_o.data != txn.wdata[w_beats_seen]) begin
                        $error("[%s] WDATA mismatch at beat %0d", test_case, w_beats_seen);
                        pass = 0;
                    end
                    
                    if (busif.w_o.last !== txn.wlast[w_beats_seen]) begin
                        $error("[%s] WLAST mismatch at beat %0d", test_case, w_beats_seen);
                        pass = 0;
                    end
                    w_beats_seen++;
                end
            end
        join

        busif.aw_o_ready <= 1'b0;
        busif.w_o_ready  <= 1'b0;
    endtask

    // --- Back-to-Back Execution Phase ---
    task automatic run_b2b_testcase(mid_t m, string name);
        axi_write_txn txn1 = new();
        axi_write_txn txn2 = new();
        bit pass1, pass2;
        bit b2b_pass = 1;

        test_case = name;
        
        // Randomize two distinct transactions for the same master
        if (!txn1.randomize() with { master == m; }) $fatal(1, "Randomization of T1 failed");
        if (!txn2.randomize() with { master == m; }) $fatal(1, "Randomization of T2 failed");
        
        $display("Starting %s", test_case);
        $display("  -> Burst 1 (AWLEN: %0d)", txn1.awlen);
        $display("  -> Burst 2 (AWLEN: %0d)", txn2.awlen);

        fork
            // Master Thread: Drive T1, then immediately drive T2
            begin
                drive_master_transaction(txn1);
                // Because drive_master_transaction ends with a clock wait and clear, 
                // this creates a realistic 1-cycle gap between bursts.
                drive_master_transaction(txn2);
            end
            
            // Subordinate Thread: Observe T1, then immediately observe T2
            begin
                observe_subordinate_transaction(txn1, pass1);
                observe_subordinate_transaction(txn2, pass2);
            end
        join

        // Evaluate overall success
        b2b_pass = pass1 & pass2;

        if (b2b_pass) $display("%s: PASSED", test_case);
        else          $error("%s: FAILED", test_case);
        
        repeat (3) @(posedge CLK); // Pad between tests
    endtask

    // --- Execute Test Phase ---
    task automatic run_testcase(mid_t m, string name);
        axi_write_txn txn = new();
        bit pass_status;

        test_case = name;
        if (!txn.randomize() with { master == m; }) $fatal(1, "Randomization failed");
        
        $display("Starting %s - AWLEN: %0d", test_case, txn.awlen);

        fork
            drive_master_transaction(txn);
            observe_subordinate_transaction(txn, pass_status);
        join

        if (pass_status) $display("%s: PASSED", test_case);
        else             $error("%s: FAILED", test_case);
        
        repeat (3) @(posedge CLK); // Pad between tests
    endtask

    initial begin
        reset_dut();

        run_testcase(SP0, "TEST 1: SP0 Write Burst");
        run_testcase(SP1, "TEST 2: SP1 Write Burst");
        run_testcase(DCACHE, "TEST 3: DCACHE Write Burst");
        run_b2b_testcase(SP0, "TEST 4: SP0 Back-to-Back Bursts");
        run_b2b_testcase(SP1, "TEST 5: SP1 Back-to-Back Bursts");

        $display("Simulation Complete.");
        $finish;
    end

endmodule