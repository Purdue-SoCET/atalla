/*  Aryan Kadakia - kadakia0@purdue.edu */

`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

// TRANSACTIONS
class axi_write_txn;
    //logic                 awvalid;
    rand logic [AWID-1:0]      awid;
    rand logic [AWADDR-1:0]    awaddr;
    rand logic [AWLEN-1:0]     awlen;
    logic [AWSIZE-1:0]         awsize = 3'b011;
    logic [AWBURST-1:0]        awburst = 2'b01;

    //logic                 wvalid;
    rand logic [WID-1:0]       wid;
    rand logic [WDATA-1:0]     wdata;
    logic [WSTRB-1:0]          wstrb = '0;
    logic                      wlast = 1'b1;

    constraint id_match {
        wid == awid;
    }

    constraint single_beat {
        awlen == 0;
    }
endclass

// GENERATOR
class axi_generator;
    // function <return_type> <function_name>();
    function axi_write_txn generate_txn();
        axi_write_txn txn; // creates handle
        txn = new(); // constructs object
        if (!txn.randomize()) begin  // randomizes input stimulus
            $fatal("Randomization failed");
        end
        return txn;
    endfunction 
endclass

// DRIVER 
class axi_driver;
    virtual axi_bus_if.tb vif; // giving class a virtual interface (handle to interface instance)
    
    function new(virtual axi_bus_if.tb vif); 
        this.vif = vif; // constructor of driver class
    endfunction
    task drive(axi_write_txn txn);
        vif.awvalid <= 1;
        vif.aw_gen_i.addr  <= txn.awaddr;
        vif.aw_gen_i.id <= txn.awid;
        vif.aw_gen_i.len <= txn.awlen;
        vif.aw_gen_i.size <= txn.awsize;
        vif.aw_gen_i.burst <= txn.awburst;

        vif.wvalid <= 1;
        vif.w_gen_i.data <= txn.wdata;
        vif.w_gen_i.id   <= txn.wid;
        vif.w_gen_i.strb <= txn.wstrb;
        vif.w_gen_i.last <= txn.wlast;
    endtask
endclass

// Monitor
class axi_monitor;
    virtual axi_bus_if.tb vif;
    function new(virtual axi_bus_if.tb vif);
        this.vif = vif;
    endfunction
    // task sample();
    //     if (vif.awvalid) begin
    //         $display("MONITOR: awid=%0d awaddr=%0h awlen=%0d", 
    //                 vif.aw_gen_i.id, vif.aw_gen_i.addr, vif.aw_gen_i.len);
    //     end

    //     if (vif.wvalid) begin
    //         $display("MONITOR: wid=%0d wdata=%0h wlast=%0b",
    //                 vif.w_gen_i.id,  vif.w_gen_i.data, vif.w_gen_i.last);
    //     end
    // endtask
    function axi_write_txn sample();
        axi_write_txn txn;
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
    task check(axi_write_txn exp, axi_write_txn obs);
        if (exp.awid   != obs.awid)   $error("AWID mismatch");
        if (exp.awaddr != obs.awaddr) $error("AWADDR mismatch");
        if (exp.awlen  != obs.awlen)  $error("AWLEN mismatch");

        if (exp.wid    != obs.wid)    $error("WID mismatch");
        if (exp.wdata  != obs.wdata)  $error("WDATA mismatch");
        if (exp.wlast  != obs.wlast)  $error("WLAST mismatch");

        if ((exp.awid   == obs.awid)   &&
            (exp.awaddr == obs.awaddr) &&
            (exp.awlen  == obs.awlen)  &&
            (exp.wid    == obs.wid)    &&
            (exp.wdata  == obs.wdata)  &&
            (exp.wlast  == obs.wlast)) begin
            $display("SCOREBOARD PASS");
        end
    endtask
endclass

module axi_write_manager_tb ();
    parameter CLK_PERIOD = 10;

    logic CLK = 0, nRST;

    // clock
    always #(CLK_PERIOD/2) CLK++;

    // interface 
    axi_bus_if busif(.CLK(CLK), .nRST(nRST));

    // DUT
    axi_write_manager DUT (
        .CLK     (CLK),
        .nRST    (nRST),
        .wrmgr_if (busif)
    );

    task reset_dut;
    begin
        nRST = 0;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        nRST = 1;
        @(posedge CLK);
        @(posedge CLK);
    end
    endtask

    axi_write_txn txn;
    axi_generator gen;
    axi_driver drv;
    axi_monitor mon;
    axi_scoreboard scb;

    axi_write_txn exp_txn;
    axi_write_txn obs_txn;

    initial begin
        $display("TB: start");
        nRST = 0;
        gen = new();
        drv = new(busif);
        mon = new(busif);
        scb = new();
        exp_txn = new();

        repeat (2) @(posedge CLK);
        nRST = 1;
        $display("TB: reset released");

        txn = gen.generate_txn();
        exp_txn = txn;

        @(posedge CLK);
        drv.drive(txn);
        $display("TB: drove txn");

        @(posedge CLK);
        obs_txn = mon.sample();
         $display("TB: sampled txn");

        scb.check(exp_txn, obs_txn);
        $display("TB: checked txn");
        repeat (2) @(posedge CLK);
        $finish;
    end


endmodule