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

    // Control signals (generated locally, no separate control unit)
    logic MAC_start, nxt_MAC_start;
    logic MAC_shift;
    logic add_start;
    logic out_fifo_shift;
    
    // Output signals
    logic [$clog2(N)-1:0] row_out;
    logic [N-1:0][DW*N-1:0] current_out;
    
    // Iteration tracking (up to 3 concurrent operations)
    logic [$clog2(3*N)-1:0] iteration [2:0];
    logic [$clog2(3*N)-1:0] nxt_iteration [2:0];
    logic [2:0] iteration_full, nxt_iteration_full;
    
    // State tracking
    logic start_flag;
    logic first_mac, nxt_first_mac;
    logic MAC_ready, nxt_MAC_ready;
    
    // Generate variables
    genvar j,m,n,o,p;
    integer i, k;

    // Instantiate MAC unit interfaces
    systolic_array_MAC_if mac_ifs[N*N-1:0] (); 
    // Instantiate partial sum adder interfaces
    systolic_array_add_if add_ifs[N-1:0] (); 
    // Instantiate Output Fifos
    systolic_array_OUT_FIFO_if out_fifos_ifs[N-1:0] (); 
    
    // Start flag: triggers when first input row loads
    assign start_flag = memory.input_en && (memory.row_in_en == 0) && !memory.stall_sa;
    
    // Always has space in streaming mode (no FIFOs to fill)
    assign memory.fifo_has_space = 1'b1;
    
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

    // ========================================================================
    // CONTROL LOGIC (replaces separate control unit for streaming mode)
    // ========================================================================
    
    // Iteration tracking
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            iteration <= '{default: '0};
            iteration_full <= '0;
        end else begin
            iteration <= nxt_iteration;
            iteration_full <= nxt_iteration_full;
        end 
    end
    
    always_comb begin
        nxt_iteration = iteration;
        nxt_iteration_full = iteration_full;
        
        // Start new iteration when first input row loads
        if (start_flag) begin
            for (i = 0; i < 3; i++) begin
                if (iteration_full[i] == 1'b0) begin
                    nxt_iteration_full[i] = 1'b1;
                    break;
                end
            end
        end
        
        // Increment active iterations
        for (k = 0; k < 3; k++) begin
            if (nxt_iteration_full[k] && nxt_MAC_start) begin
                nxt_iteration[k] = iteration[k] + 1;
                if (iteration[k] == 3*N-1) begin
                    nxt_iteration[k] = 0;
                    nxt_iteration_full[k] = 0;
                end
            end
        end
    end
    
    // MAC control
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            MAC_start <= '0;
            first_mac <= '0;
            MAC_ready <= 1'b1;
        end else begin
            MAC_start <= nxt_MAC_start;
            first_mac <= nxt_first_mac;
            MAC_ready <= nxt_MAC_ready;
        end 
    end
    
    always_comb begin
        nxt_MAC_start = 1'b0;
        nxt_first_mac = first_mac;
        nxt_MAC_ready = MAC_ready;
        
        // Set first_mac flag when weights are loaded
        if (memory.weight_en) begin
            nxt_first_mac = 1'b1;
        end
        
        // MAC becomes ready when computation completes
        if (mac_ifs[0].value_ready == 1'b1) begin
            nxt_MAC_ready = 1'b1;
        end
        
        // Start MACs when iteration is active and MAC is ready
        if (|iteration_full && (MAC_ready == 1'b1 || mac_ifs[0].value_ready)) begin
            // In streaming mode, data arrives directly - just start computing
            nxt_MAC_start = 1'b1;
            nxt_MAC_ready = 1'b0;
        end else if (first_mac == 1'b1 && start_flag) begin
            // First MAC cycle after weights loaded
            nxt_MAC_start = 1'b1;
            nxt_first_mac = 1'b0;
            nxt_MAC_ready = 1'b0;
        end
        
        // Handle stall
        nxt_MAC_start &= ~memory.stall_sa;
        nxt_MAC_ready |= memory.stall_sa;
    end
    
    // Shift and adder control
    assign MAC_shift = MAC_start && |iteration_full;
    assign add_start = (iteration[0] > N) && MAC_start;  // Start adders after data propagates
    assign out_fifo_shift = add_ifs[0].value_ready;
     
    // Extract value_ready signals into 2D array
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
        if (!nRST) begin
            for (z = 0; z < N; z++) begin
                for (y = 0; y < N; y++) begin
                    MAC_outputs[z][y] <= '0;
                end
            end
        end else begin
            // Top row always updates (no dependency)
            MAC_outputs[0] <= nxt_MAC_outputs[0];
            
            // Rows 1-N: update only when previous row has valid data
            for (z = 1; z < N; z++) begin
                for (y = 0; y < N; y++) begin
                    if (value_ready_array[z-1][y]) begin
                        MAC_outputs[z][y] <= nxt_MAC_outputs[z][y];
                    end
                    // else hold current value
                end
            end
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
                // Connect MAC control signals
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

    // Output generation and drained signal
    integer q;
    always_comb begin
        memory.out_en = 1'b0;
        memory.row_out = '0;
        memory.drained = 1'b1;
        row_out = '0;
        memory.array_output = '0;
        
        for (q = 0; q < 3; q++) begin
            if (iteration[q] >= 2*N && mac_ifs[0].value_ready == 1'b1) begin
                /* verilator lint_off WIDTHTRUNC */
                row_out = iteration[q] - 2 * N;
                /* verilator lint_off WIDTHTRUNC */
                memory.out_en = 1'b1;
                memory.row_out = row_out;
                memory.array_output = current_out[row_out];
            end
            if (iteration[q] > 0) begin
                memory.drained = 1'b0;
            end
        end
    end
endmodule
