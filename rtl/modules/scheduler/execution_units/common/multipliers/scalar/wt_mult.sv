/// Fully pipelined wallace tree multiplier
/// Three stages:
///     1) Generate partial products (1 stage)
///     2) Reduce partial products in a tree using half and full adders (lgN stages)
///     3) Reduce final two outputs (1 stage)
module wt_mult#(
    parameter int WIDTH = 32,
    parameter logic MERGE_PROD_GEN_REDUCE_STAGES=1,
    parameter int STAGE_DEPTH=8,
    parameter logic MERGE_REDUCE_FINAL_STAGES=0,
    // Generate partial products using Baugh-Wooley method
    parameter int SIGNED=0
)(
    input logic CLK, nRST,
    input logic ready,
    input logic [WIDTH-1:0] a, b,
    output logic done,
    output logic [WIDTH*2-1:0] out,
    output logic [WIDTH*2-1:0] [WIDTH-1:0] reduce_partial_prods
);
    logic [WIDTH*2-1:0] [WIDTH-1:0] partial_prods;
    logic reduce_ready, reduce_done;
    logic [WIDTH*2-1:0] out_a, out_b;
    logic [WIDTH*2-1:0] int_out;

    // Generate a sequence of [1, 2, 3, ..., WIDTH, WIDTH-1, WIDTH-2, ..., 1, 0]
    function automatic logic [WIDTH*2-1:0] [31:0] init_depth();
        logic [WIDTH*2-1 : 0] [31 : 0] result;
        for (int i = 1; i <= WIDTH*2; i++) begin
            if (i < WIDTH) begin
                result[i - 1] = i;
            end else begin
                result[i - 1] = 2 * WIDTH - i;
            end
            if (SIGNED) begin
                result[WIDTH] = WIDTH;
            end
        end
        return result;
    endfunction

    // Stage 1: Generate partial products
    wt_partial_prod_gen #(
        .WIDTH(WIDTH),
        .SIGNED(SIGNED)
    ) partial_prod_gen (
        .a(a),
        .b(b),
        .partial_prods(partial_prods)
    );

    generate
        if (MERGE_PROD_GEN_REDUCE_STAGES) begin
            assign reduce_ready = ready;
            assign reduce_partial_prods = partial_prods;
        end else begin
            always_ff @(posedge CLK, negedge nRST) begin
                if (!nRST) begin
                    reduce_ready <= 0;
                    reduce_partial_prods <= '0;
                end else begin
                    reduce_ready <= ready;
                    reduce_partial_prods <= partial_prods;
                end
            end
        end
    endgenerate

    // Stage 2: Reduce partial products
    localparam logic [WIDTH*2-1:0] [31:0] DEPTH = init_depth();

    wt_reduction #(
        .WIDTH(WIDTH),
        .STAGE_DEPTH(STAGE_DEPTH),
        .CURR_STAGE_DEPTH(STAGE_DEPTH - !MERGE_PROD_GEN_REDUCE_STAGES),
        .DEPTH(DEPTH)
    ) reduce (
        .CLK(CLK),
        .nRST(nRST),
        .ready(reduce_ready),
        .partial_prods(reduce_partial_prods),
        .done(reduce_done),
        .out_a(out_a),
        .out_b(out_b)
    );

    // Stage 3: Add remaining two values
    assign int_out = out_a + out_b;
    generate
        if (MERGE_REDUCE_FINAL_STAGES) begin
            assign out = SIGNED ? {!int_out[WIDTH*2-1], int_out[WIDTH*2-2:0]} : int_out;
            assign done = reduce_done;
        end else begin
            always_ff @(posedge CLK, negedge nRST) begin
                if (!nRST) begin
                    out <= 0;
                    done <= 0;
                end else begin
                    out <= SIGNED ? {!int_out[WIDTH*2-1], int_out[WIDTH*2-2:0]} : int_out;
                    done <= reduce_done;
                end
            end
        end
    endgenerate
endmodule