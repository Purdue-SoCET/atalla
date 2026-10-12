/* FU Vector Divide Code */
`include "div_if.vh"

module div
(
    input logic CLK, nRST,
    div_if.div divif
);

parameter int EXP_WIDTH = divif.EXP_WIDTH;
parameter int MANT_WIDTH = divif.MANT_WIDTH;

// Sequential logic to pulse done for 1 cycle
logic done, skip_divider, en_divider, is_ovf, is_sub, first_cycle;

// ============================================================
// Fixed-Latency Pipeline (Critical Fix)
// ============================================================
// DIV has variable latency: 1 cycle for NaN/Inf/Zero, 11 cycles for normal div.
// But lane_fu_pt expects FIXED latency (LATENCY=11) for metadata alignment.
// Solution: Delay fast-path results to match slow-path latency.

localparam int PIPELINE_LATENCY = 11;  // Must match lane_fu_pt LATENCY parameter
localparam int FAST_PATH_DELAY = PIPELINE_LATENCY - 1;  // Delay skip_divider by this many cycles

// Internal result ready (before fixed-latency delay)
logic result_ready_internal;

//registered signals to fix BANB
logic valid_out_r;
logic ready_in_r;

// Delay pipeline for fast-path results
logic [FAST_PATH_DELAY-1:0] fast_path_valid_shift;
logic fast_path_delayed;

assign result_ready_internal = done || (skip_divider && divif.in.valid_in && divif.out.ready_in);

always_ff @(posedge CLK, negedge nRST) begin
    if (~nRST) begin
        fast_path_valid_shift <= '0;
    end else begin
        // Shift register: delays skip_divider results to match normal div latency
        fast_path_valid_shift <= {fast_path_valid_shift[FAST_PATH_DELAY-2:0], 
                                   (skip_divider && divif.in.valid_in && divif.out.ready_in)};
    end
end

assign fast_path_delayed = fast_path_valid_shift[FAST_PATH_DELAY-1];

// Handshake state machine
always_ff @(posedge CLK, negedge nRST) begin
    if (~nRST) begin
        valid_out_r <= 0;
        ready_in_r <= 0;
        first_cycle <= 1;
    end else begin
        if (first_cycle) ready_in_r <= 1;
        first_cycle <= 0;
        
        // Assert valid_out after fixed latency for all operations
        if (done || fast_path_delayed) valid_out_r <= 1;
        else if (divif.in.ready_out && divif.out.valid_out) valid_out_r <= 0;
        
        if (divif.out.valid_out && divif.in.ready_out) ready_in_r <= 1;
        else if (divif.in.valid_in && divif.out.ready_in) ready_in_r <= 0;
    end
end

`ifdef DIV_FU_DEBUG
// Internal FU debugging
always_ff @(posedge CLK) begin
    if (nRST && divif.in.valid_in && divif.out.ready_in) begin
        $display("[%0t] DIV_FU_ACCEPT: skip=%b ops=%h/%h", 
                 $time, skip_divider, divif.in.operand1, divif.in.operand2);
    end
    if (nRST && done) begin
        $display("[%0t] DIV_FU_DONE: mant_div completed", $time);
    end
    if (nRST && fast_path_delayed) begin
        $display("[%0t] DIV_FU_FAST_DELAYED: skip_divider path delayed to 11 cycles", $time);
    end
    if (nRST && (done || fast_path_delayed)) begin
        $display("[%0t] DIV_FU_VALID_OUT asserted: result=%h", $time, divif.out.result);
    end
