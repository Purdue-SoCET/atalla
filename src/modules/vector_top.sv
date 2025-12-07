`include vector_if.vh
`include vector_pkg.vh

module vector_top
(
    input logic CLK, nRST,
    
    // Inputs to Veggie

    input veggie_in_t veggie_in,
    input logic iready,
    
    // Outputs

    output veggie_out_t veggie_out
    output logic vrf_ready,
    output logic accomplished,


);

import vector_pkg::*;

assign veggie_out = opbuff_in;

//need connection from veggie out to opbuff in
//need 



endmodule