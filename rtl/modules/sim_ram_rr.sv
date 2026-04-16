`timescale 1ns/1ps

module sim_ram_rr_32 #(
    parameter int ADDR_WIDTH   = 32,
    parameter int MEM_BYTES    = 1 << 20,
    parameter string INIT_FILE = "",
    parameter bit INIT_IS_HEX  = 1'b1,
    parameter string DUMP_FILE = "mem_dump.hex",
    parameter bit BIG_ENDIAN   = 1'b0   // 0=little-endian, 1=big-endian
)(
    input  logic                  clk,
    input  logic                  rst_n,

    // I-cache
    input  logic                  ic_req_valid,
    input  logic                  ic_req_we,
    input  logic [ADDR_WIDTH-1:0] ic_req_addr,
    input  logic [31:0]           ic_req_wdata,
    output logic [63:0]           ic_resp_rdata,
    output logic                  ic_resp_hit,

    // D-cache
    input  logic                  dc_req_valid,
    input  logic                  dc_req_we,
    input  logic [ADDR_WIDTH-1:0] dc_req_addr,
    input  logic [31:0]           dc_req_wdata,
    output logic [31:0]           dc_resp_rdata,
    output logic                  dc_resp_hit
);

    logic [7:0] mem [0:MEM_BYTES-1];

    logic rr_turn;

    logic                  sel_valid;
    logic                  sel_is_dc;
    logic                  sel_we;
    logic [ADDR_WIDTH-1:0] sel_addr;
    logic [31:0]           sel_wdata;

    logic addr_in_range;

    string dump_file_name;
    integer i;

    task automatic dump_memory_to_file(input string file_name);
        integer fd;
        integer idx;
        integer j;
        begin
            fd = $fopen(file_name, "w");
            if (fd == 0) begin
                $error("[sim_ram_rr_32] Failed to open dump file: %s", file_name);
            end
            else begin
                for (idx = 0; idx < MEM_BYTES; idx += 4) begin
                    if (idx + 3 < MEM_BYTES) begin
                        $fwrite(fd, "%02x %02x %02x %02x\n",
                            mem[idx + 0],
                            mem[idx + 1],
                            mem[idx + 2],
                            mem[idx + 3]
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
                $display("[sim_ram_rr_32] Memory dumped to %s", file_name);
            end
        end
    endtask

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
                $display("[sim_ram_rr_32] Loading HEX file: %s", file_name);
                $readmemh(file_name, mem);
            end
            else begin
                $display("[sim_ram_rr_32] Loading BIN file: %s", file_name);
                $readmemb(file_name, mem);
            end
        end
        else begin
            $display("[sim_ram_rr_32] No init file provided; memory zeroed.");
        end

        $display("[sim_ram_rr_32] Endianness: %s",
                 BIG_ENDIAN ? "BIG_ENDIAN" : "LITTLE_ENDIAN");
    end

    always_comb begin
        sel_valid = 1'b0;
        sel_is_dc = 1'b0;
        sel_we    = 1'b0;
        sel_addr  = '0;
        sel_wdata = '0;

        if (ic_req_valid && dc_req_valid) begin
            if (rr_turn == 1'b0) begin
                sel_valid = 1'b1;
                sel_is_dc = 1'b0;
                sel_we    = ic_req_we;
                sel_addr  = ic_req_addr;
                sel_wdata = ic_req_wdata;
            end else begin
                sel_valid = 1'b1;
                sel_is_dc = 1'b1;
                sel_we    = dc_req_we;
                sel_addr  = dc_req_addr;
                sel_wdata = dc_req_wdata;
            end
        end
        else if (ic_req_valid) begin
            sel_valid = 1'b1;
            sel_is_dc = 1'b0;
            sel_we    = ic_req_we;
            sel_addr  = ic_req_addr;
            sel_wdata = ic_req_wdata;
        end
        else if (dc_req_valid) begin
            sel_valid = 1'b1;
            sel_is_dc = 1'b1;
            sel_we    = dc_req_we;
            sel_addr  = dc_req_addr;
            sel_wdata = dc_req_wdata;
        end
    end

    logic [63:0] read_word;

    always_comb begin
        ic_resp_rdata = 64'h0;
        ic_resp_hit   = 1'b0;
        dc_resp_rdata = 32'h0;
        dc_resp_hit   = 1'b0;
        read_word     = 64'h0;

        if (sel_valid && !sel_we && addr_in_range && (sel_addr[1:0] == 2'b00)) begin
            if (BIG_ENDIAN) begin
                read_word = {
                    mem[sel_addr + 0],
                    mem[sel_addr + 1],
                    mem[sel_addr + 2],
                    mem[sel_addr + 3],
                    mem[sel_addr + 4],
                    mem[sel_addr + 5],
                    mem[sel_addr + 6],
                    mem[sel_addr + 7]
                };
            end
            else begin
                read_word = {
                    mem[sel_addr + 7],
                    mem[sel_addr + 6],
                    mem[sel_addr + 5],
                    mem[sel_addr + 4],
                    mem[sel_addr + 3],
                    mem[sel_addr + 2],
                    mem[sel_addr + 1],
                    mem[sel_addr + 0]
                };
            end

            if (sel_is_dc) begin
                dc_resp_rdata = read_word[31:0];
                dc_resp_hit   = 1'b1;
            end
            else begin
                ic_resp_rdata = read_word;
                ic_resp_hit   = 1'b1;
            end
        end
        if (sel_valid && sel_we && addr_in_range && (sel_addr[1:0] == 2'b00)) begin
            if (sel_is_dc) begin
                dc_resp_hit   = 1'b1;
            end
            else begin
                ic_resp_hit   = 1'b1;
            end
        end
    end

    assign addr_in_range = (sel_addr + 3) < MEM_BYTES;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rr_turn <= 1'b0;
        end
        else begin
            if (sel_valid && sel_we && addr_in_range && (sel_addr[1:0] == 2'b00)) begin
                if (BIG_ENDIAN) begin
                    mem[sel_addr + 0] <= sel_wdata[31:24];
                    mem[sel_addr + 1] <= sel_wdata[23:16];
                    mem[sel_addr + 2] <= sel_wdata[15:8];
                    mem[sel_addr + 3] <= sel_wdata[7:0];
                end
                else begin
                    mem[sel_addr + 0] <= sel_wdata[7:0];
                    mem[sel_addr + 1] <= sel_wdata[15:8];
                    mem[sel_addr + 2] <= sel_wdata[23:16];
                    mem[sel_addr + 3] <= sel_wdata[31:24];
                end
            end

            if (ic_req_valid && dc_req_valid) begin
                rr_turn <= ~rr_turn;
            end
        end
    end

    final begin
        dump_memory_to_file(dump_file_name);
    end

endmodule