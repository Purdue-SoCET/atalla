`timescale 1ns/1ps

`include "vector_pkg.vh"
`include "vector_if.vh"
`include "gsau_control_unit_if.vh"

module vector_top_tb;
    `include "scpad_params.svh"
    import vector_pkg::*;
    import scpad_pkg::*;

    logic CLK;
    logic nRST;

    localparam int CLK_PERIOD      = 10;

    initial begin
        CLK = 1'b0;
        forever #(CLK_PERIOD/2) CLK = ~CLK;
    end

    //instanciation
    vector_if vif();
    gsau_control_unit_if gsauif();
    scpad_if sif(CLK, nRST);

    vector_datapath dut (
        .CLK (CLK),
        .nRST(nRST),
        .vif (vif),
        .sif(sif),
        .gsauif(gsauif)
    );

    initial begin
        #10;
        $display("Running TB");
        #10;
        $finish();
    end

endmodule