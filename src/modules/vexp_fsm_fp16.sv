`include "vaddsub_if.vh" //includes the vaddsub interface
`include "vector_if.vh"
`include "vector_types.vh"

module vexp_fsm_fp16
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
    output logic [15:0] result,
    output logic valid_out
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
        S11,
        S12,
        S13,
        S14
    } state_t;

    state_t current_state, next_state;

    logic [15:0] t, //taylor series terms
                 r, r1, //r terms //condense to one term r and ln2*r term
                 r_ln2, //r * ln(2) terms
                 x_div_ln2_out, //x/ln(2)
                 one_over_ln2, ln2, ln2_squared_div2, ln2_cubed_div6, ln2_quartic_div24, ln2_quintic_div_120, one, zero, //constants
                 one_minus_frac;
                 
    logic [4:0] e_biased;
    logic [31:0] int_part_reg;
    logic signed [31:0] q;
    logic signed [9:0] sum;
    logic valid_in_q;
    logic start_pulse;
    logic [15:0] fraction_reg;

    assign one_over_ln2 = 16'h3DC5; // 1/ln(2)
    assign ln2 = 16'h398C; //ln(2)
    assign ln2_squared_div2 = 16'h33B0; //ln(2)^2/2
    assign ln2_cubed_div6 = 16'h2B1B; //ln(2)^3/6
    assign ln2_quartic_div24 = 16'h20ED; //ln(2)^4/24
    assign ln2_quintic_div_120 = 16'h1576; //ln(2)^5/120
    assign one = 16'h3C00; //1.0 in bf16
    assign zero = 16'h0000; //0 in bf16
    
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
        end
        else begin
            case (current_state)
                S1: begin
                    int_part_reg <= int_part;
                    fraction_reg <= fraction;
                end
                default: begin
                    int_part_reg <= int_part_reg;
                    fraction_reg <= fraction_reg;
                end
            endcase
        end
    end

    always_comb begin

        next_state = current_state;
        mul_valid_in = 0;
        mul_a = '0;
        mul_b = '0;
        
        add_a = '0;
        add_b = '0;
        sub = 0;

        x_div_ln2 = '0;
        result = '0;
        valid_out = 0;

        case (current_state)
            IDLE: begin
                if (start_pulse) begin
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
                x_div_ln2 = mul_out;
                
                //moved adder signals one state earlier
                
                if (operand[15] == 0) begin
                    // add_a = fraction;
                    // add_b = zero;
                    // sub = 1;
                    next_state = S2;
                end
                else begin
                    add_a = one;
                    add_b = fraction_reg;
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

                mul_valid_in = 1;
                mul_a = r;
                mul_b = ln2;

                next_state = S4;
            end

            S4: begin
                r_ln2 = mul_out;

                mul_valid_in = 1;
                mul_a = r;
                mul_b = r1;

                add_a = one;
                add_b = r_ln2;

                next_state = S5;
            end
            
            S5: begin
                r = mul_out; //r^2

                mul_valid_in = 1;
                mul_a = r;
                mul_b = ln2_squared_div2; 
                
                t = add_out; //(1 + r)

                next_state = S6;
            end

            S6: begin
                r_ln2 = mul_out;

                mul_valid_in = 1;
                mul_a = r;
                mul_b = r1; //r^2

                add_a = t;
                add_b = r_ln2;

                next_state = S7;
            end

            S7: begin
                r = mul_out;
                
                mul_valid_in = 1;
                mul_a = r;
                mul_b = ln2_cubed_div6;
                
                t = add_out; //(1 + r + r^2)

                next_state = S8;
            end

            S8: begin
                r_ln2 = mul_out;
                
                mul_valid_in = 1;
                mul_a = r; //r^3
                mul_b = r1;

                add_a = t;
                add_b = r_ln2;

                next_state = S9;
            end

            S9: begin
                r = mul_out;
                
                mul_valid_in = 1;
                mul_a = r;
                mul_b = ln2_quartic_div24;

                t = add_out; //(1 + r + r^2 + r^3)

                next_state = S10;
            end

            S10: begin
                r_ln2 = mul_out;

                mul_valid_in = 1;
                mul_a = r; //r^4
                mul_b = r1;

                add_a = t;
                add_b = r_ln2;

                next_state = S11;
            end

            S11: begin
                r = mul_out;

                mul_valid_in = 1;
                mul_a = r;
                mul_b = ln2_quintic_div_120;

                t = add_out; //(1 + r + r^2 + r^3 + r^4)
                
                next_state = S12;

            end

            S12: begin
                r_ln2 = mul_out;

                add_a = t;
                add_b = r_ln2;

                next_state = S13;
            end

            S13: begin
                // assuming you have something like:
                // logic signed [9:0] q, sum;
                // logic [4:0]       e_biased;
                // logic [15:0]      t, mul_a, mul_b;

                t = add_out; // full t series (fp16)

                q = $signed(int_part_reg);

                if (operand[15] == 0) begin // positive operand
                    sum = q + 10'sd15;
                end
                else begin // negative operand
                    sum = 10'sd15 - q - 1;
                end

                e_biased = (sum > 10'sd31) ? 5'd31 :
                           (sum < 10'sd0)  ? 5'd0  :
                                           sum[4:0];

                mul_valid_in = 1;
                mul_a = t;
                mul_b = {1'b0, e_biased, 10'b0000000000};

                next_state = S14;

            end

            S14: begin
                result = mul_out;
                valid_out = 1;
                next_state = IDLE;
            end

        endcase         
    end


endmodule