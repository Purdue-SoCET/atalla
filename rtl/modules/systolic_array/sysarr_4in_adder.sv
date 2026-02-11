module 4in_adder_AIHW #(
    parameter EXP = 5, //5 for FP16, 8 for BF16
    parameter MANTISSA = 10 //10 for FP16, 7 for BF16
    parameter PRECISION = 3 
)(
    input logic clk, n_rst,
    input logic [15:0] a, b, c, d,
    output logic [15:0] sum
);
    localparam MANT_WIDTH = 1 + MANTISSA + PRECISION + 1;
    
    //denormals are zero
    logic [15:0] a_daz, b_daz, c_daz, d_daz;
    
    logic [EXP-1:0] exp_a, exp_b, exp_c, exp_d;
    logic [MANTISSA-1:0] frac_a, frac_b, frac_c, frac_d;
    logic sign_a, sign_b, sign_c, sign_d;

    logic [EXP-1:0] exp_p, exp_m, exp_r, exp_n, exp_x, exp_y, exp_mx, exp_nx;
    logic [MANTISSA-1:0] frac_p, frac_m, frac_r, frac_n, frac_x, frac_y, frac_mx, frac_nx;
    logic sign_p, sign_m, sign_r, sign_n, sign_x, sign_y, sign_mx, sign_nx;

    logic [EXP-1:0] y_shift, m_shift, n_shift;
    logic [MANT_WIDTH-1:0] x_mant, y_shifted, m_shifted, n_shifted;

    logic y_op, m_op, n_op;

    logic [EXP-1:0] x_e_f;
    logic [MANT_WIDTH-1:0] x_f, y_shifted_f, m_shifted_f, n_shifted_f;
    logic y_op_f, m_op_f, n_op_f;

    logic special_case_f;
    logic [15:0] special_result_f;

    always_ff @(posedge clk, negedge n_rst) begin
        if (!n_rst) begin
	    x_e_f <= '0;
            x_f <= '0;
            y_shifted_f <= '0;
            m_shifted_f <= '0;
            n_shifted_f <= '0;
            y_op_f <= '0;
            m_op_f <= '0;
            n_op_f <= '0;
        end else begin
	    x_e_f <= exp_x;
            x_f <= x_mant;
            y_shifted_f <= y_shifted;
            m_shifted_f <= m_shifted;
            n_shifted_f <= n_shifted;
            y_op_f <= y_op;
            m_op_f <= m_op;
            n_op_f <= n_op;
        end
    end

    always_comb begin
	//DAZ
	a_daz = a;
        // DAZ: exp==0 and mant!=0 -> +-0 (keep sign)
        if ((a[14:10] == 5'd0) && (a[9:0] != 10'd0)) a_daz[14:0] = 15'd0;
        b_daz = b;
        if ((b[14:10] == 5'd0) && (b[9:0] != 10'd0)) b_daz[14:0] = 15'd0;
        
        c_daz = c;
        if ((c[14:10] == 5'd0) && (c[9:0] != 10'd0)) c_daz[14:0] = 15'd0;
        
        d_daz = d;
        if ((d[14:10] == 5'd0) && (d[9:0] != 10'd0)) d_daz[14:0] = 15'd0;
	
	//SPECIAL CASE DETECTION
	special_case = 1'b0;
        special_result = 16'h0000;

	is_nan_a = (a_daz[14:10] == 5'b11111) && (a_daz[9:0] != 10'b0);
        is_nan_b = (b_daz[14:10] == 5'b11111) && (b_daz[9:0] != 10'b0);
        is_nan_c = (c_daz[14:10] == 5'b11111) && (c_daz[9:0] != 10'b0);
        is_nan_d = (d_daz[14:10] == 5'b11111) && (d_daz[9:0] != 10'b0);

	is_inf_a = (a_daz[14:10] == 5'b11111) && (a_daz[9:0] == 10'b0);
        is_inf_b = (b_daz[14:10] == 5'b11111) && (b_daz[9:0] == 10'b0);
        is_inf_c = (c_daz[14:10] == 5'b11111) && (c_daz[9:0] == 10'b0);
        is_inf_d = (d_daz[14:10] == 5'b11111) && (d_daz[9:0] == 10'b0);
        
	//special cases
	if (is_nan_a || is_nan_b || is_nan_c || is_nan_d) begin
            special_case = 1'b1;
            special_result = 16'h7E00;
            // NaN propagation - use canonical qNaN
            special_case = 1'b1;
            special_result = 16'h7E00;  // Canonical positive quiet NaN
        end
        else if ((is_inf_a && is_inf_b) || (is_inf_a && is_inf_c) || (is_inf_a && is_inf_d) ||
                 (is_inf_b && is_inf_c) || (is_inf_b && is_inf_d) || (is_inf_c && is_inf_d)) 
	begin
            logic has_pos_inf, has_neg_inf;
            has_pos_inf = (is_inf_a && !a_daz[15]) || (is_inf_b && !b_daz[15]) || 
                         (is_inf_c && !c_daz[15]) || (is_inf_d && !d_daz[15]);
            has_neg_inf = (is_inf_a && a_daz[15]) || (is_inf_b && b_daz[15]) || 
                         (is_inf_c && c_daz[15]) || (is_inf_d && d_daz[15]);
            
            if (has_pos_inf && has_neg_inf) begin
                special_case = 1'b1;
                special_result = 16'h7E00; 
            end
            else if (has_pos_inf) begin
                special_case = 1'b1;
                special_result = 16'h7C00;
            end
            else begin
                special_case = 1'b1;
                special_result = 16'hFC00; 
            end
        end
        else if (is_inf_a) begin
                special_result = 16'h7E00;  // canonical NaN
            end
            else if (has_pos_inf) begin
                // Same sign (positive): result is +Inf
                special_case = 1'b1;
                special_result = 16'h7C00;  // +Inf
            end
            else begin
                // Same sign (negative): result is -Inf
                special_case = 1'b1;
                special_result = 16'hFC00;  // -Inf
            end
        end
        else if (is_inf_a) begin
            special_case = 1'b1;
	    special_result = a_daz;
        end
        else if (is_inf_b) begin
            special_case = 1'b1;
            special_result = b_daz;
        end
        else if (is_inf_c) begin
            special_case = 1'b1;
            special_result = c_daz;
        end
        else if (is_inf_d) begin
            special_case = 1'b1;
	    special_result = d_daz;
        end

        //STAGE 1
        
	sign_a = a_daz[15];
        exp_a = a_daz[14 -: EXP];
        frac_a = a_daz[MANTISSA-1:0];
        
        sign_b = b_daz[15];
        exp_b = b_daz[14 -: EXP];
        frac_b = b_daz[MANTISSA-1:0];
        
        sign_c = c_daz[15];
        exp_c = c_daz[14 -: EXP];
        frac_c = c_daz[MANTISSA-1:0];
        
        sign_d = d_daz[15];
        exp_d = d_daz[14 -: EXP];
        frac_d = d_daz[MANTISSA-1:0];

        //inversion operation flag
        y_op = y[15];
        m_op = m[15];
        n_op = n[15];
        //input comparison and assignment
	if (exp_a >= exp_b) begin
            exp_p = exp_a; frac_p = frac_a; sign_p = sign_a;
            exp_m = exp_b; frac_m = frac_b; sign_m = sign_b;
        end else begin
            exp_p = exp_b; frac_p = frac_b; sign_p = sign_b;
            exp_m = exp_a; frac_m = frac_a; sign_m = sign_a;
        end
	if (exp_c >= exp_d) begin
            exp_r = exp_c; frac_r = frac_c; sign_r = sign_c;
            exp_n = exp_d; frac_n = frac_d; sign_n = sign_d;
        end else begin
            exp_r = exp_d; frac_r = frac_d; sign_r = sign_d;
            exp_n = exp_c; frac_n = frac_c; sign_n = sign_c;
        end
	if (exp_p >= exp_r) begin
            exp_x = exp_p; frac_x = frac_p; sign_x = sign_p;
            exp_y = exp_r; frac_y = frac_r; sign_y = sign_r;
            exp_mx = exp_m; frac_mx = frac_m; sign_mx = sign_m;
            exp_nx = exp_n; frac_nx = frac_n; sign_nx = sign_n;
        end else begin
            exp_x = exp_r; frac_x = frac_r; sign_x = sign_r;
            exp_y = exp_p; frac_y = frac_p; sign_y = sign_p;
            exp_mx = exp_n; frac_mx = frac_n; sign_mx = sign_n;
            exp_nx = exp_m; frac_nx = frac_m; sign_nx = sign_m;
        end
      
        //shift var logic
        y_shift = exp_x - exp_y;
        m_shift = exp_x - exp_mx;
        n_shift = exp_x - exp_nx;
	
	//add hidden bit to mantissa
	x_mant = {(|exp_x), frac_x, {PRECISION{1'b0}}, 1'b0};

        //right shift
        y_shifted = shift_right_sticky({(|exp_y), frac_y, {PRECISION{1'b0}}, 1'b0}, y_shift);
        m_shifted = shift_right_sticky({(|exp_mx), frac_mx, {PRECISION{1'b0}}, 1'b0}, m_shift);
        n_shifted = shift_right_sticky({(|exp_nx), frac_nx, {PRECISION{1'b0}}, 1'b0}, n_shift);
        
	//operation flags
	y_op = sign_x ^ sign_y;
        m_op = sign_x ^ sign_mx;
        n_op = sign_x ^ sign_nx;

    end

    function automatic logic [MANT_WIDTH-1:0] shift_right_sticky(
	input logic [MANT_WIDTH-1:0] mant,
	input logic [EXP-1:0] shift_amt
    );
    	logic [MANT_WIDTH-1:0] result;
	logic sticky;

	if (shift_amt == 0) begin
            result = mant;
        end else if (shift_amt >= MANT_WIDTH) begin
            result = '0;
            result[0] = |mant; // sticky = OR of all bits
        end else begin
            result = mant >> shift_amt;
            sticky = |(mant & ((1 << shift_amt) - 1));
            if (sticky || result[0]) result[0] = 1'b1;
        end
        
        return result;
    endfunction

	if (shift_amt == 0) begin
            result = mant;
        end else if (shift_amt >= MANT_WIDTH) begin
            result = '0;
            result[0] = |mant;
        end else begin
            result = mant >> shift_amt;
            sticky = |(mant & ((1 << shift_amt) - 1));
            if (sticky || result[0]) result[0] = 1'b1;
        end
        
        return result;
    endfunction
endmodule
