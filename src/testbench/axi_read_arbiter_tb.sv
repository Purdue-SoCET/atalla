`timescale 1ps/1ps

module axi_read_arbiter_tb ();

    localparam CLK_PERIOD = 10ns;

    logic clk, nrst;
    logic ready, sp0_req, sp1_req, d_req, i_req;
    logic [2:0] grant_sel;

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

    initial begin
        nrst = 1;
        reset_dut();
        ready = 0;
        sp0_req = 0;
        sp1_req = 0;
        d_req = 0;
        i_req = 0;
        #(CLK_PERIOD);
        ready = 1;
        sp0_req = 1;
        #(CLK_PERIOD);
        #(CLK_PERIOD);
        ready = 0;
        #(CLK_PERIOD);
        #(CLK_PERIOD);
        sp0_req = 0;
        #(CLK_PERIOD);
        #(CLK_PERIOD);
        #(CLK_PERIOD);
        #(CLK_PERIOD);
        $finish;
    end
endmodule