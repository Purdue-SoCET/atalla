`include "axi_bus_if.sv"
`include "axi_bus_pkg.sv"

module axi_read_router # (
    parameter MID_I = 0, MID_D = 1, MID_SP0 = 2, MID_SP1 = 3
) (
    input logic CLK, nRST,
    axi_bus_if.router rif
);
    import axi_bus_pkg::*;
    
    master_r_channel_t sp0_o, sp1_o, i_o, d_o;
    logic sp0_sel, sp1_sel, i_sel, d_sel;

    axi_skid_buffer SKID_SP0 (
        .CLK(CLK),
        .nRST(nRST),
        .r_in(sp0_o),
        .ready(rif.r_sp0_o_ready),
        .selected(sp0_sel),
        .in_val(rif.r_valid),
        .out_val(rif.r_sp0_o_valid),
        .r_out(rif.r_sp0_o)
    );

    axi_skid_buffer SKID_SP1 (
        .CLK(CLK),
        .nRST(nRST),
        .r_in(sp1_o),
        .ready(rif.r_sp1_o_ready),
        .selected(sp1_sel),
        .in_val(rif.r_valid),
        .out_val(rif.r_sp1_o_valid),
        .r_out(rif.r_sp1_o)
    );

    axi_skid_buffer SKID_I (
        .CLK(CLK),
        .nRST(nRST),
        .r_in(i_o),
        .ready(rif.r_i_o_ready),
        .selected(i_sel),
        .in_val(rif.r_valid),
        .out_val(rif.r_i_o_valid),
        .r_out(rif.r_i_o)
    );

    axi_skid_buffer SKID_D (
        .CLK(CLK),
        .nRST(nRST),
        .r_in(d_o),
        .ready(rif.r_d_o_ready),
        .selected(d_sel),
        .in_val(rif.r_valid),
        .out_val(rif.r_d_o_valid),
        .r_out(rif.r_d_o)
    );

    always_comb begin
        sp0_sel = 0;
        sp1_sel = 0;
        i_sel = 0;
        d_sel = 0;

        sp0_o = '0;
        sp1_o = '0;
        i_o = '0;
        d_o = '0;

        rif.r_ready = 0;

        casez (rif.r_i.mid)

            MID_SP0: begin
                rif.r_ready = rif.r_sp0_o_ready;
                sp0_sel = rif.r_valid;

                sp0_o.data = rif.r_i.data;
                sp0_o.id = rif.r_i.id;
                sp0_o.resp = rif.r_i.resp;
                sp0_o.last = rif.r_i.last;
                
            end

            MID_SP1: begin
                rif.r_ready = rif.r_sp1_o_ready;
                sp1_sel = rif.r_valid;

                sp1_o.data = rif.r_i.data;
                sp1_o.id = rif.r_i.id;
                sp1_o.resp = rif.r_i.resp;
                sp1_o.last = rif.r_i.last;

            end

            MID_I: begin
                rif.r_ready = rif.r_i_o_ready;
                i_sel = rif.r_valid;

                i_o.data = rif.r_i.data;
                i_o.id = rif.r_i.id;
                i_o.resp = rif.r_i.resp;
                i_o.last = rif.r_i.last;
                
            end

            MID_D: begin
                rif.r_ready = rif.r_d_o_ready;
                d_sel = rif.r_valid;

                d_o.data = rif.r_i.data;
                d_o.id = rif.r_i.id;
                d_o.resp = rif.r_i.resp;
                d_o.last = rif.r_i.last;

            end
            default: ;
        endcase
    end

endmodule