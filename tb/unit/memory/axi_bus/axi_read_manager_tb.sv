`timescale 1ps/1ps
`include "axi_bus_pkg.sv"

import axi_bus_pkg::*;

module axi_read_manager_tb ();

    localparam CLK_PERIOD = 10ns;
    string test_case = "";

    logic clk, nrst;
    logic arvalid, aready, pop, head_valid;
    logic [ARID-1:0]      arid;
    logic [ARADDR-1 :0]   araddr;
    logic [ARLEN-1  :0]   arlen;
    logic [ARSIZE-1 :0]   arsize;
    logic [ARBURST-1:0]   arburst;
    logic [MID_ARID-1:0] head_id;
    logic [ARADDR-1 :0]  head_addr;
    logic [ARLEN-1  :0]  head_len;
    logic [ARSIZE-1 :0]  head_size;
    logic [ARBURST-1:0]  head_burst;

    axi_read_manager DUT (.CLK(clk),
                          .nRST(nrst),
                          .arvalid(arvalid),
                          .arid(arid),
                          .araddr(araddr),
                          .arlen(arlen),
                          .arsize(arsize),
                          .arburst(arburst),
                          .aready(aready),
                          .pop(pop),
                          .head_valid(head_valid),
                          .head_addr(head_addr),
                          .head_id(head_id),
                          .head_size(head_size),
                          .head_len(head_len),
                          .head_burst(head_burst));

    // clock gen 
    always begin
        clk = 0;
        #(CLK_PERIOD/2);
        clk = 1;
        #(CLK_PERIOD/2);
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
        arvalid =  0;
        arid    = '0;
        araddr  = '0;
        arlen   = '0;
        arsize  = '0;
        arlen   = '0;
        arburst = '0;
        pop     =  0;
    end 
    endtask

    // TEST CASE 1: Fill and Pop (1 payload)
    task fill_pop_one;
    begin 
        test_case = "Test Case 1";
        reset_dut();
        reset_inputs();
        #(CLK_PERIOD*2);
        arvalid = 1;
        arid    = 2'b00;
        araddr  = 32'hDEADBEEF;
        arsize  = 3'b011;
        arlen   = 3'b111;
        arburst = 3'b01;
        #(CLK_PERIOD);
        reset_inputs();
        #(CLK_PERIOD*5);
        pop = 1;
        #(CLK_PERIOD);
        pop = 0; 
        #(CLK_PERIOD*5);
    end
    endtask

    // TEST CASE 2: Fill and Pop (3 items)
    task fill_pop_three;
    begin
        test_case = "Test Case 2";
        reset_dut();
        reset_inputs();
        #(CLK_PERIOD*2);
        arvalid = 1;
        arid    = 2'b00;
        araddr  = 32'hDEADBEEF;
        arsize  = 3'b011;
        arlen   = 3'b111;
        arburst = 3'b01;
        #(CLK_PERIOD);
        arvalid = 1;
        arid    = 2'b01;
        araddr  = 32'hABCDABCD;
        arsize  = 3'b011;
        arlen   = 3'b111;
        arburst = 3'b01;
        #(CLK_PERIOD);
        arvalid = 1;
        arid    = 2'b10;
        araddr  = 32'hBEEFDEAD;
        arsize  = 3'b011;
        arlen   = 3'b111;
        arburst = 3'b01;
        #(CLK_PERIOD);
        reset_inputs();
        #(CLK_PERIOD*5);
        pop = 1; 
        #(CLK_PERIOD);
        pop = 0;
        arvalid = 1;
        arid    = 2'b11;
        araddr  = 32'h11110000;
        arsize  = 3'b011;
        arlen   = 3'b111;
        arburst = 3'b01;
        #(CLK_PERIOD);
        pop = 1;
        #(CLK_PERIOD);
        arvalid = 1;
        arid    = 2'b00;
        araddr  = 32'h10101010;
        arsize  = 3'b011;
        arlen   = 3'b111;
        arburst = 3'b01;
        pop = 0;
        #(CLK_PERIOD)
        reset_inputs();
        #(CLK_PERIOD*5);
        pop = 1;
        #(CLK_PERIOD*5);
    end
    endtask


    initial begin 
        fill_pop_one();
        fill_pop_three();
        $finish;
    end 

endmodule