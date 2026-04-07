// ramulator_sv_wrapper.sv
//
// AXI4 subordinate that talks to Ramulator2 through DPI-C.
// Sits on the subordinate side of axi_bus_if.
//
// Read path has two modes depending on AR.len:
//   len == 0  — single-beat mode. Multiple ARs can be outstanding at once;
//               completions buffer up in sr_fifo (SR_DEPTH entries) so the
//               master doesn't have to drain each one before sending the next.
//   len > 0   — burst mode (FIXED/INCR/WRAP). ar_active gates these so only
//               one burst runs at a time. Beats fan out to a 16-entry ROB and
//               come back out on R in order with the correct last flag set.
//               FIXED: every beat hits the same address; ROB slots fill in arrival order.
//               INCR:  beat i → base_addr + i*size_bytes.
//               WRAP:  increments and wraps at the aligned (len+1)*size_bytes boundary.
//
// Write path: AW and W[0] must show up in the same cycle to kick off a burst.
// Remaining beats come in one per cycle. B responses buffer in b_fifo (depth
// B_DEPTH) so we don't block on the master draining them.
//
// Limitations: one outstanding write burst at a time; one outstanding read
// burst (len > 0) at a time.

`timescale 1ns / 1ps

module ramulator_sv_wrapper #(
    parameter string CONFIG_FILE  = "ramulator_config.yaml",
    parameter int    B_DEPTH      = 4,      // B-response FIFO depth
    parameter int    SR_DEPTH     = 16,     // single-beat R-response FIFO depth
    // Optional preload — set MEM_INIT_FILE to a non-empty path and the
    // wrapper will populate functional_mem before simulation starts.
    //   "bin" — raw binary, loaded at MEM_INIT_BASE
    //   "hex" — text file, each line: <addr_hex> <data_hex>
    //   ""    — skip preload (default)
    parameter string MEM_INIT_FILE = "",
    parameter string MEM_INIT_TYPE = "",    // "bin" or "hex"
    parameter longint MEM_INIT_BASE = 0     // base address for binary loads
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
        output longint data_out
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
    int     beat_idx;       // blocking temp for ROB index calculation
    longint dpi_resp;
    longint dpi_data_out;

    // burst path drives r_reg; single-beat completions go straight to sr_fifo
    logic           r_pending;
    sub_r_channel_t r_reg;

    // single-beat response FIFO — lets multiple reads be outstanding at once
    sub_r_channel_t sr_fifo [SR_DEPTH];
    int             sr_cnt;      // entries currently in sr_fifo
    int             sr_rd;       // read  pointer
    int             sr_wr;       // write pointer
    int             sr_cnt_next; // blocking shadow of sr_cnt (same idea as b_cnt_next)

    // B-response FIFO
    sub_b_channel_t b_fifo [B_DEPTH];
    int             b_cnt;
    int             b_rd;
    int             b_wr;
    int             b_cnt_next;

    // address → id map for single-beat reads so we know which ID to return
    logic [RID-1:0] read_mid_id [longint];

    // --- Multi-beat read burst state (len > 0 only) ---
    logic                ar_active;       // burst in progress
    longint              ar_base_addr;
    logic [ARLEN-1:0]    ar_len_reg;      // burst length (beats - 1)
    logic [ARSIZE-1:0]   ar_size_reg;     // beat size (log2 bytes)
    logic [RID-1:0]      ar_id_reg;       // ID for all beats in burst
    int                  ar_beat_issued;  // next beat index to issue to Ramulator
    int                  ar_beat_out;     // next beat index to output on R channel
    longint              ar_rob [16];     // reorder buffer (max 16 beats, ARLEN=4)
    logic [15:0]         ar_rob_valid;    // valid flags for ROB slots
    logic [ARBURST-1:0]  ar_burst_reg;    // burst type for active read burst
    int                  ar_fixed_cnt;    // ROB slot counter for FIXED read bursts

    // --- Write burst state ---
    logic                aw_active;       // multi-beat W burst in progress
    longint              aw_base_addr;
    logic [AWLEN-1:0]    aw_len_reg;
    logic [AWSIZE-1:0]   aw_size_reg;
    logic [MID_AWID-1:0] aw_id_reg;
    logic [AWBURST-1:0]  aw_burst_reg;    // burst type for active write burst
    int                  aw_beat;         // next W beat index (beat 0 already sent)

    // Blocking temps for write masking (used inside always block)
    longint              wr_beat_addr;
    longint              wr_merged;

    // Merge new_data into existing using strb — strb[i]=1 takes the new byte,
    // strb[i]=0 keeps whatever was there before.
    function automatic longint apply_wstrb(
        input longint           existing,
        input logic [WDATA-1:0] new_data,
        input logic [WSTRB-1:0] strb
    );
        logic [WDATA-1:0] result;
        result = WDATA'(existing);
        for (int i = 0; i < WSTRB; i++) begin
            if (strb[i])
                result[8*i +: 8] = new_data[8*i +: 8];
        end
        return longint'(result);
    endfunction

    // Address for beat N of a burst (FIXED/INCR/WRAP).
    // burst_beat_idx is the inverse — maps a response address back to the ROB
    // slot it belongs to. FIXED always returns the same address so we use
    // fixed_cnt to assign slots in arrival order instead.
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
    // Burst path gets priority — we don't want burst beats interleaved with
    // sr_fifo drain on the R channel.
    assign axi.r_valid = r_pending || (sr_cnt > 0);
    assign axi.r_i       = r_pending ? r_reg : sr_fifo[sr_rd];
    assign axi.b_i_valid = (b_cnt > 0);
    assign axi.b_i       = b_fifo[b_rd];

    // ----------------------------------------------------------------
    // Initialization
    // ----------------------------------------------------------------
    initial begin
        handle       = null;
        init_done    = 1'b0;
        r_pending    = 1'b0;
        b_cnt        = 0;
        b_rd         = 0;
        b_wr         = 0;
        ar_active    = 1'b0;
        ar_rob_valid = '0;
        ar_burst_reg = 2'b01;
        ar_fixed_cnt = 0;
        aw_active    = 1'b0;
        aw_burst_reg = 2'b01;
        sr_cnt       = 0;
        sr_rd        = 0;
        sr_wr        = 0;

        wait (axi.nRST === 1'b0);
        wait (axi.nRST === 1'b1);
        @(posedge axi.CLK);

        handle = ramulator_init(CONFIG_FILE);
        if (handle == null)
            $fatal(1, "[ramulator_sv_wrapper] ramulator_init() returned null. Config: %s",CONFIG_FILE);

        // pre-populate functional_mem if a file was given
        if (MEM_INIT_FILE != "") begin
            longint n_loaded;
            if (MEM_INIT_TYPE == "bin") begin
                n_loaded = ramulator_load_mem_bin(handle, MEM_INIT_FILE, MEM_INIT_BASE);
                if (n_loaded < 0)
                    $fatal(1, "[ramulator_sv_wrapper] Failed to load binary file: %s",
                           MEM_INIT_FILE);
                $display("[ramulator_sv_wrapper] Loaded %0d beats from binary '%s' at base 0x%08h",
                         n_loaded, MEM_INIT_FILE, MEM_INIT_BASE);
            end else if (MEM_INIT_TYPE == "hex") begin
                n_loaded = ramulator_load_mem_hex(handle, MEM_INIT_FILE);
                if (n_loaded < 0)
                    $fatal(1, "[ramulator_sv_wrapper] Failed to load hex file: %s",
                           MEM_INIT_FILE);
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
    // Per-cycle order (matters for the blocking variables):
    //   0.  Drain SR FIFO head → R channel  (updates sr_cnt_next)
    //   1.  check_response → ROB (burst) or sr_fifo (single-beat)
    //   1b. Drive R channel from ROB in order  [burst only]
    //   2.  Issue next beat to Ramulator        [burst only]
    //   3.  Accept AR (len=0 → sr_fifo path; len>0 → ROB path)
    //   4.  Drain B FIFO head (updates b_cnt_next)
    //   5a. Accept W beat for ongoing write burst  OR
    //   5b. Accept AW+W[0] to start a new write burst
    //   6.  Commit b_cnt, sr_cnt
    //   7.  Tick Ramulator
    // ----------------------------------------------------------------
    always @(posedge axi.CLK or negedge axi.nRST) begin
        if (!axi.nRST) begin
            axi.ar_o_ready <= 1'b0;
            axi.aw_o_ready <= 1'b0;
            axi.w_o_ready  <= 1'b0;
            r_pending      <= 1'b0;
            r_reg          <= '0;
            b_cnt          <= 0;
            b_rd           <= 0;
            b_wr           <= 0;
            ar_active      <= 1'b0;
            ar_rob_valid   <= '0;
            ar_burst_reg   <= 2'b01;
            ar_fixed_cnt   <= 0;
            aw_active      <= 1'b0;
            aw_burst_reg   <= 2'b01;
            sr_cnt         <= 0;
            sr_rd          <= 0;
            sr_wr          <= 0;

        end else if (init_done) begin

            // Defaults: ready pulses for one cycle only
            axi.ar_o_ready <= 1'b0;
            axi.aw_o_ready <= 1'b0;
            axi.w_o_ready  <= 1'b0;

            // ----------------------------------------------------------
            // 0. Init sr_cnt_next; drain SR FIFO / clear r_pending
            // ----------------------------------------------------------
            sr_cnt_next = sr_cnt;

            if (!ar_active && r_pending && axi.r_ready)
                r_pending <= 1'b0;

            if (!r_pending && sr_cnt_next > 0 && axi.r_ready) begin
                sr_rd       <= (sr_rd + 1 == SR_DEPTH) ? 0 : sr_rd + 1;
                sr_cnt_next  = sr_cnt_next - 1;
            end

            // ----------------------------------------------------------
            // 1. Drain one Ramulator response.
            //    Burst path: always drain so the queue doesn't back up under
            //    R backpressure; result goes into the ROB.
            //    Single-beat path: gated on SR FIFO space; result pushed to sr_fifo.
            // ----------------------------------------------------------
            if (ar_active || sr_cnt_next < SR_DEPTH) begin
                dpi_resp = ramulator_check_response(handle, dpi_data_out);
                 if (dpi_resp !== -64'sd1) begin
                    if (ar_active) begin
                        // drop into the ROB; step 1b will drain it in order
                        beat_idx = burst_beat_idx(dpi_resp, ar_base_addr,
                                                  ar_size_reg, ar_len_reg,
                                                  ar_burst_reg, ar_fixed_cnt);
                        ar_rob[beat_idx]       <= dpi_data_out;
                        ar_rob_valid[beat_idx] <= 1'b1;
                        if (ar_burst_reg == 2'b00)
                            ar_fixed_cnt <= ar_fixed_cnt + 1;
                    end else begin
                        // Single-beat: push response into SR FIFO
                        sr_fifo[sr_wr].data <= dpi_data_out[RDATA-1:0];
                        sr_fifo[sr_wr].id   <= read_mid_id[dpi_resp][RID-1:0];
                        sr_fifo[sr_wr].last <= 1'b1;
                        sr_fifo[sr_wr].resp <= R_OKAY;
                        sr_wr               <= (sr_wr + 1 == SR_DEPTH) ? 0 : sr_wr + 1;
                        sr_cnt_next          = sr_cnt_next + 1;
                    end
                end
            end

            // ----------------------------------------------------------
            // 1b. Drive R from ROB in order. ar_rob_valid is NB so there's
            //     at most 1 cycle of extra latency from response arrival to output.
            // ----------------------------------------------------------
            if (ar_active) begin
                if (!r_pending || axi.r_ready) begin
                    if (ar_rob_valid[ar_beat_out]) begin
                        r_reg.data  <= ar_rob[ar_beat_out][RDATA-1:0];
                        r_reg.id    <= ar_id_reg[RID-1:0];
                        r_reg.last  <= (ar_beat_out == int'(ar_len_reg));
                        r_reg.resp  <= R_OKAY;
                        r_pending   <= 1'b1;
                        ar_rob_valid[ar_beat_out] <= 1'b0;
                        if (ar_beat_out == int'(ar_len_reg))
                            ar_active <= 1'b0;
                        ar_beat_out <= ar_beat_out + 1;
                    end else begin
                        if (r_pending && axi.r_ready)
                            r_pending <= 1'b0;
                    end
                end
            end

            // ----------------------------------------------------------
            // 2. Feed the next burst beat to Ramulator (one per cycle, retry if stalled).
            // ----------------------------------------------------------
            if (ar_active && ar_beat_issued <= int'(ar_len_reg)) begin
                dpi_accepted = ramulator_send_request(
                    handle,
                    burst_beat_addr(ar_base_addr, ar_beat_issued,
                                    ar_size_reg, ar_len_reg, ar_burst_reg),
                    0,                      // Read
                    int'(ar_id_reg),
                    0
                );
                if (dpi_accepted)
                    ar_beat_issued <= ar_beat_issued + 1;
            end

            // ----------------------------------------------------------
            // 3. Accept AR. Both paths gate on !ar_active so only one burst
            //    runs at a time; single-beat ARs are fine once ar_active clears.
            // ----------------------------------------------------------
            if (axi.ar_o_valid && !ar_active) begin
                dpi_accepted = ramulator_send_request(
                    handle,
                    longint'(axi.ar_o.addr),
                    0,                      // Read
                    int'(axi.ar_o.id),
                    0
                );
                if (dpi_accepted) begin
                    axi.ar_o_ready <= 1'b1;
                    if (axi.ar_o.len == '0) begin
                        // single-beat — just stash the ID for when the response comes back
                        read_mid_id[longint'(axi.ar_o.addr)] = axi.ar_o.id;
                    end else begin
                        // multi-beat burst — spin up burst state
                        ar_base_addr   <= longint'(axi.ar_o.addr);
                        ar_len_reg     <= axi.ar_o.len;
                        ar_size_reg    <= axi.ar_o.size;
                        ar_id_reg      <= axi.ar_o.id;
                        ar_burst_reg   <= axi.ar_o.burst;
                        ar_beat_issued <= 1;
                        ar_beat_out    <= 0;
                        ar_rob_valid   <= '0;
                        ar_fixed_cnt   <= 0;
                        ar_active      <= 1'b1;
                    end
                end
            end

            // ----------------------------------------------------------
            // 4. Pop B FIFO head if master is ready. b_cnt_next is blocking
            //    so step 5 sees the updated count when checking FIFO space.
            // ----------------------------------------------------------
            b_cnt_next = b_cnt;

            if (b_cnt_next > 0 && axi.b_i_ready) begin
                b_rd       <= (b_rd + 1 == B_DEPTH) ? 0 : b_rd + 1;
                b_cnt_next = b_cnt_next - 1;
            end

            // ----------------------------------------------------------
            // 5a. Accept W beat for an ongoing write burst.
            //     Read-modify-write via ramulator_read_mem before sending.
            // ----------------------------------------------------------
            if (aw_active && axi.w_o_valid) begin
                wr_beat_addr = burst_beat_addr(aw_base_addr, aw_beat,
                                               aw_size_reg, aw_len_reg, aw_burst_reg);
                wr_merged    = apply_wstrb(ramulator_read_mem(handle, wr_beat_addr),
                                           axi.w_o.data, axi.w_o.strb);
                dpi_accepted = ramulator_send_request(
                    handle,
                    wr_beat_addr,
                    1,                      // Write
                    int'(aw_id_reg),
                    wr_merged
                );
                if (dpi_accepted) begin
                    axi.w_o_ready <= 1'b1;
                    aw_beat       <= aw_beat + 1;
                    if (axi.w_o.last) begin
                        b_fifo[b_wr] <= '{id: aw_id_reg[BID-1:0], resp: B_OKAY};
                        b_wr         <= (b_wr + 1 == B_DEPTH) ? 0 : b_wr + 1;
                        b_cnt_next   = b_cnt_next + 1;
                        aw_active    <= 1'b0;
                    end
                end

            // ----------------------------------------------------------
            // 5b. Accept AW+W[0] → issue beat 0 and start write burst.
            //     Need B FIFO space and no burst already in flight.
            // ----------------------------------------------------------
            end else if (!aw_active && axi.aw_o_valid && axi.w_o_valid
                         && b_cnt_next < B_DEPTH) begin
                wr_beat_addr = longint'(axi.aw_o.addr);
                wr_merged    = apply_wstrb(ramulator_read_mem(handle, wr_beat_addr),
                                           axi.w_o.data, axi.w_o.strb);
                dpi_accepted = ramulator_send_request(
                    handle,
                    wr_beat_addr,
                    1,                      // Write
                    int'(axi.aw_o.mid_id),
                    wr_merged
                );
                if (dpi_accepted) begin
                    axi.aw_o_ready <= 1'b1;
                    axi.w_o_ready  <= 1'b1;
                    if (axi.w_o.last) begin
                        // single-beat write or last beat came with AW — we're done
                        b_fifo[b_wr] <= '{id: axi.aw_o.mid_id[BID-1:0], resp: B_OKAY};
                        b_wr         <= (b_wr + 1 == B_DEPTH) ? 0 : b_wr + 1;
                        b_cnt_next   = b_cnt_next + 1;
                    end else begin
                        // more beats coming — hold the B response until w_last
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
            b_cnt  <= b_cnt_next;
            sr_cnt <= sr_cnt_next;

            // ----------------------------------------------------------
            // 7. Tick Ramulator
            // ----------------------------------------------------------
            ramulator_tick(handle);

        end
    end

endmodule
