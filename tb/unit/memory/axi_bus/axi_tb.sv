`timescale 1ps/1ps

`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

typedef class ar_txn;
typedef class r_txn;
typedef class aw_txn;
typedef class w_txn;
typedef class ar_driver;
typedef class r_driver;
typedef class write_driver;
typedef class ar_monitor;
typedef class r_monitor;
typedef class aw_monitor;
typedef class w_monitor;
typedef class scoreboard;

module axi_tb; //TODO: add clocking feature

    parameter PERIOD=10;

    logic CLK=0, nRST;
    always #(PERIOD/2) CLK++;

    axi_bus_if abif (CLK, nRST);
    axi DUT (CLK, nRST, abif);
    test PROG (CLK, nRST, abif);

    // AR arbiter grant one at a time
    property ar_arbit_onehot; @(posedge CLK) disable iff (!nRST) $onehot0({abif.sp0_pop, abif.sp1_pop, abif.i_pop, abif.d_pop}); endproperty
    // manager pop with request
    property sp0_pop_req; @(posedge CLK) disable iff (!nRST) abif.sp0_pop |-> abif.sp0_req_r; endproperty
    property sp1_pop_req; @(posedge CLK) disable iff (!nRST) abif.sp1_pop |-> abif.sp1_req_r; endproperty
    property i_pop_req; @(posedge CLK) disable iff (!nRST) abif.i_pop   |-> abif.i_req_r;   endproperty
    property d_pop_req; @(posedge CLK) disable iff (!nRST) abif.d_pop   |-> abif.d_req_r;   endproperty
    // R send master one at a time
    property router_onehot; @(posedge CLK) disable iff (!nRST) $onehot0({abif.r_sp0_o_valid, abif.r_sp1_o_valid, abif.r_i_o_valid, abif.r_d_o_valid}); endproperty
    // R no sub valid, then no master valid
    property r_validX; @(posedge CLK) disable iff (!nRST) !abif.r_valid |-> !abif.r_sp0_o_valid && !abif.r_sp1_o_valid && !abif.r_i_o_valid && !abif.r_d_o_valid; endproperty
    
    // assert
    assert property (ar_arbit_onehot) else $error("SVA: AR arbiter grant not onehot");
    assert property (sp0_pop_req) else $error("SVA: sp0 pop when no request");
    assert property (sp1_pop_req) else $error("SVA: sp1 pop when no request");
    assert property (i_pop_req) else $error("SVA: i pop when no request");
    assert property (d_pop_req) else $error("SVA: d pop when no request");
    assert property (router_onehot) else $error("SVA: R router output not onehot");
    assert property (r_validX) else $error("SVA: R master valid without sub valid");
endmodule

