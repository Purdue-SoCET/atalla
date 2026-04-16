// ramulator_sv_wrapper.sv
//
// AXI4 subordinate that talks to Ramulator2 through DPI-C.
// Sits on the subordinate side of axi_bus_if.
//
// Read path has two modes depending on AR.len:
//   len == 0  — single-beat mode. Multiple ARs can be outstanding at once;
//               completions buffer up in sr_fifo (SR_DEPTH entries) so the
//               master doesn't have to drain each one before sending the next.
//   len > 0   — burst mode (FIXED/INCR/WRAP). Up to N_BURST_SLOTS bursts run
//               concurrently. Each slot has its own 16-entry ROB; beats come
//               back out on R in order per slot, with lowest-slot-first
//               arbitration across slots. Beat issuance runs for all active
//               slots every cycle so the DRAM scheduler sees maximum ILP.
//               FIXED: every beat hits the same address; ROB slots fill in arrival order.
//               INCR:  beat i → base_addr + i*size_bytes.
//               WRAP:  increments and wraps at the aligned (len+1)*size_bytes boundary.
//
// Write path: AW and W[0] must show up in the same cycle to kick off a burst.
// Remaining beats come in one per cycle. B responses buffer in b_fifo (depth
// B_DEPTH) so we don't block on the master draining them.
//
// Limitations: one outstanding write burst at a time.

