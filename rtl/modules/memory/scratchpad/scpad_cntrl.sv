/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

// Using full interface since sram_ctrl modport may not have all signals
module scpad_cntrl #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (scpad_if srif);

    import scpad_pkg::*;

    logic req_fifo_empty; 
    logic req_fifo_full;
    logic rd_en;
    logic rd_valid;  // Delayed rd_en - indicates dout is valid
    sel_req_t fifo_out;

    // FIFO depth based on MAX_SRAM_DELAY, minimum 4 for proper sync_fifo operation
    // Add extra depth for burst handling
    localparam FIFO_DEPTH = (MAX_SRAM_DELAY < 4) ? 8 : (MAX_SRAM_DELAY + 8);
    
    // Track in-flight SRAM operations to prevent overlapping reads
    // SRAM banks set busy during read, but we only check a subset of banks
    // so we need to explicitly track when we have an operation in progress
    localparam SRAM_READ_LATENCY = 2;
    logic [SRAM_READ_LATENCY:0] inflight_pipe;  // Shift register for in-flight reads
    logic sram_busy;  // True when any operation is in progress
    
    always_ff @(posedge srif.clk or negedge srif.n_rst) begin
        if (!srif.n_rst) begin
            inflight_pipe <= '0;
        end else begin
            // Shift the in-flight pipeline
            inflight_pipe[0] <= rd_en;  // New read issued
            for (int i = 1; i <= SRAM_READ_LATENCY; i++) begin
                inflight_pipe[i] <= inflight_pipe[i-1];
            end
        end
    end
    
    // SRAM is busy if any read is in flight (not yet completed)
    // We allow a new read only when the previous one has completed
    assign sram_busy = |inflight_pipe[SRAM_READ_LATENCY-1:0];  // Check all but last stage

    // Read when SRAM is not busy and FIFO has data
    assign rd_en = !sram_busy && !req_fifo_empty;

    // Single request FIFO for both reads and writes
    // Input comes from xbar_cntrl_req (after wxbar processing)
    // Output goes to SRAM banks via cntrl_spad_req
    // NOTE: wr_en gated by !full to prevent silent drops (though backpressure should prevent this)
    sync_fifo #(.DEPTH(FIFO_DEPTH), .DWIDTH($bits(sel_req_t))) req_fifo (
        .clk(srif.clk),
        .rstn(srif.n_rst),
        .wr_en(srif.xbar_cntrl_req[IDX].valid && !req_fifo_full),
        .din(srif.xbar_cntrl_req[IDX]),
        .rd_en(rd_en),
        .dout(fifo_out),
        .full(req_fifo_full),
        .empty(req_fifo_empty)
    );

    // Track when a read was issued - dout is valid 1 cycle after rd_en
    always_ff @(posedge srif.clk or negedge srif.n_rst) begin
        if (!srif.n_rst)
            rd_valid <= 1'b0;
        else
            rd_valid <= rd_en;
    end

    // Gate output by rd_valid - matches when dout is actually valid
    assign srif.cntrl_spad_req[IDX].valid      = rd_valid && fifo_out.valid;
    assign srif.cntrl_spad_req[IDX].write      = fifo_out.write;
    assign srif.cntrl_spad_req[IDX].src        = fifo_out.src;
    assign srif.cntrl_spad_req[IDX].xbar       = fifo_out.xbar;
    assign srif.cntrl_spad_req[IDX].wdata      = fifo_out.wdata;

    // Stall when FIFO is full
    // NOTE: Only drive w_stall (request path backpressure)
    // r_stall should be driven by rxbar when response FIFO is full
    assign srif.w_stall[IDX] = req_fifo_full;
    // assign srif.r_stall[IDX] = req_fifo_full;  // REMOVED - was blocking response path!

    `ifndef SYNTHESIS
        always_ff @(posedge srif.clk, negedge srif.n_rst) begin
            if (!srif.n_rst) begin
                srif.scpad_backpressure_buffer_read_empty[IDX]  <= '0;
                srif.scpad_backpressure_buffer_write_empty[IDX] <= '0;
                srif.scpad_backpressure_buffer_read_stall[IDX]  <= '0;
                srif.scpad_backpressure_buffer_write_stall[IDX] <= '0;
            end else begin
                if (req_fifo_empty) begin
                    srif.scpad_backpressure_buffer_read_empty[IDX] <= srif.scpad_backpressure_buffer_read_empty[IDX] + 1;
                    srif.scpad_backpressure_buffer_write_empty[IDX] <= srif.scpad_backpressure_buffer_write_empty[IDX] + 1;
                end
                if (req_fifo_full) begin
                    srif.scpad_backpressure_buffer_read_stall[IDX] <= srif.scpad_backpressure_buffer_read_stall[IDX] + 1;
                    srif.scpad_backpressure_buffer_write_stall[IDX] <= srif.scpad_backpressure_buffer_write_stall[IDX] + 1;
                end
            end
        end
    `endif

endmodule