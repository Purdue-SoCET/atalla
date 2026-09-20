/*  Aryan Kadakia - kadakia0@purdue.edu */

`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

// TRANSACTIONS
class axi_write_txn_mgr;
    //logic                 awvalid;
    rand logic [AWID-1:0]      awid;
    rand logic [AWADDR-1:0]    awaddr;
    rand logic [AWLEN-1:0]     awlen;
    logic [AWSIZE-1:0]         awsize = 3'b011;
    logic [AWBURST-1:0]        awburst = 2'b01;

    //logic                 wvalid;
    rand logic [WID-1:0]       wid;
    rand logic [WDATA-1:0]     wdata;
    rand logic [WSTRB-1:0]     wstrb;
    logic                      wlast = 0;

    constraint id_match {
        wid == awid;
    }

    constraint single_beat {
        awlen == 0;
    }
endclass

// GENERATOR
class axi_generator_mgr;
    // function <return_type> <function_name>();
    function axi_write_txn_mgr generate_txn();
        axi_write_txn_mgr txn; // creates handle
        txn = new(); // constructs object
        if (!txn.randomize()) begin  // randomizes input stimulus
            $fatal("Randomization failed");
        end
        return txn;
    endfunction 
endclass

// DRIVER 
class axi_driver_mgr;
    //virtual axi_bus_if.tb vif; // giving class a virtual interface (handle to interface instance)
    virtual axi_bus_if.write_manager_tb vif;
    function new(virtual axi_bus_if.write_manager_tb vif); 
        this.vif = vif; // constructor of driver class
    endfunction
    task drive_write_ar(axi_write_txn_mgr txn);
        vif.awvalid <= 1;
        vif.aw_gen_i.addr  <= txn.awaddr;
        vif.aw_gen_i.id <= txn.awid;
        vif.aw_gen_i.len <= txn.awlen;
        vif.aw_gen_i.size <= txn.awsize;
        vif.aw_gen_i.burst <= txn.awburst;
    endtask
    task drive_write_w(axi_write_txn_mgr txn, bit last);
        vif.wvalid <= 1;
        vif.w_gen_i.data <= txn.wdata;
        vif.w_gen_i.id   <= txn.wid;
        vif.w_gen_i.strb <= txn.wstrb;
        vif.w_gen_i.last <= last;
    endtask
    task drive_read_aw();
        vif.aw_pop <= 1'b1;
    endtask
    task drive_read_w();
        vif.w_pop <= 1'b1;
    endtask
    task drive_input_zero();
        vif.awvalid <= 0;
        vif.aw_gen_i.addr  <= '0;
        vif.aw_gen_i.id <= '0;
        vif.aw_gen_i.len <= '0;
        vif.aw_gen_i.size <= '0;
        vif.aw_gen_i.burst <= '0;
        vif.wvalid <= 0;
        vif.w_gen_i.data <= '0;
        vif.w_gen_i.id   <= '0;
        vif.w_gen_i.strb <= '0;
        vif.w_gen_i.last <= '0;
        vif.aw_pop <= 1'b0;
        vif.w_pop <= 1'b0;
    endtask
endclass

// Monitor
class axi_monitor_mgr;
    //virtual axi_bus_if.tb vif;
    virtual axi_bus_if.write_manager_tb vif;
    function new(virtual axi_bus_if.write_manager_tb vif);
        this.vif = vif;
    endfunction

    function axi_write_txn_mgr sample();
        axi_write_txn_mgr txn;
        txn = new();

        txn.awid   = vif.aw_gen_i.id;
        txn.awaddr = vif.aw_gen_i.addr;
        txn.awlen  = vif.aw_gen_i.len;
        txn.awsize = vif.aw_gen_i.size;
        txn.awburst= vif.aw_gen_i.burst;

        txn.wid    = vif.w_gen_i.id;
        txn.wdata  = vif.w_gen_i.data;
        txn.wstrb  = vif.w_gen_i.strb;
        txn.wlast  = vif.w_gen_i.last;

        return txn;
    endfunction
endclass

// Scoreboard
class axi_scoreboard;
    task check(axi_write_txn_mgr exp, axi_write_txn_mgr obs);
        if (exp.awid   != obs.awid)   $error("AWID mismatch");
        if (exp.awaddr != obs.awaddr) $error("AWADDR mismatch");
        if (exp.awlen  != obs.awlen)  $error("AWLEN mismatch");

        if (exp.wid    != obs.wid)    $error("WID mismatch");
        if (exp.wdata  != obs.wdata)  $error("WDATA mismatch");
        //if (exp.wlast  != obs.wlast)  $error("WLAST mismatch");

        if ((exp.awid   == obs.awid)   &&
            (exp.awaddr == obs.awaddr) &&
            (exp.awlen  == obs.awlen)  &&
            (exp.wid    == obs.wid)    &&
            (exp.wdata  == obs.wdata)  &&
            (exp.wlast  == obs.wlast)) begin
            $display("SCOREBOARD PASS");

        assert(exp.awid == exp.wid)
            else $error("id mismatch");
        end
    endtask
endclass

class axi_coverage_collector;
    // Local variables used by covergroup
    logic [AWID-1:0]   cov_awid;
    logic [AWLEN-1:0]  cov_awlen;
    logic              cov_wlast;

    covergroup axi_cg;
        cp_awid : coverpoint cov_awid;
        cp_awlen : coverpoint cov_awlen {
            bins beat_1 = {0};
            bins beat_2 = {1};
            bins beat_4 = {3};
            bins beat_8 = {7};
        }
        cp_wlast : coverpoint cov_wlast {
            bins last = {1};
        }
        awid_x_len : cross cp_awid, cp_awlen; // cross coverage
    endgroup
    // Constructor
    function new();
        axi_cg = new();
    endfunction

    // Sample method
    function void sample(axi_write_txn_mgr txn);
        cov_awid  = txn.awid;
        cov_awlen = txn.awlen;
        cov_wlast = txn.wlast;
        axi_cg.sample(); // built in sample function to record current values of all coverpoints right now
    endfunction

endclass

module axi_write_manager_tb ();
    parameter CLK_PERIOD = 10;

    logic CLK = 0, nRST;
    string test_case = ""; 

    // clock
    always #(CLK_PERIOD/2) CLK++;

    // interface 
    axi_bus_if busif(.CLK(CLK), .nRST(nRST));

    // DUT
    // axi_write_manager #(
    //     .MASTER_ID(2'b00)
    // ) DUT (
    //     .CLK     (CLK),
    //     .nRST    (nRST),
    //     .wrmgr_if (busif)
    // );
    axi_write_manager #(
    .MASTER_ID(2'b00)
    ) DUT (
        .CLK        (CLK),
        .nRST       (nRST),

        .awvalid    (busif.awvalid),
        .awid       (busif.aw_gen_i.id),
        .awaddr     (busif.aw_gen_i.addr),
        .awlen      (busif.aw_gen_i.len),
        .awsize     (busif.aw_gen_i.size),
        .awburst    (busif.aw_gen_i.burst),
        .awready    (busif.awready),

        .wvalid     (busif.wvalid),
        .wid        (busif.w_gen_i.id),
        .wdata      (busif.w_gen_i.data),
        .wstrb      (busif.w_gen_i.strb),
        .wlast      (busif.w_gen_i.last),
        .wready     (busif.wready),

        .aw_pop     (busif.aw_pop),
        .w_pop      (busif.w_pop),

        .head_awvalid(busif.head_awvalid),
        .head_addr  (busif.head_aw_o.addr),
        .head_awid  (busif.head_aw_o.mid_id),
        .head_len   (busif.head_aw_o.len),
        .head_size  (busif.head_aw_o.size),
        .head_burst (busif.head_aw_o.burst),

        .head_wvalid(busif.head_wvalid),
        .head_wid   (busif.head_w_o.mid_id),
        .head_data  (busif.head_w_o.data),
        .head_strb  (busif.head_w_o.strb),
        .head_last  (busif.head_w_o.last)
    );

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

    axi_write_txn_mgr txn;
    axi_generator_mgr gen;
    axi_driver_mgr drv;
    axi_monitor_mgr mon;
    axi_scoreboard scb;
    axi_coverage_collector cov;

    axi_write_txn_mgr exp_txn;
    axi_write_txn_mgr obs_txn;

    task single_write_test;
        test_case = "TEST CASE 1: SINGLE WRITE";
        drv.drive_input_zero();
        txn = gen.generate_txn();
        exp_txn = txn;
        @(posedge CLK);
        drv.drive_write_ar(txn);
        drv.drive_write_w(txn, 1);
        //busif.w_gen_i.last <= 1;
        // wait until accepted
        fork
            begin
                do @(posedge CLK); while (!(busif.awvalid && busif.awready));
                busif.awvalid <= 0;
            end
            begin
                do @(posedge CLK); while (!(busif.wvalid && busif.wready));
                busif.wvalid <= 0;
            end
        join
        $display("TB: drove txn");
        @(posedge CLK);
        obs_txn = mon.sample();
        $display("TB: sampled txn");

        cov.sample(obs_txn);
        scb.check(exp_txn, obs_txn);
        $display("TB: checked txn");
        repeat (2) @(posedge CLK);
    endtask

    task single_read_test;
        test_case = "TEST CASE 2: SINGLE READ";
        drv.drive_input_zero();
        repeat (2) @(posedge CLK);
        drv.drive_read_aw();
        drv.drive_read_w();
        repeat (3) @(posedge CLK);
    endtask

    task single_write_multi_beat_test;
        test_case = "TEST CASE 3: SINGLE WRITE MULTI BEATS";
        drv.drive_input_zero();
        txn = gen.generate_txn();
        txn.awlen = 7;
        exp_txn = txn;
        @(posedge CLK);
        drv.drive_write_ar(txn);
        drv.drive_write_w(txn, 0);
        fork
            begin
                do @(posedge CLK); while (!(busif.awvalid && busif.awready));
                busif.awvalid <= 0;
            end
            begin
                do @(posedge CLK); while (!(busif.wvalid && busif.wready));
                busif.wvalid <= 0;
            end
        join
        for (int i = 0; i < (txn.awlen); i++) begin 
            if (i == txn.awlen - 1) begin 
                drv.drive_write_w(txn, 1);
            end 
            else begin 
                drv.drive_write_w(txn, 0);
            end 
            do @(posedge CLK); while (!(busif.wvalid && busif.wready));
                busif.wvalid <= 0;
        end
        $display("TB:: drove 8-beat txn");
        repeat  (2) @(posedge CLK);
    endtask
        
    task single_read_multi_beat_test;
        test_case = "TEST CASE 4: SINGLE READ MULTI BEAT";
        drv.drive_input_zero();
        repeat (1) @(posedge CLK);
        for (int i = 0; i < 8; i++) begin 
            drv.drive_read_w();
            @(posedge CLK);
        end
        drv.drive_read_aw();
        repeat (2) @(posedge CLK);
    endtask

    task single_write_multi_beat(int len);
        txn = gen.generate_txn();
        txn.awlen = len;
        exp_txn = txn;
        @(posedge CLK);
        drv.drive_write_ar(txn);
        drv.drive_write_w(txn, 0);
        fork
            begin
                do @(posedge CLK); while (!(busif.awvalid && busif.awready));
                busif.awvalid <= 0;
            end
            begin
                do @(posedge CLK); while (!(busif.wvalid && busif.wready));
                busif.wvalid <= 0;
            end
        join
        for (int i = 0; i < (len); i++) begin 
            if (i == len - 1) begin 
                drv.drive_write_w(txn, 1);
            end 
            else begin 
                drv.drive_write_w(txn, 0);
            end 
            do @(posedge CLK); while (!(busif.wvalid && busif.wready));
                busif.wvalid <= 0;
        end
        $display("TB:: drove 8-beat txn");
        repeat  (2) @(posedge CLK);
    endtask

    task fill_fifo_test;
        test_case = "TEST CASE 5: FILL FIFO TEST";
        drv.drive_input_zero();
        single_write_multi_beat(9);
        single_write_multi_beat(9);
        single_write_multi_beat(10);
    endtask

    task single_read_multi_beat(int len);
        repeat (1) @(posedge CLK);
        for (int i = 0; i < len; i++) begin 
            drv.drive_read_w();
            @(posedge CLK);
        end
        drv.drive_read_aw();
        @(posedge CLK);
        busif.aw_pop = 0;
    endtask

    task empty_filled_fifo;
        test_case = "TEST CASE 6: EMPTY FIFO TEST";
        drv.drive_input_zero();
        single_read_multi_beat(9);
        single_read_multi_beat(9);
        single_read_multi_beat(10);
    endtask
    initial begin
        $display("TB: start");
        //nRST = 0;
        gen = new();
        drv = new(busif);
        mon = new(busif);
        scb = new();
        exp_txn = new();
        cov = new();
        reset_dut();

        single_write_test();
        single_read_test();
        reset_dut();
        single_write_multi_beat_test();
        single_read_multi_beat_test();
        reset_dut();
        fill_fifo_test();
        empty_filled_fifo();
        reset_dut();
        $finish;
    end


endmodule