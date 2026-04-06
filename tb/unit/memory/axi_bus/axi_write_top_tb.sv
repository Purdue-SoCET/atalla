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

    function logic [MID_BID-1:0] get_full_bid();
        return {master, awid};
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

class axi_b_sample;
    logic [BID-1:0] bid;
    logic [BRESP-1:0]   bresp;
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
    task drive_b(logic [MID_BID-1:0] bid, bresp_t bresp);
        vif.b_i_valid <= 1'b1;
        vif.b_i.id    <= bid;
        vif.b_i.resp  <= bresp;
    endtask
    task clear_b();
        vif.b_i_valid <= 1'b0;
        vif.b_i       <= '0;
    endtask
    task set_b_ready(mid_t m, bit rdy);
        case (m)
            SP0:    vif.b_sp0_o_ready <= rdy;
            SP1:    vif.b_sp1_o_ready <= rdy;
            DCACHE: vif.b_d_o_ready   <= rdy;
        endcase
    endtask
    task set_all_b_ready_low();
        vif.b_sp0_o_ready <= 1'b0;
        vif.b_sp1_o_ready <= 1'b0;
        vif.b_d_o_ready   <= 1'b0;
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
    function axi_b_sample sample_b_sp0();
        axi_b_sample b;
        b = new();
        b.bid   = vif.b_sp0_o.id;
        b.bresp = vif.b_sp0_o.resp;
        return b;
    endfunction
    function axi_b_sample sample_b_sp1();
        axi_b_sample b;
        b = new();
        b.bid   = vif.b_sp1_o.id;
        b.bresp = vif.b_sp1_o.resp;
        return b;
    endfunction
    function axi_b_sample sample_b_d();
        axi_b_sample b;
        b = new();
        b.bid   = vif.b_d_o.id;
        b.bresp = vif.b_d_o.resp;
        return b;
    endfunction
endclass

