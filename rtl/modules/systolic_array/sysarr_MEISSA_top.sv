`timescale 1ns/1ps
`include "gsau_control_unit_if.vh"
`include "sys_arr_pkg.vh"

/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

module sysarr_MEISSA_top #(
    parameter int ADD_LATENCY = 2
)(
    input logic clk, nRST,
    gsau_control_unit_if.systolic_array gsau_if
);
    logic sysarr_stall;
    logic [DW-1:0] mul_prod [N-1:0][N-1:0];
    logic [DW-1:0] col_prod [N-1:0][N-1:0];
    logic [DW-1:0] adder_sum [N-1:0];

    //mul grid: input and output is latched

    mul_grid u_mul_grid( 
        .clk(clk),
        .nRST(nRST),
        .sa_inputs(gsau_if.sa_array_in),
        .act_en(gsau_if.sa_input_en),
        .weight_en(gsau_if.sa_weight_en),
        .mul_stall(sysarr_stall),
        .prod_r(mul_prod)
    );

    //adder trees

    genvar j,k;
    generate
        for (j = 0; j < N; j++) begin: col
            for (k = 0; k < N; k++) begin: col_pack
                assign col_prod[j][k] = mul_prod[k][j]; //pack mul_prod into 1D arr
            end

            pipelined_adder_tree #(
                .N(N),
                .DATA_WIDTH(DW),
                .ADD_LATENCY(ADD_LATENCY)
            ) u_piped_addr_tree (
                .clk(clk),
                .nRST(nRST),
                .stall(sysarr_stall),
                .terms_in(col_prod[j]),
                .psum_in(gsau_if.sa_array_in_partials[DW*j +: DW]),
                .sum_out(adder_sum[j])
            );
        end
    endgenerate

    //output fifo

    assign sysarr_stall = 1'b0;
    
    //sysarr stall when fifo needs to stall
    //define sa_array_output for fifo outputs
    //define sa_valid_in for valid fifo output flag
    //define sa_ready_in for when output fifo can take new results


endmodule