/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`include "scpad_pkg.sv"
`include "scpad_if.sv"

// NOTE: Using full interface (no modport) because body needs access to internal signals
// like cntrl_spad_req, cntrl_spad_wr_req, spad_busy, spad_cntrl_res, spad_xbar_req
module body #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (scpad_if bif); 

    import scpad_pkg::*;

    head #(.IDX(IDX)) head (.hif(bif));

    wxbar #(.IDX(IDX)) wxbar (.wif(bif));

    scpad_cntrl #(.IDX(IDX)) scpad_cntrl (.srif(bif));

    // SRAM read latency - must match sram_bank parameter
    localparam SRAM_READ_LATENCY = 2;
    
    // Pipeline for metadata through SRAM latency
    // Only tracks READS — writes don't produce responses through rxbar.
    // Write completions go through spad_cntrl_res to head.
    logic [SRAM_READ_LATENCY:0] meta_valid_pipe;
    src_t meta_src_pipe [SRAM_READ_LATENCY+1];
    
    always_ff @(posedge bif.clk or negedge bif.n_rst) begin
        if (!bif.n_rst) begin
            meta_valid_pipe <= '0;
            for (int i = 0; i <= SRAM_READ_LATENCY; i++) begin
                meta_src_pipe[i] <= SRC_FE;
            end
        end else begin
            // Track read requests only (from cntrl_spad_req, the read path)
            meta_valid_pipe[0] <= bif.cntrl_spad_req[IDX].valid;
            meta_src_pipe[0]   <= bif.cntrl_spad_req[IDX].src;
            
            for (int i = 1; i <= SRAM_READ_LATENCY; i++) begin
                meta_valid_pipe[i] <= meta_valid_pipe[i-1];
                meta_src_pipe[i]   <= meta_src_pipe[i-1];
            end
        end
    end

    // Declare signals for SRAM banks - one per column, aggregated across subarrays
    logic [NUM_COLS-1:0] bank_rdone;
    logic [NUM_COLS-1:0] bank_wdone;
    logic [ELEM_BITS-1:0] bank_rdata [NUM_COLS];
    logic [NUM_COLS-1:0] bank_busy;

    genvar gi, ti;
    generate
        for (gi = 0; gi < NUM_COLS; gi++) begin : g_bank
            // Per-subarray signals within this bank
            logic [SRAM_VERT_FOLD_FACTOR-1:0] subarray_rdone;
            logic [SRAM_VERT_FOLD_FACTOR-1:0] subarray_wdone;
            logic [ELEM_BITS-1:0] subarray_rdata [SRAM_VERT_FOLD_FACTOR];
            logic [SRAM_VERT_FOLD_FACTOR-1:0] subarray_busy;
            
            for (ti = 0; ti < SRAM_VERT_FOLD_FACTOR; ti++) begin : g_subarray
                // Subarray selection — separate for reads and writes since they
                // come from different request paths and may target different rows
                logic rd_is_selected, wr_is_selected;
                if (SRAM_VERT_FOLD_FACTOR == 1) begin
                    assign rd_is_selected = 1'b1;
                    assign wr_is_selected = 1'b1;
                end else begin
                    assign rd_is_selected = (bif.cntrl_spad_req[IDX].xbar.slot[SRAM_SUBARRAY_WIDTH_BITS-1:0] == ti);
                    assign wr_is_selected = (bif.cntrl_spad_wr_req[IDX].xbar.slot[SRAM_SUBARRAY_WIDTH_BITS-1:0] == ti);
                end

                sram_bank #(
                    .READ_LATENCY (SRAM_READ_LATENCY), 
                    .WRITE_LATENCY(2), 
                    .HEIGHT(SRAM_SUBARRAY_HEIGHT), 
                    .WIDTH(ELEM_BITS)
                ) u_bank (
                    .clk(bif.clk), 
                    .n_rst(bif.n_rst), 
                    .busy(subarray_busy[ti]), 

                    // Read port — driven by cntrl_spad_req (read FIFO)
                    .ren(bif.cntrl_spad_req[IDX].xbar.valid_mask[gi] && 
                         bif.cntrl_spad_req[IDX].valid && 
                         rd_is_selected),
                    .raddr(bif.cntrl_spad_req[IDX].xbar.slot[SRAM_SUBARRAY_HEIGHT_BITS-1:0]),
                    .rdone(subarray_rdone[ti]),
                    .rdata(subarray_rdata[ti]),

                    // Write port — driven by cntrl_spad_wr_req (write FIFO)
                    // Independent from read — both can fire simultaneously
                    .wen(bif.cntrl_spad_wr_req[IDX].xbar.valid_mask[gi] && 
                         bif.cntrl_spad_wr_req[IDX].valid && 
                         wr_is_selected),
                    .waddr(bif.cntrl_spad_wr_req[IDX].xbar.slot[SRAM_SUBARRAY_HEIGHT_BITS-1:0]),
                    .wdone(subarray_wdone[ti]),
                    .wdata(bif.cntrl_spad_wr_req[IDX].wdata[gi])
                );
            end
            
            // Aggregate signals from all subarrays in this bank
            assign bank_busy[gi] = |subarray_busy;
            assign bank_rdone[gi] = |subarray_rdone;
            assign bank_wdone[gi] = |subarray_wdone;
            
            // Mux rdata from the subarray that completed
            always_comb begin
                bank_rdata[gi] = '0;
                for (int t = 0; t < SRAM_VERT_FOLD_FACTOR; t++) begin
                    if (subarray_rdone[t]) begin
                        bank_rdata[gi] = subarray_rdata[t];
                    end
                end
            end
            
            // Connect to interface
            assign bif.spad_busy[IDX][gi] = bank_busy[gi];
            assign bif.spad_cntrl_res[IDX][gi] = bank_rdone[gi] || bank_wdone[gi]; 
            assign bif.spad_xbar_req[IDX].rdata[gi] = bank_rdata[gi]; 
        end 
    endgenerate

    rxbar #(.IDX(IDX)) rxbar (.rif(bif));

    // Drive spad_xbar_req metadata from DELAYED pipeline (matches SRAM read latency)
    assign bif.spad_xbar_req[IDX].valid = |bank_rdone;
    assign bif.spad_xbar_req[IDX].write = 1'b0;  // only reads reach rxbar
    assign bif.spad_xbar_req[IDX].src   = meta_src_pipe[SRAM_READ_LATENCY];

    tail #(.IDX(IDX)) tail (.tif(bif));

endmodule