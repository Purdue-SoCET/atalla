`include "dram_pkg.svh"
`include "ddr_controller_if.sv"

module nb_rdata_queue_wrapper (
    input logic CLK,CLKx2, nRST,
    ddr_controller_if.rdata_wrapper rdw
);

      

    import dram_pkg::*;

    logic [ID_NUM-1:0] rvalid; 
    logic [ID_NUM-1:0] rlast;
    logic [ID_NUM-1:0][1:0] rresp;
    logic [ID_NUM-1:0][63:0] rdata;
    //logic [ID_NUM-1:0] ddr_we; 
    logic [2*ID_NUM-1:0] selected_queue_decoded;
    logic [2*ID_NUM-1:0] selected_queue_decoded_next;
    logic [$clog2(ID_NUM)-1:0]  rd_arb; 
    logic [$clog2(ID_NUM)-1:0] pri; //priority storing for bresp channel arbitration.
    logic arb_valid;
    priority_enc #(.BANK_NUM(ID_NUM)) ENCODER  ( (selected_queue_decoded[2*ID_NUM-1:ID_NUM] | selected_queue_decoded[ID_NUM-1:0]), rd_arb , arb_valid);

    //Connection to read ID queue. 
    logic [$clog2(ID_NUM)-1:0] rid_out;
    logic [ID_NUM-1:0] preamble_detected; 
    logic [ID_NUM-1:0] rd_pop_id; 

    rid_wrapper(CLK, nRST, rdw.be_rid, rdw.be_push_id, preamble_detected, |rd_pop_id, |rid_out);
    
/*
    bind nb_wdata_queue_wrapper nb_wdata_queue_prop WDATA_QUEUE_MONITOR (CLK, nRST, bwvalid, bw_arb, wdw.bwready, wdw.be_write, 
    wdw.be_wid, ddr_we);
*/

    assign rdw.rvalid = rvalid[rd_arb];
    assign rdw.rdata = rdata[rd_arb];
    assign rdw.rresp = rresp[rd_arb];
    assign rdw.rid = rd_arb;
    assign rdw.rlast = rlast[rd_arb];


    //assign wdw.ddr_we = ddr_we[selected_queue]; 
    
    genvar i;
    generate 
        for (i = 0; i < ID_NUM; i++) begin
            // Generating wdata_queues. 
            nb_rdata_queue #(.Q_ID(i)) WDATA_QUEUE_GEN ( 
                CLK, CLKx2,  nRST, rdw.rready && (rd_arb == i), rid_out, rdw.DQS_t , rdw.DQS_c, rdw.DQ, rdw.DM_n, rvalid[i], 
	       	rdata[i], rlast[i], rresp[i], preamble_detected[i], rd_pop_id[i]	
            );

        end

    endgenerate
   

    logic [2 * ID_NUM - 1:0] double_rvalid;
    logic [2 * ID_NUM - 1:0] double_mask;
    assign double_mask = {(2 * ID_NUM){1'b1}} << pri;
    assign double_rvalid = {rvalid , rvalid };
    logic [2 * ID_NUM - 1:0] double_array_masked;
    assign double_array_masked = double_mask & double_rvalid; 
    assign selected_queue_decoded_next = double_array_masked & ~(double_array_masked - 'b1);

    typedef enum logic {ARBING, BURSTING} arb_state_t;

    arb_state_t state, state_next;
    logic burst_cnt_done, burst_cnt_enable, burst_cnt_clear;

    flex_counter #(.SIZE('d4)) BURST_CNT (CLK, nRST,burst_cnt_clear, burst_cnt_enable, 4'd10, burst_cnt_done); 

    always_ff @(posedge CLK, negedge nRST) begin
        
        if(!nRST) begin
            selected_queue_decoded <= 'b0;
        end else if(state == ARBING) begin
            selected_queue_decoded <= selected_queue_decoded_next;
        end else begin
            selected_queue_decoded <= selected_queue_decoded;
        end

    end

    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST) begin
            state <= ARBING;
        end else begin
            state <= state_next;
        end
    end

    always_comb begin : ARB_STATES
        burst_cnt_clear = 1'b0;
        burst_cnt_enable = 1'b0;
        case(state)
            ARBING: begin
                if(|rvalid) begin
                    state_next = BURSTING;
                end else begin
                    state_next = ARBING;
                end
                burst_cnt_clear = 1'b1;
            end
            BURSTING: begin
                if(burst_cnt_done) begin
                    state_next = ARBING;
                end else begin
                    state_next = BURSTING;
                end
                burst_cnt_enable = 1'b1;
            end

        endcase

    end



    
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

endmodule
