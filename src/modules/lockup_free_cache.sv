`include "cache_types_pkg.svh"

module lockup_free_cache (
    input logic CLK, nRST,
    input logic mem_in,
    input logic [31:0] mem_in_addr,
    input logic mem_in_rw_mode, // 0 = read, 1 = write
    input logic[31:0] mem_in_store_value,
    input logic dp_in_halt, 
    output logic [3:0] mem_out_uuid,
    output logic stall,
    output logic hit,
    output logic [31:0] hit_load,
    output logic[NUM_BANKS-1:0] block_status,
    output logic[NUM_BANKS-1:0][UUID_SIZE-1:0] uuid_block,
    output logic dp_out_flushed,

    // RAM Signals
    output logic [NUM_BANKS-1:0] ram_mem_REN,
    output logic [NUM_BANKS-1:0] ram_mem_WEN,
    output logic [NUM_BANKS-1:0][31:0] ram_mem_addr,
    output logic [NUM_BANKS-1:0][31:0] ram_mem_store,
    input logic [NUM_BANKS-1:0][31:0] ram_mem_data,
    input logic [NUM_BANKS-1:0] ram_mem_complete
);

    in_mem_instr hit_check_instr;
    logic [NUM_BANKS-1:0] hit_check;

    assign hit_check_instr.addr = addr_t'(mem_in_addr);
    assign hit_check_instr.rw_mode = mem_in_rw_mode;
    assign hit_check_instr.store_value = mem_in_store_value;
 
    logic [NUM_BANKS-1:0] miss;
    in_mem_instr new_miss;
    logic internal_halt_banks; 
    logic [NUM_BANKS-1:0] bank_hit;
    logic [NUM_BANKS-1:0] scheduler_miss;
    logic[NUM_BANKS-1:0] bank_stall;
    logic[NUM_BANKS-1:0] hc_stall;
    logic [NUM_BANKS-1:0] bank_free;
    logic [NUM_BANKS-1:0] buffer_empty;
    logic[NUM_BANKS-1:0] internal_flushed_banks;
    logic [NUM_BANKS-1:0][31:0] hit_return_load;
    logic [NUM_BANKS-1:0][UUID_SIZE-1:0] bank_uuids;

    // SRAM Interfaces
    logic[NUM_BANKS-1:0] sram_ren;
    logic[NUM_BANKS-1:0][NUM_SETS_PER_BANK_LEN-1:0] sram_raddr;
    cache_set [NUM_BANKS-1:0] sram_rdata;
    logic[NUM_BANKS-1:0] sram_rdone;

    logic[NUM_BANKS-1:0] sram_wen;
    logic [NUM_BANKS-1:0][NUM_SETS_PER_BANK_LEN-1:0] sram_waddr;
    cache_set[NUM_BANKS-1:0] sram_wdata;
    logic[NUM_BANKS-1:0] sram_wdone;
    logic [NUM_BANKS-1:0] sram_busy;

    mshr_reg [NUM_BANKS-1:0] mshr_out;

    logic [BANKS_LEN-1:0] bank_id;
    assign bank_id = (mem_in_addr >> (BYTE_OFF_BIT_LEN + BLOCK_OFF_BIT_LEN)) & (NUM_BANKS - 1);
    
    assign new_miss.addr = addr_t'(mem_in_addr);
    assign new_miss.rw_mode = mem_in_rw_mode;
    assign new_miss.store_value = mem_in_store_value;

    assign internal_halt_banks = (&buffer_empty) && dp_in_halt; 
    assign dp_out_flushed = (&internal_flushed_banks);

    genvar i;
    generate
        for (i = 0; i < NUM_BANKS; i++) begin : BANK_GEN
            cache_mshr_buffer mshr_buffer_i (
                .CLK           (CLK),
                .nRST          (nRST),
                .bank_id       (BANKS_LEN'(i)),
                .miss          (miss[i]),
                .mem_instr     (new_miss),
                .bank_free     (bank_free[i]),
                .mshr_out      (mshr_out[i]),
                .stall         (bank_stall[i]),
                .uuid_out      (bank_uuids[i]), 
                .buffer_empty  (buffer_empty[i])
            );

            sram_bank #(
                .READ_LATENCY(2),
                .WRITE_LATENCY(4),
                .HEIGHT(NUM_SETS_PER_BANK),
                .WIDTH($bits(cache_set))
            ) u_sram (
                .clk(CLK),
                .n_rst(nRST),
                .busy(sram_busy[i]),
                .ren(sram_ren[i]),
                .raddr(sram_raddr[i]),
                .rdata(sram_rdata[i]),
                .rdone(sram_rdone[i]),
                .wen(sram_wen[i]),
                .waddr(sram_waddr[i]),
                .wdata(sram_wdata[i]),
                .wdone(sram_wdone[i])
            );

            cache_bank u_cache_bank (
                .CLK                   (CLK),
                .nRST                  (nRST),
                .bank_id               (BANKS_LEN'(i)),
                .instr_valid           (hit_check[i]),
                .ram_mem_data          (ram_mem_data[i]),
                .mshr_entry_in         (mshr_out[i]),
                .mem_instr_in          (hit_check_instr),
                .ram_mem_complete      (ram_mem_complete[i]),
                .halt                  (internal_halt_banks),
                .cache_bank_free       (bank_free[i]),
                .scheduler_hit         (bank_hit[i]),
                .scheduler_miss        (scheduler_miss[i]),
                .hc_stall              (hc_stall[i]),
                .ram_mem_REN           (ram_mem_REN[i]),
                .ram_mem_WEN           (ram_mem_WEN[i]),
                .ram_mem_store         (ram_mem_store[i]),
                .ram_mem_addr          (ram_mem_addr[i]),
                .scheduler_data_out    (hit_return_load[i]),
                .scheduler_uuid_out    (uuid_block[i]),
                .scheduler_uuid_ready  (block_status[i]), 
                .flushed               (internal_flushed_banks[i]),

                .sram_ren              (sram_ren[i]),
                .sram_raddr            (sram_raddr[i]),
                .sram_rdata            (sram_rdata[i]),
                .sram_rdone            (sram_rdone[i]),
                .sram_wen              (sram_wen[i]),
                .sram_waddr            (sram_waddr[i]),
                .sram_wdata            (sram_wdata[i]),
                .sram_wdone            (sram_wdone[i]),
                .sram_busy             (sram_busy[i])
            );
        end
    endgenerate

    always_comb begin
        miss = 0;
        stall = 0;
        hit = 0;
        hit_load = 0;
        hit_check = 0;
        mem_out_uuid = '0; 

        if (bank_stall != 0 || hc_stall != 0) begin
            stall = 1;
        end
        for (int j = 0; j < NUM_BANKS; j++) begin
            if (bank_hit[j]) begin
                hit = 1;
                hit_load = hit_return_load[j];
            end
            if (scheduler_miss[j]) begin
                miss[j] = 1;
            end
        end

        hit_check[bank_id] = mem_in;
        mem_out_uuid = bank_uuids[bank_id];
    end

endmodule