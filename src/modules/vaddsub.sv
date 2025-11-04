`include "vector_types.vh"
`include "vector_if.vh"
`include "vaddsub_if.vh"

module vaddsub(
  input  logic              CLK, 
  input  logic              nRST,
  vaddsub_if.vaddsub        vaddsubif 
);

  import vector_pkg::*;


  //Format Selection
  localparam int EXP_W  = 8;
  localparam int FRAC_W = 7;

  // Derived Parameters
  localparam int SIG_W   = FRAC_W + 1;
  localparam int GRS_W   = 3;
  localparam int EXT_W   = SIG_W + GRS_W;
  localparam int SUM_W_VAL = EXT_W + 1;                  // compile-time constant for widths
  localparam int SHL_W   = ($clog2(SUM_W_VAL) + 1);
  localparam int RAMT_W  = $clog2(SUM_W_VAL + 1);        // width to hold 0..SUM_W_VAL

  // Small Run Time Signal instead of SUM_W Parameter
  logic [RAMT_W-1:0] SUM_W_SIG; 
  assign SUM_W_SIG = SUM_W_VAL[RAMT_W-1:0];

  // Stage 1 temps
  logic [SIG_W-1:0] m1, m2;
  logic [EXT_W-1:0] M1, M2;
  logic [EXP_W-1:0] e1, e2;
  logic             swap;
  logic [EXP_W-1:0] eA, eB;
  logic [EXT_W-1:0] MA, MB;
  logic             sA, sB;
  logic [EXP_W-1:0] ediff;
  logic             stickyB;
  logic [EXT_W-1:0] MBs;
  logic [SUM_W_VAL-1:0] Aext, Bext;   // uses SUM_W_VAL
  logic             add_op;

  // Stage 2 temps
  logic [SUM_W_VAL-1:0] mag, norm;    // uses SUM_W_VAL
  logic [EXP_W-1:0] exp_r, exp_n;
  logic             carry;
  logic             tail;
  logic [$clog2(SUM_W_VAL+1)-1:0] lz;     // uses SUM_W_VAL
  logic [$clog2(SUM_W_VAL)-1:0]   target; // uses SUM_W_VAL
  logic [$clog2(SUM_W_VAL)-1:0]   msb;    // uses SUM_W_VAL
  logic signed [SHL_W-1:0]        shl;    // signed shift distance
  logic [RAMT_W-1:0]              r_amt;  // shift right amount (unsigned)
  logic [SIG_W-1:0]               sig11;
  logic                           guard, round, sticky;
  logic                           carry_up;
  logic [SIG_W-1:0]               sig_rnd;
  logic [EXP_W-1:0]               exp_post;
  logic [SIG_W-1:0]               sig_post;
  logic [FRAC_W-1:0]              subf;

  // shl expanded to exponent width (zero-extend or truncate)
  logic [EXP_W-1:0] shl_exp;
  generate
    if (EXP_W >= SHL_W) begin
      assign shl_exp = {{(EXP_W-SHL_W){1'b0}}, $unsigned(shl)};
    end else begin
      assign shl_exp = $unsigned(shl[EXP_W-1:0]);
    end
  endgenerate

  // Raw 16-bit lanes (works for both fp16 and bf16 bit layouts)
  logic [15:0] a;  
  logic [15:0] b;  
  assign a = vaddsubif.port_a;
  assign b = vaddsubif.port_b;
    
  localparam int TOTAL_W = 16;

  // Bitfield helpers (generic with EXP_W/FRAC_W)
  function automatic logic                 get_sign(input logic [TOTAL_W-1:0] x); return x[TOTAL_W-1]; endfunction
  function automatic logic [EXP_W-1:0]     get_exp (input logic [TOTAL_W-1:0] x); return x[FRAC_W+EXP_W-1 -: EXP_W]; endfunction
  function automatic logic [FRAC_W-1:0]    get_frac(input logic [TOTAL_W-1:0] x); return x[FRAC_W-1:0]; endfunction

  logic sign_a, sign_b;
  assign sign_a = get_sign(a);
  assign sign_b = vaddsubif.sub ? ~get_sign(b) : get_sign(b);

  // Helper Functions
  localparam logic [EXP_W-1:0] EXP_ALL1 = {EXP_W{1'b1}};
  function automatic bit is_nan (input logic [15:0] x); return (get_exp(x)==EXP_ALL1) && (get_frac(x)!='0); endfunction
  function automatic bit is_inf (input logic [15:0] x); return (get_exp(x)==EXP_ALL1) && (get_frac(x)=='0); endfunction
  function automatic bit is_zero(input logic [15:0] x); return (get_exp(x)=='0)       && (get_frac(x)=='0); endfunction
  function automatic bit is_sub (input logic [15:0] x); return (get_exp(x)=='0)       && (get_frac(x)!='0); endfunction

  // DAZ: subnormals act as zero
  function automatic logic [EXP_W-1:0] eff_exp(input logic [15:0] x); return (get_exp(x)=='0) ? '0 : get_exp(x); endfunction
  function automatic logic [SIG_W-1:0] make_sig(input logic [15:0] x);
    if (is_zero(x) || is_sub(x)) return '0;
    else                         return {1'b1, get_frac(x)};
  endfunction

  // Right-shift with sticky (no variable part-selects inside)
  function automatic logic [EXT_W-1:0]
    rshift_sticky(input logic [EXT_W-1:0] x, input logic [EXP_W-1:0] shamt, output logic sticky);
    logic [EXT_W-1:0] y;
    logic [EXT_W-1:0] mask;
    if (shamt == 0) begin
      y      = x;
      sticky = 1'b0;
    end else if (shamt >= EXT_W) begin
      y      = '0;
      sticky = |x;
    end else begin
      y      = x >> shamt;
      mask   = {EXT_W{1'b1}} >> (EXT_W - shamt);
      sticky = |(x & mask);
    end
    return y;
  endfunction

  // LZC over SUM_W_VAL
  function automatic logic [$clog2(SUM_W_VAL+1)-1:0] lzc (input logic [SUM_W_VAL-1:0] x);
    logic found;
    lzc   = SUM_W_VAL[$clog2(SUM_W_VAL+1)-1:0];
    found = 1'b0;
    for (int i = SUM_W_VAL-1; i >= 0; i--) begin
      if (!found && x[i]) begin
        lzc   = (SUM_W_VAL-1) - i;
        found = 1'b1;
      end
    end
  endfunction

  function automatic logic [SIG_W-1:0]
    round_rne(input logic [SIG_W-1:0] sig, input logic g, input logic r, input logic s, output logic carry_o);
    logic inc = g & (r | s | sig[0]);   // ties-to-even
    {carry_o, round_rne} = sig + inc;
  endfunction

  function automatic logic or_lower_bits
    (input logic [SUM_W_VAL-1:0] x, input logic [RAMT_W-1:0] n);
    logic acc;
    acc = 1'b0;
  // OR-reduce bits x[0 .. n-1] without variable-width part-selects
    for (int i = 0; i < SUM_W_VAL; i++) begin
      if (i < n) acc |= x[i];
    end
    return acc;
  endfunction

  // Pipeline Valid Signals
  logic s1_v, s2_v;

  // Stage 1 Registers
  logic             s1_special;
  logic [15:0]      s1_special_res;
  logic [SUM_W_VAL-1:0] s1_mag;
  logic [EXP_W-1:0] s1_exp_r;
  logic             s1_sign_r;

  // Stage 1: Next
  logic             s1n_special;
  logic [15:0]      s1n_special_res;
  logic [SUM_W_VAL-1:0] s1n_mag;
  logic [EXP_W-1:0] s1n_exp_r;
  logic             s1n_sign_r;

  // Special Case Handling
  always_comb begin
    s1n_special     = 1'b0;
    s1n_special_res = '0;
    if (is_nan(a) || is_nan(b)) begin
      s1n_special     = 1'b1;
      s1n_special_res = {1'b0, EXP_ALL1, {1'b1, {(FRAC_W-1){1'b0}}}}; // qNaN
    end else if (is_inf(a) && is_inf(b)) begin
      if (sign_a ^ sign_b) begin
        s1n_special     = 1'b1;
        s1n_special_res = {1'b0, EXP_ALL1, {1'b1, {(FRAC_W-1){1'b0}}}}; // NaN
      end else begin
        s1n_special     = 1'b1;
        s1n_special_res = {sign_a, EXP_ALL1, {FRAC_W{1'b0}}}; // ±Inf
      end
    end else if (is_inf(a)) begin
      s1n_special     = 1'b1;
      s1n_special_res = {sign_a, EXP_ALL1, {FRAC_W{1'b0}}};
    end else if (is_inf(b)) begin
      s1n_special     = 1'b1;
      s1n_special_res = {sign_b, EXP_ALL1, {FRAC_W{1'b0}}};
    end
  end

  // Magnitude Compare and Alignment
  always_comb begin
    s1n_mag    = '0;
    s1n_exp_r  = '0;
    s1n_sign_r = 1'b0;

    m1='0; m2='0; M1='0; M2='0;
    e1='0; e2='0; eA='0; eB='0; ediff='0;
    MA='0; MB='0; MBs='0;
    swap=1'b0; sA=1'b0; sB=1'b0; stickyB=1'b0;
    Aext='0; Bext='0; add_op=1'b0;

    if (!s1n_special) begin
      m1 = make_sig(a);
      m2 = make_sig(b);
      M1 = {m1,{GRS_W{1'b0}}};
      M2 = {m2,{GRS_W{1'b0}}};

      e1 = eff_exp(a);
      e2 = eff_exp(b);

      swap = (e2 > e1) || ((e2 == e1) && (m2 > m1));

      eA = swap ? e2 : e1;
      eB = swap ? e1 : e2;
      MA = swap ? M2 : M1;
      MB = swap ? M1 : M2;
      sA = swap ? sign_b : sign_a;
      sB = swap ? sign_a : sign_b;

      ediff = eA - eB;
      MBs   = rshift_sticky(MB, ediff, stickyB);
      MBs[0]= MBs[0] | stickyB;

      Aext   = {1'b0, MA};
      Bext   = {1'b0, MBs};
      add_op = (sA == sB);

      s1n_mag    = add_op ? (Aext + Bext) : (Aext - Bext);
      s1n_exp_r  = eA;
      s1n_sign_r = sA;
    end
  end

  // Register Stage 1 Outputs
  always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
      s1_v           <= '0;
      s1_special     <= '0;      
      s1_special_res <= '0;
      s1_mag         <= '0;             
      s1_exp_r       <= '0;             
      s1_sign_r      <= '0;
    end else begin
      s1_v           <= vaddsubif.enable;
      s1_special     <= s1n_special;
      s1_special_res <= s1n_special_res;
      s1_mag         <= s1n_mag;
      s1_exp_r       <= s1n_exp_r;
      s1_sign_r      <= s1n_sign_r;
    end
  end

  // Stage 2: Normalize, Round, and Pack
  logic [15:0] s2_out;
  logic        s2_ovf;
  logic [15:0] s2n_out; 
  logic        s2n_ovf;

  always_comb begin
    s2n_out = '0;
    s2n_ovf = 1'b0;

    if (s1_special || !s1_v) begin
      s2n_out = s1_special ? s1_special_res : '0;
    end else if (s1_mag == '0) begin
      s2n_out = {1'b0, {EXP_W{1'b0}}, {FRAC_W{1'b0}}}; // +0
    end else begin
      mag   = s1_mag;
      exp_r = s1_exp_r;
      norm  = '0;
      exp_n = '0;

      carry = mag[SUM_W_VAL-1];
      if (carry) begin
        tail  = mag[0];
        norm  = mag >> 1;
        norm[0] = norm[0] | tail;
        exp_n = exp_r + 1;
      end else begin
        lz     = lzc(mag);
        target = SIG_W + GRS_W - 1;
        msb    = (SUM_W_VAL-1) - lz;
        shl    = $signed({1'b0, target}) - $signed({1'b0, msb});

        if (shl > 0) begin
          norm  = mag << shl;
          exp_n = (exp_r > shl_exp) ? (exp_r - shl_exp) : '0;
        end else if (shl < 0) begin
          r_amt = $unsigned(-shl);
          norm  = mag >> r_amt;

          // Tail without wide masks, using small SUM_W_SIG
          if (r_amt >= SUM_W_SIG) begin
            tail = |mag;
          end else begin
            tail = (r_amt != '0) ? or_lower_bits(mag, r_amt) : 1'b0;
          end

          norm[0] = norm[0] | tail;
          exp_n   = exp_r + r_amt;
        end else begin
          norm  = mag;
          exp_n = exp_r;
        end
      end

      sig11  = norm[GRS_W +: SIG_W];
      guard  = norm[2];
      round  = norm[1];
      sticky = norm[0];

      carry_up = 1'b0;
      sig_rnd  = round_rne(sig11, guard, round, sticky, carry_up);

      exp_post = exp_n + (carry_up ? 1 : 0);
      sig_post = carry_up ? {1'b1, {FRAC_W{1'b0}}} : sig_rnd;

      if (exp_post >= EXP_ALL1) begin
        s2n_out = {s1_sign_r, EXP_ALL1, {FRAC_W{1'b0}}}; // ±Inf
        s2n_ovf = 1'b1;
      end else if (exp_post == '0) begin
        // FTZ
        s2n_out = {s1_sign_r, {EXP_W{1'b0}}, {FRAC_W{1'b0}}};
        s2n_ovf = 1'b0;
      end else begin
        s2n_out = {s1_sign_r, exp_post, sig_post[FRAC_W-1:0]};
        s2n_ovf = 1'b0;
      end
    end
  end

  // Register Stage 2 Outputs (final)
  always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
      s2_v   <= 1'b0;
      s2_out <= '0;
      s2_ovf <= 1'b0;
    end else begin
      s2_v   <= s1_v;
      s2_out <= s2n_out;
      s2_ovf <= s2n_ovf;
    end
  end

  // Final Outputs
  assign vaddsubif.out      = s2_v ? s2_out : 16'b0;
  assign vaddsubif.overflow = s2_v ? s2_ovf : 1'b0;

endmodule