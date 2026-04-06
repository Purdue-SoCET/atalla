`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

// typedef enum logic [1:0] {
//     SP0    = 2'b00,
//     SP1    = 2'b01,
//     DCACHE = 2'b10
// } master_t;

// RESPONSE TRANSACTIONS
class axi_write_rsp;
    rand mid_t               master;
    rand logic [BID-1:0]     id;
    bresp_t             resp = B_OKAY;

    logic [MID_BID-1:0] full_id;
    function void post_randomize(); // automatically called after randomize to preform concatenation
        full_id = {master, id};
    endfunction
endclass

// Generator
class axi_generator_rsp;
    // fucntion <return_type> <fucntion_name>()
    function axi_write_rsp generate_rsp();
        axi_write_rsp rsp; // creates handle
        rsp = new(); // constructs object
        if (!rsp.randomize()) begin
            $fatal("Randomization failed");
        end
        return rsp;
    endfunction

    // directed generator per master
    function axi_write_rsp generate_rsp_per_master(mid_t m);
        axi_write_rsp rsp = new();
        if (!rsp.randomize() with {master == m;}) begin 
            $fatal("Randomization failed");
        end 
        return rsp;
    endfunction
endclass

// Driver 
class axi_rsp_driver;
    virtual axi_bus_if.write_response_tb vif;
    function new(virtual axi_bus_if.write_response_tb vif);
        this.vif = vif;
    endfunction
    task drive_rsp(axi_write_rsp rsp);
        vif.b_i_valid <= 1'b1;
        vif.b_i.id <= rsp.full_id;
        vif.b_i.resp <= rsp.resp;
    endtask
    task stop_rsp();
        vif.b_i_valid <= 1'b0;
    endtask
    task drive_input_zero();
        vif.b_i_valid <= 1'b0;
        vif.b_i.id <= '0;
        vif.b_i.resp <= B_OKAY;
        vif.b_sp0_o_ready <= 1'b1;
        vif.b_sp1_o_ready <= 1'b1;
        vif.b_d_o_ready   <= 1'b1;
    endtask

endclass


module axi_write_router_tb ();
    parameter CLK_PERIOD = 10;
    logic CLK = 0, nRST;
    string test_case = "";

    // clock
    always #(CLK_PERIOD/2) CLK++;

    // interface
    axi_bus_if busif(.CLK(CLK), .nRST(nRST));

    // DUT 
    axi_write_router DUT (.CLK(CLK), 
                            .nRST(nRST),
                            .b_i_if(busif),
                            .sp0_b_o_if(busif),
                            .sp1_b_o_if(busif),
                            .d_b_o_if(busif));

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

    axi_write_rsp rsp;
    axi_generator_rsp gen;
    axi_rsp_driver drv;

    task route_sp0_rsp;
        reset_dut();
        test_case = "TEST CASE 1: SP0 RESPONSE";
        drv.drive_input_zero();
        rsp = gen.generate_rsp_per_master(SP0);
        @(posedge CLK);
        drv.drive_rsp(rsp);
        do @(posedge CLK); while (!(busif.b_i_valid && busif.b_i_ready));
        busif.b_i_valid <= 0;
        $display("TB: drove txn");
        @(posedge CLK);
        if (busif.b_sp0_o.id == rsp.id[BID-1:0] && busif.b_sp0_o.resp == rsp.resp) begin 
            $display("Pass");
        end 
        else begin 
            $display("Fail");
        end 
        @(posedge CLK);
        @(posedge CLK);
    endtask

    task route_sp1_rsp;
        reset_dut();
        test_case = "TEST CASE 2: SP1 RESPONSE";
        drv.drive_input_zero();
        rsp = gen.generate_rsp_per_master(SP1);
        @(posedge CLK);
        drv.drive_rsp(rsp);
        do @(posedge CLK); while (!(busif.b_i_valid && busif.b_i_ready));
        busif.b_i_valid <= 0;
        $display("TB: drove txn");
        @(posedge CLK);
        if (busif.b_sp1_o.id == rsp.id[BID-1:0] && busif.b_sp1_o.resp == rsp.resp) begin 
            $display("Pass");
        end 
        else begin 
            $display("Fail");
        end 
        @(posedge CLK);
        @(posedge CLK);
    endtask

    task route_d_rsp;
        reset_dut();
        test_case = "TEST CASE 3: D$ RESPONSE";
        drv.drive_input_zero();
        rsp = gen.generate_rsp_per_master(DCACHE);
        @(posedge CLK);
        drv.drive_rsp(rsp);
        do @(posedge CLK); while (!(busif.b_i_valid && busif.b_i_ready));
        busif.b_i_valid <= 0;
        $display("TB: drove txn");
        @(posedge CLK);
        if (busif.b_d_o.id == rsp.id[BID-1:0] && busif.b_d_o.resp == rsp.resp) begin 
            $display("Pass");
        end 
        else begin 
            $display("Fail");
        end 
        @(posedge CLK);
        @(posedge CLK);
    endtask

    task route_sp0_rsp_noready;
        axi_write_rsp rsp1, rsp2;
        reset_dut();
        test_case = "TEST CASE 4: SP0 RESPONSE READY LOW";
        drv.drive_input_zero();
        busif.b_sp0_o_ready <= 1'b0;
        // first response should be accepted into skid
        rsp1 = gen.generate_rsp_per_master(SP0);
        @(posedge CLK);
        drv.drive_rsp(rsp1);
        do @(posedge CLK); while (!(busif.b_i_valid && busif.b_i_ready));
        busif.b_i_valid <= 1'b0;
        $display("TB: drove 1st rsp");

        // second response should be blocked because skid cannot drain
        rsp2 = gen.generate_rsp_per_master(SP0);
        @(posedge CLK);
        drv.drive_rsp(rsp2);

        repeat (2) @(posedge CLK);

        if (busif.b_i_ready == 1'b0)
            $display("Pass: second rsp blocked");
        else
            $display("Fail: second rsp was not blocked");
        busif.b_i_valid <= 1'b0;
        // also check first response is still waiting at output
        if (busif.b_sp0_o_valid &&
            busif.b_sp0_o.id   == rsp1.id &&
            busif.b_sp0_o.resp == rsp1.resp)
            $display("Pass: first rsp held at SP0 output");
        else
            $display("Fail: first rsp not held correctly");
        @(posedge CLK);
        @(posedge CLK);
        busif.b_sp0_o_ready <= 1'b1;
        drv.drive_rsp(rsp2);
        do @(posedge CLK); while (!(busif.b_i_valid && busif.b_i_ready));
        @(posedge CLK);
        @(posedge CLK);
    endtask

    task route_sp1_rsp_noready;
        axi_write_rsp rsp1, rsp2;
        reset_dut();
        test_case = "TEST CASE 5: SP1 RESPONSE READY LOW";
        drv.drive_input_zero();
        busif.b_sp1_o_ready <= 1'b0;
        // first response should be accepted into skid
        rsp1 = gen.generate_rsp_per_master(SP1);
        @(posedge CLK);
        drv.drive_rsp(rsp1);
        do @(posedge CLK); while (!(busif.b_i_valid && busif.b_i_ready));
        busif.b_i_valid <= 1'b0;
        $display("TB: drove 1st rsp");

        // second response should be blocked because skid cannot drain
        rsp2 = gen.generate_rsp_per_master(SP1);
        @(posedge CLK);
        drv.drive_rsp(rsp2);

        repeat (2) @(posedge CLK);

        if (busif.b_i_ready == 1'b0)
            $display("Pass: second rsp blocked");
        else
            $display("Fail: second rsp was not blocked");
        busif.b_i_valid <= 1'b0;
        // also check first response is still waiting at output
        if (busif.b_sp1_o_valid &&
            busif.b_sp1_o.id   == rsp1.id &&
            busif.b_sp1_o.resp == rsp1.resp)
            $display("Pass: first rsp held at SP0 output");
        else
            $display("Fail: first rsp not held correctly");
        @(posedge CLK);
        @(posedge CLK);
        busif.b_sp1_o_ready <= 1'b1;
        drv.drive_rsp(rsp2);
        do @(posedge CLK); while (!(busif.b_i_valid && busif.b_i_ready));
        @(posedge CLK);
        @(posedge CLK);
    endtask

    task route_d_rsp_noready;
        axi_write_rsp rsp1, rsp2;
        reset_dut();
        test_case = "TEST CASE 6: D$ RESPONSE READY LOW";
        drv.drive_input_zero();
        busif.b_d_o_ready <= 1'b0;
        // first response should be accepted into skid
        rsp1 = gen.generate_rsp_per_master(DCACHE);
        @(posedge CLK);
        drv.drive_rsp(rsp1);
        do @(posedge CLK); while (!(busif.b_i_valid && busif.b_i_ready));
        busif.b_i_valid <= 1'b0;
        $display("TB: drove 1st rsp");

        // second response should be blocked because skid cannot drain
        rsp2 = gen.generate_rsp_per_master(DCACHE);
        @(posedge CLK);
        drv.drive_rsp(rsp2);

        repeat (2) @(posedge CLK);

        if (busif.b_i_ready == 1'b0)
            $display("Pass: second rsp blocked");
        else
            $display("Fail: second rsp was not blocked");
        busif.b_i_valid <= 1'b0;
        // also check first response is still waiting at output
        if (busif.b_d_o_valid &&
            busif.b_d_o.id   == rsp1.id &&
            busif.b_d_o.resp == rsp1.resp)
            $display("Pass: first rsp held at SP0 output");
        else
            $display("Fail: first rsp not held correctly");
        @(posedge CLK);
        @(posedge CLK);
        busif.b_d_o_ready <= 1'b1;
        drv.drive_rsp(rsp2);
        do @(posedge CLK); while (!(busif.b_i_valid && busif.b_i_ready));
        @(posedge CLK);
        @(posedge CLK);
    endtask

    task error_id;
        reset_dut();
        test_case = "TEST CASE 7: error id";
        drv.drive_input_zero();
        rsp = gen.generate_rsp_per_master(ICACHE);
        @(posedge CLK);
        drv.drive_rsp(rsp);
        // do @(posedge CLK); while (!(busif.b_i_valid && busif.b_i_ready));
        // busif.b_i_valid <= 0;
        // $display("TB: drove txn");
        // @(posedge CLK);
        // if (busif.b_d_o.id == rsp.id[BID-1:0] && busif.b_d_o.resp == rsp.resp) begin 
        //     $display("Pass");
        // end 
        // else begin 
        //     $display("Fail");
        // end 
        @(posedge CLK);
        @(posedge CLK);
    endtask

    task route_dual_sp0_rsp;
        axi_write_rsp rsp1, rsp2;
        reset_dut();
        test_case = "TEST CASE 8: SP0 RESPONSE BACK2BACK";
        drv.drive_input_zero();
        // first response should be accepted into skid
        rsp1 = gen.generate_rsp_per_master(SP0);
        rsp2 = gen.generate_rsp_per_master(SP0);
        @(posedge CLK);
        drv.drive_rsp(rsp1);
        @(posedge CLK);
        drv.drive_rsp(rsp2);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
    endtask

    initial begin 
        $display("TB: start");
        gen = new();
        drv = new(busif);

        route_sp0_rsp();
        route_sp1_rsp();
        route_d_rsp();
        route_sp0_rsp_noready();
        route_sp1_rsp_noready();
        route_d_rsp_noready();
        error_id();
        route_dual_sp0_rsp();
        $finish;
    end 

endmodule