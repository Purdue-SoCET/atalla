`ifndef VLS_IF_VH
`define VLS_IF_VH
`include "vector_types.vh"
`include "vector_if.vh"

/*
I'm ngl I have no idea how to create an interface file properly lol
Will be figuring this out as I go along, but currently will take a look at the existing vls_if.vh file and modify it for vlsu needs.
Will also be changing a bunch of stuff as the bitspec for vLSU is different from vLS.sv
*/

interface vls_if;
    import vector_pkg::*;

    // Most of this was taken from the bitspec doc for vLSU, idk if thats how I'm supposed to do it tho
    //Inputs to Vector LSU
    logic [4:0] rc_id;      // Row/Column ID input, from the bitspec in ISA doc (Which row or column)
    logic op;               // Operation input, need to know whether its a load or store
    logic rc;               // Row or Column indicator input
    logic sid;              // Scratchpad ID input, which scratchpad to access
    logic [4:0] num_rows;   // don't question it, needed for spad, smth smth ask Akshath lol
    logic [4:0] num_cols;   // don't question it, needed for spad, smth smth ask Akshath lol
    logic [7:0] rs1;        // Base row of scratchpad
    logic [7:0] vd;         // Vector destination register

    // Need to add the scratchpad vector frontend thing here:
    // Actually maybe not, I think I may be able to simply put the 

    //Outputs from Vector LSU

