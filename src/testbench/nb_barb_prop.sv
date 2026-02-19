`include "dram_pkg.vh"
`include "cpu_types_pkg.vh"
`include "ddr_controller_if.vh"

module nb_barb_prop(
    input logic CLK,
    input logic nRST,
    // 2/13 - TODO: ADD SIGNALS, DONT ADD SIGNALS, ADD PROPERTIES
    ddr_controller_if.backend_arb barb
);
    import dram_pkg::*;
    import cpu_types_pkg::*;

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
        $onehot0(barb.be_arb) || ( (barb.be_cmd[BANK_NUM-1:0]) == ((BANK_NUM){REFRESH}) & &(barb.be_queue_ready) );
    endproperty

    property timing_tCCD_L;
        integer bg_last; 
        @(posedge CLK) disable iff (!nRST)
        ( $onehot(barb.be_queue_ready & barb.be_arb), bg_last = encode(barb.be_queue_ready & barb.be_arb) ) |=> [*tCCD_L] (~|(barb.be_arb) || encode(barb.be_queue_ready & barb.be_arb) != bg_last);
    endproperty 

    property timing_tCCD_S;
        @(posedge CLK) disable iff(!nRST)
        $onehot(be_queue_ready & be_arb) |=> [*tCCD_S] ~|(barb.be_arb);
    endproperty

    property timing_tFAW;
        @(posedge CLK) disable iff(!nRST)
        ($onehot(be_queue_ready & be_arb) && ( (barb.be_cmd[encode(barb.be_queue_ready & barb.be_arb)]) == ACT) ) |-> [*tFAW](not access_counter);
    endproperty

    property check_refresh_arbitration;
        @(posedge CLK) disable iff (!nRST)
        ( (barb.be_cmd[BANK_NUM-1:0]) == ((BANK_NUM){REFRESH})  & &(barb.be_queue_ready) ) |-> &(barb.be_arb);
    endproperty

    property check_refresh_sending;
        @(posedge CLK) disable iff (!nRST)
        
        ( (barb.be_cmd[BANK_NUM-1:0]) == ((BANK_NUM){REFRESH})  & &(barb.be_queue_ready) ) 
    endproperty

endmodule 