program test (
    input logic CLK,
    output logic nRST,
    axi_bus_if abif
);
    environment env;
    int TIME_OUT = 50000;
    task automatic reset_input();
        // --- Read path ---
        abif.ar_sp0_valid = 0;
        abif.ar_sp1_valid = 0;
        abif.ar_i_valid   = 0;
        abif.ar_d_valid   = 0;

        abif.ar_sp0_i = '0;
        abif.ar_sp1_i = '0;
        abif.ar_i_i   = '0;
        abif.ar_d_i   = '0;

        abif.r_sp0_o_ready = 0;
        abif.r_sp1_o_ready = 0;
        abif.r_i_o_ready   = 0;
        abif.r_d_o_ready   = 0;

        abif.r_valid   = 0;
        abif.r_i       = '0;
        abif.ar_o_ready = 0;

        // --- Write path ---
        abif.aw_sp0_i_valid = 0; abif.aw_sp0_i = '0;
        abif.aw_sp1_i_valid = 0; abif.aw_sp1_i = '0;
        abif.aw_d_i_valid   = 0; abif.aw_d_i   = '0;

        abif.w_sp0_i_valid  = 0; abif.w_sp0_i  = '0;
        abif.w_sp1_i_valid  = 0; abif.w_sp1_i  = '0;
        abif.w_d_i_valid    = 0; abif.w_d_i    = '0;

        abif.aw_o_ready = 0;
        abif.w_o_ready  = 0;

        abif.b_sp0_o_ready = 0;
        abif.b_sp1_o_ready = 0;
        abif.b_d_o_ready   = 0;

        abif.b_i_valid = 0;
        abif.b_i       = '0;
    endtask

    task automatic reset_dut();
        nRST = 0;
        reset_input();
        repeat (3) @(negedge CLK);
        nRST = 1;
    endtask

    task automatic gen_ar_txn(
        ref ar_txn q[$],
        input int times,
        input int force_mid = -1
    );
        ar_txn t;

        for (int i=0; i<times; i++) begin
            t = new();
            if (force_mid >= 0) begin t.force_mid = force_mid; t.c_force_mid.constraint_mode(1); end
            t.randomize();
            q.push_back(t);
        end
    endtask


    task automatic gen_r_txn(
        ref r_txn q[$],
        input int times,
        input int mid = -1
    );
        
        for (int i=0; i<times; i++) begin
            r_txn t = new();
            if (mid>=0) begin t.c_force_mid.constraint_mode(1); t.force_mid = mid; end
            t.randomize();
            q.push_back(t);
        end
    endtask

    task automatic random_ar_ready(
        int cycles
    );
        for (int i=0; i<cycles; i++) begin
            @(posedge CLK);#1;
            if ($urandom_range(0,1)) abif.ar_o_ready = $urandom_range(0,1);
        end

        abif.ar_o_ready = 1;
        repeat (20) @(negedge CLK)
        abif.ar_o_ready = 0;
    endtask

    task automatic smoke_ar_test();
        ar_txn q[$];

        gen_ar_txn(q, 4);
        
        foreach (q[i]) begin
            env.send_ar_req(q[i]); 
        end
        random_ar_ready(100);
    endtask

    task automatic pressure_ar_test(
        int num_test
    );
        ar_txn q[$];

        for (int i=0; i<num_test; i++) begin
            int m;
            m=$urandom_range(0,3);
            gen_ar_txn(q, 1, m);
        end
        
        foreach (q[i]) begin
            env.send_ar_req(q[i]); 
        end
        random_ar_ready(num_test*4); 
    endtask

    task automatic idle_ar_test();
        random_ar_ready(50);
    endtask

    task automatic smoke_r_test();
        r_txn q[$];
        gen_r_txn(q, 1);

        foreach (q[i]) begin
            env.send_r_req(q[i]);
        end
        repeat (20) @(negedge CLK);
    endtask

    task automatic pressure_r_test(
        input int num_test
    );
        r_txn q[$];

        for (int i=0; i<num_test; i++) begin
            int m;
            m=$urandom_range(0,3);
            gen_r_txn(q, 1, m);
        end
        
        foreach (q[i]) begin
            env.send_r_req(q[i]); 
        end

        repeat (num_test*20+10) @(negedge CLK);
    endtask

    task automatic idle_r_test();
        @(posedge CLK); #1;
        abif.r_sp0_o_ready=1;
        abif.r_sp1_o_ready=1;
        abif.r_i_o_ready=1;
        abif.r_d_o_ready=1;
        repeat (20) @(negedge CLK);
        abif.r_sp0_o_ready=0;
        abif.r_sp1_o_ready=0;
        abif.r_i_o_ready=0;
        abif.r_d_o_ready=0;
        @(negedge CLK);
    endtask

    task automatic gen_aw_txn(
        ref aw_txn q[$],
        input int times,
        input int force_mid = -1,
        input int force_len = -1
    );
        for (int i=0; i<times; i++) begin
            aw_txn t = new();
            if (force_mid >= 0) begin t.force_mid = force_mid; t.c_force_mid.constraint_mode(1); end
            if (force_len >= 0) begin t.force_len = force_len; t.c_force_len.constraint_mode(1); end            
            t.randomize();
            q.push_back(t);
        end
    endtask

    // AW and W ready are always driven lockstep. After initial random phase both
    // are held high long enough to drain any in-flight burst beats.
    task automatic random_write_ready(int cycles);
        for (int i=0; i<cycles; i++) begin
            @(posedge CLK); #1;
            if ($urandom_range(0,1)) begin
                logic val;
                val = $urandom_range(0,1);
                abif.aw_o_ready = val;
                abif.w_o_ready  = val;
            end
        end
        abif.aw_o_ready = 1;
        abif.w_o_ready  = 1;
        repeat (50) @(negedge CLK);
        abif.aw_o_ready = 0;
        abif.w_o_ready  = 0;
    endtask

    task automatic steady_write_ready(int cycles);
        abif.aw_o_ready = 1;
        abif.w_o_ready  = 1;
        repeat (cycles) @(negedge CLK);
        abif.aw_o_ready = 0;
        abif.w_o_ready  = 0;
    endtask

    task automatic smoke_write_test();
        aw_txn q[$];
        gen_aw_txn(q, 3); // one per write master: SP0, SP1, D$
        foreach (q[i]) env.send_write_req(q[i]);
        steady_write_ready(100);
    endtask

    task automatic pressure_write_test(int num_test);
        aw_txn q[$];
        for (int i=0; i<num_test; i++) begin
            int m;
            m = $urandom_range(0, 2); // SP0=0, SP1=1, D$=2
            gen_aw_txn(q, 1, m);
        end
        foreach (q[i]) env.send_write_req(q[i]);
        steady_write_ready(num_test*16);
    endtask

    task automatic idle_write_test();
        random_write_ready(50);
    endtask

    // Send num_txn transactions back-to-back to a single master without any
    // gap between them. Ready stays asserted throughout so the DUT sees a
    // continuous stream of AW+W pairs from the same master.
    task automatic consecutive_write_test(int master_id, int len, int num_txn);
        aw_txn q[$];
        gen_aw_txn(q, num_txn, master_id, len);
        foreach (q[i]) env.send_write_req(q[i]);
        steady_write_ready(num_txn * 20 + 50);
    endtask

    initial begin
        env = new(abif); env.start();
        reset_dut();

        // tests
        // smoke_ar_test();
        // pressure_ar_test(100);
        // idle_ar_test();

        // smoke_r_test();
        // pressure_r_test(10);
        // idle_r_test();
        
        // smoke_write_test();
        // pressure_write_test(7);
        // idle_write_test();

        // consecutive: 4 back-to-back writes to SP0, then SP1, then D$
        consecutive_write_test(1, -1, 10);

        // report
        env.report();
        $finish;
    end

    initial begin
        #(TIME_OUT);
        
        $display("\nTIMEOUT: maybe a deadlock happening.");

        $finish;
    end


