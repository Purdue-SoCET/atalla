`timescale 1ns/1ps


// logic based on this paper: https://arxiv.org/pdf/2407.09980
// Potentially relevant: https://cseweb.ucsd.edu/~kastner/papers/tech-RNS_4-2_counter.pdf



module compress_4to2(input logic x1, x2, x3, x4, cin, output logic carry, sum, cout);

    logic x1_x2_xor;
    logic x3_x4_xor;

    logic all_xor;

    assign x1_x2_xor = x1 ^ x2;
    assign x3_x4_xor = x3 ^ x4;
    assign all_xor = x1_x2_xor ^ x3_x4_xor;

    assign cout = x1_x2_xor ? x3 : x1;
    assign carry = all_xor ? cin : x4;
    assign sum = all_xor ^ cin;

endmodule


