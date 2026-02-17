`ifndef VLSU_IF_VH
`define VLSU_IF_VH

interface vlsu_if (input logic clk, input logic n_rst);
    `include "scpad_params.svh"

    import scpad_pkg::*;
    import vector_pkg::*;

    

    // ------------------------------------------------------------------
    // Wires (arrayed per scratchpad)
    // ------------------------------------------------------------------
    vlsu_sched_req_t  sched_req  [NUM_SCPADS];
    vlsu_sched_res_t  sched_res  [NUM_SCPADS];
    vlsu_vrf_store_t  vrf_store  [NUM_SCPADS];
    vlsu_wb_t         wb_out     [NUM_SCPADS];
    logic             wb_ready   [NUM_SCPADS];
    vlsu_status_t     status     [NUM_SCPADS];

    // ------------------------------------------------------------------
    // Modports
    // ------------------------------------------------------------------

    // Used by the VLSU module
    modport vlsu (
        input  clk, n_rst,
        input  sched_req,
        output sched_res,
        input  vrf_store,
        output wb_out,
        input  wb_ready,
        output status
    );

    // Used by the scheduler to drive requests / read status
    modport vlsu_sched (
        output sched_req,
        input  sched_res,
        input  status
    );

    // Used by the writeback arbiter
    modport vlsu_wb (
        input  wb_out,
        output wb_ready
    );

    // Used by the testbench (full access)
    modport vlsu_tb (
        input  clk,
        output sched_req,
        input  sched_res,
        output vrf_store,
        input  wb_out,
        output wb_ready,
        input  status
    );

endinterface

`endif