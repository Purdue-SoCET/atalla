`include "vector_pkg.vh"
`include "exp_if.vh"

import vector_pkg::*; 

module exponential_unit (
    input  logic clk, 
    input  logic rst_n,
    exp_if.exif  ex  // The interface port
);

    // --- Constants ---
    localparam signed [15:0] LOG2_E_Q12 = 16'd5909;
    localparam signed [31:0] ROUND_BIT   = 32'sh1000; 
    localparam logic [14:0] OVERFLOW_MAG  = 15'h42B1; 
    localparam logic [14:0] UNDERFLOW_MAG = 15'h42B8; 

    bf16_t x_in;
    assign x_in = bf16_t'(ex.in.operand);

    logic pipe_en;
    

    assign pipe_en = ex.in.ready_out || !ex.out.valid_out;

    assign ex.out.ready_in = pipe_en;

    logic [31:0] Q8_signed_st2;
    logic        overflow_st2, underflow_st2, valid_st2;

    logic signed [8:0] z_int_st3;
    logic [6:0]        lut_mantissa_st3;
    logic              overflow_st3, underflow_st3, valid_st3;

    // --- Internal Signals ---
    logic signed [9:0]  shift_val;
    logic [31:0]        Q8_base;
    logic signed [31:0] Q8_signed;
    logic [6:0]         lut_mantissa;
    logic signed [31:0] z_full;    
    logic signed [8:0]  z_int;     
    logic [6:0]         z_frac;  
    logic               is_overflow_comb, is_underflow_comb;

    // =========================================================
    // STAGE 1: Input Logic
    // =========================================================
    
    assign is_overflow_comb  = (x_in.sign == 1'b0 && x_in[14:0] > OVERFLOW_MAG);
    assign is_underflow_comb = (x_in.sign == 1'b1 && x_in[14:0] > UNDERFLOW_MAG);
    assign shift_val         = $signed({2'b0, x_in.exp}) - 10'd127; 

    always_comb begin
        Q8_base = '0;
        if (shift_val >= 0) 
            Q8_base = {24'b0, 1'b1, x_in.frac} << (shift_val + 1);
        else 
            Q8_base = {24'b0, 1'b1, x_in.frac} >> (-shift_val - 1);
        
        Q8_signed = x_in.sign ? (-$signed(Q8_base)) : $signed(Q8_base);
    end

    // Stage 1 -> 2 Registers
    always_ff @(posedge clk or negedge rst_n) begin
        if(!rst_n) begin
            Q8_signed_st2 <= '0;
            overflow_st2  <= 1'b0;
            underflow_st2 <= 1'b0;
            valid_st2     <= 1'b0;
        end else if (pipe_en) begin
            Q8_signed_st2 <= Q8_signed;
            overflow_st2  <= is_overflow_comb;
            underflow_st2 <= is_underflow_comb;
            valid_st2 <= ex.in.valid_in; 
        end
    end

    // =========================================================
    // STAGE 2: Mult and LUT
    // =========================================================

    assign z_full = (Q8_signed_st2  * LOG2_E_Q12) + ROUND_BIT;
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
            overflow_st3     <= 1'b0;
            underflow_st3    <= 1'b0;
            valid_st3        <= 1'b0;
        end else if (pipe_en) begin
            z_int_st3        <= z_int;
            lut_mantissa_st3 <= lut_mantissa;
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
        ex.out.result = '0;
        if (overflow_st3) 
            ex.out.result = 16'h7F80; 
        else if (underflow_st3) 
            ex.out.result = 16'h0000;
        else begin
            if (final_exp_calc >= 255)      ex.out.result = 16'h7F80;
            else if (final_exp_calc <= 0)   ex.out.result = 16'h0000;
            else                            ex.out.result = {1'b0, final_exp_calc[7:0], lut_mantissa_st3};
        end
    end
    
    assign ex.out.valid_out = valid_st3;

endmodule