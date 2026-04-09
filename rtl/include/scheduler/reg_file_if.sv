// reg_file_if.sv =========================================================
// Parametric interface for the banked register file system
// ========================================================================
`ifndef REG_FILE_IF_SV
`define REG_FILE_IF_SV

interface reg_file_if #(
    parameter BANK_COUNT   = 4,
    parameter BANK_REGS    = 64,
    parameter DREAD_PORTS  = 4,
    parameter DWRITE_PORTS = 4,
    parameter NUM_ELEMENTS = 1,
    parameter DATA_WIDTH   = 32,
    parameter ZERO_REG_VAL = 0, // 0 = reg0 reads all-0s, 1 = reg0 reads all-1s

    // Derived — do not override
    parameter BANK_IDX  = $clog2(BANK_COUNT),
    parameter ADDR_IDX  = $clog2(BANK_REGS),
    parameter VREG_W    = DATA_WIDTH * NUM_ELEMENTS,
    parameter VSEL_W    = BANK_IDX + ADDR_IDX,
    parameter LOG_BANKS = BANK_COUNT / 2
);

    // -----------------------------------------------------------------------
    // Driven by upstream consumer (scheduler / scoreboard)
    // -----------------------------------------------------------------------
    logic [DREAD_PORTS-1:0][VSEL_W-1:0]   vs;
    logic [DREAD_PORTS-1:0]                REN;

    logic [DWRITE_PORTS-1:0][VSEL_W-1:0]  vd;
    logic [DWRITE_PORTS-1:0][VREG_W-1:0]  vdata;
    logic [DWRITE_PORTS-1:0]               WEN;

    logic accomplished;
    logic dependencies_ready;
    logic dec2_ready;
    logic done_state;

    // -----------------------------------------------------------------------
    // Driven by reggie → consumed by op_buffer
    // -----------------------------------------------------------------------
    logic [DREAD_PORTS-1:0][VREG_W-1:0]   reggie_vreg;
    logic [DREAD_PORTS-1:0]                reggie_dvalid;
    logic                                  reggie_ready;

    // -----------------------------------------------------------------------
    // Driven by op_buffer → consumed by execution units
    // -----------------------------------------------------------------------
    logic [DREAD_PORTS-1:0][VREG_W-1:0]   opbuff_vreg;
    logic [LOG_BANKS-1:0]                  opbuff_ivalid;

    // -----------------------------------------------------------------------
    // Surfaced to top level
    // -----------------------------------------------------------------------
    logic vrf_ready;

    // -----------------------------------------------------------------------
    // Modports
    // -----------------------------------------------------------------------
    modport reggie (
        input  vs, REN,
        input  vd, vdata, WEN,
        input dependencies_ready, dec2_ready,
        output reggie_vreg, reggie_dvalid, reggie_ready, done_state
    );

    modport op_buffer (
        input  accomplished,
        input  reggie_vreg, reggie_dvalid, reggie_ready, done_state,
        output opbuff_vreg, opbuff_ivalid
    );

    modport reg_file (
        input  vs, REN,
        input  vd, vdata, WEN,
        input  accomplished, dec2_ready,
        input  dependencies_ready, // from dependency checker
        output opbuff_vreg, opbuff_ivalid,
        output vrf_ready
    );

endinterface

`endif