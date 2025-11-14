// bfloat16 input: [15]=sign, [14:7]=exp (bias=127), [6:0]=mant
// Outputs: integer as 32-bit uint, fractional part as fp16
module bf16_to_int_frac (
  input  logic [15:0] bf16_in,
  output logic [31:0] int_u32,
  output logic [15:0] frac_fp16
);

  // ---- small leading-zero counter for up-to-7-bit values ----
  function automatic logic [2:0] lzc7(input logic [6:0] x);
    casez (x)
      7'b1??????: lzc7 = 3'd0;
      7'b01?????: lzc7 = 3'd1;
      7'b001????: lzc7 = 3'd2;
      7'b0001???: lzc7 = 3'd3;
      7'b00001??: lzc7 = 3'd4;
      7'b000001?: lzc7 = 3'd5;
      7'b0000001: lzc7 = 3'd6;
      default:     lzc7 = 3'd7; // x==0
    endcase
  endfunction

  // ---- unpack bf16 ----
  logic [7:0] exp_f;
  logic [6:0] mant_f;
  logic [7:0] sig8;      // 1.mant (8 bits)
  integer     E;         // unbiased exponent

  always_comb begin
    exp_f = bf16_in[14:7];
    mant_f= bf16_in[6:0];
    sig8  = {1'b1, mant_f};        // normalized only (assumed)
    E     = integer'(exp_f) - 127;
  end

  // ---- split into integer + remainder (fixed-point) ----
  logic [6:0] rem7;      // remainder bits (≤7 bits when E>=0)
  logic [2:0] rem_len;   // number of valid bits in rem7 (1..7), or 0 when none
  integer     s;         // denominator power for the remainder: 2^s

  always_comb begin
    if (E >= 7) begin
      // all fractional bits shifted out → purely integer
      int_u32 = {24'b0, sig8} << (E - 7);
      rem7    = 7'd0;
      rem_len = 3'd0;
      s       = 0;
    end else if (E >= 0) begin
      s       = 7 - E;                     // 1..7
      int_u32 = ({24'b0, sig8}) >> s;
      // remainder = lower s bits of sig8 (width up to 7)
      rem7    = (s < 7) ? {sig8[s-1:0], {(7-s){1'b0}}} : sig8[6:0];
      // compute significant-bit length b for rem7
      rem_len = (rem7 == 0) ? 3'd0 : (3'(7) - lzc7(rem7)); // b in 1..7
    end else begin
      // 0 <= x < 1 → integer=0; fraction uses the whole significand
      int_u32 = 32'd0;
      s       = 7 - E;                     // ≥8
      // use all 8 bits of sig8 as the numerator; store top 7 into rem7 and note b=8
      rem7    = sig8[6:0];                 // lower 7 bits (MSB=1 sits in sig8[7])
      rem_len = 3'd7;                      // we'll treat b=8 explicitly below
    end
  end

  // ---- pack fractional part into fp16 (no subnormals; drop to 0 if needed) ----
  always_comb begin
    if ((E >= 7) || ((E >= 0) && (rem_len == 0))) begin
      // no fractional part
      frac_fp16 = 16'h0000;
    end else begin
      // Determine numerator bit-length b and the raw remainder bits R
      // Case A: E >= 0 → R has rem_len (1..7) bits significant, b=rem_len, value = R / 2^s
      // Case B: E < 0  → use the full 8-bit sig8 as numerator, b=8, value = sig8 / 2^s
      int  b;
      logic [10:0] Rext;  // R left-extended to align MSB to bit (b-1)
      if (E >= 0) begin
        b    = rem_len;                         // 1..7
        Rext = { { (11-7){1'b0} }, rem7 };      // rem7 in lower 7 bits
        // shift left so MSB of R lands at position (b-1)
        if (b < 7) Rext = Rext << (7 - b);
      end else begin
        b    = 8;                               // full sig8 precision
        Rext = { { (11-8){1'b0} }, sig8 };      // put 8-bit numerator
      end

      // True exponent for the fractional value:
      // value = (R / 2^(b-1)) * 2^(b-1 - s)  with hidden-1 normalization
      // Efrac = b - s - 1
      int Efrac = b - s - 1;

      // fp16 normalized if Efrac >= -14
      if (Efrac < -14) begin
        frac_fp16 = 16'h0000;                   // would be subnormal → 0
      end else begin
        // Build fp16 significand: place MSB of R at bit10 => shift left by (11 - b)
        logic [10:0] sig11 = Rext << (11 - b);  // b in {1..8}
        logic [4:0]  exp16 = 5'((Efrac + 15));  // stored exponent
        frac_fp16 = {1'b0, exp16, sig11[9:0]};  // truncate (no rounding)
      end
    end
  end

endmodule
