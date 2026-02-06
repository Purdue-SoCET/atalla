`ifndef WRITE_DATA_QUEUE_IF_VH
`define WRITE_DATA_QUEUE_IF_VH

`include "dram_pkg.vh"

interface write_data_queue_if;

logic wstrb, wvalid, wdata, wid, wlen;
logic wready, bwvalid, bwresp, bwid;
logic bwready;

endinterface

`endif // WRITE_DATA_QUEUE_IF