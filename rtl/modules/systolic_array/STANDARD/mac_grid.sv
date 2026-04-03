`timescale 1ns/1ps
`include "systolic_array_MAC_if.vh"
`include "sys_arr_pkg.vh"

/* verilator lint_off IMPORTSTAR */
import sys_arr_pkg::*;
/* verilator lint_on IMPORTSTAR */

// only thing i connected are the computational stuff 

module mac_grid #(
    parameter MAC_LATENCY = 2
) (
    input  logic             clk,
    input  logic             nRST,
    input  logic [N*DW-1:0]  sa_inputs,
    input  logic             weight_en,
    input  logic             input_en,  
    input  logic [N*DW-1:0]  partial_in,
    input  logic             stall,  // unused 
    output logic [N*DW-1:0]  grid_out
);

    systolic_array_MAC_if mac_ifs[N*N-1:0] ();

    // todo!!! control logic 
    // per mac signals are mac shift and start 
    // mac shift - latch input now (mac captures invalue) 
    // start - just start signal
 

    // placeholder below until control logic is wired 
    genvar cm, cn;
    generate
        for (cm = 0; cm < N; cm++) begin : ctrl_row
            for (cn = 0; cn < N; cn++) begin : ctrl_col
                // replace ts w actual logic 
                assign mac_ifs[cm*N + cn].MAC_shift = '0;
                assign mac_ifs[cm*N + cn].start     = '0;
            end
        end
    endgenerate
    // place holder above 

  
    logic [DW-1:0] MAC_outputs     [N-1:0][N-1:0];
    logic [DW-1:0] nxt_MAC_outputs [N-1:0][N-1:0];

    integer z, y;
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            for (z = 0; z < N; z++)
                for (y = 0; y < N; y++)
                    MAC_outputs[z][y] <= '0;
        end
    end

    // MAC instantiation + and computation wiring
    genvar m, n;
    generate
        for (m = 0; m < N; m++) begin : mac_row_gen
            for (n = 0; n < N; n++) begin : mac_col_gen

                // 2 or 4 cycle mac
                if (MAC_LATENCY == 2) begin : mac_2c
                    sysarr_MAC_fp16_2c mac_inst (
                        .clk(clk),
                        .nRST(nRST),
                        .mac_if(mac_ifs[m*N + n].MAC)
                    );
                end else if (MAC_LATENCY == 4) begin : mac_4c
                    sysarr_MAC_fp16_4c mac_inst (
                        .clk(clk),
                        .nRST(nRST),
                        .mac_if(mac_ifs[m*N + n].MAC)
                    );
                end

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

                // vertical accumulation - row 0 takes partial_in, rest take from row above
                if (m == 0) begin : top_row
                    assign mac_ifs[m*N + n].in_accumulate = partial_in[DW*n +: DW];
                end else begin : accum_row
                    assign mac_ifs[m*N + n].in_accumulate = MAC_outputs[m-1][n];
                end

                // output capture - latch on value_ready, hold otherwise 
                assign nxt_MAC_outputs[m][n] = mac_ifs[m*N + n].value_ready ?
                    mac_ifs[m*N + n].out_accumulate : MAC_outputs[m][n];
            end
        end
    endgenerate

    // grid outputs 
    genvar oc;
    generate
        for (oc = 0; oc < N; oc++) begin : output_pack
            assign grid_out[DW*oc +: DW] = MAC_outputs[N-1][oc];
        end
    endgenerate

endmodule
