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

    covergroup wdq_cg @(posedge CLK) // TODO: FIX COVERPOINTS 
        awdata : coverpoint {wstrb, wdq_slot, wready};
        barb_wdata : coverpoint {be_wid, be_write};
        bresp : coverpoint {bwready, bwvalid, bwresp, bwid};
        
    endgroup

    wdq_cg wdqcg;

    property AXI_wdata_handshake;
        @(posedge CLK) disable iff (!nRST)
        (wdq.bwvalid && wdq.bwready) |=> !wdq.bwvalid;
    endproperty

    property AXI_wdata_wait;
        @(posedge CLK) disable iff (!nRST)
        (wdq.bwvalid && !wdq.bwready) |=>  $stable(wdq.bwvalid); 
    endproperty

    property AXI_wdata_handshake_cycle;
        @(posedge CLK) disable iff (!nRST)
        (wdq.bwvalid && wdq.bwready) |-> wdq.bwvalid; 
    endproperty

    property AXI_wdata_tCWL;
        @(posedge CLK) disable iff (!nRST)
        (wdq.be_write && (wdq.be_id == Q_ID) ) |-> [*(tCWL-1)](!wdq.ddr_we) ##1 $rose(wdq.ddr_we) ##1 $fell(wdq.ddr_we);
    endproperty

    
        
endmodule 

