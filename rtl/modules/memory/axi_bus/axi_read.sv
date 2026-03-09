`include "axi_bus_if.sv"
`include "axi_bus_pkg.sv"

module axi_read
import axi_bus_pkg::*;
(
    input logic CLK, nRST,
    axi_bus_if abif
);

    logic [ARGRANT-1:0] grant_sel;
    sub_ar_channel_t ar_o_buf, ar_o;

    // ============== AR BEGIN =============
    axi_read_manager SP0_M (
        .CLK(CLK),
        .nRST(nRST),
        .arvalid(abif.ar_sp0_valid),
        .master_in(abif.ar_sp0_i),
        .arready(abif.ar_sp0_ready),
        .pop(abif.sp0_pop),
        .manager_out(abif.ar_sp0_o),
        .req(abif.sp0_req_r)
    );

    axi_read_manager SP1_M (
        .CLK(CLK),
        .nRST(nRST),
        .arvalid(abif.ar_sp1_valid),
        .master_in(abif.ar_sp1_i),
        .arready(abif.ar_sp1_ready),
        .pop(abif.sp1_pop),
        .manager_out(abif.ar_sp1_o),
        .req(abif.sp1_req_r)
    );

    axi_read_manager D_M (
        .CLK(CLK),
        .nRST(nRST),
        .arvalid(abif.ar_d_valid),
        .master_in(abif.ar_d_i),
        .arready(abif.ar_d_ready),
        .pop(abif.d_pop),
        .manager_out(abif.ar_d_o),
        .req(abif.d_req_r)
    );

    axi_read_manager I_M (
        .CLK(CLK),
        .nRST(nRST),
        .arvalid(abif.ar_i_valid),
        .master_in(abif.ar_i_i),
        .arready(abif.ar_i_ready),
        .pop(abif.i_pop),
        .manager_out(abif.ar_i_o),
        .req(abif.i_req_r)
    );

    axi_read_arbiter ARBITER (
        .CLK(CLK),
        .nRST(nRST),
        .ready(abif.ar_o_ready),
        .sp0_req(abif.sp0_req_r),
        .sp1_req(abif.sp1_req_r),
        .d_req(abif.d_req_r),
        .i_req(abif.i_req_r),
        .grant_sel(grant_sel)
    );

    // AR MUX
    always_comb begin
        ar_o_buf = '0;
        casez (grant_sel)
            //TODO: ask Aryan


        endcase

    end

    axi_skid_buffer SKID (
        .CLK(CLK),
        .nRST(nRST),
        .r_in(ar_o_buf),
        .ready(abif.ar_o_ready),
        .selected(1),
        .in_val(grant_sel!=0), //TODO: ask aryan
        .r_out(abif.ar_o),
        .out_val(ar_o_valid)
    );

    // ============== AR END =============

    // ============== R BEGIN =============
    axi_read_router ROUTER (
        CLK, nRST, abif
    );
    // ============== R END =============


endmodule