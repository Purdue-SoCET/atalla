// Simple systolic array top module, without any iteration / GEMM tracking - simply takes input gives output.
// Myles Querimit and Vinay Pundith, December 2025


// Notes:
// You can only issue a new input vector every cycle if a MAC unit that does addition in one clock cycle is used. Otherwise, it forms a data hazard between each MAC and the MAC unit below that.
// There are ways to work around this by re-ordering input data. But those are not done here.

// We output one column of the output at a time - this means that we need a column of the partial sums


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


//


module systolic_array_simple(
    input logic clk, nRST,
    systolic_array_if.memory_array memory
);

    // MAC inputs (input_x).
    // Access column wise. Column 1 gets data from input buffer, remaining col N gets input from col N-1's mac_if.in_pass.
    logic [DW-1:0] MAC_inputs [N-1:0][N-1:0];




    // Some kind of input buffer

    // 2D array of flipflops eventually to be replaced with an SRAM block
    logic [DW-1:0] input_buffer [N-1:0][N-1:0];
    logic [DW-1:0] next_input_buffer [N-1:0][N-1:0];

    logic [N-1:0] read_pointers;
    logic [N-1:0] write_pointers;











    logic weight_enables [N-1:0] [N-1:0];                       // goes to mac_if.weight_en

    // MAC Unit inputs/outputs latched within systolic array
    logic [DW-1:0] MAC_outputs [N-1:0][N-1:0];
    logic [DW-1:0] nxt_MAC_outputs [N-1:0][N-1:0];

    systolic_array_MAC_if mac_ifs[N*N-1:0] (); 

    // do something for partial sums (buffer?) here

    // Register MAC unit mac_if.out_accumulate outputs before connecting to unit below
    // this used to use control unit value_ready signal, now it uses value_ready from MAC units directly.
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0)begin
            for (z = 0; z < N; z++)begin
                for (y = 0; y < N; y++)begin
                    MAC_outputs[z][y] <= '0;
                end
            end
        end
        else begin
            MAC_outputs[0] <= nxt_MAC_outputs[0];                           // Top most row has no "above" MAC units to take value or value_ready from, instead takes from psum system. Hard assigning this for now.
            
            for (z = 1; z < N; z++) begin           // Row Z
                for (y = 0; y < N; y++) begin                               // Column Y - count 1 to N because row 0 does not have an accumulate output above it.
                    if(mac_ifs.value_ready[z-1][y]) begin                   // Update only if above row value_ready is high. Else, hold value.
                        MAC_outputs[z][y] <= nxt_MAC_outputs[z][y];
                    end
                    else begin
                        MAC_outputs[z][y] <= MAC_outputs[z][y];
                    end
                end
            end
        end 
    end

    // MAC unit generation and connection
    generate
        for (m = 0; m < N; m++) begin : mac_row_gen
            for (n = 0; n < N; n++) begin : mac_col_gen
                sysarr_MAC_fp16_2c mac_inst (
                    .clk(clk),
                    .nRST(nRST),
                    .mac_if(mac_ifs[m*N + n].MAC)
                );
                // if (m==0 && n==0) begin : mac_ready
                //     assign control_unit_if.MAC_value_ready = mac_ifs[m*N + n].value_ready;
                // end


                // Start computation immediately when data arrives
                assign mac_ifs[m*N + n].start = control_unit_if.MAC_start;
                assign mac_ifs[m*N + n].in_value = MAC_inputs[m][n];
                assign mac_ifs[m*N + n].weight_en = weight_enables[m][n];
                assign mac_ifs[m*N + n].MAC_shift = control_unit_if.MAC_shift;
                assign mac_ifs[m*N + n].stall_sa = memory.stall_sa;
                
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


     
endmodule
