`include "dram_pkg.svh"
`include "ddr_controller_if.sv"

module nb_wdata_queue_prop(
    input logic CLK,
    input logic nRST,

    ddr_controller_if.wdata_queue wdq, 
    ddr_controller_if.wdata_wrapper wdw
);
    import dram_pkg::*;
    import cpu_types_pkg::*;

/*
    covergroup wdq_cg @(posedge CLK) // TODO: FIX COVERPOINTS 
        awdata : coverpoint {wstrb, wdq_slot, wready};
        barb_wdata : coverpoint {be_wid, be_write};
        bresp : coverpoint {bwready, bwvalid, bwresp, bwid};
        
    endgroup
*/
    wdq_cg wdqcg;

    property AXI_wdata_handshake(int i); //ensures proper handshake.
        @(posedge CLK) disable iff (!nRST)
        (wdq.bwvalid[i] && wdq.bwready && (wdw.wrap_bw_arb == i)) |=> !wdq.bwvalid[i];
    endproperty

    property AXI_wdata_wait(int i); //ensures proper handshake.
        @(posedge CLK) disable iff (!nRST)
        (wdq.bwvalid[i] && !(wdq.bwready && (wdw.wrap_bw_arb == i))) |=>  $stable(wdq.bwvalid[i]); 
    endproperty

    property AXI_wdata_handshake_cycle(int i); //ensures proper handshake.
        @(posedge CLK) disable iff (!nRST)
        (wdq.bwvalid[i] && wdq.bwready && (wdw.wrap_bw_arb == i)) |-> wdq.bwvalid[i]; 
    endproperty

    property wdata_tCWL(int i); //ensures CWL parameter upheld
        @(posedge CLK) disable iff (!nRST)
        (wdq.be_write && (wdq.be_id == i) ) |-> (!wdq.ddr_we[i])[*(tCWL-1)] ##1 (wdq.ddr_we[i])[*8] ##1 $fell(wdq.ddr_we[i]);
    endproperty

    property AXI_wdata_response(int i); //ensures response is ready from wdata queue after data sent.
        @(posedge CLK) disable iff (!nRST)
        $fell(wdq.ddr_we[i]) |-> wdq.bwvalid[i]; 
    endproperty 

    property ddr_burst_arbitration;

        @(posedge CLK) disable iff (!nRST)
        $onehot0(wdq.ddr_we);

    endproperty


    
        
endmodule 

