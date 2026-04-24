//`include "ddr_controller_if.sv"
//`include "dram_pkg.svh"
 

module rid_wrapper (
    input logic CLK, nRST,
    logic [$clog2(ID_NUM)-1:0] be_rid, logic be_push_id, logic rd_incoming, logic rd_pop_id,
    output logic [$clog2(ID_NUM)-1:0] req_id
);
        import dram_pkg::*;
    //SR for tracking reads. Sliding window style.
    //logic shift_en;
    //logic read_incoming; 
    //logic [tCL-1:0] idrc; 
    //flex_sr #(.SIZE(tCL), MSB_FIRST(1'b1)) SLIDE (CLK, nRST, 1'b1, 1'b0, be_push_id, {tCL{1'b0}}, read_incoming, idrc);

    //Timer for burst timing. 
    //logic cnt_clear; 
    //logic cnt_en;
    //logic burst_done; 
    logic fifo_pop; 
    //flex_counter #(.SIZE('d2)) BEAT_CNT (CLK, nRST, cnt_clear, cnt_en, 2'd3, burst_done );

    typedef enum logic [1:0] {IDLE, RECEIVING, POOPING} state_t;
    state_t state, state_next; 

    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST) begin
            state <= IDLE;
        end else begin
            state <= state_next; 
        end
    end

    always_comb begin : NEXT_STATE
        state_next = state;
        case(state)
            IDLE : begin
                if(rd_incoming) begin
                    state_next = RECEIVING;
                end 
            end
            RECEIVING : begin
                if(rd_pop_id) begin
                    state_next = POOPING;
                end
            end
            POOPING: begin
                state_next = IDLE; 
            end

        endcase

    end 

    //fifos for taking IDs.
    sync_fifo #(.DEPTH(ID_NUM), .DWIDTH( $clog2(ID_NUM) ) ) ID_FIFO (.clk(CLK), .wr_en(be_push_id), .din(be_rid), .rd_en(fifo_pop), .dout(req_id), .full(), .empty()  );

    always_comb begin : CONTROL_OUTPUT_LOGIC
        //req_valid = 1'b0;
        //cnt_clear = 1'b0;
        //cnt_en = 1'b0;
        fifo_pop = 1'b0; 
        if(state == RECEIVING) begin
            //req_valid = 1'b1;
            //cnt_en = 1'b1;
        end else if(state == POOPING) begin
            //cnt_clear = 1'b0;
            fifo_pop = 1'b1;
        end
    end


endmodule

    