`timescale 1ns/1ps
`include "systolic_array_MAC_if.vh"
`include "sys_arr_pkg.vh"

/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

module mul_grid (
    input logic clk, nRST,
    input logic [511:0] sa_inputs,
    input logic act_en, weight_en,
    input logic mul_stall,
    output logic [N-1:0][N-1:0][DW-1:0] prod_r
);

    import sys_arr_pkg::*;

    //DW = 16
    //N = 4

    systolic_array_MAC_if mac_ifs[N-1:0][N-1:0] (); 

    logic [N-1:0][N-1:0][DW-1:0] a_pipe;
    logic [N-1:0][N-1:0][DW-1:0] b_pipe;
    logic [N-1:0][N-1:0][DW-1:0] prod;
    // logic [DW-1:0] prod_r [N-1:0][N-1:0];

    logic [N-1:0] col_starts; // start bit mask for mul PEs per column
    logic shift_a, load_a, load_w;

    assign shift_a = |col_starts; // if any column start bits are high, must shift acts
    assign load_a = act_en;
    assign load_w = weight_en;
    //assign .sa_fifo_has_space = ~mul_stall; //req more acts

    // shift register for mul PE start bit mask
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            col_starts <= '0;
        end else if (!mul_stall) begin
            col_starts <= {col_starts[N-1:1], act_en};
        end
    end

    genvar i, j;
    generate
        for (i = 0; i < N; i++) begin: row
            for (j = 0; j < N; j++) begin: column

                always_ff @(posedge clk or negedge nRST) begin
                    if (!nRST) begin
                        a_pipe[i][j] <= 0;
                    end else if (!mul_stall) begin
                        if (load_a && j == 0) begin
                            a_pipe[i][0] <= sa_inputs[DW*i +: DW];
                        end else if (load_a && j != 0) begin
                            a_pipe[i][j] <= a_pipe[i][j-1];
                        end else if (shift_a && j != 0) begin
                            a_pipe[i][j] <= a_pipe[i][j-1];
                        end 
                    end
                end

                always_ff @(posedge clk or negedge nRST) begin
                    if (!nRST) begin
                        b_pipe[i][j] <= 0;
                    end else if (!mul_stall) begin
                        if (load_w && j == 0) begin
                            b_pipe[i][0] <= sa_inputs[DW*i +: DW];
                        end else if (load_w && j != 0) begin
                            b_pipe[i][j] <= b_pipe[i][j-1];
                        end 
                    end
                end

                //no input or output latch MAC
                mul_fp16_MAC u_mul (
                    .clk(clk),
                    .nRST(nRST),
                    .start(col_starts[j] && !mul_stall),
                    .a(a_pipe[i][j]),
                    .b(b_pipe[i][j]),
                    .result(prod[i][j]),
                    .done(mac_ifs[i][j].value_ready)
                );

                //register prod for adder tree
                always_ff @(posedge clk or negedge nRST) begin
                    if (!nRST) begin
                        prod_r[i][j] <= '0;
                    end else if (!mul_stall) begin
                        if (mac_ifs[i][j].value_ready) begin
                            prod_r[i][j] <= prod[i][j];
                        end
                    end
                end

            end
        end
    endgenerate

endmodule
