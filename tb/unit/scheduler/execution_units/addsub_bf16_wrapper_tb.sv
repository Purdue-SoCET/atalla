`timescale 1ns / 10ps
`include "bfA_bfM_bfS_bfSLT_if.sv"

module addsub_bf16_wrapper_tb;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;
    string casename;

    bfA_bfM_bfS_bfSLT_if mainport ();

    addsub_bf16_wrapper DUT (.clk(CLK), .nRST(nRST), .portmap(mainport));


    initial begin
        casename = "rst";
        mainport.bf1_in = 16'b0;
        mainport.bf2_in = 16'b0;
        mainport.add = 1'b0;
        mainport.sub = 1'b0;
        mainport.mult = 1'b0;
        mainport.slt = 1'b0;
        mainport.rdIn = 8'b0;
        mainport.valid_in = 1'b0;
        mainport.ready_out = 1'b1;
        nRST = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);

        nRST = 1'b1;

        casename = "add, no stall";
        mainport.bf1_in = 16'h4120;
        mainport.bf2_in = 16'h41a0;
        mainport.valid_in = 1'b1;
        mainport.rdIn = 8'd12;
        mainport.add = 1'b1;
        mainport.ready_out = 1'b1;
        @(negedge CLK);
        mainport.bf1_in = 16'h0;
        mainport.bf2_in = 16'h0;
        mainport.valid_in = 1'b0;
        mainport.rdIn = 8'd0;
        mainport.add = 1'b0;
        mainport.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        casename = "add, stall";
        mainport.valid_in = 1'b1;
        mainport.bf1_in = 16'h42c8;
        mainport.bf2_in = 16'h41a0;
        mainport.rdIn = 8'd28;
        mainport.ready_out = 1'b0;
        mainport.add = 1'b1;
        @(negedge CLK);
        mainport.valid_in = 1'b0;
        mainport.bf1_in = 16'h0;
        mainport.bf2_in = 16'h0;
        mainport.rdIn = 8'd0;
        mainport.add = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        mainport.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        

        casename = "sub, no stall";
        mainport.bf1_in = 16'h4120;
        mainport.bf2_in = 16'h41a0;
        mainport.valid_in = 1'b1;
        mainport.rdIn = 8'd12;
        mainport.sub = 1'b1;
        mainport.ready_out = 1'b1;
        @(negedge CLK);
        mainport.bf1_in = 16'h0;
        mainport.bf2_in = 16'h0;
        mainport.valid_in = 1'b0;
        mainport.rdIn = 8'd0;
        mainport.sub = 1'b0;
        mainport.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        casename = "sub, stall";
        mainport.valid_in = 1'b1;
        mainport.bf1_in = 16'h42c8;
        mainport.bf2_in = 16'h41a0;
        mainport.rdIn = 8'd28;
        mainport.ready_out = 1'b0;
        mainport.sub = 1'b1;
        @(negedge CLK);
        mainport.valid_in = 1'b0;
        mainport.bf1_in = 16'h0;
        mainport.bf2_in = 16'h0;
        mainport.rdIn = 8'd0;
        mainport.sub = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        mainport.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);

        casename = "slt, no stall";
        mainport.bf1_in = 16'h41a0;
        mainport.bf2_in = 16'h4120;
        mainport.valid_in = 1'b1;
        mainport.rdIn = 8'd12;
        mainport.slt = 1'b1;
        mainport.ready_out = 1'b1;
        @(negedge CLK);
        mainport.bf1_in = 16'h0;
        mainport.bf2_in = 16'h0;
        mainport.valid_in = 1'b0;
        mainport.rdIn = 8'd0;
        mainport.slt = 1'b0;
        mainport.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        casename = "slt, stall";
        mainport.valid_in = 1'b1;
        mainport.bf1_in = 16'h4120;
        mainport.bf2_in = 16'h41a0;
        mainport.rdIn = 8'd28;
        mainport.ready_out = 1'b0;
        mainport.slt = 1'b1;
        @(negedge CLK);
        mainport.valid_in = 1'b0;
        mainport.bf1_in = 16'h0;
        mainport.bf2_in = 16'h0;
        mainport.rdIn = 8'd0;
        mainport.slt = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        mainport.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);


        casename = "Mult, no stall";
        mainport.bf1_in = 16'h4b92;
        mainport.bf2_in = 16'hccec;
        mainport.valid_in = 1'b1;
        mainport.rdIn = 8'd12;
        mainport.mult = 1'b1;
        mainport.ready_out = 1'b1;
        @(negedge CLK);
        mainport.bf1_in = 16'h0;
        mainport.bf2_in = 16'h0;
        mainport.valid_in = 1'b0;
        mainport.rdIn = 8'd0;
        mainport.mult = 1'b0;
        mainport.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        casename = "Mult, stall";
        mainport.valid_in = 1'b1;
        mainport.bf1_in = 16'h4120;
        mainport.bf2_in = 16'h41a0;
        mainport.rdIn = 8'd28;
        mainport.ready_out = 1'b0;
        mainport.mult = 1'b1;
        @(negedge CLK);
        mainport.valid_in = 1'b0;
        mainport.bf1_in = 16'h0;
        mainport.bf2_in = 16'h0;
        mainport.rdIn = 8'd0;
        mainport.mult = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        mainport.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);

        $display("DONE");
        $finish;
    end


endmodule