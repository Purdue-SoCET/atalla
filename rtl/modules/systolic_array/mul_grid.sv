`timescale 1ns/1ps
`include "systolic_array_MEISSA_if.vh"
`include "systolic_array_MAC_if.vh"
`include "sys_arr_pkg.vh"

/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

module mul_grid (
    input logic clk, nRST,
    systolic_array_MEISSA_if.mul_grid mul_if
);

    //DW = 16
    //N = 4

    systolic_array_MAC_if mac_ifs[N-1:0][N-1:0] (); 

    logic [DW-1:0] a_pipe [N-1:0][N-1:0];
    logic [DW-1:0] b_pipe [N-1:0][N-1:0]; 
    logic [DW-1:0] prod [N-1:0][N-1:0];
    logic [DW-1:0] prod_r [N-1:0][N-1:0];

    logic [N-1:0] col_starts; // start bit mask for mul PEs per column
    logic mul_stall, shift_a, load_a, load_w;

    assign mul_stall = 1'b0; // later addder tree backpressue!!!!!!!!!
    assign shift_a = |col_starts; // if any column start bits are high, must shift acts
    assign load_a = mul_if.sa_input_en;
    assign load_w = mul_if.sa_weight_en;
    //assign mul_if.sa_fifo_has_space = ~mul_stall; //req more acts

    // shift register for mul PE start bit mask
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            col_starts <= '0;
        end else begin
            if (mul_stall) begin
                col_starts <= '0;
            end else begin
                col_starts <= {mul_if.sa_input_en, col_starts[N-1:1]};
            end
        end
    end

    genvar i, j;
    generate
        for (i = 0; i < N; i++) begin: row
            for (j = 0; j < N; j++) begin: column

                always_ff @(posedge clk, negedge nRST) begin
                    if (!nRST) begin
                        a_pipe[i][j] <= 0;
                    end else if (load_a && j == 0) begin
                        a_pipe[i][0] <= mul_if.sa_array_in[DW*i +: DW];
                    end else if (load_a && j != 0) begin
                        a_pipe[i][j] <= a_pipe[i][j-1];
                    end else if (shift_a && j != 0) begin
                        a_pipe[i][j] <= a_pipe[i][j-1];
                    end else a_pipe[i][j] <= a_pipe[i][j];
                end

                always_ff @(posedge clk, negedge nRST) begin
                    if (!nRST) begin
                        b_pipe[i][j] <= 0;
                    end else if (load_w && j == 0) begin
                        b_pipe[i][0] <= mul_if.sa_array_in[DW*i +: DW];
                    end else if (load_w && j != 0) begin
                        b_pipe[i][j] <= b_pipe[i][j-1];
                    end else b_pipe[i][j] <= b_pipe[i][j];
                end

                //no input or output latch MAC
                mul_fp16_MAC u_mul (
                    .clk(clk),
                    .nRST(nRST),
                    .start(col_starts[j]),
                    .a(a_pipe[i][j]),
                    .b(b_pipe[i][j]),
                    .result(prod[i][j]),
                    .done(mac_ifs.value_ready[i][j])
                );

                //register prod for adder tree
                always_ff @(posedge clk or negedge nRST) begin
                    if (!nRST) begin
                        prod_r[i][j] <= '0;
                    end else if(mac_ifs.value_ready[i][j]) begin
                        prod_r[i][j] <= prod[i][j];
                    end
                end

            end
        end
    endgenerate

endmodule