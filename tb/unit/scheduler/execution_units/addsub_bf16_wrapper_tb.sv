`timescale 1ns / 10ps
`include "addsub_bf16_wrapper_if.sv"

module addsub_bf16_wrapper_tb;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;

    addsub_bf16_wrapper_if addsub_if ();

    addsub_bf16_wrapper DUT (.clk(CLK), .nRST(nRST), .addsub_if(addsub_if));


    initial begin
        addsub_if.bf1_in = 16'b0;
        addsub_if.bf2_in = 16'b0;
        addsub_if.add_sub = 1'b0;
        addsub_if.rdIn = 8'b0;
        addsub_if.valid_in = 1'b0;
        addsub_if.ready_out = 1'b1;
        nRST = 1'b1;

        #(PERIOD);
        nRST = 1'b0;
        #(PERIOD);
        #(PERIOD);
        nRST = 1'b1;
        #(PERIOD);
        #(PERIOD);
        #(PERIOD);

        addsub_if.bf1_in = 16'h4120;
        addsub_if.bf2_in = 16'h41a0;
        addsub_if.valid_in = 1'b1;
        addsub_if.rdIn = 8'd12;
        #(PERIOD);
        #(PERIOD);
        #(PERIOD);
        addsub_if.valid_in = 1'b0;
        addsub_if.bf1_in = 16'h0;
        addsub_if.bf2_in = 16'h0;
        addsub_if.rdIn = 8'd0;
        #(PERIOD);
        #(PERIOD);
        #(PERIOD);
        addsub_if.valid_in = 1'b1;
        addsub_if.bf1_in = 16'h42c8;
        addsub_if.bf2_in = 16'h41a0;
        addsub_if.rdIn = 8'd28;
        addsub_if.ready_out = 1'b0;
        addsub_if.add_sub = 1'b1;
        #(PERIOD);
        #(PERIOD);
        #(PERIOD);
        #(PERIOD);
        #(PERIOD);
        #(PERIOD);
        addsub_if.ready_out = 1'b1;
        #(PERIOD);
        #(PERIOD);
        #(PERIOD);

        $display("DONE");
        $finish;
    end


endmodule