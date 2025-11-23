`include "vreduction_if.sv"
`include "vreduction_alu_if.vh"

module vreduction #(
    parameter int LANES = 16,
    parameter int FIFO_DEPTH = 4
)(
    input logic CLK, nRST,
    vreduction_if.ruif vruif
);

    localparam int LEVELS = $clog2(LANES);  
    import vector_pkg::*;
    import reduction_pkg::*;

    // Counter to track in-flight operations
    logic [$clog2(FIFO_DEPTH+1)-1:0] inflight_count;
    logic can_accept_new;
    
    // Internal handshake signals
    logic internal_valid_in;
    logic internal_ready_out;
    
    assign can_accept_new = (inflight_count < FIFO_DEPTH);
    assign internal_ready_out = can_accept_new;
    assign internal_valid_in = vruif.in.valid_in && vruif.in.ready_out && can_accept_new;
    
    // Track in-flight operations
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            inflight_count <= '0;
        end else begin
            case ({internal_valid_in, vruif.out.valid_out && vruif.out.ready_in})
                2'b10: inflight_count <= inflight_count + 1;  // New input, no output
                2'b01: inflight_count <= inflight_count - 1;  // Output, no new input
                default: inflight_count <= inflight_count;     // Both or neither
            endcase
        end
    end

    logic [15:0] tree_data_out;
    logic tree_valid_out;
    
    reduction_tree #(
        .LANES(LANES)
    ) reduction_tree (
        .CLK(CLK),
        .nRST(nRST),
        .data_in(vruif.in.lane_input),
        .alu_op(vruif.in.reduction_type),
        .valid_in(internal_valid_in),
        .data_out(tree_data_out),
        .valid_out(tree_valid_out)
    );

    // Register tree outputs to align with FIFO read delay
    logic [15:0] tree_data_delayed;
    logic tree_valid_delayed;
    
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            tree_data_delayed <= '0;
            tree_valid_delayed <= 1'b0;
        end else begin
            tree_data_delayed <= tree_data_out;
            tree_valid_delayed <= tree_valid_out;
        end
    end

    // FIFO for the input vector
    logic [NUM_ELEMENTS-1:0][15:0] vector_fifo_out;
    logic vector_fifo_full, vector_fifo_empty;
    
    sync_fifo #(
        .FIFODEPTH(FIFO_DEPTH),
        .DATAWIDTH(16 * NUM_ELEMENTS)
    ) vector_fifo (
        .CLK(CLK),
        .nRST(nRST),
        .wr_en(internal_valid_in),
        .din(vruif.in.vector_input),
        .shift(tree_valid_out),
        .dout(vector_fifo_out),
        .empty(vector_fifo_empty),
        .full(vector_fifo_full)
    );

    // Signals FIFO
    logic [4:0] imm_final;
    logic broadcast_final, clear_final;
    logic signals_fifo_full, signals_fifo_empty;

    sync_fifo #(
        .FIFODEPTH(FIFO_DEPTH),
        .DATAWIDTH(7)
    ) signals_fifo (
        .CLK(CLK),
        .nRST(nRST),
        .wr_en(internal_valid_in),
        .din({vruif.in.imm, vruif.in.broadcast, vruif.in.clear}),
        .shift(tree_valid_out),
        .dout({imm_final, broadcast_final, clear_final}),
        .empty(signals_fifo_empty),
        .full(signals_fifo_full)
    );

    logic [15:0] final_value;
    assign final_value = tree_data_delayed;
    logic [NUM_ELEMENTS-1:0][15:0] final_vector;

    always_comb begin
        for (int i = 0; i < NUM_ELEMENTS; i++) begin
            if (broadcast_final) begin
                final_vector[i] = final_value;
            end
            else if (clear_final) begin
                final_vector[i] = (i == int'(imm_final)) ? final_value : '0;
            end
            else begin
                final_vector[i] = (i == int'(imm_final)) ? final_value : vector_fifo_out[i];
            end
        end
    end

    // Output stage with valid/ready handshaking
    logic [NUM_ELEMENTS-1:0][15:0] output_buffer;
    logic output_buffer_valid;
    logic output_consumed;
    
    assign output_consumed = vruif.out.valid_out && vruif.out.ready_in;
    
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            for (int i = 0; i < NUM_ELEMENTS; i++)
                output_buffer[i] <= '{default: '0};
            output_buffer_valid <= 1'b0;
        end else begin
            if (!output_buffer_valid || output_consumed) begin
                // Load new data when buffer is empty or being consumed
                for (int i = 0; i < NUM_ELEMENTS; i++)
                    output_buffer[i] <= final_vector[i];
                output_buffer_valid <= tree_valid_delayed;
            end
            // If buffer has data and it's not consumed, hold it
        end
    end

    // Output assignments
    always_comb begin
        for (int i = 0; i < NUM_ELEMENTS; i++)
            vruif.out.vector_output[i] = output_buffer[i];
        vruif.out.valid_out = output_buffer_valid;
        vruif.out.ready_in = internal_ready_out;
    end
    
endmodule