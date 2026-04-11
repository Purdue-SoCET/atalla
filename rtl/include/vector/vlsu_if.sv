`ifndef VLSU_IF_SV
`define VLSU_IF_SV
`include "vector_pkg.vh"

interface vlsu_if;
    `include "scpad_params.svh"
    import scpad_pkg::*;
    import vector_pkg::*;

    // ------------------------------------------------------------------
    // Scheduler => VLSU (one per scratchpad channel)
    //
    // ISA VM instruction format (single-row transfer per instruction):
    //   sid | num_cols | rs2 (row_number reg) | rs1 (base reg) | vd
    //
    // The scheduler / decode stage is responsible for reading the scalar
    // register file BEFORE driving sched_req. By the time a request
    // reaches the VLSU, all register values must already be resolved.
    //
    // Field mapping (ISA -> struct):
    //   spad_addr <- rs1 scalar reg value (base address into scratchpad)
    //   row_id    <- rs2 scalar reg value (row offset within the tile)
    //   num_cols  <- instruction immediate (tile width - 1, 0..31)
    //   vdst      <- vd field (vector register destination)
    //   write     <- 0 for load, 1 for store
    //
    // Address convention:
    //   The scratchpad frontend computes the target SRAM row as
    //   (spad_addr + row_id). rs2 should be incremented by 1 per row
    //   in loops, NOT by ROW_BYTES. This is NOT a clean byte-addressed
    //   interface -- the SDMA/backend path uses different semantics for
    //   the same spad_addr field. Known cleanup item, pending ISA owner.
    // ------------------------------------------------------------------
    typedef struct packed {
        logic                        valid;
        logic                        write;
        logic [SCPAD_ADDR_WIDTH-1:0] spad_addr;
        logic [VIDX_W-1:0]          vdst;
        logic [MAX_DIM_WIDTH-1:0]   num_cols;
        logic [MAX_DIM_WIDTH-1:0]   row_id;
    } vlsu_sched_req_t;

    // VLSU => Scheduler
    typedef struct packed {
        logic ready;
    } vlsu_sched_res_t;

    // VRF => VLSU (store data)
    typedef struct packed {
        vreg_t data;
        logic  valid;
    } vlsu_vrf_store_t;

    // VLSU => Writeback Buffer (load data)
    typedef struct packed {
        vreg_t             load_data;
        logic [VIDX_W-1:0] vdst;
        logic              valid;
    } vlsu_wb_t;

    // VLSU status
    typedef struct packed {
        logic busy;
        logic load_queue_full;
    } vlsu_status_t;

    // ------------------------------------------------------------------
    // Wires (arrayed per scratchpad)
    // ------------------------------------------------------------------
    vlsu_sched_req_t  sched_req  [NUM_SCPADS];
    vlsu_sched_res_t  sched_res  [NUM_SCPADS];
    vlsu_vrf_store_t  vrf_store  [NUM_SCPADS];
    vlsu_wb_t         wb_out     [NUM_SCPADS];
    logic             wb_ready   [NUM_SCPADS];
    vlsu_status_t     status     [NUM_SCPADS];

    // ------------------------------------------------------------------
    // Modports
    // ------------------------------------------------------------------

    // Used by the VLSU module
    modport vlsu (
        input  sched_req,
        output sched_res,
        input  vrf_store,
        output wb_out,
        input  wb_ready,
        output status
    );

    // Used by the scheduler to drive requests / read status
    modport vlsu_sched (
        output sched_req,
        input  sched_res,
        input  status
    );

    // Used by the writeback arbiter
    modport vlsu_wb (
        input  wb_out,
        output wb_ready
    );

    // Used by the testbench (full access)
    modport vlsu_tb (
        output sched_req,
        input  sched_res,
        output vrf_store,
        input  wb_out,
        output wb_ready,
        input  status
    );

endinterface

`endif