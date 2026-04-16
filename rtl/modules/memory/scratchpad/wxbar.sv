/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

module wxbar #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (scpad_if wif); 

    import scpad_pkg::*;

    // Metadata structure
    typedef struct packed {
        logic valid;
        logic write;
        src_t src;
        logic [ROW_IDX_WIDTH-1:0] slot;
        mask_t valid_mask;
    } pass_t;

    localparam FIFO_DEPTH = 16;
    
    logic fifo_empty, fifo_full;
    logic rd_en;
    pass_t fifo_in, fifo_out;
    scpad_data_t wdata_fifo_out;
    
    // Input metadata
    assign fifo_in.valid      = wif.head_stomach_req[IDX].valid && !wif.w_stall[IDX] && !fifo_full;
    assign fifo_in.write      = wif.head_stomach_req[IDX].write;
    assign fifo_in.src        = wif.head_stomach_req[IDX].src;
    assign fifo_in.slot       = wif.head_stomach_req[IDX].xbar.slot;
    assign fifo_in.valid_mask = wif.head_stomach_req[IDX].xbar.valid_mask;
    
    assign rd_en = !wif.w_stall[IDX] && !fifo_empty;
    
    // Metadata FIFO
    fifo #(.DEPTH(FIFO_DEPTH), .DWIDTH($bits(pass_t))) meta_fifo (
        .clk(wif.clk), .rstn(wif.n_rst),
        .wr_en(fifo_in.valid),
        .din(fifo_in),
        .rd_en(rd_en),
        .dout(fifo_out),
        .full(fifo_full),
        .empty(fifo_empty)
    );
    
    // Wdata FIFO
    fifo #(.DEPTH(FIFO_DEPTH), .DWIDTH($bits(scpad_data_t))) wdata_fifo (
        .clk(wif.clk), .rstn(wif.n_rst),
        .wr_en(fifo_in.valid),
        .din(wif.head_stomach_req[IDX].wdata),
        .rd_en(rd_en),
        .dout(wdata_fifo_out),
        .full(),
        .empty()
    );
    
    // Outputs
    assign wif.xbar_cntrl_req[IDX].valid           = !fifo_empty && fifo_out.valid;
    assign wif.xbar_cntrl_req[IDX].write           = fifo_out.write;
    assign wif.xbar_cntrl_req[IDX].src             = fifo_out.src;
    assign wif.xbar_cntrl_req[IDX].xbar.slot       = fifo_out.slot;
    assign wif.xbar_cntrl_req[IDX].xbar.valid_mask = fifo_out.valid_mask;
    assign wif.xbar_cntrl_req[IDX].wdata           = wdata_fifo_out;

endmodule