// bfloat16 layout: [15]=sign, [14:7]=exp (bias=127), [6:0]=mant
// Outputs:
//   int_u32   = floor(x) as 32-bit unsigned integer
//   frac_bf16 = fractional part (x - floor(x)) as bfloat16
module bf16_to_int_frac (
  input  logic [15:0] bf16_in,
  output logic [31:0] int_u32,
  output logic [15:0] frac_bf16
);

  // ------------------------------------------------------------
  // helpers
  // ------------------------------------------------------------

  // find MSB position in 8-bit value; returns -1 if x == 0
  function automatic int msb_pos8 (input logic [7:0] x);
    begin
      unique casez (x)
        8'b1???????: msb_pos8 = 7;
        8'b01??????: msb_pos8 = 6;
        8'b001?????: msb_pos8 = 5;
        8'b0001????: msb_pos8 = 4;
        8'b00001???: msb_pos8 = 3;
        8'b000001??: msb_pos8 = 2;
        8'b0000001?: msb_pos8 = 1;
        8'b00000001: msb_pos8 = 0;
        default:      msb_pos8 = -1; // x == 0
      endcase
    end
  endfunction

  // Convert a fixed-point fraction N / 2^s (0 <= N < 256) into bfloat16.
  // Only handles magnitudes < 1.0. If it would be subnormal, returns 0.
  function automatic logic [15:0] fixed_frac_to_bf16 (
    input logic [7:0] N,
    input int         s
  );
    logic [15:0] res;
    int   k;
    int   Efrac;
    logic [7:0] norm;
    logic [7:0] exp_b;

    begin
      if (N == 8'd0) begin
        res = 16'h0000;
      end else begin
        // N = (1.xxx...) * 2^k
        k = msb_pos8(N);          // 0..7

        // fraction = N / 2^s = (1.xxx) * 2^(k - s)
        Efrac = k - s;            // unbiased exponent

        // bfloat16 normalized min exponent is -126
        if (Efrac < -126) begin
          res = 16'h0000;         // too small → flush to 0 (no subnormals)
        end else begin
          // normalize: put MSB of N at bit7
          norm  = N << (7 - k);   // norm[7] == 1
          // bias exponent (bf16 bias = 127)
          exp_b = 8'(Efrac + 127);

          // pack: sign=0, exponent=exp_b, mantissa = norm[6:0]
          res = {1'b0, exp_b, norm[6:0]};
        end
      end

      fixed_frac_to_bf16 = res;
    end
  endfunction

  // ------------------------------------------------------------
  // main logic
  // ------------------------------------------------------------

  logic       sign;
  logic [7:0] exp_f;
  logic [6:0] mant_f;
  logic [7:0] sig8;   // 1.mant as 8-bit integer
  int         E;      // unbiased exponent

  logic [7:0] N;      // numerator of fractional part
  int         s;      // denominator power-of-two: 2^s

  always_comb begin
    // unpack
    sign   = bf16_in[15];
    exp_f  = bf16_in[14:7];
    mant_f = bf16_in[6:0];

    // defaults
    int_u32   = 32'd0;
    frac_bf16 = 16'h0000;
    sig8      = 8'd0;
    E         = 0;
    N         = 8'd0;
    s         = 0;

    // only handle non-negative, normalized inputs to keep logic small
    if ((sign == 1'b1) || (exp_f == 8'd0)) begin
      int_u32   = 32'd0;
      frac_bf16 = 16'h0000;
    end else begin
      sig8 = {1'b1, mant_f};          // normalized significand (8 bits)
      E    = int'(exp_f) - 127;       // unbiased exponent

      if (E >= 7) begin
        // all bits contribute to integer → no fractional part
        // x = sig8 * 2^(E - 7)
        int_u32   = {24'b0, sig8} << (E - 7);
        frac_bf16 = 16'h0000;
      end
      else if (E >= 0) begin
        // 0 <= E <= 6 → mixed integer + fraction
        // x = sig8 * 2^(E - 7) = integer + N/2^s
        s       = 7 - E;                      // 1..7
        int_u32 = ({24'b0, sig8}) >> s;       // floor(x)

        // remainder N = sig8 & ((1<<s) - 1)
        N       = sig8 & ((8'h1 << s) - 1);

        frac_bf16 = fixed_frac_to_bf16(N, s);
      end
      else begin
        // E < 0 → 0 <= x < 1: integer part is 0, fraction is whole value
        int_u32 = 32'd0;

        // x = sig8 * 2^(E - 7) = sig8 / 2^s with s = 7 - E (>=8)
        s       = 7 - E;
        N       = sig8;

        frac_bf16 = fixed_frac_to_bf16(N, s);
      end
    end
  end

endmodule