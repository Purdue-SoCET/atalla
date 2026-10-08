// Normalizing left shifter used by add_bf16.
//
// By            : Joe Nasti
// Modified By   : Mixuan Pan
// Last Updated  : 10/1/2026 - Replace per-width casez tables with a leading-one scan
//
// Module Summary:
//   Left shifts an unsigned (MANT_B+3)-bit value until the first '1' is in the
//   MSB, drops that leading '1', and returns the amount shifted.
//   MANT_B = 7 for bf16, 23 for fp32. Zero input returns zero with no shift.
//
// Inputs:
//   fraction       - (MANT_B+3)-bit value to be shifted
// Outputs:
//   result         - (MANT_B+2)-bit shifted value below the leading '1',
//                    zeros shifted in from the right
//   shifted_amount - number of positions shifted

`timescale 1ns/1ps

module left_shift_add_bf16 #(
    parameter MANT_B = 7
)(
    input      [MANT_B+2:0] fraction,
    output reg [MANT_B+1:0] result,
    output reg [$clog2(MANT_B):0] shifted_amount
);

    localparam int WIDTH   = MANT_B + 3;
    localparam int SHIFT_W = $clog2(MANT_B) + 1;

    always_comb begin
        result         = fraction[MANT_B+1:0];
        shifted_amount = '0;

        // Ascending scan: the highest set bit below the MSB is assigned last and wins.
        if (!fraction[WIDTH-1]) begin
            for (int i = 0; i < WIDTH-1; i++) begin
                if (fraction[i]) begin
                    result         = fraction[MANT_B+1:0] << (WIDTH-1-i);
                    shifted_amount = SHIFT_W'(WIDTH-1-i);
                end
            end
        end
    end
endmodule
