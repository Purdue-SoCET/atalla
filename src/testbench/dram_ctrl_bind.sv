`include "dram_pkg.vh"
`include "cpu_types_pkg.vh"

module ddr_ctrl_confirm(
    input logic CLK,
    input logic nRST,
    // 2/13 - TODO: ADD SIGNALS
    ddr_controller_if.wdata_queue wdq
);
    import dram_pkg::*;
    import cpu_types_pkg::*;

    // // PROPERTIES
    // 2/13 - TODO: Figure out proper syntax

    property one_hot;
        @(posedge CLK); disable iff (nRST)
        $onehot(); // Put one hot signal
    endproperty

    property tccd;
    
    endproperty

    property tFAW;
    endproperty

    property write_response;
    endproperty

    sequence 

    endsequence
        
endmodule 

