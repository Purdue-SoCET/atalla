`ifndef TRANSPOSE_UNIT_IF_SV
`define TRANSPOSE_UNIT_IF_SV

interface transpose_unit_if #(
    parameter int VEC_LEN = 32, 
    parameter int DATA_W  = 16
);
    // Control Signals
    logic clk;
    logic n_rst;
    logic en;

    // Command Handshake
    logic push_req;      // Request to PUSH one row/vector into scratchpad
    logic pop_req;       // Request to POP all transposed columns
    logic busy;          // Unit is currently busy with an operation
    
    // Status Signals
    logic vec_out_valid; // High when valid transposed data is on the bus
    logic full;          // Scratchpad is full (32 rows stored)
    logic empty;         // Scratchpad is empty

    // Data Busses (Vector Wide)
    logic [VEC_LEN-1:0][DATA_W-1:0] vec_in;
    logic [VEC_LEN-1:0][DATA_W-1:0] vec_out;

    // --- Modports ---

    // The Transpose Unit side (The Slave/Module)
    modport unit (
        input  clk, n_rst, en,
        input  push_req, pop_req, vec_in,
        output busy, vec_out, vec_out_valid, full, empty
    );

    // The Controller side (The Master/Core)
    modport controller (
        input  busy, vec_out, vec_out_valid, full, empty,
        output push_req, pop_req, vec_in, en
    );

    // Monitor (For Testbenches)
    modport monitor (
        input clk, n_rst, en, push_req, pop_req, busy, 
              vec_out_valid, full, empty, vec_in, vec_out
    );

endinterface

`endif