`include "div_if.vh"
`include "mul_if.vh"

module div_bf16_goldschmidt_1mul (
    input logic CLK, nRST,
    div_if.dvif divif
);

    localparam [7:0] BIAS = 8'h7F;
    localparam [7:0] EXP_INF = 8'hFF;
    localparam [15:0] TWO = 16'h4000;
    localparam [15:0] ONE = 16'h3f80;
    localparam [15:0] MAGIC = 16'h7EF3;

    typedef struct packed {
        logic [9:0] exp;
        logic startn, startd, sign;
    } mult1_t;

    typedef struct packed {
        logic [15:0] insubn, insubd;
        logic [9:0] exp;
        logic sign;
    } subin_t;

    typedef struct packed {
        logic [15:0] muln, muld, f;
    } subout_t;

    typedef struct packed {
        logic [15:0] muln, muld, f; 
        logic startn, startd;
    } mult2_t;

    typedef struct packed {
        logic [15:0] out; 
        logic [9:0] exp;
        logic sign;
    } final_t;

    // Latched Signals
    mult1_t mult1, n_mult1;
    subin_t subin, n_subin;
    subout_t subout, n_subout;
    mult2_t mult2, n_mult2;
    final_t finish, n_finish;

    // Mult Signals
    logic [15:0] muln1, muld1, f1, outmuln1, outmuld1, subguess;
    logic [15:0] outn, outd; 

    logic donen, n_donen, doned, n_doned;

    mul_bf16 mul_numerator (
        .clk(CLK), 
        .nRST(nRST),
        .start(mult1.startn), 
        .a(muln1), 
        .b(f1),
        .result(outmuln1), 
        .done(n_donen)
    );

    mul_bf16 mul_denominator (
        .clk(CLK), 
        .nRST(nRST),
        .start(mult1.startd), 
        .a(muld1), 
        .b(f1),
        .result(outmuld1), 
        .done(n_doned)
    );

    addsub_bf16 sub (
        .clk(CLK),
        .nRST(nRST), 
        .bf1_in(TWO),
        .bf2_in(subguess),
        .op(1'b1), 
        .bf_out(subout),
        .overflow(),  // Shouldn't Ever Happen
        .underflow(), // Shouldn't Ever Happen
        .invalid()    // Figure out what the parameters of "invalid" are
    );

    typedef enum logic [1:0] {
        IDLE,
        BUSY,
        DONE
    } state_t;

    state_t state, n_state;

    always_comb begin : state_outputs
        divif.out.ready_in = 0;
        divif.out.valid_out = 0;
        unique case(state)
            IDLE: if(nRST) divif.out.ready_in = 1;
            DONE: divif.out.valid_out = 1;
        endcase
    end

    always_comb begin : next_state_logic
        n_state = state;
        unique case(state)
            IDLE: if(divif.in.valid_in) n_state = BUSY;
            BUSY: if(donen && doned) n_state = DONE;
            DONE: if(divif.in.ready_out) n_state = IDLE;
        endcase
    end

    always_ff @(posedge CLK, negedge nRST) begin
        if(~nRST) state <= IDLE;
        else      state <= n_state;
    end

    // logic special_case;
    // logic is_same_mag;
    // logic is_div_by_one;

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

    // ----------------------------------------------------------------
    // Step 1: Begin Multiplication (multiplier will latch inputs)
    // ----------------------------------------------------------------
    assign muln1 = (divif.in.operand1[14:7] == 8'h00) ? 16'h0000:{1'b0, BIAS, divif.in.operand1[6:0]};
    assign muld1 = (divif.in.operand1[14:7] == 8'h00) ? 16'h0000:{1'b0, BIAS, divif.in.operand2[6:0]};
    assign f1 = MAGIC - {1'b0, BIAS, divif.in.operand2[6:0]};

    always_comb begin : fetch
        n_mult1.exp    = '0;
        n_mult1.startn = 0;
        n_mult1.startd = 0;
        n_mult1.sign   = 0;
        if(divif.in.valid_in && state == IDLE) begin
            n_mult1.exp    = $signed({2'h0, divif.in.operand1[14:7]}) - $signed({2'h0, divif.in.operand2[14:7]}) + 10'sd127;
            n_mult1.startn = 1;
            n_mult1.startd = 1;
            n_mult1.sign   = divif.in.operand1[15] ^ divif.in.operand2[15];
        end
    end

    always_ff @(posedge CLK, negedge nRST) begin
        if(~nRST) mult1 <= '0;
        else      mult1 <= n_mult1;
    end

    // Wait 2 Cycles
    // ----------------------------------------------------------------
    // Step 2: End
    // ----------------------------------------------------------------
    always_comb begin : mult
        n_finish.out  = finish.out;
        n_finish.exp  = finish.exp;
        n_finish.sign = finish.sign;
        if(donen && doned && state == BUSY) begin
            n_finish.out  = outmuln1;
            n_finish.exp  = $signed(mult1.exp) + $signed({2'h0, outmuln1[14:7]}) - 10'sd127;
            n_finish.sign = n_mult1.sign;
        end
    end

    always_ff @(posedge CLK, negedge nRST) begin
        if(~nRST) begin
            finish <= '0;
            donen  <= '0;
            doned  <= '0;
        end else begin
            finish <= n_finish;
            donen  <= n_donen;
            doned  <= n_doned;
        end
    end

    assign divif.out.result = {finish.sign, finish.exp[7:0], finish.out[6:0]};

    // // Second Iteration Inputs/Outputs
    // logic [15:0] muln_2, muld_2, f_2;
    // logic [15:0] n_outn_2, n_outd_2, outn_2, outd_2;        // Latched Outputs from Second multiplication

    // assign f_2 = subout;

    // // Final Output
    // logic sign;
    // logic [15:0] n_fin, fin;
    // assign sign = divif.in.operand1[15] ^ divif.in.operand2[15];
    // assign n_fin = {sign, outn[14:0]};
    // assign divif.out.result = fin;

    // always_comb begin : next_state
    //     n_state = state;
    //     case(state)
    //         INITIAL:  if(divif.in.valid_in) n_state = MULT1;
    //         MULT1:    if(donen && doned) n_state = SUB1;
    //         SUB1:     n_state = SUB2;
    //         SUB2:     n_state = INITIAL2;
    //         INITIAL2: n_state = MULT2;
    //         MULT2:    if(donen && doned) n_state = EXP;
    //         EXP:      n_state = DONE;
    //         DONE:     if(divif.in.ready_out) n_state = INITIAL;
    //         S_DONE:   if(divif.in.ready_out) n_state = INITIAL;
    //         default:  n_state = INITIAL;
    //     endcase
    // end

    // always_comb begin : state_outputs
    //     n_startn = '0;
    //     n_startd = '0;
    //     muln = '0;
    //     muld = '0;
    //     divif.out.ready_in = 0;
    //     divif.out.valid_out = 0;
    //     case(state)
    //         INITIAL: begin
    //             if (nRST) divif.out.ready_in = 1;
    //             n_startn = 1;
    //             n_startd = 1;
    //             muln = muln_1;
    //             muld = muld_1;
    //             f = f_1;
    //         end
    //         MULT1: begin
    //             muln = muln_1;
    //             muld = muld_1;
    //             f = f_1;
    //         end
    //         INITIAL2: begin
    //             n_startn = 1;
    //             n_startd = 1;
    //             muln = muln_2;
    //             muld = muld_2;
    //             f = f_2;
    //         end
    //         MULT2: begin
    //             muln = muln_2;
    //             muld = muld_2;
    //             f = f_2;
    //         end
    //         DONE: begin
    //             divif.out.valid_out = 1;
    //         end
    //         S_DONE: begin
    //             divif.out.valid_out = 1;
    //         end
    //         default: begin
    //             divif.out.valid_out = 0;
    //             divif.out.ready_in = 0;
    //         end
    //     endcase
    // end

    // always_ff @(posedge CLK, negedge nRST) begin
    //     if(~nRST) begin
    //         state <= INITIAL;
    //         mult1 <= '0;
    //         fin <= '0;
    //     end else begin
    //         state <= n_state;
    //         mult1 <= n_mult1;
    //         fin <= n_fin;
    //     end
    // end
endmodule