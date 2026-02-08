// ------------------------------------------------------------
// lane.sv
// Lane wrapper: lane_sequencer + sqrt_bf16 + div + metadata sync FIFO
// ------------------------------------------------------------
`include "vector_if.vh"
//`include "vector_pkg.vh"
`include "div_if.vh"
`include "mul_if.vh"
`include "sqrt_if.sv"

module lane #(
    parameter int LANE_ID = 0   // unique per lane instance
) (
    input  logic        CLK,
    input  logic        nRST,
    vector_if.lane      lif
);
    import vector_pkg::*;

    // Common constants for last-element detection
    localparam int SLICE_W       = $bits(slice_idx_t);
    localparam int ELEM_PER_LANE = 1 << SLICE_W;
    localparam int LAST_LANE     = NUM_LANES-1;
    localparam int LAST_ELEM     = ELEM_PER_LANE-1;

    // ============================================================
    // SQRT PIPELINE
    // ============================================================

    // ------------------------------------------------------------
    // SQRT: Internal Signals & Structs
    // ------------------------------------------------------------
    lane_seq_in_t  sqrt_seq_in;
    lane_seq_out_t sqrt_seq_out;

    meta_t sqrt_meta_in;
    meta_t sqrt_meta_out;
    logic  sqrt_sync_ready;

    // SQRT FU interface
    sqrt_if sqrt_bus();

    // Sequencer -> FU fire condition (element active)
    logic sqrt_fire_valid;
    assign sqrt_fire_valid = sqrt_seq_out.valid && sqrt_seq_out.mask_bit && sqrt_sync_ready;

    // SQRT hold buffer (single-entry, matching DIV pattern)
    logic       sqrt_hold_valid;
    bf16_t      sqrt_hold_result;
    vsel_t      sqrt_hold_vd;
    slice_idx_t sqrt_hold_elem;
    logic       sqrt_hold_last;

    // ------------------------------------------------------------
    // SQRT: Sequencer Setup
    // ------------------------------------------------------------
    always_comb begin
        sqrt_seq_in = '0;

        // Map Inputs from lane interface for SQRT FU
        sqrt_seq_in.v1    = lif.lane_in.v1[SQRT];
        sqrt_seq_in.v2    = lif.lane_in.v2[SQRT];
        sqrt_seq_in.vmask = lif.lane_in.vmask[SQRT];
        sqrt_seq_in.vd    = lif.lane_in.vd[SQRT];
        sqrt_seq_in.vop   = lif.lane_in.vop[SQRT];
        sqrt_seq_in.rm    = lif.lane_in.rm[SQRT];
        sqrt_seq_in.valid = lif.lane_in.valid_in[SQRT];

        // READY Logic:
        // - Unmasked element: must wait for sync_ready (FIFO space)
        // - Masked element: always advance
        if (sqrt_seq_out.mask_bit) begin
            sqrt_seq_in.ready = sqrt_sync_ready;
        end else begin
            sqrt_seq_in.ready = 1'b1;
        end
    end

    lane_sequencer u_seq_sqrt (
        .CLK     (CLK),
        .nRST    (nRST),
        .lane_in (sqrt_seq_in),
        .lane_out(sqrt_seq_out)
    );

    // ------------------------------------------------------------
    // SQRT: Functional Unit
    // ------------------------------------------------------------
    sqrt_bf16 u_sqrt_bf16 (
        .CLK (CLK),
        .nRST(nRST),
        .srif(sqrt_bus)
    );

    // Drive FU input side
    always_comb begin
        // Operand for FU
        sqrt_bus.in.operand  = sqrt_seq_out.v1_elem;

        // FU input valid: active element and metadata FIFO has space.
        sqrt_bus.in.valid_in = sqrt_fire_valid && sqrt_sync_ready;

        // Writeback-side ready: backpressure when hold buffer is full
        sqrt_bus.in.ready_out = (!sqrt_hold_valid || lif.lane_in.ready_in[SQRT]);
    end

    // ------------------------------------------------------------
    // SQRT: Retire signal
    // ------------------------------------------------------------
    logic sqrt_retire;
    assign sqrt_retire = sqrt_bus.out.valid_out && sqrt_bus.in.ready_out;

    // ------------------------------------------------------------
    // SQRT: Metadata Sync Unit (lane_fu_pt)
    // ------------------------------------------------------------
    // SQRT metadata
    assign sqrt_meta_in.vd       = sqrt_seq_out.vd;
    assign sqrt_meta_in.elem_idx = sqrt_seq_out.elem_idx;
    // Last element when this lane is the last lane and this slice is the last
    assign sqrt_meta_in.last     =
        (LANE_ID == LAST_LANE) &&
        (sqrt_seq_out.elem_idx == LAST_ELEM);
    assign sqrt_meta_in.dbg_seq  = '0;  // No debug for SQRT

    lane_fu_pt #(
        .DATA_W ($bits(meta_t)),
        .LATENCY(8)  // Match SQRT pipeline latency
    ) u_sqrt_sync (
        .CLK        (CLK),
        .nRST       (nRST),

        // Input Side (Issue)
        .issue_valid(sqrt_fire_valid),
        .fu_ready   (sqrt_bus.out.ready_in),
        .meta_in    (sqrt_meta_in),
        .sync_ready (sqrt_sync_ready),

        // Output Side (Writeback)
        // Pop FIFO on retire event
        .wb_valid   (sqrt_retire),
        .wb_ready   (sqrt_bus.in.ready_out),
        .meta_out   (sqrt_meta_out)
    );

    // ------------------------------------------------------------
    // SQRT: Hold Buffer & Writeback Logic
    // ------------------------------------------------------------
    // Capture on retire event (matching DIV pattern)
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            sqrt_hold_valid  <= 1'b0;
            sqrt_hold_result <= '0;
            sqrt_hold_vd     <= '0;
            sqrt_hold_elem   <= '0;
            sqrt_hold_last  <= 1'b0; 
        end else begin
            // Capture when FU result is retired
            if (sqrt_retire) begin
                sqrt_hold_valid  <= 1'b1;
                sqrt_hold_result <= sqrt_bus.out.result;
                sqrt_hold_vd     <= sqrt_meta_out.vd;
                sqrt_hold_elem   <= sqrt_meta_out.elem_idx;
                sqrt_hold_last   <= sqrt_meta_out.last;  
            end
            // Clear when downstream consumes
            else if (sqrt_hold_valid && lif.lane_in.ready_in[SQRT]) begin
                sqrt_hold_valid <= 1'b0;
                sqrt_hold_last  <= 1'b0; 
            end
        end
    end

    // ============================================================
    // DIV PIPELINE
    // ============================================================

    // ------------------------------------------------------------
    // DIV: Internal Signals & Structs
    // ------------------------------------------------------------
    lane_seq_in_t  div_seq_in;
    lane_seq_out_t div_seq_out;

    meta_t div_meta_in;
    meta_t div_meta_out;
    logic  div_sync_ready;

    // DIV FU interface
    div_if #(
        .EXP_WIDTH(5),
        .MANT_WIDTH(10)
    ) div_bus();

    // DIV fire condition
    logic div_fire_valid;
    assign div_fire_valid = div_seq_out.valid && div_seq_out.mask_bit && div_sync_ready;

    // DIV hold buffer signals (declared early for use in FU backpressure)
    logic       div_hold_valid;
    bf16_t      div_hold_result;
    vsel_t      div_hold_vd;
    slice_idx_t div_hold_elem;
    logic [7:0] div_hold_dbg_seq;
    logic       div_hold_last;

    // ------------------------------------------------------------
    // DIV: Sequencer Setup
    // ------------------------------------------------------------
    always_comb begin
        div_seq_in = '0;

        // Map Inputs from lane interface for DIV FU
        div_seq_in.v1    = lif.lane_in.v1[DIV];
        div_seq_in.v2    = lif.lane_in.v2[DIV];
        div_seq_in.vmask = lif.lane_in.vmask[DIV];
        div_seq_in.vd    = lif.lane_in.vd[DIV];
        div_seq_in.vop   = lif.lane_in.vop[DIV];
        div_seq_in.rm    = lif.lane_in.rm[DIV];
        div_seq_in.valid = lif.lane_in.valid_in[DIV];

        // READY Logic:
        // - Unmasked element: must wait for div_sync_ready (FIFO space)
        // - Masked element: always advance
        if (div_seq_out.mask_bit) begin
            div_seq_in.ready = div_sync_ready;
        end else begin
            div_seq_in.ready = 1'b1;
        end
    end

    lane_sequencer u_seq_div (
        .CLK     (CLK),
        .nRST    (nRST),
        .lane_in (div_seq_in),
        .lane_out(div_seq_out)
    );

    // ------------------------------------------------------------
    // DIV: Functional Unit
    // ------------------------------------------------------------
    div u_div (
        .CLK  (CLK),
        .nRST (nRST),
        .divif(div_bus)
    );

    // Drive DIV FU input side
    always_comb begin
        // Operands for FU (operand1 / operand2)
        div_bus.in.operand1  = div_seq_out.v1_elem;
        div_bus.in.operand2  = div_seq_out.v2_elem;

        // FU input valid: active element and metadata FIFO has space
        div_bus.in.valid_in  = div_fire_valid && div_sync_ready;

        // Writeback-side ready: backpressure to FU when hold buffer is full
        div_bus.in.ready_out = (!div_hold_valid || lif.lane_in.ready_in[DIV]);
    end

    // ------------------------------------------------------------
    // DIV: Retire Signal - No WB Stage Needed
    // ------------------------------------------------------------
    // Retire event: FU result accepted by WB path (valid && ready handshake)
    logic div_retire;
    assign div_retire = div_bus.out.valid_out && div_bus.in.ready_out;

    // ------------------------------------------------------------
    // DIV: Metadata Sync Unit (lane_fu_pt)
    // ------------------------------------------------------------
    // Debug sequence counter for DIV
    logic [7:0] div_dbg_seq_cnt;
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            div_dbg_seq_cnt <= '0;
        end else if (div_fire_valid && div_sync_ready) begin
            div_dbg_seq_cnt <= div_dbg_seq_cnt + 1'b1;
        end
    end

    assign div_meta_in.vd       = div_seq_out.vd;
    assign div_meta_in.elem_idx = div_seq_out.elem_idx;
    assign div_meta_in.last     =
        (LANE_ID == LAST_LANE) &&
        (div_seq_out.elem_idx == LAST_ELEM);
    assign div_meta_in.dbg_seq  = div_dbg_seq_cnt;

    lane_fu_pt #(
        .DATA_W ($bits(meta_t)),
        .LATENCY(11)  // Sizing for DIV latency
    ) u_div_sync (
        .CLK        (CLK),
        .nRST       (nRST),

        // Input Side (Issue)
        .issue_valid(div_fire_valid),
        .fu_ready   (div_bus.out.ready_in),
        .meta_in    (div_meta_in),
        .sync_ready (div_sync_ready),

        // Output Side (Writeback)
        // Pop FIFO on retire event (same cycle as FU output acceptance)
        .wb_valid   (div_retire),                 // Use retire directly
        .wb_ready   (div_bus.in.ready_out),       // FU backpressure
        .meta_out   (div_meta_out)
    );

    // ------------------------------------------------------------
    // DIV: Hold Buffer & Writeback Logic
    // ------------------------------------------------------------
    // Capture directly on retire event (same cycle as FU output + metadata pop)
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            div_hold_valid   <= 1'b0;
            div_hold_result  <= '0;
            div_hold_vd      <= '0;
            div_hold_elem    <= '0;
            div_hold_dbg_seq <= '0;
            div_hold_last  <= 1'b0; 
        end else begin
            // Capture new FU result + metadata when retire happens
            if (div_retire) begin
                div_hold_valid   <= 1'b1;
                div_hold_result  <= div_bus.out.result;       // Direct from FU
                div_hold_vd      <= div_meta_out.vd;           // FIFO output
                div_hold_elem    <= div_meta_out.elem_idx;
                div_hold_dbg_seq <= div_meta_out.dbg_seq;
                div_hold_last    <= div_meta_out.last; 
            end
            // Once WB accepts it (and no new result arriving), drop valid
            else if (div_hold_valid && lif.lane_in.ready_in[DIV]) begin
                div_hold_valid <= 1'b0;
                div_hold_last  <= 1'b0; 
            end
        end
    end

    // ============================================================
    // MUL PIPELINE
    // ============================================================

    lane_seq_in_t  mul_seq_in;
    lane_seq_out_t mul_seq_out;

    meta_t mul_meta_in;
    meta_t mul_meta_out;
    logic  mul_sync_ready;

    mul_if mul_bus();

    logic mul_fire_valid;
    assign mul_fire_valid = mul_seq_out.valid && mul_seq_out.mask_bit && mul_sync_ready;

    logic       mul_hold_valid;
    logic [15:0] mul_hold_result;
    vsel_t      mul_hold_vd;
    slice_idx_t mul_hold_elem;
    logic        mul_hold_last;  

    // Sequencer setup
    always_comb begin
        mul_seq_in = '0;

        mul_seq_in.v1    = lif.lane_in.v1[MUL];
        mul_seq_in.v2    = lif.lane_in.v2[MUL];
        mul_seq_in.vmask = lif.lane_in.vmask[MUL];
        mul_seq_in.vd    = lif.lane_in.vd[MUL];
        mul_seq_in.vop   = lif.lane_in.vop[MUL];
        mul_seq_in.rm    = lif.lane_in.rm[MUL];
        mul_seq_in.valid = lif.lane_in.valid_in[MUL];

        if (mul_seq_out.mask_bit)
            mul_seq_in.ready = mul_sync_ready;
        else
            mul_seq_in.ready = 1'b1;
    end

    lane_sequencer u_seq_mul (
        .CLK     (CLK),
        .nRST    (nRST),
        .lane_in (mul_seq_in),
        .lane_out(mul_seq_out)
    );

    // MUL FU wrapper
    mul_bf16_fu u_mul (
        .CLK (CLK),
        .nRST(nRST),
        .m_if(mul_bus)
    );

    // Drive MUL input side
    always_comb begin
        mul_bus.in.operand1  = mul_seq_out.v1_elem;
        mul_bus.in.operand2  = mul_seq_out.v2_elem;
        mul_bus.in.valid_in  = mul_fire_valid && mul_sync_ready;
        mul_bus.in.ready_out = (!mul_hold_valid || lif.lane_in.ready_in[MUL]);
    end

    // ------------------------------------------------------------
    // MUL: Retire Signal - No WB Stage Needed
    // ------------------------------------------------------------
    // Retire event: FU result accepted by WB path (valid && ready handshake)
    logic mul_retire;
    assign mul_retire = mul_bus.out.valid_out && mul_bus.in.ready_out;

    // ------------------------------------------------------------
    // MUL: Metadata Sync (lane_fu_pt)
    // ------------------------------------------------------------
    assign mul_meta_in.vd       = mul_seq_out.vd;
    assign mul_meta_in.elem_idx = mul_seq_out.elem_idx;
    assign mul_meta_in.last     =
        (LANE_ID == LAST_LANE) &&
        (mul_seq_out.elem_idx == LAST_ELEM);
    assign mul_meta_in.dbg_seq  = '0; // or add a dbg counter like DIV

    lane_fu_pt #(
        .DATA_W ($bits(meta_t)),
        .LATENCY(2)  // MUL wrapper: 1 cycle for core + 1 for alignment = 2 total
    ) u_mul_sync (
        .CLK        (CLK),
        .nRST       (nRST),
        .issue_valid(mul_fire_valid),
        .fu_ready   (mul_bus.out.ready_in),  // FU signals when ready for input
        .meta_in    (mul_meta_in),
        .sync_ready (mul_sync_ready),
        // Use retire signal to ensure metadata pops in sync with hold buffer capture
        .wb_valid   (mul_retire),
        .wb_ready   (mul_bus.in.ready_out),
        .meta_out   (mul_meta_out)
    );

    // ------------------------------------------------------------
    // MUL: Hold Buffer & Writeback Logic
    // ------------------------------------------------------------
    // Capture directly on retire event (same cycle as FU output + metadata pop)
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            mul_hold_valid  <= 1'b0;
            mul_hold_result <= '0;
            mul_hold_vd     <= '0;
            mul_hold_elem   <= '0;
            mul_hold_last   <= 1'b0; 
        end else begin
            // Capture new FU result + metadata when retire happens
            if (mul_retire) begin
                mul_hold_valid  <= 1'b1;
                mul_hold_result <= mul_bus.out.result;        // Direct from FU
                mul_hold_vd     <= mul_meta_out.vd;            // FIFO output
                mul_hold_elem   <= mul_meta_out.elem_idx;
                mul_hold_last   <= mul_meta_out.last; 
            end
            // Once WB accepts it (and no new result arriving), drop valid
            else if (mul_hold_valid && lif.lane_in.ready_in[MUL]) begin
                mul_hold_valid <= 1'b0;
                mul_hold_last  <= 1'b0;    
            end
        end
    end

    // ------------------------------------------------------------
    // MUL: Debug Counters (always enabled for debugging)
    // ------------------------------------------------------------
    int mul_issue_cnt, mul_wb_cnt;
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            mul_issue_cnt <= 0;
            mul_wb_cnt    <= 0;
        end else begin
            if (mul_fire_valid && mul_sync_ready) mul_issue_cnt <= mul_issue_cnt + 1;
            if (lif.lane_out.valid_o[MUL] && lif.lane_in.ready_in[MUL]) mul_wb_cnt <= mul_wb_cnt + 1;
        end
    end
    
    // Print counts at end of simulation
    final begin
        $display("[%m] MUL_COUNTS: issue=%0d wb=%0d", mul_issue_cnt, mul_wb_cnt);
    end

    // ============================================================
    // VALU PIPELINE (V-ALU: add/sub/min/max bf16) with reduction (rm)
    // ============================================================

    // ------------------------------------------------------------
    // VALU: Internal Signals & Structs
    // ------------------------------------------------------------
    lane_seq_in_t  valu_seq_in;
    lane_seq_out_t valu_seq_out;

    meta_t valu_meta_in;
    meta_t valu_meta_out;
    logic  valu_sync_ready;

    // VALU FU interface (bf16: 1+8+7 = 16 bits)
    valu_if #(
        .EXP_WIDTH (8),
        .MANT_WIDTH(7)
    ) valu_bus();

    // ------------------------------------------------------------
    // VALU hold buffer signals (normal vector path)
    // ------------------------------------------------------------
    logic       valu_hold_valid;
    bf16_t      valu_hold_result;
    vsel_t      valu_hold_vd;
    slice_idx_t valu_hold_elem;
    logic       valu_hold_last;

    // Reduction fire pulse (one per *full vector* per lane)
    logic valu_reduce_fire;

    // Issue / fire conditions
    logic valu_issue_valid;
    logic valu_fire_valid;

    // Element is "issued" whenever sequencer presents a valid, masked element
    assign valu_issue_valid = valu_seq_out.valid && valu_seq_out.mask_bit;

    // Element actually "fires" into FU only when:
    //  - sequencer has a valid, masked element
    //  - metadata FIFO has space (valu_sync_ready)
    //  - FU input is ready (valu_bus.out.ready_in)
    assign valu_fire_valid  = valu_issue_valid &&
                              valu_sync_ready  &&
                              valu_bus.out.ready_in;

    // ------------------------------------------------------------
    // VALU: Sequencer Setup
    // ------------------------------------------------------------
    always_comb begin
        valu_seq_in = '0;

        // Map inputs from lane interface for VALU FU
        valu_seq_in.v1    = lif.lane_in.v1[VALU];
        valu_seq_in.v2    = lif.lane_in.v2[VALU];
        valu_seq_in.vmask = lif.lane_in.vmask[VALU];
        valu_seq_in.vd    = lif.lane_in.vd[VALU];
        valu_seq_in.vop   = lif.lane_in.vop[VALU];   // encodes SUM/SUB/MIN/MAX
        valu_seq_in.rm    = lif.lane_in.rm[VALU];    // reduction mode bit
        valu_seq_in.valid = lif.lane_in.valid_in[VALU];

        // READY back to the lane front-end:
        //  - For active (unmasked) elements, we must honor both
        //    metadata FIFO space and FU input readiness.
        //  - For fully masked elements, we just consume them.
        if (valu_seq_out.mask_bit) begin
            valu_seq_in.ready = valu_sync_ready && valu_bus.out.ready_in;
        end else begin
            valu_seq_in.ready = 1'b1;
        end
    end

    lane_sequencer u_seq_valu (
        .CLK     (CLK),
        .nRST    (nRST),
        .lane_in (valu_seq_in),
        .lane_out(valu_seq_out)
    );

    // ------------------------------------------------------------
    // VALU: Functional Unit
    // ------------------------------------------------------------
    valu u_valu (
        .CLK (CLK),
        .nRST(nRST),
        .alu (valu_bus)
    );

    // Drive VALU FU input side
    always_comb begin
        // Operands for FU come from sequencer element outputs
        valu_bus.in.operand1 = valu_seq_out.v1_elem;
        valu_bus.in.operand2 = valu_seq_out.v2_elem;

        // ALU op (SUM/SUB/MIN/MAX), taken from vop field
        valu_bus.in.alu_op   = valu_seq_out.vop[1:0];

        // FU input valid: when we actually "fire"
        valu_bus.in.valid_in = valu_fire_valid;

        // Writeback-side ready: backpressure when hold buffer is full
        // (only claim ready if we can eventually expose result downstream)
        valu_bus.in.ready_out = (!valu_hold_valid || lif.lane_in.ready_in[VALU]);
    end

    // ------------------------------------------------------------
    // VALU: Retire Signal
    // ------------------------------------------------------------
    // Result retires when FU has a valid result and downstream accepts it
    logic valu_retire;
    assign valu_retire = valu_bus.out.valid_out && valu_bus.in.ready_out;

    // ------------------------------------------------------------
    // VALU: Metadata Sync Unit (lane_fu_pt)
    // ------------------------------------------------------------
    assign valu_meta_in.vd       = valu_seq_out.vd;
    assign valu_meta_in.elem_idx = valu_seq_out.elem_idx;
    assign valu_meta_in.last     =
        (LANE_ID == LAST_LANE) &&
        (valu_seq_out.elem_idx == LAST_ELEM);
    assign valu_meta_in.dbg_seq  = '0;                      // no dbg counter for VALU
    assign valu_meta_in.rm       = valu_seq_out.rm;         // carry rm as metadata

    lane_fu_pt #(
        .DATA_W ($bits(meta_t)),
        .LATENCY(4) // VALU completion latency (for FIFO sizing only)
    ) u_valu_sync (
        .CLK        (CLK),
        .nRST       (nRST),

        // Input Side (Issue)
        .issue_valid(valu_issue_valid),       // sequencer presenting an active elem
        .fu_ready   (valu_bus.out.ready_in),  // FU actually accepted the elem
        .meta_in    (valu_meta_in),
        .sync_ready (valu_sync_ready),

        // Output Side (Writeback)
        .wb_valid   (valu_retire),            // result retires
        .wb_ready   (valu_bus.in.ready_out),  // WB backpressure to FIFO
        .meta_out   (valu_meta_out)
    );

    // ------------------------------------------------------------
    // VALU: Reduction fire pulse (rm mode)
    // ------------------------------------------------------------
    // When rm=1 and this is the *last* element of the full vector,
    // treat this retire as the reduction scalar for the whole vector.
    assign valu_reduce_fire =
        valu_retire && valu_meta_out.rm && valu_meta_out.last;

    // ------------------------------------------------------------
    // VALU: Hold Buffer (normal vector path, rm=0 only)
    // ------------------------------------------------------------
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            valu_hold_valid  <= 1'b0;
            valu_hold_result <= '0;
            valu_hold_vd     <= '0;
            valu_hold_elem   <= '0;
            valu_hold_last   <= 1'b0;
        end else begin
            // Capture new FU result + metadata when retire happens,
            // but ONLY for non-reduction (rm=0) ops.
            if (valu_retire && !valu_meta_out.rm) begin
                valu_hold_valid  <= 1'b1;
                valu_hold_result <= valu_bus.out.result;
                valu_hold_vd     <= valu_meta_out.vd;
                valu_hold_elem   <= valu_meta_out.elem_idx;
                valu_hold_last   <= valu_meta_out.last;
            end
            // Once WB accepts it (and no new result arriving), drop valid
            else if (valu_hold_valid && lif.lane_in.ready_in[VALU]) begin
                valu_hold_valid <= 1'b0;
                valu_hold_last  <= 1'b0;
            end
        end
    end

    // ============================================================
    // Lane Output Bus (Combined SQRT + DIV)
    // ============================================================
    always_comb begin
        lif.lane_out = '0;

        // SQRT outputs - from hold buffer
        lif.lane_out.ready_o[SQRT]  = sqrt_seq_out.lane_ready;
        lif.lane_out.valid_o[SQRT]  = sqrt_hold_valid;
        lif.lane_out.result[SQRT]   = sqrt_hold_result;
        lif.lane_out.vd[SQRT]       = sqrt_hold_vd;
        lif.lane_out.elem_idx[SQRT] = sqrt_hold_elem;
        lif.lane_out.last[SQRT]     = sqrt_hold_last;

        // DIV outputs
        lif.lane_out.ready_o[DIV] = div_seq_out.lane_ready;
        lif.lane_out.valid_o[DIV]  = div_hold_valid;
        lif.lane_out.result[DIV]   = div_hold_result;
        lif.lane_out.vd[DIV]       = div_hold_vd;
        lif.lane_out.elem_idx[DIV] = div_hold_elem;
        lif.lane_out.last[DIV]     = div_hold_last;

        // MUL outputs
        lif.lane_out.ready_o[MUL]  = mul_seq_out.lane_ready;
        lif.lane_out.valid_o[MUL]  = mul_hold_valid;
        lif.lane_out.result[MUL]   = mul_hold_result;
        lif.lane_out.vd[MUL]       = mul_hold_vd;
        lif.lane_out.elem_idx[MUL] = mul_hold_elem;
        lif.lane_out.last[MUL]     = mul_hold_last;

        // VALU outputs
        // Normal vector VALU path (rm = 0)
        lif.lane_out.ready_o[VALU]  = valu_seq_out.lane_ready;
        lif.lane_out.valid_o[VALU]  = valu_hold_valid;   // only set for rm=0
        lif.lane_out.result [VALU]  = valu_hold_result;
        lif.lane_out.vd     [VALU]  = valu_hold_vd;
        lif.lane_out.elem_idx[VALU] = valu_hold_elem;
        lif.lane_out.last   [VALU]  = valu_hold_last;

        // Reduction scalar (rm = 1, last element): bypass hold buffer
        lif.lane_out.rval[VALU]     = valu_reduce_fire ? valu_bus.out.result : '0;

    end

    // ============================================================
    // Performance Counters
    // ============================================================

    /*
    perf_fu u_perf_fu_valu (
        .CLK(CLK),
        .nRST(nRST),
        .seq_busy(!valu_seq_out.lane_ready),
        .issue_valid(valu_seq_out.valid),
        .fire_valid(valu_fire_valid),
        .sync_ready(valu_sync_ready),
        .hold_valid(valu_hold_valid),
        .wb_ready(lif.lane_in.ready_in[VALU])
    );

    /* TODO: enable once exp is added
    perf_fu u_perf_fu_exp (
        .CLK(CLK),
        .nRST(nRST),
        .seq_busy(!exp_seq_out.lane_ready),
        .issue_valid(exp_seq_out.valid),
        .fire_valid(exp_fire_valid),
        .sync_ready(exp_sync_ready),
        .hold_valid(exp_hold_valid),
        .wb_ready(lif.lane_in.ready_in[EXP])
    );
    */

    /*
    perf_fu u_perf_fu_sqrt (
        .CLK(CLK),
        .nRST(nRST),
        .seq_busy(!sqrt_seq_out.lane_ready),
        .issue_valid(sqrt_seq_out.valid),
        .fire_valid(sqrt_fire_valid),
        .sync_ready(sqrt_sync_ready),
        .hold_valid(sqrt_hold_valid),
        .wb_ready(lif.lane_in.ready_in[SQRT])
    );
    */

    /*
    perf_fu u_perf_fu_mul (
        .CLK(CLK),
        .nRST(nRST),
        .seq_busy(!mul_seq_out.lane_ready),
        .issue_valid(mul_seq_out.valid),
        .fire_valid(mul_fire_valid),
        .sync_ready(mul_sync_ready),
        .hold_valid(mul_hold_valid),
        .wb_ready(lif.lane_in.ready_in[MUL])
    );
    */

    /*
    perf_fu u_perf_fu_div (
        .CLK(CLK),
        .nRST(nRST),
        .seq_busy(!div_seq_out.lane_ready),
        .issue_valid(div_seq_out.valid),
        .fire_valid(div_fire_valid),
        .sync_ready(div_sync_ready),
        .hold_valid(div_hold_valid),
        .wb_ready(lif.lane_in.ready_in[DIV])
    );
    */


    logic is_mask_skip;
    assign is_mask_skip =
        (valu_seq_out.valid && !valu_seq_out.mask_bit)  ||
        // (exp_seq_out.valid  && !exp_seq_out.mask_bit)   ||
        (sqrt_seq_out.valid && !sqrt_seq_out.mask_bit)  ||
        (mul_seq_out.valid  && !mul_seq_out.mask_bit)   ||
        (div_seq_out.valid  && !div_seq_out.mask_bit);


    // perf_counter u_perf_cnt_mask_skip (
    //     .CLK(CLK),
    //     .nRST(nRST),
    //     .enable(is_mask_skip)
    // );


endmodule
