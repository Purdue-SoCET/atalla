/*  Aryan Kadakia - kadakia0@purdue.edu */

`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;
module axi_write_driver_tb ();
    parameter CLK_PERIOD = 10;

    logic CLK = 0, nRST;

    // clock
    always #(CLK_PERIOD/2) CLK++;

    // interface 
    axi_bus_if busif(.CLK(CLK), .nRST(nRST));

    // DUT
    axi_write_driver DUT (
        .CLK     (CLK),
        .nRST    (nRST),
        .wdrv_if (busif)
    );

    // test program
    test PROG (
        .CLK     (CLK),
        .nRST    (nRST),
        .wdrv_if (busif)
    );

endmodule

program test (
    input logic CLK,
    output logic nRST,
    axi_bus_if.write_driver_tb wdrv_if
);

    parameter CLK_PERIOD = 10;
    string test_case;

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
        wdrv_if.aw_grant = '0;
        wdrv_if.head_sp0_awvalid = '0;
        wdrv_if.head_sp0_aw_o = '0;
        wdrv_if.head_sp0_wvalid = '0;
        wdrv_if.head_sp0_w_o = '0;
        wdrv_if.head_sp1_awvalid = '0;
        wdrv_if.head_sp1_aw_o = '0;
        wdrv_if.head_sp1_wvalid = '0;
        wdrv_if.head_sp1_w_o = '0;
        wdrv_if.head_d_awvalid = '0;
        wdrv_if.head_d_aw_o = '0;
        wdrv_if.head_d_wvalid = '0;
        wdrv_if.head_d_w_o = '0;
        wdrv_if.aw_o_ready = '0;
        wdrv_if.w_o_ready = '0;
    end 
    endtask

    task set_sp0;
        wdrv_if.head_sp0_awvalid = 1;
        wdrv_if.head_sp0_aw_o.addr = 32'hDEADBEEF;
        wdrv_if.head_sp0_aw_o.mid_id = 4'b0010;
        wdrv_if.head_sp0_aw_o.size = 3'b011;
        wdrv_if.head_sp0_aw_o.len = 4'h7;
        wdrv_if.head_sp0_aw_o.burst = 2'b01;
    endtask

    task set_sp1;
        wdrv_if.head_sp1_awvalid = 1;
        wdrv_if.head_sp1_aw_o.addr = 32'hBEEFBEEF;
        wdrv_if.head_sp1_aw_o.mid_id = 4'b0101;
        wdrv_if.head_sp1_aw_o.size = 3'b011;
        wdrv_if.head_sp1_aw_o.len = 4'h7;
        wdrv_if.head_sp1_aw_o.burst = 2'b01;
    endtask

    task set_dcache;
        wdrv_if.head_d_awvalid = 1;
        wdrv_if.head_d_aw_o.addr = 32'hBEEFDEAD;
        wdrv_if.head_d_aw_o.mid_id = 4'b1011;
        wdrv_if.head_d_aw_o.size = 3'b011;
        wdrv_if.head_d_aw_o.len = 4'h7;
        wdrv_if.head_d_aw_o.burst = 2'b01;
    endtask


    // TEST CASE 1: RESET INIT STATE
    task reset_init_state;
    begin 
        test_case = "TEST CASE 1: RESET INIT STATE";
        reset_inputs();
        reset_dut();
    end 
    endtask
    
    // TEST CASE 2: SEND SP0 REQUEST
    task send_sp0;
    begin 
        test_case = "TEST CASE 2: SEND SP0 REQUEST";
        reset_inputs();
        reset_dut();
        #(CLK_PERIOD*2);
        set_sp0();
        set_sp1();
        set_dcache();
        #(CLK_PERIOD);
        wdrv_if.aw_grant = 3'b100;
        #(CLK_PERIOD*2);
        wdrv_if.aw_o_ready = 1;
        wdrv_if.w_o_ready = 1;
        #(CLK_PERIOD*2);
        reset_inputs();
        #(CLK_PERIOD);
    end
    endtask

    initial begin
        reset_init_state();
        send_sp0();
        $finish;
    end


endprogram