// reg_file.sv ============================================================
// Top-level wrapper — instantiates reggie and op_buffer
// ========================================================================
`include "reg_file_if.sv"

module reg_file #(
    parameter BANK_COUNT   = 4,
    parameter BANK_REGS    = 64,
    parameter DREAD_PORTS  = 4,
    parameter DWRITE_PORTS = 4,
    parameter NUM_ELEMENTS = 1,
    parameter DATA_WIDTH   = 32,
    parameter ZERO_REG_VAL = 0,

    parameter BANK_IDX  = $clog2(BANK_COUNT),
    parameter ADDR_IDX  = $clog2(BANK_REGS),
    parameter VREG_W    = DATA_WIDTH * NUM_ELEMENTS,
    parameter VSEL_W    = BANK_IDX + ADDR_IDX,
    parameter LOG_BANKS = BANK_COUNT / 2
)(
    input  logic CLK, nRST,
    reg_file_if.reg_file rif
);

    reg_file_if #(
        .BANK_COUNT  (BANK_COUNT),
        .BANK_REGS   (BANK_REGS),
        .DREAD_PORTS (DREAD_PORTS),
        .DWRITE_PORTS(DWRITE_PORTS),
        .NUM_ELEMENTS(NUM_ELEMENTS),
        .DATA_WIDTH  (DATA_WIDTH),
        .ZERO_REG_VAL(ZERO_REG_VAL)
    ) rif_reggie ();

    reg_file_if #(
        .BANK_COUNT  (BANK_COUNT),
        .BANK_REGS   (BANK_REGS),
        .DREAD_PORTS (DREAD_PORTS),
        .DWRITE_PORTS(DWRITE_PORTS),
        .NUM_ELEMENTS(NUM_ELEMENTS),
        .DATA_WIDTH  (DATA_WIDTH), 
        .ZERO_REG_VAL(ZERO_REG_VAL)
    ) rif_opbuffer ();

    assign rif_reggie.REN = rif.REN;
    assign rif_reggie.vs = rif.vs;
    assign rif_reggie.WEN = rif.WEN;
    assign rif_reggie.vd = rif.vd;
    assign rif_reggie.vdata = rif.vdata;
    assign rif_reggie.dependencies_ready = rif.dependencies_ready;
    assign rif_reggie.dec2_ready = rif.dec2_ready;

    assign rif_opbuffer.done_state = rif_reggie.done_state;
    assign rif_opbuffer.reggie_vreg = rif_reggie.reggie_vreg;
    assign rif_opbuffer.reggie_dvalid = rif_reggie.reggie_dvalid;
    assign rif_opbuffer.reggie_ready = rif_reggie.reggie_ready;


    assign rif_opbuffer.accomplished = rif.accomplished;
    assign rif.opbuff_vreg = rif_opbuffer.opbuff_vreg;
    assign rif.opbuff_ivalid = rif_opbuffer.opbuff_ivalid;



    reggie #(
        .BANK_COUNT  (BANK_COUNT),
        .BANK_REGS   (BANK_REGS),
        .DREAD_PORTS (DREAD_PORTS),
        .DWRITE_PORTS(DWRITE_PORTS),
        .NUM_ELEMENTS(NUM_ELEMENTS),
        .DATA_WIDTH  (DATA_WIDTH),
        .ZERO_REG_VAL(ZERO_REG_VAL)
    ) u_reggie (
        .CLK (CLK),
        .nRST(nRST),
        .rif (rif_reggie)
    );

    op_buffer #(
        .DREAD_PORTS(DREAD_PORTS),
        .VREG_W     (VREG_W),
        .LOG_BANKS  (LOG_BANKS)
    ) u_op_buffer (
        .CLK (CLK),
        .nRST(nRST),
        .rif (rif_opbuffer)
    );

    assign rif.vrf_ready = rif_reggie.reggie_ready;

endmodule