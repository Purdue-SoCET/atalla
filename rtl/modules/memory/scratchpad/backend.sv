`include "scpad_params.svh"
`include "scpad_pkg.sv"
`include "scpad_if.sv"

/*  Julio Hernandez - herna628@purdue.edu */
/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

module backend #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (
    scpad_if.backend_sched bshif, 
    scpad_if.backend_body bbif, 
    scpad_if.backend_dram bdrif
);
    import scpad_pkg::*;

    localparam int BURST_COLS = 4;
    localparam int BURST_WIDTH  = 2;

    logic [MAX_DIM_WIDTH-1:0] be_id, uuid, nxt_uuid, schedule_request_counter, nxt_schedule_request_counter;
    logic [MAX_REQ_WIDTH-1:0] sub_uuid, nxt_sub_uuid, num_request;
    logic [DRAM_VECTOR_MASK_LANES-1:0] dram_vector_mask;
    logic initial_request_done, nxt_initial_request_done;

    logic [DRAM_ADDR_WIDTH-1:0] row_base_addr, nxt_row_base_addr;

    logic busy, nxt_busy;

    sched_req_t latched_req, nxt_latched_req;

    always_ff @(posedge bshif.clk, negedge bshif.n_rst ) begin
        if(!bshif.n_rst) begin
            uuid <= 'b0;
            sub_uuid <= 'b0;
            schedule_request_counter <= 'b0;
            initial_request_done <= 1'b0;
            row_base_addr <= 'b0;
            busy <= 1'b0;
            latched_req <= '0;
        end else begin
            uuid <= nxt_uuid;
            sub_uuid <= nxt_sub_uuid;
            schedule_request_counter <= nxt_schedule_request_counter;
            initial_request_done <= nxt_initial_request_done;
            row_base_addr <= nxt_row_base_addr;
            busy <= nxt_busy;
            latched_req <= nxt_latched_req;
        end
    end

    scpad_if be_internal(bbif.clk, bbif.n_rst);

    sched_req_t effective_req;
    assign effective_req = busy ? latched_req : bshif.sched_req[IDX];

    xbar_desc_t be_identity_xbar;
    always_comb begin
        be_identity_xbar.slot = addr_to_row(effective_req.spad_addr) + be_id;
        for (int i = 0; i < NUM_COLS; i++)
            be_identity_xbar.valid_mask[i] = (i <= effective_req.num_cols);
    end

    dram_request_queue dr_rd_req_q(.be_dr_req_q(be_internal));
    assign be_internal.be_dr_req_q_in.sched_write = effective_req.write;
    assign be_internal.be_dr_req_q_in.be_stall = bbif.be_stall[IDX];
    assign be_internal.be_dr_req_q_in.num_request = num_request;
    assign be_internal.be_dr_req_q_in.dram_be_stall = bdrif.dram_be_stall[IDX];
    assign be_internal.be_dr_req_q_in.sched_valid = busy || (bshif.sched_req[IDX].valid && !busy);
    assign be_internal.be_dr_req_q_in.initial_request_done = initial_request_done;

    assign be_id = effective_req.write ? uuid : bdrif.dram_be_res[IDX].id[7:3];

    sram_write_latch be_sr_wr_latch(.sr_wr_l(be_internal));
    assign be_internal.sr_wr_l_in.dram_id = bdrif.dram_be_res[IDX].id;
    assign be_internal.sr_wr_l_in.dram_res_valid = bdrif.dram_be_res[IDX].valid;
    assign be_internal.sr_wr_l_in.dram_vector_mask = bdrif.dram_be_res[IDX].dram_vector_mask;
    assign be_internal.sr_wr_l_in.spad_addr = effective_req.spad_addr + (be_id << ROW_SHIFT);
    assign be_internal.sr_wr_l_in.xbar = be_identity_xbar;
    assign be_internal.sr_wr_l_in.dram_rddata = bdrif.dram_be_res[IDX].rdata;
    assign be_internal.sr_wr_l_in.num_request = num_request;
    assign be_internal.sr_wr_l_in.be_stall = bbif.be_stall[IDX];

    always_comb begin
        num_request = 0;
        nxt_sub_uuid = sub_uuid;
        nxt_uuid = uuid;
        dram_vector_mask = 0;

        bbif.be_req[IDX] = 0;

        nxt_initial_request_done = initial_request_done; 
        nxt_schedule_request_counter = schedule_request_counter;

        bdrif.be_dram_req[IDX] = 0;
        bdrif.be_dram_stall[IDX] = 0;

        nxt_row_base_addr = row_base_addr;
        nxt_busy = busy;
        nxt_latched_req = latched_req;

        bshif.sdma_done[IDX]      = 1'b0;
        bshif.sdma_done_req[IDX]  = latched_req;
        bshif.sched_accepted[IDX] = 1'b0;

        be_internal.be_dr_req_q_in.sram_res_valid = 0;
        be_internal.be_dr_req_q_in.sram_rdata = 0;
        
        if(busy || (bshif.sched_req[IDX].valid && !busy)) begin
            if(!busy) begin
                nxt_busy = 1'b1;
                nxt_latched_req = bshif.sched_req[IDX];
                bshif.sched_accepted[IDX] = 1'b1;
            end
            
            num_request = MAX_REQ_WIDTH'(effective_req.num_cols >> BURST_WIDTH);

            dram_vector_mask = 4'b1111;

            if(sub_uuid == num_request) begin
                if(effective_req.num_cols[1:0] == 2'b00) begin
                    dram_vector_mask = 4'b0001;
                end else if(effective_req.num_cols[1:0] == 2'b01) begin
                    dram_vector_mask = 4'b0011;
                end else if(effective_req.num_cols[1:0] == 2'b10) begin
                    dram_vector_mask = 4'b0111;
                end
            end

            be_internal.be_dr_req_q_in.id = uuid;
            be_internal.be_dr_req_q_in.sub_id = sub_uuid;
            
            be_internal.be_dr_req_q_in.dram_addr = effective_req.dram_addr + row_base_addr + {sub_uuid, 2'b00};

            be_internal.be_dr_req_q_in.dram_vector_mask = dram_vector_mask;

            if(be_internal.be_dr_req_q_out.burst_complete == 1'b1) begin
                nxt_sub_uuid = sub_uuid + 1;
                if(sub_uuid == num_request) begin
                    nxt_sub_uuid = 0;
                    if(effective_req.write == 1'b0) begin 
                        nxt_uuid = uuid + 1;
                        nxt_row_base_addr = row_base_addr + effective_req.full_num_cols + 1;
                        if(uuid == effective_req.num_rows) begin
                            nxt_initial_request_done = 1'b1;
                        end
                    end
                end
            end

            if(be_internal.sr_wr_l_out.sram_write_req_latched == 1'b1) begin
                bbif.be_req[IDX].valid = be_internal.sr_wr_l_out.sram_write_req.valid;
                bbif.be_req[IDX].write = 1'b1;
                bbif.be_req[IDX].spad_addr = be_internal.sr_wr_l_out.sram_write_req.spad_addr;
                bbif.be_req[IDX].wdata = be_internal.sr_wr_l_out.sram_write_req.wdata;
                bbif.be_req[IDX].xbar = be_internal.sr_wr_l_out.sram_write_req.xbar;
                nxt_schedule_request_counter = schedule_request_counter + 1;
            end
        
            bdrif.be_dram_req[IDX].valid = be_internal.be_dr_req_q_out.dram_req.valid;
            bdrif.be_dram_req[IDX].write = 1'b0;
            bdrif.be_dram_req[IDX].id = be_internal.be_dr_req_q_out.dram_req.id;
            bdrif.be_dram_req[IDX].dram_addr = be_internal.be_dr_req_q_out.dram_req.dram_addr;
            bdrif.be_dram_req[IDX].dram_vector_mask = be_internal.be_dr_req_q_out.dram_req.dram_vector_mask;
            bdrif.be_dram_req[IDX].wdata = 0;
            bdrif.be_dram_req[IDX].num_request = num_request;
            bdrif.be_dram_req[IDX].w_last = be_internal.be_dr_req_q_out.burst_complete;
            bdrif.be_dram_stall[IDX] = be_internal.sr_wr_l_out.latch_full;

            if(effective_req.write == 1'b1) begin
                if(bbif.be_stall[IDX] == 1'b0) begin
                    bbif.be_req[IDX].valid = 1'b1 && !initial_request_done;
                    bbif.be_req[IDX].write = 1'b0;
                    bbif.be_req[IDX].spad_addr = effective_req.spad_addr + (uuid << ROW_SHIFT);
                    bbif.be_req[IDX].num_rows = effective_req.num_rows;
                    bbif.be_req[IDX].num_cols = effective_req.num_cols;
                    bbif.be_req[IDX].row_id = uuid;
                    bbif.be_req[IDX].xbar = be_identity_xbar;
                    bbif.be_req[IDX].wdata = 0;
                    nxt_uuid = initial_request_done ? uuid : uuid + 1;
                    
                    if((uuid == effective_req.num_rows)) begin
                        nxt_initial_request_done = 1'b1; 
                    end
                end

                if(be_internal.be_dr_req_q_out.transaction_complete == 1'b1) begin
                    nxt_schedule_request_counter = schedule_request_counter + 1;
                    nxt_row_base_addr = row_base_addr + effective_req.full_num_cols + 1;
                end
                
                be_internal.be_dr_req_q_in.sram_res_valid = bbif.be_res[IDX].valid;
                be_internal.be_dr_req_q_in.sram_rdata = bbif.be_res[IDX].rdata;
                
                bdrif.be_dram_req[IDX].valid = be_internal.be_dr_req_q_out.dram_req.valid;
                bdrif.be_dram_req[IDX].write = be_internal.be_dr_req_q_out.dram_req.write;
                bdrif.be_dram_req[IDX].id = be_internal.be_dr_req_q_out.dram_req.id;

                bdrif.be_dram_req[IDX].dram_addr = effective_req.dram_addr + row_base_addr + {sub_uuid, 2'b00};

                bdrif.be_dram_req[IDX].dram_vector_mask = dram_vector_mask;
                bdrif.be_dram_req[IDX].wdata = be_internal.be_dr_req_q_out.dram_req.wdata;
                bdrif.be_dram_req[IDX].num_request = num_request;
                bdrif.be_dram_req[IDX].w_last = be_internal.be_dr_req_q_out.burst_complete;
                bdrif.be_dram_stall[IDX] = 0;
            end

            if(effective_req.write == 1'b1) begin
                if((schedule_request_counter == effective_req.num_rows) && (be_internal.be_dr_req_q_out.transaction_complete == 1'b1)) begin
                    nxt_busy = 1'b0;
                    nxt_uuid = 0;
                    nxt_sub_uuid = 0;
                    nxt_schedule_request_counter = 0;
                    nxt_initial_request_done = 0;
                    nxt_row_base_addr = 0;
                    bshif.sdma_done[IDX]     = 1'b1;
                    bshif.sdma_done_req[IDX] = latched_req;
                end
            end else begin
                if((schedule_request_counter == effective_req.num_rows) && (be_internal.sr_wr_l_out.sram_write_req_latched == 1'b1)) begin
                    nxt_busy = 1'b0;
                    nxt_uuid = 0;
                    nxt_sub_uuid = 0;
                    nxt_schedule_request_counter = 0;
                    nxt_initial_request_done = 0;
                    nxt_row_base_addr = 0;
                    bshif.sdma_done[IDX]     = 1'b1;
                    bshif.sdma_done_req[IDX] = latched_req;
                end
            end
        end

        bshif.sched_stall[IDX] = nxt_busy;
    end

endmodule