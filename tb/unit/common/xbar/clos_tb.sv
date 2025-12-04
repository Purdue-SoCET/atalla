`timescale 1ns / 1ns

module clos_tb;
    localparam int PERIOD = 10;
    localparam int SIZE = 32;
    localparam int DWIDTH = 16;
    localparam int TAGWIDTH = $clog2(SIZE);

    logic clk, n_rst;
    logic [DWIDTH-1:0]   in   [SIZE-1:0];
    logic [TAGWIDTH-1:0] perm [SIZE-1:0];
    logic [DWIDTH-1:0]   out  [SIZE-1:0];

    initial clk = 1'b0;
    always  #5 clk = ~clk;
    
    clos #(.SIZE(SIZE), .DWIDTH(DWIDTH), .IM_OM_NUM(8), .CM_NUM(4)) DUT (clk, n_rst, in, perm, out);

    integer i;
    logic [15:0] val;
    logic [DWIDTH-1:0] exp_out [SIZE-1:0];

    initial begin
        n_rst = 0;
        val = 16'd0;

        for (i = 0; i < 32; i = i + 1) begin
            in[i] = val;
            val = val + 16'd1;
        end

        perm = {5'd14, 5'd22, 5'd25, 5'd11, 5'd21, 5'd6, 5'd15, 5'd5, 5'd30, 5'd23, 5'd18, 5'd28, 5'd19, 5'd17, 5'd31, 5'd12, 5'd26, 5'd16, 5'd13, 5'd3, 5'd9, 5'd8, 5'd0, 5'd1, 5'd10, 5'd20, 5'd7, 5'd4, 5'd29, 5'd2, 5'd24, 5'd27};

        for (i = 0; i < 32; i = i + 1) begin
            exp_out[perm[i]] = in[i];
        end

        #(PERIOD);

        n_rst = 1;
        
        
        repeat (3) #(PERIOD);
        
        for (i = 0; i < 32; i = i + 1) begin
            if(out[i] != exp_out[i]) begin
                $display("!!! WRONG output for %d. expected : %d, output: %d !!!", i, exp_out[i], out[i]);
            end
            else begin
                $display("CORRECT output for %d. expected : %d, output: %d", i, exp_out[i], out[i]);
            end
        end
        $finish;
    end

endmodule