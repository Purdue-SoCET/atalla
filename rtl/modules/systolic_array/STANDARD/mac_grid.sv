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
    input  logic                 input_en,  
    input  logic [N*DW_ACC-1:0]  partial_in,     // FP32 partial sums (32-bit)
    input  logic                 stall,          // unused 
    output logic [N*DW_ACC-1:0]  grid_out,       // FP32 outputs (32-bit)
    output logic [N-1:0]         col_valid       // bottom-row value_ready per column
);

    systolic_array_MAC_if mac_ifs[N*N-1:0] ();

    // Staged control signals - inputs propagate horizontally, so start signal must be delayed per column
    logic [N-1:0] input_en_sr, weight_en_sr;

    // Registered portion: cols 1..N-1
    logic [N-1:1] input_en_sr_reg, weight_en_sr_reg;
    genvar col_sr;
    generate
        for (col_sr = 1; col_sr < N; col_sr++) begin : stage_shift_regs
            always_ff @(posedge clk, negedge nRST) begin
                if (!nRST) begin
                    input_en_sr_reg[col_sr]  <= '0;
                    weight_en_sr_reg[col_sr] <= '0;
                end else begin
                    if (col_sr == 1) begin
                        input_en_sr_reg[col_sr]  <= input_en_sr[0];
                        weight_en_sr_reg[col_sr] <= weight_en_sr[0];
                    end else begin
                        input_en_sr_reg[col_sr]  <= input_en_sr_reg[col_sr-1];
                        weight_en_sr_reg[col_sr] <= weight_en_sr_reg[col_sr-1];
                    end
                end
            end
        end
    endgenerate

    // Combine: col 0 = combinational, cols 1..N-1 = registered
    always_comb begin
        input_en_sr[0]      = input_en;
        weight_en_sr[0]     = weight_en;
        input_en_sr[N-1:1]  = input_en_sr_reg;
        weight_en_sr[N-1:1] = weight_en_sr_reg;
    end

    // Control logic for MAC_shift and start signals
    // MAC_shift: latch input now (mac captures invalue) - asserted during weight loading and input loading
    // start: begin MAC operation - asserted when input arrives at this column (staged by column position)
    
    genvar cm, cn;
    generate
        for (cm = 0; cm < N; cm++) begin : ctrl_row
            for (cn = 0; cn < N; cn++) begin : ctrl_col
                // Shift data through only during input loading, not weight loading
                assign mac_ifs[cm*N + cn].MAC_shift = input_en_sr[cn];
                // Start MAC operations when input arrives at this column
                assign mac_ifs[cm*N + cn].start     = input_en_sr[cn];
            end
        end
    endgenerate

  
    logic [DW_ACC-1:0] MAC_outputs     [N-1:0][N-1:0];  // FP32 accumulator outputs
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

    // MAC instantiation + and computation wiring
    genvar m, n;
    generate
        for (m = 0; m < N; m++) begin : mac_row_gen
            for (n = 0; n < N; n++) begin : mac_col_gen

                sysarr_MAC_bf #(.LATENCY(MAC_LATENCY)) mac_inst (
                    .clk(clk),
                    .nRST(nRST),
                    .mac_if(mac_ifs[m*N + n].MAC)
                );

                // horizontal pass thru - col 0 takes from sa_inputs, others chain from left neighbor
                if (n == 0) begin : first_col
                    assign mac_ifs[m*N + n].in_value = sa_inputs[DW*m +: DW];
                end else begin : other_cols
                    assign mac_ifs[m*N + n].in_value = mac_ifs[m*N + (n-1)].in_pass;
                end

                // weight loading - col 0 takes external weight_en, rest chain from left mac
                if (n == 0)
                    assign mac_ifs[m*N + n].weight_en = weight_en;
                else
                    assign mac_ifs[m*N + n].weight_en = mac_ifs[m*N + (n-1)].weight_next_en;

                // vertical accumulation - row 0 takes partial_in (FP32), rest take from row above
                if (m == 0) begin : top_row
                    assign mac_ifs[m*N + n].in_accumulate = partial_in[DW_ACC*n +: DW_ACC];
                end else begin : accum_row
                    assign mac_ifs[m*N + n].in_accumulate = MAC_outputs[m-1][n];
                end

                // output capture - latch on value_ready, hold otherwise 
                assign nxt_MAC_outputs[m][n] = mac_ifs[m*N + n].value_ready ?
                    mac_ifs[m*N + n].out_accumulate : MAC_outputs[m][n];
            end
        end
    endgenerate

    // Per-column valid: bottom-row value_ready signals
    genvar cv;
    generate
        for (cv = 0; cv < N; cv++) begin : col_valid_gen
            assign col_valid[cv] = mac_ifs[(N-1)*N + cv].value_ready;
        end
    endgenerate

    // grid outputs (FP32)
    genvar oc;
    generate
        for (oc = 0; oc < N; oc++) begin : output_pack
            assign grid_out[DW_ACC*oc +: DW_ACC] = MAC_outputs[N-1][oc];
        end
    endgenerate

endmodule