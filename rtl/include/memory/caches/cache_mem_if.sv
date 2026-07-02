/*  Vinay Jagan - vjagan@purdue.edu */
/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`ifndef CACHE_MEM_IF_SV
`define CACHE_MEM_IF_SV

interface cache_mem_if;
    import caches_pkg::*;

    logic mem_req_ren;
    logic mem_req_wen;
    cache_addr_t mem_req_addr;
    cache_word_t mem_req_wdata;

    cache_word_t mem_resp_rdata;
    logic mem_resp_complete;

    modport cache (
        output mem_req_ren,
        output mem_req_wen,
        output mem_req_addr,
        output mem_req_wdata,
        input mem_resp_rdata,
        input mem_resp_complete
    );

    modport bank (
        output mem_req_ren,
        output mem_req_wen,
        output mem_req_addr,
        output mem_req_wdata,
        input mem_resp_rdata,
        input mem_resp_complete
    );

    modport mem (
        input mem_req_ren,
        input mem_req_wen,
        input mem_req_addr,
        input mem_req_wdata,
        output mem_resp_rdata,
        output mem_resp_complete
    );
endinterface

`endif
