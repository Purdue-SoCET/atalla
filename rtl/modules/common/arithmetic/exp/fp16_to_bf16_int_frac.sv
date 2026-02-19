// Assumes fp16_in is non-negative, normalized (sign = 0, exp != 0)
// int_u32 = floor(x)
// frac_bf16 = fractional part in [0,1) as bfloat16
module fp16_to_bf16_int_frac (
  input  logic [15:0] fp16_in,
  output logic [31:0] int_u32,
  output logic [15:0] frac_bf16
);

  localparam int FP16_BIAS = 15;
  localparam int BF16_BIAS = 127;

  // -------------------------------
  // MSB finder for 11-bit value
  // -------------------------------
  function automatic int msb_pos11 (input logic [10:0] x);
    begin
      unique casez (x)
        11'b1??????????: msb_pos11 = 10;
        11'b01?????????: msb_pos11 = 9;
        11'b001????????: msb_pos11 = 8;
        11'b0001???????: msb_pos11 = 7;
        11'b00001??????: msb_pos11 = 6;
        11'b000001?????: msb_pos11 = 5;
        11'b0000001????: msb_pos11 = 4;
        11'b00000001???: msb_pos11 = 3;
        11'b000000001??: msb_pos11 = 2;
        11'b0000000001?: msb_pos11 = 1;
        11'b00000000001: msb_pos11 = 0;
        default:          msb_pos11 = -1;
      endcase
    end
  endfunction

  // --------------------------------------------
  // Convert fixed-point fraction N / 2^s to bf16
  // N: up to 11 bits
  // s: shift (denominator exponent)
  // --------------------------------------------
  function automatic logic [15:0] fixed_frac_to_bf16 (
    input logic [10:0] N,
    input int          s
  );
    logic [15:0] res;
    int   k;
    int   Efrac;        // unbiased exponent for fraction
    logic [10:0] norm;  // normalized significand with top bit at position 10
    logic [7:0]  exp_b;
    logic [6:0]  mant_b;

    // extra for rounding
    logic        guard, round_bit, sticky;
    logic [6:0]  mant_rounded;
    logic [7:0]  exp_rounded;

    begin
      if ((N == 11'd0) || (s <= 0)) begin
        res = 16'h0000; // 0.0
      end else begin
        // Find leading 1 in N
        k = msb_pos11(N);
        if (k < 0) begin
          res = 16'h0000;
        end else begin
          // fraction value is N / 2^s
          // binary exponent (unbiased) is Efrac = k - s
          Efrac = k - s;

          // Underflow to 0 if way too small for bf16 (we skip full subnormal handling)
          if (Efrac < -126) begin
            res = 16'h0000;
          end else begin
            // Normalize so that MSB is at bit 10: norm[10] = 1
            norm = N << (10 - k);  // now value ~ 1.xxx * 2^(Efrac)

            // bf16 exponent with bias
            exp_b = BF16_BIAS + Efrac;

            // ---- Round-to-nearest-even on mantissa ----
            // norm bits layout:
            //   norm[10] : implicit 1
            //   norm[9:3]: mantissa bits we keep (7 bits)
            //   norm[2]  : guard
            //   norm[1]  : round
            //   norm[0]  : sticky
            mant_b     = norm[9:3];
            guard      = norm[2];
            round_bit  = norm[1];
            sticky     = norm[0];

            mant_rounded = mant_b;
            exp_rounded  = exp_b;

            // round-to-nearest-even:
            // if guard && (round_bit || sticky || LSB of mantissa)
            if (guard && (round_bit || sticky || mant_b[0])) begin
              mant_rounded = mant_b + 7'd1;

              // handle mantissa overflow (e.g., 1.1111111 -> 10.000000)
              if (mant_rounded == 7'b1000000) begin
                mant_rounded = 7'd0;         // drop back to 0.xxx
                exp_rounded  = exp_b + 8'd1; // bump exponent
              end
            end

            // clamp exponent if it overflows bf16 range (-> +Inf)
            if (exp_rounded >= 8'hFF) begin
              res = 16'h7F80; // +Inf (sign=0)
            end else begin
              res = {1'b0, exp_rounded, mant_rounded};
            end
          end
        end
      end

      fixed_frac_to_bf16 = res;
    end
  endfunction

  // -------------------------------
  // Main logic
  // -------------------------------
  logic       sign;
  logic [4:0] exp_f;    // fp16 exponent
  logic [9:0] mant_f;   // fp16 mantissa

  logic [10:0] sig11;   // 1.mant_f
  int          E;       // unbiased exponent for fp16
  int          s;       // number of fractional bits
  logic [10:0] frac_bits;

  always_comb begin
    sign   = fp16_in[15];
    exp_f  = fp16_in[14:10];
    mant_f = fp16_in[9:0];

    int_u32   = 32'd0;
    frac_bf16 = 16'h0000;

    // handle negative, zero, or subnormal as 0 for now
    if (sign || (exp_f == 5'd0)) begin
      int_u32   = 32'd0;
      frac_bf16 = 16'h0000;
    end else begin
      // Build 11-bit significand (1.mant)
      sig11 = {1'b1, mant_f};

      // Unbiased exponent
      E = int'(exp_f) - FP16_BIAS;

      if (E >= 10) begin
        // All bits we know about are integer bits (no fractional bits in current precision)
        // x = sig11 * 2^(E-10)
        int_u32   = {21'd0, sig11} << (E - 10);
        frac_bf16 = 16'h0000;

      end else if (E >= 0) begin
        // Some integer, some fraction
        // x = sig11 * 2^(E-10) -> binary point is within sig11
        s         = 10 - E;                      // fractional bits count
        int_u32   = ({21'd0, sig11}) >> s;       // floor
        frac_bits = sig11 & ((11'h1 << s) - 1);  // residual fraction bits

        // fraction = frac_bits / 2^s -> convert to bf16
        frac_bf16 = fixed_frac_to_bf16(frac_bits, s);

      end else begin
        // E < 0: integer part is 0, whole value is fractional
        // x = sig11 / 2^(10 - E)
        int_u32   = 32'd0;
        s         = 10 - E;   // denominator exponent
        frac_bits = sig11;
        frac_bf16 = fixed_frac_to_bf16(frac_bits, s);
      end
    end
  end

endmodule