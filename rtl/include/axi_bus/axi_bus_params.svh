/*  Aryan Kadakia - kadakia0@purdue.edu */

`ifndef AXI_BUS_PARAMS_SVH
`define AXI_BUS_PARAMS_SVH

    parameter int unsigned NUM_MASTERS     = 4;
    parameter int unsigned NUM_U_READS     = 4;      // Number of outstanding reads for one UNITS (I$, D$, SP0, SP1)
    parameter int unsigned NUM_U_WRITES    = 4;      // Number of outstanding writes for one UNITS (D$, SP0, SP1)
    parameter int unsigned ADDR_WIDTH      = 32;
    parameter int unsigned DATA_BEAT_WIDTH = 64;     // Size of 1 beat in transaction

`endif