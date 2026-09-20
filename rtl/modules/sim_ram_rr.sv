`timescale 1ns/1ps

module sim_ram_rr #(
    parameter int ADDR_WIDTH        = 32,
    parameter int MEM_BYTES         = 1 << 20,
    parameter string INIT_FILE      = "",
    parameter bit INIT_IS_HEX       = 1'b1,
    parameter string DUMP_FILE      = "mem_dump.hex",
    parameter bit BIG_ENDIAN        = 1'b0,  // 0=little-endian, 1=big-endian
    parameter bit REVERSE_MASK_MAP  = 1'b0   // 0: mask[0]->[15:0], 1: mask[0]->[63:48]
)(
    input  logic                  clk,
    input  logic                  rst_n,

    // -----------------------------
    // I-cache side
    // -----------------------------
    input  logic                  ic_req_valid,
    input  logic                  ic_req_we,
    input  logic [ADDR_WIDTH-1:0] ic_req_addr,
    input  logic [63:0]           ic_req_wdata,
    output logic [63:0]           ic_resp_rdata,
    output logic                  ic_resp_hit,

    // -----------------------------
    // D-cache side
    // -----------------------------
    input  logic                  dc_req_valid,
    input  logic                  dc_req_we,
    input  logic [ADDR_WIDTH-1:0] dc_req_addr,
    input  logic [63:0]           dc_req_wdata,
    output logic [63:0]           dc_resp_rdata,
    output logic                  dc_resp_hit,

    // -----------------------------
    // Scratchpad 0
    // -----------------------------
    input  logic                  sc0_req_valid,
    input  logic                  sc0_req_rw,       // 0=read, 1=write
    input  logic [ADDR_WIDTH-1:0] sc0_req_addr,
    input  logic [63:0]           sc0_req_wdata,
    input  logic [7:0]            sc0_req_id,
    input  logic [3:0]            sc0_req_mask,
    input  logic                  sc0_stall_in,
    output logic [63:0]           sc0_resp_rdata,
    output logic                  sc0_resp_hit,
    output logic [7:0]            sc0_resp_id,
    output logic                  sc0_resp_rw,
    output logic [3:0]            sc0_resp_mask,
    output logic                  sc0_stall_out,

    // -----------------------------
    // Scratchpad 1
    // -----------------------------
    input  logic                  sc1_req_valid,
    input  logic                  sc1_req_rw,
    input  logic [ADDR_WIDTH-1:0] sc1_req_addr,
    input  logic [63:0]           sc1_req_wdata,
    input  logic [7:0]            sc1_req_id,
    input  logic [3:0]            sc1_req_mask,
    input  logic                  sc1_stall_in,
    output logic [63:0]           sc1_resp_rdata,
    output logic                  sc1_resp_hit,
    output logic [7:0]            sc1_resp_id,
    output logic                  sc1_resp_rw,
    output logic [3:0]            sc1_resp_mask,
    output logic                  sc1_stall_out,

    // -----------------------------
    // Scratchpad 2
    // -----------------------------
    input  logic                  sc2_req_valid,
    input  logic                  sc2_req_rw,
    input  logic [ADDR_WIDTH-1:0] sc2_req_addr,
    input  logic [63:0]           sc2_req_wdata,
    input  logic [7:0]            sc2_req_id,
    input  logic [3:0]            sc2_req_mask,
    input  logic                  sc2_stall_in,
    output logic [63:0]           sc2_resp_rdata,
    output logic                  sc2_resp_hit,
    output logic [7:0]            sc2_resp_id,
    output logic                  sc2_resp_rw,
    output logic [3:0]            sc2_resp_mask,
    output logic                  sc2_stall_out,

    // -----------------------------
    // Scratchpad 3
    // -----------------------------
    input  logic                  sc3_req_valid,
    input  logic                  sc3_req_rw,
    input  logic [ADDR_WIDTH-1:0] sc3_req_addr,
    input  logic [63:0]           sc3_req_wdata,
    input  logic [7:0]            sc3_req_id,
    input  logic [3:0]            sc3_req_mask,
    input  logic                  sc3_stall_in,
    output logic [63:0]           sc3_resp_rdata,
    output logic                  sc3_resp_hit,
    output logic [7:0]            sc3_resp_id,
    output logic                  sc3_resp_rw,
    output logic [3:0]            sc3_resp_mask,
    output logic                  sc3_stall_out
);

    localparam int BEAT_BYTES  = 8;
    localparam int FIXED_BEATS = 8;

    typedef enum logic [2:0] {
        OWNER_IC  = 3'd0,
        OWNER_DC  = 3'd1,
        OWNER_SC0 = 3'd2,
        OWNER_SC1 = 3'd3,
        OWNER_SC2 = 3'd4,
        OWNER_SC3 = 3'd5
    } owner_t;

    logic [7:0] mem [0:MEM_BYTES-1];

    logic [2:0] rr_turn;

    // I/D fixed read burst lock
    logic                  burst_active;
    owner_t                burst_owner;
    logic [ADDR_WIDTH-1:0] burst_base_addr;
    logic [2:0]            burst_beat_idx;
    logic                  burst_contended;

    // SCPAD transaction lock
    logic                  sc_lock_active;
    owner_t                sc_lock_owner;
    logic                  sc_lock_contended;

    // Selected transaction for current cycle
    logic                  sel_valid;
    owner_t                sel_owner;
    logic                  sel_we;
    logic [ADDR_WIDTH-1:0] sel_addr;
    logic [63:0]           sel_wdata;
    logic [7:0]            sel_sc_id;
    logic [3:0]            sel_sc_mask;
    logic                  sel_sc_stall_in;
    logic                  sel_contended;

    logic                  sel_addr_in_range;
    logic [63:0]           sel_read_word;

    logic [5:0] req_present;

    string dump_file_name;
    integer i;

    function automatic logic [63:0] assemble_read64(input logic [ADDR_WIDTH-1:0] a);
        if (BIG_ENDIAN) begin
            assemble_read64 = {
                mem[a + 0], mem[a + 1], mem[a + 2], mem[a + 3],
                mem[a + 4], mem[a + 5], mem[a + 6], mem[a + 7]
            };
        end else begin
            assemble_read64 = {
                mem[a + 7], mem[a + 6], mem[a + 5], mem[a + 4],
                mem[a + 3], mem[a + 2], mem[a + 1], mem[a + 0]
            };
        end
    endfunction

    function automatic logic mask_lane_enabled(
        input logic [3:0] mask,
        input int lane_idx
    );
        if (!REVERSE_MASK_MAP) mask_lane_enabled = mask[lane_idx];
        else                   mask_lane_enabled = mask[3-lane_idx];
    endfunction

    function automatic logic is_scpad_owner(input owner_t o);
        is_scpad_owner = (o == OWNER_SC0) || (o == OWNER_SC1) || (o == OWNER_SC2) || (o == OWNER_SC3);
    endfunction

    initial begin : init_mem
        string file_name;
        bit init_is_hex_local;

        for (i = 0; i < MEM_BYTES; i++) begin
            mem[i] = 8'h00;
        end

        file_name         = INIT_FILE;
        init_is_hex_local = INIT_IS_HEX;
        dump_file_name    = DUMP_FILE;

        void'($value$plusargs("memfile=%s", file_name));
        void'($value$plusargs("memhex=%d", init_is_hex_local));
        void'($value$plusargs("dumpfile=%s", dump_file_name));

        if (file_name != "") begin
            if (init_is_hex_local) begin
                $display("[sim_ram_rr_burst64_4scpad] Loading HEX file: %s", file_name);
                $readmemh(file_name, mem);
            end else begin
                $display("[sim_ram_rr_burst64_4scpad] Loading BIN file: %s", file_name);
                $readmemb(file_name, mem);
            end
        end else begin
            $display("[sim_ram_rr_burst64_4scpad] No init file provided; memory zeroed.");
        end
    end

    always_comb begin
        req_present[0] = ic_req_valid;
        req_present[1] = dc_req_valid;
        req_present[2] = sc0_req_valid;
        req_present[3] = sc1_req_valid;
        req_present[4] = sc2_req_valid;
        req_present[5] = sc3_req_valid;
    end

    // Selection
    always_comb begin
        sel_valid       = 1'b0;
        sel_owner       = OWNER_IC;
        sel_we          = 1'b0;
        sel_addr        = '0;
        sel_wdata       = '0;
        sel_sc_id       = 8'h00;
        sel_sc_mask     = 4'h0;
        sel_sc_stall_in = 1'b0;
        sel_contended   = 1'b0;

        if (burst_active) begin
            sel_valid = 1'b1;
            sel_owner = burst_owner;
            sel_we    = 1'b0;
            sel_addr  = burst_base_addr + (burst_beat_idx * BEAT_BYTES);
            sel_wdata = 64'h0;
        end
        else if (sc_lock_active) begin
            sel_owner = sc_lock_owner;

            unique case (sc_lock_owner)
                OWNER_SC0: begin
                    sel_valid       = sc0_req_valid;
                    sel_we          = sc0_req_rw;
                    sel_addr        = sc0_req_addr;
                    sel_wdata       = sc0_req_wdata;
                    sel_sc_id       = sc0_req_id;
                    sel_sc_mask     = sc0_req_mask;
                    sel_sc_stall_in = sc0_stall_in;
                end
                OWNER_SC1: begin
                    sel_valid       = sc1_req_valid;
                    sel_we          = sc1_req_rw;
                    sel_addr        = sc1_req_addr;
                    sel_wdata       = sc1_req_wdata;
                    sel_sc_id       = sc1_req_id;
                    sel_sc_mask     = sc1_req_mask;
                    sel_sc_stall_in = sc1_stall_in;
                end
                OWNER_SC2: begin
                    sel_valid       = sc2_req_valid;
                    sel_we          = sc2_req_rw;
                    sel_addr        = sc2_req_addr;
                    sel_wdata       = sc2_req_wdata;
                    sel_sc_id       = sc2_req_id;
                    sel_sc_mask     = sc2_req_mask;
                    sel_sc_stall_in = sc2_stall_in;
                end
                OWNER_SC3: begin
                    sel_valid       = sc3_req_valid;
                    sel_we          = sc3_req_rw;
                    sel_addr        = sc3_req_addr;
                    sel_wdata       = sc3_req_wdata;
                    sel_sc_id       = sc3_req_id;
                    sel_sc_mask     = sc3_req_mask;
                    sel_sc_stall_in = sc3_stall_in;
                end
                default: begin
                    sel_valid       = 1'b0;
                    sel_we          = 1'b0;
                    sel_addr        = '0;
                    sel_wdata       = '0;
                    sel_sc_id       = 8'h00;
                    sel_sc_mask     = 4'h0;
                    sel_sc_stall_in = 1'b0;
                end
            endcase
        end
        else begin
            sel_contended = (req_present[0] + req_present[1] + req_present[2] +
                             req_present[3] + req_present[4] + req_present[5]) > 1;

            unique case (rr_turn)
                3'd0: begin
                    if (req_present[0]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_IC;  sel_we = ic_req_we;  sel_addr = ic_req_addr;  sel_wdata = ic_req_wdata;
                    end else if (req_present[1]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_DC;  sel_we = dc_req_we;  sel_addr = dc_req_addr;  sel_wdata = dc_req_wdata;
                    end else if (req_present[2]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC0; sel_we = sc0_req_rw; sel_addr = sc0_req_addr; sel_wdata = sc0_req_wdata; sel_sc_id = sc0_req_id; sel_sc_mask = sc0_req_mask; sel_sc_stall_in = sc0_stall_in;
                    end else if (req_present[3]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC1; sel_we = sc1_req_rw; sel_addr = sc1_req_addr; sel_wdata = sc1_req_wdata; sel_sc_id = sc1_req_id; sel_sc_mask = sc1_req_mask; sel_sc_stall_in = sc1_stall_in;
                    end else if (req_present[4]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC2; sel_we = sc2_req_rw; sel_addr = sc2_req_addr; sel_wdata = sc2_req_wdata; sel_sc_id = sc2_req_id; sel_sc_mask = sc2_req_mask; sel_sc_stall_in = sc2_stall_in;
                    end else if (req_present[5]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC3; sel_we = sc3_req_rw; sel_addr = sc3_req_addr; sel_wdata = sc3_req_wdata; sel_sc_id = sc3_req_id; sel_sc_mask = sc3_req_mask; sel_sc_stall_in = sc3_stall_in;
                    end
                end
                3'd1: begin
                    if (req_present[1]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_DC;  sel_we = dc_req_we;  sel_addr = dc_req_addr;  sel_wdata = dc_req_wdata;
                    end else if (req_present[2]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC0; sel_we = sc0_req_rw; sel_addr = sc0_req_addr; sel_wdata = sc0_req_wdata; sel_sc_id = sc0_req_id; sel_sc_mask = sc0_req_mask; sel_sc_stall_in = sc0_stall_in;
                    end else if (req_present[3]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC1; sel_we = sc1_req_rw; sel_addr = sc1_req_addr; sel_wdata = sc1_req_wdata; sel_sc_id = sc1_req_id; sel_sc_mask = sc1_req_mask; sel_sc_stall_in = sc1_stall_in;
                    end else if (req_present[4]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC2; sel_we = sc2_req_rw; sel_addr = sc2_req_addr; sel_wdata = sc2_req_wdata; sel_sc_id = sc2_req_id; sel_sc_mask = sc2_req_mask; sel_sc_stall_in = sc2_stall_in;
                    end else if (req_present[5]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC3; sel_we = sc3_req_rw; sel_addr = sc3_req_addr; sel_wdata = sc3_req_wdata; sel_sc_id = sc3_req_id; sel_sc_mask = sc3_req_mask; sel_sc_stall_in = sc3_stall_in;
                    end else if (req_present[0]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_IC;  sel_we = ic_req_we;  sel_addr = ic_req_addr;  sel_wdata = ic_req_wdata;
                    end
                end
                3'd2: begin
                    if (req_present[2]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC0; sel_we = sc0_req_rw; sel_addr = sc0_req_addr; sel_wdata = sc0_req_wdata; sel_sc_id = sc0_req_id; sel_sc_mask = sc0_req_mask; sel_sc_stall_in = sc0_stall_in;
                    end else if (req_present[3]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC1; sel_we = sc1_req_rw; sel_addr = sc1_req_addr; sel_wdata = sc1_req_wdata; sel_sc_id = sc1_req_id; sel_sc_mask = sc1_req_mask; sel_sc_stall_in = sc1_stall_in;
                    end else if (req_present[4]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC2; sel_we = sc2_req_rw; sel_addr = sc2_req_addr; sel_wdata = sc2_req_wdata; sel_sc_id = sc2_req_id; sel_sc_mask = sc2_req_mask; sel_sc_stall_in = sc2_stall_in;
                    end else if (req_present[5]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC3; sel_we = sc3_req_rw; sel_addr = sc3_req_addr; sel_wdata = sc3_req_wdata; sel_sc_id = sc3_req_id; sel_sc_mask = sc3_req_mask; sel_sc_stall_in = sc3_stall_in;
                    end else if (req_present[0]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_IC;  sel_we = ic_req_we;  sel_addr = ic_req_addr;  sel_wdata = ic_req_wdata;
                    end else if (req_present[1]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_DC;  sel_we = dc_req_we;  sel_addr = dc_req_addr;  sel_wdata = dc_req_wdata;
                    end
                end
                3'd3: begin
                    if (req_present[3]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC1; sel_we = sc1_req_rw; sel_addr = sc1_req_addr; sel_wdata = sc1_req_wdata; sel_sc_id = sc1_req_id; sel_sc_mask = sc1_req_mask; sel_sc_stall_in = sc1_stall_in;
                    end else if (req_present[4]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC2; sel_we = sc2_req_rw; sel_addr = sc2_req_addr; sel_wdata = sc2_req_wdata; sel_sc_id = sc2_req_id; sel_sc_mask = sc2_req_mask; sel_sc_stall_in = sc2_stall_in;
                    end else if (req_present[5]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC3; sel_we = sc3_req_rw; sel_addr = sc3_req_addr; sel_wdata = sc3_req_wdata; sel_sc_id = sc3_req_id; sel_sc_mask = sc3_req_mask; sel_sc_stall_in = sc3_stall_in;
                    end else if (req_present[0]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_IC;  sel_we = ic_req_we;  sel_addr = ic_req_addr;  sel_wdata = ic_req_wdata;
                    end else if (req_present[1]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_DC;  sel_we = dc_req_we;  sel_addr = dc_req_addr;  sel_wdata = dc_req_wdata;
                    end else if (req_present[2]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC0; sel_we = sc0_req_rw; sel_addr = sc0_req_addr; sel_wdata = sc0_req_wdata; sel_sc_id = sc0_req_id; sel_sc_mask = sc0_req_mask; sel_sc_stall_in = sc0_stall_in;
                    end
                end
                3'd4: begin
                    if (req_present[4]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC2; sel_we = sc2_req_rw; sel_addr = sc2_req_addr; sel_wdata = sc2_req_wdata; sel_sc_id = sc2_req_id; sel_sc_mask = sc2_req_mask; sel_sc_stall_in = sc2_stall_in;
                    end else if (req_present[5]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC3; sel_we = sc3_req_rw; sel_addr = sc3_req_addr; sel_wdata = sc3_req_wdata; sel_sc_id = sc3_req_id; sel_sc_mask = sc3_req_mask; sel_sc_stall_in = sc3_stall_in;
                    end else if (req_present[0]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_IC;  sel_we = ic_req_we;  sel_addr = ic_req_addr;  sel_wdata = ic_req_wdata;
                    end else if (req_present[1]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_DC;  sel_we = dc_req_we;  sel_addr = dc_req_addr;  sel_wdata = dc_req_wdata;
                    end else if (req_present[2]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC0; sel_we = sc0_req_rw; sel_addr = sc0_req_addr; sel_wdata = sc0_req_wdata; sel_sc_id = sc0_req_id; sel_sc_mask = sc0_req_mask; sel_sc_stall_in = sc0_stall_in;
                    end else if (req_present[3]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC1; sel_we = sc1_req_rw; sel_addr = sc1_req_addr; sel_wdata = sc1_req_wdata; sel_sc_id = sc1_req_id; sel_sc_mask = sc1_req_mask; sel_sc_stall_in = sc1_stall_in;
                    end
                end
                default: begin
                    if (req_present[5]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC3; sel_we = sc3_req_rw; sel_addr = sc3_req_addr; sel_wdata = sc3_req_wdata; sel_sc_id = sc3_req_id; sel_sc_mask = sc3_req_mask; sel_sc_stall_in = sc3_stall_in;
                    end else if (req_present[0]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_IC;  sel_we = ic_req_we;  sel_addr = ic_req_addr;  sel_wdata = ic_req_wdata;
                    end else if (req_present[1]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_DC;  sel_we = dc_req_we;  sel_addr = dc_req_addr;  sel_wdata = dc_req_wdata;
                    end else if (req_present[2]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC0; sel_we = sc0_req_rw; sel_addr = sc0_req_addr; sel_wdata = sc0_req_wdata; sel_sc_id = sc0_req_id; sel_sc_mask = sc0_req_mask; sel_sc_stall_in = sc0_stall_in;
                    end else if (req_present[3]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC1; sel_we = sc1_req_rw; sel_addr = sc1_req_addr; sel_wdata = sc1_req_wdata; sel_sc_id = sc1_req_id; sel_sc_mask = sc1_req_mask; sel_sc_stall_in = sc1_stall_in;
                    end else if (req_present[4]) begin
                        sel_valid = 1'b1; sel_owner = OWNER_SC2; sel_we = sc2_req_rw; sel_addr = sc2_req_addr; sel_wdata = sc2_req_wdata; sel_sc_id = sc2_req_id; sel_sc_mask = sc2_req_mask; sel_sc_stall_in = sc2_stall_in;
                    end
                end
            endcase
        end
    end

    assign sel_addr_in_range = ((sel_addr + BEAT_BYTES - 1) < MEM_BYTES);

    always_comb begin
        sel_read_word = 64'h0;
        if (sel_valid && !sel_we && sel_addr_in_range) begin
            sel_read_word = assemble_read64(sel_addr);
        end
    end

    always_comb begin
        ic_resp_rdata = 64'h0;
        ic_resp_hit   = 1'b0;
        dc_resp_rdata = 64'h0;
        dc_resp_hit   = 1'b0;

        sc0_resp_rdata = 64'h0; sc0_resp_hit = 1'b0; sc0_resp_id = 8'h00; sc0_resp_rw = 1'b0; sc0_resp_mask = 4'h0; sc0_stall_out = 1'b0;
        sc1_resp_rdata = 64'h0; sc1_resp_hit = 1'b0; sc1_resp_id = 8'h00; sc1_resp_rw = 1'b0; sc1_resp_mask = 4'h0; sc1_stall_out = 1'b0;
        sc2_resp_rdata = 64'h0; sc2_resp_hit = 1'b0; sc2_resp_id = 8'h00; sc2_resp_rw = 1'b0; sc2_resp_mask = 4'h0; sc2_stall_out = 1'b0;
        sc3_resp_rdata = 64'h0; sc3_resp_hit = 1'b0; sc3_resp_id = 8'h00; sc3_resp_rw = 1'b0; sc3_resp_mask = 4'h0; sc3_stall_out = 1'b0;

        if (sc0_req_valid && !(sel_valid && sel_owner == OWNER_SC0 && !sc0_stall_in)) sc0_stall_out = 1'b1;
        if (sc1_req_valid && !(sel_valid && sel_owner == OWNER_SC1 && !sc1_stall_in)) sc1_stall_out = 1'b1;
        if (sc2_req_valid && !(sel_valid && sel_owner == OWNER_SC2 && !sc2_stall_in)) sc2_stall_out = 1'b1;
        if (sc3_req_valid && !(sel_valid && sel_owner == OWNER_SC3 && !sc3_stall_in)) sc3_stall_out = 1'b1;

        if (sel_valid && sel_addr_in_range) begin
            unique case (sel_owner)
                OWNER_IC: begin
                    ic_resp_hit = 1'b1;
                    if (!sel_we) ic_resp_rdata = sel_read_word;
                end

                OWNER_DC: begin
                    dc_resp_hit = 1'b1;
                    if (!sel_we) dc_resp_rdata = sel_read_word;
                end

                OWNER_SC0: begin
                    if (!sc0_stall_in) begin
                        sc0_resp_hit  = 1'b1;
                        sc0_resp_id   = sel_sc_id;
                        sc0_resp_rw   = sel_we;
                        sc0_resp_mask = sel_sc_mask;
                        if (!sel_we) sc0_resp_rdata = sel_read_word;
                    end
                end

                OWNER_SC1: begin
                    if (!sc1_stall_in) begin
                        sc1_resp_hit  = 1'b1;
                        sc1_resp_id   = sel_sc_id;
                        sc1_resp_rw   = sel_we;
                        sc1_resp_mask = sel_sc_mask;
                        if (!sel_we) sc1_resp_rdata = sel_read_word;
                    end
                end

                OWNER_SC2: begin
                    if (!sc2_stall_in) begin
                        sc2_resp_hit  = 1'b1;
                        sc2_resp_id   = sel_sc_id;
                        sc2_resp_rw   = sel_we;
                        sc2_resp_mask = sel_sc_mask;
                        if (!sel_we) sc2_resp_rdata = sel_read_word;
                    end
                end

                OWNER_SC3: begin
                    if (!sc3_stall_in) begin
                        sc3_resp_hit  = 1'b1;
                        sc3_resp_id   = sel_sc_id;
                        sc3_resp_rw   = sel_we;
                        sc3_resp_mask = sel_sc_mask;
                        if (!sel_we) sc3_resp_rdata = sel_read_word;
                    end
                end

                default: begin
                end
            endcase
        end
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rr_turn          <= 3'd0;
            burst_active     <= 1'b0;
            burst_owner      <= OWNER_IC;
            burst_base_addr  <= '0;
            burst_beat_idx   <= 3'd0;
            burst_contended  <= 1'b0;
            sc_lock_active   <= 1'b0;
            sc_lock_owner    <= OWNER_SC0;
            sc_lock_contended<= 1'b0;
        end else begin
            if (burst_active) begin
                if (sel_addr_in_range) begin
                    if (burst_beat_idx == 3'd7) begin
                        burst_active   <= 1'b0;
                        burst_beat_idx <= 3'd0;
                        if (burst_contended) begin
                            if (rr_turn == 3'd5) rr_turn <= 3'd0;
                            else                 rr_turn <= rr_turn + 3'd1;
                        end
                    end else begin
                        burst_beat_idx <= burst_beat_idx + 3'd1;
                    end
                end
            end
            else if (sc_lock_active) begin
                // release only when valid goes low
                unique case (sc_lock_owner)
                    OWNER_SC0: begin
                        if (!sc0_req_valid) begin
                            sc_lock_active <= 1'b0;
                            if (sc_lock_contended) begin
                                if (rr_turn == 3'd5) rr_turn <= 3'd0;
                                else                 rr_turn <= rr_turn + 3'd1;
                            end
                        end else if (!sc0_stall_in && sel_addr_in_range && sc0_req_rw) begin
                            if (BIG_ENDIAN) begin
                                if (mask_lane_enabled(sc0_req_mask, 3)) begin
                                    mem[sc0_req_addr + 0] <= sc0_req_wdata[63:56];
                                    mem[sc0_req_addr + 1] <= sc0_req_wdata[55:48];
                                end
                                if (mask_lane_enabled(sc0_req_mask, 2)) begin
                                    mem[sc0_req_addr + 2] <= sc0_req_wdata[47:40];
                                    mem[sc0_req_addr + 3] <= sc0_req_wdata[39:32];
                                end
                                if (mask_lane_enabled(sc0_req_mask, 1)) begin
                                    mem[sc0_req_addr + 4] <= sc0_req_wdata[31:24];
                                    mem[sc0_req_addr + 5] <= sc0_req_wdata[23:16];
                                end
                                if (mask_lane_enabled(sc0_req_mask, 0)) begin
                                    mem[sc0_req_addr + 6] <= sc0_req_wdata[15:8];
                                    mem[sc0_req_addr + 7] <= sc0_req_wdata[7:0];
                                end
                            end else begin
                                if (mask_lane_enabled(sc0_req_mask, 0)) begin
                                    mem[sc0_req_addr + 0] <= sc0_req_wdata[7:0];
                                    mem[sc0_req_addr + 1] <= sc0_req_wdata[15:8];
                                end
                                if (mask_lane_enabled(sc0_req_mask, 1)) begin
                                    mem[sc0_req_addr + 2] <= sc0_req_wdata[23:16];
                                    mem[sc0_req_addr + 3] <= sc0_req_wdata[31:24];
                                end
                                if (mask_lane_enabled(sc0_req_mask, 2)) begin
                                    mem[sc0_req_addr + 4] <= sc0_req_wdata[39:32];
                                    mem[sc0_req_addr + 5] <= sc0_req_wdata[47:40];
                                end
                                if (mask_lane_enabled(sc0_req_mask, 3)) begin
                                    mem[sc0_req_addr + 6] <= sc0_req_wdata[55:48];
                                    mem[sc0_req_addr + 7] <= sc0_req_wdata[63:56];
                                end
                            end
                        end
                    end

                    OWNER_SC1: begin
                        if (!sc1_req_valid) begin
                            sc_lock_active <= 1'b0;
                            if (sc_lock_contended) begin
                                if (rr_turn == 3'd5) rr_turn <= 3'd0;
                                else                 rr_turn <= rr_turn + 3'd1;
                            end
                        end else if (!sc1_stall_in && sel_addr_in_range && sc1_req_rw) begin
                            if (BIG_ENDIAN) begin
                                if (mask_lane_enabled(sc1_req_mask, 3)) begin
                                    mem[sc1_req_addr + 0] <= sc1_req_wdata[63:56];
                                    mem[sc1_req_addr + 1] <= sc1_req_wdata[55:48];
                                end
                                if (mask_lane_enabled(sc1_req_mask, 2)) begin
                                    mem[sc1_req_addr + 2] <= sc1_req_wdata[47:40];
                                    mem[sc1_req_addr + 3] <= sc1_req_wdata[39:32];
                                end
                                if (mask_lane_enabled(sc1_req_mask, 1)) begin
                                    mem[sc1_req_addr + 4] <= sc1_req_wdata[31:24];
                                    mem[sc1_req_addr + 5] <= sc1_req_wdata[23:16];
                                end
                                if (mask_lane_enabled(sc1_req_mask, 0)) begin
                                    mem[sc1_req_addr + 6] <= sc1_req_wdata[15:8];
                                    mem[sc1_req_addr + 7] <= sc1_req_wdata[7:0];
                                end
                            end else begin
                                if (mask_lane_enabled(sc1_req_mask, 0)) begin
                                    mem[sc1_req_addr + 0] <= sc1_req_wdata[7:0];
                                    mem[sc1_req_addr + 1] <= sc1_req_wdata[15:8];
                                end
                                if (mask_lane_enabled(sc1_req_mask, 1)) begin
                                    mem[sc1_req_addr + 2] <= sc1_req_wdata[23:16];
                                    mem[sc1_req_addr + 3] <= sc1_req_wdata[31:24];
                                end
                                if (mask_lane_enabled(sc1_req_mask, 2)) begin
                                    mem[sc1_req_addr + 4] <= sc1_req_wdata[39:32];
                                    mem[sc1_req_addr + 5] <= sc1_req_wdata[47:40];
                                end
                                if (mask_lane_enabled(sc1_req_mask, 3)) begin
                                    mem[sc1_req_addr + 6] <= sc1_req_wdata[55:48];
                                    mem[sc1_req_addr + 7] <= sc1_req_wdata[63:56];
                                end
                            end
                        end
                    end

                    OWNER_SC2: begin
                        if (!sc2_req_valid) begin
                            sc_lock_active <= 1'b0;
                            if (sc_lock_contended) begin
                                if (rr_turn == 3'd5) rr_turn <= 3'd0;
                                else                 rr_turn <= rr_turn + 3'd1;
                            end
                        end else if (!sc2_stall_in && sel_addr_in_range && sc2_req_rw) begin
                            if (BIG_ENDIAN) begin
                                if (mask_lane_enabled(sc2_req_mask, 3)) begin
                                    mem[sc2_req_addr + 0] <= sc2_req_wdata[63:56];
                                    mem[sc2_req_addr + 1] <= sc2_req_wdata[55:48];
                                end
                                if (mask_lane_enabled(sc2_req_mask, 2)) begin
                                    mem[sc2_req_addr + 2] <= sc2_req_wdata[47:40];
                                    mem[sc2_req_addr + 3] <= sc2_req_wdata[39:32];
                                end
                                if (mask_lane_enabled(sc2_req_mask, 1)) begin
                                    mem[sc2_req_addr + 4] <= sc2_req_wdata[31:24];
                                    mem[sc2_req_addr + 5] <= sc2_req_wdata[23:16];
                                end
                                if (mask_lane_enabled(sc2_req_mask, 0)) begin
                                    mem[sc2_req_addr + 6] <= sc2_req_wdata[15:8];
                                    mem[sc2_req_addr + 7] <= sc2_req_wdata[7:0];
                                end
                            end else begin
                                if (mask_lane_enabled(sc2_req_mask, 0)) begin
                                    mem[sc2_req_addr + 0] <= sc2_req_wdata[7:0];
                                    mem[sc2_req_addr + 1] <= sc2_req_wdata[15:8];
                                end
                                if (mask_lane_enabled(sc2_req_mask, 1)) begin
                                    mem[sc2_req_addr + 2] <= sc2_req_wdata[23:16];
                                    mem[sc2_req_addr + 3] <= sc2_req_wdata[31:24];
                                end
                                if (mask_lane_enabled(sc2_req_mask, 2)) begin
                                    mem[sc2_req_addr + 4] <= sc2_req_wdata[39:32];
                                    mem[sc2_req_addr + 5] <= sc2_req_wdata[47:40];
                                end
                                if (mask_lane_enabled(sc2_req_mask, 3)) begin
                                    mem[sc2_req_addr + 6] <= sc2_req_wdata[55:48];
                                    mem[sc2_req_addr + 7] <= sc2_req_wdata[63:56];
                                end
                            end
                        end
                    end

                    OWNER_SC3: begin
                        if (!sc3_req_valid) begin
                            sc_lock_active <= 1'b0;
                            if (sc_lock_contended) begin
                                if (rr_turn == 3'd5) rr_turn <= 3'd0;
                                else                 rr_turn <= rr_turn + 3'd1;
                            end
                        end else if (!sc3_stall_in && sel_addr_in_range && sc3_req_rw) begin
                            if (BIG_ENDIAN) begin
                                if (mask_lane_enabled(sc3_req_mask, 3)) begin
                                    mem[sc3_req_addr + 0] <= sc3_req_wdata[63:56];
                                    mem[sc3_req_addr + 1] <= sc3_req_wdata[55:48];
                                end
                                if (mask_lane_enabled(sc3_req_mask, 2)) begin
                                    mem[sc3_req_addr + 2] <= sc3_req_wdata[47:40];
                                    mem[sc3_req_addr + 3] <= sc3_req_wdata[39:32];
                                end
                                if (mask_lane_enabled(sc3_req_mask, 1)) begin
                                    mem[sc3_req_addr + 4] <= sc3_req_wdata[31:24];
                                    mem[sc3_req_addr + 5] <= sc3_req_wdata[23:16];
                                end
                                if (mask_lane_enabled(sc3_req_mask, 0)) begin
                                    mem[sc3_req_addr + 6] <= sc3_req_wdata[15:8];
                                    mem[sc3_req_addr + 7] <= sc3_req_wdata[7:0];
                                end
                            end else begin
                                if (mask_lane_enabled(sc3_req_mask, 0)) begin
                                    mem[sc3_req_addr + 0] <= sc3_req_wdata[7:0];
                                    mem[sc3_req_addr + 1] <= sc3_req_wdata[15:8];
                                end
                                if (mask_lane_enabled(sc3_req_mask, 1)) begin
                                    mem[sc3_req_addr + 2] <= sc3_req_wdata[23:16];
                                    mem[sc3_req_addr + 3] <= sc3_req_wdata[31:24];
                                end
                                if (mask_lane_enabled(sc3_req_mask, 2)) begin
                                    mem[sc3_req_addr + 4] <= sc3_req_wdata[39:32];
                                    mem[sc3_req_addr + 5] <= sc3_req_wdata[47:40];
                                end
                                if (mask_lane_enabled(sc3_req_mask, 3)) begin
                                    mem[sc3_req_addr + 6] <= sc3_req_wdata[55:48];
                                    mem[sc3_req_addr + 7] <= sc3_req_wdata[63:56];
                                end
                            end
                        end
                    end

                    default: begin
                        sc_lock_active <= 1'b0;
                    end
                endcase
            end
            else begin
                if (sel_valid && sel_addr_in_range) begin
                    if (is_scpad_owner(sel_owner)) begin
                        sc_lock_active    <= 1'b1;
                        sc_lock_owner     <= sel_owner;
                        sc_lock_contended <= sel_contended;

                        if (sel_we && !sel_sc_stall_in) begin
                            case (sel_owner)
                                OWNER_SC0: begin
                                    if (BIG_ENDIAN) begin
                                        if (mask_lane_enabled(sel_sc_mask, 3)) begin
                                            mem[sel_addr + 0] <= sel_wdata[63:56];
                                            mem[sel_addr + 1] <= sel_wdata[55:48];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 2)) begin
                                            mem[sel_addr + 2] <= sel_wdata[47:40];
                                            mem[sel_addr + 3] <= sel_wdata[39:32];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 1)) begin
                                            mem[sel_addr + 4] <= sel_wdata[31:24];
                                            mem[sel_addr + 5] <= sel_wdata[23:16];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 0)) begin
                                            mem[sel_addr + 6] <= sel_wdata[15:8];
                                            mem[sel_addr + 7] <= sel_wdata[7:0];
                                        end
                                    end else begin
                                        if (mask_lane_enabled(sel_sc_mask, 0)) begin
                                            mem[sel_addr + 0] <= sel_wdata[7:0];
                                            mem[sel_addr + 1] <= sel_wdata[15:8];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 1)) begin
                                            mem[sel_addr + 2] <= sel_wdata[23:16];
                                            mem[sel_addr + 3] <= sel_wdata[31:24];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 2)) begin
                                            mem[sel_addr + 4] <= sel_wdata[39:32];
                                            mem[sel_addr + 5] <= sel_wdata[47:40];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 3)) begin
                                            mem[sel_addr + 6] <= sel_wdata[55:48];
                                            mem[sel_addr + 7] <= sel_wdata[63:56];
                                        end
                                    end
                                end
                                OWNER_SC1: begin
                                    if (BIG_ENDIAN) begin
                                        if (mask_lane_enabled(sel_sc_mask, 3)) begin
                                            mem[sel_addr + 0] <= sel_wdata[63:56];
                                            mem[sel_addr + 1] <= sel_wdata[55:48];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 2)) begin
                                            mem[sel_addr + 2] <= sel_wdata[47:40];
                                            mem[sel_addr + 3] <= sel_wdata[39:32];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 1)) begin
                                            mem[sel_addr + 4] <= sel_wdata[31:24];
                                            mem[sel_addr + 5] <= sel_wdata[23:16];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 0)) begin
                                            mem[sel_addr + 6] <= sel_wdata[15:8];
                                            mem[sel_addr + 7] <= sel_wdata[7:0];
                                        end
                                    end else begin
                                        if (mask_lane_enabled(sel_sc_mask, 0)) begin
                                            mem[sel_addr + 0] <= sel_wdata[7:0];
                                            mem[sel_addr + 1] <= sel_wdata[15:8];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 1)) begin
                                            mem[sel_addr + 2] <= sel_wdata[23:16];
                                            mem[sel_addr + 3] <= sel_wdata[31:24];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 2)) begin
                                            mem[sel_addr + 4] <= sel_wdata[39:32];
                                            mem[sel_addr + 5] <= sel_wdata[47:40];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 3)) begin
                                            mem[sel_addr + 6] <= sel_wdata[55:48];
                                            mem[sel_addr + 7] <= sel_wdata[63:56];
                                        end
                                    end
                                end
                                OWNER_SC2: begin
                                    if (BIG_ENDIAN) begin
                                        if (mask_lane_enabled(sel_sc_mask, 3)) begin
                                            mem[sel_addr + 0] <= sel_wdata[63:56];
                                            mem[sel_addr + 1] <= sel_wdata[55:48];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 2)) begin
                                            mem[sel_addr + 2] <= sel_wdata[47:40];
                                            mem[sel_addr + 3] <= sel_wdata[39:32];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 1)) begin
                                            mem[sel_addr + 4] <= sel_wdata[31:24];
                                            mem[sel_addr + 5] <= sel_wdata[23:16];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 0)) begin
                                            mem[sel_addr + 6] <= sel_wdata[15:8];
                                            mem[sel_addr + 7] <= sel_wdata[7:0];
                                        end
                                    end else begin
                                        if (mask_lane_enabled(sel_sc_mask, 0)) begin
                                            mem[sel_addr + 0] <= sel_wdata[7:0];
                                            mem[sel_addr + 1] <= sel_wdata[15:8];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 1)) begin
                                            mem[sel_addr + 2] <= sel_wdata[23:16];
                                            mem[sel_addr + 3] <= sel_wdata[31:24];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 2)) begin
                                            mem[sel_addr + 4] <= sel_wdata[39:32];
                                            mem[sel_addr + 5] <= sel_wdata[47:40];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 3)) begin
                                            mem[sel_addr + 6] <= sel_wdata[55:48];
                                            mem[sel_addr + 7] <= sel_wdata[63:56];
                                        end
                                    end
                                end
                                OWNER_SC3: begin
                                    if (BIG_ENDIAN) begin
                                        if (mask_lane_enabled(sel_sc_mask, 3)) begin
                                            mem[sel_addr + 0] <= sel_wdata[63:56];
                                            mem[sel_addr + 1] <= sel_wdata[55:48];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 2)) begin
                                            mem[sel_addr + 2] <= sel_wdata[47:40];
                                            mem[sel_addr + 3] <= sel_wdata[39:32];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 1)) begin
                                            mem[sel_addr + 4] <= sel_wdata[31:24];
                                            mem[sel_addr + 5] <= sel_wdata[23:16];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 0)) begin
                                            mem[sel_addr + 6] <= sel_wdata[15:8];
                                            mem[sel_addr + 7] <= sel_wdata[7:0];
                                        end
                                    end else begin
                                        if (mask_lane_enabled(sel_sc_mask, 0)) begin
                                            mem[sel_addr + 0] <= sel_wdata[7:0];
                                            mem[sel_addr + 1] <= sel_wdata[15:8];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 1)) begin
                                            mem[sel_addr + 2] <= sel_wdata[23:16];
                                            mem[sel_addr + 3] <= sel_wdata[31:24];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 2)) begin
                                            mem[sel_addr + 4] <= sel_wdata[39:32];
                                            mem[sel_addr + 5] <= sel_wdata[47:40];
                                        end
                                        if (mask_lane_enabled(sel_sc_mask, 3)) begin
                                            mem[sel_addr + 6] <= sel_wdata[55:48];
                                            mem[sel_addr + 7] <= sel_wdata[63:56];
                                        end
                                    end
                                end
                                default: begin
                                end
                            endcase
                        end
                    end else begin
                        if (sel_we) begin
                            if (BIG_ENDIAN) begin
                                mem[sel_addr + 0] <= sel_wdata[63:56];
                                mem[sel_addr + 1] <= sel_wdata[55:48];
                                mem[sel_addr + 2] <= sel_wdata[47:40];
                                mem[sel_addr + 3] <= sel_wdata[39:32];
                                mem[sel_addr + 4] <= sel_wdata[31:24];
                                mem[sel_addr + 5] <= sel_wdata[23:16];
                                mem[sel_addr + 6] <= sel_wdata[15:8];
                                mem[sel_addr + 7] <= sel_wdata[7:0];
                            end else begin
                                mem[sel_addr + 0] <= sel_wdata[7:0];
                                mem[sel_addr + 1] <= sel_wdata[15:8];
                                mem[sel_addr + 2] <= sel_wdata[23:16];
                                mem[sel_addr + 3] <= sel_wdata[31:24];
                                mem[sel_addr + 4] <= sel_wdata[39:32];
                                mem[sel_addr + 5] <= sel_wdata[47:40];
                                mem[sel_addr + 6] <= sel_wdata[55:48];
                                mem[sel_addr + 7] <= sel_wdata[63:56];
                            end
                            if (sel_contended) begin
                                if (rr_turn == 3'd5) rr_turn <= 3'd0;
                                else                 rr_turn <= rr_turn + 3'd1;
                            end
                        end else begin
                            burst_active    <= 1'b1;
                            burst_owner     <= sel_owner;
                            burst_base_addr <= sel_addr;
                            burst_beat_idx  <= 3'd1;
                            burst_contended <= sel_contended;
                        end
                    end
                end
            end
        end
    end

    final begin
        integer fd;
        integer idx;
        integer j;

        fd = $fopen(dump_file_name, "w");
        if (fd == 0) begin
            $error("[sim_ram_rr_burst64_4scpad] Failed to open dump file: %s", dump_file_name);
        end else begin
            for (idx = 0; idx < MEM_BYTES; idx += 8) begin
                if (idx + 7 < MEM_BYTES) begin
                    $fwrite(fd, "%02x %02x %02x %02x %02x %02x %02x %02x\n",
                        mem[idx + 0], mem[idx + 1], mem[idx + 2], mem[idx + 3],
                        mem[idx + 4], mem[idx + 5], mem[idx + 6], mem[idx + 7]
                    );
                end else begin
                    for (j = idx; j < MEM_BYTES; j++) begin
                        $fwrite(fd, "%02x ", mem[j]);
                    end
                    $fwrite(fd, "\n");
                end
            end
            $fclose(fd);
            $display("[sim_ram_rr_burst64_4scpad] Memory dumped to %s", dump_file_name);
        end
    end

endmodule