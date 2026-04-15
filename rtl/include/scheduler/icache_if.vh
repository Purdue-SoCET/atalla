ifndef ICACHES_IF_VH
define ICACHES_IF_VH

interface icaches_if;

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

`endif //ICACHES_IF_VH