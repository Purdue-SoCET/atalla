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
`include "ddr_controller_if.vh"
`include "address_mapper_if.vh"
`include "dram_pkg.vh"

typedef struct packed {
    logic [3:0] len;
    logic [$clog2(ID_NUM) - 1:0] id;
    logic [31:0] addr;
    logic valid;
} buf_slot_t;

module frontend_arb (
    input logic CLK, nRST, 
    ddr_controller_if.arb arb
);

    // types import //
    import dram_pkg::*;
    address_mapper_if amif();

    buf_slot_t buff_l, buff_ln, buff_s, buff_sn;
    logic pri, pri_n;
    logic pri_bq, pri_bq_n;

    logic [1:0] rqst_select;
    assign rqst_select = {arb.request_l, arb.request_s};

    logic [1:0][31:0] addr_sel;
    assign addr_sel = {arb.address_l, arb.address_s};

    logic [1:0][3:0] len_sel;
    assign len_sel = {arb.len_l, arb.len_s};

    logic [1:0][$clog2(ID_NUM) - 1:0] id_sel;
    assign id_sel = {arb.id_l, arb.id_s};

    // mapper instance //
    // modport addr_mapper (
    //     input  address, configs,
    //     output rank, BG, bank, row, col, offset, ignore
    // );
    address_mapper AM (amif);

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
            arb.fe_if = buff_s.id;

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
            arb.fe_if = buff_l.id;

            buff_sn.valid = 0;
            arb.fe_write_bq = 1;
        end

        // read front-end queue logic //
        if(~pri && rqst_select[~pri] && ~buff_l.valid) begin
            arb.grant_l = 1;
            buff_ln.valid = 1;
            buff_ln.addr = addr_sel[0];
            buff_ln.id = id_sel[0];
            buff_ln.len = len_sel[0];
        end

        if(pri && rqst_select[pri] && ~buff_s.valid) begin
            arb.grant_s = 1;
            buff_sn.valid = 1;
            buff_sn.addr = addr_sel[0];
            buff_sn.id = id_sel[0];
            buff_sn.len = len_sel[0];
        end
    end
endmodule