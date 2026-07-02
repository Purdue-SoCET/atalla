// "Input buffer" for systolic array. Handles staggering of column inputs.

`timescale 1ns / 1ps

`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

module sysarr_input_buffer(input logic clk, nRST, input logic [N*DW-1:0] in, output logic[N*DW-1:0] out, input logic read_en, input logic write_en, output logic has_space, output logic empty);

    logic [DW-1:0] buffer_contents [N-1:0][N-1:0];
    logic [DW-1:0] next_buffer_contents [N-1:0][N-1:0];

    logic [$clog2(N):0] valid_cols, next_valid_cols;

    logic [$clog2(N)-1:0] read_pointer;
    logic [$clog2(N)-1:0] next_read_pointer;

    logic [$clog2(N)-1:0] write_pointers [N-1:0];
    logic [$clog2(N)-1:0] next_write_pointers [N-1:0];

    integer a;

    always_ff @ (posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            buffer_contents <= '{default: '{default: '0}};
            read_pointer <= '0;
            valid_cols <= '0;
            for(a = 0; a < N; a++) begin
                write_pointers[a] <= a[$clog2(N)-1:0];
            end
        end
        else begin
            read_pointer <= next_read_pointer;
            write_pointers <= next_write_pointers;
            buffer_contents <= next_buffer_contents;
            valid_cols <= next_valid_cols;
        end
    end

    integer i, j, k;
    logic [$clog2(N)-1:0] full_check_wp;

    always_comb begin
        next_buffer_contents = buffer_contents;
        next_write_pointers = write_pointers;
        next_read_pointer = read_pointer;
        next_valid_cols = valid_cols;

        for(j = 0; j < N; j++) begin
            out[DW*j +: DW] = buffer_contents[j][read_pointer];
        end

        // logic from GPT: has_space, empty calculation based on # of valid columns of data in the thing
        if(write_en && read_en) begin
            if (valid_cols == 0) begin
                next_valid_cols = valid_cols + (N-1);
            end
            else begin
                next_valid_cols = valid_cols;
            end
        end
        else if(write_en) begin
            if (valid_cols == 0) begin
                next_valid_cols = valid_cols + N;
            end
            else begin
                next_valid_cols = valid_cols;
            end
        end
        else if(read_en) begin
            next_valid_cols = valid_cols - 1;
        end

        has_space = (valid_cols < N);
        empty = (valid_cols == 0);

        if(read_en) begin
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

        if(write_en) begin
            for(i = 0; i < N; i++) begin
                next_buffer_contents[i][write_pointers[i]] = in[DW*i +: DW];
                next_write_pointers[i] = write_pointers[i] + 1;
                if(write_pointers[i] == $clog2(N)'(N-1)) begin
                    next_write_pointers[i] = 0;
                end
            end
        end
    end

endmodule


