`include "atalla_isa_types.vh"

import scheduler_pkg::*;
import atalla_isa_pkg::*;

module system #()
(
    input logic CLK, nRST,
    //from dcache
    output logic ram_mem_REN_d,
    output logic ram_mem_WEN_d,
    output logic [31:0] ram_mem_addr_d,
    output logic [31:0] ram_mem_store_d,
    //to dcache
    input logic [31:0] ram_mem_data_d,
    input logic ram_mem_complete_d,

    //from icache
    output logic         mem_req_valid_i,
    output logic [31:0]  mem_req_addr_i,
    input  logic [63:0]  mem_resp_rdata_i,
    input  logic         mem_resp_hit_i,

    output logic halt,
    output logic dp_out_flushed
);

    logic mem_in;
    logic [31:0] mem_in_addr;
    logic mem_in_rw_mode;
    logic [31:0] mem_in_store_value;
    logic [3:0] mem_out_uuid;
    logic stall;
    logic miss;
    logic hit;
    logic [31:0] hit_load;
    logic block_status;
    logic uuid_block;

    logic ihit;
    instruction_packet_t imemload;
    logic imemREN;
    word_t imemaddr;


    scheduler_core CORE(
        .CLK(CLK), .nRST(nRST),
        //dcache
        .WEN(mem_in_rw_mode), .REN(),
        .mem_in_valid(mem_in),
        .data_store(mem_in_store_value), 
        .data_addr(mem_in_addr),
        .data_load(hit_load),
        .hit(hit),
        .block_status(block_status),
        .stall(stall),
        .miss(miss),
        //icache
        .ihit(ihit),
        .imemload(imemload),
        .imemready(imemready),
        .imemREN(imemREN),
        .imemaddr(imemaddr),
        //stuff
        .ready(),
        .halt(halt)
    );

    lockup_free_cache DCACHE (
        .CLK(CLK), .nRST(nRST),
        .mem_in(mem_in),
        .mem_in_addr(mem_in_addr),
        .mem_in_rw_mode(mem_in_rw_mode), // 0 = read, 1 = write
        .mem_in_store_value(mem_in_store_value),
        .dp_in_halt(halt), 
        .mem_out_uuid(mem_out_uuid),
        .stall(stall),
        .miss(miss),
        .hit(hit),
        .hit_load(hit_load),
        .block_status(block_status),
        .uuid_block(uuid_block),
        .dp_out_flushed(dp_out_flushed),

        // RAM Signals
        .ram_mem_REN(ram_mem_REN_d),
        .ram_mem_WEN(ram_mem_WEN_d),
        .ram_mem_addr(ram_mem_addr_d),
        .ram_mem_store(ram_mem_store_d),
        .ram_mem_data(ram_mem_data_d),
        .ram_mem_complete(ram_mem_complete_d)
    );

    icache ICACHE(
        .CLK(CLK), .nRST(nRST),
        //to/from scheduler (fetch)
        .imemaddr(imemaddr),
        .imemREN(imemREN),
        .ihit(ihit),
        .imemready(imemready),
        .imemload(imemload),
        //to/from memory
        .iwait(!mem_resp_hit_i),
        .iload(mem_resp_rdata_i),
        .iREN(mem_req_valid_i),
        .iaddr(mem_req_addr_i)
    );


endmodule