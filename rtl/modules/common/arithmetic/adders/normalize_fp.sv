// Floating-point fraction normalizer (leading-one detector + barrel shift).
//
// Timing: comb only
//
// Parameters:
//   WIDTH   - bit-width of the fraction (default 13)
//
// Inputs:
//   fraction       - WIDTH-bit unsigned value to normalize
// Outputs:
//   result         - normalized WIDTH-bit value with leading 1 in MSB
//   shifted_amount - number of left-shift positions applied (0 to WIDTH-1)

`timescale 1ns/1ps

module normalize_fp #(
    parameter WIDTH = 13,
    localparam SHIFT_W = $clog2(WIDTH) + 1
) (
    input      [WIDTH-1:0]   fraction,
    output reg [WIDTH-1:0]   result,
    output reg [SHIFT_W-1:0] shifted_amount
);

    // Find leading one position
    integer i;
    reg found;

    always_comb begin
        result = fraction;
        shifted_amount = '0;
        found = 1'b0;

        // If MSB is already 1, no shift needed (shift=0)
        // Otherwise scan from bit WIDTH-2 down to 0
        for (i = WIDTH-2; i >= 0; i = i - 1) begin
            if (!found && fraction[i] && !fraction[WIDTH-1]) begin
                // Leading one is at position i, need to shift left by (WIDTH-1-i)
                result = fraction << (WIDTH - 1 - i);
                shifted_amount = WIDTH - 1 - i;
                found = 1'b1;
            end
        end

        // If fraction is 0 or MSB is already 1, defaults apply (shift=0, result=fraction)
    end
endmodule
