`include "control_unit_if.vh"
`include "signal_gen_if.vh"

module dram_controller_top (
    input logic clk,
    input logic nRST,
    // signal_gen_if sigif,
    // address_mapper_if amif,
    // init_state_if initif,
    // row_open_if polif,
    // command_fsm_if cfsmif,
    // timing_signals_if timif,
    // control_unit_if cuif,
    // data_transfer_if dataif
    
    address_mapper_if.addr_mapper amif_addr_mapper,
    address_mapper_if.row_open amif_row_open,
    init_state_if.init_fsm initif,
    row_open_if.row_open polif_row_open,
    row_open_if.cmd_fsm polif_cmd_fsm,
    command_fsm_if.cmd_fsm cfsmif_cmd_fsm,
    command_fsm_if.timing_ctrl cfsmif_timing_ctrl,
    timing_signals_if.row_open timif_row_open,
    timing_signals_if.cmd_fsm timif_cmd_fsm,
    timing_signals_if.timing_ctrl timif_timing_ctrl,
    timing_signals_if.data_transfer timif_data_trans,
    signal_gen_if.dram sigif_dram,
    control_unit_if.sig_gen cuif_sig_gen,
    control_unit_if.arb cuif_arb,
    control_unit_if.data_trans cuif_data_trans
);

    // control_unit    control_unit  (.clk(clk), .nRST(nRST), .amif(amif), .initif(initif), .polif(polif), 
    //                                .cfsmif(cfsmif), .timif(timif), .cuif(cuif));
    control_unit    control_unit  (.clk(clk), .nRST(nRST), .amif_addr_mapper(amif_addr_mapper), .amif_row_open(amif_row_open), .initif(initif), .polif_row_open(polif_row_open), 
                                   .polif_cmd_fsm(polif_cmd_fsm), .cfsmif_cmd_fsm(cfsmif_cmd_fsm), .cfsmif_timing_ctrl(cfsmif_timing_ctrl), .timif_row_open(timif_row_open),
                                   .timif_cmd_fsm(timif_cmd_fsm), .timif_timing_ctrl(timif_timing_ctrl), .timif_data_trans(timif_data_trans), .cuif_arb(cuif_arb), .cuif_sig_gen(cuif_sig_gen),
                                   .cuif_data_trans(cuif_data_trans));
    signal_gen      sig_gen       (.CLK(clk), .nRST(nRST), .cuif(cuif_sig_gen), .mysig(sigif_dram));
    //data_transfer   data_transfer (.CLK(clk), .CLKx2(clkx2), .nRST(nRST), .cuif(cuif.data_trans), .mydata(dataif.data_trans));


endmodule