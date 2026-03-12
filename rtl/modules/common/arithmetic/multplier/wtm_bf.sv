// 8-bit wallace tree multiplier for BF16 multiplication.
// by: Mixuan Pan and Vinay Pundith, September 2025
// Modified: outputs full 16-bit product for exact FP32 path. (myles)
//
// Timing: comb only (single-cycle)

`timescale 1ns/1ps

/* verilator lint_off UNUSEDSIGNAL */
module wtm_bf (input logic [7:0] a, b, output logic [15:0] product);

genvar i, j, k, l, n, p;

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// compression stage1 (level1, level2)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------

logic [1:0][9:0] stage1_sums;
logic [1:0][7:0] stage1_carries;

generate
    for(i = 0; i <=1; i++)
    begin
        assign stage1_sums[i][0] = a[i*3] & b[0];
        assign stage1_sums[i][9] = a[i*3 +2] & b[7];
        
        ha ha_00_first (.a(a[i*3] & b[1]), .b(a[i*3 + 1] & b[0]), .s(stage1_sums[i][1]), .cout(stage1_carries[i][0]));
        ha ha_00_last (.a(a[i*3 + 1] & b[7]), .b(a[i*3 + 2] & b[6]), .s(stage1_sums[i][8]), .cout(stage1_carries[i][7]));
        
            for (j = 2; j <=7; j++)
            begin
                fa fa_00 (.a(a[i*3] & b[j]), .b(a[i*3 +1] & b[j-1]), .cin(a[i*3 + 2] & b[j-2]), .s(stage1_sums[i][j]), .cout(stage1_carries[i][j-1]));
            end

    end
endgenerate

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// compression stage2 (level1, level2)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------

logic [12:0] stage2_level1_sums;
logic [9:0] stage2_level2_sums;

logic [1:0][7:0] stage2_carries;

// stage2 level1
assign stage2_level1_sums[1:0] = stage1_sums[0][1:0];

ha ha_s2_l1_b2 (.a(stage1_sums[0][2]), .b(stage1_carries[0][0]), .s(stage2_level1_sums[2]), .cout(stage2_carries[0][0]));

generate
    for(k=3; k<=9; k++)
    begin
        fa fa_s2_l1 (.a(stage1_sums[0][k]), .b(stage1_carries[0][k-2]), .cin(stage1_sums[1][k-3]), .s(stage2_level1_sums[k]), .cout(stage2_carries[0][k-2]));
    end
endgenerate

assign stage2_level1_sums[12:10] = stage1_sums[1][9:7];

// stage2 level2
assign stage2_level2_sums[0] = stage1_carries[1][0];

ha ha_s2_l2_b1 (.a(stage1_carries[1][1]), .b(a[6] & b[0]), .s(stage2_level2_sums[1]), .cout(stage2_carries[1][0]));

generate
    for(l=2; l <= 7; l++)
    begin
        fa fa_s2_l2 (.a(stage1_carries[1][l]), .b(a[6] & b[l-1]), .cin(a[7] & b[l-2]), .s(stage2_level2_sums[l]), .cout(stage2_carries[1][l-1]));
    end
endgenerate

ha ha_s2_l2_b8 (.a(a[6] & b[7]), .b(a[7] & b[6]), .s(stage2_level2_sums[8]), .cout(stage2_carries[1][7]));

assign stage2_level2_sums[9] = a[7] & b[7];

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// compression stage3
//------------------------------------------------------------------------------------------------------------------------------------------------------------------

logic [14:0] stage3_sums;
logic [9:0] stage3_carries;

assign stage3_sums[2:0] = stage2_level1_sums[2:0];

ha ha_s3_l1_b3 (.a(stage2_level1_sums[3]), .b(stage2_carries[0][0]), .s(stage3_sums[3]), .cout(stage3_carries[0]));
ha ha_s3_l1_b4 (.a(stage2_level1_sums[4]), .b(stage2_carries[0][1]), .s(stage3_sums[4]), .cout(stage3_carries[1]));

generate
    for(n = 5; n <=10; n++)
    begin
        fa fa_s3_l1 (.a(stage2_level1_sums[n]), .b(stage2_carries[0][n-3]), .cin(stage2_level2_sums[n-5]), .s(stage3_sums[n]), .cout(stage3_carries[n-3]));
    end
endgenerate

ha ha_s3_l1_b11 (.a(stage2_level1_sums[11]), .b(stage2_level2_sums[6]), .s(stage3_sums[11]), .cout(stage3_carries[8]));
ha ha_s3_l1_b12 (.a(stage2_level1_sums[12]), .b(stage2_level2_sums[7]), .s(stage3_sums[12]), .cout(stage3_carries[9]));

assign stage3_sums[14:13] = stage2_level2_sums[9:8];

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// compression stage4
//------------------------------------------------------------------------------------------------------------------------------------------------------------------

logic [14:0] stage4_sums;
logic [10:0] stage4_carries;

assign stage4_sums[3:0] = stage3_sums[3:0];

ha ha_s4_l1_b4 (.a(stage3_sums[4]), .b(stage3_carries[0]), .s(stage4_sums[4]), .cout(stage4_carries[0]));
ha ha_s4_l1_b5 (.a(stage3_sums[5]), .b(stage3_carries[1]), .s(stage4_sums[5]), .cout(stage4_carries[1]));
ha ha_s4_l1_b6 (.a(stage3_sums[6]), .b(stage3_carries[2]), .s(stage4_sums[6]), .cout(stage4_carries[2]));

generate
    for(p=7; p <=13; p++)
    begin
        fa fa_s4_l1 (.a(stage3_sums[p]), .b(stage3_carries[p-4]), .cin(stage2_carries[1][p-7]), .s(stage4_sums[p]), .cout(stage4_carries[p-4]));
    end
endgenerate

ha ha_s4_l1_b14 (.a(stage3_sums[14]), .b(stage2_carries[1][7]), .s(stage4_sums[14]), .cout(stage4_carries[10]));

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Final CPA - output full 16-bit product, no truncation
//------------------------------------------------------------------------------------------------------------------------------------------------------------------

logic [16:0] raw_product;

assign raw_product[4:0] = stage4_sums[4:0];
assign raw_product[16:5] = ({1'b0, stage4_sums[14:5]} + stage4_carries);

assign product = raw_product[15:0]; // full 16-bit product (bit 16 is always 0 for 8x8)

endmodule