`timescale 1ns / 1ps

module ramulator_sv_wrapper #(
    parameter string  CONFIG_FILE    = "ramulator_config.yaml",
    parameter int     B_DEPTH        = 4,      // B-response FIFO depth
    parameter int     SR_DEPTH       = 8192,   // single-beat R-response FIFO depth
    parameter int     N_BURST_SLOTS  = 8192,   // concurrent read burst slots
    // Optional preload — set MEM_INIT_FILE to a non-empty path and the
    // wrapper will populate functional_mem before simulation starts.
    //   "bin" — raw binary, loaded at MEM_INIT_BASE
    //   "hex" — text file, each line: <addr_hex> <data_hex>
    //   ""    — skip preload (default)
    parameter string  MEM_INIT_FILE  = "",
    parameter string  MEM_INIT_TYPE  = "",     // "bin" or "hex"
    parameter longint MEM_INIT_BASE  = 0       // base address for binary loads
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
        output longint data_out0,     // sub-beat [63:0]
        output longint data_out1,     // sub-beat [127:64]
        output longint data_out2,     // sub-beat [191:128]
        output longint data_out3,     // sub-beat [255:192]
        output int     source_id_out  // echoes the source_id from send_request
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
    int     dpi_accepted;
    int     dpi_source_id;  // source_id echoed back by ramulator_check_response
    int     beat_idx;
    longint dpi_resp;
    longint dpi_data_out0, dpi_data_out1, dpi_data_out2, dpi_data_out3; // 256-bit R beat sub-words

    // r_pending / r_reg hold the burst beat currently on the R channel.
    // Single-beat completions go directly into sr_fifo and are muxed on
    // combinatorially — r_pending is only ever set by the burst path.
    logic           r_pending;
    sub_r_channel_t r_reg;

    // Single-beat response FIFO
    sub_r_channel_t sr_fifo [SR_DEPTH];
    int             sr_cnt;
    int             sr_rd;
    int             sr_wr;
    int             sr_cnt_next;   // blocking shadow updated within cycle
    int             sr_wr_next;    // blocking shadow for sr_wr (multi-response/cycle)

    // B-response FIFO
    sub_b_channel_t b_fifo [B_DEPTH];
    int             b_cnt;
    int             b_rd;
    int             b_wr;
    int             b_cnt_next;    // blocking shadow updated within cycle

    // address → id map for single-beat reads
    logic [RID-1:0] read_mid_id [longint];

    // ----------------------------------------------------------------
    // Multi-slot read burst state
    // ----------------------------------------------------------------
    logic                slot_active      [N_BURST_SLOTS];
    longint              slot_base_addr   [N_BURST_SLOTS];
    logic [ARLEN-1:0]    slot_len         [N_BURST_SLOTS];
    logic [ARSIZE-1:0]   slot_size        [N_BURST_SLOTS];
    logic [RID-1:0]      slot_id          [N_BURST_SLOTS];
    logic [ARBURST-1:0]  slot_burst_type  [N_BURST_SLOTS];
    int                  slot_beat_issued [N_BURST_SLOTS];
    int                  slot_beat_out    [N_BURST_SLOTS];
    logic [RDATA-1:0]    slot_rob         [N_BURST_SLOTS][16]; // 256-bit per beat
    logic [15:0]         slot_rob_valid   [N_BURST_SLOTS];
    int                  slot_fixed_cnt   [N_BURST_SLOTS];

    // Slot issue-order FIFO — maintains the order in which slots were allocated
    // so burst beats are output in the same sequence the ARs were received.
    // Entries are pushed in step 3 (AR accept) and popped in step 1b (last beat out).
    int slot_order_q   [N_BURST_SLOTS];  // circular buffer of slot indices
    int slot_order_rd;                    // registered head (read pointer)
    int slot_order_wr;                    // registered tail (write pointer)
    int slot_order_cnt;                   // registered entry count
    int slot_order_cnt_nxt;              // blocking shadow for slot_order_cnt
    int slot_order_wr_nxt;               // blocking shadow for slot_order_wr

    // Blocking temps (step-local scratch — all read from old register values)
    int     free_slot;          // index of first free burst slot (-1 = all busy)
    int     resp_slot;          // slot index from dpi_source_id (-1 = single-beat)
    int     out_slot;           // slot selected for R output this cycle
    int     head_slot;          // FIFO head slot index (scratch for step 1b)
    logic   any_active;         // OR of slot_active[]

    // ----------------------------------------------------------------
    // Free-list for O(1) burst slot allocation (Fix 3)
    // ----------------------------------------------------------------
    int free_q   [N_BURST_SLOTS];  // circular queue of free slot indices
    int free_rd;                   // dequeue pointer
    int free_wr;                   // enqueue pointer
    int free_cnt;                  // number of entries (= free slots)
    // Blocking shadows committed in step 6
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

    // Merge one 8-byte sub-beat of new_data into existing using per-byte strobe.
    // With 256-bit beats each AXI W beat is split into 4 × 8-byte sub-beats;
    // this helper operates on one sub-beat at a time.
    function automatic longint apply_wstrb_sub(
        input longint      existing,   // current 8-byte value from functional_mem
        input longint      new_data,   // 8-byte slice of the incoming W beat
        input logic [7:0]  strb        // 1 bit per byte (8 bits for 8 bytes)
    );
        logic [63:0] result;
        result = existing[63:0];
        for (int i = 0; i < 8; i++) begin
            if (strb[i])
                result[8*i +: 8] = new_data[8*i +: 8];
        end
        return longint'(result);
    endfunction

    // Address for beat N of a burst (FIXED/INCR/WRAP).
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

    // Map response address back to ROB index within a burst.
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
    // r_pending (burst beat) has priority over sr_fifo (single-beat) so
    // burst beats aren't interleaved with single-beat responses mid-burst.
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
            free_q[i]          = i;  // pre-populate free-list with all slot indices
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
    // Per-cycle order (blocking temps mean order matters):
    //   0.  Scan slots → any_active, free_slot.
    //       Drain SR FIFO head (updates sr_cnt_next).
    //       Clear r_pending if no burst active and master accepted.
    //   1.  Drain up to 4 Ramulator responses; route each to its slot
    //       ROB (burst) or sr_fifo (single-beat).
    //   1b. R channel output: lowest-indexed slot with a ready beat →
    //       r_reg/r_pending. Clear r_pending if no beat ready.
    //   2.  Beat issuance: for every active slot, send its next unissued
    //       beat to Ramulator (one call per slot per cycle).
    //   3.  Accept AR.
    //       len=0 → single-beat (needs SR FIFO space).
    //       len>0 → burst (needs free slot).
    //       ar_o_ready held high when idle; deasserted on rejection or
    //       when all slots are busy.
    //   4.  Drain B FIFO head (updates b_cnt_next).
    //   5a. Accept W beat for ongoing write burst.
    //   5b. Accept AW+W[0] to start a new write burst.
    //   6.  Commit b_cnt, sr_cnt.
    //   7.  Tick Ramulator ×2 (DDR4 1600 MHz from 800 MHz SV clock).
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

            // Write-side readies pulse for one cycle on acceptance only.
            axi.aw_o_ready <= 1'b0;
            axi.w_o_ready  <= 1'b0;

            // ----------------------------------------------------------
            // 0. Slot scan; SR FIFO drain; r_pending clear
            // ----------------------------------------------------------
            sr_cnt_next        = sr_cnt;
            sr_wr_next         = sr_wr;
            slot_order_cnt_nxt = slot_order_cnt;
            slot_order_wr_nxt  = slot_order_wr;
            free_rd_nxt        = free_rd;
            free_wr_nxt        = free_wr;
            free_cnt_nxt       = free_cnt;

            // O(1) free-slot lookup and active check via free-list (Fix 3)
            any_active = (slot_order_cnt_nxt > 0);
            free_slot  = (free_cnt_nxt > 0) ? free_q[free_rd_nxt] : -1;

            // Clear r_pending once the last burst beat has been accepted
            // and no slot is still active.
            if (!any_active && r_pending && axi.r_ready)
                r_pending <= 1'b0;

            // Advance SR FIFO read pointer when the R channel is free.
            if (!r_pending && sr_cnt_next > 0 && axi.r_ready) begin
                sr_rd       <= (sr_rd + 1 == SR_DEPTH) ? 0 : sr_rd + 1;
                sr_cnt_next  = sr_cnt_next - 1;
            end

            // ----------------------------------------------------------
            // 1. Drain up to 4 Ramulator responses per SV cycle.
            //    source_id encodes the destination directly:
            //      0..N_BURST_SLOTS-1 → burst slot index
            //      N_BURST_SLOTS      → single-beat (sr_fifo)
            //    No address-range scan needed — O(1) routing per response.
            // ----------------------------------------------------------
            for (int _drain = 0; _drain < 8; _drain++) begin
                if (any_active || sr_cnt_next < SR_DEPTH) begin
                    dpi_resp = ramulator_check_response(handle,
                                   dpi_data_out0, dpi_data_out1,
                                   dpi_data_out2, dpi_data_out3,
                                   dpi_source_id);
                    if (dpi_resp !== -64'sd1) begin
                        resp_slot = dpi_source_id; // slot index, or N_BURST_SLOTS for single-beat
                        if (resp_slot >= 0 && resp_slot < N_BURST_SLOTS) begin
                            // Burst response → place in the slot's ROB.
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
                            // Pack 4 × 64-bit sub-beats into one 256-bit beat (little-endian).
                            slot_rob[resp_slot][beat_idx]       <= {dpi_data_out3, dpi_data_out2,
                                                                    dpi_data_out1, dpi_data_out0};
                            slot_rob_valid[resp_slot][beat_idx] <= 1'b1;
                            if (slot_burst_type[resp_slot] == 2'b00)
                                slot_fixed_cnt[resp_slot] <= slot_fixed_cnt[resp_slot] + 1;
                            end // beat_idx bounds check
                        end else if (sr_cnt_next < SR_DEPTH) begin
                            // Single-beat response → SR FIFO.
                            // Use sr_wr_next (blocking) so back-to-back responses
                            // within the same drain loop write to distinct slots.
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
            // 1b. R channel output: always serve the OLDEST allocated slot
            //     (FIFO head) to preserve AR issue order across slot reuse.
            //     r_pending stays set as long as we're pumping burst beats;
            //     it's cleared here when the FIFO is empty and master accepts.
            // ----------------------------------------------------------
            out_slot = -1;
            if (slot_order_cnt_nxt > 0) begin
                head_slot = slot_order_q[slot_order_rd];
                if (slot_active[head_slot] && slot_rob_valid[head_slot][slot_beat_out[head_slot]])
                    out_slot = head_slot;
            end

            if (out_slot >= 0 && (!r_pending || axi.r_ready)) begin
                // Load the next in-order beat from the head slot.
                r_reg.data  <= slot_rob[out_slot][slot_beat_out[out_slot]];
                r_reg.id    <= slot_id[out_slot][RID-1:0];
                r_reg.last  <= (slot_beat_out[out_slot] == int'(slot_len[out_slot]));
                r_reg.resp  <= R_OKAY;
                r_pending   <= 1'b1;
                slot_rob_valid[out_slot][slot_beat_out[out_slot]] <= 1'b0;
                if (slot_beat_out[out_slot] == int'(slot_len[out_slot])) begin
                    slot_active[out_slot] <= 1'b0;   // last beat — free the slot
                    // Return slot to free-list (Fix 3)
                    free_q[free_wr_nxt]  <= out_slot;
                    free_wr_nxt           = (free_wr_nxt + 1) % N_BURST_SLOTS;
                    free_cnt_nxt          = free_cnt_nxt + 1;
                    // Pop the oldest entry from the issue-order FIFO.
                    slot_order_rd      <= (slot_order_rd + 1) % N_BURST_SLOTS;
                    slot_order_cnt_nxt  = slot_order_cnt_nxt - 1;
                end
                slot_beat_out[out_slot] <= slot_beat_out[out_slot] + 1;
            end else if (out_slot < 0 && r_pending && axi.r_ready) begin
                // Master accepted the last beat and no slot has a new one ready.
                r_pending <= 1'b0;
            end

            // ----------------------------------------------------------
            // 2. Beat issuance: send the next unissued beat for every
            //    active slot. source_id = slot index so responses route
            //    back to the correct ROB without an address scan.
            // ----------------------------------------------------------
            for (int i = 0; i < N_BURST_SLOTS; i++) begin
                if (slot_active[i] && slot_beat_issued[i] <= int'(slot_len[i])) begin
                    dpi_accepted = ramulator_send_request(
                        handle,
                        burst_beat_addr(slot_base_addr[i], slot_beat_issued[i],
                                        slot_size[i], slot_len[i], slot_burst_type[i]),
                        0,          // Read
                        i,          // source_id = slot index
                        0
                    );
                    if (dpi_accepted)
                        slot_beat_issued[i] <= slot_beat_issued[i] + 1;
                end
            end

            // ----------------------------------------------------------
            // 3. Accept AR.
            //    len=0 → single-beat (sr_fifo space required).
            //    len>0 → burst (free slot required).
            //    ar_o_ready is held high when idle so the master can send
            //    back-to-back without a gap. It drops when Ramulator
            //    rejects or all slots are full.
            // ----------------------------------------------------------
            if (axi.ar_o_valid) begin
                if (axi.ar_o.len == '0) begin
                    // --- Single-beat path ---
                    // source_id = N_BURST_SLOTS (sentinel) so the response
                    // routes to sr_fifo, not a burst slot.
                    if (sr_cnt_next < SR_DEPTH) begin
                        dpi_accepted = ramulator_send_request(
                            handle,
                            longint'(axi.ar_o.addr),
                            0,                  // Read
                            N_BURST_SLOTS,      // source_id sentinel for single-beat
                            0
                        );
                        if (dpi_accepted) begin
                            axi.ar_o_ready <= 1'b1;
                            read_mid_id[longint'(axi.ar_o.addr)] = axi.ar_o.id;
                        end else begin
                            axi.ar_o_ready <= 1'b0;  // Ramulator queue full
                        end
                    end else begin
                        axi.ar_o_ready <= 1'b0;      // SR FIFO full
                    end
                end else begin
                    // --- Burst path: allocate a free slot ---
                    // source_id = free_slot index so beat-0 response routes
                    // back to the correct ROB alongside all subsequent beats.
                    if (free_slot >= 0) begin
                        dpi_accepted = ramulator_send_request(
                            handle,
                            longint'(axi.ar_o.addr),
                            0,                  // Read (beat 0)
                            free_slot,          // source_id = slot index
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
                            // Fix 2: issue remaining burst beats upfront so
                            // Ramulator sees maximum ILP without waiting a cycle
                            // per beat. Step 2 retries any that were rejected.
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
                            // Push slot into issue-order FIFO
                            slot_order_q[slot_order_wr_nxt] <= free_slot;
                            slot_order_wr_nxt                = (slot_order_wr_nxt + 1) % N_BURST_SLOTS;
                            slot_order_cnt_nxt               = slot_order_cnt_nxt + 1;
                            // Fix 3: consume slot from free-list
                            free_rd_nxt  = (free_rd_nxt + 1) % N_BURST_SLOTS;
                            free_cnt_nxt = free_cnt_nxt - 1;
                        end else begin
                            axi.ar_o_ready <= 1'b0;  // Ramulator queue full
                        end
                    end else begin
                        axi.ar_o_ready <= 1'b0;      // all slots busy
                    end
                end
            end else begin
                // No AR presented this cycle — assert ready speculatively
                // so the master sees no gap on the next valid.
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
                // Issue 4 × 8-byte sub-beat writes for the 256-bit beat.
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
            // 5b. Accept AW+W[0] → issue beat 0 and start write burst.
            // ----------------------------------------------------------
            end else if (!aw_active && axi.aw_o_valid && axi.w_o_valid
                         && b_cnt_next < B_DEPTH) begin
                wr_beat_addr = longint'(axi.aw_o.addr);
                // Issue 4 × 8-byte sub-beat writes for the 256-bit beat.
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
                        // Single-beat write — done immediately.
                        b_fifo[b_wr] <= '{id: axi.aw_o.mid_id[BID-1:0], resp: B_OKAY};
                        b_wr         <= (b_wr + 1 == B_DEPTH) ? 0 : b_wr + 1;
                        b_cnt_next    = b_cnt_next + 1;
                    end else begin
                        // Multi-beat — hold B until w_last.
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
            // 6. Commit FIFO counts
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
            // 7. Tick Ramulator ×2
            //    DDR4 memory system at 1600 MHz (clock_ratio: 1) while
            //    the frontend stays at 800 MHz (clock_ratio: 2) = SV clock.
            // ----------------------------------------------------------
            for (int _t = 0; _t < 2; _t++)
                ramulator_tick(handle);

        end
    end

endmodule
