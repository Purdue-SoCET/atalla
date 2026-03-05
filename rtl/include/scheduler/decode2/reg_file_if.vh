// reg_file_if.sv

`ifndef REG_FILE_IF_VH
`define REG_FILE_IF_VH

interface reg_file_if #(
    parameter NUM_REGS    = 256,
    parameter NUM_BANKS   = 4,
    parameter READ_PORTS  = 4,
    parameter WRITE_PORTS = 4,
    parameter DATA_WIDTH  = 32,
    parameter NUM_ELEMENTS = 1
)(
    input logic CLK, nRST
);

    localparam REG_BITS  = $clog2(NUM_REGS);
    localparam BANK_IDX  = $clog2(NUM_BANKS);
    localparam DATA_BITS = DATA_WIDTH * NUM_ELEMENTS;

    // Reggie inputs
    logic [READ_PORTS-1:0]                    REN;
    logic [READ_PORTS-1:0][REG_BITS-1:0]      rsel;

    logic [WRITE_PORTS-1:0]                   WEN;
    logic [WRITE_PORTS-1:0][REG_BITS-1:0]     wsel;
    logic [WRITE_PORTS-1:0][DATA_BITS-1:0]    wdata;

    // Reggie outputs
    logic [READ_PORTS-1:0][DATA_BITS-1:0]     rdata;
    logic [READ_PORTS-1:0]                    dvalid;
    logic                                     rf_ready;
    logic                                     dec2_ready;
    logic done_state;

    // Op buffer signals
    logic                                     accomplished;
    logic                                     iready;

    // Op buffer outputs
    localparam NUM_PAIRS = READ_PORTS / 2;
    logic [NUM_PAIRS-1:0]                     ivalid;
    logic [READ_PORTS-1:0][DATA_BITS-1:0]     opbuff_rdata;

    modport reggie (
        input  CLK, nRST,
        input  REN, rsel,
        input  WEN, wsel, wdata, dec2_ready,
        output rdata, dvalid, rf_ready, done_state
    );

    modport op_buffer (
        input  CLK, nRST,
        input  rdata, dvalid, rf_ready, done_state,
        input  accomplished,
        output ivalid, opbuff_rdata
    );

    modport reg_file (
        input  CLK, nRST,
        input  REN, rsel,
        input  WEN, wsel, wdata, dec2_ready,
        input  accomplished,
        output ivalid, opbuff_rdata,
        output rf_ready
    );

    modport tb (
        input  CLK, nRST,
        output REN, rsel,
        output WEN, wsel, wdata, dec2_ready,
        output accomplished,
        input  ivalid, opbuff_rdata,
        input  rf_ready
    );

endinterface

`endif