`timescale 1ns / 10ps
`include "atalla_isa_types.vh"
`include "decode_2_if.vh"

module decode_2_tb;
    import atalla_isa_pkg::*;

    parameter PERIOD = 2;
    logic CLK = 0, nRST;
    always #(PERIOD/2) CLK++;
    string casename;

    decode_2_if d2if ();
    decode_2 DUT (.CLK(CLK), .nRST(nRST), .d2if(d2if));

    initial begin
        casename = "rst";
        nRST = 1'b0;

        $finish;
    end


endmodule