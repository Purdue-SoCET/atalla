// modport arb (
//     //STQ -> ARB
//     input request_s, address_s, id_s, len_s,
//     //LQ -> ARB
//     request_l, address_l, id_l, len_l,
//     //BQ -> ARB
//     fe_full, 
//     //ARB -> LQ
//     output grant_l,
//     //ARB -> STQ
//     grant_s, 
//     //ARB -> BQ
//     fe_bg, fe_b, fe_r, fe_c, fe_write, fe_id, fe_write_bq, fe_len
// );

// Front End Arbiter //
`include "ddr_controller_if.sv"
`include "address_mapper_if.vh"
`include "dram_pkg.svh"

module frontend_arb (
    input logic CLK, nRST, 
    ddr_controller_if.arb arb
);

    // types import //
    import dram_pkg::*;

    typedef struct packed {
        logic [3:0] len;
        logic [$clog2(ID_NUM) - 1:0] id;
        logic [31:0] addr;
        logic valid;
    } buf_slot_t;

    address_mapper_if amif();

    buf_slot_t buff_l, buff_ln, buff_s, buff_sn;
    logic pri, pri_n;
    logic pri_bq, pri_bq_n;

    logic [1:0] rqst_select;
    assign rqst_select = {arb.request_l, arb.request_s};

    lstq_slot_t [1:0] slot_sel;
    assign slot_sel = {arb.lq_slot, arb.stq_slot};

    // mapper instance //
    // modport addr_mapper (
    //     input  address, configs,
    //     output rank, BG, bank, row, col, offset, ignore
    // );
    addr_mapper AM (amif);

    always_ff @ (posedge CLK, negedge nRST) begin
        if(~nRST) begin
            buff_l <= '0;
            buff_s <= '0;
            pri <= 0;
            pri_bq <= 0;
        end else begin
            buff_l <= buff_ln;
            buff_s <= buff_sn;
            pri <= pri_n;
            pri_bq <= pri_bq_n;
        end
    end

    always_comb begin
        buff_ln = buff_l;
        buff_sn = buff_s;
        pri_n = pri;
        pri_bq_n = pri_bq;

        // Default outputs
        arb.grant_l = 0;
        arb.grant_s = 0;
        arb.fe_write_bq = 0;
        arb.fe_bg = '0;
        arb.fe_b = '0;
        arb.fe_r = '0;
        arb.fe_c = '0;
        arb.fe_write = 0;
        arb.fe_id = '0;
        arb.fe_len = '0;

        amif.address = (pri_bq) ? buff_s.addr : buff_l.addr;
        amif.configs = x8;

        // RR pri logic //
        if((pri && rqst_select[~pri]) || (~pri && rqst_select[pri])) begin
            pri_n = ~pri;
        end

        if((~pri_bq && buff_s.valid) || (pri_bq && buff_l.valid)) begin
            pri_bq_n = ~pri_bq;
        end

        // write BQ logic //
        //potential problem here, need to talk to jason about full signals from bq->arb
        if(pri_bq && ~arb.fe_full[{amif.BG, amif.bank}] && buff_s.valid) begin
            arb.fe_r = amif.row;
            arb.fe_bg = amif.BG;
            arb.fe_b = amif.bank;
            arb.fe_c = amif.col;
            arb.fe_write = 1;
            arb.fe_len = buff_s.len;
            arb.fe_id = buff_s.id;

            buff_sn.valid = 0;
            arb.fe_write_bq = 1;
        end

        if(~pri_bq && ~arb.fe_full[{amif.BG, amif.bank}] && buff_l.valid) begin
            arb.fe_r = amif.row;
            arb.fe_bg = amif.BG;
            arb.fe_b = amif.bank;
            arb.fe_c = amif.col;
            arb.fe_write = 0;
            arb.fe_len = buff_l.len;
            arb.fe_id = buff_l.id;

            buff_ln.valid = 0;
            arb.fe_write_bq = 1;
        end

        // read front-end queue logic //
        if(~pri && rqst_select[~pri] && ~buff_l.valid) begin
            arb.grant_l = 1;
            buff_ln.valid = 1;
            buff_ln.addr = slot_sel[1].addr;
            buff_ln.id = slot_sel[1].id;
            buff_ln.len = slot_sel[1].len;
        end

        if(pri && rqst_select[~pri] && ~buff_s.valid) begin
            arb.grant_s = 1;
            buff_sn.valid = 1;
            buff_sn.addr = slot_sel[0].addr;
            buff_sn.id = slot_sel[0].id;
            buff_sn.len = slot_sel[0].len;
        end
    end
endmodule