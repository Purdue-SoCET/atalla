//By            : Joe Nasti
//Last Updated  : 10/27/2025 by Vinay Pundith - Converted to 8 bit adder for TPU Systolic Array BF16 MAC Unit
//                02/10/2006 by Mixuan Pan - extra bit for sum to handle negative value for 127 subtration that should go to underflow instead of all 1's in the exponent bit for a bf16 multiplier 
//
//Module summary:
//    Adds two unsigned 8 bit integers with ofset of 16 and signals if there is an over/underflow
//Inputs:
//    exp1/2 - 8 bit values to be summed
//Outputs:
//    sum    - 8 bit result of addition regardless of ovf/unf
//    ovf    - signal overflow has occurred
//    unf    - signal underflow has occurred

/* verilator lint_off UNUSEDSIGNAL */

`timescale 1ns/1ps

module adder_8b (
    input  logic       carry,
    input  logic [7:0] exp1,
    input  logic [7:0] exp2,
    output logic [7:0] sum, 
    output logic       ovf,
    output logic       unf, edge_case 
);

    reg [7:0] r_exp1;
    reg [7:0] r_exp2;
    reg [7:0] r_sum;


    always_comb begin
        r_exp1 = exp1 - 8'b10000000;
        r_exp2 = exp2 - 8'b10000000;
        r_sum  = r_exp1 + r_exp2;
    end

    logic [8:0] full_sum; // an adidtional bit to handle the overflow situation when subtracting 127: a negative result automatically becomes all 1's (inf)
    assign full_sum = {1'b0, exp1} + {1'b0, exp2} + {7'b0, carry} - 9'b01111111; // result estimation 
    assign sum = (exp1 + exp2 + {7'b0, carry}) - 8'b01111111;  // Changed from 5'b10000. Also added carry, which wasn't used before. add with offset
    assign ovf = (full_sum[8] & ~|full_sum[7:0]) | (r_sum[7] && ~r_exp1[7] && ~r_exp2[7]);
    assign unf = (&full_sum) | (((carry != 1) || (sum != 8'b11111111)) && (~r_sum[7] && r_exp1[7] && r_exp2[7]));

    
    assign edge_case = ~r_sum[7] & &r_sum[6:0]; // edgecase where the result is 0080 
endmodule

