`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

class axi_write_txn;
    rand mid_t master;
    // AW channel
    logic                      awvalid;
    rand logic [AWID-1:0]      awid;
    rand logic [AWADDR-1:0]    awaddr;
    rand logic [AWLEN-1:0]     awlen;
    logic [AWSIZE-1:0]         awsize = 3'b011;
    logic [AWBURST-1:0]        awburst = 2'b01;

    // W channel
    rand logic [WID-1:0]     wid[];
    rand logic [WDATA-1:0]   wdata[];
    rand logic [WSTRB-1:0]   wstrb[];
    rand logic                    wlast[];

    constraint num_beats_match {
        wid.size()   == awlen + 1;
        wdata.size() == awlen + 1;
        wstrb.size() == awlen + 1;
        wlast.size() == awlen + 1;
    }

    constraint id_match {
        foreach (wid[i])
            wid[i] == awid;
    }

    constraint valid_master {
        master inside {SP0, SP1, DCACHE};
    }

    constraint legal_lengths {
        awlen inside {[0:15]};
    }

    function void post_randomize();
        foreach (wlast[i]) begin
            wlast[i] = (i == awlen);
        end
    endfunction

    //full_id = {master, awid};
    function logic [MID_AWID-1:0] get_full_awid();
        return {master, awid};
    endfunction

    function logic [MID_WID-1:0] get_full_wid(int beat_idx);
        return {master, wid[beat_idx]};
    endfunction
endclass

class axi_aw_sample;
    logic [MID_AWID-1:0]    awid;
    logic [AWADDR-1:0]      awaddr;
    logic [AWLEN-1:0]       awlen;
    logic [AWSIZE-1:0]      awsize;
    logic [AWBURST-1:0]     awburst;
endclass

class axi_w_sample;
    logic [MID_WID-1:0]     wid;
    logic [WDATA-1:0]       wdata;
    logic [WSTRB-1:0]       wstrb;
    logic                   wlast;
endclass

class axi_generator;
    function axi_write_txn generate_txn();
        axi_write_txn txn;
        txn = new();
        if (!txn.randomize()) begin
            $fatal("Randomization failed");
        end
        return txn;
    endfunction

    function axi_write_txn generate_txn_for_master(mid_t m);
        axi_write_txn txn;
        txn = new();
        if (!txn.randomize() with { master == m; }) begin
            $fatal("Randomization failed");
        end
        return txn;
    endfunction

    function axi_write_txn generate_txn_with_len(int len);
        axi_write_txn txn;
        txn = new();
        if (!txn.randomize() with { awlen == len; }) begin
            $fatal("Randomization failed");
        end
        return txn;
    endfunction
endclass

class axi_driver;
    virtual axi_bus_if.write_path_tb vif;
    function new(virtual axi_bus_if.write_path_tb vif);
        this.vif = vif;
    endfunction
    task drive_aw_sp0(axi_write_txn txn);
        vif.aw_sp0_i_valid <= 1'b1;
        vif.aw_sp0_i.addr  <= txn.awaddr;
        vif.aw_sp0_i.id    <= txn.awid;
        vif.aw_sp0_i.len   <= txn.awlen;
        vif.aw_sp0_i.size  <= txn.awsize;
        vif.aw_sp0_i.burst <= txn.awburst;
    endtask
    task drive_aw_sp1(axi_write_txn txn);
        vif.aw_sp1_i_valid <= 1'b1;
        vif.aw_sp1_i.addr  <= txn.awaddr;
        vif.aw_sp1_i.id    <= txn.awid;
        vif.aw_sp1_i.len   <= txn.awlen;
        vif.aw_sp1_i.size  <= txn.awsize;
        vif.aw_sp1_i.burst <= txn.awburst;
    endtask
    task drive_aw_d(axi_write_txn txn);
        vif.aw_d_i_valid <= 1'b1;
        vif.aw_d_i.addr  <= txn.awaddr;
        vif.aw_d_i.id    <= txn.awid;
        vif.aw_d_i.len   <= txn.awlen;
        vif.aw_d_i.size  <= txn.awsize;
        vif.aw_d_i.burst <= txn.awburst;
    endtask
    task drive_w_sp0(axi_write_txn txn, int beat_idx);
        vif.w_sp0_i_valid <= 1'b1;
        vif.w_sp0_i.data  <= txn.wdata[beat_idx];
        vif.w_sp0_i.id    <= txn.wid[beat_idx];
        vif.w_sp0_i.strb  <= txn.wstrb[beat_idx];
        vif.w_sp0_i.last  <= txn.wlast[beat_idx];
    endtask
    task drive_w_sp1(axi_write_txn txn, int beat_idx);
        vif.w_sp1_i_valid <= 1'b1;
        vif.w_sp1_i.data  <= txn.wdata[beat_idx];
        vif.w_sp1_i.id    <= txn.wid[beat_idx];
        vif.w_sp1_i.strb  <= txn.wstrb[beat_idx];
        vif.w_sp1_i.last  <= txn.wlast[beat_idx];
    endtask
    task drive_w_d(axi_write_txn txn, int beat_idx);
        vif.w_d_i_valid <= 1'b1;
        vif.w_d_i.data  <= txn.wdata[beat_idx];
        vif.w_d_i.id    <= txn.wid[beat_idx];
        vif.w_d_i.strb  <= txn.wstrb[beat_idx];
        vif.w_d_i.last  <= txn.wlast[beat_idx];
    endtask
    task drive_aw(axi_write_txn txn);
        case (txn.master)
            SP0:    drive_aw_sp0(txn);
            SP1:    drive_aw_sp1(txn);
            DCACHE: drive_aw_d(txn);
        endcase
    endtask
    task drive_w(axi_write_txn txn, int beat_idx);
        case (txn.master)
            SP0:    drive_w_sp0(txn, beat_idx);
            SP1:    drive_w_sp1(txn, beat_idx);
            DCACHE: drive_w_d(txn, beat_idx);
        endcase
    endtask
    task clear_aw_sp0();
        vif.aw_sp0_i_valid <= 1'b0;
        vif.aw_sp0_i       <= '0;
    endtask
    task clear_aw_sp1();
        vif.aw_sp1_i_valid <= 1'b0;
        vif.aw_sp1_i       <= '0;
    endtask
    task clear_aw_d();
        vif.aw_d_i_valid <= 1'b0;
        vif.aw_d_i       <= '0;
    endtask
    task clear_w_sp0();
        vif.w_sp0_i_valid <= 1'b0;
        vif.w_sp0_i       <= '0;
    endtask
    task clear_w_sp1();
        vif.w_sp1_i_valid <= 1'b0;
        vif.w_sp1_i       <= '0;
    endtask
    task clear_w_d();
        vif.w_d_i_valid <= 1'b0;
        vif.w_d_i       <= '0;
    endtask
    task clear_master(mid_t m);
        case (m)
            SP0: begin
                clear_aw_sp0();
                clear_w_sp0();
            end
            SP1: begin
                clear_aw_sp1();
                clear_w_sp1();
            end
            DCACHE: begin
                clear_aw_d();
                clear_w_d();
            end
        endcase
    endtask
    task clear_all();
        clear_aw_sp0();
        clear_aw_sp1();
        clear_aw_d();
        clear_w_sp0();
        clear_w_sp1();
        clear_w_d();
        vif.b_sp0_o_ready <= 1'b0;
        vif.b_sp1_o_ready <= 1'b0;
        vif.b_d_o_ready   <= 1'b0;
        vif.aw_o_ready    <= 1'b0;
        vif.w_o_ready     <= 1'b0;
        vif.b_i_valid     <= 1'b0;
        vif.b_i           <= '0;
    endtask
    task clear_aw(mid_t m);
        case (m)
            SP0:    clear_aw_sp0();
            SP1:    clear_aw_sp1();
            DCACHE: clear_aw_d();
        endcase
    endtask

    task clear_w(mid_t m);
        case (m)
            SP0:    clear_w_sp0();
            SP1:    clear_w_sp1();
            DCACHE: clear_w_d();
        endcase
    endtask
    task set_subordinate_ready(bit aw_rdy, bit w_rdy);
        vif.aw_o_ready <= aw_rdy;
        vif.w_o_ready  <= w_rdy;
    endtask

    task set_subordinate_ready_high();
        vif.aw_o_ready <= 1'b1;
        vif.w_o_ready  <= 1'b1;
    endtask

    task set_subordinate_ready_low();
        vif.aw_o_ready <= 1'b0;
        vif.w_o_ready  <= 1'b0;
    endtask
endclass

class axi_monitor;
    virtual axi_bus_if.write_path_tb vif;

    function new(virtual axi_bus_if.write_path_tb vif);
        this.vif = vif;
    endfunction

    function axi_aw_sample sample_sub_aw();
        axi_aw_sample aw;
        aw = new();
        aw.awid    = vif.aw_o.mid_id;
        aw.awaddr  = vif.aw_o.addr;
        aw.awlen   = vif.aw_o.len;
        aw.awsize  = vif.aw_o.size;
        aw.awburst = vif.aw_o.burst;

        return aw;
    endfunction

    function axi_w_sample sample_sub_w();
        axi_w_sample w;
        w = new();
        w.wid   = vif.w_o.mid_id;
        w.wdata = vif.w_o.data;
        w.wstrb = vif.w_o.strb;
        w.wlast = vif.w_o.last;

        return w;
    endfunction
endclass

class axi_checker;

    task check_aw(axi_write_txn exp, axi_aw_sample obs);
        if (obs.awid   != exp.get_full_awid()) $error("AWID mismatch");
        if (obs.awaddr != exp.awaddr)          $error("AWADDR mismatch");
        if (obs.awlen  != exp.awlen)           $error("AWLEN mismatch");
        if (obs.awsize != exp.awsize)          $error("AWSIZE mismatch");
        if (obs.awburst!= exp.awburst)         $error("AWBURST mismatch");
    endtask

    task check_w_beat(axi_write_txn exp, axi_w_sample obs, int beat_idx);
        if (obs.wid   != exp.get_full_wid(beat_idx)) $error("WID mismatch");
        if (obs.wdata != exp.wdata[beat_idx])        $error("WDATA mismatch");
        if (obs.wstrb != exp.wstrb[beat_idx])        $error("WSTRB mismatch");
        if (obs.wlast != exp.wlast[beat_idx])        $error("WLAST mismatch");
    endtask

endclass

module axi_write_top_tb ();
    parameter CLK_PERIOD = 10;

    logic CLK = 0, nRST;
    string test_case = ""; 

    // clock
    always #(CLK_PERIOD/2) CLK++;

    // interface 
    axi_bus_if busif(.CLK(CLK), .nRST(nRST));
    axi_write_top DUT (.CLK(CLK), .nRST(nRST), .wr_path_if(busif));

    task reset_dut;
    begin
        test_case = "RESET ON DUT";
        nRST = 0;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        nRST = 1;
        $display("TB: reset released");
        @(posedge CLK);
        @(posedge CLK);
    end
    endtask

    axi_write_txn   txn;
    axi_generator   gen;
    axi_driver      drv;
    axi_monitor     mon;
    axi_checker     chk;

    axi_aw_sample   aw_obs;
    axi_w_sample    w_obs;

   task single_sp0_write_test;
        int beat_idx;
        int w_count;
        int last_count;
        bit aw_master_done;
        bit aw_obs_done;
        bit w_master_done;
        bit w_obs_done;
        bit test_pass;
        test_case = "TEST CASE 1: SINGLE SP0 WRITE";
        drv.clear_all();
        drv.set_subordinate_ready_high();
        txn = gen.generate_txn_for_master(SP0);
        w_count        = 0;
        last_count     = 0;
        aw_master_done = 0;
        aw_obs_done    = 0;
        w_master_done  = 0;
        w_obs_done     = 0;
        test_pass      = 1;
        @(posedge CLK);
        drv.drive_aw(txn);
        drv.drive_w(txn, 0);
        fork
            begin : MASTER_AW_THREAD
                do @(posedge CLK); while (!(busif.aw_sp0_i_valid && busif.aw_sp0_i_ready));
                drv.clear_aw(SP0);
                aw_master_done = 1;
            end
            begin : SUB_AW_THREAD
                do @(posedge CLK); while (!(busif.aw_o_valid && busif.aw_o_ready));
                aw_obs = mon.sample_sub_aw();
                chk.check_aw(txn, aw_obs);
                aw_obs_done = 1;
            end
            begin : MASTER_W_THREAD
                do @(posedge CLK); while (!(busif.w_sp0_i_valid && busif.w_sp0_i_ready));
                drv.clear_w(SP0);
                for (beat_idx = 1; beat_idx < txn.wdata.size(); beat_idx++) begin
                    @(posedge CLK);
                    drv.drive_w(txn, beat_idx);
                    do @(posedge CLK); while (!(busif.w_sp0_i_valid && busif.w_sp0_i_ready));
                    drv.clear_w(SP0);
                end
                w_master_done = 1;
            end
            begin : SUB_W_THREAD
                for (int obs_idx = 0; obs_idx < txn.wdata.size(); obs_idx++) begin
                    do @(posedge CLK); while (!(busif.w_o_valid && busif.w_o_ready));
                    w_obs = mon.sample_sub_w();
                    chk.check_w_beat(txn, w_obs, obs_idx);
                    w_count++;
                    if (w_obs.wlast)
                        last_count++;
                end
                w_obs_done = 1;
            end
        join

        // Final summary checks
        if (!aw_master_done) begin
            $error("%s FAILED: AW was never accepted on master side", test_case);
            test_pass = 0;
        end
        if (!aw_obs_done) begin
            $error("%s FAILED: AW was never observed on subordinate side", test_case);
            test_pass = 0;
        end
        if (!w_master_done) begin
            $error("%s FAILED: W beats were not all accepted on master side", test_case);
            test_pass = 0;
        end
        if (!w_obs_done) begin
            $error("%s FAILED: W beats were not all observed on subordinate side", test_case);
            test_pass = 0;
        end
        if (w_count != (txn.awlen + 1)) begin
            $error("%s FAILED: wrong number of W beats exp=%0d obs=%0d",
                test_case, txn.awlen + 1, w_count);
            test_pass = 0;
        end
        if (last_count != 1) begin
            $error("%s FAILED: expected exactly one WLAST, observed %0d",
                test_case, last_count);
            test_pass = 0;
        end
        if (test_pass)
            $display("%s PASSED", test_case);
        repeat (2) @(posedge CLK);
    endtask

    property aw_out_stable_when_stalled;
        @(posedge CLK) disable iff (!nRST)
        (busif.aw_o_valid && !busif.aw_o_ready) |=> 
            (busif.aw_o_valid && $stable(busif.aw_o));
    endproperty

    assert property (aw_out_stable_when_stalled)
        else $error("TB ASSERT: AW output changed while subordinate not ready");

    property w_out_stable_when_stalled;
        @(posedge CLK) disable iff (!nRST)
        (busif.w_o_valid && !busif.w_o_ready) |=> 
            (busif.w_o_valid && $stable(busif.w_o));
    endproperty

    assert property (w_out_stable_when_stalled)
    else $error("TB ASSERT: W output changed while subordinate not ready");

    initial begin
        gen = new();
        drv = new(busif);
        mon = new(busif);
        chk = new();
        drv.clear_all();
        reset_dut();

        single_sp0_write_test();

        $display("TB DONE");
        $stop;

    end


endmodule