`include "vector_types.vh"
`include "vaddsub_if.vh"
`include "sqrt_if.vh"

module sqrt (
    input  logic        CLK,
    input  logic        nRST,
    sqrt_if.srif        srif
);    
    localparam logic [15:0] normal_slopes [0:15] = '{
        16'h37FE, 16'h37AA, 16'h3773, 16'h373F,
        16'h3711, 16'h36E3, 16'h36BB, 16'h369B,
        16'h3679, 16'h3655, 16'h3634, 16'h3615,
        16'h35FD, 16'h35E5, 16'h35C9, 16'h35AD
    };
    
    localparam logic [15:0] normal_intercepts [0:15] = '{
        16'h3800, 16'h382C, 16'h384C, 16'h386B,
        16'h3887, 16'h38A5, 16'h38C1, 16'h38D8,
        16'h38F2, 16'h390E, 16'h3928, 16'h3943,
        16'h3958, 16'h396E, 16'h3988, 16'h39A3
    };

    import vector_pkg::*;
    localparam MULT_LATENCY = 2;
    localparam ADD_LATENCY = 2;
    localparam EXP_W = 5;
    localparam FRAC_W = 10;

    logic sign, sign_n;
    logic [EXP_W - 1:0] exp, exp_n;
    logic [FRAC_W - 1:0] frac, frac_n; 
    logic [15:0] slope, slope_n;
    logic [15:0] intercept, intercept_n;
    logic valid, valid_n;

    logic second_pass;
    logic [ADD_LATENCY-1:0] adder_valid_shift;
    logic [15:0] adder_out_reg;

    logic third_pass;
    logic third_mul_enable;
    logic [15:0] second_mult_latched;
    logic [15:0] third_mult_result;
    logic signed [5:0] exp_biased;

    always_ff @(posedge CLK, negedge nRST) begin //register all the inputs for later use
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
        if (srif.valid_data_in & srif.ready) begin
            sign_n = srif.input_val.sign;
            exp_n = srif.input_val.exp;
            frac_n = srif.input_val.frac;
            slope_n = normal_slopes[srif.input_val.frac[9:6]];
            intercept_n = normal_intercepts[srif.input_val.frac[9:6]];
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

    //ready logic
    logic ready_reg;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST)
            ready_reg <= 1'b1;
        else if (srif.valid_data_in & ready_reg)
            ready_reg <= 1'b0;
        else if (srif.valid_data_out)
            ready_reg <= 1'b1;
    end

    // For testbench/interface connection
    assign srif.ready = ready_reg;

    //multiplier logic
    logic [15:0] mul_a, mul_b, mul_out;
    logic mul_done, mul_start;
    mul_fp16 mul1 (.clk(CLK), .nRST(nRST), .start(mul_start), .a(mul_a), .b(mul_b), .result(mul_out), .done(mul_done));

    always_comb begin
        if (third_pass) begin
            mul_start = third_mul_enable;
            mul_a = {1'b0, exp_biased[4:0], 10'b0};
            mul_b = second_mult_latched;
        end
        else if (second_pass) begin
            mul_start = adder_valid_shift[ADD_LATENCY-1];
            mul_a = exp[0] ? 16'h3c00 : 16'h3da8;
            mul_b = asif.out;
        end
        else begin
            mul_start = valid;
            mul_a = {1'b0, 5'd15, frac}; //nm
            mul_b = slope; //m
        end
    end

    //adder logic
    vaddsub_if asif ();
    vaddsub add1 (.CLK(CLK), .nRST(nRST), .vaddsubif(asif));
    always_comb begin
        asif.port_a = mul_out;
        asif.port_b = intercept;
        asif.sub = 'b0;
        asif.enable = mul_done & !second_pass;
    end

    // Register adder output
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST)
            adder_out_reg <= '0;
        else if (adder_valid_shift[ADD_LATENCY-1])
            adder_out_reg <= asif.out;
    end

    //adder valid logic
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST)
            adder_valid_shift <= '0;
        else
            adder_valid_shift <= {adder_valid_shift[ADD_LATENCY-2:0], (mul_done && !second_pass && !third_pass)};
    end

    //pass logic
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            second_pass <= 1'b0;
            third_pass  <= 1'b0;
        end
        else begin
            //second
            if (mul_done && !second_pass && !third_pass)
                second_pass <= 1'b1;

            //third
            else if (mul_done && second_pass && !third_pass)
                third_pass <= 1'b1;

            //reset
            else if (mul_done & third_pass) begin
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
            if (mul_done && second_pass) begin
                second_mult_latched <= mul_out;
                third_mul_enable    <= 1'b1;
            end
            else
                third_mul_enable <= 1'b0;
        end
    end

    //third pass (second mult result * exp_half)
    logic signed [5:0] exp_unbiased;
    logic signed [5:0] exp_half;

    always_comb begin
        exp_unbiased = exp - 6'd15;    
        exp_half     = exp_unbiased >>> 1; 

        exp_biased   = exp_half + 6'd15;

        // Clamp to FP16 exponent range [0,31]
        if (exp_biased < 6'sd0)
            exp_biased = 6'sd0;
        else if (exp_biased > 6'sd31)
            exp_biased = 6'sd31;
    end

    //output
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST)
            third_mult_result <= '0;
        else if (mul_done && third_pass)
            third_mult_result <= mul_out;
    end

    logic valid_out_delay;
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            valid_out_delay <= 'b0;
        end
        else begin
            valid_out_delay <= mul_done & third_pass;
        end
    end

    // Special case handling (checks the registered inputs)
    logic special_flag;
    logic [15:0] special_result;
    logic special_flag_latched;
    logic [15:0] special_result_latched;

    logic input_is_zero;
    logic input_is_neg_zero;
    logic input_is_inf;
    logic input_is_nan;
    logic input_is_subnormal;

    // Combinational special-case detection
    always_comb begin
        // Default outputs
        special_flag   = 1'b0;
        special_result = 16'h0000;

        // Decode conditions from *latched* inputs
        input_is_zero      = (exp == 5'b0)     && (frac == 10'b0);
        input_is_neg_zero  = input_is_zero     &&  sign;
        input_is_inf       = (exp == 5'b11111) && (frac == 10'b0);
        input_is_nan       = (exp == 5'b11111) && (frac != 10'b0);
        input_is_subnormal = (exp == 5'b0)     && (frac != 10'b0);

        // Special-case classification
        if (input_is_neg_zero) begin
            special_flag   = 1'b1;
            special_result = 16'h8000;   // −0
        end
        else if (sign) begin
            special_flag   = 1'b1;
            special_result = 16'h7d00;   // NaN for negative inputs
        end
        else if (input_is_inf) begin
            special_flag   = 1'b1;
            special_result = 16'h7c00;   // +Inf
        end
        else if (input_is_nan) begin
            special_flag   = 1'b1;
            special_result = 16'h7d00;   // NaN
        end
        else if (input_is_subnormal || input_is_zero) begin
            special_flag   = 1'b1;
            special_result = 16'h0000;   // +0
        end
    end

    // Sequential latching of special-case info
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            special_flag_latched   <= 1'b0;
            special_result_latched <= 16'h0000;
        end
        else if (valid) begin
            // Capture detection results when input stage valid
            special_flag_latched   <= special_flag;
            special_result_latched <= special_result;
        end
        else if (srif.valid_data_out) begin
            // Clear after output
            special_flag_latched   <= 1'b0;
            special_result_latched <= 16'h0000;
        end
    end

    // Output muxing
    assign srif.valid_data_out = valid_out_delay;
    assign srif.output_val     = special_flag_latched
                                 ? special_result_latched
                                 : third_mult_result;


endmodule