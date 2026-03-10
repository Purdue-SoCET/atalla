`include "div_if.vh"

module div_pipeline_bf16 (
    input logic CLK, nRST,
    div_if.dvif divif
);
  // 6k Area for multiplier and sub
  // PARAMETERS AND TYPES
  localparam [7:0] BIAS = 8'h7F;
  localparam [7:0] EXP_INF = 8'hFF;
  localparam [15:0] TWO = 16'h4000;
  localparam [15:0] qNaN = 16'h7FC0; // NaN

    // Pipeline Structs
  typedef struct packed{
    logic sign, is_special, valid, is_sub_bound;
    logic [9:0] exp;
    logic [15:0] special_result;
  } mul1_t;

  typedef struct packed{
    logic sign, is_special, valid, is_sub_bound;
    logic [9:0] exp;
    logic [15:0] muln, muld, special_result;
  } sub_t;

  typedef struct packed{
    logic sign, is_special, valid, is_sub_bound;
    logic [9:0] exp;
    logic [15:0] muln, special_result;
  } mul2_t;

  typedef struct packed{
    logic valid;
    logic [15:0] fin;
  } fin_t;

// SIGNAL DECLARATIONS
  // Pipeline Signals
  mul1_t mul1Tfin1, n_mul1Tfin1, mul2Tfin3, n_mul2Tfin3;
  sub_t fin1Tsub1, n_fin1Tsub1, fin2Tmul2, n_fin2Tmul2;
  mul2_t sub1Tsub2, n_sub1Tsub2, sub2Tfin2, n_sub2Tfin2, fin3Texp, n_fin3Texp;
  fin_t expTout, n_expTout;

  // Mult and Sub signals
  logic [15:0] muln, muld, mulfin, f_1, f_2;
  logic [15:0] outn, outd, outfin;
  logic [15:0] subd, subout;
  logic startd, startfin, startsub;
  logic donen, doned, donefin;

  // Math Signals
  logic sign;
  logic [15:0] fin, result;
  logic signed [9:0] raw_exp, exp_diff;
  logic [7:0] final_exp;
  logic is_subnormal_boundary;

  // Pipeline Signals
  logic [7:0] pipe_en, flush;

  // Edge case flags
  logic op1_is_zero, op1_is_inf, op1_is_nan;
  logic op2_is_zero, op2_is_inf, op2_is_nan;
  logic op1_op2_same, op2_is_one;
  logic is_special;
  logic [15:0] special_result;

// MODULE INSTANTIATIONS
  mul_bf16 mul_numerator (
    .clk(CLK), 
    .nRST(nRST),
    .start(startn), 
    .a(muln), 
    .b(f_1),
    .result(outn), 
    .done(donen), 
    .mul_ovf(),
    .mul_unf()
  );

  mul_bf16 mul_denominator (
    .clk(CLK), 
    .nRST(nRST),
    .start(startd),
    .a(muld), 
    .b(f_1),
    .result(outd), 
    .done(doned), 
    .mul_ovf(),
    .mul_unf()
  );

  addsub_bf16 sub (
    .clk(CLK),
    .nRST(nRST), 
    .bf1_in(TWO),
    .bf2_in(subd),
    .op(1'b1), 
    .start(startsub),
    .stall(!pipe_en[1]),
    .bf_out(subout), 
    .overflow(),
    .underflow(),
    .invalid()
  );

  mul_bf16 mul_final (
    .clk(CLK), 
    .nRST(nRST),
    .start(startfin), 
    .a(mulfin), 
    .b(f_2),
    .result(outfin), 
    .done(donefin), 
    .mul_ovf(),
    .mul_unf()
  );
  
  // Pipeline Signals
  assign pipe_en = !divif.in.ready_out && divif.out.valid_out || !nRST ? 8'h00 : 8'hFF;
  assign flush = !nRST;
  assign divif.out.ready_in = pipe_en ? nRST:0;
  assign divif.out.valid_out = expTout.valid;

  // Mantissa Normalization
  assign muln = (divif.in.operand1[14:7] == 8'h00) ? 16'h8000 : {1'b0, BIAS, divif.in.operand1[6:0]};
  assign muld = (divif.in.operand2[14:7] == 8'h00) ? 16'h8000 : {1'b0, BIAS, divif.in.operand2[6:0]};
  assign f_1 = 16'h7EF3 - muld;

  // Exponent Calculation
  assign exp_diff = {2'b00, divif.in.operand1[14:7]} - {2'b00, divif.in.operand2[14:7]};
  assign is_subnormal_boundary = (exp_diff == -10'sd126) && (divif.in.operand1[6:0] < divif.in.operand2[6:0]);

  // Edge case detection
  assign op1_is_zero = (divif.in.operand1[14:7] == 15'h0000);
  assign op2_is_zero = (divif.in.operand2[14:7] == 15'h0000);
  assign op1_is_inf = (divif.in.operand1[14:7] == 8'hFF) && (divif.in.operand1[6:0] == 7'h00);
  assign op2_is_inf = (divif.in.operand2[14:7] == 8'hFF) && (divif.in.operand2[6:0] == 7'h00);
  assign op1_is_nan = (divif.in.operand1[14:7] == 8'hFF) && (divif.in.operand1[6:0] != 7'h00);
  assign op2_is_nan = (divif.in.operand2[14:7] == 8'hFF) && (divif.in.operand2[6:0] != 7'h00);
  assign op1_op2_same = divif.in.operand1[14:0] == divif.in.operand2[14:0];
  assign op2_is_one = divif.in.operand2[14:0] == 15'h3F80;

  // Sign Calculation
  assign sign = divif.in.operand1[15] ^ divif.in.operand2[15];

// COMBINATIONAL LOGIC EDGE CASES
  always_comb begin : edge_cases
    is_special = 1;
    special_result = {16'h0000};
    // NaN Propagation
    if(op1_is_nan || op2_is_nan)                                        special_result = qNaN;
    // 0 / 0 or Inf / Inf -> NaN
    else if((op1_is_zero && op2_is_zero) || (op1_is_inf && op2_is_inf)) special_result = qNaN;
    // N / 0 -> Infinity
    else if(op2_is_zero)                                                special_result = {sign, 8'hFF, 7'h00};
    // N / Inf -> Zero
    else if(op2_is_inf)                                                 special_result = {sign, 15'h0000};
    // 0 / N -> Zero
    else if(op1_is_zero)                                                special_result = {sign, 15'h0000};
    // Inf / N -> Infinity
    else if(op1_is_inf)                                                 special_result = {sign, 8'hFF, 7'h00};
    // N / N -> 1
    else if(op1_op2_same & !op2_is_zero)                                special_result = {sign, 15'h3F80};
    // N / 1 -> N
    else if(op2_is_one)                                                 special_result = {sign, divif.in.operand1[14:0]};
    // Not a special case, proceed with Goldschmidt
    else is_special = 0;
  end

  assign startn = divif.in.valid_in && !is_special && pipe_en[0];
  assign startd = divif.in.valid_in && !is_special && pipe_en[0];

  always_comb begin
    n_mul1Tfin1 = mul1Tfin1;
    if(flush[0]) n_mul1Tfin1 = '0;
    else if(pipe_en[0]) begin
      n_mul1Tfin1.sign           = sign;
      n_mul1Tfin1.is_special     = is_special;
      n_mul1Tfin1.valid          = divif.in.valid_in;
      n_mul1Tfin1.is_sub_bound   = is_subnormal_boundary;
      n_mul1Tfin1.exp            = exp_diff;
      n_mul1Tfin1.special_result = special_result;
    end
  end

// *********************************************************************************************
// MUL1 to FIN1
// *********************************************************************************************
  always_comb begin
    n_fin1Tsub1 = fin1Tsub1;
    if(flush[1]) n_fin1Tsub1 = '0;
    else if(pipe_en[1]) begin
      n_fin1Tsub1.sign           = mul1Tfin1.sign;
      n_fin1Tsub1.is_special     = mul1Tfin1.is_special;
      n_fin1Tsub1.valid          = mul1Tfin1.valid;
      n_fin1Tsub1.is_sub_bound   = mul1Tfin1.is_sub_bound;
      n_fin1Tsub1.exp            = mul1Tfin1.exp;
      n_fin1Tsub1.muln           = outn;
      n_fin1Tsub1.muld           = outd;
      n_fin1Tsub1.special_result = mul1Tfin1.special_result;
    end
  end

// *********************************************************************************************
// FIN1 to SUB1
// *********************************************************************************************
  assign startsub = !fin1Tsub1.is_special && fin1Tsub1.valid && pipe_en[2];
  assign subd = fin1Tsub1.valid && !fin1Tsub1.is_special ? fin1Tsub1.muld:'0;
  always_comb begin
    n_sub1Tsub2 = sub1Tsub2;
    if(flush[2]) n_sub1Tsub2 = '0;
    else if(pipe_en[2]) begin
      n_sub1Tsub2.sign           = fin1Tsub1.sign;
      n_sub1Tsub2.is_special     = fin1Tsub1.is_special;
      n_sub1Tsub2.valid          = fin1Tsub1.valid;
      n_sub1Tsub2.is_sub_bound   = fin1Tsub1.is_sub_bound;
      n_sub1Tsub2.exp            = fin1Tsub1.exp;
      n_sub1Tsub2.muln           = fin1Tsub1.muln;
      n_sub1Tsub2.special_result = fin1Tsub1.special_result;
    end
  end

// *********************************************************************************************
// SUB1 to SUB2
// *********************************************************************************************
  always_comb begin
    n_sub2Tfin2 = sub2Tfin2;
    if(flush[3]) n_sub2Tfin2 = '0;
    else if(pipe_en[3]) begin
      n_sub2Tfin2.sign           = sub1Tsub2.sign;
      n_sub2Tfin2.is_special     = sub1Tsub2.is_special;
      n_sub2Tfin2.valid          = sub1Tsub2.valid;
      n_sub2Tfin2.is_sub_bound   = sub1Tsub2.is_sub_bound;
      n_sub2Tfin2.exp            = sub1Tsub2.exp;
      n_sub2Tfin2.muln           = sub1Tsub2.muln;
      n_sub2Tfin2.special_result = sub1Tsub2.special_result;
    end
  end

// *********************************************************************************************
// SUB2 to FIN2
// *********************************************************************************************
  always_comb begin
    n_fin2Tmul2 = fin2Tmul2;
    if(flush[4]) n_fin2Tmul2 = '0;
    else if(pipe_en[4]) begin
      n_fin2Tmul2.sign           = sub2Tfin2.sign;
      n_fin2Tmul2.is_special     = sub2Tfin2.is_special;
      n_fin2Tmul2.valid          = sub2Tfin2.valid;
      n_fin2Tmul2.is_sub_bound   = sub2Tfin2.is_sub_bound;
      n_fin2Tmul2.exp            = sub2Tfin2.exp;
      n_fin2Tmul2.muln           = sub2Tfin2.muln;
      n_fin2Tmul2.muld           = subout; 
      n_fin2Tmul2.special_result = sub2Tfin2.special_result;
    end
  end

// *********************************************************************************************
// FIN2 to MUL2
// *********************************************************************************************
  assign startfin = !fin2Tmul2.is_special && fin2Tmul2.valid && pipe_en[5];
  assign mulfin = !fin2Tmul2.is_special && fin2Tmul2.valid ? fin2Tmul2.muln:'0;
  assign f_2 = !fin2Tmul2.is_special && fin2Tmul2.valid ? fin2Tmul2.muld:'0;
  always_comb begin
    n_mul2Tfin3 = mul2Tfin3;
    if(flush[5]) n_mul2Tfin3 = '0;
    else if(pipe_en[5]) begin
      n_mul2Tfin3.sign           = fin2Tmul2.sign;
      n_mul2Tfin3.is_special     = fin2Tmul2.is_special;
      n_mul2Tfin3.valid          = fin2Tmul2.valid;
      n_mul2Tfin3.is_sub_bound   = fin2Tmul2.is_sub_bound;
      n_mul2Tfin3.exp            = fin2Tmul2.exp;
      n_mul2Tfin3.special_result = fin2Tmul2.special_result;
    end
  end

// *********************************************************************************************
// MUL2 to FIN3
// *********************************************************************************************
  always_comb begin
    n_fin3Texp = fin3Texp;
    if(flush[6]) n_fin3Texp = '0;
    else if(pipe_en[6]) begin
      n_fin3Texp.sign           = mul2Tfin3.sign;
      n_fin3Texp.is_special     = mul2Tfin3.is_special;
      n_fin3Texp.valid          = mul2Tfin3.valid;
      n_fin3Texp.is_sub_bound   = mul2Tfin3.is_sub_bound;
      n_fin3Texp.exp            = mul2Tfin3.exp;
      n_fin3Texp.muln           = outfin;
      n_fin3Texp.special_result = mul2Tfin3.special_result;
    end
  end

// *********************************************************************************************
// FIN3 to EXP
// *********************************************************************************************
  assign raw_exp = fin3Texp.valid ? fin3Texp.exp + {2'b00, fin3Texp.muln[14:7]}:'0;

  always_comb begin : exponent_saturation
    if(raw_exp >= 10'sd255)                                        final_exp = 8'hFF; // Overflow -> Infinity
    else if(raw_exp == 10'h001 && fin3Texp.muln[14:7] < TWO[14:7]) final_exp = 8'h00;
    else if(raw_exp <= 10'sd0 || fin3Texp.is_sub_bound)            final_exp = 8'h00; // Underflow -> Flush to Zero
    else                                                           final_exp = raw_exp[7:0];
  end

  // De-Normalize
  assign fin = (final_exp == 8'h00) ? {fin3Texp.sign, 15'h0000} : {fin3Texp.sign, final_exp, fin3Texp.muln[6:0]};
  assign result = fin3Texp.is_special ? fin3Texp.special_result:fin;

  always_comb begin
    n_expTout = expTout;
    if(flush[7]) n_expTout = '0;
    else if(pipe_en[7]) begin
      n_expTout.valid = fin3Texp.valid;
      n_expTout.fin   = result;
    end
  end

// *********************************************************************************************
// EXP to OUT
// *********************************************************************************************
  assign divif.out.result = expTout.fin;

  always_ff @(posedge CLK, negedge nRST) begin : pipeline_ff
    if(~nRST) begin
      mul1Tfin1  <= '0;
      fin1Tsub1 <= '0;
      sub1Tsub2 <= '0;
      sub2Tfin2 <= '0;
      fin2Tmul2 <= '0;
      mul2Tfin3 <= '0;
      fin3Texp <= '0;
      expTout <= '0;
    end else begin
      mul1Tfin1  <= n_mul1Tfin1;
      fin1Tsub1 <= n_fin1Tsub1;
      sub1Tsub2 <= n_sub1Tsub2;
      sub2Tfin2 <= n_sub2Tfin2;
      fin2Tmul2 <= n_fin2Tmul2;
      mul2Tfin3 <= n_mul2Tfin3;
      fin3Texp <= n_fin3Texp;
      expTout <= n_expTout;
    end
  end
endmodule
// *********************************************************************************************
  
