`timescale 1ns / 1ps

`include "sys_arr_pkg.vh"
/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

module sysarr_input_buffer(input logic clk, nRST, input logic [N*DW-1:0] in, output logic[N*DW-1:0] out, input logic read_en, input logic write_en, output logic has_space);

    logic [DW-1:0] buffer_contents [N-1:0][N-1:0];
    logic [DW-1:0] next_buffer_contents [N-1:0][N-1:0];

    logic [$clog2(N)-1:0] read_pointer;
    logic [$clog2(N)-1:0] next_read_pointer;

    logic [$clog2(N)-1:0] write_pointers [N-1:0];
    logic [$clog2(N)-1:0] next_write_pointers [N-1:0];

    integer a;

    always_ff @ (posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            buffer_contents <= '{default: '{default: '0}};
            read_pointer <= '0;
            for(a = 0; a < N; a++) begin
                write_pointers[a] <= a[$clog2(N)-1:0];
            end
        end
        else begin
            read_pointer <= next_read_pointer;
            write_pointers <= next_write_pointers;
            buffer_contents <= next_buffer_contents;
        end
    end

    integer i, j;
    logic [$clog2(N)-1:0] full_check_wp;

    always_comb begin
        next_buffer_contents = buffer_contents;
        next_write_pointers = write_pointers;
        next_read_pointer = read_pointer;

        for(j = 0; j < N; j++) begin
            out[DW*j +: DW] = buffer_contents[j][read_pointer];
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

        if(read_en) begin
            if(read_pointer >= $clog2(N)'(N-1)) begin
                next_read_pointer = 0;
            end
            else begin
                next_read_pointer = read_pointer + 1;
            end
        end

        full_check_wp = (write_pointers[0] == $clog2(N)'(N-1)) ? '0 : (write_pointers[0] + 1); // This line is from GPT
        if(full_check_wp == read_pointer) begin        // GPT said this shouldn't be write_poitners[0] == read_pointers
            has_space = 1'b0;
        end
        else begin
            has_space = 1'b1;
        end

    end

endmodule