class axi_checker;
    function bit check_aw(axi_write_txn exp, axi_aw_sample obs);
        bit pass;
        pass = 1;
        if (obs.awid != exp.get_full_awid()) begin
            $error("AWID mismatch: exp=%h obs=%h", exp.get_full_awid(), obs.awid);
            pass = 0;
        end
        if (obs.awaddr != exp.awaddr) begin
            $error("AWADDR mismatch: exp=%h obs=%h", exp.awaddr, obs.awaddr);
            pass = 0;
        end
        if (obs.awlen != exp.awlen) begin
            $error("AWLEN mismatch: exp=%h obs=%h", exp.awlen, obs.awlen);
            pass = 0;
        end
        if (obs.awsize != exp.awsize) begin
            $error("AWSIZE mismatch: exp=%h obs=%h", exp.awsize, obs.awsize);
            pass = 0;
        end
        if (obs.awburst != exp.awburst) begin
            $error("AWBURST mismatch: exp=%h obs=%h", exp.awburst, obs.awburst);
            pass = 0;
        end
        return pass;
    endfunction

    function bit check_w_beat(axi_write_txn exp, axi_w_sample obs, int beat_idx);
        bit pass;
        pass = 1;
        if (obs.wid != exp.get_full_wid(beat_idx)) begin
            $error("WID mismatch @ beat %0d: exp=%h obs=%h",
                beat_idx, exp.get_full_wid(beat_idx), obs.wid);
            pass = 0;
        end
        if (obs.wdata != exp.wdata[beat_idx]) begin
            $error("WDATA mismatch @ beat %0d: exp=%h obs=%h",
                beat_idx, exp.wdata[beat_idx], obs.wdata);
            pass = 0;
        end
        if (obs.wstrb != exp.wstrb[beat_idx]) begin
            $error("WSTRB mismatch @ beat %0d: exp=%h obs=%h",
                beat_idx, exp.wstrb[beat_idx], obs.wstrb);
            pass = 0;
        end
        if (obs.wlast != exp.wlast[beat_idx]) begin
            $error("WLAST mismatch @ beat %0d: exp=%b obs=%b",
                beat_idx, exp.wlast[beat_idx], obs.wlast);
            pass = 0;
        end
        return pass;
    endfunction

    function bit check_b(logic [BID-1:0] exp_bid,
                        logic [BRESP-1:0] exp_bresp,
                        axi_b_sample obs);
        bit pass;
        pass = 1;
        if (obs.bid != exp_bid) begin
            $error("BID mismatch: exp=%0h obs=%0h", exp_bid, obs.bid);
            pass = 0;
        end
        if (obs.bresp != exp_bresp) begin
            $error("BRESP mismatch: exp=%0h obs=%0h", exp_bresp, obs.bresp);
            pass = 0;
        end
        return pass;
    endfunction
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
    axi_b_sample b_obs;

    axi_write_txn txn_sp0;
    axi_write_txn txn_sp1;
    axi_write_txn txn_d;

    bit test_pass;

    int w_count;
    int last_count;

    bit aw_master_done;
    bit aw_obs_done;
    bit w_master_done;
    bit w_obs_done;
    bit b_in_done;
    bit b_out_done;

    logic [MID_BID-1:0] full_bid;
    logic [BID-1:0]     exp_master_bid;
    //logic [BRESP-1:0]   exp_bresp;
    bresp_t exp_bresp;

    task automatic init_testcase(string name);
        test_case = name;
        drv.clear_all();
        drv.set_subordinate_ready_high();
        drv.set_all_b_ready_low();
        test_pass      = 1;
        w_count        = 0;
        last_count     = 0;
        aw_master_done = 0;
        aw_obs_done    = 0;
        w_master_done  = 0;
        w_obs_done     = 0;
        b_in_done      = 0;
        b_out_done     = 0;
        full_bid       = '0;
        exp_master_bid = '0;
        exp_bresp      = B_OKAY;
    endtask

    task automatic do_write_phase(mid_t m);
        int beat_idx;
        txn = gen.generate_txn_for_master(m);
        @(posedge CLK);
        drv.drive_aw(txn);
        drv.drive_w(txn, 0);
        fork
            begin : MASTER_AW_THREAD
                case (m)
                    SP0:    do @(posedge CLK); while (!(busif.aw_sp0_i_valid && busif.aw_sp0_i_ready));
                    SP1:    do @(posedge CLK); while (!(busif.aw_sp1_i_valid && busif.aw_sp1_i_ready));
                    DCACHE: do @(posedge CLK); while (!(busif.aw_d_i_valid   && busif.aw_d_i_ready));
                endcase
                drv.clear_aw(m);
                aw_master_done = 1;
            end
            begin : SUB_AW_THREAD
                do @(posedge CLK); while (!(busif.aw_o_valid && busif.aw_o_ready));
                aw_obs = mon.sample_sub_aw();
                if (!chk.check_aw(txn, aw_obs))
                    test_pass = 0;
                aw_obs_done = 1;
            end
            begin : MASTER_W_THREAD
                beat_idx = 0;

                while (beat_idx < txn.wdata.size()) begin
                    case (m)
                        SP0:    do @(posedge CLK); while (!(busif.w_sp0_i_valid && busif.w_sp0_i_ready));
                        SP1:    do @(posedge CLK); while (!(busif.w_sp1_i_valid && busif.w_sp1_i_ready));
                        DCACHE: do @(posedge CLK); while (!(busif.w_d_i_valid   && busif.w_d_i_ready));
                    endcase

                    beat_idx++;

                    if (beat_idx < txn.wdata.size())
                        drv.drive_w(txn, beat_idx);
                end

                drv.clear_w(m);
                w_master_done = 1;
            end
            begin : SUB_W_THREAD
                for (int obs_idx = 0; obs_idx < txn.wdata.size(); obs_idx++) begin
                    do @(posedge CLK); while (!(busif.w_o_valid && busif.w_o_ready));
                    w_obs = mon.sample_sub_w();
                    if (!chk.check_w_beat(txn, w_obs, obs_idx))
                        test_pass = 0;

                    w_count++;

                    if (w_obs.wlast)
                        last_count++;
                end
                w_obs_done = 1;
            end
        join
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
        repeat (2) @(posedge CLK);
    endtask

    task automatic do_b_phase(mid_t m, int resp_delay);
        full_bid       = txn.get_full_bid();
        exp_master_bid = txn.awid;
        exp_bresp      = B_OKAY;
        repeat (resp_delay) @(posedge CLK);
        drv.set_b_ready(m, 1'b1);
        @(posedge CLK);
        drv.drive_b(full_bid, exp_bresp);
        fork
            begin : B_IN_THREAD
                do @(posedge CLK); while (!(busif.b_i_valid && busif.b_i_ready));
                drv.clear_b();
                b_in_done = 1;
            end
            begin : B_OUT_THREAD
                case (m)
                    SP0: begin
                        do @(posedge CLK); while (!(busif.b_sp0_o_valid && busif.b_sp0_o_ready));
                        b_obs = mon.sample_b_sp0();
                    end
                    SP1: begin
                        do @(posedge CLK); while (!(busif.b_sp1_o_valid && busif.b_sp1_o_ready));
                        b_obs = mon.sample_b_sp1();
                    end
                    DCACHE: begin
                        do @(posedge CLK); while (!(busif.b_d_o_valid && busif.b_d_o_ready));
                        b_obs = mon.sample_b_d();
                    end
                endcase
                if (!chk.check_b(exp_master_bid, exp_bresp, b_obs))
                    test_pass = 0;

                b_out_done = 1;
            end
        join
        if (!b_in_done) begin
            $error("%s FAILED: B was never accepted on subordinate input", test_case);
            test_pass = 0;
        end
        if (!b_out_done) begin
            $error("%s FAILED: B was never observed on target master output", test_case);
            test_pass = 0;
        end
        repeat (2) @(posedge CLK);
    endtask

    task automatic drive_one_write_request(
        input mid_t m,
        input axi_write_txn t,
        output bit aw_master_done_o,
        output bit w_master_done_o
    );
        int beat_idx;

        aw_master_done_o = 0;
        w_master_done_o  = 0;

        drv.drive_aw(t);
        drv.drive_w(t, 0);

        fork
            begin : MASTER_AW_THREAD
                case (m)
                    SP0:    do @(posedge CLK); while (!(busif.aw_sp0_i_valid && busif.aw_sp0_i_ready));
                    SP1:    do @(posedge CLK); while (!(busif.aw_sp1_i_valid && busif.aw_sp1_i_ready));
                    DCACHE: do @(posedge CLK); while (!(busif.aw_d_i_valid   && busif.aw_d_i_ready));
                endcase
                drv.clear_aw(m);
                aw_master_done_o = 1;
            end

            begin : MASTER_W_THREAD
                beat_idx = 0;

                while (beat_idx < t.wdata.size()) begin
                    case (m)
                        SP0:    do @(posedge CLK); while (!(busif.w_sp0_i_valid && busif.w_sp0_i_ready));
                        SP1:    do @(posedge CLK); while (!(busif.w_sp1_i_valid && busif.w_sp1_i_ready));
                        DCACHE: do @(posedge CLK); while (!(busif.w_d_i_valid   && busif.w_d_i_ready));
                    endcase

                    beat_idx++;

                    if (beat_idx < t.wdata.size())
                        drv.drive_w(t, beat_idx);
                end

                drv.clear_w(m);
                w_master_done_o = 1;
            end
        join
    endtask

    task automatic send_one_b_response(
        input mid_t m,
        input axi_write_txn t,
        input bresp_t [BRESP-1:0] bresp_in,
        output bit b_in_done_o,
        output bit b_out_done_o
    );
        logic [MID_BID-1:0] full_bid_l;
        logic [BID-1:0]     exp_master_bid_l;
        b_in_done_o  = 0;
        b_out_done_o = 0;
        full_bid_l       = t.get_full_bid();
        exp_master_bid_l = t.awid;

        drv.set_b_ready(m, 1'b1);
        @(posedge CLK);
        drv.drive_b(full_bid_l, bresp_in);
        fork
            begin : B_IN_THREAD
                do @(posedge CLK); while (!(busif.b_i_valid && busif.b_i_ready));
                drv.clear_b();
                b_in_done_o = 1;
            end

            begin : B_OUT_THREAD
                case (m)
                    SP0: begin
                        do @(posedge CLK); while (!(busif.b_sp0_o_valid && busif.b_sp0_o_ready));
                        b_obs = mon.sample_b_sp0();
                    end
                    SP1: begin
                        do @(posedge CLK); while (!(busif.b_sp1_o_valid && busif.b_sp1_o_ready));
                        b_obs = mon.sample_b_sp1();
                    end
                    DCACHE: begin
                        do @(posedge CLK); while (!(busif.b_d_o_valid && busif.b_d_o_ready));
                        b_obs = mon.sample_b_d();
                    end
                endcase

                if (!chk.check_b(exp_master_bid_l, bresp_in, b_obs))
                    test_pass = 0;

                b_out_done_o = 1;
            end
        join
    endtask

    task directed_all_3_write_then_ooo_b_response_test;
        int sp0_w_count, sp1_w_count, d_w_count;
        int sp0_last_count, sp1_last_count, d_last_count;

        bit sp0_aw_master_done, sp1_aw_master_done, d_aw_master_done;
        bit sp0_w_master_done,  sp1_w_master_done,  d_w_master_done;

        bit sp0_b_in_done, sp1_b_in_done, d_b_in_done;
        bit sp0_b_out_done, sp1_b_out_done, d_b_out_done;

        test_case = "TEST CASE 10: ALL 3 WRITES THEN OUT-OF-ORDER B RESPONSES";

        drv.clear_all();
        drv.set_subordinate_ready_high();
        drv.set_all_b_ready_low();

        test_pass = 1;

        // Generate one txn per master
        txn_sp0 = gen.generate_txn_for_master(SP0);
        txn_sp1 = gen.generate_txn_for_master(SP1);
        txn_d   = gen.generate_txn_for_master(DCACHE);

        sp0_w_count    = 0;
        sp1_w_count    = 0;
        d_w_count      = 0;
        sp0_last_count = 0;
        sp1_last_count = 0;
        d_last_count   = 0;

        @(posedge CLK);

        // Launch all 3 requests together
        fork
            drive_one_write_request(SP0,    txn_sp0, sp0_aw_master_done, sp0_w_master_done);
            drive_one_write_request(SP1,    txn_sp1, sp1_aw_master_done, sp1_w_master_done);
            drive_one_write_request(DCACHE, txn_d,   d_aw_master_done,   d_w_master_done);

            // Observe outgoing AWs in request arbitration order
            begin : SUB_AW_OBS_THREAD
                do @(posedge CLK); while (!(busif.aw_o_valid && busif.aw_o_ready));
                aw_obs = mon.sample_sub_aw();
                if (!chk.check_aw(txn_sp0, aw_obs))
                    test_pass = 0;

                do @(posedge CLK); while (!(busif.aw_o_valid && busif.aw_o_ready));
                aw_obs = mon.sample_sub_aw();
                if (!chk.check_aw(txn_sp1, aw_obs))
                    test_pass = 0;

                do @(posedge CLK); while (!(busif.aw_o_valid && busif.aw_o_ready));
                aw_obs = mon.sample_sub_aw();
                if (!chk.check_aw(txn_d, aw_obs))
                    test_pass = 0;
            end

            // Observe outgoing W bursts in request arbitration order
            begin : SUB_W_OBS_THREAD
                for (int i = 0; i < txn_sp0.wdata.size(); i++) begin
                    do @(posedge CLK); while (!(busif.w_o_valid && busif.w_o_ready));
                    w_obs = mon.sample_sub_w();
                    if (!chk.check_w_beat(txn_sp0, w_obs, i))
                        test_pass = 0;
                    sp0_w_count++;
                    if (w_obs.wlast) sp0_last_count++;
                end

                for (int i = 0; i < txn_sp1.wdata.size(); i++) begin
                    do @(posedge CLK); while (!(busif.w_o_valid && busif.w_o_ready));
                    w_obs = mon.sample_sub_w();
                    if (!chk.check_w_beat(txn_sp1, w_obs, i))
                        test_pass = 0;
                    sp1_w_count++;
                    if (w_obs.wlast) sp1_last_count++;
                end

                for (int i = 0; i < txn_d.wdata.size(); i++) begin
                    do @(posedge CLK); while (!(busif.w_o_valid && busif.w_o_ready));
                    w_obs = mon.sample_sub_w();
                    if (!chk.check_w_beat(txn_d, w_obs, i))
                        test_pass = 0;
                    d_w_count++;
                    if (w_obs.wlast) d_last_count++;
                end
            end
        join

        // ---------------------------
        // Request-side summary checks
        // ---------------------------
        if (!sp0_aw_master_done) begin
            $error("%s FAILED: SP0 AW was never accepted on master side", test_case);
            test_pass = 0;
        end
        if (!sp1_aw_master_done) begin
            $error("%s FAILED: SP1 AW was never accepted on master side", test_case);
            test_pass = 0;
        end
        if (!d_aw_master_done) begin
            $error("%s FAILED: DCACHE AW was never accepted on master side", test_case);
            test_pass = 0;
        end

        if (!sp0_w_master_done) begin
            $error("%s FAILED: SP0 W beats were not all accepted on master side", test_case);
            test_pass = 0;
        end
        if (!sp1_w_master_done) begin
            $error("%s FAILED: SP1 W beats were not all accepted on master side", test_case);
            test_pass = 0;
        end
        if (!d_w_master_done) begin
            $error("%s FAILED: DCACHE W beats were not all accepted on master side", test_case);
            test_pass = 0;
        end

        if (sp0_w_count != (txn_sp0.awlen + 1)) begin
            $error("%s FAILED: SP0 wrong W beat count exp=%0d obs=%0d",
                test_case, txn_sp0.awlen + 1, sp0_w_count);
            test_pass = 0;
        end
        if (sp1_w_count != (txn_sp1.awlen + 1)) begin
            $error("%s FAILED: SP1 wrong W beat count exp=%0d obs=%0d",
                test_case, txn_sp1.awlen + 1, sp1_w_count);
            test_pass = 0;
        end
        if (d_w_count != (txn_d.awlen + 1)) begin
            $error("%s FAILED: DCACHE wrong W beat count exp=%0d obs=%0d",
                test_case, txn_d.awlen + 1, d_w_count);
            test_pass = 0;
        end

        if (sp0_last_count != 1) begin
            $error("%s FAILED: SP0 expected exactly one WLAST, observed %0d",
                test_case, sp0_last_count);
            test_pass = 0;
        end
        if (sp1_last_count != 1) begin
            $error("%s FAILED: SP1 expected exactly one WLAST, observed %0d",
                test_case, sp1_last_count);
            test_pass = 0;
        end
        if (d_last_count != 1) begin
            $error("%s FAILED: DCACHE expected exactly one WLAST, observed %0d",
                test_case, d_last_count);
            test_pass = 0;
        end

        // Wait some time before returning responses
        repeat (4) @(posedge CLK);

        // ----------------------------------------
        // Return B responses intentionally OUT OF ORDER
        // Example order: SP1 -> DCACHE -> SP0
        // ----------------------------------------
        send_one_b_response(SP1,    txn_sp1, B_OKAY, sp1_b_in_done, sp1_b_out_done);
        send_one_b_response(DCACHE, txn_d,   B_OKAY, d_b_in_done,   d_b_out_done);
        send_one_b_response(SP0,    txn_sp0, B_OKAY, sp0_b_in_done, sp0_b_out_done);

        if (!sp0_b_in_done || !sp0_b_out_done) begin
            $error("%s FAILED: SP0 B response did not complete correctly", test_case);
            test_pass = 0;
        end
        if (!sp1_b_in_done || !sp1_b_out_done) begin
            $error("%s FAILED: SP1 B response did not complete correctly", test_case);
            test_pass = 0;
        end
        if (!d_b_in_done || !d_b_out_done) begin
            $error("%s FAILED: DCACHE B response did not complete correctly", test_case);
            test_pass = 0;
        end

        if (test_pass)
            $display("%s PASSED", test_case);

        repeat (2) @(posedge CLK);
    endtask

    task automatic finish_testcase();
        if (test_pass)
            $display("%s PASSED", test_case);
    endtask

    task single_sp0_write_test;
        init_testcase("TEST CASE 1: SINGLE SP0 WRITE");
        do_write_phase(SP0);
        finish_testcase();
    endtask

    task single_sp1_write_test;
        init_testcase("TEST CASE 2: SINGLE SP1 WRITE");
        do_write_phase(SP1);
        finish_testcase();
    endtask

    task single_dcache_write_test;
        init_testcase("TEST CASE 3: SINGLE DCACHE WRITE");
        do_write_phase(DCACHE);
        finish_testcase();
    endtask

    task single_sp0_b_response_test;
        init_testcase("TEST CASE 4: SINGLE SP0 B RESPONSE");
        txn = gen.generate_txn_for_master(SP0);
        do_b_phase(SP0, 0);
        finish_testcase();
    endtask

    task single_sp1_b_response_test;
        init_testcase("TEST CASE 5: SINGLE SP1 B RESPONSE");
        txn = gen.generate_txn_for_master(SP1);
        do_b_phase(SP1, 0);
        finish_testcase();
    endtask

    task single_dcache_b_response_test;
        init_testcase("TEST CASE 6: SINGLE DCACHE B RESPONSE");
        txn = gen.generate_txn_for_master(DCACHE);
        do_b_phase(DCACHE, 0);
        finish_testcase();
    endtask

    task single_sp0_write_with_b_response_test;
        init_testcase("TEST CASE 7: SP0 WRITE THEN B RESPONSE");
        do_write_phase(SP0);
        do_b_phase(SP0, 3);
        finish_testcase();
    endtask

    task single_sp1_write_with_b_response_test;
        init_testcase("TEST CASE 8: SP1 WRITE THEN B RESPONSE");
        do_write_phase(SP1);
        do_b_phase(SP1, 3);
        finish_testcase();
    endtask

    task single_dcache_write_with_b_response_test;
        init_testcase("TEST CASE 9: DCACHE WRITE THEN B RESPONSE");
        do_write_phase(DCACHE);
        do_b_phase(DCACHE, 3);
        finish_testcase();
    endtask

    task single_sp0_write_with_subordinate_backpressure_test;
        int beat_idx;
        test_case = "TEST CASE 11: SINGLE SP0 WRITE WITH SUBORDINATE BACKPRESSURE";
        init_testcase(test_case);
        // Start with subordinate ready high so traffic can begin
        drv.set_subordinate_ready(1'b1, 1'b1);
        txn = gen.generate_txn_for_master(SP0);
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
                if (!chk.check_aw(txn, aw_obs))
                    test_pass = 0;
                aw_obs_done = 1;
            end
            begin : MASTER_W_THREAD
                beat_idx = 0;

                while (beat_idx < txn.wdata.size()) begin
                    do @(posedge CLK); while (!(busif.w_sp0_i_valid && busif.w_sp0_i_ready));

                    beat_idx++;

                    if (beat_idx < txn.wdata.size())
                        drv.drive_w(txn, beat_idx);
                end

                drv.clear_w(SP0);
                w_master_done = 1;
            end
            begin : SUB_W_THREAD
                for (int obs_idx = 0; obs_idx < txn.wdata.size(); obs_idx++) begin
                    do @(posedge CLK); while (!(busif.w_o_valid && busif.w_o_ready));
                    w_obs = mon.sample_sub_w();

                    if (!chk.check_w_beat(txn, w_obs, obs_idx))
                        test_pass = 0;

                    w_count++;

                    if (w_obs.wlast)
                        last_count++;
                end

                w_obs_done = 1;
            end
            begin : BACKPRESSURE_THREAD
                // Wait until the first outgoing W handshake happens,
                // then stall subordinate for a few cycles
                do @(posedge CLK); while (!(busif.w_o_valid && busif.w_o_ready));

                // Stall both AW and W outputs
                drv.set_subordinate_ready(1'b0, 1'b0);

                repeat (3) @(posedge CLK);

                // Release stall
                drv.set_subordinate_ready(1'b1, 1'b1);
            end
        join
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
        finish_testcase();
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

    property b_in_stable_when_stalled;
        @(posedge CLK) disable iff (!nRST)
        (busif.b_i_valid && !busif.b_i_ready) |=> 
            (busif.b_i_valid && $stable(busif.b_i));
    endproperty

    assert property (b_in_stable_when_stalled)
        else $error("TB ASSERT: B input changed while DUT not ready");

    property b_sp0_out_stable_when_stalled;
        @(posedge CLK) disable iff (!nRST)
        (busif.b_sp0_o_valid && !busif.b_sp0_o_ready) |=> 
            (busif.b_sp0_o_valid && $stable(busif.b_sp0_o));
    endproperty

    assert property (b_sp0_out_stable_when_stalled)
        else $error("TB ASSERT: SP0 B output changed while stalled");

    property b_sp1_out_stable_when_stalled;
        @(posedge CLK) disable iff (!nRST)
        (busif.b_sp1_o_valid && !busif.b_sp1_o_ready) |=> 
            (busif.b_sp1_o_valid && $stable(busif.b_sp1_o));
    endproperty

    assert property (b_sp1_out_stable_when_stalled)
        else $error("TB ASSERT: SP1 B output changed while stalled");

    property b_d_out_stable_when_stalled;
        @(posedge CLK) disable iff (!nRST)
        (busif.b_d_o_valid && !busif.b_d_o_ready) |=> 
            (busif.b_d_o_valid && $stable(busif.b_d_o));
    endproperty

    assert property (b_d_out_stable_when_stalled)
        else $error("TB ASSERT: DCACHE B output changed while stalled");

    initial begin
        gen = new();
        drv = new(busif);
        mon = new(busif);
        chk = new();
        drv.clear_all();
        reset_dut();

        single_sp0_write_test();
        single_sp1_write_test();
        single_dcache_write_test();
        single_sp0_b_response_test();
        single_sp1_b_response_test();
        single_dcache_b_response_test();
        single_sp0_write_with_b_response_test();
        single_sp1_write_with_b_response_test();
        single_dcache_write_with_b_response_test();
        directed_all_3_write_then_ooo_b_response_test();
        single_sp0_write_with_subordinate_backpressure_test();

        $display("TB DONE");
        $stop;
    end


endmodule