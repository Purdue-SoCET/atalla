// psum for systolic array. stores and delivers psum columns
// synchronized with output column production.
// unlike input, this buffer does NOT stagger - it's a simple circular buffer.

// just modified input_buffer.sv code (removed staggering) 

`timescale 1ns / 1ps

`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

module sysarr_psum_buffer(input logic clk, nRST, input logic [N*DW-1:0] psum_in, output logic[N*DW-1:0] psum_out, input logic read_en, input logic write_en, output logic has_space, output logic empty);

    logic [DW-1:0] buffer_contents [N-1:0][N-1:0];
    logic [DW-1:0] next_buffer_contents [N-1:0][N-1:0];

    logic [$clog2(N):0] valid_cols, next_valid_cols;

    logic [$clog2(N)-1:0] read_pointer;
    logic [$clog2(N)-1:0] next_read_pointer;

    logic [$clog2(N)-1:0] write_pointer;
    logic [$clog2(N)-1:0] next_write_pointer;

    integer a;

    always_ff @ (posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            buffer_contents <= '{default: '{default: '0}};
            read_pointer <= '0;
            write_pointer <= '0;
            valid_cols <= '0;
        end
        else begin
            read_pointer <= next_read_pointer;
            write_pointer <= next_write_pointer;
            buffer_contents <= next_buffer_contents;
            valid_cols <= next_valid_cols;
        end
    end

    integer i, j, k;

    always_comb begin
        next_buffer_contents = buffer_contents;
        next_write_pointer = write_pointer;
        next_read_pointer = read_pointer;
        next_valid_cols = valid_cols;

        for(j = 0; j < N; j++) begin
            psum_out[DW*j +: DW] = buffer_contents[j][read_pointer];
        end

        // has_space, empty calculation based on # of valid columns of data in the buffer
        if(write_en && read_en) begin
            if (valid_cols == 0) begin
                // Can't read from empty, only write takes effect
                next_valid_cols = valid_cols + 1;
            end
            // else: simultaneous read/write, count unchanged
        end
        else if(write_en) begin
            if (valid_cols < N) begin
                next_valid_cols = valid_cols + 1;
            end
        end
        else if(read_en) begin
            if (valid_cols > 0) begin
                next_valid_cols = valid_cols - 1;
            end
        end

        assign has_space = (valid_cols < N);
        assign empty = (valid_cols == 0);

        if(read_en && valid_cols > 0) begin
            if(read_pointer >= $clog2(N)'(N-1)) begin
                next_read_pointer = 0;
            end
            else begin
                next_read_pointer = read_pointer + 1;
            end

            // After reading the column, zero it out.
            for(k = 0; k < N; k++) begin
                next_buffer_contents[k][read_pointer] = '0;
            end
        end

        if(write_en && valid_cols < N) begin
            // Write entire column at once (no staggering unlike input buffer)
            for(i = 0; i < N; i++) begin
                next_buffer_contents[i][write_pointer] = psum_in[DW*i +: DW];
            end
            
            if(write_pointer >= $clog2(N)'(N-1)) begin
                next_write_pointer = 0;
            end
            else begin
                next_write_pointer = write_pointer + 1;
            end
        end
    end

endmodule
