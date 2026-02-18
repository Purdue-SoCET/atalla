module vlsu #(
    parameter int FIFO_DEPTH = 13,
    parameter int NUM_VREGS  = 256,
    parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0
) (
    vlsu_if.vlsu           vif,
    scpad_if.vec_frontend  sif
);

    import vector_pkg::*;
    import scpad_pkg::*;

    localparam int VDST_WIDTH  = VIDX_W;
    localparam int RDATA_WIDTH = $bits(scpad_data_t);

    logic                   lq_wr_en, lq_shift;
    logic [VDST_WIDTH-1:0]  lq_din, lq_dout;
    logic                   lq_empty, lq_full;

    sync_fifo #(
        .FIFODEPTH(FIFO_DEPTH),
        .DATAWIDTH(VDST_WIDTH)
    ) load_queue (
        .nRST  (vif.n_rst),
        .CLK   (vif.clk),
        .wr_en (lq_wr_en),
        .shift (lq_shift),
        .din   (lq_din),
        .dout  (lq_dout),
        .empty (lq_empty),
        .full  (lq_full)
    );

    logic                    rq_wr_en, rq_shift;
    logic [RDATA_WIDTH-1:0]  rq_din, rq_dout;
    logic                    rq_empty, rq_full;

    sync_fifo #(
        .FIFODEPTH(FIFO_DEPTH),
        .DATAWIDTH(RDATA_WIDTH)
    ) resp_queue (
        .nRST  (vif.n_rst),
        .CLK   (vif.clk),
        .wr_en (rq_wr_en),
        .shift (rq_shift),
        .din   (rq_din),
        .dout  (rq_dout),
        .empty (rq_empty),
        .full  (rq_full)
    );

    logic is_load, is_store, can_accept;

    always_comb begin
        // Defaults — vlsu_if outputs
        vif.sched_res[IDX].ready  = 1'b0;
        vif.wb_out[IDX].load_data = '0;
        vif.wb_out[IDX].vdst      = '0;
        vif.wb_out[IDX].valid     = 1'b0;
        vif.status[IDX].busy            = 1'b0;
        vif.status[IDX].load_queue_full = 1'b0;

        // Defaults — scpad_if outputs
        sif.vec_req[IDX].valid      = 1'b0;
        sif.vec_req[IDX].write      = 1'b0;
        sif.vec_req[IDX].spad_addr  = '0;
        sif.vec_req[IDX].num_rows   = '0;
        sif.vec_req[IDX].num_cols   = '0;
        sif.vec_req[IDX].row_id     = '0;
        sif.vec_req[IDX].col_id     = '0;
        sif.vec_req[IDX].row_or_col = 1'b0;
        sif.vec_req[IDX].xbar       = '0;
        sif.vec_req[IDX].wdata      = '0;

        // Defaults — FIFO controls
        lq_wr_en = 1'b0;
        lq_shift = 1'b0;
        lq_din   = '0;
        rq_wr_en = 1'b0;
        rq_shift = 1'b0;
        rq_din   = '0;

        // Input classification
        is_load  = vif.sched_req[IDX].valid && !vif.sched_req[IDX].write;
        is_store = vif.sched_req[IDX].valid &&  vif.sched_req[IDX].write;

        if (is_load)
            can_accept = !lq_full && !sif.fe_vec_stall[IDX];
        else if (is_store)
            can_accept = !sif.fe_vec_stall[IDX] && vif.vrf_store[IDX].valid;
        else
            can_accept = 1'b1;

        vif.sched_res[IDX].ready = can_accept;

        // Load path
        if (is_load && can_accept) begin
            lq_wr_en = 1'b1;
            lq_din   = vif.sched_req[IDX].vdst;

            sif.vec_req[IDX].valid      = 1'b1;
            sif.vec_req[IDX].write      = 1'b0;
            sif.vec_req[IDX].spad_addr  = vif.sched_req[IDX].spad_addr;
            sif.vec_req[IDX].num_rows   = vif.sched_req[IDX].num_rows;
            sif.vec_req[IDX].num_cols   = vif.sched_req[IDX].num_cols;
            sif.vec_req[IDX].row_id     = vif.sched_req[IDX].row_id;
            sif.vec_req[IDX].col_id     = vif.sched_req[IDX].col_id;
            sif.vec_req[IDX].row_or_col = vif.sched_req[IDX].row_or_col;
        end

        // Store path
        if (is_store && can_accept) begin
            sif.vec_req[IDX].valid      = 1'b1;
            sif.vec_req[IDX].write      = 1'b1;
            sif.vec_req[IDX].spad_addr  = vif.sched_req[IDX].spad_addr;
            sif.vec_req[IDX].num_rows   = vif.sched_req[IDX].num_rows;
            sif.vec_req[IDX].num_cols   = vif.sched_req[IDX].num_cols;
            sif.vec_req[IDX].row_id     = vif.sched_req[IDX].row_id;
            sif.vec_req[IDX].col_id     = vif.sched_req[IDX].col_id;
            sif.vec_req[IDX].row_or_col = vif.sched_req[IDX].row_or_col;
            sif.vec_req[IDX].wdata      = vif.vrf_store[IDX].data;
        end

        begin
            logic resp_incoming;
            logic bypass_eligible;

            resp_incoming    = sif.vec_res[IDX].valid && !sif.vec_res[IDX].write;
            bypass_eligible  = resp_incoming && rq_empty && !lq_empty;

            if (bypass_eligible) begin
                // Drive writeback straight from scratchpad response
                vif.wb_out[IDX].load_data = sif.vec_res[IDX].rdata;
                vif.wb_out[IDX].vdst      = lq_dout;
                vif.wb_out[IDX].valid     = 1'b1;
                if (vif.wb_ready[IDX]) begin
                    // Consumed — pop load queue, skip resp FIFO entirely
                    lq_shift = 1'b1;
                end else begin
                    // Writeback stalled — buffer for later
                    rq_wr_en = 1'b1;
                    rq_din   = sif.vec_res[IDX].rdata;
                end
            end else begin
                // Buffer any incoming response into FIFO
                if (resp_incoming) begin
                    rq_wr_en = 1'b1;
                    rq_din   = sif.vec_res[IDX].rdata;
                end

                // Drain from FIFOs when both have data
                if (!rq_empty && !lq_empty) begin
                    vif.wb_out[IDX].load_data = rq_dout;
                    vif.wb_out[IDX].vdst      = lq_dout;
                    vif.wb_out[IDX].valid     = 1'b1;
                    if (vif.wb_ready[IDX]) begin
                        lq_shift = 1'b1;
                        rq_shift = 1'b1;
                    end
                end
            end
        end

        // Status 
        vif.status[IDX].busy            = !lq_empty;
        vif.status[IDX].load_queue_full = lq_full;
    end

endmodule