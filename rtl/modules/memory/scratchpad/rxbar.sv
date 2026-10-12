/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

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
