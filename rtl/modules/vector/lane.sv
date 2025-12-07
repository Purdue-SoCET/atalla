// ------------------------------------------------------------
// lane.sv
// Lane wrapper: lane_sequencer + sqrt_bf16 + div + metadata sync FIFO
// ------------------------------------------------------------
`include "vector_if.vh"
`include "vector_types.vh"
`include "div_if.vh"

module lane (
    input  logic        CLK,
    input  logic        nRST,
    vector_if.lane      lif
);
    import vector_pkg::*;

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

    // SQRT hold buffer signals (declared early for use in FU backpressure)
    logic       sqrt_hold_valid;
    fp16_t      sqrt_hold_result;
    vsel_t      sqrt_hold_vd;
    slice_idx_t sqrt_hold_elem;

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

        // Writeback-side ready: backpressure to FU when hold buffer is full
        // This prevents FU from producing results that can't be accepted
        sqrt_bus.in.ready_out = (!sqrt_hold_valid || lif.lane_in.ready_in[SQRT]);
    end

    // ------------------------------------------------------------
    // SQRT: Intermediate Stage - Align FU outputs
    // ------------------------------------------------------------
    logic  sqrt_valid_wb;
    fp16_t sqrt_result_wb;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            sqrt_valid_wb  <= 1'b0;
            sqrt_result_wb <= '0;
        end else begin
            sqrt_valid_wb  <= sqrt_bus.out.valid_out;
            sqrt_result_wb <= sqrt_bus.out.result;
        end
    end

    // ------------------------------------------------------------
    // SQRT: Metadata Sync Unit (lane_fu_pt)
    // ------------------------------------------------------------
    assign sqrt_meta_in.vd       = sqrt_seq_out.vd;
    assign sqrt_meta_in.elem_idx = sqrt_seq_out.elem_idx;
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
        // Pop FIFO when FU produces result and it can be accepted
        // This ensures metadata is available (registered) when sqrt_valid_wb asserts
        .wb_valid   (sqrt_bus.out.valid_out),
        .wb_ready   (sqrt_bus.in.ready_out),  // Aligned with FU backpressure
        .meta_out   (sqrt_meta_out)
    );

    // ------------------------------------------------------------
    // SQRT: Hold Buffer & Writeback Logic
    // ------------------------------------------------------------
    // Result-holding logic
    // FU backpressure ensures results only arrive when hold buffer can accept
    // So we can safely capture whenever sqrt_valid_wb is asserted
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            sqrt_hold_valid  <= 1'b0;
            sqrt_hold_result <= '0;
            sqrt_hold_vd     <= '0;
            sqrt_hold_elem   <= '0;
        end else begin
            // Capture new FU result + metadata when available
            if (sqrt_valid_wb) begin
                sqrt_hold_valid  <= 1'b1;
                sqrt_hold_result <= sqrt_result_wb;
                sqrt_hold_vd     <= sqrt_meta_out.vd;
                sqrt_hold_elem   <= sqrt_meta_out.elem_idx;
            end
            // Once WB accepts it (and no new result arriving), drop valid
            else if (sqrt_hold_valid && lif.lane_in.ready_in[SQRT]) begin
                sqrt_hold_valid <= 1'b0;
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
    fp16_t      div_hold_result;
    vsel_t      div_hold_vd;
    slice_idx_t div_hold_elem;
    logic [7:0] div_hold_dbg_seq;

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
    // DIV: Intermediate Stage - Align FU outputs
    // ------------------------------------------------------------
    logic  div_valid_wb;
    fp16_t div_result_wb;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            div_valid_wb  <= 1'b0;
            div_result_wb <= '0;
        end else begin
            div_valid_wb  <= div_bus.out.valid_out;
            div_result_wb <= div_bus.out.result;
        end
    end

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
        .wb_valid   (div_bus.out.valid_out),
        .wb_ready   (div_bus.in.ready_out),
        .meta_out   (div_meta_out)
    );

    // ------------------------------------------------------------
    // DIV: Hold Buffer & Writeback Logic
    // ------------------------------------------------------------
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            div_hold_valid   <= 1'b0;
            div_hold_result  <= '0;
            div_hold_vd      <= '0;
            div_hold_elem    <= '0;
            div_hold_dbg_seq <= '0;
        end else begin
            // Capture new FU result + metadata when available
            if (div_valid_wb) begin
                div_hold_valid   <= 1'b1;
                div_hold_result  <= div_result_wb;
                div_hold_vd      <= div_meta_out.vd;
                div_hold_elem    <= div_meta_out.elem_idx;
                div_hold_dbg_seq <= div_meta_out.dbg_seq;
            end
            // Once WB accepts it (and no new result arriving), drop valid
            else if (div_hold_valid && lif.lane_in.ready_in[DIV]) begin
                div_hold_valid <= 1'b0;
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

    // Intermediate WB alignment (just like SQRT/DIV)
    logic        mul_valid_wb;
    logic [15:0] mul_result_wb;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            mul_valid_wb  <= 1'b0;
            mul_result_wb <= '0;
        end else begin
            mul_valid_wb  <= mul_bus.out.valid_out;
            mul_result_wb <= mul_bus.out.result;
        end
    end

    // Metadata sync (lane_fu_pt)
    assign mul_meta_in.vd       = mul_seq_out.vd;
    assign mul_meta_in.elem_idx = mul_seq_out.elem_idx;
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
        .wb_valid   (mul_bus.out.valid_out),
        .wb_ready   (mul_bus.in.ready_out),  // WB backpressure from lane
        .meta_out   (mul_meta_out)
    );

    // Hold buffer & WB
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            mul_hold_valid  <= 1'b0;
            mul_hold_result <= '0;
            mul_hold_vd     <= '0;
            mul_hold_elem   <= '0;
        end else begin
            if (mul_valid_wb) begin
                mul_hold_valid  <= 1'b1;
                mul_hold_result <= mul_result_wb;
                mul_hold_vd     <= mul_meta_out.vd;
                mul_hold_elem   <= mul_meta_out.elem_idx;
            end else if (mul_hold_valid && lif.lane_in.ready_in[MUL]) begin
                mul_hold_valid <= 1'b0;
            end
        end
    end

    // ------------------------------------------------------------
    // DIV: Debug Instrumentation
    // ------------------------------------------------------------
    
`ifdef DIV_DEBUG
    // Track when DIV FU actually accepts input (latches operands)
    always_ff @(posedge CLK) begin
        if (nRST && div_bus.in.valid_in && div_bus.out.ready_in) begin
            $display("[%0t] DIV_ACCEPT   vd=%0d elem_idx=%0d mask=%b v1=%h v2=%h (FU latches operands)",
                     $time, div_seq_out.vd, div_seq_out.elem_idx,
                     div_seq_out.mask_bit, div_seq_out.v1_elem, div_seq_out.v2_elem);
        end
    end

    // Track DIV issue events (when fire_valid asserts)
    always_ff @(posedge CLK) begin
        if (nRST && div_fire_valid && div_sync_ready) begin
            $display("[%0t] DIV_ISSUE    vd=%0d elem_idx=%0d mask=%b dbg_seq=%0d v1=%h v2=%h",
                     $time, div_seq_out.vd, div_seq_out.elem_idx, div_seq_out.mask_bit,
                     div_dbg_seq_cnt, div_seq_out.v1_elem, div_seq_out.v2_elem);
        end
    end

    // Track when DIV FU produces output (before hold buffer)
    always_ff @(posedge CLK) begin
        if (nRST && div_bus.out.valid_out && div_bus.in.ready_out) begin
            $display("[%0t] DIV_FU_OUT   result=%h (FU->intermediate stage)",
                     $time, div_bus.out.result);
        end
    end

    // Track when metadata + result enter hold buffer (intermediate stage)
    always_ff @(posedge CLK) begin
        if (nRST && div_valid_wb) begin
            $display("[%0t] DIV_HOLD_IN  vd=%0d elem_idx=%0d dbg_seq=%0d result=%h",
                     $time, div_meta_out.vd, div_meta_out.elem_idx, 
                     div_meta_out.dbg_seq, div_result_wb);
        end
    end

    // Track final writeback to lane interface
    always_ff @(posedge CLK) begin
        if (nRST && lif.lane_out.valid_o[DIV] && lif.lane_in.ready_in[DIV]) begin
            $display("[%0t] DIV_WB_OUT   vd=%0d elem_idx=%0d dbg_seq=%0d result=%h",
                     $time, lif.lane_out.vd[DIV], lif.lane_out.elem_idx[DIV],
                     div_hold_dbg_seq, lif.lane_out.result[DIV]);
        end
    end
