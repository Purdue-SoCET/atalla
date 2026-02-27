`include "vdiv_if.vh"
`include "mul_if.vh"

module div_bf16pipeline (
    input logic CLK, nRST,
    vdiv_if.div divif
);
  // 6k Area for multiplier and sub
  // PARAMETERS AND TYPES
  localparam [7:0] BIAS = 8'h7F;
  localparam [7:0] EXP_INF = 8'hFF;
  localparam [15:0] TWO = 16'h4000;
  localparam [15:0] qNaN = 16'h7FC0; // NaN

  // Won't Be utilized, simply a marker of how the pipeline goes
  typedef enum logic [2:0] {
    INITIAL, // Initial guess, clock multiplier
    MULT1,   // Multiplication Process
    SUB1,    // Subtract for next F
    SUB2,    // Lack of done signal requires multiple states
    INITIAL2,// Let SUB values sit in the register inputs of multiplication    
    MULT2,   // Multiplication Process
    EXP,     // Exponent and Sign Calculations
    DONE    // Self Explanatory
  } state_t;

    // Pipeline Structs
  typedef struct packed{
    logic sign, is_special;
    logic [7:0] exp;
    logic [16:0] special_result;
  } fetTmul_t;

  typedef struct packed{
    logic sign, is_special;
    logic [7:0] exp;
    logic [16:0] muln, special_result;
  } mulTsub_t;

