module system #()
(
    input logic CLK, nRST,
    output logic [NUM_BANKS-1:0] ram_mem_REN,
    output logic [NUM_BANKS-1:0] ram_mem_WEN,
    output logic [NUM_BANKS-1:0][31:0] ram_mem_addr,
    output logic [NUM_BANKS-1:0][31:0] ram_mem_store,
    input logic [NUM_BANKS-1:0][31:0] ram_mem_data,
    input logic [NUM_BANKS-1:0] ram_mem_complete
);

    logic mem_in;
    logic [31:0] mem_in_addr;
    logic mem_in_rw_mode;
    logic [31:0] mem_in_store_value;
    logic [3:0] mem_out_uuid;
    logic stall;
    logic hit;
    logic [31:0] hit_load;
    logic [NUM_BANKS-1:0] block_status;
    logic block_status_reduced;
    logic [NUM_BANKS-1:0][UUID_SIZE-1:0] uuid_block;
    logic dp_out_flushed;


    scheduler_core CORE(
        .CLK(CLK), .nRST(nRST),
        .WEN(mem_in_rw_mode), .REN(), .mem_in_valid(mem_in), .data_store(mem_in_store_value), .data_addr(mem_in_addr),
        .data_load(hit_load), .hit(hit), .block_status(block_status_reduced),
        .ihit(1'b0), .imemload('0), .ready()
    );

    lockup_free_cache DCACHE (
        .CLK(CLK), .nRST(nRST),
        .mem_in(mem_in),
        .mem_in_addr(mem_in_addr),
        .mem_in_rw_mode(mem_in_rw_mode), // 0 = read, 1 = write
        .mem_in_store_value(mem_in_store_value),
        .dp_in_halt(1'b0), 
        .mem_out_uuid(mem_out_uuid),
        .stall(stall),
        .hit(hit),
        .hit_load(hit_load),
        .block_status(block_status),
        .uuid_block(uuid_block),
        .dp_out_flushed(dp_out_flushed),

        // RAM Signals
        .ram_mem_REN(ram_mem_REN),
        .ram_mem_WEN(ram_mem_WEN),
        .ram_mem_addr(ram_mem_addr),
        .ram_mem_store(ram_mem_store),
        .ram_mem_data(ram_mem_data),
        .ram_mem_complete(ram_mem_complete)
    );

    assign block_status_reduced = block_status[0] | block_status[1] | block_status[2] | block_status[3];


endmodule