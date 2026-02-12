`timescale 1ns / 10ps
`include "ld_st_unit_if.sv"

module ld_st_unit_tb;


    parameter PERIOD = 2;
    logic CLK = 0, nRST;

    always #(PERIOD/2) CLK++;

    ld_st_unit_if ld_st_if ();
    ld_st_unit DUT (.CLK(CLK), .ld_st_if(ld_st_if));

    integer casenum;
    string casename;
    integer i;


initial begin
    casenum = 1;
    casename = "LD test, no hit";
    ld_st_if.rdIn = 32'd5;
    ld_st_if.addr = 32'hDEADBEEF;
    ld_st_if.ready_out = '1;
    ld_st_if.valid_in = '1;
    ld_st_if.halfWord = '0;
    ld_st_if.hit = '0;
    ld_st_if.data_load = '0;
    ld_st_if.data_in = '0;
    ld_st_if.ld = '1;
    ld_st_if.st = '0;
    #(PERIOD);
    #(PERIOD);

    casenum = 2;
    casename = "LD test, hit, WB stall";
    ld_st_if.rdIn = 32'd5;
    ld_st_if.addr = 32'hDEADBEEF;
    ld_st_if.ready_out = '0;
    ld_st_if.valid_in = '1;
    ld_st_if.halfWord = '0;
    ld_st_if.hit = '1;
    ld_st_if.data_load = 32'hDEEDDEED;
    ld_st_if.data_in = '0;
    ld_st_if.ld = '1;
    ld_st_if.st = '0;
    #(PERIOD);
    #(PERIOD);

    casenum = 3;
    casename = "LD test, hit";
    ld_st_if.rdIn = 32'd5;
    ld_st_if.addr = 32'hDEADBEEF;
    ld_st_if.ready_out = '1;
    ld_st_if.valid_in = '1;
    ld_st_if.halfWord = '0;
    ld_st_if.hit = '1;
    ld_st_if.data_load = 32'hDEEDDEED;
    ld_st_if.data_in = '0;
    ld_st_if.ld = '1;
    ld_st_if.st = '0;
    #(PERIOD);
    #(PERIOD);

    casenum = 4;
    casename = "IDLE";
    ld_st_if.rdIn = 32'd0;
    ld_st_if.addr = 32'h0;
    ld_st_if.ready_out = '1;
    ld_st_if.valid_in = '0;
    ld_st_if.halfWord = '0;
    ld_st_if.hit = '0;
    ld_st_if.data_load = 32'h0;
    ld_st_if.data_in = '0;
    ld_st_if.ld = '0;
    ld_st_if.st = '0;
    #(PERIOD);
    #(PERIOD);

    casenum = 5;
    casename = "LD test, no hit, hw";
    ld_st_if.rdIn = 32'd5;
    ld_st_if.addr = 32'hDEADBEEF;
    ld_st_if.ready_out = '1;
    ld_st_if.valid_in = '1;
    ld_st_if.halfWord = '1;
    ld_st_if.hit = '0;
    ld_st_if.data_load = '0;
    ld_st_if.data_in = '0;
    ld_st_if.ld = '1;
    ld_st_if.st = '0;
    #(PERIOD);
    #(PERIOD);

    casenum = 6;
    casename = "LD test, hit, WB stall";
    ld_st_if.rdIn = 32'd5;
    ld_st_if.addr = 32'hDEADBEEF;
    ld_st_if.ready_out = '0;
    ld_st_if.valid_in = '1;
    ld_st_if.halfWord = '1;
    ld_st_if.hit = '1;
    ld_st_if.data_load = 32'hDEEDDEED;
    ld_st_if.data_in = '0;
    ld_st_if.ld = '1;
    ld_st_if.st = '0;
    #(PERIOD);
    #(PERIOD);

    casenum = 7;
    casename = "LD test, hit";
    ld_st_if.rdIn = 32'd5;
    ld_st_if.addr = 32'hDEADBEEF;
    ld_st_if.ready_out = '1;
    ld_st_if.valid_in = '1;
    ld_st_if.halfWord = '1;
    ld_st_if.hit = '1;
    ld_st_if.data_load = 32'hDEEDDEED;
    ld_st_if.data_in = '0;
    ld_st_if.ld = '1;
    ld_st_if.st = '0;
    #(PERIOD);
    #(PERIOD);

    casenum = 8;
    casename = "IDLE";
    ld_st_if.rdIn = 32'd0;
    ld_st_if.addr = 32'h0;
    ld_st_if.ready_out = '1;
    ld_st_if.valid_in = '0;
    ld_st_if.halfWord = '0;
    ld_st_if.hit = '0;
    ld_st_if.data_load = 32'h0;
    ld_st_if.data_in = '0;
    ld_st_if.ld = '0;
    ld_st_if.st = '0;
    #(PERIOD);
    #(PERIOD);

    casenum = 9;
    casename = "ST test, no hit";
    ld_st_if.rdIn = 32'd5;
    ld_st_if.addr = 32'hDEADBEEF;
    ld_st_if.ready_out = '1;
    ld_st_if.valid_in = '1;
    ld_st_if.halfWord = '0;
    ld_st_if.hit = '0;
    ld_st_if.data_load = '0;
    ld_st_if.data_in = 32'hDEEDDEED;
    ld_st_if.ld = '0;
    ld_st_if.st = '1;
    #(PERIOD);
    #(PERIOD);

    casenum = 10;
    casename = "ST test, hit, WB stall";
    ld_st_if.rdIn = 32'd5;
    ld_st_if.addr = 32'hDEADBEEF;
    ld_st_if.ready_out = '0;
    ld_st_if.valid_in = '1;
    ld_st_if.halfWord = '0;
    ld_st_if.hit = '1;
    ld_st_if.data_load = '0;
    ld_st_if.data_in = 32'hDEEDDEED;
    ld_st_if.ld = '0;
    ld_st_if.st = '1;
    #(PERIOD);
    #(PERIOD);

    casenum = 11;
    casename = "ST test, hit";
    ld_st_if.rdIn = 32'd5;
    ld_st_if.addr = 32'hDEADBEEF;
    ld_st_if.ready_out = '1;
    ld_st_if.valid_in = '1;
    ld_st_if.halfWord = '0;
    ld_st_if.hit = '1;
    ld_st_if.data_load = '0;
    ld_st_if.data_in = 32'hDEEDDEED;
    ld_st_if.ld = '0;
    ld_st_if.st = '1;
    #(PERIOD);
    #(PERIOD);

    casenum = 12;
    casename = "IDLE";
    ld_st_if.rdIn = 32'd0;
    ld_st_if.addr = 32'h0;
    ld_st_if.ready_out = '1;
    ld_st_if.valid_in = '0;
    ld_st_if.halfWord = '0;
    ld_st_if.hit = '0;
    ld_st_if.data_load = 32'h0;
    ld_st_if.data_in = '0;
    ld_st_if.ld = '0;
    ld_st_if.st = '0;
    #(PERIOD);
    #(PERIOD);

    casenum = 13;
    casename = "ST test, no hit, HW";
    ld_st_if.rdIn = 32'd5;
    ld_st_if.addr = 32'hDEADBEEF;
    ld_st_if.ready_out = '1;
    ld_st_if.valid_in = '1;
    ld_st_if.halfWord = '1;
    ld_st_if.hit = '0;
    ld_st_if.data_load = '0;
    ld_st_if.data_in = 32'hDEEDDEED;
    ld_st_if.ld = '0;
    ld_st_if.st = '1;
    #(PERIOD);
    #(PERIOD);

    casenum = 14;
    casename = "ST test, hit, WB stall, HW";
    ld_st_if.rdIn = 32'd5;
    ld_st_if.addr = 32'hDEADBEEF;
    ld_st_if.ready_out = '0;
    ld_st_if.valid_in = '1;
    ld_st_if.halfWord = '1;
    ld_st_if.hit = '1;
    ld_st_if.data_load = '0;
    ld_st_if.data_in = 32'hDEEDDEED;
    ld_st_if.ld = '0;
    ld_st_if.st = '1;
    #(PERIOD);
    #(PERIOD);

    casenum = 15;
    casename = "ST test, hit, HW";
    ld_st_if.rdIn = 32'd5;
    ld_st_if.addr = 32'hDEADBEEF;
    ld_st_if.ready_out = '1;
    ld_st_if.valid_in = '1;
    ld_st_if.halfWord = '1;
    ld_st_if.hit = '1;
    ld_st_if.data_load = '0;
    ld_st_if.data_in = 32'hDEEDDEED;
    ld_st_if.ld = '0;
    ld_st_if.st = '1;
    #(PERIOD);
    #(PERIOD);

    casenum = 16;
    casename = "IDLE";
    ld_st_if.rdIn = 32'd0;
    ld_st_if.addr = 32'h0;
    ld_st_if.ready_out = '1;
    ld_st_if.valid_in = '0;
    ld_st_if.halfWord = '0;
    ld_st_if.hit = '0;
    ld_st_if.data_load = 32'h0;
    ld_st_if.data_in = '0;
    ld_st_if.ld = '0;
    ld_st_if.st = '0;
    #(PERIOD);
    #(PERIOD);

    

    $display("DONE");
    $finish;
end

endmodule