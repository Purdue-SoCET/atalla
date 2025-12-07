// Fancy left shifter used for floating-point addition.
//
// Updated: expand input/output width from 10 bits to 13 bits
//
// Module Summary:
//   Left shifts an unsigned 13-bit value until the first '1' is the most
//   significant bit and returns the amount shifted.

module left_shift_fp16 (
    input  logic [12:0] fraction,
    output logic [12:0] result,
    output logic [3:0]  shifted_amount
);

    always_comb begin
        // defaults
        result         = fraction;
        shifted_amount = 4'd0;

        unique casez (fraction)

            // already normalized: MSB at bit 12
            13'b1????????????: begin
                result         = fraction;
                shifted_amount = 4'd0;
            end

            13'b01???????????: begin
                result         = {fraction[11:0], 1'b0};
                shifted_amount = 4'd1;
            end

            13'b001??????????: begin
                result         = {fraction[10:0], 2'b00};
                shifted_amount = 4'd2;
            end

            13'b0001?????????: begin
                result         = {fraction[9:0], 3'b000};
                shifted_amount = 4'd3;
            end

            13'b00001????????: begin
                result         = {fraction[8:0], 4'b0000};
                shifted_amount = 4'd4;
            end

            13'b000001???????: begin
                result         = {fraction[7:0], 5'b00000};
                shifted_amount = 4'd5;
            end

            13'b0000001??????: begin
                result         = {fraction[6:0], 6'b000000};
                shifted_amount = 4'd6;
            end

            13'b00000001?????: begin
                result         = {fraction[5:0], 7'b0000000};
                shifted_amount = 4'd7;
            end

            13'b000000001????: begin
                result         = {fraction[4:0], 8'b00000000};
                shifted_amount = 4'd8;
            end

            13'b0000000001???: begin
                result         = {fraction[3:0], 9'b000000000};
                shifted_amount = 4'd9;
            end

            13'b00000000001??: begin
                result         = {fraction[2:0], 10'b0000000000};
                shifted_amount = 4'd10;
            end

            13'b000000000001?: begin
                result         = {fraction[1:0], 11'b00000000000};
                shifted_amount = 4'd11;
            end

            13'b0000000000001: begin
                result         = {fraction[0], 12'b000000000000};
                shifted_amount = 4'd12;
            end

            default: begin
                // fraction == 0 → leave as 0 and shift 0
                result         = 13'b0;
                shifted_amount = 4'd0;
            end
        endcase
    end

endmodule
