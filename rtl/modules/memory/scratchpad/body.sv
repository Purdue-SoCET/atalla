/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`include "scpad_pkg.sv"
`include "scpad_if.sv"

// NOTE: Using full interface (no modport) because body needs access to internal signals
// like cntrl_spad_req, spad_busy, spad_cntrl_res, spad_xbar_req that aren't in spad_body modport
module body #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (scpad_if bif); 

    import scpad_pkg::*;

    head #(.IDX(IDX)) head (.hif(bif));

    wxbar #(.IDX(IDX)) wxbar (.wif(bif));

    scpad_cntrl #(.IDX(IDX)) scpad_cntrl (.srif(bif));

    // SRAM read latency - must match sram_bank parameter
    localparam SRAM_READ_LATENCY = 2;
    
    // Pipeline for metadata through SRAM latency
    // We need to delay write/src signals to match when bank_rdone fires
    logic [SRAM_READ_LATENCY:0] meta_valid_pipe;
    logic [SRAM_READ_LATENCY:0] meta_write_pipe;
    src_t meta_src_pipe [SRAM_READ_LATENCY+1];
    
    // Pipeline for xbar_desc_t through SRAM latency (for rxbar un-swizzling)
    xbar_desc_t xbar_desc_pipe [SRAM_READ_LATENCY+1];
    
    always_ff @(posedge bif.clk or negedge bif.n_rst) begin
        if (!bif.n_rst) begin
            meta_valid_pipe <= '0;
            meta_write_pipe <= '0;
            for (int i = 0; i <= SRAM_READ_LATENCY; i++) begin
                meta_src_pipe[i] <= SRC_FE;
                xbar_desc_pipe[i] <= '0;
            end
        end else begin
            // Shift pipeline - only for reads
            meta_valid_pipe[0] <= bif.cntrl_spad_req[IDX].valid && !bif.cntrl_spad_req[IDX].write;
            meta_write_pipe[0] <= bif.cntrl_spad_req[IDX].write;
            meta_src_pipe[0]   <= bif.cntrl_spad_req[IDX].src;
            xbar_desc_pipe[0]  <= bif.cntrl_spad_req[IDX].xbar;  // Track xbar descriptor
            
            for (int i = 1; i <= SRAM_READ_LATENCY; i++) begin
                meta_valid_pipe[i] <= meta_valid_pipe[i-1];
                meta_write_pipe[i] <= meta_write_pipe[i-1];
                meta_src_pipe[i]   <= meta_src_pipe[i-1];
                xbar_desc_pipe[i]  <= xbar_desc_pipe[i-1];
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
                // Determine which subarray this access targets based on address bits
                // Uses lower SRAM_SUBARRAY_WIDTH_BITS of slot_mask to select subarray
                logic is_selected;
                if (SRAM_VERT_FOLD_FACTOR == 1) begin
                    // Only one subarray, always selected
                    assign is_selected = 1'b1;
                end else begin
                    assign is_selected = (bif.cntrl_spad_req[IDX].xbar.slot_mask[gi][SRAM_SUBARRAY_WIDTH_BITS-1:0] == ti);
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

                    // Read when valid, mask set, NOT a write, AND this subarray is selected
                    // Address is lower SRAM_SUBARRAY_HEIGHT_BITS of slot_mask
                    .ren(bif.cntrl_spad_req[IDX].xbar.valid_mask[gi] && 
                         bif.cntrl_spad_req[IDX].valid && 
                         !bif.cntrl_spad_req[IDX].write && 
                         is_selected),
                    .raddr(bif.cntrl_spad_req[IDX].xbar.slot_mask[gi][SRAM_SUBARRAY_HEIGHT_BITS-1:0]),
                    .rdone(subarray_rdone[ti]),
                    .rdata(subarray_rdata[ti]),

                    // Write when valid, mask set, IS a write, AND this subarray is selected
                    .wen(bif.cntrl_spad_req[IDX].xbar.valid_mask[gi] && 
                         bif.cntrl_spad_req[IDX].valid && 
                         bif.cntrl_spad_req[IDX].write && 
                         is_selected),
                    .waddr(bif.cntrl_spad_req[IDX].xbar.slot_mask[gi][SRAM_SUBARRAY_HEIGHT_BITS-1:0]),
                    .wdone(subarray_wdone[ti]),
                    .wdata(bif.cntrl_spad_req[IDX].wdata[gi])
                );
            end
            
            // Aggregate signals from all subarrays in this bank
            // Bank is busy if any subarray is busy
            assign bank_busy[gi] = |subarray_busy;
            
            // Bank rdone/wdone if any subarray completes
            assign bank_rdone[gi] = |subarray_rdone;
            assign bank_wdone[gi] = |subarray_wdone;
            
            // Mux rdata from the subarray that completed
            // One-hot select based on which subarray had rdone
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

    // Drive spad_xbar_req metadata from DELAYED pipeline (matches SRAM latency)
    assign bif.spad_xbar_req[IDX].valid = |bank_rdone;  // Valid when any bank has read data
    assign bif.spad_xbar_req[IDX].write = meta_write_pipe[SRAM_READ_LATENCY];  // Delayed metadata
    assign bif.spad_xbar_req[IDX].src   = meta_src_pipe[SRAM_READ_LATENCY];    // Delayed metadata

    // Drive tracked xbar descriptor for rxbar un-swizzling
    assign bif.spad_xbar_desc[IDX] = xbar_desc_pipe[SRAM_READ_LATENCY];

    tail #(.IDX(IDX)) tail (.tif(bif));

endmodule