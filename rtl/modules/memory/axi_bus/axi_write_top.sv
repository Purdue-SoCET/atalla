/*  Aryan Kadakia - kadakia0@purdue.edu */
`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

module axi_write_top(
    input logic CLK,
    input logic nRST,
    axi_bus_if.write_path wr_path_if
);

    // SCRATCHPAD0 (SP0) WRITE MANAGER
    axi_write_manager #(
            .MASTER_ID(SP0)
        ) SP0_wrmgr ( 
            .CLK(CLK),
            .nRST(nRST)
    );

    // SCRATCHPAD1 (SP1) WRITE MANAGER

    // DCACHE WRITE MANAGER




endmodule