`timescale 1ns / 10ps
`include "fu_gemm_if.vh"
`include "isa_types.vh"
`include "datapath_types.vh"

module fu_gemm_tb;

    parameter PERIOD = 10;
    logic CLK = 0, nRST;

    always #(PERIOD/2) CLK++;

    fu_gemm_if fugif ();

    test PROG (.CLK(CLK), .nRST(nRST), .fugif(fugif));

    dispatch DUT (.CLK(CLK), .nRST(nRST), .fugif(fugif));

endmodule

program test (
    input logic CLK, 
    output logic nRST,
    fu_gemm_if.tb fugif
);
initial begin

    nRST = 0;

    @(posedge CLK);

    nRST = 1;
    fugif.fetch_p = 32'hABCDEF01;
    fugif.flush = 0;
    fugif.freeze = 0;
    @(posedge CLK * 3);

    fugif.fetch_p = 32'h00FFAABB;
    fugif.flush = 1;
    fugif.freeze = 0;
    @(posedge CLK * 3);
    
    fugif.fetch_p = 32'hFAAAAACC;
    fugif.flush = 0;
    fugif.freeze = 1;
    @(posedge CLK * 5);
    $finish;
end
