module benes_full_tb;
    localparam int PERIOD = 10;
    localparam int SIZE = 32;
    localparam int DWIDTH = 16;
    localparam int TAGWIDTH = $clog2(SIZE);
    localparam int STAGES = (2 * TAGWIDTH) - 1;
    localparam int BITWIDTH = STAGES * (SIZE >> 1);

    logic clk, n_rst;
    logic [BITWIDTH-1:0] ctrl;
    logic [TAGWIDTH-1:0] perm [SIZE-1:0];
    logic [BITWIDTH-1:0] exp_ctrl;
    initial clk = 1'b0;
    always  #5 clk = ~clk;
    
    xbar_if #(.SIZE(SIZE), .DWIDTH(DWIDTH)) xif (.clk(clk), .n_rst(n_rst));
    benes #(.SIZE(SIZE), .DWIDTH(DWIDTH)) DUT_BENES (xif, ctrl);
    cbg_benes #(.SIZE(SIZE)) DUT_CBG (.perm(perm), .ctrl(ctrl));

    integer i;
    logic [15:0] val;
    logic [DWIDTH-1:0] exp_out [SIZE-1:0];

    // REQUIRED FOR TESTING WITH CBG

    // typedef logic [DWIDTH-1:0] vec_t [SIZE];
    // vec_t in, exp_out;

    // function automatic void make_vec(output logic [TAGW-1:0] exp_out [SIZE-1:0]);
    //     logic [DWIDTH-1:0] idx [SIZE-1:0];
    //     logic [DWIDTH-1:0] tmp;
    //     integer i, j, tmp;

    //     for (i = 0; i < 32; i++)
    //     idx[i] = i;

    //     for (i = 31; i > 0; i--) begin
    //         j = $urandom_range(0, i); // random index to swap
    //         tmp = idx[i];
    //         idx[i] = idx[j];
    //         idx[j] = tmp;
    //     end

    //     for (i = 0; i < 32; i++)
    //         exp_out[i] = idx[i];

    // endfunction

initial begin
    n_rst = 0;

    #(PERIOD);

    n_rst = 1;
    val = 16'd0;

    for (i = 0; i < 32; i = i + 1) begin
        xif.in[i] = val;
        val = val + 16'd1;
    end
    perm = {5'd14, 5'd22, 5'd25, 5'd11, 5'd21, 5'd6, 5'd15, 5'd5, 5'd30, 5'd23, 5'd18, 5'd28, 5'd19, 5'd17, 5'd31, 5'd12, 5'd26, 5'd16, 5'd13, 5'd3, 5'd9, 5'd8, 5'd0, 5'd1, 5'd10, 5'd20, 5'd7, 5'd4, 5'd29, 5'd2, 5'd24, 5'd27};

    exp_out = {5'd14, 5'd22, 5'd25, 5'd11, 5'd21, 5'd6, 5'd15, 5'd5, 5'd30, 5'd23, 5'd18, 5'd28, 5'd19, 5'd17, 5'd31, 5'd12, 5'd26, 5'd16, 5'd13, 5'd3, 5'd9, 5'd8, 5'd0, 5'd1, 5'd10, 5'd20, 5'd7, 5'd4, 5'd29, 5'd2, 5'd24, 5'd27};

    exp_ctrl = 144'b111000110101110001100100110011100111001110000000111100000001101100101011001100000000000000000000001000011001000001110110011110001011111001001100;
    
    repeat (10) #(PERIOD);
    
    for (i = 0; i < 32; i = i + 1) begin
        if(xif.out[i] != exp_out[i]) begin
            $display("wrong output for %d", i);
        end
        // $display("output %d: %d", i, xif.out[i]);
    end
    for (i = 0; i < 144; i = i + 1) begin
        if(ctrl[i] != exp_ctrl[i]) begin
            $display("wrong ctrl bit for %d", i);
        end
        // $display("output %d: %d", i, xif.out[i]);
    end
    $finish;
end

endmodule