`include "scpad_pkg.sv"
`include "scpad_if.sv"
`include "dram_req_queue_if.vh"

/*  Julio Hernandez - herna628@purdue.edu */
/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

    // modport baceknd_dram_req_queue ( 
    //     input dram_addr, id, dram_vector_mask, sram_rdata, sram_res_valid
    //     input sched_write,       // scheduler write = 1 means it's a scpad store aka we need to do a dram write.
    //     input be_stall,
    //     input dram_be_stall,     // tells us if the dram is ready to accept our req. If it is and our FIFO is valid then we can assume 
    //                               // our current req will be successfully latched in the dram controller and can invalidate nxt cycle
    //     output dram_req, dram_queue_full, dram_req_latched
    // );

module dram_request_queue ( // UUID now needs to have 3 lower bits for an offest since dram can only handle 64 bits at a time
    input logic clk, n_rst, 
    dram_req_queue_if.backend_dram_req_queue be_dr_req_q
);
    import scpad_pkg::*;

    // typedef struct packed {
    //     logic valid; 
    //     logic write;
    //     logic [7:0]   id;
    //     logic [DRAM_ADDR_WIDTH-1:0] dram_addr;
    //     logic [COL_IDX_WIDTH-1:0]   dram_vector_mask;
    //     scpad_data_t wdata;
    // } dram_req_t;

    dram_req_q_t [DRAM_ADDR_WIDTH-1:0] dram_req_latch_block; 
    dram_req_q_t nxt_dram_head_latch_set, nxt_dram_tail_latch_set;

    logic [5-1:0] fifo_head, nxt_fifo_head, fifo_tail, nxt_fifo_tail;
    logic [2:0] request_completed_counter, nxt_request_completed_counter;
    // logic be_dr_req_q.transaction_complete;
    logic sram_res_valid;
    scpad_data_t sram_rdata;

    
    always_ff @(posedge clk, negedge n_rst) begin
        if(!n_rst) begin
            dram_req_latch_block <= 'b0;
            fifo_head <= 'b0;
            fifo_tail <= 'b0;
            request_completed_counter <= 'b0;
            // be_dr_req_q.transaction_complete <= 1'b0;
            sram_res_valid <= 1'b0;
            sram_rdata <= 0;
        end else begin
            dram_req_latch_block[fifo_head] <= nxt_dram_head_latch_set;
            dram_req_latch_block[fifo_tail] <= nxt_dram_tail_latch_set;
            fifo_head <= nxt_fifo_head;
            fifo_tail <= nxt_fifo_tail;
            request_completed_counter <= nxt_request_completed_counter;
            // be_dr_req_q.transaction_complete <= be_dr_req_q.transaction_complete;
            sram_res_valid <= be_dr_req_q.sram_res_valid;
            sram_rdata <= be_dr_req_q.sram_rdata;
        end
    end

    always_comb begin
        be_dr_req_q.dram_req = 0;

        nxt_dram_head_latch_set = dram_req_latch_block[fifo_head];
        nxt_dram_tail_latch_set = dram_req_latch_block[fifo_tail];
        nxt_fifo_head = fifo_head;
        nxt_fifo_tail = fifo_tail;
        nxt_request_completed_counter = request_completed_counter;
        be_dr_req_q.transaction_complete = 1'b0;

        be_dr_req_q.dram_queue_full = 1'b0;
        be_dr_req_q.burst_complete = 1'b0;
        if(be_dr_req_q.sched_valid == 1'b1) begin
            if(be_dr_req_q.sched_write == 1'b1) begin // sched write is 1 when doing a scpad store, aka sram read to dram write
                if(sram_res_valid == 1'b1) begin
                    nxt_dram_tail_latch_set.valid = 1'b1;
                    nxt_dram_tail_latch_set.write = 1'b1;
                    nxt_dram_tail_latch_set.id = {be_dr_req_q.id, be_dr_req_q.sub_id};
                    nxt_dram_tail_latch_set.dram_addr = be_dr_req_q.dram_addr;
                    nxt_dram_tail_latch_set.dram_vector_mask = be_dr_req_q.dram_vector_mask;
                    nxt_dram_tail_latch_set.wdata = sram_rdata;
                    nxt_fifo_tail = fifo_tail + 1;
                end
            end else if(be_dr_req_q.initial_request_done == 1'b0) begin // dram read to sram write
                nxt_dram_tail_latch_set.valid = 1'b1;
                nxt_dram_tail_latch_set.write = 1'b0;
                nxt_dram_tail_latch_set.id = {be_dr_req_q.id, be_dr_req_q.sub_id};
                nxt_dram_tail_latch_set.dram_addr = be_dr_req_q.dram_addr;
                nxt_dram_tail_latch_set.dram_vector_mask = be_dr_req_q.dram_vector_mask;
                nxt_dram_tail_latch_set.wdata = 0;
                nxt_fifo_tail = fifo_tail + 1;
                nxt_request_completed_counter = request_completed_counter + 1;
                be_dr_req_q.burst_complete = 1'b1;
            end
        end

        if((be_dr_req_q.dram_be_stall == 1'b0) && (fifo_head != fifo_tail)) begin //the dram is accepting request and we aren't empty
            be_dr_req_q.dram_req = dram_req_latch_block[fifo_head];
            nxt_dram_head_latch_set = 0; // invalidate head when our request are accepted.
            nxt_fifo_head = fifo_head + 1;
            if(dram_req_latch_block[fifo_head].write == 1'b1) begin
                
                be_dr_req_q.dram_req.valid = 1'b1;
                be_dr_req_q.dram_req.write = 1'b1;
                be_dr_req_q.dram_req.id = 0;
                be_dr_req_q.dram_req.dram_addr = dram_req_latch_block[fifo_head].dram_addr;
                be_dr_req_q.dram_req.dram_vector_mask = dram_req_latch_block[fifo_head].dram_vector_mask;
                if(request_completed_counter[2:0] == 3'b000) begin
                    be_dr_req_q.dram_req.wdata = {dram_req_latch_block[fifo_head].wdata[3][15:0], dram_req_latch_block[fifo_head].wdata[2][15:0], dram_req_latch_block[fifo_head].wdata[1][15:0], dram_req_latch_block[fifo_head].wdata[0][15:0]};
                end else if(request_completed_counter[2:0] == 3'b001) begin
                    be_dr_req_q.dram_req.wdata = {dram_req_latch_block[fifo_head].wdata[7][15:0], dram_req_latch_block[fifo_head].wdata[6][15:0], dram_req_latch_block[fifo_head].wdata[5][15:0], dram_req_latch_block[fifo_head].wdata[4][15:0]};
                end else if(request_completed_counter[2:0] == 3'b010) begin
                    be_dr_req_q.dram_req.wdata = {dram_req_latch_block[fifo_head].wdata[11][15:0], dram_req_latch_block[fifo_head].wdata[10][15:0], dram_req_latch_block[fifo_head].wdata[9][15:0], dram_req_latch_block[fifo_head].wdata[8][15:0]};
                end else if(request_completed_counter[2:0] == 3'b011) begin
                    be_dr_req_q.dram_req.wdata = {dram_req_latch_block[fifo_head].wdata[15][15:0], dram_req_latch_block[fifo_head].wdata[14][15:0], dram_req_latch_block[fifo_head].wdata[13][15:0], dram_req_latch_block[fifo_head].wdata[12][15:0]};
                end else if(request_completed_counter[2:0] == 3'b100) begin
                    be_dr_req_q.dram_req.wdata = {dram_req_latch_block[fifo_head].wdata[19][15:0], dram_req_latch_block[fifo_head].wdata[18][15:0], dram_req_latch_block[fifo_head].wdata[17][15:0], dram_req_latch_block[fifo_head].wdata[16][15:0]};
                end else if(request_completed_counter[2:0] == 3'b101) begin
                    be_dr_req_q.dram_req.wdata = {dram_req_latch_block[fifo_head].wdata[23][15:0], dram_req_latch_block[fifo_head].wdata[22][15:0], dram_req_latch_block[fifo_head].wdata[21][15:0], dram_req_latch_block[fifo_head].wdata[20][15:0]};
                end else if(request_completed_counter[2:0] == 3'b110) begin
                    be_dr_req_q.dram_req.wdata = {dram_req_latch_block[fifo_head].wdata[27][15:0], dram_req_latch_block[fifo_head].wdata[26][15:0], dram_req_latch_block[fifo_head].wdata[25][15:0], dram_req_latch_block[fifo_head].wdata[24][15:0]};
                end else if(request_completed_counter[2:0] == 3'b111) begin
                    be_dr_req_q.dram_req.wdata = {dram_req_latch_block[fifo_head].wdata[31][15:0], dram_req_latch_block[fifo_head].wdata[30][15:0], dram_req_latch_block[fifo_head].wdata[29][15:0], dram_req_latch_block[fifo_head].wdata[28][15:0]};
                end
                nxt_dram_head_latch_set = dram_req_latch_block[fifo_head];
                nxt_fifo_head = fifo_head;
                nxt_request_completed_counter = request_completed_counter + 1;
                be_dr_req_q.burst_complete = 1'b1;
                if(request_completed_counter == be_dr_req_q.num_request) begin
                    nxt_dram_head_latch_set = 0; // invalidate head when our request are accepted.
                    nxt_fifo_head = fifo_head + 1;
                    be_dr_req_q.transaction_complete = 1'b1;
                end
            end
        end

        if(be_dr_req_q.burst_complete == 1'b1) begin
            if(request_completed_counter == be_dr_req_q.num_request) begin
                be_dr_req_q.transaction_complete = 1'b1;
                nxt_request_completed_counter = 0;
            end
        end

        if(fifo_tail + 1 == fifo_head) begin 
            nxt_dram_tail_latch_set = dram_req_latch_block[fifo_tail];
            nxt_fifo_tail = fifo_tail;
            if(be_dr_req_q.sched_write == 1'b0) begin
                nxt_request_completed_counter = request_completed_counter;
                be_dr_req_q.burst_complete = 1'b0;
                be_dr_req_q.transaction_complete = 1'b0;
            end
            be_dr_req_q.dram_queue_full = 1'b1;
        end

    end

endmodule