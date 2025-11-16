`include "systolic_array_if.vh"
`include "systolic_array_control_unit_if.vh"
`include "systolic_array_MAC_if.vh"
`include "systolic_array_add_if.vh"
`include "systolic_array_FIFO_if.vh"
`include "systolic_array_OUT_FIFO_if.vh"
`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */


module systolic_array(
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

    // Generate variables
    genvar j,m,n,o,p;

    // Instantiate Control Unit interface
    systolic_array_control_unit_if control_unit_if();

    // Instantiate the control unit
    sysarr_control_unit cu_inst(
        .clk(clk),
        .nRST(nRST),
        .stall_sa(memory.stall_sa),
        .cu(control_unit_if.control_unit)
    );

    // Instantiate MAC unit interfaces
    systolic_array_MAC_if mac_ifs[N*N-1:0] (); 
    // Instantiate partial sum adder interfaces
    systolic_array_add_if add_ifs[N-1:0] (); 
    // Instantiate Output Fifos
    systolic_array_OUT_FIFO_if out_fifos_ifs[N-1:0] (); 
    
    always_comb begin : control_unit_connections
        control_unit_if.weight_en = memory.weight_en;
        control_unit_if.input_en = memory.input_en;
        control_unit_if.partial_en = memory.partial_en;
        control_unit_if.row_in_en = memory.row_in_en;
        control_unit_if.row_ps_en = memory.row_ps_en;
        memory.fifo_has_space = control_unit_if.fifo_has_space;
    end
    
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
    integer z,y;
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0)begin
            for (z = 0; z < N; z++)begin
                for (y = 0; y < N; y++)begin
                    MAC_outputs[z][y] <= '0;
                end
            end
        end else if (control_unit_if.MAC_value_ready == 1'b1)begin
            MAC_outputs <= nxt_MAC_outputs;
        end 
    end

    generate
        for (m = 0; m < N; m++) begin : mac_row_gen
            for (n = 0; n < N; n++) begin : mac_col_gen
                sysarr_MAC mac_inst (
                    .clk(clk),
                    .nRST(nRST),
                    .mac_if(mac_ifs[m*N + n].MAC)
                );
                if (m==0 && n==0) begin : mac_ready
                    assign control_unit_if.MAC_value_ready = mac_ifs[m*N + n].value_ready;
                end
                // Start computation immediately when data arrives
                assign mac_ifs[m*N + n].start = control_unit_if.MAC_start;
                assign mac_ifs[m*N + n].in_value = MAC_inputs[m][n];
                assign mac_ifs[m*N + n].weight_en = weight_enables[m][n];
                assign mac_ifs[m*N + n].MAC_shift = control_unit_if.MAC_shift;
                assign mac_ifs[m*N + n].stall_sa = memory.stall_sa;
                
                // Top row (m==0): no accumulation from previous row
                if (m == 0) begin : no_accumulate
                    assign mac_ifs[m*N + n].in_accumulate = '0;
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
            if (o == 0) begin : add_ready
                assign control_unit_if.add_value_ready = add_ifs[o].value_ready;
            end
            assign add_ifs[o].start = control_unit_if.add_start;
            // Connect psum buffer to adder input1 (top row accumulation)
            assign add_ifs[o].add_input1 = psum_buffer_inputs[o];
            // Connect bottom row MAC output to adder input2
            assign add_ifs[o].add_input2 = MAC_outputs[N-1][o];
        end
    endgenerate

    // Output Fifo Generation
    logic [$clog2(N)-1:0] row_out;
    logic [N-1:0][DW*N-1:0] current_out;
    generate
        for (p = 0; p < N; p++) begin
            sysarr_OUT_FIFO o_fifo (
                .clk(clk),
                .nRST(nRST),
                .out_fifo(out_fifos_ifs[p].OUT_FIFO));
                
            assign out_fifos_ifs[p].shift = control_unit_if.out_fifo_shift;
            assign out_fifos_ifs[p].shift_value = add_ifs[p].add_output;
            assign current_out[p] = out_fifos_ifs[p].out;
        end
    endgenerate

    // output time :D
    integer q;

    always_comb begin
        memory.out_en = 1'b0;
        memory.row_out = '0;
        memory.drained = 1'b1;
        row_out = '0;
        memory.array_output = '0;
        for (q = 0; q < 3; q++)begin
            if (control_unit_if.iteration[q] >= 2*N && control_unit_if.MAC_value_ready == 1'b1)begin //first output done at 2*N then one for every iteration until it is done
                /* verilator lint_off WIDTHTRUNC */
                row_out = control_unit_if.iteration[q] - 2 * N;
                /* verilator lint_off WIDTHTRUNC */
                memory.out_en = 1'b1;
                memory.row_out = row_out;
                memory.array_output = current_out[row_out];
            end
            if (control_unit_if.iteration[q] > 0)begin
                memory.drained = 1'b0;
            end
        end
    end
endmodule
