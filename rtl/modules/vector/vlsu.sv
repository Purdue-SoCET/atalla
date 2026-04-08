module vlsu #(
    parameter int FIFO_DEPTH = 13,
    parameter int NUM_VREGS  = 256,
    parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0
) (
    input  logic               CLK,
    input  logic               nRST,
    vlsu_if.vlsu               vif,
    scpad_if.vec_frontend      sif
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
        .nRST  (nRST),
        .CLK   (CLK),
        .wr_en (lq_wr_en),
        .shift (lq_shift),
        .din   (lq_din),
        .dout  (lq_dout),
        .empty (lq_empty),
        .full  (lq_full)
    );

    logic                   skid_valid_r, skid_valid_next;
    logic [RDATA_WIDTH-1:0] skid_data_r,  skid_data_next;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            skid_valid_r     <= 1'b0;
            skid_data_r      <= '0;
        end else begin
            skid_valid_r     <= skid_valid_next;
            skid_data_r      <= skid_data_next;
        end
    end

    assign sif.fe_vec_res_stall[IDX] = skid_valid_r || skid_valid_next;

    logic is_load, is_store, can_accept;
    logic resp_incoming;

    always_comb begin
        // ── Defaults — vlsu_if outputs ───────────────────
        vif.sched_res[IDX].ready  = 1'b0;
        vif.wb_out[IDX].load_data = '0;
        vif.wb_out[IDX].vdst      = '0;
        vif.wb_out[IDX].valid     = 1'b0;
        vif.status[IDX].busy            = 1'b0;
        vif.status[IDX].load_queue_full = 1'b0;

        // ── Defaults — scpad_if outputs ──────────────────
        sif.vec_req[IDX].valid      = 1'b0;
        sif.vec_req[IDX].write      = 1'b0;
        sif.vec_req[IDX].spad_addr  = '0;
        sif.vec_req[IDX].num_rows   = '0;
        sif.vec_req[IDX].num_cols   = '0;
        sif.vec_req[IDX].row_id     = '0;
        sif.vec_req[IDX].xbar       = '0;
        sif.vec_req[IDX].wdata      = '0;

        // ── Defaults — FIFO + skid controls ──────────────
        lq_wr_en = 1'b0;
        lq_shift = 1'b0;
        lq_din   = '0;

        skid_valid_next = skid_valid_r;
        skid_data_next  = skid_data_r;

        // ── Input classification ─────────────────────────
        is_load  = vif.sched_req[IDX].valid && !vif.sched_req[IDX].write;
        is_store = vif.sched_req[IDX].valid &&  vif.sched_req[IDX].write;

        resp_incoming = sif.vec_res[IDX].valid && !sif.vec_res[IDX].write;

        // ── Accept logic ─────────────────────────────────
        if (is_load)
            can_accept = !lq_full && !sif.fe_vec_stall[IDX];
        else if (is_store)
            can_accept = !sif.fe_vec_stall[IDX] && vif.vrf_store[IDX].valid;
        else
            can_accept = !lq_full && !sif.fe_vec_stall[IDX];

        vif.sched_res[IDX].ready = can_accept;

        // ── Load path ────────────────────────────────────
        if (is_load && can_accept) begin
            lq_wr_en = 1'b1;
            lq_din   = vif.sched_req[IDX].vdst;

            sif.vec_req[IDX].valid      = 1'b1;
            sif.vec_req[IDX].write      = 1'b0;
            sif.vec_req[IDX].spad_addr  = vif.sched_req[IDX].spad_addr;
            sif.vec_req[IDX].num_rows   = vif.sched_req[IDX].num_rows;
            sif.vec_req[IDX].num_cols   = vif.sched_req[IDX].num_cols;
            sif.vec_req[IDX].row_id     = vif.sched_req[IDX].row_id;
        end

        // ── Store path ───────────────────────────────────
        if (is_store && can_accept) begin
            sif.vec_req[IDX].valid      = 1'b1;
            sif.vec_req[IDX].write      = 1'b1;
            sif.vec_req[IDX].spad_addr  = vif.sched_req[IDX].spad_addr;
            sif.vec_req[IDX].num_rows   = vif.sched_req[IDX].num_rows;
            sif.vec_req[IDX].num_cols   = vif.sched_req[IDX].num_cols;
            sif.vec_req[IDX].row_id     = vif.sched_req[IDX].row_id;
            sif.vec_req[IDX].wdata      = vif.vrf_store[IDX].data;
        end

        // ── Response + Writeback ─────────────────────────
        if (skid_valid_r && !lq_empty) begin
            // ── Drain skid ───────────────────────────────
            vif.wb_out[IDX].load_data = skid_data_r;
            vif.wb_out[IDX].vdst      = lq_dout;
            vif.wb_out[IDX].valid     = 1'b1;
            if (vif.wb_ready[IDX]) begin
                lq_shift        = 1'b1;
                skid_valid_next = 1'b0;
            end
        end else if (!skid_valid_r && resp_incoming && !lq_empty) begin
            // ── Bypass ───────────────────────────────────
            vif.wb_out[IDX].load_data = sif.vec_res[IDX].rdata;
            vif.wb_out[IDX].vdst      = lq_dout;
            vif.wb_out[IDX].valid     = 1'b1;
            if (vif.wb_ready[IDX]) begin
                lq_shift = 1'b1;
            end else begin
                // Writeback stalled — capture for later
                skid_valid_next = 1'b1;
                skid_data_next  = sif.vec_res[IDX].rdata;
            end
        end

        // ── Status ───────────────────────────────────────
        vif.status[IDX].busy            = !lq_empty || skid_valid_r;
        vif.status[IDX].load_queue_full = lq_full;
    end

endmodule