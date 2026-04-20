// test_ramulator.sv — AXI-bus-integrated ramulator wrapper testbench
// Xinyu Liu - liuxinyujames@gmail.com
//
// Instantiates the AXI bus RTL between per-master request drivers and the
// ramulator wrapper. TB drives master-side signals only (ar_{sp0,sp1,d,i}_*,
// sp{0,1,d}_i_valid/aw_/w_, r_*_o_ready, b_*_o_ready). The axi module
// (axi_read + axi_write_top) owns arbitration and response routing; the
// wrapper is the memory controller subordinate.
//
// Phases:
//   [1]  Reset + init
//   [2]  Writes striped across {SP0,SP1,D}
//   [3]  Read-after-write striped across {SP0,SP1,D,I}
//   [4]  Raw reads striped across {SP0,SP1,D,I}
//   [5]  RD flood with per-master r_*_o_ready=0; drain
//   [6]  WR backpressure on SP0 (b_sp0_o_ready=0)
//   [7]  Simultaneous R (SP0)+W (SP1) then swapped
//   [8]  INCR bursts, round-robin {SP0,SP1,D}
//   [9]  FIXED burst (SP0 write, SP0 read)
//   [10] WRAP burst (SP1 write, SP1 read)
//   [11] Multiple outstanding reads striped across all 4 read masters
//   [12] WSTRB byte masking (SP0)
//   [13] Summary

