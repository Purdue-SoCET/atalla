// reg_file.sv ============================================================
// Top-level wrapper — instantiates reggie and op_buffer
// ========================================================================
module reg_file #(
    parameter BANK_COUNT   = 4,
    parameter BANK_REGS    = 64,
    parameter DREAD_PORTS  = 4,
    parameter DWRITE_PORTS = 4,
    parameter NUM_ELEMENTS = 32,
    parameter DATA_WIDTH   = 16,

    parameter BANK_IDX  = $clog2(BANK_COUNT),
    parameter ADDR_IDX  = $clog2(BANK_REGS),
    parameter VREG_W    = DATA_WIDTH * NUM_ELEMENTS,
    parameter VSEL_W    = BANK_IDX + ADDR_IDX,
    parameter LOG_BANKS = BANK_COUNT / 2
)(
    input  logic CLK, nRST,
    reg_file_if rif
);

    reggie #(
        .BANK_COUNT  (BANK_COUNT),
        .BANK_REGS   (BANK_REGS),
        .DREAD_PORTS (DREAD_PORTS),
        .DWRITE_PORTS(DWRITE_PORTS),
        .NUM_ELEMENTS(NUM_ELEMENTS),
        .DATA_WIDTH  (DATA_WIDTH)
    ) u_reggie (
        .CLK (CLK),
        .nRST(nRST),
        .rif (rif.reggie)
    );

    op_buffer #(
        .DREAD_PORTS(DREAD_PORTS),
        .VREG_W     (VREG_W),
        .LOG_BANKS  (LOG_BANKS)
    ) u_op_buffer (
        .CLK (CLK),
        .nRST(nRST),
        .rif (rif.op_buffer)
    );

    assign rif.vrf_ready = rif.reggie_ready;

endmodule