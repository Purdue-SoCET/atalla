`timescale 1ns/1ps

module vexp_fsm_bf16_tb;

    // clock/reset
    logic CLK = 0;
    logic nRST = 0;
    parameter PERIOD = 10;
    
    always #(PERIOD/2) CLK = ~CLK;

    // DUT I/O
    logic [15:0] operand, a;
    logic        done, valid_in;

    logic        mul_valid_in;
    logic [15:0] mul_a, mul_b;
    logic        add_valid_in;
    logic [15:0] add_a, add_b;
    logic        sub;

    // instantiate DUT
    vexp_fsm_bf16 DUT (
        .CLK, .nRST,
        .operand, .a,
        .done, .valid_in,
        .mul_valid_in, .mul_a, .mul_b,
        .add_valid_in, .add_a, .add_b, .sub
    );

    int casenum;
    string casename;

    localparam logic [15:0] BF16_ZERO = 16'h0000; // +0
    localparam logic [15:0] BF16_ONE  = 16'h3F80; // +1
    localparam logic [15:0] BF16_1P5  = 16'h3FC0; // +1.5

    initial begin
    
        //Power On Reset
        casenum = 1;
        casename = "Power On Reset";
        
        nRST = 1'b0;

        #(PERIOD * 5);
    
        $stop;

    end

endmodule