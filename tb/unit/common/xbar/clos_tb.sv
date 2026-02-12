`timescale 1ns / 1ns

module clos_tb;
    localparam int PERIOD = 10;
    localparam int CLOS_SIZE = 32;
    localparam int CLOS_DWIDTH = 16;
    localparam int TAGWIDTH = $clog2(CLOS_SIZE);

    logic clk, n_rst;
    logic [CLOS_DWIDTH-1:0]   in   [CLOS_SIZE-1:0];
    logic [TAGWIDTH-1:0] perm [CLOS_SIZE-1:0];
    logic [CLOS_DWIDTH-1:0]   out  [CLOS_SIZE-1:0];

    initial clk = 1'b0;
    always  #5 clk = ~clk;

    xbar_if #(.SIZE(CLOS_SIZE), .DWIDTH(CLOS_DWIDTH)) xif (.clk(clk), .n_rst(n_rst));
    // clos_singlecycle #(.CLOS_SIZE(CLOS_SIZE), .CLOS_DWIDTH(CLOS_DWIDTH), .IM_OM_NUM(8), .CM_NUM(4)) DUT (xif);
    // clos_2cycle #(.CLOS_SIZE(CLOS_SIZE), .CLOS_DWIDTH(CLOS_DWIDTH), .IM_OM_NUM(8), .CM_NUM(4)) DUT (xif);
    clos #(.CLOS_SIZE(CLOS_SIZE), .CLOS_DWIDTH(CLOS_DWIDTH), .IM_OM_NUM(8), .CM_NUM(4)) DUT (xif);

    integer i;
    logic [15:0] val;
    logic [CLOS_DWIDTH-1:0] exp_out [CLOS_SIZE-1:0];

    genvar gi;
    generate
    for (gi = 0; gi < CLOS_SIZE; gi++) begin
        assign out[gi] = xif.out[gi];
    end
    endgenerate


    initial begin
        n_rst = 0;
        val = 16'd0;

        perm = '{
        5'd14, 5'd22, 5'd25, 5'd11, 5'd21, 5'd6, 5'd15, 5'd5,
        5'd30, 5'd23, 5'd18, 5'd28, 5'd19, 5'd17, 5'd31, 5'd12,
        5'd26, 5'd16, 5'd13, 5'd3,  5'd9,  5'd8,  5'd0,  5'd1,
        5'd10, 5'd20, 5'd7,  5'd4,  5'd29, 5'd2,  5'd24, 5'd27
        };

        xif.en = 1;
        
        for (i = 0; i < 32; i = i + 1) begin
            xif.in[i].din = val;
            xif.in[i].shift = perm[i];
            val = val + 16'd1;
        end


        for (i = 0; i < 32; i = i + 1) begin
            exp_out[perm[i]] = xif.in[i].din;
        end

        @(negedge clk);

        n_rst = 1;

        @(posedge clk);
        @(posedge clk);
        @(negedge clk);
        
        for (i = 0; i < 32; i = i + 1) begin
            if (out[i] !== exp_out[i]) begin
                $display("!!! WRONG output for %0d. expected: %0d, got: %0d !!!",
                        i, exp_out[i], out[i]);
            end else begin
                $display("CORRECT output for %0d. expected: %0d, got: %0d",
                        i, exp_out[i], out[i]);
            end
        end

        $finish;
    end

endmodule