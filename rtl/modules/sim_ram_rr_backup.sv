`timescale 1ns/1ps

module sim_ram_rr #(
    parameter int ADDR_WIDTH   = 32,
    parameter int MEM_BYTES    = 1 << 20,
    parameter string INIT_FILE = "",
    parameter bit INIT_IS_HEX  = 1'b1,
    parameter string DUMP_FILE = "mem_dump.hex",
    parameter bit BIG_ENDIAN   = 1'b0   // 0=little-endian, 1=big-endian
)(
    input  logic                  clk,
    input  logic                  rst_n,

    // I-cache side
    input  logic                  ic_req_valid,
    input  logic                  ic_req_we,
    input  logic [ADDR_WIDTH-1:0] ic_req_addr,
    input  logic [63:0]           ic_req_wdata,
    output logic [63:0]           ic_resp_rdata,
    output logic                  ic_resp_hit,

    // D-cache side
    input  logic                  dc_req_valid,
    input  logic                  dc_req_we,
    input  logic [ADDR_WIDTH-1:0] dc_req_addr,
    input  logic [63:0]           dc_req_wdata,
    output logic [63:0]           dc_resp_rdata,
    output logic                  dc_resp_hit
);

    localparam int BEAT_BYTES  = 8;
    localparam int BURST_BEATS = 8;

    typedef enum logic {
        OWNER_IC = 1'b0,
        OWNER_DC = 1'b1
    } owner_t;

    logic [7:0] mem [0:MEM_BYTES-1];

    // Round-robin tie breaker:
    // 0 => next tie goes to icache
    // 1 => next tie goes to dcache
    logic rr_turn;

    // Burst state
    logic                  burst_active;
    owner_t                burst_owner;
    logic [ADDR_WIDTH-1:0] burst_base_addr;
    logic [2:0]            burst_beat_idx;
    logic                  burst_contended;

    // Arbitration / selected transaction in IDLE
    logic                  idle_sel_valid;
    logic                  idle_sel_is_dc;
    logic                  idle_sel_we;
    logic [ADDR_WIDTH-1:0] idle_sel_addr;
    logic [63:0]           idle_sel_wdata;
    logic                  idle_sel_contended;

    // Current effective transaction for combinational read path
    logic                  cur_valid;
    logic                  cur_is_dc;
    logic                  cur_we;
    logic [ADDR_WIDTH-1:0] cur_addr;
    logic [63:0]           cur_wdata;

    logic                  cur_addr_in_range;
    logic                  cur_addr_aligned;
    logic [63:0]           cur_read_word;

    string dump_file_name;
    integer i;

    // ------------------------------------------------------------
    // Memory init
    // ------------------------------------------------------------
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
                $display("[sim_ram_rr_burst64] Loading HEX file: %s", file_name);
                $readmemh(file_name, mem);
            end
            else begin
                $display("[sim_ram_rr_burst64] Loading BIN file: %s", file_name);
                $readmemb(file_name, mem);
            end
        end
        else begin
            $display("[sim_ram_rr_burst64] No init file provided; memory zeroed.");
        end

        $display("[sim_ram_rr_burst64] Endianness: %s",
                 BIG_ENDIAN ? "BIG_ENDIAN" : "LITTLE_ENDIAN");
    end

    // ------------------------------------------------------------
    // Idle arbitration
    // Only used when no burst is currently active
    // ------------------------------------------------------------
    always_comb begin
        idle_sel_valid     = 1'b0;
        idle_sel_is_dc     = 1'b0;
        idle_sel_we        = 1'b0;
        idle_sel_addr      = '0;
        idle_sel_wdata     = '0;
        idle_sel_contended = 1'b0;

        if (!burst_active) begin
            if (ic_req_valid && dc_req_valid) begin
                idle_sel_contended = 1'b1;
                if (rr_turn == 1'b0) begin
                    idle_sel_valid = 1'b1;
                    idle_sel_is_dc = 1'b0;
                    idle_sel_we    = ic_req_we;
                    idle_sel_addr  = ic_req_addr;
                    idle_sel_wdata = ic_req_wdata;
                end
                else begin
                    idle_sel_valid = 1'b1;
                    idle_sel_is_dc = 1'b1;
                    idle_sel_we    = dc_req_we;
                    idle_sel_addr  = dc_req_addr;
                    idle_sel_wdata = dc_req_wdata;
                end
            end
            else if (ic_req_valid) begin
                idle_sel_valid = 1'b1;
                idle_sel_is_dc = 1'b0;
                idle_sel_we    = ic_req_we;
                idle_sel_addr  = ic_req_addr;
                idle_sel_wdata = ic_req_wdata;
            end
            else if (dc_req_valid) begin
                idle_sel_valid = 1'b1;
                idle_sel_is_dc = 1'b1;
                idle_sel_we    = dc_req_we;
                idle_sel_addr  = dc_req_addr;
                idle_sel_wdata = dc_req_wdata;
            end
        end
    end

    // ------------------------------------------------------------
    // Current effective request
    //
    // If burst is active:
    //   keep ownership locked and stream beat addresses
    //
    // If no burst active:
    //   use the newly arbitrated idle request
    // ------------------------------------------------------------
    always_comb begin
        cur_valid = 1'b0;
        cur_is_dc = 1'b0;
        cur_we    = 1'b0;
        cur_addr  = '0;
        cur_wdata = '0;

        if (burst_active) begin
            cur_valid = 1'b1;
            cur_is_dc = (burst_owner == OWNER_DC);
            cur_we    = 1'b0;
            cur_addr  = burst_base_addr + (burst_beat_idx * BEAT_BYTES);
            cur_wdata = 64'h0;
        end
        else begin
            cur_valid = idle_sel_valid;
            cur_is_dc = idle_sel_is_dc;
            cur_we    = idle_sel_we;
            cur_addr  = idle_sel_addr;
            cur_wdata = idle_sel_wdata;
        end
    end

    assign cur_addr_in_range = ((cur_addr + BEAT_BYTES - 1) < MEM_BYTES);
    assign cur_addr_aligned  = (cur_addr[2:0] == 3'b000);

    // ------------------------------------------------------------
    // Combinational 64-bit read assembly
    // 0-cycle read behavior
    // ------------------------------------------------------------
    always_comb begin
        cur_read_word = 64'h0;

        if (cur_valid && !cur_we && cur_addr_in_range && cur_addr_aligned) begin
            if (BIG_ENDIAN) begin
                cur_read_word = {
                    mem[cur_addr + 0],
                    mem[cur_addr + 1],
                    mem[cur_addr + 2],
                    mem[cur_addr + 3],
                    mem[cur_addr + 4],
                    mem[cur_addr + 5],
                    mem[cur_addr + 6],
                    mem[cur_addr + 7]
                };
            end
            else begin
                cur_read_word = {
                    mem[cur_addr + 7],
                    mem[cur_addr + 6],
                    mem[cur_addr + 5],
                    mem[cur_addr + 4],
                    mem[cur_addr + 3],
                    mem[cur_addr + 2],
                    mem[cur_addr + 1],
                    mem[cur_addr + 0]
                };
            end
        end
    end

    // ------------------------------------------------------------
    // Response generation
    //
    // Read:
    //   resp_hit goes high immediately when the selected/locked read is valid
    //
    // Write:
    //   resp_hit also goes high immediately as an acknowledge, but
    //   memory contents update on the next clock edge.
    // ------------------------------------------------------------
    always_comb begin
        ic_resp_rdata = 64'h0;
        ic_resp_hit   = 1'b0;
        dc_resp_rdata = 64'h0;
        dc_resp_hit   = 1'b0;

        if (cur_valid && cur_addr_in_range && cur_addr_aligned) begin
            if (cur_is_dc) begin
                dc_resp_hit = 1'b1;
                if (!cur_we) begin
                    dc_resp_rdata = cur_read_word;
                end
            end
            else begin
                ic_resp_hit = 1'b1;
                if (!cur_we) begin
                    ic_resp_rdata = cur_read_word;
                end
            end
        end
    end

    // ------------------------------------------------------------
    // Sequential state update
    //
    // - writes happen here
    // - read burst ownership / beat index advance here
    // - rr_turn updates here
    // ------------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rr_turn         <= 1'b0;
            burst_active    <= 1'b0;
            burst_owner     <= OWNER_IC;
            burst_base_addr <= '0;
            burst_beat_idx  <= 3'd0;
            burst_contended <= 1'b0;
        end
        else begin
            if (burst_active) begin
                // Advance one beat per cycle.
                // Since there is no resp_ready input, we assume the owner
                // accepts one beat every clock.
                if (cur_addr_in_range && cur_addr_aligned) begin
                    if (burst_beat_idx == 3'd7) begin
                        burst_active <= 1'b0;
                        burst_beat_idx <= 3'd0;

                        if (burst_contended) begin
                            rr_turn <= ~rr_turn;
                        end
                    end
                    else begin
                        burst_beat_idx <= burst_beat_idx + 3'd1;
                    end
                end
            end
            else begin
                // No burst active: handle newly arbitrated transaction
                if (idle_sel_valid && cur_addr_in_range && cur_addr_aligned) begin
                    if (idle_sel_we) begin
                        // Single-beat 64-bit write
                        if (BIG_ENDIAN) begin
                            mem[cur_addr + 0] <= cur_wdata[63:56];
                            mem[cur_addr + 1] <= cur_wdata[55:48];
                            mem[cur_addr + 2] <= cur_wdata[47:40];
                            mem[cur_addr + 3] <= cur_wdata[39:32];
                            mem[cur_addr + 4] <= cur_wdata[31:24];
                            mem[cur_addr + 5] <= cur_wdata[23:16];
                            mem[cur_addr + 6] <= cur_wdata[15:8];
                            mem[cur_addr + 7] <= cur_wdata[7:0];
                        end
                        else begin
                            mem[cur_addr + 0] <= cur_wdata[7:0];
                            mem[cur_addr + 1] <= cur_wdata[15:8];
                            mem[cur_addr + 2] <= cur_wdata[23:16];
                            mem[cur_addr + 3] <= cur_wdata[31:24];
                            mem[cur_addr + 4] <= cur_wdata[39:32];
                            mem[cur_addr + 5] <= cur_wdata[47:40];
                            mem[cur_addr + 6] <= cur_wdata[55:48];
                            mem[cur_addr + 7] <= cur_wdata[63:56];
                        end

                        if (idle_sel_contended) begin
                            rr_turn <= ~rr_turn;
                        end
                    end
                    else begin
                        // Start 8-beat read burst
                        burst_active    <= 1'b1;
                        burst_owner     <= idle_sel_is_dc ? OWNER_DC : OWNER_IC;
                        burst_base_addr <= idle_sel_addr;
                        burst_beat_idx  <= 3'd1;  // beat 0 already visible this cycle
                        burst_contended <= idle_sel_contended;
                    end
                end
            end
        end
    end

    // ------------------------------------------------------------
    // Dump memory on exit
    // Dumps 8 bytes per line for readability
    // ------------------------------------------------------------
    final begin
        integer fd;
        integer idx;
        integer j;

        fd = $fopen(dump_file_name, "w");
        if (fd == 0) begin
            $error("[sim_ram_rr_burst64] Failed to open dump file: %s", dump_file_name);
        end
        else begin
            for (idx = 0; idx < MEM_BYTES; idx += 8) begin
                if (idx + 7 < MEM_BYTES) begin
                    $fwrite(fd, "%02x %02x %02x %02x %02x %02x %02x %02x\n",
                        mem[idx + 0], mem[idx + 1], mem[idx + 2], mem[idx + 3],
                        mem[idx + 4], mem[idx + 5], mem[idx + 6], mem[idx + 7]
                    );
                end
                else begin
                    for (j = idx; j < MEM_BYTES; j++) begin
                        $fwrite(fd, "%02x ", mem[j]);
                    end
                    $fwrite(fd, "\n");
                end
            end
            $fclose(fd);
            $display("[sim_ram_rr_burst64] Memory dumped to %s", dump_file_name);
        end
    end

endmodule