`timescale 1ns / 1ps

module test_ramulator #(
    parameter string  CFG          = "rtl/modules/memory/ramulator_wrapper/configs/ddr4_config.yaml",
    parameter string  MEMINIT_FILE = "",
    parameter string  MEMINIT_TYPE = "hex",
    parameter longint MEMINIT_BASE = 0,
    parameter bit     USE_MEMINIT  = 0
);
    import axi_bus_pkg::*;

    localparam logic [2:0] AXI_SIZE = 3'b101; // 32 bytes/beat

    // ------------------------------------------------------------
    // Helpers
    // ------------------------------------------------------------
    function automatic longint wr_pattern(input int i);   return 64'hC0FF_EE00_0000_0000 | longint'(i); endfunction
    function automatic longint bp_pattern_a(input int i); return 64'hAAAA_0000_0000_0000 | longint'(i); endfunction
    function automatic longint bp_pattern_b(input int i); return 64'hBBBB_0000_0000_0000 | longint'(i); endfunction
    function automatic longint simul_pattern();           return 64'hFEED_FACE_CAFE_BABE; endfunction
    function automatic longint burst4_pattern();          return 64'hCAFE_0000_0050_0000; endfunction
    function automatic longint burst8_pattern();          return 64'hDEAD_0000_0060_0000; endfunction

    import "DPI-C" function void ramulator_exit(input int code);

    // ----------------------------------------------------------------
    // Parameters
    // ----------------------------------------------------------------
    localparam int     NUM_WR       = 16;
    localparam int     NUM_RD_RAW   = 8;
    localparam int     NUM_FLOOD    = 48;
    localparam int     B_DEPTH      = 4;
    localparam int     BP_HOLD      = 20;
    localparam int     MAX_CYCLES   = 2_000_000;
    localparam longint WR_BASE      = 64'h0000_0000;
    localparam longint RD_BASE      = 64'h0010_0000;
    localparam longint FLOOD_BASE   = 64'h0020_0000;
    localparam longint BP_WR_BASE   = 64'h0030_0000;
    localparam longint SIMUL_BASE   = 64'h0040_0000;
    localparam longint BURST4_BASE  = 64'h0050_0000;
    localparam longint BURST8_BASE  = 64'h0060_0000;
    localparam longint PIPE_BASE    = 64'h0070_0000;
    localparam longint STRB_BASE    = 64'h0080_0000;
    localparam longint FIXED_BASE   = 64'h0090_0000;
    localparam longint WRAP_BASE    = 64'h00A0_0000;
    localparam longint STRIDE       = 64;
    localparam int     NUM_PIPE     = 16;

    // ----------------------------------------------------------------
    // Clock / reset
    // ----------------------------------------------------------------
    logic clk  = 0;
    logic nrst = 0;
    always #0.625 clk = ~clk;  // 800 MHz

    // ----------------------------------------------------------------
    // AXI bus + DUT
    // ----------------------------------------------------------------
    axi_bus_if axi(.CLK(clk), .nRST(nrst));
    logic init_done;

    axi AXI_DUT (.CLK(clk), .nRST(nrst), .abif(axi));

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
    // Per-master scoreboards
    // read masters:  0=SP0, 1=SP1, 2=D, 3=I
    // write masters: 0=SP0, 1=SP1, 2=D
    // ----------------------------------------------------------------
    longint shadow [longint];

    int     wr_acc  [0:2] = '{0,0,0};
    int     wr_cmp  [0:2] = '{0,0,0};
    longint wr_lat_min [0:2] = '{2_000_000_000,2_000_000_000,2_000_000_000};
    longint wr_lat_max [0:2] = '{0,0,0};
    longint wr_lat_total[0:2] = '{0,0,0};

    int     rd_acc  [0:3] = '{0,0,0,0};
    int     rd_cmp  [0:3] = '{0,0,0,0};
    int     func_ok [0:3] = '{0,0,0,0};
    int     func_fail[0:3]= '{0,0,0,0};
    longint rd_lat_min [0:3] = '{2_000_000_000,2_000_000_000,2_000_000_000,2_000_000_000};
    longint rd_lat_max [0:3] = '{0,0,0,0};
    longint rd_lat_total[0:3] = '{0,0,0,0};

    // [5]
    int     flood_acc[0:3] = '{0,0,0,0};
    int     flood_cmp[0:3] = '{0,0,0,0};
    longint flood_stall_max = 0;

    // [6] — single master (SP0) backpressure
    int     bp_wr_acc = 0, bp_wr_cmp = 0;
    longint bp_stall  = 0;

    // [7] simultaneous
    int     sim_rd_acc = 0, sim_rd_cmp = 0;
    int     sim_wr_acc = 0, sim_wr_cmp = 0;
    int     sim_func_ok = 0, sim_func_fail = 0;

    // [8]
    int     burst_wr_ok = 0, burst_wr_fail = 0;
    int     burst_rd_ok = 0, burst_rd_fail = 0;

    // [11]
    int     pipe_acc[0:3] = '{0,0,0,0};
    int     pipe_cmp[0:3] = '{0,0,0,0};
    int     pipe_ok = 0, pipe_fail = 0;

    // [12]
    int     strb_ok = 0, strb_fail = 0;

    // [9]
    int     fixed_ok = 0, fixed_fail = 0;

    // [10]
    int     wrap_ok = 0, wrap_fail = 0;

    // ----------------------------------------------------------------
    // Per-master drive helpers
    // ----------------------------------------------------------------
    task automatic drv_ar(input int mid, input logic v,
                          input logic [ARADDR-1:0] addr,
                          input logic [ARID-1:0] id,
                          input logic [2:0] size,
                          input logic [3:0] len,
                          input logic [1:0] burst);
        master_ar_channel_t a;
        a.addr = addr; a.id = id; a.size = size; a.len = len; a.burst = burst;
        case (mid)
            0: begin axi.ar_sp0_valid = v; axi.ar_sp0_i = a; end
            1: begin axi.ar_sp1_valid = v; axi.ar_sp1_i = a; end
            2: begin axi.ar_d_valid   = v; axi.ar_d_i   = a; end
            3: begin axi.ar_i_valid   = v; axi.ar_i_i   = a; end
        endcase
    endtask

    function automatic logic get_ar_ready(input int mid);
        case (mid)
            0: return axi.ar_sp0_ready;
            1: return axi.ar_sp1_ready;
            2: return axi.ar_d_ready;
            3: return axi.ar_i_ready;
            default: return 0;
        endcase
    endfunction

    task automatic drv_r_ready(input int mid, input logic v);
        case (mid)
            0: axi.r_sp0_o_ready = v;
            1: axi.r_sp1_o_ready = v;
            2: axi.r_d_o_ready   = v;
            3: axi.r_i_o_ready   = v;
        endcase
    endtask

    function automatic logic get_r_valid(input int mid);
        case (mid)
            0: return axi.r_sp0_o_valid;
            1: return axi.r_sp1_o_valid;
            2: return axi.r_d_o_valid;
            3: return axi.r_i_o_valid;
            default: return 0;
        endcase
    endfunction

    function automatic master_r_channel_t get_r(input int mid);
        case (mid)
            0: return axi.r_sp0_o;
            1: return axi.r_sp1_o;
            2: return axi.r_d_o;
            3: return axi.r_i_o;
            default: return '0;
        endcase
    endfunction

    task automatic drv_wr(input int mid, input logic v,
                          input logic [AWADDR-1:0] addr,
                          input logic [AWID-1:0] id,
                          input logic [2:0] size,
                          input logic [3:0] len,
                          input logic [1:0] burst,
                          input logic [WDATA-1:0] data,
                          input logic [WSTRB-1:0] strb,
                          input logic last);
        master_aw_channel_t aw;
        master_w_channel_t  w;
        aw.addr = addr; aw.id = id; aw.size = size; aw.len = len; aw.burst = burst;
        w.data = data; w.id = id; w.strb = strb; w.last = last;
        case (mid)
            0: begin axi.sp0_i_valid = v; axi.aw_sp0_i = aw; axi.w_sp0_i = w; end
            1: begin axi.sp1_i_valid = v; axi.aw_sp1_i = aw; axi.w_sp1_i = w; end
            2: begin axi.d_i_valid   = v; axi.aw_d_i   = aw; axi.w_d_i   = w; end
        endcase
    endtask

    function automatic logic get_wr_ready(input int mid);
        case (mid)
            0: return axi.sp0_wr_ready;
            1: return axi.sp1_wr_ready;
            2: return axi.d_wr_ready;
            default: return 0;
        endcase
    endfunction

    task automatic drv_b_ready(input int mid, input logic v);
        case (mid)
            0: axi.b_sp0_o_ready = v;
            1: axi.b_sp1_o_ready = v;
            2: axi.b_d_o_ready   = v;
        endcase
    endtask

    function automatic logic get_b_valid(input int mid);
        case (mid)
            0: return axi.b_sp0_o_valid;
            1: return axi.b_sp1_o_valid;
            2: return axi.b_d_o_valid;
            default: return 0;
        endcase
    endfunction

    // ----------------------------------------------------------------
    // High-level tasks
    // ----------------------------------------------------------------
    task automatic axi_write(
        input int                  mid,
        input longint              addr,
        input logic [WDATA-1:0]    data,
        input logic [AWID-1:0]     id
    );
        longint t0, lat;
        t0 = tick;

        drv_wr(mid, 1'b1, AWADDR'(addr), id, AXI_SIZE, 4'h0, 2'b01, data, '1, 1'b1);
        @(posedge clk); #1;
        while (!get_wr_ready(mid)) begin @(posedge clk); #1; end
        drv_wr(mid, 1'b0, '0, '0, '0, '0, '0, '0, '0, 1'b0);
        wr_acc[mid]++;
        shadow[addr] = longint'(data);

        drv_b_ready(mid, 1'b1);
        while (!get_b_valid(mid)) begin @(posedge clk); #1; end
        @(posedge clk); #1;
        drv_b_ready(mid, 1'b0);
        wr_cmp[mid]++;

        lat = tick - t0;
        if (lat < wr_lat_min[mid])   wr_lat_min[mid]   = lat;
        if (lat > wr_lat_max[mid])   wr_lat_max[mid]   = lat;
        wr_lat_total[mid] += lat;
    endtask

    task automatic axi_read(
        input  int                  mid,
        input  longint              addr,
        input  logic [ARID-1:0]     id,
        output longint              got_data
    );
        longint t0, lat;
        master_r_channel_t rr;
        t0 = tick;

        drv_ar(mid, 1'b1, ARADDR'(addr), id, AXI_SIZE, 4'h0, 2'b01);
        @(posedge clk); #1;
        while (!get_ar_ready(mid)) begin @(posedge clk); #1; end
        drv_ar(mid, 1'b0, '0, '0, '0, '0, '0);
        rd_acc[mid]++;

        drv_r_ready(mid, 1'b1);
        while (!get_r_valid(mid)) begin @(posedge clk); #1; end
        rr = get_r(mid);
        got_data = longint'(rr.data);
        @(posedge clk); #1;
        drv_r_ready(mid, 1'b0);
        rd_cmp[mid]++;

        lat = tick - t0;
        if (lat < rd_lat_min[mid]) rd_lat_min[mid] = lat;
        if (lat > rd_lat_max[mid]) rd_lat_max[mid] = lat;
        rd_lat_total[mid] += lat;
    endtask

    task automatic axi_ar_send(
        input  int                  mid,
        input  longint              addr,
        input  logic [ARID-1:0]     id,
        output longint              stall_cycles
    );
        longint t0;
        t0 = tick;
        drv_ar(mid, 1'b1, ARADDR'(addr), id, AXI_SIZE, 4'h0, 2'b01);
        @(posedge clk); #1;
        while (!get_ar_ready(mid)) begin @(posedge clk); #1; end
        drv_ar(mid, 1'b0, '0, '0, '0, '0, '0);
        stall_cycles = tick - t0;
        flood_acc[mid]++;
    endtask

    task automatic axi_r_collect(input int mid, output longint got_data);
        master_r_channel_t rr;
        drv_r_ready(mid, 1'b1);
        while (!get_r_valid(mid)) begin @(posedge clk); #1; end
        rr = get_r(mid);
        got_data = longint'(rr.data);
        @(posedge clk); #1;
        drv_r_ready(mid, 1'b0);
        flood_cmp[mid]++;
    endtask

    task automatic axi_aw_nb(
        input  int                  mid,
        input  longint              addr,
        input  logic [WDATA-1:0]    data,
        input  logic [AWID-1:0]     id,
        output longint              stall_cycles
    );
        longint t0;
        t0 = tick;
        drv_wr(mid, 1'b1, AWADDR'(addr), id, AXI_SIZE, 4'h0, 2'b01, data, '1, 1'b1);
        @(posedge clk); #1;
        while (!get_wr_ready(mid)) begin @(posedge clk); #1; end
        drv_wr(mid, 1'b0, '0, '0, '0, '0, '0, '0, '0, 1'b0);
        shadow[addr] = longint'(data);
        bp_wr_acc++;
        stall_cycles = tick - t0;
    endtask

    task automatic axi_write_burst_typed(
        input  int                  mid,
        input  longint              base_addr,
        input  longint              base_data,
        input  int                  len,
        input  logic [2:0]          size,
        input  logic [1:0]          burst,
        input  logic [AWID-1:0]     id
    );
        int     stride, num_beats;
        longint beat_addr, wlen, wmask, aln;
        stride    = 1 << int'(size);
        num_beats = len + 1;

        // beat 0 = AW + W together (single-valid master protocol)
        drv_wr(mid, 1'b1, AWADDR'(base_addr), id, size, len[3:0], burst,
               WDATA'(base_data), '1, (len == 0) ? 1'b1 : 1'b0);
        @(posedge clk); #1;
        while (!get_wr_ready(mid)) begin @(posedge clk); #1; end
        shadow[base_addr] = base_data;

        for (int i = 1; i <= len; i++) begin
            longint bdata;
            bdata = base_data + longint'(i);
            case (burst)
                2'b00: beat_addr = base_addr;
                2'b10: begin
                    wlen      = longint'(num_beats) * longint'(stride);
                    wmask     = wlen - 1;
                    aln       = base_addr & ~wmask;
                    beat_addr = aln + ((base_addr - aln
                                        + longint'(i) * longint'(stride)) & wmask);
                end
                default: beat_addr = base_addr + longint'(i) * longint'(stride);
            endcase

            // sustained valid across beats; bus mgr uses in_burst state
            drv_wr(mid, 1'b1, AWADDR'(base_addr), id, size, len[3:0], burst,
                   WDATA'(bdata), '1, (i == len) ? 1'b1 : 1'b0);
            @(posedge clk); #1;
            while (!get_wr_ready(mid)) begin @(posedge clk); #1; end
            shadow[beat_addr] = bdata;
        end
        drv_wr(mid, 1'b0, '0, '0, '0, '0, '0, '0, '0, 1'b0);
        burst_wr_ok++;

        drv_b_ready(mid, 1'b1);
        while (!get_b_valid(mid)) begin @(posedge clk); #1; end
        @(posedge clk); #1;
        drv_b_ready(mid, 1'b0);
    endtask

    task automatic axi_read_burst_typed(
        input  int                  mid,
        input  longint              base_addr,
        input  int                  len,
        input  logic [2:0]          size,
        input  logic [1:0]          burst,
        input  logic [ARID-1:0]     id,
        ref    int                  ok_cnt,
        ref    int                  fail_cnt
    );
        int     stride, num_beats;
        longint beat_addr, got, exp, wlen, wmask, aln;
        logic   got_last;
        master_r_channel_t rr;
        stride    = 1 << int'(size);
        num_beats = len + 1;

        drv_ar(mid, 1'b1, ARADDR'(base_addr), id, size, len[3:0], burst);
        @(posedge clk); #1;
        while (!get_ar_ready(mid)) begin @(posedge clk); #1; end
        drv_ar(mid, 1'b0, '0, '0, '0, '0, '0);

        for (int i = 0; i <= len; i++) begin
            case (burst)
                2'b00: beat_addr = base_addr;
                2'b10: begin
                    wlen      = longint'(num_beats) * longint'(stride);
                    wmask     = wlen - 1;
                    aln       = base_addr & ~wmask;
                    beat_addr = aln + ((base_addr - aln
                                        + longint'(i) * longint'(stride)) & wmask);
                end
                default: beat_addr = base_addr + longint'(i) * longint'(stride);
            endcase

            drv_r_ready(mid, 1'b1);
            while (!get_r_valid(mid)) begin @(posedge clk); #1; end
            rr       = get_r(mid);
            got      = longint'(rr.data);
            got_last = rr.last;
            @(posedge clk); #1;
            drv_r_ready(mid, 1'b0);

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

    task automatic axi_write_strb(
        input int                  mid,
        input longint              addr,
        input logic [WDATA-1:0]    data,
        input logic [WSTRB-1:0]    strb,
        input logic [AWID-1:0]     id
    );
        drv_wr(mid, 1'b1, AWADDR'(addr), id, 3'b011, 4'h0, 2'b01, data, strb, 1'b1);
        @(posedge clk); #1;
        while (!get_wr_ready(mid)) begin @(posedge clk); #1; end
        drv_wr(mid, 1'b0, '0, '0, '0, '0, '0, '0, '0, 1'b0);

        drv_b_ready(mid, 1'b1);
        while (!get_b_valid(mid)) begin @(posedge clk); #1; end
        @(posedge clk); #1;
        drv_b_ready(mid, 1'b0);
    endtask

    task automatic axi_read_raw(
        input  int                  mid,
        input  longint              addr,
        input  logic [ARID-1:0]     id,
        output longint              got_data
    );
        master_r_channel_t rr;
        drv_ar(mid, 1'b1, ARADDR'(addr), id, 3'b011, 4'h0, 2'b01);
        @(posedge clk); #1;
        while (!get_ar_ready(mid)) begin @(posedge clk); #1; end
        drv_ar(mid, 1'b0, '0, '0, '0, '0, '0);

        drv_r_ready(mid, 1'b1);
        while (!get_r_valid(mid)) begin @(posedge clk); #1; end
        rr = get_r(mid);
        got_data = longint'(rr.data);
        @(posedge clk); #1;
        drv_r_ready(mid, 1'b0);
    endtask

    // ----------------------------------------------------------------
    // Reset defaults
    // ----------------------------------------------------------------
    task automatic reset_master_drives();
        axi.ar_sp0_valid = 1'b0; axi.ar_sp0_i = '0;
        axi.ar_sp1_valid = 1'b0; axi.ar_sp1_i = '0;
        axi.ar_d_valid   = 1'b0; axi.ar_d_i   = '0;
        axi.ar_i_valid   = 1'b0; axi.ar_i_i   = '0;
        axi.r_sp0_o_ready = 1'b0;
        axi.r_sp1_o_ready = 1'b0;
        axi.r_d_o_ready   = 1'b0;
        axi.r_i_o_ready   = 1'b0;
        axi.sp0_i_valid = 1'b0; axi.aw_sp0_i = '0; axi.w_sp0_i = '0;
        axi.sp1_i_valid = 1'b0; axi.aw_sp1_i = '0; axi.w_sp1_i = '0;
        axi.d_i_valid   = 1'b0; axi.aw_d_i   = '0; axi.w_d_i   = '0;
        axi.b_sp0_o_ready = 1'b0;
        axi.b_sp1_o_ready = 1'b0;
        axi.b_d_o_ready   = 1'b0;
    endtask

    // ----------------------------------------------------------------
    // Main test
    // ----------------------------------------------------------------
    initial begin : main
        longint got, exp;
        int     total_rd_acc, total_rd_cmp, total_func_ok, total_func_fail;
        int     total_wr_acc, total_wr_cmp;
        int     total_flood_acc, total_flood_cmp;
        int     total_pipe_acc, total_pipe_cmp;

        reset_master_drives();

        nrst = 1'b0;
        repeat(4) @(posedge clk);
        nrst = 1'b1;

        $display("=== AXI Ramulator wrapper + AXI bus integration smoketest ===");
        $display("Config : %s", CFG);
        $write("[1] ramulator_init ... ");
        wait(init_done);
        @(posedge clk); #1;
        $display("OK");

        $display("    Mode: 256-bit AXI (32-byte beats, AXI_SIZE=%0d); 4 RD masters, 3 WR masters", AXI_SIZE);

        // ============================================================
        // [2] Writes striped across SP0/SP1/D
        // ============================================================
        if (USE_MEMINIT) begin
            $display("[2] (meminit active) Skipping AXI writes — pre-loading shadow for [3] ...");
            for (int i = 0; i < NUM_WR; i++)
                shadow[WR_BASE + longint'(i) * STRIDE] = wr_pattern(i);
        end else begin
            $display("[2] %0d writes round-robin across {SP0,SP1,D} ...", NUM_WR);
            for (int i = 0; i < NUM_WR; i++) begin
                int wmid;
                wmid = i % 3;
                axi_write(wmid,
                          WR_BASE + longint'(i) * STRIDE,
                          WDATA'(wr_pattern(i)),
                          AWID'(i % (1 << AWID)));
            end
            $display("    SP0 acc/cmp=%0d/%0d  SP1=%0d/%0d  D=%0d/%0d",
                     wr_acc[0], wr_cmp[0], wr_acc[1], wr_cmp[1], wr_acc[2], wr_cmp[2]);
        end

        // ============================================================
        // [3] Read-after-write striped across {SP0,SP1,D,I}
        // ============================================================
        $display("[3] %0d reads round-robin across {SP0,SP1,D,I} ...", NUM_WR);
        for (int i = 0; i < NUM_WR; i++) begin
            int rmid;
            rmid = i % 4;
            axi_read(rmid,
                     WR_BASE + longint'(i) * STRIDE,
                     ARID'(i % (1 << ARID)),
                     got);
            exp = shadow[WR_BASE + longint'(i) * STRIDE];
            if (got === exp) func_ok[rmid]++;
            else begin
                $display("  [MISMATCH] i=%0d mid=%0d addr=0x%08h got=0x%016h exp=0x%016h",
                         i, rmid, WR_BASE + longint'(i) * STRIDE, got, exp);
                func_fail[rmid]++;
            end
        end

        // ============================================================
        // [4] Raw reads
        // ============================================================
        $display("[4] %0d raw reads round-robin across {SP0,SP1,D,I} ...", NUM_RD_RAW);
        for (int i = 0; i < NUM_RD_RAW; i++) begin
            int rmid;
            rmid = i % 4;
            axi_read(rmid,
                     RD_BASE + longint'(i) * STRIDE,
                     ARID'(i % (1 << ARID)),
                     got);
            exp = RD_BASE + longint'(i) * STRIDE;
            if (got === exp) func_ok[rmid]++;
            else begin
                $display("  [MISMATCH] i=%0d mid=%0d got=0x%016h exp=0x%016h", i, rmid, got, exp);
                func_fail[rmid]++;
            end
        end

        // ============================================================
        // [5] RD flood — all 4 masters, r_*_o_ready=0 during issue
        // ============================================================
        $display("[5] RD flood: %0d ARs across 4 masters with r_*_o_ready=0 ...", NUM_FLOOD);
        axi.r_sp0_o_ready = 0; axi.r_sp1_o_ready = 0;
        axi.r_d_o_ready   = 0; axi.r_i_o_ready   = 0;
        for (int i = 0; i < NUM_FLOOD; i++) begin
            longint stall;
            int rmid;
            rmid = i % 4;
            axi_ar_send(rmid,
                        FLOOD_BASE + longint'(i) * STRIDE,
                        ARID'(i % (1 << ARID)),
                        stall);
            if (stall > flood_stall_max) flood_stall_max = stall;
        end
        $display("    accepted: SP0=%0d SP1=%0d D=%0d I=%0d  max_stall=%0d",
                 flood_acc[0], flood_acc[1], flood_acc[2], flood_acc[3], flood_stall_max);

        // Drain: for each issued AR per master, collect one R response
        for (int m = 0; m < 4; m++) begin
            while (flood_cmp[m] < flood_acc[m]) begin
                longint d; axi_r_collect(m, d);
            end
        end
        $display("    drained: SP0=%0d SP1=%0d D=%0d I=%0d",
                 flood_cmp[0], flood_cmp[1], flood_cmp[2], flood_cmp[3]);

        // ============================================================
        // [6] WR backpressure on SP0 (b_sp0_o_ready=0)
        // ============================================================
        $display("[6] WR backpressure on SP0: b_sp0_o_ready=0, fill then stall ...");
        axi.b_sp0_o_ready = 0;

        // Fire B_DEPTH writes; they should be accepted (bus + wrapper absorb them)
        for (int i = 0; i < B_DEPTH; i++) begin
            longint stall;
            axi_aw_nb(0,
                      BP_WR_BASE + longint'(i) * STRIDE,
                      WDATA'(bp_pattern_a(i)),
                      AWID'(i % (1 << AWID)),
                      stall);
            $display("    sp0 wr[%0d] accepted (stall=%0d)", i, stall);
        end

        // Drive one more write; expect sp0_wr_ready=0 for a while
        $display("    driving overflow write with b_sp0_o_ready=0 ...");
        drv_wr(0, 1'b1,
               AWADDR'(BP_WR_BASE + longint'(B_DEPTH) * STRIDE),
               AWID'(B_DEPTH % (1 << AWID)),
               AXI_SIZE, 4'h0, 2'b01,
               WDATA'(bp_pattern_b(B_DEPTH)), '1, 1'b1);
        begin
            int early_ready;
            early_ready = 0;
            repeat(BP_HOLD) begin
                @(posedge clk); #1;
                if (axi.sp0_wr_ready) early_ready++;
                bp_stall++;
            end
            if (early_ready == 0)
                $display("    sp0_wr_ready held low for %0d cycles (FIFO pressure OK).", bp_stall);
            else
                $display("    [WARN] sp0_wr_ready pulsed %0d times during stall window.", early_ready);
        end

        // Release and let it land
        axi.b_sp0_o_ready = 1;
        @(posedge clk); #1;
        while (!axi.sp0_wr_ready) begin @(posedge clk); #1; end
        drv_wr(0, 1'b0, '0, '0, '0, '0, '0, '0, '0, 1'b0);
        shadow[BP_WR_BASE + longint'(B_DEPTH) * STRIDE] = bp_pattern_b(B_DEPTH);
        bp_wr_acc++;

        // Drain all B responses
        for (int i = 0; i <= B_DEPTH; i++) begin
            while (!axi.b_sp0_o_valid) begin @(posedge clk); #1; end
            @(posedge clk); #1;
            bp_wr_cmp++;
        end
        axi.b_sp0_o_ready = 0;
        $display("    bp_wr_acc=%0d bp_wr_cmp=%0d stall_obs=%0d", bp_wr_acc, bp_wr_cmp, bp_stall);

        // ============================================================
        // [7] Simultaneous R on SP0 + W on SP1 (same cycle)
        // ============================================================
        $display("[7] Simultaneous R (SP0) + W (SP1) ...");
        begin
            bit     ar_done, aw_done;
            longint rd_addr, wr_addr, wr_data, t_issue;
            master_r_channel_t rr;

            rd_addr = SIMUL_BASE;
            wr_addr = SIMUL_BASE + STRIDE;
            wr_data = simul_pattern();
            ar_done = 0; aw_done = 0;

            drv_ar(0, 1'b1, ARADDR'(rd_addr), ARID'(0), AXI_SIZE, 4'h0, 2'b01);
            drv_wr(1, 1'b1, AWADDR'(wr_addr), AWID'(0), AXI_SIZE, 4'h0, 2'b01,
                   WDATA'(wr_data), '1, 1'b1);

            t_issue = tick;
            @(posedge clk); #1;
            while (!ar_done || !aw_done) begin
                if (!ar_done && axi.ar_sp0_ready) begin
                    drv_ar(0, 1'b0, '0, '0, '0, '0, '0);
                    sim_rd_acc++; ar_done = 1;
                end
                if (!aw_done && axi.sp1_wr_ready) begin
                    drv_wr(1, 1'b0, '0, '0, '0, '0, '0, '0, '0, 1'b0);
                    shadow[wr_addr] = wr_data;
                    sim_wr_acc++; aw_done = 1;
                end
                if (!ar_done || !aw_done) begin @(posedge clk); #1; end
            end

            if (tick - t_issue <= 2)
                $display("    AR(SP0) + AW(SP1) accepted in same cycle.");
            else
                $display("    AR/AW split over %0d ticks.", tick - t_issue);

            // Collect B on SP1
            axi.b_sp1_o_ready = 1;
            while (!axi.b_sp1_o_valid) begin @(posedge clk); #1; end
            @(posedge clk); #1;
            axi.b_sp1_o_ready = 0;
            sim_wr_cmp++;

            // Collect R on SP0
            axi.r_sp0_o_ready = 1;
            while (!axi.r_sp0_o_valid) begin @(posedge clk); #1; end
            rr = axi.r_sp0_o;
            got = longint'(rr.data);
            @(posedge clk); #1;
            axi.r_sp0_o_ready = 0;
            sim_rd_cmp++;

            exp = rd_addr;
            if (got === exp) begin sim_func_ok++; $display("    simul-rd OK  got=0x%016h", got); end
            else begin sim_func_fail++; $display("    simul-rd MISMATCH got=0x%016h exp=0x%016h", got, exp); end

            // Swap: read-back wr_addr via a second master (D=mid2) to confirm cross-master path
            axi_read(2, wr_addr, ARID'(1), got);
            sim_rd_acc++; sim_rd_cmp++;
            exp = wr_data;
            if (got === exp) begin sim_func_ok++; $display("    readback OK got=0x%016h", got); end
            else begin sim_func_fail++; $display("    readback MISMATCH got=0x%016h exp=0x%016h", got, exp); end
        end

        // ============================================================
        // [8] INCR bursts — striped across write masters, read masters
        // ============================================================
        $display("[8] INCR bursts ...");
        $display("  [8a] 4-beat INCR write on SP0, read on SP1");
        axi_write_burst_typed(0, BURST4_BASE, burst4_pattern(), 3, AXI_SIZE, 2'b01, AWID'(0));
        axi_read_burst_typed(1, BURST4_BASE, 3, AXI_SIZE, 2'b01, ARID'(0), burst_rd_ok, burst_rd_fail);

        $display("  [8b] 8-beat INCR write on D, read on I");
        axi_write_burst_typed(2, BURST8_BASE, burst8_pattern(), 7, AXI_SIZE, 2'b01, AWID'(1));
        axi_read_burst_typed(3, BURST8_BASE, 7, AXI_SIZE, 2'b01, ARID'(1), burst_rd_ok, burst_rd_fail);

        $display("  [8] Total burst rd_ok=%0d/12 rd_fail=%0d wr_ok=%0d wr_fail=%0d",
                 burst_rd_ok, burst_rd_fail, burst_wr_ok, burst_wr_fail);

        // ============================================================
        // [9] FIXED burst (SP0 write, SP0 read)
        // ============================================================
        $display("[9] FIXED burst on SP0 ...");
        begin
            longint fixed_addr, fixed_base_data;
            fixed_addr      = FIXED_BASE;
            fixed_base_data = 64'hF1F1_0000_0000_0000;
            axi_write_burst_typed(0, fixed_addr, fixed_base_data, 3, 3'b101, 2'b00, AWID'(0));
            axi_read_burst_typed (0, fixed_addr, 3, 3'b101, 2'b00, ARID'(0), fixed_ok, fixed_fail);
            $display("    FIXED: OK=%0d/4 FAIL=%0d", fixed_ok, fixed_fail);
        end

        // ============================================================
        // [10] WRAP burst (SP1 write, SP1 read)
        // ============================================================
        $display("[10] WRAP burst on SP1 ...");
        begin
            longint wrap_start, wrap_base_data;
            wrap_start     = WRAP_BASE + 64'h40;
            wrap_base_data = 64'hC0DE_0000_0000_0000;
            axi_write_burst_typed(1, wrap_start, wrap_base_data, 3, 3'b101, 2'b10, AWID'(1));
            axi_read_burst_typed (1, wrap_start, 3, 3'b101, 2'b10, ARID'(1), wrap_ok, wrap_fail);
            $display("    WRAP:  OK=%0d/4 FAIL=%0d", wrap_ok, wrap_fail);
        end

        // ============================================================
        // [11] Multiple outstanding reads striped across all 4 masters
        // ============================================================
        $display("[11] %0d outstanding reads across 4 masters (r_*_o_ready=0 during issue) ...", NUM_PIPE);
        begin
            axi.r_sp0_o_ready = 0; axi.r_sp1_o_ready = 0;
            axi.r_d_o_ready   = 0; axi.r_i_o_ready   = 0;
            for (int i = 0; i < NUM_PIPE; i++) begin
                int pmid;
                longint paddr;
                pmid  = i % 4;
                paddr = PIPE_BASE + longint'(i) * STRIDE;
                drv_ar(pmid, 1'b1, ARADDR'(paddr), ARID'(i % (1 << ARID)),
                       3'b011, 4'h0, 2'b01);
                @(posedge clk); #1;
                while (!get_ar_ready(pmid)) begin @(posedge clk); #1; end
                drv_ar(pmid, 1'b0, '0, '0, '0, '0, '0);
                pipe_acc[pmid]++;
            end
            $display("    issued: SP0=%0d SP1=%0d D=%0d I=%0d",
                     pipe_acc[0], pipe_acc[1], pipe_acc[2], pipe_acc[3]);

            // Drain per master
            for (int m = 0; m < 4; m++) begin
                while (pipe_cmp[m] < pipe_acc[m]) begin
                    longint got_d;
                    master_r_channel_t rr;
                    drv_r_ready(m, 1'b1);
                    while (!get_r_valid(m)) begin @(posedge clk); #1; end
                    rr = get_r(m);
                    got_d = longint'(rr.data);
                    @(posedge clk); #1;
                    drv_r_ready(m, 1'b0);
                    pipe_cmp[m]++;
                    if (got_d >= PIPE_BASE &&
                        got_d < PIPE_BASE + longint'(NUM_PIPE) * STRIDE &&
                        ((got_d - PIPE_BASE) % STRIDE) == 0)
                        pipe_ok++;
                    else begin
                        $display("    mid=%0d pipe mismatch got=0x%016h", m, got_d);
                        pipe_fail++;
                    end
                end
            end
            $display("    drained: SP0=%0d SP1=%0d D=%0d I=%0d OK=%0d FAIL=%0d",
                     pipe_cmp[0], pipe_cmp[1], pipe_cmp[2], pipe_cmp[3], pipe_ok, pipe_fail);
        end

        // ============================================================
        // [12] WSTRB byte masking (SP0)
        // ============================================================
        $display("[12] WSTRB byte masking on SP0 ...");
        begin
            longint g, e;

            axi_write_strb(0, STRB_BASE,          64'hDEADBEEF_12345678, 8'hFF, AWID'(0));
            axi_write_strb(0, STRB_BASE,          64'hAAAAAAAA_BBBBBBBB, 8'h0F, AWID'(0));
            e = 64'hDEADBEEF_BBBBBBBB;
            axi_read_raw(0, STRB_BASE, ARID'(0), g);
            if (g === e) begin strb_ok++; $display("  [12a] lower-half OK  got=0x%016h", g); end
            else begin strb_fail++; $display("  [12a] lower-half FAIL got=0x%016h exp=0x%016h", g, e); end

            axi_write_strb(0, STRB_BASE+STRIDE,   64'h11111111_22222222, 8'hFF, AWID'(0));
            axi_write_strb(0, STRB_BASE+STRIDE,   64'h99999999_00000000, 8'hF0, AWID'(0));
            e = 64'h99999999_22222222;
            axi_read_raw(0, STRB_BASE+STRIDE, ARID'(0), g);
            if (g === e) begin strb_ok++; $display("  [12b] upper-half OK  got=0x%016h", g); end
            else begin strb_fail++; $display("  [12b] upper-half FAIL got=0x%016h exp=0x%016h", g, e); end

            axi_write_strb(0, STRB_BASE+2*STRIDE, 64'h5A5A5A5A_5A5A5A5A, 8'hFF, AWID'(0));
            axi_write_strb(0, STRB_BASE+2*STRIDE, 64'hFFFFFFFF_FFFFFFFF, 8'h00, AWID'(0));
            e = 64'h5A5A5A5A_5A5A5A5A;
            axi_read_raw(0, STRB_BASE+2*STRIDE, ARID'(0), g);
            if (g === e) begin strb_ok++; $display("  [12c] zero strobe OK  got=0x%016h", g); end
            else begin strb_fail++; $display("  [12c] zero strobe FAIL got=0x%016h exp=0x%016h", g, e); end

            axi_write_strb(0, STRB_BASE+3*STRIDE, 64'hFEDCBA98_76543210, 8'h01, AWID'(0));
            e = 64'h0000000000000010;
            axi_read_raw(0, STRB_BASE+3*STRIDE, ARID'(0), g);
            if (g === e) begin strb_ok++; $display("  [12d] single-byte OK  got=0x%016h", g); end
            else begin strb_fail++; $display("  [12d] single-byte FAIL got=0x%016h exp=0x%016h", g, e); end

            $display("  WSTRB: OK=%0d/4 FAIL=%0d", strb_ok, strb_fail);
        end

        // ============================================================
        // [13] Summary
        // ============================================================
        total_wr_acc     = wr_acc[0]+wr_acc[1]+wr_acc[2];
        total_wr_cmp     = wr_cmp[0]+wr_cmp[1]+wr_cmp[2];
        total_rd_acc     = rd_acc[0]+rd_acc[1]+rd_acc[2]+rd_acc[3];
        total_rd_cmp     = rd_cmp[0]+rd_cmp[1]+rd_cmp[2]+rd_cmp[3];
        total_func_ok    = func_ok[0]+func_ok[1]+func_ok[2]+func_ok[3];
        total_func_fail  = func_fail[0]+func_fail[1]+func_fail[2]+func_fail[3];
        total_flood_acc  = flood_acc[0]+flood_acc[1]+flood_acc[2]+flood_acc[3];
        total_flood_cmp  = flood_cmp[0]+flood_cmp[1]+flood_cmp[2]+flood_cmp[3];
        total_pipe_acc   = pipe_acc[0]+pipe_acc[1]+pipe_acc[2]+pipe_acc[3];
        total_pipe_cmp   = pipe_cmp[0]+pipe_cmp[1]+pipe_cmp[2]+pipe_cmp[3];

        $display("\n--- Summary ---");
        $display("  Total ticks   : %0d", tick);
        if (USE_MEMINIT)
            $display("  [2] Writes    : SKIPPED");
        else
            $display("  [2] Writes    : SP0=%0d/%0d SP1=%0d/%0d D=%0d/%0d  total acc/cmp=%0d/%0d of %0d",
                     wr_acc[0], wr_cmp[0], wr_acc[1], wr_cmp[1], wr_acc[2], wr_cmp[2],
                     total_wr_acc, total_wr_cmp, NUM_WR);
        $display("  [3-4] Reads   : SP0=%0d SP1=%0d D=%0d I=%0d  total acc/cmp=%0d/%0d of %0d",
                 rd_cmp[0], rd_cmp[1], rd_cmp[2], rd_cmp[3],
                 total_rd_acc, total_rd_cmp, NUM_WR+NUM_RD_RAW);
        $display("  [3-4] Functional: OK=%0d/%0d FAIL=%0d",
                 total_func_ok, NUM_WR+NUM_RD_RAW, total_func_fail);
        $display("  [5] RD flood  : acc=%0d/%0d drained=%0d/%0d max_stall=%0d",
                 total_flood_acc, NUM_FLOOD, total_flood_cmp, NUM_FLOOD, flood_stall_max);
        $display("  [6] WR BP SP0 : acc=%0d/%0d cmp=%0d/%0d stall_obs=%0d",
                 bp_wr_acc, B_DEPTH+1, bp_wr_cmp, B_DEPTH+1, bp_stall);
        $display("  [7] Simul     : rd acc/cmp=%0d/%0d wr acc/cmp=%0d/%0d OK=%0d FAIL=%0d",
                 sim_rd_acc, sim_rd_cmp, sim_wr_acc, sim_wr_cmp, sim_func_ok, sim_func_fail);
        $display("  [8] INCR      : rd_ok=%0d/12 rd_fail=%0d wr_ok=%0d",
                 burst_rd_ok, burst_rd_fail, burst_wr_ok);
        $display("  [9] FIXED     : OK=%0d/4 FAIL=%0d", fixed_ok, fixed_fail);
        $display("  [10] WRAP     : OK=%0d/4 FAIL=%0d", wrap_ok, wrap_fail);
        $display("  [11] pipeline : acc=%0d cmp=%0d OK=%0d FAIL=%0d",
                 total_pipe_acc, total_pipe_cmp, pipe_ok, pipe_fail);
        $display("  [12] WSTRB    : OK=%0d/4 FAIL=%0d", strb_ok, strb_fail);

        if ((USE_MEMINIT ? (total_wr_acc == 0 && total_wr_cmp == 0)
                         : (total_wr_acc == NUM_WR && total_wr_cmp == NUM_WR)) &&
            total_rd_acc   == NUM_WR+NUM_RD_RAW &&
            total_rd_cmp   == NUM_WR+NUM_RD_RAW &&
            total_func_fail == 0 &&
            total_flood_acc == NUM_FLOOD &&
            total_flood_cmp == NUM_FLOOD &&
            bp_wr_acc == B_DEPTH+1 && bp_wr_cmp == B_DEPTH+1 &&
            bp_stall  >= BP_HOLD &&
            sim_rd_acc == 2 && sim_rd_cmp == 2 &&
            sim_wr_acc == 1 && sim_wr_cmp == 1 &&
            sim_func_fail == 0 &&
            burst_rd_ok == 12 && burst_rd_fail == 0 &&
            total_pipe_acc == NUM_PIPE && total_pipe_cmp == NUM_PIPE &&
            pipe_ok == NUM_PIPE && pipe_fail == 0 &&
            strb_ok == 4 && strb_fail == 0 &&
            fixed_ok == 4 && fixed_fail == 0 &&
            wrap_ok == 4 && wrap_fail == 0)
        begin
            $display("\n=== PASSED ===");
            ramulator_exit(0);
        end else begin
            $display("\n=== FAILED ===");
            ramulator_exit(1);
        end
    end

    // ----------------------------------------------------------------
    // SVA — arbiter + router onehot properties
    // ----------------------------------------------------------------
    property ar_arbit_onehot;
        @(posedge clk) disable iff (!nrst)
        $onehot0({axi.sp0_pop, axi.sp1_pop, axi.d_pop, axi.i_pop});
    endproperty
    assert property (ar_arbit_onehot)
        else $error("ar arbiter grant not onehot0");

    property r_router_onehot;
        @(posedge clk) disable iff (!nrst)
        $onehot0({axi.r_sp0_o_valid, axi.r_sp1_o_valid, axi.r_d_o_valid, axi.r_i_o_valid});
    endproperty
    assert property (r_router_onehot)
        else $error("r router valid not onehot0");

    property r_valid_quiet;
        @(posedge clk) disable iff (!nrst)
        (!axi.r_valid) |-> (!axi.r_sp0_o_valid && !axi.r_sp1_o_valid
                            && !axi.r_d_o_valid && !axi.r_i_o_valid);
    endproperty
    assert property (r_valid_quiet)
        else $error("master r_*_o_valid raised while sub r_valid=0");

    // ----------------------------------------------------------------
    // Watchdog
    // ----------------------------------------------------------------
    initial begin : watchdog
        repeat(MAX_CYCLES) @(posedge clk);
        $display("WATCHDOG: simulation exceeded %0d cycles — aborting.", MAX_CYCLES);
        ramulator_exit(1);
    end

endmodule
