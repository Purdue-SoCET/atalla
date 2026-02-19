`include "vdiv_if.vh"
`include "mul_if.vh"

module div_bf16pipeline_1mul (
    input logic CLK, nRST,
    vdiv_if.div divif
);

    // localparam [7:0] BIAS = 8'h7F;
    // localparam [7:0] EXP_INF = 8'hFF;

    // typedef struct packed {
    //     logic [7:0] exp;
    //     logic sign, start;
    // } fTm;

    // // Multiplier signals
    // logic [15:0] mul_a, mul_b, mul_out, init;
    // logic mul_start, mul_done;

    // // Pipeline Signals
    // fTm n_fetTmul, fetTmul;

    // // Initial Guess
    // assign init = (16'h7EF3 - divif.in.operand2 & 16'h7FFF) & 16'h7FFF; 

    // // Map Inputs
    // assign mul_a = {8'b0, divif.operand1[6:0] << 1, 0};
    // assign mul_b = init;
    // assign n_fetTmul.start = divif.in.valid_in;

    // // Exponent + Sign Calculation
    // assign n_fetTmul.exp = divif.in.operand1[14:7] - divif.in.operand2[14:7];
    // assign n_fetTmul.sign = divif.in.operand1[15] | divif.in.operand2[15];

    // always_ff @(posedge CLK, negedge nRST) begin : FETCH_FF
    //     if(~nRST) mul_start <= 0;
    //     else      mul_start <= n_mul_start;
    // end

    // // *********************************************************************************************
    // // FETCH to MULT
    // // *********************************************************************************************
    // mul_bf16_fu mul (
    //     .clk(CLK), 
    //     .nRST(nRST),
    //     .start(mul_start), 
    //     .a(mul_a), 
    //     .b(mul_b),
    //     .result(mul_out), 
    //     .done(mul_done)
    // );
    
    // *********************************************************************************************
    // FETCH to MULT
    // *********************************************************************************************

endmodule