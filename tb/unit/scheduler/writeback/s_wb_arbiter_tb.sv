`timescale 1ns / 10ps
`include "s_wb_arbiter_if.vh"
//`include "cpu_types.vh"

module s_wb_arbiter_tb;
    import scalar_wb_pkg::*;
    parameter PERIOD = 10;
    logic CLK = 0, nRST;

    always #(PERIOD/2) CLK++;

    s_wb_arbiter_if wbif ();

    test PROG (.CLK(CLK), .nRST(nRST), .tbif(wbif));

    s_wb_arbiter DUT (.CLK(CLK), .nRST(nRST), .vif(wbif));

endmodule

program test (
    input logic CLK, 
    output logic nRST,
    s_wb_arbiter_if.tbif tbif
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
        //   TODO BRING INPUTS LOW WAIT ONE CYCLE
        tbif.scalar_wb_in = '0;
        @(posedge CLK);
        end
    endtask

    initial begin
        automatic string tb_test_case = "INIT";
        reset_in();
        reset_dut();
        @(posedge CLK);

    
        tb_test_case = "NORMAL 4 INPUT NO CONFLICT";
        tbif.scalar_wb_in.valid = 9'b000001111;
        tbif.scalar_wb_in.data[0] = 32'hDEADBEEF;
        tbif.scalar_wb_in.data[1] = 32'hFEEDBEEF;
        tbif.scalar_wb_in.data[2] = 32'hBAD0BAD0;
        tbif.scalar_wb_in.data[3] = 32'hCAFEBABE;
        tbif.scalar_wb_in.data[4] = 32'hDEADBEBE;
        tbif.scalar_wb_in.rd[0] = 8'd0;
        tbif.scalar_wb_in.rd[1] = 8'd64;
        tbif.scalar_wb_in.rd[2] = 8'd128;
        tbif.scalar_wb_in.rd[3] = 8'd192;
        tbif.scalar_wb_in.rd[4] = 8'd0; 
        #(100);
        reset_in();
        
        tb_test_case = "5 INPUT";
        tbif.scalar_wb_in.valid = 9'b000011111;
        tbif.scalar_wb_in.data[0] = 32'hDEADBEEF;
        tbif.scalar_wb_in.data[1] = 32'hFEEDBEEF;
        tbif.scalar_wb_in.data[2] = 32'hBAD0BAD0;
        tbif.scalar_wb_in.data[3] = 32'hCAFEBABE;
        tbif.scalar_wb_in.data[4] = 32'hDEADBEBE;
        tbif.scalar_wb_in.rd[0] = 8'd0;
        tbif.scalar_wb_in.rd[1] = 8'd64;
        tbif.scalar_wb_in.rd[2] = 8'd128;
        tbif.scalar_wb_in.rd[3] = 8'd192;
        tbif.scalar_wb_in.rd[4] = 8'd0; 
        #(100);
        reset_in();
        
        tb_test_case = "3 INPUT NO CONFLICT";
        tbif.scalar_wb_in.valid = 9'b000000111;
        tbif.scalar_wb_in.data[0] = 32'hDEADBEEF;
        tbif.scalar_wb_in.data[1] = 32'hFEEDBEEF;
        tbif.scalar_wb_in.data[2] = 32'hBAD0BAD0;
        tbif.scalar_wb_in.data[3] = 32'hCAFEBABE;
        tbif.scalar_wb_in.data[4] = 32'hDEADBEBE;
        tbif.scalar_wb_in.rd[0] = 8'd0;
        tbif.scalar_wb_in.rd[1] = 8'd64;
        tbif.scalar_wb_in.rd[2] = 8'd128;
        tbif.scalar_wb_in.rd[3] = 8'd0;
        tbif.scalar_wb_in.rd[4] = 8'd0; 
       #(100);
        reset_in();
 
        tb_test_case = "4 INPUT";
        tbif.scalar_wb_in.valid = 9'b000001111;
        tbif.scalar_wb_in.data[0] = 32'hDEADBEEF;
        tbif.scalar_wb_in.data[1] = 32'hFEEDBEEF;
        tbif.scalar_wb_in.data[2] = 32'hBAD0BAD0;
        tbif.scalar_wb_in.data[3] = 32'hCAFEBABE;
        tbif.scalar_wb_in.rd[0] = 8'd0;
        tbif.scalar_wb_in.rd[1] = 8'd64;
        tbif.scalar_wb_in.rd[2] = 8'd128;
        tbif.scalar_wb_in.rd[3] = 8'd3;
        #(100);
        reset_in();

        tb_test_case = "9 INPUT";
        tbif.scalar_wb_in.valid = 9'b000001111;
        tbif.scalar_wb_in.data[0] = 32'hDEADBEEF;
        tbif.scalar_wb_in.data[1] = 32'hFEEDBEEF;
        tbif.scalar_wb_in.data[2] = 32'hBAD0BAD0;
        tbif.scalar_wb_in.data[3] = 32'hCAFEBABE;
        tbif.scalar_wb_in.data[4] = 32'hDEADBEBE;
        tbif.scalar_wb_in.data[5] = 32'hDEADBEEF;
        tbif.scalar_wb_in.data[6] = 32'hFEEDBEEF;
        tbif.scalar_wb_in.data[7] = 32'hBAD0BAD0;
        tbif.scalar_wb_in.data[8] = 32'hCAFEBABE;
        tbif.scalar_wb_in.rd[0] = 8'd0;
        tbif.scalar_wb_in.rd[1] = 8'd64;
        tbif.scalar_wb_in.rd[2] = 8'd128;
        tbif.scalar_wb_in.rd[3] = 8'd192;
        tbif.scalar_wb_in.rd[4] = 8'd0;
        tbif.scalar_wb_in.rd[5] = 8'd64;
        tbif.scalar_wb_in.rd[6] = 8'd128;
        tbif.scalar_wb_in.rd[7] = 8'd192;
        tbif.scalar_wb_in.rd[8] = 8'd0; 
        #(100);
        reset_in();

        tb_test_case = "4 INPUT";
        tbif.scalar_wb_in.valid = 9'b000011110;
        tbif.scalar_wb_in.data[0] = 32'hDEADBEEF;
        tbif.scalar_wb_in.data[1] = 32'hFEEDBEEF;
        tbif.scalar_wb_in.data[2] = 32'hBAD0BAD0;
        tbif.scalar_wb_in.data[3] = 32'hCAFEBABE;
        tbif.scalar_wb_in.data[4] = 32'hDEADBEBE;
        tbif.scalar_wb_in.rd[0] = 8'd0;
        tbif.scalar_wb_in.rd[1] = 8'd64;
        tbif.scalar_wb_in.rd[2] = 8'd128;
        tbif.scalar_wb_in.rd[3] = 8'd192;
        tbif.scalar_wb_in.rd[4] = 8'd0; 
        #(100);
        reset_in();


        $finish;
    end


endprogram
