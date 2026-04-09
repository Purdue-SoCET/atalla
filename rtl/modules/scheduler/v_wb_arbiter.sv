// Vector Writeback Arbiter Module ============================================
// Author: Jaideep Dadi
// Email: djaideep@purdue.edu
// TODO 
// - We have only 3 Functional units, not five. So now I have to remove 2 functional units (lane outs)
// - Add mask related stuff.
//      - I can take lane outs sure, but which functional unit does it come out of? Is it FU0, 1 2...? Reduction?
//      - Where is meggie stuff?
// - Add two more vector inputs from the load/store units
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

    logic [3:0] banks; // valid for each port
    logic [1:0] bankSelected;

    always_comb begin
	//vif.vector_wb_out.vector_if_wb_ready = '0;
	vif.vector_wb_out.WEN   = '0;
	vif.vector_wb_out.vd    = '0;
	vif.vector_wb_out.vdata = '0;

    vif.vector_wb_out.vd_mask = '0;
    vif.vector_wb_out.vdata_mask = '0;
    vif.vector_wb_out.WEN_mask = '0;

	vif.vector_wb_out.vector_if_wb_ready = '1; // First, all writeback readys are 1.
    //clear bank when veggie ready to accept new data
    banks = '0;

    //Mask stuff: let's test it
    if (vif.vector_wb_in.mvvOrMvs) begin
        vif.vector_wb_out.vd_mask = vif.vector_wb_in.vector_if_lanes_out.result_collectors[0].vd_output;
        vif.vector_wb_out.WEN_mask = 1;

        foreach (vif.vector_wb_in.vector_if_lanes_out.result_collectors[0][i]) begin
            vif.vector_wb_out.vdata_mask[i] = vif.vector_wb_in.vector_if_lanes_out.result_collectors[0][i][0];
        end
    end

    //WB0
    if (vif.vector_wb_in.vector_if_vlsu_out.wb[0].valid) begin
        bankSelected = vif.vector_wb_in.vector_if_vlsu_out.wb[0].vdst[7:6];
        if (!(banks[bankSelected])) begin
            banks[bankSelected] = 1'b1; // Mark bank as used
            vif.vector_wb_out.vd[bankSelected]   = vif.vector_wb_in.vector_if_vlsu_out.wb[0].vdst;
            vif.vector_wb_out.vdata[bankSelected] = vif.vector_wb_in.vector_if_vlsu_out.wb[0].load_data;
            vif.vector_wb_out.WEN[bankSelected] = 1;
        end else begin
            vif.vector_wb_out.vector_if_wb_ready.vlsu_wb_ready[0] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
        end
    end

    //WB1
    if (vif.vector_wb_in.vector_if_vlsu_out.wb[1].valid) begin
        bankSelected = vif.vector_wb_in.vector_if_vlsu_out.wb[1].vdst[7:6];
        if (!(banks[bankSelected])) begin
            banks[bankSelected] = 1'b1; // Mark bank as used
            vif.vector_wb_out.vd[bankSelected]   = vif.vector_wb_in.vector_if_vlsu_out.wb[1].vdst;
            vif.vector_wb_out.vdata[bankSelected] = vif.vector_wb_in.vector_if_vlsu_out.wb[1].load_data;
            vif.vector_wb_out.WEN[bankSelected] = 1;
        end else begin
            vif.vector_wb_out.vector_if_wb_ready.vlsu_wb_ready[1] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
        end
    end

    //GSAU
    if (vif.vector_wb_in.vector_if_gsau_out.wb_valid) begin
        bankSelected = vif.vector_wb_in.vector_if_gsau_out.vd[7:6];
        if (!(banks[bankSelected])) begin
            banks[bankSelected] = 1'b1; // Mark bank as used
            vif.vector_wb_out.vd[bankSelected]   = vif.vector_wb_in.vector_if_gsau_out.vd;
            vif.vector_wb_out.vdata[bankSelected] = vif.vector_wb_in.vector_if_gsau_out.psum;
            vif.vector_wb_out.WEN[bankSelected] = 1;
        end else begin
            vif.vector_wb_out.vector_if_wb_ready.gsau_wb_ready = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
        end
    end

    //Reduction Unit
    if (vif.vector_wb_in.vector_if_reduction_out.wb_valid) begin
        bankSelected = vif.vector_wb_in.vector_if_reduction_out.vd_output[7:6];
        if (!(banks[bankSelected])) begin
            banks[bankSelected] = 1'b1; // Mark bank as used
            vif.vector_wb_out.vd[bankSelected]   = vif.vector_wb_in.vector_if_reduction_out.vd_output;
            vif.vector_wb_out.vdata[bankSelected] = vif.vector_wb_in.vector_if_reduction_out.vector_output;
            vif.vector_wb_out.WEN[bankSelected] = 1;
        end else begin
            vif.vector_wb_out.vector_if_wb_ready.reduction_wb_ready = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
        end
    end
    if (vif.vector_wb_in.vector_if_lanes_out.result_collectors[0].wb_valid) begin
        bankSelected = vif.vector_wb_in.vector_if_lanes_out.result_collectors[0].vd_output[7:6];
        if (!(banks[bankSelected])) begin
            banks[bankSelected] = 1'b1; // Mark bank as used
            vif.vector_wb_out.vd[bankSelected]   = vif.vector_wb_in.vector_if_lanes_out.result_collectors[0].vd_output;
            vif.vector_wb_out.vdata[bankSelected] = vif.vector_wb_in.vector_if_lanes_out.result_collectors[0].vector_output;
            vif.vector_wb_out.WEN[bankSelected] = 1;
        end else begin
            vif.vector_wb_out.vector_if_wb_ready.lanes_wb_ready[0] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
        end
    end
    if (vif.vector_wb_in.vector_if_lanes_out.result_collectors[1].wb_valid) begin
        bankSelected = vif.vector_wb_in.vector_if_lanes_out.result_collectors[1].vd_output[7:6];
        if (!(banks[bankSelected])) begin
            banks[bankSelected] = 1'b1; // Mark bank as used
            vif.vector_wb_out.vd[bankSelected]   = vif.vector_wb_in.vector_if_lanes_out.result_collectors[1].vd_output;
            vif.vector_wb_out.vdata[bankSelected] = vif.vector_wb_in.vector_if_lanes_out.result_collectors[1].vector_output;
            vif.vector_wb_out.WEN[bankSelected] = 1;
        end else begin
            vif.vector_wb_out.vector_if_wb_ready.lanes_wb_ready[1] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
        end
    end
    if (vif.vector_wb_in.vector_if_lanes_out.result_collectors[2].wb_valid) begin
        bankSelected = vif.vector_wb_in.vector_if_lanes_out.result_collectors[2].vd_output[7:6];
        if (!(banks[bankSelected])) begin
            banks[bankSelected] = 1'b1; // Mark bank as used
            vif.vector_wb_out.vd[bankSelected]   = vif.vector_wb_in.vector_if_lanes_out.result_collectors[2].vd_output;
            vif.vector_wb_out.vdata[bankSelected] = vif.vector_wb_in.vector_if_lanes_out.result_collectors[2].vector_output;
            vif.vector_wb_out.WEN[bankSelected] = 1;
        end else begin
            vif.vector_wb_out.vector_if_wb_ready.lanes_wb_ready[2] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
        end
    end
    if (vif.vector_wb_in.vector_if_lanes_out.result_collectors[3].wb_valid) begin
        bankSelected = vif.vector_wb_in.vector_if_lanes_out.result_collectors[3].vd_output[7:6];
        if (!(banks[bankSelected])) begin
            banks[bankSelected] = 1'b1; // Mark bank as used
            vif.vector_wb_out.vd[bankSelected]   = vif.vector_wb_in.vector_if_lanes_out.result_collectors[3].vd_output;
            vif.vector_wb_out.vdata[bankSelected] = vif.vector_wb_in.vector_if_lanes_out.result_collectors[3].vector_output;
            vif.vector_wb_out.WEN[bankSelected] = 1;
        end else begin
            vif.vector_wb_out.vector_if_wb_ready.lanes_wb_ready[3] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
        end
    end
    if (vif.vector_wb_in.vector_if_lanes_out.result_collectors[4].wb_valid) begin
        bankSelected = vif.vector_wb_in.vector_if_lanes_out.result_collectors[4].vd_output[7:6];
        if (!(banks[bankSelected])) begin
            banks[bankSelected] = 1'b1; // Mark bank as used
            vif.vector_wb_out.vd[bankSelected]   = vif.vector_wb_in.vector_if_lanes_out.result_collectors[4].vd_output;
            vif.vector_wb_out.vdata[bankSelected] = vif.vector_wb_in.vector_if_lanes_out.result_collectors[4].vector_output;
            vif.vector_wb_out.WEN[bankSelected] = 1;
        end else begin
            vif.vector_wb_out.vector_if_wb_ready.lanes_wb_ready[4] = 0; // Bank conflict with higher-priority port, stall this request. Indicate which input is causing the stall
        end
    end
    end
endmodule
