`timescale 1ns/1ns

`include "xbar_params.svh"
`include "xbar_if.sv"
`include "cabbage_singlecycle.sv"
`include "cabbage_pipelined.sv"

module cabbage_tb;
    localparam int PERIOD = 10;
    localparam int SIZE = 32;
    localparam int TAGWIDTH = $clog2(SIZE);
    localparam int STAGES = (2 * TAGWIDTH) - 1;
    localparam int BITWIDTH = STAGES * (SIZE >> 1);

    logic clk, n_rst;
    logic start, don; 
    logic [BITWIDTH-1:0] ctrl_i, ctrl_j;
    logic [TAGWIDTH-1:0] perm_i [SIZE-1:0];
    logic [TAGWIDTH-1:0] perm_j [SIZE-1:0];
    logic [BITWIDTH-1:0] exp_ctrl;
    integer mismatches;

    always #(PERIOD/2) clk = ~clk;

    cabbage_singlecycle #(.SIZE(SIZE)) DUT (.perm(perm_i), .ctrl(ctrl_i));
    cabbage_pipelined #(.SIZE(SIZE)) DUT_P (.clk(clk), .n_rst(n_rst), .perm(perm_j), .ctrl(ctrl_j));

    initial begin
        clk = 1'b0;
        n_rst = 1'b0;
        #(PERIOD/2);
        n_rst = 1'b1;

        perm_i = '{5'd14, 5'd22, 5'd25, 5'd11, 5'd21, 5'd6, 5'd15, 5'd5, 5'd30, 5'd23, 5'd18, 5'd28, 5'd19, 5'd17, 5'd31, 5'd12, 5'd26, 5'd16, 5'd13, 5'd3, 5'd9, 5'd8, 5'd0, 5'd1, 5'd10, 5'd20, 5'd7, 5'd4, 5'd29, 5'd2, 5'd24, 5'd27};
        exp_ctrl = 144'b111000110101110001100100110011100111001110000000111100000001101100101011001100000000000000000000001000011001000001110110011110001011111001001100;
        
        @(posedge clk); 

        mismatches = 0;
        for (int i = 0; i < BITWIDTH; i++) begin
            if (exp_ctrl[i] !== ctrl_i[i]) begin
                mismatches += 1; 
                $display("[SingleCycle] WRONG bit %d not equal. Expected: %d, output: %d", i, exp_ctrl[i], ctrl_i[i]);
            end
        end
        if (mismatches == 0) begin $display("[SingleCycle] Passed"); end 

        perm_j = '{5'd14, 5'd22, 5'd25, 5'd11, 5'd21, 5'd6, 5'd15, 5'd5, 5'd30, 5'd23, 5'd18, 5'd28, 5'd19, 5'd17, 5'd31, 5'd12, 5'd26, 5'd16, 5'd13, 5'd3, 5'd9, 5'd8, 5'd0, 5'd1, 5'd10, 5'd20, 5'd7, 5'd4, 5'd29, 5'd2, 5'd24, 5'd27};
        
        repeat($clog2(SIZE) + 1) @(posedge clk); // Pipelined latency

        mismatches = 0; 
        for (int i = 0; i < BITWIDTH; i++) begin
            if (exp_ctrl[i] !== ctrl_j[i]) begin
                mismatches += 1; 
                $display("[Pipelined] WRONG bit %d not equal. Expected: %d, output: %d", i, exp_ctrl[i], ctrl_j[i]);
            end
        end
        if (mismatches == 0) begin $display("[Pipelined] Passed"); end


        $finish();
    end
    
endmodule
