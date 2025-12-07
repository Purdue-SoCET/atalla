// Assumes fp16_in is non-negative, normalized.
// int_u32 = floor(x)  (unsigned)
// frac_fp16 = fractional part in [0,1) as fp16
module fp16_to_bf16_int_frac (
  input  logic [15:0] fp16_in,
  output logic [31:0] int_u32,
  output logic [15:0] frac_fp16
);

  // MSB position for 11-bit value
  function automatic int msb_pos11 (input logic [10:0] x);
    begin
      unique casez (x)
        11'b1?????????? : msb_pos11 = 10;
        11'b01????????? : msb_pos11 = 9;
        11'b001???????? : msb_pos11 = 8;
        11'b0001??????? : msb_pos11 = 7;
        11'b00001?????? : msb_pos11 = 6;
        11'b000001????? : msb_pos11 = 5;
        11'b0000001???? : msb_pos11 = 4;
        11'b00000001??? : msb_pos11 = 3;
        11'b000000001?? : msb_pos11 = 2;
        11'b0000000001? : msb_pos11 = 1;
        11'b00000000001 : msb_pos11 = 0;
        default         : msb_pos11 = -1;
      endcase
    end
  endfunction

  // Convert fixed fraction N / 2^s (0 <= N < 2^s) into fp16
  function automatic logic [15:0] fixed_frac_to_fp16 (
    input logic [10:0] N,
    input int          s
  );
    logic [15:0] res;
    int          k;
    int          Efrac;
    logic [10:0] norm;
    logic [4:0]  exp_b;
    begin
      if ((N == 11'd0) || (s <= 0)) begin
        res = 16'h0000; // 0.0
      end else begin
        k     = msb_pos11(N);      // position of MSB in N
        Efrac = k - s;             // unbiased exponent

        // Smallest normal fp16 exponent = -14 (exp field = 1)
        if (Efrac < -14) begin
          res = 16'h0000;          // treat very small as 0 (ignore subnormals)
        end else begin
          // Normalize so MSB of N becomes bit 10 of "norm"
          norm  = N << (10 - k);   // now norm[10] = 1
          exp_b = 5'(Efrac + 15);  // bias = 15
          res   = {1'b0, exp_b, norm[9:0]}; // sign=0, exponent, mantissa
        end
      end
      fixed_frac_to_fp16 = res;
    end
  endfunction

  // fp16 fields
  logic       sign;
  logic [4:0] exp_f;
  logic [9:0] mant_f;

  // 11-bit significand (1.m)
  logic [10:0] sig11;

  int          E;   // unbiased exponent
  logic [10:0] N;
  int          s;

  always_comb begin
    sign   = fp16_in[15];
    exp_f  = fp16_in[14:10];
    mant_f = fp16_in[9:0];

    int_u32   = 32'd0;
    frac_fp16 = 16'h0000;
    sig11     = 11'd0;
    E         = 0;
    N         = 11'd0;
    s         = 0;

    // handle negative / zero / subnormal as 0 for now
    if (sign || (exp_f == 5'd0)) begin
      int_u32   = 32'd0;
      frac_fp16 = 16'h0000;
    end else begin
      sig11 = {1'b1, mant_f};        // 1.mmmm (11 bits)
      E     = int'(exp_f) - 15;      // unbiased exponent

      if (E >= 10) begin
        // All bits of sig11 go to the integer part (and more after shifting)
        int_u32   = {21'b0, sig11} << (E - 10);
        frac_fp16 = 16'h0000;
      end else if (E >= 0) begin
        // Integer and fractional parts both non-zero
        s         = 10 - E;                      // number of frac bits after binary point
        int_u32   = ({21'b0, sig11}) >> s;       // floor(x)
        N         = sig11 & ((11'h1 << s) - 1);  // remainder (lower s bits)
        frac_fp16 = fixed_frac_to_fp16(N, s);    // convert remainder/2^s to fp16
      end else begin
        // |x| < 1 → integer = 0, all in fractional part
        int_u32   = 32'd0;
        s         = 10 - E;                      // x = sig11 / 2^(10 - E)
        N         = sig11;
        frac_fp16 = fixed_frac_to_fp16(N, s);
      end
    end
  end
endmodule