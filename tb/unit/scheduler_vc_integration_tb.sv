`timescale 1ns / 10ps
`include "atalla_isa_types.vh"
`include "scheduler_core_if.vh"
`include "vector_pkg.vh"
`include "vector_if.vh"
`include "gsau_control_unit_if.vh"

module scheduler_vc_integration_tb;
    `include "scpad_params.svh"
    import vector_pkg::*;
    import scpad_pkg::*;
    // import inst_parser_dpi_pkg::*;
    import atalla_isa_pkg::*;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;
    string casename;

    // -----------------------------------------------------------------------
    // Interfaces
    // -----------------------------------------------------------------------
    vector_if vif();
    gsau_control_unit_if gsauif();
    scpad_if sif(CLK, nRST);
    scheduler_core_if scif();
    

    // Vector Core
    vector_datapath dut (
        .CLK    (CLK),
        .nRST   (nRST),
        .vif    (vif),
        .sif    (sif),
        .gsauif (gsauif)
    );

    // Scratchpad RTL
    scratchpad sp_inst (
        .sif(sif)
    );

    // Systolic Array RTL
    sysarr_MEISSA_top sa_inst (
        .clk    (CLK),
        .nRST   (nRST),
        .gsau_if(gsauif)
    );

    
    

    initial begin


        $finish;
    end


endmodule