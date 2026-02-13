`include "dram_pkg.vh"
`include "cpu_types_pkg.vh"
`include "ddr_controller_if.vh"

module nb_barb_prop(
    input logic CLK,
    input logic nRST,
    // 2/13 - TODO: ADD SIGNALS
    ddr_controller_if.backend_arb barb
);
    import dram_pkg::*;
    import cpu_types_pkg::*;

    property onehot
        @(posedge CLK) disable iff (!nRST || (barb.be_cmd[BANK_NUM-1:0]) == ((BANK_NUM){REFRESH}) )
        $onehot0(barb.be_arb);
    endproperty

    property timing_tCCD_L
        @(posedge CLK) disable iff (!nRST)
        ($onehot(be_queue_ready & be_arb) ) |-> [*tCCD_L] ~|(barb.be_arb)
    endproperty 


endmodule 