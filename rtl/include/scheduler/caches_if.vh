`ifndef CACHES_IF_VH
`define CACHES_IF_VH

interface caches_if;

  // arbitration
  logic          iwait, iREN;
  logic [63:0]         iload;
  logic [31:0]         iaddr;

  // icache ports to controller
  modport icache (
    input   iwait, iload,
    output  iREN, iaddr
  );

endinterface

`endif //CACHES_IF_VH