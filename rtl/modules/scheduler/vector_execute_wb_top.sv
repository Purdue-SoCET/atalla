`include "vector_if.vh"
`include "scpad_if.sv"
`include "gsau_control_unit_if.vh"
`include "vector_pkg.vh"
`include "v_wb_arbiter_if.vh"

module vector_execute_wb_top (
    input logic CLK,
    input logic nRST,
    vector_if    vif,
    scpad_if.vec_frontend  sif,
    gsau_control_unit_if.gsau gsauif
);

    import vector_pkg::*;
    //====================================================
    // Interface instances
    //====================================================
    v_wb_arbiter_if v_wb_arbiter();      // writeback arbiter interface

    vector_datapath u_vector_datapath (
        .CLK  (CLK),
        .nRST (nRST),
        .vif  (vif),
	.sif  (sif),
	.gsauif(gsauif)
    );


    //====================================================
    // Execution → Writeback connections
    //====================================================

    always_comb begin

        // lanes
        v_wb_arbiter.vector_wb_in.vector_if_lanes_out =
            vif.lanes_out;

        // reduction
        v_wb_arbiter.vector_wb_in.vector_if_reduction_out =
            vif.lanes_out.reduction;

        // vlsu
        v_wb_arbiter.vector_wb_in.vector_if_vlsu_out =
            vif.vlsu_out;

        // gsau
        v_wb_arbiter.vector_wb_in.vector_if_gsau_out =
            vif.gsau_out;

    end


    //====================================================
    // Writeback Arbiter
    //====================================================

    v_wb_arbiter u_v_wb_arbiter (
        .CLK (CLK),
        .nRST(nRST),
        .vif (v_wb_arbiter)
    );


    //====================================================
    // Writeback → Execution ready signals
    //====================================================

    always_comb begin
        vif.wb_ready_signals =
            v_wb_arbiter.vector_wb_out.vector_if_wb_ready;
    end


endmodule
