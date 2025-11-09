`timescale 1ns/1ps
`default_nettype none

module wtm_bf16_tb;

  // ===== DUT ports =====
  logic [15:0] Ain, Bin;
  logic [15:0] Sum;
  logic [1:0]  Error;

  // ===== Instantiate DUT =====
  wtm_bf16 dut (
    .Ain(Ain),
    .Bin(Bin),
    .Sum(Sum),
    .Error(Error)
  );

  // ====== BF16 helpers ======
  // Format: [15]=sign, [14:7]=exp(8), [6:0]=frac(7)
  function automatic bit        bf16_is_nan    (input bit [15:0] x);
    bf16_is_nan = (x[14:7] == 8'hFF) && (x[6:0] != 7'd0);
  endfunction

  function automatic bit        bf16_is_inf    (input bit [15:0] x);
    bf16_is_inf = (x[14:7] == 8'hFF) && (x[6:0] == 7'd0);
  endfunction

  function automatic bit        bf16_is_zero   (input bit [15:0] x);
    bf16_is_zero = (x[14:7] == 8'h00) && (x[6:0] == 7'd0);
  endfunction

  // Convert BF16 -> shortreal by placing the 16 BF16 bits as MSBs of IEEE754 single
  function automatic shortreal  bf16_to_shortreal(input bit [15:0] x);
    bit [31:0] f32 = {x, 16'h0000};
    bf16_to_shortreal = $bitstoshortreal(f32);
  endfunction

  // Round-to-nearest, ties-to-even: IEEE754 single -> bfloat16
  function automatic bit [15:0] shortreal_to_bf16(input shortreal r);
    bit [31:0] f = $shortrealtobits(r);

    bit sign = f[31];
    bit [7:0] exp = f[30:23];
    bit [22:0] frac = f[22:0];

    // Pack to BF16 (keep top 7 frac bits) with RNE on the discarded 16 LSBs
    bit [15:0] upper = {sign, exp, frac[22:16]};   // tentative (no rounding)
    bit [15:0] lower = {frac[15:0]};               // to be rounded away

    // If NaN or Inf, just truncate payload (preserve signaling/quiet by MSB of frac)
    if (exp == 8'hFF) begin
      shortreal_to_bf16 = {sign, exp, (frac == 0) ? 7'd0 : {1'b1, 6'd0}}; // qNaN payload 0x40
      return;
    end

    // RNE: increment if (bit15==1) and (any lower bits set OR LSB of kept mantissa==1)
    bit guard = lower[15];
    bit round = |lower[14:1];
    bit lsb_kept = upper[0];
    bit inc = guard & (round | lsb_kept);

    bit [16:0] rounded = {1'b0, upper} + inc;

    // Handle mantissa overflow into exponent (rounded[16] carry or exp all ones)
    if (rounded[16]) begin
      // Carry into exponent; BF16 mantissa becomes 0, exponent increments
      bit [7:0] exp_inc = exp + 8'd1;
      if (exp_inc == 8'hFF) begin
        shortreal_to_bf16 = {sign, 8'hFF, 7'd0}; // overflow -> Inf
      end else begin
        shortreal_to_bf16 = {sign, exp_inc, 7'd0};
      end
    end else begin
      shortreal_to_bf16 = rounded[15:0];
    end
  endfunction

  // Reference multiply (software model): A*B in shortreal, convert back to BF16
  function automatic bit [15:0] bf16_mul_ref(input bit [15:0] a, input bit [15:0] b);
    shortreal ra = bf16_to_shortreal(a);
    shortreal rb = bf16_to_shortreal(b);
    shortreal rr = ra * rb;

    // Handle NaN rules similar to IEEE:
    // If either is NaN -> NaN
    if (bf16_is_nan(a) || bf16_is_nan(b)) return 16'h7FC0; // qNaN

    // Inf * 0 -> NaN
    if ((bf16_is_inf(a) && bf16_is_zero(b)) || (bf16_is_inf(b) && bf16_is_zero(a))) return 16'h7FC0;

    // Otherwise convert real result
    return shortreal_to_bf16(rr);
  endfunction

  // ===== Stimulus task (similar to your FP16 TB) =====
  task automatic run_test(input bit [15:0] a, input bit [15:0] b, string name);
    bit [15:0] refS;
    begin
      A = a; B = b;
      #5; // wait for propagation
      refS = bf16_mul_ref(a, b);

      // Compare (tolerate any NaN payload mismatch: NaN ~ NaN)
      bit pass;
      if (bf16_is_nan(refS) && bf16_is_nan(S)) pass = 1'b1;
      else pass = (S === refS);

      $display("[%s] A=0x%h, B=0x%h -> S=0x%h, E=%0d  | ref=0x%h  %s",
               name, A, B, S, E, refS, pass ? "PASS" : "FAIL");

      if (!pass) begin
        $error("Mismatch for '%s': DUT S=0x%h, REF=0x%h", name, S, refS);
      end
    end
  endtask

  // ===== Constants (BF16 encodings) =====
  localparam bit [15:0]
    BF16_PZERO = 16'h0000,     // +0
    BF16_NZERO = 16'h8000,     // -0
    BF16_ONE   = 16'h3F80,     // +1.0
    BF16_TWO   = 16'h4000,     // +2.0
    BF16_MONE  = 16'hBF80,     // -1.0
    BF16_INF   = 16'h7F80,     // +Inf
    BF16_NINF  = 16'hFF80,     // -Inf
    BF16_QNAN  = 16'h7FC0,     // qNaN
    BF16_TINY  = 16'h0001;     // smallest subnormal > 0

  // ===== Test sequence =====
  initial begin
    void'($mkdir("waves"));
    $dumpfile("waves/wtm_bf16.vcd");
    $dumpvars(0, wtm_bf16_tb);
    $display("=== Wallace Tree BF16 Multiplier Testbench ===");

    // Basic directed tests (mirroring your FP16 style)
    run_test(BF16_PZERO, BF16_ONE,  "Zero * 1.0");
    run_test(BF16_ONE,   BF16_ONE,  "1.0 * 1.0");
    run_test(BF16_TWO,   BF16_TWO,  "2.0 * 2.0");
    run_test(BF16_MONE,  BF16_TWO,  "-1.0 * 2.0");
    run_test(BF16_ONE,   16'h4080,  "1.0 * 4.0"); // 4.0 = 0x4080

    // Edge cases
    run_test(BF16_INF,   BF16_ONE,  "Inf * 1.0");
    run_test(BF16_INF,   BF16_INF,  "Inf * Inf");
    run_test(BF16_QNAN,  BF16_ONE,  "NaN * 1.0");
    run_test(BF16_QNAN,  BF16_QNAN, "NaN * NaN");
    run_test(BF16_TINY,  BF16_ONE,  "Denormal * 1.0");
    run_test(BF16_INF,   BF16_PZERO,"Inf * 0.0 (NaN)");
    run_test(BF16_NINF,  BF16_PZERO,"-Inf * 0.0 (NaN)");

    // Overflow case (large * large -> Inf)
    run_test(16'h7F7F, 16'h7F7F, "Max finite * Max finite (likely overflow)");

    // Underflow-ish / small products
    run_test(BF16_TINY, BF16_TINY, "Tiny * Tiny");

    // Mixed sign and random sweeps
    run_test(BF16_NZERO, BF16_ONE, "(-0) * 1.0");
    run_test(16'h3F00, 16'h3F00,  "0.5 * 0.5"); // 0.5 = 0x3F00 in BF16

    // Random regression (skips signaling NaN patterns by construction here)
    for (int i = 0; i < 200; i++) begin
      bit [15:0] ra, rb;
      ra = {$urandom, $urandom} >> 16;
      rb = {$urandom, $urandom} >> 16;

      // Lightly bias to include zeros/inf sometimes
      if ((i % 25) == 0) ra = BF16_PZERO;
      if ((i % 40) == 0) rb = BF16_INF;

      run_test(ra, rb, $sformatf("rand_%0d", i));
    end

    $display("=== Testbench complete ===");
    $finish;
  end

endmodule
