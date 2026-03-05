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
        imemload.inst0 = 48'h00003c000096;
        imemload.inst1 = 48'h2f; //NOP
        imemload.inst2 = 48'h2f; //NOP
        imemload.inst3 = 48'h2f; //NOP
        @(negedge CLK);
        ihit = 1'b0;

        repeat(8) @(posedge CLK);

        @(negedge CLK);
        ihit = 1'b1;
        imemload.inst0 = 48'h00003c008196;
        imemload.inst1 = 48'h000005008119; //NOP
        imemload.inst2 = 48'h000001008218; //NOP
        imemload.inst3 = 48'h2f; //NOP

        @(negedge CLK);
        ihit = 1'b1;
        imemload.inst0 = 48'h000022800296;
        imemload.inst1 = 48'h2f; //NOP
        imemload.inst2 = 48'h2f; //NOP
        imemload.inst3 = 48'h2f; //NOP
        @(negedge CLK);
        ihit = 1'b0;

        repeat(80) @(posedge CLK);


        $display("DONE");
        $finish;
    end


endmodule