`timescale 1ns/1ps
`include "systolic_array_MAC_if.vh"
`include "sys_arr_pkg.vh"

/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_off IMPORTSTAR */

module mul_grid #(
    parameter int FP_BF = 0           // Determine whether to use FP16 (1) or BF16 (0)
)(
    input logic clk, nRST,
    input logic [N * DW - 1:0] sa_inputs,
    input logic act_en, weight_en,
    input logic mul_stall,
    output logic [N-1:0][N-1:0][(FP_BF ? DW : DW_ACC)-1:0] prod_r
);

    import sys_arr_pkg::*;

    //DW = 16
    //N = 4

    // prod width: FP16 stays 16-bit, BF16 path outputs FP32
    localparam int PROD_W = FP_BF ? DW : DW_ACC;

    logic [N-1:0][N-1:0][DW-1:0] input_pipe;
    logic [N-1:0][N-1:0][DW-1:0] weight_pipe;
    logic [N-1:0][N-1:0][PROD_W-1:0] prod;
    // logic [DW-1:0] prod_r [N-1:0][N-1:0];

    //logic [N-1:0] col_starts; // start bit mask for mul PEs per column
    //logic shift_a, load_a, load_w;
    logic load_w;
    logic load_a;

    //assign shift_a = |col_starts; // if any column start bits are high, must shift acts
    assign load_a = act_en;
    assign load_w = weight_en;
    //assign .sa_fifo_has_space = ~mul_stall; //req more acts

    // shift register for mul PE start bit mask
    /*
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            col_starts <= '0;
        end else if (!mul_stall) begin
            col_starts <= {col_starts[N-2:0], act_en};
        end
    end */

    genvar i, j;
    generate
        for (i = 0; i < N; i++) begin: row
            for (j = 0; j < N; j++) begin: column

                always_ff @(posedge clk or negedge nRST) begin
                    if (!nRST) begin
                        input_pipe[i][j] <= 0;
                    end else if (!mul_stall) begin
                        if (j == 0) begin // special case first column
                            if (load_a) begin
                                input_pipe[i][0] <= sa_inputs[DW*i +: DW];
                            end else begin
                                input_pipe[i][0] <= '0;
                            end
                        end else begin // all other columns, shift forever
                            input_pipe[i][j] <= input_pipe[i][j-1];
                        end /*else if (shift_a && j != 0) begin
                            input_pipe[i][j] <= input_pipe[i][j-1];
                        end */
                    end
                end

                // weight_pipe update
                always_ff @(posedge clk or negedge nRST) begin
                    if (!nRST) begin
                        weight_pipe[i][j] <= 0;
                    end else if (!mul_stall) begin
                        if (j == 0) begin
                            if (load_w) begin
                                weight_pipe[i][0] <= sa_inputs[DW*i +: DW];
                            end
                        end else begin
                            if (load_w) begin
                                weight_pipe[i][j] <= weight_pipe[i][j-1];
                            end
                        end
                    end
                end

                if (FP_BF) begin: fp16
                    //no input or output latch MAC
                    mul_fp16_1c u_mul_fp (
                        .clk(clk),
                        .nRST(nRST),
                        .a(input_pipe[i][j]),
                        .b(weight_pipe[i][j]),
                        .result(prod[j][i])
                        //.done(mac_ifs[i][j].value_ready)
                    );
                end else begin: bf16
                    // there's a latch in bf16
                    mul_bf u_mul_bf (
                        .clk(clk),
                        .nRST(nRST),
                        .start(!mul_stall),
                        .a(input_pipe[i][j]),
                        .b(weight_pipe[i][j]),
                        .result(prod[j][i]),
                        //.done(mac_ifs[i][j].value_ready),
                        .done(),
                        .mul_ovf(),
                        .mul_unf()
                    );
                end

                // combinational pass-through to adder tree
                assign prod_r[i][j] = prod[i][j];

            end
        end
    endgenerate

endmodule