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

    logic mul_valid_in, add_valid_in, sub;

    assign add_result = vaddsubif.out;
    assign vaddsubif.port_a = add_a;
    assign vaddsubif.port_b = add_b;
    assign vaddsubif.sub = sub;
    assign vaddsubif.enable = add_valid_in;

    //instantiating the adder
    vaddsub_if vaddsubif();
    vaddsub ADDER (.CLK(CLK), .nRST(nRST), .vaddsubif(vaddsubif));

    //instantiating the multiplier
    mul_fp16_singlecycle MULTIPLIER (.CLK(CLK), .nRST(nRST),
        .start(mul_valid_in), .a(mul_a), .b(mul_b),
        .result(mul_result), .done(done));

    bf16_to_int_frac CONVERTER (
        .bf16_in(x_div_ln2), .int_u32(int_part), .frac_fp16(fraction)
    );

    // `ifdef BF_16

        //instantiating the fsm
        vexp_fsm_bf16 FSM 
            //inputs of FSM
            (.CLK(CLK), .nRST(nRST),
            .operand(vexpif.operand), .a(vexpif.a), .valid_in(vexpif.valid_in),
            .mul_out(mul_result), .add_out(add_result), .int_part(int_part), .fraction(fraction),
            
            //outputs of FSM 
            .mul_a(mul_a), .mul_b(mul_b), .mul_valid_in(mul_valid_in),
            .add_a(add_a), .add_b(add_b), .add_valid_in(add_valid_in),
            .sub(sub), 
            .x_div_ln2(x_div_ln2),
            .result(vexpif.result));

        //instantiating the adder for bf16

    // `else
        
        //instatiating the fsm
        // vexp_fsm_fp16 FSM

        //instatiating the adder for fp16

    // `endif

endmodule