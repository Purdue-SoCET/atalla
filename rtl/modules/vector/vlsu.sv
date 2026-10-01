module vlsu #(
    parameter int FIFO_DEPTH = 13,
    parameter int NUM_VREGS  = 256,
    parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0,
    parameter bit HAS_TRANSPOSE = (IDX == 0)
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
    localparam int LQ_WIDTH    = 1 + VDST_WIDTH; // bit [VDST_WIDTH] = transpose

    logic                   lq_wr_en, lq_shift;
    logic [LQ_WIDTH-1:0]    lq_din, lq_dout;
    logic                   lq_empty, lq_full;  

    logic                   lq_is_transpose;
    logic [VDST_WIDTH-1:0]  lq_vdst;
    assign lq_is_transpose = lq_dout[VDST_WIDTH];
    assign lq_vdst         = lq_dout[VDST_WIDTH-1:0];

    sync_fifo #(
        .FIFODEPTH(FIFO_DEPTH),
        .DATAWIDTH(LQ_WIDTH)
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

    // ── Transpose Unit (instantiated on port 0) ──────
    transpose_unit_if #(.VEC_LEN(NUM_ELEMENTS), .DATA_W(ESZ)) tu_if();

    generate
        if (HAS_TRANSPOSE) begin : gen_transpose
            transpose_unit tu_inst (
                .CLK(CLK),
                .nRST(nRST),
                .tif(tu_if.transpose)
            );
        end else begin : gen_no_transpose
            assign tu_if.out.valid_out = 1'b0;
            assign tu_if.out.ready_in  = 1'b1;
            assign tu_if.out.vec_out   = '0;
        end
    endgenerate

    logic                   skid_valid_r, skid_valid_next;
    logic [RDATA_WIDTH-1:0] skid_data_r,  skid_data_next;

    // Transpose control registers
    logic [4:0]             tu_push_cnt_r, tu_push_cnt_next;
    logic [4:0]             tu_pop_cnt_r,  tu_pop_cnt_next;
    logic [VDST_WIDTH-1:0]  tu_base_vdst_r, tu_base_vdst_next;
    logic                   tu_popping_r, tu_popping_next;
    logic                   tu_all_pushed_r, tu_all_pushed_next;
    logic                   tu_in_flight_r, tu_in_flight_next;
    scpad_data_t            tu_data_r, tu_data_next;
    logic                   tu_stall_scpad;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            skid_valid_r       <= 1'b0;
            skid_data_r        <= '0;
            tu_push_cnt_r      <= '0;
            tu_pop_cnt_r       <= '0;
            tu_base_vdst_r     <= '0;
            tu_popping_r       <= 1'b0;
            tu_all_pushed_r    <= 1'b0;
            tu_in_flight_r     <= 1'b0;
            tu_data_r          <= '0;
        end else begin
            skid_valid_r       <= skid_valid_next;
            skid_data_r        <= skid_data_next;
            tu_push_cnt_r      <= tu_push_cnt_next;
            tu_pop_cnt_r       <= tu_pop_cnt_next;
            tu_base_vdst_r     <= tu_base_vdst_next;
            tu_popping_r       <= tu_popping_next;
            tu_all_pushed_r    <= tu_all_pushed_next;
            tu_in_flight_r     <= tu_in_flight_next;
            tu_data_r          <= tu_data_next;
        end
    end

    assign sif.fe_vec_res_stall[IDX] = skid_valid_r || skid_valid_next || tu_stall_scpad;

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
        vif.status[IDX].transpose_active= 1'b0;
        vif.status[IDX].transpose_push  = 1'b0;
        vif.status[IDX].transpose_pop   = 1'b0;
        vif.status[IDX].transpose_done  = 1'b0;

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

        // ── Defaults — Transpose Unit signals ────────────
        tu_if.in.valid_in  = 1'b0;
        tu_if.in.push_req  = 1'b0;
        tu_if.in.pop_req   = 1'b0;
        tu_if.in.ready_out = 1'b0;
        tu_if.in.vec_in    = tu_data_r;

        tu_stall_scpad      = 1'b0;
        tu_push_cnt_next    = tu_push_cnt_r;
        tu_pop_cnt_next     = tu_pop_cnt_r;
        tu_base_vdst_next   = tu_base_vdst_r;
        tu_popping_next     = tu_popping_r;
        tu_all_pushed_next  = tu_all_pushed_r;
        tu_in_flight_next   = tu_in_flight_r;
        tu_data_next        = tu_data_r;

        // ── Input classification ─────────────────────────
        is_load  = vif.sched_req[IDX].valid && !vif.sched_req[IDX].write;
        is_store = vif.sched_req[IDX].valid &&  vif.sched_req[IDX].write;

        resp_incoming = sif.vec_res[IDX].valid && !sif.vec_res[IDX].write;

        // ── Accept logic ─────────────────────────────────
        if (HAS_TRANSPOSE && (tu_popping_r || tu_all_pushed_r || tu_in_flight_r || !tu_if.out.ready_in)) begin
            can_accept = 1'b0;
        end else if (is_load) begin
            if (HAS_TRANSPOSE && tu_push_cnt_r != 0 && !vif.sched_req[IDX].transpose)
                can_accept = 1'b0;
            else
                can_accept = !lq_full && !sif.fe_vec_stall[IDX];
        end else if (is_store) begin
            if (HAS_TRANSPOSE && tu_push_cnt_r != 0)
                can_accept = 1'b0;
            else
                can_accept = !sif.fe_vec_stall[IDX] && vif.vrf_store[IDX].valid;
        end else begin
            can_accept = !lq_full && !sif.fe_vec_stall[IDX];
        end

        vif.sched_res[IDX].ready = can_accept;

        // ── Load path ────────────────────────────────────
        if (is_load && can_accept) begin
            lq_wr_en = 1'b1;
            lq_din   = { (HAS_TRANSPOSE ? vif.sched_req[IDX].transpose : 1'b0), vif.sched_req[IDX].vdst };
            if (HAS_TRANSPOSE && vif.sched_req[IDX].transpose)
                tu_in_flight_next = 1'b1;

            sif.vec_req[IDX].valid      = 1'b1;
            sif.vec_req[IDX].write      = 1'b0;
            sif.vec_req[IDX].spad_addr  = vif.sched_req[IDX].spad_addr;
            sif.vec_req[IDX].num_rows   = '0;  // VM is single-row
            sif.vec_req[IDX].num_cols   = vif.sched_req[IDX].num_cols;
            sif.vec_req[IDX].row_id     = vif.sched_req[IDX].row_id;
        end

        // ── Store path ───────────────────────────────────
        if (is_store && can_accept) begin
            sif.vec_req[IDX].valid      = 1'b1;
            sif.vec_req[IDX].write      = 1'b1;
            sif.vec_req[IDX].spad_addr  = vif.sched_req[IDX].spad_addr;
            sif.vec_req[IDX].num_rows   = '0;  // VM is single-row
            sif.vec_req[IDX].num_cols   = vif.sched_req[IDX].num_cols;
            sif.vec_req[IDX].row_id     = vif.sched_req[IDX].row_id;
            sif.vec_req[IDX].wdata      = vif.vrf_store[IDX].data;
        end

        // ── Transpose Unit Push Path ──────────────────────
        if (HAS_TRANSPOSE && resp_incoming && !lq_empty && lq_is_transpose) begin
            if (tu_if.out.ready_in) begin
                tu_if.in.valid_in = 1'b1;
                tu_if.in.push_req = 1'b1;
                tu_if.in.vec_in   = sif.vec_res[IDX].rdata;
                tu_data_next      = sif.vec_res[IDX].rdata;
                lq_shift          = 1'b1;
                tu_in_flight_next = 1'b0;
                vif.status[IDX].transpose_push = 1'b1;
                if (tu_push_cnt_r == 5'd0) begin
                    tu_base_vdst_next = lq_vdst;
                end
                if (tu_push_cnt_r == 5'd31) begin
                    tu_push_cnt_next   = 5'd0;
                    tu_all_pushed_next = 1'b1;
                end else begin
                    tu_push_cnt_next = tu_push_cnt_r + 1;
                end
            end else begin
                tu_stall_scpad = 1'b1;
            end
        end

        // ── Transpose Unit Pop Initiation ─────────────────
        if (HAS_TRANSPOSE && tu_all_pushed_r && tu_if.out.ready_in) begin
            tu_if.in.pop_req   = 1'b1;
            tu_all_pushed_next = 1'b0;
            tu_popping_next    = 1'b1;
        end

        // ── Response + Writeback (Priority: Transpose Pop > Skid > Normal Bypass)
        if (HAS_TRANSPOSE && tu_popping_r && tu_if.out.valid_out) begin
            // Transposed column writeback to VRF
            vif.wb_out[IDX].load_data = tu_if.out.vec_out;
            vif.wb_out[IDX].vdst      = tu_base_vdst_r + tu_pop_cnt_r;
            vif.wb_out[IDX].valid     = 1'b1;
            tu_if.in.ready_out        = vif.wb_ready[IDX];
            vif.status[IDX].transpose_pop = 1'b1;
            if (vif.wb_ready[IDX]) begin
                if (tu_pop_cnt_r == 5'd31) begin
                    tu_pop_cnt_next  = 5'd0;
                    tu_popping_next  = 1'b0;
                    vif.status[IDX].transpose_done = 1'b1;
                end else begin
                    tu_pop_cnt_next = tu_pop_cnt_r + 1;
                end
            end
        end else if (skid_valid_r && !lq_empty && !lq_is_transpose) begin
            // ── Drain skid ───────────────────────────────
            vif.wb_out[IDX].load_data = skid_data_r;
            vif.wb_out[IDX].vdst      = lq_vdst;
            vif.wb_out[IDX].valid     = 1'b1;
            if (vif.wb_ready[IDX]) begin
                lq_shift        = 1'b1;
                skid_valid_next = 1'b0;
            end
        end else if (!skid_valid_r && resp_incoming && !lq_empty && !lq_is_transpose) begin
            // ── Bypass ───────────────────────────────────
            vif.wb_out[IDX].load_data = sif.vec_res[IDX].rdata;
            vif.wb_out[IDX].vdst      = lq_vdst;
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
        vif.status[IDX].busy            = !lq_empty || skid_valid_r || (HAS_TRANSPOSE && (tu_push_cnt_r != 0 || tu_all_pushed_r || tu_popping_r || tu_in_flight_r));
        vif.status[IDX].load_queue_full = lq_full;
        vif.status[IDX].transpose_active= HAS_TRANSPOSE && (tu_push_cnt_r != 0 || tu_all_pushed_r || tu_popping_r || tu_in_flight_r);
    end

endmodule