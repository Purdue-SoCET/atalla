module 4in_adder_AIHW #(
    parameter EXPONENT_SIZE = 5, //5 for FP16, 8 for BF16
    parameter MANTISSA_SIZE = 10 //10 for FP16, 7 for BF16
    parameter PRECISION_BITS = 3 
)(
    input logic clk, nRST,
    input logic [15:0] a, b, c, d,
    output logic [15:0] sum
    output logic y_op_f, m_op_f, n_op_f;
);
    logic [15:0] x, y, m, n;
    logic [15:0] temp; //temp var for comparison of inputs
    logic [4:0] y_shift, m_shift, n_shift;
    logic [MANTISSA-1:0] y_shifted, m_shifted, n_shifted;
    logic [MANTISSA-1:0] x_f, y_shifted_f, m_shifted_f, n_shifted_f;
    logic y_op, m_op, n_op;
    logic y_op_f, m_op_f, n_op_f;

    always_ff @(posedge clk, negedge n_rst) begin
        if (!n_rst) begin
            x_f <= '0;
            y_shifted_f <= '0;
            m_shifted_f <= '0;
            n_shifted_f <= '0;
            y_op_f <= '0;
            m_op_f <= '0;
            n_op_f <= '0;
        end else begin
            x_f <= x;
            y_shifted_f <= y_shifted;
            m_shifted_f <= m_shifted;
            n_shifted_f <= n_shifted;
            y_op_f <= y_op;
            m_op_f <= m_op;
            n_op_f <= n_op;
        end
    end

    always_comb begin
        //STAGE 1
        
        //inversion operation flag
        y_op = y[15];
        m_op = m[15];
        n_op = n[15];
        //input comparison and assignment
        x = a;
        y = b;
        m = c;
        n = d;
        if (x < y) begin temp = x; x = y; y = temp; end 
        if (m < n) begin temp = m; m = n; n = temp; end
        if (x < m) begin temp = x; x = m; m = temp; end
        if (y < n) begin temp = y; y = n; n = temp; end
        if (y < m) begin temp = y; y = m; m = temp; end 

        //shift var logic
        y_shift = x[14:(14-EXP+1)] - y[14:(14-EXP+1)];
        m_shift = x[14:(14-EXP+1)] - m[14:(14-EXP+1)];
        n_shift = x[14:(14-EXP+1)] - n[14:(14-EXP+1)];

        //right shift
        y_shifted = y[MANTISSA-1 : 0] >> y_shift;
        m_shifted = m[MANTISSA-1 : 0] >> m_shift;
        n_shifted = n[MANTISSA-1 : 0] >> n_shift;
        
    end


endmodule
