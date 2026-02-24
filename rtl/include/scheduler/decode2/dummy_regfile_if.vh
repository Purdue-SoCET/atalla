`ifndef DUMMY_REGFILE_IF_VH
`define DUMMY_REGFILE_IF_VH

`include "atalla_isa_types.vh"

interface dummy_regfile_if;
    import atalla_isa_pkg::*;

    logic                     WEN [4];
    logic                     REN [4];
    logic [SCALAR_REG_W-1:0]       wsel  [4];
    word_t                         wdata [4];
    logic [SCALAR_REG_W-1:0]       rsel  [4];
    word_t                         rdata [4];

    modport rf (
        input   REN, WEN, wsel, wdata, rsel,
        output  rdata
    );

    modport tb (
        input   rdata,
        output  WEN, wsel, wdata, rsel
    );

endinterface

`endif // REGFILE_IF_VH
