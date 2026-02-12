// ============================================================================
// pipelined_adder_tree.sv
// Parameterized binary adder tree for MEISSA systolic array column reduction.
// Sums N FP16 products and injects an external partial sum (psum_in).
// ============================================================================

module pipelined_adder_tree #(
    parameter int N           = 4,    // Number of inputs to sum (MUST be a power of 2)
    parameter int DATA_WIDTH  = 16,   // Element width; must match add_fp16 (FP16 = 16)
    parameter int ADD_LATENCY = 2     // Pipeline depth of the adder (0 = combinational)
)(
    input  logic                    clk,
    input  logic                    nRST,
    input  logic                    stall,
    input  logic [DATA_WIDTH-1:0]   terms_in [N],   // Products from one column
    input  logic [DATA_WIDTH-1:0]   psum_in,         // Partial sum; must be valid alongside terms_in
    output logic [DATA_WIDTH-1:0]   sum_out          // Final result = sum(terms_in) + psum_in
);

    // -----------------------------------------------------------------------
    // Tree geometry  (N must be a power of 2)
    // -----------------------------------------------------------------------
    // initial assert (N > 0 && (N & (N-1)) == 0) else $fatal("N must be a power of 2");

    localparam int TREE_DEPTH = $clog2(N); // number of tree levels
    localparam int PSUM_DELAY = TREE_DEPTH * ADD_LATENCY;  // cycles psum_in must be held before final add

    // -----------------------------------------------------------------------
    // Inter-stage wires
    //   stage_data[l][k]  – data at tree level l, element k
    //   Level 0 : N elements (inputs)
    //   Level l : N >> l elements
    //   Level TREE_DEPTH : 1 element (tree result)
    // -----------------------------------------------------------------------
    logic [DATA_WIDTH-1:0] stage_data [0:TREE_DEPTH][0:N-1];

    assign stage_data[0] = terms_in;

    // -----------------------------------------------------------------------
    // Binary reduction tree  (TREE_DEPTH levels of add_fp16)
    // -----------------------------------------------------------------------
    generate
        for (genvar l = 0; l < TREE_DEPTH; l++) begin : tree_level
            localparam int PAIRS = N >> (l + 1);

            for (genvar k = 0; k < PAIRS; k++) begin : pair
                add_fp16 u_add (
                    .clk    (clk),
                    .nRST   (nRST),
                    .start  (1'b1),
                    .stall  (stall),
                    .sub    (1'b0),
                    .fp1_in (stage_data[l][2*k]),
                    .fp2_in (stage_data[l][2*k+1]),
                    .fp_out (stage_data[l+1][k]),
                    .done   ()
                );
            end
        end
    endgenerate

    // -----------------------------------------------------------------------
    // psum_in delay line  –  holds psum_in for PSUM_DELAY cycles so it
    // arrives at the final adder aligned with the tree result
    // -----------------------------------------------------------------------
    logic [DATA_WIDTH-1:0] psum_delayed;

    generate
        if (PSUM_DELAY == 0) begin : no_psum_delay
            psum_delayed = psum_in;
        end else begin : psum_delay_sr
            logic [DATA_WIDTH-1:0] psum_sr [0:PSUM_DELAY-1];

            always_ff @(posedge clk or negedge nRST) begin
                if (!nRST) begin
                    for (int i = 0; i < PSUM_DELAY; i++) begin
                        psum_sr[i] <= '0;
                    end
                end else if (!stall) begin
                    psum_sr[0] <= psum_in;
                    for (int i = 1; i < PSUM_DELAY; i++) begin
                        psum_sr[i] <= psum_sr[i - 1];
                    end
                end
            end

            psum_delayed = psum_sr[PSUM_DELAY - 1];
        end
    endgenerate

    // -----------------------------------------------------------------------
    // Final addition :  sum_out = tree_result + psum_delayed
    // -----------------------------------------------------------------------
    add_fp16 u_psum_add (
        .clk    (clk),
        .nRST   (nRST),
        .start  (1'b1),
        .stall  (stall),
        .sub    (1'b0),
        .fp1_in (stage_data[TREE_DEPTH][0]),
        .fp2_in (psum_delayed),
        .fp_out (sum_out),
        .done   ()
    );

endmodule


/*
module pipelined_adder_tree #(
    parameter int NUM_INPUTS  = 32,   // Number of inputs to sum
    parameter int DATA_WIDTH  = 16,   // Element width (FP16)
    parameter int ADD_LATENCY = 2     // Pipeline depth of the add_fp16 module
)(
    input  logic                    clk,
    input  logic                    nRST,
    input  logic                    start,     // Asserted when terms_in & psum_in are valid
    input  logic                    stall,
    input  logic [DATA_WIDTH-1:0]   terms_in [NUM_INPUTS],   // Products from one column
    input  logic [DATA_WIDTH-1:0]   psum_in,         // Partial sum (aligned with terms_in)
    output logic [DATA_WIDTH-1:0]   sum_out,         // Final result = sum(terms_in) + psum_in
    output logic                    done             // Asserted when sum_out is valid
);

    localparam int TREE_DEPTH = $clog2(NUM_INPUTS); // num_inputs rounded up to next power of 2 with psums included

    logic [DATA_WIDTH-1:0] stage_data [0:TREE_DEPTH][0:N_PADDED-1];

    generate 
        for (genvar i = 0; i < TREE_DEPTH; i++) begin : tree_rows
            localparam int PAIRS = N_PADDED >> (i + 1); // tree has 1/2 the adders of previous level
            
            for (genvar j = 0; j < PAIRS; j++) begin : adders_per_row
                add_fp16 u_add (
                    .clk    (clk),
                    .nRST   (nRST),
                    .start  (1'b1),
                    .stall  (stall),
                    .sub    (1'b0),
                    .fp1_in (stage_data[i][2*j]),
                    .fp2_in (stage_data[i][2*j+1]),
                    .fp_out (stage_data[i+1][j]),
                    .done   ()                       // timing from valid_sr
                );
            end
        end
    endgenerate

endmodule
*/