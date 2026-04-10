`include "dram_pkg.svh"
`include "ddr_controller_if.sv"

module nb_wdata_queue_wrapper (
    input logic CLK, nRST,
    ddr_controller_if.wdata_wrapper wdw
);

      

    import dram_pkg::*;

    logic [ID_NUM-1:0] wready; 
    logic [ID_NUM-1:0] bwvalid;
    logic [ID_NUM-1:0][1:0] bwresp;
    logic [ID_NUM-1:0][$clog2(ID_NUM)-1:0] bwid;
    logic [ID_NUM-1:0][63:0] ddr_wdata_data;
    logic [ID_NUM-1:0] ddr_wdata_en;
    logic [ID_NUM-1:0][7:0] ddr_wdata_mask;
    logic [ID_NUM-1:0] ddr_we; 
    logic [2*ID_NUM-1:0] selected_queue_decoded;
    logic [$clog2(ID_NUM)-1:0]  bw_arb; 
    logic [$clog2(ID_NUM)-1:0] pri; //priority storing for bresp channel arbitration.
    logic idrc;
    priority_enc #(.BANK_NUM(ID_NUM)) ENCODER  ( (selected_queue_decoded[2*ID_NUM-1:ID_NUM] | selected_queue_decoded[ID_NUM-1:0]), bw_arb , idrc);


    logic [$clog2(ID_NUM)-1:0] selected_queue; //for outputting data to dram. Backend arbiter should be in charge of making sure that no two output bursts intefere. 
    

    bind nb_wdata_queue_wrapper nb_wdata_queue_prop WDATA_QUEUE_MONITOR (CLK, nRST, bwvalid, bw_arb, wdw.bwready, wdw.be_write, 
    wdw.be_wid, ddr_we);


    assign wdw.wready = wready[wdw.wdq_slot.wid];
    assign wdw.bwvalid = bwvalid[bw_arb];
    assign wdw.bwresp = bwresp[bw_arb];
    assign wdw.bwid = bwid[bw_arb];
    assign wdw.ddr_wdata_data = ddr_wdata_data[selected_queue];
    assign wdw.ddr_wdata_en = ddr_wdata_en[selected_queue];
    assign wdw.ddr_wdata_mask = ddr_wdata_mask[selected_queue];
    assign wdw.ddr_we = ddr_we[selected_queue]; 
    
    genvar i;
    generate 
        for (i = 0; i < ID_NUM; i++) begin
            // Generating wdata_queues. 
            nb_wdata_queue #(.Q_ID(i)) WDATA_QUEUE_GEN ( 
                CLK, nRST, wdw.wdq_slot, wdw.bwready, wdw.wvalid, wdw.wlast, wdw.be_wid, wdw.be_write, bw_arb, 
	       	wready[i], bwvalid[i], bwresp[i], bwid[i], ddr_wdata_data[i], ddr_wdata_en[i], ddr_wdata_mask[i], ddr_we[i]	
            );

        end

    endgenerate
   

    logic [2 * ID_NUM - 1:0] double_bwvalid;
    logic [2 * ID_NUM - 1:0] double_mask;
    assign double_mask = {(2 * ID_NUM){1'b1}} << pri;
    assign double_bwvalid = {bwvalid , bwvalid };
    logic [2 * ID_NUM - 1:0] double_array_masked;
    assign double_array_masked = double_mask & double_bwvalid; 
    assign selected_queue_decoded = double_array_masked & ~(double_array_masked - 'b1);

    
/*
    logic [$clog2(ID_NUM)-1:0] idx;
    logic [$clog2(ID_NUM)-1:0] j;
    always_comb  begin : PRIORITY_COMB
        selected_queue_decoded = 'b0;
        for(j = 0; j < ID_NUM; j++) begin
	    idx = j + pri;
            if(bwvalid[idx]) begin
                selected_queue_decoded[idx] = 1'b1; 
                break;
            end 
        end 
    end
*/
       

    always_ff @(posedge CLK, negedge nRST) begin : PRIORITY
        if(!nRST)
            pri <= 'b0;
        else
            pri <= pri + 'b1;
    end

    always_ff @(posedge CLK, negedge nRST) begin : SELECTED_BURST_QUEUE

        if(!nRST) 
            selected_queue <= 'b0;
        else if(wdw.be_write)
            selected_queue <= wdw.be_wid;

    end

endmodule 
