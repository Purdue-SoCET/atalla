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

module axi_tb;

    parameter PERIOD = 10;

    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;

    axi_bus_if abif(CLK, nRST);
    axi DUT(CLK, nRST, abif);
    test PROG(CLK, nRST, abif);

    // --- SVA ---
    property ar_arbit_onehot;
        @(posedge CLK) disable iff (!nRST)
        $onehot0({abif.sp0_pop, abif.sp1_pop, abif.i_pop, abif.d_pop});
    endproperty
    property sp0_pop_req; @(posedge CLK) disable iff (!nRST) abif.sp0_pop |-> abif.sp0_req_r; endproperty
    property sp1_pop_req; @(posedge CLK) disable iff (!nRST) abif.sp1_pop |-> abif.sp1_req_r; endproperty
    property i_pop_req;   @(posedge CLK) disable iff (!nRST) abif.i_pop   |-> abif.i_req_r;   endproperty
    property d_pop_req;   @(posedge CLK) disable iff (!nRST) abif.d_pop   |-> abif.d_req_r;   endproperty
    property router_onehot;
        @(posedge CLK) disable iff (!nRST)
        $onehot0({abif.r_sp0_o_valid, abif.r_sp1_o_valid, abif.r_i_o_valid, abif.r_d_o_valid});
    endproperty
    property r_validX;
        @(posedge CLK) disable iff (!nRST)
        !abif.r_valid |-> !abif.r_sp0_o_valid && !abif.r_sp1_o_valid && !abif.r_i_o_valid && !abif.r_d_o_valid;
    endproperty

    assert property (ar_arbit_onehot) else $error("SVA: AR arbiter grant not onehot");
    assert property (sp0_pop_req)     else $error("SVA: sp0 pop when no request");
    assert property (sp1_pop_req)     else $error("SVA: sp1 pop when no request");
    assert property (i_pop_req)       else $error("SVA: i pop when no request");
    assert property (d_pop_req)       else $error("SVA: d pop when no request");
    assert property (router_onehot)   else $error("SVA: R router output not onehot");
    assert property (r_validX)        else $error("SVA: R master valid without sub valid");

endmodule

