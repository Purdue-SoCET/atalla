// ramulator_sv_wrapper_hbm3_pc32.sv
//
// HBM3 pseudo-channel oriented AXI4 subordinate wrapper around the Ramulator DPI-C library.
//
// Key change from the original wrapper:
//   - payload to/from DPI is 32 bits (one HBM3 pseudo-channel beat)
//   - intended AXI beat size is 4 bytes (ARSIZE/AWSIZE = 2)
//   - full HBM3 packet-style access is naturally len=7 (8 beats)
//
// NOTE:
//   If your AXI bus is wider than 32 bits, this wrapper uses only [31:0] of WDATA
//   and zero-extends read data onto RDATA. For a wider AXI bus, a proper width
//   adapter is better.

`timescale 1ns / 1ps

module ramulator_sv_wrapper_hbm3_pc32 #(
    parameter string CONFIG_FILE = "ramulator_config.yaml",
    parameter int    B_DEPTH     = 4
)(
    axi_bus_if  axi,
    output logic init_done
);

    import axi_bus_pkg::*;

    localparam int HBM_PC_BITS  = 32;
    localparam int HBM_PC_BYTES = 4;
    localparam int HBM_PC_SIZE  = 2;   // log2(4 bytes)
    localparam int HBM_PC_BLEN  = 7;   // 8 beats => AXI len = 7

    typedef logic [HBM_PC_BITS-1:0] hbm_pc_data_t;

    // ------------------------------------------------------------
    // Helpers
    // ------------------------------------------------------------
    function automatic logic [RDATA-1:0] pack_rdata(input hbm_pc_data_t d);
        logic [RDATA-1:0] tmp;
        begin
            tmp = '0;
            tmp[HBM_PC_BITS-1:0] = d;
            return tmp;
        end
    endfunction

    function automatic hbm_pc_data_t unpack_wdata(input logic [WDATA-1:0] d);
        begin
            return d[HBM_PC_BITS-1:0];
        end
    endfunction

    // ------------------------------------------------------------
    // DPI-C imports
    // ------------------------------------------------------------
    import "DPI-C" function chandle ramulator_init(
        input string config_file
    );

    // data payload changed from longint -> int unsigned (32-bit)
    import "DPI-C" function int ramulator_send_request(
        input chandle      handle,
        input longint      addr,
        input int          req_type,
        input int          source_id,
        input int unsigned data
    );

    import "DPI-C" function void ramulator_tick(
        input chandle handle
    );

    // response data changed from longint -> int unsigned (32-bit)
    import "DPI-C" function longint ramulator_check_response(
        input  chandle      handle,
        output int unsigned data_out
    );

    import "DPI-C" function void ramulator_finalize(
        input chandle handle
    );

    // ------------------------------------------------------------
    // Internal state
    // ------------------------------------------------------------
    chandle        handle;
    int            dpi_accepted;
    int            beat_idx;
    longint        dpi_resp;
    int unsigned   dpi_data_out;

    // R channel register
    logic           r_pending;
    sub_r_channel_t r_reg;

    // B-response FIFO
    sub_b_channel_t b_fifo [B_DEPTH];
    int             b_cnt;
    int             b_rd;
    int             b_wr;
    int             b_cnt_next;

    // --- Single-beat read path ---
    logic [MID_ARID-1:0] read_mid_id [longint];

    // --- Multi-beat read burst state ---
    logic                ar_active;
    longint              ar_base_addr;
    logic [ARLEN-1:0]    ar_len_reg;
    logic [ARSIZE-1:0]   ar_size_reg;
    logic [MID_ARID-1:0] ar_id_reg;
    int                  ar_beat_issued;
    int                  ar_beat_out;
    hbm_pc_data_t        ar_rob [16];
    logic [15:0]         ar_rob_valid;

    // --- Write burst state ---
    logic                aw_active;
    longint              aw_base_addr;
    logic [AWLEN-1:0]    aw_len_reg;
    logic [AWSIZE-1:0]   aw_size_reg;
    logic [MID_AWID-1:0] aw_id_reg;
    int                  aw_beat;

    // ------------------------------------------------------------
    // Combinatorial outputs
    // ------------------------------------------------------------
    assign axi.r_i_valid = r_pending;
    assign axi.r_i       = r_reg;
    assign axi.b_i_valid = (b_cnt > 0);
    assign axi.b_i       = b_fifo[b_rd];

    // ------------------------------------------------------------
    // Initialization
    // ------------------------------------------------------------
    initial begin
        handle       = null;
        init_done    = 1'b0;
        r_pending    = 1'b0;
        b_cnt        = 0;
        b_rd         = 0;
        b_wr         = 0;
        ar_active    = 1'b0;
        ar_rob_valid = '0;
        aw_active    = 1'b0;

        wait (axi.nRST === 1'b0);
        wait (axi.nRST === 1'b1);
        @(posedge axi.CLK);

        handle = ramulator_init(CONFIG_FILE);
        if (handle == null)
            $fatal(1, "[ramulator_sv_wrapper_hbm3_pc32] ramulator_init() returned null. Config: %s",
                   CONFIG_FILE);

        init_done = 1'b1;
        $display("[ramulator_sv_wrapper_hbm3_pc32] Init OK (config=%s)", CONFIG_FILE);
    end

    // ------------------------------------------------------------
    // Clocked logic
    // ------------------------------------------------------------
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
            aw_active      <= 1'b0;

        end else if (init_done) begin

            axi.ar_o_ready <= 1'b0;
            axi.aw_o_ready <= 1'b0;
            axi.w_o_ready  <= 1'b0;

            // ------------------------------------------------------
            // 1. Drain one Ramulator response
            // ------------------------------------------------------
            if (ar_active || !r_pending || axi.r_i_ready) begin
                dpi_resp = ramulator_check_response(handle, dpi_data_out);

                if (dpi_resp !== -64'sd1) begin
                    if (ar_active) begin
                        beat_idx = int'((dpi_resp - ar_base_addr) >> int'(ar_size_reg));

                        if (beat_idx >= 0 && beat_idx < 16 && beat_idx <= int'(ar_len_reg)) begin
                            ar_rob[beat_idx]       <= hbm_pc_data_t'(dpi_data_out);
                            ar_rob_valid[beat_idx] <= 1'b1;
                        end else begin
                            $fatal(1,
                                "[ramulator_sv_wrapper_hbm3_pc32] Bad burst response: resp_addr=%0h base=%0h beat_idx=%0d len=%0d size=%0d",
                                dpi_resp, ar_base_addr, beat_idx, ar_len_reg, ar_size_reg);
                        end
                    end else begin
                        r_reg.data <= pack_rdata(hbm_pc_data_t'(dpi_data_out));
                        r_reg.id   <= read_mid_id[dpi_resp][RID-1:0];
                        r_reg.last <= 1'b1;
                        r_reg.resp <= R_OKAY;
                        r_pending  <= 1'b1;
                    end
                end else begin
                    if (!ar_active && r_pending && axi.r_i_ready)
                        r_pending <= 1'b0;
                end
            end

            // ------------------------------------------------------
            // 1b. Drive R channel in burst order from ROB
            // ------------------------------------------------------
            if (ar_active) begin
                if (!r_pending || axi.r_i_ready) begin
                    if (ar_rob_valid[ar_beat_out]) begin
                        r_reg.data <= pack_rdata(ar_rob[ar_beat_out]);
                        r_reg.id   <= ar_id_reg[RID-1:0];
                        r_reg.last <= (ar_beat_out == int'(ar_len_reg));
                        r_reg.resp <= R_OKAY;
                        r_pending  <= 1'b1;
                        ar_rob_valid[ar_beat_out] <= 1'b0;

                        if (ar_beat_out == int'(ar_len_reg))
                            ar_active <= 1'b0;

                        ar_beat_out <= ar_beat_out + 1;
                    end else begin
                        if (r_pending && axi.r_i_ready)
                            r_pending <= 1'b0;
                    end
                end
            end

            // ------------------------------------------------------
            // 2. Issue remaining beats of active read burst
            // ------------------------------------------------------
            if (ar_active && ar_beat_issued <= int'(ar_len_reg)) begin
                dpi_accepted = ramulator_send_request(
                    handle,
                    ar_base_addr + longint'(ar_beat_issued) * longint'(HBM_PC_BYTES),
                    0,
                    int'(ar_id_reg),
                    32'h0
                );

                if (dpi_accepted)
                    ar_beat_issued <= ar_beat_issued + 1;
            end

            // ------------------------------------------------------
            // 3. Accept AR
            //
            // For HBM3 pseudo-channel style traffic, we expect size==2
            // (4 bytes / beat). len==7 is the natural full 32-byte packet.
            // ------------------------------------------------------
            if (axi.ar_o_valid && !ar_active) begin
                if (axi.ar_o.size != HBM_PC_SIZE[ARSIZE-1:0]) begin
                    $fatal(1,
                        "[ramulator_sv_wrapper_hbm3_pc32] ARSIZE must be 2 (4 bytes/beat) for HBM3 pseudo-channel mode. Got %0d",
                        axi.ar_o.size);
                end

                dpi_accepted = ramulator_send_request(
                    handle,
                    longint'(axi.ar_o.addr),
                    0,
                    int'(axi.ar_o.mid_id),
                    32'h0
                );

                if (dpi_accepted) begin
                    axi.ar_o_ready <= 1'b1;

                    if (axi.ar_o.len == '0) begin
                        read_mid_id[longint'(axi.ar_o.addr)] = axi.ar_o.mid_id;
                    end else begin
                        ar_base_addr   <= longint'(axi.ar_o.addr);
                        ar_len_reg     <= axi.ar_o.len;
                        ar_size_reg    <= axi.ar_o.size;
                        ar_id_reg      <= axi.ar_o.mid_id;
                        ar_beat_issued <= 1;
                        ar_beat_out    <= 0;
                        ar_rob_valid   <= '0;
                        ar_active      <= 1'b1;
                    end
                end
            end

            // ------------------------------------------------------
            // 4. Drain B FIFO head
            // ------------------------------------------------------
            b_cnt_next = b_cnt;

            if (b_cnt_next > 0 && axi.b_i_ready) begin
                b_rd       <= (b_rd + 1 == B_DEPTH) ? 0 : b_rd + 1;
                b_cnt_next = b_cnt_next - 1;
            end

            // ------------------------------------------------------
            // 5a. Accept W beat for ongoing write burst
            // ------------------------------------------------------
            if (aw_active && axi.w_o_valid) begin
                dpi_accepted = ramulator_send_request(
                handle,
                aw_base_addr + longint'(aw_beat) * longint'(HBM_PC_BYTES),
                1,
                int'(aw_id_reg),
                unpack_wdata(axi.w_o.data)
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

            // ------------------------------------------------------
            // 5b. Accept AW + W[0]
            // ------------------------------------------------------
            end else if (!aw_active && axi.aw_o_valid && axi.w_o_valid
                         && b_cnt_next < B_DEPTH) begin

                if (axi.aw_o.size != HBM_PC_SIZE[AWSIZE-1:0]) begin
                    $fatal(1,
                        "[ramulator_sv_wrapper_hbm3_pc32] AWSIZE must be 2 (4 bytes/beat) for HBM3 pseudo-channel mode. Got %0d",
                        axi.aw_o.size);
                end

                dpi_accepted = ramulator_send_request(
                handle,
                longint'(axi.aw_o.addr),
                1,
                int'(axi.aw_o.mid_id),
                unpack_wdata(axi.w_o.data)
            );

                if (dpi_accepted) begin
                    axi.aw_o_ready <= 1'b1;
                    axi.w_o_ready  <= 1'b1;

                    if (axi.w_o.last) begin
                        b_fifo[b_wr] <= '{id: axi.aw_o.mid_id[BID-1:0], resp: B_OKAY};
                        b_wr         <= (b_wr + 1 == B_DEPTH) ? 0 : b_wr + 1;
                        b_cnt_next   = b_cnt_next + 1;
                    end else begin
                        aw_base_addr <= longint'(axi.aw_o.addr);
                        aw_len_reg   <= axi.aw_o.len;
                        aw_size_reg  <= axi.aw_o.size;
                        aw_id_reg    <= axi.aw_o.mid_id;
                        aw_beat      <= 1;
                        aw_active    <= 1'b1;
                    end
                end
            end

            // ------------------------------------------------------
            // 6. Commit final B FIFO count
            // ------------------------------------------------------
            b_cnt <= b_cnt_next;

            // ------------------------------------------------------
            // 7. Advance Ramulator by one cycle
            // ------------------------------------------------------
            ramulator_tick(handle);
        end
    end

endmodule