// reggie.sv ==============================================================
// Banked vector register file with conflict-detection FSM
// ========================================================================

`define priority_encode(one_hot_vec, index_var)                          \
    for (int _pe_i = 0; _pe_i < $bits(one_hot_vec); _pe_i++) begin      \
        if (one_hot_vec[_pe_i]) begin                                    \
            index_var = _pe_i;                                           \
            break;                                                       \
        end                                                              \
    end

module reggie #(
    parameter BANK_COUNT   = 4,
    parameter BANK_REGS    = 64,
    parameter DREAD_PORTS  = 4,
    parameter DWRITE_PORTS = 4,
    parameter NUM_ELEMENTS = 32,
    parameter DATA_WIDTH   = 16,

    parameter BANK_IDX  = $clog2(BANK_COUNT),
    parameter ADDR_IDX  = $clog2(BANK_REGS),
    parameter VREG_W    = DATA_WIDTH * NUM_ELEMENTS,
    parameter VSEL_W    = BANK_IDX + ADDR_IDX
)(
    input  logic CLK, nRST,
    reg_file_if.reggie rif
);

    typedef enum logic [0:0] { READY_S = 1'b0, CONFLICT_S = 1'b1 } cstate_t;

    // -----------------------------------------------------------------------
    // Bank-number extraction
    // -----------------------------------------------------------------------
    logic [DREAD_PORTS-1:0] [BANK_IDX-1:0]  vs_bnum;
    logic [DWRITE_PORTS-1:0][BANK_IDX-1:0]  vd_bnum;

    generate
        genvar gi;
        for (gi = 0; gi < DREAD_PORTS;  gi++)
            assign vs_bnum[gi] = rif.vs[gi][BANK_IDX-1:0];
        for (gi = 0; gi < DWRITE_PORTS; gi++)
            assign vd_bnum[gi] = rif.vd[gi][BANK_IDX-1:0];
    endgenerate

    // -----------------------------------------------------------------------
    // Per-bank request / pending vectors
    // -----------------------------------------------------------------------
    logic [DREAD_PORTS-1:0]  bank_rreqs    [BANK_COUNT-1:0];
    logic [DWRITE_PORTS-1:0] bank_wreqs    [BANK_COUNT-1:0];
    logic [DREAD_PORTS-1:0]  bank_rpend    [BANK_COUNT-1:0];
    logic [DWRITE_PORTS-1:0] bank_wpend    [BANK_COUNT-1:0];
    logic [DREAD_PORTS-1:0]  bank_rpend_nxt[BANK_COUNT-1:0];
    logic [DWRITE_PORTS-1:0] bank_wpend_nxt[BANK_COUNT-1:0];

    // -----------------------------------------------------------------------
    // Bank drive signals
    // -----------------------------------------------------------------------
    logic                    bank_ren  [BANK_COUNT-1:0];
    logic                    bank_wen  [BANK_COUNT-1:0];
    logic [ADDR_IDX-1:0]     bank_raddr[BANK_COUNT-1:0];
    logic [ADDR_IDX-1:0]     bank_waddr[BANK_COUNT-1:0];
    logic [VREG_W-1:0]       bank_wdata[BANK_COUNT-1:0];
    logic [VREG_W-1:0]       bank_rdata[BANK_COUNT-1:0];
    logic [DREAD_PORTS-1:0]  bank_rtag [BANK_COUNT-1:0];

    // -----------------------------------------------------------------------
    // FSM signals
    // -----------------------------------------------------------------------
    cstate_t state, state_nxt;
    logic    conflict, d_conflict, nxt_conflict;

    // -----------------------------------------------------------------------
    // Conflict detection + arbitration
    // -----------------------------------------------------------------------

    logic dependencies_ready;
    logic [DREAD_PORTS-1:0] REN;

    assign REN = (rif.REN | rif.dependencies_ready);

    always_comb begin : CONFLICT_FSM

        for (int b = 0; b < BANK_COUNT; b++) begin
            bank_rreqs[b] = '0;
            bank_wreqs[b] = '0;
        end
        for (int i = 0; i < DREAD_PORTS;  i++) if (REN[i]) bank_rreqs[vs_bnum[i]][i] = 1'b1;
        for (int i = 0; i < DWRITE_PORTS; i++) if (rif.WEN[i]) bank_wreqs[vd_bnum[i]][i] = 1'b1;

        d_conflict = 1'b0;
        for (int b = 0; b < BANK_COUNT; b++) begin
            if (($countones(bank_rreqs[b]) > 1) || ($countones(bank_wreqs[b]) > 1))
                d_conflict = 1'b1;
        end
        conflict = d_conflict;

        bank_rpend_nxt = bank_rpend;
        bank_wpend_nxt = bank_wpend;
        nxt_conflict   = 1'b0;

        unique case (state)
            READY_S: begin
                bank_rpend_nxt   = bank_rreqs;
                bank_wpend_nxt   = bank_wreqs;
                rif.reggie_ready = 1'b1;
                state_nxt        = conflict ? CONFLICT_S : READY_S;
            end

            CONFLICT_S: begin
                bank_rreqs = bank_rpend;
                bank_wreqs = bank_wpend;

                rif.reggie_ready = 1'b0;

                for (int b = 0; b < BANK_COUNT; b++) begin
                    if (($countones(bank_rpend_nxt[b]) > 1) ||
                        ($countones(bank_wpend_nxt[b]) > 1))
                        nxt_conflict = 1'b1;
                end
                state_nxt = nxt_conflict ? CONFLICT_S : READY_S;
            end

            default: begin
                rif.reggie_ready = 1'b0;
                state_nxt        = READY_S;
            end
        endcase

        for (int b = 0; b < BANK_COUNT; b++) begin
            bank_ren  [b] = 1'b0;
            bank_wen  [b] = 1'b0;
            bank_raddr[b] = '0;
            bank_waddr[b] = '0;
            bank_wdata[b] = '0;
            bank_rtag [b] = '0;
        end

        for (int b = 0; b < BANK_COUNT; b++) begin

            if (|(bank_rreqs[b])) begin
                logic [DREAD_PORTS-1:0] rwin;
                int                     rwin_idx;
                rwin     = bank_rreqs[b] & (-bank_rreqs[b]);
                rwin_idx = 0;
                `priority_encode(rwin, rwin_idx)

                bank_ren  [b] = REN[rwin_idx];
                bank_raddr[b] = rif.vs[rwin_idx][BANK_IDX +: ADDR_IDX];
                bank_rtag [b] = rwin;

                bank_rpend_nxt[b] &= ~rwin;
            end

            if (|(bank_wreqs[b])) begin
                logic [DWRITE_PORTS-1:0] wwin;
                int                      wwin_idx;
                wwin     = bank_wreqs[b] & (-bank_wreqs[b]);
                wwin_idx = 0;
                `priority_encode(wwin, wwin_idx)

                bank_wen  [b] = rif.WEN[wwin_idx];
                bank_waddr[b] = rif.vd[wwin_idx][BANK_IDX +: ADDR_IDX];
                bank_wdata[b] = rif.vdata[wwin_idx];

                bank_wpend_nxt[b] &= ~wwin;
            end
        end
    end

    // -----------------------------------------------------------------------
    // State + pending registers
    // -----------------------------------------------------------------------
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            state      <= READY_S;
            bank_rpend <= bank_rreqs;
            bank_wpend <= bank_wreqs;
        end else begin
            state      <= state_nxt;
            bank_rpend <= bank_rpend_nxt;
            bank_wpend <= bank_wpend_nxt;
        end
    end

    // -----------------------------------------------------------------------
    // Bank instantiation
    // -----------------------------------------------------------------------
    generate
        genvar i_db;
        for (i_db = 0; i_db < BANK_COUNT; i_db++) begin : DATA_BANK_GEN
            bank #(
                .NUM_ELEMENTS(NUM_ELEMENTS),
                .DATA_WIDTH  (DATA_WIDTH),
                .NUM_ROWS    (BANK_REGS),
                .ADDR_WIDTH  (ADDR_IDX)
            ) u_bank (
                .clk  (CLK),
                .nRST (nRST),
                .ren  (bank_ren  [i_db]),
                .raddr(bank_raddr[i_db]),
                .rdata(bank_rdata[i_db]),
                .wen  (bank_wen  [i_db]),
                .waddr(bank_waddr[i_db]),
                .wdata(bank_wdata[i_db]),
                .wstrb('1)
            );
        end
    endgenerate

    // -----------------------------------------------------------------------
    // Output mux
    // -----------------------------------------------------------------------
    always_comb begin : OUTPUTS
        rif.reggie_vreg   = '{default:'0};
        rif.reggie_dvalid = '0;

        for (int b = 0; b < BANK_COUNT; b++) begin
            if (bank_ren[b]) begin
                for (int p = 0; p < DREAD_PORTS; p++) begin
                    if (bank_rtag[b][p]) begin
                        rif.reggie_vreg  [p] = bank_rdata[b];
                        rif.reggie_dvalid[p] = 1'b1;
                    end
                end
            end
        end
    end

endmodule