// Simple systolic array top module, without any iteration / GEMM tracking - simply takes input gives output.
// Myles Querimit and Vinay Pundith, December 2025


// Notes:
// You can only issue a new input vector every cycle if a MAC unit that does addition in one clock cycle is used. Otherwise, it forms a data hazard between each MAC and the MAC unit below that.
// There are ways to work around this by re-ordering input data. But those are not done here.

// We output one column of the output at a time - this means that we need a column of the partial sums

`timescale 1ns / 1ps


`include "gsau_control_unit_if.vh"

`include "systolic_array_MAC_if.vh"

`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */


//


module systolic_array_simple(
    input logic clk, nRST,
    gsau_control_unit_if.systolic_array gsau_if
);
    // Forward declarations for signals used before their main definition
    logic [DW-1:0] MAC_outputs [N-1:0][N-1:0];
    logic [DW-1:0] nxt_MAC_outputs [N-1:0][N-1:0];
    logic [N-1:0] first_column_MAC_readies;

    logic [(DW*N)-1:0] to_output_buffer;
    genvar q;
    for(q = 0; q < N; q++)
    begin
        assign to_output_buffer[DW*q +: DW] = MAC_outputs[N-1][N-1-q];
    end

    // Input buffer. Feed a column into this, and it arranges it in staggered fashion. And outputs buffer_empty=0 until all written columns have been sent into the systolic array (one column needs 4 systolic array shifts)
    logic [(DW*N)-1:0] input_column;
    logic buffer_empty;
    logic read_from_buffer;
    sysarr_input_buffer silo(.clk(clk), .nRST(nRST), .in(gsau_if.sa_array_in), .out(input_column), .write_en(gsau_if.sa_input_en), .read_en(read_from_buffer), .has_space(gsau_if.sa_fifo_has_space), .empty(buffer_empty));

    // If we are loading weights, special data path - data should NOT go into input buffer, instead it should go straight to the MAC units to put in weights register.
    logic weight_enables [N-1:0] [N-1:0];                       // goes to mac_if.weight_en

    // this will depend on the output buffer. that does not yet exist.
    logic sysarr_stall;
    // assign read_from_buffer = 

    // Logic here: As long as the buffer has valid data, it should be sent through the systolic array, UNLESS the array needs to stall.
    // But MAC units need to shift data in first, and "Start" one clock cycle later.
    // And the first column needs to start immediately, not one clock cycle later.
    // NOTE: The column ordering is REVERSED!! No idea why, but the leftmost column of MAC units has column index 0.
    // MAC_shift must also be active during weight loading so weights propagate across columns
    logic MAC_shifts_0;
    logic MAC_input_shift_0;  // MAC shift signal for input data only (not weights)
    assign MAC_shifts_0 = !(buffer_empty) || gsau_if.sa_weight_en;
    assign MAC_input_shift_0 = !(buffer_empty);  // Only active when input buffer has data
    
    logic [N-2:0] MAC_shifts_remaining;                       // I run a whole column of MAC units in sync. Technically you don't need to, but I am too sleepy to optimize that.
    // assign MAC_shifts[N-1] = !(buffer_empty);              // Whenever there is data in the buffer, MACs must go on.
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            MAC_shifts_remaining[N-2:0] <= '0;
        end
        else begin
            if(sysarr_stall) begin
                MAC_shifts_remaining <= MAC_shifts_remaining;
            end
            else begin
                MAC_shifts_remaining[N-2:0] <= {MAC_shifts_0, MAC_shifts_remaining[N-2:1]};
            end
        end
    end

    // Read data from the buffer (what this actually does is increment the buffer's read_pointer) whenever there is data
    // except when the array is stalled. Only read during input processing, not during weight loading.
    assign read_from_buffer = MAC_input_shift_0 & ~sysarr_stall;

    // Similar logic for weight enables. Again, handling a whole column of weight_en's at once.
    // Nevermind we don't need this, the MAC units already have a weight_next_en signal.
    // logic weight_enables [N-1:0];
    // assign weight_enables[N-1] = gsau_if.sa_weight_en;
    // always_ff @(posedge clk, negedge nRST) begin
    //     if(nRST == 1'b0) begin
    //         weight_enables[N-2:0] <= '0;
    //     end
    //     else begin
    //         weight_enables[N-2:0] <= weight_enables[N-1:1];
    //     end
    // end


    // Because of the GSAU design expecting computation to start immediately, it's likely possible to get rid of MAC_starts at all.
    // But for now since the MAC units expect the start signal, we just start each MAC unit (or, column of MAC units) one cycle after they got a value shifted in.
    // Except, turn all starts off if the array needs to stall. (Might not be necessary either? Idk it's 4:28am.)
    // IMPORTANT: Do NOT start MAC computation during weight loading - only during input processing
    logic [N-1:0] MAC_starts;
    logic [N-2:0] MAC_input_shifts_remaining;
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            MAC_input_shifts_remaining[N-2:0] <= '0;
        end
        else begin
            if(sysarr_stall) begin
                MAC_input_shifts_remaining <= MAC_input_shifts_remaining;
            end
            else begin
                MAC_input_shifts_remaining[N-2:0] <= {MAC_input_shift_0, MAC_input_shifts_remaining[N-2:1]};
            end
        end
    end
    
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            MAC_starts <= '0;
        end
        else begin
            if(sysarr_stall) begin
                MAC_starts <= '0;
            end
            else begin
                // Use input-only shift signals for MAC_starts to avoid starting during weight loading
                MAC_starts <= {MAC_input_shift_0, MAC_input_shifts_remaining};
            end
        end
    end

    


    // MAC Unit inputs/outputs latched within systolic array
    // (MAC_outputs, nxt_MAC_outputs, first_column_MAC_readies declared at top of module)

    systolic_array_MAC_if mac_ifs[N*N-1:0] ();

    // Partial sum buffer - stores and delivers partial sum columns synchronized with output production
    logic [N*DW-1:0] psum_column;
    logic psum_buffer_has_space;
    logic psum_buffer_empty;
    
    sysarr_psum_buffer psum_buffer (
        .clk(clk),
        .nRST(nRST),
        .psum_in(gsau_if.sa_array_in_partials),     // Partial sum input from GSAU interface
        .psum_out(psum_column),                      // Partial sum output to top row MACs
        .write_en(gsau_if.sa_partial_en),           // Write enable from GSAU
        .read_en(first_column_MAC_readies[0]),      // Read when output column is ready
        .has_space(psum_buffer_has_space),
        .empty(psum_buffer_empty)
    );

    // Register MAC unit mac_if.out_accumulate outputs before connecting to unit below
    // this used to use control unit value_ready signal, now it uses value_ready from MAC units directly.
    integer z, y;
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0)begin
            for (z = 0; z < N; z++)begin
                for (y = 0; y < N; y++)begin
                    MAC_outputs[z][y] <= '0;
                end
            end
        end
        else begin
            // update the MAC_outputs cell for each MAC unit only if its value_ready signal is high.
            for (z = 0; z < N; z++) begin           // Row Z
                for (y = 0; y < N; y++) begin       // Column Y             
                    MAC_outputs[z][y] <= nxt_MAC_outputs[z][y];
                end
            end
        end 
    end



    // MAC inputs (input_x).
    // Access column wise. Column 1 gets data from input buffer, remaining col N gets input from col N-1's mac_if.in_pass.
    logic [DW-1:0] MAC_inputs [N-1:0][N-1:0];
    genvar j, k;
    generate
        for (j = 0; j < N; j++) begin : input_connections
            // Directly drive front column from either input buffer or input bus directly if weight_en is high.
            // Indexing gsau_if.sa_array_in with j because it is of type vreg_t.
            assign MAC_inputs[j][0] = gsau_if.sa_weight_en ? gsau_if.sa_array_in[j] : input_column[DW*j +: DW];             // Column 0. Note: this indexing may be incorrect
            for(k = 1; k < N; k++) begin                                    // All remaining columns take input from the pass-down port of the MAC unit to their left. 
                assign MAC_inputs[j][k] = mac_ifs[j*N + (k-1)].in_pass;
            end
        end
    endgenerate
    

    // MAC unit generation and connection
    genvar m, n;
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
                assign mac_ifs[m*N + n].start = MAC_starts[N-1-n];
                assign mac_ifs[m*N + n].in_value = MAC_inputs[m][n];
                assign mac_ifs[m*N + n].weight_en = weight_enables[m][n];

                // MAC_shift controls input data latching
                // Use MAC_input_shift signals (only active during input processing, not weight loading)
                if(n == 0)
                    assign mac_ifs[m*N + n].MAC_shift = MAC_input_shift_0;
                else
                    assign mac_ifs[m*N + n].MAC_shift = MAC_input_shifts_remaining[N-n-1];

                assign mac_ifs[m*N + n].stall_sa = sysarr_stall;
                
                // Top row (m==0): connect psum buffer output to adder input
                if (m == 0) begin : psum_accumulate
                    // Route partial sum column to top row MAC units
                    // If psum buffer is empty, use zero (graceful degradation per design doc)
                    assign mac_ifs[m*N + n].in_accumulate = psum_buffer_empty ? '0 : psum_column[DW*n +: DW];
                end else begin : accumulation_blk
                    // Accumulate from previous row
                    assign mac_ifs[m*N + n].in_accumulate = MAC_outputs[m-1][n];
                end
                
                // Horizontal data forwarding (systolic flow)
                assign weight_enables[m][0] = gsau_if.sa_weight_en;
                if (n != 0)begin : macInputForwarding
                    // assign MAC_inputs[m][n] = mac_ifs[m*N + (n-1)].in_pass;
                    assign weight_enables[m][n] = mac_ifs[m*N + (n-1)].weight_next_en;       // I forgot the MAC units had a weight_next_en
                end
                assign nxt_MAC_outputs[m][n] = mac_ifs[m*N + n].value_ready ? mac_ifs[m*N + n].out_accumulate : MAC_outputs[m][n];
            end
        end
    endgenerate

    // Registering the value_ready signal from the top left corner MAC unit. Need this for the output buffer.
    // When you start the program, I turn on MAC_start for a whole column of MAC units. In the first iteration only the top left corner MAC unit has meaningful values, but since all MACs in that column are getting a start signal, they will all output value_ready two cycles later
    // but their values are still garbage, until the value from the top left corner accumulates down to the bottom left corner.
    // This one column tall shift register is how I track when the first valid number enters the output buffer's input port - by waiting until the top left corner MAC unit's value_ready propagates down the column.
    
    // first_column_MAC_readies declared earlier for psum_buffer use

    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            first_column_MAC_readies <= '0;
        end
        else begin
            first_column_MAC_readies <= {mac_ifs[0].value_ready, first_column_MAC_readies[N-1:1]};
        end
    end

    // Output buffer.
    // This needs to be optimized. Either turn it into a pointer based buffer or make it triangular.
    logic [(DW*N):0] out_buffer [N-1:0];
    logic [(DW*N):0] next_out_buffer [N-1:0];

    // logic [DW-1:0] next_out_buffer [N-1:0][N-1:0];

    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            out_buffer <= '{default: '{default: '0}};
        end
        else begin
            if(sysarr_stall) begin
                out_buffer <= out_buffer;
            end
            else begin
                out_buffer <= next_out_buffer;
            end
        end
    end

    always_comb begin
        next_out_buffer = out_buffer;
        // I append an extra bit to the top of to_output_buffer to signify that the item in that row of the output buffer is actually a real value, and not the result of a MAC unit computing 0*0 because it does not yet have inputs. 
        // To know if the output buffer is full, I check the MSB of the lowermost row of the buffer.
        if(first_column_MAC_readies[0]) begin
            next_out_buffer = {out_buffer[N-2:0], {1'b1,to_output_buffer}};
        end
        if(gsau_if.sa_output_ready & ~first_column_MAC_readies[0]) begin //out_buffer[N-1][N*DW]) begin
            next_out_buffer[N-1][N*DW] = 1'b0;
        end
    end

    assign gsau_if.sa_out_valid = out_buffer[N-1][N*DW];
    
    // Connect output bus to output buffer contents
    // Extract output column from out_buffer[N-1] - the lower DW*N bits contain the data
    assign gsau_if.sa_array_output = out_buffer[N-1][DW*N-1:0];

    // "Output buffer is filled" logic. When the output buffer is full, if data is not read out, the systolic array must stall so that the values in the buffer are not lost.
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            sysarr_stall <= 0;
        end
        else begin
            sysarr_stall <= (sysarr_stall | next_out_buffer[N-1][N*DW]) & ~gsau_if.sa_output_ready;
        end
    end

endmodule
