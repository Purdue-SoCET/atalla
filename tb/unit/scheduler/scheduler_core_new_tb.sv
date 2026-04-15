`timescale 1ns / 10ps
`include "atalla_isa_types.vh"
`include "vector_pkg.vh"
`include "vector_if.vh"
`include "scheduler_core_if.vh"
`include "scheduler_pkg.sv"
`include "scpad_if.sv"

module scheduler_core_new_tb;
    import atalla_isa_pkg::*;
    import vector_pkg::*;
    import scheduler_pkg::*;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;
    string casename;

    scheduler_core_if scif ();
    vector_if vif();
    gsau_control_unit_if gsauif();
    scpad_if sif(CLK, nRST);

    scheduler_core DUT (.CLK(CLK), .nRST(nRST), .scif(scif));
    vector_datapath vec (
        .CLK    (CLK),
        .nRST   (nRST),
        .vif    (vif),
        .sif    (sif),
        .gsauif (gsauif)
    );

    // scratchpad sp_inst (
    //     .sif(sif)
    // );

    // sysarr_MEISSA_top sa_inst (
    //     .clk    (CLK),
    //     .nRST   (nRST),
    //     .gsau_if(gsauif)
    // );

    assign vif.lanes_in = scif.lanes_in;
    // assign vif.vlsu_in = scif.vlsu_in;
    // assign vif.gsau_in = scif.gsau_in;
    assign vif.wb_ready_signals = scif.vector_if_wb_ready;

    assign scif.vector_wb_in.vector_if_lanes_out = vif.lanes_out;

    task reset;
        nRST = 0;
        // Drive all inputs to safe defaults
        scif.data_load      = '0;
        scif.hit            = 0;
        scif.block_status   = 0;
        scif.ihit           = 0;
        scif.iload          = '0;
        scif.vector_wb_in   = '0;
        scif.SDMA_scalar_rs1s = '0;
        scif.SDMA_scalar_WEN  = '0;
        @(negedge CLK);
        nRST = 1;
        @(negedge CLK);
    endtask

    initial begin
        casename = "rst";

        reset();

        @(posedge CLK);
        @(posedge CLK);

        @(negedge CLK);
        scif.ihit = 1'b1;
        scif.iload.inst0 = 40'h0000800096;  // ADD_I {'opcode': 0b0010110, 'rs1': 0, 'rd': 1, 'imm12': 1}
        scif.iload.inst1 = 40'h2f; //NOP
        scif.iload.inst2 = 40'h2f; //NOP
        scif.iload.inst3 = 40'h2f; //NOP
        @(negedge CLK);
        scif.ihit = 1'b0;


        repeat(6) @(negedge CLK);   

        @(negedge CLK);
        scif.ihit = 1'b1;
        scif.iload.inst0 = 40'h00008000CB;  // ADD_VS (vms = 0 (all 1's), vd=1, vs1=0, rs1=1)
        scif.iload.inst1 = 40'h2f; //NOP
        scif.iload.inst2 = 40'h2f; //NOP
        scif.iload.inst3 = 40'h2f; //NOP
        @(negedge CLK);
        scif.ihit = 1'b0;

        repeat(15) @(negedge CLK);   






        

        $finish;
    end


endmodule