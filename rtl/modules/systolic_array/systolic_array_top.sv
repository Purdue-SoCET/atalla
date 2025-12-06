`include "systolic_array_if.vh"
`include "systolic_array_MAC_if.vh"
`include "systolic_array_add_if.vh"
`include "systolic_array_OUT_FIFO_if.vh"
`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */


module systolic_array_top(
    input logic clk, nRST,
    systolic_array_if.memory_array memory
);
    // MAC Unit inputs/outputs latched within systolic array
    logic [DW-1:0] MAC_inputs [N-1:0][N-1:0];
    logic weight_enables [N-1:0] [N-1:0];
    logic [DW-1:0] MAC_outputs [N-1:0][N-1:0];
    logic [DW-1:0] nxt_MAC_outputs [N-1:0][N-1:0];
    
    // Partial sum buffer inputs (connected to top row adders)
    logic [DW-1:0] psum_buffer_inputs [N-1:0];

    // Local control signals (previously from control unit)
    logic MAC_start;
    logic MAC_shift;
    logic add_start;
    logic [$clog2(3*N)-1:0] iteration [2:0];
    
    // Generate variables
    genvar j,m,n,o,p;

    // Instantiate MAC unit interfaces
    systolic_array_MAC_if mac_ifs[N*N-1:0] (); 
    // Instantiate partial sum adder interfaces
    systolic_array_add_if add_ifs[N-1:0] (); 
    // Instantiate Output Fifos
    systolic_array_OUT_FIFO_if out_fifos_ifs[N-1:0] (); 
    
    // Control logic for streaming mode
    logic mac_computing;
    
    // Track when MACs should be computing
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            mac_computing <= 1'b0;
        end else begin
            // Start computing when inputs arrive
            if (memory.input_en) begin
                mac_computing <= 1'b1;
            end
            // Stop after outputs are done
            else if (iteration[0] >= 3*N) begin
                mac_computing <= 1'b0;
            end
        end
    end
    
    // MAC control signals
    assign MAC_start = mac_computing;  // Keep MACs running while computing
    assign MAC_shift = memory.input_en;  // Shift when loading new inputs
    assign add_start = mac_ifs[0].value_ready;  // Start adders when MACs are ready
    assign memory.fifo_has_space = 1'b1;  // Always ready in streaming mode
    
    // Direct input connection - take values immediately from array_in
    // Each row gets its corresponding slice of the input bus
    // Data streams in and computation starts immediately (no buffering)
    generate
        for (j = 0; j < N; j++) begin : input_connections
            // Directly drive front column from array_in
            assign MAC_inputs[j][0] = memory.array_in[((N-j)*DW)-1 : ((N-j-1)*DW)];
            assign weight_enables[j][0] = memory.weight_en;
        end
    endgenerate

    // Partial sum buffer connection - connect to top row adders
    // hey vinay this needs to be connected to an actual input buffer i think
    // For now, using array_in_partials as the psum buffer source
    generate
        for (j = 0; j < N; j++) begin : psum_buffer_connections
            assign psum_buffer_inputs[j] = memory.array_in_partials[((N-j)*DW)-1 : ((N-j-1)*DW)];
        end
    endgenerate

    // MAC Generation
    // Register MAC unit mac_if.out_accumulate outputs before connecting to unit below
    // this used to use control unit value_ready signal, now it uses value_ready from MAC units
    
    // Extract value_ready signals into a 2D array for easier indexing
    logic value_ready_array [N-1:0][N-1:0];
    generate
        for (m = 0; m < N; m++) begin : vr_row
            for (n = 0; n < N; n++) begin : vr_col
                assign value_ready_array[m][n] = mac_ifs[m*N + n].value_ready;
            end
        end
    endgenerate
    
    integer z, y;
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0)begin
            for (z = 0; z < N; z++)begin
                for (y = 0; y < N; y++)begin
                    MAC_outputs[z][y] <= '0;
                end
            end
        end else begin
            // Temporarily disable value_ready gating to debug
            // Update all MAC outputs every cycle
            MAC_outputs <= nxt_MAC_outputs;
        end 
    end

    generate
        for (m = 0; m < N; m++) begin : mac_row_gen
            for (n = 0; n < N; n++) begin : mac_col_gen
                sysarr_MAC_fp16_2c mac_inst (
                    .clk(clk),
                    .nRST(nRST),
                    .mac_if(mac_ifs[m*N + n].MAC)
                );
                // Start computation immediately when data arrives
                assign mac_ifs[m*N + n].start = MAC_start;
                assign mac_ifs[m*N + n].in_value = MAC_inputs[m][n];
                assign mac_ifs[m*N + n].weight_en = weight_enables[m][n];
                assign mac_ifs[m*N + n].MAC_shift = MAC_shift;
                assign mac_ifs[m*N + n].stall = memory.stall_sa;
                
                // Top row (m==0): connect psum buffer to adder input
                if (m == 0) begin : no_accumulate
                    assign mac_ifs[m*N + n].in_accumulate = psum_buffer_inputs[n];
                end else begin : accumulation_blk
                    // Accumulate from previous row
                    assign mac_ifs[m*N + n].in_accumulate = MAC_outputs[m-1][n];
                end
                
                // Horizontal data forwarding (systolic flow)
                if (n != 0)begin : macInputForwarding
                    assign MAC_inputs[m][n] = mac_ifs[m*N + (n-1)].in_pass;
                    assign weight_enables[m][n] = mac_ifs[m*N + (n-1)].weight_next_en;
                end
                assign nxt_MAC_outputs[m][n] = mac_ifs[m*N + n].out_accumulate;
            end
        end
    endgenerate

    // Partial Sum Output Adders Generation
    // Connected to top row (row 0) of MAC units for psum accumulation
    generate
        for (o = 0; o < N; o++) begin : adder_gen
            sysarr_add add_inst (
                .clk(clk),
                .nRST(nRST),
                .adder(add_ifs[o].add)
            );
            assign add_ifs[o].start = add_start;
            // Connect psum buffer to adder input1 (top row accumulation)
            assign add_ifs[o].add_input1 = psum_buffer_inputs[o];
            // Connect bottom row MAC output to adder input2
            assign add_ifs[o].add_input2 = MAC_outputs[N-1][o];
        end
    endgenerate

    // Output Fifo Generation
    logic [$clog2(N)-1:0] row_out;
    logic [N-1:0][DW*N-1:0] current_out;
    logic out_fifo_shift;
    
    assign out_fifo_shift = add_ifs[0].value_ready;  // Shift output FIFOs when adders produce results
    
    generate
        for (p = 0; p < N; p++) begin
            sysarr_OUT_FIFO o_fifo (
                .clk(clk),
                .nRST(nRST),
                .out_fifo(out_fifos_ifs[p].OUT_FIFO));
                
            assign out_fifos_ifs[p].shift = out_fifo_shift;
            assign out_fifos_ifs[p].shift_value = add_ifs[p].add_output;
            assign current_out[p] = out_fifos_ifs[p].out;
        end
    endgenerate

    // Iteration tracking for output timing
    // Tracks cycles since computation started to determine when outputs are ready
    integer i;
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            for (i = 0; i < 3; i++) begin
                iteration[i] <= '0;
            end
        end else if (!memory.stall_sa) begin
            // Start or restart iteration counter when loading new data
            if (memory.weight_en || memory.input_en) begin
                if (iteration[0] == 0 || iteration[0] >= 3*N) begin
                    iteration[0] <= 1;
                end else begin
                    iteration[0] <= iteration[0] + 1;
                end
            end 
            // Continue counting while data is in pipeline
            else if (iteration[0] > 0 && iteration[0] < 3*N) begin
                iteration[0] <= iteration[0] + 1;
            end
            // Reset after all outputs produced
            else if (iteration[0] >= 3*N) begin
                iteration[0] <= '0;
            end
        end
    end

    // Output generation and drained signal
    // DEBUG: Read directly from MAC outputs to see if they're computing
    integer q;
    always_comb begin
        memory.out_en = 1'b0;
        memory.row_out = '0;
        memory.drained = 1'b1;
        row_out = '0;
        memory.array_output = '0;
        
        // Generate outputs when iteration count indicates data has propagated through array
        // First output ready at iteration 2*N, then one per cycle
        for (q = 0; q < 3; q++) begin
            if (iteration[q] >= 2*N && iteration[q] < 3*N) begin
                /* verilator lint_off WIDTHTRUNC */
                row_out = iteration[q] - 2*N;
                /* verilator lint_off WIDTHTRUNC */
                memory.out_en = 1'b1;
                memory.row_out = row_out;
                // DEBUG: Read directly from bottom row of MACs instead of output FIFOs
                memory.array_output = {MAC_outputs[N-1][N-1], MAC_outputs[N-1][N-2], MAC_outputs[N-1][N-3], MAC_outputs[N-1][0]};
            end
            if (iteration[q] > 0) begin
                memory.drained = 1'b0;
            end
        end
    end
endmodule
