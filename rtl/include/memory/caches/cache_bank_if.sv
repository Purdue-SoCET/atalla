/*  Vinay Jagan - vjagan@purdue.edu */
/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`ifndef CACHE_BANK_IF_SV
`define CACHE_BANK_IF_SV

interface cache_bank_if;
    import caches_pkg::*;

    // Cache -> Bank
    logic lookup_req_valid;
    cache_req_t lookup_req;
    cache_mshr_entry_t dispatch_entry;
    logic halt_flush;

    // Bank -> Cache
    logic bank_ready;
    logic lookup_hit;
    cache_word_t lookup_rdata;
    logic miss_complete_valid;
    cache_uuid_t miss_complete_uuid;
    logic flushed;

    modport cache (
        output lookup_req_valid,
        output lookup_req,
        output dispatch_entry,
        output halt_flush,
        input bank_ready,
        input lookup_hit,
        input lookup_rdata,
        input miss_complete_valid,
        input miss_complete_uuid,
        input flushed
    );

    modport bank (
        input lookup_req_valid,
        input lookup_req,
        input dispatch_entry,
        input halt_flush,
        output bank_ready,
        output lookup_hit,
        output lookup_rdata,
        output miss_complete_valid,
        output miss_complete_uuid,
        output flushed
    );
endinterface

`endif
