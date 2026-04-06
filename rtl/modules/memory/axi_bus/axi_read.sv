`include "axi_bus_if.sv"
`include "axi_bus_pkg.sv"

module axi_read
import axi_bus_pkg::*;
(
    input logic CLK, nRST,
    axi_bus_if abif
); 
    logic [ARGRANT-1:0] grant_sel;
    logic ar_valid;

    // ============== AR BEGIN =============
    axi_read_manager #(
        .MASTER_ID(MID_SP0)
    ) SP0_M (
        .CLK(CLK),
        .nRST(nRST),
        .arvalid(abif.ar_sp0_valid),
        .master_in(abif.ar_sp0_i),
        .arready(abif.ar_sp0_ready),
        .pop(abif.sp0_pop),
        .manager_out(abif.ar_sp0_o),
        .req(abif.sp0_req_r)
    );

    axi_read_manager #(
        .MASTER_ID(MID_SP1)
    ) SP1_M (
        .CLK(CLK),
        .nRST(nRST),
        .arvalid(abif.ar_sp1_valid),
        .master_in(abif.ar_sp1_i),
        .arready(abif.ar_sp1_ready),
        .pop(abif.sp1_pop),
        .manager_out(abif.ar_sp1_o),
        .req(abif.sp1_req_r)
    );

    axi_read_manager #(
        .MASTER_ID(MID_D)
    ) D_M (
        .CLK(CLK),
        .nRST(nRST),
        .arvalid(abif.ar_d_valid),
        .master_in(abif.ar_d_i),
        .arready(abif.ar_d_ready),
        .pop(abif.d_pop),
        .manager_out(abif.ar_d_o),
        .req(abif.d_req_r)
    );

    axi_read_manager #(
        .MASTER_ID(MID_I)
    ) I_M (
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
        abif.ar_o = '0;
        abif.sp0_pop = 0;
        abif.sp1_pop = 0;
        abif.i_pop = 0;
        abif.d_pop = 0;
        if (grant_sel[2]) begin
            casez (grant_sel[1:0])
                2'b00: begin
                    abif.sp0_pop = 1;
                    abif.ar_o = abif.ar_sp0_o;
                end
                2'b01: begin
                    abif.sp1_pop = 1;
                    abif.ar_o = abif.ar_sp1_o;
                end 
                2'b10: begin
                    abif.d_pop = 1;
                    abif.ar_o = abif.ar_d_o;
                end 
                2'b11: begin
                    abif.i_pop = 1;
                    abif.ar_o = abif.ar_i_o;
                end
                default: ;
            endcase
        end
    end

    assign abif.ar_o_valid = abif.i_req_r | abif.d_req_r | abif.sp0_req_r | abif.sp1_req_r;
    // ============== AR END =============

    // ============== R BEGIN =============
    axi_read_router #(
        .MID_SP0(MID_SP0),
        .MID_SP1(MID_SP1),
        .MID_I(MID_I),
        .MID_D(MID_D)
    ) ROUTER (
        CLK, nRST, abif
    );
    // ============== R END =============


endmodule