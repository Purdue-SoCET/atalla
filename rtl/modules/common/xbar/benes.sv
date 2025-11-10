// /*  Haejune Kwon - kwon196@purdue.edu */
// /*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`include "xbar_params.svh"
`include "xbar_if.sv"

import xbar_pkg::*;

module benes #(
    parameter int SIZE = `BENES_SIZE,
    parameter int DWIDTH = `BENES_DWIDTH,

    parameter int TAGWIDTH = $clog2(SIZE),
    parameter int STAGES = (2 * TAGWIDTH) - 1, 
    parameter int HALF = (SIZE >> 1),
    parameter int BITWIDTH = STAGES * HALF

    parameter logic [STAGES-2:0] REGISTER_MASK = `BENES_REGISTER_MASK
) (
    xbar_if.xbar xif,
    input logic [BITWIDTH-1:0] control_bit
);
    logic [DWIDTH-1:0] out_latch [STAGES][SIZE];
    logic [DWIDTH-1:0] in_latch [STAGES][SIZE];
    logic [DWIDTH-1:0] reg_latch [STAGES-1][SIZE];

    always_ff @(posedge xif.clk, negedge xif.n_rst) begin
        if (!xif.n_rst) begin
            for (int s = 0; s < STAGES-1; s++) begin
                for (int i = 0; i < SIZE; i++) begin
                    reg_latch[s][i] <= '0;
                end
            end
        end else begin
            for (int s = 0; s < STAGES-1; s++) begin
                if (REGISTER_MASK[s]) begin
                    for (int i = 0; i < SIZE; i++) begin
                        reg_latch[s][i] <= out_latch[s][i];
                    end
                end
            end
        end
    end

    generate
        genvar gi, gs;
        for (gs = 1; gs < STAGES; gs++) begin //  generate in_latch
            for (gi = 0; gi < SIZE; gi++) begin 
                assign in_latch[gs][gi] = REGISTER_MASK[gs-1] ? reg_latch[gs-1][gi] : out_latch[gs-1][gi];
            end
        end
    endgenerate

    generate
        genvar stage, j, group;
        for (stage = 0; stage < STAGES; stage++) begin
            if (stage == 0) begin 
                for (j = 0; j < SIZE; j += 2) begin 
                    localparam int ctrl = (0 * HALF) + (j/2); // base 0
                    crossover_switch #(.SIZE(DWIDTH)) u_sw (
                        .din({xif.in[j], xif.in[j+1]}),
                        .cntrl(control_bit[ctrl]),
                        .dout({out_latch[0][j], out_latch[0][j+1]})
                    );
                end
            end

            else if (stage == (STAGES-1)) begin 
                localparam int CTRL_BASE = (STAGES-1) * HALF;
                for (j = 0; j < SIZE; j += 2) begin 
                    localparam int ctrl = CTRL_BASE + (j/2);
                    crossover_switch #(.SIZE(DWIDTH)) u_sw (
                        .din({in_latch[stage][j], in_latch[stage][j+1]}),
                        .cntrl(control_bit[ctrl]),
                        .dout({out_latch[stage][j], out_latch[stage][j+1]})
                    );
                end
            end

            else begin 
                localparam int d = (stage < TAGWIDTH) ? (1 << stage) : (1 << ((STAGES-1) - stage));
                for (group = 0; group < (HALF / d); group++) begin
                    localparam int base_idx = group * (d << 1);            
                    localparam int ctrl_adj = (stage * HALF) - (d * group); 

                    for (j = 0; j < d; j++) begin : PAIR
                        localparam int idx  = base_idx + j;
                        localparam int ctrl = ctrl_adj + idx;

                        crossover_switch #(.SIZE(DWIDTH)) u_sw (
                            .din({in_latch[stage][idx], in_latch[stage][idx + d]}),
                            .cntrl(control_bit[ctrl]),
                            .dout({out_latch[stage][idx], out_latch[stage][idx + d]})
                        );
                    end
                end
            end
        end
    endgenerate

    always_comb begin
        for (int i = 0; i < SIZE; i++) begin
            xif.out[i] = out_latch[STAGES-1][i];
        end
    end

endmodule
