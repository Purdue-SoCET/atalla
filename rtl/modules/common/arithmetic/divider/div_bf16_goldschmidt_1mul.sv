`include "div_if.vh"

module div_bf16_goldschmidt_1mul (
    input logic CLK, nRST,
    div_if.dvif divif
);

// PARAMETERS AND TYPES
    localparam [7:0] BIAS = 8'h7F;
    localparam [7:0] EXP_INF = 8'hFF;
    localparam [15:0] TWO = 16'h4000;
    logic [15:0] qNaN = 16'h7FC0; // NaN

    typedef enum logic [3:0] {
        INITIAL, // Initial guess, clock multiplier
        MULT1,   // Multiplication Process
        SUB1,    // Subtract for next F
        SUB2,    // Lack of done signal requires multiple states
        INITIAL2,// Let SUB values sit in the register inputs of multiplication    
        MULT2,   // Multiplication Process
        EXP,     // Exponent and Sign Calculations
        DONE,    // Self Explanatory
        S_DONE   // Subnormal Output
    } state_t;

// SIGNAL DECLARATIONS
    // FSM State
    state_t state, n_state;

    // Mult and Sub signals
    logic [15:0] muln, muld, f;
    logic [15:0] outn, outd;
    logic [15:0] subout;
    logic startn, startd, n_startn, n_startd;
    logic donen, doned;

    // Pipeline Registers
    logic [15:0] iter1_outn, iter1_outd, iter1_f;
    logic [15:0] n_iter1_outn, n_iter1_outd, n_iter1_f;
    logic [15:0] fin;
    logic [15:0] next_fin;

    // Datapath and Math Signals
    logic [15:0] muln_1, muld_1, f_1;
    logic [15:0] n_fin;
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
        .b(f),
        .result(outn), 
        .done(donen)
    );

    mul_bf16 mul_denominator (
        .clk(CLK), 
        .nRST(nRST),
        .start(startd), 
        .a(muld), 
        .b(f),
        .result(outd), 
        .done(doned)
    );

    addsub_bf16 sub (
        .clk(CLK),
        .nRST(nRST), 
        .bf1_in(TWO),
        .bf2_in(outd),
        .op(1'b1), 
        .bf_out(subout),
        .overflow(),  // Shouldn't Ever Happen
        .underflow(), // Shouldn't Ever Happen
        .invalid()    // Figure out what the parameters of "invalid" are
    );

// COMBINATIONLA LOGIC
    assign muln_1 = (divif.in.operand1[14:7] == 8'h00) ? 16'h8000 : {1'b0, BIAS, divif.in.operand1[6:0]};
    assign muld_1 = (divif.in.operand2[14:7] == 8'h00) ? 16'h8000 : {1'b0, BIAS, divif.in.operand2[6:0]};
    assign f_1 = 16'h7EF3 - muld_1;

    // EXPONENT MATH AND SUBNORMAL BOUNDARY
    assign exp_diff = {2'b00, divif.in.operand1[14:7]} - {2'b00, divif.in.operand2[14:7]};
    assign is_subnormal_boundary = (exp_diff == -10'sd126) && (divif.in.operand1[6:0] < divif.in.operand2[6:0]);
    assign raw_exp = {2'b00, divif.in.operand1[14:7]} - {2'b00, divif.in.operand2[14:7]} + {2'b00, outn[14:7]};

    always_comb begin : exponent_saturation
        if (raw_exp >= 10'sd255) begin
            final_exp = 8'hFF; // Overflow -> Infinity
        end else if (raw_exp <= 10'sd0 || is_subnormal_boundary) begin
            final_exp = 8'h00; // Underflow -> Flush to Zero
        end else begin
            final_exp = raw_exp[7:0];
        end
    end

    // Final Math Output Assembly
    assign sign = divif.in.operand1[15] ^ divif.in.operand2[15];
    assign n_fin = (final_exp == 8'h00) ? {sign, 15'h0000} : {sign, final_exp, outn[6:0]};
    assign divif.out.result = fin;

    // Edge case detection
    assign op1_is_zero = (divif.in.operand1[14:7] == 15'h0000);
    assign op2_is_zero = (divif.in.operand2[14:7] == 15'h0000);
    assign op1_is_inf = (divif.in.operand1[14:7] == 8'hFF) && (divif.in.operand1[6:0] == 7'h00);
    assign op2_is_inf = (divif.in.operand2[14:7] == 8'hFF) && (divif.in.operand2[6:0] == 7'h00);
    assign op1_is_nan = (divif.in.operand1[14:7] == 8'hFF) && (divif.in.operand1[6:0] != 7'h00);
    assign op2_is_nan = (divif.in.operand2[14:7] == 8'hFF) && (divif.in.operand2[6:0] != 7'h00);
    assign op1_op2_same = divif.in.operand1[14:0] == divif.in.operand2[14:0];
    assign op2_is_one = divif.in.operand2[14:0] == 15'h3F80;

// COMBINATIONAL LOGIC EDGE CASES
    always_comb begin
        is_special = 1'b1;
        special_result = {sign, 15'h0000};
        // NaN Propagation
        if (op1_is_nan || op2_is_nan) special_result = qNaN;
        // 0 / 0 or Inf / Inf -> NaN
        else if ((op1_is_zero && op2_is_zero) || (op1_is_inf && op2_is_inf)) special_result = qNaN;
        // N / 0 -> Infinity
        else if (op2_is_zero) special_result = {sign, 8'hFF, 7'h00};
        // N / Inf -> Zero
        else if (op2_is_inf) special_result = {sign, 15'h0000};
        // 0 / N -> Zero
        else if (op1_is_zero) special_result = {sign, 15'h0000};
        // Inf / N -> Infinity
        else if (op1_is_inf) special_result = {sign, 8'hFF, 7'h00};
        // N / N -> 1
        else if (op1_op2_same & !op2_is_zero) special_result = {sign, 15'h3F80};
        // N / 1 -> N
        else if (op2_is_one) special_result = {sign, divif.in.operand1[14:0]};
        // Not a special case, proceed with Goldschmidt
        else is_special = 1'b0;
    end

// FSM NEXT STATE AND OUTPUTS
    always_comb begin : next_state
        n_state = state;
        case(state)
            INITIAL:  begin
                if (divif.in.valid_in) begin
                    if (is_special) n_state = DONE;  // Early Out
                    else            n_state = MULT1; // Normal path
                end
            end
            MULT1:    if(donen && doned) n_state = SUB1;
            SUB1:     n_state = SUB2;
            SUB2:     n_state = INITIAL2;
            INITIAL2: n_state = MULT2;
            MULT2:    if(donen && doned) n_state = EXP;
            EXP:      n_state = DONE;
            DONE:     if(divif.in.ready_out) n_state = INITIAL;
            S_DONE:   if(divif.in.ready_out) n_state = INITIAL;
            default:  n_state = INITIAL;
        endcase
    end

    always_comb begin : state_outputs
        n_startn = '0;
        n_startd = '0;
        muln = '0;
        muld = '0;
        f = '0;
        divif.out.ready_in = 0;
        divif.out.valid_out = 0;

        n_iter1_outn = iter1_outn;
        n_iter1_outd = iter1_outd;
        n_iter1_f = iter1_f;

        next_fin = fin;

        if (state == INITIAL && divif.in.valid_in && is_special) begin
            next_fin = special_result;
        end
        if (state == MULT1 && donen && doned) begin
            n_iter1_outn = outn;
            n_iter1_outd = outd;
        end
        if (state == SUB2) begin
            n_iter1_f = subout;
        end
        if (state == MULT2 && donen && doned) begin
            next_fin = n_fin;
        end

        case(state)
            INITIAL: begin
                if (nRST) divif.out.ready_in = 1;
                n_startn = 1;
                n_startd = 1;
                muln = muln_1;
                muld = muld_1;
                f = f_1;
            end
            MULT1: begin
                muln = muln_1;
                muld = muld_1;
                f = f_1;
            end
            SUB1, SUB2: begin
                muln = muln_1;
                muld = muld_1;
                f = f_1;
            end
            INITIAL2: begin
                n_startn = 1;
                n_startd = 1;
                muln = iter1_outn;
                muld = iter1_outd;
                f = iter1_f;
            end
            MULT2: begin
                muln = iter1_outn; 
                muld = iter1_outd; 
                f = iter1_f;
            end
            DONE: begin
                divif.out.valid_out = 1;
            end
            S_DONE: begin
                divif.out.valid_out = 1;
            end
            default: begin
                divif.out.valid_out = 0;
                divif.out.ready_in = 0;
            end
        endcase
    end

// SEQUENTIAL LOGIC
    always_ff @(posedge CLK, negedge nRST) begin
        if(~nRST) begin
            state <= INITIAL;
            startn <= '0;
            startd <= '0;
            fin <= '0;
            iter1_outn <= '0;
            iter1_outd <= '0;
            iter1_f <= '0;
        end else begin
            state <= n_state;
            startn <= n_startn;
            startd <= n_startd;
            iter1_outn <= n_iter1_outn;
            iter1_outd <= n_iter1_outd;
            iter1_f <= n_iter1_f;
            fin <= next_fin;
        end
    end

endmodule