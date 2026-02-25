`ifndef DUMMY_REGFILE_IF_VH
`define DUMMY_REGFILE_IF_VH

`include "atalla_isa_types.vh"

interface dummy_regfile_if;
    import atalla_isa_pkg::*;

    logic [3:0]                     WEN;
    logic [3:0]                     REN;

    logic  [3:0][SCALAR_REG_W-1:0]  wsel;
    word_t [3:0]                    wdata;

    logic  [3:0][SCALAR_REG_W-1:0]  rsel;
    word_t [3:0]                    rdata;

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