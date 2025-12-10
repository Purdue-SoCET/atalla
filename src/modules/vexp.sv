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
    logic [15:0] /*mul_result,*/
                  mul_result_fp, mul_result_bf,
                  mul_a_fp, mul_b_fp,
                  mul_a_bf, mul_b_bf,
                //  mul_a, mul_b,
                 add_result, //output from adder
                 add_a, add_b,
                 fraction,   //fraction output from converter
                 x_div_ln2, //output from FSM to go to converter
                 x_div_ln2_abs,
                 result,           //result signal
                 operand_bf16,
                 operand_fp16;
                 

    logic /*mul_valid_in,*/ mul_valid_in_fp, mul_valid_in_bf,  /*add_valid_in*/ sub, overflow, underflow, invalid, start;

    assign x_div_ln2_abs = {1'b0, x_div_ln2[14:0]};   // clear sign bit → |z|


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

        vexp_fsm_bf16 BF16_FSM 
            //inputs of FSM
            (.CLK(CLK), .nRST(nRST),
            .operand(vexpif.operand), .valid_in(vexpif.valid_in),
            .mul_out_fp(mul_result_fp), .mul_out_bf(mul_result_bf),
            .add_out(add_result), .int_part(int_part), .fraction(fraction),
            .operand_fp16(operand_fp16),
            
            //outputs of FSM 
            .mul_a_fp(mul_a_fp), .mul_b_fp(mul_b_fp), .mul_valid_in_fp(mul_valid_in_fp),
            .mul_a_bf(mul_a_bf), .mul_b_bf(mul_b_bf), .mul_valid_in_bf(mul_valid_in_bf),
            // .mul_a(mul_a), .mul_b(mul_b), .mul_valid_in(mul_valid_in),
            .add_a(add_a), .add_b(add_b),
            .sub(sub), 
            .x_div_ln2(x_div_ln2),
            .result(vexpif.result),
            .valid_out(vexpif.valid_out),
            .operand_bf16(operand_bf16)
            );

        addsub_bf16 BF16_ADDER
            //inputs
            (.clk(CLK), .nRST(nRST),
            .bf1_in(add_a), .bf2_in(add_b), .op(sub),

            //outputs
            .bf_out(add_result), .overflow(overflow), .underflow(underflow),
            .invalid(invalid));
        
        //using fp16 for higher precision
        mul_fp16_singlecycle ONE_LN2_FP16_MULTIPLIER
            (.clk(CLK), .nRST(nRST),
            .start(mul_valid_in_fp), .a(mul_a_fp), .b(mul_b_fp),
            .result(mul_result_fp), .done(done));
        
        mul_bf16 BF16_MULTIPLIER
            (.clk(CLK), .nRST(nRST),
            .start(mul_valid_in_bf), .a(mul_a_bf), .b(mul_b_bf),
            .result(mul_result_bf), .done(done));
            
        fp16_to_bf16_int_frac FP16_TO_BF16_FRACTION_CONVERTER 
            (.fp16_in(x_div_ln2_abs), .int_u32(int_part), .frac_bf16(fraction));

        // bf16_to_int_frac BF16_FRACTION_CONVERTER 
        //     (.bf16_in(x_div_ln2_abs), .int_u32(int_part), .frac_bf16(fraction));

        bf16_to_fp16 BF16_TO_FP16_CONVERTER
            (.CLK(CLK), .nRST(nRST),
            .bf16_in(operand_bf16), .fp16_out(operand_fp16));

    // `else
        
        // vexp_fsm_fp16 FP16_FSM 
        //     //inputs of FSM
        //     (.CLK(CLK), .nRST(nRST),
        //     .operand(vexpif.operand), .valid_in(vexpif.valid_in),
        //     .mul_out(mul_result), .add_out(add_result), .int_part(int_part), .fraction(fraction),
            
        //     //outputs of FSM 
        //     .mul_a(mul_a), .mul_b(mul_b), .mul_valid_in(mul_valid_in),
        //     .add_a(add_a), .add_b(add_b),
        //     .sub(sub), 
        //     .x_div_ln2(x_div_ln2),
        //     .result(vexpif.result),
        //     .valid_out(vexpif.valid_out));

        // addsub_fp16 FP16_ADDER
        //     //inputs
        //     (.clk(CLK), .nRST(nRST), .start(start),
        //     .fp1_in(add_a), .fp2_in(add_b), .op(sub),

        //     //outputs
        //     .fp_out(add_result));

        // mul_fp16_singlecycle FP16_MULTIPLIER 
        //     (.clk(CLK), .nRST(nRST),
        //     .start(mul_valid_in), .a(mul_a), .b(mul_b),
        //     .result(mul_result), .done(done));    
            
        // fp16_to_int_frac FP16_CONVERTER 
        //     (.fp16_in(x_div_ln2_abs), .int_u32(int_part), .frac_fp16(fraction));

    // `endif

endmodule