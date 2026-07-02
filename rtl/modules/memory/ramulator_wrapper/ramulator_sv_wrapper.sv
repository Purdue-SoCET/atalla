// ramulator_sv_wrapper.sv
// Heng-I (Ivor) Chu - ivorchu@gmail.com
//
//
// AXI4 subordinate that wires the AXI bus to Ramulator2 over DPI-C.
//
// Single-beat reads (AR.len=0) queue in sr_fifo so the master can keep
// firing ARs without waiting for each one to return.
// Bursts (AR.len>0) each get a slot with a small ROB; beats come out in
// request order even if DRAM returns them out of order.
// FIXED, INCR, and WRAP burst types all work.
// Only one write burst can be in flight at a time.

`timescale 1ns / 1ps

module ramulator_sv_wrapper #(
    parameter string  CONFIG_FILE    = "ramulator_config.yaml",
    parameter int     B_DEPTH        = 4,      // write-response FIFO depth
    parameter int     SR_DEPTH       = 8192,   // single-beat read FIFO depth
    parameter int     N_BURST_SLOTS  = 8192,   // max concurrent read bursts
    // Set MEM_INIT_FILE to preload functional_mem before sim starts.
    //   bin = raw binary at MEM_INIT_BASE, hex = addr/data text pairs
    //   ""  = skip
    parameter string  MEM_INIT_FILE  = "",
    parameter string  MEM_INIT_TYPE  = "",     // "bin" or "hex"
    parameter longint MEM_INIT_BASE  = 0
)(
    axi_bus_if  axi,
    output logic init_done
);

    import axi_bus_pkg::*;

    // ----------------------------------------------------------------
    // DPI-C imports
    // ----------------------------------------------------------------
    import "DPI-C" function chandle ramulator_init(
        input string config_file
    );

    import "DPI-C" function void ramulator_set_single_beat_sentinel(
        input chandle handle,
        input int     sentinel
    );

    import "DPI-C" function int ramulator_send_request(
        input chandle handle,
        input longint addr,
        input int     req_type,
        input int     source_id,
        input longint data
    );

    import "DPI-C" function void ramulator_tick(
        input chandle handle
    );

    import "DPI-C" function longint ramulator_check_response(
        input  chandle handle,
        output longint data_out0,
        output longint data_out1,
        output longint data_out2,
        output longint data_out3,
        output int     source_id_out
    );

    import "DPI-C" function int ramulator_get_clock_ratio(
        input chandle handle
    );

    import "DPI-C" function void ramulator_finalize(
        input chandle handle
    );

    import "DPI-C" function longint ramulator_read_mem(
        input chandle handle,
        input longint addr
    );

    import "DPI-C" function longint ramulator_load_mem_bin(
        input chandle handle,
        input string  path,
        input longint base_addr
    );

    import "DPI-C" function longint ramulator_load_mem_hex(
        input chandle handle,
        input string  path
    );

    // ----------------------------------------------------------------
    // Internal state
    // ----------------------------------------------------------------
    chandle handle;
    int     clock_ratio_val; // DDR4=2, HBM=1
    int     dpi_accepted;
    int     dpi_source_id;
    int     beat_idx;
    longint dpi_resp;
    longint dpi_data_out0, dpi_data_out1, dpi_data_out2, dpi_data_out3;

    // r_pending/r_reg = whatever beat is currently on the R channel (burst path).
    // SR FIFO completions mux onto R when no burst beat is pending.
    logic           r_pending;
    sub_r_channel_t r_reg;

    // Single-beat response FIFO
    sub_r_channel_t sr_fifo [SR_DEPTH];
    int             sr_cnt;
    int             sr_rd;
    int             sr_wr;
    int             sr_cnt_next;   // blocking shadow, updated mid-cycle
    int             sr_wr_next;    // blocking shadow for wr pointer

    // Write-response FIFO
    sub_b_channel_t b_fifo [B_DEPTH];
    int             b_cnt;
    int             b_rd;
    int             b_wr;
    int             b_cnt_next;

    // address -> AXI ID, keyed on request address (single-beat reads only)
    logic [RID-1:0] read_mid_id [longint];

    // ----------------------------------------------------------------
    // Burst slot state
    // ----------------------------------------------------------------
    logic                slot_active      [N_BURST_SLOTS];
    longint              slot_base_addr   [N_BURST_SLOTS];
    logic [ARLEN-1:0]    slot_len         [N_BURST_SLOTS];
    logic [ARSIZE-1:0]   slot_size        [N_BURST_SLOTS];
    logic [RID-1:0]      slot_id          [N_BURST_SLOTS];
    logic [ARBURST-1:0]  slot_burst_type  [N_BURST_SLOTS];
    int                  slot_beat_issued [N_BURST_SLOTS];
    int                  slot_beat_out    [N_BURST_SLOTS];
    logic [RDATA-1:0]    slot_rob         [N_BURST_SLOTS][16];
    logic [15:0]         slot_rob_valid   [N_BURST_SLOTS];
    // Counts responses received for FIXED bursts — used as beat_idx.
    // Updated with blocking assign in the drain loop so multiple completions
    // arriving in the same cycle each get a different beat_idx.
    int                  slot_fixed_cnt   [N_BURST_SLOTS];

    // Tracks AR arrival order so R beats come out in the right sequence
    // even when multiple slots are active at once.
    int slot_order_q   [N_BURST_SLOTS];
    int slot_order_rd;
    int slot_order_wr;
    int slot_order_cnt;
    int slot_order_cnt_nxt;
    int slot_order_wr_nxt;

    // Per-cycle scratch — read from registered state, updated mid-cycle
    int     free_slot;
    int     resp_slot;
    int     out_slot;
    int     head_slot;
    logic   any_active;

    // ----------------------------------------------------------------
    // Free-list for slot allocation
    // Pre-populated with all slot indices so AR accept is O(1).
    // ----------------------------------------------------------------
    int free_q   [N_BURST_SLOTS];
    int free_rd;
    int free_wr;
    int free_cnt;
    int free_rd_nxt;
    int free_wr_nxt;
    int free_cnt_nxt;

    // ----------------------------------------------------------------
    // Write burst state
    // ----------------------------------------------------------------
    logic                aw_active;
    longint              aw_base_addr;
    logic [AWLEN-1:0]    aw_len_reg;
    logic [AWSIZE-1:0]   aw_size_reg;
    logic [MID_AWID-1:0] aw_id_reg;
    logic [AWBURST-1:0]  aw_burst_reg;
    int                  aw_beat;

    longint              wr_beat_addr;
    longint              wr_merged;

    // ----------------------------------------------------------------
    // Helper functions
    // ----------------------------------------------------------------

    // Read-modify-write one 8-byte sub-beat using a per-byte strobe.
    function automatic longint apply_wstrb_sub(
        input longint      existing,
        input longint      new_data,
        input logic [7:0]  strb
    );
        logic [63:0] result;
        result = existing[63:0];
        for (int i = 0; i < 8; i++) begin
            if (strb[i])
                result[8*i +: 8] = new_data[8*i +: 8];
        end
        return longint'(result);
    endfunction

    // Byte address of beat N within a burst.
    function automatic longint burst_beat_addr(
        input longint             base_addr,
        input int                 beat,
        input logic [ARSIZE-1:0]  size,
        input logic [ARLEN-1:0]   len,
        input logic [ARBURST-1:0] burst
    );
        longint size_bytes, wrap_len, wrap_mask, aligned;
        size_bytes = longint'(1 << int'(size));
        case (burst)
            2'b00:   return base_addr;                                       // FIXED
            2'b10: begin                                                     // WRAP
                wrap_len  = longint'(int'(len) + 1) * size_bytes;
                wrap_mask = wrap_len - 1;
                aligned   = base_addr & ~wrap_mask;
                return aligned + ((base_addr - aligned
                                   + longint'(beat) * size_bytes) & wrap_mask);
            end
            default: return base_addr + longint'(beat) * size_bytes;        // INCR
        endcase
    endfunction

    // Map a response address back to its ROB slot index.
    function automatic int burst_beat_idx(
        input longint             resp_addr,
        input longint             base_addr,
        input logic [ARSIZE-1:0]  size,
        input logic [ARLEN-1:0]   len,
        input logic [ARBURST-1:0] burst,
        input int                 fixed_cnt
    );
        longint size_bytes, wrap_len, wrap_mask, aligned, start_off;
        size_bytes = longint'(1 << int'(size));
        case (burst)
            2'b00:   return fixed_cnt;                                       // FIXED
            2'b10: begin                                                     // WRAP
                wrap_len  = longint'(int'(len) + 1) * size_bytes;
                wrap_mask = wrap_len - 1;
                aligned   = base_addr & ~wrap_mask;
                start_off = base_addr & wrap_mask;
                return int'(((resp_addr - aligned - start_off + wrap_len)
                             & wrap_mask) / size_bytes);
            end
            default: return int'((resp_addr - base_addr) / size_bytes);     // INCR
        endcase
    endfunction

    // ----------------------------------------------------------------
    // Combinatorial outputs
    // ----------------------------------------------------------------
    // Burst beats take priority over sr_fifo so single-beats don't
    // slip in between beats of an active burst.
    assign axi.r_valid   = r_pending || (sr_cnt > 0);
    assign axi.r_i       = r_pending ? r_reg : sr_fifo[sr_rd];
    assign axi.b_i_valid = (b_cnt > 0);
    assign axi.b_i       = b_fifo[b_rd];

    // ----------------------------------------------------------------
    // Initialization
    // ----------------------------------------------------------------
    initial begin
        handle    = null;
        init_done = 1'b0;
        r_pending = 1'b0;
        b_cnt = 0; b_rd = 0; b_wr = 0;
        aw_active    = 1'b0;
        aw_burst_reg = 2'b01;
        sr_cnt = 0; sr_rd = 0; sr_wr = 0;
        for (int i = 0; i < N_BURST_SLOTS; i++) begin
            slot_active[i]     = 1'b0;
            slot_rob_valid[i]  = '0;
            slot_burst_type[i] = 2'b01;
            slot_fixed_cnt[i]  = 0;
            free_q[i]          = i;
        end
        slot_order_rd  = 0;
        slot_order_wr  = 0;
        slot_order_cnt = 0;
        free_rd  = 0;
        free_wr  = 0;
        free_cnt = N_BURST_SLOTS;

        wait (axi.nRST === 1'b0);
        wait (axi.nRST === 1'b1);
        @(posedge axi.CLK);

        handle = ramulator_init(CONFIG_FILE);
        if (handle == null)
            $fatal(1, "[ramulator_sv_wrapper] ramulator_init() returned null. Config: %s", CONFIG_FILE);

        ramulator_set_single_beat_sentinel(handle, N_BURST_SLOTS);

        clock_ratio_val = ramulator_get_clock_ratio(handle);

        if (MEM_INIT_FILE != "") begin
            longint n_loaded;
            if (MEM_INIT_TYPE == "bin") begin
                n_loaded = ramulator_load_mem_bin(handle, MEM_INIT_FILE, MEM_INIT_BASE);
                if (n_loaded < 0)
                    $fatal(1, "[ramulator_sv_wrapper] Failed to load binary file: %s", MEM_INIT_FILE);
                $display("[ramulator_sv_wrapper] Loaded %0d beats from binary '%s' at base 0x%08h",
                         n_loaded, MEM_INIT_FILE, MEM_INIT_BASE);
            end else if (MEM_INIT_TYPE == "hex") begin
                n_loaded = ramulator_load_mem_hex(handle, MEM_INIT_FILE);
                if (n_loaded < 0)
                    $fatal(1, "[ramulator_sv_wrapper] Failed to load hex file: %s", MEM_INIT_FILE);
                $display("[ramulator_sv_wrapper] Loaded %0d entries from hex '%s'",
                         n_loaded, MEM_INIT_FILE);
            end else begin
                $fatal(1, "[ramulator_sv_wrapper] MEM_INIT_FILE set but MEM_INIT_TYPE is not 'bin' or 'hex': '%s'",
                       MEM_INIT_TYPE);
            end
        end

        init_done = 1'b1;
        $display("[ramulator_sv_wrapper] Init OK (config=%s)", CONFIG_FILE);
    end

    // ----------------------------------------------------------------
    // Finalize on simulation exit
    // ----------------------------------------------------------------
    /*final begin
        if (handle != null) begin
            ramulator_finalize(handle);
            $display("[ramulator_sv_wrapper] Finalized.");
        end
    end*/

    // ----------------------------------------------------------------
    // Clocked logic
    //
    // Step order matters — blocking assigns are used throughout so
    // later steps see values updated by earlier ones.
    //
    //   0.  Snapshot blocking vars; check which slots are active/free.
    //   1.  Drain up to 8 Ramulator completions per cycle into ROBs
    //       or sr_fifo, routed by source_id.
    //   1b. Push the next ready beat from the head slot onto R.
    //   2.  Issue any un-sent burst beats to Ramulator.
    //   3.  Accept AR (single-beat or burst).
    //   4.  Pop B FIFO if master is ready.
    //   5a. Accept W beat for an ongoing write burst.
    //   5b. Accept AW+W[0] to start a new write burst.
    //   6.  Commit blocking shadows to registers.
    //   7.  Tick Ramulator.
    // ----------------------------------------------------------------
    always @(posedge axi.CLK or negedge axi.nRST) begin
        if (!axi.nRST) begin
            axi.ar_o_ready <= 1'b0;
            axi.aw_o_ready <= 1'b0;
            axi.w_o_ready  <= 1'b0;
            r_pending      <= 1'b0;
            r_reg          <= '0;
            b_cnt <= 0; b_rd <= 0; b_wr <= 0;
            for (int i = 0; i < N_BURST_SLOTS; i++) begin
                slot_active[i]    <= 1'b0;
                slot_rob_valid[i] <= '0;
                free_q[i]         <= i;
            end
            slot_order_rd  <= 0;
            slot_order_wr  <= 0;
            slot_order_cnt <= 0;
            free_rd  <= 0;
            free_wr  <= 0;
            free_cnt <= N_BURST_SLOTS;
            aw_active    <= 1'b0;
            aw_burst_reg <= 2'b01;
            sr_cnt <= 0; sr_rd <= 0; sr_wr <= 0;

        end else if (init_done) begin

            // write-side readies pulse for one cycle only
            axi.aw_o_ready <= 1'b0;
            axi.w_o_ready  <= 1'b0;

            // ----------------------------------------------------------
            // 0. Snapshot blocking vars
            // ----------------------------------------------------------
            sr_cnt_next        = sr_cnt;
            sr_wr_next         = sr_wr;
            slot_order_cnt_nxt = slot_order_cnt;
            slot_order_wr_nxt  = slot_order_wr;
            free_rd_nxt        = free_rd;
            free_wr_nxt        = free_wr;
            free_cnt_nxt       = free_cnt;

            any_active = (slot_order_cnt_nxt > 0);
            free_slot  = (free_cnt_nxt > 0) ? free_q[free_rd_nxt] : -1;

            if (!any_active && r_pending && axi.r_ready)
                r_pending <= 1'b0;

            // advance SR FIFO read pointer once master takes the beat
            if (!r_pending && sr_cnt_next > 0 && axi.r_ready) begin
                sr_rd       <= (sr_rd + 1 == SR_DEPTH) ? 0 : sr_rd + 1;
                sr_cnt_next  = sr_cnt_next - 1;
            end

            // ----------------------------------------------------------
            // 1. Drain Ramulator completions.
            //    source_id tells us where each response goes:
            //      0..N_BURST_SLOTS-1  -> burst slot ROB
            //      N_BURST_SLOTS       -> sr_fifo (single-beat)
            // ----------------------------------------------------------
            for (int _drain = 0; _drain < 8; _drain++) begin
                if (any_active || sr_cnt_next < SR_DEPTH) begin
                    dpi_resp = ramulator_check_response(handle,
                                   dpi_data_out0, dpi_data_out1,
                                   dpi_data_out2, dpi_data_out3,
                                   dpi_source_id);
                    if (dpi_resp !== -64'sd1) begin
                        resp_slot = dpi_source_id;
                        if (resp_slot >= 0 && resp_slot < N_BURST_SLOTS) begin
                            beat_idx = burst_beat_idx(
                                dpi_resp,
                                slot_base_addr[resp_slot],
                                slot_size[resp_slot],
                                slot_len[resp_slot],
                                slot_burst_type[resp_slot],
                                slot_fixed_cnt[resp_slot]
                            );
                            if (beat_idx < 0 || beat_idx >= 16) begin
                                $display("[wrapper] ERROR: beat_idx=%0d OOB for slot=%0d resp=0x%h base=0x%h",
                                         beat_idx, resp_slot, dpi_resp, slot_base_addr[resp_slot]);
                            end else begin
                            slot_rob[resp_slot][beat_idx]       <= {dpi_data_out3, dpi_data_out2,
                                                                    dpi_data_out1, dpi_data_out0};
                            slot_rob_valid[resp_slot][beat_idx] <= 1'b1;
                            // blocking assign so the next iteration sees the updated count
                            if (slot_burst_type[resp_slot] == 2'b00)
                                slot_fixed_cnt[resp_slot] = slot_fixed_cnt[resp_slot] + 1;
                            end
                        end else if (sr_cnt_next < SR_DEPTH) begin
                            // use sr_wr_next so multiple completions this cycle
                            // land in different FIFO entries
                            sr_fifo[sr_wr_next].data <= {dpi_data_out3, dpi_data_out2,
                                                         dpi_data_out1, dpi_data_out0};
                            sr_fifo[sr_wr_next].id   <= read_mid_id[dpi_resp][RID-1:0];
                            sr_fifo[sr_wr_next].last <= 1'b1;
                            sr_fifo[sr_wr_next].resp <= R_OKAY;
                            sr_wr_next               = (sr_wr_next + 1 == SR_DEPTH) ? 0 : sr_wr_next + 1;
                            sr_cnt_next              = sr_cnt_next + 1;
                        end
                    end
                end
            end

            // ----------------------------------------------------------
            // 1b. Output R beats from the oldest active slot (FIFO head).
            //     Serving head-first keeps AXI R ordering consistent with
            //     the order ARs were received.
            // ----------------------------------------------------------
            out_slot = -1;
            if (slot_order_cnt_nxt > 0) begin
                head_slot = slot_order_q[slot_order_rd];
                if (slot_active[head_slot] && slot_rob_valid[head_slot][slot_beat_out[head_slot]])
                    out_slot = head_slot;
            end

            if (out_slot >= 0 && (!r_pending || axi.r_ready)) begin
                r_reg.data  <= slot_rob[out_slot][slot_beat_out[out_slot]];
                r_reg.id    <= slot_id[out_slot][RID-1:0];
                r_reg.last  <= (slot_beat_out[out_slot] == int'(slot_len[out_slot]));
                r_reg.resp  <= R_OKAY;
                r_pending   <= 1'b1;
                slot_rob_valid[out_slot][slot_beat_out[out_slot]] <= 1'b0;
                if (slot_beat_out[out_slot] == int'(slot_len[out_slot])) begin
                    slot_active[out_slot] <= 1'b0;
                    free_q[free_wr_nxt]  <= out_slot;
                    free_wr_nxt           = (free_wr_nxt + 1) % N_BURST_SLOTS;
                    free_cnt_nxt          = free_cnt_nxt + 1;
                    slot_order_rd      <= (slot_order_rd + 1) % N_BURST_SLOTS;
                    slot_order_cnt_nxt  = slot_order_cnt_nxt - 1;
                end
                slot_beat_out[out_slot] <= slot_beat_out[out_slot] + 1;
            end else if (out_slot < 0 && r_pending && axi.r_ready) begin
                r_pending <= 1'b0;
            end

            // ----------------------------------------------------------
            // 2. Issue un-sent burst beats to Ramulator.
            //    source_id = slot index so responses route back correctly.
            // ----------------------------------------------------------
            for (int i = 0; i < N_BURST_SLOTS; i++) begin
                if (slot_active[i] && slot_beat_issued[i] <= int'(slot_len[i])) begin
                    dpi_accepted = ramulator_send_request(
                        handle,
                        burst_beat_addr(slot_base_addr[i], slot_beat_issued[i],
                                        slot_size[i], slot_len[i], slot_burst_type[i]),
                        0,
                        i,
                        0
                    );
                    if (dpi_accepted)
                        slot_beat_issued[i] <= slot_beat_issued[i] + 1;
                end
            end

            // ----------------------------------------------------------
            // 3. Accept AR.
            //    len=0 -> single-beat, goes to sr_fifo.
            //    len>0 -> burst, needs a free slot.
            //    ar_o_ready stays high when idle; drops on queue full or
            //    when all slots are busy.
            // ----------------------------------------------------------
            if (axi.ar_o_valid) begin
                if (axi.ar_o.len == '0) begin
                    // single-beat: sentinel source_id so it routes to sr_fifo
                    if (sr_cnt_next < SR_DEPTH) begin
                        dpi_accepted = ramulator_send_request(
                            handle,
                            longint'(axi.ar_o.addr),
                            0,
                            N_BURST_SLOTS,
                            0
                        );
                        if (dpi_accepted) begin
                            axi.ar_o_ready <= 1'b1;
                            read_mid_id[longint'(axi.ar_o.addr)] = axi.ar_o.id;
                        end else begin
                            axi.ar_o_ready <= 1'b0;
                        end
                    end else begin
                        axi.ar_o_ready <= 1'b0;
                    end
                end else begin
                    // burst: allocate a slot and fire beat 0
                    if (free_slot >= 0) begin
                        dpi_accepted = ramulator_send_request(
                            handle,
                            longint'(axi.ar_o.addr),
                            0,
                            free_slot,
                            0
                        );
                        if (dpi_accepted) begin
                            axi.ar_o_ready <= 1'b1;
                            slot_active[free_slot]     <= 1'b1;
                            slot_base_addr[free_slot]  <= longint'(axi.ar_o.addr);
                            slot_len[free_slot]        <= axi.ar_o.len;
                            slot_size[free_slot]       <= axi.ar_o.size;
                            slot_id[free_slot]         <= axi.ar_o.id;
                            slot_burst_type[free_slot] <= axi.ar_o.burst;
                            slot_beat_out[free_slot]   <= 0;
                            slot_rob_valid[free_slot]  <= '0;
                            slot_fixed_cnt[free_slot]  <= 0;
                            // fire remaining beats immediately so Ramulator
                            // sees the full burst up front; step 2 retries any rejected ones
                            begin : ar_upfront_issue
                                int _next_issued;
                                _next_issued = 1;
                                for (int _b = 1; _b <= int'(axi.ar_o.len); _b++) begin
                                    if (ramulator_send_request(handle,
                                            burst_beat_addr(longint'(axi.ar_o.addr), _b,
                                                            axi.ar_o.size, axi.ar_o.len,
                                                            axi.ar_o.burst),
                                            0, free_slot, 0))
                                        _next_issued = _b + 1;
                                    else
                                        break;
                                end
                                slot_beat_issued[free_slot] <= _next_issued;
                            end
                            slot_order_q[slot_order_wr_nxt] <= free_slot;
                            slot_order_wr_nxt                = (slot_order_wr_nxt + 1) % N_BURST_SLOTS;
                            slot_order_cnt_nxt               = slot_order_cnt_nxt + 1;
                            free_rd_nxt  = (free_rd_nxt + 1) % N_BURST_SLOTS;
                            free_cnt_nxt = free_cnt_nxt - 1;
                        end else begin
                            axi.ar_o_ready <= 1'b0;
                        end
                    end else begin
                        axi.ar_o_ready <= 1'b0;
                    end
                end
            end else begin
                // keep ready high when idle so there's no gap before the next AR
                axi.ar_o_ready <= (free_cnt_nxt > 0) && (sr_cnt_next < SR_DEPTH);
            end

            // ----------------------------------------------------------
            // 4. Pop B FIFO head if master is ready.
            // ----------------------------------------------------------
            b_cnt_next = b_cnt;
            if (b_cnt_next > 0 && axi.b_i_ready) begin
                b_rd       <= (b_rd + 1 == B_DEPTH) ? 0 : b_rd + 1;
                b_cnt_next  = b_cnt_next - 1;
            end

            // ----------------------------------------------------------
            // 5a. Accept W beat for an ongoing write burst.
            // ----------------------------------------------------------
            if (aw_active && axi.w_o_valid) begin
                wr_beat_addr = burst_beat_addr(aw_base_addr, aw_beat,
                                               aw_size_reg, aw_len_reg, aw_burst_reg);
                // split the 256-bit beat into four 8-byte sub-beat writes
                dpi_accepted = 1;
                for (int _sb = 0; _sb < 4; _sb++) begin
                    wr_merged = (axi.w_o.strb[8*_sb +: 8] == 8'hFF)
                                ? longint'(axi.w_o.data[64*_sb +: 64])
                                : apply_wstrb_sub(
                                      ramulator_read_mem(handle, wr_beat_addr + _sb * 8),
                                      longint'(axi.w_o.data[64*_sb +: 64]),
                                      axi.w_o.strb[8*_sb +: 8]);
                    if (!ramulator_send_request(handle, wr_beat_addr + _sb * 8,
                                                1, int'(aw_id_reg), wr_merged))
                        dpi_accepted = 0;
                end
                if (dpi_accepted) begin
                    axi.w_o_ready <= 1'b1;
                    aw_beat       <= aw_beat + 1;
                    if (axi.w_o.last) begin
                        b_fifo[b_wr] <= '{id: aw_id_reg[BID-1:0], resp: B_OKAY};
                        b_wr         <= (b_wr + 1 == B_DEPTH) ? 0 : b_wr + 1;
                        b_cnt_next    = b_cnt_next + 1;
                        aw_active    <= 1'b0;
                    end
                end

            // ----------------------------------------------------------
            // 5b. Accept AW+W[0] to start a new write burst.
            // ----------------------------------------------------------
            end else if (!aw_active && axi.aw_o_valid && axi.w_o_valid
                         && b_cnt_next < B_DEPTH) begin
                wr_beat_addr = longint'(axi.aw_o.addr);
                dpi_accepted = 1;
                for (int _sb = 0; _sb < 4; _sb++) begin
                    wr_merged = (axi.w_o.strb[8*_sb +: 8] == 8'hFF)
                                ? longint'(axi.w_o.data[64*_sb +: 64])
                                : apply_wstrb_sub(
                                      ramulator_read_mem(handle, wr_beat_addr + _sb * 8),
                                      longint'(axi.w_o.data[64*_sb +: 64]),
                                      axi.w_o.strb[8*_sb +: 8]);
                    if (!ramulator_send_request(handle, wr_beat_addr + _sb * 8,
                                                1, int'(axi.aw_o.mid_id), wr_merged))
                        dpi_accepted = 0;
                end
                if (dpi_accepted) begin
                    axi.aw_o_ready <= 1'b1;
                    axi.w_o_ready  <= 1'b1;
                    if (axi.w_o.last) begin
                        b_fifo[b_wr] <= '{id: axi.aw_o.mid_id[BID-1:0], resp: B_OKAY};
                        b_wr         <= (b_wr + 1 == B_DEPTH) ? 0 : b_wr + 1;
                        b_cnt_next    = b_cnt_next + 1;
                    end else begin
                        aw_base_addr <= longint'(axi.aw_o.addr);
                        aw_len_reg   <= axi.aw_o.len;
                        aw_size_reg  <= axi.aw_o.size;
                        aw_id_reg    <= axi.aw_o.mid_id;
                        aw_burst_reg <= axi.aw_o.burst;
                        aw_beat      <= 1;
                        aw_active    <= 1'b1;
                    end
                end
            end

            // ----------------------------------------------------------
            // 6. Commit blocking shadows
            // ----------------------------------------------------------
            b_cnt          <= b_cnt_next;
            sr_cnt         <= sr_cnt_next;
            sr_wr          <= sr_wr_next;
            slot_order_cnt <= slot_order_cnt_nxt;
            slot_order_wr  <= slot_order_wr_nxt;
            free_rd        <= free_rd_nxt;
            free_wr        <= free_wr_nxt;
            free_cnt       <= free_cnt_nxt;

            // ----------------------------------------------------------
            // 7. Tick Ramulator
            // ----------------------------------------------------------
            for (int _t = 0; _t < 2; _t++)
                ramulator_tick(handle);

        end
    end

endmodule
