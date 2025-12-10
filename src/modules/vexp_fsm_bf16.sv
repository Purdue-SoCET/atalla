`include "vaddsub_if.vh" //includes the vaddsub interface
`include "vector_if.vh"
`include "vector_types.vh"

module vexp_fsm_bf16
(
    input logic CLK,
    input logic nRST,
    input logic [15:0] operand, //input
    input logic valid_in,
    input logic [15:0] mul_out_fp, mul_out_bf,
    // input logic [15:0] mul_out,
    input logic [15:0] add_out,
    input logic [31:0] int_part,
    input logic [15:0] fraction, 
    input logic [15:0] operand_fp16,

    output logic [15:0] mul_a_fp, mul_a_bf,
    output logic [15:0] mul_b_fp, mul_b_bf,
    // output logic [15:0] mul_a, mul_b,
    // output logic mul_valid_in,
    output logic mul_valid_in_fp, mul_valid_in_bf,
    output logic [15:0] add_a,
    output logic [15:0] add_b,
    output logic sub,
    output logic [15:0] x_div_ln2,
    output logic [15:0] result,
    output logic valid_out,
    output logic [15:0] operand_bf16
);

    import vector_pkg::*;

    //FSM States
    typedef enum logic [3:0] {
        IDLE,
        CONV,
        S1,
        S2,
        S3,
        S4,
        S5,
        S6,
        S7,
        S8,
        S9,
        S10,
        S11,
        S12
    } state_t;

    state_t current_state, next_state;

    logic [15:0] t, //taylor series terms
                 r, r1, //r terms //condense to one term r and ln2*r term
                 r_ln2, //r * ln(2) terms
                 x_div_ln2_out, //x/ln(2)
                 one_over_ln2, ln2, ln2_squared_div2, ln2_cubed_div6, ln2_quartic_div24, one, zero, one_fourth, //constants
                 one_minus_frac;
                 
    logic [7:0] e_biased;
    logic [31:0] int_part_reg;
    logic signed [31:0] q;
    logic signed [9:0] sum;
    logic valid_in_q;
    logic start_pulse;
    logic [15:0] fraction_reg;
    // logic [15:0] x_ln2_reg;
    // logic [15:0] conv;
    // logic [15:0] result_reg;
    // logic [15:0] result_ready;
    logic sign;
    logic [7:0] exp;
    logic [6:0] mant;

    assign one_over_ln2 = 16'h3DC5; //fp16
    // assign one_over_ln2 = 16'h3FB9; // 1/ln(2) bf16
    assign ln2 = 16'h3F32; //ln(2)
    assign ln2_squared_div2 = 16'h3E76; //ln(2)^2/2
    assign ln2_cubed_div6 = 16'h3D63;
    assign ln2_quartic_div24 = 16'h3C1D; //ln(2)^4/24
    assign one = 16'h3F80; //1.0 in bf16
    assign zero = 16'h0000; //0 in bf16
    assign one_fourth = 16'h3e80;

    assign sign = operand[15];
    assign exp = operand[14:7];
    assign mant = operand[6:0];

    //instantiating the bf16 to int frac converter
    // logic [15:0] frac_part;
    // bf16_to_int_frac BF16_CONV (
    //     .bf16_in(x_div_ln2),
    //     .int_u32(int_part),
    //     .frac_fp16(frac_part)
    // );
    
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            current_state <= IDLE;
            valid_in_q <= 0;
        end
        else begin
            current_state <= next_state;
            valid_in_q <= valid_in;
        end
    end

    assign start_pulse = valid_in & ~valid_in_q;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            int_part_reg <= '0;
            fraction_reg <= '0;
            // x_ln2_reg <= '0;
            // result_reg <= '0;
        end
        else begin
            case (current_state)
                S1: begin
                    int_part_reg <= int_part;
                    fraction_reg <= fraction;
                    // x_ln2_reg <= x_div_ln2;
                end
                // S12: begin
                //     result_reg <= result_ready;
                // end
                default: begin
                    int_part_reg <= int_part_reg;
                    fraction_reg <= fraction_reg;
                    // x_ln2_reg <= x_ln2_reg;
                    // result_reg <= result_reg;
                end
            endcase
        end
    end

    always_comb begin

        next_state = current_state;
        mul_valid_in_fp = 0;
        mul_valid_in_bf = 0;
        mul_a_fp = '0;
        mul_a_bf = '0;
        mul_b_fp = '0;
        mul_b_bf = '0;
        // mul_valid_in = 0;
        // mul_a = '0;
        // mul_b = '0;
        
        add_a = '0;
        add_b = '0;
        sub = 0;

        x_div_ln2 = '0;
        result = '0;
        valid_out = 0;
        operand_bf16 = '0;

        case (current_state)
            IDLE: begin
                if (start_pulse) begin
                    if (exp == 8'hFF && mant != 0) begin //NaN case
                        next_state = S1; //don't want to issue valid_out in idle as it will break it
                                         //so just move to S1 and handle NaN there
                    end
                    else if (exp == 8'hFF && mant == 0) begin //inf case
                        next_state = S1;
                    end
                    else begin
                        operand_bf16 = operand;
                        next_state = CONV;
                        // mul_valid_in = 1;
                        // mul_a = operand;
                        // mul_b = one_over_ln2;
                        
                        next_state = CONV;
                    end
                    
                    // end
                end
                else begin
                    next_state = IDLE;
                end
            end

            CONV: begin
                // conv = operand_fp16;
                
                mul_valid_in_fp = 1;
                mul_a_fp = operand_fp16;
                mul_b_fp = one_over_ln2;

                next_state = S1;
            end

            S1: begin
                x_div_ln2 = mul_out_fp;

                //moved adder signals one state earlier
                if (exp == 8'hFF && mant != 0) begin //NaN case
                    result = 16'h7FC0; //return quiet NaN
                    valid_out = 1;
                    next_state = IDLE;
                end
                else if (exp  == 8'hFF && mant == 0) begin //inf case
                    if (sign == 0) begin// +inf
                        result = 16'h7F80;
                        valid_out = 1;
                        next_state = IDLE;
                    end
                    else begin //-inf
                        result = 16'h3F80; //return 1.0
                        valid_out = 1;
                        next_state = IDLE;
                    end
                end
                else if (operand[15] == 0) begin
                    // add_a = fraction;
                    // add_b = zero;
                    // sub = 1;
                    next_state = S2;
                end
                else begin
                    add_a = one;
                    add_b = fraction;
                    sub = 1;
                    next_state = S2;
                end
            end

            S2: begin
                
                if (operand[15] == 0) begin
                    add_a = fraction_reg; //(x - a)
                    add_b = zero;
                    sub = 1;
                    next_state = S3;
                end
                else begin //negative case ((1-fraction) - a))
                    r = add_out;
                    r1 = add_out;

                    add_a = r;
                    add_b = zero;
                    sub = 1;
                    next_state = S3;
                end
            end


            S3: begin
                r = add_out;
                r1 = add_out;

                mul_valid_in_bf = 1;
                mul_a_bf = r;
                mul_b_bf = ln2;

                next_state = S4;
            end

            S4: begin
                r_ln2 = mul_out_bf;

                mul_valid_in_bf = 1;
                mul_a_bf = r;
                mul_b_bf = r1;

                add_a = one;
                add_b = r_ln2;

                next_state = S5;
            end
            
            S5: begin
                r = mul_out_bf;

                mul_valid_in_bf = 1;
                mul_a_bf = r;
                mul_b_bf = ln2_squared_div2;
                
                t = add_out; //(1 + r)

                next_state = S6;
            end

            S6: begin
                r_ln2 = mul_out_bf;

                mul_valid_in_bf = 1;
                mul_a_bf = r;
                mul_b_bf = r1; //r^2

                add_a = t;
                add_b = r_ln2;

                next_state = S7;
            end

            S7: begin
                r = mul_out_bf;
                
                mul_valid_in_bf = 1;
                mul_a_bf = r;
                mul_b_bf = ln2_cubed_div6;
                
                t = add_out; //(1 + r + r^2)

                next_state = S8;
            end

            S8: begin
                r_ln2 = mul_out_bf;
                
                mul_valid_in_bf = 1;
                mul_a_bf = r; //r^3
                mul_b_bf = r1;

                add_a = t;
                add_b = r_ln2;

                next_state = S9;
            end

            S9: begin
                r = mul_out_bf;
                
                mul_valid_in_bf = 1;
                mul_a_bf = r;
                mul_b_bf = ln2_quartic_div24;

                t = add_out;

                next_state = S10;
            end

            S10: begin
                r_ln2 = mul_out_bf;

                add_a = t;
                add_b = r_ln2;

                next_state = S11;
            end

            S11: begin
                t = add_out; //full t series

                q = $signed(int_part_reg);     // int_part_reg driven from int_u32
                
                if (operand[15] == 0) begin //positive operand
                    sum = q + 10'sd127;
                end
                else begin //negative operand
                    sum = 10'sd127 - q - 1;
                end
                
                e_biased = (sum > 10'sd255) ? 8'd255 :
                           (sum < 10'sd0)   ? 8'd0   :
                                             sum[7:0];
                
                mul_valid_in_bf = 1;
                mul_a_bf = t;
                mul_b_bf = {1'b0, e_biased, 7'b0000000};

                next_state = S12;
            end

            S12: begin
                // result_ready = mul_out;
                // valid_out = 1;
                
                // if (vexpif.ready_out) begin
                //     result = result_reg;
                //     next_state = IDLE;
                // end
                // else begin
                //     result = result_reg;
                //     next_state = S12;
                // end

                // result = x_ln2_reg;
                result = mul_out_bf;
                valid_out = 1;
                next_state = IDLE;
            end
        endcase         
    end


endmodule