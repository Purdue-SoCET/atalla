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
        imemload.inst0 = 48'h000002000116; // ADD_I {'opcode': 0b0010110, 'rs1': 0, 'rd': 2, 'imm12': 2}
        imemload.inst1 = 48'h2f; //NOP
        imemload.inst2 = 48'h2f; //NOP
        imemload.inst3 = 48'h2f; //NOP

        @(negedge CLK);
        ihit = 1'b1;
        imemload.inst0 = 48'h000001008181; // ADD_S rd=3, rs1=1, rs2=2
        imemload.inst1 = 48'h2f; //NOP
        imemload.inst2 = 48'h2f; //NOP
        imemload.inst3 = 48'h2f; //NOP
        @(negedge CLK);
        ihit = 1'b0;

        repeat(8) @(posedge CLK);


        // Test 1: SUB_S, 
        set_tv(
            .tv_instr0(48'h2f), // NOP
            .tv_instr1(48'h000000810202), // SUB_S rd=4, rs1=2, rs2=1
            .tv_instr2(48'h2f), // NOP
            .tv_instr3(48'h2f), // NOP
            .idx(1)
        );

        // Test 2: OR.S
        set_tv(
            .tv_instr0(48'h000001008286), // OR.S {'opcode': 6, 'rs1': 1, 'rs2': 2, 'rd': 3}
            .tv_instr1(48'h2f), // NOP
            .tv_instr2(48'h2f), // NOP
            .tv_instr3(48'h2f), // NOP
            .idx(2)
        );

        // Test 3: AND.S
        set_tv(
            .tv_instr0(48'h000001008307), // AND.S {'opcode': 7, 'rs1': 1, 'rs2': 2, 'rd': 4}
            .tv_instr1(48'h2f), // NOP
            .tv_instr2(48'h2f), // NOP
            .tv_instr3(48'h2f), // NOP
            .idx(3)
        );

        // Test 4: XOR.S
        set_tv(
            .tv_instr0(48'h000001008388), // XOR.S {'opcode': 8, 'rs1': 1, 'rs2': 2, 'rd': 5}
            .tv_instr1(48'h2f), // NOP
            .tv_instr2(48'h2f), // NOP
            .tv_instr3(48'h2f), // NOP
            .idx(4)
        );

        // Test 5: SLL.S
        set_tv(
            .tv_instr0(48'h000001008409), // SLL.S{'opcode': 9, 'rs1': 1, 'rs2': 2, 'rd': 6}
            .tv_instr1(48'h2f), // NOP
            .tv_instr2(48'h2f), // NOP
            .tv_instr3(48'h2f), // NOP
            .idx(5)
        );

        // Test 6: SRL.S
        set_tv(
            .tv_instr0(48'h00000100848a), // SRL.S{'opcode': 10, 'rs1': 1, 'rs2': 2, 'rd': 7}
            .tv_instr1(48'h2f), // NOP
            .tv_instr2(48'h2f), // NOP
            .tv_instr3(48'h2f), // NOP
            .idx(6)
        );

        // Test 7: SRA.S
        set_tv(
            .tv_instr0(48'h00000100850b), // SRA.S {'opcode': 11, 'rs1': 1, 'rs2': 2, 'rd': 8}
            .tv_instr1(48'h2f), // NOP
            .tv_instr2(48'h2f), // NOP
            .tv_instr3(48'h2f), // NOP
            .idx(7)
        );

        // Test 8: SLT.S
        set_tv(
            .tv_instr0(48'h00000100858c), // SLT.S {'opcode': 12, 'rs1': 1, 'rs2': 2, 'rd': 9}
            .tv_instr1(48'h2f), // NOP
            .tv_instr2(48'h2f), // NOP
            .tv_instr3(48'h2f), // NOP
            .idx(8)
        );

        // Test 9: SLTU.S
        set_tv(
            .tv_instr0(48'h00000100860d), // SLTU.S {'opcode': 13, 'rs1': 1, 'rs2': 2, 'rd': 10}
            .tv_instr1(48'h2f), // NOP
            .tv_instr2(48'h2f), // NOP
            .tv_instr3(48'h2f), // NOP
            .idx(9)
        );




        $display("DONE");
        $finish;
    end


endmodule