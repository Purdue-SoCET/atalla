`include "vector_pkg.vh"
`include "valu_if.vh"

module valu (
    input  logic       CLK,
    input  logic       nRST,
    valu_if.valu_if    alu
);

    import vector_pkg::*;

    // ----------------------------------------------------------------
    // Internal wires / regs
    // ----------------------------------------------------------------
    logic [15:0] bf1_in, bf2_in, bf_out;
    logic        op;
    logic        overflow, underflow, invalid;

    // Simple BF16 add/sub block (already existing IP)
    addsub_bf16 adder (
        .clk      (CLK),
        .nRST     (nRST),
        .bf1_in   (bf1_in),
        .bf2_in   (bf2_in),
        .op       (op),
        .bf_out   (bf_out),
        .overflow (overflow),
        .underflow(underflow),
        .invalid  (invalid)
    );

    // Pipeline staging
    logic [15:0] value_a_s1, value_b_s1;
    logic [15:0] value_a_s2, value_b_s2;
    logic [1:0]  alu_op_s1,  alu_op_s2;
    logic        any_nan_s1, any_nan_s2;
    logic        valid_s1,   valid_s2;

    // Input handshake
    logic        ready_in_reg;   // FU input ready (to lane)
    logic        accept_in;      // actual accept pulse

    // Output stage
    logic [15:0] result_reg;
    logic [15:0] result_next;

    // ----------------------------------------------------------------
    // Handshake: one in-flight op at a time
    // ----------------------------------------------------------------

    // We are ready to accept a new op when ready_in_reg is 1.
    assign accept_in = alu.in.valid_in & ready_in_reg;

    // Advertise input readiness to lane
    assign alu.out.ready_in = ready_in_reg;

    // ready_in_reg: 1 after reset, drops when we accept an op,
    // goes back to 1 once the result has been consumed.
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            ready_in_reg <= 1'b1;
        end else begin
            if (accept_in) begin
                // Took a new operation – block new ones until retire
                ready_in_reg <= 1'b0;
            end else if (alu.out.valid_out && alu.in.ready_out) begin
                // Result has been consumed by WB – we can take another
                ready_in_reg <= 1'b1;
            end
        end
    end

    // ----------------------------------------------------------------
    // NaN detection / stage-1 register
    // ----------------------------------------------------------------
    logic a_is_nan_raw, b_is_nan_raw, any_nan_raw;

    always_comb begin
        a_is_nan_raw = (&alu.in.operand1[14:7]) && (|alu.in.operand1[6:0]);
        b_is_nan_raw = (&alu.in.operand2[14:7]) && (|alu.in.operand2[6:0]);
        any_nan_raw  = a_is_nan_raw | b_is_nan_raw;

        // adder inputs driven from stage-1 registers
        bf1_in = value_a_s1;
        bf2_in = value_b_s1;

        // use stage-1 opcode for add/sub path
        op = (alu_op_s1 == VR_SUB ||
              alu_op_s1 == VR_MIN ||
              alu_op_s1 == VR_MAX);
    end

    // Stage 1: capture operands/op when we truly accept an input
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            value_a_s1 <= '0;
            value_b_s1 <= '0;
            alu_op_s1  <= 2'b00;
            any_nan_s1 <= 1'b0;
            valid_s1   <= 1'b0;
        end else begin
            if (accept_in) begin
                value_a_s1 <= alu.in.operand1;
                value_b_s1 <= alu.in.operand2;
                alu_op_s1  <= alu.in.alu_op;
                any_nan_s1 <= any_nan_raw;
            end
            // valid_s1 is a 1-cycle pulse when we accept an input
            valid_s1 <= accept_in;
        end
    end

    // Stage 2: align control / NaN flag with adder output
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            value_a_s2 <= '0;
            value_b_s2 <= '0;
            alu_op_s2  <= 2'b00;
            any_nan_s2 <= 1'b0;
            valid_s2   <= 1'b0;
        end else begin
            value_a_s2 <= value_a_s1;
            value_b_s2 <= value_b_s1;
            alu_op_s2  <= alu_op_s1;
            any_nan_s2 <= any_nan_s1;
            valid_s2   <= valid_s1;
        end
    end

    // ----------------------------------------------------------------
    // Result select (NaN / MIN / MAX / ADD / SUB)
    // ----------------------------------------------------------------
    always_comb begin
        if (any_nan_s2) begin
            result_next = 16'h7FC0; // canonical bf16 qNaN
        end else begin
            unique case (alu_op_s2)
                VR_SUM, VR_SUB: result_next = bf_out;
                VR_MIN:         result_next = (bf_out[15] ? value_a_s2 : value_b_s2);
                VR_MAX:         result_next = (bf_out[15] ? value_b_s2 : value_a_s2);
                default:        result_next = 16'h0000;
            endcase
        end
    end

    // ----------------------------------------------------------------
    // Output register + valid_out
    // ----------------------------------------------------------------
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            result_reg        <= 16'h0000;
            alu.out.valid_out <= 1'b0;
        end else begin
            // Drop valid when WB consumes the result
            if (alu.out.valid_out && alu.in.ready_out) begin
                alu.out.valid_out <= 1'b0;
            end

            // Latch a new result when stage-2 fires
            // (valid_s2 can only be 1 when valid_out is 0, because
            //  we don't accept a new op until the previous result retires.)
            if (valid_s2) begin
                result_reg        <= result_next;
                alu.out.valid_out <= 1'b1;
            end
        end
    end

    // Drive result
    assign alu.out.result = result_reg;

endmodule