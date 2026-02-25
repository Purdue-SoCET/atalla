`timescale 1ns / 10ps
`include "execution_unit_if.sv"
`include "scheduler_pkg.sv"
`include "atalla_isa_types.vh"

module scheduler_core_tb;
    import execution_unit_types_pkg::*;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;
    string casename;

    instr_t [3:0] scalar_instrs;
    logic hit;
    logic [31:0] data_load;
    logic [31:0] pred_pc, pc;
    logic pred_taken;
    logic ready_DEC2_out;

    scheduler_core DUT (.CLK(CLK), .nRST(nRST), .hit(hit), .data_load(data_load), .scalar_instrs(scalar_instrs), .predict_taken_in(pred_taken), .pc_in(pc), .pc_pred_addr_in(pred_pc), .ready(ready_DEC2_out));


    initial begin
        casename = "rst";
        scalar_instrs = '{default: '0};
        data_load = 32'b0;
        hit = 1'b0;
        pred_pc = 32'b0;
        pc = 32'b0;
        pred_taken = 1'b0;
        nRST = 1'b0;

        @(posedge CLK);
        @(posedge CLK);
        nRST = 1'b1;
        @(posedge CLK);
        @(posedge CLK);


        @(negedge CLK);
        scalar_instrs[0] = 48'h000000810304; // // DIV_S rd=6, rs1=2, rs2=1
        scalar_instrs[1] = 48'h2f; //NOP
        scalar_instrs[2] = 48'h2f; //NOP
        scalar_instrs[3] = 48'h2f; //NOP

        repeat(80) @(negedge CLK);


        $display("DONE");
        $finish;
    end


endmodule