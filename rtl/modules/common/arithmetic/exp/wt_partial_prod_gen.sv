// Computes forall_i forall_j a_i * b_j and returns values in a square matrix
// based on weight.
//
// For example, with WIDTH=4, the weight=4 bin (index 2) would have [a_2*b_0, a_1*b_1, a_0*b_2]
// See partial_prods.py for a script that will generate the correct indexing
// for a wallace tree
//
// For Baugh-Wooley signed partial product generation, there are a few more steps.
// 1) Invert all final bits of the first WIDTH-1 rows
// 2) Invert all bits of the final row except the MSB
// 3) Add a 1 in the WIDTH column of the first row
module wt_partial_prod_gen#(
    parameter int WIDTH,
    parameter int SIGNED
)(
    input logic [WIDTH-1:0] a, b,
    output logic [WIDTH*2-1:0] [WIDTH-1:0] partial_prods
);
    always_comb begin
        // Init to 0
        partial_prods = '0;

        // Now group all values of the same weight (e.g. i=2,j=1 and i=1,j=2)
        // into the same output
        // partial_prods[i][j] represents the j'th value of weight 2^i
        for (int i = 0; i < WIDTH*2-1; i++) begin
            if (i < WIDTH) begin
                for (int a_i = 0; a_i <= i; a_i++) begin
                    partial_prods[i][a_i] = a[a_i] & b[i - a_i];
                end
            end else begin
                for (int a_i = i - WIDTH + 1; a_i < WIDTH; a_i++) begin
                    partial_prods[i][a_i - (i - WIDTH + 1)] = a[a_i] & b[i - a_i];
                end
            end
        end

        // Make adjustments for signed multiplication
        if (SIGNED) begin
            // Step 1
            for (int i = WIDTH-1; i < 2*WIDTH-2; i++) begin
                partial_prods[i][0] = !partial_prods[i][0];
            end

            // Step 2
            for (int i = WIDTH - 1; i < 2*WIDTH-2; i++) begin
                partial_prods[i][2*WIDTH - i - 2] = !partial_prods[i][2*WIDTH - i - 2];
            end

            // Step 3
            partial_prods[WIDTH][WIDTH-1] = 1;
        end
    end
endmodule