// ============================================================================
// Test program
// ============================================================================
program test(
    input logic CLK,
    output logic nRST,
    axi_bus_if abif
);
    environment env;
    int TIME_OUT = 50000;

    // ----- Reset -----
    task automatic reset_input();
        // Read path
        abif.ar_sp0_valid  = 0; abif.ar_sp0_i = '0;
        abif.ar_sp1_valid  = 0; abif.ar_sp1_i = '0;
        abif.ar_i_valid    = 0; abif.ar_i_i   = '0;
        abif.ar_d_valid    = 0; abif.ar_d_i   = '0;
        abif.r_sp0_o_ready = 0;
        abif.r_sp1_o_ready = 0;
        abif.r_i_o_ready   = 0;
        abif.r_d_o_ready   = 0;
        abif.r_valid       = 0; abif.r_i      = '0;
        abif.ar_o_ready    = 0;

        // Write path
        abif.sp0_i_valid   = 0; abif.aw_sp0_i = '0; abif.w_sp0_i = '0;
        abif.sp1_i_valid   = 0; abif.aw_sp1_i = '0; abif.w_sp1_i = '0;
        abif.d_i_valid     = 0; abif.aw_d_i   = '0; abif.w_d_i   = '0;
        abif.aw_o_ready    = 0;
        abif.w_o_ready     = 0;
        abif.b_sp0_o_ready = 0;
        abif.b_sp1_o_ready = 0;
        abif.b_d_o_ready   = 0;
        abif.b_i_valid     = 0; abif.b_i      = '0;
    endtask

    task automatic reset_dut();
        nRST = 0;
        reset_input();
        repeat (3) @(negedge CLK);
        nRST = 1;
    endtask

    // ----- Transaction generators -----
    task automatic gen_ar_txn(ref ar_txn q[$], input int times, input int force_mid = -1);
        for (int i = 0; i < times; i++) begin
            ar_txn t = new();
            if (force_mid >= 0) begin t.force_mid = force_mid; t.c_force_mid.constraint_mode(1); end
            t.randomize();
            q.push_back(t);
        end
    endtask

    task automatic gen_r_txn(ref r_txn q[$], input int times, input int mid = -1);
        for (int i = 0; i < times; i++) begin
            r_txn t = new();
            if (mid >= 0) begin t.c_force_mid.constraint_mode(1); t.force_mid = mid; end
            t.randomize();
            q.push_back(t);
        end
    endtask

    task automatic gen_aw_txn(ref aw_txn q[$], input int times,
                              input int force_mid = -1, input int force_len = -1);
        for (int i = 0; i < times; i++) begin
            aw_txn t = new();
            if (force_mid >= 0) begin t.force_mid = force_mid; t.c_force_mid.constraint_mode(1); end
            if (force_len >= 0) begin t.force_len = force_len; t.c_force_len.constraint_mode(1); end
            t.randomize();
            q.push_back(t);
        end
    endtask

    // ----- Slave-side ready helpers -----
    task automatic random_ar_ready(int cycles);
        for (int i = 0; i < cycles; i++) begin
            @(posedge CLK); #1;
            if ($urandom_range(0,1)) abif.ar_o_ready = $urandom_range(0,1);
        end
        abif.ar_o_ready = 1;
        repeat (20) @(negedge CLK);
        abif.ar_o_ready = 0;
    endtask

    task automatic random_write_ready(int cycles);
        for (int i = 0; i < cycles; i++) begin
            @(posedge CLK); #1;
            if ($urandom_range(0,1)) begin
                logic val = $urandom_range(0,1);
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

    // ----- Test scenarios -----
    task automatic smoke_ar_test();
        ar_txn q[$];
        gen_ar_txn(q, 4);
        foreach (q[i]) env.send_ar_req(q[i]);
        random_ar_ready(100);
    endtask

    task automatic pressure_ar_test(int num_test);
        ar_txn q[$];
        for (int i = 0; i < num_test; i++) gen_ar_txn(q, 1, $urandom_range(0,3));
        foreach (q[i]) env.send_ar_req(q[i]);
        random_ar_ready(num_test * 4);
    endtask

    task automatic idle_ar_test();
        random_ar_ready(50);
    endtask

    task automatic smoke_r_test();
        r_txn q[$];
        gen_r_txn(q, 1);
        foreach (q[i]) env.send_r_req(q[i]);
        repeat (20) @(negedge CLK);
    endtask

    task automatic pressure_r_test(int num_test);
        r_txn q[$];
        for (int i = 0; i < num_test; i++) gen_r_txn(q, 1, $urandom_range(0,3));
        foreach (q[i]) env.send_r_req(q[i]);
        repeat (num_test * 20 + 10) @(negedge CLK);
    endtask

    task automatic idle_r_test();
        @(posedge CLK); #1;
        abif.r_sp0_o_ready = 1; abif.r_sp1_o_ready = 1;
        abif.r_i_o_ready   = 1; abif.r_d_o_ready   = 1;
        repeat (20) @(negedge CLK);
        abif.r_sp0_o_ready = 0; abif.r_sp1_o_ready = 0;
        abif.r_i_o_ready   = 0; abif.r_d_o_ready   = 0;
        @(negedge CLK);
    endtask

    task automatic smoke_write_test();
        aw_txn q[$];
        gen_aw_txn(q, 3);
        foreach (q[i]) env.send_write_req(q[i]);
        steady_write_ready(100);
    endtask

    task automatic pressure_write_test(int num_test);
        aw_txn q[$];
        for (int i = 0; i < num_test; i++) gen_aw_txn(q, 1, $urandom_range(0,2));
        foreach (q[i]) env.send_write_req(q[i]);
        steady_write_ready(num_test * 16);
    endtask

    task automatic idle_write_test();
        random_write_ready(50);
    endtask

    task automatic consecutive_write_test(int master_id, int len, int num_txn);
        aw_txn q[$];
        gen_aw_txn(q, num_txn, master_id, len);
        foreach (q[i]) env.send_write_req(q[i]);
        steady_write_ready(num_txn * 20 + 50);
    endtask

    // ----- Main -----
    initial begin
        env = new(abif); env.start();
        reset_dut();

        // smoke_ar_test();
        // pressure_ar_test(100);
        // idle_ar_test();

        // smoke_r_test();
        // pressure_r_test(10);
        // idle_r_test();

        // smoke_write_test();
        // pressure_write_test(7);
        // idle_write_test();

        consecutive_write_test(1, -1, 6);

        env.report();
        $finish;
    end

    initial begin
        #(TIME_OUT);
        $display("\nTIMEOUT: maybe a deadlock happening.");
        $finish;
    end

