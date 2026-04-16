// ============================================================================
// vector_core_L3_tb.sv
// L3 Integration Testbench 
//
//   Scheduler  → REAL RTL
//   Veggie     → REAL RTL
//   Sysarr     → REAL RTL (sysarr_MEISSA_top)
//   Scratchpad → REAL RTL (scratchpad)
//
// DUT: scheduler + vector_datapath + scratchpad + systolic_array
// Owner: Navya Datla
// ============================================================================

/*
L3 TB:
*/

`timescale 1ns/1ps

`include "vector_pkg.vh"
`include "vector_if.vh"
`include "gsau_control_unit_if.vh"
`include "scheduler_core_if.vh"
`include "atalla_isa_types.vh"

module vector_core_L3_tb;
    `include "scpad_params.svh"
    import atalla_isa_pkg::*;
    import vector_pkg::*;
    import scpad_pkg::*;
    import inst_parser_dpi_pkg::*;
    string casename;

    // -----------------------------------------------------------------------
    // Parameters
    // -----------------------------------------------------------------------
    parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-vector/add_vv";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/load-store/store_load_l2";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/gemmm/gemm_vv";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/load-store/store_load_l2";

    // bp test for sys array works, there is a timeout from scheduler stalls and the NO OPs dont go thru so my cond in the all_issued doesnt work,
    // my termination cond didnt trigger causing the timeout, sys array works properly, need to fix the tb condition, but backpressure is now done for both spad and sys array
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/gemmm/gemm_bp_test";
    // make drain 500 for sysarray bp test, 300 for gemm, 150 for reg.
    parameter int    DRAIN_CYCLES = 500;
    parameter int    TIMEOUT      = 10000;

    // -----------------------------------------------------------------------
    // Clock / Reset
    // -----------------------------------------------------------------------
    logic CLK;
    logic nRST;
    localparam int CLK_PERIOD = 10;

    initial begin
        CLK = 1'b0;
        forever #(CLK_PERIOD/2) CLK = ~CLK;
    end

    // -----------------------------------------------------------------------
    // Interfaces
    // -----------------------------------------------------------------------
    instruction_packet_t imemload; 
    logic ihit;
    scheduler_core_if scif ();
    vector_if vif();
    gsau_control_unit_if gsauif();
    scpad_if sif(CLK, nRST);

    // -----------------------------------------------------------------------
    scheduler_core sched_core (.CLK(CLK), .nRST(nRST), .scif(scif), .imemload(imemload), .ihit(ihit));

    // -----------------------------------------------------------------------
    // DUT: Vector Datapath
    // -----------------------------------------------------------------------
    vector_datapath vec_datapath (
        .CLK    (CLK),
        .nRST   (nRST),
        .vif    (vif),
        .sif    (sif),
        .gsauif (gsauif)
    );

    // -----------------------------------------------------------------------
    // L2: Real Scratchpad RTL
    // -----------------------------------------------------------------------
    scratchpad sp_inst (
        .sif(sif)
    );

    // -----------------------------------------------------------------------
    // L2: Real Systolic Array RTL
    // -----------------------------------------------------------------------
    sysarr_MEISSA_top sa_inst (
        .clk    (CLK),
        .nRST   (nRST),
        .gsau_if(gsauif)
    );

    perf_monitor monitor (
        .CLK(CLK),
        .nRST(nRST),
        .sif(sif),
        .gsauif(gsauif),
        .vif(vif)
    );

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
        ihit           = 0;
        imemload          = '0;
        scif.vector_wb_in   = '0;
        scif.SDMA_scalar_rs1s = '0;
        scif.SDMA_scalar_WEN  = '0;
        @(negedge CLK);
        nRST = 1;
        @(negedge CLK);
    endtask

    // -----------------------------------------------------------------------
    // DRAM Tie-off (controllable for backpressure testing)
    // -----------------------------------------------------------------------
    logic dram_stall_inject [NUM_SCPADS];
    initial begin
        for (int i = 0; i < NUM_SCPADS; i++) dram_stall_inject[i] = 1'b0;
    end

    genvar dram_i;
    generate
        for (dram_i = 0; dram_i < NUM_SCPADS; dram_i++) begin : dram_tieoff
            assign sif.dram_be_stall[dram_i] = dram_stall_inject[dram_i];
            assign sif.dram_be_res[dram_i]   = '0;
        end
    endgenerate

    // -----------------------------------------------------------------------
    // Main
    // -----------------------------------------------------------------------

    initial begin
        $display("============================================================");
        $display(" Vector Core L3 Integration Testbench (DPI-C + Real RTL)");
        $display("============================================================");

        casename = "rst";

        reset();

        @(posedge CLK);
        @(posedge CLK);

        //lui imm=7f will put 3f80 (1) in reg
        @(negedge CLK);
        ihit = 1'b1;
        imemload.inst0 = 40'h3F80B0;  // LUI, rd=1, imm=0x7f (3f80 in bf16)
        imemload.inst1 = 40'h2f; //NOP
        imemload.inst2 = 40'h2f; //NOP
        imemload.inst3 = 40'h2f; //NOP
        @(negedge CLK);
        ihit = 1'b0;

        // @(negedge CLK); // 16'b1 is way too small for bf16 shit
        // ihit = 1'b1;
        // imemload.inst0 = 40'h0000800096;  // ADD_I {'opcode': 0b0010110, 'rs1': 0, 'rd': 1, 'imm12': 1}
        // imemload.inst1 = 40'h2f; //NOP
        // imemload.inst2 = 40'h2f; //NOP
        // imemload.inst3 = 40'h2f; //NOP
        // @(negedge CLK);
        // ihit = 1'b0;


        repeat(6) @(negedge CLK);   

        @(negedge CLK);
        ihit = 1'b1;
        imemload.inst0 = 40'h00008000CB;  // ADD_VS (vms = 0 (all 1's), vd=1, vs1=0, rs1=1)
        imemload.inst1 = 40'h2f; //NOP
        imemload.inst2 = 40'h2f; //NOP
        imemload.inst3 = 40'h2f; //NOP
        @(negedge CLK);
        ihit = 1'b0;

        repeat(15) @(negedge CLK);   






        

        $finish;
    end



endmodule
