// ------------------------------------------------------------
// lane_fu_pt.sv
// Metadata sync pipeline between sequencer (issue) and FU (wb).
// Uses the shared sync_fifo (unchanged).
// ------------------------------------------------------------

module lane_fu_pt #(
    parameter int DATA_W  = 16,
    parameter int LATENCY = 8  // FU pipeline latency (or higher)
)(
    input  logic              CLK,
    input  logic              nRST,

    // Input Side (Issue Stage)
    input  logic              issue_valid, // Sequencer is trying to push
    input  logic              fu_ready,    // FU is ready to accept
    input  logic [DATA_W-1:0] meta_in,     // Tags (vd, idx, etc.)
    output logic              sync_ready,  // Backpressure to sequencer

    // Output Side (Writeback Stage)
    input  logic              wb_valid,    // FU has a valid result
    input  logic              wb_ready,    // WB stage is ready to accept
    output logic [DATA_W-1:0] meta_out     // Tags aligned with result
);

    // FIFO depth: enough to cover latency + a bit of slack
    localparam int FIFO_DEPTH =
        (LATENCY < 2) ? 4 : (1 << $clog2(LATENCY + 4));

    logic fifo_empty;
    logic fifo_full;
    logic push;
    logic pop;

    // ---------------------------------------------------------
    // Push / Pop Conditions
    // ---------------------------------------------------------

    // Push when the sequencer fires and FU is conceptually ready.
    // The FIFO itself still guards with !full internally.
    assign push = issue_valid && fu_ready;

    // Pop when FU result is valid and WB is ready, BUT do not pop empty.
    // This prevents reading an uninitialized dout.
    assign pop  = wb_valid && wb_ready && !fifo_empty;

    // Backpressure to sequencer: ready when FIFO has space.
    assign sync_ready = fu_ready && !fifo_full;

    // ---------------------------------------------------------
    // FIFO Instantiation
    //   Uses your shared sync_fifo exactly as defined.
//   Port order: (rstn, clk, wr_en, rd_en, din, dout, empty, full)
// ---------------------------------------------------------
    sync_fifo #(
        .DEPTH  (FIFO_DEPTH),
        .DWIDTH (DATA_W)
    ) u_fifo (
        .rstn  (nRST),
        .clk   (CLK),
        .wr_en (push),
        .rd_en (pop),
        .din   (meta_in),
        .dout  (meta_out),
        .empty (fifo_empty),
        .full  (fifo_full)
    );

endmodule