// SIGNAL DECLARATIONS
  // Pipeline Signals
  fetTmul_t fetTmul1, n_fetTmul1, mul1Tmul2, n_mul1Tmul2, mul2Tfin1, n_mul2Tfin1, mul3Tmul4, n_mul3Tmul4, mul4Tfin3, n_mul4Tfin3, fin2Tmul3, n_fin2Tmul3;
  mulTsub_t fin1Tsub1, n_fin1Tsub1, sub1Tsub2, n_sub1Tsub2, sub2Tfin2, n_sub2Tfin2;

  // FSM State
  state_t state, n_state;

  // Mult and Sub signals
  logic [15:0] muln, muld, mulfin, f_1, f_2;
  logic [15:0] outn, outd, outfin;
  logic [15:0] subd, subout;
  logic startn, startd, startfin;
  logic donen, doned, donefin;

  // Pipeline Registers
  logic [15:0] iter1_outn, iter1_outd, iter1_f;
  logic [15:0] n_iter1_outn, n_iter1_outd, n_iter1_f;
  logic [15:0] fin;
  logic [15:0] next_fin;

  // Datapath and Math Signals
  logic sign;
  logic signed [9:0] raw_exp, exp_diff;
  logic [7:0] final_exp;
  logic is_subnormal_boundary;

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
    .done(donen)
  );

  mul_bf16 mul_denominator (
    .clk(CLK), 
    .nRST(nRST),
    .start(startd), 
    .a(muld), 
    .b(f_1),
    .result(outd), 
    .done(doned)
  );

  addsub_bf16 sub (
    .clk(CLK),
    .nRST(nRST), 
    .bf1_in(TWO),
    .bf2_in(subd),
    .op(1'b1), 
    .bf_out(subout),
    .overflow(),  // Shouldn't Ever Happen
    .underflow(), // Shouldn't Ever Happen
    .invalid()    // Invalid Handled by us
  );

  mul_bf16 mul_final (
    .clk(CLK), 
    .nRST(nRST),
    .start(startfin), 
    .a(mulfin), 
    .b(f_2),
    .result(outfin), 
    .done(donefin)
  );


  // Mantissa Normalization
  assign muln = (divif.in.operand1[14:7] == 8'h00) ? 16'h8000 : {1'b0, BIAS, divif.in.operand1[6:0]};
  assign muld = (divif.in.operand2[14:7] == 8'h00) ? 16'h8000 : {1'b0, BIAS, divif.in.operand2[6:0]};
  assign f_1 = 16'h7EF3 - muld;

  // Exponent Calculation
  assign exp_diff = {2'b00, divif.in.operand1[14:7]} - {2'b00, divif.in.operand2[14:7]};
  assign is_subnormal_boundary = (exp_diff == -10'sd126) && (divif.in.operand1[6:0] < divif.in.operand2[6:0]);
  assign raw_exp = {2'b00, divif.in.operand1[14:7]} - {2'b00, divif.in.operand2[14:7]} + {2'b00, outn[14:7]};

  always_comb begin : exponent_saturation
    if(raw_exp >= 10'sd255)                             final_exp = 8'hFF; // Overflow -> Infinity
    else if(raw_exp <= 10'sd0 || is_subnormal_boundary) final_exp = 8'h00; // Underflow -> Flush to Zero
    else                                                final_exp = raw_exp[7:0];
  end

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
    is_special = 1'b1;
    special_result = {sign, 15'h0000};
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
    else is_special = 1'b0;
  end

  assign divif.out.ready_in =  nRST ? 1:0;
  assign divif.out.valid_out = donefin ? 1:0;

  assign startn = divif.in.valid_in && !is_special ? 1:0;
  assign startd = divif.in.valid_in && !is_special ? 1:0;

  always_comb begin
    n_fetTmul1.sign           = sign;
    n_fetTmul1.is_special     = is_special;
    n_fetTmul1.exp            = final_exp;
    n_fetTmul1.special_result = special_result;
  end

// *********************************************************************************************
// FET to MUL1
// *********************************************************************************************
  always_comb begin
    n_mul1Tmul2.sign           = fetTmul1.sign;
    n_mul1Tmul2.is_special     = fetTmul1.is_special;
    n_mul1Tmul2.exp            = fetTmul1.exp;
    n_mul1Tmul2.special_result = fetTmul1.special_result;
  end

// *********************************************************************************************
// MUL1 to MUL2
// *********************************************************************************************
  always_comb begin
    n_mul2Tfin1.sign           = mul1Tmul2.sign;
    n_mul2Tfin1.is_special     = mul1Tmul2.is_special;
    n_mul2Tfin1.exp            = mul1Tmul2.exp;
    n_mul2Tfin1.special_result = mul1Tmul2.special_result;
  end

// *********************************************************************************************
// MUL2 to FIN1
// *********************************************************************************************
  assign subd = !is_special ? outd:'0;
  always_comb begin
    n_fin1Tsub1.sign           = mul2Tfin1.sign;
    n_fin1Tsub1.is_special     = mul2Tfin1.is_special;
    n_fin1Tsub1.exp            = mul2Tfin1.exp;
    n_fin1Tsub1.muln           = outn;
    n_fin1Tsub1.special_result = mul2Tfin1.special_result;
  end

// *********************************************************************************************
// FIN1 to SUB1
// *********************************************************************************************
  always_comb begin
    n_sub1Tsub2.sign           = fin1Tsub1.sign;
    n_sub1Tsub2.is_special     = fin1Tsub1.is_special;
    n_sub1Tsub2.exp            = fin1Tsub1.exp;
    n_sub1Tsub2.muln           = fin1Tsub1.muln;
    n_sub1Tsub2.special_result = fin1Tsub1.special_result;
  end

// *********************************************************************************************
// SUB1 to SUB2
// *********************************************************************************************
  always_comb begin
    n_sub2Tfin2.sign           = sub1Tsub2.sign;
    n_sub2Tfin2.is_special     = sub1Tsub2.is_special;
    n_sub2Tfin2.exp            = sub1Tsub2.exp;
    n_sub2Tfin2.muln           = sub1Tsub2.muln;
    n_sub2Tfin2.special_result = sub1Tsub2.special_result;
  end

// *********************************************************************************************
// SUB2 to FIT2
// *********************************************************************************************
  assign startfin = !sub2Tfin2.is_special ? 1:0;
  assign mulfin = !sub2Tfin2.is_special ? sub2Tfin2.muln:'0;
  assign f_2 = !sub2Tfin2.is_special ? subout:'0;
  always_comb begin
    n_fin2Tmul3.sign           = sub2Tfin2.sign;
    n_fin2Tmul3.is_special     = sub2Tfin2.is_special;
    n_fin2Tmul3.exp            = sub2Tfin2.exp;
    n_fin2Tmul3.special_result = sub2Tfin2.special_result;
  end

// *********************************************************************************************
// FIT2 to MUL3
// *********************************************************************************************
  always_comb begin
    n_mul3Tmul4.sign           = fin2Tmul3.sign;
    n_mul3Tmul4.is_special     = fin2Tmul3.is_special;
    n_mul3Tmul4.exp            = fin2Tmul3.exp;
    n_mul3Tmul4.special_result = fin2Tmul3.special_result;
  end

// *********************************************************************************************
// MUL3 to MUL4
// *********************************************************************************************
  always_comb begin
    n_mul4Tfin3.sign           = mul3Tmul4.sign;
    n_mul4Tfin3.is_special     = mul3Tmul4.is_special;
    n_mul4Tfin3.exp            = mul3Tmul4.exp;
    n_mul4Tfin3.special_result = mul3Tmul4.special_result;
  end

// *********************************************************************************************
// MUL4 to FIN3
// *********************************************************************************************
  assign divif.out.result = (mul4Tfin3.exp == 8'h00) ? {mul4Tfin3.sign, 15'h0000} : {mul4Tfin3.sign, mul4Tfin3.exp, outfin[6:0]};

  always_ff @(posedge CLK, negedge nRST) begin : pipeline_ff
    if(~nRST) begin
      fetTmul1  <= '0;
      mul1Tmul2 <= '0;
      mul2Tfin1 <= '0;
      fin1Tsub1 <= '0;
      sub1Tsub2 <= '0;
      sub2Tfin2 <= '0;
      fin2Tmul3 <= '0;
      mul3Tmul4 <= '0;
      mul4Tfin3 <= '0;
    end else begin
      fetTmul1  <= n_fetTmul1;
      mul1Tmul2 <= n_mul1Tmul2;
      mul2Tfin1 <= n_mul2Tfin1;
      fin1Tsub1 <= n_fin1Tsub1;
      sub1Tsub2 <= n_sub1Tsub2;
      sub2Tfin2 <= n_sub2Tfin2;
      fin2Tmul3 <= n_fin2Tmul3;
      mul3Tmul4 <= n_mul3Tmul4;
      mul4Tfin3 <= n_mul4Tfin3;
    end
  end
endmodule