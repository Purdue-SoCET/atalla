`timescale 1ps/1ps

import axi_bus_pkg::*;
module axi_read_router_tb;
    import axi_bus_pkg::*;

    parameter PERIOD = 10;

    logic CLK=0, nRST;
    always #(PERIOD/2) CLK++;

    axi_bus_if rif ();

`ifndef MAPPED
    axi_read_router DUT (CLK, nRST, rif);
`else
    axi_read_router DUT (
        .CLK (CLK),
        .nRST (nRST),
        .\rif\.r_sp0_o_ready (rif.r_sp0_o_ready),
        .\rif\.r_sp1_o_ready (rif.r_sp1_o_ready),
        .\rif\.r_i_o_ready (rif.r_i_o_ready),
        .\rif\.r_d_o_ready (rif.r_d_o_ready),
        // From Controller
        .\rif\.r_valid (rif.r_valid),
        .\rif\.r_i (rif.r_i),
        // To Master
        .\rif\.r_sp0_o (rif.r_sp0_o),
        .\rif\.r_sp1_o (rif.r_sp1_o),
        .\rif\.r_i_o (rif.r_i_o),
        .\rif\.r_d_o (rif.r_d_o),
        .\rif\.r_sp0_o_valid (rif.r_sp0_o_valid),
        .\rif\.r_sp1_o_valid (rif.r_sp1_o_valid),
        .\rif\.r_i_o_valid (rif.r_i_o_valid),
        .\rif\.r_d_o_valid (rif.r_d_o_valid),
        // To Controller
        .\rif\.r_ready (rif.r_ready)
    );
`endif

    task reset;
        nRST = 0;
        repeat (3) @(negedge CLK);
        nRST = 1;
        repeat (3) @(negedge CLK);
    endtask

    initial begin
        reset;
        $finish;
    end



endmodule