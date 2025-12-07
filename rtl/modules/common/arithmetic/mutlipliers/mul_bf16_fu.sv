// ------------------------------------------------------------
// mul_bf16_fu.sv
// Wrapper: div_if-style handshake around mul_bf16 (start/done).
// Single in-flight op, full backpressure on input/output.
// ------------------------------------------------------------
`include "mul_if.vh"

module mul_bf16_fu (
    input  logic  CLK,
    input  logic  nRST,
    mul_if        m_if
);

    // --------------------------------------------
    // Underlying core: your existing mul_bf16
    // --------------------------------------------
    logic        core_start;
    logic [15:0] core_a, core_b;
    logic [15:0] core_result;
    logic        core_done;

    mul_bf16 u_mul_core (
        .clk   (CLK),
        .nRST  (nRST),
        .start (core_start),
        .a     (core_a),
        .b     (core_b),
        .result(core_result),
        .done  (core_done)
    );

    // --------------------------------------------
    // Wrapper state
    // --------------------------------------------
    logic        busy;        // 1 op in-flight inside mul_bf16
    logic        has_result;  // result captured, waiting for WB consumption
    logic [15:0] result_reg;  // latched product

    // Output channel
    assign m_if.out.valid_out = has_result;
    assign m_if.out.result    = result_reg;

    // --------------------------------------------
    // Input handshake -> drive core_start, core_a/b, out.ready_in
    // --------------------------------------------
    // NOTE: mul_bf16 core has 0-cycle latency - done pulses in the SAME cycle as start
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            has_result        <= 1'b0;
            result_reg        <= '0;
            core_start        <= 1'b0;
            core_a            <= '0;
            core_b            <= '0;
            m_if.out.ready_in <= 1'b1;  // Initially ready for input
        end else begin
            // Default: no start pulse unless we explicitly fire
            core_start <= 1'b0;

            // Consume result when lane is ready (check in.ready_out for WB backpressure)
            if (has_result && m_if.out.valid_out && m_if.in.ready_out) begin
                has_result        <= 1'b0;
                m_if.out.ready_in <= 1'b1;  // Ready for next input after consuming result
            end

            // Launch new op if lane has valid and we are ready for input
            // Since done=1 in same cycle as start=1, we can capture result immediately
            if (m_if.in.valid_in && m_if.out.ready_in && !has_result) begin
                core_a            <= m_if.in.operand1;
                core_b            <= m_if.in.operand2;
                core_start        <= 1'b1;   // 1-cycle pulse
                // Result will be ready combinationally from latched inputs in same cycle
                // But done pulse happens in same cycle, so we latch on done
            end

            // Capture done -> latch result and mark has_result
            // For mul_bf16, done=1 in same cycle as start=1
            if (core_done) begin
                result_reg        <= core_result;
                has_result        <= 1'b1;
                m_if.out.ready_in <= 1'b0;   // Not ready while has unread result
            end
        end
    end

endmodule
