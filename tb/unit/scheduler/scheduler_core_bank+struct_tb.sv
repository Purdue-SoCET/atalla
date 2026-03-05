`timescale 1ns / 10ps
`include "execution_unit_if.sv"
`include "scheduler_pkg.sv"
`include "atalla_isa_types.vh"


module scheduler_core_tb;
    import execution_unit_types_pkg::*;
    import atalla_isa_pkg::*;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;
    string casename;

    logic dhit;
    logic [31:0] data_load;
    logic ready_DEC2_out;
    logic ihit;
    instruction_packet_t imemload;


    scheduler_core DUT (.CLK(CLK), .nRST(nRST), .hit(dhit), .data_load(data_load), .ihit(ihit), .imemload(imemload), .ready(ready_DEC2_out));

    task set_tv (
        input logic [47:0] tv_instr0, tv_instr1, tv_instr2, tv_instr3,
        // input logic [3:0][47:0] expected
        input int idx
    );

        $display(idx);
        @(negedge CLK);
        ihit = 1'b1;
        imemload.inst0 = tv_instr0;
        imemload.inst1 = tv_instr1;
        imemload.inst2 = tv_instr2;
        imemload.inst3 = tv_instr3;
        @(negedge CLK);
        ihit = 1'b0;

        repeat(8) @(negedge CLK);
    endtask


    initial begin

        casename = "rst";
        data_load = 32'b0;
        dhit = 1'b0;
        ihit = 1'b0;
        imemload = 'b0;
        nRST = 1'b0;

        @(posedge CLK);
        @(posedge CLK);
        nRST = 1'b1;
        @(posedge CLK);
        @(posedge CLK);


        @(negedge CLK);
        ihit = 1'b1;
        imemload.inst0 = 48'h000000800096;  // ADD_I {'opcode': 0b0010110, 'rs1': 0, 'rd': 1, 'imm12': 1}
        imemload.inst1 = 48'h2f; //NOP
        imemload.inst2 = 48'h2f; //NOP
        imemload.inst3 = 48'h2f; //NOP
        @(negedge CLK);
        ihit = 1'b0;

        repeat(8) @(posedge CLK);

        @(negedge CLK);
        ihit = 1'b1;
        imemload.inst0 = 48'h000002000116; // ADD_I {'opcode': 0b0010110, 'rs1': 0, 'rd': 2, 'imm12': 4}
        imemload.inst1 = 48'h2f; //NOP
        imemload.inst2 = 48'h2f; //NOP
        imemload.inst3 = 48'h2f; //NOP
        @(negedge CLK);
        ihit = 1'b0;

        repeat(8) @(posedge CLK);


        @(negedge CLK);
        ihit = 1'b1;
        imemload.inst0 = 48'h000000810204; // DIV_S {'opcode': 4, 'rs1': 2, 'rs2': 1, 'rd': 4} 
        imemload.inst1 = 48'h2f; //NOP
        imemload.inst2 = 48'h2f; //NOP
        imemload.inst3 = 48'h2f; //NOP



        @(negedge CLK);
        ihit = 1'b1;
        imemload.inst0 = 48'h000000810184; // DIV_S {'opcode': 4, 'rs1': 2, 'rs2': 1, 'rd': 3} 
        imemload.inst1 = 48'h000000810683; //MUL_S {'opcode': 0b0000011, 'rs1': 2, 'rs2': 1, 'rd': 13} #mul
        imemload.inst2 = 48'h2f; //NOP
        imemload.inst3 = 48'h2f; //NOP
        @(negedge CLK);
        ihit = 1'b0;

        repeat(150) @(posedge CLK);


        $display("DONE");
        $finish;
    end


endmodule