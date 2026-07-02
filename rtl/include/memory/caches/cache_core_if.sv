/*  Vinay Jagan - vjagan@purdue.edu */
/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`ifndef CACHE_CORE_IF_SV
`define CACHE_CORE_IF_SV

interface cache_core_if;
    import caches_pkg::*;

    // Core -> Cache
    logic req_valid;
    cache_req_t req;
    logic halt;

    // Cache -> Core
    logic stall;
    logic hit;
    cache_word_t hit_rdata;
    // UUID accepted into an MSHR entry (0 when no miss enqueue was accepted).
    cache_uuid_t alloc_uuid;
    logic [NUM_BANKS-1:0] miss_complete_valid;
    cache_uuid_t miss_complete_uuid [NUM_BANKS-1:0];
    logic flushed;

    modport core (
        output req_valid,
        output req,
        output halt,
        input stall,
        input hit,
        input hit_rdata,
        input alloc_uuid,
        input miss_complete_valid,
        input miss_complete_uuid,
        input flushed
    );

    modport cache (
        input req_valid,
        input req,
        input halt,
        output stall,
        output hit,
        output hit_rdata,
        output alloc_uuid,
        output miss_complete_valid,
        output miss_complete_uuid,
        output flushed
    );
endinterface

`endif
