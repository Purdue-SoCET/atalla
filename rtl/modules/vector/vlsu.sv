`include "vector_pkg.vh"
`include "scpad_pkg.sv"

module vlsu #(
    parameter int FIFO_DEPTH = 13,
    parameter int NUM_VREGS  = 256
) (
    input  logic        CLK,
    input  logic        nRST,

    // Scheduler interface - one channel per scratchpad
    input  logic                                        sched_valid_in  [scpad_pkg::NUM_SCPADS],
    output logic                                        sched_ready_out [scpad_pkg::NUM_SCPADS],
    input  logic                                        sched_write     [scpad_pkg::NUM_SCPADS],
    input  logic [scpad_pkg::SCPAD_ADDR_WIDTH-1:0]      sched_addr      [scpad_pkg::NUM_SCPADS],
    input  logic [vector_pkg::VIDX_W-1:0]               sched_vdst      [scpad_pkg::NUM_SCPADS],

    // Swizzle parameters - per channel
    input  logic [scpad_pkg::MAX_DIM_WIDTH-1:0]         sched_num_rows  [scpad_pkg::NUM_SCPADS],
    input  logic [scpad_pkg::MAX_DIM_WIDTH-1:0]         sched_num_cols  [scpad_pkg::NUM_SCPADS],
    input  logic [scpad_pkg::MAX_DIM_WIDTH-1:0]         sched_row_id    [scpad_pkg::NUM_SCPADS],
    input  logic [scpad_pkg::MAX_DIM_WIDTH-1:0]         sched_col_id    [scpad_pkg::NUM_SCPADS],
    input  logic                                        sched_row_or_col[scpad_pkg::NUM_SCPADS],

    // VRF store data - one per channel
    input  vector_pkg::vreg_t                           vrf_store_data  [scpad_pkg::NUM_SCPADS],
    input  logic                                        vrf_store_valid [scpad_pkg::NUM_SCPADS],

    // Scratchpad interface - per scratchpad
    output scpad_pkg::req_t                             sp_req  [scpad_pkg::NUM_SCPADS],
    input  logic                                        sp_stall [scpad_pkg::NUM_SCPADS],
    input  scpad_pkg::res_t                             sp_res  [scpad_pkg::NUM_SCPADS],

    // Writeback - single port to writeback buffer
    output vector_pkg::vreg_t                           wb_load_data,
    output logic [vector_pkg::VIDX_W-1:0]               wb_vdst,
    output logic                                        wb_valid_out,
    input  logic                                        wb_ready_in,

    output logic                                        vlsu_busy,
    output logic                                        load_queue_full [scpad_pkg::NUM_SCPADS]
);

    import vector_pkg::*;
    import scpad_pkg::*;

    localparam int VDST_WIDTH   = VIDX_W;
    localparam int RDATA_WIDTH  = $bits(scpad_data_t);
    localparam int SP_IDX_WIDTH = (NUM_SCPADS > 1) ? $clog2(NUM_SCPADS) : 1;

    //----------------------------------------------------------------
    // Per-channel load queue FIFOs (stores vdst, pushed on load issue)
    //----------------------------------------------------------------
    logic [NUM_SCPADS-1:0]                   fifo_wr_en;
    logic [NUM_SCPADS-1:0]                   fifo_shift;
    logic [NUM_SCPADS-1:0][VDST_WIDTH-1:0]   fifo_din;
    logic [NUM_SCPADS-1:0][VDST_WIDTH-1:0]   fifo_dout;
    logic [NUM_SCPADS-1:0]                   fifo_empty;
    logic [NUM_SCPADS-1:0]                   fifo_full;

    //----------------------------------------------------------------
    // Per-channel response FIFOs (stores rdata, pushed on sp_res valid)
    //----------------------------------------------------------------
    logic [NUM_SCPADS-1:0]                   resp_wr_en;
    logic [NUM_SCPADS-1:0]                   resp_shift;
    logic [NUM_SCPADS-1:0][RDATA_WIDTH-1:0]  resp_din;
    logic [NUM_SCPADS-1:0][RDATA_WIDTH-1:0]  resp_dout;
    logic [NUM_SCPADS-1:0]                   resp_empty;
    logic [NUM_SCPADS-1:0]                   resp_full;

    genvar gi;
    generate
        for (gi = 0; gi < NUM_SCPADS; gi++) begin : gen_queues
            sync_fifo #(
                .FIFODEPTH(FIFO_DEPTH),
                .DATAWIDTH(VDST_WIDTH)
            ) load_queue (
                .nRST, .CLK,
                .wr_en  (fifo_wr_en[gi]),
                .shift  (fifo_shift[gi]),
                .din    (fifo_din[gi]),
                .dout   (fifo_dout[gi]),
                .empty  (fifo_empty[gi]),
                .full   (fifo_full[gi])
            );

            sync_fifo #(
                .FIFODEPTH(FIFO_DEPTH),
                .DATAWIDTH(RDATA_WIDTH)
            ) resp_queue (
                .nRST, .CLK,
                .wr_en  (resp_wr_en[gi]),
                .shift  (resp_shift[gi]),
                .din    (resp_din[gi]),
                .dout   (resp_dout[gi]),
                .empty  (resp_empty[gi]),
                .full   (resp_full[gi])
            );
        end
    endgenerate

    // Round-robin priority for writeback arbitration
    logic [SP_IDX_WIDTH-1:0] rr_priority;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST)
            rr_priority <= '0;
        else if (wb_valid_out && wb_ready_in) begin
            if (rr_priority == SP_IDX_WIDTH'(NUM_SCPADS - 1))
                rr_priority <= '0;
            else
                rr_priority <= rr_priority + 1'b1;
        end
    end

    // Combinational signals
    logic [NUM_SCPADS-1:0] is_load;
    logic [NUM_SCPADS-1:0] is_store;
    logic [NUM_SCPADS-1:0] can_accept;
    logic [NUM_SCPADS-1:0] resp_pending;  // channel has both vdst and rdata ready

    logic                    found_pending;
    logic [SP_IDX_WIDTH-1:0] winner_idx;

    always_comb begin
        // FIFO control defaults
        fifo_wr_en = '0;
        fifo_shift = '0;
        fifo_din   = '0;
        resp_wr_en = '0;
        resp_shift = '0;
        resp_din   = '0;

        // Scratchpad request defaults
        for (int i = 0; i < NUM_SCPADS; i++) begin
            sp_req[i].valid      = 1'b0;
            sp_req[i].write      = 1'b0;
            sp_req[i].spad_addr  = '0;
            sp_req[i].num_rows   = '0;
            sp_req[i].num_cols   = '0;
            sp_req[i].row_id     = '0;
            sp_req[i].col_id     = '0;
            sp_req[i].row_or_col = 1'b0;
            sp_req[i].xbar       = '0;
            sp_req[i].wdata      = '0;
        end

        // Writeback defaults
        wb_load_data = '0;
        wb_vdst      = '0;
        wb_valid_out = 1'b0;

        is_load      = '0;
        is_store     = '0;
        can_accept   = '0;
        resp_pending = '0;
        found_pending = 1'b0;
        winner_idx    = '0;

        //--------------------------------------------------------------
        // Input: per-channel request handling
        //--------------------------------------------------------------
        for (int i = 0; i < NUM_SCPADS; i++) begin
            is_load[i]  = sched_valid_in[i] && !sched_write[i];
            is_store[i] = sched_valid_in[i] &&  sched_write[i];

            if (is_load[i])
                can_accept[i] = !fifo_full[i] && !sp_stall[i];
            else if (is_store[i])
                can_accept[i] = !sp_stall[i] && vrf_store_valid[i];
            else
                can_accept[i] = 1'b1;

            sched_ready_out[i] = can_accept[i];

            // Load: push vdst to load queue, send read to scratchpad
            if (is_load[i] && can_accept[i]) begin
                fifo_wr_en[i] = 1'b1;
                fifo_din[i]   = sched_vdst[i];

                sp_req[i].valid      = 1'b1;
                sp_req[i].write      = 1'b0;
                sp_req[i].spad_addr  = sched_addr[i];
                sp_req[i].num_rows   = sched_num_rows[i];
                sp_req[i].num_cols   = sched_num_cols[i];
                sp_req[i].row_id     = sched_row_id[i];
                sp_req[i].col_id     = sched_col_id[i];
                sp_req[i].row_or_col = sched_row_or_col[i];
            end

            // Store: send write with data to scratchpad
            if (is_store[i] && can_accept[i]) begin
                sp_req[i].valid      = 1'b1;
                sp_req[i].write      = 1'b1;
                sp_req[i].spad_addr  = sched_addr[i];
                sp_req[i].num_rows   = sched_num_rows[i];
                sp_req[i].num_cols   = sched_num_cols[i];
                sp_req[i].row_id     = sched_row_id[i];
                sp_req[i].col_id     = sched_col_id[i];
                sp_req[i].row_or_col = sched_row_or_col[i];
                sp_req[i].wdata      = vrf_store_data[i];
            end
        end

        //--------------------------------------------------------------
        // Response capture: push rdata to response queue
        //--------------------------------------------------------------
        for (int i = 0; i < NUM_SCPADS; i++) begin
            resp_wr_en[i] = sp_res[i].valid && !sp_res[i].write;
            resp_din[i]   = sp_res[i].rdata;
        end

        //--------------------------------------------------------------
        // Writeback arbitration: channel ready when both FIFOs non-empty
        //--------------------------------------------------------------
        for (int i = 0; i < NUM_SCPADS; i++)
            resp_pending[i] = !resp_empty[i] && !fifo_empty[i];

        // Round-robin starting from rr_priority
        for (int offset = 0; offset < NUM_SCPADS; offset++) begin
            int idx;
            idx = (int'(rr_priority) + offset) % NUM_SCPADS;
            if (resp_pending[idx] && !found_pending) begin
                found_pending = 1'b1;
                winner_idx    = SP_IDX_WIDTH'(idx);
            end
        end

        // Present writeback (valid independent of ready)
        if (found_pending) begin
            wb_load_data = resp_dout[winner_idx];
            wb_vdst      = fifo_dout[winner_idx];
            wb_valid_out = 1'b1;
            // Pop both FIFOs only on completed handshake
            if (wb_ready_in) begin
                fifo_shift[winner_idx] = 1'b1;
                resp_shift[winner_idx] = 1'b1;
            end
        end

        // Status
        vlsu_busy = |(~fifo_empty);
        for (int i = 0; i < NUM_SCPADS; i++)
            load_queue_full[i] = fifo_full[i];
    end

endmodule