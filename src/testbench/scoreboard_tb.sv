`timescale 1ns / 10ps
`include "scoreboard_if.vh"
`include "datapath_types.vh"
`include "isa_types.vh"


import isa_pkg::*;
import datapath_pkg::*;

module scoreboard_tb;

    parameter PERIOD = 10;
    logic CLK = 0, nRST;

    always #(PERIOD/2) CLK++;

    scoreboard_if sbif();

    test PROG (.CLK(CLK), .nRST(nRST), .sbif(sbif));

    scoreboard DUT (.CLK(CLK), .nRST(nRST), .sbif(sbif));

endmodule

program test (
    input logic CLK, 
    output logic nRST,
    scoreboard_if.tb sbif
);

    task reset_dut;
        begin
            nRST = 1'b0;

            @(posedge CLK);
            @(posedge CLK);

            @(negedge CLK);
            nRST = 1'b1;

            @(negedge CLK);
            @(negedge CLK);
        end
    endtask

    task reset_in;
        begin
            sbif.flush = '0;
            sbif.freeze = '0;
            sbif.wb = '0;
            sbif.fetch = '0;
            @(posedge CLK);
        end
    endtask

    task rtype_instr;
        input opcode_t opcode;
        input regbits_t rd;
        input regbits_t rs1;
        input regbits_t rs2;
        input funct3_r_t funct3;
        input funct7_r_t funct7;
        begin
            sbif.fetch.imemload = {funct7, rs2, rs1, funct3, rd, opcode};
            @(posedge CLK);
        end
    endtask

    task itype_instr;
        input opcode_t opcode;
        input regbits_t rd;
        input regbits_t rs1;
        input funct3_r_t funct3;
        input logic [11:0] imm;
        begin
            sbif.fetch.imemload = {imm, rs1, funct3, rd, opcode};
            @(posedge CLK);
        end
    endtask

    task stype_instr;
        input opcode_t opcode;
        input regbits_t rs1;
        input regbits_t rs2;
        input funct3_r_t funct3;
        input logic [11:0] imm;
        begin
            sbif.fetch.imemload = {imm[11:5], rs2, rs1, funct3, imm[4:0], opcode};
            @(posedge CLK);
        end
    endtask

    task btype_instr;
        input opcode_t opcode;
        input regbits_t rs1;
        input regbits_t rs2;
        input funct3_r_t funct3;
        input logic [12:0] imm;
        begin
            sbif.fetch.imemload = {imm[12], imm[10:5], rs2, rs1, funct3, imm[4:1], imm[11], opcode};
            @(posedge CLK);
        end
    endtask

    task jtype_instr;
        input opcode_t opcode;
        input regbits_t rd;
        input logic [20:0] imm;
        begin
            sbif.fetch.imemload = {imm[20], imm[10:1], imm[11], imm[19:12], rd, opcode};
            @(posedge CLK);
        end
    endtask

    task m_ls_instr;
        input opcode_t opcode;
        input matbits_t rd;
        input regbits_t rs1;     // reg file register that holds location of matrix wanted
        input regbits_t stride;  // offset
        input logic [10:0] imm;
        begin
            sbif.fetch.imemload = {rd, rs1, stride, imm[10:0], opcode};
            @(posedge CLK);
        end
    endtask

    task gemm_instr;
        input opcode_t opcode;
        input matbits_t rd;
        input matbits_t ra;
        input matbits_t rb;
        input matbits_t rc;
        begin
            sbif.fetch.imemload = {rd, ra, rb, rc, 9'd0, opcode};
            @(posedge CLK);
        end
    endtask

    initial begin

        reset_in();
        reset_dut();

        @(posedge CLK);

        // (opcode, rd, rs1, rs2, funct3, funct7)
        rtype_instr(RTYPE, 5'd10, 5'd11, 5'd12, ADD_SUB, ADD); 
        rtype_instr(RTYPE, 5'd15, 5'd10, 5'd12, ADD_SUB, ADD);

        // once that instruction is done and wb sends done, send second instruction
        // allow second instruction to go through 
        // do the same as above but add a load/store instruction for the third instruction 
        // let it all go through 

        // do three s type instructions all back to back no dependencies
        
        // do three s type instructions all back to back with dependencies 
        // do three i type (lw) instructions all back to back no dependencies
        
        // do three i type (lw) instructions all back to back with dependencies 
        // mix and match the above
        // go into matrix stuff now, similar to the above stuff

        @(posedge CLK);
        @(posedge CLK);
        

        $finish;
    end


endprogram
