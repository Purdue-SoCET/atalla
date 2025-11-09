`include "sqrt_types.vh"
`include "sqrt_fp16_if.sv"

/* 
BF16 sqaure root module.
Written by Jacob Walter

Notes about design:
Uses a piecewise linear algorithim and gaurentees X ULP
X Cycles
all subnormal values are treated as 0
complaint with IEE 754

Lint/compile command: make lint folder=/common/arithmetic/sqrt
Running tests (no gui): make test folder=/common/arithmetic/sqrt tb_file=sqrt_bf16_tb.sv
Running tests (gui): make test folder=/common/arithmetic/sqrt tb_file=sqrt_bf16_tb.sv GUI=ON
*/


module sqrt_bf16 (
    input logic         CLK,
    input logic         nRST,
    sqrt_if.srif        srif
);

    localparam logic [15:0] slope_lut [0:7] = '{
        16'h3EF8, 16'h3EEB, 16'h3EDF, 16'h3ED5,
        16'h3ECC, 16'h3EC5, 16'h3EBE, 16'h3EB7
    };

    localparam logic [15:0] intercept_lut [0:7] = '{
        16'h3F03, 16'h3F0B, 16'h3F12, 16'h3F19,
        16'h3F1F, 16'h3F26, 16'h3F2C, 16'h3F32
    };

    import vector_pkg::*;
    localparam MULT_LATENCY = 3;
    localparam ADD_LATENCY = 2;
    localparam EXP_W = 8;
    localparam FRAC_W = 7;

    //input signals for latching
    logic sign, sign_n;
    logic [EXP_W - 1:0] exp, exp_n;
    logic [FRAC_W - 1:0] frac, frac_n; 
    logic [15:0] slope, slope_n;
    logic [15:0] intercept, intercept_n;
    logic valid, valid_n;

    //second pass signals and adder
    logic second_pass;
    logic [ADD_LATENCY-1:0] adder_valid_shift;
    logic [15:0] adder_out_reg;

    //third pass signals and registers to help critical path
    logic third_pass;
    logic third_mul_enable;
    logic [15:0] second_mult_latched;
    logic [15:0] third_mult_result;
    
    //exponent handling signals
    logic [EXP_W:0] exp_biased_comb;
    logic [EXP_W:0] exp_biased_reg;

    //critical path helpers
    logic [15:0] mul_out_reg;
    logic mul_done_reg;

    //holding for when writeback is not ready
    logic output_held;
    logic [15:0] output_held_val;
    logic valid_data_out_internal;

    //input logic
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            sign <= 'b0;
            exp <= 'b0;
            frac <= 'b0;
            slope <= 'b0;
            intercept <= 'b0;
            valid <= 'b0;
        end
        else begin
            sign <= sign_n;
            exp <= exp_n;
            frac <= frac_n;
            slope <= slope_n;
            intercept <= intercept_n;
            valid <= valid_n;
        end   
    end

    //input determination
    always_comb begin
        if (srif.in.valid_in & srif.out.ready_in) begin
            sign_n = srif.in.operand[15];
            exp_n = srif.in.operand[14:7];
            frac_n = srif.in.operand[6:0];
            slope_n = normal_slopes[srif.in.operand[6:4]];
            intercept_n = normal_intercepts[srif.in.operand[6:4]];
            valid_n = 'b1;
        end
        else begin
            sign_n = sign;
            exp_n = exp;
            frac_n = frac;
            slope_n = slope;
            intercept_n = intercept;
            valid_n = 'b0;
        end
    end

    //ready_input logic
    logic ready_input_reg;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST)
            ready_input_reg <= 1'b1;
        else if (srif.in.valid_in & ready_input_reg)
            ready_input_reg <= 1'b0;
        else if (valid_data_out_internal & srif.in.ready_out)
            ready_input_reg <= 1'b1;
    end

    assign srif.out.ready_in = ready_input_reg;

    logic [15:0] mul_a, mul_b, mul_out;
    logic mul_done, mul_start;
    mul_bf16 mul1 (.clk(CLK), .nRST(nRST), .start(mul_start), .a(mul_a), .b(mul_b), .result(mul_out), .done(mul_done));

    //critical path helper, maybe can go unsure at the moment
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            mul_out_reg <= 16'h0000;
            mul_done_reg <= 1'b0;
        end
        else begin
            mul_out_reg <= mul_out;
            mul_done_reg <= mul_done;
        end
    end

    //multiplier control logic
    always_comb begin
        if (third_pass) begin
            mul_start = third_mul_enable;
            mul_a = {1'b0, exp_biased_reg[4:0], 10'b0};
            mul_b = second_mult_latched;
        end
        else if (second_pass) begin
            mul_start = adder_valid_shift[ADD_LATENCY-1];
            mul_a = exp[0] ? 16'h3c00 : 16'h3da8;
            mul_b = adder_out_reg;
        end
        else begin
            mul_start = valid;
            mul_a = {1'b0, 8'd127, frac};
            mul_b = slope;
        end
    end

    //adder logic
    logic [15:0] add_out;
    logic add_start;

    //BF16 ADDER GOES HERE


    assign add_start = mul_done_reg & !second_pass & !third_pass;


    // Register adder output, maybe can go
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST)
            adder_out_reg <= '0;
        else
            adder_out_reg <= add_out;
    end

    //adder valid 
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST)
            adder_valid_shift <= '0;
        else
            adder_valid_shift <= {adder_valid_shift[ADD_LATENCY-2:0], add_start};
    end     

    //pass logic
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            second_pass <= 1'b0;
            third_pass  <= 1'b0;
        end
        else begin
            if (mul_done_reg && !second_pass && !third_pass)
                second_pass <= 1'b1;
            else if (mul_done_reg && second_pass && !third_pass)
                third_pass <= 1'b1;
            else if (mul_done_reg & third_pass) begin
                second_pass <= 1'b0;
                third_pass  <= 1'b0;
            end
        end
    end

    //register outputs of second pass
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            third_mul_enable      <= 1'b0;
            second_mult_latched   <= 16'b0;
        end
        else begin
            if (mul_done_reg && second_pass) begin
                second_mult_latched <= mul_out_reg;
                third_mul_enable    <= 1'b1;
            end
            else
                third_mul_enable <= 1'b0;
        end
    end

    // exponent computation
    logic signed [EXP_W:0] exp_unbiased;
    logic signed [EXP_W:0] exp_half;

    always_comb begin
        exp_unbiased = exp - 8'd127;    
        exp_half     = exp_unbiased >>> 1; 
        exp_biased_comb = exp_half + 8'd127;
    end
    
    // Register exp_biased at the end of second pass
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST)
            exp_biased_reg <= 6'sd0;
        else if (mul_done_reg && second_pass)
            exp_biased_reg <= exp_biased_comb;
    end

    //output
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST)
            third_mult_result <= '0;
        else if (mul_done_reg && third_pass)
            third_mult_result <= mul_out_reg;
    end

    //valid out allignment
    logic valid_out_delay;
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            valid_out_delay <= 'b0;
        end
        else begin
            valid_out_delay <= mul_done_reg & third_pass;
        end
    end

    // Special case handling
    logic special_flag;
    logic [15:0] special_result;
    logic special_flag_latched;
    logic [15:0] special_result_latched;

    logic input_is_zero;
    logic input_is_neg_zero;
    logic input_is_inf;
    logic input_is_nan;
    logic input_is_subnormal;

    always_comb begin
        special_flag   = 1'b0;
        special_result = 16'h0000;

        input_is_zero      = (exp == 8'b0)     && (frac == 7'b0);
        input_is_neg_zero  = input_is_zero     &&  sign;
        input_is_inf       = (exp == 8'b11111111) && (frac == 7'b0);
        input_is_nan       = (exp == 8'b11111111) && (frac != 7'b0);
        input_is_subnormal = (exp == 8'b0)     && (frac != 7'b0);
        if (input_is_neg_zero) begin
            special_flag   = 1'b1;
            special_result = 16'h8000;
        end
        else if (sign) begin
            special_flag   = 1'b1;
            special_result = 16'h7d00;
        end
        else if (input_is_inf) begin
            special_flag   = 1'b1;
            special_result = 16'h7c00;
        end
        else if (input_is_nan) begin
            special_flag   = 1'b1;
            special_result = 16'h7d00;
        end
        else if (input_is_subnormal || input_is_zero) begin
            special_flag   = 1'b1;
            special_result = 16'h0000;
        end
    end

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            special_flag_latched   <= 1'b0;
            special_result_latched <= 16'h0000;
        end
        else if (valid) begin
            special_flag_latched   <= special_flag;
            special_result_latched <= special_result;
        end
        else if (valid_data_out_internal & srif.in.ready_out) begin
            special_flag_latched   <= 1'b0;
            special_result_latched <= 16'h0000;
        end
    end

    //writeback ready handling
    logic [15:0] result_internal;
    assign result_internal = special_flag_latched ? special_result_latched : third_mult_result;
    assign valid_data_out_internal = valid_out_delay;

    // Output holding for when writeback is not ready
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            output_held <= 1'b0;
            output_held_val <= 16'h0000;
        end
        else begin
            if (valid_data_out_internal && !srif.in.ready_out) begin
                output_held <= 1'b1;
                output_held_val <= result_internal;
            end
            else if (output_held && srif.in.ready_out) begin
                output_held <= 1'b0;
            end
        end
    end


    //final output
    assign srif.out.valid_out = output_held || valid_data_out_internal;
    assign srif.out.result = output_held ? output_held_val : result_internal;
endmodule