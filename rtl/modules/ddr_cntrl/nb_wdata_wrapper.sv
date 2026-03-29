`timescale 1ns/1ps
`include "ddr_controller_if.sv"

module nb_wdata_queue_wrapper (
    input logic CLK, nRST,
    ddr_controller_if.wdata_wrapper wdw,
    ddr_controller_if.wdata_queue wdq
);


    `include "dram_pkg.svh"
    import dram_pkg::*;

    logic [$clog2(ID_NUM)-1:0] selected_queue; //for outputting data to dram. Backend arbiter should be in charge of making sure that no two output bursts intefere. 
    logic [$clog2(ID_NUM)-1:0] pri; //priority storing for bresp channel arbitration.

    assign wdw.wrap_ready = wdq.wready[wdq.wdq_slot.wid];
    assign wdw.wrap_bwvalid = wdq.bwvalid[wdw.wrap_bw_arb];
    assign wdw.wrap_bwresp = wdq.bwresp[wdw.wrap_bw_arb];
    assign wdw.wrap_bwid = wdq.bwid[wdw.wrap_arb];
    assign wdw.wrap_ddr_wdata_data = wdq.ddr_wdata_data[selected_queue];
    assign wdw.wrap_ddr_wdata_en = wdq.ddr_wdata_en[selected_queue];
    assign wdw.wrap_ddr_wdata_mask = wdq.ddr_wdata_mask[selected_queue];
    assign wdw.wrap_ddr_we = wdq.ddr_we[selected_queue]; 
    
    assign wdq.wrap_bw_arb = wdw.wrap_ready;
    
    genvar i;
    generate 
        for (i = 0; i < ID_NUM; i++) begin
            // Generating wdata_queues. 
            nb_wdata_queue #(.Q_ID(i)) WDATA_QUEUE_GEN ( 
                CLK, nRST, wdq
            );

        end

    endgenerate

    logic [$clog2(ID_NUM)-1:0] j;
    always_comb  begin : PRIORITY_COMB
        for(j = 0; j < ID_NUM; j++) begin
            if(wdq.bwvalid[pri + j]) begin
                wdw.wrap_bw_arb = pri + j; 
                break;
            end else begin
                wdw.wrap_bw_arb = pri; 
            end
        end 
    end

    always_ff @(posedge CLK, negedge nRST) begin : PRIORITY
        if(!nRST)
            pri <= 'b0;
        else if (wdq.bwready && wdw.wrap_bwvalid)
            pri <= pri + 'b1;
    end

    always_ff @(posedge CLK, negedge nRST) begin : SELECTED_BURST_QUEUE

        if(!nRST) 
            selected_queue <= 'b0;
        else if(wdq.be_write)
            selected_queue <= wdq.be_wid;

    end

endmodule //67 Lines yay!!