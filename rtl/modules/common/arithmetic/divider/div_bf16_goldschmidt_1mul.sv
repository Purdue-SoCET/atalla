`include "div_if.vh"

module div_bf16_goldschmidt_1mul (
    input logic CLK, nRST,
    div_if.dvif divif
);

    localparam [7:0] BIAS = 8'h7F;
    localparam [7:0] EXP_INF = 8'hFF;
    localparam [15:0] TWO = 16'h4000;

    // Mult Signals
    logic [15:0] muln, muld, f;
    logic [15:0] outn, outd; 

    logic n_startn, startn, n_startd, startd, donen, doned;

    // Subtraction Signals
    logic [15:0] subout;

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

    typedef enum logic [4:0] {
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
    state_t state, n_state;

    // logic special_case;
    // logic is_same_mag;
    // logic is_div_by_one;

    // Initial Inputs/Outputs
    logic [15:0] mulm_1, muld_1, f_1;

    assign muln_1 = (divif.in.operand1[14:7] == 8'h00) ? 16'h0000:{1'b1, divif.in.operand1[14:0]};
    assign muld_1 = (divif.in.operand1[14:7] == 8'h00) ? 16'h0000:{1'b1, divif.in.operand2[14:0]};
    assign f_1 = (16'h7EF3 - divif.in.operand2 & 16'h7FFF) & 16'h7FFF;

    // Second Iteration Inputs/Outputs
    logic [15:0] muln_2, muld_2, f_2;
    logic [15:0] n_outn_2, n_outd_2, outn_2, outd_2;        // Latched Outputs from Second multiplication

    assign f_2 = subout;

    // Final Output
    logic sign;
    logic [15:0] n_fin, fin;
    assign sign = divif.in.operand1[15] ^ divif.in.operand2[15];
    assign n_fin = {sign, outn[14:0]};
    assign divif.out.result = fin;

    // ----------------------------------------------------------------
    // Special cases: NaN / Inf / invalid (Deal with later)
    // ----------------------------------------------------------------
    // assign a_nan = (divif.in.operand1[14:7] == EXP_INF) && (divif.in.operand1[6:0] != 0);
    // assign a_inf = (divif.in.operand1[14:7] == EXP_INF) && (divif.in.operand1[6:0] == 0);
    // assign a_zero = (divif.in.operand1[14:7] == 0);
    // assign b_nan = (divif.in.operand2[14:7] == EXP_INF) && (divif.in.operand2[6:0] != 0);
    // assign b_inf = (divif.in.operand2[14:7] == EXP_INF) && (divif.in.operand2[6:0] == 0);
    // assign b_zero = (divif.in.operand2[14:7] == 0);
    // assign is_same_mag = (op1_ftz[14:0] == op2_ftz[14:0]);
    // assign is_div_by_one = (op2_ftz[14:0] == 15'h3F80);
    // assign special_case = a_nan || a_inf || a_zero || b_nan || b_inf || b_zero || is_same_mag || is_div_by_one || special_case; 

    always_comb begin : next_state
        n_state = state;
        case(state)
            INITIAL:  n_state = MULT1;
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
        divif.out.ready_in = 0;
        divif.out.valid_out = 0;
        case(state)
            INITIAL: begin
                if(nRST) divif.out.ready_in = 1;
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
            INITIAL2: begin
                n_startn = 1;
                n_startd = 1;
                muln = muln_2;
                muld = muld_2;
                f = f_2;
            end
            MULT2: begin
                muln = muln_2;
                muld = muld_2;
                f = f_2;
            end
            DONE: begin
                divif.out.valid_out = 1;
            end
            S_DONE: begin
                divif.out.valid_out = 1;
            end
            default: begin end
        endcase
    end

    always_ff @(posedge CLK, negedge nRST) begin
        if(~nRST) begin
            state <= INITIAL;
            startn <= '0;
            startd <= '0;
            fin <= '0;
        end else begin
            state <= n_state;
            startn <= n_startn;
            startd <= n_startd;
            fin <= n_fin;
        end
    end

    // always_comb begin
    //     d_exp  = reg_d[14:7];
    //     d_mant = reg_d[6:0];

    //     // 1. Convert BF16 D to 3.10 fixed-point format (Value = [12:10].[9:0])
    //     if (d_exp == 8'h00) begin
    //         fixed_d = 13'h000;
    //     end else if (d_exp <= 8'd127) begin
    //         // Shift down based on how much smaller exponent is than 127
    //         fixed_d = {2'b00, 1'b1, d_mant, 3'b000} >> (8'd127 - d_exp);
    //     end else begin
    //         // Hard clip at 2.0 to prevent underflow wrap
    //         fixed_d = 13'h0800; 
    //     end

    //     // 2. Fixed-point subtraction: 2.0 - D
    //     // 2.0 represented in 3.10 fixed-point is 13'b010_0000000000 = 13'h0800
    //     fixed_f = 13'h0800 - fixed_d;

    //     // 3. Normalize back to BF16 (Priority Encoder)
    //     if (fixed_f == 13'h0000) begin
    //         f_exp = 8'h00; f_mant = 7'h00;
    //     end else if (fixed_f[11]) begin f_exp = 8'd128; f_mant = 7'h00; // 2.0
    //     end else if (fixed_f[10]) begin f_exp = 8'd127; f_mant = fixed_f[9:3]; // 1.xxx
    //     end else if (fixed_f[9])  begin f_exp = 8'd126; f_mant = fixed_f[8:2]; // 0.1xxx
    //     end else if (fixed_f[8])  begin f_exp = 8'd125; f_mant = fixed_f[7:1];
    //     end else if (fixed_f[7])  begin f_exp = 8'd124; f_mant = fixed_f[6:0];
    //     end else if (fixed_f[6])  begin f_exp = 8'd123; f_mant = {fixed_f[5:0], 1'b0};
    //     end else if (fixed_f[5])  begin f_exp = 8'd122; f_mant = {fixed_f[4:0], 2'b00};
    //     end else if (fixed_f[4])  begin f_exp = 8'd121; f_mant = {fixed_f[3:0], 3'b000};
    //     end else if (fixed_f[3])  begin f_exp = 8'd120; f_mant = {fixed_f[2:0], 4'h0};
    //     end else if (fixed_f[2])  begin f_exp = 8'd119; f_mant = {fixed_f[1:0], 5'h0};
    //     end else if (fixed_f[1])  begin f_exp = 8'd118; f_mant = {fixed_f[0],   6'h0};
    //     end else if (fixed_f[0])  begin f_exp = 8'd117; f_mant = 7'h00;
    //     end else begin                  f_exp = 8'h00;  f_mant = 7'h00;
    //     end

    //     // F is always positive in Goldschmidt
    //     fast_f_out = {1'b0, f_exp, f_mant};
    // end

    // always_ff @(posedge CLK or negedge nRST) begin
    //     if (~nRST) begin
    //         state <= IDLE;
    //         reg_n <= '0;
    //         reg_d <= '0;
    //         reg_f <= '0;
    //         res_exp <= '0;
    //         res_sign <= '0;
    //         divif.out.result <= '0;
    //     end else begin
    //         state <= next_state;
    //         reg_n <= next_n;
    //         reg_d <= next_d;
    //         reg_f <= next_f;
    //         res_exp <= next_exp;
    //         res_sign <= next_sign;
    //         divif.out.result <= next_res_out;
    //     end
    // end

    // always_comb begin
    //     next_state = state;
    //     next_n = reg_n;
    //     next_d = reg_d;
    //     next_f = reg_f;
    //     next_exp = res_exp;
    //     next_sign = res_sign;
    //     next_res_out = divif.out.result;

    //     mul_a = '0;
    //     mul_b = '0;
    //     mul_start = 0;
    //     divif.out.ready_in = 0;
    //     divif.out.valid_out = 0;

    //     case (state)
    //         IDLE: begin
    //             if (nRST) divif.out.ready_in = 1;
    //             if (divif.in.valid_in) begin
    //                 next_sign = op1_ftz[15] ^ op2_ftz[15];

    //                 next_exp = $signed({2'b0, op1_ftz[14:7]}) - $signed({2'b0, op2_ftz[14:7]}) + 10'sd127;
                    
    //                 // Force exponents to 1.0 (0x7F) to normalize mantissas for Goldschmidt
    //                 next_n = {1'b0, BIAS, op1_ftz[6:0]};
    //                 next_d = {1'b0, BIAS, op2_ftz[6:0]};

    //                 // Initial Seed F0 (Magic Number)
    //                 next_f = 16'h7EF3 - {1'b0, BIAS, op2_ftz[6:0]};

    //                 if (a_nan || b_nan || (a_inf && b_inf) || (a_zero && b_zero) || a_inf || b_zero || a_zero || b_inf) begin
    //                     next_state = SPECIAL;
    //                 end else if (is_same_mag || is_div_by_one) begin
    //                     next_state = SPECIAL;
    //                 end else
    //                     next_state = INIT_NF;
    //             end
    //         end

    //         SPECIAL: begin
    //             // One-cycle result for edge cases
    //             if (a_nan || b_nan || (a_inf && b_inf) || (a_zero && b_zero))
    //                 next_res_out = {1'b0, EXP_INF, 7'h40}; // NaN
    //             else if (a_inf || b_zero)
    //                 next_res_out = {next_sign, EXP_INF, 7'h00}; // Infinity
    //             else if (is_same_mag)
    //                 next_res_out = {next_sign, 8'h7F, 7'h00};
    //             else if (is_div_by_one)
    //                 next_res_out = {next_sign, op1_ftz[14:7], op1_ftz[6:0]};
    //             else
    //                 next_res_out = {next_sign, 8'h00, 7'h00};
                
    //             next_state = DONE;
    //         end

    //         INIT_NF: begin
    //             mul_a = reg_n;
    //             mul_b = reg_f;
    //             mul_start = 1;
    //             if (mul_done) begin
    //                 next_n = mul_out;
    //                 next_state = ITER_DF;
    //             end
    //         end

    //         ITER_DF: begin
    //             mul_a = reg_d;
    //             mul_b = reg_f;
    //             mul_start = 1;
    //             if (mul_done) begin
    //                 next_d = mul_out;
    //                 next_state = REFINE_F;
    //             end
    //         end

    //         REFINE_F: begin
    //             // F = 2 - D.
    //             next_f = fast_f_out;
    //             next_state = FINAL_NF;
    //         end

    //         FINAL_NF: begin
    //             mul_a = reg_n;
    //             mul_b = reg_f;
    //             mul_start = 1;
    //             if (mul_done) begin
    //                 next_n = mul_out;
    //                 next_state = ROUND;
    //             end
    //         end

    //         ROUND: begin
    //             if (!(a_nan || b_nan || (a_inf && b_inf) || (a_zero && b_zero) || a_inf || b_zero || a_zero || b_inf)) begin ---------------------------------------
    //                 // Reconstruct the true exponent by combining the input difference
    //                 // with the normalized exponent generated by the final mul_bf16 result
    //                 true_exp_calc = $signed(res_exp) + $signed({2'b0, reg_n[14:7]}) - 10'sd127;
                    
    //                 if (true_exp_calc >= 10'sd255) begin
    //                     // Overflow to Infinity
    //                     next_res_out = {res_sign, EXP_INF, 7'h00};
    //                 end else if (true_exp_calc <= 10'sd0) begin
    //                     // Underflow to Zero
    //                     next_res_out = {res_sign, 8'h00, 7'h00};
    //                 end else begin
    //                     // Normal Result
    //                     next_res_out = {res_sign, true_exp_calc[7:0], reg_n[6:0]};
    //                 end
    //             end
                
    //             next_state = DONE;
    //         end

    //         DONE: begin
    //             divif.out.valid_out = 1; // Assert valid_out AFTER the result is safely flopped
    //             if (divif.in.ready_out) begin
    //                 next_state = IDLE;
    //             end
    //         end

    //         default: next_state = IDLE;
    //     endcase
    // end

endmodule