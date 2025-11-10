`include "scpad_pkg.sv"
`include "scpad_if.sv"

/*  Julio Hernandez - herna628@purdue.edu */
/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

module sram_write_latch (scpad_if.sram_write_latch sr_wr_l);
    import scpad_pkg::*;

    sram_write_req_t sram_write_latch;
    sram_write_req_t nxt_sram_write_latch;

    logic [MAX_REQ_WIDTH-1:0] request_completed_counter, nxt_request_completed_counter;
    always_ff @(posedge sr_wr_l.clk, negedge sr_wr_l.n_rst) begin
        if(!sr_wr_l.n_rst) begin
            sram_write_latch <= 'b0;
            request_completed_counter <= 'b0;
        end else begin
            sram_write_latch <= nxt_sram_write_latch;
            request_completed_counter <= nxt_request_completed_counter;
        end
    end

    always_comb begin
        nxt_sram_write_latch = sram_write_latch;
        nxt_request_completed_counter = request_completed_counter;
        sr_wr_l.sr_wr_l_out.sram_write_req_latched = 1'b0;
        sr_wr_l.sr_wr_l_out.sram_write_req = 0;

        if((sr_wr_l.sr_wr_l_in.be_stall == 1'b0) && (sram_write_latch.valid == 1'b1)) begin
            sr_wr_l.sr_wr_l_out.sram_write_req = sram_write_latch;
            sr_wr_l.sr_wr_l_out.sram_write_req_latched = 1'b1;
            nxt_sram_write_latch = 0;
        end

        if(sr_wr_l.sr_wr_l_in.dram_res_valid) begin
            nxt_sram_write_latch.valid = ((request_completed_counter) == sr_wr_l.sr_wr_l_in.num_request) ? 1'b1 : 1'b0;
            nxt_sram_write_latch.wdata[({DRAM_VECTOR_MASK_LANES_SHIFT'(0), sr_wr_l.sr_wr_l_in.dram_id[MAX_REQ_WIDTH-1:0]} << DRAM_VECTOR_MASK_LANES_SHIFT) +: DRAM_VECTOR_MASK_LANES] = sr_wr_l.sr_wr_l_in.dram_rddata;
            nxt_sram_write_latch.spad_addr = sr_wr_l.sr_wr_l_in.spad_addr;
            nxt_sram_write_latch.xbar = sr_wr_l.sr_wr_l_in.xbar;
            nxt_request_completed_counter = request_completed_counter + 1;

            if(request_completed_counter == sr_wr_l.sr_wr_l_in.num_request) begin
                nxt_request_completed_counter = 0;
            end
        end
    end

endmodule