`include "bf_to_int_if.sv"

module bf_to_int #()
(
    input logic CLK, nRST,
    bf_to_int_if.bf_int bf_intif
);

    localparam int signed I32_MAX = 32'sh7FFF_FFFF;
    localparam int signed I32_MIN = 32'sh8000_0000;

    logic sign;
    logic [7:0] exp;
    logic [6:0] frac;

    assign sign = bf_intif.inputBF[15];
    assign exp = bf_intif.inputBF[14:7];
    assign frac = bf_intif.inputBF[6:0];

    assign bf_intif.valid_out = bf_intif.valid_in;
    assign bf_intif.ready_in = bf_intif.ready_out;
    assign bf_intif.rdOut = bf_intif.rdIn;

    logic [8:0] mant8;
    int E;
    int shift_amt;

    logic [63:0] mag;
    logic [63:0] mag_shifted;
    logic [31:0] mag32;
    logic roundBit;



    always_comb begin : conversionUnit

        if (exp == 8'hFF) begin
            if(sign == 1'b0) begin
                bf_intif.outputInt = I32_MAX;
            end else begin
                bf_intif.outputInt = I32_MIN;
            end
        end
        else if (exp == 8'h00 && frac == 7'h00) begin
            bf_intif.outputInt = 32'd0;
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
                if ((mag_shifted > 64'd2147483647) || (roundBit && (mag_shifted > 64'd2147483646))) begin
                    //overflow = 1'b1;
                    bf_intif.outputInt = I32_MAX;
                end else begin
                    mag32 = mag_shifted[31:0];
                    if(roundBit) begin
                        bf_intif.outputInt = $signed(mag32) + 1;
                    end else begin
                        bf_intif.outputInt = $signed(mag32);
                    end
                end
            end else begin
                if (mag_shifted >= 64'd2147483648 || (roundBit && (mag_shifted >= 64'd2147483647))) begin
                    //overflow = 1'b1;
                    bf_intif.outputInt = I32_MIN;
                end else begin
                    mag32 = mag_shifted[31:0];
                    if(roundBit) begin
                        bf_intif.outputInt = -$signed(mag32) - 1;
                    end else begin
                        bf_intif.outputInt = -$signed(mag32);
                    end
                end
            end
        end
    end
endmodule