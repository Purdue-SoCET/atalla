/*  Vinay Jagan - vjagan@purdue.edu */
/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`ifndef CACHE_MSHR_IF_SV
`define CACHE_MSHR_IF_SV

interface cache_mshr_if;
    import caches_pkg::*;

    // Cache -> MSHR queue
    logic enqueue_miss_valid;
    cache_req_t enqueue_miss_req;
    cache_uuid_t enqueue_miss_uuid;
    logic dispatch_ready;

    // MSHR queue -> Cache
    cache_mshr_entry_t dispatch_entry;
    logic enqueue_stall;
    cache_uuid_t alloc_uuid;
    logic is_full;
    logic is_empty;

    modport cache (
        output enqueue_miss_valid,
        output enqueue_miss_req,
        output enqueue_miss_uuid,
        output dispatch_ready,
        input dispatch_entry,
        input enqueue_stall,
        input alloc_uuid,
        input is_full,
        input is_empty
    );

    modport mshr_buffer (
        input enqueue_miss_valid,
        input enqueue_miss_req,
        input enqueue_miss_uuid,
        input dispatch_ready,
        output dispatch_entry,
        output enqueue_stall,
        output alloc_uuid,
        output is_full,
        output is_empty
    );
endinterface

`endif
