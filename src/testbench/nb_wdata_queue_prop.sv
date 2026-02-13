`include "dram_pkg.vh"
`include "cpu_types_pkg.vh"
`include "ddr_controller_if.vh"

module nb_wdata_queue_prop(
    input logic CLK,
    input logic nRST,
    // 2/13 - TODO: ADD SIGNALS
    ddr_controller_if.wdata_queue wdq
);
    import dram_pkg::*;
    import cpu_types_pkg::*;

    // // PROPERTIES
    // 2/13 - TODO: Figure out proper syntax

    property AXI_wdata_handshake;
        @(posedge CLK) disable iff (!nRST)
        (wdq.bwvalid && wdq.bwready) |=> !wdq.bwvalid;
    endproperty

    property 
        @(posedge CLK) disable iff (!nRST)
        (wdq.bwvalid && !wdq.bwready) |=>  $stable(wdq.bwvalid); 
    endproperty

    property 
        @(posedge CLK) disable iff (!nRST)
        (wdq.bwvalid && wdq.bwready) |-> wdq.bwvalid; 
    endproperty

    sequence 

    endsequence
        
endmodule 

