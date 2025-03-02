`ifndef FETCH_TBP_IF_VH
`define FETCH_TBP_IF_VH
`include "isa_types.vh"
`include "datapath_types.vh"

interface fetch_tbp_if;
    import isa_pkg::*;
    import datapath_pkg::*;
    
    // Signals
    /*
        Inputs: 
        pc_res: PC from resolution stage
        bt_res: branch target from resolution stage
        taken_res: 1 if branch taken in resolution stage
        enable_res: enable signal from resolution stage

        enable_fetch: enable signal (if BYTPE instruction) from fetch 
    */
    word_t pc_res, bt_res;
    logic taken_res;
    logic enable_res;

    logic enable_fetch;

    /*
        Outputs: 
        nxt_PC : next PC prediction
        pred_2bit_fetch: prediction for 2bit from fetch
        pred_gshare_fetch: prediction for gshare from fetch
    */
    word_t nxt_PC;
    logic pred_2bit_fetch;
    logic pred_gshare_fetch;

    modport tp (
        input 
        output 
    );

    modport tb (
        input 
        output 
    );
endinterface
`endif
