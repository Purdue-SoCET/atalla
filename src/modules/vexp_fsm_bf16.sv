`include "vaddsub_if.vh" //includes the vaddsub interface
`include "vector_if.vh"
`include "vector_types.vh"

module vexp_fsm_bf16
(
    input logic CLK,
    input logic nRST,
    input logic [15:0] operand, //input
    input logic valid_in,
    input logic [15:0] mul_out,
    input logic [15:0] add_out,
    input logic [31:0] int_part,
    input logic [15:0] fraction, 

    output logic [15:0] mul_a,
    output logic [15:0] mul_b,
    output logic mul_valid_in,
    output logic [15:0] add_a,
    output logic [15:0] add_b,
    output logic sub,
    output logic [15:0] x_div_ln2,
    output logic [15:0] result
);

    import vector_pkg::*;

    //FSM States
    typedef enum logic [3:0] {
        IDLE,
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
        S11
    } state_t;

    state_t current_state, next_state;

    logic [15:0] t, //taylor series terms
                 r, r1, //r terms //condense to one term r and ln2*r term
                 r_ln2, //r * ln(2) terms
                 x_div_ln2_out, //x/ln(2)
                 one_over_ln2, ln2, ln2_squared_div2, ln2_cubed_div6, ln2_quartic_div24, one, zero; //constants
                 
    logic [7:0] e_biased;
    logic signed [9:0] sum;

    assign one_over_ln2 = 16'h3FB9; // 1/ln(2)
    assign ln2 = 16'h3F32; //ln(2)
    assign ln2_squared_div2 = 16'h3E76; //ln(2)^2/2
    assign ln2_cubed_div6 = 16'h3D63;
    assign ln2_quartic_div24 = 16'h3C1D; //ln(2)^4/24
    assign one = 16'h3F80; //1.0 in bf16
    assign zero = 16'h0000; //0 in bf16

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
        end
        else begin
            current_state <= next_state;
        end
    end

    always_comb begin

        next_state = current_state;
        mul_valid_in = 1'b0;
        mul_a = 1'b0;
        mul_b = 1'b0;
        
        add_a = 1'b0;
        add_b = 1'b0;
        sub = 1'b0;

        case (current_state)
            IDLE: begin
                if (valid_in) begin
                    mul_valid_in = 1;
                    mul_a = operand;
                    mul_b = one_over_ln2;
                    
                    next_state = S1;
                end
                else begin
                    next_state = IDLE;
                end
            end

            S1: begin
                // mul_valid_in = 1'b1;
                // mul_a = operand;
                // mul_b = one_over_ln2;
                x_div_ln2 = mul_out;
                
                //moved adder signals one state earlier
                add_a = fraction;
                add_b = zero;
                sub = 1'b1;
                
                next_state = S2;
            end

            S2: begin
                r = add_out;
                r1 = add_out;

                mul_valid_in = 1'b1;
                mul_a = r;
                mul_b = ln2;

                next_state = S3;
            end

            S3: begin
                mul_valid_in = 1'b1;
                mul_a = r;
                mul_b = ln2;

                r_ln2 = mul_out;

                next_state = S4;
            end
            
            S4: begin
                mul_valid_in = 1'b1;
                mul_a = r;
                mul_b = r1;
                r = mul_out;
                

                // add_valid_in = 1'b1;
                add_a = one;
                add_b = r_ln2;
                t = add_out; //(1 + r)

                next_state = S5;
            end

            S5: begin
                mul_valid_in = 1'b1;
                mul_a = ln2_squared_div2;
                mul_b = r; //r^2
                r_ln2 = mul_out;

                next_state = S6;
            end

            S6: begin
                mul_valid_in = 1'b1;
                mul_a = r;
                mul_b = r1;
                r = mul_out;
                
                add_a = t;
                add_b = r_ln2;
                t = add_out; //(1 + r + r^2)

                next_state = S7;
            end

            S7: begin
                mul_valid_in = 1'b1;
                mul_a = ln2_cubed_div6;
                mul_b = r;
                r_ln2 = mul_out;

                next_state = S8;
            end

            S8: begin
                mul_valid_in = 1'b1;
                mul_a = r;
                mul_b = r1;
                r = mul_out; //(r^4)

                // add_valid_in = 1'b1;
                add_a = t;
                add_b = r_ln2;
                t = add_out; //(1 + r + r^2 + r^3)

                next_state = S9;
            end

            S9: begin
                mul_valid_in = 1'b1;
                mul_a = ln2_quartic_div24;
                mul_b = r;
                r_ln2 = mul_out;

                next_state = S10;
            end

            S10: begin
                add_a = t;
                add_b = r_ln2;
                t = add_out; //(1 + r + r^2 + r^3 + r^4)

                next_state = S11;
            end

            S11: begin
                //final stage output
                sum = int_part + 127;
                e_biased = (sum > 255) ? 8'd255 :
                           (sum < 0)   ? 8'd0   :
                            sum[7:0];
                mul_valid_in = 1'b1;
                mul_a = t;
                mul_b = {1'b0, e_biased, 7'b0000000};
                result = mul_out;
            end
        endcase         
    end


endmodule