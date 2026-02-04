`ifndef PERF_HANDSHAKE_IF_VH
`define PERF_HANDSHAKE_IF_VH

interface perf_handshake_if #(
  parameter int SIG_WIDTH = 1, // Width of the valid/ready signals
  parameter int CNT_WIDTH = 32 // Width of the cycle count
);

  // Handshake signals
  logic [SIG_WIDTH-1:0] valid, ready;

  // Performance counters
  logic [CNT_WIDTH-1:0] cnt_trans_cycles; // Cycles where transaction occurred (valid & ready)
  logic [CNT_WIDTH-1:0] cnt_stall_cycles; // Cycles where stall occurred (valid & ~ready)
  logic [CNT_WIDTH-1:0] cnt_starve_cycles; // Cycles where starve occurred (~valid & ready)
  logic [CNT_WIDTH-1:0] cnt_total_items; // Total number of items processed (transactions)

  modport phif (
    input valid, ready,
    output cnt_trans_cycles, cnt_stall_cycles, cnt_starve_cycles, cnt_total_items
  );

endinterface

`endif
