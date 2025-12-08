`include "vreduction_alu_if.vh"

module reduction_tree #(
    parameter LANES = 16        // Must be power of 2
) (
    input  logic CLK,
    input  logic nRST,
    input  logic [LANES-1:0][15:0] data_in,  // Packed input: LANES elements of 16 bits each
    input  logic [1:0]  alu_op,              // Now stays constant during operation
    input  logic        valid_in,
    output logic [15:0] data_out,
    output logic        valid_out
);

    localparam TREE_DEPTH = $clog2(LANES);
    localparam ALU_LATENCY = 2;

    // Simplified storage: one register per tree level for data
    logic [15:0] tree_data [0:TREE_DEPTH][LANES-1:0];
    
    // Valid signal pipeline - tracks when each level completes
    logic [TREE_DEPTH:0] level_valid;

    // Input stage (tree level 0)
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            for (int i = 0; i < LANES; i++)
                tree_data[0][i] <= '0;
            level_valid[0] <= 1'b0;
        end 
        else begin
            for (int i = 0; i < LANES; i++)
                tree_data[0][i] <= data_in[i];
            level_valid[0] <= valid_in;
        end
    end

    genvar level, lane;
    generate
        for (level = 0; level < TREE_DEPTH; level++) begin : gen_level
            localparam NUM_ALUS = LANES >> (level + 1);

            // Instantiate ALUs for this tree level
            for (lane = 0; lane < NUM_ALUS; lane++) begin : gen_alu
                vreduction_alu_if vralu_if ();

                // Connect inputs from current level
                assign vralu_if.value_a = tree_data[level][2*lane];
                assign vralu_if.value_b = tree_data[level][2*lane + 1];
                assign vralu_if.alu_op  = alu_op;  // Direct connection - no pipelining

                vreduction_alu alu_inst (
                    .CLK(CLK),
                    .nRST(nRST),
                    .vraluif(vralu_if.vralu)
                );

                // Capture output to next tree level
                always_ff @(posedge CLK or negedge nRST) begin
                    if (!nRST)
                        tree_data[level+1][lane] <= '0;
                    else
                        tree_data[level+1][lane] <= vralu_if.value_out;
                end
            end

            // Pipeline the valid signal with ALU_LATENCY + 1 (for the output register)
            logic [ALU_LATENCY:0] valid_pipe;
            
            always_ff @(posedge CLK or negedge nRST) begin
                if (!nRST) begin
                    valid_pipe <= '0;
                end else begin
                    valid_pipe[0] <= level_valid[level];
                    for (int p = 1; p <= ALU_LATENCY; p++) begin
                        valid_pipe[p] <= valid_pipe[p-1];
                    end
                end
            end
            
            assign level_valid[level+1] = valid_pipe[ALU_LATENCY];
        end
    endgenerate

    // Output from final tree level
    logic [15:0] data_out_reg;
    logic valid_out_reg;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            data_out_reg <= '0;
            valid_out_reg <= 1'b0;
        end else begin
            data_out_reg <= tree_data[TREE_DEPTH][0];
            valid_out_reg <= level_valid[TREE_DEPTH];
        end
    end

    assign data_out = data_out_reg;
    assign valid_out = valid_out_reg;

endmodule