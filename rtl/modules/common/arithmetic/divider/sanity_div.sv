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

  // typedef enum logic [2:0] {
  //   IDLE,
  //   BUSY, 
  //   DONE 
  // } state_t;

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

// SIGNAL DECLARATIONS
  // Pipeline Signals
  mul1_t fetTmul1, n_fetTmul1, subTmul2, n_subTmul2;
  sub_t mul1Tfin1, n_mul1Tfin1;
  mul2_t fin1Tsub1, n_fin1Tsub1, sub1Tsub2, n_sub1Tsub2;

  // FSM State
  // state_t state, n_state;

  // Mult and Sub signals
  logic [15:0] muln, muld, mulfin, f_1, f_2;
  logic [15:0] outn, outd, outfin;
  logic [15:0] subd, subout;
  logic startn, startd, startfin, startsub;
  logic donen, doned, donefin;

  // Math Signals
  logic sign;
  logic [15:0] fin, result;
  logic signed [9:0] raw_exp, exp_diff;
  logic [7:0] final_exp;
  logic is_subnormal_boundary;

  // Pipeline Signals
  logic pause, wen, ren, flush;
  logic [2:0] ir, iw;
  logic [2:0] fifo_count;
  logic [7:0][15:0] fifo, n_fifo;

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
    .stall(0),
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
  
  // Pipeline Signal
  assign flush = pause ? 1:0;
  assign divif.out.ready_in = pause ? 0:nRST;
  assign divif.out.valid_out = fifo_count > 0;

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

  assign startn = divif.in.valid_in && !is_special && !flush;
  assign startd = divif.in.valid_in && !is_special && !flush;

  always_comb begin
    if(flush) n_fetTmul1 = '0;  // For feeding in bubbles on pauses
    else begin
      n_fetTmul1.sign           = sign;
      n_fetTmul1.is_special     = is_special;
      n_fetTmul1.valid          = divif.in.valid_in;
      n_fetTmul1.is_sub_bound   = is_subnormal_boundary;
      n_fetTmul1.exp            = exp_diff;
      n_fetTmul1.special_result = special_result;
    end
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
    n_mul1Tfin1.muln           = outn;
    n_mul1Tfin1.muld           = outd;
    n_mul1Tfin1.special_result = fetTmul1.special_result;
  end

// *********************************************************************************************
// MUL1 to FIN1
// *********************************************************************************************
  assign startsub = !mul1Tfin1.is_special && mul1Tfin1.valid;
  assign subd = mul1Tfin1.valid && !mul1Tfin1.is_special ? mul1Tfin1.muld:'0;
  always_comb begin
    n_fin1Tsub1.sign           = mul1Tfin1.sign;
    n_fin1Tsub1.is_special     = mul1Tfin1.is_special;
    n_fin1Tsub1.valid          = mul1Tfin1.valid;
    n_fin1Tsub1.is_sub_bound   = mul1Tfin1.is_sub_bound;
    n_fin1Tsub1.exp            = mul1Tfin1.exp;
    n_fin1Tsub1.muln           = mul1Tfin1.muln;
    n_fin1Tsub1.special_result = mul1Tfin1.special_result;
  end

// *********************************************************************************************
// FIN1 to SUB1
// *********************************************************************************************
  always_comb begin
    n_sub1Tsub2.sign           = fin1Tsub1.sign;
    n_sub1Tsub2.is_special     = fin1Tsub1.is_special;
    n_sub1Tsub2.valid          = fin1Tsub1.valid;
    n_sub1Tsub2.is_sub_bound   = fin1Tsub1.is_sub_bound;
    n_sub1Tsub2.exp            = fin1Tsub1.exp;
    n_sub1Tsub2.muln           = fin1Tsub1.muln;
    n_sub1Tsub2.special_result = fin1Tsub1.special_result;
  end

// *********************************************************************************************
// SUB1 to SUB2
// *********************************************************************************************
  // For Back Pressure Store Sub Values Stall Fetch stages and let it flow out for 2 cycles, then resetn_ir
  assign startfin = !sub1Tsub2.is_special && sub1Tsub2.valid;
  assign mulfin = !sub1Tsub2.is_special && sub1Tsub2.valid ? sub1Tsub2.muln:'0;
  assign f_2 = !sub1Tsub2.is_special && sub1Tsub2.valid ? subout:'0;
  always_comb begin
    n_subTmul2.sign           = sub1Tsub2.sign;
    n_subTmul2.is_special     = sub1Tsub2.is_special;
    n_subTmul2.valid          = sub1Tsub2.valid;
    n_subTmul2.is_sub_bound   = sub1Tsub2.is_sub_bound;
    n_subTmul2.exp            = sub1Tsub2.exp;
    n_subTmul2.special_result = sub1Tsub2.special_result;
  end

// *********************************************************************************************
// SUB2 to MUL2
// *********************************************************************************************
  assign raw_exp = subTmul2.valid ? subTmul2.exp + {2'b00, outfin[14:7]}:'0;

  always_comb begin : exponent_saturation
    if(raw_exp >= 10'sd255)                             final_exp = 8'hFF; // Overflow -> Infinity
    else if(raw_exp == 10'h001 && outfin[14:7] < TWO)   final_exp = 8'h00;
    else if(raw_exp <= 10'sd0 || is_subnormal_boundary) final_exp = 8'h00; // Underflow -> Flush to Zero
    else                                                final_exp = raw_exp[7:0];
  end

  // De-Normalize
  assign fin = (final_exp == 8'h00) ? {subTmul2.sign, 15'h0000} : {subTmul2.sign, final_exp, outfin[6:0]};
  assign result = subTmul2.is_special ? subTmul2.special_result:fin;

  always_ff @(posedge CLK, negedge nRST) begin : pipeline_ff
    if(~nRST) begin
      fetTmul1  <= '0;
      mul1Tfin1 <= '0;
      fin1Tsub1 <= '0;
      sub1Tsub2 <= '0;
      subTmul2  <= '0;
    end else begin
      fetTmul1  <= n_fetTmul1;
      mul1Tfin1 <= n_mul1Tfin1;
      fin1Tsub1 <= n_fin1Tsub1;
      sub1Tsub2 <= n_sub1Tsub2;
      subTmul2  <= n_subTmul2;
    end
  end

  assign ren = divif.in.ready_out && fifo_count > 0;
  assign wen = subTmul2.valid;
  assign pause = !divif.in.ready_out && divif.out.valid_out;
  always_comb begin
    n_fifo = fifo;
    if(wen) n_fifo[iw] = result;
  end

  always_ff @(posedge CLK, negedge nRST) begin
    if(~nRST) begin
      fifo       <= '0;
      fifo_count <= '0;
      ir         <= '0;
      iw         <= '0;
    end else begin
      case({wen, ren})
        2'b10: begin iw <= iw + 1; fifo_count <= fifo_count + 1; end 
        2'b01: begin ir <= ir + 1; fifo_count <= fifo_count - 1; end 
        2'b11: begin iw <= iw + 1; ir <= ir + 1; end 
        default: ;
      endcase
      fifo <= n_fifo;
    end
  end

  // Output
  assign divif.out.result = fifo[ir];
endmodule