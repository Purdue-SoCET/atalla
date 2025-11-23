// Assumes bf16_in is non-negative, normalized.
// int_u32 = floor(x)  (unsigned)
// frac_bf16 = fractional part in [0,1) as bf16
module bf16_to_int_frac (
  input  logic [15:0] bf16_in,
  output logic [31:0] int_u32,
  output logic [15:0] frac_bf16
);

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
        default:      msb_pos8 = -1;
      endcase
    end
  endfunction

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
      if ((N == 8'd0) || (s <= 0)) begin
        res = 16'h0000;
      end else begin
        k     = msb_pos8(N);
        Efrac = k - s;
        if (Efrac < -126) begin
          res = 16'h0000;
        end else begin
          norm  = N << (7 - k);
          exp_b = 8'(Efrac + 127);
          res   = {1'b0, exp_b, norm[6:0]};
        end
      end
      fixed_frac_to_bf16 = res;
    end
  endfunction

  logic       sign;
  logic [7:0] exp_f;
  logic [6:0] mant_f;
  logic [7:0] sig8;
  int         E;
  logic [7:0] N;
  int         s;

  always_comb begin
    sign   = bf16_in[15];
    exp_f  = bf16_in[14:7];
    mant_f = bf16_in[6:0];

    int_u32   = 32'd0;
    frac_bf16 = 16'h0000;
    sig8      = 8'd0;
    E         = 0;
    N         = 8'd0;
    s         = 0;

    // handle negative / zero / subnormal as 0 for now
    if (sign || (exp_f == 8'd0)) begin
      int_u32   = 32'd0;
      frac_bf16 = 16'h0000;
    end else begin
      sig8 = {1'b1, mant_f};
      E    = int'(exp_f) - 127;

      if (E >= 7) begin
        int_u32   = {24'b0, sig8} << (E - 7);
        frac_bf16 = 16'h0000;
      end else if (E >= 0) begin
        s         = 7 - E;
        int_u32   = ({24'b0, sig8}) >> s;
        N         = sig8 & ((8'h1 << s) - 1);
        frac_bf16 = fixed_frac_to_bf16(N, s);
      end else begin
        int_u32   = 32'd0;
        s         = 7 - E;
        N         = sig8;
        frac_bf16 = fixed_frac_to_bf16(N, s);
      end
    end
  end
endmodule