`endif

    // Assertions for DIV path correctness
    // Ensure masked elements never fire
    always_ff @(posedge CLK) begin
        if (nRST && div_seq_out.valid && !div_seq_out.mask_bit) begin
            assert (!div_fire_valid) 
                else $error("[%0t] DIV: Attempting to fire with mask_bit=0!", $time);
            assert (!div_bus.in.valid_in)
                else $error("[%0t] DIV: FU valid_in asserted with mask_bit=0!", $time);
        end
    end

`ifdef DIV_DBG_SEQ_CHECK
    // Optional assertion: metadata dbg_seq should increment monotonically at WB
    // This is a debug-only check, disabled by default
    logic [7:0] last_div_dbg_seq;
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            last_div_dbg_seq <= '0;
        end else if (lif.lane_out.valid_o[DIV] && lif.lane_in.ready_in[DIV]) begin
            // Check that dbg_seq increments (allowing for wraps and initial values)
            if (last_div_dbg_seq != 0 && div_hold_dbg_seq == last_div_dbg_seq) begin
                $error("[%0t] DIV: dbg_seq repeated! seq=%0d", $time, last_div_dbg_seq);
            end
            last_div_dbg_seq <= div_hold_dbg_seq;
        end
    end
`endif

`ifdef MUL_DEBUG
    initial $display("[%0t] MUL_DEBUG is ON in %m", $time);
    // Track when MUL FU actually accepts input
    always_ff @(posedge CLK) begin
        if (nRST && mul_bus.in.valid_in && mul_bus.out.ready_in) begin
            $display("[%0t] MUL_ACCEPT  vd=%0d elem=%0d mask=%b  v1=%h v2=%h",
                     $time,
                     mul_seq_out.vd,
                     mul_seq_out.elem_idx,
                     mul_seq_out.mask_bit,
                     mul_seq_out.v1_elem,
                     mul_seq_out.v2_elem);
        end
    end

    // Track when we *intend* to issue (sequencer fire)
    always_ff @(posedge CLK) begin
        if (nRST && mul_fire_valid && mul_sync_ready) begin
            $display("[%0t] MUL_ISSUE   vd=%0d elem=%0d mask=%b",
                     $time,
                     mul_seq_out.vd,
                     mul_seq_out.elem_idx,
                     mul_seq_out.mask_bit);
        end
    end

    // Track FU producing an output (pre-align)
    always_ff @(posedge CLK) begin
        if (nRST && mul_bus.out.valid_out && mul_bus.in.ready_out) begin
            $display("[%0t] MUL_FU_OUT  result=%h",
                     $time, mul_bus.out.result);
        end
    end

    // Track when metadata + result enter hold buffer (aligned stage)
    always_ff @(posedge CLK) begin
        if (nRST && mul_valid_wb) begin
            $display("[%0t] MUL_HOLD_IN vd=%0d elem=%0d result=%h",
                     $time,
                     mul_meta_out.vd,
                     mul_meta_out.elem_idx,
                     mul_result_wb);
        end
    end

    // Track final writeback to lane interface
    always_ff @(posedge CLK) begin
        if (nRST && lif.lane_out.valid_o[MUL] && lif.lane_in.ready_in[MUL]) begin
            $display("[%0t] MUL_WB_OUT  vd=%0d elem=%0d result=%h",
                     $time,
                     lif.lane_out.vd[MUL],
                     lif.lane_out.elem_idx[MUL],
                     lif.lane_out.result[MUL]);
        end
    end
