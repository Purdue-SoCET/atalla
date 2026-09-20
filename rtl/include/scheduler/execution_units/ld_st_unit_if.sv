`ifndef LD_ST_UNIT_IF_VH
`define LD_ST_UNIT_IF_VH
`include "atalla_isa_types.vh"

interface ld_st_unit_if;
    import atalla_isa_pkg::*;


    //to dcache
    logic WEN, REN, mem_in_valid;
    logic [31:0] data_store, data_addr;

    //from dcache
    logic [31:0] data_load;
    logic hit, block_status, stall, miss;

    //from decode 2
    logic [31:0] addr, data_in;
    logic [7:0] rdIn;
    logic halfWord, valid_in;
    scalar_fu_enable_t scalar_type_enable;

    //to decode 2
    logic ready_in;

    //from WB
    logic ready_out;

    //to WB
    logic [31:0] data_out;
    logic [7:0] rdOut;
    logic valid_out;

    modport ld_st (
        input rdIn, halfWord, valid_in, scalar_type_enable, data_load, hit, block_status, stall, miss, ready_out, addr, data_in,
        output WEN, REN, mem_in_valid, data_store, data_addr, ready_in, data_out, rdOut, valid_out
    );

    modport tb (
        input WEN, REN, mem_in_valid, data_store, data_addr, ready_in, data_out, rdOut, valid_out,
        output rdIn, halfWord, valid_in, scalar_type_enable, data_load, hit, block_status, stall, miss, ready_out, addr, data_in
    );

endinterface
`endif
