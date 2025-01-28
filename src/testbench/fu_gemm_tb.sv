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

    fu_gemm DUT (.CLK(CLK), .nRST(nRST), .fugif(fugif));

endmodule

program test (
    input logic CLK, 
    output logic nRST,
    fu_gemm_if.tb fugif
);
initial begin
    parameter PERIOD = 1;
    nRST = 0;
    
    #(PERIOD * 10);

    nRST = 1;
    fugif.fetch_p = 32'hABCDEF01;
    fugif.flush = 0;
    fugif.freeze = 0;

    #(PERIOD * 10);

    fugif.fetch_p = 32'h00FFAABB;
    fugif.flush = 1;
    fugif.freeze = 0;

    #(PERIOD * 10);
    
    fugif.fetch_p = 32'hFAAAAACC;
    fugif.flush = 0;
    fugif.freeze = 1;

    #(PERIOD * 10);
    $finish;
end
endprogram 
