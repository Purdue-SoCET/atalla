/*  Haejune Kwon - kwon196@purdue.edu */
/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`include "xbar_if.vh"

import xbar_pkg::*;

module clos #(
    parameter int CLOS_SIZE = 32,
    parameter int CLOS_DWIDTH = 16,
    parameter int IM_OM_NUM = 8,
    parameter int CM_NUM = 4,

    localparam int TAGWIDTH = $clog2(CLOS_SIZE),

    localparam int IM_OM_SIZE = CLOS_SIZE / IM_OM_NUM,       // 8
    localparam int IM_OM_NUM_TAG = $clog2(IM_OM_NUM),   // 2
    localparam int IM_OM_SIZE_TAG = $clog2(IM_OM_SIZE), // 3

    localparam int CM_SIZE = CLOS_SIZE / CM_NUM,             // 8
    localparam int CM_SIZE_TAG = $clog2(CM_SIZE)        // 3
) (
    xbar_if.xbar xif
);
    logic [CLOS_DWIDTH-1:0] input_module   [IM_OM_NUM-1:0][IM_OM_SIZE-1:0];
    logic [CLOS_DWIDTH-1:0] center_module     [CM_NUM-1:0][CM_SIZE-1:0];
    logic [CLOS_DWIDTH-1:0] output_module  [IM_OM_NUM-1:0][IM_OM_SIZE-1:0];

    logic [CLOS_DWIDTH-1:0] n_center_module [CM_NUM-1:0]     [CM_SIZE-1:0];
    logic [CLOS_DWIDTH-1:0] n_output_module [IM_OM_NUM-1:0]  [IM_OM_SIZE-1:0];

    logic [TAGWIDTH-1:0] input_perm    [IM_OM_NUM-1:0] [IM_OM_SIZE-1:0];
    logic [TAGWIDTH-1:0] center_perm      [CM_NUM-1:0] [CM_SIZE-1:0];
    logic [TAGWIDTH-1:0] output_perm   [IM_OM_NUM-1:0] [IM_OM_SIZE-1:0];
    logic [TAGWIDTH-1:0] out_perm [CLOS_SIZE-1:0];

    logic [CLOS_DWIDTH-1:0] n_center_perm  [CM_NUM-1:0]     [CM_SIZE-1:0];
    logic [CLOS_DWIDTH-1:0] n_output_perm  [IM_OM_NUM-1:0]  [IM_OM_SIZE-1:0];

    logic [IM_OM_SIZE_TAG-1:0] lsb [IM_OM_NUM-1:0] [IM_OM_SIZE-1:0];

    always_ff @( posedge xif.clk, negedge xif.n_rst ) begin : blockName
        if(!xif.n_rst) begin
            for (int i = 0; i < CM_NUM; i++) begin
                for (int j = 0; j < CM_SIZE; j++) begin
                    center_module[i][j] <= '0;
                    center_perm[i][j]   <= '0;
                end
            end
            for (int i = 0; i < IM_OM_NUM; i++) begin
                for (int j = 0; j < IM_OM_SIZE; j++) begin
                    output_module[i][j] <= '0;
                    output_perm[i][j]   <= '0;
                end
            end
        end
        else if (xif.en) begin
            for (int i = 0; i < CM_NUM; i++) begin
                for (int j = 0; j < CM_SIZE; j++) begin
                    center_module[i][j] <= n_center_module[i][j];
                    center_perm[i][j]   <= n_center_perm[i][j];
                end
            end
            for (int i = 0; i < IM_OM_NUM; i++) begin
                for (int j = 0; j < IM_OM_SIZE; j++) begin
                    output_module[i][j] <= n_output_module[i][j];
                    output_perm[i][j]   <= n_output_perm[i][j];
                end
            end
        end
    end
    
    genvar i, j;
    generate
        for (i = 0; i < IM_OM_NUM; i++) begin
            for (j = 0; j < IM_OM_SIZE; j++) begin
                assign input_module[i][j] = xif.in[i * IM_OM_SIZE + j].din;
                assign input_perm[i][j]   = xif.in[i * IM_OM_SIZE + j].shift;
                assign lsb[i][j] = output_perm[i][j][1:0];
            end
            param_switch #(.N_IN(IM_OM_SIZE), .N_OUT(IM_OM_SIZE), .DATA_W(CLOS_DWIDTH)
            ) out_switch (
                .in_data(output_module[i]),
                .sel_in(lsb[i]),
                .out_data(xif.out[i * IM_OM_SIZE +: IM_OM_SIZE])
            );
            param_switch #(.N_IN(IM_OM_SIZE), .N_OUT(IM_OM_SIZE), .DATA_W(TAGWIDTH)
            ) out_perm_switch (
                .in_data(output_perm[i]),
                .sel_in(lsb[i]),
                .out_data(out_perm[i * IM_OM_SIZE +: IM_OM_SIZE])
            );
        end

        for (i = 0; i < CM_NUM; i++) begin
            for (j = 0; j < CM_SIZE; j++) begin
                assign n_output_module[j][i] = center_module[i][j];
                assign n_output_perm[j][i]   = center_perm[i][j];
            end
        end
    endgenerate

    logic [CLOS_SIZE-1:0] num_counter [IM_OM_NUM-1:0];
    logic [IM_OM_NUM_TAG-1:0] om_dest;

    always_comb begin : n_center_comb
        for (int i = 0; i < IM_OM_NUM; i++) begin
            num_counter[i] = 0;
        end
        
        for (int i = 0; i < IM_OM_NUM; i++) begin
            for (int j = 0; j < IM_OM_SIZE; j++) begin
                om_dest = ((input_perm[i][j]) >> 2);
                n_center_module[num_counter[om_dest]][om_dest] = input_module[i][j];
                n_center_perm[num_counter[om_dest]][om_dest]   = input_perm[i][j];
                num_counter[om_dest] += 1;
            end
        end
    end
endmodule

