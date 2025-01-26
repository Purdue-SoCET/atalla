/* Writeback Module */

`include "datapath_types.vh"
`include "isa_types.vh"
`include "writeback_if.vh"

module writeback
(
    input logic CLK, 
    input logic nRST,
    writeback_if.wb wbif // MATRIX LOAD STORE IF
);

// importing types
import datapath_pkg::*;
import isa_pkg::*;


endmodule