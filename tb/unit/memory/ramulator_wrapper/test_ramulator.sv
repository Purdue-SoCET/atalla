// test_ramulator.sv
// Heng-I (Ivor) Chu - ivorchu@gmail.com
//
//
// Runs through the main features in order:
//   [1]  Reset + init
//   [2]  Write phase — NUM_WR writes, one B-ack each
//   [3]  Read-after-write — read back all written addresses, verify vs shadow
//   [4]  Raw reads — read unwritten addresses, wrapper should return addr-as-data
//   [5]  Read backpressure — flood with r_i_ready=0, check stall cycles, then drain
//   [6]  Write backpressure — fill B FIFO with b_i_ready=0, verify stall, then drain
//   [7]  Simultaneous R+W — AR and AW+W in the same cycle; both should be accepted
//   [8]  INCR bursts — 4-beat and 8-beat write+read, check per-beat data and last flag
//   [9]  FIXED burst — 4-beat write+read to same address; last write wins on readback
//   [10] WRAP burst — 4-beat write+read starting mid-region; address should wrap
//   [11] Multiple outstanding reads — issue NUM_PIPE ARs, verify SR FIFO buffers them
//   [12] WSTRB byte masking — lower-half, upper-half, zero-strobe, single-byte cases
//   [13] Pass/fail summary

