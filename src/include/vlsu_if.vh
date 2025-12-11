`ifndef VLS_IF_VH
`define VLS_IF_VH
`include "vector_if.vh"
//`include "scpad_if.sv"
`include "vector_pkg.vh"
`include "scpad_pkg.vh"


/*
I'm ngl I have no idea how to create an interface file properly lol
Will be figuring this out as I go along, but currently will take a look at the existing vls_if.vh file and modify it for vlsu needs.
Will also be changing a bunch of stuff as the bitspec for vLSU is different from vLS.sv
*/

interface vls_if;
    import scpad_pkg::*;
    import vector_pkg::*;

    typedef struct packed {
        logic [4:0] rc_id;      // Row/Column ID input, from the bitspec in ISA doc (Which row or column)
        logic rc; // 0 = row, 1 = column
        vsel_t vd;
        reg_t rs1; // base address
        logic [4:0] num_rows;   // don't question it, needed for spad, smth smth ask Akshath lol
        logic [4:0] num_cols;
    } vm_if_t;

    //Input struct
    typedef struct packed {
        vm_if_t [NUM_SP-1:0] sp_in;
        logic [NUM_SP-1:0] op;
        vr_in_t [NUM_SP-1:0] sp_vr; // 0 idx = sp0, 1 = sp1, 2 = sched, 3 = wb
        vr_in_t wb_vr;
        logic sched_ready_in;
        vreg_t wdata;
    } vls_input_t;

    typedef struct packed {
        vr_out_t [NUM-1:0] sp_out;
        
    } vls_output_t;

    typedef struct packed {
        logic valid_in;
        logic read_in;
    } vr_in_t;

    typedef struct packed {
        logic valid_out;
        logic read_out;
    } vr_out_t;


    // Most of this was taken from the bitspec doc for vLSU, idk if thats how I'm supposed to do it tho
    //Inputs to Vector LSU


    
    logic [4:0] rc_id;      // Row/Column ID input, from the bitspec in ISA doc (Which row or column)
    logic op;               // Operation input, need to know whether its a load or store
    logic rc;               // Row or Column indicator input
    //logic sid;            // Scratchpad ID input, which scratchpad to access
    logic [4:0] num_rows;   // don't question it, needed for spad, smth smth ask Akshath lol
    logic [4:0] num_cols;   // don't question it, needed for spad, smth smth ask Akshath lol
    logic [7:0] rs1;        // Base row of scratchpad
    logic [7:0] vd;         // Vector destination register
    logic valid_in_1;       // valid signal
    logic valid_out_1;      // valid signal
    logic valid_in_2;       // valid signal
    logic valid_out_2;      // valid signal
    logic ready_in_1;       // ready signal
    logic ready_in_2;       // ready signal

    logic [16*32-1:0] wdata; // Data to be written to scratchpad from veggie file during store operations

    // Performance Benchmarks, suggestion counter fifo full vs fifo empty work storein starvation detection



    // Vector to Frontend Scratchpad Interface
    modport vlsu (
        // inputs: instruction fields
        input valid, op, sid, rc, rc_id, num_rows, num_cols, rs1, vd,
        // outputs: handshake / pass-through / writeback notifications
        output ready,
        output req_valid, req_op, req_sid, req_rc, req_rc_id, req_num_rows, req_num_cols, req_rs1, req_vd,
        output sp0_load_valid, sp0_veg_dst_idx, sp1_load_valid, sp1_veg_dst_idx
    );




    // Need to add the scratchpad vector frontend thing here:
    // Actually maybe not, I think I may be able to simply put the


    //Outputs from Vector LSU

endinterface 
`endif