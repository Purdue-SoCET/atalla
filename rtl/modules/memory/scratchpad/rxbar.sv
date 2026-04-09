/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

<<<<<<< HEAD
`include "xbar_if.sv"

module rxbar #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (scpad_if.xbar_r rif); 

    import scpad_pkg::*;

    typedef struct packed {
        logic valid;
        src_t src;
        slot_mask_t  slot_mask;
        mask_t  valid_mask;
    } pass_t;

    sync_fifo #(.DEPTH(XBAR_LATENCY), .DWIDTH($bits(pass_t))) pass_through_fifo (
        .clk(rif.clk), .rstn(rif.n_rst),
        .wr_en(!rif.r_stall[IDX]),
        .din(!rif.head_stomach_req[IDX].write ? {
            rif.spad_xbar_req[IDX].valid, 
            rif.spad_xbar_req[IDX].src,
            rif.spad_xbar_req[IDX].xbar.slot_mask, 
            rif.spad_xbar_req[IDX].xbar.valid_mask
            } : '0),
        .rd_en(!rif.r_stall[IDX]),
        .dout({
            rif.stomach_tail_res[IDX].valid, 
            rif.stomach_tail_res[IDX].src, 
            rif.stomach_tail_res[IDX].xbar.slot_mask, 
            rif.stomach_tail_res[IDX].xbar.valid_mask
            }),
        .full(),
        .empty()
    );

    xbar_if #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) rxbar_vif (.clk(rif.clk), .n_rst(rif.n_rst));

    always_comb begin 
        rxbar_vif.out = rif.stomach_tail_res[IDX].wdata;
        rxbar_vif.en = !rif.r_stall[IDX];
        for (int i = 0; i < NUM_COLS; i++) begin 
            rxbar_vif.in.din = !rif.head_stomach_req[IDX].write ? rif.spad_xbar_req[IDX].wdata[i] : '0;
            rxbar_vif.in.shift = rif.spad_xbar_req[IDX].xbar.shift_mask[i];
        end 
    end

    generate
        case (XBAR_TYPE)
            "NAIVE": naive_xbar #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) u_rxbar (rxbar_vif);
            "BENES": benes_xbar #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) u_rxbar (rxbar_vif);
            "BATCHER": batcher_xbar #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) u_rxbar (rxbar_vif);
        endcase
    endgenerate

endmodule

`ifndef SYNTHESIS



`endif 
=======
module rxbar #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (scpad_if rif); 

    import scpad_pkg::*;

    // Metadata structure
    typedef struct packed {
        logic valid;
        logic write;
        src_t src;
    } pass_t;

    // For all crossbar types, use FIFO-based identity pass-through
    // BENES with control_bit=0 is identity, BATCHER can't un-swizzle properly
    // So we bypass the crossbar entirely and just buffer through FIFOs
    
    localparam FIFO_DEPTH = 16;
    
    logic fifo_empty, fifo_full;
    logic rd_en;
    pass_t fifo_in, fifo_out;
    scpad_data_t rdata_fifo_out;
    
    assign fifo_in.valid = rif.spad_xbar_req[IDX].valid;
    assign fifo_in.write = rif.spad_xbar_req[IDX].write;
    assign fifo_in.src   = rif.spad_xbar_req[IDX].src;
    
    assign rd_en = !fifo_empty && !rif.fe_vec_res_stall[IDX];
    assign rif.r_stall[IDX] = fifo_full;
    
    // Metadata FIFO
    fifo #(.DEPTH(FIFO_DEPTH), .DWIDTH($bits(pass_t))) meta_fifo (
        .clk(rif.clk), .rstn(rif.n_rst),
        .wr_en(rif.spad_xbar_req[IDX].valid),
        .din(fifo_in),
        .rd_en(rd_en),
        .dout(fifo_out),
        .full(fifo_full),
        .empty(fifo_empty)
    );
    
    // Rdata FIFO - direct pass-through (identity permutation for all types)
    fifo #(.DEPTH(FIFO_DEPTH), .DWIDTH($bits(scpad_data_t))) rdata_fifo (
        .clk(rif.clk), .rstn(rif.n_rst),
        .wr_en(rif.spad_xbar_req[IDX].valid),
        .din(rif.spad_xbar_req[IDX].rdata),
        .rd_en(rd_en),
        .dout(rdata_fifo_out),
        .full(),
        .empty()
    );
    
    logic rd_valid;
    pass_t out_meta;
    scpad_data_t out_rdata;

    always_ff @(posedge rif.clk or negedge rif.n_rst) begin
        if (!rif.n_rst) begin
            rd_valid <= 1'b0;
            out_meta <= '0;
            out_rdata <= '0;
        end else begin
            rd_valid <= rd_en;
            if (rd_en) begin
                out_meta  <= fifo_out;
                out_rdata <= rdata_fifo_out;
            end
        end
    end
    
    // Outputs
    assign rif.stomach_tail_res[IDX].valid = rd_valid && out_meta.valid;
    assign rif.stomach_tail_res[IDX].write = out_meta.write;
    assign rif.stomach_tail_res[IDX].src   = out_meta.src;
    assign rif.stomach_tail_res[IDX].rdata = out_rdata;

endmodule
>>>>>>> origin/Vector_S26_L1_TB
