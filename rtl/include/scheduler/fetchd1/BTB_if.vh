`ifndef BTB_IF_VH
`define BTB_IF_VH
`include "atalla_isa_types.vh"

interface BTB_if;
    import atalla_isa_pkg::*;

    // -----------------------------------------------------------------------
    // 1. Fetch Stage Signals (Read Port)
    // -----------------------------------------------------------------------
    address_t pc_fetch;       
    logic     bhit;           
    address_t predict_target; 

    // -----------------------------------------------------------------------
    // 2. Branch Unit / Execute Stage Signals (Write Port)
    // -----------------------------------------------------------------------
    logic     update_en;      
    address_t pc_update;      
    address_t true_target;    


    modport fetch_view (
        output pc_fetch,
        input  bhit, predict_target
    );


    modport bu_view (
        output update_en, pc_update, true_target
    );


    modport btb_view (
        input  pc_fetch, pc_update, true_target, update_en,
        output bhit, predict_target
    );

endinterface

`endif