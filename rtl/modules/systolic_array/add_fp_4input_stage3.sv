module add_fp_4input_stage3 #(
    parameter EXPONENT_SIZE = 5,
    parameter MANTISSA_SIZE = 10,
    parameter PRECISION_BITS = 3
) (
    input logic clk, nRST,
    input logic [$clog2(MANTISSA_SIZE)-1:0] leading_zeros,
    input logic [1:0] right_shifts,
    input logic [MANTISSA_SIZE+PRECISION_BITS+2:0] sum, 
    input logic sign,
    input logic [EXPONENT_SIZE - 1:0] exponent,
    input logic special_case,
    input logic [EXPONENT_SIZE+MANTISSA_SIZE:0] special_result,
    output logic [EXPONENT_SIZE+MANTISSA_SIZE:0] final_sum
);

    logic [MANTISSA_SIZE+PRECISION_BITS:0] shifted_sum; 
    logic [MANTISSA_SIZE+PRECISION_BITS:0] sum_reg;
    logic [$clog2(MANTISSA_SIZE)-1:0] leading_zeros_reg;
    logic sign_reg;
    logic [EXPONENT_SIZE - 1:0] exponent_reg;
    // logic sticky_in_reg;
    logic special_case_reg;
    logic [EXPONENT_SIZE+MANTISSA_SIZE:0] special_result_reg;
    logic [EXPONENT_SIZE+MANTISSA_SIZE:0] final_sum_next;
    logic [1:0] right_shift_reg;

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            sum_reg <= '0;
            leading_zeros_reg <= '0;
            sign_reg <= '0;
            exponent_reg <= '0;
            // sticky_in_reg <= '0;
            special_case_reg <= '0;
            special_result_reg <= '0;
            final_sum <= '0;
            right_shift_reg <= '0;
        end else begin
            sum_reg <= sum;
            leading_zeros_reg <= leading_zeros;
            sign_reg <= sign;
            exponent_reg <= exponent;
            // sticky_in_reg <= sticky_in;
            special_case_reg <= special_case;
            special_result_reg <= special_result;
            final_sum <= final_sum_next;
            right_shift_reg <= right_shifts;
        end
    end

    always_comb begin : reset_sticky
        if (right_shift_reg != 0) begin
            shifted_sum = sum_reg >> right_shift_reg; 
        end
        else begin
            shifted_sum = sum_reg << leading_zeros_reg; 
            shifted_sum[0] = (leading_zeros_reg >= PRECISION_BITS ? 1'b0 : sum_reg[0]);
        end
    end
 
    logic overflow; 
    logic [MANTISSA_SIZE-1:0] unrounded_mantissa; 
    logic [MANTISSA_SIZE:0] rounded_mantissa_internal;
    logic guard, round, sticky; 

    assign unrounded_mantissa = shifted_sum[MANTISSA_SIZE+PRECISION_BITS-1:PRECISION_BITS];
    assign guard = shifted_sum[PRECISION_BITS]; 
    assign round = shifted_sum[PRECISION_BITS-1];
    assign sticky = |shifted_sum[PRECISION_BITS-2:0]; 

    logic round_up;     

    assign round_up = guard & (round | sticky | unrounded_mantissa[0]);
    assign rounded_mantissa_internal = unrounded_mantissa + round_up; 
    assign overflow = rounded_mantissa_internal[MANTISSA_SIZE];

    logic [MANTISSA_SIZE-1:0] final_mantissa;
    always_comb begin
        if (overflow) begin
            final_mantissa = {MANTISSA_SIZE{1'b0}};
        end
        else begin
            final_mantissa = rounded_mantissa_internal[MANTISSA_SIZE-1:0];
        end
    end

    logic signed [EXPONENT_SIZE+1:0] new_exponent_internal; 
    logic [EXPONENT_SIZE-1:0] new_exponent;
    logic inf;

    assign new_exponent_internal = $signed({2'b0, exponent_reg}) + $signed({{(EXPONENT_SIZE+1){1'b0}}, overflow}) + $signed({2'b0, right_shifts});

    always_comb begin
        new_exponent_internal = $signed({2'b0, exponent_reg}) + $signed({{(EXPONENT_SIZE+1){1'b0}}, overflow}) + $signed({2'b0, right_shifts});
        if (right_shift_reg == 0) begin
            new_exponent_internal -= $signed({2'b0, leading_zeros_reg});
            
        end
    end
    
    always_comb begin
        inf = 0; 
        new_exponent = new_exponent_internal[EXPONENT_SIZE-1:0];
        if ($signed(new_exponent_internal) >= $signed({2'b0, {EXPONENT_SIZE{1'b1}}}) ) begin
            inf = 1'b1; 
            new_exponent = {EXPONENT_SIZE{1'b1}};
        end
        else if ($signed(new_exponent_internal) <= 0) begin
            new_exponent = {EXPONENT_SIZE{1'b0}}; 
        end
    end

    always_comb begin : final_mux
        if (special_case_reg) begin
            final_sum_next = special_result_reg; 
        end
        else if (inf) begin
            final_sum_next = {sign_reg, new_exponent, {MANTISSA_SIZE{1'b0}}};
        end
        else if (new_exponent == {EXPONENT_SIZE{1'b0}}) begin
            final_sum_next = {sign_reg, new_exponent, {MANTISSA_SIZE{1'b0}}};
        end
        else begin
            final_sum_next = {sign_reg, new_exponent, final_mantissa};
        end
    end

endmodule