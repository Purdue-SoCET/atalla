`timescale 1ps/1ps
`include "axi_bus_pkg.sv"

import axi_bus_pkg::*;
module axi_read_arbiter_tb ();

    localparam CLK_PERIOD = 10ns;

    logic clk, nrst;
    logic ready, sp0_req, sp1_req, d_req, i_req;
    logic [ARGRANT-1:0] grant_sel;

    string test_case = "";

    axi_read_arbiter DUT (.CLK(clk), 
                          .nRST(nrst), 
                          .ready(ready), 
                          .sp0_req(sp0_req), 
                          .sp1_req(sp1_req), 
                          .d_req(d_req), 
                          .i_req(i_req),
                          .grant_sel(grant_sel));

    // clockgen
    always begin
        clk = 0;
        #(CLK_PERIOD / 2.0);
        clk = 1;
        #(CLK_PERIOD / 2.0);
    end

    task reset_dut;
    begin
        nrst = 0;
        @(posedge clk);
        @(posedge clk);
        @(negedge clk);
        nrst = 1;
        @(posedge clk);
        @(posedge clk);
    end
    endtask

    task reset_inputs;
    begin
        ready = 0;
        sp0_req = 0;
        sp1_req = 0;
        d_req = 0;
        i_req = 0;
    end 
    endtask

    // TEST CASE 1: IDLE TO SP0
    task idle_to_sp0;
    begin
        test_case = "TEST CASE 1";
        reset_dut();
        reset_inputs();
        #(CLK_PERIOD);
        ready = 1;
        sp0_req = 1;
        #(CLK_PERIOD*2);
        ready = 0;
        #(CLK_PERIOD);
        sp0_req = 0;
        #(CLK_PERIOD);
        #(CLK_PERIOD);
    end
    endtask

    // TEST CASE 2: IDLE TO SP1
    task idle_to_sp1;
    begin
        test_case = "TEST CASE 2";
        reset_dut();
        reset_inputs();
        #(CLK_PERIOD);
        ready = 1;
        sp1_req = 1;
        #(CLK_PERIOD*2);
        ready = 0;
        #(CLK_PERIOD);
        sp1_req = 0;
        #(CLK_PERIOD);
        #(CLK_PERIOD);
    end
    endtask

    // TEST CASE 3: IDLE TO D$
    task idle_to_d;
    begin
        test_case = "TEST CASE 3";
        reset_dut();
        reset_inputs();
        #(CLK_PERIOD);
        ready = 1;
        d_req = 1;
        #(CLK_PERIOD*2);
        ready = 0;
        #(CLK_PERIOD);
        d_req = 0;
        #(CLK_PERIOD);
        #(CLK_PERIOD);
    end
    endtask

    // TEST CASE 4: IDLE TO I$
    task idle_to_i;
    begin
        test_case = "TEST CASE 4";
        reset_dut();
        reset_inputs();
        #(CLK_PERIOD);
        ready = 1;
        i_req = 1;
        #(CLK_PERIOD*2);
        ready = 0;
        #(CLK_PERIOD);
        i_req = 0;
        #(CLK_PERIOD);
        #(CLK_PERIOD);
    end
    endtask

    // TEST CASE 5: IDLE->SP0->SP1->D$->I$->IDLE
    task one_rotation;
    begin
        test_case = "TEST CASE 5";
        reset_dut();
        reset_inputs();
        #(CLK_PERIOD);
        ready = 1;
        sp0_req = 1;
        sp1_req = 1;
        d_req = 1;
        i_req = 1;
        #(CLK_PERIOD*5)
        sp0_req = 0;
        sp1_req = 0;
        d_req = 0;
        i_req = 0;
    end 
    endtask

    // TEST CASE 6: RANDOM TRANSISTIONS (leaving ready high)
    task rand_transitions;
    begin
        test_case = "TEST CASE 6";
        reset_dut();
        reset_inputs();
        #(CLK_PERIOD);
        ready = 1;
        // idle to sp0 to d$
        sp0_req = 1;
        d_req = 1;
        #(CLK_PERIOD*3);
        //  d$ to i$ to sp0
        d_req = 0;
        i_req = 1;
        #(CLK_PERIOD*2);
        // sp0 to sp1 to i$
        sp1_req = 1;
        #(CLK_PERIOD*2);
        // i$ to d$
        sp0_req = 0;
        sp1_req = 0;
        d_req = 1; 
        i_req = 0;
        #(CLK_PERIOD);
        // d$ to sp1
        sp1_req = 1;
        d_req = 0;
        #(CLK_PERIOD);
        // sp1 to i$ to sp1
        i_req = 1;
        #(CLK_PERIOD*2);
        // sp1 to sp0
        i_req = 0;
        sp1_req = 0;
        sp0_req = 1;
        #(CLK_PERIOD);
        sp0_req = 0;
        #(CLK_PERIOD*3);
        sp0_req = 1;
        #(CLK_PERIOD*3);

    end 
    endtask

    // TESTCASE 7: IDLE NO READY
    task idle_no_ready;
    begin
        test_case = "TEST CASE 7";
        reset_dut();
        reset_inputs();
        #(CLK_PERIOD);
        ready = 0;
        sp0_req = 1;
        sp1_req = 1;
        d_req = 1;
        i_req = 1;
        #(CLK_PERIOD*4);
    end
    endtask

    initial begin
        idle_to_sp0();
        idle_to_sp1();
        idle_to_d();
        idle_to_i();
        one_rotation();
        rand_transitions();
        idle_no_ready();
        $finish;
    end
endmodule