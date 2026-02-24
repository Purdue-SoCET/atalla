// Vector Writeback Arbiter Module ============================================
// Author: Jaideep Dadi
// Email: djaideep@purdue.edu
// TODO 
// -  Scpad parameters used by vector_pkg is weird & doesn't compile, so did a temporary fix
//    Need to talk to vectorcore about these parameters
// - Do we need ready signals from every bank in veggie?
// - A code review with Rishi
// - Integration
// ============================================================================
`include "v_wb_arbiter_if.vh"
`include "vector_pkg.vh"

module v_wb_arbiter #(
    localparam INPUTS      = 9 //the number of input sources (reduction + LS + FU lanes (5) + GSAU): current priority
)(
    input logic CLK, nRST,
    v_wb_arbiter_if.v_wb_arbiter_if vif
); 
    import vector_pkg::*;

    logic [INPUTS-1:0] vectorOut_valid;
    vsel_t [INPUTS-1:0] vectorOut_destReg;
    vreg_t [INPUTS-1:0] vectorOut_result;

    assign vectorOut_valid = {
        vif.vector_if_vlsu_out.wb[0].valid,
        vif.vector_if_vlsu_out.wb[1].valid,
        vif.vector_if_gsau_out.wb_valid,
        vif.vector_if_lanes_out.result_collectors[0].wb_valid,
        vif.vector_if_lanes_out.result_collectors[1].wb_valid,
        vif.vector_if_lanes_out.result_collectors[2].wb_valid,
        vif.vector_if_lanes_out.result_collectors[3].wb_valid,
        vif.vector_if_lanes_out.result_collectors[4].wb_valid,
        vif.vector_if_reduction_out.wb_valid
        };
    
    assign vectorOut_destReg = {
        vif.vector_if_vlsu_out.wb[0].vdst,
        vif.vector_if_vlsu_out.wb[1].vdst,
        vif.vector_if_gsau_out.vd,
        vif.vector_if_lanes_out.result_collectors[0].vd_output,
        vif.vector_if_lanes_out.result_collectors[1].vd_output,
        vif.vector_if_lanes_out.result_collectors[2].vd_output,
        vif.vector_if_lanes_out.result_collectors[3].vd_output,
        vif.vector_if_lanes_out.result_collectors[4].vd_output,
        vif.vector_if_reduction_out.vd_output
        };

    assign vectorOut_result = {
        vif.vector_if_vlsu_out.wb[0].load_data,
        vif.vector_if_vlsu_out.wb[1].load_data,
        vif.vector_if_gsau_out.psum,    
        vif.vector_if_lanes_out.result_collectors[0].vector_output,
        vif.vector_if_lanes_out.result_collectors[1].vector_output,
        vif.vector_if_lanes_out.result_collectors[2].vector_output,
        vif.vector_if_lanes_out.result_collectors[3].vector_output,
        vif.vector_if_lanes_out.result_collectors[4].vector_output,
        vif.vector_if_reduction_out.vector_output
    };

