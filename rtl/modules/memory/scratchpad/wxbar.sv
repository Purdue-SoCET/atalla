/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

<<<<<<< HEAD
`include "xbar_if.sv"

module wxbar #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (scpad_if.xbar_w wif); 

    import scpad_pkg::*;

    typedef struct packed {
        logic valid;
        src_t src;
        slot_mask_t  slot_mask;
        mask_t valid_mask;
    } pass_t;

    sync_fifo #(.DEPTH(XBAR_LATENCY), .DWIDTH($bits(pass_t))) pass_through_fifo (
        .clk(wif.clk), .rstn(wif.n_rst),
        .wr_en(!wif.w_stall[IDX]),
        .din(wif.head_stomach_req[IDX].write ? {
                wif.head_stomach_req[IDX].valid, 
                wif.head_stomach_req[IDX].src, 
                wif.head_stomach_req[IDX].xbar.slot_mask, 
                wif.head_stomach_req[IDX].xbar.valid_mask
            } : '0),
        .rd_en(!wif.w_stall[IDX]),
        .dout({
                wif.xbar_cntrl_req[IDX].valid, 
                wif.xbar_cntrl_req[IDX].src, 
                wif.xbar_cntrl_req[IDX].xbar.slot_mask, 
                wif.xbar_cntrl_req[IDX].xbar.valid_mask
            }),
        .full(),
        .empty()
    );

    xbar_if #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) wxbar_vif (.clk(wif.clk), .n_rst(wif.n_rst));

    always_comb begin 
        wxbar_vif.out = wif.xbar_cntrl_req[IDX].wdata;
        wxbar_vif.en = !wif.w_stall[IDX];
        for (int i = 0; i < NUM_COLS; i++) begin 
            wxbar_vif.in.din = wif.head_stomach_req[IDX].write ? wif.head_stomach_req[IDX].wdata[i] : '0;
            wxbar_vif.in.shift = wif.head_stomach_req[IDX].xbar.shift_mask[i];
        end 
    end

    generate
        case (XBAR_TYPE)
            "NAIVE": naive_xbar #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) u_wxbar (wxbar_vif);
            "BENES": benes_xbar #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) u_wxbar (wxbar_vif);
            "BATCHER": batcher_xbar #(.SIZE(NUM_COLS), .DWIDTH(ELEM_BITS)) u_wxbar (wxbar_vif);
        endcase
    endgenerate

endmodule

`ifndef SYNTHESIS



`endif 
=======
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
>>>>>>> origin/Vector_S26_L1_TB
