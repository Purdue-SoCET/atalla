`include "div_if.vh"

module div_bf16_goldschmidt_1mul (
    input logic CLK, nRST,
    div_if.dvif divif
);
  // 6k Area for multiplier and sub
  // PARAMETERS AND TYPES
  localparam [7:0] BIAS = 8'h7F;
  localparam [7:0] EXP_INF = 8'hFF;
  localparam [15:0] TWO = 16'h4000;
  localparam [15:0] qNaN = 16'h7FC0; // NaN

  typedef enum logic [2:0] {
    IDLE,
    BUSY, 
    DONE 
  } state_t;

    // Pipeline Structs
  typedef struct packed{
    logic sign, is_special, valid, is_sub_bound;
    logic [9:0] exp;
    logic [16:0] special_result;
  } mul1_t;

  typedef struct packed{
    logic sign, is_special, valid, is_sub_bound;
    logic [9:0] exp;
    logic [16:0] muln, special_result;
  } mul2_t;

// SIGNAL DECLARATIONS
  // Pipeline Signals
  mul1_t fetTmul1, n_fetTmul1, mul1Tfin1, n_mul1Tfin1, fin2Tmul2, n_fin2Tmul2;
  mul2_t fin1Tsub, n_fin1Tsub, subTmul2, n_subTmul2;

  // FSM State
  state_t state, n_state;

  // Mult and Sub signals
  logic [15:0] muln, muld, mulfin, f_1, f_2;
  logic [15:0] outn, outd, outfin;
  logic [15:0] subd, subout;
  logic startn, startd, startfin;
  logic donen, doned, donefin;

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
    is_special = divif.in.valid_in;
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

  // assign divif.out.ready_in =  nRST ? 1:0;
  // assign divif.out.valid_out = donefin;

  assign startn = divif.in.valid_in && !is_special ? 1:0;
  assign startd = divif.in.valid_in && !is_special ? 1:0;

  always_comb begin
    n_fetTmul1.sign           = sign;
    n_fetTmul1.is_special     = is_special;
    n_fetTmul1.valid          = divif.in.valid_in;
    n_fetTmul1.is_sub_bound   = is_subnormal_boundary;
    n_fetTmul1.exp            = exp_diff;
    n_fetTmul1.special_result = special_result;
  end

// *********************************************************************************************
// FET to MUL1
// *********************************************************************************************
  always_comb begin
    n_mul1Tfin1.sign           = fetTmul1.sign;
    n_mul1Tfin1.is_special     = fetTmul1.is_special;
    n_mul1Tfin1.valid          = fetTmul1.valid;
    n_mul1Tfin1.is_sub_bound   = fetTmul1.is_sub_bound;
    n_mul1Tfin1.exp            = fetTmul1.exp;
    n_mul1Tfin1.special_result = fetTmul1.special_result;
  end

// *********************************************************************************************
// MUL1 to FIN1
// *********************************************************************************************
  assign subd = mul1Tfin1.valid && !mul1Tfin1.is_special && doned ? outd:'0;
  always_comb begin
    n_fin1Tsub.sign           = mul1Tfin1.sign;
    n_fin1Tsub.is_special     = mul1Tfin1.is_special;
    n_fin1Tsub.valid          = mul1Tfin1.valid;
    n_fin1Tsub.is_sub_bound   = mul1Tfin1.is_sub_bound;
    n_fin1Tsub.exp            = mul1Tfin1.exp;
    n_fin1Tsub.muln           = outn;
    n_fin1Tsub.special_result = mul1Tfin1.special_result;
  end

// *********************************************************************************************
// FIN1 to SUB
// *********************************************************************************************
  assign startfin = !fin1Tsub.is_special && fin1Tsub.valid ? 1:0;
  assign mulfin = !fin1Tsub.is_special && fin1Tsub.valid ? fin1Tsub.muln:'0;
  assign f_2 = !fin1Tsub.is_special && fin1Tsub.valid ? subout:'0;
  always_comb begin
    n_subTmul2.sign           = fin1Tsub.sign;
    n_subTmul2.is_special     = fin1Tsub.is_special;
    n_subTmul2.valid          = fin1Tsub.valid;
    n_subTmul2.is_sub_bound   = fin1Tsub.is_sub_bound;
    n_subTmul2.exp            = fin1Tsub.exp;
    n_subTmul2.muln           = outfin;
    n_subTmul2.special_result = fin1Tsub.special_result;
  end

// *********************************************************************************************
// SUB to MUL
// *********************************************************************************************
  logic [15:0] fin, result;
  assign raw_exp = subTmul2.valid ? subTmul2.exp + {2'b00, subTmul2.muln[14:7]}:'0;

  always_comb begin : exponent_saturation
    if(raw_exp >= 10'sd255)                             final_exp = 8'hFF; // Overflow -> Infinity
    else if(raw_exp <= 10'sd0 || is_subnormal_boundary) final_exp = 8'h00; // Underflow -> Flush to Zero
    else                                                final_exp = raw_exp[7:0];
  end

  assign fin = (final_exp == 8'h00) ? {subTmul2.sign, 15'h0000} : {subTmul2.sign, final_exp, subTmul2.muln[6:0]};
  assign result = subTmul2.is_special ? subTmul2.special_result:fin;
  assign divif.out.result = subTmul2.is_special ? subTmul2.special_result:fin;

  always_ff @(posedge CLK, negedge nRST) begin : pipeline_ff
    if(~nRST) begin
      fetTmul1  <= '0;
      mul1Tfin1 <= '0;
      fin1Tsub  <= '0;
      subTmul2  <= '0;
    end else begin
      fetTmul1  <= n_fetTmul1;
      mul1Tfin1 <= n_mul1Tfin1;
      fin1Tsub  <= n_fin1Tsub;
      subTmul2  <= n_subTmul2;
    end
  end

  always_comb begin
    n_state = state;
    unique case(state)
      IDLE: if(divif.in.valid_in)              n_state = BUSY;
      BUSY: if(donefin || subTmul2.is_special) n_state = DONE;
      DONE: if(divif.in.ready_out)             n_state = IDLE;
    endcase
  end

  always_comb begin
    divif.out.valid_out = 0;
    divif.out.ready_in = 0;
    case(state)
      IDLE: if(nRST) divif.out.ready_in = 1;
      DONE: divif.out.valid_out = 1;
    endcase
  end

  always_ff @(posedge CLK, negedge nRST) begin
    if(~nRST) state <= IDLE;
    else      state <= n_state;
  end
endmodule