endprogram

// ============================================================================
// Transactions
// ============================================================================
class ar_txn;
    rand logic [1:0]          mid;
    rand logic [ARADDR-1:0]   addr;
    rand logic [ARID-1:0]     id;
    rand logic [ARSIZE-1:0]   size;
    rand logic [ARLEN-1:0]    len;
    rand logic [ARBURST-1:0]  burst;

    logic [1:0] force_mid;
    constraint c_force_mid { mid == force_mid; }

    function new();
        c_force_mid.constraint_mode(0);
    endfunction
endclass

class r_txn;
    rand logic [1:0]         mid;
    rand logic [RDATA-1:0]   data;
    rand logic [RID-1:0]     id;
    rand rresp_t             resp;
    rand logic               last;
    rand logic [ARLEN-1:0]   len;

    logic [1:0] force_mid;

    constraint c_resp      { resp inside {R_OKAY, R_EXOKAY, R_SLVERR, R_DECERR}; }
    constraint c_force_mid { mid == force_mid; }

    function new();
        c_force_mid.constraint_mode(0);
    endfunction
endclass

class aw_txn;
    rand logic [1:0]          mid;
    rand logic [AWADDR-1:0]   addr;
    rand logic [AWID-1:0]     id;
    rand logic [AWSIZE-1:0]   size;
    rand logic [AWLEN-1:0]    len;
    rand logic [AWBURST-1:0]  burst;

    logic [1:0] force_mid;
    logic [3:0] force_len;

    constraint c_mid_valid { mid inside {0, 1, 2}; }
    constraint c_force_mid { mid == force_mid; }
    constraint c_force_len { len == force_len; }
    constraint c_burst     { burst != 2'b11; }
    constraint c_len       { len <= 7; }

    function new();
        c_force_mid.constraint_mode(0);
        c_force_len.constraint_mode(0);
        c_burst.constraint_mode(0);
        c_len.constraint_mode(1);
    endfunction
endclass

class w_txn;
    rand logic [1:0]         mid;
    rand logic [WID-1:0]     id;
    rand logic [AWLEN-1:0]   len;
    logic [WDATA-1:0]        data;
    logic                    last;
    logic [WSTRB-1:0]        strb;

    constraint c_len       { len <= 7; }
    constraint c_mid_valid { mid inside {0, 1, 2}; }
endclass

// ============================================================================
// Drivers
// ============================================================================
class ar_driver;
    logic [1:0]           mid;
    scoreboard            scb;
    virtual axi_bus_if    vif;
    mailbox #(ar_txn)     mbx;

    function new(logic [1:0] mid, scoreboard scb, virtual axi_bus_if vif, mailbox #(ar_txn) mbx);
        this.mid = mid; this.scb = scb; this.vif = vif; this.mbx = mbx;
    endfunction

    task run();
        ar_txn t;
        forever begin
            mbx.get(t);
            scb.push_ar_exp(t, t.mid);
            drive(t);
            $display("[%0t] AR: mid=%0d addr=%h id=%h len=%0d", $time, t.mid, t.addr, t.id, t.len);
        end
    endtask

    task drive(ar_txn t);
        @(negedge axi_tb.CLK);
        set_valid(1); set_payload(t);
        @(negedge axi_tb.CLK);
        set_valid(0); clear_payload();
    endtask

    task set_valid(logic v);
        case (mid)
            MID_SP0: vif.ar_sp0_valid = v;
            MID_SP1: vif.ar_sp1_valid = v;
            MID_D:   vif.ar_d_valid   = v;
            MID_I:   vif.ar_i_valid   = v;
        endcase
    endtask

    task set_payload(ar_txn t);
        case (mid)
            MID_SP0: begin vif.ar_sp0_i.addr=t.addr; vif.ar_sp0_i.id=t.id;
                           vif.ar_sp0_i.size=t.size; vif.ar_sp0_i.len=t.len; vif.ar_sp0_i.burst=t.burst; end
            MID_SP1: begin vif.ar_sp1_i.addr=t.addr; vif.ar_sp1_i.id=t.id;
                           vif.ar_sp1_i.size=t.size; vif.ar_sp1_i.len=t.len; vif.ar_sp1_i.burst=t.burst; end
            MID_D:   begin vif.ar_d_i.addr=t.addr; vif.ar_d_i.id=t.id;
                           vif.ar_d_i.size=t.size; vif.ar_d_i.len=t.len; vif.ar_d_i.burst=t.burst; end
            MID_I:   begin vif.ar_i_i.addr=t.addr; vif.ar_i_i.id=t.id;
                           vif.ar_i_i.size=t.size; vif.ar_i_i.len=t.len; vif.ar_i_i.burst=t.burst; end
        endcase
    endtask

    task clear_payload();
        case (mid)
            MID_SP0: vif.ar_sp0_i = '0;
            MID_SP1: vif.ar_sp1_i = '0;
            MID_D:   vif.ar_d_i   = '0;
            MID_I:   vif.ar_i_i   = '0;
        endcase
    endtask
endclass

class r_driver;
    virtual axi_bus_if    vif;
    mailbox #(r_txn)      mbx;
    scoreboard            scb;

    function new(virtual axi_bus_if vif, mailbox #(r_txn) mbx, scoreboard scb);
        this.vif = vif; this.mbx = mbx; this.scb = scb;
    endfunction

    task run();
        r_txn t;
        forever begin
            mbx.get(t);
            drive(t);
        end
    endtask

    task drive(r_txn t);
        @(posedge axi_tb.CLK);
        set_ready(t.mid, 1);
        for (int i = 0; i < $urandom_range(0,3); i++) @(posedge axi_tb.CLK);

        vif.r_valid  = 1;
        vif.r_i.mid  = t.mid;
        vif.r_i.id   = t.id;
        vif.r_i.resp = t.resp;
        vif.r_i.last = 0;

        for (int i = 0; i <= t.len; i++) begin
            vif.r_i.data = {$urandom, $urandom};
            vif.r_i.last = (i == t.len);
            t.last = vif.r_i.last; t.data = vif.r_i.data;
            scb.push_r_exp(t);
            $display("[%0t] R: mid=%0d data=%h id=%h beat=%0d/%0d",
                     $time, t.mid, t.data, t.id, i, t.len);
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

class write_driver;
    logic [1:0]           mid;
    scoreboard            scb;
    virtual axi_bus_if    vif;
    mailbox #(aw_txn)     mbx;

    function new(logic [1:0] mid, scoreboard scb, virtual axi_bus_if vif, mailbox #(aw_txn) mbx);
        this.mid = mid; this.scb = scb; this.vif = vif; this.mbx = mbx;
    endfunction

    task run();
        aw_txn t;
        forever begin
            mbx.get(t);
            scb.push_aw_exp(t, t.mid);
            drive(t);
            $display("[%0t] WR done: mid=%0d addr=%h id=%h len=%0d (W beats=%0d)",
                     $time, t.mid, t.addr, t.id, t.len, t.len + 1);
        end
    endtask

    // task drive(aw_txn t);
    //     w_txn wt;
    //     logic [WDATA-1:0] dat;
    //     logic [WSTRB-1:0] stb;

    //     // Beat 0: AW + W fire on a single unified handshake
    //     @(negedge axi_tb.CLK);
    //     dat = {$urandom, $urandom}; stb = $urandom;
    //     wt = new();
    //     wt.mid = t.mid; wt.id = t.id; wt.len = t.len;
    //     wt.data = dat; wt.strb = stb; wt.last = (t.len == 0);
    //     scb.push_w_exp(wt);

    //     set_valid(1'b1);
    //     set_aw(t);
    //     set_w(t.id, dat, stb, wt.last);

    //     // do @(posedge axi_tb.CLK); while (!get_wr_ready());
    //     if (get_wr_ready()) @(negedge axi_tb.CLK);
    //     else begin
    //         while (!get_wr_ready()) @(negedge axi_tb.CLK); @(negedge axi_tb.CLK);
    //     end
    //     clear_aw();

    //     // Beats 1..len: only W changes
    //     for (int i = 1; i <= t.len; i++) begin
    //         dat = {$urandom, $urandom}; stb = $urandom;
    //         wt = new();
    //         wt.mid = t.mid; wt.id = t.id; wt.len = t.len;
    //         wt.data = dat; wt.strb = stb; wt.last = (i == t.len);
    //         scb.push_w_exp(wt);

    //         set_w(t.id, dat, stb, wt.last);
    //         //do @(posedge axi_tb.CLK); while (!get_wr_ready());
    //         if (get_wr_ready()) @(negedge axi_tb.CLK);
    //         else begin
    //             while (!get_wr_ready()) @(negedge axi_tb.CLK); @(negedge axi_tb.CLK);
    //         end
    //     end

    //     set_valid(1'b0);
    //     clear_w();
    // endtask

    task drive(aw_txn t);
        w_txn wt;
        logic [WDATA-1:0] dat;
        logic [WSTRB-1:0] stb;

        // Beat 0: AW + W fire on a single unified handshake
        @(negedge axi_tb.CLK);
        dat = {$urandom, $urandom}; stb = $urandom;
        wt = new();
        wt.mid = t.mid; wt.id = t.id; wt.len = t.len;
        wt.data = dat; wt.strb = stb; wt.last = (t.len == 0);
        scb.push_w_exp(wt);

        set_valid(1'b1);
        set_aw(t);
        set_w(t.id, dat, stb, wt.last);

        // Initial handshake: Wait for ready to go high
        if (get_wr_ready()) @(negedge axi_tb.CLK);
        else begin
            while (!get_wr_ready()) @(negedge axi_tb.CLK); @(negedge axi_tb.CLK);
        end
        
        clear_aw();
        set_valid(1'b0); // Drop valid immediately after handshake

        // Beats 1..len: Stream continuously, ignoring ready
        for (int i = 1; i <= t.len; i++) begin
            dat = {$urandom, $urandom}; stb = $urandom;
            wt = new();
            wt.mid = t.mid; wt.id = t.id; wt.len = t.len;
            wt.data = dat; wt.strb = stb; wt.last = (i == t.len);
            scb.push_w_exp(wt);

            set_w(t.id, dat, stb, wt.last);
            
            // Just advance the clock one cycle. No ready check!
            @(negedge axi_tb.CLK);
        end
        clear_w();
    endtask

    function logic get_wr_ready();
        case (mid)
            0:       return vif.sp0_wr_ready;
            1:       return vif.sp1_wr_ready;
            2:       return vif.d_wr_ready;
            default: return 1'b0;
        endcase
    endfunction

    task set_valid(logic v);
        case (mid)
            0: vif.sp0_i_valid = v;
            1: vif.sp1_i_valid = v;
            2: vif.d_i_valid   = v;
        endcase
    endtask

    task set_aw(aw_txn t);
        case (mid)
            0: begin vif.aw_sp0_i.addr=t.addr; vif.aw_sp0_i.id=t.id;
                     vif.aw_sp0_i.size=t.size; vif.aw_sp0_i.len=t.len; vif.aw_sp0_i.burst=t.burst; end
            1: begin vif.aw_sp1_i.addr=t.addr; vif.aw_sp1_i.id=t.id;
                     vif.aw_sp1_i.size=t.size; vif.aw_sp1_i.len=t.len; vif.aw_sp1_i.burst=t.burst; end
            2: begin vif.aw_d_i.addr=t.addr; vif.aw_d_i.id=t.id;
                     vif.aw_d_i.size=t.size; vif.aw_d_i.len=t.len; vif.aw_d_i.burst=t.burst; end
        endcase
    endtask

    task clear_aw();
        case (mid)
            0: vif.aw_sp0_i = '0;
            1: vif.aw_sp1_i = '0;
            2: vif.aw_d_i   = '0;
        endcase
    endtask

    task set_w(logic [WID-1:0] id, logic [WDATA-1:0] d, logic [WSTRB-1:0] s, logic l);
        case (mid)
            0: begin vif.w_sp0_i.id=id; vif.w_sp0_i.data=d; vif.w_sp0_i.strb=s; vif.w_sp0_i.last=l; end
            1: begin vif.w_sp1_i.id=id; vif.w_sp1_i.data=d; vif.w_sp1_i.strb=s; vif.w_sp1_i.last=l; end
            2: begin vif.w_d_i.id=id;   vif.w_d_i.data=d;   vif.w_d_i.strb=s;   vif.w_d_i.last=l;   end
        endcase
    endtask

    task clear_w();
        case (mid)
            0: vif.w_sp0_i = '0;
            1: vif.w_sp1_i = '0;
            2: vif.w_d_i   = '0;
        endcase
    endtask
endclass

// ============================================================================
// Monitors (all sample at slave side)
// ============================================================================
class ar_monitor;
    virtual axi_bus_if             vif;
    mailbox #(sub_ar_channel_t)    mbx;

    function new(virtual axi_bus_if vif, mailbox #(sub_ar_channel_t) mbx);
        this.vif = vif; this.mbx = mbx;
    endfunction

    task run();
        forever begin
            @(posedge axi_tb.CLK); #3;
            if (vif.ar_o_ready & vif.ar_o_valid) mbx.put(vif.ar_o);
        end
    endtask
endclass

class r_monitor;
    virtual axi_bus_if              vif;
    mailbox #(master_r_channel_t)   mbx;

    function new(virtual axi_bus_if vif, mailbox #(master_r_channel_t) mbx);
        this.vif = vif; this.mbx = mbx;
    endfunction

    task run();
        forever begin
            @(posedge axi_tb.CLK); #3;
            if (vif.r_ready && vif.r_valid) begin
                casez (vif.r_i.mid)
                    MID_SP0: mbx.put(vif.r_sp0_o);
                    MID_SP1: mbx.put(vif.r_sp1_o);
                    MID_D:   mbx.put(vif.r_d_o);
                    MID_I:   mbx.put(vif.r_i_o);
                endcase
            end
        end
    endtask
endclass

class aw_monitor;
    logic [1:0]                    mid;
    virtual axi_bus_if             vif;
    mailbox #(sub_aw_channel_t)    mbx;

    function new(logic [1:0] mid, virtual axi_bus_if vif, mailbox #(sub_aw_channel_t) mbx);
        this.mid = mid; this.vif = vif; this.mbx = mbx;
    endfunction

    task run();
        forever begin
            @(posedge axi_tb.CLK); #3;
            if (vif.aw_o_valid && vif.aw_o_ready &&
                vif.aw_o.mid_id[MID_AWID-1:AWID] == mid)
                mbx.put(vif.aw_o);
        end
    endtask
endclass

class w_monitor;
    logic [1:0]                    mid;
    virtual axi_bus_if             vif;
    mailbox #(sub_w_channel_t)     mbx;

    function new(logic [1:0] mid, virtual axi_bus_if vif, mailbox #(sub_w_channel_t) mbx);
        this.mid = mid; this.vif = vif; this.mbx = mbx;
    endfunction

    task run();
        forever begin
            @(posedge axi_tb.CLK); #3;
            if (vif.w_o_valid && vif.w_o_ready &&
                vif.w_o.mid_id[MID_WID-1:WID] == mid)
                mbx.put(vif.w_o);
        end
    endtask
endclass

// ============================================================================
// Scoreboard
// ============================================================================
class scoreboard;
    mailbox #(sub_ar_channel_t)   mbx_mon_ar;
    mailbox #(master_r_channel_t) mbx_mon_r;
    mailbox #(sub_aw_channel_t)   mbx_mon_aw[3];
    mailbox #(sub_w_channel_t)    mbx_mon_w[3];

    ar_txn exp_ar_q[4][$];
    r_txn  exp_r_q[$];
    aw_txn exp_aw_q[3][$];
    w_txn  exp_w_q[3][$];

    int fail_cnt = 0;
    int pass_cnt = 0;

    function new(mailbox #(sub_ar_channel_t)   mbx_mon_ar,
                 mailbox #(master_r_channel_t) mbx_mon_r,
                 mailbox #(sub_aw_channel_t)   mbx_mon_aw[3],
                 mailbox #(sub_w_channel_t)    mbx_mon_w[3]);
        this.mbx_mon_ar = mbx_mon_ar;
        this.mbx_mon_r  = mbx_mon_r;
        foreach (mbx_mon_aw[i]) this.mbx_mon_aw[i] = mbx_mon_aw[i];
        foreach (mbx_mon_w[i])  this.mbx_mon_w[i]  = mbx_mon_w[i];
    endfunction

    // ----- Push expected -----
    task push_ar_exp(ar_txn exp, logic [1:0] mid);
        exp_ar_q[mid].push_back(exp);
    endtask

    task push_r_exp(r_txn exp);
        exp_r_q.push_back(exp);
    endtask

    task push_aw_exp(aw_txn exp, logic [1:0] mid);
        exp_aw_q[mid].push_back(exp);
    endtask

    task push_w_exp(w_txn exp);
        exp_w_q[exp.mid].push_back(exp);
    endtask

    // ----- Checkers -----
    task check_ar();
        sub_ar_channel_t mon;
        ar_txn exp;
        forever begin
            int err = 0;
            mbx_mon_ar.get(mon);
            if (exp_ar_q[mon.mid].size() == 0) begin fail_cnt++; continue; end
            exp = exp_ar_q[mon.mid].pop_front();
            if (mon.addr  != exp.addr)  begin err=1; $error("AR addr [exp:obs] [%h:%h]",  exp.addr,  mon.addr);  end
            if (mon.id    != exp.id)    begin err=1; $error("AR id [exp:obs] [%h:%h]",    exp.id,    mon.id);    end
            if (mon.size  != exp.size)  begin err=1; $error("AR size [exp:obs] [%h:%h]",  exp.size,  mon.size);  end
            if (mon.len   != exp.len)   begin err=1; $error("AR len [exp:obs] [%h:%h]",   exp.len,   mon.len);   end
            if (mon.burst != exp.burst) begin err=1; $error("AR burst [exp:obs] [%h:%h]", exp.burst, mon.burst); end
            if (err) fail_cnt++; else pass_cnt++;
        end
    endtask

    task check_r();
        master_r_channel_t mon;
        r_txn exp;
        forever begin
            int err = 0;
            mbx_mon_r.get(mon);
            if (exp_r_q.size() == 0) begin fail_cnt++; continue; end
            exp = exp_r_q.pop_front();
            if (mon.data != exp.data) begin err=1; $error("R data [exp:obs] [%h:%h]", exp.data, mon.data); end
            if (mon.id   != exp.id)   begin err=1; $error("R id [exp:obs] [%h:%h]",   exp.id,   mon.id);   end
            if (mon.last != exp.last) begin err=1; $error("R last [exp:obs] [%h:%h]", exp.last, mon.last); end
            if (mon.resp != exp.resp) begin err=1; $error("R resp [exp:obs] [%h:%h]", exp.resp, mon.resp); end
            if (err) fail_cnt++; else pass_cnt++;
        end
    endtask

    task check_aw(int mid);
        sub_aw_channel_t mon;
        aw_txn exp;
        forever begin
            int err = 0;
            mbx_mon_aw[mid].get(mon);
            if (exp_aw_q[mid].size() == 0) begin
                $error("AW mid=%0d: unexpected (empty queue)", mid);
                fail_cnt++; continue;
            end
            exp = exp_aw_q[mid].pop_front();
            if (mon.addr  != exp.addr)                begin err=1; $error("AW[%0d] addr [exp:obs] [%h:%h]",  mid, exp.addr,  mon.addr);  end
            if (mon.mid_id[AWID-1:0] != exp.id)       begin err=1; $error("AW[%0d] id [exp:obs] [%h:%h]",    mid, exp.id,    mon.mid_id[AWID-1:0]); end
            if (mon.mid_id[MID_AWID-1:AWID] != mid)   begin err=1; $error("AW[%0d] mid [exp:obs] [%h:%h]",   mid, mid,       mon.mid_id[MID_AWID-1:AWID]); end
            if (mon.size  != exp.size)                 begin err=1; $error("AW[%0d] size [exp:obs] [%h:%h]",  mid, exp.size,  mon.size);  end
            if (mon.len   != exp.len)                  begin err=1; $error("AW[%0d] len [exp:obs] [%h:%h]",   mid, exp.len,   mon.len);   end
            if (mon.burst != exp.burst)                begin err=1; $error("AW[%0d] burst [exp:obs] [%h:%h]", mid, exp.burst, mon.burst); end
            if (err) fail_cnt++; else pass_cnt++;
        end
    endtask

    task check_w(int mid);
        sub_w_channel_t mon;
        w_txn exp;
        forever begin
            int err = 0;
            mbx_mon_w[mid].get(mon);
            if (exp_w_q[mid].size() == 0) begin
                $error("W mid=%0d: unexpected (empty queue)", mid);
                fail_cnt++; continue;
            end
            exp = exp_w_q[mid].pop_front();
            if (mon.mid_id != {exp.mid, exp.id}) begin err=1; $error("W[%0d] mid_id [exp:obs] [%h:%h]", mid, {exp.mid, exp.id}, mon.mid_id); end
            if (mon.data   != exp.data)          begin err=1; $error("W[%0d] data [exp:obs] [%h:%h]",   mid, exp.data, mon.data);            end
            if (mon.strb   != exp.strb)          begin err=1; $error("W[%0d] strb [exp:obs] [%h:%h]",   mid, exp.strb, mon.strb);            end
            if (mon.last   != exp.last)          begin err=1; $error("W[%0d] last [exp:obs] [%h:%h]",   mid, exp.last, mon.last);            end
            if (err) fail_cnt++; else pass_cnt++;
        end
    endtask

    // ----- Report -----
    task report();
        $display("===== REPORT =====");
        $display("PASS: %0d  FAIL: %0d", pass_cnt, fail_cnt);
        $display("REMAIN AR: %0d  R: %0d",
            exp_ar_q[0].size() + exp_ar_q[1].size() + exp_ar_q[2].size() + exp_ar_q[3].size(),
            exp_r_q.size());
        $display("REMAIN AW: %0d  W: %0d",
            exp_aw_q[0].size() + exp_aw_q[1].size() + exp_aw_q[2].size(),
            exp_w_q[0].size()  + exp_w_q[1].size()  + exp_w_q[2].size());
    endtask

    task run();
        fork
            check_ar();
            check_r();
            check_aw(0); check_aw(1); check_aw(2);
            check_w(0);  check_w(1);  check_w(2);
        join_none
    endtask
endclass

// ============================================================================
// Environment
// ============================================================================
class environment;
    virtual axi_bus_if vif;

    mailbox #(sub_ar_channel_t)   mbx_mon_ar;
    mailbox #(master_r_channel_t) mbx_mon_r;
    mailbox #(sub_aw_channel_t)   mbx_mon_aw[3];
    mailbox #(sub_w_channel_t)    mbx_mon_w[3];

    mailbox #(ar_txn) mbx_drv_ar[4];
    mailbox #(r_txn)  mbx_drv_r;
    mailbox #(aw_txn) mbx_drv_write[3];

    ar_driver     ar_drv[4];
    r_driver      r_drv;
    write_driver  write_drv[3];

    ar_monitor    ar_mon;
    r_monitor     r_mon;
    aw_monitor    aw_mon[3];
    w_monitor     w_mon[3];

    scoreboard    scb;

    function new(virtual axi_bus_if vif);
        this.vif = vif;

        foreach (mbx_drv_ar[i])    mbx_drv_ar[i]    = new();
        foreach (mbx_drv_write[i]) mbx_drv_write[i]  = new();
        mbx_drv_r  = new();
        mbx_mon_ar = new();
        mbx_mon_r  = new();
        foreach (mbx_mon_aw[i]) mbx_mon_aw[i] = new();
        foreach (mbx_mon_w[i])  mbx_mon_w[i]  = new();

        ar_mon = new(vif, mbx_mon_ar);
        r_mon  = new(vif, mbx_mon_r);
        foreach (aw_mon[i]) aw_mon[i] = new(i, vif, mbx_mon_aw[i]);
        foreach (w_mon[i])  w_mon[i]  = new(i, vif, mbx_mon_w[i]);

        scb = new(mbx_mon_ar, mbx_mon_r, mbx_mon_aw, mbx_mon_w);

        foreach (ar_drv[i])    ar_drv[i]    = new(i, scb, vif, mbx_drv_ar[i]);
        r_drv = new(vif, mbx_drv_r, scb);
        foreach (write_drv[i]) write_drv[i] = new(i, scb, vif, mbx_drv_write[i]);
    endfunction

    task send_ar_req(ar_txn t);    mbx_drv_ar[t.mid].put(t);    endtask
    task send_r_req(r_txn t);      mbx_drv_r.put(t);            endtask
    task send_write_req(aw_txn t); mbx_drv_write[t.mid].put(t); endtask

    task start();
        fork
            ar_drv[0].run(); ar_drv[1].run(); ar_drv[2].run(); ar_drv[3].run();
            r_drv.run();
            write_drv[0].run(); write_drv[1].run(); write_drv[2].run();
            ar_mon.run();
            r_mon.run();
            aw_mon[0].run(); aw_mon[1].run(); aw_mon[2].run();
            w_mon[0].run();  w_mon[1].run();  w_mon[2].run();
            scb.run();
        join_none
    endtask

    task report();
        scb.report();
    endtask
endclass