endprogram

class environment;
    virtual axi_bus_if vif;

    mailbox #(sub_ar_channel_t) mbx_mon_ar;
    mailbox #(master_r_channel_t) mbx_mon_r;
    mailbox #(sub_aw_channel_t) mbx_mon_aw;
    mailbox #(sub_w_channel_t) mbx_mon_w;

    mailbox #(ar_txn) mbx_drv_ar[4];
    mailbox #(r_txn) mbx_drv_r;
    mailbox #(aw_txn) mbx_drv_write[3]; // combined AW+W per master

    ar_driver ar_drv[4];
    r_driver r_drv;
    write_driver write_drv[3];

    ar_monitor ar_mon;
    r_monitor r_mon;
    aw_monitor aw_mon;
    w_monitor w_mon;

    scoreboard scb;

    function new(
        virtual axi_bus_if vif
    );
        this.vif = vif;

        // mailbox setup
        foreach (mbx_drv_ar[i]) mbx_drv_ar[i] = new();
        foreach (mbx_drv_write[i]) mbx_drv_write[i] = new();
        mbx_drv_r = new();
        mbx_mon_ar = new();
        mbx_mon_r = new();
        mbx_mon_aw = new();
        mbx_mon_w = new();

        // monitor setup
        ar_mon = new(vif, mbx_mon_ar);
        r_mon = new(vif, mbx_mon_r);
        aw_mon = new(vif, mbx_mon_aw);
        w_mon = new(vif, mbx_mon_w);

        // scoreboard setup
        scb = new(mbx_mon_ar, mbx_mon_r, mbx_mon_aw, mbx_mon_w);

        // driver setup
        ar_drv[0] = new(0, scb, vif, mbx_drv_ar[0]);
        ar_drv[1] = new(1, scb, vif, mbx_drv_ar[1]);
        ar_drv[2] = new(2, scb, vif, mbx_drv_ar[2]);
        ar_drv[3] = new(3, scb, vif, mbx_drv_ar[3]);
        r_drv = new(vif, mbx_drv_r, scb);

        write_drv[0] = new(0, scb, vif, mbx_drv_write[0]);
        write_drv[1] = new(1, scb, vif, mbx_drv_write[1]);
        write_drv[2] = new(2, scb, vif, mbx_drv_write[2]);

    endfunction

    task send_ar_req(ar_txn t); mbx_drv_ar[t.mid].put(t); endtask
    task send_r_req(r_txn t); mbx_drv_r.put(t); endtask
    task send_write_req(aw_txn t); mbx_drv_write[t.mid].put(t); endtask

    task start();
        fork
            ar_drv[0].run(); ar_drv[1].run(); ar_drv[2].run(); ar_drv[3].run();
            r_drv.run();
            write_drv[0].run(); write_drv[1].run(); write_drv[2].run();
            ar_mon.run();
            r_mon.run();
            aw_mon.run();
            w_mon.run();
            scb.run();
        join_none
    endtask

    task report();
        scb.report();
    endtask

endclass


class ar_txn;
    rand logic [1:0] mid;
    rand logic [ARADDR-1:0] addr;
    rand logic [ARID-1:0] id;
    rand logic [ARSIZE-1:0] size;
    rand logic [ARLEN-1:0] len;
    rand logic [ARBURST-1:0] burst;

    logic [1:0] force_mid;
    constraint c_force_mid {mid == force_mid;}

    function new();
        c_force_mid.constraint_mode(0);
    endfunction
