`include "scpad_pkg.sv"
`include "scpad_if.sv"

/*  Julio Hernandez - herna628@purdue.edu */
/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

module dram_request_queue (scpad_if.backend_dram_req_queue be_dr_req_q);
    import scpad_pkg::*;

    dram_req_q_t [NUM_ROWS-1:0] dram_req_latch_block; 
    dram_req_q_t nxt_dram_head_latch_set, nxt_dram_tail_latch_set;

    logic [MAX_DIM_WIDTH-1:0] fifo_head, nxt_fifo_head, fifo_tail, nxt_fifo_tail;
    logic [MAX_REQ_WIDTH-1:0] request_completed_counter, nxt_request_completed_counter;
    logic sram_res_valid;
    scpad_data_t sram_rdata;
    
    always_ff @(posedge be_dr_req_q.clk, negedge be_dr_req_q.n_rst) begin
        if(!be_dr_req_q.n_rst) begin
            dram_req_latch_block <= 'b0;
            fifo_head <= 'b0;
            fifo_tail <= 'b0;
            request_completed_counter <= 'b0;
            sram_res_valid <= 1'b0;
            sram_rdata <= 0;
        end else begin
            dram_req_latch_block[fifo_head] <= nxt_dram_head_latch_set;
            dram_req_latch_block[fifo_tail] <= nxt_dram_tail_latch_set;
            fifo_head <= nxt_fifo_head;
            fifo_tail <= nxt_fifo_tail;
            request_completed_counter <= nxt_request_completed_counter;
            sram_res_valid <= be_dr_req_q.be_dr_req_q_in.sram_res_valid;
            sram_rdata <= be_dr_req_q.be_dr_req_q_in.sram_rdata;
        end
    end

    always_comb begin
        be_dr_req_q.be_dr_req_q_out.dram_req = 0;

        nxt_dram_head_latch_set = dram_req_latch_block[fifo_head];
        nxt_dram_tail_latch_set = dram_req_latch_block[fifo_tail];
        nxt_fifo_head = fifo_head;
        nxt_fifo_tail = fifo_tail;
        nxt_request_completed_counter = request_completed_counter;
        be_dr_req_q.be_dr_req_q_out.transaction_complete = 1'b0;

        be_dr_req_q.be_dr_req_q_out.dram_queue_full = 1'b0;
        be_dr_req_q.be_dr_req_q_out.burst_complete = 1'b0;
        if(be_dr_req_q.be_dr_req_q_in.sched_valid == 1'b1) begin
            if(be_dr_req_q.be_dr_req_q_in.sched_write == 1'b1) begin
                if(sram_res_valid == 1'b1) begin
                    nxt_dram_tail_latch_set.valid = 1'b1;
                    nxt_dram_tail_latch_set.write = 1'b1;
                    nxt_dram_tail_latch_set.id = {be_dr_req_q.be_dr_req_q_in.id, be_dr_req_q.be_dr_req_q_in.sub_id};
                    nxt_dram_tail_latch_set.dram_addr = be_dr_req_q.be_dr_req_q_in.dram_addr;
                    nxt_dram_tail_latch_set.dram_vector_mask = be_dr_req_q.be_dr_req_q_in.dram_vector_mask;
                    nxt_dram_tail_latch_set.wdata = sram_rdata;
                    nxt_fifo_tail = fifo_tail + 1;
                end
            end else if(be_dr_req_q.be_dr_req_q_in.initial_request_done == 1'b0) begin
                nxt_dram_tail_latch_set.valid = 1'b1;
                nxt_dram_tail_latch_set.write = 1'b0;
                nxt_dram_tail_latch_set.id = {be_dr_req_q.be_dr_req_q_in.id, be_dr_req_q.be_dr_req_q_in.sub_id};
                nxt_dram_tail_latch_set.dram_addr = be_dr_req_q.be_dr_req_q_in.dram_addr;
                nxt_dram_tail_latch_set.dram_vector_mask = be_dr_req_q.be_dr_req_q_in.dram_vector_mask;
                nxt_dram_tail_latch_set.wdata = 0;
                nxt_fifo_tail = fifo_tail + 1;
                nxt_request_completed_counter = request_completed_counter + 1;
                be_dr_req_q.be_dr_req_q_out.burst_complete = 1'b1;
            end
        end

        if((be_dr_req_q.be_dr_req_q_in.dram_be_stall == 1'b0) && (fifo_head != fifo_tail)) begin
            be_dr_req_q.be_dr_req_q_out.dram_req.valid = dram_req_latch_block[fifo_head].valid;
            be_dr_req_q.be_dr_req_q_out.dram_req.write = dram_req_latch_block[fifo_head].write;
            be_dr_req_q.be_dr_req_q_out.dram_req.id = dram_req_latch_block[fifo_head].id;
            be_dr_req_q.be_dr_req_q_out.dram_req.dram_addr = dram_req_latch_block[fifo_head].dram_addr;
            be_dr_req_q.be_dr_req_q_out.dram_req.dram_vector_mask = dram_req_latch_block[fifo_head].dram_vector_mask;
            be_dr_req_q.be_dr_req_q_out.dram_req.wdata = 0;

            nxt_dram_head_latch_set = 0;
            nxt_fifo_head = fifo_head + 1;
            if(dram_req_latch_block[fifo_head].write == 1'b1) begin
                be_dr_req_q.be_dr_req_q_out.dram_req.valid = 1'b1;
                be_dr_req_q.be_dr_req_q_out.dram_req.write = 1'b1;
                be_dr_req_q.be_dr_req_q_out.dram_req.id = 0;
                be_dr_req_q.be_dr_req_q_out.dram_req.dram_addr = dram_req_latch_block[fifo_head].dram_addr;
                be_dr_req_q.be_dr_req_q_out.dram_req.dram_vector_mask = dram_req_latch_block[fifo_head].dram_vector_mask;
                be_dr_req_q.be_dr_req_q_out.dram_req.wdata = {<<ELEM_BITS{ dram_req_latch_block[fifo_head].wdata[({DRAM_VECTOR_MASK_LANES_SHIFT'(0), request_completed_counter[MAX_REQ_WIDTH-1:0]} << DRAM_VECTOR_MASK_LANES_SHIFT) +: DRAM_VECTOR_MASK_LANES] }};


                nxt_dram_head_latch_set = dram_req_latch_block[fifo_head];
                nxt_fifo_head = fifo_head;
                nxt_request_completed_counter = request_completed_counter + 1;

                be_dr_req_q.be_dr_req_q_out.burst_complete = 1'b1;

                if(request_completed_counter == be_dr_req_q.be_dr_req_q_in.num_request) begin
                    nxt_dram_head_latch_set = 0; 
                    nxt_fifo_head = fifo_head + 1;
                    be_dr_req_q.be_dr_req_q_out.transaction_complete = 1'b1;
                end
            end
        end

        if(be_dr_req_q.be_dr_req_q_out.burst_complete == 1'b1) begin
            if(request_completed_counter == be_dr_req_q.be_dr_req_q_in.num_request) begin
                nxt_request_completed_counter = 0;
            end
        end

        if(fifo_tail + 1 == fifo_head) begin 
            nxt_dram_tail_latch_set = dram_req_latch_block[fifo_tail];
            nxt_fifo_tail = fifo_tail;
            if(be_dr_req_q.be_dr_req_q_in.sched_write == 1'b0) begin
                nxt_request_completed_counter = request_completed_counter;
                be_dr_req_q.be_dr_req_q_out.burst_complete = 1'b0;
                be_dr_req_q.be_dr_req_q_out.transaction_complete = 1'b0;
            end
            be_dr_req_q.be_dr_req_q_out.dram_queue_full = 1'b1;
        end

    end

endmodule