`ifndef DDR_CONTROLLER_IF_VH
`define DDR_CONTROLLER_IF_VH

`include "dram_pkg.vh"

interface ddr_controller_if;

// AXI 

logic wstrb, wvalid, wdata, wid, wlen;
logic wready, bwvalid, bwresp, bwid;
logic bwready;

endinterface

`endif // DDR_CONTROLLER_IF_VH