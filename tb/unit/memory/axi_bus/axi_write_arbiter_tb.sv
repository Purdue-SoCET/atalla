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
    
    // TEST CASE 1: RESET INIT STATE
    task reset_init_state;
    begin 
        test_case = "TEST CASE 1: RESET INIT STATE";
        sub_test_case = "1A: reset init state";
        reset_dut();
    end 
    endtask


    initial begin
        reset_init_state();
        $finish;
    end 

endprogram