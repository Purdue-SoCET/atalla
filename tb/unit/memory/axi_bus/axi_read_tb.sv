`timescale 1ps/1ps

`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

// ================================================================
//                     TRANSACTION CLASSES
// ================================================================

// AR transaction — constrained-random with switchable profiles
class ar_txn;
    rand logic [1:0]          mid;
    rand logic [ARADDR-1:0]   addr;
    rand logic [ARID-1:0]     id;
    rand logic [ARSIZE-1:0]   size;
    rand logic [ARLEN-1:0]    len;
    rand logic [ARBURST-1:0]  burst;

    // Default constraints
    constraint c_mid   { mid inside {[0:3]}; }
    constraint c_burst { burst inside {2'b00, 2'b01, 2'b10}; }
    constraint c_size  { size inside {3'b000, 3'b001, 3'b010}; }
    constraint c_len   { len inside {0, 1, 3, 7, 15}; }

    // Switchable: force single-beat
    constraint c_single { len == 0; }

    // Switchable: force specific master
    logic [1:0] forced_mid;
    constraint c_force_mid { mid == forced_mid; }

    function new();
        c_single.constraint_mode(0);    // off by default
        c_force_mid.constraint_mode(0); // off by default
    endfunction

    function string to_s();
        return $sformatf("mid=%0d addr=%08h id=%0d size=%0d len=%0d burst=%0b",
                         mid, addr, id, size, len, burst);
    endfunction
endclass

// R transaction
class r_txn;
    rand logic [1:0]       mid;
    rand logic [RDATA-1:0] data;
    rand logic [RID-1:0]   id;
    rand rresp_t           resp;
    rand logic [ARLEN-1:0] len;

    constraint c_mid  { mid inside {[0:3]}; }
    constraint c_resp { resp inside {R_OKAY, R_EXOKAY, R_SLVERR, R_DECERR}; }
    constraint c_len  { len inside {0, 1, 3, 7, 15}; }
endclass

// ================================================================
//                          DRIVER
// ================================================================
typedef class scoreboard;

class ar_driver;
    virtual axi_bus_if vif;
    mailbox #(ar_txn) mbx;          // from test → driver
    scoreboard scb;

    function new(virtual axi_bus_if vif, mailbox #(ar_txn) mbx, scoreboard scb);
        this.vif = vif;
        this.mbx = mbx;
        this.scb = scb;
    endfunction

    task run();
        ar_txn t;
        forever begin
            mbx.get(t);
            scb.push_expected(t);
            drive(t);
        end
    endtask

    task drive(ar_txn t);
        @(negedge axi_read_tb.CLK);
        case (t.mid)
            0: begin vif.ar_sp0_valid=1; vif.ar_sp0_i.addr=t.addr; vif.ar_sp0_i.id=t.id;
                     vif.ar_sp0_i.size=t.size; vif.ar_sp0_i.len=t.len; vif.ar_sp0_i.burst=t.burst; end
            1: begin vif.ar_sp1_valid=1; vif.ar_sp1_i.addr=t.addr; vif.ar_sp1_i.id=t.id;
                     vif.ar_sp1_i.size=t.size; vif.ar_sp1_i.len=t.len; vif.ar_sp1_i.burst=t.burst; end
            2: begin vif.ar_i_valid=1; vif.ar_i_i.addr=t.addr; vif.ar_i_i.id=t.id;
                     vif.ar_i_i.size=t.size; vif.ar_i_i.len=t.len; vif.ar_i_i.burst=t.burst; end
            3: begin vif.ar_d_valid=1; vif.ar_d_i.addr=t.addr; vif.ar_d_i.id=t.id;
                     vif.ar_d_i.size=t.size; vif.ar_d_i.len=t.len; vif.ar_d_i.burst=t.burst; end
        endcase
        @(negedge axi_read_tb.CLK);
        // Hold valid until ready (AXI handshake rule)
        case (t.mid) // trap original signal in while loop, release value when ready
            0: begin while (!vif.ar_sp0_ready) @(negedge axi_read_tb.CLK); vif.ar_sp0_valid=0; vif.ar_sp0_i='0; end
            1: begin while (!vif.ar_sp1_ready) @(negedge axi_read_tb.CLK); vif.ar_sp1_valid=0; vif.ar_sp1_i='0; end
            2: begin while (!vif.ar_i_ready)   @(negedge axi_read_tb.CLK); vif.ar_i_valid=0;   vif.ar_i_i='0;   end
            3: begin while (!vif.ar_d_ready)   @(negedge axi_read_tb.CLK); vif.ar_d_valid=0;   vif.ar_d_i='0;   end
        endcase
    endtask
endclass

class r_driver;
    virtual axi_bus_if vif;
    mailbox #(r_txn) mbx;

    function new(virtual axi_bus_if vif, mailbox #(r_txn) mbx);
        this.vif = vif;
        this.mbx = mbx;
    endfunction

    task run();
        r_txn t;
        forever begin
            mbx.get(t);
            drive(t);
        end
    endtask

    task drive(r_txn t);
        @(negedge axi_read_tb.CLK);
        set_ready(t.mid, 1);

        vif.r_valid  = 1;
        vif.r_i.mid  = t.mid;
        vif.r_i.id   = t.id;
        vif.r_i.resp = t.resp;
        vif.r_i.last = 0;

        for (int i = 0; i <= t.len; i++) begin
            vif.r_i.data = {$urandom, $urandom};
            vif.r_i.last = (i == t.len);

            // Random backpressure: ~25% chance drop ready 1-3 cycles
            if ($urandom_range(0, 3) == 0) begin
                set_ready(t.mid, 0);
                repeat ($urandom_range(1, 3)) @(negedge axi_read_tb.CLK);
                set_ready(t.mid, 1);
            end
            @(negedge axi_read_tb.CLK);
        end

        vif.r_valid = 0; vif.r_i = '0;
        set_ready(t.mid, 0);
    endtask

    task set_ready(logic [1:0] mid, logic val);
        case (mid)
            0: vif.r_sp0_o_ready = val;
            1: vif.r_sp1_o_ready = val;
            2: vif.r_i_o_ready   = val;
            3: vif.r_d_o_ready   = val;
        endcase
    endtask
endclass

// ================================================================
//                 SUBORDINATE-SIDE MONITOR
//   Sits on ar_o and auto-checks every handshake
// ================================================================
class ar_monitor;
    virtual axi_bus_if vif;
    mailbox #(sub_ar_channel_t) mon2scb;   // observed transactions → scoreboard
    int txn_cnt = 0;

    function new(virtual axi_bus_if vif, mailbox #(sub_ar_channel_t) mon2scb);
        this.vif = vif;
        this.mon2scb = mon2scb;
    endfunction

    // Runs forever, samples ar_o on every valid+ready handshake
    task run();
        forever begin
            @(posedge axi_read_tb.CLK);#1;
            if (vif.ar_o_valid && vif.ar_o_ready) begin
                mon2scb.put(vif.ar_o);
                txn_cnt++;
            end
        end
    endtask
endclass

// ================================================================
//                     SCOREBOARD
//   Receives expected (from driver) and observed (from monitor),
//   matches them per-master using queues
// ================================================================
class scoreboard;
    mailbox #(sub_ar_channel_t)  mon_mbx;
    ar_txn exp_q[4][$];
    int pass_cnt=0, fail_cnt=0;

    function new(mailbox #(sub_ar_channel_t) mon_mbx);
        this.mon_mbx = mon_mbx;
    endfunction

    // Collector: pull from driver mailbox into per-master queues
    function void push_expected(ar_txn t);
        exp_q[t.mid].push_back(t);
    endfunction

    // Checker: pull from monitor mailbox and compare
    task check_observed();
        sub_ar_channel_t obs;
        ar_txn exp;
        forever begin
            mon_mbx.get(obs);
            // Find which master this came from
            if (exp_q[obs.mid].size() == 0) begin
                $error("[SCB] Unexpected txn on mid=%0d addr=%08h; expected value", obs.mid, obs.addr);
                fail_cnt++;
                continue;
            end
            exp = exp_q[obs.mid].pop_front();
            compare(exp, obs);
        end
    endtask

    task run();
        fork
            check_observed();
        join_none
    endtask

    function void compare(ar_txn exp, sub_ar_channel_t obs);
        int err = 0;
        if (exp.addr  !== obs.addr)  begin $error("[SCB] ADDR exp=%08h obs=%08h", exp.addr, obs.addr); err=1; end
        if (exp.id    !== obs.id)    begin $error("[SCB] ID exp=%0d obs=%0d",      exp.id,   obs.id);   err=1; end
        if (exp.size  !== obs.size)  begin $error("[SCB] SIZE exp=%0d obs=%0d",    exp.size, obs.size); err=1; end
        if (exp.len   !== obs.len)   begin $error("[SCB] LEN exp=%0d obs=%0d",     exp.len,  obs.len);  err=1; end
        if (exp.burst !== obs.burst) begin $error("[SCB] BURST exp=%0b obs=%0b",   exp.burst,obs.burst);err=1; end
        if (err) begin fail_cnt++; $display("======================="); end
        else     pass_cnt++;
    endfunction

    function void report();
        int remaining = 0;
        for (int i = 0; i < 4; i++) remaining += exp_q[i].size();
        $display("======== SCOREBOARD ========");
        $display("  PASS: %0d  FAIL: %0d  Remained: %0d", pass_cnt, fail_cnt, remaining);
        if (fail_cnt > 0 || remaining > 0) $display("  *** FAIL ***");
        else $display("  *** PASS ***");
        $display("============================");
    endfunction
endclass

// ================================================================
//                     ENVIRONMENT
//   Wires everything together. Tests interact with env.
// ================================================================
class environment;
    virtual axi_bus_if vif;

    mailbox #(ar_txn)            ar_drv_mbx;
    mailbox #(r_txn)             r_drv_mbx;
    mailbox #(sub_ar_channel_t)  mon2scb;

    ar_driver  ar_drv;
    r_driver   r_drv;
    ar_monitor ar_mon;
    scoreboard scb;

    function new(virtual axi_bus_if vif);
        this.vif    = vif;
        ar_drv_mbx  = new();
        r_drv_mbx   = new();
        mon2scb     = new();

        scb    = new(mon2scb);
        ar_drv = new(vif, ar_drv_mbx, scb);
        r_drv  = new(vif, r_drv_mbx);
        ar_mon = new(vif, mon2scb);
        
    endfunction

    task start();
        fork
            ar_drv.run();
            r_drv.run();
            ar_mon.run();
        join_none
        scb.run();
    endtask

    // Send AR transaction through proper driver→monitor→scoreboard pipeline
    task send_ar(ar_txn t);
        ar_drv_mbx.put(t);
    endtask

    task send_r(r_txn t);
        r_drv_mbx.put(t);
    endtask

    function void report();
        $display("\n  Monitor saw %0d AR handshakes", ar_mon.txn_cnt);
        scb.report();
    endfunction
endclass

// ================================================================
//                    TOP-LEVEL MODULE
// ================================================================
module axi_read_tb;

    parameter PERIOD = 10;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;

    axi_bus_if abif();
    axi_read DUT (CLK, nRST, abif);

    // ----------------------------------------------------------
    //  FUNCTIONAL COVERAGE (sampled automatically every cycle)
    // ----------------------------------------------------------

    // AR output
    covergroup ar_out_cg @(posedge CLK);
        option.per_instance = 1;

        cp_valid: coverpoint abif.ar_o_valid;
        cp_ready: coverpoint abif.ar_o_ready;
        cp_hsk:   coverpoint (abif.ar_o_valid && abif.ar_o_ready) { bins y={1}; bins n={0}; }

        cp_mid: coverpoint abif.ar_o.mid iff (abif.ar_o_valid) {
            bins sp0={0}; bins sp1={1}; bins d={2}; bins i={3};
        }
        cp_id: coverpoint abif.ar_o.id iff (abif.ar_o_valid);
        cp_len: coverpoint abif.ar_o.len iff (abif.ar_o_valid) {
            bins single={0}; bins b2={1}; bins b4={3}; bins b8={7}; bins b16={15};
        }
        cp_burst: coverpoint abif.ar_o.burst iff (abif.ar_o_valid) {
            bins fixed={2'b00}; bins incr={2'b01}; bins wrap={2'b10};
        }
        cp_size: coverpoint abif.ar_o.size iff (abif.ar_o_valid) {
            bins b1={3'b000}; bins b2={3'b001}; bins b4={3'b010};
        }

        // cross to cover all combinations
        mid_x_len:   cross cp_mid, cp_len;
        mid_x_burst: cross cp_mid, cp_burst;
        mid_x_size:  cross cp_mid, cp_size;
        mid_x_id:    cross cp_mid, cp_id;
    endgroup

    // Arbiter request combinations
    covergroup arb_cg @(posedge CLK);
        option.per_instance = 1;

        cp_reqs: coverpoint {abif.sp0_req_r, abif.sp1_req_r, abif.d_req_r, abif.i_req_r} {
            bins none     = {4'b0000};
            bins singles[] = {4'b1000, 4'b0100, 4'b0010, 4'b0001};
            bins pairs[]   = {4'b1100, 4'b1010, 4'b1001, 4'b0110, 4'b0101, 4'b0011};
            bins triples[] = {4'b1110, 4'b1101, 4'b1011, 4'b0111};
            bins all       = {4'b1111};
        }

        cp_grant: coverpoint axi_read_tb.DUT.grant_sel {
            bins idle={3'b000};
            bins sp0={3'b100}; bins sp1={3'b101};
            bins d={3'b110};   bins i={3'b111};
        }

        cp_ready: coverpoint abif.ar_o_ready;
        grant_x_ready: cross cp_grant, cp_ready;
    endgroup

    // R channel
    covergroup r_cg @(posedge CLK);
        option.per_instance = 1;

        cp_valid: coverpoint abif.r_valid;
        cp_ready: coverpoint abif.r_ready;

        cp_mid: coverpoint abif.r_i.mid iff (abif.r_valid) {
            bins sp0={0}; bins sp1={1}; bins i={2}; bins d={3};
        }
        cp_resp: coverpoint abif.r_i.resp iff (abif.r_valid) {
            bins okay={R_OKAY}; bins exokay={R_EXOKAY};
            bins slverr={R_SLVERR}; bins decerr={R_DECERR};
        }
        cp_last: coverpoint abif.r_i.last iff (abif.r_valid);
        mid_x_resp: cross cp_mid, cp_resp;

        // Backpressure on each port
        cp_sp0_bp: coverpoint {abif.r_sp0_o_valid, abif.r_sp0_o_ready} {
            bins idle={2'b00}; bins stall={2'b10}; bins accept={2'b11};
        }
        cp_sp1_bp: coverpoint {abif.r_sp1_o_valid, abif.r_sp1_o_ready} {
            bins idle={2'b00}; bins stall={2'b10}; bins accept={2'b11};
        }
        cp_i_bp: coverpoint {abif.r_i_o_valid, abif.r_i_o_ready} {
            bins idle={2'b00}; bins stall={2'b10}; bins accept={2'b11};
        }
        cp_d_bp: coverpoint {abif.r_d_o_valid, abif.r_d_o_ready} {
            bins idle={2'b00}; bins stall={2'b10}; bins accept={2'b11};
        }
    endgroup

    ar_out_cg ar_out_cov = new();
    arb_cg    arb_cov    = new();
    r_cg      r_cov      = new();

    // ----------------------------------------------------------
    //  SVA — PROTOCOL ASSERTIONS
    // ----------------------------------------------------------

    // ar_o_valid / r_ready no X after reset
    a_valid_known: assert property (
        @(posedge CLK) disable iff (!nRST) !$isunknown(abif.ar_o_valid)
    ) else $error("SVA: ar_o_valid X/Z");

    a_r_ready_known: assert property (
        @(posedge CLK) disable iff (!nRST) !$isunknown(abif.r_ready)
    ) else $error("SVA: r_ready X/Z");

    a_grant_known: assert property (
        @(posedge CLK) disable iff (!nRST) !$isunknown(DUT.grant_sel)
    ) else $error("SVA: grant_sel X/Z");

    // AR handshake: fields not X
    a_ar_hsk_clean: assert property (
        @(posedge CLK) disable iff (!nRST)
        (abif.ar_o_valid && abif.ar_o_ready) |->
            !$isunknown(abif.ar_o.addr) && !$isunknown(abif.ar_o.id)
    ) else $error("SVA: ar_o X during handshake");

    // Mutual exclusion: at most one pop
    a_pop_mutex: assert property (
        @(posedge CLK) disable iff (!nRST)
        $onehot0({abif.sp0_pop, abif.sp1_pop, abif.i_pop, abif.d_pop})
    ) else $error("SVA: multiple simultaneous pops");

    // Pop implies request
    a_sp0_pop: assert property (@(posedge CLK) disable iff (!nRST) abif.sp0_pop |-> abif.sp0_req_r) else $error("SVA: sp0 pop w/o req");
    a_sp1_pop: assert property (@(posedge CLK) disable iff (!nRST) abif.sp1_pop |-> abif.sp1_req_r) else $error("SVA: sp1 pop w/o req");
    a_i_pop:   assert property (@(posedge CLK) disable iff (!nRST) abif.i_pop   |-> abif.i_req_r)   else $error("SVA: i pop w/o req");
    a_d_pop:   assert property (@(posedge CLK) disable iff (!nRST) abif.d_pop   |-> abif.d_req_r)   else $error("SVA: d pop w/o req");

    // Router: one-hot output during R handshake
    a_router_1hot: assert property (
        @(posedge CLK) disable iff (!nRST)
        (abif.r_valid && abif.r_ready) |->
            $onehot({abif.r_sp0_o_valid, abif.r_sp1_o_valid,
                     abif.r_i_o_valid,   abif.r_d_o_valid})
    ) else $error("SVA: router not one-hot");

    // Router: correct destination
    a_r_sp0: assert property (@(posedge CLK) disable iff (!nRST) (abif.r_valid && abif.r_ready && abif.r_i.mid==0) |-> abif.r_sp0_o_valid) else $error("SVA: R mid=0 wrong dest");
    a_r_sp1: assert property (@(posedge CLK) disable iff (!nRST) (abif.r_valid && abif.r_ready && abif.r_i.mid==1) |-> abif.r_sp1_o_valid) else $error("SVA: R mid=1 wrong dest");
    a_r_i:   assert property (@(posedge CLK) disable iff (!nRST) (abif.r_valid && abif.r_ready && abif.r_i.mid==2) |-> abif.r_i_o_valid)   else $error("SVA: R mid=2 wrong dest");
    a_r_d:   assert property (@(posedge CLK) disable iff (!nRST) (abif.r_valid && abif.r_ready && abif.r_i.mid==3) |-> abif.r_d_o_valid)   else $error("SVA: R mid=3 wrong dest");

    // No phantom output when r_valid=0
    a_no_phantom: assert property (
        @(posedge CLK) disable iff (!nRST)
        !abif.r_valid |->
            !abif.r_sp0_o_valid && !abif.r_sp1_o_valid &&
            !abif.r_i_o_valid   && !abif.r_d_o_valid
    ) else $error("SVA: phantom router output");

    // ----------------------------------------------------------
    //  COVER PROPERTIES
    // ----------------------------------------------------------
    c_all4:       cover property (@(posedge CLK) abif.sp0_req_r && abif.sp1_req_r && abif.i_req_r && abif.d_req_r);
    c_hsk:        cover property (@(posedge CLK) abif.ar_o_valid && abif.ar_o_ready);
    c_stall:      cover property (@(posedge CLK) abif.ar_o_valid && !abif.ar_o_ready);
    c_idle_ready: cover property (@(posedge CLK) abif.ar_o_ready && !abif.ar_o_valid);
    c_r_last:     cover property (@(posedge CLK) abif.r_valid && abif.r_i.last);
    c_r_slverr:   cover property (@(posedge CLK) abif.r_valid && abif.r_i.resp == R_SLVERR);
    c_r_decerr:   cover property (@(posedge CLK) abif.r_valid && abif.r_i.resp == R_DECERR);
    c_r_exokay:   cover property (@(posedge CLK) abif.r_valid && abif.r_i.resp == R_EXOKAY);

    // ----------------------------------------------------------
    //  TEST PROGRAM
    // ----------------------------------------------------------
    test PROG (CLK, nRST, abif);

endmodule

// ================================================================
//                      TEST PROGRAM
// ================================================================
program test (
    input  logic CLK,
    output logic nRST,
    axi_bus_if abif
);
    import axi_bus_pkg::*;

    environment env;
    int TIMEOUT_CYCLES = 50000;

    // ----------------------------------------------------------
    //  Reset + ready control
    // ----------------------------------------------------------
    task automatic reset_dut();
        nRST = 0;
        abif.ar_sp0_valid  = 0; abif.ar_sp0_i  = '0;
        abif.ar_sp1_valid  = 0; abif.ar_sp1_i  = '0;
        abif.ar_d_valid    = 0; abif.ar_d_i    = '0;
        abif.ar_i_valid    = 0; abif.ar_i_i    = '0;
        abif.ar_o_ready    = 0;
        abif.r_valid       = 0; abif.r_i       = '0;
        abif.r_sp0_o_ready = 0; abif.r_sp1_o_ready = 0;
        abif.r_i_o_ready   = 0; abif.r_d_o_ready   = 0;
        repeat (3) @(negedge CLK);
        nRST = 1;
        repeat (3) @(negedge CLK);
    endtask

    // Background: random ar_o_ready toggling (mimics slow subordinate)
    task automatic random_ar_ready(int cycles);
        @(posedge CLK);
        for (int i = 0; i < cycles; i++) begin
            abif.ar_o_ready = $urandom_range(0, 1);
            @(posedge CLK);
        end
        // Drain at end
        abif.ar_o_ready = 1;
        repeat (20) @(posedge CLK);
        abif.ar_o_ready = 0;
    endtask

    // Background: steady ar_o_ready
    task automatic steady_ar_ready(int cycles);
        @(posedge CLK);
        abif.ar_o_ready = 1;
        repeat (cycles) @(posedge CLK);
        abif.ar_o_ready = 0;
    endtask

    // Watchdog
    task automatic watchdog(int cycles);
        repeat (cycles) @(negedge CLK);
        $fatal("[WATCHDOG] Timeout after %0d cycles", cycles);
    endtask

    // ----------------------------------------------------------
    //  HELPER: generate N random AR transactions
    // ----------------------------------------------------------
    function automatic void gen_random_ar(
        ref ar_txn txns[$],
        input int  n,
        input bit  single_only = 0,
        input int  force_mid   = -1   // -1 = no constraint
    );
        for (int i = 0; i < n; i++) begin
            ar_txn t = new();
            if (single_only) t.c_single.constraint_mode(1);
            if (force_mid >= 0) begin
                t.forced_mid = force_mid[1:0];
                t.c_force_mid.constraint_mode(1);
            end
            assert(t.randomize()) else $fatal("gen_random_ar randomize fail");
            txns.push_back(t);
        end
    endfunction

    function automatic void gen_random_r(
        ref r_txn txns[$],
        input int n
    );
        for (int i = 0; i < n; i++) begin
            r_txn t = new();
            assert(t.randomize()) else $fatal("gen_random_r randomize fail");
            txns.push_back(t);
        end
    endfunction

    // ----------------------------------------------------------
    //  TEST 1: Directed smoke — one txn per master, immediate pop
    //  Goal: basic datapath sanity, toggle ar_o bits
    // ----------------------------------------------------------
    task automatic test_smoke();
        ar_txn t;
        $display("\n===== TEST 1: Smoke =====");

        // Use contrasting bit patterns to maximize toggle
        for (int m = 0; m < 16; m++) begin
            t = new();
            t.c_single.constraint_mode(1);
            t.forced_mid = m[1:0];
            t.c_force_mid.constraint_mode(1);
            assert(t.randomize()) else $fatal("smoke randomize");
            env.send_ar(t);
        end
        steady_ar_ready(50);
    endtask

    // ----------------------------------------------------------
    //  TEST 2: Toggle coverage — all-1s then all-0s addresses
    //  Goal: every bit of ar_o.addr, ar_o.id etc. toggles
    // ----------------------------------------------------------
    task automatic test_toggle();
        ar_txn t;
        $display("\n===== TEST 2: Toggle =====");

        for (int m = 0; m < 4; m++) begin
            // All ones
            t = new();
            t.c_force_mid.constraint_mode(0);
            t.c_single.constraint_mode(0);
            t.c_len.constraint_mode(0);
            t.c_burst.constraint_mode(0);
            t.c_size.constraint_mode(0);
            assert(t.randomize() with {
                t.mid   == m[1:0];
                t.addr  == '1;
                t.id    == '1;
                t.size  == '1;
                t.len   == '1;
                t.burst == '1;
            }) else $fatal("toggle-1 randomize");
            env.send_ar(t);

            // All zeros
            t = new();
            t.c_force_mid.constraint_mode(0);
            t.c_single.constraint_mode(0);
            t.c_len.constraint_mode(0);
            t.c_burst.constraint_mode(0);
            t.c_size.constraint_mode(0);
            assert(t.randomize() with {
                t.mid   == m[1:0];
                t.addr  == '0;
                t.id    == '0;
                t.size  == '0;
                t.len   == '0;
                t.burst == '0;
            }) else $fatal("toggle-0 randomize");
            env.send_ar(t);
        end
        steady_ar_ready(30);
    endtask

    // ----------------------------------------------------------
    //  TEST 3: All-4-masters simultaneous contention
    //  Goal: hit all arbiter priority branches, all req combos
    // ----------------------------------------------------------
    task automatic test_contention();
        ar_txn q[$];
        $display("\n===== TEST 3: Contention =====");

        // Load all 4 masters with multiple requests each
        for (int m = 0; m < 4; m++)
            gen_random_ar(q, 4, .force_mid(m));

        // Fire them all rapidly (driver serializes per-master,
        // but multiple masters fill concurrently via fork in driver)
        foreach (q[i]) env.send_ar(q[i]);

        // Slow drain: creates contention
        random_ar_ready(80);
    endtask

    // ----------------------------------------------------------
    //  TEST 4: Arbiter stall — grant active, ready drops
    //  Goal: hit the "!ready" branches in each GRANTED state
    // ----------------------------------------------------------
    task automatic test_arbiter_stall();
        ar_txn q[$];
        $display("\n===== TEST 4: Arbiter stall (ready toggling) =====");

        for (int m = 0; m < 4; m++)
            gen_random_ar(q, 2, .force_mid(m));
        foreach (q[i]) env.send_ar(q[i]);

        // Pattern: ready on→off→on to hit !ready in each GRANTED state
        for (int i = 0; i < 8; i++) begin
            abif.ar_o_ready = 1;
            @(negedge CLK);          // accept one
            abif.ar_o_ready = 0;
            repeat (2) @(negedge CLK); // stall in GRANTED
        end
        steady_ar_ready(20);
    endtask

    // ----------------------------------------------------------
    //  TEST 5: Idle with ready (no requests) — "All False" branch
    //  Goal: ready=1, no master requesting
    // ----------------------------------------------------------
    task automatic test_idle_ready();
        $display("\n===== TEST 5: Idle + ready (all-false branch) =====");
        // Just assert ready with nothing pending
        abif.ar_o_ready = 1;
        repeat (5) @(negedge CLK);
        abif.ar_o_ready = 0;
        @(negedge CLK);
    endtask

    // ----------------------------------------------------------
    //  TEST 6: FIFO fill/drain per master
    //  Goal: fill each manager FIFO to capacity, then drain all
    // ----------------------------------------------------------
    task automatic test_fifo_pressure();
        ar_txn q[$];
        $display("\n===== TEST 6: FIFO pressure =====");

        // No ready yet — let FIFOs fill
        abif.ar_o_ready = 0;
        for (int m = 0; m < 4; m++)
            gen_random_ar(q, NUM_U_READS, .force_mid(m));
        foreach (q[i]) env.send_ar(q[i]);

        repeat (NUM_U_READS * 5) @(negedge CLK); // let them fill

        // Now drain
        steady_ar_ready(NUM_U_READS * 8);
    endtask

    // ----------------------------------------------------------
    //  TEST 7: R channel — all response types, all masters
    //  Goal: route coverage, resp coverage, last toggle
    // ----------------------------------------------------------
    task automatic test_r_directed();
        r_txn t;
        rresp_t resps[4] = '{R_OKAY, R_EXOKAY, R_SLVERR, R_DECERR};
        $display("\n===== TEST 7: R directed (all resp x all mid) =====");

        for (int m = 0; m < 4; m++) begin
            for (int r = 0; r < 4; r++) begin
                t = new();
                assert(t.randomize() with {
                    t.mid  == m[1:0];
                    t.resp == resps[r];
                    t.len  inside {0, 3, 7};
                }) else $fatal("r_directed randomize");
                env.send_r(t);
            end
        end
        repeat (10) @(negedge CLK);
    endtask

    // ----------------------------------------------------------
    //  TEST 8: R backpressure — ready drops mid-burst
    //  Goal: stall bins in R coverage, stress router
    // ----------------------------------------------------------
    task automatic test_r_backpressure();
        r_txn t;
        $display("\n===== TEST 8: R backpressure =====");

        for (int m = 0; m < 4; m++) begin
            t = new();
            assert(t.randomize() with {
                t.mid == m[1:0];
                t.len == 7;
            }) else $fatal("r_bp randomize");
            env.send_r(t);
        end
        repeat (10) @(negedge CLK);
    endtask

    // ----------------------------------------------------------
    //  TEST 9: Fully constrained-random — AR + R concurrent
    //  Goal: cross-coverage, corner cases via random exploration
    // ----------------------------------------------------------
    task automatic test_random(int n_ar, int n_r);
        ar_txn aq[$];
        r_txn  rq[$];
        $display("\n===== TEST 9: Random (%0d AR, %0d R) =====", n_ar, n_r);

        gen_random_ar(aq, n_ar);
        gen_random_r(rq, n_r);

        fork
            // AR stimulus
            foreach (aq[i]) env.send_ar(aq[i]);
            // AR consumer (random ready)
            random_ar_ready(n_ar * 4);
            // R stimulus (delayed start)
            begin
                repeat (10) @(negedge CLK);
                foreach (rq[i]) env.send_r(rq[i]);
            end
        join
        repeat (10) @(negedge CLK);
    endtask

    // ----------------------------------------------------------
    //  TEST 10: Starvation — one master floods, others trickle
    //  Goal: fairness, check other masters still get served
    // ----------------------------------------------------------
    task automatic test_starvation();
        ar_txn q[$];
        $display("\n===== TEST 10: Starvation =====");

        // SP0 floods 16 txns
        gen_random_ar(q, 16, .force_mid(0));
        // Others trickle 2 each
        for (int m = 1; m < 4; m++)
            gen_random_ar(q, 2, .force_mid(m));

        foreach (q[i]) env.send_ar(q[i]);
        random_ar_ready(80);
    endtask

    // ----------------------------------------------------------
    //  TEST 11: Back-to-back — no idle cycles between handshakes
    //  Goal: pipe full throughput, no bubble
    // ----------------------------------------------------------
    task automatic test_back2back();
        ar_txn q[$];
        $display("\n===== TEST 11: Back-to-back =====");

        gen_random_ar(q, 20, .single_only(1));
        foreach (q[i]) env.send_ar(q[i]);
        // Keep ready always high
        steady_ar_ready(40);
    endtask

    // ----------------------------------------------------------
    //  MAIN
    // ----------------------------------------------------------
    initial begin
        int iteration = 10;
        int i;

        $display("\n########################################");
        $display("# AXI Read Path Testbench   #");
        $display("########################################");

        env = new(abif);
        env.start();

        fork
            // Global watchdog
            watchdog(TIMEOUT_CYCLES);
        join_none

        reset_dut();
        
        

        // Run all tests sequentially
        for (i = 0; i < iteration; i++) begin
            $display("=========== Iteration %d ===========", i);
            
            test_smoke();           reset_dut();
            test_toggle();          reset_dut();
            test_contention();      reset_dut();
            test_idle_ready();      reset_dut();
            test_fifo_pressure();   reset_dut();
            test_r_directed();      reset_dut();
            test_r_backpressure();  reset_dut();
            test_random(100, 50);   reset_dut();
            test_starvation();      reset_dut();
            test_back2back();       reset_dut();
        end
        

        // test_arbiter_stall();   reset_dut(); // bad one

        // Let scoreboard drain remaining comparisons
        repeat (50) @(negedge CLK);

        // Final reports
        env.report();
        $display("\n  AR output cov: %.1f%%", axi_read_tb.ar_out_cov.get_coverage());
        $display("  Arbiter cov:   %.1f%%", axi_read_tb.arb_cov.get_coverage());
        $display("  R channel cov: %.1f%%", axi_read_tb.r_cov.get_coverage());

        $finish;
    end
endprogram