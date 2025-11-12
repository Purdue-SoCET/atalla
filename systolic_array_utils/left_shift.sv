
// Fancy left shifter used for floating-point addition.

//By            : Joe Nasti
//Modified By   : Mixuan Pan 
//Last Updated  : 11/1/2025 - Convert to BF16 for systolic array MAC unit
//
//Module Summary:
//    Left shifts an unsigned 10 bit value until the first '1' is the most significant bit and returns the amount shifted
//
//Inputs:
//    fraction - 10 bit value to be shifted
//Outputs:
//    result   - resulting 10 bit value with a '1' in most significance and zeros shifted in from the right

`timescale 1ns/1ps

module left_shift (
    input      [9:0] fraction,
    output reg [9:0] result,
    output reg [3:0] shifted_amount
);

    always_comb begin
        result = fraction;
        shifted_amount = 0;
        casez (fraction)
            10'b01????????: begin
                result = {fraction[8:0], 1'd0};
                shifted_amount = 1;
            end
            10'b001???????: begin
                result = {fraction[7:0], 2'd0};
                shifted_amount = 2;
            end
            10'b0001??????: begin
                result = {fraction[6:0], 3'd0};
                shifted_amount = 3;
            end
            10'b00001?????: begin
                result = {fraction[5:0], 4'd0};
                shifted_amount = 4;
            end
            10'b000001????: begin
                result = {fraction[4:0], 5'd0};
                shifted_amount = 5;
            end
            10'b0000001???: begin
                result = {fraction[3:0], 6'd0};
                shifted_amount = 6;
            end
            10'b00000001??: begin
                result = {fraction[2:0], 7'd0};
                shifted_amount = 7;
            end
            10'b000000001?: begin
                result = {fraction[1:0], 8'd0};
                shifted_amount = 8;
            end
            10'b0000000001: begin
                result = {fraction[0], 9'd0};
                shifted_amount = 9;
            end
            default: begin
                result = fraction;
                shifted_amount = 0;
            end
        endcase
    end
endmodule
