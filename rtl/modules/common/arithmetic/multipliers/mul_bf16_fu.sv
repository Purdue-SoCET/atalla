// ------------------------------------------------------------
// mul_bf16_fu.sv
// Robust wrapper around mul_bf16:
//   - Single in-flight operation
//   - 1:1 mapping between accepted inputs and retired results
//   - No result overwrites, no dropped done pulses
// ------------------------------------------------------------
`include "mul_if.vh"

module mul_bf16_fu (
    input  logic  CLK,
    input  logic  nRST,
    mul_if        m_if
);

    // --------------------------------------------
    // Underlying core
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
    // Simple FSM: IDLE -> BUSY -> HAVE_RES
    //   IDLE     : no op in flight, no result pending
    //   BUSY     : core has an in-flight op (waiting for done)
    //   HAVE_RES : result ready, waiting for downstream to consume
    // --------------------------------------------
    typedef enum logic [1:0] { IDLE, BUSY, HAVE_RES } state_t;
    state_t state, state_n;

    logic [15:0] result_reg;

    // Output channel: result + valid
    assign m_if.out.result    = result_reg;
    assign m_if.out.valid_out = (state == HAVE_RES);

    // Input backpressure:
    //   - Only accept a new op when there is NO in-flight op and NO pending result
    assign m_if.out.ready_in  = (state == IDLE);

    // --------------------------------------------
    // Sequential logic
    // --------------------------------------------
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            state      <= IDLE;
            result_reg <= '0;
            core_start <= 1'b0;
            core_a     <= '0;
            core_b     <= '0;
        end else begin
            state      <= state_n;

            // Default: no start pulse unless we explicitly fire this cycle
            core_start <= 1'b0;

            // Accept new input ONLY in IDLE
            if (state == IDLE &&
                m_if.in.valid_in &&
                m_if.out.ready_in) begin

                core_a     <= m_if.in.operand1;
                core_b     <= m_if.in.operand2;
                core_start <= 1'b1;   // 1-cycle start pulse
            end

            // Capture core result when it completes
            if (core_done) begin
                result_reg <= core_result;
            end
        end
    end

    // --------------------------------------------
    // Next state logic
    // --------------------------------------------
    always_comb begin
        state_n = state;

        unique case (state)
            // No op in flight, no result pending:
            //  - Wait for input accept → go BUSY
            IDLE: begin
                if (m_if.in.valid_in && m_if.out.ready_in) begin
                    state_n = BUSY;
                end
            end

            // Core is computing:
            //  - Wait for core_done → result becomes pending → HAVE_RES
            BUSY: begin
                if (core_done) begin
                    state_n = HAVE_RES;
                end
            end

            // Result is available:
            //  - Hold valid_out high until downstream consumes it
            //    (valid_out && ready_out)
            //  - After consumption → back to IDLE
            HAVE_RES: begin
                if (m_if.out.valid_out && m_if.in.ready_out) begin
                    state_n = IDLE;
                end
            end
        endcase
    end

endmodule