`timescale 1ns / 1ps

module test_ramulator #(
    // Override from make: make sim CFG=rtl/modules/memory/ramulator_wrapper/configs/other.yaml  (passed via -G)
    parameter string  CFG          = "rtl/modules/memory/ramulator_wrapper/configs/ddr4_config.yaml",
    // Forwarded to ramulator_sv_wrapper for functional_mem preload.
    // With USE_MEMINIT=1, phase [2] is skipped and shadow[] is pre-populated
    // from the known meminit pattern so [3] can verify the preloaded data.
    parameter string  MEMINIT_FILE = "",
    parameter string  MEMINIT_TYPE = "hex",
    parameter longint MEMINIT_BASE = 0,
    parameter bit     USE_MEMINIT  = 0
);
    import axi_bus_pkg::*;

    localparam logic [2:0] AXI_SIZE = 3'b101; // 32 bytes/beat — full 256-bit bus width

    // ------------------------------------------------------------
    // Helpers
    // ------------------------------------------------------------
    function automatic longint norm_data(input longint d);
        return d;
    endfunction

    function automatic longint wr_pattern(input int i);
        return 64'hC0FF_EE00_0000_0000 | longint'(i);
    endfunction

    function automatic longint bp_pattern_a(input int i);
        return 64'hAAAA_0000_0000_0000 | longint'(i);
    endfunction

    function automatic longint bp_pattern_b(input int i);
        return 64'hBBBB_0000_0000_0000 | longint'(i);
    endfunction

    function automatic longint simul_pattern();
        return 64'hFEED_FACE_CAFE_BABE;
    endfunction

    function automatic longint burst4_pattern();
        return 64'hCAFE_0000_0050_0000;
    endfunction

    function automatic longint burst8_pattern();
        return 64'hDEAD_0000_0060_0000;
    endfunction

    // Use ramulator_exit() to bypass QuestaSim post-sim cleanup which
    // hits heap corruption left by Ramulator2 (see ramulator_dpi.cpp).
    import "DPI-C" function void ramulator_exit(input int code);

    // ----------------------------------------------------------------
    // Parameters — B_DEPTH must match ramulator_sv_wrapper's B_DEPTH
    // ----------------------------------------------------------------
    localparam int     NUM_WR       = 16;
    localparam int     NUM_RD_RAW   = 8;
    localparam int     NUM_FLOOD    = 48;   // ARs to fire in read-BP test
    localparam int     B_DEPTH      = 4;    // must match wrapper parameter
    localparam int     BP_HOLD      = 20;   // cycles to observe write stall
    localparam int     MAX_CYCLES   = 2_000_000;
    localparam longint WR_BASE      = 64'h0000_0000;
    localparam longint RD_BASE      = 64'h0010_0000;
    localparam longint FLOOD_BASE   = 64'h0020_0000;
    localparam longint BP_WR_BASE   = 64'h0030_0000;
    localparam longint SIMUL_BASE   = 64'h0040_0000;
    localparam longint BURST4_BASE  = 64'h0050_0000;  // [8] 4-beat burst test
    localparam longint BURST8_BASE  = 64'h0060_0000;  // [8] 8-beat burst test
    localparam longint PIPE_BASE    = 64'h0070_0000;  // [11] SR FIFO pipeline test
    localparam longint STRB_BASE    = 64'h0080_0000;  // [12] WSTRB byte-mask test
    localparam longint FIXED_BASE   = 64'h0090_0000;  // [9]  FIXED burst test
    localparam longint WRAP_BASE    = 64'h00A0_0000;  // [10] WRAP burst test
    localparam longint STRIDE       = 64;
    localparam int     NUM_PIPE     = 16;              // [11] must be <= SR_DEPTH

    // ----------------------------------------------------------------
    // Clock / reset
    // ----------------------------------------------------------------
    logic clk  = 0;
    logic nrst = 0;
    always #0.625 clk = ~clk;  // 800 MHz

    // ----------------------------------------------------------------
    // AXI bus interface + DUT
    // ----------------------------------------------------------------
    axi_bus_if axi(.CLK(clk), .nRST(nrst));
    logic init_done;

    ramulator_sv_wrapper #(
        .CONFIG_FILE   (CFG),
        .B_DEPTH       (B_DEPTH),
        .MEM_INIT_FILE (MEMINIT_FILE),
        .MEM_INIT_TYPE (MEMINIT_TYPE),
        .MEM_INIT_BASE (MEMINIT_BASE)
    ) dut (
        .axi      (axi),
        .init_done(init_done)
    );

    // ----------------------------------------------------------------
    // Tick counter
    // ----------------------------------------------------------------
    longint tick = 0;
    always @(posedge clk) tick++;

    // ----------------------------------------------------------------
    // Scoreboards
    // ----------------------------------------------------------------
    longint shadow [longint];
    int     wr_acc    = 0, wr_cmp    = 0;
    int     rd_acc    = 0, rd_cmp    = 0;
    int     func_ok   = 0, func_fail = 0;
    longint wr_lat_min = 2_000_000_000, wr_lat_max = 0, wr_lat_total = 0;
    longint rd_lat_min = 2_000_000_000, rd_lat_max = 0, rd_lat_total = 0;

    // [5] read flood
    int     flood_acc = 0, flood_cmp = 0;
    longint flood_stall_max = 0;

    // [6] write backpressure
    // bp_wr_acc  : writes accepted (aw_o_ready seen)
    // bp_wr_cmp  : B-acks collected
    // bp_stall   : how many cycles write #B_DEPTH stalled waiting for FIFO room
    int     bp_wr_acc = 0, bp_wr_cmp = 0;
    longint bp_stall  = 0;

    // [7] simultaneous R+W
    int     sim_rd_acc = 0, sim_rd_cmp = 0;
    int     sim_wr_acc = 0, sim_wr_cmp = 0;
    int     sim_func_ok = 0, sim_func_fail = 0;

    // [8] INCR bursts
    int     burst_wr_ok = 0, burst_wr_fail = 0;
    int     burst_rd_ok = 0, burst_rd_fail = 0;

    // [11] SR FIFO pipeline
    int     pipe_acc = 0, pipe_cmp = 0, pipe_ok = 0, pipe_fail = 0;

    // [12] WSTRB
    int     strb_ok = 0, strb_fail = 0;

    // [9] FIXED burst
    int     fixed_ok = 0, fixed_fail = 0;

    // [10] WRAP burst
    int     wrap_ok = 0, wrap_fail = 0;

    // ----------------------------------------------------------------
    // Task: full AXI write (issue AW+W, wait for aw_o_ready, collect B)
    // ----------------------------------------------------------------
    task automatic axi_write(
        input longint              addr,
        input logic [WDATA-1:0]    data,
        input logic [MID_AWID-1:0] mid_id
    );
        longint t0, lat;
        t0 = tick;

        axi.aw_o_valid  = 1'b1;
        axi.aw_o.addr   = AWADDR'(addr);
        axi.aw_o.mid_id = mid_id;
        axi.aw_o.size   = AXI_SIZE;
        axi.aw_o.len    = 4'h0;
        axi.aw_o.burst  = 2'b01;

        axi.w_o_valid   = 1'b1;
        axi.w_o.data    = data;
        axi.w_o.mid_id  = MID_ARID'(mid_id);
        axi.w_o.last    = 1'b1;
        axi.w_o.strb    = '1;

        @(posedge clk); #1;
        while (!axi.aw_o_ready) begin @(posedge clk); #1; end
        axi.aw_o_valid = 1'b0;
        axi.w_o_valid  = 1'b0;
        wr_acc++;
        shadow[addr] = norm_data(longint'(data));

        axi.b_i_ready = 1'b1;
        while (!axi.b_i_valid) begin @(posedge clk); #1; end
        @(posedge clk); #1;
        axi.b_i_ready = 1'b0;
        wr_cmp++;

        lat = tick - t0;
        $display("    wr[%0d] addr=0x%08h  ticks=%0d", wr_cmp - 1, addr, lat);
        if (lat < wr_lat_min) wr_lat_min = lat;
        if (lat > wr_lat_max) wr_lat_max = lat;
        wr_lat_total += lat;
    endtask

    // ----------------------------------------------------------------
    // Task: full AXI read (issue AR, collect R response)
    // ----------------------------------------------------------------
    task automatic axi_read(
        input  longint              addr,
        input  logic [RID-1:0] mid_id,
        output longint              got_data
    );
        longint t0, lat;
        t0 = tick;

        axi.ar_o_valid  = 1'b1;
        axi.ar_o.addr   = ARADDR'(addr);
        axi.ar_o.id = mid_id;
        axi.ar_o.size   = AXI_SIZE;
        axi.ar_o.len    = 4'h0;
        axi.ar_o.burst  = 2'b01;

        @(posedge clk); #1;
        while (!axi.ar_o_ready) begin @(posedge clk); #1; end
        axi.ar_o_valid = 1'b0;
        rd_acc++;

        axi.r_ready = 1'b1;
        while (!axi.r_valid) begin @(posedge clk); #1; end
        got_data = norm_data(longint'(axi.r_i.data));
        @(posedge clk); #1;
        axi.r_ready = 1'b0;
        rd_cmp++;

        lat = tick - t0;
        $display("    rd[%0d] addr=0x%08h  ticks=%0d", rd_cmp - 1, addr, lat);
        if (lat < rd_lat_min) rd_lat_min = lat;
        if (lat > rd_lat_max) rd_lat_max = lat;
        rd_lat_total += lat;
    endtask

    // ----------------------------------------------------------------
    // Task: issue AR only, no R collection. Returns stall cycles.
    // r_i_ready is NOT touched — caller controls it.
    // ----------------------------------------------------------------
    task automatic axi_ar_send(
        input  longint              addr,
        input  logic [RID-1:0] mid_id,
        output longint              stall_cycles
    );
        longint t0;
        t0 = tick;

        axi.ar_o_valid  = 1'b1;
        axi.ar_o.addr   = ARADDR'(addr);
        axi.ar_o.id = mid_id;
        axi.ar_o.size   = AXI_SIZE;
        axi.ar_o.len    = 4'h0;
        axi.ar_o.burst  = 2'b01;

        @(posedge clk); #1;
        while (!axi.ar_o_ready) begin @(posedge clk); #1; end
        axi.ar_o_valid = 1'b0;
        stall_cycles = tick - t0;
        flood_acc++;
    endtask

    // ----------------------------------------------------------------
    // Task: collect one R response (asserts/deasserts r_i_ready)
    // ----------------------------------------------------------------
    task automatic axi_r_collect(output longint got_data);
        axi.r_ready = 1'b1;
        while (!axi.r_valid) begin @(posedge clk); #1; end
        got_data = norm_data(longint'(axi.r_i.data));
        @(posedge clk); #1;
        axi.r_ready = 1'b0;
        flood_cmp++;
    endtask

    // ----------------------------------------------------------------
    // Task: issue AW+W without collecting B (non-blocking write).
    // Waits for aw_o_ready, then returns. Caller must drain B-acks.
    // ----------------------------------------------------------------
    task automatic axi_aw_nb(
        input  longint              addr,
        input  logic [WDATA-1:0]    data,
        input  logic [MID_AWID-1:0] mid_id,
        output longint              stall_cycles
    );
        longint t0;
        t0 = tick;

        axi.aw_o_valid  = 1'b1;
        axi.aw_o.addr   = AWADDR'(addr);
        axi.aw_o.mid_id = mid_id;
        axi.aw_o.size   = AXI_SIZE;
        axi.aw_o.len    = 4'h0;
        axi.aw_o.burst  = 2'b01;

        axi.w_o_valid   = 1'b1;
        axi.w_o.data    = data;
        axi.w_o.mid_id  = MID_ARID'(mid_id);
        axi.w_o.last    = 1'b1;
        axi.w_o.strb    = '1;

        @(posedge clk); #1;
        while (!axi.aw_o_ready) begin @(posedge clk); #1; end
        axi.aw_o_valid = 1'b0;
        axi.w_o_valid  = 1'b0;

        shadow[addr] = norm_data(longint'(data));
        bp_wr_acc++;
        stall_cycles = tick - t0;
    endtask

    // ----------------------------------------------------------------
    // Task: INCR write burst
    // ----------------------------------------------------------------
    task automatic axi_write_burst(
        input  longint              base_addr,
        input  longint              base_data,
        input  int                  len,        // beats - 1
        input  logic [2:0]          size,       // log2(bytes per beat)
        input  logic [MID_AWID-1:0] mid_id
    );
        int stride;
        stride = 1 << int'(size);

        axi.aw_o_valid  = 1'b1;
        axi.aw_o.addr   = AWADDR'(base_addr);
        axi.aw_o.mid_id = mid_id;
        axi.aw_o.size   = size;
        axi.aw_o.len    = AWLEN'(len);
        axi.aw_o.burst  = 2'b01;       // INCR

        axi.w_o_valid   = 1'b1;
        axi.w_o.data    = WDATA'(base_data);
        axi.w_o.mid_id  = MID_ARID'(mid_id);
        axi.w_o.last    = (len == 0) ? 1'b1 : 1'b0;
        axi.w_o.strb    = '1;

        @(posedge clk); #1;
        while (!axi.aw_o_ready) begin @(posedge clk); #1; end
        axi.aw_o_valid = 1'b0;
        shadow[base_addr] = norm_data(base_data);

        for (int i = 1; i <= len; i++) begin
            longint baddr, bdata;
            baddr = base_addr + longint'(i) * longint'(stride);
            bdata = base_data + longint'(i);

            axi.w_o.data  = WDATA'(bdata);
            axi.w_o.last  = (i == len) ? 1'b1 : 1'b0;
            axi.w_o_valid = 1'b1;

            @(posedge clk); #1;
            while (!axi.w_o_ready) begin @(posedge clk); #1; end
            shadow[baddr] = norm_data(bdata);
        end
        axi.w_o_valid = 1'b0;
        burst_wr_ok++;

        axi.b_i_ready = 1'b1;
        while (!axi.b_i_valid) begin @(posedge clk); #1; end
        @(posedge clk); #1;
        axi.b_i_ready = 1'b0;
    endtask

    // ----------------------------------------------------------------
    // Task: INCR read burst
    // ----------------------------------------------------------------
    task automatic axi_read_burst(
        input  longint              base_addr,
        input  int                  len,
        input  logic [2:0]          size,
        input  logic [RID-1:0] mid_id
    );
        int stride;
        stride = 1 << int'(size);

        axi.ar_o_valid  = 1'b1;
        axi.ar_o.addr   = ARADDR'(base_addr);
        axi.ar_o.id = mid_id;
        axi.ar_o.size   = size;
        axi.ar_o.len    = ARLEN'(len);
        axi.ar_o.burst  = 2'b01;       // INCR

        @(posedge clk); #1;
        while (!axi.ar_o_ready) begin @(posedge clk); #1; end
        axi.ar_o_valid = 1'b0;

        for (int i = 0; i <= len; i++) begin
            longint baddr, got, exp;
            logic   got_last;
            baddr = base_addr + longint'(i) * longint'(stride);

            axi.r_ready = 1'b1;
            while (!axi.r_valid) begin @(posedge clk); #1; end
            got      = norm_data(longint'(axi.r_i.data));
            got_last = axi.r_i.last;
            @(posedge clk); #1;
            axi.r_ready = 1'b0;

            exp = shadow.exists(baddr) ? norm_data(shadow[baddr]) : norm_data(baddr);
            if (got === exp) burst_rd_ok++;
            else begin
                $display("  [BURST RD MISMATCH] beat=%0d addr=0x%08h got=0x%016h exp=0x%016h",
                         i, baddr, got, exp);
                burst_rd_fail++;
            end

            if ((i == len) && !got_last) begin
                $display("  [BURST RD ERROR] beat=%0d: expected last=1, got last=0", i);
                burst_rd_fail++;
            end else if ((i < len) && got_last) begin
                $display("  [BURST RD ERROR] beat=%0d: expected last=0, got last=1", i);
                burst_rd_fail++;
            end
        end
    endtask

    // ----------------------------------------------------------------
    // Task: single-beat AXI write with an explicit WSTRB value.
    //   Issues AW+W simultaneously, waits for aw_o_ready, collects B ack.
    //   Does NOT update shadow[] — caller manages expected values.
    // ----------------------------------------------------------------
    task automatic axi_write_strb(
        input longint              addr,
        input logic [WDATA-1:0]    data,
        input logic [WSTRB-1:0]    strb,
        input logic [MID_AWID-1:0] mid_id
    );
        axi.aw_o_valid  = 1'b1;
        axi.aw_o.addr   = AWADDR'(addr);
        axi.aw_o.mid_id = mid_id;
        axi.aw_o.size   = 3'b011;
        axi.aw_o.len    = 4'h0;
        axi.aw_o.burst  = 2'b01;

        axi.w_o_valid   = 1'b1;
        axi.w_o.data    = data;
        axi.w_o.mid_id  = MID_ARID'(mid_id);
        axi.w_o.last    = 1'b1;
        axi.w_o.strb    = strb;

        @(posedge clk); #1;
        while (!axi.aw_o_ready) begin @(posedge clk); #1; end
        axi.aw_o_valid = 1'b0;
        axi.w_o_valid  = 1'b0;

        axi.b_i_ready = 1'b1;
        while (!axi.b_i_valid) begin @(posedge clk); #1; end
        @(posedge clk); #1;
        axi.b_i_ready = 1'b0;
    endtask

    // ----------------------------------------------------------------
    // Task: single-beat AXI read without touching global rd counters.
    //   Used by [10] WSTRB tests so they don't skew [3-4] pass checks.
    // ----------------------------------------------------------------
    task automatic axi_read_raw(
        input  longint              addr,
        input  logic [RID-1:0] mid_id,
        output longint              got_data
    );
        axi.ar_o_valid  = 1'b1;
        axi.ar_o.addr   = ARADDR'(addr);
        axi.ar_o.id = mid_id;
        axi.ar_o.size   = 3'b011;
        axi.ar_o.len    = 4'h0;
        axi.ar_o.burst  = 2'b01;

        @(posedge clk); #1;
        while (!axi.ar_o_ready) begin @(posedge clk); #1; end
        axi.ar_o_valid = 1'b0;

        axi.r_ready = 1'b1;
        while (!axi.r_valid) begin @(posedge clk); #1; end
        got_data = longint'(axi.r_i.data);
        @(posedge clk); #1;
        axi.r_ready = 1'b0;
    endtask

    // ----------------------------------------------------------------
    // Task: write burst with explicit burst type (FIXED=0/INCR=1/WRAP=2).
    //   Drives AW.burst correctly; updates shadow at the per-burst-type
    //   address for each beat so read-back tasks see the right expected value.
    //   Beat i data = base_data + i.
    // ----------------------------------------------------------------
    task automatic axi_write_burst_typed(
        input  longint              base_addr,
        input  longint              base_data,
        input  int                  len,
        input  logic [2:0]          size,
        input  logic [1:0]          burst,
        input  logic [MID_AWID-1:0] mid_id
    );
        int     stride, num_beats;
        longint beat_addr, wlen, wmask, aln;
        stride    = 1 << int'(size);
        num_beats = len + 1;

        axi.aw_o_valid  = 1'b1;
        axi.aw_o.addr   = AWADDR'(base_addr);
        axi.aw_o.mid_id = mid_id;
        axi.aw_o.size   = size;
        axi.aw_o.len    = AWLEN'(len);
        axi.aw_o.burst  = burst;

        axi.w_o_valid   = 1'b1;
        axi.w_o.data    = WDATA'(base_data);
        axi.w_o.mid_id  = MID_ARID'(mid_id);
        axi.w_o.last    = (len == 0) ? 1'b1 : 1'b0;
        axi.w_o.strb    = '1;

        @(posedge clk); #1;
        while (!axi.aw_o_ready) begin @(posedge clk); #1; end
        axi.aw_o_valid  = 1'b0;
        shadow[base_addr] = base_data;   // beat 0 always at base_addr

        for (int i = 1; i <= len; i++) begin
            longint bdata;
            bdata = base_data + longint'(i);
            case (burst)
                2'b00: beat_addr = base_addr;  // FIXED: same address every beat
                2'b10: begin  // WRAP
                    wlen      = longint'(num_beats) * longint'(stride);
                    wmask     = wlen - 1;
                    aln       = base_addr & ~wmask;
                    beat_addr = aln + ((base_addr - aln
                                        + longint'(i) * longint'(stride)) & wmask);
                end
                default: beat_addr = base_addr + longint'(i) * longint'(stride);
            endcase
            axi.w_o.data  = WDATA'(bdata);
            axi.w_o.last  = (i == len) ? 1'b1 : 1'b0;
            axi.w_o_valid = 1'b1;
            @(posedge clk); #1;
            while (!axi.w_o_ready) begin @(posedge clk); #1; end
            shadow[beat_addr] = bdata;
        end
        axi.w_o_valid = 1'b0;

        axi.b_i_ready = 1'b1;
        while (!axi.b_i_valid) begin @(posedge clk); #1; end
        @(posedge clk); #1;
        axi.b_i_ready = 1'b0;
    endtask

    // ----------------------------------------------------------------
    // Task: read burst with explicit burst type (FIXED=0/INCR=1/WRAP=2).
    //   Issues AR with the given burst type; collects len+1 R beats;
    //   verifies each beat's data against shadow at the burst-correct
    //   address and checks the last flag.
    //   ok_cnt / fail_cnt updated per beat (passed by ref).
    // ----------------------------------------------------------------
    task automatic axi_read_burst_typed(
        input  longint              base_addr,
        input  int                  len,
        input  logic [2:0]          size,
        input  logic [1:0]          burst,
        input  logic [RID-1:0] mid_id,
        ref    int                  ok_cnt,
        ref    int                  fail_cnt
    );
        int     stride, num_beats;
        longint beat_addr, got, exp, wlen, wmask, aln;
        logic   got_last;
        stride    = 1 << int'(size);
        num_beats = len + 1;

        axi.ar_o_valid  = 1'b1;
        axi.ar_o.addr   = ARADDR'(base_addr);
        axi.ar_o.id = mid_id;
        axi.ar_o.size   = size;
        axi.ar_o.len    = ARLEN'(len);
        axi.ar_o.burst  = burst;

        @(posedge clk); #1;
        while (!axi.ar_o_ready) begin @(posedge clk); #1; end
        axi.ar_o_valid = 1'b0;

        for (int i = 0; i <= len; i++) begin
            case (burst)
                2'b00: beat_addr = base_addr;  // FIXED
                2'b10: begin  // WRAP
                    wlen      = longint'(num_beats) * longint'(stride);
                    wmask     = wlen - 1;
                    aln       = base_addr & ~wmask;
                    beat_addr = aln + ((base_addr - aln
                                        + longint'(i) * longint'(stride)) & wmask);
                end
                default: beat_addr = base_addr + longint'(i) * longint'(stride);
            endcase

            axi.r_ready = 1'b1;
            while (!axi.r_valid) begin @(posedge clk); #1; end
            got      = longint'(axi.r_i.data);
            got_last = axi.r_i.last;
            @(posedge clk); #1;
            axi.r_ready = 1'b0;

            exp = shadow.exists(beat_addr) ? shadow[beat_addr] : beat_addr;
            if (got === exp) ok_cnt++;
            else begin
                $display("  [BURST RD MISMATCH] burst=%0d beat=%0d addr=0x%08h got=0x%016h exp=0x%016h",
                         burst, i, beat_addr, got, exp);
                fail_cnt++;
            end

            if ((i == len) && !got_last) begin
                $display("  [BURST RD ERROR] beat=%0d: expected last=1 got last=0", i);
                fail_cnt++;
            end else if ((i < len) && got_last) begin
                $display("  [BURST RD ERROR] beat=%0d: expected last=0 got last=1", i);
                fail_cnt++;
            end
        end
    endtask

    // ----------------------------------------------------------------
    // Main test
    // ----------------------------------------------------------------
    initial begin : main
        longint got, exp;
        int     total_rd;

        axi.ar_o_valid = 1'b0;  axi.ar_o = '0;
        axi.aw_o_valid = 1'b0;  axi.aw_o = '0;
        axi.w_o_valid  = 1'b0;  axi.w_o  = '0;
        axi.r_ready  = 1'b0;
        axi.b_i_ready  = 1'b0;

        nrst = 1'b0;
        repeat(4) @(posedge clk);
        nrst = 1'b1;

        $display("=== AXI Ramulator wrapper smoketest ===");
        $display("Config : %s", CFG);
        $write("[1] ramulator_init ... ");
        wait(init_done);
        @(posedge clk); #1;
        $display("OK");

        $display("    Mode: 256-bit AXI wrapper (32-byte beats, AXI_SIZE=%0d)", AXI_SIZE);

        // [2] Write phase — skipped when USE_MEMINIT=1 (data already in functional_mem)
        if (USE_MEMINIT) begin
            // Pre-populate shadow[] with the values meminit.hex loaded into
            // functional_mem.  Pattern matches wr_pattern(i) for i = 0..NUM_WR-1
            $display("[2] (meminit active) Skipping AXI writes — pre-loading shadow for [3] ...");
            for (int i = 0; i < NUM_WR; i++)
                shadow[WR_BASE + longint'(i) * STRIDE] = wr_pattern(i);
            $display("    shadow pre-loaded for %0d addresses", NUM_WR);
        end else begin
            $display("[2] %0d writes (AW+W simultaneous, B ack per write) ...", NUM_WR);
            for (int i = 0; i < NUM_WR; i++) begin
                axi_write(
                    WR_BASE + longint'(i) * STRIDE,
                    WDATA'(wr_pattern(i)),
                    MID_AWID'(i % (1 << MID_AWID))
                );
            end
            $display("    accepted=%0d  B-acks=%0d", wr_acc, wr_cmp);
        end

        // [3] Read-after-write / read-after-preload
        $display("[3] %0d reads (%0s, verify vs shadow) ...", NUM_WR,
                 USE_MEMINIT ? "read-after-preload" : "read-after-write");
        for (int i = 0; i < NUM_WR; i++) begin
            axi_read(
                WR_BASE + longint'(i) * STRIDE,
                MID_ARID'(i % (1 << MID_ARID)),
                got
            );
            exp = norm_data(shadow[WR_BASE + longint'(i) * STRIDE]);
            if (got === exp) func_ok++;
            else begin
                $display("  [MISMATCH] i=%0d addr=0x%08h got=0x%016h exp=0x%016h",
                         i, WR_BASE + longint'(i) * STRIDE, got, exp);
                func_fail++;
            end
        end
        $display("    accepted=%0d  R-data=%0d  OK=%0d  FAIL=%0d",
                 rd_acc, rd_cmp, func_ok, func_fail);

        // [4] Raw reads
        $display("[4] %0d raw reads (unwritten region, expect addr as data) ...", NUM_RD_RAW);
        for (int i = 0; i < NUM_RD_RAW; i++) begin
            axi_read(
                RD_BASE + longint'(i) * STRIDE,
                MID_ARID'(i % (1 << MID_ARID)),
                got
            );
            exp = norm_data(RD_BASE + longint'(i) * STRIDE);
            if (got === exp) func_ok++;
            else begin
                $display("  [MISMATCH] i=%0d addr=0x%08h got=0x%016h exp=0x%016h",
                         i, RD_BASE + longint'(i) * STRIDE, got, exp);
                func_fail++;
            end
        end
        total_rd = NUM_WR + NUM_RD_RAW;
        $display("    accepted=%0d  R-data=%0d  OK=%0d  FAIL=%0d",
                 rd_acc, rd_cmp, func_ok, func_fail);

        // [5] Read backpressure
        $display("[5] Read backpressure: %0d ARs issued with r_i_ready=0 ...", NUM_FLOOD);
        axi.r_ready = 1'b0;

        for (int i = 0; i < NUM_FLOOD; i++) begin
            longint stall;
            axi_ar_send(
                FLOOD_BASE + longint'(i) * STRIDE,
                MID_ARID'(i % (1 << MID_ARID)),
                stall
            );
            if (stall > flood_stall_max) flood_stall_max = stall;
            if (stall > 1)
                $display("    flood AR[%0d] addr=0x%08h  stall=%0d cycles (backpressure)",
                         i, FLOOD_BASE + longint'(i) * STRIDE, stall);
        end
        $display("    All %0d ARs accepted. Max stall=%0d cycles. Draining ...",
                 flood_acc, flood_stall_max);

        for (int i = 0; i < NUM_FLOOD; i++) begin
            axi_r_collect(got);
        end
        $display("    Drained %0d R responses.", flood_cmp);

        // [6] Write backpressure
        $display("[6] Write backpressure: fill %0d-deep B FIFO then stall ...", B_DEPTH);
        axi.b_i_ready = 1'b0;

        for (int i = 0; i < B_DEPTH; i++) begin
            longint stall;
            axi_aw_nb(
                BP_WR_BASE + longint'(i) * STRIDE,
                WDATA'(bp_pattern_a(i)),
                MID_AWID'(i % (1 << MID_AWID)),
                stall
            );
            $display("    write[%0d] accepted (stall=%0d, FIFO count=%0d/%0d)", i, stall, i+1, B_DEPTH);
        end
        $display("    B FIFO full. Driving write[%0d] with b_i_ready=0 ...", B_DEPTH);

        axi.aw_o_valid  = 1'b1;
        axi.aw_o.addr   = AWADDR'(BP_WR_BASE + longint'(B_DEPTH) * STRIDE);
        axi.aw_o.mid_id = MID_AWID'(B_DEPTH % (1 << MID_AWID));
        axi.aw_o.size   = AXI_SIZE;
        axi.aw_o.len    = 4'h0;
        axi.aw_o.burst  = 2'b01;

        axi.w_o_valid   = 1'b1;
        axi.w_o.data    = WDATA'(bp_pattern_b(B_DEPTH));
        axi.w_o.mid_id  = MID_ARID'(B_DEPTH % (1 << MID_ARID));
        axi.w_o.last    = 1'b1;
        axi.w_o.strb    = '1;

        begin
            int early_ready;
            early_ready = 0;
            repeat(BP_HOLD) begin
                @(posedge clk); #1;
                if (axi.aw_o_ready) early_ready++;
                bp_stall++;
            end
            if (early_ready == 0)
                $display("    write[%0d]: correctly stalled for %0d cycles (FIFO full).",
                         B_DEPTH, bp_stall);
            else
                $display("    write[%0d]: [WARN] aw_o_ready pulsed early %0d times.",
                         B_DEPTH, early_ready);
        end

        axi.b_i_ready = 1'b1;
        @(posedge clk); #1;
        while (!axi.aw_o_ready) begin @(posedge clk); #1; end
        axi.aw_o_valid = 1'b0;
        axi.w_o_valid  = 1'b0;
        shadow[BP_WR_BASE + longint'(B_DEPTH) * STRIDE] = norm_data(bp_pattern_b(B_DEPTH));
        bp_wr_acc++;
        $display("    write[%0d] accepted after stall.", B_DEPTH);

        bp_wr_cmp++;  // one B consumed in simultaneous drain+push
        for (int i = 0; i < B_DEPTH; i++) begin
            while (!axi.b_i_valid) begin @(posedge clk); #1; end
            @(posedge clk); #1;
            bp_wr_cmp++;
        end
        axi.b_i_ready = 1'b0;
        $display("    All %0d B-acks collected. bp_wr_acc=%0d  bp_wr_cmp=%0d",
                 B_DEPTH + 1, bp_wr_acc, bp_wr_cmp);

        // [7] Simultaneous read + write
        $display("[7] Simultaneous read + write ...");
        begin
            bit     ar_done, aw_done;
            longint simul_rd_addr, simul_wr_addr, simul_wr_data;
            longint t_issue;

            simul_rd_addr = SIMUL_BASE;
            simul_wr_addr = SIMUL_BASE + STRIDE;
            simul_wr_data = simul_pattern();
            ar_done = 0;
            aw_done = 0;

            axi.ar_o_valid  = 1'b1;
            axi.ar_o.addr   = ARADDR'(simul_rd_addr);
            axi.ar_o.id = MID_ARID'(0);
            axi.ar_o.size   = AXI_SIZE;
            axi.ar_o.len    = 4'h0;
            axi.ar_o.burst  = 2'b01;

            axi.aw_o_valid  = 1'b1;
            axi.aw_o.addr   = AWADDR'(simul_wr_addr);
            axi.aw_o.mid_id = MID_AWID'(0);
            axi.aw_o.size   = AXI_SIZE;
            axi.aw_o.len    = 4'h0;
            axi.aw_o.burst  = 2'b01;

            axi.w_o_valid   = 1'b1;
            axi.w_o.data    = WDATA'(simul_wr_data);
            axi.w_o.mid_id  = MID_ARID'(0);
            axi.w_o.last    = 1'b1;
            axi.w_o.strb    = '1;

            axi.b_i_ready   = 1'b0;

            t_issue = tick;
            @(posedge clk); #1;

            while (!ar_done || !aw_done) begin
                if (!ar_done && axi.ar_o_ready) begin
                    axi.ar_o_valid = 1'b0;
                    sim_rd_acc++;
                    ar_done = 1;
                end
                if (!aw_done && axi.aw_o_ready) begin
                    axi.aw_o_valid = 1'b0;
                    axi.w_o_valid  = 1'b0;
                    shadow[simul_wr_addr] = norm_data(simul_wr_data);
                    sim_wr_acc++;
                    aw_done = 1;
                end
                if (!ar_done || !aw_done) begin @(posedge clk); #1; end
            end

            if (tick - t_issue <= 2)
                $display("    AR and AW accepted in same cycle (tick=%0d).", tick);
            else
                $display("    AR and AW accepted in different cycles (%0d ticks).",
                         tick - t_issue);

            axi.b_i_ready = 1'b1;
            while (!axi.b_i_valid) begin @(posedge clk); #1; end
            @(posedge clk); #1;
            axi.b_i_ready = 1'b0;
            sim_wr_cmp++;

            axi.r_ready = 1'b1;
            while (!axi.r_valid) begin @(posedge clk); #1; end
            got = norm_data(longint'(axi.r_i.data));
            @(posedge clk); #1;
            axi.r_ready = 1'b0;
            sim_rd_cmp++;

            exp = norm_data(simul_rd_addr);
            if (got === exp) begin
                sim_func_ok++;
                $display("    Simul-read  OK : got=0x%016h", got);
            end else begin
                sim_func_fail++;
                $display("    Simul-read  MISMATCH: got=0x%016h exp=0x%016h", got, exp);
            end

            axi.ar_o_valid  = 1'b1;
            axi.ar_o.addr   = ARADDR'(simul_wr_addr);
            axi.ar_o.id = MID_ARID'(1);
            axi.ar_o.size   = AXI_SIZE;
            axi.ar_o.len    = 4'h0;
            axi.ar_o.burst  = 2'b01;
            @(posedge clk); #1;
            while (!axi.ar_o_ready) begin @(posedge clk); #1; end
            axi.ar_o_valid = 1'b0;
            sim_rd_acc++;

            axi.r_ready = 1'b1;
            while (!axi.r_valid) begin @(posedge clk); #1; end
            got = norm_data(longint'(axi.r_i.data));
            @(posedge clk); #1;
            axi.r_ready = 1'b0;
            sim_rd_cmp++;

            exp = norm_data(simul_wr_data);
            if (got === exp) begin
                sim_func_ok++;
                $display("    Read-back   OK : got=0x%016h", got);
            end else begin
                sim_func_fail++;
                $display("    Read-back   MISMATCH: got=0x%016h exp=0x%016h", got, exp);
            end
        end

        // [8] Multi-beat INCR bursts
        $display("[8] Multi-beat INCR bursts ...");

        $display("  [8a] 4-beat write burst at 0x%08h (len=3, size=%0d)", BURST4_BASE, AXI_SIZE);
        axi_write_burst(BURST4_BASE, burst4_pattern(), 3, AXI_SIZE, MID_AWID'(0));
        $display("  [8b] 4-beat read burst  at 0x%08h", BURST4_BASE);
        axi_read_burst(BURST4_BASE, 3, AXI_SIZE, MID_ARID'(0));
        $display("    4-beat: rd_ok=%0d  rd_fail=%0d", burst_rd_ok, burst_rd_fail);

        $display("  [8c] 8-beat write burst at 0x%08h (len=7, size=%0d)", BURST8_BASE, AXI_SIZE);
        axi_write_burst(BURST8_BASE, burst8_pattern(), 7, AXI_SIZE, MID_AWID'(1));
        $display("  [8d] 8-beat read burst  at 0x%08h", BURST8_BASE);
        axi_read_burst(BURST8_BASE, 7, AXI_SIZE, MID_ARID'(1));
        $display("    8-beat: rd_ok=%0d  rd_fail=%0d",
                 burst_rd_ok - (burst_rd_ok >= 4 ? 4 : burst_rd_ok),
                 burst_rd_fail);

        $display("  [8] Total burst rd_ok=%0d/12  rd_fail=%0d  wr_ok=%0d  wr_fail=%0d",
                 burst_rd_ok, burst_rd_fail, burst_wr_ok, burst_wr_fail);

        // [9] FIXED burst — all 4 beats go to the same address, last write wins.
        //   4-beat write then read; every read beat should return base_data+3.
        $display("[9] FIXED burst ...");
        begin
            longint fixed_addr, fixed_base_data;
            fixed_addr      = FIXED_BASE;
            fixed_base_data = 64'hF1F1_0000_0000_0000;

            $display("  [9a] 4-beat FIXED write at 0x%08h (all beats → same addr)", fixed_addr);
            axi_write_burst_typed(fixed_addr, fixed_base_data, 3, 3'b101, 2'b00, MID_AWID'(0));
            // shadow[fixed_addr] = fixed_base_data+3 = 0xF1F1_0000_0000_0003

            $display("  [9a] 4-beat FIXED read  at 0x%08h (expect 0x%016h x4)",
                     fixed_addr, shadow[fixed_addr]);
            axi_read_burst_typed(fixed_addr, 3, 3'b101, 2'b00, MID_ARID'(0),
                                 fixed_ok, fixed_fail);
            $display("    FIXED: OK=%0d/4  FAIL=%0d", fixed_ok, fixed_fail);
        end

        // [10] WRAP burst — 4 beats, 32 B/beat, 128-byte boundary.
        //   Start at +0x40: beats land at +0x40, +0x60, +0x00 (wrap), +0x20.
        $display("[10] WRAP burst ...");
        begin
            longint wrap_start, wrap_base_data;
            // Start mid-region: offset 64 within a 128-byte (4*32) wrap boundary
            wrap_start     = WRAP_BASE + 64'h40;
            wrap_base_data = 64'hC0DE_0000_0000_0000;

            $display("  [10a] 4-beat WRAP write at 0x%08h (wrap_len=128B, starts mid-region)",
                     wrap_start);
            axi_write_burst_typed(wrap_start, wrap_base_data, 3, 3'b101, 2'b10, MID_AWID'(1));
            // Beat addresses (verified against burst_beat_addr formula):
            //   0: WRAP_BASE+0x40  data=0xC0DE_...0000
            //   1: WRAP_BASE+0x60  data=0xC0DE_...0001
            //   2: WRAP_BASE+0x00  data=0xC0DE_...0002  (wrapped)
            //   3: WRAP_BASE+0x20  data=0xC0DE_...0003

            $display("  [10a] 4-beat WRAP read  at 0x%08h", wrap_start);
            axi_read_burst_typed(wrap_start, 3, 3'b101, 2'b10, MID_ARID'(1),
                                 wrap_ok, wrap_fail);
            $display("    WRAP:  OK=%0d/4  FAIL=%0d", wrap_ok, wrap_fail);
        end

        // [11] SR FIFO pipeline: fire NUM_PIPE ARs with r_i_ready=0, then drain.
        //   Unwritten addresses return addr-as-data; responses may arrive out of order.
        $display("[11] Multiple outstanding reads: %0d ARs pipelined (r_i_ready=0) ...", NUM_PIPE);
        begin
            // --- Phase A: issue all ARs back-to-back, r_i_ready=0 ---
            axi.r_ready = 1'b0;
            for (int i = 0; i < NUM_PIPE; i++) begin
                longint paddr;
                paddr = PIPE_BASE + longint'(i) * STRIDE;

                axi.ar_o_valid  = 1'b1;
                axi.ar_o.addr   = ARADDR'(paddr);
                axi.ar_o.id = MID_ARID'(i % (1 << MID_ARID));
                axi.ar_o.size   = 3'b011;
                axi.ar_o.len    = 4'h0;
                axi.ar_o.burst  = 2'b01;

                @(posedge clk); #1;
                while (!axi.ar_o_ready) begin @(posedge clk); #1; end
                axi.ar_o_valid = 1'b0;
                pipe_acc++;
            end
            $display("    All %0d ARs accepted. Draining SR FIFO ...", pipe_acc);

            // --- Phase B: drain all responses, verify data = addr ---
            axi.r_ready = 1'b1;
            for (int i = 0; i < NUM_PIPE; i++) begin
                longint got_d;
                while (!axi.r_valid) begin @(posedge clk); #1; end
                got_d = longint'(axi.r_i.data);
                @(posedge clk); #1;
                pipe_cmp++;
                // Unwritten region: wrapper returns addr as data.
                // Responses may arrive out-of-order; verify got_d is
                // one of the valid PIPE_BASE addresses.
                if (got_d >= PIPE_BASE &&
                    got_d < PIPE_BASE + longint'(NUM_PIPE) * STRIDE &&
                    ((got_d - PIPE_BASE) % STRIDE) == 0) begin
                    pipe_ok++;
                    $display("    pipe R[%0d] data=0x%016h OK", i, got_d);
                end else begin
                    pipe_fail++;
                    $display("    pipe R[%0d] data=0x%016h MISMATCH (not in expected set)", i, got_d);
                end
            end
            axi.r_ready = 1'b0;
            $display("    Pipeline: acc=%0d  cmp=%0d  OK=%0d  FAIL=%0d",
                     pipe_acc, pipe_cmp, pipe_ok, pipe_fail);
        end

        // [12] WSTRB: wrapper merges bytes before Ramulator sees the write.
        //   lower-half mask, upper-half mask, zero strobe (no-op), single byte.
        $display("[12] WSTRB byte masking ...");
        begin
            longint got, exp;

            // [12a] Lower-half mask: establish full word, then update bytes 0-3 only
            axi_write_strb(STRB_BASE,          64'hDEADBEEF_12345678, 8'hFF, MID_AWID'(0));
            axi_write_strb(STRB_BASE,          64'hAAAAAAAA_BBBBBBBB, 8'h0F, MID_AWID'(0));
            exp = 64'hDEADBEEF_BBBBBBBB;  // bytes 4-7 from 1st write, bytes 0-3 from 2nd
            axi_read_raw(STRB_BASE, MID_ARID'(0), got);
            if (got === exp) begin
                strb_ok++;
                $display("  [12a] lower-half mask OK  got=0x%016h", got);
            end else begin
                strb_fail++;
                $display("  [12a] lower-half mask FAIL got=0x%016h exp=0x%016h", got, exp);
            end

            // [12b] Upper-half mask: establish full word, then update bytes 4-7 only
            axi_write_strb(STRB_BASE+STRIDE,   64'h11111111_22222222, 8'hFF, MID_AWID'(0));
            axi_write_strb(STRB_BASE+STRIDE,   64'h99999999_00000000, 8'hF0, MID_AWID'(0));
            exp = 64'h99999999_22222222;  // bytes 4-7 from 2nd write, bytes 0-3 from 1st
            axi_read_raw(STRB_BASE+STRIDE, MID_ARID'(0), got);
            if (got === exp) begin
                strb_ok++;
                $display("  [12b] upper-half mask OK  got=0x%016h", got);
            end else begin
                strb_fail++;
                $display("  [12b] upper-half mask FAIL got=0x%016h exp=0x%016h", got, exp);
            end

            // [12c] Zero strobe: write should be a complete no-op for data
            axi_write_strb(STRB_BASE+2*STRIDE, 64'h5A5A5A5A_5A5A5A5A, 8'hFF, MID_AWID'(0));
            axi_write_strb(STRB_BASE+2*STRIDE, 64'hFFFFFFFF_FFFFFFFF, 8'h00, MID_AWID'(0));
            exp = 64'h5A5A5A5A_5A5A5A5A;  // unchanged
            axi_read_raw(STRB_BASE+2*STRIDE, MID_ARID'(0), got);
            if (got === exp) begin
                strb_ok++;
                $display("  [12c] zero strobe OK      got=0x%016h", got);
            end else begin
                strb_fail++;
                $display("  [12c] zero strobe FAIL    got=0x%016h exp=0x%016h", got, exp);
            end

            // [12d] Single-byte strobe to fresh address (shadow defaults to 0)
            //   data=0xFEDCBA98_76543210, strb=0x01 → only byte 0 = 0x10
            axi_write_strb(STRB_BASE+3*STRIDE, 64'hFEDCBA98_76543210, 8'h01, MID_AWID'(0));
            exp = 64'h0000000000000010;
            axi_read_raw(STRB_BASE+3*STRIDE, MID_ARID'(0), got);
            if (got === exp) begin
                strb_ok++;
                $display("  [12d] single-byte OK      got=0x%016h", got);
            end else begin
                strb_fail++;
                $display("  [12d] single-byte FAIL    got=0x%016h exp=0x%016h", got, exp);
            end

            $display("  WSTRB: OK=%0d/4  FAIL=%0d", strb_ok, strb_fail);
        end

        // ============================================================
        // [13] Summary
        // ============================================================
        $display("\n--- Summary ---");
        $display("  Total ticks   : %0d", tick);
        if (USE_MEMINIT)
            $display("  [2] Writes    : SKIPPED (meminit active — shadow pre-loaded)");
        else
            $display("  [2] Writes    : acc=%0d/%0d  B-acks=%0d/%0d  lat(min/max/avg)=%0d/%0d/%0d",
                     wr_acc, NUM_WR, wr_cmp, NUM_WR,
                     wr_lat_min, wr_lat_max, wr_lat_total / (wr_cmp > 0 ? wr_cmp : 1));
        $display("  [3-4] Reads   : acc=%0d/%0d  R-data=%0d/%0d  lat(min/max/avg)=%0d/%0d/%0d",
                 rd_acc, total_rd, rd_cmp, total_rd,
                 rd_lat_min, rd_lat_max, rd_lat_total / (rd_cmp > 0 ? rd_cmp : 1));
        $display("  [3-4] Functional: OK=%0d/%0d  FAIL=%0d",
                 func_ok, total_rd, func_fail);
        $display("  [5] RD flood  : ARs acc=%0d/%0d  R drained=%0d/%0d  max_stall=%0d cycles",
                 flood_acc, NUM_FLOOD, flood_cmp, NUM_FLOOD, flood_stall_max);
        $display("  [6] WR BP     : writes acc=%0d/%0d  B-acks=%0d/%0d  stall=%0d cycles",
                 bp_wr_acc, B_DEPTH + 1, bp_wr_cmp, B_DEPTH + 1, bp_stall);
        $display("  [7] Simul     : rd acc=%0d/2  rd cmp=%0d/2  wr acc=%0d/1  wr cmp=%0d/1  func OK=%0d  FAIL=%0d",
                 sim_rd_acc, sim_rd_cmp, sim_wr_acc, sim_wr_cmp, sim_func_ok, sim_func_fail);
        $display("  [8]  INCR     : rd_ok=%0d/12  rd_fail=%0d  wr_fail=%0d",
                 burst_rd_ok, burst_rd_fail, burst_wr_fail);
        $display("  [9]  FIXED    : OK=%0d/4  FAIL=%0d",
                 fixed_ok, fixed_fail);
        $display("  [10] WRAP     : OK=%0d/4  FAIL=%0d",
                 wrap_ok, wrap_fail);
        $display("  [11] SR FIFO  : acc=%0d/%0d  cmp=%0d/%0d  OK=%0d  FAIL=%0d",
                 pipe_acc, NUM_PIPE, pipe_cmp, NUM_PIPE, pipe_ok, pipe_fail);
        $display("  [12] WSTRB    : OK=%0d/4  FAIL=%0d",
                 strb_ok, strb_fail);

        if ((USE_MEMINIT ? (wr_acc == 0 && wr_cmp == 0)
                         : (wr_acc == NUM_WR && wr_cmp == NUM_WR)) &&
            rd_acc    == total_rd  && rd_cmp  == total_rd  &&
            func_fail == 0         &&
            flood_acc == NUM_FLOOD && flood_cmp == NUM_FLOOD &&
            bp_wr_acc == B_DEPTH + 1 && bp_wr_cmp == B_DEPTH + 1 &&
            bp_stall  >= BP_HOLD   &&
            sim_rd_acc == 2        && sim_rd_cmp == 2       &&
            sim_wr_acc == 1        && sim_wr_cmp == 1       &&
            sim_func_fail == 0     &&
            burst_rd_ok == 12      && burst_rd_fail == 0    &&
            burst_wr_fail == 0     &&
            pipe_acc == NUM_PIPE   && pipe_cmp == NUM_PIPE  &&
            pipe_ok == NUM_PIPE    && pipe_fail == 0        &&
            strb_ok == 4           && strb_fail == 0        &&
            fixed_ok == 4          && fixed_fail == 0       &&
            wrap_ok == 4           && wrap_fail == 0)
        begin
            $display("\n=== PASSED ===");
            ramulator_exit(0);
        end else begin
            $display("\n=== FAILED ===");
            ramulator_exit(1);
        end
    end

    // ----------------------------------------------------------------
    // Watchdog
    // ----------------------------------------------------------------
    initial begin : watchdog
        repeat(MAX_CYCLES) @(posedge clk);
        $display("WATCHDOG: simulation exceeded %0d cycles — aborting.", MAX_CYCLES);
        ramulator_exit(1);
    end

endmodule
