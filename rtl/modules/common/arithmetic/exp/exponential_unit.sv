`include "vector_pkg.vh"
`include "exp_if.vh"


module exponential_unit (
    input  logic clk, 
    input  logic rst_n,
    exp_if.exif  expif  // The interface port
);
    import vector_pkg::*; 

    // --- Constants ---
    localparam signed [15:0] LOG2_E_Q12 = 16'd5909;
    localparam signed [31:0] ROUND_BIT   = 32'sh1000; 
    localparam logic [14:0] OVERFLOW_MAG  = 15'h42B1; 
    localparam logic [14:0] UNDERFLOW_MAG = 15'h42B8; 
    localparam logic [14:0] NAN_MAG = 15'h7f81;

    logic [15:0] x_in;
    logic sign;
    logic [7:0] exp;
    logic [6:0] frac;

    assign x_in = expif.in.operand;
    assign x_in_sign = x_in[15];
    assign x_in_exp = x_in[14:7];
    assign x_in_frac = x_in[6:0];

    logic pipe_en;

    assign pipe_en = expif.in.ready_out || !expif.out.valid_out;

    assign expif.out.ready_in = pipe_en;

    logic [31:0] Q8_signed_st2;
    logic        is_NAN_st2, overflow_st2, underflow_st2, valid_st2;

    logic signed [8:0] z_int_st3;
    logic [6:0]        lut_mantissa_st3;
    logic              is_NAN_st3, overflow_st3, underflow_st3, valid_st3;

    // --- Internal Signals ---
    logic signed [9:0]  shift_val;
    logic [31:0]        Q8_base;
    logic signed [31:0] Q8_signed;
    logic [6:0]         lut_mantissa;
    logic signed [31:0] z_full;    
    logic signed [8:0]  z_int;     
    logic [6:0]         z_frac;  
    logic               is_NAN_comb, is_overflow_comb, is_underflow_comb;

    logic mult_done;
    logic reduce_partial_prods;
    logic signed [63:0] mult_out;

    // =========================================================
    // STAGE 1: Input Logic
    // =========================================================
    
    assign is_NAN_comb = (x_in[14:0] >= NAN_MAG);
    assign is_overflow_comb  = (x_in_sign == 1'b0 && x_in[14:0] > OVERFLOW_MAG);
    assign is_underflow_comb = (x_in_sign == 1'b1 && x_in[14:0] > UNDERFLOW_MAG);
    assign shift_val         = $signed({2'b0, x_in_exp}) - 10'd127; 

    always_comb begin
        Q8_base = '0;
        if (shift_val >= 0) 
            Q8_base = {24'b0, 1'b1, x_in_frac} << (shift_val + 1);
        else 
            Q8_base = {24'b0, 1'b1, x_in_frac} >> (-shift_val - 1);
        
        Q8_signed = x_in_sign ? (-$signed(Q8_base)) : $signed(Q8_base);
    end

    // Stage 1 -> 2 Registers
    always_ff @(posedge clk or negedge rst_n) begin
        if(!rst_n) begin
            Q8_signed_st2 <= '0;
            is_NAN_st2 <= 1'b0;
            overflow_st2  <= 1'b0;
            underflow_st2 <= 1'b0;
            valid_st2     <= 1'b0;
        end else if (pipe_en) begin
            Q8_signed_st2 <= Q8_signed;
            is_NAN_st2 <= is_NAN_comb;
            overflow_st2  <= is_overflow_comb;
            underflow_st2 <= is_underflow_comb;
            valid_st2 <= expif.in.valid_in; 
        end
    end

    // =========================================================
    // STAGE 2: Mult and LUT
    // =========================================================
    
    // USES 32-BIT MULTIPLIER FROM DIGITAL DESIGN TEAM.
    wt_mult mult32(.CLK(clk), .nRST(rst_n), .a(Q8_signed_st2), .b({16'b0,LOG2_E_Q12}), .ready(valid_st2), .done(mult_one), .out(mult_out));
    assign z_full = mult_out[31:0] + ROUND_BIT;

    //assign z_full = (Q8_signed_st2 * LOG2_E_Q12) + ROUND_BIT;
    assign z_int  = z_full[28:20];
    assign z_frac = z_full[19:13]; 

    bf16_exp_lut u_frac_lut (
        .addr_frac (z_frac),
        .mant_out  (lut_mantissa)
    );

    // Stage 2 -> 3 Registers
    always_ff @(posedge clk or negedge rst_n) begin
        if(!rst_n) begin
            z_int_st3        <= '0;
            lut_mantissa_st3 <= '0;
            is_NAN_st3 <= 1'b0;
            overflow_st3     <= 1'b0;
            underflow_st3    <= 1'b0;
            valid_st3        <= 1'b0;
        end else if (pipe_en) begin
            z_int_st3        <= z_int;
            lut_mantissa_st3 <= lut_mantissa;
            is_NAN_st3 <= is_NAN_st2;
            overflow_st3     <= overflow_st2;
            underflow_st3    <= underflow_st2;
            valid_st3        <= valid_st2;
        end
    end

    // =========================================================
    // STAGE 3: Reconstruction & Output
    // =========================================================
    
    logic signed [9:0] final_exp_calc;
    assign final_exp_calc = 10'sd127 + $signed(z_int_st3);

    // Drive Output Signals
    always_comb begin
        expif.out.result = '0;
        if (is_NAN_st3) begin
            expif.out.result = 16'h7fc0;
        end else if (overflow_st3) begin
            expif.out.result = 16'h7F80;
        end else if (underflow_st3) begin
            expif.out.result = 16'h0000;
        end else begin
            if (final_exp_calc >= 255)      expif.out.result = 16'h7F80;
            else if (final_exp_calc <= 0)   expif.out.result = 16'h0000;
            else
                expif.out.result = {1'b0, final_exp_calc[7:0], lut_mantissa_st3};
        end
    end
    
    assign expif.out.valid_out = valid_st3;

endmodule