`endif


    // ============================================================
    // Lane Output Bus (Combined SQRT + DIV)
    // ============================================================
    always_comb begin
        lif.lane_out = '0;

        // SQRT outputs
        lif.lane_out.ready_o[SQRT] = sqrt_seq_out.lane_ready;
        lif.lane_out.valid_o[SQRT]  = sqrt_hold_valid;
        lif.lane_out.result[SQRT]   = sqrt_hold_result;
        lif.lane_out.vd[SQRT]       = sqrt_hold_vd;
        lif.lane_out.elem_idx[SQRT] = sqrt_hold_elem;

        // DIV outputs
        lif.lane_out.ready_o[DIV] = div_seq_out.lane_ready;
        lif.lane_out.valid_o[DIV]  = div_hold_valid;
        lif.lane_out.result[DIV]   = div_hold_result;
        lif.lane_out.vd[DIV]       = div_hold_vd;
        lif.lane_out.elem_idx[DIV] = div_hold_elem;

        // MUL outputs
        lif.lane_out.ready_o[MUL]  = mul_seq_out.lane_ready;
        lif.lane_out.valid_o[MUL]  = mul_hold_valid;
        lif.lane_out.result[MUL]   = mul_hold_result;
        lif.lane_out.vd[MUL]       = mul_hold_vd;
        lif.lane_out.elem_idx[MUL] = mul_hold_elem;

    end

endmodule
