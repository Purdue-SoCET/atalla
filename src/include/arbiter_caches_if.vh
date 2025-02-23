`ifndef ARBITER_CACHES_IF_VH
`define ARBITER_CACHES_IF_VH

// ram memory types
`include "cpu_types_pkg.vh"

interface arbiter_caches_if;

  // import types
  import cpu_types_pkg::*;

  // arbitration
  logic          iwait, dwait, iREN, dREN, dWEN;
  word_t         iload, dload, dstore;
  word_t         iaddr, daddr;


  // icache ports to controller
  modport icache (
    input   iwait, iload,
    output  iREN, iaddr
  );

  // dcache ports to controller
  modport dcache (
    input   dwait, dload,
    output  dREN, dWEN, daddr, dstore
  );

  // caches ports to controller
  modport caches(
    input   dwait, dload,
            iwait, iload,
    output  dREN, dWEN, daddr, dstore,
            iREN, iaddr
  );


endinterface

`endif //ARBITER_CACHES_IF_VH
