`include "dram_pkg.svh"
`include "ddr_controller_if.sv"

module nb_barb_prop(
    input logic CLK,
    input logic nRST,
    ddr_controller_if.barb_prop barb
);
    import dram_pkg::*;

    /* covergroup nb_cg @(posedge CLK) // TODO: FIX COVERPOINTS 
        fsm_be : coverpoint {be_r, be_c, be_b, be_bg, be_cmd, be_id, be_rlen, be_queue_ready};
        be_fsm : coverpoint {be_arb};
        be_wdq : coverpoint {be_wid, be_write};
        be_riq : coverpoint {be_rid, be_push_id, be_rlen}; 
    endgroup

    nb_cg nbcg; */

    int debug_counter = 0;
    always @(posedge CLK) begin
        debug_counter <= debug_counter + 1;
    end

    function automatic integer encode (input logic [15:0] in);
        for (int i = 0; i < 16; i++) begin
            if (in[i]) return i;
        end
        return -1;
    endfunction

    sequence access_counter;

        |( (barb.be_queue_ready & barb.be_arb) && ( (barb.be_cmd[encode(barb.be_queue_ready & barb.be_arb)]) == ACT) )[->3];

    endsequence

    property onehot;
        @(posedge CLK) disable iff (!nRST)
        $onehot0(barb.be_arb) || ( (barb.be_cmd[BANK_NUM-1:0]) == ({BANK_NUM{REFRESH}}) & &(barb.be_queue_ready) );
    endproperty

    /* property timing_tCCD_L; TODO:  DONT WORK "[*]"
        integer bg_last; 
        @(posedge CLK) disable iff (!nRST)
        ( $onehot(barb.be_queue_ready & barb.be_arb), bg_last = encode(barb.be_queue_ready & barb.be_arb) ) |-> [*tCCD_L] (~|(barb.be_arb) || encode(barb.be_queue_ready & barb.be_arb) != bg_last);
    endproperty */ 

    /* property timing_tCCD_S; TODO: DONT WORK "[*]"
        @(posedge CLK) disable iff(!nRST)
        $onehot(be_queue_ready & be_arb) |=> [*tCCD_S] ~|(barb.be_arb);
    endproperty */

    /* property timing_tFAW; TODO: DONT WORK "[*]""
        @(posedge CLK) disable iff(!nRST)
        ($onehot(be_queue_ready & be_arb) && ( (barb.be_cmd[encode(barb.be_queue_ready & barb.be_arb)]) == ACT) ) |-> [*tFAW](not access_counter);
    endproperty */

    property check_refresh_arbitration;
        @(posedge CLK) disable iff (!nRST)
        ( (barb.be_cmd[BANK_NUM-1:0]) == ({BANK_NUM{REFRESH}})  & &(barb.be_queue_ready) ) |-> &(barb.be_arb);
    endproperty

    property check_refresh_sending;
        @(posedge CLK) disable iff (!nRST)
        
        ( (barb.be_cmd[BANK_NUM-1:0]) == ({BANK_NUM{REFRESH}})  & &(barb.be_queue_ready) ) ;
    endproperty


    /////COMMENT THE BELOW PROPERTY OUT IF WDATA_QUEUE IS NOT YET CONNECTED OR VERIFIED.
    /* property timing_tCWL;
        @(posedge CLK) disable iff(!nRST)
        (|(barb.be_queue_ready & barb.be_arb) ) &&  ( (barb.be_cmd[encode(barb.be_queue_ready & barb.be_arb)]) == WRITE ) |-> [*tCWL](!wdq.ddr_we) ##1 $rose(wdq.ddr_we) ##1 $fell(wdq.ddr_we);
    endproperty */

endmodule 

