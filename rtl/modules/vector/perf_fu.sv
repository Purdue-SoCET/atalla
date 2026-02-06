module perf_fu #(
    parameter int CNT_WIDTH = 32
) (
    input logic CLK, nRST,

    input logic
        seq_busy,       // Sequencer is in busy state
        issue_valid,    // Sequencer is trying to issue
        fire_valid,     // Pipeline actually accepted data
        sync_ready,     // Metadata FIFO ready
        hold_valid,     // Output buffer has valid result
        wb_ready,       // Downsteam WB path is ready

    output logic [CNT_WIDTH-1:0]
        cnt_busy,       // Cycles FU is busy
        cnt_fire,       // Cycles pipeline accepted data
        cnt_stall_fifo, // Cycles stall occured because FIFO is full
        cnt_stall_wb,   // Cycles stall occured because result collector is backpressuring the lane

    input logic enable  = 1'b1,
                clear   = 1'b0
);

    logic is_stall_fifo, is_stall_wb;
    assign is_stall_fifo = issue_valid && !sync_ready;
    assign is_stall_wb = hold_valid && !wb_ready;

    perf_counter #(
        .WIDTH(CNT_WIDTH)
    ) u_cnt_busy (
        .CLK(CLK),
        .nRST(nRST),
        .enable(enable && seq_busy),
        .clear(clear),
        .count(cnt_busy)
    );

    perf_counter #(
        .WIDTH(CNT_WIDTH)
    ) u_cnt_fire (
        .CLK(CLK),
        .nRST(nRST),
        .enable(enable && fire_valid),
        .clear(clear),
        .count(cnt_fire)
    );

    perf_counter #(
        .WIDTH(CNT_WIDTH)
    ) u_cnt_stall_fifo (
        .CLK(CLK),
        .nRST(nRST),
        .enable(enable && is_stall_fifo),
        .clear(clear),
        .count(cnt_stall_fifo)
    );

    perf_counter #(
        .WIDTH(CNT_WIDTH)
    ) u_cnt_stall_wb (
        .CLK(CLK),
        .nRST(nRST),
        .enable(enable && is_stall_wb),
        .clear(clear),
        .count(cnt_stall_wb)
    );

endmodule

