module sysarr_4in_adder #(
    parameter EXPONENT_SIZE = 5, 
    parameter MANTISSA_SIZE = 10,
    parameter PRECISION_BITS = 3 
)(
    input logic clk, nRST,
    input logic [15:0] a, b, c, d,
    
    output logic a_s,               
    output logic b_op, c_op, d_op,  
    output logic b_sb, c_sb, d_sb,  
    output logic [EXPONENT_SIZE - 1:0] a_e_out,
    output logic [MANTISSA_SIZE + PRECISION_BITS:0] a_f, b_f, c_f, d_f
);

    logic [15:0] x, y, m, n; 
    logic [15:0] temp;
    
    logic [EXPONENT_SIZE-1:0] y_shift_amt, m_shift_amt, n_shift_amt;
    logic [MANTISSA_SIZE + PRECISION_BITS:0] x_f_next, y_f_next, m_f_next, n_f_next;
    logic a_s_next;
    logic b_op_next, c_op_next, d_op_next;
    logic b_sb_next, c_sb_next, d_sb_next;
    logic [EXPONENT_SIZE-1:0] a_e_next;
    logic [MANTISSA_SIZE + PRECISION_BITS:0] y_full, m_full, n_full;

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            a_f <= '0;
            b_f <= '0;
            c_f <= '0;
            d_f <= '0;
            a_s <= '0;
            b_op <= '0;
            c_op <= '0;
            d_op <= '0;
            b_sb <= '0;
            c_sb <= '0;
            d_sb <= '0;
            a_e_out <= '0;
        end else begin
            a_f <= x_f_next;
            b_f <= y_f_next;
            c_f <= m_f_next;
            d_f <= n_f_next;
            a_s <= a_s_next;
            b_op <= b_op_next;
            c_op <= c_op_next;
            d_op <= d_op_next;
            b_sb <= b_sb_next;
            c_sb <= c_sb_next;
            d_sb <= d_sb_next;
            a_e_out <= a_e_next;
        end
    end

    always_comb begin        
        // Input comparison and assignment
        x = a; y = b; m = c; n = d;
        if ((x & 16'h7FFF) < (y & 16'h7FFF)) begin temp = x; x = y; y = temp; end 
        if ((m & 16'h7FFF) < (n & 16'h7FFF)) begin temp = m; m = n; n = temp; end
        if ((x & 16'h7FFF) < (m & 16'h7FFF)) begin temp = x; x = m; m = temp; end
        if ((y & 16'h7FFF) < (n & 16'h7FFF)) begin temp = y; y = n; n = temp; end
        if ((y & 16'h7FFF) < (m & 16'h7FFF)) begin temp = y; y = m; m = temp; end 

        // Operation flags (XOR sign logic)
        a_s_next  = x[15];
        b_op_next = x[15] ^ y[15]; 
        c_op_next = x[15] ^ m[15];
        d_op_next = x[15] ^ n[15];

        // Shift amount calculation
        y_shift_amt = x[14:(14-EXPONENT_SIZE+1)] - y[14:(14-EXPONENT_SIZE+1)];
        m_shift_amt = x[14:(14-EXPONENT_SIZE+1)] - m[14:(14-EXPONENT_SIZE+1)];
        n_shift_amt = x[14:(14-EXPONENT_SIZE+1)] - n[14:(14-EXPONENT_SIZE+1)];

        
        x_f_next = {1'b1, x[MANTISSA_SIZE-1:0], {PRECISION_BITS{1'b0}}};
        
        // Y, M, N (To be shifted)
        y_full = {1'b1, y[MANTISSA_SIZE-1:0], {PRECISION_BITS{1'b0}}};
        m_full = {1'b1, m[MANTISSA_SIZE-1:0], {PRECISION_BITS{1'b0}}};
        n_full = {1'b1, n[MANTISSA_SIZE-1:0], {PRECISION_BITS{1'b0}}};

        // Right shift logic
        y_f_next = y_full >> y_shift_amt;
        m_f_next = m_full >> m_shift_amt;
        n_f_next = n_full >> n_shift_amt;

        // Sticky bit logic
        b_sb_next = (y_f_next != 0) && ((y_f_next << y_shift_amt) != y_full);
        c_sb_next = (m_f_next != 0) && ((m_f_next << m_shift_amt) != m_full);
        d_sb_next = (n_f_next != 0) && ((n_f_next << n_shift_amt) != n_full);

        a_e_next = x[14:(14-EXPONENT_SIZE+1)];
    end

endmodule