/*
    typedef struct packed {
        logic [LANE_FU_COUNT-1:0] lanes_wb_ready;
        logic gsau_wb_ready;
        logic [NUM_SCPADS-1:0] vlsu_wb_ready;
        logic reduction_wb_ready;
    } vector_if_wb_ready_t;

    Bit 8 → lanes_wb_ready[4]
    Bit 7 → lanes_wb_ready[3]
    Bit 6 → lanes_wb_ready[2]
    Bit 5 → lanes_wb_ready[1]
    Bit 4 → lanes_wb_ready[0]
    Bit 3 → gsau_wb_ready
    Bit 2 → vlsu_wb_ready[1]
    Bit 1 → vlsu_wb_ready[0]
    Bit 0 → reduction_wb_ready
*/

    logic [3:0] banks; // valid for each port
    logic [1:0] bankSelected;
    logic [$clog2(INPUTS)-1:0] inputIndex; // For the for loop
    logic [$clog2(INPUTS)-1:0] FU_writing [3:0];

    always_comb begin
        vif.vector_if_wb_ready = '0;
        vif.veggie_in.WEN   = '0;
        vif.veggie_in.vd    = '0;
        vif.veggie_in.vdata = '0;

        if (!(vif.veggie_out.ready)) begin
            vif.vector_if_wb_ready = '0; // If Veggie is not ready, not ready goes to all FUs
        end else begin
            vif.vector_if_wb_ready = '1; // First, all writeback readys are 1.
            //clear bank when veggie ready to accept new data
            banks = '0;

            //WB0
            if (vif.vector_if_vlsu_out.wb[0].valid) begin
                bankSelected = vif.vector_if_vlsu_out.wb[0].vdst[7:6];
                if (!(banks[bankSelected])) begin
                    banks[bankSelected] = 1'b1; // Mark bank as used
                    vif.veggie_in.vd[bankSelected]   = vif.vector_if_vlsu_out.wb[0].vdst;
                    vif.veggie_in.vdata[bankSelected] = vif.vector_if_vlsu_out.wb[0].load_data;
                    vif.veggie_in.WEN[bankSelected] = 1;
                end else begin
                    vif.vector_if_wb_ready.vlsu_wb_ready[0] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                end
            end

            //WB1
            if (vif.vector_if_vlsu_out.wb[1].valid) begin
                bankSelected = vif.vector_if_vlsu_out.wb[1].vdst[7:6];
                if (!(banks[bankSelected])) begin
                    banks[bankSelected] = 1'b1; // Mark bank as used
                    vif.veggie_in.vd[bankSelected]   = vif.vector_if_vlsu_out.wb[1].vdst;
                    vif.veggie_in.vdata[bankSelected] = vif.vector_if_vlsu_out.wb[1].load_data;
                    vif.veggie_in.WEN[bankSelected] = 1;
                end else begin
                    vif.vector_if_wb_ready.vlsu_wb_ready[1] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                end
            end

            //GSAU
            if (vif.vector_if_gsau_out.wb_valid) begin
                bankSelected = vif.vector_if_gsau_out.vd[7:6];
                if (!(banks[bankSelected])) begin
                    banks[bankSelected] = 1'b1; // Mark bank as used
                    vif.veggie_in.vd[bankSelected]   = vif.vector_if_gsau_out.vd;
                    vif.veggie_in.vdata[bankSelected] = vif.vector_if_gsau_out.psum;
                    vif.veggie_in.WEN[bankSelected] = 1;
                end else begin
                    vif.vector_if_wb_ready.gsau_wb_ready = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                end
            end

            //Reduction Unit
            if (vif.vector_if_reduction_out.wb_valid) begin
                bankSelected = vif.vector_if_reduction_out.vd_output[7:6];
                if (!(banks[bankSelected])) begin
                    banks[bankSelected] = 1'b1; // Mark bank as used
                    vif.veggie_in.vd[bankSelected]   = vif.vector_if_reduction_out.vd_output;
                    vif.veggie_in.vdata[bankSelected] = vif.vector_if_reduction_out.vector_output;
                    vif.veggie_in.WEN[bankSelected] = 1;
                end else begin
                    vif.vector_if_wb_ready.reduction_wb_ready = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                end
            end
            if (vif.vector_if_lanes_out.result_collectors[0].wb_valid) begin
                bankSelected = vif.vector_if_lanes_out.result_collectors[0].vd_output[7:6];
                if (!(banks[bankSelected])) begin
                    banks[bankSelected] = 1'b1; // Mark bank as used
                    vif.veggie_in.vd[bankSelected]   = vif.vector_if_lanes_out.result_collectors[0].vd_output;
                    vif.veggie_in.vdata[bankSelected] = vif.vector_if_lanes_out.result_collectors[0].vector_output;
                    vif.veggie_in.WEN[bankSelected] = 1;
                end else begin
                    vif.vector_if_wb_ready.lanes_wb_ready[0] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                end
            end
            if (vif.vector_if_lanes_out.result_collectors[1].wb_valid) begin
                bankSelected = vif.vector_if_lanes_out.result_collectors[1].vd_output[7:6];
                if (!(banks[bankSelected])) begin
                    banks[bankSelected] = 1'b1; // Mark bank as used
                    vif.veggie_in.vd[bankSelected]   = vif.vector_if_lanes_out.result_collectors[1].vd_output;
                    vif.veggie_in.vdata[bankSelected] = vif.vector_if_lanes_out.result_collectors[1].vector_output;
                    vif.veggie_in.WEN[bankSelected] = 1;
                end else begin
                    vif.vector_if_wb_ready.lanes_wb_ready[1] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                end
            end
            if (vif.vector_if_lanes_out.result_collectors[2].wb_valid) begin
                bankSelected = vif.vector_if_lanes_out.result_collectors[2].vd_output[7:6];
                if (!(banks[bankSelected])) begin
                    banks[bankSelected] = 1'b1; // Mark bank as used
                    vif.veggie_in.vd[bankSelected]   = vif.vector_if_lanes_out.result_collectors[2].vd_output;
                    vif.veggie_in.vdata[bankSelected] = vif.vector_if_lanes_out.result_collectors[2].vector_output;
                    vif.veggie_in.WEN[bankSelected] = 1;
                end else begin
                    vif.vector_if_wb_ready.lanes_wb_ready[2] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                end
            end
            if (vif.vector_if_lanes_out.result_collectors[3].wb_valid) begin
                bankSelected = vif.vector_if_lanes_out.result_collectors[3].vd_output[7:6];
                if (!(banks[bankSelected])) begin
                    banks[bankSelected] = 1'b1; // Mark bank as used
                    vif.veggie_in.vd[bankSelected]   = vif.vector_if_lanes_out.result_collectors[3].vd_output;
                    vif.veggie_in.vdata[bankSelected] = vif.vector_if_lanes_out.result_collectors[3].vector_output;
                    vif.veggie_in.WEN[bankSelected] = 1;
                end else begin
                    vif.vector_if_wb_ready.lanes_wb_ready[3] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                end
            end
            if (vif.vector_if_lanes_out.result_collectors[4].wb_valid) begin
                bankSelected = vif.vector_if_lanes_out.result_collectors[4].vd_output[7:6];
                if (!(banks[bankSelected])) begin
                    banks[bankSelected] = 1'b1; // Mark bank as used
                    vif.veggie_in.vd[bankSelected]   = vif.vector_if_lanes_out.result_collectors[4].vd_output;
                    vif.veggie_in.vdata[bankSelected] = vif.vector_if_lanes_out.result_collectors[4].vector_output;
                    vif.veggie_in.WEN[bankSelected] = 1;
                end else begin
                    vif.vector_if_wb_ready.lanes_wb_ready[4] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
                end
            end
        end
    end
endmodule