`define ADD_TO_PARTIAL_PRODS(idx, value)                            \
    next_next_partial_prods[(idx)][curr_depth[(idx)]] = (value);    \
    curr_depth[(idx)] += 1;

/// Reduces a tree of length 2*WIDTH, height WIDTH to a tree of height 2 using
/// roughly lgN stages of full and half adders.
/// General strategy is as follows:
///     1) If the current weight has more than 3 wires, greedily use full
//          adders and optionally use a final half adder
//      2) If the current weight has 3 wires, use a half adder if we
//         don't have a carry, otherwise use a full adder
//      3) If the current weight has 2 wires, use a half adder except in the
//         cases where we haven't seen a carry (where adding a half adder
//         would generate a carry where none previously existed), or in the
//         case where the next weight has more than 2 wires (can reduce using
//         a full adders which provide 3:2 compression instead of 2:2
//         compression).
//  See reduction_tree.py for more information on the next_depth function.
module wt_reduction#(
    parameter int WIDTH,
    parameter int STAGE_DEPTH,
    parameter int CURR_STAGE_DEPTH,
    parameter logic [2*WIDTH-1:0] [31:0] DEPTH
) (
    input logic CLK, nRST,
    input logic ready,
    input logic [WIDTH*2-1:0] [WIDTH-1:0] partial_prods,
    output logic done,
    output logic [WIDTH*2-1:0] out_a, out_b
);
    function automatic logic final_layer();
        for (int i = 0; i < WIDTH*2; i++) begin
            if (DEPTH[i] > 2) return 0;
        end
        return 1;
    endfunction

    function automatic logic [2*WIDTH-1:0] [31:0] next_depth();
        logic seen_carry;
        logic [31:0] saved_depth;
        // Don't use a half adder if we only have 2 bits in a position and all
        // previous positions have 1 or 2 bits
        seen_carry = 1'b0;
        next_depth = '0;
        saved_depth = 0;

        for (int i = 0; i < WIDTH*2; i++) begin
            saved_depth = DEPTH[i];
            // Add in all previous bits, we'll reduce them using half and full
            // adders in the next step
            next_depth[i] += DEPTH[i];

            if (saved_depth < 2) begin
                seen_carry = 0;
            end else if (saved_depth == 2) begin
                // Only emit half adders if we've seen 3 before (meaning there
                // will be a carry), but not if the carry would require a half
                // adder in the next stage
                if (seen_carry && (DEPTH[i + 1] == 1 || DEPTH[i + 1] == 2)) begin // Use a half adder
                    next_depth[i] -= 1;
                    next_depth[i + 1] += 1;
                    seen_carry = 1;
                end
            end else if (saved_depth == 3) begin
                if (!seen_carry) begin // Use a half adder
                    next_depth[i] -= 1;
                    next_depth[i + 1] += 1;
                end else begin // Use a full adder
                    next_depth[i] -= 2;
                    next_depth[i + 1] += 1;
                end
                seen_carry = 1;
            end else begin
                while (saved_depth > 1) begin
                    seen_carry = 1;
                    if (saved_depth > 2) begin // Use a full adder
                        next_depth[i] -= 2;
                        next_depth[i + 1] += 1;
                        saved_depth -= 3;
                    end else begin // Use a half adder
                        next_depth[i] -= 1;
                        next_depth[i + 1] += 1;
                        saved_depth -= 2;
                    end
                end
            end
        end
        return next_depth;
    endfunction

    generate
        if (final_layer()) begin
            assign done = ready;

            // Only two layers left, gather them into out_a and out_b
            always_comb begin
                for (int i = 0; i < WIDTH*2; i++) begin
                    out_a[i] = partial_prods[i][0];
                    out_b[i] = partial_prods[i][1];
                end
            end
        end else begin
            logic next_ready;
            logic [WIDTH*2-1:0] [WIDTH-1:0] next_next_partial_prods, next_partial_prods;

            localparam logic [2*WIDTH-1:0] [31:0] NEXT_DEPTH = next_depth();

            // Next stage in the reduction
            wt_reduction #(
                .WIDTH(WIDTH),
                .STAGE_DEPTH(STAGE_DEPTH),
                .CURR_STAGE_DEPTH((CURR_STAGE_DEPTH + STAGE_DEPTH - 1) % STAGE_DEPTH),
                .DEPTH(NEXT_DEPTH)
            ) reduce (
                .CLK(CLK),
                .nRST(nRST),
                .ready(next_ready),
                .partial_prods(next_partial_prods),
                .done(done),
                .out_a(out_a),
                .out_b(out_b)
            );

            if (CURR_STAGE_DEPTH == 0) begin
                always_ff @(posedge CLK, negedge nRST) begin
                    if (!nRST) begin
                        next_ready <= 0;
                        next_partial_prods <= '0;
                    end else begin
                        next_ready <= ready;
                        next_partial_prods <= next_next_partial_prods;
                    end
                end
            end else begin
                assign next_ready = ready;
                assign next_partial_prods = next_next_partial_prods;
            end

            logic seen_carry;
            logic [2*WIDTH-1:0] [31:0] curr_depth;
            int saved_depth;
            logic [1:0] half_adder_out;
            logic [1:0] full_adder_out;
            always_comb begin
                seen_carry = 0;
                curr_depth = '0;
                next_next_partial_prods = '0;
                saved_depth = 0;
                half_adder_out = '0;
                full_adder_out = '0;

                // See `next_depth` for more info on placement of half and
                // full adders
                for (int i = 0; i < WIDTH*2; i++) begin
                    saved_depth = DEPTH[i];
                    half_adder_out = '0;
                    full_adder_out = '0;

                    for (int j = DEPTH[i]; j < WIDTH; j++) begin
                        if (ready && partial_prods[i][j]) begin
                            $warning("bit set outside DEPTH: %0d, i: %0d, j: %0d\n", DEPTH[i], i, j);
                        end
                    end

                    if (saved_depth < 2) begin
                        seen_carry = 0;
                        if (saved_depth == 1) begin
                            `ADD_TO_PARTIAL_PRODS(i, partial_prods[i][0]);
                        end
                    end else if (saved_depth == 2) begin
                        if (seen_carry && (DEPTH[i + 1] == 1 || DEPTH[i + 1] == 2)) begin
                            // Create half adder
                            half_adder_out = partial_prods[i][0] + partial_prods[i][1];
                            `ADD_TO_PARTIAL_PRODS(i, half_adder_out[0]);
                            `ADD_TO_PARTIAL_PRODS(i + 1, half_adder_out[1]);
                            seen_carry = 1;
                        end else begin
                            `ADD_TO_PARTIAL_PRODS(i, partial_prods[i][0]);
                            `ADD_TO_PARTIAL_PRODS(i, partial_prods[i][1]);
                        end
                    end else if (saved_depth == 3) begin
                        if (!seen_carry) begin
                            // Create half adder
                            half_adder_out = partial_prods[i][0] + partial_prods[i][1];
                            `ADD_TO_PARTIAL_PRODS(i, half_adder_out[0]);
                            `ADD_TO_PARTIAL_PRODS(i + 1, half_adder_out[1]);
                            `ADD_TO_PARTIAL_PRODS(i, partial_prods[i][2]);
                        end else begin
                            // Create full adder
                            full_adder_out = partial_prods[i][0] + partial_prods[i][1] + partial_prods[i][2];
                            `ADD_TO_PARTIAL_PRODS(i, full_adder_out[0]);
                            `ADD_TO_PARTIAL_PRODS(i + 1, full_adder_out[1]);
                        end
                        seen_carry = 1;
                    end else begin
                        while (saved_depth > 1) begin
                            if (saved_depth > 2) begin // Use a full adder
                                // Create full adder
                                full_adder_out = partial_prods[i][saved_depth - 3] + partial_prods[i][saved_depth - 2] + partial_prods[i][saved_depth - 1];
                                `ADD_TO_PARTIAL_PRODS(i, full_adder_out[0]);
                                `ADD_TO_PARTIAL_PRODS(i + 1, full_adder_out[1]);

                                saved_depth -= 3;
                            end else begin // Use a half adder
                                // Create half adder
                                half_adder_out = partial_prods[i][saved_depth - 2] + partial_prods[i][saved_depth - 1];
                                `ADD_TO_PARTIAL_PRODS(i, half_adder_out[0]);
                                `ADD_TO_PARTIAL_PRODS(i + 1, half_adder_out[1]);

                                saved_depth -= 2;
                            end
                            seen_carry = 1;
                        end
                        if (saved_depth == 1) begin
                            `ADD_TO_PARTIAL_PRODS(i, partial_prods[i][0]);
                        end
                    end
                end
            end

            logic [2*WIDTH-1:0] expected_out;
            logic [2*WIDTH-1:0] actual_out;
            // Check that the sum of bits is the same across `partial_prods`
            always_comb begin
                expected_out = 0;
                actual_out = 0;
                for (int i = 0; i < WIDTH*2; i++) begin
                    for (int j = 0; j < WIDTH; j++) begin
                        expected_out += partial_prods[i][j] << i;
                        actual_out += next_next_partial_prods[i][j] << i;
                    end
                end
                //if (ready && expected_out != actual_out) begin
                //    $warning("error in reduction: expected: %0x, actual: %0x\n", expected_out, actual_out);
                //end
            end
        end
    endgenerate
endmodule