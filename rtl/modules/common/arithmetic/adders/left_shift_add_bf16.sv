
// Fancy left shifter used for floating-point addition.

//By            : Joe Nasti
//Modified By   : Mixuan Pan 
//Last Updated  : 2/17/2026 - Convert it to parametrizable bf16 adder
//
//Module Summary:
//    Left shifts an unsigned 10 bit value until the first '1' is the most significant bit and returns the amount shifted
//
//Inputs:
//    fraction - 10 bit value to be shifted
//Outputs:
//    result   - resulting 9 bit value with a '1' in most significance and zeros shifted in from the right

`timescale 1ns/1ps

module left_shift_add_bf16 #(
    parameter MANT_B = 7
)(
    input      [MANT_B+2:0] fraction,
    output reg [MANT_B+1:0] result,
    output reg [$clog2(MANT_B):0] shifted_amount
);

    always_comb begin
        result = fraction[MANT_B+1:0];
        shifted_amount = 0;

        if (MANT_B == 'd7) begin 
            casez (fraction)
                10'b01????????: begin
                    result = {fraction[7:0], 1'd0};
                    shifted_amount = 1;
                end
                10'b001???????: begin
                    result = {fraction[6:0], 2'd0};
                    shifted_amount = 2;
                end
                10'b0001??????: begin
                    result = {fraction[5:0], 3'd0};
                    shifted_amount = 3;
                end
                10'b00001?????: begin
                    result = {fraction[4:0], 4'd0};
                    shifted_amount = 4;
                end
                10'b000001????: begin
                    result = {fraction[3:0], 5'd0};
                    shifted_amount = 5;
                end
                10'b0000001???: begin
                    result = {fraction[2:0], 6'd0};
                    shifted_amount = 6;
                end
                10'b00000001??: begin
                    result = {fraction[1:0], 7'd0};
                    shifted_amount = 7;
                end
                10'b000000001?: begin
                    result = {fraction[0], 8'd0};
                    shifted_amount = 8;
                end
                default: begin
                    result = fraction[8:0];
                    shifted_amount = 0;
                end
            endcase
        end else if (MANT_B == 'd23) begin 
            casez (fraction)
                23'b01?????????????????????: begin
                    result = {fraction[MANT_B-0:0], 1'd0};
                    shifted_amount = 'd1;
                end
                23'b1?????????????????????: begin
                    result = {fraction[MANT_B-1:0], 2'd0};
                    shifted_amount = 'd2;
                end
                23'b1????????????????????: begin
                    result = {fraction[MANT_B-2:0], 3'd0};
                    shifted_amount = 'd3;
                end
                23'b01???????????????????: begin
                    result = {fraction[MANT_B-3:0], 4'd0};
                    shifted_amount = 'd4;
                end
                23'b001??????????????????: begin
                    result = {fraction[MANT_B-4:0], 5'd0};
                    shifted_amount = 'd5;
                end
                23'b0001?????????????????: begin
                    result = {fraction[MANT_B-5:0], 6'd0};
                    shifted_amount = 'd6;
                end
                23'b00001????????????????: begin
                    result = {fraction[MANT_B-6:0], 7'd0};
                    shifted_amount = 'd7;
                end
                23'b000001???????????????: begin
                    result = {fraction[MANT_B-7:0], 8'd0};
                    shifted_amount = 'd8;
                end
                23'b0000001??????????????: begin
                    result = {fraction[MANT_B-8:0], 9'd0};
                    shifted_amount = 'd9;
                end
                23'b00000001?????????????: begin
                    result = {fraction[MANT_B-9:0], 10'd0};
                    shifted_amount = 'd10;
                end
                23'b000000001????????????: begin
                    result = {fraction[MANT_B-10:0], 11'd0};
                    shifted_amount = 'd11;
                end
                23'b0000000001???????????: begin
                    result = {fraction[MANT_B-11:0], 12'd0};
                    shifted_amount = 'd12;
                end
                23'b00000000001??????????: begin
                    result = {fraction[MANT_B-12:0], 13'd0};
                    shifted_amount = 'd13;
                end
                23'b000000000001?????????: begin
                    result = {fraction[MANT_B-13:0], 14'd0};
                    shifted_amount = 'd14;
                end
                23'b0000000000001????????: begin
                    result = {fraction[MANT_B-14:0], 15'd0};
                    shifted_amount = 'd15;
                end
                23'b00000000000001???????: begin
                    result = {fraction[MANT_B-15:0], 16'd0};
                    shifted_amount = 'd16;
                end
                23'b000000000000001??????: begin
                    result = {fraction[MANT_B-16:0], 17'd0};
                    shifted_amount = 'd17;
                end
                23'b0000000000000001?????: begin
                    result = {fraction[MANT_B-17:0], 18'd0};
                    shifted_amount = 'd18;
                end
                23'b00000000000000001????: begin
                    result = {fraction[MANT_B-18:0], 19'd0};
                    shifted_amount = 'd19;
                end
                23'b000000000000000001???: begin
                    result = {fraction[MANT_B-19:0], 20'd0};
                    shifted_amount = 'd20;
                end
                23'b0000000000000000001??: begin
                    result = {fraction[MANT_B-20:0], 21'd0};
                    shifted_amount = 'd21;
                end
                23'b00000000000000000001?: begin
                    result = {fraction[MANT_B-21:0], 22'd0};
                    shifted_amount = 'd22;
                end
                23'b000000000000000000001: begin
                    result = {fraction[MANT_B-22:0], 23'd0};
                    shifted_amount = 'd23;
                end                              
                default: begin
                    result = fraction[MANT_B+1:0];
                    shifted_amount = 0;
                end
            endcase
        end
    end
endmodule