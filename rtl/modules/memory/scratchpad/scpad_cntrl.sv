/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

// Using full interface since sram_ctrl modport may not have all signals
module scpad_cntrl #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (scpad_if srif);

    import scpad_pkg::*;

    // ─── FIFO parameters ───
    localparam FIFO_DEPTH = (MAX_SRAM_DELAY < 4) ? 8 : (MAX_SRAM_DELAY + 8);
    localparam SRAM_READ_LATENCY  = 2;
    localparam SRAM_WRITE_LATENCY = 2;

    // ─── Read FIFO + inflight tracking ───
    logic rd_fifo_empty, rd_fifo_full;
    logic rd_en;
    sel_req_t rd_fifo_out;

    logic [SRAM_READ_LATENCY:0] rd_inflight_pipe;
    logic sram_rd_busy;

    wire incoming_valid = srif.xbar_cntrl_req[IDX].valid;
    wire incoming_write = srif.xbar_cntrl_req[IDX].write;

    fifo #(.DEPTH(FIFO_DEPTH), .DWIDTH($bits(sel_req_t))) rd_fifo (
        .clk(srif.clk), .rstn(srif.n_rst),
        .wr_en(incoming_valid && !incoming_write && !rd_fifo_full),
        .din(srif.xbar_cntrl_req[IDX]),
        .rd_en(rd_en),
        .dout(rd_fifo_out),
        .full(rd_fifo_full),
        .empty(rd_fifo_empty)
    );

    always_ff @(posedge srif.clk or negedge srif.n_rst) begin
        if (!srif.n_rst) begin
            rd_inflight_pipe <= '0;
        end else begin
            rd_inflight_pipe[0] <= rd_en;
            for (int i = 1; i <= SRAM_READ_LATENCY; i++)
                rd_inflight_pipe[i] <= rd_inflight_pipe[i-1];
        end
    end

    assign sram_rd_busy = |rd_inflight_pipe[SRAM_READ_LATENCY-1:0];
    assign rd_en = !sram_rd_busy && !rd_fifo_empty;

    // ─── Write FIFO + inflight tracking ───
    logic wr_fifo_empty, wr_fifo_full;
    logic wr_en;
    sel_req_t wr_fifo_out;

    logic [SRAM_WRITE_LATENCY:0] wr_inflight_pipe;
    logic sram_wr_busy;

    fifo #(.DEPTH(FIFO_DEPTH), .DWIDTH($bits(sel_req_t))) wr_fifo (
        .clk(srif.clk), .rstn(srif.n_rst),
        .wr_en(incoming_valid && incoming_write && !wr_fifo_full),
        .din(srif.xbar_cntrl_req[IDX]),
        .rd_en(wr_en),
        .dout(wr_fifo_out),
        .full(wr_fifo_full),
        .empty(wr_fifo_empty)
    );

    always_ff @(posedge srif.clk or negedge srif.n_rst) begin
        if (!srif.n_rst) begin
            wr_inflight_pipe <= '0;
        end else begin
            wr_inflight_pipe[0] <= wr_en;
            for (int i = 1; i <= SRAM_WRITE_LATENCY; i++)
                wr_inflight_pipe[i] <= wr_inflight_pipe[i-1];
        end
    end

    assign sram_wr_busy = |wr_inflight_pipe[SRAM_WRITE_LATENCY-1:0];
    assign wr_en = !sram_wr_busy && !wr_fifo_empty;

    // ─── Outputs: separate read and write request paths ───
    // Read requests → cntrl_spad_req (drives sram_bank ren/raddr)
    // Write requests → cntrl_spad_wr_req (drives sram_bank wen/waddr/wdata)
    // Both can fire simultaneously — sram_bank has independent R+W ports.
    assign srif.cntrl_spad_req[IDX].valid = rd_en && rd_fifo_out.valid;
    assign srif.cntrl_spad_req[IDX].write = 1'b0;  // read path only
    assign srif.cntrl_spad_req[IDX].src   = rd_fifo_out.src;
    assign srif.cntrl_spad_req[IDX].xbar  = rd_fifo_out.xbar;
    assign srif.cntrl_spad_req[IDX].wdata = '0;

    assign srif.cntrl_spad_wr_req[IDX].valid = wr_en && wr_fifo_out.valid;
    assign srif.cntrl_spad_wr_req[IDX].write = 1'b1;  // write path only
    assign srif.cntrl_spad_wr_req[IDX].src   = wr_fifo_out.src;
    assign srif.cntrl_spad_wr_req[IDX].xbar  = wr_fifo_out.xbar;
    assign srif.cntrl_spad_wr_req[IDX].wdata = wr_fifo_out.wdata;

    // ─── Backpressure ───
    // Stall head when either FIFO is full. Conservative but correct:
    // head doesn't know if the next grant will be a read or write, so
    // we must stall if either path can't accept.
    assign srif.w_stall[IDX] = rd_fifo_full || wr_fifo_full;

    `ifndef SYNTHESIS
        always_ff @(posedge srif.clk, negedge srif.n_rst) begin
            if (!srif.n_rst) begin
                srif.scpad_backpressure_buffer_read_empty[IDX]  <= '0;
                srif.scpad_backpressure_buffer_write_empty[IDX] <= '0;
                srif.scpad_backpressure_buffer_read_stall[IDX]  <= '0;
                srif.scpad_backpressure_buffer_write_stall[IDX] <= '0;
            end else begin
                if (rd_fifo_empty) srif.scpad_backpressure_buffer_read_empty[IDX] <= srif.scpad_backpressure_buffer_read_empty[IDX] + 1;
                if (wr_fifo_empty) srif.scpad_backpressure_buffer_write_empty[IDX] <= srif.scpad_backpressure_buffer_write_empty[IDX] + 1;
                if (rd_fifo_full)  srif.scpad_backpressure_buffer_read_stall[IDX]  <= srif.scpad_backpressure_buffer_read_stall[IDX] + 1;
                if (wr_fifo_full)  srif.scpad_backpressure_buffer_write_stall[IDX] <= srif.scpad_backpressure_buffer_write_stall[IDX] + 1;
            end
        end
    `endif

endmodule