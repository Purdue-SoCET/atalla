`include "vector_if.vh"
`include "vector_types.vh"
`include "vexp_if.vh" //includes the vexp interface

module vexp (
    input logic CLK,
    input logic nRST,
    vexp_if.vexp vexpif
);

    import vector_pkg::*;

    logic [31:0] int_part; //int output from converter
    logic [15:0] mul_result, //output from multiplier
                 mul_a, mul_b,
                 add_result, //output from adder
                 add_a, add_b,
                 fraction,   //fraction output from converter
                 x_div_ln2, //output from FSM to go to converter
                 result;             //result signal

    logic mul_valid_in, /*add_valid_in*/ sub, overflow, underflow, invalid;

    // assign add_result = vaddsubif.out;
    // assign vaddsubif.port_a = add_a;
    // assign vaddsubif.port_b = add_b;
    // assign vaddsubif.sub = sub;
    // assign vaddsubif.enable = add_valid_in;

    //instantiating the adder

    //instantiating the multiplier
    // mul_fp16_singlecycle MULTIPLIER (.clk(CLK), .nRST(nRST),
    //     .start(mul_valid_in), .a(mul_a), .b(mul_b),
    //     .result(mul_result), .done(done));



    // `ifdef BF_16

        //instantiating the fsm
        vexp_fsm_bf16 BF16_FSM 
            //inputs of FSM
            (.CLK(CLK), .nRST(nRST),
            .operand(vexpif.operand), .valid_in(vexpif.valid_in),
            .mul_out(mul_result), .add_out(add_result), .int_part(int_part), .fraction(fraction),
            
            //outputs of FSM 
            .mul_a(mul_a), .mul_b(mul_b), .mul_valid_in(mul_valid_in),
            .add_a(add_a), .add_b(add_b),
            .sub(sub), 
            .x_div_ln2(x_div_ln2),
            .result(vexpif.result));

        addsub_bf16 BF16_ADDER
            //inputs
            (.clk(CLK), .nRST(nRST),
            .bf1_in(add_a), .bf2_in(add_b), .op(sub),

            //outputs
            .bf_out(add_out), .overflow(overflow), .underflow(underflow),
            .invalid(invalid));

        mul_bf16 BF16_MULTIPLIER 
            (.clk(CLK), .nRST(nRST),
            .start(mul_valid_in), .a(mul_a), .b(mul_b),
            .result(mul_result), .done(done));    
            
        bf16_to_int_frac BF16_CONVERTER 
            (.bf16_in(x_div_ln2), .int_u32(int_part), .frac_bf16(fraction));

        //instantiating the adder for bf16

    // `else
        
        //instatiating the fsm
        // vexp_fsm_fp16 FSM

        //instatiating the adder for fp16

    // `endif

endmodule