`ifndef DDR_CONTROLLER_IF_VH
`define DDR_CONTROLLER_IF_VH

`include "dram_pkg.vh"

interface ddr_controller_if;

// 2.5.2025 -> TASK - UPDATE WIDTHS

// AXI -> WRITE_QUEUE
logic wstrb, wvalid, wdata, wid, wlen;
logic wready, bwvalid, bwresp, bwid;
logic bwready;

// AXI -> LQ
logic arvalid, araddr, arid, arsize, arlen, arburst;
logic arready;
logic rvalid, rdata, rid, rlast, rresp;
logic rready; 

// AXI -> STQ
logic awvalid, awaddr, awid, awsize, awlen, awburst;
logic awready;

// STQ/LQ -> FRONTEND ARBITER
logic request_l, request_s;
logic address_l, address_s;
logic grant_l, grant_s;

// FRONTEND ARBITER -> BQ
logic fe_bg, fe_b, fe_r, fe_c;
logic fe_read, fe_write;
logic fe_id;
logic fe_write_bq;
logic fe_full; // [QUEUE_SIZE-1:0]

// BANK QUEUE -> COMMAND FSM
logic bq_pop; // 16
logic bq_rw; // 16
logic bq_bg, bq_b; // 2*16
logic bq_r; // 15*16
logic bq_c; // 10*16
logic bq_id; // 4*16

// COMMAND FSM -> BACKEND ARBITER
logic be_arb;
logic be_queue_ready;
logic be_bg, be_b; // 2*16
logic be_r; // 15*16
logic be_c; // 10*16
logic be_id; // 4*16

// BACKEND -> READ_ID_QUEUE
logic be_push_id, be_rid, be_rlen, be_rstrb;

// AXI -> READ_ID_QUEUE
logic rready;
logic rq_rid, rq_rvalid, rq_rlen, rq_rstrb; 

endinterface

`endif // DDR_CONTROLLER_IF_VH