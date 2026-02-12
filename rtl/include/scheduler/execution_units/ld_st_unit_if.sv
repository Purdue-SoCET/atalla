`ifndef LD_ST_UNIT_IF_VH
`define LD_ST_UNIT_IF_VH

interface ld_st_unit_if;


    //to dcache
    logic WEN, REN, halfWord_dcache;
    logic [31:0] data_store, data_addr;

    //from dcache
    logic [31:0] data_load;
    logic hit;

    //from decode 2
    logic [31:0] addr, data_in;
    logic [7:0] rdIn;
    logic halfWord, valid_in, ld, st;

    //to decode 2
    logic ready_in;

    //from WB
    logic ready_out;

    //to WB
    logic [31:0] data_out;
    logic [7:0] rdOut;
    logic valid_out;

    modport ld_st (
        input rdIn, halfWord, valid_in, ld, st, data_load, hit, ready_out, addr, data_in,
        output WEN, REN, data_store, data_addr, ready_in, data_out, rdOut, valid_out, halfWord_dcache
    );

    modport tb (
        input WEN, REN, data_store, data_addr, ready_in, data_out, rdOut, valid_out, halfWord_dcache,
        output rdIn, halfWord, valid_in, ld, st, data_load, hit, ready_out, addr, data_in
    );

endinterface
`endif
