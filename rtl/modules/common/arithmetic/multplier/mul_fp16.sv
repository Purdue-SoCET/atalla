`timescale 1ps/1ps
// FP16 Parameterized Multiplier with DAZ/FTZ and special case handling
//
// LATENCY parameter controls pipeline depth:
//   0: Purely combinational (no clock). Equivalent to old mul_fp16_1c.
//   1: Combinational core + 1 output register.
//   2: Pipelined WTM (2-cycle) + pipeline registers for flags/exponents.
//      Equivalent to old mul_fp16. Supports start/stall/done.
//
// Submodules: wtm_fp (LATENCY 0,1), wtm_fp_2c (LATENCY 2), adder_5b

module mul_fp16 #(
    parameter LATENCY = 0  // 0 = combinational, 1 = 1-cycle, 2 = 2-cycle pipelined
)(
    input  logic        clk,    // unused when LATENCY=0
    input  logic        nRST,   // unused when LATENCY=0
    input  logic        start,  // unused when LATENCY<2
    input  logic        stall,  // unused when LATENCY<2
    input  logic [15:0] a, b,
    output logic [15:0] result,
    output logic        done    // unused when LATENCY<2
);

    // Field extraction
    logic [4:0] exp_a, exp_b;
    logic [9:0] mant_a, mant_b;
    assign exp_a  = a[14:10];
    assign exp_b  = b[14:10];
    assign mant_a = a[9:0];
    assign mant_b = b[9:0];

    // Special value detection (combinational, shared by all latencies)
    logic a_exp_zero, b_exp_zero;
    logic a_exp_max, b_exp_max;
    logic a_mant_zero, b_mant_zero;
    assign a_exp_zero  = (exp_a == 5'b0);
    assign b_exp_zero  = (exp_b == 5'b0);
    assign a_exp_max   = (exp_a == 5'h1F);
    assign b_exp_max   = (exp_b == 5'h1F);
    assign a_mant_zero = (mant_a == 10'b0);
    assign b_mant_zero = (mant_b == 10'b0);

    logic a_is_zero, b_is_zero;
    logic a_is_special, b_is_special;
    logic any_nan, any_inf, any_zero, inf_times_zero;

    assign a_is_zero      = a_exp_zero;
    assign b_is_zero      = b_exp_zero;
    assign a_is_special   = a_exp_max;
    assign b_is_special   = b_exp_max;
    assign any_nan        = (a_is_special & ~a_mant_zero) | (b_is_special & ~b_mant_zero);
    assign any_inf        = (a_is_special & a_mant_zero) | (b_is_special & b_mant_zero);
    assign any_zero       = a_is_zero | b_is_zero;
    assign inf_times_zero = ((a_is_special & a_mant_zero) & b_is_zero) |
                            ((b_is_special & b_mant_zero) & a_is_zero);

    // Sign calculation
    logic mul_sign;
    assign mul_sign = a[15] ^ b[15];

    // Implicit leading bits
    logic frac_leading_bit_fp1, frac_leading_bit_fp2;
    assign frac_leading_bit_fp1 = ~a_exp_zero;
    assign frac_leading_bit_fp2 = ~b_exp_zero;

    // Wallace tree multiplier instantiation
    logic [12:0] mul_product;
    logic mul_carryout;
    logic mul_round_loss;

    generate
        if (LATENCY <= 1) begin : gen_wtm_comb
            // Combinational WTM for latency 0 and 1
            wtm_fp wallaca (
                .a({frac_leading_bit_fp1, a[9:0]}),
                .b({frac_leading_bit_fp2, b[9:0]}),
                .result(mul_product),
                .overflow(mul_carryout),
                .round_loss(mul_round_loss)
            );
        end
        else begin : gen_wtm_pipe
            // Pipelined 2-cycle WTM for latency 2
            logic wtm_ready;

            wtm_fp_2c wallaca (
                .clk(clk),
                .nRST(nRST),
                .a({frac_leading_bit_fp1, a[9:0]}),
                .b({frac_leading_bit_fp2, b[9:0]}),
                .active(start),
                .stall(stall),
                .result(mul_product),
                .overflow(mul_carryout),
                .round_loss(mul_round_loss),
                .value_ready(wtm_ready)
            );
        end
    endgenerate

    // Pipeline registers for special-case flags (LATENCY=2 only)
    // For LATENCY 0/1 these are just pass-through wires.
    logic        mul_sign_q;
    logic        any_nan_q, any_inf_q, any_zero_q, inf_times_zero_q;
    logic [4:0]  exp_a_q, exp_b_q;

    generate
        if (LATENCY <= 1) begin : gen_flags_comb
            // Pass-through: no pipeline register
            assign mul_sign_q        = mul_sign;
            assign any_nan_q         = any_nan;
            assign any_inf_q         = any_inf;
            assign any_zero_q        = any_zero;
            assign inf_times_zero_q  = inf_times_zero;
            assign exp_a_q           = exp_a;
            assign exp_b_q           = exp_b;
        end
        else begin : gen_flags_pipe
            // Register flags to align with pipelined WTM output
            always_ff @(posedge clk, negedge nRST) begin
                if (!nRST) begin
                    mul_sign_q        <= '0;
                    any_nan_q         <= '0;
                    any_inf_q         <= '0;
                    any_zero_q        <= '0;
                    inf_times_zero_q  <= '0;
                    exp_a_q           <= '0;
                    exp_b_q           <= '0;
                end
                else if (stall) begin
                    mul_sign_q        <= mul_sign_q;
                    any_nan_q         <= any_nan_q;
                    any_inf_q         <= any_inf_q;
                    any_zero_q        <= any_zero_q;
                    inf_times_zero_q  <= inf_times_zero_q;
                    exp_a_q           <= exp_a_q;
                    exp_b_q           <= exp_b_q;
                end
                else begin
                    mul_sign_q        <= mul_sign;
                    any_nan_q         <= any_nan;
                    any_inf_q         <= any_inf;
                    any_zero_q        <= any_zero;
                    inf_times_zero_q  <= inf_times_zero;
                    exp_a_q           <= exp_a;
                    exp_b_q           <= exp_b;
                end
            end
        end
    endgenerate

    // Exponent addition (combinational, uses registered or direct exp values)
    logic [4:0] exp_sum;
    logic exp_ovf, exp_unf;

    adder_5b add_EXPs (
        .carry(mul_carryout),
        .exp1(exp_a_q),
        .exp2(exp_b_q),
        .sum(exp_sum),
        .ovf(exp_ovf),
        .unf(exp_unf)
    );

    // Normalization shift + guard/round/sticky extraction
    logic [9:0] mul_frac_normalized;
    logic guard_bit, round_bit, sticky_bit;

    always_comb begin
        if (mul_carryout) begin
            // Product >= 2.0, shift right by 1
            mul_frac_normalized = mul_product[12:3];
            guard_bit  = mul_product[2];
            round_bit  = mul_product[1];
            sticky_bit = mul_product[0] | mul_round_loss;
        end
        else if (exp_unf && (exp_sum == 5'd0)) begin
            // Subnormal boundary: shift right 1 more for 0.1xxx format
            mul_frac_normalized = mul_product[12:3];
            guard_bit  = mul_product[2];
            round_bit  = mul_product[1];
            sticky_bit = mul_product[0] | mul_round_loss;
        end
        else begin
            // Product in [1.0, 2.0), no shift needed
            mul_frac_normalized = mul_product[11:2];
            guard_bit  = mul_product[1];
            round_bit  = mul_product[0];
            sticky_bit = mul_round_loss;
        end
    end

    // Rounding (round to nearest even, ties to even)
    logic round_up;
    logic [10:0] mul_significand_rounded;
    assign round_up = guard_bit & (round_bit | sticky_bit | mul_frac_normalized[0]);
    assign mul_significand_rounded = {1'b0, mul_frac_normalized} + {10'b0, round_up};

    // Overflow / Underflow detection
    logic exp_overflow, exp_underflow, boundary_case;
    assign exp_overflow  = exp_ovf | (~exp_unf & mul_significand_rounded[10] & (exp_sum == 5'd30));
    assign boundary_case = exp_unf & (exp_sum == 5'd0) & mul_significand_rounded[10];
    assign exp_underflow = exp_unf & ~boundary_case;

    // Final exponent
    logic [4:0] mul_final_exp;
    logic mul_product_valid;
    assign mul_product_valid = (mul_product != 13'b0) | mul_carryout;

    always_comb begin
        if (~mul_product_valid)
            mul_final_exp = 5'b0;
        else if (boundary_case)
            mul_final_exp = 5'd1;
        else
            mul_final_exp = mul_significand_rounded[10] ? exp_sum + 5'd1 : exp_sum;
    end

    // FTZ check
    logic result_is_subnormal;
    assign result_is_subnormal = ~exp_overflow & ~exp_underflow & mul_product_valid &
                                  (mul_final_exp == 5'b0) & (mul_significand_rounded[9:0] != 10'b0);

    // Output mux with special case handling
    logic has_special_case;
    logic [15:0] special_result;

    assign has_special_case = any_nan_q | inf_times_zero_q | any_inf_q | any_zero_q |
                              exp_overflow | exp_underflow | result_is_subnormal;

    always_comb begin
        if (any_nan_q | inf_times_zero_q)
            special_result = 16'h7E00;
        else if (any_inf_q)
            special_result = {mul_sign_q, 5'h1F, 10'b0};
        else if (any_zero_q | exp_overflow)
            special_result = {mul_sign_q, any_zero_q ? 15'b0 : {5'h1F, 10'b0}};
        else
            special_result = {mul_sign_q, 15'b0};
    end

    logic [15:0] result_comb;
    assign result_comb = has_special_case ? special_result :
                         {mul_sign_q, mul_final_exp, mul_significand_rounded[9:0]};

    // Output register (LATENCY >= 1) and done logic (LATENCY == 2)
    generate
        if (LATENCY == 0) begin : gen_out_comb
            // Purely combinational output
            assign result = result_comb;
            assign done   = 1'b0; // unused
        end
        else if (LATENCY == 1) begin : gen_out_1c
            // Single output register
            always_ff @(posedge clk, negedge nRST) begin
                if (~nRST)
                    result <= '0;
                else
                    result <= result_comb;
            end
            assign done = 1'b0; // unused
        end
        else begin : gen_out_2c
            // Combinational output (registered flags already provide alignment)
            assign result = result_comb;

            // Done tracking: delay wtm_ready by 1 cycle for comb2 stage
            logic done_r;
            always_ff @(posedge clk, negedge nRST) begin
                if (!nRST)
                    done_r <= 1'b0;
                else if (stall)
                    done_r <= done_r;
                else
                    done_r <= gen_wtm_pipe.wtm_ready;
            end
            assign done = done_r & ~stall;
        end
    endgenerate

endmodule
