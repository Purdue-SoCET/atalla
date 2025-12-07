
// Fancy left shifter used for floating-point addition.

//By            : Joe Nasti
//Last Updated  : 11/17/2024 - Convert to FP16 for systolic array MAC unit
//
//Module Summary:
//    Left shifts an unsigned 13 bit value until the first '1' is the most significant bit and returns the amount shifted
//
//Inputs:
//    fraction - 13 bit value to be shifted
//Outputs:
//    result   - resulting 13 bit value with a '1' in most significance and zeros shifted in from the right

module left_shift_bf16 (
    input  logic [9:0] fraction,
    output logic [9:0] result,
    output logic [3:0] shifted_amount
);

    always_comb begin
        // defaults
        result         = fraction;
        shifted_amount = 4'd0;

        unique casez (fraction)
            // already normalized: MSB at bit 9
            10'b1?????????: begin
                result         = fraction;
                shifted_amount = 4'd0;
            end

            10'b01????????: begin
                result         = {fraction[8:0], 1'b0};
                shifted_amount = 4'd1;
            end

            10'b001???????: begin
                result         = {fraction[7:0], 2'b00};
                shifted_amount = 4'd2;
            end

            10'b0001??????: begin
                result         = {fraction[6:0], 3'b000};
                shifted_amount = 4'd3;
            end

            10'b00001?????: begin
                result         = {fraction[5:0], 4'b0000};
                shifted_amount = 4'd4;
            end

            10'b000001????: begin
                result         = {fraction[4:0], 5'b00000};
                shifted_amount = 4'd5;
            end

            10'b0000001???: begin
                result         = {fraction[3:0], 6'b000000};
                shifted_amount = 4'd6;
            end

            10'b00000001??: begin
                result         = {fraction[2:0], 7'b0000000};
                shifted_amount = 4'd7;
            end

            10'b000000001?: begin
                result         = {fraction[1:0], 8'b00000000};
                shifted_amount = 4'd8;
            end

            10'b0000000001: begin
                result         = {fraction[0], 9'b000000000};
                shifted_amount = 4'd9;
            end

            default: begin
                // fraction == 0 → leave as 0 and shift 0
                result         = 10'b0;
                shifted_amount = 4'd0;
            end
        endcase
    end

endmodule
