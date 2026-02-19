`timescale 1ns / 10ps
`include "sMult_if.sv"

module mult_wrapper_tb;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;
    string casename;

    sMult_if mainport ();

    mult_wrapper DUT (.clk(CLK), .nRST(nRST), .portmap(mainport));


    initial begin
        casename = "rst";
        mainport.input1 = 32'b0;
        mainport.input2 = 32'b0;
        mainport.sMult = 1'b0;
        mainport.rdIn = 8'b0;
        mainport.valid_in = 1'b0;
        mainport.ready_out = 1'b1;
        nRST = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);

        nRST = 1'b1;

        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        casename = "mult";
        mainport.input1 = 32'd125;
        mainport.input2 = 32'd7;
        mainport.sMult = 1'b1;
        mainport.rdIn = 8'd94;
        mainport.valid_in = 1'b1;
        mainport.ready_out = 1'b1;
        @(negedge CLK);
        mainport.input1 = 32'b0;
        mainport.input2 = 32'b0;
        mainport.sMult = 1'b0;
        mainport.rdIn = 8'b0;
        mainport.valid_in = 1'b0;
        mainport.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        casename = "mult, stall";
        mainport.input1 = 32'd125;
        mainport.input2 = 32'hFFFFFFF9;
        mainport.sMult = 1'b1;
        mainport.rdIn = 8'd94;
        mainport.valid_in = 1'b1;
        mainport.ready_out = 1'b0;
        @(negedge CLK);
        mainport.input1 = 32'b0;
        mainport.input2 = 32'b0;
        mainport.sMult = 1'b0;
        mainport.rdIn = 8'b0;
        mainport.valid_in = 1'b0;
        mainport.ready_out = 1'b0;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);
        mainport.ready_out = 1'b1;
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(negedge CLK);

        $display("DONE");
        $finish;
    end


endmodule