`timescale 1ns/1ps
// Wallace Tree Multiplier for BF16
/* verilator lint_off UNUSEDSIGNAL */
module wtm_bf16_mantissa (
    input logic clk, nRST, en, 
    input logic [7:0] A_in, B_in,
    output logic [15:0] S_out, 
    output logic done 
); 
    
    logic [50:0] s; 
    logic [52:0] c; 
    logic [15:0] S; 
    logic [7:0] A, B; 
    logic unused; 

    always_ff @(posedge clk, negedge nRST) begin 
        if (!nRST) begin 
            A <= 0; 
            B <= 0; 
            S_out <= 0; 
            done <= 0; 
        end else begin
            if (en) begin 
                A <= A_in; 
                B <= B_in; 
                S_out <= S; 
                done <= 1'b1; 
            end else begin
                done <= 1'b0;
            end
        end
    end
    
    // Stage 1 

    assign S[0] = A[0] & B[0];

    ha ha01 (.a(A[0] & B[1]), .b(A[1] & B[0]), .s(S[1]), .cout(c[0]));
    
    fa fa02 (.a(A[0] & B[2]), .b(A[1] & B[1]), .cin(A[2] & B[0]), .s(s[0]), .cout(c[1]));
    fa fa03 (.a(A[0] & B[3]), .b(A[1] & B[2]), .cin(A[2] & B[1]), .s(s[1]), .cout(c[2]));
    fa fa04 (.a(A[0] & B[4]), .b(A[1] & B[3]), .cin(A[2] & B[2]), .s(s[2]), .cout(c[3]));
    fa fa05 (.a(A[0] & B[5]), .b(A[1] & B[4]), .cin(A[2] & B[3]), .s(s[3]), .cout(c[4]));
    fa fa06 (.a(A[0] & B[6]), .b(A[1] & B[5]), .cin(A[2] & B[4]), .s(s[4]), .cout(c[5]));
    fa fa07 (.a(A[0] & B[7]), .b(A[1] & B[6]), .cin(A[2] & B[5]), .s(s[5]), .cout(c[6]));
    
    ha ha08 (.a(A[1] & B[7]), .b(A[2] & B[6]), .s(s[6]), .cout(c[7]));
    ha ha09 (.a(A[3] & B[1]), .b(A[4] & B[0]), .s(s[7]), .cout(c[8]));
    
    fa fa010 (.a(A[3] & B[2]), .b(A[4] & B[1]), .cin(A[5] & B[0]), .s(s[8]), .cout(c[9]));
    fa fa011 (.a(A[3] & B[3]), .b(A[4] & B[2]), .cin(A[5] & B[1]), .s(s[9]), .cout(c[10]));
    assign S[2] = s[9];

    fa fa012 (.a(A[3] & B[4]), .b(A[4] & B[3]), .cin(A[5] & B[2]), .s(s[10]), .cout(c[11]));
    fa fa013 (.a(A[3] & B[5]), .b(A[4] & B[4]), .cin(A[5] & B[3]), .s(s[11]), .cout(c[12]));
    fa fa014 (.a(A[3] & B[6]), .b(A[4] & B[5]), .cin(A[5] & B[4]), .s(s[12]), .cout(c[13]));
    fa fa015 (.a(A[3] & B[7]), .b(A[4] & B[6]), .cin(A[5] & B[5]), .s(s[13]), .cout(c[14]));
    
    ha ha016 (.a(A[4] & B[7]), .b(A[5] & B[6]), .s(s[14]), .cout(c[15]));

    // Stage 2
    ha ha11 (.a(c[0]), .b(s[0]), .s(s[15]), .cout(c[16]));
    fa fa12 (.a(c[1]), .b(s[1]), .cin(A[3] & B[0]), .s(s[16]), .cout(c[17]));
    fa fa13 (.a(c[2]), .b(s[2]), .cin(s[7]), .s(s[17]), .cout(c[18]));
    fa fa14 (.a(c[3]), .b(s[3]), .cin(c[8]), .s(s[18]), .cout(c[19]));
    fa fa15 (.a(c[4]), .b(s[4]), .cin(c[9]),      .s(s[19]), .cout(c[20]));
    fa fa16 (.a(c[5]), .b(s[5]), .cin(c[10]),     .s(s[20]), .cout(c[21]));
    fa fa17 (.a(c[6]), .b(s[6]), .cin(c[11]),     .s(s[21]), .cout(c[22]));
    fa fa18 (.a(c[7]), .b(A[2] & B[7]), .cin(c[12]),.s(s[22]), .cout(c[23]));
    fa fa19 (.a(c[13]), .b(s[8]), .cin(c[14]),    .s(s[23]), .cout(c[24]));
    ha ha110 (.a(c[15]), .b(s[9]),               .s(s[24]), .cout(c[25]));
    fa fa111 (.a(A[6] & B[2]), .b(s[11]), .cin(A[7] & B[1]), .s(s[25]), .cout(c[26]));
    fa fa112 (.a(A[6] & B[3]), .b(s[12]), .cin(A[7] & B[2]), .s(s[26]), .cout(c[27]));
    fa fa113 (.a(A[6] & B[4]), .b(s[13]), .cin(A[7] & B[3]), .s(s[27]), .cout(c[28]));
    fa fa114 (.a(A[6] & B[5]), .b(s[14]), .cin(A[7] & B[4]), .s(s[28]), .cout(c[29]));
    fa fa115 (.a(A[6] & B[6]), .b(A[5] & B[7]), .cin(A[7] & B[5]), .s(s[29]), .cout(c[30]));
    ha ha116 (.a(A[6] & B[7]), .b(A[7] & B[6]), .s(s[30]), .cout(c[31]));

    // Stage 3
    ha ha21 (.a(c[16]), .b(s[16]), .s(s[31]), .cout(c[32]));
    assign S[3] = s[31];

    ha ha22 (.a(c[17]), .b(s[17]), .s(s[32]), .cout(c[33]));
    fa fa23 (.a(c[18]), .b(s[18]), .cin(s[8]), .s(s[33]), .cout(c[34]));
    fa fa24 (.a(c[19]), .b(s[19]), .cin(s[23]), .s(s[34]), .cout(c[35]));
    fa fa25 (.a(c[20]), .b(s[20]), .cin(c[24]), .s(s[35]), .cout(c[36]));
    fa fa26   (.a(c[21]), .b(s[21]), .cin(c[25]),  .s(s[36]), .cout(c[37]));
    fa fa27   (.a(c[22]), .b(s[22]), .cin(c[26]),  .s(s[37]), .cout(c[38]));
    fa fa28   (.a(c[23]), .b(c[13]), .cin(c[27]),  .s(s[38]), .cout(c[39]));
    ha ha29 (.a(c[14]), .b(c[28]), .s(s[39]), .cout(c[40])); 
    ha ha210 (.a(c[15]), .b(c[29]), .s(s[40]), .cout(c[41])); 
   
    // Stage 4
    ha ha31 (.a(c[32]), .b(s[32]), .s(S[4]), .cout(c[42]));
    ha ha32 (.a(c[33]), .b(s[33]), .s(s[41]), .cout(c[43]));
    ha ha33 (.a(c[34]), .b(s[34]), .s(s[42]), .cout(c[44]));
    fa fa34 (.a(c[35]), .b(s[35]), .cin(s[24]),   .s(s[43]), .cout(c[45]));
    fa fa35 (.a(c[36]), .b(s[36]), .cin(s[25]),   .s(s[44]), .cout(c[46]));
    fa fa36 (.a(c[37]), .b(s[37]), .cin(s[26]),   .s(s[45]), .cout(c[47]));
    fa fa37 (.a(c[38]), .b(s[38]), .cin(s[27]),   .s(s[46]), .cout(c[48]));
    fa fa38 (.a(c[39]), .b(s[39]), .cin(s[28]),   .s(s[47]), .cout(c[49]));
    fa fa39 (.a(c[40]), .b(s[40]), .cin(s[29]),   .s(s[48]), .cout(c[50]));
    fa fa310 (.a(c[41]), .b(c[30]), .cin(s[30]),   .s(s[49]), .cout(c[51]));
    ha ha311 (.a(c[31]), .b(A[7] & B[7]), .s(s[50]), .cout(c[52]));

    // Final Stage - Ripple Carry Adder (no writes to c[])
    logic [10:0] rcarry;
    ha ha41   (.a(c[42]), .b(s[41]),  .s(S[5]),  .cout(rcarry[1]));
    fa fa42   (.a(c[43]), .b(s[42]),  .cin(rcarry[1]),  .s(S[6]),  .cout(rcarry[2]));
    fa fa43   (.a(c[44]), .b(s[43]),  .cin(rcarry[2]),  .s(S[7]),  .cout(rcarry[3]));
    fa fa44   (.a(c[45]), .b(s[44]),  .cin(rcarry[3]),  .s(S[8]),  .cout(rcarry[4]));
    fa fa45   (.a(c[46]), .b(s[45]),  .cin(rcarry[4]),  .s(S[9]),  .cout(rcarry[5]));
    fa fa46   (.a(c[47]), .b(s[46]),  .cin(rcarry[5]),  .s(S[10]),  .cout(rcarry[6]));
    fa fa47   (.a(c[48]), .b(s[47]),  .cin(rcarry[6]),  .s(S[11]),  .cout(rcarry[7]));
    fa fa48   (.a(c[49]), .b(s[48]),  .cin(rcarry[7]),  .s(S[12]),  .cout(rcarry[8]));
    fa fa49   (.a(c[50]), .b(s[49]),  .cin(rcarry[8]),  .s(S[13]),  .cout(rcarry[9]));
    fa fa410  (.a(c[51]), .b(s[50]),  .cin(rcarry[9]),  .s(S[14]), .cout(rcarry[10]));
    ha ha411  (.a(c[52]), .b(rcarry[10]), .s(S[15]), .cout(unused)); 
    
/* verilator lint_on UNUSEDSIGNAL */
endmodule
