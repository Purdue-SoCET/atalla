/*  Aryan Kadakia - kadakia0@purdue.edu */

`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;
module axi_write_arbiter_tb ();
    
    parameter CLK_PERIOD = 10;

    logic CLK = 0, nRST;

    // clock
    always #(CLK_PERIOD/2) CLK++;

    // interface 
    axi_bus_if busif(.CLK(clk), .nRST(nrst));

    // DUT
    axi_write_arbiter DUT (
        .CLK     (CLK),
        .nRST    (nRST),
        .arbw_if (busif)
    );

    // test program
    test PROG (
        .CLK     (CLK),
        .nRST    (nRST),
        .arbw_if (busif)  
    );

endmodule

program test (
    input  logic CLK,
    output logic nRST,
    axi_bus_if.write_arbiter_tb arbw_if
);
    parameter CLK_PERIOD = 10;
    string test_case;
    string sub_test_case;

    task reset_dut;
    begin
        nRST = 0;
        @(posedge CLK);
        @(posedge CLK);
        nRST = 1;
        @(posedge CLK);
        @(posedge CLK);
    end
    endtask

    task reset_inputs;
    begin 
        arbw_if.sp0_req_w = 0;
        arbw_if.sp1_req_w = 0;
        arbw_if.d_req_w = 0;
        arbw_if.sp0_len_w = '0; 
        arbw_if.sp1_len_w = '0;
        arbw_if.d_len_w = '0;
        arbw_if.skid_ready_w = 1;
    end 
    endtask
    
    // TEST CASE 1: RESET INIT STATE
    task reset_init_state;
    begin 
        test_case = "TEST CASE 1: RESET INIT STATE";
        sub_test_case = "1A: reset init state";
        reset_inputs();
        reset_dut();
    end 
    endtask

    // TEST CASE 2: READY-GATED HOLD
    task ready_gated_hold;
    begin
        test_case = "TEST CASE 2: READY-GATED HOLD";
        sub_test_case = "2A: From IDLE with SP0 request";
        reset_inputs();
        reset_dut();
        arbw_if.skid_ready_w = 0;
        arbw_if.sp0_req_w = 1;
        arbw_if.sp0_len_w = 4'h7;
        #(CLK_PERIOD*2);
        sub_test_case = "2B: From IDLE with SP1 request";
        reset_inputs();
        reset_dut();
        arbw_if.skid_ready_w = 0;
        arbw_if.sp1_req_w = 1;
        arbw_if.sp1_len_w = 4'h7;
        #(CLK_PERIOD*2);
        sub_test_case = "2C: From IDLE with D$ request";
        reset_inputs();
        reset_dut();
        arbw_if.skid_ready_w = 0;
        arbw_if.d_req_w = 1;
        arbw_if.d_len_w = 4'h7;
        #(CLK_PERIOD*2);
    end
    endtask

    // TEST CASE 3: LATCH AND DECREMENT 1
    task latch_and_decrement_1;
    begin 
        test_case = "TEST CASE 3: LATCH AND DECREMENT 1";
        sub_test_case = "3A: From IDLE with SP0 request (8 beats)";
        reset_inputs();
        reset_dut();
        arbw_if.sp0_req_w = 1;
        arbw_if.sp0_len_w = 4'h7;
        #(CLK_PERIOD*3);
        arbw_if.skid_ready_w = 0;
        #(CLK_PERIOD*3);
        arbw_if.skid_ready_w = 1;
        #(CLK_PERIOD*5);
        arbw_if.sp0_req_w = 0;
        #(CLK_PERIOD);

        sub_test_case = "3B: From IDLE with SP1 request (8 beats)";
        reset_inputs();
        reset_dut();
        arbw_if.sp1_req_w = 1;
        arbw_if.sp1_len_w = 4'h7;
        #(CLK_PERIOD);
        arbw_if.skid_ready_w = 0;
        #(CLK_PERIOD*3);
        arbw_if.skid_ready_w = 1;
        #(CLK_PERIOD*8);
        arbw_if.sp1_req_w = 0;
        #(CLK_PERIOD);

        sub_test_case = "3C: From IDLE with D$ request (8 beats)";
        reset_inputs();
        reset_dut();
        arbw_if.d_req_w = 1;
        arbw_if.d_len_w = 4'h7;
        #(CLK_PERIOD*7);
        arbw_if.skid_ready_w = 0;
        #(CLK_PERIOD*3);
        arbw_if.skid_ready_w = 1;
        #(CLK_PERIOD);
        arbw_if.d_req_w = 0;
        #(CLK_PERIOD);

        sub_test_case = "3D: From IDLE with SP0 request (1 beats)";
        reset_inputs();
        reset_dut();
        arbw_if.sp0_req_w = 1;
        arbw_if.sp0_len_w = 4'h0;
        #(CLK_PERIOD);
        arbw_if.sp0_req_w = 0;
        #(CLK_PERIOD);

        sub_test_case = "3E: From IDLE with SP1 request (1 beats)";
        reset_inputs();
        reset_dut();
        arbw_if.sp0_req_w = 1;
        arbw_if.sp0_len_w = 4'h0;
        #(CLK_PERIOD*2);
        arbw_if.sp0_req_w = 0;
        #(CLK_PERIOD);

        sub_test_case = "3F: From IDLE with D$ request (1 beats)";
        reset_inputs();
        reset_dut();
        arbw_if.d_req_w = 1;
        arbw_if.d_len_w = 4'h0;
        arbw_if.skid_ready_w = 0;
        #(CLK_PERIOD*2);
        arbw_if.skid_ready_w = 1;
        #(CLK_PERIOD);
        arbw_if.d_req_w = 0;
        #(CLK_PERIOD);

        sub_test_case = "3F: From IDLE with SP0$ request (MAX (16) beats)";
        reset_inputs();
        reset_dut();
        arbw_if.sp0_req_w = 1;
        arbw_if.sp0_len_w = 4'hF;
        #(CLK_PERIOD*16);
        arbw_if.sp0_req_w = 0;
        #(CLK_PERIOD);
    end 
    endtask

    // TEST CASE 4: LATCH AND DECREMENT 2
    task latch_and_decrement_2;
    begin
        test_case = "TEST CASE 4: LATCH AND DECREMENT 2";
        sub_test_case = "4A: From IDLE with SP0 2 requests (7beats, 4 beats)";
        reset_inputs();
        reset_dut();
        arbw_if.sp0_req_w = 1;
        arbw_if.sp0_len_w = 4'h6;
        #(CLK_PERIOD*7);
        arbw_if.sp0_len_w = 4'h3;
        #(CLK_PERIOD*4)
        arbw_if.sp0_req_w = 0;
        #(CLK_PERIOD);
    end 
    endtask

    // TEST CASE 5: PRIORITY UNDER CONTENTION
    task priority_under_contention;
    begin 
        test_case = "TEST CASE 5: PRIORITY UNDER CONTENTION";
        sub_test_case = "5A: From IDLE -> SP0 -> SP1 -> D$ -> IDLE";
        reset_inputs();
        reset_dut();
        arbw_if.sp0_req_w = 1;
        arbw_if.sp0_len_w = 4'h7;
        arbw_if.sp1_req_w = 1;
        arbw_if.sp1_len_w = 4'h7;
        arbw_if.d_req_w = 1;
        arbw_if.d_len_w = 4'h7;
        //#(CLK_PERIOD*8);
        #(CLK_PERIOD*24);
        arbw_if.sp0_req_w = 0;
        //#(CLK_PERIOD*8);
        arbw_if.sp1_req_w = 0;
        //#(CLK_PERIOD*8);
        arbw_if.d_req_w = 0;
        #(CLK_PERIOD);

        sub_test_case = "5B: From IDLE -> SP0 -> SP1 -> SP0 -> IDLE";
        reset_inputs();
        reset_dut();
        arbw_if.sp0_req_w = 1;
        arbw_if.sp0_len_w = 4'h6;
        arbw_if.sp1_req_w = 1;
        arbw_if.sp1_len_w = 4'h2;
        #(CLK_PERIOD*17);
        arbw_if.sp0_req_w = 0;
        arbw_if.sp1_req_w = 0;
        #(CLK_PERIOD);

        sub_test_case = "5C: From IDLE -> SP0 -> D$ -> SP0 -> IDLE";
        reset_inputs();
        reset_dut();
        arbw_if.sp0_req_w = 1;
        arbw_if.sp0_len_w = 4'h1;
        arbw_if.d_req_w = 1;
        arbw_if.d_len_w = 4'h5;
        #(CLK_PERIOD*10);
        arbw_if.sp0_req_w = 0;
        arbw_if.d_req_w = 0;
        #(CLK_PERIOD);

        sub_test_case = "5D: From IDLE -> SP1 -> D$ -> SP1 -> IDLE";
        reset_inputs();
        reset_dut();
        arbw_if.sp1_req_w = 1;
        arbw_if.sp1_len_w = 4'h4;
        arbw_if.d_req_w = 1;
        arbw_if.d_len_w = 4'h3;
        #(CLK_PERIOD*14);
        arbw_if.sp1_req_w = 0;
        arbw_if.d_req_w = 0;
        #(CLK_PERIOD);
    end 
    endtask

    // TEST CASE 6: STAY ON SAME GRANT
    task stay_on_same_grant;
    begin 
        test_case = "TEST CASE 6: STAY ON SAME GRANT";
        sub_test_case = "6A: From IDLE -> SP0 -> SP0 -> SP0 -> IDLE";
        reset_inputs();
        reset_dut();
        arbw_if.sp0_req_w = 1;
        arbw_if.sp0_len_w = 4'h7;
        #(CLK_PERIOD*8);
        arbw_if.skid_ready_w = 0;
        #(CLK_PERIOD);
        arbw_if.skid_ready_w = 1;
        arbw_if.sp0_len_w = 4'h6;
        #(CLK_PERIOD*7);
        arbw_if.skid_ready_w = 0;
        #(CLK_PERIOD);
        arbw_if.skid_ready_w = 1;
        arbw_if.sp0_len_w = 4'h5;
        #(CLK_PERIOD*6);
        arbw_if.sp0_req_w = 0;
        #(CLK_PERIOD);

        sub_test_case = "6B: From IDLE -> SP1 -> SP1 -> SP1 -> IDLE";
        reset_inputs();
        reset_dut();
        arbw_if.sp1_req_w = 1;
        arbw_if.sp1_len_w = 4'h4;
        #(CLK_PERIOD*5);
        arbw_if.skid_ready_w = 0;
        #(CLK_PERIOD);
        arbw_if.skid_ready_w = 1;
        arbw_if.sp1_len_w = 4'h3;
        #(CLK_PERIOD*4);
        arbw_if.skid_ready_w = 0;
        #(CLK_PERIOD);
        arbw_if.skid_ready_w = 1;
        arbw_if.sp1_len_w = 4'h2;
        #(CLK_PERIOD*3);
        arbw_if.sp1_req_w = 0;
        #(CLK_PERIOD);

        sub_test_case = "6C: From IDLE -> D$ -> D$ -> D$ -> IDLE";
        reset_inputs();
        reset_dut();
        arbw_if.d_req_w = 1;
        arbw_if.d_len_w = 4'h2;
        #(CLK_PERIOD*3);
        arbw_if.skid_ready_w = 0;
        #(CLK_PERIOD);
        arbw_if.skid_ready_w = 1;
        arbw_if.d_len_w = 4'h1;
        #(CLK_PERIOD*2);
        arbw_if.skid_ready_w = 0;
        #(CLK_PERIOD);
        arbw_if.skid_ready_w = 1;
        arbw_if.d_len_w = 4'h0;
        #(CLK_PERIOD);
        arbw_if.d_req_w = 0;
        #(CLK_PERIOD);
    end
    endtask

    task random_requests;
    int i;
    int rand_len;
    begin
        test_case = "TEST CASE 7: RANDOM REQUESTS";
        reset_inputs();
        reset_dut();

        // run random traffic for N cycles
        for (i = 0; i < 200; i++) begin
            @(posedge CLK);

            // Randomly toggle skid_ready (80% ready, 20% stall)
            arbw_if.skid_ready_w = ($urandom_range(0,4) != 0);

            // Randomly decide if each master issues a request
            arbw_if.sp0_req_w = $urandom_range(0,1);
            arbw_if.sp1_req_w = $urandom_range(0,1);
            arbw_if.d_req_w   = $urandom_range(0,1);

            // Randomize lengths when request is high
            if (arbw_if.sp0_req_w) begin
                rand_len = ($urandom_range(0,9)); // bias toward 0–9
                arbw_if.sp0_len_w = rand_len[3:0];
            end

            if (arbw_if.sp1_req_w) begin
                rand_len = ($urandom_range(0,9));
                arbw_if.sp1_len_w = rand_len[3:0];
            end

            if (arbw_if.d_req_w) begin
                rand_len = ($urandom_range(0,9));
                arbw_if.d_len_w = rand_len[3:0];
            end
        end

        // Clean exit
        reset_inputs();
        repeat (5) @(posedge CLK);
    end
    endtask


    initial begin
        reset_init_state();
        ready_gated_hold();
        latch_and_decrement_1();
        latch_and_decrement_2();
        priority_under_contention();
        stay_on_same_grant();
        random_requests();
        $finish;
    end 

endprogram