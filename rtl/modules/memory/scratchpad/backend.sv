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
    logic nxt_sched_res_valid;
    logic initial_request_done, nxt_initial_request_done;

    always_ff @(posedge bshif.clk, negedge bshif.n_rst ) begin
        if(!bshif.n_rst || bshif.sched_res[IDX].valid) begin
            uuid <= 'b0;
            sub_uuid <= 'b0;
            bshif.sched_res[IDX].valid <= 'b0;
            schedule_request_counter <= 'b0;
            initial_request_done <= 1'b0;
        end else begin
            uuid <= nxt_uuid;
            sub_uuid <= nxt_sub_uuid;
            bshif.sched_res[IDX].valid <= nxt_sched_res_valid;
            schedule_request_counter <= nxt_schedule_request_counter;
            initial_request_done <= nxt_initial_request_done;
        end
    end

    scpad_if be_internal(bbif.clk, bbif.n_rst);

    swizzle swizzle_metadata(.swizz(be_internal));
    assign be_internal.swizz_req.row_or_col = 1'b1; 
    assign be_internal.swizz_req.spad_addr = bshif.sched_req[IDX].spad_addr; 
    assign be_internal.swizz_req.num_rows = bshif.sched_req[IDX].num_rows;
    assign be_internal.swizz_req.num_cols = bshif.sched_req[IDX].num_cols;
    assign be_internal.swizz_req.row_id = be_id;  
    assign be_internal.swizz_req.col_id = be_id;  

    dram_request_queue dr_rd_req_q(.be_dr_req_q(be_internal));
    assign be_internal.be_dr_req_q_in.sched_write = bshif.sched_req[IDX].write;
    assign be_internal.be_dr_req_q_in.be_stall = bbif.be_stall[IDX];
    assign be_internal.be_dr_req_q_in.num_request = num_request;
    assign be_internal.be_dr_req_q_in.dram_be_stall = bdrif.dram_be_stall[IDX];
    assign be_internal.be_dr_req_q_in.sched_valid = bshif.sched_req[IDX].valid;
    assign be_internal.be_dr_req_q_in.initial_request_done = initial_request_done;

    sram_write_latch be_sr_wr_latch(.sr_wr_l(be_internal));
    assign be_internal.sr_wr_l_in.dram_id = bdrif.dram_be_res[IDX].id;
    assign be_internal.sr_wr_l_in.dram_res_valid = bdrif.dram_be_res[IDX].valid;
    assign be_internal.sr_wr_l_in.spad_addr = bshif.sched_req[IDX].spad_addr + {be_id, 5'b00000};
    assign be_internal.sr_wr_l_in.xbar = be_internal.swizz_res.xbar_desc;
    assign be_internal.sr_wr_l_in.dram_rddata = bdrif.dram_be_res[IDX].rdata;
    assign be_internal.sr_wr_l_in.num_request = num_request;
    assign be_internal.sr_wr_l_in.be_stall = bbif.be_stall[IDX];

    always_comb begin
        num_request = 0;
        be_id = 0;
        nxt_sub_uuid = sub_uuid;
        nxt_uuid = uuid;
        dram_vector_mask = 0;

        bbif.be_req[IDX] = 0;

        nxt_sched_res_valid = 1'b0;
        nxt_initial_request_done = initial_request_done; 

        bdrif.be_dram_req[IDX] = 0;
        bdrif.be_dram_stall[IDX] = 0;

        be_internal.be_dr_req_q_in.sram_res_valid = 0;
        be_internal.be_dr_req_q_in.sram_rdata = 0;
        
        
        if(bshif.sched_req[IDX].valid == 1'b1) begin
            be_id = bdrif.dram_be_res[IDX].id[7:3];
            
            num_request = MAX_REQ_WIDTH'(bshif.sched_req[IDX].num_cols >> BURST_WIDTH);

            if((uuid == bshif.sched_req[IDX].num_rows) && (sub_uuid == num_request)) begin
                nxt_initial_request_done = 1'b1; 
            end

            dram_vector_mask = 4'b1111;

            if(sub_uuid == num_request) begin
                if(bshif.sched_req[IDX].num_cols[1:0] == 2'b00) begin
                    dram_vector_mask = 4'b0001;
                end else if(bshif.sched_req[IDX].num_cols[1:0] == 2'b01) begin
                    dram_vector_mask = 4'b0011;
                end else if(bshif.sched_req[IDX].num_cols[1:0] == 2'b10) begin
                    dram_vector_mask = 4'b0111;
                end
            end

            be_internal.be_dr_req_q_in.id = uuid;
            be_internal.be_dr_req_q_in.sub_id = sub_uuid;
            
            if(bshif.sched_req[IDX].num_cols == 5'b11111) begin
                be_internal.be_dr_req_q_in.dram_addr = bshif.sched_req[IDX].dram_addr + {uuid, sub_uuid, 2'b00};
            end else begin 
                be_internal.be_dr_req_q_in.dram_addr = bshif.sched_req[IDX].dram_addr + uuid * (bshif.sched_req[IDX].num_cols + 1) + {sub_uuid, 2'b00};
            end

            be_internal.be_dr_req_q_in.dram_vector_mask = dram_vector_mask;

            if(be_internal.be_dr_req_q_out.burst_complete == 1'b1) begin
                nxt_sub_uuid = sub_uuid + 1;
                if(sub_uuid == num_request) begin
                    nxt_sub_uuid = 0;
                    nxt_uuid = uuid + 1;
                end
            end

            nxt_schedule_request_counter = schedule_request_counter;

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
            bdrif.be_dram_stall[IDX] = bbif.be_stall[IDX];

            if(bshif.sched_req[IDX].write == 1'b1) begin
                be_id = uuid;
                
                if(bbif.be_stall[IDX] == 1'b0) begin
                    bbif.be_req[IDX].valid = 1'b1 && !initial_request_done;
                    bbif.be_req[IDX].write = 1'b0;
                    bbif.be_req[IDX].spad_addr = bshif.sched_req[IDX].spad_addr + {uuid, 5'b00000};
                    bbif.be_req[IDX].num_rows = bshif.sched_req[IDX].num_rows;
                    bbif.be_req[IDX].num_cols = bshif.sched_req[IDX].num_cols;
                    bbif.be_req[IDX].row_id = uuid;
                    bbif.be_req[IDX].col_id = uuid;
                    bbif.be_req[IDX].row_or_col = 1'b1;
                    bbif.be_req[IDX].xbar = be_internal.swizz_res.xbar_desc;
                    bbif.be_req[IDX].wdata = 0;
                    nxt_uuid = initial_request_done ? uuid : uuid + 1;
                end

                if(be_internal.be_dr_req_q_out.transaction_complete == 1'b1) begin
                    nxt_schedule_request_counter = schedule_request_counter + 1;
                end
                
                be_internal.be_dr_req_q_in.sram_res_valid = bbif.be_res[IDX].valid;
                be_internal.be_dr_req_q_in.sram_rdata = bbif.be_res[IDX].rdata;
                
                bdrif.be_dram_req[IDX].valid = be_internal.be_dr_req_q_out.dram_req.valid;
                bdrif.be_dram_req[IDX].write = be_internal.be_dr_req_q_out.dram_req.write;
                bdrif.be_dram_req[IDX].id = be_internal.be_dr_req_q_out.dram_req.id;

                if(bshif.sched_req[IDX].num_cols == 5'b11111) begin
                    bdrif.be_dram_req[IDX].dram_addr = bshif.sched_req[IDX].dram_addr + {schedule_request_counter, sub_uuid, 2'b00};
                end else begin 
                    bdrif.be_dram_req[IDX].dram_addr = bshif.sched_req[IDX].dram_addr + schedule_request_counter * (bshif.sched_req[IDX].num_cols + 1) + {sub_uuid, 2'b00};
                end

                bdrif.be_dram_req[IDX].dram_vector_mask = dram_vector_mask;
                bdrif.be_dram_req[IDX].wdata = be_internal.be_dr_req_q_out.dram_req.wdata;
                bdrif.be_dram_stall[IDX] = 0;

                if((uuid == bshif.sched_req[IDX].num_rows)) begin
                    nxt_initial_request_done = 1'b1; 
                end
            end

            if((schedule_request_counter == bshif.sched_req[IDX].num_rows) && ((be_internal.be_dr_req_q_out.transaction_complete == 1'b1) || (be_internal.sr_wr_l_out.sram_write_req_latched == 1'b1))) begin
                nxt_sched_res_valid = 1'b1;
                nxt_uuid = 0;
                nxt_sub_uuid = 0;
                nxt_schedule_request_counter = 0;
                nxt_initial_request_done = 0;
            end
        end
    end

endmodule

`ifndef SYNTHESIS



`endif 