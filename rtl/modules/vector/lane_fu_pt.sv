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
    // Backpressure: FU must be ready *and* FIFO must have space
    assign sync_ready = fu_ready && !fifo_full;

    // Push exactly when an element is truly accepted at the FU input
    assign push = issue_valid && sync_ready;

    // Pop exactly when a result is truly accepted at WB
    //assign pop  = wb_valid && wb_ready && !fifo_empty;
    assign pop = wb_valid && wb_ready;

    // ---------------------------------------------------------
    // FIFO Instantiation
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