end
`endif
assign en_divider = (divif.in.valid_in && divif.out.ready_in) || (!divif.out.ready_in && !divif.out.valid_out);

// ============================================================
// Input Latching (Critical Fix: Match SQRT Behavior)
// ============================================================
// Latch operands when accepting new input to prevent corruption
// from changing input wires during multi-cycle operations.
// This uses the exact same pattern as sqrt_bf16.

localparam int OPERAND_WIDTH = 1 + EXP_WIDTH + MANT_WIDTH;

// Registered operand storage
logic [OPERAND_WIDTH-1:0] operand1_reg, operand2_reg;

// Combinational operand mux (sample new or hold old)
logic [OPERAND_WIDTH-1:0] operand1_next, operand2_next;

always_comb begin
    if (divif.in.valid_in && divif.out.ready_in) begin
        // Sample new inputs when accepting operation
        operand1_next = divif.in.operand1;
        operand2_next = divif.in.operand2;
    end else begin
        // Hold previous registered values
        operand1_next = operand1_reg;
        operand2_next = operand2_reg;
    end
end

always_ff @(posedge CLK, negedge nRST) begin
    if (~nRST) begin
        operand1_reg <= '0;
        operand2_reg <= '0;
    end else begin
        operand1_reg <= operand1_next;
        operand2_reg <= operand2_next;
    end
end

// Split operands into components
// Use the COMBINATIONAL operand1_next/operand2_next so values are available
// immediately on the accept cycle (matching sqrt_bf16 behavior)
logic sign_a, sign_b;
logic [EXP_WIDTH-1:0] exp_a, exp_b;
logic [MANT_WIDTH-1:0] mant_a, mant_b;
assign {sign_a, exp_a, mant_a} = operand1_next;
assign {sign_b, exp_b, mant_b} = operand2_next;

// Compute sign (simple XOR)
logic final_sign;
assign final_sign = sign_a ^ sign_b;

// Check if inputs are special values
logic exp_a_max, exp_b_max;
assign exp_a_max = &exp_a;
assign exp_b_max = &exp_b;
logic a_zero, b_zero, a_inf, b_inf, a_nan, b_nan;
assign a_zero = (exp_a == 0); // Treat subnormals as zero
assign b_zero = (exp_b == 0); // Treat subnormals as zero
assign a_inf = exp_a_max && (mant_a == 0);
assign b_inf = exp_b_max && (mant_b == 0);
assign a_nan = exp_a_max && (mant_a != 0);
assign b_nan = exp_b_max && (mant_b != 0);

// Edge case handling for NaN, infinity, and zero outputs
logic is_nan, is_inf, is_zero;
assign is_nan = a_nan || b_nan || (a_zero && b_zero) || (a_inf && b_inf);
assign is_inf = (!is_nan) && (a_inf || b_zero);
assign is_zero = (!is_nan) && (!is_inf) && (a_zero || b_inf);
assign skip_divider = is_nan || is_inf || is_zero; // skip division if edge case

// Compute raw exponent
localparam int bias = (1 << (EXP_WIDTH - 1)) - 1;
logic [EXP_WIDTH:0] exp;
assign exp = exp_a - exp_b + bias;

// int_div #(.SIZE(MANT_WIDTH*2+3), .SKIP(MANT_WIDTH+1)) divider (
//     .CLK(CLK), .nRST(nRST), .en(en_divider && !skip_divider),
//     .x({divif.in.operand1[MANT_WIDTH+:EXP_WIDTH] != 0, mant_a, {(MANT_WIDTH+2){1'b0}}}),
//     .y({{(MANT_WIDTH + 2){1'b0}}, exp_b != 0, mant_b}),
//     .result(quotient), .done(done)
// );

// Use optimized mantissa divider (unused reg space removed)
logic [MANT_WIDTH+2:0] quotient;
mant_div #(.MANT_WIDTH(MANT_WIDTH)) m_div (
    .CLK(CLK), .nRST(nRST), .en(en_divider && !skip_divider),
    .x({exp_a != 0, mant_a}),  // Use latched exp_a, not live input
    .y({exp_b != 0, mant_b}),  // Already using latched exp_b
    .result(quotient), .done(done)
);

// Normalize exponent and quotient, set rounding bit
logic [MANT_WIDTH-1:0] final_mant;
logic [EXP_WIDTH:0] exp_norm;
logic [EXP_WIDTH-1:0] final_exp;
always_comb begin
    if (exp == 0) begin
        final_mant = quotient[MANT_WIDTH+2:3] + quotient[2];
        exp_norm = exp;
    end else if (exp == 1) begin
        final_mant = quotient[MANT_WIDTH+1:2] + quotient[1];
        exp_norm = quotient[MANT_WIDTH+2];
    end else if (quotient[MANT_WIDTH+2]) begin
        final_mant = quotient[MANT_WIDTH+1:2] + quotient[1];
        exp_norm = exp;
    end else begin
        final_mant = quotient[MANT_WIDTH:1] + quotient[0];
        exp_norm = exp - 1;
    end
end
assign final_exp = exp_norm[EXP_WIDTH-1:0];

// Detect overflow (positive exponent minus negative exponent, exp > 2 ^ EXP_WIDTH - 2)
assign is_ovf = ~skip_divider & exp_a[EXP_WIDTH-1] & ~exp_b[EXP_WIDTH-1] & (exp_norm > (1 << EXP_WIDTH) - 2);
assign is_sub = exp_norm[EXP_WIDTH] || exp_norm == 0;

// Compute final result (accounting for edge cases)
always_comb begin
    if (is_nan)
        divif.out.result = {final_sign, {EXP_WIDTH{1'b1}}, 1'b1, {(MANT_WIDTH-1){1'b0}}};
    else if (is_inf || is_ovf && !skip_divider)
        divif.out.result = {final_sign, {EXP_WIDTH{1'b1}}, {MANT_WIDTH{1'b0}}};
    else if (is_zero || is_sub)
        divif.out.result = {final_sign, {EXP_WIDTH{1'b0}}, {MANT_WIDTH{1'b0}}};
    else
        divif.out.result = {final_sign, final_exp, final_mant};
end

assign divif.out.valid_out = valid_out_r;
assign divif.out.ready_in = ready_in_r;

endmodule



// Submodule: Integer divider modified for mantissa division
module mant_div #(
    parameter MANT_WIDTH = 10
)(
    input logic CLK, nRST, en,
    input logic [MANT_WIDTH:0] x, y,
    output logic [MANT_WIDTH+2:0] result,
    output logic done
);

localparam A_WIDTH = MANT_WIDTH * 2 + 3;

typedef enum logic {IDLE, DIV} state_t;
state_t state, next_state;

logic [MANT_WIDTH+2:0] q, next_q;
logic [A_WIDTH:0] a, next_a;
logic [MANT_WIDTH:0] m, next_m;
logic [$clog2(MANT_WIDTH+2):0] n, next_n;
always_ff @(posedge CLK) begin
    if (~nRST) begin
        state <= IDLE;
        q <= 0;
        m <= 0;
        a <= 0;
        n <= 0;
    end else begin
        state <= next_state;
        q <= next_q;
        m <= next_m;
        a <= next_a;
        n <= next_n;
    end
end

always_comb begin
    next_state = state;
    next_q = q;
    next_m = m;
    next_a = a;
    next_n = n;
    case (state)
        IDLE: begin
            if (en) begin
                next_state = DIV;
                next_m = {1'b0, y};
                next_n = MANT_WIDTH + 1;
                // Do first iteration immediately
                next_a = x - next_m;
                next_q = {1'b0, ~next_a[A_WIDTH]};
            end
        end
        DIV: begin
            next_a = a[A_WIDTH] ? {a[A_WIDTH-1:0], q[MANT_WIDTH+2]} + m : {a[A_WIDTH-1:0], q[MANT_WIDTH+2]} - m;
            next_q = {q[MANT_WIDTH+1:0], ~next_a[A_WIDTH]};
            next_n = n - 1;
            if (n == 0) next_state = IDLE;
        end
    endcase
end

assign result = next_q[MANT_WIDTH+2:0];
assign done = (state == DIV && n == 0);

endmodule
