`include "bf_to_int_if.sv"

module bf_to_int #()
(
    input logic [15:0] inputBF,
    output logic [31:0] outputInt
);

    localparam int signed I32_MAX = 32'sh7FFF_FFFF;
    localparam int signed I32_MIN = 32'sh8000_0000;

    logic sign;
    logic [7:0] exp;
    logic [6:0] frac;

    assign sign = inputBF[15];
    assign exp = inputBF[14:7];
    assign frac = inputBF[6:0];

    logic [7:0] mant8, mag;
    int E;
    int shift_amt;

    logic [63:0] mag_shifted;
    logic [31:0] mag32;
    logic roundBit;



    always_comb begin : conversionUnit

        if (exp == 8'hFF) begin
            if(sign == 1'b0) begin
                outputInt = I32_MAX;
            end else begin
                outputInt = I32_MIN;
            end
        end
        else if (exp == 8'h00 && frac == 7'h00) begin
            outputInt = 32'd0;
        end
        else begin

            E = $signed({1'b0, exp}) - 127;
            mant8 = {1'b1, frac};
            shift_amt = E - 7;
            mag = mant8;
            if (shift_amt >= 0) begin
                mag_shifted = mag << shift_amt;
            end else begin
                roundBit = mag[(-shift_amt)-1];
                mag_shifted = mag >> (-shift_amt); // trunc toward 0
            end

            if (!sign) begin
                if (mag_shifted > 32'd2147483647) begin
                    //overflow = 1'b1;
                    outputInt = I32_MAX;
                end else begin
                    mag32 = mag_shifted[31:0];
                    if(roundBit) begin
                        outputInt = $signed(mag32) + 1;
                    end else begin
                        outputInt = $signed(mag32);
                    end
                end
            end else begin
                if (mag_shifted >= 32'd2147483648) begin
                    //overflow = 1'b1;
                    outputInt = I32_MIN;
                end else begin
                    mag32 = mag_shifted[31:0];
                    if(roundBit) begin
                        outputInt = -$signed(mag32) - 1;
                    end else begin
                        outputInt = -$signed(mag32);
                    end
                end
            end
        end
    end
endmodule