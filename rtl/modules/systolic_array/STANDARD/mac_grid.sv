`timescale 1ns/1ps
`include "systolic_array_MAC_if.vh"
`include "sys_arr_pkg.vh"

/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_on IMPORTSTAR */

module mac_grid #(
    parameter MAC_LATENCY = 2
) (
    input  logic                 clk,
    input  logic                 nRST,
    input  logic [N*DW-1:0]      sa_inputs,      // BF16 activations (16-bit)
    input  logic                 weight_en,
    input  logic [N-1:0]         row_en,          // per-row input enable (skewed)
    input  logic [N*DW_ACC-1:0]  partial_in,      // FP32 partial sums (32-bit)
    input  logic                 stall,
    output logic [N*DW_ACC-1:0]  grid_out,        // FP32 outputs (32-bit)
    output logic [N-1:0]         col_valid        // bottom-row value_ready per column
);

    systolic_array_MAC_if mac_ifs[N*N-1:0] ();

    // Per-row horizontal shift registers for input_en.
    // Within each row, the enable propagates left-to-right (1 cycle per column).
    // Col 0 is combinational from row_en[m]; cols 1..N-1 are registered.
    logic [N-1:0][N-1:0] row_input_en_sr;
    logic [N-1:0][N-1:1] row_input_en_sr_reg;

    genvar rm, rc;
    generate
        for (rm = 0; rm < N; rm++) begin : row_sr_gen
            for (rc = 1; rc < N; rc++) begin : col_sr_gen
                always_ff @(posedge clk, negedge nRST) begin
                    if (!nRST)
                        row_input_en_sr_reg[rm][rc] <= '0;
                    else if (rc == 1)
                        row_input_en_sr_reg[rm][rc] <= row_en[rm];
                    else
                        row_input_en_sr_reg[rm][rc] <= row_input_en_sr_reg[rm][rc-1];
                end
            end
        end
    endgenerate

    always_comb begin
        for (int i = 0; i < N; i++) begin
            row_input_en_sr[i][0] = row_en[i];
            row_input_en_sr[i][N-1:1] = row_input_en_sr_reg[i];
        end
    end

    // Weight enable shift register (shared across all rows, shifts left-to-right)
    logic [N-1:0] weight_en_sr;
    logic [N-1:1] weight_en_sr_reg;

    genvar col_sr;
    generate
        for (col_sr = 1; col_sr < N; col_sr++) begin : weight_sr_gen
            always_ff @(posedge clk, negedge nRST) begin
                if (!nRST)
                    weight_en_sr_reg[col_sr] <= '0;
                else if (col_sr == 1)
                    weight_en_sr_reg[col_sr] <= weight_en_sr[0];
                else
                    weight_en_sr_reg[col_sr] <= weight_en_sr_reg[col_sr-1];
            end
        end
    endgenerate

    always_comb begin
        weight_en_sr[0]     = weight_en;
        weight_en_sr[N-1:1] = weight_en_sr_reg;
    end

    // MAC control: per-row, per-column enable signals
    genvar cm, cn;
    generate
        for (cm = 0; cm < N; cm++) begin : ctrl_row
            for (cn = 0; cn < N; cn++) begin : ctrl_col
                assign mac_ifs[cm*N + cn].MAC_shift = row_input_en_sr[cm][cn];
                assign mac_ifs[cm*N + cn].start     = row_input_en_sr[cm][cn];
                assign mac_ifs[cm*N + cn].stall_sa  = 1'b0;
            end
        end
    endgenerate

    // Vertical accumulator storage
    logic [DW_ACC-1:0] MAC_outputs     [N-1:0][N-1:0];
    logic [DW_ACC-1:0] nxt_MAC_outputs [N-1:0][N-1:0];

    integer z, y;
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            for (z = 0; z < N; z++)
                for (y = 0; y < N; y++)
                    MAC_outputs[z][y] <= '0;
        end else begin
            for (z = 0; z < N; z++)
                for (y = 0; y < N; y++)
                    MAC_outputs[z][y] <= nxt_MAC_outputs[z][y];
        end
    end

    // MAC instantiation + wiring
    genvar m, n;
    generate
        for (m = 0; m < N; m++) begin : mac_row_gen
            for (n = 0; n < N; n++) begin : mac_col_gen

                sysarr_MAC_bf #(.LATENCY(MAC_LATENCY)) mac_inst (
                    .clk(clk),
                    .nRST(nRST),
                    .mac_if(mac_ifs[m*N + n].MAC)
                );

                // Horizontal pass-through: col 0 from sa_inputs, others from left neighbor
                if (n == 0) begin : first_col
                    assign mac_ifs[m*N + n].in_value = sa_inputs[DW*m +: DW];
                end else begin : other_cols
                    assign mac_ifs[m*N + n].in_value = mac_ifs[m*N + (n-1)].in_pass;
                end

                // Weight loading: col 0 from external, rest chain from left
                if (n == 0)
                    assign mac_ifs[m*N + n].weight_en = weight_en;
                else
                    assign mac_ifs[m*N + n].weight_en = mac_ifs[m*N + (n-1)].weight_next_en;

                // Vertical accumulation: row 0 from partial_in, rest from row above
                if (m == 0) begin : top_row
                    assign mac_ifs[m*N + n].in_accumulate = partial_in[DW_ACC*n +: DW_ACC];
                end else begin : accum_row
                    assign mac_ifs[m*N + n].in_accumulate = MAC_outputs[m-1][n];
                end

                // Hold on ready: capture new result when value_ready fires, hold otherwise.
                assign nxt_MAC_outputs[m][n] = mac_ifs[m*N + n].value_ready ?
                    mac_ifs[m*N + n].out_accumulate : MAC_outputs[m][n];
            end
        end
    endgenerate

    // Per-column valid from bottom row
    genvar cv;
    generate
        for (cv = 0; cv < N; cv++) begin : col_valid_gen
            assign col_valid[cv] = mac_ifs[(N-1)*N + cv].value_ready;
        end
    endgenerate

    // Grid outputs: bottom row nxt_MAC_outputs directly.
    genvar oc;
    generate
        for (oc = 0; oc < N; oc++) begin : output_pack
            assign grid_out[DW_ACC*oc +: DW_ACC] = nxt_MAC_outputs[N-1][oc];
        end
    endgenerate

endmodule