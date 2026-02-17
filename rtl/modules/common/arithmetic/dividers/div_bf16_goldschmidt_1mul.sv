`include "div_if.vh"

module div_bf16_goldschmidt_1mul (
    input logic CLK, nRST,
    div_if.div divif
);

    localparam [7:0] BIAS = 8'h7F;
    localparam [7:0] EXP_INF = 8'hFF;

    mul_bf16 shared_mul (
        .clk(CLK), 
        .nRST(nRST),
        .start(mul_start), 
        .a(mul_a), 
        .b(mul_b),
        .result(mul_out), 
        .done(mul_done)
    );
    
    typedef enum logic [2:0] {
        IDLE,
        SPECIAL,
        INIT_NF,
        ITER_DF,
        REFINE_F,
        FINAL_NF,
        ROUND
    } state_t;

    state_t state, next_state;
    logic [15:0] reg_n, next_n;
    logic [15:0] reg_d, next_d;
    logic [15:0] reg_f, next_f;
    logic [7:0] res_exp, next_exp;
    logic res_sign, next_sign;
    logic [15:0] res_out, next_res_out;

    logic [15:0] mul_a, mul_b, mul_out;
    logic mul_start, mul_done;

    logic a_nan, a_inf, a_zero, b_nan, b_inf, b_zero;
    assign a_nan = (divif.in.operand1[14:7] == EXP_INF) && (divif.in.operand1[6:0] != 0);
    assign a_inf = (divif.in.operand1[14:7] == EXP_INF) && (divif.in.operand1[6:0] == 0);
    assign a_zero = (divif.in.operand1[14:7] == 0);
    assign b_nan = (divif.in.operand2[14:7] == EXP_INF) && (divif.in.operand2[6:0] != 0);
    assign b_inf = (divif.in.operand2[14:7] == EXP_INF) && (divif.in.operand2[6:0] == 0);
    assign b_zero = (divif.in.operand2[14:7] == 0);

    always_ff @(posedge CLK or negedge nRST) begin
        if (~nRST) begin
            state <= IDLE;
            reg_n <= '0;
            reg_d <= '0;
            reg_f <= '0;
            res_exp <= '0;
            res_sign <= '0;
            divif.out.result <= '0;
        end else begin
            state <= next_state;
            reg_n <= next_n;
            reg_d <= next_d;
            reg_f <= next_f;
            res_exp <= next_exp;
            res_sign <= next_sign;
            divif.out.result <= next_res_out;
        end
    end

    always_comb begin
        next_state = state;
        next_n = reg_n;
        next_d = reg_d;
        next_f = reg_f;
        next_exp = res_exp;
        next_sign = res_sign;
        next_res_out = divif.out.result;

        mul_a = '0;
        mul_b = '0;
        mul_start = 0;
        divif.out.ready_in = 0;
        divif.out.valid_out = 0;

        case (state)
            IDLE: begin
                divif.out.ready_in = 1;
                if (divif.in.valid_in) begin
                    next_sign = divif.in.operand1[15] ^ divif.in.operand2[15];
                    next_exp = divif.in.operand1[14:7] - divif.in.operand2[14:7] + BIAS;
                    
                    // Force exponents to 1.0 (0x7F) to normalize mantissas for Goldschmidt
                    next_n = {1'b0, BIAS, divif.in.operand1[6:0]};
                    next_d = {1'b0, BIAS, divif.in.operand2[6:0]};

                    // Initial Seed F0 (Magic Number)
                    next_f = 16'h7EF3 - {1'b0, BIAS, divif.in.operand2[6:0]};

                    if (a_nan || b_nan || (a_inf && b_inf) || (a_zero && b_zero) || a_inf || b_zero || a_zero || b_inf)
                        next_state = SPECIAL;
                    else
                        next_state = INIT_NF;
                end
            end

            SPECIAL: begin
                // One-cycle result for edge cases
                if (a_nan || b_nan || (a_inf && b_inf) || (a_zero && b_zero))
                    next_res_out = {1'b0, EXP_INF, 7'h40}; // NaN
                else if (a_inf || b_zero)
                    next_res_out = {next_sign, EXP_INF, 7'h00}; // Infinity
                else
                    next_res_out = {next_sign, 8'h00, 7'h00};
                
                next_state = ROUND;
            end

            INIT_NF: begin
                mul_a = reg_n;
                mul_b = reg_f;
                mul_start = 1;
                if (mul_done) begin
                    next_n = mul_out;
                    next_state = ITER_DF;
                end
            end

            ITER_DF: begin
                mul_a = reg_d;
                mul_b = reg_f;
                mul_start = 1;
                if (mul_done) begin
                    next_d = mul_out;
                    next_state = REFINE_F;
                end
            end

            REFINE_F: begin
                // F = 2 - D.
                next_f = 16'h4000 - reg_d;
                next_state = FINAL_NF;
            end

            FINAL_NF: begin
                mul_a = reg_n;
                mul_b = reg_f;
                mul_start = 1;
                if (mul_done) begin
                    next_n = mul_out;
                    next_state = ROUND;
                end
            end

            ROUND: begin
                divif.out.valid_out = 1;
                // reg_n[7] is the overflow bit from the shared_mul rounding
                if (!(a_nan || b_nan || (a_inf && b_inf) || (a_zero && b_zero) || a_inf || b_zero || a_zero || b_inf)) begin
                    if (reg_n[7]) 
                        next_res_out = {res_sign, res_exp + 1'b1, reg_n[6:0]};
                    else          
                        next_res_out = {res_sign, res_exp, reg_n[6:0]};
                end

                if (divif.in.ready_out) begin
                    next_state = IDLE;
                end
            end

            default: next_state = IDLE;
        endcase
    end

endmodule