endclass

class r_txn;
    rand logic [1:0] mid;
    rand logic [RDATA-1:0] data;
    rand logic [RID-1:0] id;
    rand rresp_t resp;
    rand logic last;
    rand logic [ARLEN-1:0] len;

    logic [1:0] force_mid;
    
    constraint c_resp {resp inside {R_OKAY, R_EXOKAY, R_SLVERR, R_DECERR}; }
    constraint c_force_mid {mid == force_mid;}

    function new();
        c_force_mid.constraint_mode(0);
    endfunction
endclass

class aw_txn;
    rand logic [1:0] mid;
    rand logic [AWADDR-1:0] addr;
    rand logic [AWID-1:0] id;     // Local (2-bit) ID: index within master
    rand logic [AWSIZE-1:0] size; // beat size
    rand logic [AWLEN-1:0] len;   // burst length
    rand logic [AWBURST-1:0] burst; // burst mode (WRAP, INCR)

    logic [1:0] force_mid;
    logic [3:0] force_len;

    constraint c_mid_valid {mid inside {0, 1, 2};}  // SP0=0, SP1=1, D$=2 (no I$ on write path)
    constraint c_force_mid {mid == force_mid;}
    constraint c_force_len {len == force_len;}
    constraint c_burst     {burst != 2'b11;}

    function new();
        c_force_mid.constraint_mode(0);
        c_force_len.constraint_mode(0);
        c_burst.constraint_mode(0);
    endfunction
endclass

class w_txn;
    rand logic [1:0] mid;         // master: SP0=0, SP1=1, D$=2
    rand logic [WID-1:0] id;      // local write ID
    rand logic [AWLEN-1:0] len;   // burst length (driver sends len+1 beats)
    // Captured per beat by driver before push_w_exp:
    logic [WDATA-1:0] data;
    logic last;
    logic [WSTRB-1:0] strb;

    constraint c_mid_valid {mid inside {0, 1, 2};}
endclass

class ar_driver; // get transaction, drive it, push expected to scoreboard
    logic [1:0] mid;
    scoreboard scb;
    virtual axi_bus_if vif;
    mailbox #(ar_txn) mbx_drv_ar; // transaction fifo pushed by environment

    function new(
        logic [1:0] mid,
        scoreboard scb,
        virtual axi_bus_if vif,
        mailbox #(ar_txn) mbx_drv_ar
    );
        this.mid = mid;
        this.scb = scb;
        this.vif = vif;
        this.mbx_drv_ar = mbx_drv_ar;
    endfunction

    task run();
        ar_txn t;
        forever begin
            mbx_drv_ar.get(t);
            scb.push_ar_exp(t, t.mid);
            drive(t);
            
            $display("send ar request: mid=%0d addr=%h id=%h len=%0d", $time, t.mid, t.addr, t.id, t.len);
        end

    endtask

    task drive(ar_txn t);
        @(negedge axi_tb.CLK);
        case (t.mid)
            MID_SP0: begin vif.ar_sp0_valid=1; vif.ar_sp0_i.addr=t.addr; vif.ar_sp0_i.id=t.id;
                          vif.ar_sp0_i.size=t.size; vif.ar_sp0_i.len=t.len; vif.ar_sp0_i.burst=t.burst; end
            MID_SP1: begin vif.ar_sp1_valid=1; vif.ar_sp1_i.addr=t.addr; vif.ar_sp1_i.id=t.id;
                          vif.ar_sp1_i.size=t.size; vif.ar_sp1_i.len=t.len; vif.ar_sp1_i.burst=t.burst; end
            MID_D:   begin vif.ar_d_valid=1; vif.ar_d_i.addr=t.addr; vif.ar_d_i.id=t.id;
                          vif.ar_d_i.size=t.size; vif.ar_d_i.len=t.len; vif.ar_d_i.burst=t.burst; end
            MID_I:   begin vif.ar_i_valid=1; vif.ar_i_i.addr=t.addr; vif.ar_i_i.id=t.id;
                          vif.ar_i_i.size=t.size; vif.ar_i_i.len=t.len; vif.ar_i_i.burst=t.burst; end
        endcase
        @(negedge axi_tb.CLK);

        case (t.mid)
            MID_SP0: begin while (!vif.ar_sp0_ready) @(negedge axi_tb.CLK); vif.ar_sp0_valid=0; vif.ar_sp0_i='0; end
            MID_SP1: begin while (!vif.ar_sp1_ready) @(negedge axi_tb.CLK); vif.ar_sp1_valid=0; vif.ar_sp1_i='0; end
            MID_D:   begin while (!vif.ar_d_ready)   @(negedge axi_tb.CLK); vif.ar_d_valid=0;   vif.ar_d_i='0;   end
            MID_I:   begin while (!vif.ar_i_ready)   @(negedge axi_tb.CLK); vif.ar_i_valid=0;   vif.ar_i_i='0;   end
        endcase
    endtask

endclass

class r_driver;
    virtual axi_bus_if vif;
    mailbox #(r_txn) mbx_drv_r;
    scoreboard scb;

    function new(
        virtual axi_bus_if vif, 
        mailbox #(r_txn) mbx_drv_r,
        scoreboard scb
    );
        this.vif = vif;
        this.mbx_drv_r = mbx_drv_r;
        this.scb = scb;
    endfunction

    task run();
        r_txn t;
        forever begin
            mbx_drv_r.get(t);
            drive(t);
        end
    endtask

    task drive(r_txn t);
        @(posedge axi_tb.CLK);
        set_ready(t.mid, 1);
        for (int i=0; i<$urandom_range(0,3); i++) @(posedge axi_tb.CLK);

        vif.r_valid = 1;
        vif.r_i.mid = t.mid;
        vif.r_i.id = t.id;
        vif.r_i.resp = t.resp;
        vif.r_i.last = 0;

        for (int i = 0; i <= t.len; i++) begin
            vif.r_i.data = {$urandom, $urandom};
            vif.r_i.last = (i == t.len);

            t.last = vif.r_i.last; t.data = vif.r_i.data;
            scb.push_r_exp(t);
            $display("send r data: mid=%0d data=%h id=%h len=%0d", $time, t.mid, t.data, t.id, t.len);

            
            @(posedge axi_tb.CLK);
        end

        vif.r_valid = 0; vif.r_i = '0;
        set_ready(t.mid, 0);
    endtask

    task set_ready(logic [1:0] mid, logic val);
        case (mid)
            MID_SP0: vif.r_sp0_o_ready = val;
            MID_SP1: vif.r_sp1_o_ready = val;
            MID_D:   vif.r_d_o_ready   = val;
            MID_I:   vif.r_i_o_ready   = val;
        endcase
    endtask
endclass

// Combined AW+W driver: AW and first W beat are asserted simultaneously.
// The handshake completes only when both aw_spX_i_ready AND w_spX_i_ready
// are high on the same cycle.  After the first beat is accepted, AW is
// deasserted and remaining burst beats stream out with w_o_ready held high.
class write_driver;
    logic [1:0] mid;
    scoreboard scb;
    virtual axi_bus_if vif;
    mailbox #(aw_txn) mbx_drv_write;

    function new(
        logic [1:0] mid,
        scoreboard scb,
        virtual axi_bus_if vif,
        mailbox #(aw_txn) mbx_drv_write
    );
        this.mid = mid;
        this.scb = scb;
        this.vif = vif;
        this.mbx_drv_write = mbx_drv_write;
    endfunction

    task run();
        aw_txn t;
        forever begin
            mbx_drv_write.get(t);
            scb.push_aw_exp(t, t.mid);
            drive(t);
            $display("[%0t] write done: mid=%0d addr=%h id=%h len=%0d",
                     $time, t.mid, t.addr, t.id, t.len);
        end
    endtask

    task drive(aw_txn t);
        w_txn wt;
        logic [WDATA-1:0] rand_data;
        logic [WSTRB-1:0] rand_strb;

        // ---- Beat 0: generate data and push expected ----
        rand_data = {$urandom, $urandom};
        rand_strb = $urandom;
        wt = new();
        wt.mid = t.mid; wt.id = t.id; wt.len = t.len;
        wt.data = rand_data; wt.strb = rand_strb; wt.last = (t.len == 0);
        scb.push_w_exp(wt);

        // Assert AW valid + beat-0 W valid simultaneously
        // @(negedge axi_tb.CLK);
        case (t.mid)
            0: begin
                vif.aw_sp0_i_valid=1; vif.aw_sp0_i.addr=t.addr; vif.aw_sp0_i.id=t.id;
                vif.aw_sp0_i.size=t.size; vif.aw_sp0_i.len=t.len; vif.aw_sp0_i.burst=t.burst;
                vif.w_sp0_i_valid=1; vif.w_sp0_i.data=rand_data; vif.w_sp0_i.id=t.id;
                vif.w_sp0_i.strb=rand_strb; vif.w_sp0_i.last=wt.last;
            end
            1: begin
                vif.aw_sp1_i_valid=1; vif.aw_sp1_i.addr=t.addr; vif.aw_sp1_i.id=t.id;
                vif.aw_sp1_i.size=t.size; vif.aw_sp1_i.len=t.len; vif.aw_sp1_i.burst=t.burst;
                vif.w_sp1_i_valid=1; vif.w_sp1_i.data=rand_data; vif.w_sp1_i.id=t.id;
                vif.w_sp1_i.strb=rand_strb; vif.w_sp1_i.last=wt.last;
            end
            2: begin
                vif.aw_d_i_valid=1; vif.aw_d_i.addr=t.addr; vif.aw_d_i.id=t.id;
                vif.aw_d_i.size=t.size; vif.aw_d_i.len=t.len; vif.aw_d_i.burst=t.burst;
                vif.w_d_i_valid=1; vif.w_d_i.data=rand_data; vif.w_d_i.id=t.id;
                vif.w_d_i.strb=rand_strb; vif.w_d_i.last=wt.last;
            end
        endcase

        // Wait until BOTH aw_ready AND w_ready are high on the same cycle
        // @(negedge axi_tb.CLK);
        case (t.mid)
            0: begin
                if (vif.aw_sp0_i_ready && vif.w_sp0_i_ready) begin @(negedge axi_tb.CLK); vif.aw_sp0_i_valid=0; vif.aw_sp0_i='0; end
                else begin
                    while (!(vif.aw_sp0_i_ready && vif.w_sp0_i_ready)) @(negedge axi_tb.CLK); @(negedge axi_tb.CLK);
                    vif.aw_sp0_i_valid=0; vif.aw_sp0_i='0;
                end
                
            end
            1: begin
                if (vif.aw_sp1_i_ready && vif.w_sp1_i_ready) begin @(negedge axi_tb.CLK); vif.aw_sp1_i_valid=0; vif.aw_sp1_i='0; end
                else begin
                    while (!(vif.aw_sp1_i_ready && vif.w_sp1_i_ready)) @(negedge axi_tb.CLK); @(negedge axi_tb.CLK);
                    vif.aw_sp1_i_valid=0; vif.aw_sp1_i='0;
                end
            end
            2: begin
                if (vif.aw_d_i_ready && vif.w_d_i_ready) begin @(negedge axi_tb.CLK); vif.aw_d_i_valid=0; vif.aw_d_i='0; end
                else begin
                    while (!(vif.aw_d_i_ready && vif.w_d_i_ready)) @(negedge axi_tb.CLK); @(negedge axi_tb.CLK);
                    vif.aw_d_i_valid=0; vif.aw_d_i='0;
                end
            end
        endcase

        // ---- Remaining beats (1..len): stream with w_o_ready held high ----
        for (int i = 1; i <= t.len; i++) begin
            rand_data = {$urandom, $urandom};
            rand_strb = $urandom;
            wt = new();
            wt.mid = t.mid; wt.id = t.id; wt.len = t.len;
            wt.data = rand_data; wt.strb = rand_strb; wt.last = (i == t.len);
            scb.push_w_exp(wt);

            // @(negedge axi_tb.CLK);
            case (t.mid)
                0: begin vif.w_sp0_i.data=rand_data; vif.w_sp0_i.strb=rand_strb; vif.w_sp0_i.last=wt.last; end
                1: begin vif.w_sp1_i.data=rand_data; vif.w_sp1_i.strb=rand_strb; vif.w_sp1_i.last=wt.last; end
                2: begin vif.w_d_i.data=rand_data;   vif.w_d_i.strb=rand_strb;   vif.w_d_i.last=wt.last;   end
            endcase

            @(negedge axi_tb.CLK);
            case (t.mid)
                0: while (!vif.w_sp0_i_ready) @(negedge axi_tb.CLK);
                1: while (!vif.w_sp1_i_ready) @(negedge axi_tb.CLK);
                2: while (!vif.w_d_i_ready)   @(negedge axi_tb.CLK);
            endcase
        end

        // Deassert W valid
        case (t.mid)
            0: begin vif.w_sp0_i_valid=0; vif.w_sp0_i='0; end
            1: begin vif.w_sp1_i_valid=0; vif.w_sp1_i='0; end
            2: begin vif.w_d_i_valid=0;   vif.w_d_i='0;   end
        endcase
    endtask
endclass

class ar_monitor; // monitor actual ar_o signal from DUT
    virtual axi_bus_if vif;
    mailbox #(sub_ar_channel_t) mbx_mon_ar;

    function new(
        virtual axi_bus_if vif,
        mailbox #(sub_ar_channel_t) mbx_mon_ar
    );
        this.vif = vif;
        this.mbx_mon_ar = mbx_mon_ar;

    endfunction

    task run();
        forever begin
            @(posedge axi_tb.CLK); #3;
            if (vif.ar_o_ready & vif.ar_o_valid) begin mbx_mon_ar.put(vif.ar_o); end
        end
        
    endtask
endclass

class r_monitor;
    virtual axi_bus_if vif;
    mailbox #(master_r_channel_t) mbx_mon_r;

    function new(
        virtual axi_bus_if vif,
        mailbox #(master_r_channel_t) mbx_mon_r
    );
        this.vif = vif;
        this.mbx_mon_r = mbx_mon_r;
    endfunction

    task run(); // transaction will only happen when handshake, and will not interrupt
        forever begin
            @(posedge axi_tb.CLK); #3;
            if (vif.r_ready && vif.r_valid) begin
                casez (vif.r_i.mid)
                    MID_SP0: mbx_mon_r.put(vif.r_sp0_o);
                    MID_SP1: mbx_mon_r.put(vif.r_sp1_o);
                    MID_D:   mbx_mon_r.put(vif.r_d_o);
                    MID_I:   mbx_mon_r.put(vif.r_i_o);
                endcase
            end
        end
    endtask

endclass

class aw_monitor;
    virtual axi_bus_if vif;
    mailbox #(sub_aw_channel_t) mbx_mon_aw;

    function new(
        virtual axi_bus_if vif,
        mailbox #(sub_aw_channel_t) mbx_mon_aw
    );
        this.vif = vif;
        this.mbx_mon_aw = mbx_mon_aw;
    endfunction

    task run();
        forever begin
            @(posedge axi_tb.CLK); #3;
            if (vif.aw_o_valid & vif.aw_o_ready) mbx_mon_aw.put(vif.aw_o);
        end
    endtask
endclass

class w_monitor;
    virtual axi_bus_if vif;
    mailbox #(sub_w_channel_t) mbx_mon_w;

    function new(
        virtual axi_bus_if vif,
        mailbox #(sub_w_channel_t) mbx_mon_w
    );
        this.vif = vif;
        this.mbx_mon_w = mbx_mon_w;
    endfunction

    task run();
        forever begin
            @(posedge axi_tb.CLK); #3;
            if (vif.w_o_valid === 1 & vif.w_o_ready === 1) mbx_mon_w.put(vif.w_o);

        end
    endtask
endclass

class scoreboard;
    mailbox #(sub_ar_channel_t) mbx_mon_ar;
    mailbox #(master_r_channel_t) mbx_mon_r;
    mailbox #(sub_aw_channel_t) mbx_mon_aw;
    mailbox #(sub_w_channel_t) mbx_mon_w;

    ar_txn exp_ar_q[4][$];
    r_txn exp_r_q[$];
    aw_txn exp_aw_q[3][$]; // SP0=0, SP1=1, D$=2
    w_txn exp_w_q[3][$];   // per-master beat queue: SP0=0, SP1=1, D$=2

    int fail_cnt=0;
    int pass_cnt=0;

    function new(
        mailbox #(sub_ar_channel_t) mbx_mon_ar,
        mailbox #(master_r_channel_t) mbx_mon_r,
        mailbox #(sub_aw_channel_t) mbx_mon_aw,
        mailbox #(sub_w_channel_t) mbx_mon_w
    );
        this.mbx_mon_ar = mbx_mon_ar;
        this.mbx_mon_r = mbx_mon_r;
        this.mbx_mon_aw = mbx_mon_aw;
        this.mbx_mon_w = mbx_mon_w;
    endfunction

    task check_ar();
        ar_txn exp;
        sub_ar_channel_t mon;

        forever begin
            int err=0;
            mbx_mon_ar.get(mon);
            if (exp_ar_q[mon.mid].size() == 0) begin fail_cnt++; continue; end

            exp = exp_ar_q[mon.mid].pop_front();
            if (mon.addr != exp.addr) begin err=1; $error("addr, [exp:obs] [%h,%h]", exp.addr, mon.addr); end
            if (mon.id != exp.id) begin err=1; $error("id, [exp:obs] [%h,%h]", exp.id, mon.id); end
            if (mon.size != exp.size) begin err=1; $error("size, [exp:obs] [%h,%h]", exp.size, mon.size); end
            if (mon.len != exp.len) begin err=1; $error("len, [exp:obs] [%h,%h]", exp.len, mon.len); end
            if (mon.burst != exp.burst) begin err=1; $error("burst, [exp:obs] [%h,%h]", exp.burst, mon.burst); end
            if (err == 1) fail_cnt++; else pass_cnt++;
        end
    endtask

    task check_r();
        r_txn exp;
        master_r_channel_t mon;

        forever begin
            int err=0;
            mbx_mon_r.get(mon);
            if (exp_r_q.size() == 0) begin fail_cnt++; continue; end

            exp = exp_r_q.pop_front();
            if (mon.data != exp.data) begin err=1; $error("r data, [exp:obs] [%h,%h]", exp.data, mon.data); end
            if (mon.id != exp.id) begin err=1; $error("r id, [exp:obs] [%h,%h]", exp.id, mon.id); end
            if (mon.last != exp.last) begin err=1; $error("r last, [exp:obs] [%h,%h]", exp.last, mon.last); end
            if (mon.resp != exp.resp) begin err=1; $error("r resp, [exp:obs] [%h,%h]", exp.resp, mon.resp); end
            if (err == 1) fail_cnt++; else pass_cnt++;
        end
    endtask

    task check_aw();
        aw_txn exp;
        sub_aw_channel_t mon;
        // mid is in the upper MID bits of mid_id: mid_id[MID_AWID-1:AWID]
        logic [1:0] mid;

        forever begin
            int err=0;
            mbx_mon_aw.get(mon);
            mid = mon.mid_id[MID_AWID-1:AWID];
            if (exp_aw_q[mid].size() == 0) begin fail_cnt++; continue; end

            exp = exp_aw_q[mid].pop_front();
            if (mon.addr != exp.addr) begin err=1; $error("aw addr, [exp:obs] [%h,%h]", exp.addr, mon.addr); end
            if (mon.mid_id[AWID-1:0] != exp.id) begin err=1; $error("aw id, [exp:obs] [%h,%h]", exp.id, mon.mid_id[AWID-1:0]); end
            if (mon.size != exp.size) begin err=1; $error("aw size, [exp:obs] [%h,%h]", exp.size, mon.size); end
            if (mon.len != exp.len) begin err=1; $error("aw len, [exp:obs] [%h,%h]", exp.len, mon.len); end
            if (mon.burst != exp.burst) begin err=1; $error("aw burst, [exp:obs] [%h,%h]", exp.burst, mon.burst); end
            if (err == 1) fail_cnt++; else pass_cnt++;
        end
    endtask

    task check_w();
        w_txn exp;
        sub_w_channel_t mon;
        logic [1:0] mid;

        forever begin
            int err=0;
            mbx_mon_w.get(mon);
            // mid_id format: {mid[1:0], id[WID-1:0]}
            mid = mon.mid_id[MID_WID-1:WID];
            if (exp_w_q[mid].size() == 0) begin fail_cnt++; continue; end

            exp = exp_w_q[mid].pop_front();
            $display("pop:[mid,data] [%0h,%0h] at %t", exp.mid, exp.data, $time);
            if (mon.mid_id != {exp.mid, exp.id}) begin err=1; $error("w mid_id, [exp:obs] [%h,%h]", {exp.mid, exp.id}, mon.mid_id); end
            if (mon.data != exp.data)             begin err=1; $error("w data, [exp:obs] [%h,%h]", exp.data, mon.data); end
            if (mon.strb != exp.strb)             begin err=1; $error("w strb, [exp:obs] [%h,%h]", exp.strb, mon.strb); end
            if (mon.last != exp.last)             begin err=1; $error("w last, [exp:obs] [%h,%h]", exp.last, mon.last); end
            if (err == 1) fail_cnt++; else pass_cnt++;
        end
    endtask

    task push_ar_exp(
        ar_txn exp,
        logic [1:0] mid
    );
        this.exp_ar_q[mid].push_back(exp);
    endtask

    task push_r_exp(
        r_txn exp
    );
        this.exp_r_q.push_back(exp);
    endtask

    task push_aw_exp(
        aw_txn exp,
        logic [1:0] mid
    );
        this.exp_aw_q[mid].push_back(exp);
    endtask

    task push_w_exp(
        w_txn exp
    );
        this.exp_w_q[exp.mid].push_back(exp);
        $display("push: [mid,data] [%0h, %0h]", exp.mid, exp.data);
    endtask

    task report();
        $display("===== REPORT =====");
        $display("PASS: %0d, FAIL: %0d", pass_cnt, fail_cnt);
        $display("REMAIN AR: %0d, REMAIN R: %0d",
            exp_ar_q[0].size()+exp_ar_q[1].size()+exp_ar_q[2].size()+exp_ar_q[3].size(),
            exp_r_q.size());
        $display("REMAIN AW: %0d, REMAIN W beats: %0d",
            exp_aw_q[0].size()+exp_aw_q[1].size()+exp_aw_q[2].size(),
            exp_w_q[0].size()+exp_w_q[1].size()+exp_w_q[2].size());
    endtask

    task run();
        fork
            check_ar();
            check_r();
            check_aw();
            check_w();
        join_none
    endtask
endclass








